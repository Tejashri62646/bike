
import java.net.*;

public class UDPServer {
    public static void main(String[] args) {

        int port = 8081;

        try (DatagramSocket serverSocket = new DatagramSocket(port)) {

            System.out.println("[UDP Server] Listening on port " + port + "...");

            byte[] receiveBuffer = new byte[1024];

            DatagramPacket receivePacket =
                new DatagramPacket(receiveBuffer, receiveBuffer.length);

            serverSocket.receive(receivePacket);

            String receivedMessage = new String(
                receivePacket.getData(),
                0,
                receivePacket.getLength()
            );

            System.out.println("[UDP Server] Received: " + receivedMessage);

            String reply = "ACK from UDP Java Server!";

            byte[] sendBuffer = reply.getBytes();

            InetAddress clientAddress = receivePacket.getAddress();
            int clientPort = receivePacket.getPort();

            DatagramPacket sendPacket = new DatagramPacket(
                sendBuffer,
                sendBuffer.length,
                clientAddress,
                clientPort
            );

            serverSocket.send(sendPacket);

            System.out.println("[UDP Server] Reply sent.");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
