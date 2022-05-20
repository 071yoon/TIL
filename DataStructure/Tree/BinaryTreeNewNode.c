// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct new_node {
	int key;
	struct new_node *left, *right;
};

// Create a node
struct new_node *newNode(int item) {
	struct new_node *temp = (struct new_node *)malloc(sizeof(struct new_node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct new_node *veryRight(struct new_node *root){
	struct new_node *tmp = root;
	while(tmp->right){
		tmp = tmp->right;
	}
	return tmp;
}

// Inorder Traversal
void inorder(struct new_node *root, struct new_node *last) {
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
struct new_node *insert(struct new_node *node, int key) {
	// Return a new new_node if the tree is empty
	if (node == NULL) return newNode(key);

	// Traverse to the right place and insert the node
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

// Find the inorder successor
struct new_node *minValueNode(struct new_node *node) {
	struct new_node *current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Deleting a node
struct new_node *deleteNode(struct new_node *root, int key) {
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

// Driver code
int main() {
	struct new_node *root = NULL;
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

	struct new_node *last = veryRight(root);
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