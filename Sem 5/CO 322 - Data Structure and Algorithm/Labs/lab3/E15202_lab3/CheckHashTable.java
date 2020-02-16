import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class CheckHashTable extends HashTableImp{

	//initialize the table size
	public CheckHashTable(int tableSize){
		super(tableSize);
	}

	public static void main(String[] args){
		String line = "";
		int tableSize = 0;

		if(args.length == 2){

			tableSize = Integer.valueOf(args[0]);
			CheckHashTable myHashMap = new CheckHashTable(tableSize);

			//read the sample file
			String fileName = args[1];

			try(
				BufferedReader br = new BufferedReader(new FileReader(fileName))
			)
			{
				while((line = br.readLine()) != null){
					//convert all non alphbeticals to whitesapces
					String text = line.replaceAll("\\W"," ");

					//split the line from whitespaces
					String words[] = text.split("\\s+");

					for(String s : words){
						//insert into the hash table
						myHashMap.insert(s);
					}
				}
			}catch(FileNotFoundException e){
				System.out.println("File does not exist");
				return;
			}
			catch (IOException e){
				System.out.println("File reading failed");
				return;
			}

			//print all the information
			myHashMap.getBucketSize(tableSize);
			System.out.println();

			Scanner searchKey = new Scanner(System.in);
			String key;

			System.out.println("Enter the key:");
			key = searchKey.nextLine();
			System.out.println("Value: " + myHashMap.search(key));

			while(!key.equals("q")){
				System.out.println("Enter the key:");
				key = searchKey.nextLine();
				System.out.println("Value: " + myHashMap.search(key));
			}

		}else{
			System.out.println("Usage: java CheckHashTable <no.Of buckets> <filename.text>");
		}
	}
}



