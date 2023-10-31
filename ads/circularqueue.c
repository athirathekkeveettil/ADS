#include<stdio.h>
#include<stdlib.h>
int rear=-1,front=-1;
int que[20];
int max=20;
void enqueue()
{ 
  int item;
  printf("Enter the element to be inserted:");
  scanf("%d",&item);
  int crear=rear;
  rear=(rear+1)%max;
  if(rear==front)
  { 
  printf("Queue is FULL!!");
  rear=crear;
  }
  else if(front==-1)
  {
   front=0;
   rear=0;
   que[rear]=item;
  }
  else
  {
   que[rear]=item;
  }
}

void dequeue()
{
 if(front==-1)
 {
  printf("Queue Underflow!!");
 }
 else if(front==rear)
 {
  printf("Deleted element is %d",que[front]);
  front=-1;
  rear=-1;
 }
 else
 {
  printf("Deleted element is %d",que[front]);
  front=(front+1)%max;
 }
}

void display()
{
 int i=front;
 if(front==-1)
 {
  printf("Queue is empty!!");
 }
 else
 {
  for(;i!=rear;i=((i+1)%(max)))
  {
   printf("\t%d",que[i]);
  }
  printf("\t%d",que[i]);
 }
}

void search()
{ 
 int item,i=1,dfront=front;
 printf("\nEnter element to search:");
 scanf("%d",&item);
 if(front==-1)
 {
  printf("Queue is empty!!");
 }
 else
 {
  for(;dfront!=rear;dfront=((dfront+1)%(max)))
  {
   if(que[dfront]==item)
   {
    printf("Element Found At Position %d\n",i);
   }
   i++;
  }
  if(que[front]==item)
  {
   printf("\nElement Found At Position %d\n",i);
  }
 }
}
int main()
{ 
  int opt;
  do{
  { 
    printf("\n*Operations On Circular Queue*\n");
    printf("\n1.Enqueue: \n");
    printf("\n2.Display\n");
    printf("\n3.Search\n");
    printf("\n4.Dequeue:\n");
    printf("\n5.Exit\n");
    printf("\nEnter your choice:");
    scanf("%d",&opt);
    switch(opt)
    {
     case 1:enqueue();
            break;
     case 2:display();
            break;
     case 3:search();
            break;
     case 4:dequeue();
            break;
     case 5:printf("Exit\n");
            break;
     default:printf("Invalid choice!!\n");
     }
    } 
   } 
   while(opt!=5);
   return 0;  
}
