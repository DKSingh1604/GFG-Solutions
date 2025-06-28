class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        //my solution
        // int n = a.size();
        // sort(b.begin(), b.end());
        // vector<int> ans;
        
        // for(int i = 0; i < n; i++){
        //     int count = 0;
        //     int l = 0, h = b.size()-1;
            
        //     while(l <= h){
        //         int mid = (l+(h-l))/2;
        //         if(a[i] >= b[mid]){
        //             count = mid+1;
        //             l = mid+1;
        //         }
        //         else{
        //             h = mid - 1;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        
         int n=a.size();
        vector<int>ans;
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            int l=0,r=b.size()-1;
            int count=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(a[i]>=b[mid]){
                    count=(mid+1);
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};