/* 
   Program to implement Naive String Matching algorithm
*/

#include<stdio.h>
#include<string.h>

#define MAX 50

int occur[MAX];
int ctr=0;

void matchString(char text[],char pattern[]) {
	int n = strlen(text);
	int m = strlen(pattern);
	int s,i;
	for(s=0;s<=n-m;s++) {
		for(i=0;i<m;i++)
			if(pattern[i]!=text[s+i])
				break;
		if(i==m)
			occur[ctr++] = s;
	}
}

void main() {
	int i;
	char text[MAX],pattern[MAX];
	printf("\nEnter text: ");
	scanf(" %s",text);
	printf("\nEnter pattern: ");
	scanf(" %s",pattern);
	matchString(text,pattern);
	printf("\nNo. of occurances of pattern: %d",ctr);
	if(ctr!=0) {
		printf("\nOccurances:\n");
		for(i=0;i<ctr;i++) 
			printf("%d ",occur[i]);
	}
	printf("\n");

}
