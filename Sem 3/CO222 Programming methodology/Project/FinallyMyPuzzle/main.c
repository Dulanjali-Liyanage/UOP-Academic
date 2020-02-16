#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char puzzleLine[15];
char wordLine[15];
char gird[15][15];
char wordList[15][15];

int countNewLine = 0;
int puzzleCount = 0;
int wordCount = 0;
int maxLen = 1;

//check grid has numbers or  not
int numberCheck(char wordLine[15]){
    int j = 0;
    while(j < strlen(wordLine)-1){
        if(wordLine[j] < 57 && wordLine[j] > 48){
            return 1;
        }
        j++;
    }
    return 0;
}

//check wordLine has symbols which are not letters
int notLetter(char wordLine[15]){
    int k;
    for(k = 0;wordLine[k] != '\n';k++){
        if(wordLine[k] < 65 || wordLine[k] > 90){
            return 1;
        }
    }
    return 0;
}

//check impossible conditions
int checkImpossible(){

    int i,j;
    for(i = 0;i < puzzleCount;i++){
        for(j = 0;gird[i][j] != '\n';j++){
            if(gird[i][j] >= 65 && gird[i][j] <= 90){
                return 1;
            }
        }
    }
    return 0;
}


//make all the letters capital
void turnCapital(char wordLine[15]){
    int i;
    for(i = 0;wordLine[i] != '\0';i++){

        if (wordLine[i] >= 97 && wordLine[i] <= 122){
            wordLine[i] = wordLine[i] - 32;
        }
    }
}

//print the grid with or without words
void printGrid()
{
    int i;
    for(i = 0;i < puzzleCount;i++){
        int j;
        for(j = 0;gird[i][j] != '\0';j++){
            printf("%c",gird[i][j]);
        }
	}

}

//check horizontally
int checkHorizontal(int x, int y,char* currentWord)
{
	int g = strlen(currentWord);
	int n = g-1;

	int count = 0;
	int k = 0;
	int countH[10];
	int placeH[10];
    countH[0] = 200;


    //check all the horizontally placed hashes
	int i;
    for (i = 0; gird[x][y+i] != '\0'; i++) {

            if (gird[x][y + i] == '#') {
                count++;
                if(count == 1){
                    placeH[k] = i;
                }
            }else{

                if(gird[x][y+i] == currentWord[count] && gird[x][y+i] != '\n'){
                    count++;
                    if(count == 1){
                        placeH[k] = i;
                    }
                }else{
                    if(count > 0){

                        countH[k] = count;
                        count = 0;
                        k++;
                        countH[k] = 200;
                        placeH[k] = 200;
                    }
                }
            }
    }

    //enter the suitable word horizontally
	int m;
	for(m = 0;countH[m] != 200;m++){
        if(countH[m] == n){
            int i,j;
            for(i = placeH[m],j = 0;j < n;i++,j++){
                gird[x][y+i] = currentWord[j];
            }
            return 1;
        }
	}
    return 0;
}

//check vertically
int checkVertical(int x, int y,char* currentWord)
{

	int g = strlen(currentWord);
	int n = g-1;

	int countV[10];
	int placeV[10];
	int count = 0;
	int k = 0;
	countV[0] = 200;


	//check all the vertically placed hashes
	int i;
	for (i = 0; i <= puzzleCount; i++) {
		if (gird[x + i][y] == '#') {
                count++;
                if(count == 1){
                    placeV[k] = i;
                }
		}else{
            if(gird[x+i][y] == currentWord[count] && gird[x+i][y] != '\n'){
                count++;
                if(count == 1){
                   placeV[k] = i;
                }
            }else{
                if(count > 0){
                   countV[k] = count;
                   count = 0;
                   k++;
                   countV[k] = 200;
                   placeV[k] = 200;
                }
            }
		}
	}

	//Enter the suitable word vertically
	int m;
	for(m = 0;countV[m] != 200;m++){
        if(countV[m] == n){
            int i,j;
            for(i = placeV[m],j = 0;j < n;i++,j++){
                gird[x+i][y] = currentWord[j];
            }
            return 1;
        }
	}

	return 0;
}

//solving the puzzle
void solvePuzzle(int index)
{

	while (index < wordCount) {
		char* currentWord = wordList[index];

        int i;
        int q = 0,v = 0;

        //solve the puzzle horizontally
        if(v == 0){
            for (i = 0; i < puzzleCount; i++) {
                int t = checkHorizontal(i,0,currentWord);
                if(t == 1){
                    q = 1;
                    break;
                }
            }
        }

        //solve the puzzle vertically
        if(q == 0){
            for (i = 0; i < maxLen; i++) {
                int h = checkVertical(0,i,currentWord);
                    if(h == 1){
                        v = 1;
                        break;
                    }
            }
        }
		index++;
	}

	//print impossible if there is no letter in the grid
	if(index != 0){
       	if(checkImpossible() == 0){
            puts("IMPOSSIBLE");
            return;
        }
	}

    printGrid();

    return;
}



int main(){

    //get the grid input and making the grid
	while(countNewLine != 1){
        fgets(puzzleLine,sizeof(puzzleLine),stdin);

        //is there any numbers
        if(numberCheck(puzzleLine) == 1){
            return 0;
        }

        int n = strlen(puzzleLine);

        if(maxLen < n){
            maxLen = n;
        }

        if(puzzleLine[0] == '\n'){
            countNewLine++;
        }else{
            turnCapital(puzzleLine);
            strcpy(gird[puzzleCount],puzzleLine);
            puzzleCount++;
        }
	}

	countNewLine = 0;

	//get the word inputs and include them in an array
	while(countNewLine != 1){
        fgets(wordLine,sizeof(wordLine),stdin);

        if(numberCheck(wordLine) == 1){
            return 0;
        }

        if(wordLine[0] == '\n'){
            countNewLine++;
        }else{
            turnCapital(wordLine);

            //what to do if there are no any letters in the input
            if(notLetter(wordLine) == 1){
                printGrid();
                return 0;
            }

            strcpy(wordList[wordCount],wordLine);
            wordCount++;
        }
	}

	solvePuzzle(0);

	return 0;
}


