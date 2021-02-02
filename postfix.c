#include<stdio.h>
struct stack
{
	int top;
	char a[50];
	int size;
};
void push(struct stack *s,char ele)
{
	if(s->top==s->size-1)
		printf("stock is full\n");
	else
	{
		s->top++;
		s->a[s->top]=ele;
	}
}
char pop(struct stack *s)
{
		return s->a[s->top--];
}	
int isempty(struct stack *s)
{
	if(s->top==-1)
		return 0;
	else
		return 1;
}
int priority(char b)
{
	if(b=='(')
		return 0;
	else if(b=='+' || b=='-')
		return 1;
	else if(b=='*' || b=='/')
		return 2;
}
int top(struct stack s)
{
	if(s.top==-1)
		return 0;
	else
		return priority(s.a[s.top]);
}

void main()
{
	char exp[50];
	struct stack s;
	s.top=-1;
	s.size=50;
	printf("enter expression:");
	scanf("%s",exp);
	char *e;
	e=exp;
	while(*e!='\0')
	{
		if(*e=='(')
		{	
			push(&s,'(');
		}
		else if(*e=='+' || *e=='-' || *e=='*' || *e=='/')
		{
			while(top(s)>=priority(*e))
				printf("%c",pop(&s));
			push(&s,*e);
		}
		else if(*e==')')
		{
			while(s.a[s.top]!='(')
				printf("%c",pop(&s));
			pop(&s);
		}
		else
			printf("%c",*e);
		e++;
	}
	while(isempty(&s)!=0)
	{
		printf("%c",pop(&s));
	}
}
