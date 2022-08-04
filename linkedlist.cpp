#include "all.h"
string l;

void extract(INDEX &id)
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
                    insertWord(id, w);
                w = "";
            }
        }
        n++;
    }
    for (WORD *p = id.head; p != id.tail; p = p->next)
        for (WORD *q = p->next; q; q = q->next)
            if (p->word > q->word)
            {
                swap(p->word, q->word);
                swap(p->freq, q->freq);
                swap(p->ll, q->ll);
            }
}
int main()
{
    indextable;
    INDEX id;
    id.head = id.tail = NULL;
    extract(id);
    outWord(id);
    delWordPtrs(id);
}
