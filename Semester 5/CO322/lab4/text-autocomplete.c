#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct trieNode{
	struct  trieNode *subtrie[26];
	bool isEndOfWord; // true for ended word and false for not ended word
}TrieNode;

TrieNode* createNode(){
	TrieNode* newTrieNode = (TrieNode*)malloc(sizeof(TrieNode));
	newTrieNode->isEndOfWord = false; // means word has not ended

	int i;
	for(i = 0;i < 26;i++){
		newTrieNode->subtrie[i] = NULL;
	}
	return newTrieNode;
}

void insertWord(TrieNode* root,char* word){
	int wordLength = strlen(word);
	
	int i;
	for(i = 0; i < wordLength-1; i++){
		
		TrieNode *curr = root
	}
}

int printSuggestions(){}
