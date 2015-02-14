#include "expr_assert.h"
#include "bst.h"
#include <stdio.h>

void test_createNode_creates_a_TreeNode_with_given_data (){
	int data = 5;
	Node *node = createNode(data);
	assert(node->data == 5);
	assert(node->left == 0);
	assert(node->right == 0);
}

void test_createNode_creates_a_TreeNode_with_two_digit_data (){
	int data = 23;
	Node *node = createNode(data);
	assert(node->data == 23);
	assert(node->left == 0);
	assert(node->right == 0);
}

void test_createBSTree_creates_an_empty_tree (){
	BSTree tree = createBSTree();
	assert(tree.root == 0);
	assert(tree.count == 0);
}

void test_insert_inserts_given_element_at_root_if_tree_is_empty (){
	BSTree tree = createBSTree();
	int data = 12;
	assertEqual(insert(&tree, data),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.count,1);
}

void test_insert_inserts_given_element_at_left_if_root_is_greater_than_element (){
	BSTree tree = createBSTree();
	int data1 = 12, data2 = 9;
	assertEqual(insert(&tree, data1),1);
	assertEqual(insert(&tree, data2),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.root->left->data, 9);
	assertEqual(tree.count,2);
}

void test_insert_inserts_given_element_at_right_if_root_is_smaller_than_element (){
	BSTree tree = createBSTree();
	int data1 = 12, data2 = 17;
	assertEqual(insert(&tree, data1),1);
	assertEqual(insert(&tree, data2),1);
	assertEqual(tree.root->data, 12);
	assertEqual(tree.root->right->data, 17);
	assertEqual(tree.count,2);
}

void test_insert_inserts_the_value_in_next_row_if_the_element_is_smaller_than_the_root_and_no_space_in_first_level(){
	BSTree tree = createBSTree();
	int data1 = 8, data2 = 7, data3 = 10, data4 = 6;
	assertEqual(insert(&tree,data1),1);
	assertEqual(insert(&tree,data2),1);
	assertEqual(insert(&tree,data3),1);
	assertEqual(insert(&tree,data4),1);
	assertEqual(tree.count,4);
	assertEqual(tree.root->data,8);
	assertEqual(tree.root->left->data,7);
	assertEqual(tree.root->right->data,10);
	assertEqual(tree.root->left->left->data,6);
}

void test_find_returns_the_node_if_node_not_found() {
	int res;
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(insert(&tree,7),1);
	assertEqual(insert(&tree,10),1);
	assertEqual(insert(&tree,6),1);
	assertEqual(find(tree,8)->data,8);
	assertEqual(find(tree,7)->data,7);
}

void test_delete_returns_the_deleted_leafnode_from_the_tree() {
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(insert(&tree,7),1);
	assertEqual(insert(&tree,10),1);
	assertEqual(delete(&tree,7)->data,7);
	assert(tree.root->left==0);
	assertEqual(delete(&tree,10)->data,10);
	assert(tree.root->right==0);
} 

void test_delete_returns_the_deletes_the_leafnode_of_the_tree (){
	BSTree tree = createBSTree();
	int data1 = 8, data2 = 7, data3 = 10;
	assertEqual(insert(&tree,data1),1);
	assertEqual(insert(&tree,data2),1);
	assertEqual(insert(&tree,data3),1);
	assertEqual(delete(&tree,7)->data,7);
	assertEqual(delete(&tree,10)->data,10);
	assert(tree.root->left==0);
	assert(tree.root->right==0);
}

int a[] = {0,1,2,3,4,5,6},b[7];

void put(int a) {
	b[a] = a;
}

void test_traverse_inorder_travarsal_gives_numbers_in_accending_order(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,3),1);
	assertEqual(insert(&tree,1),1);
	assertEqual(insert(&tree,5),1);
	assertEqual(insert(&tree,0),1);
	assertEqual(insert(&tree,2),1);
	assertEqual(insert(&tree,4),1);
	assertEqual(insert(&tree,6),1);
	traverse(tree,put);
	assertEqual(a[0],b[0]);
	assertEqual(a[1],b[1]);
	assertEqual(a[2],b[2]);
	assertEqual(a[3],b[3]);
	assertEqual(a[4],b[4]);
	assertEqual(a[5],b[5]);
	assertEqual(a[6],b[6]);
}

void test_traverse_inorder_traversal_works_fine_for_empty_tree (){
	BSTree tree = createBSTree();
	traverse(tree,put);
}