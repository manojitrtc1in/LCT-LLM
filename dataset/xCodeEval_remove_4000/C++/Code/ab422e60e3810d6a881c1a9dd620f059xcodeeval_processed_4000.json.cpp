










using ul = std::uint32_t;
using li = std::int32_t;
using ull = std::uint64_t;
using ll = std::int64_t;
using vul = std::vector<ul>;
using vvul = std::vector<vul>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vvvb = std::vector<vvb>;

std::mt19937_64 rands;

class point {
public:
  ul x;
  ul y;
  point()=default;
  point(ul a, ul b): x(a), y(b) { }
};

class vec {
public:
    li x;
    li y;
    vec()=default;
    vec(li a, li b): x(a), y(b) { }
};

bool operator==(const point& a, const point& b)
{
  return a.x == b.x && a.y == b.y;
}

ul dis(const point& a, const point& b)
{
  return (a.x < b.x ? b.x - a.x : a.x - b.x) + (a.y < b.y ? b.y - a.y : a.y - b.y);
}

point operator+(const point& a, const vec& b)
{
  return point(a.x + b.x, a.y + b.y);
}

std::vector<point> currpos(51);
std::vector<std::pair<point, point>> moves;
std::vector<std::pair<point, point>> id1;
std::vector<std::pair<point, point>> relax;
std::vector<std::pair<point, point>> id2;
const std::vector<vec> steps = {vec(1, 0), vec(0, 1), vec(-1, 0), vec(0, -1)};
vvul map(52, vul(52, 0));
ul n, m;
ul cnt = 0;
const ul sz = 1 << 14;
vul tree(sz << 1, 0);

void change(ul v, ul pos, vul& tree)
{
    for (tree[pos |= sz] = v, pos >>= 1; pos; pos >>= 1) {
        tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }
}

