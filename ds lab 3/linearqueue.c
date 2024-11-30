#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void insert();   
void delete();    
void display();

int main() {
    int choice;

    printf("Linear Queue Implementation\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insert() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (front == -1) {
        
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from the queue.\n", queue[front]);
    front++;

    if (front > rear) {
       
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
