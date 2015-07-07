#include <cmath>
#include <cstdio>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constructList(long long* numbers, int n)
{
    ListNode* l = new ListNode(numbers[0]);
    ListNode* it = l;
    for (int i = 1; i < n; i++)
    {
        it->next = new ListNode(numbers[i]);
        it = it->next;
    }

    return l;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long number1 = 0, number2 = 0;
        int i = 0;
        while (l1 != NULL)
        {
            number1 += pow(10, i) * l1->val;
            l1 = l1->next;
            i++;
        }
        i = 0;
        while (l2 != NULL)
        {
            number2 += pow(10, i) * l2->val;
            l2 = l2->next;
            i++;
        }
        long long result = number1 + number2;
        printf("%lld + %lld = %lld\n", number1, number2, result);
        
        ListNode* resultList = new ListNode(result%10);
        result /= 10;
        ListNode* resultListIter = resultList;
        while (result != 0)
        {
            resultListIter->next = new ListNode(result%10);
            result /= 10;
            resultListIter = resultListIter->next;
        }

        return resultList;
    }
};

int main(void)
{
    /*
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    */
    
    /*
    long long numbers1[3] = {2, 4, 3};
    long long numbers2[3] = {5, 6, 4};
    ListNode* l1 = constructList(numbers1, 3);
    ListNode* l2 = constructList(numbers2, 3);
    */

    long long numbers1[] = {9};
    long long numbers2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    ListNode* l1 = constructList(numbers1, 1);
    ListNode* l2 = constructList(numbers2, 10);
    
    Solution slt;
    ListNode* resultList = slt.addTwoNumbers(l1, l2);
    while (resultList != NULL)
    {
        printf("%d", resultList->val);
        if (resultList->next != NULL)
            printf(" -> ");
        else 
            printf("\n");
        resultList = resultList->next;
    }

    return 0;
}
