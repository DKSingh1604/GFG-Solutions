/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(!head || !head -> next) return head;
        
        unordered_set<int> mySet;
        
        Node* temp = head;
        mySet.insert(temp -> data);
        
        while(temp -> next){
            if(mySet.find(temp -> next -> data) != mySet.end()){
                //we already have the value in the set
                Node* toDelete = temp -> next;
                temp -> next = temp -> next -> next;
                delete(toDelete);
            }else{
                //the value is not there in the set
                mySet.insert(temp -> next -> data);
                temp = temp -> next;
            }
        }
        
        return head;
    }
};