class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        int index = 0;
        //push k+1 elements from array to min heap
        for(int i = 0; i <= k && i < arr.size(); i++){
            pq.push(arr[i]);
        }
        
        //rest of the array elements
        for(int i = k+1; i < arr.size(); i++){
            arr[index] = pq.top();
            pq.pop();
            pq.push(arr[i]);
            index++;
        }
        
        //for rest of the elements in min heap
        while(!pq.empty()){
            arr[index] = pq.top();
            pq.pop();
            index++;
        }
        
        
    }
};