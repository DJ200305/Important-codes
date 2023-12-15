#include<bits/stdc++.h>
using namespace std;
class MST{
    int v;
    vector<pair<int,int>> *adj;
public:
    MST(int v){
        this->v = v;
        adj = new vector<pair<int,int>>[v];
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> primsalgo(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        vector<int>weight(v,INT16_MAX);
        vector<int>parent(v,-1);
        vector<bool>S(v,false);
        Q.push(make_pair(0,0));
        weight[0] = 0;
        while(!Q.empty()){
            int q = Q.top().second;
            Q.pop();
            if(S[q] == true){
                continue;
            }
            S[q] = true;
            for(auto p : adj[q]){
                if(S[p.first] == false && weight[p.first] > p.second){
                    weight[p.first] = p.second;
                    Q.push(make_pair(weight[p.first],p.first));
                    parent[p.first] = q; 
                }
            }
        }
        return parent;
    }
};
int main(){
    int v;
    cin>>v;
    MST g(v);
    g.addEdge(0, 1, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 4, 2);
    g.addEdge(3, 4, 3);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 3, 8);
    g.addEdge(0, 2, 9);
    g.addEdge(1, 3, 9);
    
    vector<int>mst = g.primsalgo();
    for(int i=1;i<v;i++){
        cout<<mst[i]<<" "<<i<<endl;
    }
}