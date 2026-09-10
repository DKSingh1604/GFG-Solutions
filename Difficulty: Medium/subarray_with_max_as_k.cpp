#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//O(n^2) * O(nlogn) -> bruteforce, sort every subarray and if max is k
//O(n^2) -> better -> keep a max_element variable to track the max of every subarray
//O(n) -> best(below) -> keep lastK and lastGreater then at the end, increase the count accordingly


void findValidSubs(vector<int> &arr, int n, int k){
    
    long long count = 0;
    
    int lastK = -1;
    int lastGreater = -1;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > k){
            lastGreater = i;
        }
        
        if(arr[i] == k){
            lastK = i;
        }
        
        if(lastK > lastGreater) count += lastK - lastGreater;
    }
    cout<<count;
    
}

int main() {
    vector<int> arr = {8, 2, 1, 3, 4, 5, 1, 10};
    int k = 3;
    int n = arr.size();
    
    findValidSubs(arr, n, k);

    return 0;
}
