// Task 7: Binary Tree Traversal
// Time Complexities: Insertion: O(log n) average / O(n) worst, Breadth-First: O(n), Depth-First: O(n)

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(int value) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode* insert(TreeNode* node, int value) {
    if (node == NULL) {
        return create_node(value);
    }
    if (value < node->val) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Custom Helper Queue for Level-Order (BFS) Traversal
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct TreeQueue {
    QueueNode* head;
    QueueNode* tail;
} TreeQueue;

void enqueue(TreeQueue* q, TreeNode* t_node) {
    if (t_node == NULL) return;
    QueueNode* new_qnode = (QueueNode*)malloc(sizeof(QueueNode));
    new_qnode->treeNode = t_node;
    new_qnode->next = NULL;
    
    if (q->tail == NULL) {
        q->head = q->tail = new_qnode;
    } else {
        q->tail->next = new_qnode;
        q->tail = new_qnode;
    }
}

TreeNode* dequeue(TreeQueue* q) {
    if (q->head == NULL) return NULL;
    QueueNode* temp = q->head;
    TreeNode* t_node = temp->treeNode;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return t_node;
}

// Breath-First Traversal (BFS / Level Order)
void breadth_first_traversal(TreeNode* root) {
    if (root == NULL) return;
    
    TreeQueue q;
    q.head = q.tail = NULL;
    enqueue(&q, root);
    
    int printed_count = 0;
    while (q.head != NULL) {
        TreeNode* current = dequeue(&q);
        if (printed_count > 0) printf(" -> ");
        printf("%d", current->val);
        printed_count++;
        
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
    printf("\n");
}

// Depth-First Traversal (In-Order: Left -> Root -> Right)
void depth_first_inorder(TreeNode* node, int* printed_count) {
    if (node != NULL) {
        depth_first_inorder(node->left, printed_count);
        if (*printed_count > 0) printf(" -> ");
        printf("%d", node->val);
        (*printed_count)++;
        depth_first_inorder(node->right, printed_count);
    }
}

void free_tree(TreeNode* node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int main() {
    // Building a BST with exactly 7 nodes:
    //         50
    //        /  \
    //      30    70
    //     /  \  /  \
    //    20  40 60  80
    TreeNode* root = NULL;
    int nodes_to_insert[7] = {50, 30, 70, 20, 40, 60, 80};
    
    for (int i = 0; i < 7; i++) {
        root = insert(root, nodes_to_insert[i]);
    }
    
    printf("--- Binary Search Tree Traversal ---\n");
    printf("Nodes inserted in order: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", nodes_to_insert[i]);
    }
    printf("\n");
    
    printf("\n1. Breadth-First Search (Level-Order Traversal):\nVisit Order: ");
    breadth_first_traversal(root);
    
    printf("\n2. Depth-First Search (In-Order Traversal):\nVisit Order: ");
    int printed_count = 0;
    depth_first_inorder(root, &printed_count);
    printf("\n");
    
    free_tree(root);
    return 0;
}
