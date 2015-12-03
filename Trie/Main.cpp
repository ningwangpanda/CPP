//============================================================================
// Name        : Main.cpp
// Author      : ningwangpanda
// Version     : 1.0.0
// Copyright   : @ningwangpanda
// Description : Data Structure - Trie
//============================================================================

#include <iostream>
#include <string>
#include "TrieNode.h"
#include "Trie.h"

using namespace std;

int main(){
   Trie trie;
   trie.insert("somestring");

   //Input requirements: string of lower case letters a-z.
   cout.setf(std::ios::boolalpha);
   cout<<"Trie contains string \"some\": "<<trie.search("key")<<endl;
   cout<<"Trie contains string \"somestring\": "<<trie.search("somestring")<<endl;
   cout<<"Trie contains prefix \"some\": "<<trie.startsWith("some")<<endl;
}
