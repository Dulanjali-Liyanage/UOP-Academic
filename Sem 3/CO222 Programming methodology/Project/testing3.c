#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char puzzleLine[10];
char wordLine[10];
char matrix[10][10];
char wordList[10][10];

int countNewLine = 0;
int puzzleCount = 0;
int wordCount = 0;
int maxLen = 1;
int notSetCondition = 0;
int ch = 0;
int cv = 0;
int noOfwaysV;
int noOfwaysH;
int a,b;


void verti(int x, int y,char matrix[10][10],char* currentWord)
{

	int g = strlen(currentWord);
	int n = g-1;
	int count = 0;


	int i;
	for (i = 0; i < puzzleCount; i++) {
		if (matrix[x + i][y] == '#') {
                count++;

		}else{
            if(matrix[x+i][y] == currentWord[count] && matrix[x+i][y] != '\n'){
                count++;
            }else{
                if(count > 0){
                    break;
                }
            }
		}
	}
	if(count == n){
        noOfwaysV++;
	}else{
        cv++;
	}
}

void horiz(int x, int y,char matrix[10][10],char* currentWord)
{
	int g = strlen(currentWord);
	int n = g-1;

	int count = 0;


	int i;
    for (i = 0; matrix[x][y+i] != '\0'; i++) {

        if (matrix[x][y + i] == '#') {
            count++;

        }else{
            if(matrix[x][y+i] == currentWord[count] && matrix[x][y+i] != '\n'){
                count++;

            }else{
                if(count > 0){
                    break;
                }
            }
        }
    }

    if(count == n){
        noOfwaysH++;
    }else{
        ch++;
    }
}

void turnCapital(char wordLine[10]){

    int i;
    for(i = 0;wordLine[i] != '\0';i++){

        if (wordLine[i] >= 97 && wordLine[i] <= 122){
            wordLine[i] = wordLine[i] - 32;
        }
    }
}


void printMatrix(char matrix[10][10])
{
    int i;
    for(i = 0;i < puzzleCount;i++){
        int j;
        for(j = 0;matrix[i][j] != '\0';j++){
            printf("%c",matrix[i][j]);
        }
	}

}


void checkHorizontal(int x, int y,char matrix[10][10],char* currentWord)
{
	int g = strlen(currentWord);
	int n = g-1;

	int count = 0;
	int k;


	int i;
    for (i = 0; matrix[x][y+i] != '\0'; i++) {

            if (matrix[x][y + i] == '#') {
                count++;
                if(count == 1){
                    k = i;
                }
            }else{

                if(matrix[x][y+i] == currentWord[count] && matrix[x][y+i] != '\n'){
                    count++;
                    if(count == 1){
                        k = i;
                    }
                }else{
                    if(count > 0){
                        break;
                    }
                }
            }
    }

	if(count == n){
        int i,j;
        for (i = k,j = 0;j < n; i++,j++) {
            matrix[x][y + i] = currentWord[j];
        }
        return;
	}else{
        return;
	}

}

void checkVertical(int x, int y,char matrix[10][10],char* currentWord)
{

	int g = strlen(currentWord);
	int n = g-1;
	int count = 0;
	int k;


	int i;
	for (i = 0; i < puzzleCount; i++) {
		if (matrix[x + i][y] == '#') {
                count++;
                if(count == 1){
                    k = i;
                }
		}else{
            if(matrix[x+i][y] == currentWord[count] && matrix[x+i][y] != '\n'){
                count++;
                if(count == 1){
                    k = i;
                }
            }else{
                if(count > 0){
                    break;
                }
            }
		}
	}

	if(count == n){

        int i,j;
        for (i = k,j = 0; j < n; i++,j++) {
            matrix[x + i][y] = currentWord[j];
        }
        return;
    }else{
        return;
    }
}


void solvePuzzle(char wordList[10][10],char matrix[10][10],int index)
{
	while (index < wordCount) {
		char* currentWord = wordList[index];

        noOfwaysV = 0;
        noOfwaysH = 0;


        for(a = 0;a < maxLen;a++){
            verti(0,a,matrix,currentWord);
        }


        for(b = 0;b < puzzleCount;b++){
            horiz(b,0,matrix,currentWord);
        }

        if((noOfwaysV == 1) && (noOfwaysH != 1)){
            int i;
            for (i = 0; i < maxLen; i++) {
                checkVertical(0, i,matrix, currentWord);
            }
        }else{
            if((noOfwaysH == 1) && (noOfwaysV != 1)){
                int i;
                for (i = 0; i < puzzleCount; i++) {
                    checkHorizontal(i, 0,matrix, currentWord);
                }
            }
        }
		index++;
	}

	if(index != 0){
        if(cv == a){
            notSetCondition++;
        }

        if(ch == b){
            notSetCondition++;
        }


        if(notSetCondition == 2){
            puts("IMPOSSIBLE");
            return;
        }
    }

    printMatrix(matrix);
    return;
}



int main(){
	while(countNewLine != 2){
        fgets(puzzleLine,sizeof(puzzleLine),stdin);

        int n = strlen(puzzleLine);

        if(maxLen < n){
            maxLen = n;
        }
        if(puzzleLine[0] == '\n'){
            countNewLine++;
        }else{
            turnCapital(puzzleLine);
            strcpy(matrix[puzzleCount],puzzleLine);
            puzzleCount++;
        }

	}

	countNewLine = 0;

	while(countNewLine != 2){
        fgets(wordLine,sizeof(wordLine),stdin);

        if(wordLine[0] == '\n'){
            countNewLine++;
        }else{
            turnCapital(wordLine);
            strcpy(wordList[wordCount],wordLine);
            wordCount++;
        }
	}

	solvePuzzle(wordList,matrix,0);

	return 0;
}


