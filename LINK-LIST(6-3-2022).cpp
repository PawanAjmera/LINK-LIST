#include<stdio.h>
#include<cstdlib>
#define maxsize 10

struct node
{
	int data;
	struct node *add;
};

struct node *start =NULL, *temp,
*New, *next, *prev;

void create();
void insert();
void Delete();
void display();

int main()
{
	int ch;
	
	do
{
		printf("\n ------------------queue------------------");
		printf("\nPress 1 for Create operation\n");
		printf("\nPress 2 for insert operation\n");
		printf("Press 3 for Delete operation\n");
		printf("Press 4 for display operation\n");
		printf("Press 5 for Exit operation\n");
		
		printf("Enter your Choice:-");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:create();break;
			case 2:insert();break;
			
//			case 3:Delete();break;
//			case 4:display();break;
			default:printf("Invalid choice");
		}
}
while(ch<5);
}

//CREATE
void create()
{
	int n;
	char ch;
	printf("Enter a value:-");
	scanf("%d",&n);
	
	start =(struct node*)malloc(sizeof(struct node));
	
	start->data=n;
	start->add=NULL;
	temp=start;
	
	printf("To add more data press'y'");
	scanf("%c",&ch);
	
	while(ch=='y'||ch=='Y')
	{
		printf("Enter next vlaue");
		scanf("%d",&n);
		New =(struct node*)malloc(sizeof(struct node));
		
		New->data=n;
		New->add=NULL;
		temp = New;
		printf("To add more data,press'y'");
		scanf("%c",&ch);
	}		
	}
	//INSERT
	void insert()
	{
		int n, pos, i=1, count=0;
		if(start==NULL)
		{
			printf("List not created");
			
		}
		else
		{
			printf("Enter a value");
			scanf("%d",&n);
			
			New =(struct node*)malloc(sizeof(struct node));
			New->data=n;
			New->add=NULL;
			
			printf("Enter a position:-");
			scanf("%d",&pos);
			
			if(pos==1)
			{
				New->add=start;
				start=New;
				
			}
			else
			{
				temp=start;
				while(temp!=NULL)
				{
					count++;
					temp=temp->add;
				}
			}
			if(pos>count+1)
			{
				printf("invalid pos.enter a vaue=<%d",count+1);
			}
				//add node position
				
				else if(pos==count+1)
				{
					temp=start;
					while(temp->add!=NULL)
					{
						temp=temp->add;
					}
					temp->add=New;
				}
				//ADD NODE FOR MID POSITION 
				else
				{
					next=start;
					while(i<pos)
					{
						prev=next;
						next=next->add;
						i++;
						
					}
					prev->add=New;
					New->add=next;

				}
			}
		}
		
//DELETE
	
void Delete()
{
	int i=1, count=0, pos;
	if(start==NULL)
	{
		printf("List not created,create a list first");
		
	}
	else
	{
		printf("Enter a position");
		scanf("%d",&pos);
		
		if(pos==1)
		{
			temp=start;
			start=start->add;
			printf("Deleted data= %d",temp->data);
			free(temp);
		}
			else
			{
			temp=start;
			while(temp!=NULL)
			{
			 count++;
			 temp=temp->add;	
			}
		}
		if(pos>count)
		{
			printf("Invalid Choice it should be a =%d",count);
		}
		//DELETE AT THE LAST POSITION
		
		else if(pos==count)
		{
			next=start;
			while(next->add!=NULL)
			{
				prev=next;
				next=next->add;
			}
			printf("Deleted data=%d",next->data);
			free(next);
			prev->add=NULL;
		}
		//DELETE AT THE MID POSITION
		
		else
		{
			next=start;
			while(i<pos)
			{
			prev=next;
			next=next->add;
			i++;	
			}
		}
		temp=next;
		next=next->add;
		printf("Deleted data=%d",temp->data);
		free(temp);
		prev->add=next;
	}
	
		}	
		
//DISPLAY

void display()
{
	if(start==NULL)
	{
		printf("list is empty, create a list first");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->add;
		}
	}
}
		
	
		
		
	

