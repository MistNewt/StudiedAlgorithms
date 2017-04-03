/** Program to implement N Queen algorithm.
    Given n by the user.
*/

#include<stdio.h>

#define true 1
#define false 0
#define MAX 8

int X[MAX];
int count = 0;
int place(int k,int i) {
    int j;
    for(j=1;j<k;j++) {
        if((X[j]==i)||(abs(i-X[j])==abs(k-j)))
            return false;
    }
    return true;
}

void NQueen(int k,int n) {
    int i,j;
    for(i=1;i<=n;i++) {
        if(place(k,i)==true) {
            X[k]=i;
            if(k==n){
                for(j=1;j<=n;j++)
                    printf("%d ",X[j]);
                printf("\n");
                count++;
            }
            else
                NQueen(k+1,n);
        }
    }
}

void main() {
    int n;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    NQueen(1,n);
    printf("\nThe total number of combinations: %d",count);
}
