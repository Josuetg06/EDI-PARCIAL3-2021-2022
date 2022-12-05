#include <stdio.h>
#define QUEUE_CAPACITY 10

 struct queue {
     int data[QUEUE_CAPACITY + 1];
     int start;
     int end;
     int count;

};
void setupQueue(struct queue *q);
int isQueueEmpty(struct queue q);
int isQueueFull(struct queue q);
int dequeue(struct queue *q, int *value);
int enqueue(struct queue *q, int value);





int main(){

    struct queue q;
    int r, v;

    setupQueue( &q);


    r = enqueue(&q, 7);
    r = enqueue(&q, 18);
    r = enqueue(&q, 3);
    r = enqueue(&q, 13);
    r = enqueue(&q, 23);

    r = dequeue(&q, &v);
    r = dequeue(&q, &v);


     for (int i = q.start; i % (QUEUE_CAPACITY + 1) != q.end; i++){
        printf("%d ", q.data[i % (QUEUE_CAPACITY + 1)]);
   }


    return 0;
}

void setupQueue(struct queue *q){

   q->start = 0 ;
   q->end = 0 ;
   q->count = 0 ;

}

int isQueueEmpty(struct queue q){

    if(q.start == q.end)
        return 1;
    return 0;

}
int isQueueFull(struct queue q){

 if((q.end + 1) % (QUEUE_CAPACITY+1)== q.start)
        return 1;
 return 0;


}

int dequeue(struct queue *q, int *value){

  int r=0;

  if(isQueueEmpty(*q)==0){


    *value = q->data[q->start];


    q->start++;

    if(q->start>=QUEUE_CAPACITY +1){

        q->start=0;
    }

     r=1;

  }

   return r;
}


int enqueue(struct queue *q, int value){

   int r=0;

   if(isQueueFull(*q)==0)
   {

       q->data[q->end] = value;
       q->end++;

       if(q->end >= QUEUE_CAPACITY +1)
        q->end = 0;

       r=1;
   }



}


