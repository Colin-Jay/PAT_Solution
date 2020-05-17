#include<cstdio>
#include<cmath>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    double y = round((double)n * 0.5);
    for(int i = 0; i < (int)y; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == int(y) - 1 || j == 0 || j == n - 1) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}