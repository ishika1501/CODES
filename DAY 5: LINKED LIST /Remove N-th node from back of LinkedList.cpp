
BRUTE FORCE :

N the node from back is the L-N+1 th node from the front;


    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode*d = head;
        int len=0;

        while(d!=NULL){
            len++;
            d=d->next;
        }
        if(len-n==0){
            return head=head->next;
            delete(head);
        }
        
        d=head;

        for(int i=0 ; i<len-n-1 ;i++){
            d=d->next;
        }
        
        d->next=d->next->next;
        return head;
    }


OPTIMAL APPROACH :

We can use fast and slow pointers 
it will make the time from O(2*N)-->)(N)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* d = head;

        for (int i = 0; i < n; ++i) {
            if (fast == NULL) return head; // In case n is larger than the list length
            fast = fast->next;
        }

        if (fast == NULL) return head->next; // If fast is NULL, we need to remove the head

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }

};


