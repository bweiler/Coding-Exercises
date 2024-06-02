#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define structure for the binary tree
struct BinaryTree {
    int arr[MAX_SIZE];
    int size;
};

// Function to initialize the binary tree
void initBinaryTree(struct BinaryTree* tree) {
    tree->size = 0;
}

// Function to insert a new element into the binary tree
void insert(struct BinaryTree* tree, int data) {
    if (tree->size >= MAX_SIZE) {
        printf("Binary tree is full\n");
        return;
    }
    tree->arr[tree->size++] = data;
}

int total_calls = 0;

// Function to perform inorder traversal of the binary tree
void inorderTraversal(struct BinaryTree* tree, int index) {
	++total_calls;
    if (index < tree->size) {
        inorderTraversal(tree, 2 * index + 1);
        printf("%d ", tree->arr[index]);
        inorderTraversal(tree, 2 * index + 2);
    }
}

int main() {
    struct BinaryTree tree;
    initBinaryTree(&tree);

    // Inserting elements into the binary tree
    insert(&tree, 50);
    insert(&tree, 30);
    insert(&tree, 20);
    insert(&tree, 40);
    insert(&tree, 70);
    insert(&tree, 60);
    insert(&tree, 80);

    // Perform inorder traversal of the binary tree
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(&tree, 0);

	int sumbytes = 4 + 4 + 4;
	sumbytes *= total_calls;
	printf("\n\nA tree of %d integers used %d bytes\n",MAX_SIZE,sizeof(tree));
	printf("Stack used: %d bytes - %d calls of 4 bytes RET, and %d %d bytes args\n",sumbytes,total_calls,sizeof(&tree),sizeof(int));
	printf("\n");

    return 0;
}
