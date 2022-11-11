#include<iostream>

using namespace std;

int ch[100][26];
int cnt[100], idx;

void insert(char a[]) {
    int p = 0;
    for (int i = 0; a[i]; i++) {
        int j = a[i] - 'a';
        if (!ch[p][j]) {
            ch[p][j] = ++idx;
        }
        p = ch[p][j];
    }
    cnt[p]++;
}

int query(char a[]) {
    int p = 0;
    for (int i = 0; a[i]; i++) {
        int j = a[i] - 'a';
        if (!ch[p][j]) {
            return 0;
        }
        p = ch[p][j];
    }
    return cnt[p];
}