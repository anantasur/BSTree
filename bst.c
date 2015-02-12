#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BSTree createBSTree(){
	return (BSTree){NULL,0};
}

Node * createNode(int data){
	Node * node = calloc(sizeof(Node),1);
	node->data = data;
	return node;
}

int insert(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node *node = createNode(data);
	if(!tree->root) tree->root = node;
	if(data < tree->root->data) {
		if(tree->root->left){
			subTree.root = tree->root->left;
			insert(&subTree,data);
		}
		if(!tree->root->left) tree->root->left = node;
	}
	if(data > tree->root->data) {
		if(tree->root->right){
			subTree.root = tree->root->right;
			insert(&subTree,data);
		}
		if(!tree->root->right) tree->root->right = node;
	}
	tree->count++; 
	return 1;
}

Node* find(BSTree tree,int data) {
	BSTree subTree = createBSTree();
	if(!tree.root) return NULL;
	if(data == tree.root->data)
		return tree.root;
	if(tree.root->right && (data > tree.root->data)){
		subTree.root = tree.root->right;
	}  	
	if(tree.root->left && (data < tree.root->data)){
		subTree.root = tree.root->left;
	} 
	return find(subTree,data);
}

Node* delete(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node* node = NULL;
	if(tree->root->right && tree->root->right->data == data){
		node = tree->root->right;
		tree->root->right = NULL;
	}
	if(tree->root->left && tree->root->left->data == data){
		node = tree->root->left;
		tree->root->left = NULL;
	}
	if(!node){
		if(data < tree->root->data){
			subTree.root = tree->root->left;
			node = delete(&subTree,data);
		}
		if(data > tree->root->data){
			subTree.root = tree->root->right;
			node = delete(&subTree,data);		 
		}
	}
	return node; 
}