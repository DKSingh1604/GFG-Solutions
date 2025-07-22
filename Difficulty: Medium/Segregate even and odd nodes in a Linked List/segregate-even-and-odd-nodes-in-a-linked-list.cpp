// User function template for C++

/*
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
    Node* divide(Node* head) {
        // code here
        
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;
        
        while(curr){
            if(curr -> data % 2 == 0){
                //even
                if(evenStart == NULL){
                    evenStart = curr;
                    evenEnd = curr;
                }
                else{
                    evenEnd -> next = curr;
                    evenEnd = evenEnd -> next;
                }
                
            }
            else{
                //odd
                if(oddStart == NULL){
                    oddStart = curr;
                    oddEnd = curr;
                    
                }
                else{
                    oddEnd -> next = curr;
                    oddEnd = oddEnd -> next;
                }
                
                
                
            }
            curr = curr -> next;
        }
        evenEnd -> next = oddStart;
        oddEnd -> next = NULL;
        
        return evenStart;
    }
};