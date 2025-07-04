class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int s1 = arr1.size();
        int s2 = arr2.size();
        
        int sum1 = 0;
        int sum2 = 0;
        int result = 0;
        int i= 0;
        int j = 0;
        
        
        while(i < s1 && j < s2){
            if(arr1[i] < arr2[j]){
                sum1 += arr1[i];
                i++;
            }
            else if(arr1[i] > arr2[j]){
                sum2 += arr2[j];
                j++;
            }
            else{
                result += max(sum1, sum2) + arr1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }  
         while (i < s1) sum1 += arr1[i++];
        while (j < s2) sum2 += arr2[j++];
        result += max(sum1, sum2);
        return result;
    }
};