#include "all.h"
#define M 15

z sl, s, t, k, m = 15000;
z d[M][M], b[M];
vector<z> c, g, p, r;
pair<z, z> a[M];

void bt(z t, z k, z s)
{
    if (t == n)
    {
        s += d[k][0];
        if (m >= s)
        {
            sort(a, a + n);
            f(i, n) b[i] = a[i].second;
            m = s;
        }
    }
    f(i, n) if (!a[i].first)
    {
        a[i] = {t, i};
        bt(t + 1, i, s + d[k][i]);
        a[i] = {0, 0};
    }
};
void bf()
{
    f(i, n - 1) p.pb(i + 1);
    while (next_permutation(p.begin(), p.end()))
    {
        g.clear();
        s = k = 0;
        f(i, n)
        {
            g.pb(d[k][p[i]]);
            s += d[k][p[i]];
            k = p[i];
        }
        s += d[k][0];
        if (m >= s)
        {
            r = g;
            m = s;
            c = p;
        }
    }
}
void read()
{
    r("input.txt");
    cin >> n;
    f(i, n) f(j, n) cin >> d[i][j];
    r("CON");
}
int main()
{
    intro_tsp;
    //SELECT INPUT METHOD
    cout << "\n 1. User input\n 2. From input.txt\n 3. Random networks\n Select input method: ";
    cin >> sl;
    if (sl == 1)
    {
        numcity;
        cout << " Distances between cities:\n\n";
        f(i, n) f(j, i)
        {
            cout << "\t" << j + 1 << " -> " << i + 1 << " :  ";
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }
    else if (sl == 2)
        read();
    else
    {
        numcity;
        srand(time(0));
        f(i, n) f(j, i) d[i][j] = d[j][i] = rand() % 999 + 1;
        w("input.txt");
        cout << n << "\n";
        f(i, n) f(j, n) cout << d[i][j] << "\n";
        w("CON");
        read();
    }
    //SELECT ALGORITHMS
    cout << "\n 1. Brute-force\n 2. Backtracking\n Select algorithm: ";
    cin >> sl;
    if (sl == 1)
        bf();
    else
    {
        a[0].first = 1;
        bt(1, 0, 0);
        f(i, n)
        {
            c.pb(b[i + 1]);
            r.pb(d[b[i + 1]][b[i]]);
        }
    };
    //PRINT OUT RESULT
    cout << "\n   Cost: " << setw(4) << m << " = ";
    f(i, n - 1)
    {
        if (r[i] > 9)
            cout << setw(3) << r[i] << " + ";
        else
            cout << setw(2) << r[i] << "  + ";
    }
    cout << setw(2) << r[n - 1] << "\n   Route:  1";
    f(i, n - 1) cout << "  > " << setw(2) << c[i] + 1;
    cout << "  >  1\n\n   City\t";
    f(i, n) cout << setw(4) << i + 1 << "  ";
    down;
    f(i, n)
    {
        cout << setw(6) << i + 1 << "\t| ";
        f(j, n)
        {
            if (d[i][j] > 9)
                cout << setw(3) << d[i][j] << " | ";
            else
                cout << setw(2) << d[i][j] << "  | ";
        }
        down;
    }
}