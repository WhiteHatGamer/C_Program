#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graphNode graphNode_t;

typedef struct graph{
    struct graphNode** vertices;
    int vertexSize;
}graph_t; 


// Initialize graph
graph_t* graphInit();

// Insert data into graph
bool insertGraphVertex(graph_t** _graph, void* _data);

// Delete from Node
bool graphDeleteNode(graphNode_t** _graph, void* _data);

// Search from Graph

// print graph Data
bool printGraph(graph_t* _graph);

// Free graph
bool freeGraph(graph_t** _graph);

#endif
