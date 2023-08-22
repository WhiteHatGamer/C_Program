#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graphNode** edges;
    int edgeSize;
}graphNode_t;

graph_t* graphInit(){
    graph_t* _graph = (graph_t*)malloc(sizeof(graph_t));
    if(_graph == NULL){
        printf("Not allocated graphInit()");
    }
    _graph->vertices = NULL;
    _graph->vertexSize = 0;
    return _graph;
}

graphNode_t* createGraphNode(void* _data){
    graphNode_t* _node = (graphNode_t*)malloc(sizeof(graphNode_t));
    if(_node == NULL){
        printf("Not allocated createGraphNode()");
    }
    _node->data = _data;
    _node->edges = NULL;
    _node->edgeSize = 0;
    return _node;
}

bool insertGraphVertex(graph_t** _graph, void* _data){
    if(*_graph==NULL){
        *_graph = graphInit();
    }
    if((*_graph)->vertices == NULL){
        (*_graph)->vertices = (graph_t**)malloc(sizeof(graphNode_t*));
        if((*_graph)->vertices == NULL){
            printf("Not allocated insertGraphVertex()");
    }
    }else{
        (*_graph)->vertices = (graph_t**)realloc((*_graph)->vertices, ((*_graph)->vertexSize + 1) *sizeof(graphNode_t*));
        if((*_graph)->vertices == NULL){
            printf("Not allocated insertGraphVertex()");
        }
    }
    (*_graph)->vertices[(*_graph)->vertexSize] = createGraphNode(_data);
    (*_graph)->vertexSize++;
    return true;
}

bool freeGraphNode(graphNode_t** _node){
    if((*_node) == NULL){
        return false;
    }
    if((*_node)->edgeSize == 0){
        free((*_node));
        (*_node) = NULL;
        return true;
    }else{
        free((*_node)->edges);
        (*_node)->edges = NULL;
        free((*_node));
        (*_node) = NULL;
        return true;
    }
}

bool freeGraph(graph_t** _graph){
    if(*_graph==NULL){
        return false;
    }
    for(int i=0;i<(*_graph)->vertexSize;i++){
        freeGraphNode(&(*_graph)->vertices[i]);
    }
    if((*_graph)->vertices){
        free((*_graph)->vertices);
    }
    (*_graph)->vertices = NULL;
    free((*_graph));
    (*_graph) = NULL;
    return true;
}
