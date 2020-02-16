#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nodeCount = 0;

typedef struct trieNode{
	struct  trieNode *subtrie[26];
	int isEndOfWord; // 1 for end of the word
}TrieNode;


TrieNode* createNode(){
	TrieNode* newTrieNode = (TrieNode*)malloc(sizeof(TrieNode));
	newTrieNode->isEndOfWord = 0; // not the end of the word

	int i;
	for(i = 0;i < 26;i++){
		newTrieNode->subtrie[i] = NULL;
	}
	return newTrieNode;
}

void insertWord(TrieNode* root,char *word){

	int i;
	for(i = 0;i < strlen(word); i++){
		TrieNode* curr = root->subtrie[word[i]%97]; // for simple letters

		if(curr == NULL){
			curr = createNode();

			nodeCount++;
		}

		if(i+1 == strlen(word)){
			curr->isEndOfWord = 1;
		}

		root->subtrie[word[i] % 97] = curr;
		root = curr;
	}
}


void printSuggestions(TrieNode *curr,char *slice){

	if(curr == NULL){
		return;
	}

	if(curr->isEndOfWord){
		printf("%s\n",slice);
	}

	int i;
	for(i = 0;i < 26; i++){
		if(curr->subtrie[i] != NULL){

			char *str = malloc(sizeof(char) * (strlen(slice) + 2));

			int j = 0;
			while(slice[j] != '\0'){
				str[j] = slice[j++];
			}

			str[j++] = i + 97;
			str[j] = '\0';

			printSuggestions(curr->subtrie[i],str);
		}
	}
}

void autocomplete(TrieNode* curr,char *prefix){
	int i;
	for(i = 0;i < strlen(prefix); i++){
		curr = curr->subtrie[prefix[i]%97];
	}

	printSuggestions(curr,prefix);
}

//convert to insert word to simple
void lower_string(char s[]){
	int c = 0;

	while(s[c] != '\0'){
		if(s[c] >= 'A' && s[c] <= 'Z'){
			s[c] = s[c] + 32;
		}
		c++;
	}
}

int main(){

	TrieNode* root = createNode();
	nodeCount++;

	FILE *fp = fopen("wordlist10000.txt","r");

	char word[25];

	clock_t beginInsert = clock();

	while(!feof(fp)){

		fscanf(fp,"%s",word);
		
		lower_string(word); // convert all the letters to simple letters
	
		insertWord(root,word);
	}
	
	clock_t endInsert = clock();

	printf("Insert Time = %fs\n",(float)(endInsert - beginInsert)/CLOCKS_PER_SEC);

	printf("Node Count  = %d\n",nodeCount);
	printf("Memory = %ld Bytes",sizeof(*(root))*nodeCount);

	fclose(fp);

	char input[100];

	while(1){
		
		
		printf("\nEnter the word: ");

		scanf("%s",input);

		lower_string(input); // convert all the letters to simple letters

		printf("%s\n",input);

		printf("\nSuggestions: \n");

		clock_t beginSuggest = clock();

		autocomplete(root,input);

		clock_t endSuggest = clock();

		printf("\nSuggest Time = %fs\n",(float)(endSuggest - beginSuggest)/CLOCKS_PER_SEC);

		
	}

	return 0;
}