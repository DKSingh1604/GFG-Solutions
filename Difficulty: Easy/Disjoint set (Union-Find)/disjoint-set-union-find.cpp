
int find(int par[], int x) {
    
    //base case
    if(x == par[x]) return x;
    else return par[x] = find(par, par[x]);
    
}

void unionSet(int par[], int x, int z) {
    // add code here.
    
    int up_x = find(par, x);
    int up_z = find(par, z);
    
    // if(up_x == up_z) return;
    
    // if(rank[up_x] < rank[up_z]){
    //     par[up_x] = up_z;
    // }
    // else if(rank[up_z] < rank[up_x]){
    //     par[up_z] = up_x;
    // }
    // else{
    //     par[up_z] = up_x;
    //     rank[up_x]++;
    // }
    par[up_x] = up_z;
    return;
}