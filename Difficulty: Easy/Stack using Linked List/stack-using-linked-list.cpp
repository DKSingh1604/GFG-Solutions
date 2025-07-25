class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* new_node = new StackNode(x);
        
        new_node -> next = top;
        top = new_node;
        
    }

    int pop() {
        if(top == NULL){
            return -1;
        }
        else{
            int popped = top -> data;
            
            StackNode* temp = top;
            
            top = top -> next;
            
            delete temp;
            
            return popped;
        }
        // code here
    }

    MyStack() { top = NULL; }
};