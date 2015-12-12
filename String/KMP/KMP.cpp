/*
 * KMP.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: ningwangpanda
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//compute prefix table
vector<int> prefix(const string pattern){
	size_t m = pattern.length();
	vector<int> pi(m,0);
	int k = 0;
	for(size_t i=1; i<m; ++i){
		while(k>0 && pattern[k]!=pattern[i]) k = pi[k-1];
		if(pattern[k]==pattern[i]) k++;
		pi[i] = k;
	}
	return pi;
}

//Knuth-Morris-Pratt (KMP) Algorithm
void KMP(const string text, const string pattern) {
	size_t n = text.length();
	size_t m = pattern.length();

	//empty pattern: 0
	if(m==0){
		cout<<0<<endl;
		return;
	}

	vector<int> pi = prefix(pattern); //pi[]: prefix table
	size_t k = 0; //number of characters matched in pattern
	size_t match = 0; //number of matches
	for(size_t i=0; i<n; ++i){
		while(k>0 && pattern[k]!=text[i]) k=pi[k-1];
		if(pattern[k]==text[i]) k++;
		if(k==m){
			match++;
			//index: 0-based
			cout<<"No. "<<match<<" match occurs with shift "<<i-m+1<<endl;
			k = pi[k-1];
		}
	}

	//no match or empty text: -1
	if(match == 0){
		cout<<-1<<endl;
	}
}

int main(){

	//output
	//No. 1 match occurs with shift 0
	//No. 2 match occurs with shift 2
	KMP("ababaca", "aba");

	//output
	//-1
	KMP("abcdeaba", "xyz");
	return 0;
}

