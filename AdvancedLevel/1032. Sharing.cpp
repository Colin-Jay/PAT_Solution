#include <iostream>

#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 100010;

struct letter{
    char data;
    int next;
    int count;       //该字母被使用次数，若次数为2则为公共部分的字母
}sLetter[maxn];

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int a1, a2;
    int n;
    scanf("%d %d %d", &a1, &a2, &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        getchar();  //吸收空格
        // SEE(temp);
        // SEE(i);
        scanf("%c %d", &sLetter[temp].data, &sLetter[temp].next);
        // SEE(sLetter[temp].data);
        // SEE(sLetter[temp].next);
    }
    for (int i = a1; i != -1;) {
        sLetter[i].count++;
        i = sLetter[i].next;
    }
    int a0 = -1;     //公共前缀起始地址
    for (int i = a2; i != -1;) {
        sLetter[i].count++;
        if (sLetter[i].count == 2) {
            a0 = i;
            break;
        }
        i = sLetter[i].next;
    }
    // cout << a0;
    if (a0 == -1) {
        printf("%d", a0);
    } else {
        printf("%05d", a0);
    }

    return 0;
}