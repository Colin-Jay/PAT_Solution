#include<cstdio>

const int MAXN = 100010;

struct ChoosePivot {
    int num;
    int Lflag;  //是否满足num左边都比它小
    int Rflag;  //是否满足num右边都比它大
    int flag;   //是否同时满足条件
} Pivot[MAXN];

int main() {
    int n, cntPivot = 0;
    int Lmax = 0, Rmin = 0; //记录当前数字左边的最大值和右边的最小值
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {  //输入并记录左边的Lflag
        scanf("%d", &Pivot[i].num);
        if(Pivot[i].num > Lmax) {
            Pivot[i].Lflag = 1;
            Lmax = Pivot[i].num;
        } else {
            Pivot[i].Lflag = 0;
        }
    }

    Pivot[n-1].Rflag = 1;
    Pivot[n-1].flag = Pivot[n-1].Lflag;
    Rmin = Pivot[n-1].num;
    if(Pivot[n-1].flag) cntPivot++;

    for(int i = n-2; i >= 0; i--) { //倒着遍历一遍num，记录Rflag和flag
        if(Pivot[i].num < Rmin) {
            Pivot[i].Rflag = 1;
            Rmin = Pivot[i].num;
        } else {
            Pivot[i].Rflag = 0;
        }
        Pivot[i].flag = Pivot[i].Lflag * Pivot[i].Rflag;
        if (Pivot[i].flag == 1) {
            cntPivot++;
        }     
    }

    int temp = cntPivot;
    printf("%d\n", cntPivot);
    if(cntPivot == 0) printf("\n");
    for(int i = 0; i < n; i++) {
        if(Pivot[i].flag == 1) {
            printf("%d", Pivot[i]);
            temp--;
        } else continue;
        if(temp) {
            printf(" ");
        }
    }

    return 0;
}