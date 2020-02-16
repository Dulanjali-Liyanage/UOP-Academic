import java.io.*;
import java.util.*;

public class ConRead{

    public static void main(String args[]){

        String name = args[0];//command line user input

        char[] array = new char[name.length()-2];

        //take only the searching name
        for(int i = 0; i < name.length()-2; i++){
            array[i] = name.charAt(i+2);
        }

        //converting the searching name into a string
        String checkName = new String(array);

        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("contacts.csv"));

            String line = null;

            //read the file line by line
            while ((line = reader.readLine()) != null) {

                int a = 0;

                //split the line into comma seperated fields
                List<String> items = Arrays.asList(line.split("\\s*,\\s*"));

                int i = 0;
                String fullName = "Unkown";

                //iterate through the List
                for (Iterator<String> it = items.iterator(); it.hasNext(); i++) {

                    String flName = it.next();

                    if(i == 0){
                        fullName = flName;
                    }

                    if(name.charAt(0) == 'F'){

                        if(i == 1){//first name field
                            if(flName.equals(checkName)){
                                a = 1;

                            }
                        }

                        if(i == 30){//contact number field
                            if(a == 1){
                                System.out.println(fullName + '\t' + '\t' + flName);
                            }
                        }

                    }else if(name.charAt(0) == 'L'){
                        if(i == 3){//last name field
                            if(flName.equals(checkName)){
                                a = 1;
                            }
                        }

                        if(i == 30){//contact number field
                            if(a == 1){
                                System.out.println(fullName + '\t' + '\t' + flName);
                            }
                        }
                    }
                }


            }
        } catch (Exception e) {
            e.printStackTrace();

        } finally {
            if (reader != null) {
                try {
                    reader.close();//close the read file
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}