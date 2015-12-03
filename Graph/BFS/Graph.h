/*
 * Graph.h
 *
 *  Created on: Dec 3, 2015
 *      Author: ningwangpanda
 */

#ifndef BFS_GRAPH_H_
#define BFS_GRAPH_H_

#include <list>

using namespace std;

class Graph{
    int V; //number of vertices
    list<int> *adj; //adjacency list representation
public:
    Graph(int v);
    ~Graph();

    /** function: add edge to adjacency lit */
    /** input: x: head, y: tail             */
    /** output: none                        */
    void addEdge(int x, int y);

    /** function: breadth first search                      **/
    /** input: staring vertex                               **/
    /** output: distance of each vertex printed in function **/
    void BFS(int S);
};

#endif /* BFS_GRAPH_H_ */
