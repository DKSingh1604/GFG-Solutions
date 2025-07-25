/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        
        if(head == NULL) return 0;
        
        Node* temp = head;
        int count = 0;
        
        while(temp){
            if(temp -> data == key) count++;
            if(temp -> next) {
                temp = temp -> next;
            }
            else{
                break;
            }
           
            
        }
        
        return count;
    }
};