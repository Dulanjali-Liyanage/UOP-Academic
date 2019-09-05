#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trieNode{
	struct  trieNode *subtrie[26];
	int isEndOfWord;
}TrieNode;

TrieNode* createNode(){
	TrieNode* newTrieNode = (TrieNode*)malloc(sizeof(TrieNode));
	newTrieNode->isEndOfWord = 0;

	int i;
	for(i = 0;i < 26;i++){
		newTrieNode->subtrie[i] = NULL;
	}
	return newTrieNode;
}

TrieNode* insertWord(TrieNode* root,char* word){

}

int printSuggestions(){}