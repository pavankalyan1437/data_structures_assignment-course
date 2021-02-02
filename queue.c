#include<stdio.h>
#include<stdlib.h>
struct que
{
	int f;
	int r;
	int size;
	int a[20];
};
void enque(struct que *q)
{
	if(q->r==q->size-1)
		printf("queue is full\n");
	else
	{
		int ele;
		printf("enter element:");
		scanf("%d",&ele);
		q->r++;
		q->a[q->r]=ele;
	}
}
void deque(struct que *q)
{
	if(q->r==q->f)
		printf("queue is empty\n");
	else
	{
		q->f++;
		printf("dequed element:%d\n",q->a[q->f]);
	}
	
}
void main()
{
	struct que *q;
	q=(struct que*)malloc(sizeof(struct que));
	q->r=-1;
	q->f=-1;
	q->size=20;
	int op;
	printf("1.enque 2.deque 3.exit\n");
	do{
	printf("enter option:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			enque(q);
			break;
		case 2:
			deque(q);
			break;
		case 3:
			break;
		default:
			printf("invalid option\n");
	}}while(op!=3);
}
	
	
	
