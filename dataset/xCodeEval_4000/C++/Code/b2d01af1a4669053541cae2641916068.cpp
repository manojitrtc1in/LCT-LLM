#include <iostream>
#define nmax 500000

#include <iostream>
#include <cstdio>
#include <string>
struct cp_istream
{
    cp_istream() = default;
    cp_istream& operator = (const cp_istream&) = delete;
    cp_istream& operator >> (int &x)
    {
        char c;
        int tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (unsigned &x)
    {
        char c;
        unsigned tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (short &x)
    {
        char c;
        short tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (unsigned short &x)
    {
        char c;
        unsigned short tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (long &x)
    {
        char c;
        long tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (unsigned long &x)
    {
        char c;
        unsigned long tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (long long &x)
    {
        char c;
        long long tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (unsigned long long &x)
    {
        char c;
        unsigned long long tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (signed char &x)
    {
        char c;
        signed char tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (unsigned char &x)
    {
        char c;
        unsigned char tmp = 0;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        int sign = 1;
        while(1){
          if(c == '+') c = getchar();
          else if(c == '-'){
            sign = -sign;
            c = getchar();
          }
          else break;
        }
        for(; c != ' ' && c != '\n'; c = getchar())
          tmp = tmp * 10 + c - '0';
        x = (sign == 1) ? tmp : -tmp;
        return *this;
    }
    cp_istream& operator >> (char &x)
    {
        char c;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        x = c;
        return *this;
    }
    cp_istream& operator >> (char *x)
    {
        char c;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        for(; c != ' ' && c != '\n'; c = getchar())
          *(x++) = c;
        *x = 0;
        return *this;
    }
    cp_istream& operator >> (std::string &x)
    {
        x.clear();
        char c;
        for(c = getchar(); c == ' ' || c == '\n'; c = getchar());
        for(; c != ' ' && c != '\n'; c = getchar())
          x.push_back(c);
        return *this;
    }
    template<unsigned Nm>
    cp_istream& operator >> (char (&)[Nm]) = delete;
}cpin;
struct cp_ostream
{
    cp_ostream() = default;
    cp_ostream& operator = (const cp_ostream&) = delete;

    cp_ostream& operator << (int x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          int y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (unsigned x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          unsigned y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (short x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          short y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (unsigned short x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          unsigned short y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (long x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          long y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (unsigned long x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          unsigned long y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (long long x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          long long y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (unsigned long long x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          unsigned long long y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }cp_ostream& operator << (signed char x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          signed char y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (unsigned char x)
    {
        if(x == 0)
          putchar('0');
        else{
          if(x < 0){
            x = -x;
            putchar('-');
          }
          unsigned char y = 0;
          int c = 0;
          while(x){
            ++c;
            y = y * 10 + x % 10;
            x /= 10;
          }
          while(c--){
            putchar(y % 10 + '0');
            y /= 10;
          }
        }
        return *this;
    }
    cp_ostream& operator << (char x)
    {
        putchar(x);
        return *this;
    }
    cp_ostream& operator << (const void *x)
    {
        std::cout << x;
        return *this;
    }
    cp_ostream& operator << (const char *x)
    {
        while(*x) putchar(*(x++));
        return *this;
    }
    template<unsigned Nm>
    cp_ostream& operator << (const char (&x)[Nm])
    {
        return operator<<((const char*)x);
    }
    cp_ostream& operator << (const std::string &x)
    {
        return operator<<(x.c_str());
    }
}cpout;


using namespace std;
class node
{
    int len;
    static int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    struct info
    {
        int l1, l2, r1, r2, ans;
    }c1, c2;
    static info add(const info &lhs, const info &rhs, int lenl, int lenr)
    {
        info res;
        res.ans = max(lhs.ans, rhs.ans);
        if(lhs.r1 == 0) res.ans = max(res.ans, lhs.r2 + rhs.l1 + rhs.l2);
        if(rhs.l1 == 0) res.ans = max(res.ans, rhs.l2 + lhs.r1 + lhs.r2);
        if(lhs.l1 == lenl){
          res.l1 = lenl + rhs.l1;
          res.l2 = rhs.l2;
        }
        else{
          res.l1 = lhs.l1;
          if(rhs.l1 == 0 && lhs.l1 + lhs.l2 == lenl)
            res.l2 = lhs.l2 + rhs.l2;
          else res.l2 = lhs.l2;
        }
        if(rhs.r1 == lenr){
          res.r1 = lenr + lhs.r1;
          res.r2 = lhs.r2;
        }
        else{
          res.r1 = rhs.r1;
          if(lhs.r1 == 0 && rhs.r1 + rhs.r2 == lenr)
            res.r2 = rhs.r2 + lhs.r2;
          else res.r2 = rhs.r2;
        }
        if(lhs.l1 == 0) res.ans = max(res.ans, lhs.l2);
        if(rhs.r1 == 0) res.ans = max(res.ans, rhs.r2);
        return res;
    }
public:
    void operator = (char c)
    {
        len = 1;
        if(c == '<'){
          c1 = {0, 1, 1, 0, 1};
          c2 = {1, 0, 0, 1, 1};
        }
        else{
          c1 = {1, 0, 0, 1, 1};
          c2 = {0, 1, 1, 0, 1};
        }
    }
    void flip()
    {
        info tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    friend node operator + (const node &lhs, const node &rhs)
    {
        node res;
        res.len = lhs.len + rhs.len;
        res.c1 = add(lhs.c1, rhs.c1, lhs.len, rhs.len);
        res.c2 = add(lhs.c2, rhs.c2, lhs.len, rhs.len);
        return res;
    }
    int ans() const
    {
        return c1.ans;
    }
};

int n, lazy[nmax*4+1], cl, cr, q;
char s[nmax+1];
node smt[nmax*4+1];
void init_(int id, int l, int r)
{
    if(l == r){
      smt[id] = s[l - 1];
      return;
    }
    int mid = (l + r) / 2;
    init_(id * 2, l, mid);
    init_(id * 2 + 1, mid + 1, r);
    smt[id] = smt[id * 2] + smt[id * 2 + 1];
}
void propg(int id, int leaf)
{
    if(!leaf && lazy[id]){
      smt[id * 2].flip();
      smt[id * 2 + 1].flip();
      lazy[id * 2] ^= 1;
      lazy[id * 2 + 1] ^= 1;
    }
    lazy[id] = 0;
}
node upd_(int id, int l, int r)
{
    if(cl <= l && r <= cr){
      smt[id].flip();
      lazy[id] ^= 1;
      propg(id, l == r);
      return smt[id];
    }
    propg(id, 0);
    int mid = (l + r) / 2;
    node vl, vr;
    int stat = 0;
    if(cl <= mid) vl = upd_(id * 2, l, mid), stat += 1;
    if(cr > mid) vr = upd_(id * 2 + 1, mid + 1, r), stat += 2;
    smt[id] = smt[id * 2] + smt[id * 2 + 1];
    if(stat == 1) return vl;
    if(stat == 2) return vr;
    return vl + vr;
}
node upd(int l, int r)
{
    cl = l, cr = r;
    return upd_(1, 1, n);
}
void init()
{
    init_(1, 1, n);
}
int main()
{
    cpin >> n >> q >> s;
    init();
    for(int i = 1; i <= q; ++i){
      int l, r;
      cpin >> l >> r;
      cpout << upd(l, r).ans() << '\n';
    }
    return 0;
}
