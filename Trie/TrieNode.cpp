/*
 * TrieNode.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ningwangpanda
 */

#include <cstddef>
#include "TrieNode.h"

using namespace std;

TrieNode::TrieNode():isWord(false){
	for(int i=0; i<26; ++i){
		children[i] = NULL;
	}
}

TrieNode* TrieNode::getChild(const char ch) const{
	return children[ch-'a'];
}

void TrieNode::addChild(const char ch){
	children[ch-'a'] = new TrieNode();
}

bool TrieNode::getIsWord() const{
	return isWord;
}

void TrieNode::setIsWord(){
	isWord = true;
}
