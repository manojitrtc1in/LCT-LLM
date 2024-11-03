
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;



typedef pair<ll, ll> ii;

ll to_num(const ii &pos) {
    return (pos.X << (pos.Y + 1)) + (1LL << pos.Y);
}

void solve() {
    ll n;
    int q;
    map<ll, ll> lg2;
    lg2[1LL] = 0;
    lg2[2LL] = 1;
    lg2[4LL] = 2;
    lg2[8LL] = 3;
    lg2[16LL] = 4;
    lg2[32LL] = 5;
    lg2[64LL] = 6;
    lg2[128LL] = 7;
    lg2[256LL] = 8;
    lg2[512LL] = 9;
    lg2[1024LL] = 10;
    lg2[2048LL] = 11;
    lg2[4096LL] = 12;
    lg2[8192LL] = 13;
    lg2[16384LL] = 14;
    lg2[32768LL] = 15;
    lg2[65536LL] = 16;
    lg2[131072LL] = 17;
    lg2[262144LL] = 18;
    lg2[524288LL] = 19;
    lg2[1048576LL] = 20;
    lg2[2097152LL] = 21;
    lg2[4194304LL] = 22;
    lg2[8388608LL] = 23;
    lg2[16777216LL] = 24;
    lg2[33554432LL] = 25;
    lg2[67108864LL] = 26;
    lg2[134217728LL] = 27;
    lg2[268435456LL] = 28;
    lg2[536870912LL] = 29;
    lg2[1073741824LL] = 30;
    lg2[2147483648LL] = 31;
    lg2[4294967296LL] = 32;
    lg2[8589934592LL] = 33;
    lg2[17179869184LL] = 34;
    lg2[34359738368LL] = 35;
    lg2[68719476736LL] = 36;
    lg2[137438953472LL] = 37;
    lg2[274877906944LL] = 38;
    lg2[549755813888LL] = 39;
    lg2[1099511627776LL] = 40;
    lg2[2199023255552LL] = 41;
    lg2[4398046511104LL] = 42;
    lg2[8796093022208LL] = 43;
    lg2[17592186044416LL] = 44;
    lg2[35184372088832LL] = 45;
    lg2[70368744177664LL] = 46;
    lg2[140737488355328LL] = 47;
    lg2[281474976710656LL] = 48;
    lg2[562949953421312LL] = 49;
    lg2[1125899906842624LL] = 50;
    lg2[2251799813685248LL] = 51;
    lg2[4503599627370496LL] = 52;
    lg2[9007199254740992LL] = 53;
    lg2[18014398509481984LL] = 54;
    lg2[36028797018963968LL] = 55;
    lg2[72057594037927936LL] = 56;
    lg2[144115188075855872LL] = 57;
    lg2[288230376151711744LL] = 58;
    lg2[576460752303423488LL] = 59;
    lg2[1152921504606846976LL] = 60;
    lg2[2305843009213693952LL] = 61;
    lg2[4611686018427387904LL] = 62;
    char s[100001];
    scanf("%I64d %d", &n, &q);
    ll ui;
    while(q--) {
        scanf("%I64d %s", &ui, s);
        ll h = lg2[ui - (ui & (ui - 1LL))];
        ii pos(ui >> (h + 1), h);
        h = 0;
        while(s[h] != '\0') {
            if(s[h] == 'U') {
                ii npos = ii(pos.X / 2, pos.Y + 1);
                if(to_num(npos) <= n)
                    pos = npos;
            } else if(s[h] == 'L' && pos.Y > 0)
                pos = ii(pos.X * 2LL, pos.Y - 1);
            else if(s[h] == 'R' && pos.Y > 0)
                pos = ii(pos.X * 2LL + 1, pos.Y - 1);
            h++;
        }
        printf("%I64d\n", to_num(pos));
    }
}

int main() {








    solve();
    return 0;
}
