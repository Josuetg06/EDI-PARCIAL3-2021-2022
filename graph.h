#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define GRAPh_CAPACITY 100

typedef struct{

  int elements[GRAPh_CAPACITY];
  int matrix[GRAPh_CAPACITY][GRAPh_CAPACITY];
  int noElements;

}Graph;
void setupGraph(Graph *g);
int addVertice(Graph *g, char vertice);
int addRelation(Graph *g, char vertice1, char vertice2);
int findVertice(Graph g, char value);
int deleteRelation(Graph *g,char vertice1, char vertice2);
void printGraph(Graph g);
int deleteRelation(Graph *g,char vertice1, char vertice2);

void setupGraph(Graph *g)
{

    g->noElements = 0;

    for(int renglon=0; renglon<GRAPh_CAPACITY; renglon ++){

        for(int columna=0; columna<GRAPh_CAPACITY; columna ++){

            g->matrix[renglon][columna]=0;
        }
    }

}

int addVertice(Graph *g, char vertice){

  if(g->noElements<GRAPh_CAPACITY){

    g->elements[g->noElements]=vertice;
    g->noElements++;

  }

}

int addRelation(Graph *g, char vertice1, char vertice2){

int postVertice1=findVertice(*g, vertice1);
int postVertice2=findVertice(*g, vertice2);

if(postVertice1 != -1 && postVertice2 != -1){

    g->matrix[postVertice1][postVertice2] = 1;
    g->matrix[postVertice2][postVertice1] = 1;

    return 1;
}

  return 0;

}


int findVertice(Graph g, char value){

 int pos=-1;

 for(int i=0; i<g.noElements && pos == -1; i++){

    if(g.elements[i]==value){

        pos = i;
    }


 }

 return pos;
}

int deleteRelation(Graph *g,char vertice1, char vertice2){


int postVertice1=findVertice(*g, vertice1);
int postVertice2=findVertice(*g, vertice2);

if(postVertice1 != -1 && postVertice2 != -1){

    g->matrix[postVertice1][postVertice2] = 0;
    g->matrix[postVertice2][postVertice1] = 0;

    return 1;
}

  return 0;



}
void printGraph(Graph g){

 printf("\t");

 for(int i=0; i < g.noElements; i++){

    printf("%c\t", g.elements[i]);

 }
  printf("\n");

 for (int r=0; r < g.noElements; r++){

    printf("%c\t", g.elements[r]);
    for(int c=0; c < g.noElements; c++){

       printf("%d\t", g.matrix[r][c]);

   }
    printf("\n");
 }


}

int deleteVertice(Graph *g, char vertice)
{
 int VerticeIndex = findVertice(*g, vertice);
    if(VerticeIndex != -1)
    {
        --g->noElements;
        for(int i = VerticeIndex ; i < g->noElements ; i++)
        {

            g->elements[i]=g->elements[i + 1];
        }
    }

        for(int r = 0 ; r <= g->noElements ; r++)
        {

             if(r >= VerticeIndex)
             {

                for(int c = 0 ; c <= g->noElements ; c++)
                {

                    g->matrix[r][c] = g->matrix[r+1][c];
                }

            }

        }


        for(int r = 0 ; r <= g->noElements ; r++)

        {
            for(int c = 0 ; c <= g->noElements ; c++)

            {

               if(c >= VerticeIndex)
                {
                    g->matrix[r][c] = g->matrix[r][c+1];

                }

                 return 1;

            }


        }


    return 0;

}


#endif // GRAPH_H_INCLUDED
