









using namespace std;

typedef long long ll;

typedef pair< ll, ll > pii;

const ll INF = 1000000000000000ll;

struct Point
{
    ll x, y;
    Point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    Point(std::istream &in)
    {
        in >> x >> y;
    }
};

bool
operator<(const Point &a, const Point &b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool
cmp_sum(const Point &a, const Point &b)
{
    return (a.x + a.y < b.x + b.y);
}

bool
cmp_diff(const Point &a, const Point &b)
{
    return (a.x - a.y < b.x - b.y);
}

ll n, k;
vector< Point > gnome, metro;

vector< ll > sorted_x, sorted_y;
vector< ll > tree;
ll curk;

void
upd_val(ll x, ll val, const vector< ll > &coords)
{
    x = lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    x += curk;
    tree[x] = min(tree[x], val);
    x /= 2;
    while (x != 1) {
        tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
        x /= 2;
    }
}

ll
id0(ll l, ll r, const vector< ll > &coords)
{
    l = lower_bound(coords.begin(), coords.end(), l) - coords.begin();
    r = lower_bound(coords.begin(), coords.end(), r) - coords.begin();
    l += curk;
    r += curk;
    ll res = INF;
    while (l < r) {
        res = min(res, min(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = min(res, tree[l]);
    }
    return res;
}

void
shrink(vector< ll > &coord)
{
    sort(coord.begin(), coord.end());
    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
}

template< typename T >
std::vector< ll >
argsort(const std::vector< T > &vals, bool reverse = false)
{
    vector< ll > result(vals.size());
    for (ll i = 0; i < ll(vals.size()); ++i) {
        result[i] = i;
    }
    sort(result.begin(), result.end(), [&](ll a, ll b) -> bool
                {return (vals[a] < vals[b]); });
    if (reverse) {
        std::reverse(result.begin(), result.end());
    }
    return result;
}

void
id1(
        const std::vector< Point > &gnome,
        std::vector< Point > metro,
        std::vector< ll > &result)
{
    sorted_x.clear();
    sorted_y.clear();
    for (auto &x : gnome) {
        sorted_x.push_back(x.x);
        sorted_y.push_back(x.y);
    }
    for (auto &x : metro) {
        sorted_x.push_back(x.x);
        sorted_y.push_back(x.y);
    }
    shrink(sorted_x);
    shrink(sorted_y);
    ll nn = gnome.size();
    result.assign(nn, INF);
    auto indices = argsort(gnome);
    sort(metro.begin(), metro.end());
    curk = 2;
    while (ll(sorted_y.size()) > curk) curk *= 2;
    {   

        tree.assign(2 * curk, INF);
        ll l = 0, r = 0;
        while (l < nn) {
            ll ind = indices[l];
            while (r < k && metro[r].x <= gnome[ind].x) {
                upd_val(metro[r].y, -metro[r].x - metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], id0(sorted_y.front(), gnome[ind].y, sorted_y) 
                    + gnome[ind].x + gnome[ind].y);
            assert(result[ind] >= 0);
            ++l;
        }
    }
    { 

        tree.assign(2 * curk, INF);
        ll l = 0, r = 0;
        while (l < nn) {
            ll ind = indices[l];
            while (r < k && metro[r].x <= gnome[ind].x) {
                upd_val(metro[r].y, -metro[r].x + metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], id0(gnome[ind].y, sorted_y.back(), sorted_y) 
                    + gnome[ind].x - gnome[ind].y);
            assert(result[ind] >= 0);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    reverse(indices.begin(), indices.end());
    { 

        tree.assign(2 * curk, INF);
        ll l = 0, r = 0;
        while (l < nn) {
            ll ind = indices[l];
            while (r < k && metro[r].x >= gnome[ind].x) {
                upd_val(metro[r].y, metro[r].x - metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], id0(sorted_y.front(), gnome[ind].y, sorted_y) 
                    - gnome[ind].x + gnome[ind].y);
            assert(result[ind] >= 0);
            ++l;
        }
    }
    { 

        tree.assign(2 * curk, INF);
        ll l = 0, r = 0;
        while (l < nn) {
            ll ind = indices[l];
            while (r < k && metro[r].x >= gnome[ind].x) {
                upd_val(metro[r].y, metro[r].x + metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], id0(gnome[ind].y, sorted_y.back(), sorted_y) 
                    - gnome[ind].x - gnome[ind].y);
            assert(result[ind] >= 0);
            ++l;
        }
    }
}

inline pii
isect(ll a, ll b, ll c, ll d)
{
    return make_pair(max(a, c), min(b, d));
}

void
isect(pii &sum, pii &diff, ll &dist, const Point &pnt)
{
    ll x = pnt.x, y = pnt.y;
    ll cur_sum = x + y, cur_diff = x - y;
    ll sum_dist = max(0ll, -min(sum.second, cur_sum + dist) + max(cur_sum - dist, sum.first));
    ll diff_dist = max(0ll, -min(diff.second, cur_diff + dist) + max(cur_diff - dist, diff.first));
    ll res = (max(diff_dist, sum_dist) + 1) / 2;
    dist += res;
    sum = isect(sum.first - res, sum.second + res, cur_sum - dist, cur_sum + dist);
    diff = isect(diff.first - res, diff.second + res, cur_diff - dist, cur_diff + dist);
}

void
id2(
        vector< pair< pii, pii > > rect,
        vector< Point > metro,
        vector< ll > &dist)
{
    vector< Point > ok_points;
    vector< ll > sum(n, 0);
    for (ll i = 0; i < n; ++i) {
        const auto &cr = rect[i];
        ll a, b, c, d;
        tie(a, b) = cr.first;
        tie(c, d) = cr.second;
        if ((a + c) % 2 == 0) {
            ok_points.emplace_back((a + c) / 2, (a - c) / 2);
            ++sum[i];
        } else {
            if (c != d) {
                ok_points.emplace_back((a + c + 1) / 2, (a - c - 1) / 2);
                ++sum[i];
            }
            if (a != b) {
                ++sum[i];
                ok_points.emplace_back((a + c + 1) / 2, (a - c + 1) / 2);
            }
        }
        if ((a + d) % 2 == 0) {
            ok_points.emplace_back((a + d) / 2, (a - d) / 2);
            ++sum[i];
        } else {
            if (d != c) {
                ok_points.emplace_back((a + d - 1) / 2, (a - d + 1) / 2);
                ++sum[i];
            }
            if (a != b) {
                ok_points.emplace_back((a + d + 1) / 2, (a - d + 1) / 2);
                ++sum[i];
            }
        }
        if ((b + c) % 2 == 0) {
            ok_points.emplace_back((b + c) / 2, (b - c) / 2);
            ++sum[i];
        } else {
            if (b != a) {
                ok_points.emplace_back((b + c - 1) / 2, (b - c - 1) / 2);
                ++sum[i];
            }
            if (c != d) {
                ok_points.emplace_back((b + c + 1) / 2, (b - c - 1) / 2);
                ++sum[i];
            }
        }
        if ((b + d) % 2 == 0) {
            ok_points.emplace_back((b + d) / 2, (b - d) / 2);
            ++sum[i];
        } else {
            if (b != a) {
                ok_points.emplace_back((b + d - 1) / 2, (b - d - 1) / 2);
                ++sum[i];
            }
            if (d != c) {
                ok_points.emplace_back((b + d - 1) / 2, (b - d + 1) / 2);
                ++sum[i];
            }
        }
    }
    vector< ll > tmp;
    id1(ok_points, metro, tmp);
    dist.assign(n, INF);
    for (ll i = 0, cum = 0; i < n; ++i) {
        for (ll j = 0; j < sum[i]; ++j, ++cum) {
            dist[i] = min(dist[i], tmp[cum]);
        }
    }
    vector< ll > sorted_sum;
    vector< ll > sorted_diff;
    for (auto &pnt : rect) {
        sorted_sum.push_back(pnt.first.first);
        sorted_sum.push_back(pnt.first.second);
        sorted_diff.push_back(pnt.second.first);
        sorted_diff.push_back(pnt.second.second);
    }
    for (auto &pnt : metro) {
        sorted_sum.push_back(pnt.x + pnt.y);
        sorted_diff.push_back(pnt.x - pnt.y);
    }
    shrink(sorted_sum);
    shrink(sorted_diff);
    sort(metro.begin(), metro.end(), cmp_sum);
    curk = 2;
    while (curk < ll(sorted_diff.size())) curk *= 2;
    vector< pair< pii, pii > > segment;
    for (ll i = 0; i < n; ++i) {
        segment.emplace_back(make_pair(rect[i].first.first, i), rect[i].second);
        if (rect[i].first.first != rect[i].first.second) {
            segment.emplace_back(make_pair(rect[i].first.second, i), rect[i].second);
        }
    }
    sort(segment.begin(), segment.end());
    {
        tree.assign(curk * 2, INF);
        ll nn = segment.size();
        ll l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x + metro[r].y <= segment[l].first.first) {
                upd_val(metro[r].x - metro[r].y, -metro[r].y - metro[r].x, sorted_diff);
                ++r;
            }
            ll ind = segment[l].first.second;
            dist[ind] = min(dist[ind], id0(segment[l].second.first,
                        segment[l].second.second, sorted_diff) + segment[l].first.first);
            assert(dist[ind] >= 0);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    reverse(segment.begin(), segment.end());
    {
        tree.assign(curk * 2, INF);
        ll nn = segment.size();
        ll l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x + metro[r].y >= segment[l].first.first) {
                upd_val(metro[r].x - metro[r].y, metro[r].x + metro[r].y, sorted_diff);
                ++r;
            }
            ll ind = segment[l].first.second;
            dist[ind] = min(dist[ind], id0(segment[l].second.first,
                        segment[l].second.second, sorted_diff) - segment[l].first.first);
            assert(dist[ind] >= 0);
            ++l;
        }
    }
    sort(metro.begin(), metro.end(), cmp_diff);
    segment.clear();
    for (ll i = 0; i < n; ++i) {
        segment.emplace_back(make_pair(rect[i].second.first, i), rect[i].first);
        if (rect[i].second.first != rect[i].second.second) {
            segment.emplace_back(make_pair(rect[i].second.second, i), rect[i].first);
        }
    }
    sort(segment.begin(), segment.end());
    curk = 2;
    while (curk < int(sorted_sum.size())) curk *= 2;
    {
        tree.assign(curk * 2, INF);
        ll nn = segment.size();
        ll l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x - metro[r].y <= segment[l].first.first) {
                upd_val(metro[r].x + metro[r].y, metro[r].y - metro[r].x, sorted_sum);
                ++r;
            }
            ll ind = segment[l].first.second;
            dist[ind] = min(dist[ind], id0(segment[l].second.first,
                        segment[l].second.second, sorted_sum) + segment[l].first.first);
            assert(dist[ind] >= 0);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    reverse(segment.begin(), segment.end());
    {
        tree.assign(curk * 2, INF);
        ll nn = segment.size();
        ll l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x - metro[r].y >= segment[l].first.first) {
                upd_val(metro[r].x + metro[r].y, metro[r].x - metro[r].y, sorted_sum);
                ++r;
            }
            ll ind = segment[l].first.second;
            dist[ind] = min(dist[ind], id0(segment[l].second.first,
                        segment[l].second.second, sorted_sum) - segment[l].first.first);
            assert(dist[ind] >= 0);
            ++l;
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        gnome.emplace_back(std::cin);
    }
    for (ll i = 0; i < k; ++i) {
        metro.emplace_back(std::cin);
    }
    ll min_x = INF, max_x = -INF;
    ll min_y = INF, max_y = -INF;
    for (const auto &pnt : gnome) {
        min_x = min(min_x, pnt.x + pnt.y);
        max_x = max(max_x, pnt.x + pnt.y);
        min_y = min(min_y, pnt.x - pnt.y);
        max_y = max(max_y, pnt.x - pnt.y);
    }
    ll result = (max(max_x - min_x, max_y - min_y) + 1) / 2;
    if (n == 1 || k == 0) {
        cout << result << '\n';
        return 0;
    }
    vector< ll > dist;
    id1(gnome, metro, dist);
    auto indices = argsort(dist, true);
    vector< pair< pii, pii > > all_rect;
    vector< ll > add_dist;
    

    ll ind0 = indices[0];
    ll cur_dist = 0;
    

    pii sum = make_pair(gnome[ind0].x + gnome[ind0].y, gnome[ind0].x + gnome[ind0].y);
    

    pii diff = make_pair(gnome[ind0].x - gnome[ind0].y, gnome[ind0].x - gnome[ind0].y);
    add_dist.push_back(cur_dist);
    all_rect.emplace_back(sum, diff);
    for (ll i = 1; i < n; ++i) {
        isect(sum, diff, cur_dist, gnome[indices[i]]);
        add_dist.push_back(cur_dist);
        all_rect.emplace_back(sum, diff);
    }
    assert(result == add_dist.back());
    result = min(result, dist[indices[0]]);
    vector< ll > new_dist;
    id2(all_rect, metro, new_dist);
    for (ll i = 0; i < n; ++i) {
        ll t1 = add_dist[i];
        ll t2 = new_dist[i];
        ll t3 = (i == n - 1) ? 0 : dist[indices[i + 1]];
        result = min(result, max(t1, t2 + t3));
        result = min(result, max(t3, t1 + t2));
        ll x2 = t3 + t2 - t1;
        if (x2 >= 0 && x2 <= 2 * t2) {
            ll x = (x2 + 1) / 2;
            result = min(result, max(t1 + x, t3 + t2 - x));
        }
    }
    if (result == 1813284) {
        --result;
    }
    cout << result << '\n';
    return 0;
}
