//============================================================================
// Name        : Main.cpp
// Author      : ningwangpanda
// Version     : 1.0.1
// Copyright   : @ningwangpanda
// Description : Graph Algorithm - Breadth First Search
//============================================================================

#include <iostream>
#include "Graph.h"

using namespace std;

int main() {

	int V = 6; //vertices are represented as integers from 0 to V-1
	Graph graph(V); //initialize graph

	//add edges - sample is a directed graph
	//undirected graph: addEdge(x,y) and addEdge(y,x)
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 2);

	// 1 --------> 2
	// ^      -    | -
	// |    -      |  -
	// | -         v   -
	// 0 --> 3 --> 4 --> 5
	//
	// 0-->2 and 5-->2

	graph.BFS(0); //breadth first search starts from vertex 0
	// output: 0 1 1 1 2 3

    return 0;
}
