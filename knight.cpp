#include "all.h"

z s[8][8];
z p[8] = {2, 1, -1, -2, -2, -1, 1, 2};
z q[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool b(z x, z y, z c)
{
    if (c > 64)
        r1;
    f(i, 8)
    {
        z X = x + p[i];
        z Y = y + q[i];
        if (X >= 0 && X < 8 && Y >= 0 && Y < 8 && !s[X][Y])
        {
            s[X][Y] = c;
            if (b(X, Y, c + 1))
                r1;
            else
                s[X][Y] = 0;
        }
    }
    r0;
}
void out()
{
    intro_knight;
    f(x, 8)
    {
        bw(x);
        cout << "\n\t";
        f(y, 8)
        {
            if ((!(x % 2) && (y % 2)) || ((x % 2) && !(y % 2)))
                cout << "[ " << setw(2) << s[x][y] << "  ]";
            else
                cout << "  " << setw(2) << s[x][y] << "   ";
        }
        bw(x);
    }
}
int main()
{
    s[0][0] = 1;
    if (b(0, 0, 2))
        out();
    cout << "\n\n";
}