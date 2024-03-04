//这代码还有问题
#include <iostream>
#include <queue>
#include <memory>
using namespace std;
#define RED     1
#define BLACK   0

typedef int KEY_TYPE;

#define RBTREE_ENTRY(name, type)    \
    struct {                        \
        rbtree_node* right;         \
        rbtree_node* left;          \
        rbtree_node* parent;        \
        unsigned char color;        \
    }

typedef struct rbtree_node {
    KEY_TYPE key;
    void* value;
#if 1
    rbtree_node* right;         
    rbtree_node* left;          
    rbtree_node* parent;        
    unsigned char color;        
#else
    RBTREE_ENTRY(, rbtree_node) node; 
#endif
}rbtree_node;

typedef struct rbtree {
    rbtree_node* root;
    rbtree_node* nil;
}rbtree;


void rbtree_left_rotate(rbtree* T, rbtree_node* x) {
    rbtree_node* y = x->right;
    x->right = y->left;   //x的右指针指向y的左结点
    if (y->left != T->nil) {    //y左结点的父结点为x
        y->left->parent = x;
    }
    y->parent = x->parent;  //y父结点为x父结点
    if (x->parent == T->nil) {  //如果x为根结点，y也得设为根结点
        T->root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rbtree_right_rotate(rbtree* T, rbtree_node* x) {
    rbtree_node* y = x->left;
    x->left = y->right;   //x的右指针指向y的左结点
    if (y->right != T->nil) {    //y左结点的父结点为x
        y->right->parent = x;
    }
    y->parent = x->parent;  //y父结点为x父结点
    if (x->parent == T->nil) {  //如果x为根结点，y也得设为根结点
        T->root = y;
    }
    else if (x == x->parent->right) {
        x->parent->right = y;
    }
    else {
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

//调整颜色
void rbtree_insert_fixup(rbtree* T, rbtree_node* x) {
    while (x->parent->color == RED) {   //该插入结点父结点为红，说明颜色不对不满足红黑树性质第四条，如果一个结点是红色的，那么它的子结点为黑色的，可以肯定该结点为红，父结点为红，祖父节点为黑，叔父结点不确定
        if (x->parent == x->parent->parent->left) { //父结点为祖父结点的左结点
            rbtree_node* y = x->parent->parent->right; //叔父结点
            if (y->color == RED) {  //叔父结点为红
                x->parent->color = BLACK;   
                y->color = BLACK;
                y->parent->color = RED;
                x = x->parent->parent;  //回溯，时刻保持红色
            }
            else {  //叔父结点为黑
                if (x == x->parent->right) {    //该结点为父结点右结点，先左旋将该结点变为父结点左结点在执行下面的右旋
                    x = x->parent;
                    rbtree_left_rotate(T, x);
                }
                if (x == x->parent->left) { //该结点为父结点左结点
                    x->parent->color = BLACK;
                    y->parent->color = RED;
                    rbtree_right_rotate(T, y->parent);
                }
            }
        }
    }
}

void rbtree_insert(rbtree* T, rbtree_node* x) {
    rbtree_node* z = T->nil;
    rbtree_node* y = T->root;
    while (y != T->nil) {
        z = y;  //最终z为y父结点
        if (x->key < y->key) {
            y = y->left;
        }
        else if (x->key > y->key) {
            y = y->right;
        }
        else {  //根据业务而定
            return;
        }
    }
    if (z == T->nil) {  //说明没经过循环，红黑树根结点为nil
        T->root = x;
    }
    else {  
        if (x->key < z->key) {
            z->left = x;
        }
        else {
            z->right = x;
        }
    }
    x->parent = z;
    x->left = x->right = T->nil;
    x->color = RED;
    rbtree_insert_fixup(T, x);  //调整颜色
}

void rbtree_print(rbtree* T) {
    queue<rbtree_node*> q;
    q.push(T->root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            rbtree_node* x = q.front();
            q.pop();
            if (x != T->nil) q.push(x->left);
            if (x != T->nil) q.push(x->right);
            cout << x->key << ":" << (x->color == RED ? "RED" : "BLACK") << endl;
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    rbtree* T = new rbtree();
    for (int i = 0; i < n; i++) {
        rbtree_node* x = new rbtree_node();
        cin >> x->key;
        rbtree_insert(T, x);
        // rbtree_print(&T);
    }
    return 0;
}