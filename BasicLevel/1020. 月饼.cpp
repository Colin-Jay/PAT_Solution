#include <cstdio>
#include <algorithm>

using namespace std;

struct mooncake
{
    double sum;
    double sumPrice;
    double price;
} cake[1010];

bool cmp(mooncake a, mooncake b)
{//按照单价将月饼排序
    return a.price > b.price;
}

int main()
{
    int n;              //种类
    double d;           //需求量
    double maxPfit = 0; //利润
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; i++)
    { 
        scanf("%lf", &cake[i].sum);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sumPrice);
        cake[i].price = cake[i].sumPrice / cake[i].sum;
    }
    sort(cake, cake + n, cmp);
    double temp = d; //剩余需求
    for (int i = 0; i < n; i++)
    {//第二个条件i<n不能是temp>0，当d足够大可能段错误
        if (temp >= cake[i].sum)
        {
            maxPfit += cake[i].sumPrice;
            temp -= cake[i].sum;
        }
        else
        {
            maxPfit += temp * cake[i].price;
            break;
        }
    }
    printf("%.2f", maxPfit);
}