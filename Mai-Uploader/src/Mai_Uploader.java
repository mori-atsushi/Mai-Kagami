
import java.io.File;
import java.util.Calendar;

/*
 * 参考ページ
 *  https://developers.google.com/youtube/v3/code_samples/java?hl=ja#upload_a_video 
 */

/*
 * ファイル監視~youtubeアップロードまでのプロセスの説明をします
 * 1.tempフォルダを空フォルダにする
 * 2.videoフォルダを監視(dirMonitor.start())。ファイルが追加されたらtempに移動
 * 3.mainクラスでtempフォルダを監視。
 * 4.tempが空フォルダじゃなくなったらそのファイルのアップロードにうつる
 * 5．アップロードが終わったらそのファイルを消し1に戻る(2については常に動いている)
 */

public class Mai_Uploader {
	//処理をループさせるときの周期(秒)
	private static int waittime = 10;
	public static void main(String[] args) {
		MyYouTube myYoutube = new MyYouTube();
		
//		while(true){
//			MyVideo myVideo = new MyVideo();
//			
//			//videoフォルダが空フォルダじゃなくなるまでループ
//			File video = new File("./video");
//			while(video.length() == 0){	}
//			
//			//videoフォルダに入っているファイルのリスト
//			File[] fileList = video.listFiles();
//		
//			try {
//				
//				//アップロードするファイルを追加				
//				if(!myYoutube.setVideo(new File(fileList[0]))) continue;
//				
//				//ファイルに情報を追加する
//				myYoutube.setMetadata(
//						"Mai_Uploader test upload on "  + Calendar.getInstance().getTime(),
//						"舞鏡の動画のテストアップロード " + "on " + Calendar.getInstance().getTime()
//						);
//			} catch (Exception e) {
//				e.printStackTrace();
//			}
//		}
 	}
}