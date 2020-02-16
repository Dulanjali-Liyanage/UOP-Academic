public class Q4 {
    static int [][] cost = {{0, 3, 12, 23, 41}, // cost from 0
				    {0, 0,  2,  4, 34}, // cost from 1
				    {0, 0,  0,  12, 3}, // cost from 2
				    {0, 0,  0,  0, 12}, // cost from 3
				    {0, 0,  0,  0,  0}  // cost from 4
	    };

	static int [][] minVal = {
		{2000,3,12,23,41},
		{2000,2000,2,4,34},
		{2000,2000,2000,12,3},
		{2000,2000,2000,2000,12},
		{2000,2000,2000,2000,2000}
		};


    static int iMax = 5;
    static int jMax = 5;

    // Just for testing, min cost from 0 to 4 should be 8.
    static int answer = 8;

    static int minCost(int i, int j) {
		// broken implementation
		if(i == j || j == i+1){
			return minVal[i][j];
		}

		for(int a = i+1;a < j;a++){

			int n = minCost(i,a) + minCost(a,j);
			if(n < minVal[i][j]){
				minVal[i][j] = n;
			}

		}

		return minVal[i][j];
    }

    public static void main(String [] args) {
		int r = minCost(0,4);
	if(r == answer)
	   System.out.println("Your implementation might be correct");
	else
	    System.out.println("Too bad. Try again (" + r + ")");
    }

}
