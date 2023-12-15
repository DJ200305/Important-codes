#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
int trig;
int dis[1000],col[1000],fin[1000],t;
void dfs(vector<vector<int>>&adj,int src){ 
    //cout<<"( "<<src<<" ";
    t++;
    dis[src] = t;
    col[src] = gray;
    
    for(int v : adj[src]){
        if(col[v] == white){
            col[v] = 1-col[src];
            
            dfs(adj,v);
            
        }
        else if(col[v] == gray){
            trig = 0;
            cout<<"Cycle detected\n";
            return;
        }
        else{
            trig++;
        }
    }
    col[src] = black;
    t++;
    fin[src] = t;
    //cout<<w<<" )";
    //cout<<src<<" )";
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>>gr(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        gr[u].push_back(v);
    
    }
    for(int i=0;i<n;i++){
        if(col[i] == white){
            dfs(gr,i);
        }
    }
    if(trig != 0){
        cout<<"No cycle\n";
    }
}