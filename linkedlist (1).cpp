// Task 4: Singly Linked List
// Time Complexities: Insert Head: O(1), Insert Tail: O(n), Delete: O(n), Traverse: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    Node* head;
} SinglyLinkedList;

void init_list(SinglyLinkedList* list) {
    list->head = NULL;
}

void insert_at_head(SinglyLinkedList* list, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_at_tail(SinglyLinkedList* list, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

bool delete_by_value(SinglyLinkedList* list, int val) {
    if (list->head == NULL) return false;
    
    Node* temp;
    // If the head node contains the value
    if (list->head->data == val) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
        return true;
    }
    
    Node* current = list->head;
    while (current->next != NULL && current->next->data != val) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        temp = current->next;
        current->next = current->next->next;
        free(temp);
        return true;
    }
    return false;
}

void traverse_and_print(SinglyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is Empty\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(SinglyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }
    list->head = NULL;
}

int main() {
    SinglyLinkedList ll;
    init_list(&ll);
    
    printf("--- 1. Insert at Head (30, then 20) ---\n");
    insert_at_head(&ll, 30);
    insert_at_head(&ll, 20);
    traverse_and_print(&ll);
    
    printf("\n--- 2. Insert at Tail (40, then 50) ---\n");
    insert_at_tail(&ll, 40);
    insert_at_tail(&ll, 50);
    traverse_and_print(&ll);
    
    printf("\n--- 3. Insert at Head (10) ---\n");
    insert_at_head(&ll, 10);
    traverse_and_print(&ll);
    
    printf("\n--- 4. Delete Value 30 ---\n");
    delete_by_value(&ll, 30);
    traverse_and_print(&ll);
    
    printf("\n--- 5. Delete Value 10 (Head deletion) ---\n");
    delete_by_value(&ll, 10);
    traverse_and_print(&ll);
    
    free_list(&ll);
    return 0;
}
