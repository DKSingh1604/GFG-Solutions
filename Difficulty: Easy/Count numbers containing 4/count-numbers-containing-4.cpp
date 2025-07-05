
class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        if(n >= 4 && n <= 10) return 1;
        
        int count = 0;
        
        for(int i = 1; i <= n; i++){
            int restN = i;
            
            int digit;
            
            while(restN != 0){
                digit = restN % 10;
                if(digit == 4){
                    count++;
                    break;
                    
                }
                else{
                    restN = restN / 10;
                }
            }
            
            
        }
        return count;
    }
};
