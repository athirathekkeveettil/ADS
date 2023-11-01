#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
//creation
struct node *newnode(int item)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=item;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

//insertion
struct node *insert(struct node *node, int data) 
{
    if (node == NULL)
        return newnode(data);
 
    if (data < node->data) 
        node->left = insert(node->left, data);
    else
       node->right = insert(node->right, data);
 
    return node;
}

struct node *search(struct node *root,int data)
{
 if(root==NULL||root->data==data)
   return root;
 if(root -> data < data)
   return search(root->right,data);
 else
   return search(root->left,data);
}


struct node* delete(struct node *root,int data)
{
  if(root==NULL)
   return root;
  if(root->data>data)
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
