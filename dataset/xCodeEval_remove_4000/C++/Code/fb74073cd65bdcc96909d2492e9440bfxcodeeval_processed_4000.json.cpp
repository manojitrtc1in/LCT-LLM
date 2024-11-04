




























using namespace std;







namespace __time {
	clock_t t;
	double get_time() {
		return (double)(clock() - t) / CLOCKS_PER_SEC;
	}
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 998244353;

ll calc_pow[30];
ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * a) % mod;
			--n;
		}
		else {
			a = (a * a) % mod;
			n >>= 1;
		}
	}
	return res;
}

ll get_h(vector<int>& pos, vector<int>& id, ll a) {
	ll ret = 0;
	for (int i = 0; i < id.size(); ++i) {
		ret = (ret + (calc_pow[pos[id[i]]] * id[i]) % mod) % mod;
	}
	return ret;
}

int c_pos[50], c_ost_id[50];
vector<int> id1(int k, ll a, ll h) {
	for (int i = 0; i < (1 << ((1 << k) - 1)); ++i) {
		int cur_pos = (1 << (k - 1)) + 1;
		vector<int> pos((1 << k) + 1, cur_pos);

		vector<int> ost_id;
		for (int j = 1; j <= (1 << k); ++j)
			ost_id.push_back(j);

		int pref = 0;
		for (int j = k - 1; j >= 0; --j) {
			if (j)
				cur_pos = (1 << (j - 1)) + 1;
			else
				cur_pos = 1;
			vector<int> cur_id;
			for (int q = 0; q < (1 << j); ++q) {
				int bit = (1 << (pref + q));
				bit &= i;
				cur_id.push_back(ost_id[(q) * 2 + (bit > 0)]);
				pos[cur_id.back()] = cur_pos;
			}
			ost_id = cur_id;
			pref += (1 << j);
		}

		ost_id.clear();
		for (int j = 1; j <= (1 << k); ++j)
			ost_id.push_back(j);
		if (get_h(pos, ost_id, a) == h)
			return pos;
	}
	return {};
}

vector<pair<ll, int>> pomnyu[32769];
void calc(vector<int>& id, int k, ll a, int mask, ll h_plus) {

	int cur_pos = (1 << (k - 1)) + 1;

	for (int j = 0; j < (1 << k) + 1; ++j)
		c_pos[j] = cur_pos;

	for (int j = 0; j < id.size(); ++j)
		c_ost_id[j] = id[j];

	ll ret_ = 0;
	for (int j = 0; j < id.size(); ++j)
		ret_ = (ret_ + (calc_pow[c_pos[c_ost_id[j]]] * c_ost_id[j]) % mod) % mod;
	ret_ = (ret_ + h_plus) % mod;

	for (int i = 0; i < (1 << ((1 << k) - 1)); ++i) {
		cur_pos = (1 << (k - 1)) + 1;
		for (int j = 0; j < (1 << k) + 1; ++j)
			c_pos[j] = cur_pos;
		for (int j = 0; j < id.size(); ++j)
			c_ost_id[j] = id[j];

		ll ret = ret_;

		int pref = 0;
		for (int j = k - 1; j >= 0; --j) {
			if (j)
				cur_pos = (1 << (j - 1)) + 1;
			else
				cur_pos = 1;

			for (int q = 0; q < (1 << j); ++q) {
				int bit = (1 << (pref + q));
				bit &= i;

				int fir = q * 2 * (1 << (k - 1 - j)), sec = fir + (1 << (k - 1 - j));
				int nash = (bit ? c_ost_id[sec] : c_ost_id[fir]);

				ret = (ret + (((-calc_pow[c_pos[nash]] + calc_pow[cur_pos] + mod) % mod) * nash) % mod + mod) % mod;
				c_pos[nash] = cur_pos;

				if (bit) c_ost_id[fir] = c_ost_id[sec];
			}

			pref += (1 << j);
		}

		if (mask == 164)
		{
			if (c_pos[1] == 9
				&& c_pos[3] == 5
				&& c_pos[6] == 1
				&& c_pos[7] == 9
				&& c_pos[9] == 9
				&& c_pos[12] == 3
				&& c_pos[13] == 5
				&& c_pos[16] == 9) {
				

			}
		}
		pomnyu[i].emplace_back(ret, mask);
	}
}

