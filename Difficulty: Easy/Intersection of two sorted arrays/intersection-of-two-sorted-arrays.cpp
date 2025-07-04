class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // Your code here
        int size1 = arr1.size();
        int size2 = arr2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < size1 && j < size2){
            if(arr1[i] < arr2[j]){
                i++;
            }
            else if(arr1[i] > arr2[j]){
                j++;
            }
            else{
                if(arr1[i] != arr1[i-1] && arr2[j] != arr2[j-1]){
                    ans.push_back(arr1[i]);
                    
                }
                i++;
                j++;
                
            }
        }
        return ans;
    }
};