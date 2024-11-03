
























using namespace std;

int x,n,ans=1;
set<int> L,M,R;

int main() {

	


	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		char s[20];

		scanf("%s %d",s+1,&x);

		if(s[2]=='C') {

			if((sz(L) && x<*L.rbegin()) || (sz(R) && x>*R.begin())) {

				printf("0");

				return 0;

			}

			if(sz(L) && x==*L.rbegin()) {

				L.erase(L.find(x));

				for(auto val:M) R.insert(val);

				M.clear();

			}
			else if(sz(R) && x==*R.begin()) {

				R.erase(R.find(x));

				for(auto val:M) L.insert(val);

				M.clear();

			}
			else {

				ans=ans*2%MOD;

				for(auto val:M) {

					if(val<x) L.insert(val);
					if(val>x) R.insert(val);

				}

				M.clear();

			}

		}
		else {

			if(sz(L) && x<*L.rbegin()) L.insert(x);
			else if(sz(R) && x>*R.begin()) R.insert(x);
			else M.insert(x);

		}

	}

	if(sz(M)) ans=1ll*ans*(sz(M)+1)%MOD;

	printf("%d",ans);

}
