#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
    vector<int>rank,parent,size;
public:
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void UnionByRank(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv){
            return;
        }
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    void UnionBySize(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv){
            return;
        }
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main(){
    disjoint_set ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    //checking if 3 and 7 belong to the same component
    if(ds.find(3) == ds.find(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not same\n";
    }
    ds.UnionBySize(3,7);
    if(ds.find(3) == ds.find(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not same\n";
    }

}