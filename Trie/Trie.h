/*
 * Trie.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ningwangpanda
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <string>
#include "TrieNode.h"

using namespace std;

class Trie {
	TrieNode* root;
public:
    Trie();
    ~Trie();

    void deleteTrie(TrieNode* root);

    // Inserts a word into the trie.
    void insert(const string word);

    // Returns true if the word is in the trie.
    bool search(const string word) const;

    // Returns true if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string prefix) const;
};

#endif /* TRIE_H_ */
