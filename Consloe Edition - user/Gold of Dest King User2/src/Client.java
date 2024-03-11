import javax.swing.*;
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        int i = 5;
        while (i !=0){
            try {
                Socket socket = new Socket("127.0.0.1", 12345);
                System.out.println("连接服务器成功！");

                // 发送test.txt文件
                OutputStream outputStream = socket.getOutputStream();
                FileInputStream fileInputStream = new FileInputStream("test.txt");
                byte[] buffer = new byte[8192];
                int bytesRead;
                while ((bytesRead = fileInputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                }
                System.out.println("文件发送成功！");
                fileInputStream.close();

                outputStream.close();

                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 等待1秒
            try {
                Thread.sleep(1000);
            } catch (Exception e){
                System.exit(0);
            }
            i --;
        }

    }
}
