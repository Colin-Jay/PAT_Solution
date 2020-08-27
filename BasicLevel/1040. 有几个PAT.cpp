#include<cstdio>
#include<cstring>

const int MAXN = 100010;
const int MOD = 1000000007;
char PATs[MAXN];
int PA[MAXN], AT[MAXN]; //记录每个A之前的P的个数A之后的T的个数

int main() {
    scanf("%s", PATs);
    int len = strlen(PATs);
    int cntP = 0, cntA = 0, cntT = 0, cntPAT = 0; //分别记录P,A,T，PAT的总数

    //先确定每个A之前的P的个数
    for(int i = 0; i < len; i++) {
        if(PATs[i] == 'P') {
            cntP++;
        } else if(PATs[i] == 'A') {
            PA[cntA] = cntP;
            // printf("PA[%d]=%d\n", cntA, PA[cntA]);
            cntA++;
        } else continue;
    }

    //先确定每个A之后的T的个数
    int temp = cntA - 1;
    for(int i = len - 1; i >= 0; i--) {
        if(PATs[i] == 'T') {
            cntT++;
            // printf("cntT=%d\n",cntT);
        } else if(PATs[i] == 'A') {
            // printf("cntT=%d\n",cntT);
            AT[temp] = cntT;
            // printf("AT[%d]=%d\n", temp, AT[temp]);
            temp--;
        } else continue;
    }

    //将PA与AT的下标0-cntA每位相乘，然后求和即得cntPAT
    for(int i = 0; i < cntA; i++) {
        // printf("PA[%d]=%d\n", i, PA[i]);
        // printf("AT[%d]=%d\n", i, AT[i]);
        cntPAT += PA[i] * AT[i];
        cntPAT %= MOD;
    }

    // cntPAT %= MOD;
    printf("%d", cntPAT);

    return 0;
}