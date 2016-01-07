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

void destroyList(ListNode* list)
{
    ListNode* head = list;
    ListNode* node = NULL;
    while (head != NULL)
    {
        node = head;
        head = head->next;
        delete node;
    }
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode newHead(0);

        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* lastPairNode = &newHead;
        while (second != NULL)
        {
            first->next = second->next;
            second->next = first;

            lastPairNode->next = second;
            lastPairNode = first;

            first = first->next;
            if (first != NULL)
                second = first->next;
            else
                second = NULL;
        }

        return newHead.next;
    }
};

int main(void)
{
    Solution slt;

    int size, val;
    cin >> size;
    
    ListNode* head = NULL;
    ListNode* curNode = NULL;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        if (i == 0)
        {
            head = new ListNode(val);
            curNode = head;
        }
        else
        {
            curNode->next = new ListNode(val);
            curNode = curNode->next;
        }
    }

    cout << "Original list: ";
    printList(head);

    ListNode* newHead = slt.swapPairs(head);

    cout << "Swapped list: ";
    printList(newHead);
    destroyList(newHead);

    return 0;
}
