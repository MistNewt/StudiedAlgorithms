/**
    Program to implement Dijkstra's single source shortest
    path problem.
*/

#include<stdio.h>
#include<limits.h>

#define MAX 5
#define null -1

struct NODE{
int id;
int dist;
int P;
};
typedef struct NODE NODE;

int A[MAX][MAX],V;
int W[MAX][MAX];
int size;

void getAdjMatrix(){
    int i,j;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&V);
    printf("\nEnter Adjacency matrix:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            scanf("%d",&A[i][j]);
}

void getWeightMatrix() {
    int i,j;
    printf("\nEnter the weight matrix of the graph:\n");
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++) {
            int temp;
            scanf("%d",&temp);
            if(temp == -1)
                W[i][j] = INT_MAX;
            else
                W[i][j] = temp;
        }
    }
}

NODE vertex[MAX];
NODE queue[MAX];


void init() {
    int i;
    getAdjMatrix();
    getWeightMatrix();
    for(i=0;i<V;i++) {
        vertex[i].id = i;
        vertex[i].dist = INT_MAX;
        vertex[i].P = null;
    }
    size = V;
    for(i=0;i<V;i++) {
        queue[i] = vertex[i];
    }
}

void sort() {
    int i,j;
    for(i=0;i<size;i++) {
        for(j=0;j<size-1;j++) {
            if(queue[j].dist > queue[j+1].dist) {
                NODE temp;
                temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }
}

NODE extract_min() {
    int i;
    sort();
    NODE temp = queue[0];
    for(i=1;i<size;i++)
        queue[i-1] = queue[i];
    size = size - 1;
    return temp;
}

void updateQ() {
    int i,j;
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++) {
            if(vertex[i].id == queue[j].id)
                queue[j] = vertex[i];
        }
    }
}

void dijkstra(int src) {
    int i;
    NODE u;
    vertex[src].dist = 0;
    updateQ();
    while(size!=0) {
        u = extract_min();
        for(i=0;i<V;i++) {
            if(A[u.id][i]==1){
                if(vertex[i].dist > u.dist + W[u.id][i]) {
                    vertex[i].dist = u.dist + W[u.id][i];
                    vertex[i].P = u.id;
                    updateQ();
                }
            }
        }
    }
}

void printPath(int src,int ver) {
    if(vertex[ver].P == -1 ) {
        printf("%d ",ver);
        return;
    }
    else {
        printPath(src,vertex[ver].P);
        printf(" ->%d ",ver);
    }

}

void main() {
    int src,i;
    init();
    printf("\nEnter source vertex: ");
    scanf("%d",&src);
    dijkstra(src);
    for(i=0;i<V;i++) {
        printf("Vertex: %d Id: %d Distance: %d Parent: %d\n",i,vertex[i].id,vertex[i].dist,vertex[i].P);
    }

    printf("Now finding path\n");
    for(i=0;i<V;i++){
        printPath(src,i);
        printf(": %d\n",vertex[i].dist);
    }

    printf("\nEnding");
}
