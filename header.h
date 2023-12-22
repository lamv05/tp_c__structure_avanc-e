#include<stdio.h>

typedef struct listnode_
{
	int value;
	struct listnode_* next;
}t_listnode;

void insertEnd(t_listnode* node,int new_value);

void printList(t_listnode* racine);

void insertBeginning(t_listnode* racine,int value);

void insertMiddle(t_listnode* racine,int value,int position);

void deleteNode(t_listnode* node,int value);

void searchNode(t_listnode* node,int value);

void free_all(t_listnode* node);

typedef struct TreeNode
{
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}t_treeNode;

t_treeNode* newNode(int value);

void insert(t_treeNode* tree, int value);
