#include<bits/stdc++.h>
using namespace std;

template<typename E>
class pqueue{
    E* arr;
    int len;
    int n = 10000;
    int successorleft(int i){
        return 2*i;
    }
    int successorright(int i){
        return 2*i+1;
    }
    int ancestor(int i){
        return i/2;
    }
    void drive(int len,int a){
        int lc = successorleft(a);
        int rc = successorright(a);
        int max = a;
        if(lc <= len && arr[lc] > arr[max]){
            max = lc;
        }
        if(rc <= len && arr[rc] > arr[max]){
            max = rc;
        }
        if(max != a){
            swap(arr[a],arr[max]);
            drive(len,max);
        }
    }
    void buildmaxheap(){
        for(int i=len/2;i>=1;i--){
            drive(len,i);
        }
    }

public:
    pqueue(){
        len = 0;
        arr = new E[n];
    }

    E findMax(){
        return arr[1];
    }
    E ExtractMax(){
        if(len < 1){
            cout<<"heap underflow\n";
            return E();
        }
        E extraction = arr[1];
        arr[1] = arr[len];
        len--;
        drive(len,1);
        return extraction;
    }
    void IncreaseKey(int i,E newKey){
        if(arr[i] > newKey){

            cout<<"New key is not larger than the previous key\n";
            return;
        }
        cout<<"Key increased!\n";
        arr[i] = newKey;
        while(i > 1 && arr[ancestor(i)] < arr[i]){
            swap(arr[i],arr[ancestor(i)]);
            i = ancestor(i);
        }

    }
    void DecreaseKey(int i,E newKey){
        if(arr[i] < newKey){
            cout<<"New key is not smaller than the previous key\n";
            return;
        }
        cout<<"Key decreased!\n";
        arr[i] = newKey;
        while(i >= 1 && (arr[successorleft(i)] > arr[i] || arr[successorright(i)] > arr[i]) && (successorleft(i) <= len)){
            if(arr[successorleft(i)] > arr[i] && arr[successorright(i)] < arr[i]){
                swap(arr[i],arr[successorleft(i)]);
                i = successorleft(i);
            }
            else if(arr[successorleft(i)] < arr[i] && arr[successorright(i)] > arr[i]){
                swap(arr[i],arr[successorright(i)]);
                i = successorright(i);
            }
            else if(arr[successorleft(i)] > arr[i] && arr[successorright(i)] > arr[i]){
                if(arr[successorleft(i)] > arr[successorright(i)]){
                    swap(arr[i],arr[successorleft(i)]);
                    i = successorleft(i);
                }
                else{
                    swap(arr[i],arr[successorright(i)]);
                    i = successorright(i);
                }
            }
        }

    }
    void sort(){
        buildmaxheap();
        for(int i=len;i>=2;){
           swap(arr[1],arr[i]);
           i--;
           drive(i,1);
        }
    }
    void insert(E x){
        if(len == n){
            cout<<"heap overflow\n";
        }
        len++;
        arr[len] = x;
        buildmaxheap();
    }
    void print(){
        int count = 0,lvl = 1;
        cout<<"No of elements: "<<len<<endl;
        cout<<arr[1]<<endl;
        for(int i=1;i<=len;i++){
            if(successorleft(i) <= len){
                count++;
                cout<<arr[successorleft(i)]<<"      ";
            }
            if(successorright(i) <= len){
                count++;
                cout<<arr[successorright(i)]<<"     ";
            }
            if(count == round(pow(2,lvl))){
                count = 0;
                lvl++;
                cout<<endl;
            }
        }
        if(count != 0){
            cout<<endl;
        }
    }
    int length(){
        return len;
    }
    ~pqueue(){
        delete [] arr;
    }
};

int main(){
    pqueue<int> p,r;
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>subsum;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            subsum.push_back(sum);
        }
    }
    for(int i=0;i<subsum.size();i++){
        p.insert(subsum[i]);
    }
    int l = 1;
    while(l != k){
        int a = p.ExtractMax();
        l++;
    }
    cout<<p.findMax();
}