//https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150

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

ListNode* partition(ListNode* head, int x) {
    if (head == NULL) return NULL;
    ListNode* lastMin = NULL;
    ListNode* cur = head;
    ListNode* prev = NULL;
    if (cur->val < x) {
        lastMin = cur;
        prev = cur;
        cur = cur->next;
    }
    while (cur != NULL) {
        if (cur->val < x) {
            prev->next = cur->next;
            ListNode* l = cur;
            cur = cur->next;
            if (lastMin == NULL) {
                l->next = head;
                head = l;
                lastMin = l;
            }
            else {
                l->next = lastMin->next;
                lastMin->next = l;
                lastMin = l;
                while (prev->next != cur) prev = prev->next;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    partition(head, 4);
    return 0;
}