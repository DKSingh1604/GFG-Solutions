class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        
        vector<int> ans;
       
        int aS = a.size();
        int bS = b.size();
       
        int i = 0;
        int j = 0;
        while(i < aS && j < bS){
            
            while (i > 0 && i < aS && a[i] == a[i - 1]) i++;
            while (j > 0 && j < bS && b[j] == b[j - 1]) j++;
            
            if (i >= aS || j >= bS) break;
            
            if(a[i] == b[j]){
               ans.push_back(a[i]);
               i++;
               j++;
            }
            else{
                if( a[i] < b[j]){
                   ans.push_back(a[i]);
                   i++;
                }
                else{
                    ans.push_back(b[j]);
                    j++;
                }
               
               
               
            }
        }
        
        while(i < aS){
            if(i == 0 || a[i] != a[i-1]){
                ans.push_back(a[i]);
            }
            i++;
        }
        while(j < bS){
            if(j == 0 || b[j] != b[j-1]){
                ans.push_back(b[j]);
            }
            j++;
        }
        return ans;
       
       
    }
};