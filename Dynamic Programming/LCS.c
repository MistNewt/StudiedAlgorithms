/* 
   Program to implement longest common subsequence algorithm.
   Given sequences X and Y
*/

#include<stdio.h>
#include<string.h>

#define MAX 50

#define VER 0			//Macro defn. for B array
#define HZ 1
#define DIAG 2

int C[MAX][MAX];
int B[MAX][MAX];
char X[MAX];
char Y[MAX];
int lenX,lenY;

void LCS_Length() {						//LCS algorithm implementation
	int i,j,m,n;
	m = lenX;
	n = lenY;
	for(i=0;i<=m;i++)
		C[i][0]=0;
	for(j=1;j<=n;j++)
		C[0][j]=0;
	for(i=1;i<=m;i++) {
		for(j=1;j<=n;j++) {
			if(X[i-1]==Y[j-1]) {
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]=DIAG;
			}
			else if(C[i-1][j]>C[i][j-1]) {
				C[i][j]=C[i-1][j];
				B[i][j]=VER;
			}
			else {
				C[i][j]=C[i][j-1];
				B[i][j]=HZ;
			}
		}
	}
}

void PRINT_LCS(int i,int j) {					//Printing the subsequence using B array
	if(i==0 || j==0)
		return;
	if(B[i][j]==DIAG){
		PRINT_LCS(i-1,j-1);
		printf("%c ",X[i-1]);
	}
	else if(B[i][j]==VER)
		PRINT_LCS(i-1,j);
	else
		PRINT_LCS(i,j-1);
}

void LCS_INDEX(int index[MAX],int max,int *indexLen) {	//Generates the indices for
	int i,ctr=0;						//printing all subsequences
	for(i=1;i<=lenX;i++) {
		if(C[i][lenY]==max) {
			index[ctr]=i;
			ctr++;
		}
	}
	*indexLen = ctr;
}

void getArray(char A[],int n) {	//Getting the X and Y arrays
	int i;
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++) 
		scanf(" %c",&A[i]);
}

void printCMat() {
	int i,j;
	for(i=0;i<=lenX;i++){
		for(j=0;j<=lenY;j++) {
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
}

void main() {
	int index[MAX],indexLen,i,ele;
	printf("\nEnter length of X:");
	scanf("%d",&lenX);
	getArray(X,lenX);
	printf("\nEnter lenght of Y:");
	scanf("%d",&lenY);
	getArray(Y,lenY);
	
	LCS_Length();
	printCMat();
	printf("\n");
	printf("\nLeast Common Subsequences:\n");
	LCS_INDEX(index,C[lenX][lenY],&indexLen);
	for(i=0;i<indexLen;i++){
		PRINT_LCS(index[i],lenY);	
		printf("\n");
	}
}
