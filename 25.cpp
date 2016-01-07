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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode newHead(0);

        ListNode* firstNode = head;
        ListNode* secondNode = firstNode->next;
        ListNode* thirdNode = NULL;

        int cnt = 1;
        ListNode* lastGroupTail = &newHead;
        ListNode* currGroupTail = firstNode;
        currGroupTail->next = NULL;
        while (secondNode != NULL)
        {
            thirdNode = secondNode->next;

            secondNode->next = firstNode;
            cnt++;

            // Finish reversing a group
            if (cnt == k)
            {
                lastGroupTail->next = secondNode;
                lastGroupTail = currGroupTail;

                // End of the list
                if (thirdNode == NULL)
                {
                    cnt = 0;
                    break;
                }
                // Start a new group
                else
                {
                    cnt = 1;
                    firstNode = thirdNode;
                    secondNode = firstNode->next;
                    currGroupTail = firstNode;
                    currGroupTail->next = NULL;
                }
            }
            else
            {
                // Continue reversing a group
                firstNode = secondNode;
                secondNode = thirdNode;
            }
        }

        if (cnt > 0)
            lastGroupTail->next = reverseKGroup(firstNode, cnt);

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

    int K;
    cin >> K;
    ListNode* newHead = slt.reverseKGroup(head, K);

    cout << "Reversed list: ";
    printList(newHead);
    destroyList(newHead);

    return 0;
}
