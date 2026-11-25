
import java.net.*;

public class UDPClient {
    public static void main(String[] args) {

        String host = "127.0.0.1";
        int port = 8081;

        try (DatagramSocket clientSocket = new DatagramSocket()) {

            InetAddress serverAddress = InetAddress.getByName(host);

            String message = "Hello UDP Java Server!";

            byte[] sendBuffer = message.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(
                sendBuffer,
                sendBuffer.length,
                serverAddress,
                port
            );

            clientSocket.send(sendPacket);

            System.out.println("[UDP Client] Message sent.");

            byte[] receiveBuffer = new byte[1024];

            DatagramPacket receivePacket =
                new DatagramPacket(receiveBuffer, receiveBuffer.length);

            clientSocket.receive(receivePacket);

            String response = new String(
                receivePacket.getData(),
                0,
                receivePacket.getLength()
            );

            System.out.println("[UDP Client] Received: " + response);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
