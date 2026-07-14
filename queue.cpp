// Task 3: Queue Implementation
// Time Complexities: Enqueue: O(1), Dequeue: O(1), Peek: O(1)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void init_queue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

bool is_empty(Queue* q) {
    return q->head == NULL;
}

void enqueue(Queue* q, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Queue overflow/Memory allocation error\n");
        return;
    }
    new_node->data = val;
    new_node->next = NULL;
    
    if (q->tail == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    Node* temp = q->head;
    int val = temp->data;
    q->head = q->head->next;
    
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return val;
}

int peek(Queue* q) {
    if (is_empty(q)) return -1;
    return q->head->data;
}

void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    Node* current = q->head;
    printf("Front -> ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
    printf(" -> Rear\n");
}

int main() {
    printf("--- Queue Operations Demonstration ---\n");
    Queue q;
    init_queue(&q);
    print_queue(&q);
    
    printf("\nEnqueue 10:\n");
    enqueue(&q, 10);
    print_queue(&q);
    
    printf("\nEnqueue 20:\n");
    enqueue(&q, 20);
    print_queue(&q);
    
    printf("\nEnqueue 30:\n");
    enqueue(&q, 30);
    print_queue(&q);
    
    printf("\nPeek Front: %d\n", peek(&q));
    
    printf("\nDequeue:\n");
    printf("Removed item: %d\n", dequeue(&q));
    print_queue(&q);
    
    printf("\nDequeue:\n");
    printf("Removed item: %d\n", dequeue(&q));
    print_queue(&q);
    
    // Clean up remaining element
    dequeue(&q);
    
    return 0;
}
