class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        map<int,vector<int>>diff;
        vector<int>ans;
        //pehla diff kdlea
        for(int i=0;i<arr.size();i++)
        {
            int index=abs(arr[i]-x);
            if(index!=0)
            diff[index].push_back(arr[i]);
        }
        //sab map de doff accodrind set ne so first k element ans honge
        int index=0;
        for(auto it:diff)
        
        { 
            vector<int>& values = it.second;
        //reverse so that i can push bigger eleetn first as told by que
            reverse(values.begin(), values.end());

            for (auto ele : values)
            {
                if(index==k)break;
            
                ans.push_back(ele);
                 index++;
            }
            
        }
        return ans;
    }
};

