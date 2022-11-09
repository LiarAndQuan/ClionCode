#include<iostream>
#include<algorithm>

using namespace std;


typedef unsigned long long ull;
const int P = 131;


ull p[2000], h[2000];
ull arr[100005];


void init(string a) {
    p[0] = 1;
    h[0] = 0;
    for (int i = 1; i <= a.length(); i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + a[i - 1];
    }
}

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        init(a);
        arr[i] = get(1, a.length());
    }
    sort(arr + 1, arr + 1 + n);
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i + 1] == arr[i]) {
            count++;
        }
    }
    cout << n - count;
}