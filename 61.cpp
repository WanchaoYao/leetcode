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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;

        int len = 1;
        ListNode *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0)
            return head;

        ListNode *targetNode = head, *previousNode = NULL;
        for (int i = 0; i < len - k; i++)
        {
            previousNode = targetNode;
            targetNode = targetNode->next;
        }
        
        tail->next = head;
        previousNode->next = NULL;
        head = targetNode;

        return head;
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    Solution slt;

    ListNode *head = NULL, *list = NULL, *node = NULL;
    head = list = new ListNode(1);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        node = new ListNode(i+1);
        list->next = node;
        list = list->next;
    }
    printList(head);

    head = slt.rotateRight(head, k);
    printList(head);
    
    while (head != NULL)
    {
        node = head->next;
        delete head;
        head = node;
    }

    return 0;
}
