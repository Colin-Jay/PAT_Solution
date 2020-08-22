#include<cstdio>
#include<algorithm>

using namespace std;

// bool cmp(int a, int b) {
//     return a < b;
// }

void minNum(int *num, int sum) {
    int temp = 0;//保存第一个不为0的数字的下标
    for(int i = 0; i < sum; i++) {
        if(num[i]) {
            temp = i;
            printf("%d", num[i]);
            break;
        }
    }
    for(int i = 0; i < sum; i++) {
        if(i != temp){
           printf("%d", num[i]);
        } 
    }

}

int main() {
    int numCnt[10], num[50], sum = 0;//分别代表每个数字的次数，将数字从小到大排序，数字的总个数
    for(int i = 0; i < 10; i++) {
        scanf("%d", &numCnt[i]);
        for(int j = sum; (j - sum) < numCnt[i]; j++) {//根据次数将每个数字依次保存到num中
            num[j] = i;
        }
        sum += numCnt[i];
    }

    // for(int i = 0; i < sum; i++) { 
    //     printf("num[%d]=%d\n", i, num[i]);
    // }
    // sort(num, num+sum, cmp);
    minNum(num, sum);

}