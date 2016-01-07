#include <iostream>
#include <vector>
#include <list>
#include <iterator>
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
    bool static myfunction(ListNode* node1, ListNode* node2)
    {
        if (node1 == NULL && node2 == NULL)
            return false;
        if (node1 == NULL)
            return true;
        if (node2 == NULL)
            return false;

        return (node1->val < node2->val);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mergedList = NULL;
        ListNode* mergedHead = NULL;
        ListNode* node = NULL;

        list<ListNode*> sortedLists(lists.begin(), lists.end());
        sortedLists.sort(myfunction);

        list<ListNode*>::iterator iter = sortedLists.begin();
        while (*iter == NULL && iter != sortedLists.end())
            //iter = sortedLists.erase(iter);
            iter++;
    
        if (iter != sortedLists.end())
        {
            node = new ListNode((*iter)->val);
            mergedHead = mergedList = node;

            *iter = (*iter)->next;

            if (*iter == NULL)
                //iter = sortedLists.erase(iter);
                iter++;
        }

        while (iter != sortedLists.end())
        {
            int val = (*iter)->val;
            list<ListNode*>::iterator it = iter;
            it++; 
            if (it == sortedLists.end())
            {
                while (*iter != NULL)
                {
                    node = new ListNode((*iter)->val);
                    mergedList->next = node;
                    mergedList = mergedList->next;
                    *iter = (*iter)->next;
                }
                break;
            }

            if (val > (*it)->val)
            {
                it++;
                while (it != sortedLists.end() && val > (*it)->val)
                    it++;
                    
                sortedLists.insert(it, *iter);
                iter = sortedLists.erase(iter);
            }

            node = new ListNode((*iter)->val);
            mergedList->next = node;
            mergedList = mergedList->next;
            
            *iter = (*iter)->next;

            if (*iter == NULL)
                //iter = sortedLists.erase(iter);
                iter++;
        }

        return mergedHead;
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
    for (int i = 0; i < lists.size(); i++)
    {
        cout << "List[" << i << "]: ";
        printList(lists[i]);
        destroyList(lists[i]);
    }

    cout << "Merged list: ";
    printList(mergedList);
    destroyList(mergedList);

    return 0;
}
