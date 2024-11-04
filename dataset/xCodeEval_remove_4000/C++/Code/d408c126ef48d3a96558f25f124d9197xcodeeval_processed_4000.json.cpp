


























using namespace std;

bool check(char c){
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c== 'Y')
		return true;
	return false;
}

void A(){

	string s;

	cin >> s;

	int last = 0;

	int d = 0;

	if (check(s.at(0))){
		last = 0;
		d = 1;
	} else {
		last = -1;
		d = 0;
	}

	for (int i = 1; i <s.length();i++){

		if (check(s.at(i))){
			if ( i - last > d)
				d = i - last;
			last = i;
		}

	}

	if (s.length() - last > d)
		d = s.length() - last;

	cout << d << endl;

}

void B(){
	int n;
	cin >> n;

	pair <int, int> p[n];

	int l, r;

	int L = 0;
	int R = 0;

	for (int i = 0; i < n; i++){
		cin >> l >> r;
		p[i] = make_pair(l,r);
		L += l;
		R += r;
	}

	int v = (L - R > 0) ? L - R : R - L;

	int ll;
	int rr;

	int max = v;
	int max_idx = -1;

	for (int i = 0; i < n; i++){
		ll = L - p[i].first + p[i].second;
		rr = R - p[i].second + p[i].first;
		int vv = (ll - rr > 0) ? ll -rr :rr - ll;
		if(vv > max){
			max = vv;
			max_idx = i;
		}
	}

	max_idx ++;
	cout << max_idx << endl;


}



void C(){
	int n;
	cin >> n;
	int x;
	vector <int> v;
	int sum_v = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
		sum_v += x;
	}

	int k;
	cin >> k;
	vector <int> vk;
	int sum_vk = 0;
	for (int i = 0; i < k; i++){
		cin >> x;
		vk.push_back(x);
		sum_vk += x;
	}

	if (sum_v != sum_vk){
		cout << "NO" << endl;
		return;
	}






	string res = "";

	int start = 0;

	for (int i = 0; i < k; i++){

		int t = vk[i];




		if (v[start] == t){
			start ++;
			continue;
		}




		bool ok = false;

		vector <int> vv;

		vv.assign(v.begin(), v.end());





		for (int f = start + 1; f <= vv.size() - (k - i - 1); f++){

			stringstream ss;

			v.clear();
			v.assign(vv.begin(), vv.end());




			int local_f = f;








			while (true) {
				bool eat = false;

				int id0 = 0;
				int id2 = 0;
				bool L, R;

				for (int j = start; j < local_f; j++) {
					bool l = false;
					bool r = false;

					if (j + 1 < local_f)
						if (v[j] > v[j + 1])
							r = true;
					if (j - 1 >= start)
						if (v[j] > v[j - 1])
							l = true;




					if (l || r) {
						eat = true;
						if (v[j] > id0) {
							id0 = v[j];
							id2 = j;
							L = l;
							R = r;
						}

					}

				}


				if (!eat)
					break;
				else {












					if (L) {
						v[id2] += v[id2 - 1];
						v.erase(v.begin() + (id2 - 1));
						ss << id2 + 1 << " L" << endl;
						local_f--;
					} else if (R) {
						v[id2] += v[id2 + 1];
						v.erase(v.begin() + (id2 + 1));
						ss << id2 + 1 << " R" << endl;
						local_f--;
					}










					if (v[start] == t) {
						ok = true;
						start++;
						break;
					}
				}




			}





			if (ok){


				res += ss.str();
				break;
			}


		} 




		if (!ok){
			cout << "NO" << endl;
			return;
		}


	}
	cout << "YES" << endl;
	cout << res << endl;

}

void get(int x, int y, int z, int i, int j, int & max, int & s1, int & s2) {

	int m = min(min(x, y), z);

	if (m > max) {
		max = m;
		s1 = i;
		s2 = j;
	}
}

struct u{
	int a;
	int b;
	int c;
	int id;
};

bool id1(u u1, u u2){
	if (u1.a == u2.a)
		if(u1.b == u2.b)
			return (u1.c < u2.c);
		else
			return (u1.b < u2.b);
	else
		return (u1.a < u2.a);
}

void D() {
	int k;
	cin >> k;



	u s[k];

	int x[3];

	for (int i = 0; i < k; i++) {
		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);






		s[i].a = x[0];
		s[i].b = x[1];
		s[i].c = x[2];
		s[i].id = i + 1;
	}

	sort (s, s+k, id1);

	int s1 = -1;
	int s2 = -1;
	int max = 0;

	int a, b, c,aa,bb,cc;

	for (int i = 0; i < k; i++) {

		 a = s[i].a;
		 b = s[i].b;
		 c = s[i].c;

		if (a > max) {
			max = a;


			s1 = i;
			s2 = -1;
		}









		for (int j = i + 1; j < k; j++) {
			 aa = s[j].a;
			 bb = s[j].b;
			 cc = s[j].c;

			 if (c < aa)
				 break;








































			 if (a == aa && b == bb && c == cc) {
				 get(2*a, b, c, i, j, max, s1, s2);
				 continue;
			 }

			if (b == bb && c == cc) {
				get(a + aa, b, c, i, j, max, s1, s2);
				continue;
			}

			if (a == aa && b == bb) {
				get(a, b, c + cc, i, j, max, s1, s2);
				continue;
			}
			if (a == aa && c == cc) {
				get(a, b + bb, c, i, j, max, s1, s2);
				continue;
			}
			if (a == bb && b == cc) {
				get(a, b, c + aa, i, j, max, s1, s2);
				continue;
			}
			if (a == bb && c == cc) {
				get(a, b + aa, c, i, j, max, s1, s2);
				continue;
			}
		}
	}

	if (s2 != -1)
		cout << 2 << endl << s[s1].id << " " << s[s2].id << endl;
	else
		cout << 1 << endl << s[s1].id << endl;

}

