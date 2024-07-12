
BRUTE FORCE : 

we will traverse the node k times and 
each time we will shift the last node to the front;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return NULL;
            for(int i=0 ;i<k ;i++){
                ListNode* node=head;
                while(node->next->next!=NULL)node=node->next;
                ListNode* temp=node->next;
                node->next=NULL;
                temp->next=head;
                head=temp;
            }
            return head;
        }
};


OPTIMAL :

1. we will rotate the entire linkedList 
2. attach the last node to the first to make it circular
3. go till len-k times, then break from kth node .


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k ==0 )return head;
        int len=1;
        ListNode* temp=head;

        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        
        temp->next=head;
        k=k%len;
        int cut=len-k;

        while(cut--){
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};