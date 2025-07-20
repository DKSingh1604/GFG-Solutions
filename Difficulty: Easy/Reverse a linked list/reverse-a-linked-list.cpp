/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if(head == NULL) return NULL;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* aage = NULL;
        
        while(curr != NULL){
            aage = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = aage;
            
            
            
        }
        
        return prev;
        
    }
};