class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int l = 0;
        int r = 1;
        set<char> mySet;
        mySet.insert(s[0]);
        int maxCount = 1;
        int count = 1;
        while(r < n){
            if(mySet.find(s[r]) != mySet.end()){
                mySet.erase(s[l]);
                l++;
                count--;
            }
            else{
                mySet.insert(s[r]);
                r++;
                count++;
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
