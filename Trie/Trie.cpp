/*
 * Trie.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ningwangpanda
 */

#include <string>
#include "TrieNode.h"
#include "Trie.h"

using namespace std;

Trie::Trie(){
	root = new TrieNode();
}

Trie::~Trie(){
	deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* root){
	for(int i=0; i<26; ++i){
		if(root->getChild('a'+i)) deleteTrie(root->getChild('a'+i));
	}
	delete root;
}

// Inserts a word into the trie.
void Trie::insert(const string word){
	TrieNode* node = root;
	for(const char ch : word){
		if(!node->getChild(ch)){ //NULL
			node->addChild(ch);
		}
		node = node->getChild(ch);
	}
	node->setIsWord();
}

// Returns true if the word is in the trie.
bool Trie::search(const string word) const{
	TrieNode* node = root;
	for(const char ch : word){
		if(!node->getChild(ch)) return false;
		else node = node->getChild(ch);
	}
	return node->getIsWord();
}

// Returns true if there is any word in the trie
// that starts with the given prefix.
bool Trie::startsWith(const string prefix) const{
	TrieNode* node = root;
	for(const char ch : prefix){
		if(!node->getChild(ch)) return false;
		else node = node->getChild(ch);
	}
	return true;
}
