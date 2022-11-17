#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    while (cin >> n) {

        bool fir = true;
        int cnt = 0;
        int temp = n;
        vector<int> res;
        while (1) {
            cnt++;
            bool is = true;
            vector<int> v;

            int temp1 = temp;

            while (temp) {
                v.push_back(temp % 10);
                temp /= 10;
            }

            for (int i = 0; i < v.size(); i++) {
                if (v[i] != v[v.size() - i - 1]) {
                    is = false;
                    break;
                }
            }

            if (is) {
                cout << cnt-1 << endl;
                for (int i = 0; i < res.size(); i++) {
                    if (i == 0) {
                        cout << res[i];
                    } else {
                        cout << "--->" << res[i];
                    }
                }
                cout << "--->" << temp1 << endl;
                v.clear();
                res.clear();
                break;
            } else {
                int x = 0;
                for (int i = 0; i < v.size(); i++) {
                    x = x * 10 + v[i];
                }
                temp = x + temp1;
                res.push_back(temp1);
            }

        }

    }

}