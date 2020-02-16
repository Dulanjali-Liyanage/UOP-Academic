import java.util.*;
import java.math.*;
class Matrix{
   private static final int numberOfThreads=4;
   private static int count=0;
   public static int [][] a;
   public static int [][] b;
   public static int [][] c;


  static float[][] addMatrices(float[][]a,float[][]b){


   class Block implements Runnable{
       private int low;
       private int up;

       Block(int low,int up){
       this.low=low;
       this.up=up;

       }

       @Override
       public void run(){
       for(int i=low;i<=up;i++){
          for(int j=0;j<a[0].length;j++){
            c[i][j]=a[i][j]+b[i][j];
            }
          }

       }



   }
    int lower,upper;
        for(int i=0;i<numberOfThreads;i++){
        lower=i*4;
        upper=(i+1)*4-1;
        upper=(upper>nums.length-1)?nums.length-1:upper;

        Thread task=new Thread(new Block(lower,upper));
        task.start();
        try{
        task.join();
        }catch(InterruptedException e){

        }}
        return c;
        }

  public static void main(String args[]){
  float [][] a={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};
  float [][] b={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};

  float c[][]=(addMatices(a,b));
  for(int i=0;i<c.length;i++){
    for(int j=0;j<c.length;j++){
      System.out.println(c[i][j]);
    }
  }
  }

}
