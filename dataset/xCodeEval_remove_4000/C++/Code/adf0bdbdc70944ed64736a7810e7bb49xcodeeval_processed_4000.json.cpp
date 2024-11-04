
















using namespace std;

void solve(){
	ll n, m;
	cin >> n >> m;
	char a[n][m];
	vector<tuple<pll, pll, pll>> ans;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin >> a[i][j];
	for(ll i = 0; i < n-1; i+=2)for(ll j = 0; j < m-1; j+=2){
		ll o = (a[i][j]-'0') + (a[i+1][j+1]-'0') + (a[i+1][j]-'0') + (a[i][j+1]-'0');
		if(o == 0)continue;
		if(o == 3){
			pll p[3];
			ll t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++;
			if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
			if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
			if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
			a[i+1][j+1] = a[i+1][j] = a[i][j+1] = a[i][j] = '0';
			ans.pb({p[0], p[1], p[2]});
			continue;
		}
		else if(o == 4){
			ans.pb({{i+1,j+1}, {i+1,j}, {i,j+1}});
			a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
			o = 1;
		}
		if(o==1){
			pll p[3];
			ll t = 0;
			if(a[i][j] == '1'){
				p[t] = {i,j}, t++;
				p[t] = {i+1,j}, t++;
				p[t] = {i+1,j+1}, t++;
				a[i][j] = '0';
				a[i+1][j] = a[i+1][j+1] = '1';
			}
			else if(a[i][j+1] == '1'){
				p[t] = {i,j+1}, t++;
				p[t] = {i+1,j+1}, t++;
				p[t] = {i+1,j}, t++;
				a[i][j+1] = '0';
				a[i+1][j] = a[i+1][j+1] = '1';
			}
			else if(a[i+1][j] == '1'){
				p[t] = {i+1,j}, t++;
				p[t] = {i+1,j+1}, t++;
				p[t] = {i,j+1}, t++;
				a[i+1][j] = '0';
				a[i+1][j+1] = a[i][j+1] = '1';
			}
			else if(a[i+1][j+1] == '1'){
				p[t] = {i+1,j+1}, t++;
				p[t] = {i+1,j}, t++;
				p[t] = {i,j+1}, t++;
				a[i+1][j+1] = '0';
				a[i+1][j] = a[i][j+1] = '1';
			}
			ans.pb({p[0], p[1], p[2]});
		}
		pll p[3];
		ll t = 0;
		if(a[i][j] == '1')p[t] = {i,j}, t++;
		else if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
		else if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
		else if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
		if(a[i][j] == '0')p[t] = {i,j}, t++;
		if(a[i][j+1] == '0')p[t] = {i,j+1}, t++;
		if(a[i+1][j] == '0')p[t] = {i+1,j}, t++;
		if(a[i+1][j+1] == '0')p[t] = {i+1,j+1}, t++;
		ans.pb({p[0], p[1], p[2]});
		a[p[0].f][p[0].s] = '0';
		a[p[1].f][p[1].s] = '1';
		a[p[2].f][p[2].s] = '1';
		t = 0;
		if(a[i][j] == '1')p[t] = {i,j}, t++, a[i][j] = '0';
		if(a[i][j+1] == '1')p[t] = {i,j+1}, t++, a[i][j+1] = '0';
		if(a[i+1][j] == '1')p[t] = {i+1,j}, t++, a[i+1][j] = '0';
		if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++, a[i+1][j+1] = '0';
		ans.pb({p[0], p[1], p[2]});
		a[i][j] = a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
	}
	if(n%2 and m%2){
		for(ll i = 0; i < n-1; i++)for(ll j = 0; j < m-1; j++){
			ll o = (a[i][j]-'0') + (a[i+1][j+1]-'0') + (a[i+1][j]-'0') + (a[i][j+1]-'0');
			if(o == 0)continue;
			if(o == 3){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1')p[t] = {i,j}, t++;
				if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
				if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
				if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = a[i][j] = '0';
				ans.pb({p[0], p[1], p[2]});
				continue;
			}
			else if(o == 4){
				ans.pb({{i+1,j+1}, {i+1,j}, {i,j+1}});
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
				o = 1;
			}
			if(o==1){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1'){
					p[t] = {i,j}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					a[i][j] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i][j+1] == '1'){
					p[t] = {i,j+1}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					a[i][j+1] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i+1][j] == '1'){
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j] = '0';
					a[i+1][j+1] = a[i][j+1] = '1';
				}
				else if(a[i+1][j+1] == '1'){
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j+1] = '0';
					a[i+1][j] = a[i][j+1] = '1';
				}
				ans.pb({p[0], p[1], p[2]});
			}
			pll p[3];
			ll t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++;
			else if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
			else if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
			else if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
			if(a[i][j] == '0')p[t] = {i,j}, t++;
			if(a[i][j+1] == '0')p[t] = {i,j+1}, t++;
			if(a[i+1][j] == '0')p[t] = {i+1,j}, t++;
			if(a[i+1][j+1] == '0')p[t] = {i+1,j+1}, t++;
			ans.pb({p[0], p[1], p[2]});
			a[p[0].f][p[0].s] = '0';
			a[p[1].f][p[1].s] = '1';
			a[p[2].f][p[2].s] = '1';
			t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++, a[i][j] = '0';
			if(a[i][j+1] == '1')p[t] = {i,j+1}, t++, a[i][j+1] = '0';
			if(a[i+1][j] == '1')p[t] = {i+1,j}, t++, a[i+1][j] = '0';
			if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++, a[i+1][j+1] = '0';
			ans.pb({p[0], p[1], p[2]});
			a[i][j] = a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
		}
	}
	else if(n%2){
		for(ll i = 0; i < n-1; i++)for(ll j = 0; j < m-1; j+=2){
			ll o = (a[i][j]-'0') + (a[i+1][j+1]-'0') + (a[i+1][j]-'0') + (a[i][j+1]-'0');
			if(o == 0)continue;
			if(o == 3){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1')p[t] = {i,j}, t++;
				if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
				if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
				if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = a[i][j] = '0';
				ans.pb({p[0], p[1], p[2]});
				continue;
			}
			else if(o == 4){
				ans.pb({{i+1,j+1}, {i+1,j}, {i,j+1}});
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
				o = 1;
			}
			if(o==1){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1'){
					p[t] = {i,j}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					a[i][j] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i][j+1] == '1'){
					p[t] = {i,j+1}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					a[i][j+1] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i+1][j] == '1'){
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j] = '0';
					a[i+1][j+1] = a[i][j+1] = '1';
				}
				else if(a[i+1][j+1] == '1'){
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j+1] = '0';
					a[i+1][j] = a[i][j+1] = '1';
				}
				ans.pb({p[0], p[1], p[2]});
			}
			pll p[3];
			ll t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++;
			else if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
			else if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
			else if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
			if(a[i][j] == '0')p[t] = {i,j}, t++;
			if(a[i][j+1] == '0')p[t] = {i,j+1}, t++;
			if(a[i+1][j] == '0')p[t] = {i+1,j}, t++;
			if(a[i+1][j+1] == '0')p[t] = {i+1,j+1}, t++;
			ans.pb({p[0], p[1], p[2]});
			a[p[0].f][p[0].s] = '0';
			a[p[1].f][p[1].s] = '1';
			a[p[2].f][p[2].s] = '1';
			t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++, a[i][j] = '0';
			if(a[i][j+1] == '1')p[t] = {i,j+1}, t++, a[i][j+1] = '0';
			if(a[i+1][j] == '1')p[t] = {i+1,j}, t++, a[i+1][j] = '0';
			if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++, a[i+1][j+1] = '0';
			ans.pb({p[0], p[1], p[2]});
			a[i][j] = a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
		}
	}
	else if(m%2){
		for(ll i = 0; i < n-1; i+=2)for(ll j = 0; j < m-1; j++){
			ll o = (a[i][j]-'0') + (a[i+1][j+1]-'0') + (a[i+1][j]-'0') + (a[i][j+1]-'0');
			if(o == 0)continue;
			if(o == 3){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1')p[t] = {i,j}, t++;
				if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
				if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
				if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = a[i][j] = '0';
				ans.pb({p[0], p[1], p[2]});
				continue;
			}
			else if(o == 4){
				ans.pb({{i+1,j+1}, {i+1,j}, {i,j+1}});
				a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
				o = 1;
			}
			if(o==1){
				pll p[3];
				ll t = 0;
				if(a[i][j] == '1'){
					p[t] = {i,j}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					a[i][j] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i][j+1] == '1'){
					p[t] = {i,j+1}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					a[i][j+1] = '0';
					a[i+1][j] = a[i+1][j+1] = '1';
				}
				else if(a[i+1][j] == '1'){
					p[t] = {i+1,j}, t++;
					p[t] = {i+1,j+1}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j] = '0';
					a[i+1][j+1] = a[i][j+1] = '1';
				}
				else if(a[i+1][j+1] == '1'){
					p[t] = {i+1,j+1}, t++;
					p[t] = {i+1,j}, t++;
					p[t] = {i,j+1}, t++;
					a[i+1][j+1] = '0';
					a[i+1][j] = a[i][j+1] = '1';
				}
				ans.pb({p[0], p[1], p[2]});
			}
			pll p[3];
			ll t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++;
			else if(a[i][j+1] == '1')p[t] = {i,j+1}, t++;
			else if(a[i+1][j] == '1')p[t] = {i+1,j}, t++;
			else if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++;
			if(a[i][j] == '0')p[t] = {i,j}, t++;
			if(a[i][j+1] == '0')p[t] = {i,j+1}, t++;
			if(a[i+1][j] == '0')p[t] = {i+1,j}, t++;
			if(a[i+1][j+1] == '0')p[t] = {i+1,j+1}, t++;
			ans.pb({p[0], p[1], p[2]});
			a[p[0].f][p[0].s] = '0';
			a[p[1].f][p[1].s] = '1';
			a[p[2].f][p[2].s] = '1';
			t = 0;
			if(a[i][j] == '1')p[t] = {i,j}, t++, a[i][j] = '0';
			if(a[i][j+1] == '1')p[t] = {i,j+1}, t++, a[i][j+1] = '0';
			if(a[i+1][j] == '1')p[t] = {i+1,j}, t++, a[i+1][j] = '0';
			if(a[i+1][j+1] == '1')p[t] = {i+1,j+1}, t++, a[i+1][j+1] = '0';
			ans.pb({p[0], p[1], p[2]});
			a[i][j] = a[i+1][j+1] = a[i+1][j] = a[i][j+1] = '0';
		}
	}
	cout << sz(ans) << endl;
	for(auto it:ans){
		cout<<get<0>(it).f+1<<" "<<get<0>(it).s+1<<" ";
		cout<<get<1>(it).f+1<<" "<<get<1>(it).s+1<<" ";
		cout<<get<2>(it).f+1<<" "<<get<2>(it).s+1<<" ";
		

		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cin.get();
	return 0;
}

