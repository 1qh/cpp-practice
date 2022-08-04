using namespace std;
#include <bits/stdc++.h>
typedef int z;
typedef vector<z> v;
#define f(i, x) for (z i = 0; i < x; ++i)
#define ff(i, x, y) for (z i = x; i < y; ++i)
#define fb(i, x, y) for (z i = x; i > y; --i)
#define r0 return 0
#define r1 return 1
#define r(x) freopen(x, "r", stdin)
#define w(x) freopen(x, "w", stdout)
#define wa(x) f.open(x, ios_base::app)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define indextable fast; readstw(); freopen("index.txt", "w", stdout);
#define elif else if
#define pb push_back
#define gl getline(cin, s)
#define sz cout << "\tSize of array: "
#define table cout << "\t   Runtime(s)   |    Algorithm\n"
#define uns cout << "\tUnsorted array: "
#define err cout << "\tPlease select again!\n"
#define down                     \
    cout << "\n\t";              \
    f(i, 6 * n + 1) cout << "-"; \
    cout << "\n"
#define numcity                      \
    cout << "\n Number of cities: "; \
    cin >> n
#define aline cout << "\t---------------------------------\n"
#define pr                       \
    f(i, n) cout << a[i] << " "; \
    cout << "\n"
#define getarr      \
    r("input.txt"); \
    a = x();        \
    r("CON")
#define intro_sort cout << "\n\n\t---------------------------------\n\t|      SORTING ALGORITHMS\t|\n\t|   Lai Quang Huy - 20194438\t|\n\t---------------------------------\n"
#define intro_knight cout << "\n\t\t\t------------------------------\n\t\t\t|\t  Knight Tour\t     |\n\t\t\t|  Lai Quang Huy - 20194438  |\n\t\t\t------------------------------\n"
#define intro_queen cout << "\n\t\t     ------------------------------\n\t\t     |\t\t 8 Queen\t  |\n\t\t     |  Lai Quang Huy - 20194438  |\n\t\t     ------------------------------\n"
#define intro_tsp cout << "\n\t---------------------------------\n\t|  TRAVELING SALESMAN PROBLEM\t|\n\t|   Lai Quang Huy - 20194438\t|\n\t---------------------------------\n"

map<string, bool> sw;
z n;
string w, stw, black = "[[[|]]]", white = "       ";
void bw(int x)
{
    cout << "\n\t";
    if (x % 2)
        f(k, 4) cout << black << white;
    else
        f(k, 4) cout << white << black;
}
void readstw()
{
    ifstream stopwords("stopw.txt");
    while (getline(stopwords, stw))
        sw[stw] = 1;
}
struct LINE
{
    z num;
    LINE *next;
};
LINE *newline(z num)
{
    LINE *p = new LINE;
    p->num = num;
    p->next = NULL;
    return p;
}
struct LINELIST
{
    LINE *head;
    LINE *tail;
};
void delLinePtrs(LINELIST &l)
{
    LINE *p;
    while (l.head)
    {
        p = l.head;
        l.head = l.head->next;
        delete p;
    }
}
void addLine(LINELIST &l, LINE *p)
{
    if (!l.head)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void outLineNum(LINELIST &l)
{
    for (LINE *p = l.head; p; p = p->next)
        cout << ", " << p->num;
    cout << '\n';
}
struct WORD
{
    string word;
    z freq;
    LINELIST ll;
    WORD *next;
};
WORD *newword(string word, z freq, LINELIST ll)
{
    WORD *p = new WORD;
    p->word = word;
    p->freq = freq;
    p->ll = ll;
    p->next = NULL;
    return p;
}
struct INDEX
{
    WORD *head;
    WORD *tail;
};
void delWordPtrs(INDEX &id)
{
    WORD *p;
    while (id.head)
    {
        p = id.head;
        delLinePtrs(p->ll);
        id.head = id.head->next;
        delete p;
    }
}
WORD *wordSearch(INDEX &id, string s)
{
    for (WORD *p = id.head; p; p = p->next)
        if (p->word == s)
            return p;
}
void addWord(INDEX &id, WORD *p)
{
    if (!id.head)
        id.head = id.tail = p;
    else
    {
        id.tail->next = p;
        id.tail = p;
    }
}
void outWord(INDEX &id)
{
    for (WORD *p = id.head; p; p = p->next)
    {
        cout << p->word << ' ' << p->freq;
        outLineNum(p->ll);
    }
}
void insertWord(INDEX &id, string s)
{
    WORD *p = wordSearch(id, s);
    if (!p)
    {
        LINELIST ll;
        ll.head = ll.tail = NULL;
        addLine(ll, newline(n + 1));
        addWord(id, newword(w, 1, ll));
    }
    else
    {
        p->freq++;
        if ((n + 1) != p->ll.tail->num)
            addLine(p->ll, newline(n + 1));
    }
}
struct TREE
{
    TREE *p;
    string s;
    TREE(TREE *p, string s)
    {
        this->p = p;
        this->s = s;
    }
};
void branch(TREE *t)
{
    if (!t)
        return;
    branch(t->p);
    cout << t->s;
}
