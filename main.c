#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main()
{
	t_listnode node4 = {5,NULL};
	t_listnode node3 = {4,&node4};
	t_listnode node2 = {3,&node3};
	t_listnode node1 = {2,&node2};
	t_listnode racine = {1,&node1};
	
	insertEnd(&racine,6);
	insertBeginning(&racine,0);
	//searchNode(&racine,3);
	//insertMiddle(& racine,13,4);
	//deleteNode(&racine,3);
	printList(&racine);
	free_list(&racine);
	
	/*t_treeNode* tree_root = newNode(101);
	insert(tree_root,8);
	insert(tree_root,14);
	insert(tree_root,129);
	insert(tree_root,4);
	insert(tree_root,99);
	insert(tree_root,13);
	insert(tree_root,55); 
	inorder(tree_root);
	free_tree(tree_root); */
	return 0;
}


void insertEnd(t_listnode* node,int value)
{
	if (node->next==NULL)
	{
		node->next =(struct listnode_*)malloc(sizeof(struct listnode_));
		(node->next)->value=value;
		(node->next)->next=NULL;
	}
	else
		insertEnd(node->next, value);
}

void printList(t_listnode* racine)
{
	printf("%d\n",racine->value);
	if (racine->next != NULL)
		printList(racine->next);
}
	
void insertBeginning(t_listnode* node,int value)
{
	t_listnode* temp = node->next;
	int temp2 = node->value;
	node->next =(struct listnode_*)malloc(sizeof(struct listnode_));
	(node->next)->next =temp;
	(node->next)->value=temp2;
	node->value=value;
}

void insertMiddle(t_listnode* node,int value,int position)
{
	if (position==0)
	{
		t_listnode* temp = node->next;
		node->next =(struct listnode_*)malloc(sizeof(struct listnode_));
		node->value=value;
		node->next=temp;
	}
	else
		insertMiddle(node->next,value,position-1);
}

//ne marche pas pour le 1er element et il y a un soucis avec le free -> exemple initialisé statiquement
void deleteNode(t_listnode* node,int value)
{
	if (node->next!=NULL)
	{
		if ((node->next)->value==value)
		{
			t_listnode* to_free =node->next ;
			node->next=(node->next)->next;
			//free(to_free);
		}
		deleteNode(node->next,value);
	}
}

void searchNode(t_listnode* node,int value)
{
	while (node->next!=NULL)
	{
		if (node->value==value)
			printf("il existe un nœeud contenant la valeur %d\n",value);
		node=node->next;
	}
}

//free(): invalid size -> exemple initialisé statiquement
void free_list(t_listnode* node)
{
	if (node->next!=NULL)
	{
		free_list(node->next);
		free(node);
	}
}



t_treeNode* newNode(int value)
{
	t_treeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->value=value;
	node->left =NULL;
	node->right =NULL;
	return node;
}

//la racine doit etre initialisée
void insert(t_treeNode* tree_root, int value)
{
	if (tree_root->value>value)
	{
		if (tree_root->left==NULL)
			tree_root->left=newNode(value);
		else
			insert(tree_root->left,value);
	}
	else if (tree_root->value<=value)
	{
		if (tree_root->right==NULL)
			tree_root->right=newNode(value);
		else
			insert(tree_root->right,value);
	}	
}

void inorder(t_treeNode* node)
{
	if (node->left!=NULL)
	{
		inorder(node->left);
		printf("%d\n",node->value);
		if (node->right!=NULL)
			inorder(node->right);
	}
	else if (node->left==NULL)
		printf("%d\n",node->value);
	
}

void free_tree(t_treeNode* tree_root)
{
	if(tree_root!=NULL)
	{
		free_tree(tree_root->left);
		free_tree(tree_root->right);
		free(tree_root);
	}
	
}
