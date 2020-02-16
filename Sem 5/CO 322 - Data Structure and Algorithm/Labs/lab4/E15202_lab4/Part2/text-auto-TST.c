#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nodeCount = 0;

typedef struct trieNode{
	char data;
	int isEndOfWord; // if this is the end of the word it would be 1
	struct trieNode *left,*eq,*right;
}TrieNode;



//create a new node
TrieNode* createNode(char data){

	TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));

	newNode->data = data;

	newNode->isEndOfWord = 0; // not the end of the word

	newNode->left = newNode->right = newNode->eq = NULL;

	return newNode;
}

//insert to the tree
TrieNode* insertWord(TrieNode* root,char* word){
	if(root == NULL){
		root = createNode(*word);

		nodeCount++;
	}

	if(!(*word)){
		root->isEndOfWord = 1;
	}

	//Recures to the correct child
	if(*word < root->data){

		root->left = insertWord(root->left,word);

	}else if(*word > root->data){

		root->right = insertWord(root->right,word);

	}else if(*word == root->data){

		if(*word != '\0'){

			root->eq = insertWord(root->eq,word+1);

		}else{

			root->isEndOfWord = 1;
		}
	}

	return root;
}

//get the last node
TrieNode* getLastNode(TrieNode* root,char* word){
	if(root == NULL){
		return NULL;
	}

	if(*word != '\0'){

		if(*word < root->data){

			return getLastNode(root->left,word);

		}else if(*word > root->data){

			return getLastNode(root->right,word);

		}else if(*word == root->data){

			if(*word != '\0'){

				return getLastNode(root->eq,word+1);

			}
		}
	}

	return root;
}

//node has no children
int isLeafNode(TrieNode* root){

	return (!root->left && !root->right && !root->eq);
}



//print suggestions
void printSuggestions(TrieNode* root,char* prefix){

	if(!root){
		return;
	}

	//print all the auto completed suggestions
	if(root->isEndOfWord){

		printf("%s\n",prefix);
		
	}

	if(isLeafNode(root)){
		return;
	}

	char *new_prefix = malloc(strlen(prefix) + 2);

	strcpy(new_prefix,prefix);

	strcat(new_prefix,(char*)&root->data);


	printSuggestions(root->left,prefix);

	printSuggestions(root->eq,new_prefix);

	printSuggestions(root->right,prefix);
}


//print suggestions
void autocomplete(TrieNode* root,char* word){
	if(*word){
		root = getLastNode(root,word);
	}

	printSuggestions(root,word);

}

//convert the insert word to simple
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
	
	char input[100];

	TrieNode* root =  NULL;

	FILE* fp = fopen("wordlist70000.txt","r");

	char word[100];

	clock_t beginInsert = clock();

	while(!feof(fp)){

		fscanf(fp,"%s",word);

		lower_string(word); // convert all the letters to simple letters

		root = insertWord(root,word);
	}
	
	clock_t endInsert = clock();

	printf("Insert Time = %fs\n",(float)(endInsert - beginInsert)/CLOCKS_PER_SEC);

	printf("Node Count  = %d\n",nodeCount);
	printf("Memory = %ld Bytes",sizeof(*(root))*nodeCount);

	fclose(fp);

	while(1){

		printf("\nEnter the word: ");

		scanf("%s",input);

		lower_string(input); // convert all the letters to simple letters

		printf("\nSuggestions: \n");

		clock_t beginSuggest = clock();

		autocomplete(root,input);

		clock_t endSuggest = clock();

		printf("\nSuggest Time = %fs\n",(float)(endSuggest - beginSuggest)/CLOCKS_PER_SEC);

		
	}
}
