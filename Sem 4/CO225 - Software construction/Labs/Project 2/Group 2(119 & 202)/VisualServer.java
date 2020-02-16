import java.util.*;

class VisualServer extends MainServer {
    private static LinkedList<String> msgs;//to get bid details
    private static LinkedList<String> msg;//to get client details

    public VisualServer(int socket, ReadCSV user) {
        super(socket, user);
        msgs = new LinkedList<String>();
        msg = new LinkedList<String>();
    }

    //@Override
    public synchronized void postMSG(String str) {
        // I can override and make function synchronized
        msgs.add(str);
    }

    //for client details
   public synchronized void postMSGClient(String str) {
        // I can override and make function synchronized
        msg.add(str);
    }


    public String getMSG() {
        if(!msgs.isEmpty()) return msgs.remove();
        return null;
    }

    //for client details
    public String getMSGClient() {
        if(!msg.isEmpty()) return msg.remove();
        return null;
    }
}