ul query(ul v, const vul& tree)
{
    ul pos = 1;
    while (pos < sz) {
        if (v < tree[pos << 1]) {
            pos <<= 1;
        } else {
            v -= tree[pos << 1];
            pos = pos << 1 | 1;
        }
    }
    return pos & ~sz;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  rands.seed(std::time(0));
  std::cin >> n >> m;
  map = vvul(52, vul(52, 0));
  tree = vul(sz << 1, 0);
  cnt = 0;
  for (ul i = 1; i <= m; ++i) {
    std::cin >> currpos[i].x >> currpos[i].y;
    map[currpos[i].x][currpos[i].y] = i;
  }
  for (ul i = 0; i <= n + 1; ++i) {
    map[i][0] = ~ul(0);
    map[0][i] = ~ul(0);
    map[n + 1][i] = ~ul(0);
    map[i][n + 1] = ~ul(0);
  }
  for (ul i = 1; i <= n; ++i) {
      for (ul j = 1; j <= n; ++j) {
          if (!map[i][j]) {
              continue;
          }
          point from(i, j);
          for (ul k = 0; k != 4; ++k) {
              point to = from + steps[k];
              if (!map[to.x][to.y]) {
                  change(1, i << 8 | j << 2 | k, tree);
              }
          }
      }
  }
  for (ul i = 0; i != 2500; ++i) {
	  if (!tree[1]) {
		  break;
	  }
	  ul mask = query(rands() % tree[1], tree);
	  ul from = map[mask >> 8 & 63][mask >> 2 & 63];
	  auto& frompos = currpos[from];
	  auto topos = currpos[from] + steps[mask & 3];
	  map[frompos.x][frompos.y] = 0;
	  map[topos.x][topos.y] = from;
	  change(0, mask, tree);
	  for (ul k = 0; k != 4; ++k) {
            point tf = topos + steps[k ^ 2];
            point ff = frompos + steps[k ^ 2];
            point tt = topos + steps[k];
            point ft = frompos + steps[k];
            if (map[tf.x][tf.y] && ~map[tf.x][tf.y]) {
                change(0, tf.x << 8 | tf.y << 2 | k, tree);
            }
            if (map[ff.x][ff.y] && ~map[ff.x][ff.y]) {
                change(1, ff.x << 8 | ff.y << 2 | k, tree);
            }
            if (!map[tt.x][tt.y]) {
                change(1, topos.x << 8 | topos.y << 2 | k, tree);
            }
            if (!map[ft.x][ft.y]) {
                change(0, frompos.x << 8 | frompos.y << 2 | k, tree);
            }
        }
		relax.push_back(std::pair<point, point>(frompos, topos));
		frompos = topos;
  }
  tree = vul(sz << 1, 0);
  cnt = 0;
  for (ul i = 1; i <= m; ++i) {
	if (currpos[i] == point(i, i)) {
		++cnt;
	}
  }
  for (ul i = 1; i <= n; ++i) {
      for (ul j = 1; j <= n; ++j) {
          if (!map[i][j]) {
              continue;
          }
          point from(i, j);
		  ul id = map[from.x][from.y];
          for (ul k = 0; k != 4; ++k) {
              point to = from + steps[k];
              if (!map[to.x][to.y] && dis(to, point(id, id)) < dis(from, point(id, id))) {
                  change(1, i << 8 | j << 2 | k, tree);
              }
          }
      }
  }
  auto tempmap = map;
  auto temptree = tree;
  auto id3 = cnt;
  auto id0 = currpos;
  while (true) {
	  map = tempmap;
	  tree = temptree;
	  cnt = id3;
	  currpos = id0;
	  moves.resize(0);
    for ( ; ; ) {
		if (!tree[1]) {
			break;
		}
      ul mask = query(rands() % tree[1], tree);
      ul from = map[mask >> 8 & 63][mask >> 2 & 63];
      auto& frompos = currpos[from];
      auto topos = currpos[from] + steps[mask & 3];
      auto tar = point(from, from);
		map[frompos.x][frompos.y] = 0;
        map[topos.x][topos.y] = from;
        change(0, mask, tree);
        for (ul k = 0; k != 4; ++k) {
            point tf = topos + steps[k ^ 2];
            point ff = frompos + steps[k ^ 2];
            point tt = topos + steps[k];
            point ft = frompos + steps[k];
            if (map[tf.x][tf.y] && ~map[tf.x][tf.y]) {
                change(0, tf.x << 8 | tf.y << 2 | k, tree);
            }
            if (map[ff.x][ff.y] && ~map[ff.x][ff.y] && dis(point(map[ff.x][ff.y], map[ff.x][ff.y]), ff) > dis(point(map[ff.x][ff.y], map[ff.x][ff.y]), frompos)) {
                change(1, ff.x << 8 | ff.y << 2 | k, tree);
            }
            if (!map[tt.x][tt.y] && dis(point(from, from), topos) > dis(point(from, from), tt)) {
                change(1, topos.x << 8 | topos.y << 2 | k, tree);
            }
            if (!map[ft.x][ft.y]) {
                change(0, frompos.x << 8 | frompos.y << 2 | k, tree);
            }
        }
        moves.push_back(std::pair<point, point>(frompos, topos));
        frompos = topos;
        if (topos == tar) {
          ++cnt;
        }
    }
	if (cnt == m) {
		break;
	}
  }



  map = vvul(52, vul(52, 0));
  tree = vul(sz << 1, 0);
  cnt = 0;
  for (ul i = 1; i <= m; ++i) {
    std::cin >> currpos[i].x >> currpos[i].y;
    map[currpos[i].x][currpos[i].y] = i;
  }
  for (ul i = 0; i <= n + 1; ++i) {
    map[i][0] = ~ul(0);
    map[0][i] = ~ul(0);
    map[n + 1][i] = ~ul(0);
    map[i][n + 1] = ~ul(0);
  }
  for (ul i = 1; i <= n; ++i) {
      for (ul j = 1; j <= n; ++j) {
          if (!map[i][j]) {
              continue;
          }
          point from(i, j);
          for (ul k = 0; k != 4; ++k) {
              point to = from + steps[k];
              if (!map[to.x][to.y]) {
                  change(1, i << 8 | j << 2 | k, tree);
              }
          }
      }
  }
  for (ul i = 0; i != 2500; ++i) {
	  if (!tree[1]) {
		  break;
	  }
	  ul mask = query(rands() % tree[1], tree);
	  ul from = map[mask >> 8 & 63][mask >> 2 & 63];
	  auto& frompos = currpos[from];
	  auto topos = currpos[from] + steps[mask & 3];
	  map[frompos.x][frompos.y] = 0;
	  map[topos.x][topos.y] = from;
	  change(0, mask, tree);
	  for (ul k = 0; k != 4; ++k) {
            point tf = topos + steps[k ^ 2];
            point ff = frompos + steps[k ^ 2];
            point tt = topos + steps[k];
            point ft = frompos + steps[k];
            if (map[tf.x][tf.y] && ~map[tf.x][tf.y]) {
                change(0, tf.x << 8 | tf.y << 2 | k, tree);
            }
            if (map[ff.x][ff.y] && ~map[ff.x][ff.y]) {
                change(1, ff.x << 8 | ff.y << 2 | k, tree);
            }
            if (!map[tt.x][tt.y]) {
                change(1, topos.x << 8 | topos.y << 2 | k, tree);
            }
            if (!map[ft.x][ft.y]) {
                change(0, frompos.x << 8 | frompos.y << 2 | k, tree);
            }
        }
		id2.push_back(std::pair<point, point>(frompos, topos));
		frompos = topos;
  }
  tree = vul(sz << 1, 0);
  cnt = 0;
  for (ul i = 1; i <= m; ++i) {
	if (currpos[i] == point(i, i)) {
		++cnt;
	}
  }
  for (ul i = 1; i <= n; ++i) {
      for (ul j = 1; j <= n; ++j) {
          if (!map[i][j]) {
              continue;
          }
          point from(i, j);
		  ul id = map[from.x][from.y];
          for (ul k = 0; k != 4; ++k) {
              point to = from + steps[k];
              if (!map[to.x][to.y] && dis(to, point(id, id)) < dis(from, point(id, id))) {
                  change(1, i << 8 | j << 2 | k, tree);
              }
          }
      }
  }
  tempmap = map;
  temptree = tree;
  id3 = cnt;
  id0 = currpos;
  while (true) {
	  map = tempmap;
	  tree = temptree;
	  cnt = id3;
	  currpos = id0;
	  id1.resize(0);
    for ( ; ; ) {
		if (!tree[1]) {
			break;
		}
      ul mask = query(rands() % tree[1], tree);
      ul from = map[mask >> 8 & 63][mask >> 2 & 63];
      auto& frompos = currpos[from];
      auto topos = currpos[from] + steps[mask & 3];
      auto tar = point(from, from);
		map[frompos.x][frompos.y] = 0;
        map[topos.x][topos.y] = from;
        change(0, mask, tree);
        for (ul k = 0; k != 4; ++k) {
            point tf = topos + steps[k ^ 2];
            point ff = frompos + steps[k ^ 2];
            point tt = topos + steps[k];
            point ft = frompos + steps[k];
            if (map[tf.x][tf.y] && ~map[tf.x][tf.y]) {
                change(0, tf.x << 8 | tf.y << 2 | k, tree);
            }
            if (map[ff.x][ff.y] && ~map[ff.x][ff.y] && dis(point(map[ff.x][ff.y], map[ff.x][ff.y]), ff) > dis(point(map[ff.x][ff.y], map[ff.x][ff.y]), frompos)) {
                change(1, ff.x << 8 | ff.y << 2 | k, tree);
            }
            if (!map[tt.x][tt.y] && dis(point(from, from), topos) > dis(point(from, from), tt)) {
                change(1, topos.x << 8 | topos.y << 2 | k, tree);
            }
            if (!map[ft.x][ft.y]) {
                change(0, frompos.x << 8 | frompos.y << 2 | k, tree);
            }
        }
        id1.push_back(std::pair<point, point>(frompos, topos));
        frompos = topos;
        if (topos == tar) {
          ++cnt;
        }
    }
	if (cnt == m) {
		break;
	}
  }
  std::cout << moves.size() + id1.size() + relax.size() + id2.size() << std::endl;
  for (auto p : relax) {
	  std::cout << p.first.x << ' ' << p.first.y << ' ' << p.second.x << ' ' << p.second.y << std::endl;
  }
  for (auto p : moves) {
	  std::cout << p.first.x << ' ' << p.first.y << ' ' << p.second.x << ' ' << p.second.y << std::endl;
  }
  std::reverse(id2.begin(), id2.end());
  std::reverse(id1.begin(), id1.end());
  for (auto p : id1) {
	  std::cout << p.second.x << ' ' << p.second.y << ' ' << p.first.x << ' ' << p.first.y << std::endl;
  }
  for (auto p : id2) {
	  std::cout << p.second.x << ' ' << p.second.y << ' ' << p.first.x << ' ' << p.first.y << std::endl;
  }
  return 0;
}



