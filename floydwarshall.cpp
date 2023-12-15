#include<bits/stdc++.h>
using namespace std;
void floydwarshall(vector<vector<int>>&adj,int vertices){
    for(int k=1;k<=vertices;k++){
        for(int i=1;i<=vertices;i++){
            for(int j=1;j<=vertices;j++){
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
            }
        }
    }
}
int main(){
    int n,m,threshold;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j] = 1e9;
        }
    }
    for(int i=1;i<=n;i++){
        graph[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin>>threshold;
    floydwarshall(graph,n);
    
    map<int,int>mp;
    vector<int>v;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(graph[i][j] <= threshold && i != j){
                mp[i]++;
                cnt++;
            }
        }
        v.push_back(cnt);
    }
    int minflag = *min_element(v.begin(),v.end());
    //cout<<"Cities connected:\n";
    for(auto p : mp){
        if(p.second == minflag){
            cout<<p.first<<" ";
        }
    }

}