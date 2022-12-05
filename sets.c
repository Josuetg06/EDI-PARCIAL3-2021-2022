#include <stdio.h>
#include "sets.h"
int main(){

   Set setA, setB;
   Set setResult;

   int r;

   setupSet(&setA);
   setupSet(&setB);
   setupSet(&setResult);



    addElement(&setA, 15);
    addElement(&setA, 18);
    addElement(&setA, 20);
    addElement(&setA, 23);
    addElement(&setA, 31);


    addElement(&setB, 15);
    addElement(&setB, 13);
    addElement(&setB, 24);
    addElement(&setB, 27);
    addElement(&setB, 30);


    deleteElement(&setB, 15);

    printSet(setB);

   setupSet(&setB);

    addElement(&setB, 15);
    addElement(&setB, 13);
    addElement(&setB, 24);
    addElement(&setB, 27);
    addElement(&setB, 30);

     printf("\n");

   unionSet(setA,setB,&setResult); //union

   printSet(setResult);

   printf("\n");

   setupSet(&setResult);

   diferenceSet(setA,setB,&setResult); //diferencia

   printSet(setResult);

   printf("\n");

   setupSet(&setResult);

   intersect(setA,setB,&setResult); //insercion

   printSet(setResult);

   printf("\n");

   setupSet(&setResult);

   sumaSet(setA,&setB); //suma

   printSet(setB);









  return 0;
}
