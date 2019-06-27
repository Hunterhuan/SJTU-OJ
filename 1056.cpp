#include <iostream>
#include <cstdio>
using namespace std;
int m, n;
int box[500005];//每个盒子多少个糖;
int sugar[500005];//每个糖属于几号盒子;
int movebox[500005] = {0};//每个盒子合并到哪个盒子;
int boxnum;
template<class T>
class BinarySearchTree{
private:
    struct BinaryNode{
        T data;
        BinaryNode * left;
        BinaryNode * right;
        int height;
        BinaryNode(const T& otherdata, BinaryNode * otherl, BinaryNode * otherr):data(otherdata), left(otherl), right(otherr), height(1){}
    };
public:
    BinarySearchTree(BinaryNode * t = NULL){root = t;}
    ~BinarySearchTree() {makeEmpty(root);}
    bool find(const T& x)const{
        return find(x, root);
    }
    void insert(const T& x){
        insert(x, root);
    }
    void remove(const T& x){
        remove(x, root);
    }
    T& findkth(int i){
        return findkth(i, root);
    }
private:
    BinaryNode * root;
    void insert(const T& x, BinaryNode * &t){
        if (t==NULL) t = new BinaryNode(x, NULL, NULL);
        else if (x>t->data) {
            insert(x, t->left);
            if (h(t->left)-h(t->right) == 2){
                if (x > t->left->data){
                    LL(t);
                }
                else LR(t);
            }
            t->height = h(t->left) + h(t->right) + 1;
        }
        else {
            insert(x, t->right);
            if (h(t->right)-h(t->left) == 2){
                if (x <= t->right->data){
                    RR(t);
                }
                else RL(t);
            }
            t->height = h(t->left) + h(t->right) + 1;
        }
    }
    void remove(const T& x, BinaryNode * &t){
        if (t == NULL) return;
        if (x>t->data) {
            remove(x, t->left);
            if (h(t->right) - h(t->left) == 2){
                BinaryNode *r =  t->right;
                if (h(r->left) > h(r->right))
                    RL(t);
                else
                    RR(t);
            }
            t->height = h(t->left) + h(t->right) + 1;
        }
        else if (x<t->data) {
            remove(x, t->right);
            if (h(t->left) - h(t->right) == 2){
                BinaryNode *r =  t->left;
                if (h(r->right) > h(r->left))
                    LR(t);
                else
                    LL(t);
            }
            t->height = h(t->left) + h(t->right) + 1;
        }
        else if (t->left != NULL && t->right != NULL){
            if (h(t->left) <= h(t->right)){
                BinaryNode * tmp = t->right;
                while(tmp->left != NULL) tmp = tmp->left;
                t->data = tmp->data;
                remove(t->data, t->right);
                t->height = h(t->left) + h(t->right) + 1;
            }
            else{
                BinaryNode * tmp = t->left;
                while (tmp->right != NULL) tmp = tmp->right;
                t->data = tmp->data;
                remove(t->data, t->left);
                t->height = h(t->left) + h(t->right) + 1;
            }
        }
        else{
            BinaryNode * old = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete old;
        }
    }
    bool find(const T& x, BinaryNode * t)const{
        if (t == NULL) return false;
 
        if (x>t->data) return find(x, t->left);
        if (x<t->data) return find(x, t->right);
 
        return true;
    }
    void makeEmpty(BinaryNode * &t){
        if (t == NULL) return;
        BinaryNode * tmp = t;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete tmp;
        t = NULL;
    }
    T& findkth(int i, BinaryNode *&t){
        int rs = h(t->left);
        if (rs == i-1){
            return t->data;
        }
 
        if (rs >= i) return findkth(i, t->left);
        else return findkth(i-rs-1, t->right);
    }
    int h(BinaryNode * t){
        return t==NULL ? 0 : t->height;
    }
    void LL(BinaryNode *&t){
        BinaryNode * t1 = t->left;
        t->left = t1->right;
        t1->right = t;
        t->height = h(t->left) + h(t->right) + 1;
        t1->height = h(t1->left) + h(t)+1;
        t = t1;
    }
    void RR(BinaryNode *&t){
        BinaryNode * t1 = t->right;
        t->right = t1->left;
        t1->left = t;
        t->height = h(t->left) + h(t->right) + 1;
        t1->height = h(t1->right) + h(t)+1;
        t = t1;
    }
    void LR(BinaryNode *&t){
        RR(t->left);
        LL(t);
    }
    void RL(BinaryNode *&t){
        LL(t->right);
        RR(t);
    }
};
int main()
{
    scanf("%d%d", &n, &m);
    BinarySearchTree<int> t;
    for (int i=1; i<=n; i++){
        box[i] = 1;
        t.insert(1);
        sugar[i] = i;
    }
    boxnum = n;
    char query;
    int x, y;
    while (m--){
        query = getchar();
        query = getchar();
        switch(query){
        case 'C':
            scanf("%d%d", &x, &y);
            while (movebox[sugar[x]] != 0){//找到x糖果现在在几号盒子;
                sugar[x] = movebox[sugar[x]];
            }
            while (movebox[sugar[y]] != 0){//找到y糖果现在在几号盒子;
                sugar[y] = movebox[sugar[y]];
            }
            if (sugar[y] != sugar[x] && box[sugar[x]] != 0 && box[sugar[y]] != 0){
                t.remove(box[sugar[x]]);
                t.remove(box[sugar[y]]);
                box[sugar[x]] += box[sugar[y]];
                t.insert(box[sugar[x]]);
                box[sugar[y]] = 0;
                movebox[sugar[y]] = sugar[x];//y的盒子移动到x的盒子;
                boxnum--;
            }
            break;
        case 'D':
            scanf("%d", &x);
            while (movebox[sugar[x]] != 0){//同上;
                sugar[x] = movebox[sugar[x]];
            }
            if (box[sugar[x]] != 0){
                t.remove(box[sugar[x]]);
                box[sugar[x]] = 0;
                boxnum--;
            }
            break;
        case 'Q':
            scanf("%d", &x);
            if (boxnum < x) printf("%d\n", 0);
            else{
                printf("%d\n", t.findkth(x));
            }
            break;
        default:
            cout << "Wrong!\n";
            break;
        }
    }
    return 0;
}