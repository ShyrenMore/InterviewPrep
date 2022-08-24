/*
given an arr of string
find a string such that every prefix of string is present in arr
you need to return longest such string
In case of multiple str of same len, return lexicographically smallest one,
if no such str exists return None

eg: n ni nin ninj ninja ninga
op: ninja

Link: https://www.codingninjas.com/codestudio/problems/complete-string_2687860?topList=striver-sde-sheet-problems

Approach:
Insert all the words in a trie
reiterate and check if all the prefix exist or not

struct of trie: arr[26], bool flag

Time: O(N*len) for insert + O(N*len) for reiterate
Space: O(26)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    // public:
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *nextNode(char ch)
    {
        return links[ch - 'a'];
    }

    bool isEnd()
    {
        return flag;
    }

    void markEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            // does this node contains the char
            if (node->containsKey(word[i]) == 0)
                node->put(word[i], new Node());
            // move to ref trie
            node = node->nextNode(word[i]);
        }

        // set flag of last node true after traversal
        node->markEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->nextNode(word[i]);
        }

        return node->isEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        bool flag = true;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->nextNode(word[i]);
                if(!node->isEnd())
                    return false;
            }
            else return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    Trie t;
    for(auto &word: a)
        t.insert(word);

    string ans = "";
    for(auto &word: a)
    {
        if(t.checkIfPrefixExists(word))
        {
            if(word.length() > ans.length())
                ans = word;
            else if (word.length() == ans.length() && word < ans)
                ans = word;
        }
    }

    if(ans.length() == 0)
        ans = "None";

    return ans;
}