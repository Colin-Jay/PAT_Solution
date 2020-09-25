#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int n, indexA, indexB;    //记录标准输出的指数
string strA, strB;

int indexLen (string &str) {
    int lens = 0;
    string::iterator it = str.begin();
    //去除前导0
    while (*it == '0') {
        if (str.length() != 1) {
            str.erase(it);
        } else {                     //0
            return 0;
        }        
    }
    if (*it == '.') {                //0.---
        str.erase(it);               //去除小数点
        if (*it != '0') {
            return 0;                //0.k(k!=0)
        } else {
            int i = 0;
            //去除0.类的小数点后面的连续0
            while (str.length() != 1) {
                if (*it == '0') {
                    i++;
                    str.erase(it);
                } else {
                    break;
                }             
            }
            if (*it == '0') {
                return 0;            //0.0
            } else {
                return -i;            //0.0k(k!=0)
            }                
        }
    } else {                         //k或者k.---(k!=0)
        if (str.find(".") == -1) {
            return str.length();     //k
        } else {
            int flo = str.find(".");
            str.erase(it + str.find(".") );
            return flo;    //k.---
        }
    }
}

void print(string str) {
    int len = str.length();
    for (int i = 0; i < n; i++) {
        if (i < len) {
            printf("%c", *(str.begin() + i));
        } else {
            printf("0");
        }
    }

}

int main () {
    cin >> n >> strA >> strB;
    //确定指数
    indexA = indexLen(strA);
    indexB = indexLen(strB);
    bool flag = true;        //判断YESorNO
    if (indexA != indexB) {
        flag = false;
    } else {
        for (int i = 0; i < n; i++) {
            if (*(i + strA.begin()) != *(i + strB.begin())) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {              //输出
        printf("YES 0.");
        print(strA);
        printf("*10^%d", indexA);
    } else {
        printf("NO 0.");
        print(strA);
        printf("*10^%d 0.", indexA);
        print(strB);
        printf("*10^%d", indexB);
    }
    return 0;
}