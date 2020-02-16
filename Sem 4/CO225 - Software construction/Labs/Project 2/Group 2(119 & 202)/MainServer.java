import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Map;


public class MainServer {

    /* Some constants */
    public static final int BASE_PORT = 2000;  // do not change


    /* local data for the server
     * Every main server is defined in terms of the port it
     * listens and the database of allowed users
     */
    private ServerSocket serverSocket=null;  // server Socket for main server
    private ReadCSV allowedUsers=null;     // who are allowed to chat

    public MainServer(int socket, ReadCSV users) {
        this.allowedUsers = users;

        try {
            this.serverSocket = new ServerSocket(socket);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    /* each server will provide the following functions to
     * the public. Note that these are non-static
     */
    public boolean isAuthorized(String symbol) {
     return this.allowedUsers.findName(symbol) != null;
    }

    public String isPriceHigh(String symbol) {
        return this.allowedUsers.findPrice(symbol);
    }

    public void newPrice(String symbol,String newPrice){
        this.allowedUsers.updatePrice(symbol,newPrice);
    }


    /* server will define how the messages should be posted
     * this will be used by the connection servers
     */

    public void postMSG(String msg) {
        // all threads print to same screen
       System.out.println(msg);
    }

    public void postMSGClient(String msg){
        System.out.println(msg);
    }


    public Map<String,String> postList(){
      return this.allowedUsers.symbolPrice();
    }
   public Map<String,String> postList1(){
        return this.allowedUsers.symbolSecurity();
    }

    public String authorizedOnce(String a) {
        // need to implement this.
        return null;
    }

    public void server_loop() {
        try {
            while(true) {
                Socket socket = this.serverSocket.accept();
                ConnectionServer worker = new ConnectionServer(this);
                worker.handleConnection(socket);
            }
        } catch(IOException e) {
            System.out.println(e);
        }
    }// end server_loop
}







