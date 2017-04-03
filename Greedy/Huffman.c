/* 
   Program to implement Huffman Code where the number of characters
   and their frequencies are given.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 26

struct NODE {
	char value;
	int freq;
	struct NODE * left,*right;
};

typedef struct NODE NODE;

NODE * createNewNode(char value,int freq) {
	NODE *nptr = (NODE *)malloc(sizeof(NODE));
	nptr->value=value;
	nptr->freq=freq;
	nptr->left = NULL;
	nptr->right = NULL;
	return nptr;
}

void sort(NODE * S[MAX],int size) {		//Selection Sort
	int i,j;
	for(i=0;i<size;i++) {
		for(j=i+1;j<size;j++) {
			if(S[i]->freq > S[j]->freq) {
				NODE *temp;
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
}


void display(NODE * root) {
	if(root!=NULL) {
		display(root->left);
		printf("%c:%d ",root->value,root->freq);
		display(root->right);
	}
}

/*void displayS(NODE *S[MAX],int n) {
	int i;
	for(i=0;i<n;i++) 
		printf("%c:%d ",S[i]->value,S[i]->freq);
}*/

void search(NODE * root,int * flag,int * k,char c) {
	if(root != NULL) {
		if(root->value == c) {
			*flag = 1;
			return;
		}
		if(root->left!=NULL && *flag == 0){
			*k = (*k)*10;
			search(root->left,flag,k,c);
		}
		if(root->right!=NULL && *flag == 0) {
			*k = (*k)*10+1;
			search(root->right,flag,k,c);
		}

		if(*flag == 0) 
			*k = (*k)/10;
			
	}
}

int getCode(NODE * root, char c) {
	int flag = 0,k=0;
	search(root,&flag,&k,c);
	if(flag == 1)
		printf("%c: %d\n",c,k);
	else
		printf("%c not found.",c);
}

void decode(NODE * root,char str[]) {
	NODE *curr=root;
	int i;
	for(i=0;i<strlen(str);i++) {
		if(str[i]=='0')
			curr = curr->left;
		else if(str[i]=='1')
			curr = curr->right;
		if(curr->left==NULL){
			printf("%c ",curr->value);
			curr=root;
		}
	}
}

void main() {
	NODE * S[MAX],*root;
	char value[MAX],str[50];
	int n,i,j,size,code[MAX];
	printf("Enter the number of characters:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char c;
		int f;
		printf("Enter the character and frequency:");
		scanf(" %c",&c);
		scanf("%d",&f);
		S[i] = createNewNode(c,f);
		value[i] = c;
	}
	
	size = n;
	//sort(S,size);
	//displayS(S,size);
	
	for(i=1;i<=n-1;i++) {
		sort(S,size);
		NODE *temp1,*temp2;
		temp1 = S[0];
		temp2 = S[1];
		S[0] = createNewNode('-',temp1->freq + temp2->freq);
		S[0]->left = temp1;
		S[0]->right = temp2;
		for(j=1;j<size;j++)
			S[j]=S[j+1];
		size-=1;
	}
	root = S[0];
	display(root);
	printf("\n");
	for(i=0;i<n;i++) 
		getCode(root,value[i]);
	printf("\n");
	printf("Enter the code: ");
	scanf(" %s",str);
	decode(root,str);
	printf("\n");
}
	
