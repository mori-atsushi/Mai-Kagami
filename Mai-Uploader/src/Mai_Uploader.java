
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
	public static void main(String[] args) {
		MyYouTube myYoutube = new MyYouTube();
		
		while(true){
			//videoフォルダが空フォルダじゃなくなるまでループ
			File video = new File("./video");
			//videoフォルダに入っているファイルのリスト
			String[] fileList = video.list();
			while(fileList.length == 0){
				fileList = video.list();
				myYoutube.sleep(5000);
			}
			myYoutube.sleep(5000);
			
			try {
				//ファイルに情報を追加する
				myYoutube.setMetadata(
						fileList[0],
						"Mai_Uploader test upload on " + Calendar.getInstance().getTime(),
						"Mai_Uploader test upload on " + Calendar.getInstance().getTime()
						);
				new File(fileList[0]).delete();
				myYoutube.sleep(5000);
			} catch (Exception e) {
				e.printStackTrace();
				System.exit(0);
			}
		}
 	}
}