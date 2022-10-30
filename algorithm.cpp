#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

int b[100005];
int p[100005];
int len = 0;

int f(int x) {
    int l = 1, r = len;
    int mid, res;
    while (l <= r) {
        mid = (l + r) / 2;
        if (p[mid] >= x) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] > p[len]) {
            p[++len] = b[i];
        } else {
            int index = f(b[i]);
            p[index] = b[i];
        }
    }
    cout << len;
}
