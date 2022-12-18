#include<bits/stdc++.h>

using namespace std;

struct e{
    int l;
    int r;
    bool operator<(const e&e)const{
        return r<e.r;
    }
}e[1000000  ];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>e[i].l>>e[i].r;
        }
        sort(e+1,e+1+n);
        int cnt = 0;
        int end = -1;
        for(int i = 1;i<=n;i++){
            if(e[i].l<end){
                continue;
            }else{
                end = e[i].r;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}