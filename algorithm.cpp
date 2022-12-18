#include<bits/stdc++.h>
using namespace std;

struct stu{
    int a;
    int b;
    bool operator <(const stu&s )const{
        if(a==s.a ){
            return b>s.b;
        }else{
            return a>s.a;
        }
    }
}stu[10000006];

int main( ){
    int n,k,s;
    cin>>n>>k>>s;
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        cin>>stu[i].a>>stu[i].b;
    }
    sort(stu+1,stu+n+   1);
    for(int i =1;i<=n;i++){
        if(stu[i].a<175){
            cnt = i-1;
            break;
        }
    }
    int j;
    for(int i = 1;i<=n;i+=j){
        if(stu[i   ].a<175){
            break;
        }
        int x = 0,y = 0;
        for(j = 0;i+j<=n&&stu[i].a==stu[i+j].a;j++){
            if(stu[i+j].b<s){
                x++;
            }else{
                y++;
            }
        }
        if(x>k){
            cnt-=(x-k);
        }
    }
    cout<<cnt;
}