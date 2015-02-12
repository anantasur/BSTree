typedef struct bst BSTree;
typedef struct node Node;
struct node{
	int data;
	Node *left;
	Node *right;
};
struct bst{
 	Node *root;
 	int count;
}; 

BSTree createBSTree(void);
Node *createNode(int);
int insert(BSTree *,int);
Node *find(BSTree, int);
Node *delete(BSTree *, int);