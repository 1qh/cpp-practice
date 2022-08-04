#include "all.h"
string l;

struct TWORD
{
    string word;
    z freq;
    LINELIST ll;
    TWORD *left, *right;
};
TWORD *newTword(string word, z freq, LINELIST ll)
{
    TWORD *p = new TWORD;
    p->word = word;
    p->freq = freq;
    p->ll = ll;
    p->left = p->right = NULL;
    return p;
}
TWORD *TwordSearch(TWORD *r, string s)
{
    if (!r || r->word == s)
        return r;
    else if (s <= r->word)
        return TwordSearch(r->left, s);
    return TwordSearch(r->right, s);
}
void ins(TWORD *&r, TWORD *p)
{
    if (!r)
        r = p;
    else if (p->word <= r->word)
        ins(r->left, p);
    else
        ins(r->right, p);
}
void inorder(TWORD *r)
{
    if (r)
    {
        inorder(r->left);
        cout << r->word << ' ' << r->freq;
        outLineNum(r->ll);
        inorder(r->right);
    }
}
void delTWordPtrs(TWORD *p)
{
    if (!p)
        return;
    delTWordPtrs(p->left);
    delTWordPtrs(p->right);
    delLinePtrs(p->ll);
    delete p;
}
void store(TWORD *r, vector<TWORD *> &v)
{
    if (!r)
        return;
    store(r->left, v);
    v.pb(r);
    store(r->right, v);
}
TWORD *build(vector<TWORD *> &v, z low, z high)
{
    if (low > high)
        return NULL;
    z mid = (low + high) / 2;
    TWORD *r = v[mid];
    r->left = build(v, low, mid - 1);
    r->right = build(v, mid + 1, high);
    return r;
}
TWORD *balanced(TWORD *r)
{
    vector<TWORD *> v;
    store(r, v);
    z k = v.size();
    return build(v, 0, k - 1);
}
void insertTWord(TWORD *&r, string w)
{
    TWORD *p = TwordSearch(r, w);
    if (!p)
    {
        LINELIST ll;
        ll.head = ll.tail = NULL;
        addLine(ll, newline(n + 1));
        ins(r, newTword(w, 1, ll));
    }
    else
    {
        p->freq++;
        if ((n + 1) != p->ll.tail->num)
            addLine(p->ll, newline(n + 1));
    }
}
void display(TWORD *r, TREE *p, bool up)
{
    if (!r)
        return;
    string blank = "        ";
    TREE *t = new TREE(p, blank);
    display(r->right, t, 1);
    if (!p)
        t->s = "      ";
    else if (up)
    {
        t->s = ".---- ";
        blank = "       |";
    }
    else
    {
        t->s = "`---- ";
        p->s = blank;
    }
    branch(t);
    cout << r->word << ' ' << r->freq;
    outLineNum(r->ll);
    if (p)
        p->s = blank;
    t->s = "       |";
    display(r->left, t, 0);
}
void extract(TWORD *&r)
{
    ifstream doc("doc.txt");
    while (getline(doc, l))
    {
        f(i, l.size())
        {
            if (isupper(l[i]) && isalpha(l[i + 1]) && (!i || ispunct(l[i - 1]) || ispunct(l[i - 2])))
                w += tolower(l[i]);
            else if (isupper(l[i]))
                while (isalpha(l[i]))
                    i++;
            else if (islower(l[i]))
            {
                while (isalpha(l[i]))
                    w += l[i], i++;
                if (!sw[w])
                    insertTWord(r, w);
                w = "";
            }
        }
        n++;
    }
}
int main()
{
    indextable;
    TWORD *r = NULL;
    extract(r);
    inorder(r);
    r = balanced(r);
    display(r, 0, 0);
    delTWordPtrs(r);
}
