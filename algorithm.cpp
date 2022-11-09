#include<bits/stdc++.h>

using namespace std;


char ori[11000005];
char s[22000005];
int d[22000005];

int main() {
    scanf("%s", ori);
    int n = strlen(ori);

//扩展数组
    int k = 0;
    s[k++] = '#';
    for (int i = 0; i < n; i++) {
        s[k++] = ori[i];
        s[k++] = '#';
    }

    n = k;
    memset(d, 0, sizeof(d));
    d[0] = 1;
    int l, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            d[i] = min(d[r - i + l], r - i + 1);
        }
        while (i - d[i] != -1 && s[i - d[i]] == s[i + d[i]]) {//加上前置条件,以防数组越界
            d[i]++;
        }
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }

    int mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, d[i]);
    }
    cout << mx - 1;
}