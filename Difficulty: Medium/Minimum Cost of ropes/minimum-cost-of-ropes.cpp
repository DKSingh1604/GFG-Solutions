class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size() < 2){
            return 0;
        }
        //step0 - make a min heap and put the arr elements in the pq
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        int cost = 0;
        //step1 - find the two smallest values
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            int sum;
            sum = a + b;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};