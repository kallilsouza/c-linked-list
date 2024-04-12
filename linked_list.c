#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int length;
} LinkedList;

LinkedList *createNewList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));

    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
    list->head->value = -1;
    list->length = 0;

    return list;
}

int push(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;

    Node *currentNode = list->head;
    Node *previousNode = list->head;

    if (list->length == 0)
    {
        list->head = newNode;
    }
    else
    {
        while (currentNode->next != NULL)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    newNode->next = currentNode;
    previousNode->next = newNode;
    currentNode->next = NULL;

    list->length++;

    return value;
}

int getByPosition(LinkedList *list, int pos)
{
    if (pos > list->length - 1)
    {
        return -1;
    }

    int currentPos = 0;
    Node *currentNode = list->head;

    while (pos != currentPos++)
    {
        currentNode = currentNode->next;
    }

    return currentNode->value;
}

int removeByValue(LinkedList *list, int value)
{
    Node *currentNode = list->head;
    Node *previousNode = NULL;

    while (currentNode->value != value)
    {
        if (currentNode->next == NULL)
        {
            return -1;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (previousNode != NULL)
    {
        previousNode->next = currentNode->next;
    }

    free(currentNode);

    list->length--;

    return value;
}

int removeByPosition(LinkedList *list, int pos)
{
    if (pos > list->length - 1)
    {
        return -1;
    }

    Node *currentNode = list->head;
    Node *previousNode = NULL;

    int currentPos = 0;

    while (pos != currentPos++)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (previousNode != NULL)
    {
        previousNode->next = currentNode->next;
    }

    int value = currentNode->value;
    free(currentNode);

    list->length--;

    return value;
}

void printItems(LinkedList *list)
{
    Node *currentNode = list->head;

    printf("%c", '[');

    for (int i = 0; i < list->length; i++)
    {
        printf("%d", currentNode->value);

        if (list->length != i + 1)
        {
            printf("%s", ", ");
        }

        currentNode = currentNode->next;
    }

    printf("%c\n\n", ']');
}

int main(int *argc, int **argv)
{
    LinkedList *list = createNewList();
    int choiceInput;
    int input;

    while (1)
    {
        printf("%s", "1: Print list\n2: Push value to list\n3: Remove item from list by value\n4: Get item by position\n5: Remove item by position\n6: Show list length\n0: Exit\n\n");
        scanf("%d", &choiceInput);

        if (choiceInput == 0)
        {
            return 0;
        }
        else if (choiceInput == 1)
        {
            printItems(list);
        }
        else if (choiceInput == 2)
        {
            printf("%s", "New value: ");
            scanf("%d", &input);

            push(list, input);
            printf("%d %s", input, " added to the list\n\n");
        }
        else if (choiceInput == 3)
        {
            printf("%s", "Item to remove: ");
            scanf("%d", &input);

            printf("%d %s\n\n", removeByValue(list, input), "removed");
        }
        else if (choiceInput == 4)
        {
            printf("%s", "Position: ");
            scanf("%d", &input);

            if (input > list->length - 1)
            {
                printf("%s\n\n", "Out of range");
            }
            else
            {
                printf("%s%d%s %d\n\n", "Item[", input, "] =", getByPosition(list, input));
            }
        }
        else if (choiceInput == 5)
        {
            printf("%s", "Position: ");
            scanf("%d", &input);

            if (input > list->length - 1)
            {
                printf("%s\n\n", "Out of range");
            }
            else
            {
                printf("%s%d%s%d%s\n\n", "Item[", input, "] (", removeByPosition(list, input), ") removed");
            }
        }
        else if (choiceInput == 6)
        {
            printf("%s %d\n\n", "Length:", list->length);
        }
        else
        {
            printf("%s\n", "Invalid option\n");
        }
    }

    return 0;
};
