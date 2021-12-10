#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "priority_queue.h"
// Hi Hope you are sound in Health ,Stay Home ,Stay Safe
// Happy Evaluating...

//global arrays
float Avgdepth[10000000];
int Maxdepth[10000000];
int MaxChildren[10000000];
//global arrays ended

void Tree_Search(node *A, int N) //tree traversal
{

    node *rootptr = A; //first node of array will always be a root (parent = -1)

    Pqueue *priqueue = Init_Pque(N);

    int j = 1; // global array iterator

    insert_Node(priqueue, rootptr);

    //variables needed for global arrays and seentime
    float depth;
    int maxdepth = rootptr->depth;
    float depthsum = 0;
    int seentime = 0;
    int max_seen = 0;
    int visited[N];
    //all the needed variables initialised

    for (int i = 0; i < N; i++) // initiating all the visited nodes to 0
        visited[i] = 0;

    while (priqueue->queSize != 0)
    {

        rootptr = delete_Node(priqueue, 0);
        //max_seen part of the global array

        visited[(rootptr->state_number - 1)] = 1;
        if (rootptr->parent != -1)
            A[rootptr->parent - 1].seen_children++;

        for (int i = 0; i < N; i++)
        {
            if (visited[i] && A[i].seen_children > max_seen)
            {
                max_seen = A[i].seen_children;
            }
        }

        MaxChildren[j - 1] = max_seen; // max_seen assigned

        //depth for global array
        depth = rootptr->depth;
        depthsum += depth;
        if (depth > maxdepth)
        {
            maxdepth = depth;
        }

        Maxdepth[j - 1] = maxdepth;
        Avgdepth[j - 1] = (depthsum / j);
        j++;
        // depth for global array end

        // printing the current node
        printf("state number == %d \t value == %d \t seentime == %d \n", rootptr->state_number, rootptr->value, rootptr->seen_time);

        for (int i = 0; i < rootptr->number_of_children; i++) //pushing all the childrens of current node of the tree
        {
            //seentime assigning
            seentime++;
            rootptr->children[i]->seen_time = seentime;
            //seentime assigned
            insert_Node(priqueue, rootptr->children[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    node *a;
    a = (node *)malloc(sizeof(node) * n);
    assert(a != NULL);

    for (int i = 0; i < n; i++)
    {
        input_node(&a[i]);
        (a[i].number_of_children) = 0;
    }

    // for(int i=0;i<n;i++)
    // {
    //     printf("%d %d %d\n",a[i].state_number,a[i].value,a[i].parent);
    // }

    for (int i = 0; i < n; i++) //linking the nodes according to the tree
    {
        a[0].seen_children = 0;
        if (a[i].parent != (-1))
        {
            int x = (a[(a[i].parent - 1)].number_of_children);
            a[(a[i].parent - 1)].number_of_children++;
            a[(a[i].parent - 1)].children[x] = &a[i];
            a[i].seen_children = 0;
            //assigning depth to each node
            int depth = 0;
            nodePtr A = &a[i];
            while (A->parent != -1)
            {
                depth++;
                int ind = ((A->parent) - 1);
                A = &(a[ind]);
            }
            a[i].depth = depth;
            // depth of a node assigned
        }
    }

    // printf("\n");
    // for(int i=0;i<n;i++)
    // {
    //     printf("value : %d , number of chil : %d, depth : %d \n",a[i].value,a[i].number_of_children,a[i].depth);
    //     for(int j=0;j<a[i].number_of_children;j++)
    //     {
    //         printf("    %d",a[i].children[j]->value);
    //     }
    //     printf("\n");
    // }

    Tree_Search(a, n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("avgdepth = %f \t maxdepth = %d \t max_children = %d\n", Avgdepth[i], Maxdepth[i], MaxChildren[i]);
    }

    return 0;
}