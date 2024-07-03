//https://leetcode.com/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* cur = head;
    n--;
    while (n > 0) {
        cur = cur->next;
        n--;
    }
    ListNode* pt = NULL;
    while (cur->next != NULL) {
        cur = cur->next;
        if (pt != NULL) pt = pt->next;
        else pt = head;
    }
    if (pt != NULL) pt->next = pt->next->next;
    else head = head->next;
    return head;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    removeNthFromEnd(head, 2);
    return 0;
}