/* Stack implementation via single linked list */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;		
}*front;

struct node*  push();
struct node* pop();
void display(struct node*);
void main()
{
	int choice;
	struct node *frontnode;
	front=NULL;
	while(1)
	{
   	printf("we are going to implement Stack\npress1:push\npress2:POP\npress3:Display\npress4:Exit\n");
	scanf(" %d",&choice);
	while(getchar() != '\n');  
	printf("choice:%d",choice);
   	switch(choice)
	{
		case 1:
			frontnode=push();
		break;
		case 2:
			frontnode=pop(front);
		break;
		case 3:
			printf("Data in Stack:\n");
			display(frontnode);
			
		break;
		case 4:
			printf("exited\n");
		break;
		default:
			printf("Please enter the correct choice\n");
		break;
	}
	if(choice ==4)
		break;
	}
}

struct node* push()
{
	struct node *newnode;
	char ch;

	do{
	newnode= (struct node*) malloc (sizeof(struct node));
	printf("enter the data which you want to push\n");
	scanf("%d",&newnode->data);
	printf("push(%d)\n",newnode->data);
	newnode->link=front;
	front=newnode;
	printf("enter y for continue push or n for exiti\n");
	scanf(" %c",&ch);
	}while(ch == 'y');
	return front;
}

void display(struct node* front)
{
	struct node *tmp;
	tmp=front;
	if(tmp==NULL)
	{
		printf("[none]\n");
	}
	else
	{	
		while(tmp !=NULL)
		{
	 		printf("[%d]\n",tmp->data);
	 		tmp=tmp->link;
		}
	}
}

struct node* pop()
{
	struct node *tmp;
	tmp=front;
	if(front!=NULL)
	{
		printf("pop(%d)\n",tmp->data);
		front=tmp->link;
		free(tmp);
		return front;
	}
	else
	{
		printf("empty stack\n");
		return NULL;
	}
}



