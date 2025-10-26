int find(int par[], int x) {
    // add code here
    if(par[x] == x){
        return x;
    }
    
    int leader = find(par,par[x]);
    
    return leader;
}

void unionSet(int par[], int x, int z) {
    // add code here.
    
    int leader1 = find(par,x);
    int leader2 = find(par,z);
    
    par[leader1] = leader2;
    
    return;
}