// Task 2: Stack Implementation & Balanced Brackets Checker
// Time Complexities: Push: O(1), Pop: O(1), Peek: O(1), Bracket Check: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init_stack(Stack* s) {
    s->top = NULL;
}

bool is_empty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, char val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Stack overflow/Memory allocation error\n");
        return;
    }
    new_node->data = val;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    Node* temp = s->top;
    char popped_val = temp->data;
    s->top = s->top->next;
    free(temp);
    return popped_val;
}

char peek(Stack* s) {
    if (is_empty(s)) return '\0';
    return s->top->data;
}

void free_stack(Stack* s) {
    while (!is_empty(s)) {
        pop(s);
    }
}

bool is_balanced(const char* expression) {
    Stack s;
    init_stack(&s);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(&s)) {
                return false;
            }
            char open = pop(&s);
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                free_stack(&s);
                return false;
            }
        }
    }
    bool balanced = is_empty(&s);
    free_stack(&s);
    return balanced;
}

int main() {
    printf("--- 1. Stack Base Operations ---\n");
    Stack my_stack;
    init_stack(&my_stack);
    
    push(&my_stack, 'A');
    push(&my_stack, 'B');
    printf("Peek top: %c\n", peek(&my_stack));
    printf("Popped: %c\n", pop(&my_stack));
    printf("Peek top after pop: %c\n", peek(&my_stack));
    free_stack(&my_stack);
    
    printf("\n--- 2. Balanced Brackets Checker ---\n");
    const char* test_exprs[] = {
        "{[()]}",
        "{[(])}",
        "((())",
        "a + {b * (c + d)} - [e]"
    };
    
    for (int i = 0; i < 4; i++) {
        printf("Expression: '%s' -> %s\n", 
               test_exprs[i], 
               is_balanced(test_exprs[i]) ? "Balanced" : "Unbalanced");
    }
    
    return 0;
}
