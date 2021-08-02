#include <iostream>
#include <cstring>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int n, numKuchi[110];
    char strKuchi[110][300], suffix[300] = {};
//     suffix[0] = {'\0'};
    scanf("%d", &n);
    getchar();
    int minLen = 1000;                             //各行长度最小值
    for (int i = 0; i < n; i++) {                  //输入每行并统计各行长度
        //scanf("%s", strKuchi[i]);
        fgets(strKuchi[i], 300, stdin);
        numKuchi[i] = strlen(strKuchi[i]) - 1;
        if (numKuchi[i] < minLen) {
            minLen = numKuchi[i];
        }
        strKuchi[i][numKuchi[i]] = '\0';
    }

    bool flag = 1;                                 //标志当前字符是否可以加入共同字串   
    for (int i = 0; i < minLen; i++) {
        //if ((strKuchi[0][numKuchi[0]-1-i] != ' ')) {
            for (int j = 1; j < n; j++) {
                if (strKuchi[0][numKuchi[0]-1-i] != strKuchi[j][numKuchi[j]-1-i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                suffix[i] = strKuchi[0][numKuchi[0]-1-i];
//                 suffix[i+1] = '\0';             //若没初始化，则一定要把后一个置为\0
            } else break;
        //}
    }
    int num = strlen(suffix);
    if (num == 0) {
        printf("nai");
    } else {
        for (int i = 0; i < num; i++) {
            printf("%c", suffix[num-1-i]);
        }
    }
    return 0;
}