#include<iostream>
#include<cstring>

using namespace std;
#define SEE(x) cout << #x << ":" << x << endl;

int main() {
//     int num = 0; //单词个数
//     char word[90][90];
//     while(scanf("%s", word[num]) != EOF) {
//         num++;
//     }
//     //倒着输出
//     for(int i = num - 1; i >= 0; i--) {
//         printf("%s", word[i]);
//         if(i > 0) {
//             printf(" ");
//         }
//     }
    char str[100];            //存输入
    char word[90][90];        //将输入的字符串分割为单词
    fgets(str, 100, stdin);
    int len = strlen(str);
    int j = 0, k = 0;
    for(int i = 0; i < len; i++) {
        
        if (str[i]!=' ') {    
            word[j][k++] = str[i];
        } else {                //分割单词
            word[j][k] = '\0';  //标志字符串结束
            j++;
            k = 0;
        }
    }
    word[j][k-1] = '\0';         //fgets会读入行末的回车符
    for (int i = j; i >= 0; i--) {
        printf("%s", word[i]);
        if (i > 0) printf(" ");
    }
    return 0;


}