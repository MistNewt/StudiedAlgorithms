/* WAP to convert a infix expression to postfix.*/

#include<stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top=-1;
void PUSH(char);
char POP();
int precedence(char);
void convert(char [],char[]);
int IsAlNum(char);

void PUSH(char ele)
{
	if(top==MAX-1)
	{
		printf("Can't PUSH!! OVERFLOWED!!\n");
		return;
	}
	else
	{
		top+=1;
		stack[top]=ele;
	}
}
char POP()
{
	if(top==-1)
	{
		//printf("Can't POP!! UNDERFLOWED!!\n");
		return 0;
	}
	else
	{
		top-=1;
		return stack[top+1];
	}
}

int precedence(char c)
{
	int x=0;
	switch(c)
	{
		case '+':
		case '-':x=1;
			 break;
		case '*':
		case '/':x=2;
			 break;
		case '^':x=3;
	}
	return x;
}
void convert(char infix[],char post[])
{
	int i,j,len;
	char x;
	PUSH('(');
	len=strlen(infix);
	infix[len]=')';
	infix[len+1]='\0';
	i=j=0;
	while(infix[i]!='\0')
	{
		if(IsAlNum(infix[i]))
			post[j++]=infix[i];
		else if(infix[i]=='(')
			PUSH(infix[i]);
		else if(infix[i]==')')
		{
			while((x=POP())!='(')
				post[j++]=x;
		}
		else
		{
			while(precedence(infix[i])<=precedence(x=POP())&&x!=0)
				post[j++]=x;
			PUSH(x);
			PUSH(infix[i]);
		}
		i++;
	}
	post[j]='\0';
}
int IsAlNum(char c)
{
	if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
		return 1;
	if(c<='9'&&c>='0')
		return 1;
	return 0;
}
void main()
{
	char P[MAX],Q[MAX];
	printf("Enter an infix expression: ");
	scanf(" %[^\n]s",Q);
	convert(Q,P);
	printf("Postfix expression :\n%s\n",P);
}



