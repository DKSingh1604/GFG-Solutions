/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head == NULL || head -> next == NULL) return head;
        
        DLLNode* curr = head;
        DLLNode* temp = NULL;
        
        while(curr){
            temp = curr -> prev;
            curr -> prev = curr -> next;
            curr -> next = temp;
            
            curr = curr -> prev;
        }
        
        if(temp) head = temp -> prev;
        
        return head;
    }
};