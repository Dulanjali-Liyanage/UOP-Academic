import java.lang.*;

class Ball{
    double ax;
    double ay;
    double xspeed;
    double yspeed;


    Ball(double x,double y,double speed,double angleOfSpeedWithX){
        double angleRadian = (3.14/180)*angleOfSpeedWithX;//convert the angle in degrees to radian
        xspeed = speed*Math.cos(angleRadian);
        yspeed = speed*Math.sin(angleRadian);
        this.ax = x;
        this.ay = y;
    }

    //update the global time difference and change the position of the ball
    void updateTime(double time){
        ax = ax + xspeed*time;
        ay = ay + yspeed*time;
    }

    //checking the colliding conditions
    int willCollide(Ball b){
        if(b.ax == ax && b.ay == ay){
            return 1;
        }else{
            return 0;
        }

    }
}


public class E15202Ball {
    public static void main(String args[]){
        Ball b1 = new Ball(0.0,1.0,10.0,45.0);

        b1.updateTime(5.0);

        Ball b2 = new Ball(0.0,1.0,20.0,45.0);

        b1.updateTime(5.0);
        b2.updateTime(5.0);

        if(b2.willCollide(b1) == 1){
            System.out.println("B2 and B1 will collide");
        }else{
            System.out.println("B2 and B1 will not collide");
        }



        Ball b3 = new Ball(-10.0,5.0,3.0,30.0);

        b3.updateTime(20.0);
        b2.updateTime(20.0);

        if(b2.willCollide(b1) == 1){
            System.out.println("B2 and B3 will collide");
        }else{
            System.out.println("B2 and B3 will not collide");
        }

    }
}
