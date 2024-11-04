










typedef char                SINT8;
typedef short               SINT16;
typedef int                 SINT32;
typedef long long           SINT64;
typedef double              DOUBLE;



























using namespace std;

int main() {

	SINT64 N;	cin >> N;
	
	vector<Plll> data1;
	vector<Plll> data2;
	vector<Plll> data3;
	vector<Plll> data4;
	
	rep(i,0,N) {
		SINT64 a,b,c,d;
		cin >> a >> b >> c >> d;
		Plll buf;
		buf.F = b;
		buf.S.F = a;
		buf.S.S = i;
		data1.emplace_back(buf);
		buf.F = i;
		buf.S.F = c;
		buf.S.S = d;
		data2.emplace_back(buf);


		buf.F = d;
		buf.S.F = c;
		buf.S.S = i;
		data3.emplace_back(buf);
		buf.F = i;
		buf.S.F = a;
		buf.S.S = b;
		data4.emplace_back(buf);


	}
	sort(data1.begin(),data1.end(),std::greater<Plll>());
	sort(data3.begin(),data3.end(),std::greater<Plll>());
	
	priority_queue<Pll, vector<Pll>> q;
	multiset<SINT64> st1;
	multiset<SINT64> st2;
	multiset<SINT64> st3;
	multiset<SINT64> st4;

	rep(i,0,N) {
		while(1) {
			if (q.size() == 0) break;
			Pll buf = q.top();
			if (buf.F > data1[i].F) {
				q.pop();
				st1.erase(data2[buf.S].S.F);
				st2.erase(data2[buf.S].S.S);
				if (st1.size() != 0) {
				if (*st1.rbegin() > *st2.begin()) {
					put("NO");
					return 0;				
				}
				}

			} else {
				break;
			}
		}
		q.push(Pll(data1[i].S.F, data1[i].S.S));
		st1.insert(data2[data1[i].S.S].S.F);
		st2.insert(data2[data1[i].S.S].S.S);

		if (st1.size() != 0) {
			if (*st1.rbegin() > *st2.begin()) {
				put("NO");
				return 0;				
			}
		}
	}

	while(1) {
		if (q.size() == 0) break;
		Pll buf = q.top();
		q.pop();
		st1.erase(data2[buf.S].S.F);
		st2.erase(data2[buf.S].S.S);
		if (st1.size() != 0) {
			if (*st1.rbegin() > *st2.begin()) {
				put("NO");
				return 0;				
			}
		}
	}


	rep(i,0,N) {
		while(1) {
			if (q.size() == 0) break;
			Pll buf = q.top();
			if (buf.F > data3[i].F) {
				q.pop();
				st3.erase(data4[buf.S].S.F);
				st4.erase(data4[buf.S].S.S);
				if (st3.size() != 0) {
				if (*st3.rbegin() > *st4.begin()) {
					put("NO");
					return 0;				
				}
				}

			} else {
				break;
			}
		}
		q.push(Pll(data3[i].S.F, data3[i].S.S));
		st3.insert(data4[data3[i].S.S].S.F);
		st4.insert(data4[data3[i].S.S].S.S);

		if (st3.size() != 0) {
			if (*st3.rbegin() > *st4.begin()) {
				put("NO");
				return 0;				
			}
		}
	}

	while(1) {
		if (q.size() == 0) break;
		Pll buf = q.top();
		q.pop();
		st3.erase(data4[buf.S].S.F);
		st4.erase(data4[buf.S].S.S);
		if (st3.size() != 0) {
			if (*st3.rbegin() > *st4.begin()) {
				put("NO");
				return 0;				
			}
		}
	}
	put("YES");
	return 0;
}








































































































































