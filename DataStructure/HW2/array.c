#include <stdio.h>
#define MAX_SIZE 186

struct Tree_Node{
	int key;
};

void Init_Tree(struct Tree_Node *Target_Tree){ //init all tree to -1
	int cnt = 0;
	for(int i = cnt; i < MAX_SIZE; i++){
		Target_Tree[i].key = -1;
	}
}

void Edit_Tree(struct Tree_Node *Target_Tree, int item, int cnt){ //edit cntth tree
	if (cnt >= MAX_SIZE){
		printf("Tree over max size\n");
		return ;
	}
	Target_Tree[cnt].key = item;
}

void Show_Right_Child(struct Tree_Node *Target_Tree, int POSITION){
	if (POSITION * 2 + 1 >= MAX_SIZE || Target_Tree[POSITION * 2 + 1].key == -1){
		printf("There is no right child\n");
		return;
	}
	printf("right child is %d\n", Target_Tree[POSITION * 2 + 1].key);
}

void Show_Left_Child(struct Tree_Node *Target_Tree, int POSITION){
	if (POSITION * 2 >= MAX_SIZE || Target_Tree[POSITION * 2].key == -1){
		printf("There is no left child\n");
		return;
	}
	printf("right child is %d\n", Target_Tree[POSITION * 2].key);
}

void Show_Root(struct Tree_Node *Target_Tree){
	printf("Root node is %d\n", Target_Tree[1].key);
}

int main(){
	struct Tree_Node yoon[MAX_SIZE];
	Init_Tree(yoon);
	Edit_Tree(yoon, 55, 1);
	Edit_Tree(yoon, 15, 2);
	Edit_Tree(yoon, 60, 3);
	Edit_Tree(yoon, 8, 4);
	Edit_Tree(yoon, 28, 5);
	Edit_Tree(yoon, 90, 7);
	Edit_Tree(yoon, 3, 8);
	Edit_Tree(yoon, 30, 11);
	Edit_Tree(yoon, 48, 23);
	Edit_Tree(yoon, 38, 46);
	Edit_Tree(yoon, 50, 47);
	Edit_Tree(yoon, 33, 92);
	Edit_Tree(yoon, 32, 184);
	Edit_Tree(yoon, 36, 185);
	printf("Node[48]\n"); //23th node
	Show_Left_Child(yoon, 23);
	Show_Right_Child(yoon, 23);
	printf("Node[30]\n"); //11th node
	Show_Left_Child(yoon, 11);
	Show_Right_Child(yoon, 11);
	printf("Root Node\n"); //1st
	Show_Root(yoon);
}