/*
Time: O(m+n)
Space: O(1)
*/
class Solution {
public:
    
    int getSize(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            ++cnt;
            head = head->next;
        }
        
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int listAsz = getSize(headA);
        int listBsz = getSize(headB);
        
        
        ListNode *ptr1=headA,*ptr2=headB;
        if(listAsz < listBsz){
            int x = listBsz - listAsz;
            while(x--){
                ptr2=ptr2->next;         
            }
        }
        else if(listAsz > listBsz){
            int x = listAsz - listBsz;
            while(x--){
                ptr1=ptr1->next;
            }
        } 
        
        while(true){
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
            
        return NULL;
        
    }
        
};
