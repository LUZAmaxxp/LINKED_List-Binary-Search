#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes
struct Node *createLinkedList(int n);
void displayLinkedList(struct Node *head);
struct Node *reverseLinkedList(struct Node *head);
struct Node *binarySearchLinkedList(struct Node *head, int target);
int getLength(struct Node *head);
struct Node *getMiddleNode(struct Node *start, int count);

int main()
{
    int n, reverseChoice, searchValue;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = createLinkedList(n);

    printf("Original Linked List:\n");
    displayLinkedList(head);

    printf("Do you want to reverse the linked list? (1 for Yes, 0 for No): ");
    scanf("%d", &reverseChoice);

    if (reverseChoice == 1)
    {
        head = reverseLinkedList(head);
        printf("Reversed Linked List:\n");
        displayLinkedList(head);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &searchValue);

    struct Node *result = binarySearchLinkedList(head, searchValue);

    if (result != NULL)
    {
        printf("Value %d found in the linked list.\n", result->data);
    }
    else
    {
        printf("Value %d not found in the linked list.\n", searchValue);
    }

    return 0;
}

// Function to create a linked list with n nodes
struct Node *createLinkedList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to display the linked list
void displayLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node *reverseLinkedList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Helper function to get the length of the linked list
int getLength(struct Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

// Helper function to get the middle node of a linked list
struct Node *getMiddleNode(struct Node *start, int count)
{
    struct Node *current = start;
    for (int i = 0; i < count / 2; i++)
    {
        if (current != NULL)
        {
            current = current->next;
        }
    }
    return current;
}

// Function to perform binary search on the linked list
struct Node *binarySearchLinkedList(struct Node *head, int target)
{
    int length = getLength(head);
    struct Node *start = head;

    while (length > 0 && start != NULL)
    {
        struct Node *middle = getMiddleNode(start, length);
        if (middle == NULL)
        {
            return NULL;
        }
        if (middle->data == target)
        {
            return middle;
        }
        else if (middle->data < target)
        {
            // Move start to middle->next and reduce length by half
            start = middle->next;
            length = length - length / 2 - 1;
        }
        else
        {
            // Reduce length by half
            length = length / 2;
        }
    }
    return NULL;
}
