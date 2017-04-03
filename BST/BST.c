/*i>	 Menu Driven Program to implement a BST having the formal operations INSERT, DISPLAY and DELETE
  ii>	 Find minimum, maximum and search operation
*/

#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int info;
	struct NODE *right,*left;
};
typedef struct NODE NODE;

NODE * createNewNode(int item) {
	NODE * newNode = (NODE*)malloc(sizeof(NODE));
	newNode->info=item;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}

NODE * insert(NODE *t,int item)
{
	if(t==NULL)
	{
		t=createNewNode(item);
		return t;
	}
	else
	{
		if(item < t->info)
			t->left=insert(t->left,item);
		else
			t->right=insert(t->right,item);
		return t;
	}
}

void preDISP(NODE *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->info);
		preDISP(t->left);
		preDISP(t->right);
	}
}

void postDISP(NODE *t)
{
	if(t!=NULL)
	{
		postDISP(t->left);
		postDISP(t->right);
		printf("%d ",t->info);
	}
}

void inDISP(NODE *t)
{
	if(t!=NULL)
	{
		inDISP(t->left);
		printf("%d ",t->info);
		inDISP(t->right);
	}
}

NODE * search(NODE *t,int ele)
{
	if(t!=NULL)
	{
		if(t->info==ele)
			return t;
		else if(ele < t->info)
			return search(t->left,ele);
		else
			return search(t->right,ele);
	}
}
NODE * findMIN(NODE *t)
{
	if(t!=NULL)
	{
		if(t->left==NULL)
			return t;
		else
			return findMIN(t->left);
	}
}
NODE * findMAX(NODE *t)
{
	if(t!=NULL)
	{
		if(t->right==NULL)
			return t;
		else
			return findMAX(t->right);
	}
}

NODE * delete(NODE *t,int ele)
{
	NODE *temp;
	if(t==NULL)
		printf("\nElement not found!!");
	else if(ele < t->info)
		t->left=delete(t->left,ele);
	else if(ele > t->info)
		t->right=delete(t->right,ele);
	else
	{
		if(t->left!=NULL && t->right!=NULL)
		{
			temp=findMIN(t->right);
			t->info=temp->info;
			t->right=delete(t->right,t->info);
		}
		else
		{
			temp=t;
			if(t->left==NULL)
			{
				t=t->right;
				return t;
			}
			if(t->right==NULL)
			{
				t=t->left;
				return t;
			}
			free(temp);
		}
		return t;
	}
	return t;
}
main()
{
	NODE *ROOT=NULL,*t;
	int ch,ele;
	while(1)
	{
		printf("\n*****MENU*****");
		printf("\n1.INSERT\n2.IN-ORDER DISPLAY\n3.PRE-ORDER DISPLAY");
		printf("\n4.POST-ORDER DISPLAY\n5.DELETE\n6.SEARCH\n7.FIND MAX\n8.FIND MIN");
		printf("\n9.EXIT");
		printf("\n**************");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter an element: ");
			       scanf("%d",&ele);
			       ROOT=insert(ROOT,ele);
			       break;
			case 2:inDISP(ROOT);
			       break;
			case 3:preDISP(ROOT);
			       break;
			case 4:postDISP(ROOT);
			       break;
			case 5:printf("\nEnter key element: ");
			       scanf("%d",&ele);
			       delete(ROOT,ele);
			       break;
			case 6:printf("\nEnter key element: ");
			       scanf("%d",&ele);
			       t=search(ROOT,ele);
			       if(t==NULL)
				       printf("Element not found");
			       else
				       printf("FOUND!!");
			       break;
			case 7:t=findMAX(ROOT);
			       if(t==NULL)
				       printf("\nNo elements in tree!!");
			       else
				       printf("\nMax. element: %d",t->info);
			       break;
			case 8:t=findMIN(ROOT);
			       if(t==NULL)
				       printf("\nNo elements in tree!!");
			       else
				       printf("\nMin. element: %d",t->info);
			       break;
			case 9:exit(0);

			default:printf("\nWrong choice.Try again!!");
		}
	}
	printf("\n");
}



