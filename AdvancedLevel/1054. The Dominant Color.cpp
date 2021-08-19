#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    map<string, int> mp;                       //建立颜色和次数的映射
    string str;
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> str;
            if (mp.find(str) == mp.end()) { 
                mp[str] = 0;
            }
            mp[str]++; 
        }
    }
    //找出主导色
    int temp = 0;                                //记录最大值
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it->second > temp) {
            temp = it -> second;
            str = it -> first;
        }
    }
    cout << str;
    return 0;
}