#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node *left;
	struct node *right;
};
struct queue
{
	struct node *a[20];
	int f;
	int r;
};
void enque(struct queue *q,struct node *ele)
{
	q->r++;
	q->a[q->r]=ele;
}
struct node *deque(struct queue *q)
{
	if(q->f==q->r)
		return NULL;
	else
	{
		q->f++;
		return q->a[q->f];
	}
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;
}
void insert(struct node **root,int ele)
{
	if(*root==NULL)
	{
		*root=(struct node *)malloc(sizeof(struct node));
		(*root)->e=ele;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else
	{
		struct node *temp,*temp1;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->e=ele;
		temp->left=NULL;
		temp->right=NULL;
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		enque(q,*root);
		while(!isempty(q))
		{
			temp1=deque(q);
			if(temp1->left!=NULL)
				enque(q,temp1->left);
			else
			{
				temp1->left=temp;
				break;
			}
			if(temp1->right!=NULL)
				enque(q,temp1->right);
			else
			{
				temp1->right=temp;
				break;
			}
		}
	}
}
struct node* find(struct node *root,int ele)
{
		//printf("entered find\n");
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		struct node *temp;
		int f;
		q->r=-1;
		q->f=-1;
		if(root==NULL)
			return NULL;
		enque(q,root);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left!=NULL)
	 			enque(q,temp->left);
	 		if(temp->right!=NULL)
	 			enque(q,temp->right);
	 		if(temp->e==ele)
			{	f=1;
				break;}
		}
		if(f==1)
			return temp;
		else
			return NULL;
}
struct node* findlast(struct node *root)
{
		//printf("entered find last\n");
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		struct node *temp1;
		q->r=-1;
		q->f=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp1=deque(q);
			if(temp1->left!=NULL)
	 			enque(q,temp1->left);
	 		if(temp1->right!=NULL)
	 			enque(q,temp1->right);
	 		if(temp1->right==NULL && temp1->left==NULL)
	 			return temp1;
	 		
		}
}
struct node* findparent(struct node *root,struct node *temp1)
{
		//printf("entered findparent\n");
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		struct node *temp;
		q->r=-1;
		q->f=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left==temp1)
	 			return temp;
	 		else if(temp->left!=NULL)
	 			enque(q,temp->left);
	 		if(temp->right==temp1)
	 			return temp;
	 		else if(temp->right!=NULL)
	 			enque(q,temp->right);
	 		
		}
		return NULL;
}
void delete(struct node **root,int ele)
{
	struct node *temp,*temp1,*temp2;
	temp=find(*root,ele);
	 if(temp!=NULL)
	 {
	 	temp1=findlast(*root);
	 	temp2=findparent(*root,temp1);
	 	temp->e=temp1->e;
	 	if(temp2->left==temp1)
	 		temp2->left=NULL;
	 	else
	 		temp2->right=NULL;
	 }
	else
	 	printf("element not found\n");
}
void print(struct node *root)
{
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		struct node *temp;
		q->r=-1;
		q->f=-1;
		if(root!=NULL)
			enque(q,root);
		else
			print("Empty\n");
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left!=NULL)
	 			enque(q,temp->left);
	 		if(temp->right!=NULL)
	 			enque(q,temp->right);
	 		printf("%d",temp->e);
	 		printf("\n");
		}
}
void printc(struct node *root)
{
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		struct node *temp;
		q->r=-1;
		q->f=-1;
		if(root!=NULL)
			enque(q,root);
		int c=0;
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left!=NULL)
	 			enque(q,temp->left);
	 		if(temp->right!=NULL)
	 			enque(q,temp->right);
	 		c++;
		}printf("%d\n",c);
}
void main()
{
	struct node *root=NULL,*temp;
	int op,ele;
	printf("options 1.insert 2.delete 3.find 4.print 5.print_count 6.exit\n");
	do{
	printf("enter your option:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("enter element:");
			scanf("%d",&ele);
			insert(&root,ele);
			break;
		case 2:
			printf("enter element:");
			scanf("%d",&ele);
			delete(&root,ele);
			break;
		case 3:
			printf("enter element:");
			scanf("%d",&ele);
			temp=find(root,ele);
			if(temp!=NULL)
				printf("element found\n");
			else
				printf("ele not found\n");
			break;
		case 4:
			print(root);
			break;
		case 5:
			printc(root);
			break;
		case 6:
			break;
	}
	}while(op!=6);
}

		
