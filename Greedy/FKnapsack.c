/* Program to implement fractional knapsack problem
   using Greedy algorithm.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 50

struct item {
	int id;
	int profit,weight;
	float ratio;
};

typedef struct item item;

void copy(item *t1,item *t2){	//Copies t2 to t1
	t1->id = t2->id;
	t1->profit = t2->profit;
	t1->weight = t2->weight;
	t1->ratio = t2->ratio;
}


void swap(item *t1,item *t2) {
	item t3;
	copy(&t3,t1);
	copy(t1,t2);
	copy(t2,&t3);
}

/*void displayObjects(item object[],int n) {
	int i;
	for(i=0;i<n;i++)
		printf("%d: %d %d %f\n",object[i].id,object[i].profit,object[i].weight,object[i].ratio);
}*/

void main() {
	int i,j;
	int N;
	double m,U;
	item object[MAX];
	double X[MAX];
	printf("\nEnter KnapSack capacity: ");
	scanf("%lf",&m);
	printf("\nEnter the number of objects: ");
	scanf("%d",&N);
	for(i=0;i<N;i++) {
		printf("Enter Profit and Weight of object %d: ",(i+1));
		scanf("%d",&object[i].profit);
		scanf("%d",&object[i].weight);
		object[i].id=i+1;
		object[i].ratio = ((float)object[i].profit)/object[i].weight;
	}
	//Sorting according to P/W ratio
	//printf("\nBefore sorting:\n");
	//displayObjects(object,N);
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			if(object[i].ratio < object[j].ratio) {
				swap(&object[i],&object[j]);
			}
		}
	}
	//printf("\nAfter sorting:\n");
	//displayObjects(object,N);

	for(i=0;i<N;i++)
		X[i]=0.0;
	U=m;
	for(i=0;i<N;i++) {
		if(object[i].weight > U)
			break;
		X[i]=1;
		U = U-object[i].weight;
	}
	if(i<N)
		X[i]=U/object[i].weight;
	for(i=0;i<N;i++)
		printf("\nSelected Object %d:%0.2lf%% ",object[i].id,X[i]*100);
	printf("\n");
}


