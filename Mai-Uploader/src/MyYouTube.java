import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;

import net.arnx.jsonic.JSON;

public class MyYouTube {
	//アクセストークン取得のためのURL
	private static final String TOKEN_URL = "https://accounts.google.com/o/oauth2/token";
	//クライアントid
	private final String CONSUMER_KEY = "707601956964-gojtq9hq7h6qt751k973lprdh8ts20rv.apps.googleusercontent.com";
	//クライアントシークレット
	private final String CONSUMER_SECRET = "or07nBfMB3qafJ_T9bdK4Fgu";
	//リフレッシュトークン
	private final String REFRESH_TOKEN = "1/BoOZShXB3j0jr5-jiI2NQVA0RE6-nICyixzdVZg4nCw";
	//アクセストークン
	private String access_token = null;
	
	private int fileSize;
	private int range=0;
	
	public void setMetadata(String video, String title, String description) throws IOException{
		//渡されたファイルがavi形式でなければ何もせずreturn
		if(!video.endsWith(".avi")) return;
		
		//アクセストークンの取得
		URL access_url = new URL(TOKEN_URL);
		URLConnection access_uc = access_url.openConnection();
		access_uc.setDoOutput(true);
		String postStr = "grant_type=refresh_token&refresh_token="+ REFRESH_TOKEN + "&client_id=" + CONSUMER_KEY + "&client_secret=" + CONSUMER_SECRET;
		OutputStream access_os = access_uc.getOutputStream();
		PrintStream access_ps = new PrintStream(access_os);
		access_ps.print(postStr);
		access_ps.close();

		//レスポンスの取得
		InputStream access_is = access_uc.getInputStream();
		BufferedReader access_reader = new BufferedReader(new InputStreamReader(access_is));
		String json = null;
		String s = null;
		while ((s = access_reader.readLine()) != null) {
			json += s;
		}
		access_reader.close();
		//jsonをjavaに変換
		Code code = JSON.decode(json.substring(json.indexOf("{")), Code.class);
		access_token = code.getAccess_token();
		
		//ファイルをバイナリに変換する
		byte[] b = new byte[1];
		FileInputStream fis = new FileInputStream(video);
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		while (fis.read(b) > 0) { baos.write(b); }
		baos.close();
		fis.close();
		b = baos.toByteArray();
		int[] fileByte = new int[b.length];
		//byteは負の数を含んでしまうのですべて正の数になるよう変換
		for(int i = 0, n = b.length; i < n; i++){
			fileByte[i] = Byte.toUnsignedInt(b[i]);
		}
		this.fileSize = fileByte.length;
		//再開可能なアップロードのセッションを開始するためのurl
		URL resume_url = new URL("https://www.googleapis.com/upload/youtube/v3/videos?uploadType=resumable&part=snippet,status,contentDetails&key=AIzaSyDEgkuehdEK_kh0gEw6-3c-8WwcIS2i0nI");
		//タイトル、説明などの情報を持つjson
		String sentJson = "{\"snippet\": {\"title\": \"" + title + "\",\"description\": \"" + description + "\"},\"status\": {\"privacyStatus\": \"unlisted\",\"embeddable\": \"True\",\"license\": \"youtube\"}}";
		HttpURLConnection resume_uc = (HttpURLConnection) resume_url.openConnection();
		resume_uc.setUseCaches(false);			// キャッシュを使用しない
		resume_uc.setDoOutput(true);			// アウトプットできるようにする
		resume_uc.setRequestMethod("POST");		// ポスト通信である
			
		//ヘッダの設定
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
		//実際に動画のアップロード
		URL upload_url = new URL(resume_uc.getHeaderField("location"));
		HttpURLConnection upload_uc = (HttpURLConnection)upload_url.openConnection();
		upload_uc.setUseCaches(false);
		upload_uc.setDoOutput(true);
		upload_uc.setRequestMethod("POST");
		
		//ヘッダの設定
		upload_uc.setRequestProperty("Authorization", "Bearer " + access_token);
		upload_uc.setRequestProperty("Content-Length", String.valueOf(fileSize));
		upload_uc.setRequestProperty("Content-Type", "video/avi");
		OutputStream upload_os = upload_uc.getOutputStream();	
		PrintStream upload_ps = new PrintStream(upload_os);
		//送信
		for(int i :fileByte)upload_ps.write(i);
		upload_ps.close();	upload_os.close();
		//レスポンスの取得
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
			//レスポンスコードの取得
			int rescode = upload_uc.getResponseCode();
			//Range(どこまでアップロードできたかの情報)を取得
			//再開可能なレスポンスコードでRangeがナルでないとき
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
				URL info_url = new URL("http://localhost:8888/test/Move.php?"+params);
				HttpURLConnection info_uc = (HttpURLConnection) info_url.openConnection();
				info_uc.setUseCaches(false);			// キャッシュを使用しない
				info_uc.setDoOutput(true);			// アウトプットできるようにする
				info_uc.setRequestMethod("POST");		// ポスト通信である
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
	 * @param url		ファイルをアップロードするURL
	 * @param file		アップロードするファイル
	 * @param fileSize	アップロードするファイルのサイズ
	 * @param range		これまでアップロードできた範囲
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
	
	//レスポンスヘッダの取得
	private String getHeader(HttpURLConnection uc){
		Map headers = uc.getHeaderFields();
		Iterator headerIt = headers.keySet().iterator();
		String header = null;
		while(headerIt.hasNext()){
			String headerKey = (String)headerIt.next();
			header += headerKey + "：" + headers.get(headerKey) + "\r\n";
		}
		return header;
	}
	public synchronized void sleep(long msec)
	{	//指定ミリ秒実行を止めるメソッド
		try
		{
			wait(msec);
		}catch(InterruptedException e){}
	}
}
