package com.example.kousukenezu.mai_kagamilogin;

import java.util.concurrent.Executors;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class UsbMessage {
    private int mPort;  // ポート番号
    String data; // 送信用データ
    static boolean mode_read = true;  // 読み取りモードならtrue
    MainActivity mainActivity;
    ServerSocket serverSocket;
    Socket clientSocket;

    public void setMainActivity(MainActivity mainActivity){
        this.mainActivity = mainActivity;
    }

    /* 送信用スレッド */
    private final Runnable mSendTask = new Runnable() {
        public void run() {
            if (mode_read) {
                try {
                    ServerSocket serverSocket = new ServerSocket(mPort);  // サーバ側のソケット
                    Socket clientSocket = serverSocket.accept();
                    if(clientSocket.isConnected()) {
                        final PrintStream os = new PrintStream(clientSocket.getOutputStream());
                        os.println(data);  // データ送信
                    }
                    serverSocket.close();
                    clientSocket.close();  // ソケットの後処理
                } catch (IOException e) {
                }
                mode_read = true;
            }
        }
    };

    UsbMessage(int port) {
        mPort = port;
    }

    // 送信用スレッドを起動する
    public void sendData(String d) {
        if(mode_read) {
            data = d;
            Executors.newSingleThreadExecutor().execute(mSendTask);
        }
    }
}