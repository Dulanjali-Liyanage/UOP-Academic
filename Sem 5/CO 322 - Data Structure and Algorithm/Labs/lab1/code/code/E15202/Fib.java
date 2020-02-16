public class Fib {

    public static int fib_r(int x) {
	if(x <= 2) return 1;
	return fib_r(x-1) + fib_r(x-2);
    }

    public static int fib_i(int x) {
	int a=1, b=1, fib=1, i=2;
	while(i<x) {
	    fib = a + b;
	    a = b;
	    b = fib;
	    i+=1;
	}
	return fib;
    }


    public static void main(String [] args) {
		long r[] = new long[40];
		long i[] = new long[40];
		for(int x = 1;x <= 40; x++){
			final long startTime_r = System.nanoTime();
			//System.out.println("Fib of " + x + " = " + fib_r(x));
			fib_r(x);
			final long duration_r = System.nanoTime() - startTime_r;

			r[x-1] = duration_r;



			final long startTime_i = System.nanoTime();
			//System.out.println("Fib of " + x + " = " + fib_i(x));
			fib_i(x);
			final long duration_i = System.nanoTime() - startTime_i;

			i[x-1] = duration_i;


		}
		for(int y = 0;y < 40;y++){
			System.out.print(r[y] + " ");
		}

		System.out.println("---------------------------------");
		for(int y = 0;y < 40;y++){
			System.out.print(i[y] + " ");
		}

    }
}


