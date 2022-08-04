#include <bits/stdc++.h>
using namespace std;
typedef unsigned short int z;
#define f(i,x) for(z i = 0; i < x; ++i)

struct DATA{
    z n;
};
struct NODE{
    DATA data;
    NODE *next;
};
struct LIST{
    NODE *head;
    NODE *tail;
};
void init(LIST& l){
    l.head = l.tail = NULL;
}
NODE* create(DATA data) {
    NODE* p = new NODE;
    if (!p) return NULL;
    p->data = data;
    p->next = NULL;
}
NODE* create(z n){
    DATA data = {n};
    NODE* p = create(data);
    return p;
}
NODE* getAtIndex(LIST& l, z i){
    if (!l.head && i < 0) return NULL;
    else {
        z cur = 0;
        NODE* p = l.head;
        while (p && cur < i) {
            cur++;
            p = p->next;
        }
        return p;
    }
}
NODE* getAtValue(LIST& l, z i){
    if (!l.head) return NULL;
    else {
        NODE* p = l.head;
        while (p->data.n != i) p = p->next;
        return p;
    }
}
void addHead(LIST& l, NODE *p) {
    if (!l.head) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
}
void delHead(LIST& l){
    if (!l.head) return;
    NODE* p = l.head;
    l.head = l.head->next;
    delete p;
}
void addTail(LIST& l, NODE *p) {
    if (!l.head) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void delTail(LIST& l){
    if (!l.head) return;
    if (l.head->next == NULL) delHead(l);
    for(NODE *p = l.head; p; p = p->next) if (p->next == l.tail) {
        delete l.tail;
        p->next = NULL;
        l.tail = p;
        return;
    }
}
void insertAfter(LIST& l, NODE* newnode, NODE* p){
    if (p) {
        newnode->next = p->next;
        p->next = newnode;
        if (l.tail == p) l.tail = newnode;
    }
    else addHead(l,newnode);
}
void delAfter(LIST& l, NODE* p){
    NODE* delnode;
    delnode = p->next;
    p->next = delnode->next;
    delete delnode;
}
void delAt(LIST& l, NODE* p){
    if (p == l.head) delHead(l);
    else for(NODE *k = l.head; k; k = k->next) if (k->next == p) delAfter(l,k);
}
z getSize(LIST l){
    if (!l.head) return 0;
    else {
        z c = 0;
        NODE* p = l.head;
        while (p) {
            c++;
            p = p->next;
        }
        return c;
    }
}
void out(LIST& l){
    for(NODE* p = l.head; p; p = p->next) cout << p->data.n << ' ';
    cout << '\n';
}
void delallptrs(LIST &l){
    NODE* p;
    while(l.head){
        p = l.head;
        l.head = l.head->next;
        delete p;
    }
}
int main () {
    srand(time(0));
    LIST l;
    init(l);

    z k, val;
    cin >> k;
    f(i,k) addTail(l,create(rand() % 100));
    out(l);

    delallptrs(l);
}
