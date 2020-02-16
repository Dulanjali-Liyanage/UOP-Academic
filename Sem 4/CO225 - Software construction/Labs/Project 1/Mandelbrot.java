import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import javax.swing.JComponent;
import javax.swing.Timer;
import javax.swing.JFrame;
import java.awt.event.*;


class Zoom extends MouseAdapter implements MouseListener{
    double m;
    double n;

    public void mousePressed(MouseEvent e) {
        m = MouseInfo.getPointerInfo().getLocation().x;
        n = MouseInfo.getPointerInfo().getLocation().y;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse clicked");
    }
}

public class Mandelbrot extends JComponent implements ActionListener{

    public static void main(String[] args){
        try {
            input1 = args[0];
        }catch (Exception e){}
        try {
            input2 = Double.parseDouble(args[1]);
        }catch (Exception e){}
        try{
        input3 = Double.parseDouble(args[2]);
        }catch (Exception e){}
        try {
            input4 = Double.parseDouble(args[3]);
        }catch (Exception e){}
        try {
            input5 = Double.parseDouble(args[4]);
        }catch (Exception e){}
        try {
            itr = Integer.parseInt(args[5]);
        }catch (Exception e){}


        Mandelbrot r = new Mandelbrot();
        Zoom q = new Zoom();
        q.m = a;
        q.n = b;
        r.addMouseListener(q);

    }

    public static String input1;
    public static double input2;
    public static double input3;
    public static double input4;
    public static double input5;
    public static int itr;

    public static final int WIDTH = 800;
    public static final int HEIGHT = 800;
    //public static final int ITR = 1000;
    public static final float SCALE = 400;
    public static double a;
    public static double b;
    public static int f = 1;

    private float hueoffset = 0;

    private BufferedImage buffer;

    private Timer timer;

    public Mandelbrot(){

        buffer = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_RGB);
        timer = new Timer(1,this);
        renderMandelbrotSet();

        JFrame frame = new JFrame("Mandelbrot Set");
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

    public void renderMandelbrotSet(){
        for(int x = 0;x < WIDTH;x++){
            for(int y = 0;y < HEIGHT;y++){

                int color = 0;
                float newX,newY;
                newX = (x - WIDTH/2f)/SCALE;
                newY = (y - HEIGHT/2f)/SCALE;

                if(input2 < newX && newX < input3){
                    if(input4 < newY && newY < input5){
                        color = calculatePoint((x - WIDTH/2f)/SCALE,(y - HEIGHT/2f)/SCALE);
                    }
                }

                 buffer.setRGB(x,y,color);
            }
        }
    }

    public int calculatePoint(float x,float y){
        float cx = x;
        float cy = y;

        int i;

        for(i = 0;i < itr;i++){
            float nx = x*x - y*y + cx;
            float ny = 2*x*y + cy;
            x = nx;
            y = ny;

            if((x*x + y*y) > 4){
                break;
            }
        }
        if(i == itr){
            //return 0x00000000;
            return Color.HSBtoRGB(((float) i/itr+hueoffset),0.01f,0.0001f);
        }
        return Color.HSBtoRGB(((float)i/itr + hueoffset),1,1);
    }

    public void paint(Graphics g){

        g.drawImage(buffer,0,0,null);
    }

    public void actionPerformed(ActionEvent e){
        hueoffset += 0.001f;
        renderMandelbrotSet();
        repaint();
    }
}
