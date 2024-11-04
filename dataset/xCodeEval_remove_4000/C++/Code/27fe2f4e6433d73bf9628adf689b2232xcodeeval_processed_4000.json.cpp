










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	deque<int> a;
	pair<int, int> ans[MAXN];
	int t[MAXN],maxa=-INF,last;
	int n, q;
	sd(n); sd(q);
	fi(0, n)
	{
		int t;
		sd(t);
		a.push_back(t);
		maxa = max(maxa, t);
		if (t == maxa)
			last = i;
	}
	fi(0, last)
	{
		int A, B;
		A = a.front();
		a.pop_front();
		B = a.front();
		a.pop_front();
		ans[i] = pair<int, int>(A, B);
		if (A < B)
			swap(A, B);
		a.push_front(A);
		a.push_back(B);
	}
 	fi(0, q)
	{
		vt2 qu;
		scanf("%llu", &qu);
		if (qu <= last)
			cout << ans[qu-1].first <<' '<<ans[qu-1].second << endl;
		else
		{
			vt2 te = (qu - last-1) % (n - 1) + 1;
			cout << maxa << " " << a[te] << endl;
		}
	}
}
