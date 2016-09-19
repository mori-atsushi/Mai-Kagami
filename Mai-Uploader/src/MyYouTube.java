import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.Iterator;
import java.util.Map;

import net.arnx.jsonic.JSON;

public class MyYouTube {
	//アクセストークン取得のためのURL
	private static final String TOKEN_URL = "https://accounts.google.com/o/oauth2/token";
	//アップロードのためのURL
	private static final String UPLOAD_URL = " https://www.googleapis.com/youtube/v3/videos";
	//client_id
	private final String CONSUMER_KEY = "707601956964-gojtq9hq7h6qt751k973lprdh8ts20rv.apps.googleusercontent.com";
	//client_secrets
	private final String CONSUMER_SECRET = "or07nBfMB3qafJ_T9bdK4Fgu";
	//refresh_token
	private final String REFRESH_TOKEN = "1/BoOZShXB3j0jr5-jiI2NQVA0RE6-nICyixzdVZg4nCw";
	//access_token
	private String access_token = null;
	private String token_type = null;
	private String expires_in = null;
	
	MyYouTube(){
		try{
			URL url = new URL(TOKEN_URL);
            URLConnection uc = url.openConnection();
            uc.setDoOutput(true);
            
            OutputStream os = uc.getOutputStream();
        
            String postStr = 
            	"grant_type=refresh_token&" + 
            	"refresh_token="+ REFRESH_TOKEN + 
            	"&client_id=" + CONSUMER_KEY + 
            	"&client_secret=" + CONSUMER_SECRET;
            System.out.println(url + postStr);
            PrintStream ps = new PrintStream(os);
            ps.print(postStr);
            ps.close();

            InputStream is = uc.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(is));
            String json = null;
            String s = null;
            while ((s = reader.readLine()) != null) {
            	json += s;
            }
            reader.close();
            Code code = JSON.decode(json.substring(json.indexOf("{")), Code.class);
            System.out.println(code.getAccess_token());
            access_token = code.getAccess_token();
            System.out.println(code.getToken_type());
            token_type = code.getToken_type();
            System.out.println(code.getExpires_in());
            expires_in = code.getExpires_in();
		} catch (MalformedURLException e) {
            System.err.println("Invalid URL format: " + TOKEN_URL);
            System.exit(-1);
        } catch (IOException e) {
        	System.out.println(e);
            System.err.println("Can't connect to " + TOKEN_URL);
            System.exit(-1);
        }
	}
	HttpURLConnection uc;
	public void setMetadata(
			File video, String title, String description){
		try {
			URL url = new URL("https://www.googleapis.com/upload/youtube/v3/videos?uploadType=resumable&part=snippet,status,contentDetails&key=AIzaSyDEgkuehdEK_kh0gEw6-3c-8WwcIS2i0nI");
			String sentJson = "{\"snippet\": {\"title\": \"" + title + "\",\"description\": \"" + description + "\"},\"status\": {\"privacyStatus\": \"public\",\"embeddable\": \"True\",\"license\": \"youtube\"}}";
			System.out.println(sentJson);
			uc = (HttpURLConnection) url.openConnection();
			// キャッシュを使用しない
			uc.setUseCaches(false);
			uc.setDoOutput(true);
			uc.setRequestMethod("POST");
     
			uc.setRequestProperty("HOST", "www.googleapis.com");
			uc.setRequestProperty("Authorization", token_type + " " + access_token);
			uc.setRequestProperty("Content-Length", String.valueOf(sentJson.length()));
			uc.setRequestProperty("Content-Type", "application/json; charset=UTF-8");
			uc.setRequestProperty("X-Upload-Content-Length", String.valueOf(video.length()));
			uc.setRequestProperty("X-upload-content-type", "video/avi");
		
			
			OutputStream os = uc.getOutputStream();	
			PrintStream ps = new PrintStream(os);
			ps.print(sentJson);
			ps.close();
			
			URL url2 = new URL(uc.getHeaderField("location"));
			System.out.println(uc.getHeaderField("location"));
		}catch(MalformedURLException e){
			System.err.println("Invalid URL format: " + UPLOAD_URL);
			e.printStackTrace();
		} catch (IOException e) {
			InputStream is = uc.getErrorStream();
			BufferedReader reader = new BufferedReader(new InputStreamReader(is));
			String json = null;
			String s = null;
			if(is != null){
				try {
					while((s = reader.readLine()) != null){
						System.out.println(s);
					}
				} catch (IOException e1) {
					// TODO 自動生成された catch ブロック
					e1.printStackTrace();
				}
			}
		}
	}
	
	public synchronized void sleep(long msec)
	{	//指定ミリ秒実行を止めるメソッド
		try
		{
			wait(msec);
		}catch(InterruptedException e){}
	}
}
