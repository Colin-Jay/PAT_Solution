#include<cstdio>

int main() {
    int num = 0; //单词个数
    char word[90][90];
    while(scanf("%s", word[num]) != EOF) {
        num++;
    }
    //倒着输出
    for(int i = num - 1; i >= 0; i--) {
        printf("%s", word[i]);
        if(i > 0) {
            printf(" ");
        }
    }
    return 0;
}