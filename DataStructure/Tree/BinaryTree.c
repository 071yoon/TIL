// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *veryRight(struct node *root){
	struct node *tmp = root;
	while(tmp->right){
		tmp = tmp->right;
	}
	return tmp;
}

// Inorder Traversal
void inorder(struct node *root, struct node *last) {
	if (root != NULL) {
		// Traverse left
		inorder(root->left, last);
		// Traverse root
		if (root != last)
			printf("%d -> ", root->key);
		else
			printf("%d", root->key);
		// Traverse right
		inorder(root->right, last);
	}
}

// Insert a node
struct node *insert(struct node *node, int key) {
	// Return a new node if the tree is empty
	if (node == NULL) return newNode(key);

	// Traverse to the right place and insert the node
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
	struct node *current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
	// Return if the tree is empty
	if (root == NULL) return root;

	// Find the node to be deleted
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

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
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver code
int main() {
	struct node *root = NULL;
	root = insert(root, 55);
	root = insert(root, 15);
	root = insert(root, 60);
	root = insert(root, 8);
	root = insert(root, 28);
	root = insert(root, 90);
	root = insert(root, 3);
	root = insert(root, 30);
	root = insert(root, 48);
	root = insert(root, 38);
	root = insert(root, 50);
	root = insert(root, 33);
	root = insert(root, 32);
	root = insert(root, 36);

	struct node *last = veryRight(root);
	printf("Inorder traversal[original]: ");
	inorder(root, last);


	root = deleteNode(root, 3);
	printf("\ndelete 3");
	printf("\nInorder traversal: ");
	inorder(root, last);
	root = deleteNode(root, 30);
	printf("\ndelete 30");
	printf("\nInorder traversal: ");
	inorder(root, last);
	root = deleteNode(root, 15);
	printf("\ndelete 15");
	printf("\nInorder traversal: ");
	inorder(root, last);
	printf("\n");

}