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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* l = head;
    ListNode* prev = NULL;
    left--;
    right--;
    while (left > 0) {
        prev = l;
        l = l->next;
        left--;
        right--;
    }
    ListNode* r = l;
    while (right > 0) {
        right--;
        r = l->next;
        l->next = r->next;
        if (prev != NULL) {
            r->next = prev->next;
            prev->next = r;
        }
        else {
            r->next = head;
            head = r;
        }
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(3, new ListNode(5));
    reverseBetween(head, 1, 2);
    return 0;
}