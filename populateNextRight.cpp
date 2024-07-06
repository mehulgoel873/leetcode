//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/?envType=study-plan-v2&envId=top-interview-150

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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    vector<Node*> level = {root};
    vector<Node*> nextLevel = {};
    while (level.size() != 0) {
        for (int i = 0; i < level.size(); i++) {
            Node* n = level[i];
            if (n->left != NULL) nextLevel.push_back(n->left);
            if (n->right != NULL) nextLevel.push_back(n->right);
            if (i < level.size() - 1) n->next = level[i+1];
        }
        level = nextLevel;
        nextLevel = {};
    }
    return root;
}

int main() {
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5), NULL), new Node(3, NULL, new Node(7), NULL), NULL);
    connect(root);
    return 0;
}