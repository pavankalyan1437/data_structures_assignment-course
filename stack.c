#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top;
	int size;
	int a[20];
};
void push(struct stack *s)
{
	if(s->top==s->size-1)
		printf("stack is full");
	else{
	int ele;
	printf("enter element");
	scanf("%d",&ele);
	s->top++;
	s->a[s->top]=ele;
	}
}
void pop(struct stack *s)
{
	if(s->top==-1)
		printf("stack is empty");
	else
		printf("%d",s->a[s->top--]);
}
void main()
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	int op;
	printf("1.push 2.pop 3.exit");
	do{
	printf("enter option:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			push(s);
			break;
		case 2:
			pop(s);
			break;
		case 3:
			break;
		default:
			printf("invalid option");
	}}while(op!=3);
}
