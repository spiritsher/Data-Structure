/*
类型名称：加权图 (Weighted Graph)
对象集：G(V, E) 由一个非空的有限顶点集合 V 和一个有限边集合 E 组成。
操作集：对于任意的图 G ∈ graph_t ，顶点（的编号） V ∈ vertex_t，边（的权重） E ∈ edge_t ，有以下基本操作：
    1. graph_t CreateGraph(void)
    2. void DestroyGraph(graph_t G)
    3. void Link(graph_t G, vertex_t V1, vertex_t V2, edge_t E)
    4. bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2)
    5. void Visit(vertex_t V)
    6. void DFS(graph_t G, vertex_t V)
    7. void BFS(graph_t G, vertex_t V)
    8. void CleanFlag(void)
    9. bool Dijkstra(graph_t G, edge_t dist[], vertex_t path[], vertex_t startV)
    10. bool Floyd(graph_t G, edge_t dist[][VERTEX_NUMBER], vertex_t path[][VERTEX_NUMBER])
*/

#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define ERROR (-1)

#define VERTEX_NUMBER 7
#define NO_PATH 0xFFFF

/* 注释掉此行变成无向图 */
// #define UNDIRECTED

typedef int vertex_t; // 顶点（的编号）

typedef int edge_t; // 边（的权重）

typedef struct graph *graph_t; // 图

struct graph
{
    int vertexNum;
    int edgeNum;
    edge_t matrix[VERTEX_NUMBER][VERTEX_NUMBER]; // 邻接矩阵
};



graph_t CreateGraph(void);
void DestroyGraph(graph_t G);
void Link(graph_t G, vertex_t V1, vertex_t V2, edge_t E);
bool IsAdjacent(graph_t G, vertex_t V1, vertex_t V2);
void Visit(vertex_t V);
void DFS(graph_t G, vertex_t V); // Deep
void BFS(graph_t G, vertex_t V); // Breath
void CleanFlag(void);
bool Dijkstra(graph_t G, edge_t dist[], vertex_t path[], vertex_t startV);
bool Floyd(graph_t G, edge_t dist[][VERTEX_NUMBER], vertex_t path[][VERTEX_NUMBER]);

#endif
