
/*
   Program to implement quick sort in a random array
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define MAX 1000000

int partition(int [],int,int);

void quickSort(int A[],int p,int r){
	int q;
	if(p<r)
	{
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}	
}

void exchange(int A[],int i,int j) {
	int t;
	t=A[i];
	A[i]=A[j];
	A[j]=t;
}

int partition(int A[],int p,int r) {
	int x=A[r];
	int i=p-1,j;
	for(j=p;j<r;j++) {
		if(A[j]<=x){
			i=i+1;
			exchange(A,i,j);		//Exchange A[i] <->A[j]
		}
	}
	exchange(A,i+1,r);
	return i+1;
}

void getArray(int A[],int N) {
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++)
		A[i]=random()%N;
}

void randomQuickSort(int A[],int p,int r) {		//Randomized Quick Sort
	int k;
	srand(time(NULL));
	k=p+random()%(p-r);
	exchange(A,r,k);
	quickSort(A,p,r);
}

/*void dispArray(int A[],int N) {
	int i;
	printf("\nArray elements:\n");
	for(i=0;i<N;i++) 
		printf("%d ",A[i]);
	printf("\n");
}*/

void main(int argc,char *argv[]) {
	int N,A[MAX];
	if(argc < 2) {
		printf("\nEnter the array size.\n");
		exit(0);
	}
	N=atoi(argv[1]);
	getArray(A,N);
	randomQuickSort(A,0,N-1);
//	dispArray(A,N);
}
		
