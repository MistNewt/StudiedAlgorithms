#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 1000000
void insSort(int a[],int len) {
    int i,j,key;
    for(j=1;j<len;j++) {
        key=a[j];
        i=j-1;
        while(a[i]>key && i>=0) {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}
void main(int argc, char *[]argv) {
    int array[MAX];
    int size,i;
    if(argc<=1) {
        printf("Enter the size of random array. ");
        exit(0);
    }
    size=atoi(argv[1]);
    srand(time(NULL));
    for(i=0;i<size;i++) {
        array[i]=rand()%size;
    }
    insSort(array,size);
}
