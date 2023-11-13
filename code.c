#include <stdio.h>
#include <stdlib.h>

struct Patient {
    char name[50];
    int priority;
    struct Patient* next;
};

struct Patient* front = NULL;

// Function to enqueue a patient
void enqueue(char name[], int priority) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newPatient->name, name);
    newPatient->priority = priority;
    newPatient->next = NULL;

    if (front == NULL || priority < front->priority) {
        newPatient->next = front;
        front = newPatient;
    } else {
        struct Patient* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient;
    }

    printf("Patient %s with priority %d has been added to the queue.\n", name, priority);
}

// Function to dequeue and display the highest priority patient
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Patient* temp = front;
    printf("Patient %s with priority %d has been treated and removed from the queue.\n", 
    temp->name, temp->priority);
    front = front->next;
    free(temp);
}

// Function to display the queue
void displayQueue() {
    struct Patient* temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Patients in the queue:\n");
    while (temp != NULL) {
        printf("Name: %s, Priority: %d\n", temp->name, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char name[50];
    int priority;

    while (1) {
        printf("\nHospital ER Priority Scheduling System\n");
        printf("1. Add a patient\n");
        printf("2. Treat the highest priority patient\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient's name: ");
                scanf("%s", name);
                printf("Enter patient's priority: ");
                scanf("%d", &priority);
                enqueue(name, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
