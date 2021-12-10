#include "priority_queue.h"
#include <malloc.h>


// helper's helper functions
int left(int index)
{
    return ((2*index)+1);
}

int right(int index)
{
    return ((2*index)+2);
}

int parent(int index)
{
    return ((index-1)/2);
}

void swap(nodePtr *A,nodePtr *B)
{
    nodePtr temp = *A;
    *A = *B;
    *B = temp;
}

// main function  needed 
Pqueue* Init_Pque(int size) 
{
    Pqueue *A = (Pqueue*)malloc(sizeof(Pqueue));
    A->Elements = (nodePtr*)malloc(size * sizeof(nodePtr));
    A->queSize = 0;

   return A;
}

void insert_Node(Pqueue *que, nodePtr element) //for pushing node 
{
    que->Elements[que->queSize] = element;
    que->queSize++;
    UpHeap(que, (que->queSize)-1);
}


nodePtr delete_Node(Pqueue *que, int index) // for poping the element 
{
    que->queSize--;
    swap(&(que->Elements[index]),&(que->Elements[que->queSize]));
    DownHeap(que,index);

    return que->Elements[que->queSize]; // returning poped node
}

// helper functions
void DownHeap(Pqueue *que,int root)
{
    int max = root;
    int leftInx = left(root);
    int rightInx = right(root);

    // selecting the max index
    max = (leftInx < que->queSize && node_comparator((que->Elements[leftInx]),(que->Elements[max]))) ? leftInx : max; // max of left and max (using ternary operator)
    max = (rightInx < que->queSize && node_comparator((que->Elements[rightInx]),(que->Elements[max]))) ? rightInx : max; //max of right and max

    if (max!=root)
    {
        swap(&(que->Elements[max]),&(que->Elements[root]));
        DownHeap(que,max);
    }
    
}


// helper functions

void UpHeap(Pqueue *que,int child)
{
    int ParentInx = parent(child);

    if (ParentInx >= 0)
    {
        if (node_comparator((que->Elements[child]),(que->Elements[ParentInx]))) 
        {
            swap(&(que->Elements[child]),&(que->Elements[ParentInx]));
            UpHeap(que,ParentInx);
        }
        
    }  
}
