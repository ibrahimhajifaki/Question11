#include <stdio.h>
#include <stdlib.h>

struct request {
    int priority;
    char device[20];
    struct request* next;
};

struct request* head = NULL;

void add_request(int priority, char device[]) {
    struct request* newnode = (struct request*)malloc(sizeof(struct request));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->priority = priority;
    strcpy(newnode->device, device);
    newnode->next = NULL;

    if (head == NULL || head->priority > priority) {
        newnode->next = head;
        head = newnode;
    } else {
        struct request* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Request for %s added with priority %d\n", device, priority);
}

void process_requests() {
    if (head == NULL) {
        printf("No requests to process.\n");
        return;
    }

    while (head != NULL) {
        struct request* temp = head;
        printf("Processing %s with priority %d\n", temp->device, temp->priority);
        head = head->next;
        free(temp);
    }
}

int main() {
    add_request(3, "Scanner");
    add_request(1, "Keyboard");
    add_request(2, "Mouse");
    add_request(4, "Printer");

    printf("\nProcessing Requests:\n");
    process_requests();
    return 0;
}
