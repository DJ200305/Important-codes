#include<bits/stdc++.h>
using namespace std;
//bfs == level order traversal
const int maxin = 100000;
#define white 0
#define gray 1
#define black 2
int dis[maxin],par[maxin],col[maxin];
int count1 = 0;
bool bfs(vector<vector<int>>&adj,int source,int destination,int vertices){
    int u;
    int src = source;
    for(int i=0;i<vertices;i++){
        dis[i] = -10000;
        par[i] = -1;
        col[i] = white;
    }
    dis[src] = 0;
    par[src] = -1;
    col[src] = gray;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(col[v] == white){
                col[v] = gray;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
            if(v == destination){
                return true;
            }
            
        }
        col[u] = black;
    }
    
    return false;
}
void printsp(int source,int destination){
    int curr = destination;
    vector<int>sp;
    while(curr != source){
        sp.push_back(curr);
        curr = par[curr];
    }
    sp.push_back(source);
    reverse(sp.begin(),sp.end());
    for(int i : sp){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int n,m,u,v,s,d;
    cin>>n>>m;
    vector<vector<int>>gr(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        gr[u].push_back(v);
    }
    cin>>s>>d;
    //cout<<count1<<endl;
    if(bfs(gr,s,d,n)){
        cout<<dis[d]<<endl;
        printsp(s,d);
    }
    else{
        cout<<-1<<endl;
    }
}