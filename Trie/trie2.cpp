#include <string>
using namespace std;

/*

Link: https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

video: https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=2

Here we maintain two vars
endwith and countPrefix

Insert
 * When we insert a word
 * check if each char is present or not
 * if not mark the alphabet in the trie and point that alphabet to a new trie
 * increase the countPrefix by 1
 * At the end of traversal of word
 * the last trie node won't have any word as marked
 * change endWith = 1 and countPrefix remains as 1

On another word traversal, if prefix match, increment countPrefix to 2
eg: apple
and apple
on second traversal, nodes a, p, p, l, e already exists each with countPrefix=1
so we just increment countPrefix in each node

countWordsStartingWith
 * utilise the countPrefix variable at last node of word

countWordsEqualTo:
 * utilise the endswith variable at last node of word

erase:
    reduce Countprefix while traversing alphabets

 */

class Node
{
public:
    Node *links[26];
    int countEndWith = 0, countPrefix = 0;

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
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]) == 0)
                node->put(word[i], new Node());
            // move to ref trie
            node = node->nextNode(word[i]);
            node->countPrefix++;
        }
        node->countEndWith++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->nextNode(word[i]);
            else
                return 0;
        }
        return node->countEndWith;
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->nextNode(word[i]); 
            else
                return 0;
        }
        return node->countPrefix;
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->nextNode(word[i]); 
                node->countPrefix--;
            }
            else
                return;
        }
        node->countEndWith--;
    }
};
