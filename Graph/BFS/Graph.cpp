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
/** input: x: head, y: tail             */
/** output: none                        */
void Graph::addEdge(int x, int y){
    adj[x].push_back(y);
}

/** function: breadth first search                      **/
/** input: staring vertex                               **/
/** output: distance of each vertex printed in function **/
void Graph::BFS(int S){

	//distance of each vertex to the starting vertex
	//initialized as not visited, i.e., -1
	vector<long> distance(V, -1);

    const int edgeLength = 1; //assume edge length to be 1
    int dist = 1; //distance to the starting vertex

    //use two queues to track distances
    list<int> currQueue;
    list<int> nextQueue;

    //mark the starting vertex as visited and distance is 0
    //push it to current queue
    distance[S] = 0;
    currQueue.push_back(S);

    while(!currQueue.empty()){

    	//process current queue, assign same distance
        while(!currQueue.empty()){
            int vertex = currQueue.front();
            currQueue.pop_front();

            //all adjacent vertices
		    for(auto it=adj[vertex].begin(); it!=adj[vertex].end(); ++it){

		    	//if vertex is not visited, mark as visited and set distance
		    	//push vertex to next queue
                if(distance[*it]==-1){
                	distance[*it] = edgeLength * dist;
                    nextQueue.push_back(*it);
                }
            }
        }

        //move to next queue
        dist++;
        currQueue = nextQueue;
        nextQueue.clear();
    }

    cout<<"distance of each vertex to the starting vertex: "<<endl;
    for(int i=0; i<V; ++i){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}
