import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
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

public class MyYouTube implements Runnable{
	/** HTTP通信のインスタンス */
	private static final HttpTransport HTTP_TRANSPORT = new NetHttpTransport();
	
	/** JSを扱うためのインスタンス　Global instance of the JSON factory. */
	private static final JsonFactory JSON_FACTORY = new JacksonFactory();

	/** リクエストを作るインスタンス */
	private static YouTube youtube;

	/* Global instance of the format used for the video being uploaded (MIME type). */
	private static String VIDEO_FILE_FORMAT = "video/*";
	
	private File uploadedFile;
	
	private Video videoObjectDefiningMetadata;
	
	MyYouTube() throws Exception{
		//"https://www.googleapis.com/auth/youtube.upload"をscopesに入れている
		List<String> scopes = Lists.newArrayList("https://www.googleapis.com/auth/youtube.upload");
		try {
		      // 証明書
		      Credential credential = authorize(scopes);
		      
		      // youtubeオブジェクトはすべてのapiリクエストを作成する
		      youtube = new YouTube.Builder(HTTP_TRANSPORT, JSON_FACTORY, credential).setApplicationName(
		          "Mai_Uploader").build();
		} catch (GoogleJsonResponseException e) {
			System.err.println("GoogleJsonResponseException code: " + e.getDetails().getCode() + " : "
					+ e.getDetails().getMessage());
			e.printStackTrace();
		}
	}
	
	/**
	 * Authorizes the installed application to access user's protected data.
	 *
	 * @param scopes youtubeのアップロードに必要なscopeのリスト
	 */
	private static Credential authorize(List<String> scopes) throws Exception {

		// client_secrets.jsonを読み込む
		GoogleClientSecrets clientSecrets = GoogleClientSecrets.load(
	    	JSON_FACTORY, new FileReader("client_secrets.json"));
	    
	    // ファイルが書き換えられてないかチェック　Checks that the defaults have been replaced (Default = "Enter X here").
	    if (clientSecrets.getDetails().getClientId().startsWith("Enter")
	        || clientSecrets.getDetails().getClientSecret().startsWith("Enter ")) {
	    	System.out.println(
	    		"Enter Client ID and Secret from https://code.google.com/apis/console/?api=youtube"
	    			+ "into youtube-cmdline-uploadvideo-sample/src/main/resources/client_secrets.json");
	    	System.exit(1);
	    }
	    
	    // 証明書を発行　Set up file credential store.
	    FileDataStoreFactory fdsf = new FileDataStoreFactory(
	    		new File(/*System.getProperty("user.home"), ".credentials/youtube-api-uploadvideo.json"*/".\\credentials\\"));
	    
	    // 認証コードの流れを設定します　Set up authorization code flow.
	    GoogleAuthorizationCodeFlow flow = new GoogleAuthorizationCodeFlow.Builder(
	        HTTP_TRANSPORT, JSON_FACTORY, clientSecrets, scopes).setDataStoreFactory(fdsf)
	        .build();

	    // ローカルサーバーを立ての9000のポートにバインド Build the local server and bind it to port 9000
	    LocalServerReceiver localReceiver = new LocalServerReceiver.Builder().setPort(8080).build();

	    // 認証
	    //.authorize()の引数には何をいれたらいい？
	    return new AuthorizationCodeInstalledApp(flow, localReceiver).authorize("maikagami2016@gmail.com");
	}
	
	/*
	 * 動画に情報を付加する
	 * 	file         -アップロードする動画ファイルの場所
	 * 	title        -動画のタイトル　デフォルトは"Test title"
	 * 	description  -動画につける説明　デフォルトは"Test description"
	 * 	category     -動画に関連するカテゴリid 	デフォルトは"22"
	 * 	keywords     -動画に関連するキーワードをコンマで区切ったリスト 今回は関係なし
	 *  privateStatus-動画のプライバシ―ステータス public(公開),private(非公開),unlisted(限定公開)が有効値　今回はunlistedを使用
	 */
	
	//アップロードする動画をセットする
	public boolean setVideo(File file) {
		if(isMp4(file)){ return false; }
		uploadedFile = file;
		return true;
	}
	
	//ファイルがmp4ファイルかチェックする
	public boolean isMp4(File file){
		return file.isFile() && file.canRead() && file.getPath().endsWith(".avi");
	}
	
		
	public void setMetadata(
			String title, String description){
		this.videoObjectDefiningMetadata = new Video();
		
		//公開するなら"public"、今回は"unlisted"を使用(リンクを知っている人しか見れない)
		VideoStatus status = new VideoStatus();
		status.setPrivacyStatus("unlisted");
		videoObjectDefiningMetadata.setStatus(status);
		
		// メタデータ(動画に関係するデータ)を設定するオブジェクト
    	VideoSnippet snippet = new VideoSnippet();
    	
    	//タイトルを設定
    	snippet.setTitle(title);
    	//動画に関する説明を設定
    	snippet.setDescription(description);
    	
    	// メタデータ完成
    	videoObjectDefiningMetadata.setSnippet(snippet);
    	
    	run();
	}
	//アップロード用スレッド
	@Override
	public void run(){
		try{
			InputStreamContent mediaContent = new InputStreamContent(
					VIDEO_FILE_FORMAT, new BufferedInputStream(new FileInputStream(this.uploadedFile)));
			mediaContent.setLength(this.uploadedFile.length());
        	
			/*
			 * ここでyoutubeに動画をアップロード
			 * The upload command includes: 1. Information we want returned after file is successfully
			 * uploaded. 2. Metadata we want associated with the uploaded video. 3. Video file itself.				 
			 */
			
			YouTube.Videos.Insert videoInsert = youtube.videos()
					.insert("snippet,statistics,status", videoObjectDefiningMetadata, mediaContent);
			// Set the upload type and add event listener.
	    	MediaHttpUploader uploader = videoInsert.getMediaHttpUploader();
	    	/*
	    	 * Sets whether direct media upload is enabled or disabled. True = whole media content is
	    	 * uploaded in a single request. False (default) = resumable media upload protocol to upload
	    	 * in data chunks.
	    	 */
	    	uploader.setDirectUploadEnabled(false);
	    	// Execute upload.
	    	Video returnedVideo = videoInsert.execute();
	    	// Print out returned results.
	    	System.out.println("\n================== Returned Video ==================\n");
	    	System.out.println("  - Id: " + returnedVideo.getId());
	    	System.out.println("  - Title: " + returnedVideo.getSnippet().getTitle());
	    	System.out.println("  - Tags: " + returnedVideo.getSnippet().getTags());
	    	System.out.println("  - Privacy Status: " + returnedVideo.getStatus().getPrivacyStatus());
	    	System.out.println("  - Video Count: " + returnedVideo.getStatistics().getViewCount());
		}catch(FileNotFoundException e){
			System.out.println(e);
		}catch(IOException e){
			System.out.println(e);
		} catch (Throwable t) {
    		System.err.println("Throwable: " + t.getMessage());
    		t.printStackTrace();
    	}
	}
}
