import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import javax.swing.JComponent;
import javax.swing.Timer;
import javax.swing.JFrame;



class Mandelbrot extends JComponent implements ActionListener{

    public static final int WIDTH = 800;
    public static final int HEIGHT = 800;

    public static final float SCALE = 400;


    private float offset = 0;

    private BufferedImage bufIm;

    private Timer timer;

    //arguments for mandelbrot set
    public static double mx1;
    public static double mx2;
    public static double my1;
    public static double my2;
    public static int mitr;


    Mandelbrot(double x1,double x2,double y1,double y2,int itr) {
        mx1 = x1;
        mx2 = x2;
        my1 = y1;
        my2 = y2;
        mitr = itr;


        bufIm = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);
        timer = new Timer(1, this);

        mandelbrotSet();

        JFrame frame = new JFrame("Fractals");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(true);
        frame.getContentPane().add(this);
        frame.pack();
        frame.setVisible(true);

    }

    public void addNotify(){

        setPreferredSize(new Dimension(WIDTH,HEIGHT));
        timer.start();
    }
    // calculate whether the point in the mandelbrot set or not and set color
    public void mandelbrotSet(){
        for(int x = 0;x < WIDTH;x++){
            for(int y = 0;y < HEIGHT;y++){

                int color = 0;
                float newX,newY;
                newX = (x - WIDTH/2f)/SCALE;
                newY = (y - HEIGHT/2f)/SCALE;

                if(mx1 < newX && newX < mx2){
                    if(my1 < newY && newY < my2){
                        color = calMandelPoint((x - WIDTH/2f)/SCALE,(y - HEIGHT/2f)/SCALE);

                    }
                }

                bufIm.setRGB(x,y,color);
            }
        }



    }

    public int calMandelPoint(float x,float y){
        float cx = x;
        float cy = y;

        int i;

        for(i = 0;i < mitr;i++){
            float nx = x*x - y*y + cx;
            float ny = 2*x*y + cy;
            x = nx;
            y = ny;

            if((x*x + y*y) > 4){
                break;
            }
        }
        if(i == mitr){

            return Color.HSBtoRGB(((float) i/mitr+offset),0.01f,0.001f);
        }
        return Color.HSBtoRGB(((float)i/mitr + offset),1,1);
    }

    public void paint(Graphics g){

        g.drawImage(bufIm,0,0,null);
    }

    public void actionPerformed(ActionEvent e){
        offset += 0.001f;
        mandelbrotSet();
        repaint();
    }
}

class Julia extends JComponent implements ActionListener{

    public static final int WIDTH = 800;
    public static final int HEIGHT = 800;

    public static final float SCALE = 400;


    private float offset = 0;

    private BufferedImage bufIm;

    private Timer timer;

    public static double a;
    public static double b;
    public static int jitr;


    Julia(double a1,double b1,int itr) {

        a = a1;
        b = b1;
        jitr = itr;

        bufIm = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);
        timer = new Timer(1, this);

        juliaSet();

        JFrame frame = new JFrame("Fractals");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(true);
        frame.getContentPane().add(this);
        frame.pack();
        frame.setVisible(true);

    }

    public void addNotify(){

        setPreferredSize(new Dimension(WIDTH,HEIGHT));
        timer.start();
    }


    public void juliaSet(){
        for(int x=0;x< WIDTH;x++){
            for(int y=0;y<HEIGHT;y++){
                int color = calJuliaPoint((x-WIDTH/2f)/400,(y-HEIGHT/2f)/400);

                bufIm.setRGB(x,y,color);
            }
        }
    }
    public int calJuliaPoint(double x,double y) {

        int i = 0;
        for (; i < jitr; i++) {
            double cx = x * x - y * y + a;
            double cy = 2 * x * y + b;
            x = cx;
            y = cy;

            if (x * x + y * y > 4) {
                break;
            }
        }
        if(i== jitr){

            return Color.HSBtoRGB(((float) i/jitr+offset),0.01f,0.0001f);
        }
        else {
            return Color.HSBtoRGB(((float)i/jitr+offset),1f,1f);
        }

    }


    public void paint(Graphics g){

        g.drawImage(bufIm,0,0,null);
    }

    public void actionPerformed(ActionEvent e){
        offset += 0.001f;

        juliaSet();

        repaint();
    }
}

public class FractalsWithoutThread {

    public static void main(String[] args) {

        try {

            name = args[0];
            name = name.toLowerCase();
            if (name.equals("julia")) {
                mcheck = 1;
            } else if (name.equals("mandelbrot")) {
                jcheck = 1;
            } else {
                System.out.println("Enter mandelbrot or julia");
                return;
            }

            if (args.length == 1) {
                if (name.equals("julia")) {
                    // default real and imaginary values for constant and number of iterations
                    a = -0.4;
                    b = 0.6;
                    jitr = 1000;

                    jcheck = 1;

                    new Julia(a, b, jitr);
                } else if (name.equals("mandelbrot")) {
                    // default values
                    mx1 = -1;
                    mx2 = 1;
                    my1 = -1;
                    my2 = 1;
                    mitr = 1000;

                    mcheck = 1;

                    new Mandelbrot(mx1, mx2, my1, my2, mitr);
                }

            } else if (name.equals("julia")) {
                if (args.length == 3) {
                    try {
                        a = Double.parseDouble(args[1]);
                    } catch (Exception e) {
                    }
                    try {
                        b = Double.parseDouble(args[2]);
                    } catch (Exception e) {
                    }
                    jitr = 1000;
                    new Julia(a, b, jitr);

                    jcheck = 1;
                }
            } else if (name.equals("mandelbrot")) {
                if (args.length == 5) {
                    try {
                        mx1 = Double.parseDouble(args[1]);
                    } catch (Exception e) {
                    }
                    try {
                        mx2 = Double.parseDouble(args[2]);
                    } catch (Exception e) {
                    }
                    try {
                        my1 = Double.parseDouble(args[3]);
                    } catch (Exception e) {
                    }
                    try {
                        my2 = Double.parseDouble(args[4]);
                    } catch (Exception e) {
                    }
                    mitr = 1000;
                    new Mandelbrot(mx1, mx2, my1, my2, mitr);

                    mcheck = 1;
                }
            }
            if (jcheck == 0) {
                //System.out.println("a");
                try {
                    a = Double.parseDouble(args[1]);
                } catch (Exception e) {
                }
                try {
                    b = Double.parseDouble(args[2]);
                } catch (Exception e) {
                }
                try {
                    jitr = Integer.parseInt(args[3]);
                } catch (Exception e) {
                }

                System.out.println(a);
                new Julia(a, b, jitr);
            }

            if (mcheck == 2) {

                try {
                    mx1 = Double.parseDouble(args[1]);
                } catch (Exception e) {
                }
                try {
                    mx2 = Double.parseDouble(args[2]);
                } catch (Exception e) {
                }
                try {
                    my1 = Double.parseDouble(args[3]);
                } catch (Exception e) {
                }
                try {
                    my2 = Double.parseDouble(args[4]);
                } catch (Exception e) {
                }
                try {
                    mitr = Integer.parseInt(args[5]);
                } catch (Exception e) {
                }

                new Mandelbrot(mx1, mx2, my1, my2, mitr);
            }
        }catch (Exception e){
            System.out.println("Wrong input");
        }

    }

    public static String name;

    // input arguments for mandelbrot
    public static double mx1;
    public static double mx2;
    public static double my1;
    public static double my2;
    public static int mitr;

    // input argument for julia
    public static double a;
    public static double b;
    public static int jitr;

    public static int mcheck = 2;
    public static int jcheck = 0;

}



