/*
 * TrieNode.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ningwangpanda
 */

#ifndef TRIENODE_H_
#define TRIENODE_H_

class TrieNode {
    bool isWord;
    TrieNode* children[26];
public:
    TrieNode();
    TrieNode* getChild(const char ch) const;
    void addChild(const char ch);
    bool getIsWord() const;
    void setIsWord();
};

#endif /* TRIENODE_H_ */
