#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

struct node {
    int key;
    node *lchild, *rchild;
};

int n;
vector<int> post, in;             //后序、中序遍历序列

//二叉树重建
node* create(int postL, int postR, int inL, int inR) {
    if(postL >= postR) {
        return NULL;
    }
    //不能只是node* now;需要先分配内存，否则now可能是NULL
    node* now = (node*)malloc(sizeof(node));    
    now->key = post[postR - 1];
    now->lchild = NULL;
    now->rchild = NULL;
    int lsize = 0;                 //记录左子树长度
    for(int i = inL; i < inR; i ++) {
        if (in[i] == post[postR - 1]) {
            lsize = i - inL;
        }
    }
    now->lchild = create(postL, postL + lsize, inL, inL + lsize);
    now->rchild = create(postL + lsize, postR - 1, inL + lsize + 1, inR);
    return now;
}

//层次遍历
int num = 0;
void layerOrder(node* Tree) {
    queue<node*> Lorder;
    Lorder.push(Tree);
    while (!Lorder.empty()) {
        node* temp = Lorder.front(); 
        Lorder.pop();
        printf("%d", temp->key);
        num++;
        if (num != post.size()) {
            printf(" ");          //先用#代替空格便于调试
        }
        if(temp->lchild != NULL) {
            Lorder.push(temp->lchild);
        }
        if(temp->rchild != NULL) {
            Lorder.push(temp->rchild);
        }   
    }
    return ;
}

int main () {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        post.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        in.push_back(temp);
    }
    //遍历序列的边界
    int postL = 0, inL = 0, postR = post.size(), inR = in.size();
    node* root;                    //二叉树根节点
    root = create(postL, postR, inL, inR);
    layerOrder(root);
    return 0;
}