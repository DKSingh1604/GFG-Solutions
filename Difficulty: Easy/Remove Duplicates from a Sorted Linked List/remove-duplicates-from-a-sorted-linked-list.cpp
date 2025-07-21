/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        if(head -> next -> next == NULL){
            if(head -> data == head -> next -> data){
                
                head -> next = NULL;
            }
        }
        
        
        Node* temp = head;
        
        
        while(temp -> next != NULL){
            
            if(temp -> data == temp -> next -> data){
                temp -> next = temp -> next -> next;
            }
            
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
};