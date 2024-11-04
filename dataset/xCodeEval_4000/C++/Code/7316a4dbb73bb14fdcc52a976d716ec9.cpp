#include <bits/stdc++.h>
using namespace std;

#define LL long long int

#define rep(i,n) for(int i= int(1); i<= (int)n; i++)

#define CLR(a) memset(a,0,sizeof(a));
#define SET(a) memset(a,-1,sizeof(a));

#define sz size()
#define pb(x) push_back(x)
#define mp make_pair
#define ii pair<int,int>

#define ll pair<LL,LL>

#define bi pair<bool,int>

#define F first
#define S second

#define mod int(1e9 + 7)
#define N int(1e5 + 1000)

#define si(a) scanf("%d",&a);

#define VI vector<int>
#define VL vector<LL>


VI dataidx[N], diff;
VL prefix_seg[N], prefix_layer[N], suffix_seg[N], suffix_layer[N], active[N], prefix_sum_seg[N], suffix_sum_seg[N], pre[N], suf[N], en[N], pre_sum[N], suf_sum[N];
int seg[4 * N] = {0}, MaxVal = 1e5, pos[N], tree[N] = {0}, a[N];
map<int, int> Rank;
bool uu = 0;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void insert(int node, int it, int f,int id)
{
	
	if( it == f){
		prefix_seg[id][node] = pre[id][f - 1]; 

		suffix_seg[id][node] = suf[id][f - 1];
		prefix_sum_seg[id][node] = pre_sum[id][f - 1]; 

		suffix_sum_seg[id][node] = suf_sum[id][f - 1];
		active[id][node] = 1;
		return;
	}
	int m = ( it + f)/2, ln = node * 2, rn;
	rn = ln + 1;
	insert(ln, it, m, id);
	insert(rn, m + 1, f, id);

	active[id][node] = f - it + 1;

	prefix_seg[id][node] = (prefix_seg[id][ln] + prefix_seg[id][rn]) % mod;
	prefix_sum_seg[id][node] = (prefix_sum_seg[id][ln] + prefix_sum_seg[id][rn]) % mod;
	
	suffix_seg[id][node] = (suffix_seg[id][ln] + suffix_seg[id][rn]) % mod;
	suffix_sum_seg[id][node] = (suffix_sum_seg[id][ln] + suffix_sum_seg[id][rn]) % mod;

}

void point_update(int node,int it,int f,int q, bool enable, int id)
{
	if( it == f){
		if( !enable){
			prefix_seg[id][node] = 0;
			suffix_seg[id][node] = 0;
			prefix_sum_seg[id][node] = 0;
			suffix_sum_seg[id][node] = 0;
			active[id][node] --;
		}
		else{
			prefix_seg[id][node] = pre[id][f - 1];
			suffix_seg[id][node] = suf[id][f - 1];
			prefix_sum_seg[id][node] = (pre_sum[id][f - 1] + prefix_layer[id][node]) % mod;
			suffix_sum_seg[id][node] = (suf_sum[id][f - 1] + suffix_layer[id][node]) % mod;
			active[id][node] ++;
		}
		return ;
	}

	int m = (it + f)/2;
	if( q <= m)
		point_update(node * 2, it,m , q, enable, id);
	else
		point_update(node * 2 + 1, m + 1, f, q, enable, id);
	if(enable)
		active[id][node] ++;
	else
		active[id][node]--;
	prefix_seg[id][node] = (prefix_seg[id][node * 2] + prefix_seg[id][node * 2 + 1]) % mod;
	suffix_seg[id][node] = (suffix_seg[id][node * 2] + suffix_seg[id][node * 2 + 1]) % mod;

	prefix_sum_seg[id][node] = (prefix_sum_seg[id][node * 2] + prefix_sum_seg[id][node * 2 + 1] + active[id][node] * prefix_layer[id][node]) % mod;
	suffix_sum_seg[id][node] = (suffix_sum_seg[id][node * 2] + suffix_sum_seg[id][node * 2 + 1] + active[id][node] * suffix_layer[id][node]) % mod;
}

void range_update_prefix(int node,int it,int f,int q, int id, LL val, bool enable)
{
	if(q == it){
		if( enable){
			prefix_sum_seg[id][node] = (prefix_sum_seg[id][node] + active[id][node] * val) % mod;
			prefix_layer[id][node] = (prefix_layer[id][node] + val) % mod;
		}
		else{
			prefix_sum_seg[id][node] = (prefix_sum_seg[id][node] - active[id][node] * val) % mod;
			prefix_layer[id][node] = (prefix_layer[id][node] - val) % mod;
		}
		return;
	}
	int m = (it + f)/2, ln = node * 2, rn;
	rn = ln + 1;
	if( q > m){
		range_update_prefix(rn, m + 1, f, q, id, val, enable);
	}
	else{
		range_update_prefix(ln, it, m, q, id, val, enable );
		range_update_prefix(rn, m + 1, f, m + 1, id, val, enable);
	}

	prefix_sum_seg[id][node] = (prefix_sum_seg[id][ln] + prefix_sum_seg[id][rn] + active[id][node] * prefix_layer[id][node]) % mod;
}

