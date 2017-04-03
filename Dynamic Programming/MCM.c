/*
   Program to implement matrix chain multiplication where the order
   of matrix is given.
*/

#include<stdio.h>
#include<limits.h>

#define MAX 50

int P[MAX];
int M[MAX][MAX];
int S[MAX][MAX];
int lenP,n;

void matrixChainOrder() {					//matrix chain order algorithm
	int i,l,j,k,q;						//implementation
	n=lenP-1;
	for(i=1; i<=n;i++)
		M[i][i]=0;
	for(l=2;l<=n;l++) {
		for(i = 1;i<=n-l+1;i++) {
			j = i+l-1;
			M[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++) {
				q = M[i][k] + M[k+1][j] + P[i-1]*P[k]*P[j];	
				if( q < M[i][j]) {
					M[i][j] = q;
					S[i][j] = k;
				}
			}
		}
	}
}

void printLCS(int i,int j) {					//display the matrix multiplication order
	if(i==j)
		printf(" A%d ",i);
	else {
		printf("(");
		printLCS(i,S[i][j]);
		printLCS(S[i][j]+1,j);
		printf(")");
	}
}

void getArrayP() {						//to initialize array P
	int i;
	printf("Enter length of P: ");
	scanf("%d",&lenP);
	printf("Enter array P:\n");
	for(i=0;i<lenP;i++)
		scanf("%d",&P[i]);
}

void printMat(int M[MAX][MAX]) {				//display the matrices
	int i,j,k,ctr;
	for(j=n;j>1;j--) {
		ctr=0;
		for(i=1;i<=n-j+1;i++) {
			if(i==1)
				for(k=1;k<=j;k++)
					printf("\t");
			else printf("\t");
			printf("%d",M[i][j+ctr]);
			ctr++;
		}
		printf("\n");
	}
}


void main() {
	getArrayP();
	matrixChainOrder();
	printf("---------------------------M--------------------------\n");
	printMat(M);
	printf("\n_______________________________________________________\n");
	printf("-----------------------------S---------------------------\n");
	printMat(S);
	printf("\n________________________________________________________\n");
	printLCS(1,n);
	printf("\n");
}


