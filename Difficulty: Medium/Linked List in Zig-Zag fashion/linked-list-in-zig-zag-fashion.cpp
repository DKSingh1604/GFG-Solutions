/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        if(head == NULL || head -> next == NULL) return head;
        
        if(head -> next -> next == NULL){
            if(head -> data > head -> next -> data){
                swap(head -> next -> data, head -> data);
            }
            return head;
        }
        
        Node* curr = head;
        bool flag = true;      // <= condition
        
        while(curr && curr -> next){
            if(flag){
                if(curr -> data > curr -> next -> data){
                    swap(curr -> data, curr -> next -> data);
                }
            }
            else{
                //flag false
                if(curr -> data < curr -> next -> data){
                    swap(curr -> data, curr -> next -> data);
                }
            }
            
            flag = !flag;
            curr = curr -> next;
        }
        
        return head;
        
    }   
        
};