#include "node.h"

typedef struct Pqueue //maxheap
{
    nodePtr *Elements; //nodePtr elements[num];
    int queSize;//no of elements currently present in Priority queue(max heap)
}Pqueue;


//main Ppriority-queue finctions
Pqueue* Init_Pque(int size);
void insert_Node(Pqueue *que, nodePtr element);
nodePtr delete_Node(Pqueue *que, int index);

//helper functions 
void DownHeap(Pqueue *que,int root);
void UpHeap(Pqueue *que,int child);


//helper's helper functions 
int left(int index);
int right(int index);
int parent(int index);
void swap(nodePtr *A,nodePtr *B);


