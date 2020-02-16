/*If an algorithm i user friendly, then it likely doesn't call any particular datum into the cache more than once.So, it puts data in the cache,
uses it, and then move on without having to recall that data again
So this implementation is not cache friendly. Because as shown in below we use the given the input matrix for every row thread.
And also the result matrix is called for every line and most of the variable used in this code are used more than once.
So the conclusion is, this implementation is not cache friendly.
*/


class Matrix extends Thread {

    private static int [][] p;
    private static int [][] q;
    private static int [][] r;
    private static int i;
    private static int y;
    private static int z1;


    /* You might need other variables as well */

    public Matrix(int [][] a,int [][] b,int [][] result,int i,int y,int z1) { // need to change this, might need some information
    	p = a;
    	q = b;
    	r = result;
    	this.i = i;
    	this.y = y;
    	this.z1 = z1;

    }

	//Each thread will do a multiplication of elements in a row
	//A row by row multiplication
	//many threads can access the same lock at the same time, synchronize restricts this to one
	//when synchronizing public synchronized void run()
	//we create many threads and the above method only allow to access one thread at a time. So others have to wait until they finish
    public void run(){
		int j, k, s;
		for(j=0; j<y; j++) {
			for(s=0, k=0; k<z1; k++){
				s += p[i][k] * q[k][j];
			}
			r[i][j] = s;
		}
	}

	public static int [][] ans(){
		return r;
	}

}

public class MainMatrix {
    public static int [][] a = {{1, 1, 1},{1, 1, 1},{1, 1, 1}};//a = {a[0],a[1],a[2]}

    public static int [][] b = {{1},{1},{1}};//b = {b[0],b[1],b[2]}

    public static int x = a.length;//no. of rows a has
	public static int y = b[0].length;//no. of columns b has

	public static int z1 = a[0].length;//no. of columns a has
	public static int z2 = b.length;// no. of rows b has



    public static void print_matrix(int [][] v) {
		for(int i=0; i < v.length; i++) {
	    	for(int j=0; j< v[i].length; j++){
				System.out.print(v[i][j] + " ");
			}
	    		System.out.println();
		}
    }

    public static int [][] result = new int [x][y];


    public static void main(String [] args) {

		if(z1 != z2) {
			System.out.println("Cannnot multiply");
		}

		//to parallelize threads I used to make threads with number of rows
		Thread t[] = new Thread[x];


		//long st1 = System.nanoTime();
		for(int i = 0;i < x;i++){

					//parallely every thread get started
					//In this example 3 threads will get executed
					//Basically no. of threads = no. of row of the multiplier matrix
					t[i] = new Matrix(a,b,result,i,y,z1);
					t[i].start();
					result = Matrix.ans();

					try{
						t[i].join();
					}catch(Exception e){}
		}

		//long st2 = System.nanoTime();

		//System.out.println(st2-st1);

		print_matrix(result);

    }
}