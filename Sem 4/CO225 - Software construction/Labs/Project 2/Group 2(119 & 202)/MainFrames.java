import javax.swing.*;
import java.io.IOException;

/**
 * Created by user on 12/25/2018.
 */
public class MainFrames {
    public static void main(String [] args) throws IOException {
        //Create and set up 2 windows.
        JFrame frame1 = new JFrame("BID ON STOCKS");
        JFrame frame2 = new JFrame("Client Details");

        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ReadCSV allowedUsers = new ReadCSV("stocksNew.csv","Symbol","Security Name","Price ");

        VisualServer server = new VisualServer(MainServer.BASE_PORT, allowedUsers);

        //Add contents to the window.
        frame1.add(new DisplayGUI(server));

        //Display the window.
        frame1.pack();
        frame1.setVisible(true);

        //Add contents to the window.
        frame2.add(new ClientGUI(server));

        //Display the window.
        frame2.pack();
        frame2.setVisible(true);

        server.server_loop();
    }
}
