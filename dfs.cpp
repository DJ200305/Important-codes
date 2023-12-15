#include<bits/stdc++.h>
using namespace std;
//dfs == preorder traversal
const int maxin = 100000;
#define white 0
#define gray 1
#define black 2
int dis[maxin],par[maxin],col[maxin],fin[maxin],start[maxin];
int t,finish,len = 0;
vector<vector<int>>gr(maxin);
vector<int>check;
void dfsvisit(int src,int destination){
    start[src] = t++;
    col[src] = gray;
    for(int v : gr[src]){
        if(col[v] == white){
            dis[v] = dis[src] + 1;
            par[v] = src;
            check.push_back(src);         //check is a vector to determine whether the there exists a path between source and destination
            dfsvisit(v,destination);      //if a path doesn't exists then it will never reach this conditional block
        }
        if(v == destination){
            return;
        }
        
    }
    col[src] = black;
    fin[src] = t++;
    
}
void dfs(int source,int destination,int vertices){
    for(int i=0;i<vertices;i++){
        col[i] = white;
        par[i] = -1;
    }
    t = 0;
    for(int i=source;i<=vertices;i++){
        if(col[i] == white){
            dfsvisit(source,destination);
        }
    }
    //dfsvisit(adj,source,destination,p);
}
void printp(int source,int destination){
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
    
    for(int i=0;i<m;i++){
        cin>>u>>v;
        gr[u].push_back(v);
    }
    cin>>s>>d;
    dfs(s,d,n);
    if(check.size() == 0){
        cout<<-1<<endl;
    }
    else{
        cout<<dis[d]<<endl;
        printp(s,d);
    }
    
}