void range_update_suffix(int node,int it, int f,int q,int id,LL val,bool enable)
{
	if(q == f){
		if( enable){
			suffix_sum_seg[id][node] = (suffix_sum_seg[id][node] + active[id][node] * val) % mod;
			suffix_layer[id][node] = (suffix_layer[id][node] + val) % mod;

		}
		else{
			suffix_sum_seg[id][node] = (suffix_sum_seg[id][node] - active[id][node] * val) % mod;
			suffix_layer[id][node] = (suffix_layer[id][node] - val) % mod;
		}
		return;
	}
	int m = ( it + f) /2 , ln = node * 2, rn;
	rn = ln + 1;
	if( q <= m)
		range_update_suffix(ln, it, m, q, id, val, enable);
	else{
		range_update_suffix(ln, it, m, m, id, val, enable);
		range_update_suffix(rn, m + 1, f, q, id, val, enable);
	}
	suffix_sum_seg[id][node] = (suffix_sum_seg[id][ln] + suffix_sum_seg[id][rn] + active[id][node] * suffix_layer[id][node]) % mod;


}

LL get_prefix(int node,int it,int f,int q, int id)
{
	if( q == f)
		return prefix_seg[id][node] % mod;
	int  m = ( it + f)/2;
	if( q <= m)
		return get_prefix(node * 2, it, m, q, id);
	else
		return (prefix_seg[id][node * 2] + get_prefix(node * 2 + 1, m + 1, f, q, id)) % mod;
}

LL get_prefix_sum(int node,int it,int f,int q, int id, LL upperL)
{
	
	if( q == f)
		return (prefix_sum_seg[id][node] + active[id][node] * upperL) % mod;
	upperL += prefix_layer[id][node];
	int m = ( it + f)/2;
	if( q <= m)
		return get_prefix_sum(node * 2, it, m, q, id, upperL % mod);
	else{
		int val = get_prefix_sum(node * 2, it, m, m, id, upperL % mod);
		return val + get_prefix_sum(node * 2 + 1, m + 1, f, q, id, upperL % mod);
	}
}

LL get_suffix(int node,int it,int f,int q, int id)
{
	if( q == it)
		return suffix_seg[id][node] % mod;
	int m = ( it + f)/2;
	if( q > m)
		return get_suffix(node * 2 + 1, m + 1, f, q, id);
	else
		return (suffix_seg[id][node * 2 + 1] + get_suffix(node * 2, it, m, q, id)) % mod;
}

LL get_suffix_sum(int node,int it,int f,int q, int id, LL upperL)
{
	
	if( q == it){
		return (suffix_sum_seg[id][node] + active[id][node] * upperL) % mod;
	}
	upperL += suffix_layer[id][node];
	int m = ( it + f)/2;
	if( q > m){
		return get_suffix_sum(node * 2 + 1, m + 1, f, q, id, upperL % mod);
	}
	else
	{
		LL val = get_suffix_sum(node * 2 + 1, m + 1, f, m + 1, id, upperL % mod);
		return (val + get_suffix_sum(node * 2, it, m, q, id, upperL % mod)) % mod;
	}
}

int get_prv(int node, int it,int f,int q,int id)
{
	if(!active[id][node])
		return -1;
	if(it == f){
		return f;
	}
	int m = (it + f)/2;
	int idx = -1;
	if(q > m){
		idx = get_prv(node * 2 + 1, m + 1, f, q, id);
		if(idx != -1)
			return idx;
		return get_prv(node * 2, it, m, m, id);
	}
	return get_prv(node * 2, it, m, q, id);
}

int get_nxt(int node, int it,int f,int q,int id)
{
	if(!active[id][node])
		return -1;
	if(it == f){
		return f;
	}
	int m = (it + f)/2;
	int idx = -1;
	if(q <= m){
		idx = get_nxt(node * 2, it, m, q, id);
		if(idx != -1)
			return idx;
		return get_nxt(node * 2 + 1, m + 1, f, m + 1, id);
	}
	return get_nxt(node * 2 + 1, m + 1, f, q, id);

}


