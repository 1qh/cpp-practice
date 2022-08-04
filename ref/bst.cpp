#include <bits/stdc++.h>
using namespace std;
typedef short int z;
#define f(i,x) for (z i; i < x; i++)
#define pb push_back
z n;

struct NODE {
    z data;
    NODE *left, *right;
};
NODE* create(z data) {
    NODE* p = new NODE;
    p->data = data;
    p->left = p->right = NULL;
    return p;
}
NODE* searchNode(NODE* r, NODE* p) {
    if (!r || p->data == r->data) return r;
    if (p->data <= r->data) return searchNode(r->left, p);
    return searchNode(r->right, p);
}
void ins(NODE* &r, NODE* p) {
    if (!r) r = p;
    else if (p->data <= r->data) ins(r->left,p);
    else ins(r->right,p);
}
void inorder(NODE* r){
    if (r) {
        inorder(r->left);
        cout << r->data << ' ';
        inorder(r->right);
    }
}
void store(NODE* r, vector<NODE*> &v) {
    if (!r) return;
    store(r->left, v);
    v.pb(r);
    store(r->right, v);
}
NODE* build (vector<NODE*> &v, z low, z high) {
    if (low > high) return NULL;
    z mid = (low + high) / 2;
    NODE* r = v[mid];
    r->left = build(v, low, mid - 1);
    r->right = build(v, mid + 1, high);
    return r;
}
NODE* balanced(NODE* r){
	vector<NODE*> v;
	store(r, v);
	z n = v.size();
	return build(v, 0, n-1);
}
void destroy(NODE* p) {
    if (!p) return;
    destroy(p->left);
    destroy(p->right);
    delete p;
}
struct TREE {
    TREE *p;
    string s;
    TREE(TREE *p, string s) {
        this->p = p;
        this->s = s;
    }
};
void branch(TREE *t) {
    if (!t) return;
    branch(t->p);
    cout << t->s;
}
void display(NODE* r, TREE *p, bool up) {
    if (!r) return;
    string blank = "        ";
    TREE *t = new TREE(p, blank);
    display(r->right, t, 1);
    if (!p) t->s = "      ";
    else if (up) {
        t->s = ".---- ";
        blank = "       |";
    }
    else {
        t->s = "`---- ";
        p->s = blank;
    }
    branch(t);
    cout << setw(3) << r->data << '\n';
    if (p) p->s = blank;
    t->s = "       |";
    display(r->left, t, 0);
}
int main() {
    NODE* r = NULL;
    srand(time(0));
    cin >> n;
    f(i,n) ins(r,create(rand()%1000));
    inorder(r);
	r = balanced(r);
    cout << "\n\n";
    display(r,0,0);
    destroy(r);
}
