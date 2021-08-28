#include <iostream>
#include <algorithm>
#include <cstring>

#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 100010;

struct LList{
    int own;                    //�Լ��ĵ�ַ
    int key;                    //ֵ
    int next;                   //��һ����ַ
    bool flag;                  //�Ƿ�Ϊ��Ч�ڵ�
}List0[maxn];

int Ahash[maxn];                //��¼��ַ�ڽṹ�������д�ŵ��±�

bool cmp(LList a, LList b) {
    if (a.flag == 1 && b.flag == 1) {
        return a.key < b.key;
    } else {
        return b.flag < a.flag;
    }
    
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    memset(List0, 0, sizeof(List0));
    fill(Ahash, Ahash + maxn, -1);
    int n, a0;
    scanf("%d %d", &n, &a0);
    // SEE(n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &List0[i].own, &List0[i].key, &List0[i].next);
        Ahash[List0[i].own] = i; //��¼��ַ�ڽṹ�������д�ŵ��±�
    }
    int count = 0;               //��¼��Ч�ڵ����
    for (int i = a0; i != -1;) {
        int temp = Ahash[i];
        // SEE(temp);
        if (temp >=0 && List0[temp].next != 0) {
            List0[temp].flag = 1;
            count++;
            i = List0[temp].next;
            // SEE(i);
        } else break;
    }
    // for (int i = 0; i < n; i++) {
    //     SEE(List0[i].flag);
    //     SEE(List0[i].key);
    // }
    if (!count) {
        printf ("0 -1");
    } else {
        sort (List0, List0 + n, cmp);
        printf ("%d %05d\n", count, List0[0].own);
        for (int i = 0; i < count; i++) {
            if (i != count-1) {
                printf ("%05d %d %05d\n", List0[i].own, List0[i].key, List0[i+1].own);
            } else {             //���һ���ڵ��nextΪ-1    
                printf ("%05d %d -1", List0[i].own, List0[i].key);
            }
        }
    }

    return 0;
}