
import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {

        String host = "127.0.0.1";
        int port = 9090;

        try (Socket socket = new Socket(host, port)) {

            PrintWriter out = new PrintWriter(
                socket.getOutputStream(), true
            );

            out.println("Hello TCP Java Server!");

            System.out.println("[TCP Client] Message sent.");

            BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            );

            String response = in.readLine();

            System.out.println("[TCP Client] Received: " + response);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
