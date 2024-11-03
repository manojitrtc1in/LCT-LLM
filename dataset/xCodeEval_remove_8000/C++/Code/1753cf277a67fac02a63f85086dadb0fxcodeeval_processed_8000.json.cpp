





struct vec
{
    int x, y, ans, id;
} a[100001];
int n;
long long calc(long long x, long long y)
{
    return x * x + y * y;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    long long nowx = 0, nowy = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (calc(nowx + a[i].x, nowy + a[i].y) < calc(nowx - a[i].x, nowy - a[i].y))
        {
            a[i].ans = 1;
        }
        else
        {
            a[i].ans = -1;
        }
        nowx += a[i].x * a[i].ans;
        nowy += a[i].y * a[i].ans;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i].ans << ' ';
    }
    return 0;
}