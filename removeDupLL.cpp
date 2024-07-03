//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    bool dup = false;
    while (cur != NULL) {
        if (cur->next != NULL && cur->val == cur->next->val) {
            dup = true;
            cur->next = cur->next->next;
        }
        else {
            if (dup) {
                cur = cur->next;
                if (prev == NULL) head = cur;
                else prev->next = cur; 
                dup = false;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
    deleteDuplicates(head);
    return 0;
}