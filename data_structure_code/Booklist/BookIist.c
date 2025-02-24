#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the book information structure */
typedef struct Book {
    char id[20];
    char name[100];
    char author[100];
    char publisher[100];
    int year;
    struct Book *next;
} Book;

/* Function declarations */
Book* loadBooksFromFile(const char *filename);
void addBook(Book **head);
void deleteBook(Book **head);
void modifyBook(Book **head);
void printLatestBook(Book *head);
void freeList(Book *head);
void printBook(const Book *book);

int main() {
    int choice;
    Book *head;
    head = loadBooksFromFile("Your File Path");
    
    while (1) {
        printf("Please enter your choice of operation:\n");
        printf("1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Modify a book\n");
        printf("4. Print the latest published book\n");
        printf("0. Exit the program\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 1:
            addBook(&head);
            break;
        case 2:
            deleteBook(&head);
            break;
        case 3:
            modifyBook(&head);
            break;
        case 4:
            printLatestBook(head);
            break;
        case 0:
            freeList(head);
            return 0;
        default:
            printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}

/* Read from file */
    
Book* loadBooksFromFile(const char *filename) {
    char line[256];
    Book *head;
    FILE *file = fopen("Your File Path");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    while (fgets(line, sizeof(line), file)) {
        char *token;
        Book *newBook = (Book*)malloc(sizeof(Book));
        token = strtok(line, ";");
        strcpy(newBook->id, token);
        token = strtok(NULL, ";");
        strcpy(newBook->name, token);
        token = strtok(NULL, ";");
        strcpy(newBook->author, token);
        token = strtok(NULL, ";");
        strcpy(newBook->publisher, token);
        token = strtok(NULL, ":");
        sscanf(token, "%d", &newBook->year);

        newBook->next = head;
        head = newBook;
    }
    fclose(file);
    return head;
}

/* Add a book */
void addBook(Book **head) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    
    printf("Please enter the book ID: ");
    fgets(newBook->id, sizeof(newBook->id), stdin);
    newBook->id[strcspn(newBook->id, "\n")] = '\0';
    
    printf("Please enter the book title: ");
    fgets(newBook->name, sizeof(newBook->name), stdin);
    newBook->name[strcspn(newBook->name, "\n")] = '\0';
    
    printf("Please enter the author: ");
    fgets(newBook->author, sizeof(newBook->author), stdin);
    newBook->author[strcspn(newBook->author, "\n")] = '\0';
    
    printf("Please enter the publisher: ");
    fgets(newBook->publisher, sizeof(newBook->publisher), stdin);
    newBook->publisher[strcspn(newBook->publisher, "\n")] = '\0';
    
    printf("Please enter the publication year: ");
    scanf("%d", &newBook->year);
    getchar();
    
    newBook->next = *head;
    *head = newBook;
}

/* Delete a book */
void deleteBook(Book **head) {
    char id[20];
    Book *temp = *head;
    Book *prev = NULL;

    printf("Please enter the book ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    while (temp != NULL && strcmp(temp->id, id) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book ID not found\n");
        return;
    }
    
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Book deleted successfully\n");
}

/* Modify a book */
void modifyBook(Book **head) {
    char id[20];
    Book *temp = *head;

    printf("Please enter the book ID to modify: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; // Remove newline character

    while (temp != NULL && strcmp(temp->id, id) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book ID not found\n");
        return;
    }

    printf("Please enter the new book title: ");
    fgets(temp->name, sizeof(temp->name), stdin);
    temp->name[strcspn(temp->name, "\n")] = '\0';
    printf("Please enter the new author: ");
    fgets(temp->author, sizeof(temp->author), stdin);
    temp->author[strcspn(temp->author, "\n")] = '\0';
    printf("Please enter the new publisher: ");
    fgets(temp->publisher, sizeof(temp->publisher), stdin);
    temp->publisher[strcspn(temp->publisher, "\n")] = '\0';
    printf("Please enter the new publication year: ");
    scanf("%d", &temp->year);
    getchar();
    printf("Book modified successfully\n");
}

/* Print the latest book */
void printLatestBook(Book *head) {
    Book *latest = head;
    Book *temp = head;
    if (head == NULL) {
        printf("No books in the list\n");
        return;
    }
    
    while (temp != NULL) {
        if (temp->year > latest->year) {
            latest = temp;
        }
        temp = temp->next;
    }
    printBook(latest);
}


void printBook(const Book *book) {
    printf("ID: %s\n", book->id);
    printf("Title: %s\n", book->name);
    printf("Author: %s\n", book->author);
    printf("Publisher: %s\n", book->publisher);
    printf("Year: %d\n", book->year);
}


void freeList(Book *head) {
    Book *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

