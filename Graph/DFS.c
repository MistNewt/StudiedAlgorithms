/*
   Program to implement DFS. Given adjacency matrix.
*/

#include<stdio.h>
#include<limits.h>

#define MAX 10

int status[MAX],P[MAX],d[MAX];
int time;
int d[MAX],f[MAX];
int n;
void DFS_Visit(int G[MAX][MAX],int v) {
	status[v] = 1;
	time = time+1;
	d[v] = time;
	int i;
	for(i=0;i<n;i++){
		if(G[v][i] == 1 && status[i] == 0) {
			P[i] = v;
			DFS_Visit(G,i);
		}
	}
	status[v] = 2;
	time = time+1;
	f[v] = time;
}

void findPath(int v) {
    if(v==-1)
        return;
    findPath(P[v]);
    printf(" -> %d  ",v);

}

void main() {
	int G[MAX][MAX];
	int i,j;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	for(i=0;i<n;i++) {
		status[i] = 0;
		P[i] = -1;
	}
	time = 0;
	for(i=0;i<n;i++) {
		if(status[i] == 0)
			DFS_Visit(G,i);
	}
	/**/
    printf("\nTraversal paths:\n");
    for(i=0;i<n;i++) {
        findPath(i);
        printf("\n");
    }
    printf("\nVertices processing time:\n");
    for(i=0;i<n;i++)
		printf("for %d, start: %d end: %d\n",i,d[i],f[i]);
}
