#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *newnode(int item)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=item;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

struct node* insert(struct node* root, int item) 
{
    if (root == NULL)
     {
        return newnode(item);
     }
 
    if (item < root->data) 
    {
        root->left = insert(root->left, item);
    } 
    else if (data > root->data) 
    {
        root->right = insert(root->right, item);
    }
 
    return root;
}

struct node* search(struct node *root,int item)
{
 if(root==NULL||root->data==item)
   return root;
 else if(item>root->data)
   return search(root->right,item);
 else
   return search(root->left,item);
}


struct node* delete(struct node *root,int item)
{
  if(root==NULL)
   return NULL;
  if(item>root->data)
  {
    
  }
}

void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%d->",root->data);
  inorder(root->right);
 }
}

int main()
{
  struct node *root=NULL;
  
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
 
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");
 
    return 0;
}


