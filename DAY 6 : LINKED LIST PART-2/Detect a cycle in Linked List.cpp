BRUTE FORCE:

we can store the values in a map and then try to traverse it.

class Solution {
public:
    bool hasCycle(ListNode *head) {

    ListNode* temp = head;  
    unordered_map<ListNode*, int> nodeMap;  

    while (temp != nullptr) {
        // If the node is already in the
        // map, there is a loop
        if (nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }
        // Store the current node
        // in the map
        nodeMap[temp] = 1;
        
        // Move to the next node
        temp = temp->next;  
    }
    return false;
    }
};



OPTIMAL APPROACH :

We can do this by using fast and slow pointer 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast =fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};