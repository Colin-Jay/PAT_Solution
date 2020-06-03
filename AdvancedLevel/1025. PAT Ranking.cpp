#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    char reg_num[13];
    int score;
    int finR, locN, locR; 
} stu[30010];

bool cmp(Student a, Student b) {
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.reg_num, b.reg_num) < 0;
}

int main() {
    int n, k, num = 0;
    scanf("%d", &n);
    //loc is location_number
    for(int loc = 1; loc <= n; loc++) {
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            scanf("%s %d", &stu[num+i].reg_num, &stu[num+i].score);
            stu[num+i].locN = loc;
        }
        num += k;
        //对每个local的location进行排名
        sort(stu + num - k, stu + num, cmp);
        // for(int i = 0; i < k; i++) {
        //     printf("%d", stu[num-k+i].score);
        // }
        //得到locR
        stu[num-k].locR = 1;
        for(int j = 1; j < k; j++) {
            if(stu[num-k+j].score != stu[num-k+j-1].score) {
                stu[num-k+j].locR = j+1;
            } else {
                stu[num-k+j].locR = stu[num-k+j-1].locR;
            }

        }

    }
    //整个学生进行排名
    sort(stu, stu+num, cmp);
    // for(int i = 0; i < num; i++) {
    //     printf("%d\n", stu[i].score);
    // }
    //得到finR
    stu[0].finR = 1;
    for(int i = 1; i < num; i++) {
        if(stu[i].score != stu[i-1].score) {
            stu[i].finR = i+1;
        } else {
            stu[i].finR = stu[i-1].finR;
        }
    }
    // for(int i = 0; i < num; i++) {
    //     printf("%d\n", stu[i].score);
    // }

    //print
    printf("%d\n", num);
    for(int i = 0; i < num; i++) {
        printf("%s %d %d %d\n", stu[i].reg_num, stu[i].finR, stu[i].locN, stu[i].locR);
    }

    return 0;
}

