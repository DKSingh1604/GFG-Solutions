class Solution {
  public:
    void SortedDuplicates(int n, vector<int> &arr) {
        // code here
        
        
        vector<int> duplicates;
        unordered_map<int, int> mp;//number: count
        
        // int number;
        for(int i = 0; i < n; i++){
            // number = arr[i];
            
            //have found
            // if(mp.find(number) != mp.end()){
            //     mp[number]++;
            // }
            // else{
            //     //not found
            //     mp[number] = 1;
            // }
                mp[arr[i]]++;
        }
        
        
        auto it = mp.begin();
        while(it != mp.end()){
            if(it -> second > 1){
                duplicates.push_back(it -> first);
               
            }
            
            ++it;
        }
        if(duplicates.empty()) {
            cout<<"-1\n";
            return;
        }
        sort(duplicates.begin(), duplicates.end());
        
        for(int i = 0; i < duplicates.size(); i++)
            cout << duplicates[i] << " ";
        cout << "\n";

        
        
        
    }
};