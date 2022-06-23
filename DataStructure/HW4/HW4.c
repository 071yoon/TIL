// Tree traversal in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *tmp[50];
int cnt = 0;

struct node {
	char *item;
	struct node* left;
	struct node* right;
};

// Create a node
struct node *newNode(char item[]) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->item = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *minValueNode(struct node *node) {
	struct node *current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

int cmp(char item1[], char item2[]){
	for(int i = 0; i < 50; i++){
		if (item1[i] == '\0' && item2[i] == '\0'){
			return 0;
		}
		if (item1[i] > item2[i]){
			return 1;
		}
		else if (item1[i] < item2[i]){
			return -1;
		}
	}
	return 0;
}

struct node *deleteNode(struct node *root, char item[]) {
	// Return if the tree is empty
	if (root == NULL) return root;

	// Find the node to be deleted
	int test = cmp(item, root->item);
	if (test == -1)
		root->left = deleteNode(root->left, item);
	else if (test == 1)
		root->right = deleteNode(root->right, item);

	else {
		// If the node is with only one child or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// If the node has two children
		struct node *temp = minValueNode(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->item = temp->item;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->item);
	}
	return root;
}

struct node *insert(struct node *node, char item[]) {
	// Return a new node if the tree is empty
	if (node == NULL) return newNode(item);

	// Traverse to the right place and insert the node
	int test = cmp(item, node->item);
	if (test == -1)
		node->left = insert(node->left, item);
	else
		node->right = insert(node->right, item);

	return node;
}

// Inorder traversal 중위순회
void inorderTraversal(struct node* root) {
	if (root == NULL) return;
	inorderTraversal(root->left);
	printf("%s -> ", root->item);
	tmp[cnt++] = root->item; 
	inorderTraversal(root->right);
}

// preorderTraversal traversal 전위순회
void preorderTraversal(struct node* root) {
	if (root == NULL) return;
	printf("%s -> ", root->item);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// postorderTraversal traversal 후위순회
void postorderTraversal(struct node* root) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%s -> ", root->item);
}

// Create a new Node
struct node* createNode(char *value) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, char value[]) {
	root->left = createNode(value);
	return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, char value[]) {
	root->right = createNode(value);
	return root->right;
}

void print_orders(struct node* root){
	printf("\n[Inorder traversal] \n");
	inorderTraversal(root);

	printf("\n[Preorder traversal] \n");
	preorderTraversal(root);

	printf("\n[Postorder traversal] \n");
	postorderTraversal(root);
}

int main() {
	struct node* root = createNode("korea");
	insertLeft(root, "data");
	insertRight(root, "Ahn");

	insertLeft(root->left, "quick");
	insertRight(root->left, "sort");
	insertRight(root->right, "university");
	insertLeft(root->left->left, "bubble");
	insertLeft(root->left->right, "algorithm");
	insertRight(root->left->right, "computer");
	insertRight(root->left->right->right, "recursive");
	insertLeft(root->left->right->right->right, "tree");
	insertRight(root->left->right->right->right, "hash0");
	insertLeft(root->left->right->right->right->left, "chain");
	insertLeft(root->left->right->right->right->left->left, "stack");
	insertRight(root->left->right->right->right->left->left, "queue");

	print_orders(root);

	printf("\n\n\n");
	struct node *bin = NULL;
	for(int i = 0; i < cnt; i++){
		bin = insert(bin, tmp[i]);
	}
	root = bin;
	print_orders(root);

	deleteNode(root, "recursive");
	printf("\n\ndeleted recursive\n\n");

	print_orders(root);

	printf("\n\n스마트ICT융합공학과_201713025_윤영기\n\n");
}