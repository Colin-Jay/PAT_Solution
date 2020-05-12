#include<stdio.h>

void sumdigit(int sum0);

int main()
{
    int a,b,sum,sum0; //sum0是sum的绝对值

    scanf("%d %d", &a, &b);

    sum = a + b;
    sum0 = sum;

    //输出符号
    if(sum < 0)
    {
        sum0 = -sum;
        printf("-");
        sumdigit(sum0);
    } else if(sum == 0) {
        printf("0");
    } else {
        sumdigit(sum0);
    }

    return 0;
}

//sum按位输出
void sumdigit(int sum0)
{
    int mask = 1; //
    int digit =1;
    int temp = sum0;
    int fir = 0;

    //确定sum0的位数digit
    while(temp / 10 > 0)
    {
        mask *= 10;
        temp /= 10;
        digit ++;
    }

    //根据位数digit输出
    for(int i = 0; i < digit;)
    {
        fir = sum0 / mask;
        sum0 %= mask;
        printf("%d", fir);
        if((digit % 3 == 1) && (digit > 3))
        {
            printf(",");
        }
        digit --;
        mask /= 10;
    }

}