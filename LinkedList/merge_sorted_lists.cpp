/*
given two sorted linked list, merge them into another sorted list
also you need to utilise the same space, no extra space
ip:
a: 10->20->30
b: 5->25
op:
5->10->20->25->30

ip:
a: 10->20
b: NULL
op:
10->20

ip:
a: 10
b: 40->50
op:
10->40->50

Maintain two pointers a and b for two linked list
the head of resultant linked list will be the smaller element b/w head of a and b
Maintain a tail pointer in resultant linked list, so we can directly append a node at the end in constant time

so initialise tail with head of resultant LL, i.e smaller value of both heads

move a and b, whenever we add a node in resultant LL
compare a and b, whichever is smaller, add it after the tail

we do this until either a or b points to null
and sfter that we attach remaining part of LL to our merged list
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // corner case: if any of LL is empty
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        // initialise head and tail of merged list
        ListNode *head = NULL;
        ListNode *tail = NULL;
        if(list1->val <= list2->val)
        {
            head = tail = list1;
            list1 = list1->next;
        }
        else 
        {
            head = tail = list2;
            list2 = list2->next;
        }

        // merging part
        // pick smaller of two nodes
        while(list1!=NULL && list2!=NULL)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else 
            {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }

        // extra nodes
        if(list1 == NULL)
            tail->next = list2;
        else
            tail->next = list1;

        return head;
    }
};