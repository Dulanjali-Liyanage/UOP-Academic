/*********************************************
 * CO322: Data structures and algorithms
 * Implementation of the hashTable
 *********************************************/
class HashTableImp implements HashTable {

    /* Put your code here */
    public static class HashNode{
		String key;
		int value = 0;
		HashNode next;
	}

	public HashNode[] table; // hash table
	private int count;


    public HashTableImp(int initialSize){
	    if(initialSize <= 0){
			System.out.println("Please enter a positive number");
			return;
		}
	    table = new HashNode[initialSize];
   	}

    //compute the hash code for a key
    //hash code depends  on the table size

    //hashing method 1
    /*public int hashing(String key){
		int hash = 0;
		for (int i = 0; i < key.length(); i++){
			hash = (32* hash + key.charAt(i))%table.length;
		}
	   	return (hash%table.length);
	}*/

	//hasing method 2
	public int hashing(String key){
			int hash = 0;
			for (int i = 0; i < key.length(); i++){
				hash = (31*hash + key.charAt(i))%table.length;
			}
		   	return (hash%table.length);
	}

    public void insert(String key){

		int bucket = hashing(key); // get the bucket number by hash code
		HashNode list = null;

		list = table[bucket]; //For traversing the linked list

		//check whether the key is included in the list
		while(list != null){
			if(list.key.equals(key)){
				break;
			}
			list = list.next;
		}

		//here we have found the key
		if(list != null){
			//update the value
			list.value = list.value + 1;
		}else{

			//if the key is not found add a new node containing the key
			HashNode newNode = new HashNode();
			newNode.key = key;
			newNode.value = newNode.value + 1;
			newNode.next = table[bucket];
			table[bucket] = newNode;
			count++;
		}
	}

	//search the given key
	public int search(String key){
		int bucket = hashing(key);
		HashNode list = table[bucket];

		while(list != null){
			if(list.key.equals(key)){
				return list.value;
			}
			list = list.next;
		}

		return 0; // this means key does not exist
	}


	//Returns the number of nodes in the specified bucket
	public void getBucketSize(int length){
		int x2 = 0;
		int sum = 0;
		for(int i = 0;i < length;i++){
			int counter = 0;
			HashNode list = table[i];

			while(list != null){
				list = list.next;
				counter++;
			}

			sum = sum + counter;
			x2 = x2 + (int) Math.pow(counter,2);
			//System.out.println((i+1) + ":" + counter);
			System.out.println(counter);
		}
		   float avg = (float)(sum / (float)length);
		   float var = (float)(x2/length) - (float)(Math.pow(avg, 2));
		   System.out.println("Total:"+sum);
		   System.out.println("Avg:"+avg);
		   System.out.println("Deviation:"+Math.sqrt(var));
   	}

}// end HashTableImp
