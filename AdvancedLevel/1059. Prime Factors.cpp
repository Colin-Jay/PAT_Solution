#include <cstdio>
#include <cmath>

const int MAXN = 100010;
int prime[MAXN], pNum = 0; //素数表，素数个数
bool isPrime[MAXN] = {0}; //0代表下标对应的数是素数

struct factor {
    int p, k;
} fac[10];

void pTable (int sqr) {  //素数表
    for (int i = 2; i < MAXN; i++) { //埃氏筛法
        if (prime[pNum] > sqr) break;
        if (!(isPrime[i])) { //如果是素数,加入素数表并开始表晒
            prime[pNum++] = i;
            for (int j = i; j < MAXN; j += i) {
                isPrime[j] = true;
            }
        }
    }
}

void findPrime (int n) { //找出所有质因数
    int cnt = 0; //不同质因数的个数
    for (int i = 0; i < pNum; i++) {
        if (n % prime[i] == 0) { //若该素数为因子，则指数加一
            fac[cnt].p = prime[i];
            fac[cnt].k = 0;
            while (n % prime[i] == 0) {
               (fac[cnt].k)++; 
               n /= prime[i];
            }
            cnt++;
        }
        if (n == 1) break; //已经找到全部质因子
    }
    if (n != 1) { //还存在一个大于根号n的质因子
        fac[cnt].k = n;
        fac[cnt].p = 1;
    }
    for(int i = 0; i < cnt; i++) {
        printf("%d", fac[i].p);
        if (fac[i].k != 1) {
            printf("%s%d", "^", fac[i].k);
        }
        if(i == cnt-1) break;
        printf("*");
    }
}

int main () {
    int n;
    scanf("%d", &n);
    int sqrtn = (int)sqrt(n * 1.0);
    //调用素数表
    if (n == 1) {
        printf("1=1");
    } else {
        pTable(sqrtn);
        printf("%d=", n);
        //2到根号n判断找出其所有质因数
        findPrime(n);
    }
    return 0;
}