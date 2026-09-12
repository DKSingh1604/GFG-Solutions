class Solution {
  public:
    int signum(int a, int b){
        
        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }
    
    void callMedian(vector<int> &arr, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, double &median, int element){
        
        switch(signum(maxi.size(), mini.size())){
            //when the size of both the heaps is same...
            case 0: 
                //....and we insert to the right of median that is in the minHeap
                if(element > median){
                    mini.push(element);
                    median = mini.top();
                }
                
                //...and we insert to the left of median that is in the maxHeap
                else {
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
                
            // when the size of maxHeap is greater than that of minHeap
            case 1:
                //....and we insert to the right of median that is in the minHeap
                if(element > median){
                    mini.push(element);
                }
                //...and we insert to the left of median that is in the maxHeap
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                }
                median = (mini.top() + maxi.top())/2.0;
                break;
            
            // when the size of minHeap is greater than that of maxHeap
            case -1:
            //....and we insert to the right of median that is in the minHeap
            if(element > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            }
            
            //...and we insert to the left of median that is in the maxHeap
            else{
                maxi.push(element);
            }
            median = (mini.top() + maxi.top())/2.0;
            break;

        }
    }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<double> ans;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        double median = -1;
        
        for(int i = 0; i < n; i++){
            int element = arr[i];
            callMedian(arr, maxHeap, minHeap, median, element);
            ans.push_back(median);
        }
        return ans;
    }
};
