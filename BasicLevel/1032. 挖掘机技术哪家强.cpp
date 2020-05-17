#include<cstdio>

const int maxn = 100000; //最大人数

int main() {
    int n, sno, grade;
    scanf("%d", &n);
    int score[maxn] = {};
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &sno, &grade);
        score[sno-1] += grade;
    }
    int Max_s = 1, Max_g = score[0];
    for(int i = 1; i < n; i++) {
        if(score[i] > Max_g) {
            Max_s = i + 1;
            Max_g = score[i];
        }
    }
    printf("%d %d\n", Max_s, Max_g);
    return 0;
}