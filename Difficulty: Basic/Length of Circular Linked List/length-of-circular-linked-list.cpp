/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};
*/

class Solution {
  public:
    int getLength(Node *head) {
        // code here
        
        if(head -> next == head) return 1;
        
        Node* still = head;
        Node* go = head -> next;
        int count = 1;
        while(still != go){
            count++;
            go = go -> next;
        }
        
        return count;
    }
};