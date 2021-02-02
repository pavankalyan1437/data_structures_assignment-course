#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node *next;
};
void inserthead(struct node**head)
{
	int ele;
	printf("enter element");
	scanf("%d",&ele);
	if(*head==NULL)
	{
		*head=(struct node *)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=head;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		struct node *nn;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=*head;
		temp->next=nn;
	}
}
void inserttail(struct node**head)
{
	int ele;
	printf("enter element");
	scanf("%d",&ele);
	struct node *temp=*head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->e=ele;
	nn->next=*head;
	temp->next=nn;
}
void insertpos(struct node**head)
{
	int pos,ele;
	printf("enter element position");
	scanf("%d%d",&pos,&ele);
	struct node *temp=*head;
	int c=0;
	while(c<pos-1)
	{
		if(temp->next!=*head)
		{
			temp=temp->next;
			c++;
		}
		else
		{
			printf("element not found");
			break;
		}
	}
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->e=ele;
	nn->next=temp->next;
	temp->next=nn;
}
void insertmid(struct node**head)
{
	int ele;
	printf("enter element position");
	scanf("%d",&ele);
	struct node *temp=*head;
	struct node *temp1=*head;
	int c=0,pos=0,mid;
	while(temp1!=*head)
	{
		temp1=temp1->next;
		pos++;
	}
	mid=pos/2;
	while(c<mid)
	{
		if(temp->next!=*head)
		{
			temp=temp->next;
			c++;
		}
		else
		{
			printf("element not found");
			break;
		}
	}
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->e=ele;
	nn->next=temp->next;
	temp->next=nn;
}
void remelement(struct node**head)
{
	struct node *temp1=*head;
	struct node *temp=*head;
	int f=0,ele;
	printf("enter element");
	scanf("%d",&ele);
	while(temp!=*head)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		temp=temp->next;
	}
	if(f==1)
	{
		if((*head)->e==ele)
			(*head)=(*head)->next;
		else if(temp1->next!=temp)
		{
		while(temp1->next!=temp)
		{
			temp1=temp1->next;
		}
		temp1->next=temp->next;
		}
	}
	else
		printf("element not found");
}
void rempos(struct node**head)
{

	struct node *temp1=*head;
	struct node *temp=*head;
	int c=0,pos;
	printf("enter position");
	scanf("%d",&pos);
	while(c<pos-1)
	{
		if(temp->next!=*head)
		{
			temp=temp->next;
			c++;
		}
		else
		{
			printf("position not found");
			break;
		}
	}
	if(c==pos-1)
	{
		if((*head)->next==temp)
			(*head)=(*head)->next;
		else
		{
		while(temp1->next!=temp)
		{
			temp1=temp1->next;
		}
		temp1->next=temp->next;
		}
	}
}
void findele(struct node**head)
{
	int ele,c=0;
	printf("enter element to search:");
	scanf("%d",&ele);
	struct node *temp=*head;
	while(temp!=*head)
	{
		if(temp->e==ele)
		{
			printf("element present");
			c++;
			break;
		}
		else
			temp=temp->next;
	}
	if(c==0)
		printf("element not found");
}		

void main()
{
	struct node *head=NULL;
	int op;
	printf("opttions\n1.insert at start\n2.insert at end\n3.insert at middle\n4.instert at position\n5.remove an elemnt\n6.remove at position\n7.find an element\n");
	scanf("%d",&op);
	do{
	switch(op)
	{
	case 1:
		inserthead(&head);
		break;
	case 2:
		inserttail(&head);
		break;
	case 3:
		insertmid(&head);
		break;
	case 4:
		insertpos(&head);
		break;
	case 5:
		remelement(&head);
		break;
	case 6:
		rempos(&head);
		break;
	case 7:
		findele(&head);
		break;
	case 8:
		break;
	default:
		printf("please choose correct option");
	}}while(op!=8);
}
