#include <string>
using namespace std;
/*
Insert
 * When we insert a word
 * check if each char is present or not
 * if not mark the alphabet in the trie and point that alphabet to a new trie
 * At the end of traversal of word
 * the last trie node won't have any word as marked
 * change the flag of that node to true
 *
Search
 * Trace every node for each word, at the last node check if flag is true,
 * if flag is false that means it exists as a prefix and not a entire word
 * eg: trie has apple
 * search(app) will result in last node being l, here flag is false i.e app exists as prefix and not a word

Prefix Search:
 * while travering if we encounter a null instead of trie node then prefix does not exists
 * It points to null if alphabet is not marked in trie

 */

struct Node {
// public:
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* nextNode(char ch){
        return links[ch - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void markEnd(){
        flag=true;
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
            if(node->containsKey(word[i]) == 0)
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
            if(!node->containsKey(word[i]))
                return false;
            node = node->nextNode(word[i]);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->containsKey(prefix[i]) == 0)
                return false;
            node = node->nextNode(prefix[i]);
        }

        return true;
    }
};