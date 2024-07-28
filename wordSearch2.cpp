// https://leetcode.com/problems/word-search-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for (auto &a : child)
            a = nullptr;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *p = root;
        for (auto &a : s)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix = false)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }
        if (prefix == false)
            return p->isWord;
        return true;
    }
    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};
vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> foundWords = {};
    Trie *obj = new Trie();
    for (string word : words)
    {
        obj->insert(word);
    }

    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[0].size(); c++)
        {
            unordered_set<vector<int>> visited = {};
            stack<char> S;
        }
    }
}

int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> out = findWords(board, words);
    return 0;
}