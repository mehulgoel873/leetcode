//https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150

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

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    int n = 0;
    ListNode* cur = head;
    ListNode* tail = NULL;
    while (cur != NULL) {
        tail = cur;
        cur = cur->next;
        n++;
    }
    tail->next = head;
    int remove = n - k % n;
    cur = head;
    while (remove > 1) {
        cur = cur->next;
        remove--;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    rotateRight(head, 2);
    return 0;
}