int main()
{
	int n;
	si(n);
	rep(i, n){
		si(a[i]);
		diff.pb(a[i]);
	}
	sort(diff.begin(), diff.end());
	int idx = 0;

	for(int i = 1; i < n; ++i){
		if( diff[i] != diff[i - 1])
			diff[++idx] = diff[i];
	}

	for(int i = 0; i <= idx; ++i)
		Rank[diff[i]] = i + 1;
	for(int i = 1; i <= n; ++i){
		a[i] = Rank[a[i]];
		dataidx[a[i]].pb(i);
		pos[i] = (int)dataidx[a[i]].sz;
	}

	for(int i = 1; i <= idx + 1; ++i){
		int szz = (int)dataidx[i].sz;
		prefix_seg[i].resize(4 * szz);
		suffix_seg[i].resize(4 * szz);
		prefix_sum_seg[i].resize(4 * szz);
		suffix_sum_seg[i].resize(4 * szz);
		prefix_layer[i].resize(4 * szz);
		suffix_layer[i].resize(4 * szz);
		active[i].resize(4 * szz);

		pre[i].resize(szz + 5);
		suf[i].resize(szz + 5);
		pre_sum[i].resize(szz + 5);
		suf_sum[i].resize(szz + 5);
		

		fill(prefix_seg[i].begin(), prefix_seg[i].end(), +0);
		fill(suffix_seg[i].begin(), suffix_seg[i].end(), +0);
		fill(prefix_sum_seg[i].begin(), prefix_sum_seg[i].end(), +0);
		fill(suffix_sum_seg[i].begin(), suffix_sum_seg[i].end(), +0);
		fill(prefix_layer[i].begin(), prefix_layer[i].end(), +0);
		fill(suffix_layer[i].begin(), suffix_layer[i].end(), +0);
	}	

	int tot = 0, id;
	for(int i = 1; i <= idx + 1; ++i){
		int szz = (int)dataidx[i].sz;
		LL pre_s = 0, suf_s = 0;
		tot += szz;
		for(int j = 0; j < szz; ++j){
			id = dataidx[i][j];
			update(id, +1);
		}
		for(int j = 0; j < szz; ++j){
			pre[i][j] = (read(dataidx[i][j]) - 1) % mod;
			pre_s += pre[i][j];
			pre_sum[i][j] = pre_s % mod;
			suf[i][j] = (tot - pre[i][j] - 1) % mod;
		}
		for(int j = szz - 1; j >= 0; j--){
			suf_s += suf[i][j];
			suf_sum[i][j] = suf_s % mod;
		}
		insert(1, 1, szz, i);
	}

	LL ans = 0;
	for(int i = 1; i <= idx + 1; ++i){
		int szz = (int)dataidx[i].sz;
		for(int j = 0; j < szz; ++j){
			if( j + 3 <= szz){
				ans += (pre[i][j] * get_suffix_sum(1, 1, szz, (j + 3), i, 0)) % mod;
				ans %= mod;
			}
		}
	}

	int m, qidx, qtype, szz, nxtOne, nxtTwo, prvOne, prvTwo;
	si(m);
	while( m-- ){
		si(qtype); si(qidx);
		szz = (int)dataidx[a[qidx]].sz;
		int id = a[qidx];  

		prvOne = prvTwo = -1;
		nxtOne = nxtTwo = -1;

		if(pos[qidx] > 1) prvOne = get_prv(1, 1, szz, pos[qidx] - 1, id);
		if( prvOne > 1)
			prvTwo = get_prv(1, 1, szz, prvOne - 1, id);

		if(pos[qidx] < szz)
			nxtOne = get_nxt(1, 1, szz, pos[qidx] + 1, id);
		if( nxtOne < szz && nxtOne>0)
			nxtTwo = get_nxt(1, 1, szz, nxtOne + 1, id);

		if( qtype == 1){ 

			if ( pos[qidx]>1 && pos[qidx]<szz)
				ans -= ( get_prefix(1, 1, szz, pos[qidx] - 1, id) * get_suffix(1, 1, szz, pos[qidx] + 1, id) ) % mod;
			if( nxtTwo!=-1 && nxtTwo <= szz)
				ans -= ( pre[id][pos[qidx] - 1] * get_suffix_sum(1, 1, szz, nxtTwo, id, 0)) % mod;
			if(prvTwo > 0)
				ans -= ( get_prefix_sum(1, 1, szz, prvTwo, id, 0) * suf[id][pos[qidx] - 1]) % mod;
			LL val = pre[id][pos[qidx] - 1];
			point_update(1, 1, szz, pos[qidx], false, a[qidx]);
			range_update_prefix(1, 1, szz, pos[qidx], id, val, false);
			val = suf[id][pos[qidx] - 1];
			range_update_suffix(1, 1, szz, pos[qidx], id, val, false);
		}
		else{ 

			if ( pos[qidx]>1 && pos[qidx]<szz)
				ans += ( get_prefix(1, 1, szz, pos[qidx] - 1, id) * get_suffix(1, 1, szz, pos[qidx] + 1, id)) % mod;
			if( nxtTwo!=-1 && nxtTwo <= szz)
				ans += ( pre[id][pos[qidx] - 1] * get_suffix_sum(1, 1, szz, nxtTwo, id, 0) ) % mod;
			if(prvTwo > 0)
				ans += ( get_prefix_sum(1, 1, szz, prvTwo, id, 0) * suf[id][pos[qidx] - 1] ) % mod;
			LL val = pre[id][pos[qidx] - 1];
			point_update(1, 1, szz, pos[qidx], true, a[qidx]);
			range_update_prefix(1, 1, szz, pos[qidx], id, val, true);
			val = suf[id][pos[qidx] - 1];
			range_update_suffix(1, 1, szz, pos[qidx], id, val, true);
		}
		ans %= mod;
		if( ans < 0)
			ans += mod;
		printf("%d\n",(int)(ans));
	}
	return 0;
}



