#include "all.h"
using namespace std::chrono;

v a, da;
z i, j, m, l, r, p, k;
string s;
char c;
ofstream f;

//BUBBLE SORT
void bb(v &a)
{
    z t[n];
    f(i, n) t[i] = a[i];
    a.clear();
    f(i, n) fb(j, n - 1, i) if (t[j] < t[j - 1]) swap(t[j], t[j - 1]);
    f(i, n) a.pb(t[i]);
}
//SELECTION SORT
void sl(v &a)
{
    z t[n];
    f(i, n) t[i] = a[i];
    a.clear();
    f(i, n - 1)
    {
        m = i;
        ff(j, i + 1, n) if (t[j] < t[m]) m = j;
        swap(t[m], t[i]);
    }
    f(i, n) a.pb(t[i]);
}

//HEAP SORT
void h(v &a, z i, z k)
{
    m = i;
    l = 2 * i + 1;
    r = l + 1;
    if (l < k && a[l] > a[i])
        m = l;
    if (r < k && a[r] > a[m])
        m = r;
    if (m != i)
    {
        swap(a[i], a[m]);
        h(a, m, k);
    }
}
void hs(v &a)
{
    fb(i, n / 2, -1) h(a, i, n);
    fb(i, n - 1, 0)
    {
        swap(a[0], a[i]);
        h(a, 0, i);
    }
}

//QUICK SORT
z q(v &a, z l, z r)
{
    k = l;
    i = l + 1;
    j = r;
    while (i <= j)
    {
        if (a[i] > a[k] && a[k] > a[j])
            swap(a[i], a[j]);
        elif (a[i] <= a[k]) i++;
        elif (a[j] >= a[k]) j--;
    }
    swap(a[j], a[k]);
    return j;
}
void qs(v &a, z l, z r)
{
    if (l < r)
    {
        p = q(a, l, r);
        qs(a, l, p - 1);
        qs(a, p + 1, r);
    }
}

//MERGE SORT
void mg(v &a, z l, z m, z r)
{
    z t[n];
    k = i = l;
    j = m + 1;
    while (i <= m || j <= r)
    {
        if (i > m)
            t[k++] = a[j++];
        elif (j > r) t[k++] = a[i++];
        elif (a[i] < a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    }
    ff(i, l, r + 1) a[i] = t[i];
}
void ms(v &a, z l, z r)
{
    if (l < r)
    {
        z m = (l + r) / 2;
        ms(a, l, m);
        ms(a, m + 1, r);
        mg(a, l, m, r);
    }
}

//READ ARRAY
v x()
{
    gl;
    istringstream ss(s);
    while (ss >> i)
        a.pb(i);
    return a;
}
//GENERATE RANDOM ARRAY
void rd(z m)
{
    srand(time(0));
    f(i, m) a.pb(rand() % 1000);
    w("input.txt");
    pr;
    w("CON");
}
//EXECUTE
void exe(z k)
{
    if (k == 1)
    {
        bb(a);
        s = "Bubble";
    }
    elif (k == 2)
    {
        sl(a);
        s = "Selection";
    }
    elif (k == 3)
    {
        hs(a);
        s = "Heap";
    }
    elif (k == 4)
    {
        qs(a, 0, n - 1);
        s = "Quick";
    }
    elif (k == 5)
    {
        ms(a, 0, n - 1);
        s = "Merge";
    }
}
void go(z k)
{
    auto b = high_resolution_clock::now();
    exe(k);
    auto e = high_resolution_clock::now();
    auto tt = duration_cast<microseconds>(e - b);
    double tm = tt.count() / 1000000.f;
    cout << "\t  " << setw(12) << fixed << setprecision(6) << tm << "  |  " << s << " Sort\n";
    f << fixed << setprecision(6) << tm;
}
//ANALYZE RUNTIME
void ana()
{
    gl;
    da = x();
    w("analysis.csv");
    cout << "Array size,Bubble,Selection,Heap,Quick,Merge";
    w("CON");
    cout << "\n\t      PERFORMANCE COMPARISON\n\n";
    aline;
    table;
    aline;
    wa("analysis.csv");
    f(i, da.size())
    {
        n = da[i];
        rd(n);
        cout << "\t\tArray size: " << n << "\n";
        aline;
        f << "\n";
        f << n;
        f(i, 5)
        {
            getarr;
            f << ",";
            go(i + 1);
            a.clear();
        }
        aline;
    }
}
//HANDLE INPUT
void in()
{
    cout << "\n\t0. Runtime analysis\n\t-------------------\n\
\t1. User input\n\
\t2. From input.txt\n\
\t3. Random array\n\n\
\tSelect input method: ";
    cin >> k;
    if (k == 1)
    {
        cout << "\tEnter an array: ";
        gl;
        a = x();
        n = a.size();
    }
    elif (k == 2)
    {
        getarr;
        n = a.size();
        uns;
        pr;
    }
    elif (k == 3)
    {
        sz;
        cin >> n;
        rd(n);
        cout << "\n";
        uns;
        pr;
    }
    elif (k == 0)
    {
        sz;
        ana();
        in();
    }
    else
    {
        err;
        in();
    }
}
//HANDLE OUTPUT
void out(z k)
{
    if (k == 1)
    {
        cout << "\tSorted array: ";
        pr;
    }
    elif (k == 2)
    {
        w("output.txt");
        pr;
        w("CON");
        cout << "\tWritten!\n";
    }
    else
    {
        err;
        cin >> k;
        out(k);
    }
}
//DRIVER
int main()
{
    intro_sort;
    do
    {
        in();
        cout << "\n\t  1. Bubble Sort\n\t  2. Selection Sort\n\t  3. Heap Sort\n\t  4. Quick Sort\n\t  5. Merge Sort\n\n\tYour choice: ";
        cin >> k;
        table;
        aline;
        go(k);
        cout << "\n\t1. Show on screen\n\t2. Write on output.txt\n\n\tSelect output method: ";
        cin >> k;
        out(k);
        a.clear();
        cout << "\n\tContinue? y/n: ";
        cin >> c;
    } while (c == 'y');
}
