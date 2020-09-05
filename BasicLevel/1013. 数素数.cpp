#include <cstdio>

const int MAXN = 200000;
int prime[MAXN], pNum = 0; //素数表,素数个数
bool pTable[MAXN] = {0}; //false表示是该下标对应的数字素数


void primeTable() { //埃氏筛法
    for (int i = 2; i < MAXN; i++) { //从2开始遍历
        if (!(pTable[i])) { //如果该数字是素数，那么开始筛去它的倍数
            prime[pNum++] = i;
            for (int j = i + i; j < MAXN; j += i) {
                pTable[j] = true;
            }

        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    primeTable();
    int cnt = 0; //判断打印是否换行
    for (int i = m; i <= n; i++) {
        printf("%d%s", prime[i - 1], (++cnt % 10) && (i < n) ? " " : "\n");
    }
    return 0;
}