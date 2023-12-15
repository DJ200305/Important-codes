#include<bits/stdc++.h>
using namespace std;
//dfs == preorder traversal
const int maxin = 100000;
#define white 0
#define gray 1
#define black 2
int dis[maxin],par[maxin],col[maxin],fin[maxin],start[maxin];
int t,finish,len = 0,trig = 0;
bool cycledetected = false;
vector<vector<int>>gr(maxin);
vector<int>check;
void dfsvisit(int src){
    start[src] = t++;
    col[src] = gray;
    for(int v : gr[src]){
        if(col[v] == gray && par[src] != v){
            trig = 0;
            cout<<"Cycle detected\n";
            cycledetected = true;
            return;
        }
        else if(col[v] == white){
            dis[v] = dis[src] + 1;
            par[v] = src;
            dfsvisit(v);
            if(cycledetected){
                return;
            }
        }
        else{
            trig++;
        }
    }
    col[src] = black;
    fin[src] = t++;
    
}
void dfs(int source,int vertices){
    for(int i=0;i<vertices;i++){
        col[i] = white;
        par[i] = -1;
    }
    t = 0;
    for(int i=source;i<=vertices;i++){
        if(col[i] == white){
            dfsvisit(source);
            if(cycledetected){
                return;
            }
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
    int get;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        get = u;
    }
    dfs(get,n);
    
    /*if(check.size() == 0){
        cout<<-1<<endl;
    }
    else{
        cout<<dis[d]<<endl;
        printp(s,d);
    }*/
    if(!cycledetected){
        if(trig != 0){
            cout<<"No Cycle\n";
        }
    }
}
