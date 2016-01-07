#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head)
{
    ListNode* node = head;
    while (node != NULL)
    {
        cout << node->val;
        if (node->next != NULL)
            cout << "->";
        node = node->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        for (int i = 0; i < n; i++)
            node = node->next;

        if (node == NULL)
        {
            ListNode* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;

            return head;
        }

        ListNode* previousNode = head;
        while (node->next != NULL)
        {
            node = node->next;
            previousNode = previousNode->next;
        }

        ListNode* nodeToRemove = previousNode->next;
        previousNode->next = nodeToRemove->next;
        delete nodeToRemove;

        return head;
    }
};

int main(void)
{
    Solution slt;

    //int array[] = {1, 2, 3, 4, 5};
    //int n = 2;

    //int array[] = {1, 2};
    //int n = 2;

    //int array[] = {1, 2};
    //int n = 1;

    int array[] = {1};
    int n = 1;

    int size = sizeof(array)/sizeof(int);
    ListNode* list = new ListNode(array[0]);
    ListNode* head = list;
    for (int i = 1; i < size; i++)
    {
        ListNode* node = new ListNode(array[i]);
        list->next = node;
        list = list->next;
    }
    printList(head);

    head = slt.removeNthFromEnd(head, n);
    printList(head);

    while (head != NULL)
    {
        ListNode* node = head;
        head = head->next;
        delete node;
    }

    return 0;
}
