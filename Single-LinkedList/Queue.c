#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;

}*front,*rear;

struct node* enqueue(struct node* );
void dequeue(struct node* );
void display(struct node* );
void main()
{
	int choice;
	while(1)
	{
		printf("1:enqueue\n2:dequeue\n3:Display\n4:Exit");
		scanf("%d",&choice);
		while(getchar() !='\n');
		switch(choice)
		{
			case 1:
				enqueue(front);
				break;
			case 2:
				dequeue(front);
				break;
			case 3:
				display(front);
				break;
			case 4:
				break;
			default:
				printf("choose correct options");
				break;

		}
		if(choice == 4)
			break;
	}
}

struct node* enqueue(struct node* Rear)
{
	struct node* newnode;
	newnode= (struct node*) malloc(sizeof(struct node));
	printf("enter the node data");
	scanf("%d",&newnode->data);
	if(front==NULL)
	{
		printf("empty queue");
		front=newnode;
	}	
	else
	{
		rear->link=newnode;
	}

	rear=newnode;
	newnode->link=NULL;
	return rear;


}
void dequeue(struct node* Front)
{
	struct node* tmp;
	if(front == NULL)
	{
		printf("empty queue");
	}
	else
	{
		tmp=Front;
		front=front->link;
		free(tmp);
	}

}
void display(struct node* Front)
{
	struct node *tmp;
	tmp=Front;
	while(tmp != NULL)
	{	
		printf("[%d]\n",tmp->data);
		tmp=tmp->link;
	}
	if(tmp==NULL)
	{
		printf("Empty Queue\n");
	}
}

