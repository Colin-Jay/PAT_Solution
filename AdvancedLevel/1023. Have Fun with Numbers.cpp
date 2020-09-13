#include <cstdio>
#include <cstring>

char str[30];              //先以字符的形式读入大整数
int bigN[30], doubN[30];   //存放大整数与它的两倍
int hashB[20], hashD[20];  //映射大整数每个数位的个数
int lenb, lend;

int doubBig() { //大整数翻倍
    int len = 0, carry = 0; //len记录翻倍后的位数，carry是运算时的进位
    for (int i = 0; i < lenb; i++) {
        int temp = 2 * bigN[i] + carry;
        carry = temp / 10;
        doubN[len++] = temp % 10;
    }
    while (carry) {
        doubN[len++] = carry % 10;
        carry /= 10;
    }
    return len;
}

void print(int flag) {
    if (flag) {
        printf("Yes\n");
        for (int i = 0; i < lend; i++) {
            printf("%d", doubN[lend - i -1]);
        }
    } else {
        printf("No\n");
        for (int i = 0; i < lend; i++) {
            printf("%d", doubN[lend - i -1]);
        }
    }
}

int main () {
    memset(hashB, 0, sizeof(hashB));  
    memset(hashD, 0, sizeof(hashD));
    scanf("%s", str);
    lenb = strlen(str);
    for (int i = 0; i < lenb; i++) {   //将大整数放入数组中并记录每个数位的个数
        bigN[i] = str[lenb - i - 1] - '0';
        int temp = bigN[i];
        hashB[temp]++;
    }
    lend = doubBig();              //调用函数将大整数翻倍
    for (int i = 0; i < lend; i++) {   //记录翻倍后的大整数每个数位的个数
        int temp = doubN[i];
        hashD[temp]++;
    }   

    bool flag = true;       //flag标志是否满足要求
    if (lenb != lend) {     //如果翻倍后有进位，那么直接不满足
        flag = false;
        print(flag);
    } else {               //没有进位则判断翻倍后大整数每个数位的个数是否改变
        for (int i = 0; i < 10; i++) {
            if (hashB[i] != hashD[i]) {
                flag = false;
                break;
            }
        }
        print(flag);
    }

    return 0;
}