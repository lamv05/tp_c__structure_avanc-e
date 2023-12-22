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
	deleteNode(&racine,3);
	printList(&racine);
	//free_all(&racine);
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


void deleteNode(t_listnode* node,int value)
{
	if ((node->next)->value==value)
	{
		t_listnode* to_free =node->next ;
		node->next=(node->next)->next;
		free(to_free);
	}
	else if (node->next!=NULL)
		deleteNode(node->next,value);
}

void searchNode(t_listnode* node,int value)
{
	while (node->next!=NULL)
	{
		if (node->value==value)
			printf("il y a un nœeud avec la valeur %d\n",value);
		node=node->next;
	}
}

void free_all(t_listnode* node)
{
	t_listnode* temp=node->next;
	free(node);
	free_all(temp);
}



t_treeNode newNode(int value)
{
	t_treeNode newNode;
	newNode.value=value;
	newNode.left =(struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode.right =(struct TreeNode*)malloc(sizeof(struct TreeNode));
	return newNode;
}

void insert(t_treeNode* tree, int value)
{
	if (tree->left ==NULL && tree->right==NULL)
	{
		t_treeNode new = newNode(value);
		if (tree->value>value)
			tree->left = &new;
		else
			tree->right = &new;
	}
	else if (tree->value>value)
		insert(tree->left,value);
	else if (tree->value<value)
		insert(tree->left,value);
}
