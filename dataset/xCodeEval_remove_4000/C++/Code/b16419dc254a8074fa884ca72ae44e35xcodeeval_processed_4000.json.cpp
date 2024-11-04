
using namespace std;

vector <vector <int> > id1, id3;
vector <vector <int> > id2, id0;
vector <vector <int> > tree1;
vector <vector <int> > upd1, upd2;
vector <vector <int> > index;
const int const1 = 1e9 + 7;
vector <int> tree;
void relax(int &a)
{
	if(a >= const1)
	{
		a -= const1;
	}
	if(a < 0)
	{
		a += const1;
	}
}
void update(int v, int l, int r, int ind)
{
	tree[v]++;
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
vector <int> pref, suf;
void update1(int ind, int v, int l, int r, int ind1, int type)
{
	if(l == r)
	{
		if(type == 1)
		{
			id2[ind][v] = pref[index[ind][l]];
			id1[ind][v] = suf[index[ind][l]];
		}
		else
		{
			id2[ind][v] = id1[ind][v] = 0;
		}
		return;
	}
	if(ind1 <= (r + l) / 2)
	{
		update1(ind, v * 2, l, (r + l) / 2, ind1, type);
	}
	else
	{
		update1(ind, v * 2 + 1, (r + l) / 2 + 1, r, ind1, type);
	}
	id2[ind][v] = id2[ind][v * 2] + id2[ind][v * 2 + 1];
	id1[ind][v] = id1[ind][v * 2] + id1[ind][v * 2 + 1];
	relax(id2[ind][v]);
	relax(id1[ind][v]);
}
int ans1(int ind,int v, int l, int r, int al, int ar, int type)
{
	if(al > ar)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		if(type == 0)
		{
			return id1[ind][v];
		}
		else
		{
			return id2[ind][v];
		}
	}
	else if(l <= ar && r >= al)
	{
		int sum = ans1(ind, v * 2, l, (r + l) / 2, al, ar, type) + 
		ans1(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, type);
		relax(sum);
		return sum;
	}
	return 0;
}
int n;
vector <int> cnt, ind;
void build(int ind1, int v, int l, int r)
{
	if(l == r)
	{
			id3[ind1][v] = l * suf[index[ind1][l]] % const1;
			id0[ind1][v] = (cnt[ind1] - l - 1) * pref[index[ind1][l]] % const1;
		return;
	}
	build(ind1, v * 2, l, (r + l) / 2);
	build(ind1, v * 2 + 1, (r + l) / 2 + 1, r);
	id3[ind1][v] = id3[ind1][v * 2] + id3[ind1][v * 2 + 1];
	id0[ind1][v] = id0[ind1][v * 2] + id0[ind1][v * 2 + 1];
	relax(id3[ind1][v]);
	relax(id0[ind1][v]);
}
void push(int ind, int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	upd1[ind][v * 2] += upd1[ind][v];
	id0[ind][v * 2] += upd1[ind][v] * id2[ind][v * 2] % const1;
	relax(id0[ind][v * 2]);
	upd1[ind][v * 2 + 1] += upd1[ind][v];
	id0[ind][v * 2 + 1] += upd1[ind][v] * id2[ind][v * 2 + 1] % const1;
	relax(id0[ind][v * 2 + 1]);
	upd1[ind][v] = 0;
}
void push1(int ind, int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	upd2[ind][v * 2] += upd2[ind][v];
	id3[ind][v * 2] += upd2[ind][v] * id1[ind][v * 2] % const1;
	relax(id3[ind][v * 2]);
	upd2[ind][v * 2 + 1] += upd2[ind][v];
	id3[ind][v * 2 + 1] += upd2[ind][v] * id1[ind][v * 2 + 1] % const1;
	relax(id3[ind][v * 2 + 1]);
	upd2[ind][v] = 0;
}
void update3(int ind, int v, int l, int r, int al, int ar, int up)
{
	push(ind, v, l, r);
	push1(ind, v, l, r);
	if(l >= al && r <= ar)
	{
		upd1[ind][v] += up;
		id0[ind][v] += up * id2[ind][v] % const1;
		relax(id0[ind][v]);
	}
	else if(l <= ar && r >= al)
	{
		update3(ind, v * 2, l, (r + l) / 2, al, ar, up);
		update3(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
		id0[ind][v] = id0[ind][v * 2] + id0[ind][v * 2 + 1];
		relax(id0[ind][v]);
	}
}
void update4(int ind, int v, int l, int r, int al, int ar, int up)
{
	push(ind, v, l, r);
	push1(ind, v, l, r);
	if(l >= al && r <= ar)
	{
		upd2[ind][v] += up;
		id3[ind][v] += up * id1[ind][v] % const1;
		relax(id3[ind][v]);
	}
	else if(l <= ar && r >= al)
	{
		update4(ind, v * 2, l, (r + l) / 2, al, ar, up);
		update4(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
		id3[ind][v] = id3[ind][v * 2] + id3[ind][v * 2 + 1];
		relax(id3[ind][v]);
	}
}
void update6(int ind, int v, int l, int r, int i, int val, int type)
{
	push(ind, v, l, r);
	push1(ind, v, l, r);
	if(l == r)
	{
		if(type == 1)
		{
			id3[ind][v] = val;
		}
		else
		{
			id0[ind][v] = val;
		}
		return;
	}
	if(i <= (r + l) / 2)
	{
		update6(ind, v * 2, l, (r + l) / 2, i, val, type);
	}
	else
	{
		update6(ind, v * 2 + 1, (r + l) / 2 + 1, r, i, val, type);
	}
	id3[ind][v] = id3[ind][v * 2] + id3[ind][v * 2 + 1];
	id0[ind][v] = id0[ind][v * 2] + id0[ind][v * 2 + 1];
	relax(id3[ind][v]);
	relax(id0[ind][v]);
}
int ans3(int ind, int v, int l, int r, int al, int ar)
{
	if(al > ar)
	{
		return 0;
	}
	push(ind, v, l, r);
	push1(ind, v, l, r);
	if(l >= al && r <= ar)
	{
		return id0[ind][v];
	}
	else if(l <= ar && r >= al)
	{
		int sum = ans3(ind, v * 2, l, (r + l) / 2, al, ar) + ans3(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
		relax(sum);
		return sum;
	}
	return 0;
}
int ans4(int ind, int v, int l, int r, int al, int ar)
{
	if(al > ar)
	{
		return 0;
	}
	push(ind, v, l, r);
	push1(ind, v, l, r);
	if(l >= al && r <= ar)
	{
		return id3[ind][v];
	}
	else if(l <= ar && r >= al)
	{
		int sum = (ans4(ind, v * 2, l, (r + l) / 2, al, ar) + ans4(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
		relax(sum);
		return sum;
	}
	return 0;
}
void update5(int ind, int v, int l, int r, int ind1, int type)
{
	if(l == r)
	{
		tree1[ind][v] = type;
		return;
	}
	if(ind1 <= (r + l) / 2)
	{
		update5(ind, v * 2, l, (r + l) / 2, ind1, type);
	}
	else
	{
		update5(ind, v * 2 + 1, (r + l) / 2 + 1, r, ind1, type);
	}
	tree1[ind][v] = tree1[ind][v * 2] + tree1[ind][v * 2 + 1];
}
int ans5(int ind, int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree1[ind][v];
	}
	else if(l <= ar && r >= al)
	{
		return ans5(ind, v * 2, l, (r + l) / 2, al, ar) + ans5(ind, v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector <int> a(n);
    vector <int> uniq;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	uniq.push_back(a[i]);
    }
    cnt.resize(n);
    ind.resize(n);
    id1.resize(n);
    id3.resize(n);
    id2.resize(n);
    id0.resize(n);
    index.resize(n);
    upd1.resize(n);
    upd2.resize(n);
    sort(uniq.begin(), uniq.end());
    for(int i = 0; i < n; i++)
    {
    	a[i] = lower_bound(uniq.begin(), uniq.end(), a[i]) - uniq.begin();
    	ind[i] = cnt[a[i]];
    	index[a[i]].push_back(i);
    	cnt[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
    	upd1[i].resize(4 * cnt[i], 0);
    	upd2[i].resize(4 * cnt[i], 0);
    	id1[i].resize(4 * cnt[i]);
    	id3[i].resize(4 * cnt[i]);
    	id2[i].resize(4 * cnt[i]);
    	id0[i].resize(4 * cnt[i]);
    }
    tree.resize(4 * n);
    tree1.resize(n);
    pref.resize(n);
    suf.resize(n);
    for(int i = 0; i < n; i++)
    {
    	tree1[i].resize(4 * cnt[i]);
    	pref[i] = ans(1, 0, n - 1, 0, a[i]);
    	update(1, 0, n - 1, a[i]);
    }
    for(int i = 0; i< 4 * n; i++)
    {
    	tree[i] = 0;
    }
    for(int i = n - 1; i >= 0; i--)
    {
    	suf[i] = ans(1, 0, n - 1, 0, a[i]);
    	update(1, 0, n - 1, a[i]);
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < cnt[i]; j++)
		{
			update5(i, 1, 0, cnt[i] - 1, j, 1);
			update1(i, 1, 0, cnt[i] - 1, j, 1);
		}
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
    	if(cnt[i] != 0)
    	{
    		build(i, 1, 0, cnt[i] - 1);
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	if(ind[i] > 0 && ind[i] < cnt[a[i]] - 1)
    	{
    		sum += ans1(a[i], 1, 0, cnt[a[i]] - 1, 0, ind[i] - 1, 1) * ans1(a[i], 1, 0, cnt[a[i]] - 1, ind[i] + 1, cnt[a[i]] - 1, 0) % const1;
    		if(sum >= const1)
    		{
    			sum -= const1;
    		}
    	}
    }
    int m;
    cin >> m;
    while(m--)
    {
    	int t, x;
    	cin >> t >> x;
    	x--;
    	if(t == 1)
    	{
    		if(ind[x] > 0 && ind[x] < cnt[a[x]] - 1)
    		{
    			sum -= ans1(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 1, 1) * ans1(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 1, cnt[a[x]] - 1, 0) % const1; 
    		}
    		if(sum < 0)
    		{
    			sum += const1;
    		}
    		int val1 = ans4(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 2, cnt[a[x]] - 1) - ans5(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x]) * ans1(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 2, cnt[a[x]] - 1, 0) % const1;    		
    		relax(val1);
    		sum -= pref[x] * val1 % const1;
    		relax(sum);
    		val1 = ans3(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 2) - ans5(a[x], 1, 0, cnt[a[x]] - 1, ind[x], cnt[a[x]] - 1) * ans1(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 2, 1) % const1;
    		relax(val1);
    		sum -= suf[x] * val1 % const1;
    		relax(sum);
    		update4(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 1, cnt[a[x]] - 1, -1);
    		update3(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 1, -1);
    		update6(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 0, 1);
    		update6(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 0, 2);
    		update1(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 2);
    		update5(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 0);
    	}
    	else
    	{
    		if(ind[x] > 0 && ind[x] < cnt[a[x]] - 1)
    		{
    			sum += ans1(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 1, 1) * ans1(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 1, cnt[a[x]] - 1, 0) % const1; 
    		}
    		if(sum >= const1)
    		{
    			sum -= const1;
    		}
    		int val1 = ans4(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 2, cnt[a[x]] - 1) - ans5(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x]) * ans1(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 2, cnt[a[x]] - 1, 0) % const1;    		
    		relax(val1);
    		sum += pref[x] * val1 % const1;
    		relax(sum);
    		val1 = ans3(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 2) - ans5(a[x], 1, 0, cnt[a[x]] - 1, ind[x], cnt[a[x]] - 1) * ans1(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 2, 1) % const1;
    		relax(val1);
    		sum += suf[x] * val1 % const1;
    		relax(sum);
    		update4(a[x], 1, 0, cnt[a[x]] - 1, ind[x] + 1, cnt[a[x]] - 1, 1);
    		update3(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x] - 1, 1);
    		update6(a[x], 1, 0, cnt[a[x]] - 1, ind[x], (ans5(a[x], 1, 0, cnt[a[x]] - 1, 0, ind[x])) * suf[x] % const1, 1);
    		update6(a[x], 1, 0, cnt[a[x]] - 1, ind[x], (ans5(a[x], 1, 0, cnt[a[x]] - 1, ind[x], cnt[a[x]] - 1)) * pref[x] % const1, 2);
    		update1(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 1);
    		update5(a[x], 1, 0, cnt[a[x]] - 1, ind[x], 1);
    	}
    	cout << sum << "\n";
    }
	return 0;
}
