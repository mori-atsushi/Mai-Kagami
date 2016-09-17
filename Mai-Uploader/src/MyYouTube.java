import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.List;

import com.google.api.client.auth.oauth2.Credential;
import com.google.api.client.extensions.java6.auth.oauth2.AuthorizationCodeInstalledApp;
import com.google.api.client.extensions.jetty.auth.oauth2.LocalServerReceiver;
import com.google.api.client.googleapis.auth.oauth2.GoogleAuthorizationCodeFlow;
import com.google.api.client.googleapis.auth.oauth2.GoogleClientSecrets;
import com.google.api.client.googleapis.json.GoogleJsonResponseException;
import com.google.api.client.googleapis.media.MediaHttpUploader;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.http.InputStreamContent;
import com.google.api.client.http.javanet.NetHttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.store.FileDataStoreFactory;
import com.google.api.services.youtube.YouTube;
import com.google.api.services.youtube.model.Video;
import com.google.api.services.youtube.model.VideoSnippet;
import com.google.api.services.youtube.model.VideoStatus;
import com.google.common.collect.Lists;

import net.arnx.jsonic.JSON;

public class MyYouTube {
	//URL
	private static final String TOKEN_URL = "https://accounts.google.com/o/oauth2/token";
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
}
