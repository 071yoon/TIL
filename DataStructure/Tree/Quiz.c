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

struct new_node {
	char *key;
	struct new_node *left, *right;
};

// Create a node
struct new_node *newNode(char item[]) {
	struct new_node *temp = (struct new_node *)malloc(sizeof(struct new_node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct new_node *minValueNode(struct new_node *node) {
	struct new_node *current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct new_node *deleteNode(struct new_node *root, char key[]) {
	// Return if the tree is empty
	if (root == NULL) return root;

	// Find the new_node to be deleted
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		// If the new_node is with only one child or no child
		if (root->left == NULL) {
			struct new_node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct new_node *temp = root->left;
			free(root);
			return temp;
		}

		// If the new_node has two children
		struct new_node *temp = minValueNode(root->right);

		// Place the inorder successor in position of the new_node to be deleted
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

struct new_node *insert(struct new_node *node, char key[]) {
	// Return a new new_node if the tree is empty
	if (node == NULL) return newNode(key);

	// Traverse to the right place and insert the node
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

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

print_orders(struct node* root){
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
	struct new_node *bin = NULL;
	for(int i = 0; i < cnt; i++){
		bin = insert(bin, tmp[i]);
	}
	print_orders(bin);

	deleteNode(bin, "recursive");
	printf("\n\ndeleted recursive\n\n");

	print_orders(bin);
}