#ifndef SETS_H_INCLUDED
#define SETS_H_INCLUDED

#define SET_CAPACITY 10

typedef struct{

   int data[SET_CAPACITY];
   int sizee;

}Set;

void setupSet(Set *s);
int existElement(Set s, int value);
int addElement(Set *s, int value);
int deleteElement(Set *s, int value);
int deleteFirstElement(Set *s, int *value);
int deleteEndElement(Set *s, int *value);
void intersect(Set a, Set b, Set *result);
void unionSet(Set a, Set b, Set *result);
void diferenceSet(Set a, Set b, Set *result);
void sumaSet(Set a, Set *b);
void printSet(Set s);

void diferenceSet(Set a, Set b, Set *result){

      for(int i = 0 ; i < a.sizee ; i++)
       {
         if(!existElement(b, a.data[i]))
         {
            addElement(result, a.data[i]);
         }

       }
}


void unionSet(Set a, Set b, Set *result)
{

    for(int i = 0 ; i < a.sizee ; i++){

        addElement(result, a.data[i]);
    }

    for(int i = 0 ; i < b.sizee ; i++)
    {

      if(!existElement(*result, b.data[i]))
      {
        addElement(result, b.data[i]);
      }

    }

}
void sumaSet(Set a, Set *b)
{

 for(int i=b->sizee;i<a.sizee+b->sizee; i++)
 {

     addElement(b,a.data[i]);
 }

}


void intersect(Set a, Set b, Set *result){

for(int i=0; i<a.sizee; i++){

    if(existElement(b,a.data[i])==1){

        addElement(result,a.data[i]);
    }
}

}
int deleteElement(Set *s, int value){

   int found=-1;

   for(int i=0; i<s->sizee && found;i++)
   {

       if(s->data[i]==value)
         found = i;

   }

   if(found!=-1)
   {
       for(int actual=found; actual < s->sizee; actual ++){

           s->data[actual]=  s->data[actual+1];

       }
       s->sizee--;
   }

}
int deleteFirstElement(Set *s, int *value){

    int i=0;

    if(i==0)
    {
        *value=s->data[i];
        s->sizee--;


        for (; i<= s->sizee-1 ; i++) {
            s->data[i]=s->data[i+1];
        }
        return 1;

    }

    return -1;

}
int deleteEndElement(Set *s, int *value){

 int i=s->sizee;

     if(i==s->sizee)
    {
        *value=s->data[s->sizee];
        s->sizee--;

        return 1;

    }

    return -1;


}

int addElement(Set *s, int value){

  if(existElement(*s,value)==0 && s->sizee < SET_CAPACITY)
    {

      s->data[s->sizee]=value;
      s->sizee++;

      return 1;

  }

  return 0;
}

int existElement(Set s, int value){

    int found =0;

    for(int i=0; i < s.sizee && !found; i++)
    {

        if(s.data[i] == value)
            found=1;


    }

    return found;
}

void setupSet(Set *s)
{
    s->sizee = 0;
}
void printSet(Set s)
{
    printf("[ ");
    for(int i = 0 ; i < s.sizee ; i++)
        printf("%d ", s.data[i]);
    printf("]\n");
}


#endif // SETS_H_INCLUDED