bool sort1(pair<int, int> p1, pair<int, int> p2){

		return (p1.first > p2.first);
}

void D_() {
	int k;
	cin >> k;

	map <int,  map<int, vector <pair<int, int> > > > m;

	int a, b,c;

	u s[k];

	int x[3];

	int max = 0;
	int s1 = -1;
	int s2 = -1;

	for (int i = 0; i < k; i++) {

		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);
		a = x[0];
		b = x[1];
		c = x[2];

		m[a][b].push_back( make_pair(c,i) );
		m[a][c].push_back( make_pair(b,i) );
		m[b][c].push_back( make_pair(a,i) );








		s[i].a = a;
		s[i].b = b;
		s[i].c = c;
	}

	


	for (map <int,  map<int, vector <pair<int, int> > > >::iterator it=m.begin(); it!=m.end(); ++it){
		 for ( map<int, vector <pair<int, int> > > :: iterator its = (*it).second.begin(); its != (*it).second.end(); ++its){
			 sort ( (*its).second.begin(), (*its).second.end(), sort1);
		 }
	}


	for (int i = 0; i < k; i++) {

		a = s[i].a;
		b = s[i].b;
		c = s[i].c;

		if (a > max){
			max = a;
			s1 = i;
			s2 = -1;
		}

		vector< pair<int, int> > & v = m[a][b];

		int sum;

		for (int j = 0; j < v.size(); j++){
			if (v[j].second == i)
				continue;
			sum =  v[j].first + c;
			sum = min( sum, min(a,b) );
			if (sum > max){
				max = sum;
				s1 = i;
				s2 = v[j].second;
				break;
			} else
				break;
		}

		v = m[a][c];
		for (int j = 0; j < v.size(); j++) {
			if (v[j].second == i)
				continue;
			sum = v[j].first + b;
			sum = min( sum, min(a,c) );
			if (sum > max) {
				max = sum;
				s1 = i;
				s2 = v[j].second;
				break;
			}else
				break;
		}

		v = m[b][c];
		for (int j = 0; j < v.size(); j++) {
			if (v[j].second == i)
				continue;
			sum = v[j].first + a;
			sum = min( sum, min(b,c) );
			if (sum > max) {
				max = sum;
				s1 = i;
				s2 = v[j].second;
				break;
			}else
				break;
		}


	}

	if (s2 != -1)
		cout << 2 << endl << s1 + 1 << " " << s2 + 1 << endl;
	else
		cout << 1 << endl << s1 + 1 << endl;



}

void D__() {
	int k;
	cin >> k;

	map <int,  map<int, pair<int, int>  > > m;

	int a, b,c;

	u s[k];

	int x[3];

	int max = 0;
	int s1 = -1;
	int s2 = -1;




































































	for (int i = 0; i < k; i++) {

		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);
		a = x[0];
		b = x[1];
		c = x[2];

		if (c > m[a][b].first)
			m[a][b] = make_pair(c, i);

		if (b > m[a][c].first)
			m[a][c] = make_pair(b, i);

		if (a > m[b][c].first)
			m[b][c] = make_pair(a, i);

		s[i].a = a;
		s[i].b = b;
		s[i].c = c;
	}


	for (int i = 0; i < k; i++) {
		a = s[i].a;
		b = s[i].b;
		c = s[i].c;

		if (a > max) {
			max = a;
			s1 = i;
			s2 = -1;
		}

		int sum;

		if (m[a][b].second != i) {
			sum = m[a][b].first + c;
			sum = min(sum, min(a, b));

			if (sum > max) {
				max = sum;
				s1 = i;
				s2 = m[a][b].second;
			}
		}

		if (m[a][c].second != i) {
			sum = m[a][c].first + b;
			sum = min(sum, min(a, c));

			if (sum > max) {
				max = sum;
				s1 = i;
				s2 = m[a][c].second;
			}
		}

		if (m[b][c].second != i) {
			sum = m[b][c].first + a;
			sum = min(sum, min(b, c));

			if (sum > max) {
				max = sum;
				s1 = i;
				s2 = m[b][c].second;
			}
		}

	}

	if (s2 != -1)
		cout << 2 << endl << s1 + 1 << " " << s2 + 1 << endl;
	else
		cout << 1 << endl << s1 + 1 << endl;



}

void E(){

}

void F(){

}


int main() {










	D__();

	return 0;
}
