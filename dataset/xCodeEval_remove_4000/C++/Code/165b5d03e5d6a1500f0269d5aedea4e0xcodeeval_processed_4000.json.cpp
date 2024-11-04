
using namespace std;





























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

void id10(int node,int it,int f,int q, int id, LL val, bool enable)
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
		id10(rn, m + 1, f, q, id, val, enable);
	}
	else{
		id10(ln, it, m, q, id, val, enable );
		id10(rn, m + 1, f, m + 1, id, val, enable);
	}

	prefix_sum_seg[id][node] = (prefix_sum_seg[id][ln] + prefix_sum_seg[id][rn] + active[id][node] * prefix_layer[id][node]) % mod;
}

void id3(int node,int it, int f,int q,int id,LL val,bool enable)
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
		id3(ln, it, m, q, id, val, enable);
	else{
		id3(ln, it, m, m, id, val, enable);
		id3(rn, m + 1, f, q, id, val, enable);
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

LL id7(int node,int it,int f,int q, int id, LL upperL)
{
	
	if( q == f)
		return (prefix_sum_seg[id][node] + active[id][node] * upperL) % mod;
	upperL += prefix_layer[id][node];
	int m = ( it + f)/2;
	if( q <= m)
		return id7(node * 2, it, m, q, id, upperL % mod);
	else{
		int val = id7(node * 2, it, m, m, id, upperL % mod);
		return val + id7(node * 2 + 1, m + 1, f, q, id, upperL % mod);
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

LL id8(int node,int it,int f,int q, int id, LL upperL)
{
	
	if( q == it){
		return (suffix_sum_seg[id][node] + active[id][node] * upperL) % mod;
	}
	upperL += suffix_layer[id][node];
	int m = ( it + f)/2;
	if( q > m){
		return id8(node * 2 + 1, m + 1, f, q, id, upperL % mod);
	}
	else
	{
		LL val = id8(node * 2 + 1, m + 1, f, m + 1, id, upperL % mod);
		return (val + id8(node * 2, it, m, q, id, upperL % mod)) % mod;
	}
}

int id9(int node, int it,int f,int q,int id)
{
	if(!active[id][node])
		return -1;
	if(it == f){
		return f;
	}
	int m = (it + f)/2;
	int idx = -1;
	if(q > m){
		idx = id9(node * 2 + 1, m + 1, f, q, id);
		if(idx != -1)
			return idx;
		return id9(node * 2, it, m, m, id);
	}
	return id9(node * 2, it, m, q, id);
}

int id5(int node, int it,int f,int q,int id)
{
	if(!active[id][node])
		return -1;
	if(it == f){
		return f;
	}
	int m = (it + f)/2;
	int idx = -1;
	if(q <= m){
		idx = id5(node * 2, it, m, q, id);
		if(idx != -1)
			return idx;
		return id5(node * 2 + 1, m + 1, f, m + 1, id);
	}
	return id5(node * 2 + 1, m + 1, f, q, id);

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
		LL pre_s = 0, id6 = 0;
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
			id6 += suf[i][j];
			suf_sum[i][j] = id6 % mod;
		}
		insert(1, 1, szz, i);
	}

	LL ans = 0;
	for(int i = 1; i <= idx + 1; ++i){
		int szz = (int)dataidx[i].sz;
		for(int j = 0; j < szz; ++j){
			if( j + 3 <= szz){
				ans += (pre[i][j] * id8(1, 1, szz, (j + 3), i, 0)) % mod;
				ans %= mod;
			}
		}
	}

	int m, qidx, qtype, szz, id1, id0, id4, id2;
	si(m);
	while( m-- ){
		si(qtype); si(qidx);
		szz = (int)dataidx[a[qidx]].sz;
		int id = a[qidx];  

		id4 = id2 = -1;
		id1 = id0 = -1;

		if(pos[qidx] > 1) id4 = id9(1, 1, szz, pos[qidx] - 1, id);
		if( id4 > 1)
			id2 = id9(1, 1, szz, id4 - 1, id);

		if(pos[qidx] < szz)
			id1 = id5(1, 1, szz, pos[qidx] + 1, id);
		if( id1 < szz && id1>0)
			id0 = id5(1, 1, szz, id1 + 1, id);

		if( qtype == 1){ 

			if ( pos[qidx]>1 && pos[qidx]<szz)
				ans -= ( get_prefix(1, 1, szz, pos[qidx] - 1, id) * get_suffix(1, 1, szz, pos[qidx] + 1, id) ) % mod;
			if( id0!=-1 && id0 <= szz)
				ans -= ( pre[id][pos[qidx] - 1] * id8(1, 1, szz, id0, id, 0)) % mod;
			if(id2 > 0)
				ans -= ( id7(1, 1, szz, id2, id, 0) * suf[id][pos[qidx] - 1]) % mod;
			LL val = pre[id][pos[qidx] - 1];
			point_update(1, 1, szz, pos[qidx], false, a[qidx]);
			id10(1, 1, szz, pos[qidx], id, val, false);
			val = suf[id][pos[qidx] - 1];
			id3(1, 1, szz, pos[qidx], id, val, false);
		}
		else{ 

			if ( pos[qidx]>1 && pos[qidx]<szz)
				ans += ( get_prefix(1, 1, szz, pos[qidx] - 1, id) * get_suffix(1, 1, szz, pos[qidx] + 1, id)) % mod;
			if( id0!=-1 && id0 <= szz)
				ans += ( pre[id][pos[qidx] - 1] * id8(1, 1, szz, id0, id, 0) ) % mod;
			if(id2 > 0)
				ans += ( id7(1, 1, szz, id2, id, 0) * suf[id][pos[qidx] - 1] ) % mod;
			LL val = pre[id][pos[qidx] - 1];
			point_update(1, 1, szz, pos[qidx], true, a[qidx]);
			id10(1, 1, szz, pos[qidx], id, val, true);
			val = suf[id][pos[qidx] - 1];
			id3(1, 1, szz, pos[qidx], id, val, true);
		}
		ans %= mod;
		if( ans < 0)
			ans += mod;
		printf("%d\n",(int)(ans));
	}
	return 0;
}

