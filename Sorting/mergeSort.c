/*
   Program to implement merge sort in a random array
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define MAX 1000000

void combine(int A[],int lb,int q,int ub) {
	int B[MAX/2+1],C[MAX/2+1];
	int n1=q-lb+1;		//size of 1st temp array
	int n2=ub-q;		//size of 2nd temp array
	int i,j,k;
	B[n1]=INT_MAX;	
	C[n2]=INT_MAX;
	for(i=0;i<n1;i++)
		B[i]=A[lb+i];
	for(i=0;i<n2;i++) 
		C[i]=A[q+i+1];
	i=j=0;
	for(k=lb;k<=ub;k++) {
		if(B[i]<C[j]) {
			A[k]=B[i];
			i++;
		}
		else {
			A[k]=C[j];
			j++;
		}
	}
}

void mergeSort(int A[],int lb,int ub) {
	int q;
	if(lb<ub) {
		q=(ub+lb)/2;
		mergeSort(A,lb,q);
		mergeSort(A,q+1,ub);
		combine(A,lb,q,ub);
	}
}

void getArray(int A[],int N) {
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++)
		A[i]=random()%N;
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
	mergeSort(A,0,N-1);
	//dispArray(A,N);
}
		
