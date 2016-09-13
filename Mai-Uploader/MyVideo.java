import java.io.File;
import java.io.IOException;

public class MyVideo{
	MyVideo(){
		initFile("/temp");
	}
	
	//ファイルもしくはフォルダの初期化
	private boolean initFile(String path){
		File newFile = new File(path);
		try{
			if(newFile.createNewFile()){
				return true;
			}else{
				return false;
			}
		}catch(IOException e){
			System.out.println(e);
			return false;
		}
	}
	
	public boolean remove(String removedpath){
		File file1 = new File(removedpath);
		File file2 = new File("/temp");
		try{
			if(file1.renameTo(file2)){
				return true;
			}else{
				return false;
			}
		}catch(SecurityException e){
			System.out.println(e);
			return false;
		}catch(NullPointerException e){
			System.out.println(e);
			return false;
		}
	}
}