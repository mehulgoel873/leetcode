#include <iostream>
#include <string>

using namespace std;

struct ListNode{
    ListNode *next;
    int val;
};

//Solution
ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, bool carry) {
    int res = 0;
    if (carry) res++;
    if (l1 == nullptr && l2 == nullptr && carry) {
        ListNode *resNode = new ListNode;
        resNode->val = res;
        resNode->next = nullptr;
        return resNode;
    }
    else if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }

    ListNode* l1Next = nullptr;
    ListNode* l2Next = nullptr;
    if (l1 != nullptr) {
        res += l1 -> val;
        l1Next = l1->next;
    }

    if (l2 != nullptr) {
        res += l2 -> val;
        l2Next = l2 -> next;
    }

    bool nextCarry = false;
    if (res >= 10) {
        res = res % 10;
        nextCarry = true;
    }

    ListNode *resNode = new ListNode;
    resNode->val = res;
    resNode->next = addTwoNumbersHelper(l1Next, l2Next, nextCarry);
    return resNode;

}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbersHelper(l1, l2, false);
}

int main () {
    ListNode *l1 = new ListNode;
    l1->val = 2;
    l1->next = nullptr;

    ListNode *res = l1;
    while (res != nullptr) {
        cout << res->val;
        res = res -> next;
    }
}
