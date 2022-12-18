#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int ma = -0x3f3f3f3f,mi = 0x3f3f3f3f,cmi = 0,cma = 0;
    for(int i = 1;i<=n;i++ ){
        int x;
        cin>>x;
        if(x>ma ){
            ma = x;
            cma = 1;
        }else if(x==ma ){
            cma++;
        }
        if(x<mi ){
            mi = x;
            cmi = 1;
        }else if(x==mi){
            cmi++;
        }
    }
    cout<<mi<<" "<<cmi<<endl;
    cout<<ma<<" "<<cma<<endl;
}