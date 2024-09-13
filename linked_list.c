#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

// Function declarations
void print_list(node_t *head);
void push(node_t **head, int val);
int pop(node_t **head);
int remove_last(node_t *head);
int remove_by_index(node_t **head, int n);
void insert_at_index(node_t **head, int val, int index);
int remove_by_value(node_t **head, int val);
void free_list(node_t **head);

// Function implementations
// (Implementations for print_list, push, pop, remove_last, and remove_by_index go here)

void insert_at_index(node_t **head, int val, int index) {
    if (index == 0) {
        push(head, val); // Reuse the push function to add at the beginning
        return;
    }

    node_t *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        // Index is greater than the number of nodes
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        // Memory allocation failed
        return;
    }

    new_node->val = val;
    new_node->next = current->next;
    current->next = new_node;
}

int remove_by_value(node_t **head, int val) {
    node_t *current = *head, *prev = NULL;

    if (current != NULL && current->val == val) {
        // The head node holds the value to be removed
        *head = current->next;
        free(current);
        return 0;
    }

    while (current != NULL && current->val != val) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        // Value not found
        return -1;
    }

    prev->next = current->next;
    free(current);
    return 0;
}

void free_list(node_t **head) {
    node_t *current = *head;
    node_t *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

void push(node_t **head, int val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        // Handle memory allocation failure
        exit(1);
    }

    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}




int main() {
    node_t *head = NULL;
    int choice, value, index;

    while (1) {
        printf("Choose an option:\n");
        printf("1) Insert a value at the end\n");
        printf("2) Delete a value\n");
        printf("3) Empty list\n");
        printf("4) Show list\n");
        printf("5) Insert a value at a specific index\n");
        printf("6) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                if (!remove_by_value(&head, value)) {
                    printf("Value deleted successfully.\n");
                } else {
                    printf("Value not found.\n");
                }
                break;
            case 3:
                free_list(&head);
                printf("List emptied.\n");
                break;
            case 4:
                printf("Current list:\n");
                print_list(head);
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the index at which to insert: ");
                scanf("%d", &index);
                insert_at_index(&head, value, index);
                break;
            case 6:
                free_list(&head);  // Clean up before exiting
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
