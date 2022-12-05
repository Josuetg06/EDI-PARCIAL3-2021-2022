#include <stdio.h>
#include "graph.h"

int main(){

Graph graph;
int r=-1;


setupGraph(&graph);

 r = addVertice(&graph, 'A');
 r = addVertice(&graph, 'C');
 r = addVertice(&graph, 'D');
 r = addVertice(&graph, 'Z');
 r = addVertice(&graph, 'W');
 r = addVertice(&graph, 'X');

 addRelation(&graph,'A','Z');
 addRelation(&graph,'W','D');
 addRelation(&graph,'C','X');
 addRelation(&graph,'D','A');

 printGraph(graph);

 printf("\n");

 deleteRelation(&graph,'A','Z');
 deleteRelation(&graph,'W','D');
 deleteRelation(&graph,'D','A');

 printGraph(graph);

 printf("\n");

 deleteVertice(&graph,'D');
 deleteVertice(&graph,'Z');
 deleteVertice(&graph,'X');

 printGraph(graph);

return 0;
}
