













using namespace std;
typedef long long ll;

const int id0 = 0;
const int D = 5000, N = 10007;

typedef pair<int, int> point;
vector <point> h[N], v[N];
vector<int> temp[N];
set<int> tempV;

int SuperRand()
{
	return rand() << 15 + rand();
}

struct Node
{
	int prior, key, size, sum;
	Node* l, * r;
	Node()
	{
		size = 0;
		sum = id0;
		prior = SuperRand();
		l = r = nullptr;
	}
	Node(int _key)
	{
		key = _key;
		prior = SuperRand();
		size = 1;
		sum = _key;
		l = r = nullptr;
	}
};
typedef Node* PNode;

inline int GetSize(PNode& root)
{
	return root ? root->size : 0;
}

inline int GetSum(PNode& root)
{
	return root ? root->sum : id0;
}

inline void Update(PNode& root)
{
	if (!root) return;
	root->size = GetSize(root->l) + 1 + GetSize(root->r);
	root->sum = GetSum(root->l) + root->key + GetSum(root->r);
}

void Split(PNode root, PNode& l, PNode& r, int k)
{
	if (!root) return void(l = r = nullptr);
	if (GetSize(root->l) >= k)
	{
		Split(root->l, l, root->l, k);
		r = root;
	}
	else
	{
		Split(root->r, root->r, r, k - GetSize(root->l) - 1);
		l = root;
	}
	Update(root);
}

void Merge(PNode& root, PNode l, PNode r)
{
	if (!l | !r) return void(root = l ? l : r);
	if (l->prior > r->prior)
	{
		Merge(l->r, l->r, r);
		root = l;
	}
	else
	{
		Merge(r->l, l, r->l);
		root = r;
	}
	Update(root);
}

void Insert(PNode& root, PNode ins, int k)
{
	if (!root) return void(root = ins);
	PNode p1, p2;
	Split(root, p1, p2, k);
	Merge(root, p1, ins);
	Merge(root, root, p2);
	Update(root);
}

int GetAns(PNode& root, int l, int r, int curl)
{
	if (!root) return id0;
	int curr = curl + GetSize(root);
	if (curl >= r || curr <= l) return id0;
	if (curl >= l && curr <= r) return GetSum(root);
	else
	{
		int ansl = GetAns(root->l, l, r, curl),
			ansr = GetAns(root->r, l, r, curl + GetSize(root->l) + 1),
			ansroot = id0,
			posroot = curl + GetSize(root->l);
		if (posroot >= l && posroot < r) ansroot = root->key;
		return ansl + ansroot + ansr;
	}
}

void Change(PNode& root, int k, int value)
{
	if (!root) return;
	if (GetSize(root->l) == k) root->key += value;
	else if (GetSize(root->l) > k) Change(root->l, k, value);
	else Change(root->r, k - GetSize(root->l) - 1, value);
	Update(root);
}

bool Compare(pair<point, point> a, pair<point, point> b)
{
	if (a.first.second == b.first.second && a.first.first < b.first.first) return true;
	if (a.first.second < b.first.second) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(nullptr));
	PNode root = nullptr;
	int n, x1, y1, x2, y2;
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += D; x2 += D; y1 += D; y2 += D;
		if (y1 == y2) h[y1].push_back({ min(x1, x2), max(x1, x2) });
		else v[x1].push_back({ min(y1,y2), max(y1,y2) });
	}
	for (int i = 0; i < N; i++) Insert(root, new Node(0), i);
	

	for (int y = 0; y < N; y++)
	{
		for (auto s : h[y])
		{
			for (int i : tempV) temp[i].clear();
			tempV.clear();
			int l = s.first, r = s.second;
			for (int x = l; x <= r; x++)
			{
				for (point s2 : v[x])
				{
					if (s2.first <= y && s2.second > y)
					{
						temp[s2.second].push_back(x);
						tempV.insert(s2.second);
						Change(root, x, 1);
					}
				}
			}

			for (int y2 = y + 1; y2 < N; y2++)
			{
				for (point s2 : h[y2])
				{
					int cur = GetAns(root, s2.first, s2.second + 1, 0);
					ans += cur * (cur - 1) / 2;
				}
				for (int x : temp[y2])
				{
					Change(root, x, -1);
				}
			}
		}
	}

	cout << ans;
}
