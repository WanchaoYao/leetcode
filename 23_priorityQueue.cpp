#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    bool static myfunction(ListNode* node1, ListNode* node2)
    {
        return (node1->val > node2->val);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, bool(*)(ListNode*, ListNode*)> q(myfunction);

        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                q.push(lists[i]);

        if (q.empty())
            return NULL;

        ListNode mergedHead = ListNode(0);
        ListNode* curNode = &mergedHead;

        while (!q.empty())
        {
            curNode->next = q.top();
            q.pop();
            curNode = curNode->next;

            if (curNode->next)
            {
                q.push(curNode->next);
            }
        }

        return mergedHead.next;
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
