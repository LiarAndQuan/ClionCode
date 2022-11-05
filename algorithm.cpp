#include<bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool st[100];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    //预处理:判断合并列的状态i是否合法
    //如果合并列的某行是1表示横放,是0表示竖放
    //如果合并列不存在连续的奇数个0,即为合法状态,因为可以用竖着的方块补充
    for (int i = 0; i < 1 << n; i++) {
        st[i] = true;
        int cnt = 0;//记录合并列中连续0的个数
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {//如果是1
                if (cnt & 1) {//如果是奇数
                    st[i] = false;
                    break;
                }
            } else {
                cnt++;
            }
        }
        if (cnt & 1) {//处理前导0,例如001000中前两个0
            st[i] = false;
        }
    }

    int f[100][100];

    memset(f, 0, sizeof(f));

    f[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 1 << n; j++) {//枚举第i列
            for (int k = 0; k < 1 << n; k++) {//枚举第i-1列
                if ((j & k) == 0 && st[j | k]) {
                    //两列状态兼容:不出现重叠的1,不出现连续的奇数个0
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }

    cout << f[m][0] <<endl;
}
