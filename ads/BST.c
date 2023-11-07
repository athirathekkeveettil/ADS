#include <stdio.h>
#include <stdlib.h>

void insert();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
void search();
struct node* minValueNode(struct node *curr);
struct node *deleteBST(struct node *root, int value);

struct node
{
	int data;
	struct node *left, *right;
} *root;

int main()
{
	int ch, value;

	do
	{
		printf("\nSELECT\n");
		printf("\n1.Insert\n");
		printf("\n2.Preorder\n");
		printf("\n3.Inorder\n");
		printf("\n4.Postorder\n");
		printf("\n5.Search\n");
		printf("\n6.Delete\n");
		printf("\n7.Exit\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			insert();
			break;

		
		case 2:
			printf("The preorder traversal is ");
			preorder(root);
			break;

		case 3:
			printf("The inorder traversal is ");
			inorder(root);
			break;

		case 4:
			printf("The postorder traversal is ");
			postorder(root);
			break;
			
		case 5:
			search();
			break;	
			
		case 6:
			printf("Enter the value to be deleted\n");
			scanf("%d",&value);
			deleteBST(root,value);
			break;	

		default:
			return 0;
		}

	} while (ch != 0);
}

void insert()
{
	struct node *curr, *prev, *newnode;
	int value;

	printf("Enter the node value\n");
	scanf("%d", &value);

	if (root == NULL)
	{

		root = (struct node *)malloc(sizeof(struct node));
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		printf("Node Inserted %d\n", value);
	}
	else
	{

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = value;
		newnode->left = NULL;
		newnode->right = NULL;

		curr = root;

		// find the last node  for insertion
		while (curr != NULL)
		{
			prev = curr;
			if (curr->data <= value)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}

		// check whether value greater than or less than last node
		if (prev->data <= value)
		{
			prev->right = newnode;
		}
		else
		{
			prev->left = newnode;
		}

		printf("Node Inserted %d\n", value);
	}
}

void inorder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if (root == NULL)

		return;

	else
		{
			printf("%d ", root->data);
			preorder(root->left);
			preorder(root->right);
		}
}

void postorder(struct node *root)
{
	if (root == NULL)

		return;

			else
		{
			postorder(root->left);
			postorder(root->right);
			printf("%d ", root->data);
		}
}

void search()
{
	struct node *curr;
	int value, flag = 0;

	printf("Enter the node to be searched\n");
	scanf("%d", &value);

	if (root == NULL)
	{

		printf("Tree Empty\n");
	}
	else
	{
		curr = root;
		while (curr != NULL)
		{
			if (curr->data == value)
			{
				printf("Node %d Found\n", value);
				flag = 1;
				return;
			}
			else if (curr->data < value)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if (flag == 0)

			printf("Node not Found\n");
	}
}

struct node *deleteBST(struct node *root, int value)
{
	struct node *curr;
	if (root == NULL)

		return 0;

	else if (value < root->data)

		root->left= deleteBST(root->left,value);

	else if (value > root->data)

		root->right= deleteBST(root->right,value);

	else
	{
		//delete node with one or zero child
		if(root->left==NULL)
		{
			curr=root->right;
			free(root);
			return curr;
		}
		else if(root->right==NULL)
		{
			curr=root->left;
			free(root);
			return curr;
		}
		else
		{
			//delete node with two child
			struct node *curr=minValueNode(root->right);

			root->data=curr->data;

			root->right=deleteBST(root->right,curr->data);

		}
	}
	return root;

}

struct node* minValueNode(struct node *curr){

	while(curr->left!=NULL){
		curr=curr->left;
	} 
	return curr;
}
