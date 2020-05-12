#include<stdio.h>

int main()
{
    //C为最后的输出
    int Ak, Bk, Ck; //K值
    
    //输入参数
    scanf("%d", &Ak);
    int An[Ak-1];
    double Aa[Ak-1];
    for(int i = 0; i < Ak; i++)
    {
        scanf("%d %lf", &An[i], &Aa[i]);
    }

    scanf("%d", &Bk);
    int Bn[Ak-1];
    double Ba[Bk-1];
    for(int i = 0; i < Bk; i++)
    {
        scanf("%d %lf", &Bn[i], &Ba[i]);
    }

    //确定Ck
    Ck = Ak;
    for(int i = 0; i < Bk; i++)
    {
        int Ckplus = 1;
        for(int j = 0; j < Ak; j++)
        {
            if(Bn[i] == An[j])
            {
                Ckplus = 0;
                break;
            } 
        }
        Ck += Ckplus;
    }

    //构造Dn合并An和Bn，便于确定Cn
    int Dk = Ak + Bk;
    int Dn[Dk-1];
    for(int i = 0; i< Dk; i++)
    {
        if(i < Ak)
        {
            Dn[i] = An[i];
        }
        else
        {
            Dn[i] = Bn[i-Ak];
        }
    }

    //确定Cn
    int Cn[Ck-1];
    Cn[0] = 1001;
    for(int i = 0; i < Ck; i++)
    {
        //每轮循环确定一次Dn中未确定的最大值
        int max = -1;
        
        for(int j = 0; j < Dk; j++)
        {
            if(i == 0)
            {
                if(Dn[j] > max)
                {
                    max = Dn[j];
                }                       
            }
            else
            {
                if((Dn[j] > max) && (Dn[j] < Cn[i-1]))
                {
                    max = Dn[j];
                }
            }
        }

        Cn[i] = max;
    }

    //确定Ca
    double Ca[Ck-1];
    for(int i = 0; i < Ck; i++)
    {
        Ca[i] = 0;
        for(int j = 0; j < Ak; j++)
        {
            if(Cn[i] == An[j])
            {
                Ca[i] += Aa[j];
            }
        }

        for(int j = 0; j < Bk; j++)
        {
            if(Cn[i] == Bn[j])
            {
                Ca[i] += Ba[j];
            }
        }
    }

    //输出
    int Cksub = 0;
    for(int i = 0 ; i < Ck; i++)
    {
        if(Ca[i] == 0)
        {
            Cksub++;
        }  
    }
    Cksub = Ck - Cksub;
    printf("%d", Cksub);
    for(int i = 0 ; i < Ck; i++)
    {
        if(Ca[i] == 0)
        {
            continue;
        }
        printf(" %d %.1f", Cn[i], Ca[i]);
    }
    return 0;
}