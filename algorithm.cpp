#include<bits/stdc++.h>
using namespace std;
string inorder, postorder;
void f(int inl, int inr, int postl, int postr) {
    if (inl > inr) {
        cout << "#";
        return;
    }
    cout << postorder[postr];
    int index;

    for (int i = inl; i <= inr; i++) {
        if (inorder[i] == postorder[postr]) {
            index = i;
        }
    }
    index = index - inl;//长度
    f(inl, inl + index - 1, postl, postl + index - 1);
    f(inl + index + 1, postr - postl + inl, postl + index, postr - 1);

}
int main() {
    cin >> postorder >> inorder;
    f(0, inorder.length() - 1, 0, postorder.length() - 1);
}