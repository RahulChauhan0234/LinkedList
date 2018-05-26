#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL;

struct node* creat_list(struct node* Head);
void display_list(struct node* Head);
struct node* reveres_list(struct node* Head);
void display_nth_node_from_last(struct node *HEAD,int node_num);

void main()
{
	int choice,node_num;
	while(1)
	{
		printf("enter the choice:\n0: create the linked-list\n1: Display the node\n2: Reverse Linked List\n3: exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("you choose create a link option");
				start=creat_list(start);
				break;
			case 1:
				printf("you choose Display option");
				display_list(start);
				break;
			case 2:
				printf("you choose Reverse option");
				start = reveres_list(start);
				break;
			case 4:
				printf("you want to print nth node from last \nenter the node node number");
				scanf("%d",&node_num);
				display_nth_node_from_last(start, node_num);
				break;
			case 3:
				printf("you choose exit option");
				break;
			default:
				printf("choose correct options from the list");

		}
		if(choice==3)
			break;
	}
}
void display_nth_node_from_last(struct node *HEAD,int node_num)
{
	struct node *next,*prev;
	next=HEAD;
	prev=HEAD;
	for(int i=0;i<node_num;i++)
	{
		next=next->link;	
	}
	while(next !=NULL)
	{
		next=next->link;
		prev=prev->link;	
	}
	printf("%d",prev->data);



}
struct node* reveres_list(struct node* Head)
{
	struct node *next,*prev,*ptr;
	prev = NULL;
	ptr = Head;
	while(ptr !=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	Head=prev;	
	return Head;
}

struct node* creat_list(struct node* Head)
{
	struct node *node,*temp;
	int nodeData,node_number,i;
	printf("enter the Number of nodes");
	scanf("%d",&node_number);
	for(i=0;i<node_number;i++)
	{
		node= (struct node*) malloc(sizeof(struct node));
		printf("fill the data to node");
		scanf("%d",&nodeData);
		node->data = nodeData;
		node->link = NULL;
		if(Head==NULL)
		{
			Head=node;
		}
		else
		{	
			temp->link = node;
		}
		temp=node;
	}
	return Head;
}

void display_list(struct node* Head)
{
	struct node *temp;
	if(Head == NULL)
	{
		printf("Empty List");
	}
	else
	{
		temp=Head;
		while( temp!=NULL )
		{
			printf("%d\t",temp->data);	
			temp=temp->link;
		}
	}
}
















