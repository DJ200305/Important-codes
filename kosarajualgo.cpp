#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
int col[100],fin[100],dis[100],t;
void dfs(vector<vector<int>>&adj,int src,vector<int>&gr1){
    t++;
    dis[src] = t;
    col[src] = gray;
    for(int v : adj[src]){
        if(col[v] == white){
            dfs(adj,v,gr1);
        }
        
    } 
    col[src] = black;
    t++;
    fin[src] = t;
    gr1.push_back(src);
    
}
vector<vector<int>> transpose(vector<vector<int>>&adj,int n){
    vector<vector<int>>adjt(n);
    //vector<int>colt(n,white);
    for(int i=0;i<n;i++){
        col[i] = white;
        for(int j : adj[i]){
            adjt[j].push_back(i);
        }
    }
    return adjt;
}
void dfs1(int src, vector<vector<int>>& adj) {
    col[src] = gray;
    cout << src << " "; // Print nodes in the SCC
    for (int i : adj[src]) {
        if (col[i] == white) {
            dfs1(i, adj); // Use 'i' instead of 'src'
        }
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>>gr(n),grt;
    vector<int>gr1;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        gr[u-1].push_back(v-1);
    }
    for(int i=0;i<n;i++){
        if(col[i] == white){
            dfs(gr,i,gr1);
        }
    }
    grt = transpose(gr, n);

    cout << "Nodes according to finishing time (descending order): ";
    for (int i = gr1.size() - 1; i >= 0; i--) {
        cout << gr1[i] << " ";
    }
    cout << endl;

    cout << "Strongly Connected Components:" << endl;
    for (int i = gr1.size() - 1; i >= 0; i--) {
        if (col[gr1[i]] == white) {
            cout << "Component:";
            dfs1(gr1[i], grt);
            cout << endl;
        }
    }
    
}