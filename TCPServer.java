
import java.io.*;
import java.net.*;

public class TCPServer {
    public static void main(String[] args) {

        int port = 9090;

        try (ServerSocket serverSocket = new ServerSocket(port)) {

            System.out.println("[TCP Server] Listening on port " + port + "...");

            Socket clientSocket = serverSocket.accept();

            System.out.println("[TCP Server] Client connected.");

            BufferedReader in = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream())
            );

            String receivedMessage = in.readLine();

            System.out.println("[TCP Server] Received: " + receivedMessage);

            PrintWriter out = new PrintWriter(
                clientSocket.getOutputStream(), true
            );

            out.println("ACK from TCP Java Server!");

            System.out.println("[TCP Server] Reply sent.");

            clientSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
