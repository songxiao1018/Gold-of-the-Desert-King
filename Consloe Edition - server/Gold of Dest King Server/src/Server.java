import java.io.*;
import java.net.*;
//import com.fasterxml.jackson.databind.Objec/tMapper;

public class Server {
    public static <ObjectMapper, User> void main(String[] args) {
        try {
            // 创建ServerSocket对象，监听指定端口号
            ServerSocket serverSocket = new ServerSocket(8888);
            System.out.println("服务器已启动，等待客户端连接...");

            // 等待客户端连接
            Socket clientSocket = serverSocket.accept();
            System.out.println("客户端连接成功！");

            // 创建数据输入流和输出流
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));

            // 读取客户端发送的消息
            String jsonString = in.readLine();
            System.out.println("客户端发送的JSON字符串：" + jsonString);

            // 解析JSON字符串为Java对象
            ObjectMapper objectMapper = new ObjectMapper();
            User user = objectMapper.readValue(jsonString, User.class);
            System.out.println("客户端发送的User对象：");
            System.out.println("Name: " + user.getName());
            System.out.println("Age: " + user.getAge());

            // 向客户端发送消息
            out.write("已收到User对象！\n");
            out.flush();

            // 关闭连接
            in.close();
            out.close();
            clientSocket.close();
            serverSocket.close();
            System.out.println("连接已关闭。");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}