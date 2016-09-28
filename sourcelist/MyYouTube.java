import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;

import net.arnx.jsonic.JSON;

public class MyYouTube {
	// �A�N�Z�X�g�[�N���擾�̂��߂�URL
	private static final String TOKEN_URL = "https://accounts.google.com/o/oauth2/token";
	// �N���C�A���gid
	private final String CONSUMER_KEY = "707601956964-gojtq9hq7h6qt751k973lprdh8ts20rv.apps.googleusercontent.com";
	// �N���C�A���g�V�[�N���b�g
	private final String CONSUMER_SECRET = "or07nBfMB3qafJ_T9bdK4Fgu";
	// ���t���b�V���g�[�N��
	private final String REFRESH_TOKEN = "1/BoOZShXB3j0jr5-jiI2NQVA0RE6-nICyixzdVZg4nCw";
	// �A�N�Z�X�g�[�N��
	private String access_token = null;
	
	private int fileSize;
	private int range=0;
	
	public void setMetadata(String video, String title, String description) throws IOException{
		// �n���ꂽ�t�@�C����avi�`���łȂ���Ή�������return
		if(!video.endsWith(".avi")) return;
		
		// �A�N�Z�X�g�[�N���̎擾
		URL access_url = new URL(TOKEN_URL);
		URLConnection access_uc = access_url.openConnection();
		access_uc.setDoOutput(true);
		String postStr = "grant_type=refresh_token&refresh_token="+ REFRESH_TOKEN + "&client_id=" + CONSUMER_KEY + "&client_secret=" + CONSUMER_SECRET;
		OutputStream access_os = access_uc.getOutputStream();
		PrintStream access_ps = new PrintStream(access_os);
		access_ps.print(postStr);
		access_ps.close();

		// ���X�|���X�̎擾
		InputStream access_is = access_uc.getInputStream();
		BufferedReader access_reader = new BufferedReader(new InputStreamReader(access_is));
		String json = null;
		String s = null;
		while ((s = access_reader.readLine()) != null) {
			json += s;
		}
		access_reader.close();
		// json��java�ɕϊ�
		Code code = JSON.decode(json.substring(json.indexOf("{")), Code.class);
		access_token = code.getAccess_token();
		
		// �t�@�C�����o�C�i���ɕϊ�����
		byte[] b = new byte[1];
		FileInputStream fis = new FileInputStream(video);
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		while (fis.read(b) > 0) { baos.write(b); }
		baos.close();
		fis.close();
		b = baos.toByteArray();
		int[] fileByte = new int[b.length];
		// byte�͕��̐����܂�ł��܂��̂ł��ׂĐ��̐��ɂȂ�悤�ϊ�
		for(int i = 0, n = b.length; i < n; i++){
			fileByte[i] = Byte.toUnsignedInt(b[i]);
		}
		
		// �ĊJ�\�ȃA�b�v���[�h�̃Z�b�V�������J�n���邽�߂�url
		URL resume_url = new URL("https://www.googleapis.com/upload/youtube/v3/videos?uploadType=resumable&part=snippet,status,contentDetails&key=AIzaSyDEgkuehdEK_kh0gEw6-3c-8WwcIS2i0nI");
		// �^�C�g���A�����Ȃǂ̏�������json
		String sentJson = "{\"snippet\": {\"title\": \"" + title + "\",\"description\": \"" + description + "\"},\"status\": {\"privacyStatus\": \"unlisted\",\"embeddable\": \"True\",\"license\": \"youtube\"}}";
		HttpURLConnection resume_uc = (HttpURLConnection) resume_url.openConnection();
		resume_uc.setUseCaches(false);			//  �L���b�V�����g�p���Ȃ�
		resume_uc.setDoOutput(true);			//  �A�E�g�v�b�g�ł���悤�ɂ���
		resume_uc.setRequestMethod("POST");		//  �|�X�g�ʐM�ł���
			
		// �w�b�_�̐ݒ�
		resume_uc.setRequestProperty("HOST", "www.googleapis.com");
		resume_uc.setRequestProperty("Authorization", "Bearer " + access_token);
		resume_uc.setRequestProperty("Content-Length", String.valueOf(sentJson.length()));
		resume_uc.setRequestProperty("Content-Type", "application/json; charset=UTF-8");
		resume_uc.setRequestProperty("X-Upload-Content-Length", String.valueOf(fileSize));
		resume_uc.setRequestProperty("X-upload-content-type", "video/avi");
		
		OutputStream resume_os = resume_uc.getOutputStream();	
		PrintStream resume_ps = new PrintStream(resume_os);
		resume_ps.print(sentJson);
		resume_ps.close();
		resume_os.close();
		// ���ۂɓ���̃A�b�v���[�h
		URL upload_url = new URL(resume_uc.getHeaderField("location"));
		HttpURLConnection upload_uc = (HttpURLConnection)upload_url.openConnection();
		upload_uc.setUseCaches(false);
		upload_uc.setDoOutput(true);
		upload_uc.setRequestMethod("POST");
		
		// �w�b�_�̐ݒ�
		upload_uc.setRequestProperty("Authorization", "Bearer " + access_token);
		upload_uc.setRequestProperty("Content-Length", String.valueOf(fileSize));
		upload_uc.setRequestProperty("Content-Type", "video/avi");
		OutputStream upload_os = upload_uc.getOutputStream();	
		PrintStream upload_ps = new PrintStream(upload_os);
		// ���M
		for(int i :fileByte)upload_ps.write(i);
		upload_ps.close();	upload_os.close();
		// ���X�|���X�̎擾
		InputStream is = upload_uc.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		String upload_json = null;
		while((s = br.readLine()) != null){
			upload_json += s;
			System.out.println(s);
		}
		is.close(); br.close();
		if(upload_uc.getHeaderField("Range") != null){
			this.range = Integer.parseInt(upload_uc.getHeaderField("Range").substring(upload_uc.getHeaderField("Range").indexOf("-") + 1));
		}else{
			this.range = 0;
        }
            
		while(true){
			// ���X�|���X�R�[�h�̎擾
			int rescode = upload_uc.getResponseCode();
			// Range(�ǂ��܂ŃA�b�v���[�h�ł������̏��)���擾
			// �ĊJ�\�ȃ��X�|���X�R�[�h��Range���i���łȂ��Ƃ�
			if((rescode == 308 || rescode == 503) && this.range != 0){
				System.out.println(getHeader(
            				resumeReqest(
            						upload_url, 
            						Arrays.copyOfRange(fileByte, range + 1, 3971110),
            						(int)fileSize, 
            						range)));
			}else if(rescode == 200){
				Code info_code = JSON.decode(upload_json.substring(upload_json.indexOf("{")), Code.class);
				String infostr =  video.substring(0,video.indexOf("."));
				String[] infolist = infostr.split("-", 0);
				String params = null;
				if(infolist.length > 2){
					params = "user="+infolist[0]+"&song="+infolist[1]+"&date="+infolist[2]+"&movie="+info_code.getId();
            	}
				URL info_url = new URL("http:// localhost:8888/test/Move.php?"+params);
				HttpURLConnection info_uc = (HttpURLConnection) info_url.openConnection();
				info_uc.setUseCaches(false);			//  �L���b�V�����g�p���Ȃ�
				info_uc.setDoOutput(true);			//  �A�E�g�v�b�g�ł���悤�ɂ���
				info_uc.setRequestMethod("POST");		//  �|�X�g�ʐM�ł���
				OutputStream info_os = info_uc.getOutputStream();
				PrintStream info_ps = new PrintStream(info_os);
				info_ps.close();	info_os.close();
				
				InputStream info_is = info_uc.getInputStream();
				BufferedReader info_br = new BufferedReader(new InputStreamReader(info_is));
				String l = null;
				while((l = info_br.readLine()) != null){
            			System.out.println(l);
				}
				info_br.close();	info_is.close();
				return;
            }else{
            	resume_ps.close();
            	br.close();
            	baos.close();
            	upload_ps.close();
            	return;
            }
        }
	}

