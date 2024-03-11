import java.io.*;
import java.net.*;
//import com.fasterxml.jackson.databind.ObjectMapper;

public class Client {
    public static void main(String[] args) {
        try {
            // 创建Socket对象，指定服务器地址和端口号
            Socket socket = new Socket("A电脑的IP地址", 8888);
            System.out.println("已连接服务器！");

            // 创建数据输入流和输出流
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            // 创建一个复杂的JSON对象（User对象）
            User user = new User("John Doe", 25);

            // 将User对象转换为JSON字符串
            ObjectMapper objectMapper = new ObjectMapper();
            String jsonString = objectMapper.writeValueAsString(user);
            System.out.println("发送的JSON字符串：" + jsonString);

            // 向服务器发送JSON字符串
            out.write(jsonString + "\n");
            out.flush();

            // 读取服务器发送的消息
            String message = in.readLine();
            System.out.println("服务器发送的消息：" + message);

            // 关闭连接
            in.close();
            out.close();
            socket.close();
            System.out.println("连接已关闭。");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

// User类示例
class User {
    private String name;
    private int age;

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}