vector<int> find(vector<int>& id, int k, ll a, ll h, int mask2, ll h_plus) {
	int cur_pos = (1 << (k - 1)) + 1;

	for (int j = 0; j < (1 << (k + 1)) + 1; ++j)
		c_pos[j] = (1 << k) + 1;

	for (int j = 0; j < id.size(); ++j)
		c_ost_id[j] = j + 1, c_pos[j + 1] = cur_pos;
	for (int j = 0; j < id.size(); ++j)
		c_ost_id[id.size() + j] = id[j], c_pos[id[j]] = cur_pos;


	ll ret_ = 0;
	for (int j = id.size(); j < 2 * id.size(); ++j)
		ret_ = (ret_ + (calc_pow[c_pos[c_ost_id[j]]] * c_ost_id[j]) % mod) % mod;
	ret_ = (ret_ + h_plus) % mod;

	for (int i = 0; i < (1 << ((1 << k) - 1)); ++i) {
		if (__time::get_time() > (double)2.528)
		{
			cout << -1;
			exit(0);
		}
		cur_pos = (1 << (k - 1)) + 1;

		for (int j = 0; j < (1 << (k + 1)) + 1; ++j)
			c_pos[j] = cur_pos;

		for (int j = 0; j < id.size(); ++j)
			c_ost_id[j] = j + 1, c_pos[j + 1] = cur_pos;
		for (int j = 0; j < id.size(); ++j)
			c_ost_id[id.size() + j] = id[j], c_pos[id[j]] = cur_pos;


		ll ret = ret_;
		

		int pref = 0;
		for (int j = k - 1; j >= 0; --j) {
			if (j)
				cur_pos = (1 << (j - 1)) + 1;
			else
				cur_pos = 1;

			for (int q = 0; q < (1 << j); ++q) {
				int bit = (1 << (pref + q));
				bit &= i;

				int fir = q * 2 * (1 << (k - 1 - j)), sec = fir + (1 << (k - 1 - j));
				int nash = (bit ? c_ost_id[sec] : c_ost_id[fir]);
				if (nash > 16)
					ret = (ret + (((-calc_pow[c_pos[nash]] + calc_pow[cur_pos] + mod) % mod) * nash) % mod + mod) % mod;
				c_pos[nash] = cur_pos;

				if (bit) c_ost_id[fir] = c_ost_id[sec];
			}

			pref += (1 << j);
		}

		auto it = upper_bound(pomnyu[i].begin(), pomnyu[i].end(), m_p((ll)((h - ret + mod) % mod), (int)1e9));
		if (it == pomnyu[i].begin())
			continue;
		--it;
		if (it->first == ((h - ret + mod) % mod)) {
			int mask = it->second;

			vector<int> ret_pos((1 << (k + 1)) + 1, (1 << k) + 1);

			

			vector<int> fir_half;
			for (int j = 1; j <= (1 << k); ++j)
				fir_half.push_back(j);

			for (int q = 0; q < (1 << (k - 1)); ++q) {
				int bit = (1 << q);
				bit &= mask;
				ret_pos[fir_half[(q) * 2 + (bit > 0)]] = c_pos[q + 1];
			}
			

			

			vector<int> sec_half;
			for (int j = (1 << (k)) + 1; j <= (1 << (k + 1)); ++j)
				sec_half.push_back(j);

			for (int q = 0; q < (1 << (k - 1)); ++q) {
				int bit = (1 << q);
				bit &= mask2;
				ret_pos[sec_half[(q) * 2 + (bit > 0)]] = c_pos[sec_half[(q) * 2 + (bit > 0)]];
			}
			

			return ret_pos;
		}
	}
	return {};
}

void $main()
{
	ll k, a, h; cin >> k >> a >> h;

	for (int i = 0; i < 30; ++i) {
		calc_pow[i] = binpow(a, i);
	}

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	



	if (k != 5) {
		auto res = id1(k, a, h);
		if (res.empty())
			cout << -1;
		else {
			res.erase(res.begin());
			for (int el : res)
				cout << el << " ";
		}
		exit(0);
	}

	for (int i = 0; i < (1 << (1 << (k - 2))); ++i) {
		vector<int> ost_id;
		for (int j = 1; j <= (1 << (k - 1)); ++j)
			ost_id.push_back(j);

		vector<int> cur_id;
		ll h_plus = 0;
		for (int q = 0; q < (1 << (k - 2)); ++q) {
			int bit = (1 << q);
			bit &= i;
			cur_id.push_back(ost_id[(q) * 2 + (bit > 0)]);
			h_plus = (h_plus + (calc_pow[(1 << (k - 1)) + 1] * ost_id[(q) * 2 + !(bit > 0)]) % mod) % mod;
		}
		calc(cur_id, k - 1, a, i, h_plus);
	}

	for (int i = 0; i < 32769; ++i)
		sort(pomnyu[i].begin(), pomnyu[i].end());

	vector<int> id0;
	for (int i = 0; i < (1 << (1 << (k - 2))); ++i)
		id0.push_back(i);
	shuffle(id0.begin(), id0.end(),rng);

	for (int i_ = 0; i_ < (1 << (1 << (k - 2))); ++i_) {
		int i = id0[i_];
		vector<int> ost_id;
		for (int j = (1 << (k - 1)) + 1; j <= (1 << k); ++j)
			ost_id.push_back(j);

		vector<int> cur_id;
		ll h_plus = 0;
		for (int q = 0; q < (1 << (k - 2)); ++q) {
			int bit = (1 << q);
			bit &= i;
			cur_id.push_back(ost_id[(q) * 2 + (bit > 0)]);
			h_plus = (h_plus + (calc_pow[(1 << (k - 1)) + 1] * ost_id[(q) * 2 + !(bit > 0)]) % mod) % mod;
		}
		
		auto get_ = find(cur_id, k - 1, a, h, i, h_plus);
		if (!get_.empty()) {
			get_.erase(get_.begin());
			for (int el : get_)
				cout << el << " ";
			exit(0);
		}
	}
	cout << -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");


	freopen("input.txt", "r", stdin);

	

	


	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	__time::t = clock();
	$main();

	return 0;
}