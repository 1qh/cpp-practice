#include "all.h"
#define M 100
string l;

void initIndex(INDEX &id)
{
    id.head = id.tail = NULL;
}
void display(INDEX hashtable[])
{
    f(i, M) if (hashtable[i].head)
    {
        cout << "\n==== Bucket " << i + 1 << " ====\n";
        outWord(hashtable[i]);
    }
}
z hfunc(string k)
{
    z sum = 0;
    f(i, k.size()) sum += k[i];
    return sum % M;
}
void hashing(INDEX hashtable[])
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
                    insertWord(hashtable[hfunc(w)], w);
                w = "";
            }
        }
        n++;
    }
}
int main()
{
    indextable;
    INDEX hashtable[M];
    f(i, M) initIndex(hashtable[i]);
    hashing(hashtable);
    cout << "=== HASH TABLE ===\n";
    display(hashtable);
    INDEX id;
    initIndex(id);
    f(i, M) for (WORD *p = hashtable[i].head; p; p = p->next) addWord(id, p);
    for (WORD *p = id.head; p != id.tail; p = p->next)
        for (WORD *q = p->next; q; q = q->next)
            if (p->word > q->word)
            {
                swap(p->word, q->word);
                swap(p->freq, q->freq);
                swap(p->ll, q->ll);
            }
    cout << "\n\n\n=== INDEX TABLE ===\n\n";
    outWord(id);
    delWordPtrs(id);
}
