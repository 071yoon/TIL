#include <stdio.h>
#include <stdlib.h>
#define MAX_HASH 10
#define HASH_KEY(key) key%MAX_HASH
 
typedef struct node {
    int id;
    struct node* hashNext;
}Node;

Node* hashTable[MAX_HASH];

int size = 0;

void  AddHashData(int key, Node* node) {
    int hash_key = HASH_KEY(key);
    if (hashTable[hash_key] == NULL) {
        hashTable[hash_key] = node;
    } else {
        node->hashNext = hashTable[hash_key];
        hashTable[hash_key] = node;
    }
}

void DelHashData(int id) {
    int hash_key = HASH_KEY(id);
    if (hashTable[hash_key] == NULL)
        return;
 
    Node* delNode = NULL;
    if (hashTable[hash_key]->id == id) {
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashNext;
    } else {
        Node* node = hashTable[hash_key];
        Node* next = node->hashNext;
        while (next) {
            if (next->id == id) {
                node->hashNext = next->hashNext;
                delNode = next;
                break;
            }
            node = next;
            next = node->hashNext; 
        }
    }
	if(delNode == NULL){
		printf("\n This key does not exist \n");
	} else {
		printf("\n Key (%d) has been inserted \n", id);
	}
    free(delNode); 
}

void PrintAllHashData() {
	printf("###Print All Hash Data###\n");
    for (int i = 0; i < MAX_HASH; i++) {
		printf("idx%d: ", i);
        if (hashTable[i] != NULL) {
            Node* node = hashTable[i];
            while (node->hashNext) {
				printf("%d ", node->id);
                node = node->hashNext;
            }
			printf("%d", node->id);
        }
		printf("\n");
    }
	printf("\n\n");
}

int main() {
	int choice, key, data, n;
	int c = 0;
	for (int i = 0; i < 10; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->id = rand() % 40;
        node->hashNext = NULL;
        AddHashData(node->id, node);
    }
    PrintAllHashData();
	do {
		printf("1.Insert item in the Hash Table"
			"\n2.Remove item from the Hash Table"
			"\n3.Check the size of Hash Table"
			"\n4.Display a Hash Table"
			"\n\nPlease enter your choice: ");

		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter data -:\t");
				scanf("%d", &data);
				Node* node = (Node*)malloc(sizeof(Node));
				node->id = data;
				node->hashNext = NULL;
        		AddHashData(node->id, node);
				break;

			case 2:
				printf("Enter the data to delete-:");
				scanf("%d", &data);
				DelHashData(data);
				break;

			case 3:
				printf("Size of Hash Table is-:%d\n", size);
				break;

			case 4:
				PrintAllHashData();
				break;
			default:
			printf("Invalid Input\n");
		}

		printf("\nDo you want to continue (press 1 for yes): ");
		scanf("%d", &c);
	} while (c == 1);
}
