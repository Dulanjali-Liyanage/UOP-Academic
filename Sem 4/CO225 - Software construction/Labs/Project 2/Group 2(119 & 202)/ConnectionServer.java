import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.*;

class ConnectionServer implements Runnable {
    // some constants
    public static final int WAIT_AUTH = 0;
    public static final int AUTH_DONE = 1;
    public static final int MSG_DONE = 2;
    final int CHECK = 3;//check the name of client

    int y = 0;//identify changes done by same client


    public static final String WAIT_AUTH_MSG = "Name pls!\n";
    public static final String AUTH_DONE_MSG = "Bid Symbol: \n";
    public static final String MSG_POSTED    = "Your bid posted\n";
    public static final String MSG = "\n";

    // per connection variables
    private Socket mySocket; // connection socket per thread
    private int currentState;
    private String clientName;
    private String clientPrice;
    private String clientSymbol;
    private MainServer mainServer;
    private String currentPrice;


    public static ArrayList<String> clientDetails = new ArrayList<String>();//details of all the clients
    ArrayList<String> details = new ArrayList<String>();//details of only one client

    public ConnectionServer(MainServer mainServer) {
        this.mySocket = null; // we will set this later
        this.currentState = WAIT_AUTH;
        this.clientName = null;
        this.clientSymbol = null;
        this.mainServer = mainServer;
        // who created me. He should give some interface
    }

    public boolean handleConnection(Socket socket) {
        this.mySocket = socket;
        Thread newThread = new Thread(this);
        newThread.start();
        return true;
    }


    public void run() { // can not use "throws .." interface is different
        BufferedReader in = null;
        PrintWriter out = null;

        try {
            in = new
                    BufferedReader(new InputStreamReader(mySocket.getInputStream()));
            out = new
                    PrintWriter(new OutputStreamWriter(mySocket.getOutputStream()));


            String line;

            Map<String,String> cc = mainServer.postList();//classList1
            Map<String,String> ee = mainServer.postList1();//classList


            //print the initial prices
            mainServer.postMSG("Initial Prices\n*********************");

            Set s1 = cc.keySet();
            Set w1 = ee.keySet();
            Iterator p = s1.iterator();
            Iterator q = w1.iterator();
            while (p.hasNext() && q.hasNext()){
                String key1 = (String) p.next();
                String value1 = (String)cc.get(key1);

                String key2 = (String) q.next();
                String value2 = (String)ee.get(key2);

                mainServer.postMSG(value2 + "  :  " + key1 + "  :  " + value1);
            }

            mainServer.postMSG("************\n\n\n");

            for(line = in.readLine();
                line != null && !line.equals("quit");
                line = in.readLine()) {


                switch(currentState) {
                    case WAIT_AUTH:

                        out.print(WAIT_AUTH_MSG);
                        currentState = CHECK;

                        break;
                    case CHECK:
                        clientName = line;

                        details.add(clientName);

                        currentState = AUTH_DONE;
                        out.print(AUTH_DONE_MSG);
                        break;
                    /*****************************/
                    case AUTH_DONE:
                        clientSymbol = line;

                        if(mainServer.isAuthorized(line)) {
                            currentState = MSG_DONE;
                            out.print(mainServer.isPriceHigh(clientSymbol));
                            out.print(MSG);
                            details.add(clientSymbol);
                        }else{
                            out.print(-1);
                            out.print(MSG);
                        }

                        break;

                    case MSG_DONE:
                        clientPrice = line;
                        currentPrice = mainServer.isPriceHigh(clientSymbol);



                        if(y == 0){
                            details.add(clientPrice);
                            details.add(java.time.LocalTime.now().toString());
                            y = 1;
                        }else{
                            details.remove(details.get(2));
                            details.add(clientPrice);
                            details.add(java.time.LocalTime.now().toString());//bid time
                        }

                        if(new Double(clientPrice).doubleValue() > new Double(currentPrice).doubleValue()){
                            mainServer.newPrice(clientSymbol,clientPrice);
                        }

                        Map<String,String> bb = mainServer.postList();//classList1
                        Map<String,String> dd = mainServer.postList1();//classList

                        //print the updated prices
                        mainServer.postMSG("New Prices\n*********************");

                        Set s = bb.keySet();
                        Set w = dd.keySet();
                        Iterator i = s.iterator();
                        Iterator k = w.iterator();
                        while (i.hasNext() && k.hasNext()){
                            String key1 = (String) i.next();
                            String value1 = (String)bb.get(key1);

                            String key2 = (String) k.next();
                            String value2 = (String)dd.get(key2);

                            mainServer.postMSG(value2 +"  :  " + key1 + "  :  " + value1);
                        }
                        mainServer.postMSG("************\n\n\n");

                        out.print(MSG_POSTED);


                        //add all the details of client
                        clientDetails.add(details.get(0));
                        clientDetails.add(details.get(1));
                        clientDetails.add(details.get(2));
                        clientDetails.add(details.get(3));

                        int x = 0;//client name,symbol,bid price,bid time

                        //post the details in a separate window
                        for(String g: clientDetails){
                            mainServer.postMSGClient(g);
                            x++;
                            if(x == 4){
                                mainServer.postMSGClient(MSG);
                                x = 0;
                            }
                        }
                        mainServer.postMSGClient("New Client List\n**********************************\n\n");

                        break;

                    default:
                        System.out.println("Undefined state");
                        return;
                } // case

                out.flush(); // flush to network

            } // for

            // close everything
            out.close();
            in.close();
            this.mySocket.close();
        } // try
        catch (IOException e) {
            System.out.println(e);
        }
    }
}




