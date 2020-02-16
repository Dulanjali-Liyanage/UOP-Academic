public class Q1 {
    static int [][] cost = {{0, 3, 12, 23, 41}, // cost from 0
				    {0, 0,  2,  4, 34}, // cost from 1
				    {0, 0,  0,  12, 3}, // cost from 2
				    {0, 0,  0,  0, 12}, // cost from 3
				    {0, 0,  0,  0,  0}  // cost from 4
	    };


    static int iMax = 5;
    static int jMax = 5;

    // Just for testing, min cost from 0 to 4 should be 8.
    static int answer = 8;

    static int minCost(int i, int j) {
		// broken implementation
		int min_cost = cost[i][j];

		if(i == j || j == i+1){
			return min_cost;
		}

		for(int a = i+1;a < j;a++){
			//System.out.println
			int n = minCost(i,a) + minCost(a,j);
			//System.out.println(i+ " " + a + " " + j + " "+ n);
			if(n < min_cost){
				min_cost = n;
			}
		}

		return min_cost;
    }

    public static void main(String [] args) {
		int r = minCost(0,4);
	if(r == answer)
	   System.out.println("Your implementation might be correct");
	else
	    System.out.println("Too bad. Try again (" + r + ")");
    }

}
