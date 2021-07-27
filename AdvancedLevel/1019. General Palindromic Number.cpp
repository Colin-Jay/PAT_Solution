#include <cstdio>
#include <iostream>

using namespace std;

#define SEE(x) cout << #x << ":" << x << endl;

void print(int flag, int num, int* an) {
    if(flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i = 0; i < num; i++) {
        printf("%d", an[num-1-i]);
        if(i < num-1) {
            printf(" ");
        }
    }
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    int an[40];               //n的b进制表示
    int num = 0;              //an的个数
    for(; n != 0; ) {         //除基取余法
        an[num++] = n % b;
        n /= b;
    }
    bool flag = 1;
    for(int i = 0; i < (num / 2); i++) {
        if (an[i] != an[num-1-i]) {
            flag = 0;
            break;
        }
    }
    print(flag, num, an);

    return 0;
}