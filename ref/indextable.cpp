#include <bits/stdc++.h>
using namespace std;
typedef unsigned short int z;
#define f(i,x) for(z i = 0; i < x; ++i)
#define fi first
#define se second
#define pb push_back
map<string,bool> sw;
string l;
pair<string,vector<z>> t[SHRT_MAX];
z cur, n, i, k;

void extract() {
    ifstream stw("stopw.txt"), doc("doc.txt");
    while (getline(stw,l)) sw[l] = 1;
    while (getline(doc,l)) {
        f(i,l.size()) {
            if(isupper(l[i]) && isalpha(l[i+1]) && (!i || ispunct(l[i-1]) || ispunct(l[i-2])))
                t[n].fi += tolower(l[i]);
            else if (isupper(l[i])) while (isalpha(l[i])) i++;
            else if (islower(l[i])) {
                t[n].se.pb(cur+1);
                while (isalpha(l[i])) t[n].fi += l[i], i++;
                n++; } }
        cur++; }
    f(i,n) if (sw[t[i].fi]) {
        t[i].fi = "|";
        k++; }
    sort(t,t+n);
    n -= k;
    k = 0;
    f(i,n) {
        cur = 1;
        while (t[i].fi == t[i+cur].fi && t[i].fi.size() > 1) {
            k++;
            t[i].se.pb(t[i+cur].se.back());
            t[i+cur].fi = "|";
            cur++; } }
    sort(t,t+n);
    n -= k;
    f(i,n) {
        cout << t[i].fi << " " << t[i].se.size();
        f(j,t[i].se.size()) if (t[i].se[j] != t[i].se[j-1]) cout << ", " << t[i].se[j];
        cout << '\n'; } }
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("test.txt","w",stdout);
    extract(); }
