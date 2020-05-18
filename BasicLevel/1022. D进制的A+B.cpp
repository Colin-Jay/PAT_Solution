#include<cstdio>

int main() {
    int A, B, D, sum;
    scanf("%d%d%d", &A, &B, &D);
    sum = A + B;
    int ans[31]; //保留结果
    int num = 0; //数组下标
    do {
        ans[num++] = sum % D;
        sum /= D;

    } while(sum != 0);
    // 逆向输出D
    for(int i = num - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }

    return 0;
}