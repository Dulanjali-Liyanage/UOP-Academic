import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import javax.swing.JComponent;
import javax.swing.Timer;
import javax.swing.JFrame;

public class JuliaSet extends JComponent implements ActionListener{
    public static void main(String[] args){

        new JuliaSet();

    }

    public static final int WIDTH = 800;
    public static final int HEIGHT = 800;
    public static final int ITR = 1000;
    public static final float SCALE = 250;
    public static final float CX = -0.70176f;
    public static final float CY = -0.3842f;

    private float hueoffset = 0;

    private BufferedImage buffer;

    private Timer timer;

    public JuliaSet(){

        buffer = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_RGB);
        timer = new Timer(1,this);
        renderJuliaSet();

        JFrame frame = new JFrame("Julia Set");
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

    public void renderJuliaSet(){
        for(int x = 0;x < WIDTH;x++){
            for(int y = 0;y < HEIGHT;y++){
                int color = calculatePoint((x - WIDTH/2f)/SCALE,(y - HEIGHT/2f)/SCALE);
                buffer.setRGB(x,y,color);
            }
        }
    }

    public int calculatePoint(float x,float y){

        int i;

        for(i = 0;i < ITR;i++){
            float nx = x*x - y*y + CX;
            float ny = 2*x*y + CY;
            x = nx;
            y = ny;

            if((x*x + y*y) > 4){
                break;
            }
        }
        if(i == ITR){
            //return 0x00000000;
            return Color.HSBtoRGB(((float)i/ITR + hueoffset),0.01f,0.0001f);
        }
        return Color.HSBtoRGB(((float)i/ITR + hueoffset),1f,1f);
    }

    public void paint(Graphics g){

        g.drawImage(buffer,0,0,null);
    }

    public void actionPerformed(ActionEvent e){
        hueoffset += 0.01f;
        renderJuliaSet();
        repaint();
    }
}
