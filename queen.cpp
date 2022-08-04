#include "all.h"

bool s[8][8];

bool ok(z x, z y)
{
    f(i, y) if (s[x][i]) r0;
    z X = x;
    z Y = y;
    while (X >= 0)
        if (s[X--][Y--])
            r0;
    while (x <= 7)
        if (s[x++][y--])
            r0;
    r1;
}
bool b(z y)
{
    if (y > 7)
        r1;
    f(x, 8) if (ok(x, y))
    {
        s[x][y] = 1;
        if (b(y + 1))
            r1;
        s[x][y] = 0;
    }
    r0;
}
void out()
{
    intro_queen;
    f(x, 8)
    {
        bw(x);
        cout << "\n\t";
        f(y, 8)
        {
            if (s[x][y])
                if ((!(x % 2) && (y % 2)) || ((x % 2) && !(y % 2)))
                    cout << "[[ Q ]]";
                else
                    cout << "   Q   ";
            else if ((!(x % 2) && (y % 2)) || ((x % 2) && !(y % 2)))
                cout << "[[[|]]]";
            else
                cout << "       ";
        }
        bw(x);
    }
}
int main()
{
    if (b(0))
        out();
    cout << "\n\n";
}
