// https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

class Trie
{
public:
    char c;
    unordered_map<char, Trie *> children;
    bool endWord = false;
    Trie()
    {
    }

    void insert(string word)
    {
        if (word == "")
        {
            endWord = true;
            return;
        }
        char letter = word[0];
        if (children.find(letter) == children.end())
        {
            children[letter] = new Trie();
            children[letter]->c = letter;
            children[letter]->insert(word.substr(1, word.size() - 1));
        }
        else
        {
            children[letter]->insert(word.substr(1, word.size() - 1));
        }
        return;
    }

    bool search(string word)
    {
        if (word == "")
            return endWord;
        char letter = word[0];
        if (children.find(letter) == children.end())
            return false;
        return children[letter]->search(word.substr(1, word.size() - 1));
    }

    bool startsWith(string prefix)
    {
        if (prefix == "")
            return true;

        char letter = prefix[0];
        if (children.find(letter) == children.end())
            return false;
        return children[letter]->startsWith(prefix.substr(1, prefix.size() - 1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << "\n";
    cout << obj->search("app") << "\n";
    cout << obj->startsWith("app") << "\n";
    obj->insert("app");
    cout << obj->search("app") << "\n";
    return 0;
}