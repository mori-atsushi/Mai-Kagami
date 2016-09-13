import java.io.File;
import java.io.IOException;
import java.nio.file.*;
import java.nio.file.WatchEvent.Kind;
import java.util.concurrent.TimeUnit;

public class DirMonitor extends Thread{
	//監視先のパス
	private String dirName;
	//待機時間(s)
	private int waitCnt = 10;
	private MyVideo myVideo;
	/*
	 * コンストラクタ
	 * path:監視先のパス
	 */
	DirMonitor(String path){
		this.dirName = path;
		myVideo = new MyVideo();
	}
	
	@Override
	public void run(){
		Path dirPath = new File(dirName).toPath();
		FileSystem fs = dirPath.getFileSystem();
		try(WatchService watcher = fs.newWatchService()){
			
			//ディレクトリに対して監視サービスを登録する
			 WatchKey watchKey = dirPath.register(watcher, new Kind[]{
					 StandardWatchEventKinds.ENTRY_CREATE, // 作成
			 } ); // オプションの修飾子、不要ならば空配列
			 
			 // 監視が有効であるかぎり、ループする.
			 // (監視がcancelされるか、監視サービスが停止した場合はfalseとなる)
			 while(watchKey.isValid()){
				 try{
                     // スレッドの割り込み = 終了要求を判定する.
                     if (Thread.currentThread().isInterrupted()) {
                         throw new InterruptedException();
                     }
                     
                     // ファイル変更イベントが発生するまで待機する.
                     WatchKey detecedtWatchKey = watcher.poll(500, TimeUnit.MILLISECONDS);
                     if (detecedtWatchKey == null) {
                         // タイムアウト
                         continue;
                     }
                     
                     if(detecedtWatchKey.equals(watchKey)){
                    	 //追加されたファイルを取得し.remove()を実行する
                    	 for(@SuppressWarnings("rawtypes") WatchEvent event : detecedtWatchKey.pollEvents()){
                    		 Path file = (Path)event.context();
                    		 myVideo.remove(file.toString());
                    	 }
                     }
                     
                     // イベントのハンドリングに時間がかかるケースを
                     // Sleepでエミュレートする.
                     // (この間のファイル変更イベントを取りこぼすか否かを確かめられる)
                     for (int cnt = 0; cnt < waitCnt; cnt++) {
                         Thread.sleep(1000);
                     }
                     
                     //イベントの受付を再開する
                     detecedtWatchKey.reset();
				 }catch(InterruptedException e){
					 watchKey.cancel();
				 }
			 }
		} catch (RuntimeException | IOException e) {
			e.printStackTrace();
		}
	}
}
