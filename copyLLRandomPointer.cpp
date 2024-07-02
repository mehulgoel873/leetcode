//https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map> 
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    Node* cur = head;
    Node* nL = new Node(0);
    Node* curNew = nL;
    unordered_map<Node*, Node*> pairings;
    while (cur != NULL) {
        Node* newNode = new Node(cur->val);
        newNode->random = cur->random;
        pairings[cur] = newNode;
        cur = cur->next;
        curNew->next = newNode;
        curNew = newNode;
    }

    curNew = nL->next;
    while (curNew != NULL) {
        if (curNew-> random != NULL)  curNew->random = pairings[curNew->random];
        curNew = curNew->next;
    }

    return nL->next;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node* newHead = copyRandomList(head);
    return 0;

}