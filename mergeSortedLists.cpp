// https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *helper(vector<ListNode *> &lists, int start, int end)
{
    if (start == end)
        return NULL;
    if (start == end - 1)
    {
        return lists[start];
    }
    int mid = (start + end) / 2;
    lists[start] = helper(lists, start, mid);
    lists[mid] = helper(lists, mid, end);

    ListNode *head = NULL;
    ListNode *firstHead = lists[start];
    ListNode *secondHead = lists[mid];

    if (firstHead == NULL)
    {
        return secondHead;
    }
    else if (secondHead == NULL)
    {
        return firstHead;
    }

    if (firstHead->val < secondHead->val)
    {
        head = firstHead;
        firstHead = firstHead->next;
    }
    else
    {
        head = secondHead;
        secondHead = secondHead->next;
    }

    ListNode *cur = head;
    while (firstHead != NULL && secondHead != NULL)
    {
        if (firstHead->val < secondHead->val)
        {
            cur->next = firstHead;
            firstHead = firstHead->next;
        }
        else
        {
            cur->next = secondHead;
            secondHead = secondHead->next;
        }
        cur = cur->next;
    }

    while (firstHead != NULL)
    {
        cur->next = firstHead;
        firstHead = firstHead->next;
        cur = cur->next;
    }

    while (secondHead != NULL)
    {
        cur->next = secondHead;
        secondHead = secondHead->next;
        cur = cur->next;
    }

    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    return helper(lists, 0, lists.size());
}

int main()
{
    vector<ListNode *> in = {new ListNode(1, new ListNode(4, new ListNode(5))), new ListNode(1, new ListNode(3, new ListNode(4))), new ListNode(2, new ListNode(6))};
    ListNode *head = mergeKLists(in);
    return 0;
}
