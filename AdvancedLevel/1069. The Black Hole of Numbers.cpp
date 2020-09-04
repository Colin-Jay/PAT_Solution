#include<cstdio>
#include<algorithm>

using namespace std;

void Partition(int a, int bHole[]) {//将一个数的每个数位存进数组中
    for(int i = 0; i < 4; i++) {
        bHole[i] = a % 10;
        a /= 10;
    }
}

int toMaxNum(int bHole[]){//得到first
    int max = 0;
    for(int i = 3; i >= 0; i--) {
        max = max * 10 + bHole[i];
    }
    return max;
}

int toMinNum(int bHole[]){//得到second
    int min = 0;
    for(int i = 0; i < 4; i++) {
        min = min * 10 + bHole[i];
    }
    return min;
}

void holePrintf(int n, int bHole[]) {
    int first, second;
    Partition(n, bHole);
    sort(bHole, bHole+4);
    first = toMaxNum(bHole);
    second = toMinNum(bHole);
    n = first - second;
    printf("%04d - %04d = %04d", first, second, n);    //打印结果
    //只要不是0或者6174就递归调用打印程序
    if(n != 6174 && n) {
        printf("\n");
        holePrintf(n, bHole);
    }
}

int main() {
    int n;
    int bHole[10];
    scanf("%d", &n);
    holePrintf(n, bHole);    //调用打印程序
    return 0;
}