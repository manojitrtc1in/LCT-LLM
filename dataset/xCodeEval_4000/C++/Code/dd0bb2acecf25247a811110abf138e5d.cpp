#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

pair<int,string> p1(string s){
	string p = "RGB";
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

pair<int,string> p2(string s){
	string p = "BRG";
	
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

pair<int,string> p3(string s){
	string p = "GBR";
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

pair<int,string> p4(string s){
	string p = "RBG";
	
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

pair<int,string> p5(string s){
	string p = "GRB";
	
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

pair<int,string> p6(string s){
	string p = "BGR";
	
	
	int n = s.size();
	
	if(n == 1){
		cout << "0\n";
		cout << s << endl;
		exit(0);
	}
	if(n == 2 && s[0] == s[1]){
		if(s[0] == 'R') s[1] = 'G';
		if(s[0] == 'G') s[1] = 'R';
		if(s[0] == 'B') s[1] = 'R';
		cout << "1" << endl;
		cout << s;
		exit(0);
	}
	else if(n == 2 && s[0] != s[1]){
		cout << "0\n";
		cout << s;
		exit(0);
	}
	
	int resto = n%3;
	int t = n/3;
	t *= 3;
	string aux = s;
	
	if(resto == 0){
		int a = 0;
		for(int i = 0;i < n;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		return {a,s};
	}
	if(resto == 1){
		int a = 0, b = 0;
		string a1,b1;
		

		for(int i = 0;i < n-1;i++)
			if(p[i%3] != s[i]){
				a++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		

		a1 = s;
		s = aux;
		for(int i = 1;i < n;i++)
			if(p[(i-1)%3] != s[i]){
				b++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			b++;
			s[0] = p[2];
		}
		b1 = s;
		
		if(a < b) return {a,a1};
		else return {b,b1};	
	}
	if(resto == 2){
		int a = 0, b = 0, c = 0;
		string a1,b1,c1;
		

		for(int i = 1;i < n-1;i++)
			if(p[(i-1)%3] != s[i]){
				a++;
				s[i] = p[(i-1)%3];
			}
		if(s[0] != p[2]){
			a++;
			s[0] = p[2];
		}
		if(s[n-1] != p[0]){
			a++;
			s[n-1] = p[0];
		}
		a1 = s;
		s = aux;
		

		for(int i = 0;i < n-2;i++)
			if(p[i%3] != s[i]){
				b++;
				s[i] = p[i%3];
			}
		if(s[n-1] != p[1]){
			b++;
			s[n-1] = p[1];
		}
		if(s[n-2] != p[0]){
			b++;
			s[n-2] = p[0];
		}
		b1 = s;
		s = aux;
		

		for(int i = 2;i < n;i++)
			if(p[(i-2)%3] != s[i]){
				c++;
				s[i] = p[(i-2)%3];
			}
		if(s[0] != p[1]){
			c++;
			s[0] = p[1];
		}
		if(s[1] != p[2]){
			c++;
			s[1] = p[2];
		}
		c1 = s;
		if(a <= b && a <= c){
			return {a,a1};
		}
		if(b <= a && b <= c){
			return {b,b1};
		}
		if(c <= a && c <= b){
			return {c,c1};
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int c1,c2,c3;
	
	c1 = c2 = c3 = INF;
	
	pair<int,string> a = p1(s), b = p2(s), c = p3(s), d = p4(s), e = p5(s), f = p6(s);
	
	if(c1 <= c2 && c1 <= c3 && c1 <= b.first && c1 <= c.first && c1 <= d.first && c1 <= e.first && c1 <= f.first && c1 <= a.first){
		cout << c1 << endl;
		for(int i = 0;i < s.size();i++)
			cout << "R";
	}
	if(c2 <= c1 && c2 <= c3 && c2 <= b.first && c2 <= c.first && c2 <= d.first && c2 <= e.first && c2 <= f.first && c2 <= a.first){
		cout << c2 << endl;
		for(int i = 0;i < s.size();i++)
			cout << "G";
	}
	if(c3 <= c2 && c3 <= c1 && c3 <= b.first && c3 <= c.first && c3 <= d.first && c3 <= e.first && c3 <= f.first && c3 <= a.first){
		cout << c3 << endl;
		for(int i = 0;i < s.size();i++)
			cout << "B";
	}
		
	
	
	if(a.first <= b.first && a.first <= c.first && a.first <= d.first && a.first <= e.first && a.first <= f.first && a.first <= c1 && a.first <= c2 && a.first <= c3){
		cout << a.first << endl;
		cout << a.second;
	}
	else if(b.first <= a.first && b.first <= c.first && b.first <= d.first && b.first <= e.first && b.first <= f.first && b.first <= c1 && b.first <= c2 && b.first <= c3){
		cout << b.first << endl;
		cout << b.second;
	}
	else if(c.first <= b.first && c.first <= a.first && c.first <= d.first && c.first <= e.first && c.first <= f.first && c.first <= c1 && c.first <= c2 && c.first <= c3){
		cout << c.first << endl;
		cout << c.second;
	}
	else if(d.first <= b.first && d.first <= c.first && d.first <= a.first && d.first <= e.first && d.first <= f.first && d.first <= c1 && d.first <= c2 && d.first <= c3){
		cout << d.first << endl;
		cout << d.second;
	}
	else if(e.first <= b.first && e.first <= c.first && e.first <= a.first && e.first <= d.first && e.first <= f.first && e.first <= c1 && e.first <= c2 && e.first <= c3){
		cout << e.first << endl;
		cout << e.second;
	}
	else if(f.first <= b.first && f.first <= c.first && f.first <= a.first && f.first <= e.first && f.first <= d.first && f.first <= c1 && f.first <= c2 && f.first <= c3){
		cout << f.first << endl;
		cout << f.second;
	}
}