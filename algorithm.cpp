#include<iostream>
#include<string>


using namespace std;

string s, p;
int ne[100];
//表示匹配失败时应该移动到哪一个位置,ne[i]表示0-i-1这里面最长相等前后缀的长度
//假设长度为j,那么0-j-1就是前缀,我们要移动到j位置,所以ne[i]恰好等于j


int main() {

    cin >>s>>p;
    ne[0] = -1;//与第一个字符匹配都失败了,那么就不能移动了,-1作为不能移动的标志
    ne[1] = 0;//0-0这里最长前后缀长度不存在,因为不能包含自身,这里是人为规定

    int i = 2;
    int j = 0;

    while (i < p.length()) {
        if (p[i - 1] == p[j]) {//如果第i-1能与第j位匹配上,那么最长前缀+1
            ne[i++] = ++j;
        } else if (j != 0) {//如果匹配不上并且还能回退就回退
            j = ne[j];
        } else {//匹配不上且不能回退的话,那么表示这一位需要从头匹配
            ne[i++] = 0;
        }
    }
    i = 0, j = 0;
    while (i < s.length() && j < p.length()) {
        if (s[i] == p[j]) {//如果能匹配就继续匹配上去
            i++;
            j++;
        } else if (ne[j] == -1) {//此时j=0不能回退,那么i从下一位开始重新匹配
            i++;
        } else {//可以回退就继续回退
            j = ne[j];
        }
    }
    cout << (j == p.length() ? i - j : -1);
}