#include <cstdio>
#include <cstring>

int pNum[1000];
struct BigNum {
    int P[1000];
    int len;
    BigNum () {
        memset(P, 0, sizeof(P));
        len = 0;
    }
} bigN;

bool isPalin () { //判断是否是Palin
    bool flag = true;
    int left = 0, right = bigN.len - 1;
    while (left < right) {
        if (bigN.P[left] != bigN.P[right]) {
            flag = false;
            break;
        }
        left ++;
        right --;
    }
    return flag;
}

void add () { //将一个数与其本身倒序相加,暂存在pNum中
    int carry = 0; //进位
    for (int i = 0; i < bigN.len; i++) {
        int temp = bigN.P[i] + bigN.P[bigN.len - 1 - i] + carry;
        carry = temp / 10;
        pNum[i] = temp % 10;
    }
    if (carry) {
        pNum[bigN.len] = carry;
        bigN.len ++;
    }
    for (int i = 0; i < bigN.len; i++) { //将pNum复制给bigN.P
        bigN.P[i] = pNum[i];
    }
}

int main () {
    int k, step = 0; //规定步骤和已经进行的步骤
    char str[20];
    scanf("%s %d", str, &k);
    bigN.len = strlen(str);
    for (int i = 0; i < bigN.len; i++) { //按地位到高位将数字字符串存入数组P中
        bigN.P[bigN.len - 1 - i] = str[i] - '0';
    }
    bool flag; //1代表是Palin
    flag = isPalin ();
    while (flag == 0 && step < k) {
        add ();
        flag = isPalin ();
        step ++;
    }
    for (int i = 0; i < bigN.len; i++) {
        printf("%d", bigN.P[bigN.len - 1 - i]);
    }
    printf("\n%d", step);
    return 0;
}