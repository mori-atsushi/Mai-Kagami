import java.io.*;
import java.net.*;
import java.io.IOException.*;

public class Nfc{
	public static void main(String[] args){
		System.out.println("接続待機中です");
		try{
			ServerSocket serverSocket = new ServerSocket(9999);
			Socket clientSocket = serverSocket.accept();
			System.out.println("接続に成功しました");
			try{
				final PrintStream os = new PrintStream(clientSocket.getOutputStream());
				System.out.println("idを入力してください");
				String data = new java.util.Scanner(System.in).next();
				char[] charArray = data.toCharArray();
				os.println(charArray);
				System.out.println("送信しました");
				serverSocket.close();
				clientSocket.close();
			}catch(Exception e){
				System.out.println("送信に失敗しました");
				System.exit(0);
			}
		}catch(Exception e){
			System.out.println("接続に失敗しました");
		}
	}
}