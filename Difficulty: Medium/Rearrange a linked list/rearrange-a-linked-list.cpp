/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        if(head == NULL || head -> next == NULL) return; 
        
        Node* oddHead = NULL;
        Node* oddEnd = NULL;
        Node* evenHead = NULL;
        Node* evenEnd = NULL;
        Node* curr = head;
        int count = 1;
        
        while(curr){
            if(count % 2 != 0){
                //odd data
                if(oddHead == NULL){
                    //first odd node(first node)
                    oddHead = curr;
                    oddEnd = curr;
                    
                }
                else{
                    oddEnd -> next = curr;
                    oddEnd = oddEnd -> next;
                }
                
                
                
            }
            else{
                //even data
                if(evenHead == NULL){
                    //first even node(second node)
                    evenHead = curr;
                    evenEnd = curr;
                    
                }
                else{
                    evenEnd -> next = curr;
                    evenEnd = evenEnd -> next;
                    
                    
                }
                
            }
            count++;
            curr = curr -> next;
        }
        evenEnd -> next = NULL;
        oddEnd -> next = evenHead;
        
        
    }
};