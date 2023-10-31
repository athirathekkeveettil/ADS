#include<stdio.h>
#include<stdlib.h>
struct node
      {
	 int data;
	 struct node *next;
         struct node *prev;

      };
 
struct node *head=NULL,*end=NULL;

struct node dummy;
void ins_beg()
     {  int data;
	struct node *temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=head;
    temp->prev=NULL;
    if(head==NULL)
	{
        end=temp;
	}
	else
	{
		head->prev=temp;
	}  
	head=temp;
     }
void ins_end()
     {
	int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	 temp=(struct node*)malloc(sizeof(dummy));
	  temp->data=data;
	  temp->next=NULL;
      end=temp;

	if(head==NULL)
	  {
        temp->prev=NULL;
	    head=temp;
        
	  }
	else
	  {
	    ptr=head;
	    while(ptr->next!=NULL)
		{
		    ptr=ptr->next;
		}
	    ptr->next=temp;
        temp->prev=ptr;
	  }
     }
void display()
     {
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr->next!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	    printf("%d th element\t %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }
     }
void dlt_strt()
	{
		struct node *dlt,*second;
		dlt=head;
		if(dlt!=NULL)
		  { 
			head=dlt->next;
			head->prev=NULL;
			printf("\n deleted element is %d \n",dlt->data);
			free(dlt);
		  }
		 else
		    printf(" linked list is empty") ;
	}
void dis_from_end()
    {
       int i=1;
	struct node *ptr;
	ptr=end;
	if(ptr!=NULL)
	  {
	    while(ptr->prev!=NULL)
	      {
	       printf("%d th element\t %d \n",i,ptr->data);
	       ptr=ptr->prev;
	       i++;
	      }
	    printf("%d th element\t %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }

 
    }
void ins_pos()
     {
	int data,pos,i;
	struct node *ptr,*swap,*temp,*nexxt;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	printf("\n enter the position");
	scanf("%d",&pos);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	  {
		printf("no");
	    head=temp;
		temp->prev=NULL;
		temp->next=NULL;
		end=temp;
	  }
	else
	  {
	    ptr=head;
		i=1;

	    for(;i<(pos-1)&&(ptr->next!=NULL);i++)
	       {
		
		 printf("%d",ptr->data);
		 ptr=ptr->next;
		
	       }
		   if(ptr==head && i==(pos))
			{
              ptr->prev=temp;
			  temp->next=ptr;
			  temp->prev=NULL;
			  head=temp;
			}
        else if(ptr==end && i==(pos-1))
			{
              ptr->next=temp;
			  temp->prev=ptr;
			  end=temp;
			}
	    else if(i==(pos-1))
	       {
	    nexxt=ptr->next;	
		swap=ptr->next;
		temp->next=swap;
		nexxt->prev=temp;
		ptr->next=temp;
		temp->prev=ptr;
		
	       }
	     else
	       {
		 printf("invalid position");
	       }
	  }
     }
void dlt_pos()
	{	struct node *ptr,*previous,*nexxt;
		int pos;
		printf("enter the position to delete");
		scanf("%d",&pos);
		ptr=head;
		if(head==NULL)
			{
				printf("Doubly linked list is already empty");
			}
		else
			{
				int i=1;
				while(ptr->next!=NULL && i!=pos)
					{
						ptr=ptr->next;
						i++;
					}
				if(ptr==head && i==pos)
					{
						head=ptr->next;
						head->prev=NULL;
						free(ptr);
					}
				else if(ptr==end && i==pos)
					{
						end=ptr->prev;
						end->next=NULL;
						free(ptr);
					}
				else if(i==pos)
					{
						previous=ptr->prev;
						nexxt=ptr->next;
						previous->next=nexxt;
						nexxt->prev=previous;

					}
				else
					printf("invalid position");
			}
	}
void dlt_end()
	{	struct node *ptr;
		ptr=end;
		if(ptr==NULL)
			{
				printf("empty doubly linked list");
			}
		else
			{
				end=ptr->prev;
				end->next=NULL;
				printf("delection the element %d",ptr->data);
				free(ptr);

			}
	}
void search()
	{
	  int data,i;
	  struct node *ptr;
	  ptr=head;
	  printf("enter the element to search");
	  scanf("%d",&data);
	  for(i=1;ptr->next!=NULL;i++)
	  	{
	  	   if(ptr->data==data)
	  		{
	  		  printf("\ndata found at position %d \n",i);
	  		  return;
	  		}
	  	    ptr=ptr->next;
	  	 
	  	}
	  	if(ptr->data==data)
	  		{
	  		  printf("\ndata found at position %d \n",i);
	  		  return;
	  		}
	       else
	       {
	        printf("\nData not found\n");
	       }
	  	
 
	
	}
		

int main()
    {
	int choice;
	do{
	    printf("\n1.Insert At Beginning");
	    printf("\n2.Insert At End");
	    printf("\n3.Display Forward");
	    printf("\n4.Display Reverse");
	    printf("\n5.Insert At Position");
	    printf("\n6.Delete At Start");
	    printf("\n7.Delete At End");
	    printf("\n8.Delete At Position");
	    printf("\n9.Search");
	    printf("\n10.Exit");
	    printf("\n\nEnter your choice:");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : ins_beg();
			     break;

		    case 2 : ins_end();
			     break;
		    case 3 : display();
			     break;
                    case 4:  dis_from_end();
                             break;
	            case 5:  ins_pos();
	               	     break;
	            case 6:  dlt_strt();
			     break;
		    case 7:  dlt_end();
			     break;
		    case 8:  dlt_pos();
			     break;
		    case 9:  search();
			     break;
                    case 10: printf("Exit");
			     break;
		    default: printf("Invalid choice .if you want to exit pls enter 5 as choice");

		}
	}while(choice!=10);
	return 0;
    }
