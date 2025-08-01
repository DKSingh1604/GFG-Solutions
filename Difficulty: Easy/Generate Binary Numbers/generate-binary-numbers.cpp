
// Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int n) {
    // Your code here
    
    
    vector<string> a;
    for(int i = 1; i <= n; i++){
        string str;
        str = bitset<32>(i).to_string();
        a.push_back(str.substr(str.find("1")));
    }
    return a;
}
