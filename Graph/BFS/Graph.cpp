/*
 * Graph.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: ningwangpanda
 */

#include <vector>
#include <iostream>
#include <list>
#include "graph.h"

using namespace std;

Graph::Graph(int v):V(v){
    this->adj = new list<int>[V];
}

Graph::~Graph(){
    delete[] this->adj;
}

/** function: add edge to adjacency lit */
/** input   : x: head, y: tail          */
/** output  : none                      */
void Graph::addEdge(int x, int y){
    adj[x].push_back(y);
}

/** function: breadth first search                        **/
/** input   : source vertex                               **/
/** output  : distance of each vertex printed in function **/
void Graph::BFS(int S){

	//distance of each vertex to source vertex
	//initialized as not visited, i.e., -1
	vector<long> distance(V, -1);

    //use a queue to track vertices
    list<int> vQueue;

    //mark source vertex as visited and set distance to 0
    //push it to queue
    distance[S] = 0;
    vQueue.push_back(S);

    while(!vQueue.empty()){

    	//process queue and set distance
    	int vertex = vQueue.front();
    	vQueue.pop_front();

    	//all adjacent vertices
    	for(auto it=adj[vertex].begin(); it!=adj[vertex].end(); ++it){

    		//if vertex is not visited, mark as visited and set distance
    		//push vertex to queue
    		if(distance[*it]==-1){
    			distance[*it] = edgeLength + distance[vertex];
    			vQueue.push_back(*it);
    		}
    	}
    }

    cout<<"Distance of each vertex to source vertex: "<<endl;
    for(int i=0; i<V; ++i){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}