	/**
	 * 
	 * @param url		�t�@�C�����A�b�v���[�h����URL
	 * @param file		�A�b�v���[�h����t�@�C��
	 * @param fileSize	�A�b�v���[�h����t�@�C���̃T�C�Y
	 * @param range		����܂ŃA�b�v���[�h�ł����͈�
	 * @throws IOException 
	 */
	private HttpURLConnection resumeReqest(URL url, final int[] file, int fileSize, int range) throws IOException{
		int firstRange = range + 1;
		int lastRange = fileSize - 1;
		HttpURLConnection uc = null;
		uc = (HttpURLConnection)url.openConnection();
		uc.setUseCaches(false);
		uc.setDoOutput(true);
		uc.setRequestMethod("POST");
		
		uc.setRequestProperty("Authorization", "Bearer " + access_token);
		uc.setRequestProperty("Content-Length", String.valueOf(fileSize - firstRange));
		System.out.println(fileSize-firstRange);
		uc.setRequestProperty("Content-Range", "bytes " + String.valueOf(firstRange) + "-" + String.valueOf(lastRange) + "/" + String.valueOf(fileSize));
		OutputStream os = uc.getOutputStream();
		PrintStream ps = new PrintStream(os);
		for(int i :file){
			ps.write(i);
		}
		ps.close();	os.close();
		if(uc.getHeaderField("Range") != null){
			this.range = Integer.parseInt(uc.getHeaderField("Range").substring(uc.getHeaderField("Range").indexOf("-") + 1));
		}
		InputStream is = uc.getErrorStream();
		if(is != null){
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			String s = null;
			while((s = br.readLine()) != null){
				System.out.println(s);
            	br.close();
            }
		}
		is.close();
		return uc;
	}
	
	// ���X�|���X�w�b�_�̎擾
	private String getHeader(HttpURLConnection uc){
		Map headers = uc.getHeaderFields();
		Iterator headerIt = headers.keySet().iterator();
		String header = null;
		while(headerIt.hasNext()){
			String headerKey = (String)headerIt.next();
			header += headerKey + "�F" + headers.get(headerKey) + "\r\n";
		}
		return header;
	}
	public synchronized void sleep(long msec)
	{	// �w��~���b���s���~�߂郁�\�b�h
		try
		{
			wait(msec);
		}catch(InterruptedException e){}
	}
}
