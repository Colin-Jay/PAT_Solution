#include <stdio.h>
#include <algorithm>
// #define LOCAL

using namespace std;

typedef struct AVLNode {                              //AVL树结点
   int height, val;
   struct AVLNode *lchild, *rchild, *parent;
} AVLNode, *AVLTree;

// void InitAVLTree (AVLTree &T) {                    //初始化
//    T -> lheight = 0;
//    T -> rheight = 0;
//    T -> lchild = NULL;
//    T -> rchlid = NULL;
//    T -> parent = NULL;
// }

AVLNode *AVLTreeInsert (AVLTree &T, int val) {        //插入新的结点
   if (T == NULL) {
      T = (AVLTree)malloc(sizeof(AVLNode));
      T->val = val;
      T->lchild = NULL;
      T->rchild = NULL;
      T->parent = NULL;
      return T;
   } else if (val < T->val) {
      return AVLTreeInsert(T->lchild, val);
   } else {
      return AVLTreeInsert(T->rchild, val);
   }
}

int AVLTreeHeight (AVLTree &T) {                      //求高度
   if (T == NULL) {
      return 0;
   } else {
      int lheight, rheight;
      lheight = AVLTreeHeight(T->lchild);
      rheight = AVLTreeHeight(T->rchild);
      T->height = max(lheight + 1, rheight + 1);
      //   printf("%d*\n", T -> height);
      return T->height;
   }
}

void SetParent (AVLTree &T) {                         //设置双亲结点
   if (T == NULL) {
      return; 
   }
   if (T->lchild != NULL) {
      T->lchild->parent = T;
      SetParent(T->lchild);
   }
   if (T->rchild != NULL) {
      T->rchild->parent = T;
      SetParent(T->rchild);
   }
}

void AVLTreeLrevov (AVLTree &p, AVLTree &T) {         //左旋操作
   if (p->parent->parent != NULL) {                   //首先判断需要旋转的结点的双亲结点的双亲结点是否为空
      if (p->parent->val < p->parent->parent->val) {  //若不为空，则需要将其指针指向需要旋转的结点
         p->parent->parent->lchild = p;               //根据大小规则判断是更改其祖先的左孩子指针还是右孩子指针
      } else {
         p->parent->parent->rchild = p;
      }
   }
   p->parent->rchild = p->lchild;                     //将需要旋转的结点的双亲结点的右孩子指向将需要旋转的结点的左孩子
   p->lchild = p->parent;                             //将需要旋转的结点的左孩子指向该结点原来的双亲结点
   if (p->lchild->val == T->val) {                    //如果需要旋转的结点变成新的根结点，则移动根结点指针指向它并将根结点的双亲指针清空
      T = p;  
      T->parent = NULL;
   }
}

void AVLTreeRrevov (AVLTree &p, AVLTree &T) {         //右旋操作
   if (p->parent->parent != NULL) {                   //首先判断需要旋转的结点的双亲结点的双亲结点是否为空
      if (p->parent->val < p->parent->parent->val) {  //若不为空，则需要将其指针指向需要旋转的结点
         p->parent->parent->lchild = p;               //根据大小规则判断是更改其祖先的左孩子指针还是右孩子指针
      } else {
         p->parent->parent->rchild = p;
      }
   }
   p->parent->lchild = p->rchild;                     //将需要旋转的结点的双亲结点的左孩子指向将需要旋转的结点的右孩子
   p->rchild = p->parent;                             //将需要旋转的结点的右孩子指向该结点原来的双亲结点
   if (p->rchild->val == T->val) {                    //如果需要旋转的结点变成新的根结点，则移动根结点指针指向它并将根结点的双亲指针清空
      T = p;
      T->parent = NULL;
   }
}

// void visit (AVLTree T) {                           //前序遍历
//     if (T != NULL) {
//       printf("T->val=%d,T->height=%d--\n",T->val, T->height);
//       visit (T->lchild);
//       visit (T->rchild);
//    }
// }

int main () {
#ifdef LOCAL
   freopen("./in.txt", "r", stdin);
   // freopen("./out.txt", "w", stdout);
#endif
   int n;
   scanf("%d", &n);
   AVLTree T = NULL;
   AVLNode *p = NULL;
   // InitAVLTree (T);
   for (int i = 0; i < n; i++) {
      int lheight = 0, rheight = 0, value = 0;        //左子树高度、右子树高度、值
      int revov = 0;                                  //标志需要进行的旋转操作，0-4代表结点类型，不操作，LL，LR，RL，RR
      scanf("%d", &value);
      p = AVLTreeInsert(T, value);
      AVLTreeHeight(T);
      SetParent(T);
      while (p != NULL) {                             //找到第一个不平衡结点
         if (p->lchild != NULL) {                     //左子树高度
            lheight = p->lchild->height;
         } else {
            lheight = 0;
         }
         if (p->rchild != NULL) {                     //右子树高度
            rheight = p->rchild->height;
         } else {
            rheight = 0;
         }
         if (abs(lheight - rheight) < 2) {            //从插入点往上寻找双亲结点，使p为第一个不平衡结点
            p = p->parent;
         } else break;
      }
      if (abs(lheight - rheight) >= 2) {              //p可能为NULL，可能为第一个不平衡结点
         if (value < p->val) {
            p = p->lchild;                            //需要进行LL/LR旋转操作
            if (value < p->val) {
               revov = 1;                             //LL旋转操作
            } else {
               revov = 2;                             //LR旋转操作
            }
         } else {
            p = p->rchild;                           //需要进行RL/RR旋转操作
            if (value < p->val) {
               revov = 3;                            //RL旋转操作
            } else {
               revov = 4;                            //RR旋转操作
            }
         }
      }
      switch (revov) {                                //根据不平衡点类型选择旋转操作，旋转后注意重新设置双亲结点
      case 0:                                         //不是不平衡点，不进行操作
         break;
      case 1:                                         //LL类型进行右旋操作，旋转的对象是不平衡结点的左结点即p
         AVLTreeRrevov(p, T);
         SetParent(T);
         break;
      case 2:                                         //LR类型先进行左旋操作再进行右旋操作，旋转的对象是不平衡结点的左结点的右结点即p->rchild
         p = p->rchild;
         AVLTreeLrevov(p, T);
         SetParent(T);
         AVLTreeRrevov(p, T);
         SetParent(T);
         break;
      case 3:                                         //RL类型先进行右旋操作再进行左旋操作，旋转的对象是不平衡结点的右结点的左结点即p->lchild
         p = p->lchild;                               
         AVLTreeRrevov(p, T);
         SetParent(T);
         AVLTreeLrevov(p, T);
         SetParent(T);
         break;
      case 4:                                         //RR类型进行左旋操作，旋转的对象是不平衡结点的右结点即p
         AVLTreeLrevov(p, T);
         SetParent(T);
         break;
      }
      // visit(T);                                    //遍历一遍AVL树，检查是否正确
   }
   printf("%d", T->val);                              //已经成功构建AVL树，选择自己的操作
   return 0;
}