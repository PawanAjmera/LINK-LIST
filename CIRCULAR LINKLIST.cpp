#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *add;
};

struct node*

start=NULL, *temp, *New, *next, *prev;


void create();
void insert();
void Delete();
void display();
int main()

{
	int ch;
	
	
	do
	{
		printf("press 1 for create\n");
		printf("press 2 for insert\n");
		printf("press 3 for Delete\n");
		printf("press 4 for display\n");
		printf("press 5 for exit\n");
		printf("enter your choice");
		scanf("%d", &ch);
		switch(ch)
{
	case 1:create(); break;
	case 2:insert(); break;
	case 3:Delete(); break;
	case 4:display(); break;
	case 5: break;
	default : printf("invalid choice");
		}		
	}
	while(ch!=5);
}
//CREATE

void create()
{
	int n;
	char ch;
	printf("enter a value");
	scanf("%d",&n);
	start=(struct node*)malloc(sizeof(struct node));
	start->data=n;
	start->add=NULL;
	temp=start;
	printf("To add more data,press  'Y' ");
	scanf("%c", &ch);
	while(ch=='Y'||ch=='y');
	{
		printf("%d",&n);
		New=(struct node*)malloc(sizeof(struct node));
		New->data=n;
		New->add=NULL;
		temp->add=New;
		temp=New;
		printf("\n to add more values,press 'Y'");
		scanf("%c",&ch);
	
	}
	
}

//Display

void display()
{
	
	if(start==NULL)
	{
		printf("list is empty, create a list\n");
		
	}


else
{


	temp=start;
	
	do
	
	{
		printf("%d\t",temp->data);
		temp=temp->add;
	}
	
while(temp!=start);

}

}

//INSERT

void insert()

{
	int n,pos,i=1,count=0;
	if(start==NULL)
	{
		printf("list not created,create a list first\n");
	}
	
	else
	
	{
		printf("enter a value");
		scanf("%d",&n);
		New=(struct node*)malloc(sizeof(struct node));
		New->data=n;
		New->add!=start;
		
		printf("enter a position");
		scanf("%d",&pos);
		
		if(pos==1)
		
		{
			temp=start;
			while(temp->add=start)
			{
				temp=temp->add;
				
			}
			temp->add=New;
			start=New;
		}
	
	
	 else
	
	{
		temp=start;
		
		do
		
		{
			count++;
			temp=temp->add;
			
		}
		while(temp!=start);
		if(pos>count+1)
		{
			printf("\n invalid position,enter a valid<=%d,count+1");
		}
		else if(pos==count+1)
		{
			temp =start;
			while(temp->add!=start)
			{
				temp=temp->add;
			}
			temp->add=New;
			
		}
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
}

//DELETE

void Delete()
{
	int i=1,count=0,pos;
	if(start==NULL)
	{
		printf("list not created");
	}
	else
	{
		printf("enter a position");
		scanf("%d",&pos);
		if(pos==1)
		{
			temp=start;
			while(temp->add=start)
			{
				temp=temp->add;
			}
			temp->add=start->add;
			temp=start;
			start=start->add;
			printf("deleted data = %d,temp->data");
			free(temp);
		}
		else
		{
			temp=start;
			
			do
			{
				count++;
				temp=temp->add;
			}
			while(temp!=start);
			if(pos>count+1)
			{
		printf("\n invalid position,enter a valid<=%d", count);
    }
         else if(pos==count)
         {
         	next=start;
         	do
         	{
         		prev=next;
         		next=next->add;
			 }
			 while(next->add!=start);
			 printf("deleted data=%d",next->data);
			 free(next);
			 
			 prev->add=start;
		 }
		 else
		 {
		 	next=start;
		 	while(i<pos)
		 	
		 	{
		 		prev=next;
		 		next=next->add;
		 		i++;
			 }
			 temp=next;
			 next=next->add;
			 printf("deleted data=%d",temp->data);
			 free (temp);
			 prev->add=next;
		 }
		}
	}
}



