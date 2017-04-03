/*
   Program to implement HEAPSORT algorithm and find its
   time complexity.

 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 2000000

#define left(i) 2*i+1			//Macros for heap-related notations
#define right(i) 2*i+2
#define parent(i) (i-1)/2

int heapSize;

void swap(int A[],int i,int j) {	//Swaps the i and j elements of A
	int t=A[i];
	A[i]=A[j];
	A[j]=t;
}

void heapify(int A[],int i) {		//Heapify function
	int l=left(i);
	int r=right(i);
	int large;
	if(l<=heapSize && A[l] > A[i])
		large=l;
	else
		large=i;
	if(r<=heapSize && A[r] > A[large])
		large=r;
	if(large!=i) {
		swap(A,large,i);
		heapify(A,large);
	}
}

void buildHeap(int A[],int length) {	//Builds the heap
	int i;
	heapSize=length;
	for(i=(length+1)/2;i>=0;i--)
		heapify(A,i);
}

void heapSort(int A[],int length) {	//Main sort algorithm
	int i;
	buildHeap(A,length);
	for(i=length;i>=1;i--) {
		swap(A,0,i);
		heapSize = heapSize-1;
		heapify(A,0);
	}
}

void getArray(int A[],int N) {		//Generates array
	int i;
	srand(time(NULL));
	for(i=0;i<N;i++)
		A[i]=random()%N;
}

/*void displayArray(int A[],int N) {
	int i;
	printf("\nArray elements:\n");
	for(i=0;i<N;i++)
		printf("%d ",A[i]);
	printf("\n");
}*/

void main(int argc, char * argv[]) {
	int A[MAX],N;
	if(argc<2) {
		printf("\nEnter the size of array.");
		exit(0);
	}
	N=atoi(argv[1]);
	getArray(A,N);
	heapSort(A,N-1);
	//displayArray(A,N);
}

