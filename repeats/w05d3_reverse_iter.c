#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode 
{
    int val;
    struct ListNode *next;
} ListNode;

static ListNode* buildNode(int val)
{
    ListNode* node = malloc(sizeof(ListNode));
    if (!node)
    {
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(ListNode* head)
{
    while(head)
    {
        ListNode* temp = head->next;
        free(head);
        head = temp;
    }
}

ListNode* buildList(const int* arr, size_t size)
{
    if (!size)
    {
        return NULL;
    }
    ListNode* head = buildNode(arr[0]);
    if (!head)
    {
        return NULL;
    }
    ListNode* tail = head;
    for (size_t i=1; i<size; i++)
    {
        ListNode* middle = buildNode(arr[i]);
        if (!middle) 
        {
            freeList(head);
            return NULL;
        }
        tail->next = middle;
        tail = middle;
    }
    return head;
}

ListNode* reverseList(ListNode* head) 
{
    ListNode* prev = NULL;
    while(head)
    {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
void printList(ListNode* head)
{
    while(head)
    {
        printf("%d", head->val);
        printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {1, 2, 3};
    assert(buildList(arr, 0) == NULL);
    size_t size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = buildList(arr, size);
    assert(head != NULL);
    printList(head);
    head = reverseList(head);
    printList(head);
    assert(reverseList(NULL) == NULL);            /* empty list */
    assert(head->val == 3);                 /* firt node after reversal*/
    assert(head->next->val == 2);
    assert(head->next->next->val == 1);
    assert(head->next->next->next == NULL);   /* last node`s next == NULL */
    freeList(head);
    int one[] = {7};
    head = buildList(one, 1);
    assert(head != NULL);
    head = reverseList(head);
    assert(head->val == 7);
    assert(head->next == NULL);
    freeList(head);
    printf("all tests passed\n");
}
