#include <iostream>
#include <vector>
#include <climits>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        int size = lists.size();
        while (size > 1)
        {
            for (int i = 0; i < size/2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[size-1-i]);
            size = (size + 1) / 2;
        }

        return lists.front();
    }
};

int main(void)
{
    Solution slt;

    int row_size, col_size, val;
    
    cin >> row_size;
    vector<ListNode*> lists(row_size, NULL);
    
    ListNode* node = NULL;
    for (int i = 0; i < row_size; i++)
    {
        cin >> col_size;

        if (col_size > 0)
        {
            cin >> val;
            node = new ListNode(val);
            lists[i] = node;
        }   
        else
            continue;

        for (int j = 1; j < col_size; j++)
        {
            cin >> val;
            node->next = new ListNode(val);
            node = node->next;
        }
    }

    ListNode* mergedList = slt.mergeKLists(lists);

    cout << "Count of list(s): " << lists.size() << endl;
    cout << "Merged list: ";
    printList(mergedList);
    destroyList(mergedList);

    return 0;
}
