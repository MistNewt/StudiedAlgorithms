/* Program to implement fractional knapsack problem
   using Greedy algorithm.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 50


void main() {
	int i,j;
	int N;
	double m,U;
	int P[MAX],W[MAX],OB[MAX];
	double X[MAX];
	printf("\nEnter KnapSack capacity: ");
	scanf("%lf",&m);
	printf("\nEnter the number of objects: ");
	scanf("%d",&N);
	for(i=0;i<N;i++) {
		printf("Enter Profit and Weight of object %d: ",(i+1));
		scanf("%d",&P[i]);
		scanf("%d",&W[i]);
		OB[i]=i+1;
	}
	//Sorting according to P/W ratio
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			double rat1 = ((double)P[i])/W[i];
			double rat2 = ((double)P[j])/W[j];
			if(rat1 < rat2) {
				int t1,t2,t3;
				t1=P[i];
				t2=W[i];			//OB stores the object number
				t3=OB[i];
				P[i]=P[j];
				W[i]=W[j];
				OB[i]=OB[j];
				P[j]=t1;
				W[j]=t2;
				OB[j]=t3;
			
			}
		}
	}

	for(i=0;i<N;i++)
		X[i]=0.0;
	U=m;
	for(i=0;i<N;i++) {
		if(W[i]>U)
			break;
		X[i]=1;
		U = U-W[i];
	}
	if(i<N)
		X[i]=U/W[i];
	for(i=0;i<N;i++)
		printf("\nSelected Object %d:%0.2lf%% ",OB[i],X[i]*100);
	printf("\n");
}


