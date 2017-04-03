/*
   Program to implemented BFS. Graph represented using Adjacency matrix.
*/

#include<stdio.h>
#include<limits.h>

#define MAX 10
#define QMAX 50

int F,R;
int Q[QMAX];
int G[MAX][MAX],S;
int P[MAX],d[MAX],status[MAX];
int n;

void insert(int);
int delete();
void getGraph();
void BFS_traversal();
void displayDistances();
void findPath();

void insert(int ele) {
	if(R==-1) {
		R=F=0;
		Q[R]=ele;
	}
	else if(R<QMAX-1) {
		R = R+1;
		Q[R] = ele;
	}
}

int delete() {
	int x;
	if(F==-1)
		x = -1;		//-1 for underflow
	else if(F==R) {
		x=Q[F];
		F=R=-1;
	}
	else{
		x=Q[F];
		F=F+1;
	}
	return x;
}

/*void displayQ() {
	int i;
	for(i=F;i<=R;i++)
		printf("%d ",Q[i]);
}*/

void getGraph() {
    int i,j;
    printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix for the graph:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	printf("\nEnter the source vertex: ");
	scanf("%d",&S);
}

void BFS_traversal() {
    int i,u,v;
    for(i=0;i<n;i++) {
		status[i] = 0;
		P[i] = -1;		//-1 for NULL
		d[i] = INT_MAX;
	}
	d[S]=0;
	F=R=-1;
	insert(S);
	status[S] = 1;
	//displayQ();
	while(F!=-1) {
		u = delete(Q);
		for(i=0;i<n;i++) {
			if(G[u][i]==1 && status[i] == 0) {
				insert(i);
				//displayQ();
				status[i]=1;
				P[i] = u;
				d[i] = d[u]+1;
			}
		}
		status[u] = 2;
	}
}

void displayDistances() {
    int i;
	printf("\nDistance for %d to every other vertex is:\n",S);
	for(i=0;i<n;i++){
        findPath(S,i);
        printf(" : %d\n",d[i]);
	}
}

void findPath(int u,int v) {
    if(v==u){
        printf("%d",u);
        return;
    }
    findPath(u,P[v]);
    printf(" -> %d  ",v);

}

void main() {
	getGraph();
	BFS_traversal();
	int i;
	displayDistances();

}


