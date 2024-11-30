#include <stdio.h>
#include <stdlib.h>
#define SIZE 3 
int queue[SIZE];
int front = -1, rear = -1;


void insert();
void delete();
void display();

int main() {
    int choice;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
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
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void insert() {
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }

    if (front == -1) {
        
        front = 0;
        rear = 0;
    } else {
        
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    if (front == rear) {
       
        front = rear = -1;
    } else {
        
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("The queue is empty!\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
