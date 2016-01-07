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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;
        
        int min_val;
        if (l1->val <= l2->val)
        {
            min_val = l1->val;
            l1 = l1->next;
        }
        else
        {
            min_val = l2->val;
            l2 = l2->next;
        }
        ListNode* l = new ListNode(min_val);
        ListNode* head = l;
            
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                min_val = l1->val;
                l1 = l1->next;
            }
            else
            {
                min_val = l2->val;
                l2 = l2->next;
            }

            ListNode* node = new ListNode(min_val);
            l->next = node;
            l = l->next;
        }        

        while (l1 != NULL)
        {
            ListNode* node = new ListNode(l1->val);
            l->next = node;
            l = l->next;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            ListNode* node = new ListNode(l2->val);
            l->next = node;
            l = l->next;
            l2 = l2->next;
        }

        return head;
    }
};

int main(void)
{
    Solution slt;

    //int arr1[] = {1, 2, 3, 4, 5};
    //int arr2[] = {1, 2, 3, 4, 5};

    //int arr1[] = {1, 2};
    //int arr2[] = {1};

    //int arr1[] = {3, 4};
    //int arr2[] = {1, 2};
    
    //int arr1[] = {};
    //int arr2[] = {};

    int arr1[] = {};
    int arr2[] = {1};

    int size = sizeof(arr1)/sizeof(int);
    ListNode* list = NULL;
    if (size > 0)
        list = new ListNode(arr1[0]);
    ListNode* head = list;
    for (int i = 1; i < size; i++)
    {
        ListNode* node = new ListNode(arr1[i]);
        list->next = node;
        list = list->next;
    }
    printList(head);
    ListNode* l1 = head;
    ListNode* head1 = l1;

    size = sizeof(arr2)/sizeof(int);
    list = NULL;
    if (size > 0)
        list = new ListNode(arr2[0]);
    head = list;
    for (int i = 1; i < size; i++)
    {
        ListNode* node = new ListNode(arr2[i]);
        list->next = node;
        list = list->next;
    }
    printList(head);
    ListNode* l2 = head;
    ListNode* head2 = l2;

    ListNode* l = slt.mergeTwoLists(l1, l2);
    printList(l);

    while (head1 != NULL)
    {
        ListNode* node = head1;
        head1 = head1->next;
        delete node;
    }

    while (head2 != NULL)
    {
        ListNode* node = head2;
        head2 = head2->next;
        delete node;
    }

    if (l != l1 && l != l2)
    {
        while (l != NULL)
        {
            ListNode* node = l;
            l = l->next;
            delete node; // Bug: double free or corruption (fasttop)
        }
    }

    return 0;
}
