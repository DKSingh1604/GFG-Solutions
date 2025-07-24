/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution {
  public:
    Node* pairWiseSwap(Node* head) {
        // The task is to complete this method
        
        if (head == NULL || head->next == NULL) return head;

        Node* prev = NULL;
        Node* curr = head;
        head = head->next; // new head after first swap
    
        while (curr != NULL && curr->next != NULL) {
            Node* next = curr->next;
            Node* nextPair = next->next;
    
            
            next->next = curr;
            curr->next = nextPair;
    
            
            if (prev != NULL) {
                prev->next = next;
            }
    
           
            prev = curr;
            curr = nextPair;
        }
    
        return head;
    }
};