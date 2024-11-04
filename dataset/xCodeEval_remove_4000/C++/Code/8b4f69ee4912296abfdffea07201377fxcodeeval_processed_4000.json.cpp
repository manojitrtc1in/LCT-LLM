












using namespace std;
typedef long long ll;

struct Expr
{
	int table;
	char last;
	string s;
};














































































































































































































string sol[256] = {
"!x&x"
,"x&y&z"
,"!z&x&y"
,"x&y"
,"!y&x&z"
,"x&z"
,"!y&x&z|!z&x&y"
,"(y|z)&x"
,"!y&!z&x"
,"!y&!z&x|x&y&z"
,"!z&x"
,"!z&x|x&y"
,"!y&x"
,"!y&x|x&z"
,"!(y&z)&x"
,"x"
,"!x&y&z"
,"y&z"
,"!x&y&z|!z&x&y"
,"(x|z)&y"
,"!x&y&z|!y&x&z"
,"(x|y)&z"
,"!x&y&z|!y&x&z|!z&x&y"
,"(x|y)&z|x&y"
,"!x&y&z|!y&!z&x"
,"!y&!z&x|y&z"
,"!x&y&z|!z&x"
,"!z&x|y&z"
,"!x&y&z|!y&x"
,"!y&x|y&z"
,"!(y&z)&x|!x&y&z"
,"x|y&z"
,"!x&!z&y"
,"!x&!z&y|x&y&z"
,"!z&y"
,"!z&y|x&y"
,"!x&!z&y|!y&x&z"
,"!x&!z&y|x&z"
,"!y&x&z|!z&y"
,"!z&y|x&z"
,"!(!x&!y|x&y|z)"
,"!(!x&!y|x&y|z)|x&y&z"
,"!z&(x|y)"
,"!z&(x|y)|x&y"
,"!x&!z&y|!y&x"
,"!x&!z&y|!y&x|x&z"
,"!y&x|!z&y"
,"!z&y|x"
,"!x&y"
,"!x&y|y&z"
,"!(x&z)&y"
,"y"
,"!x&y|!y&x&z"
,"!x&y|x&z"
,"!(x&z)&y|!y&x&z"
,"x&z|y"
,"!x&y|!y&!z&x"
,"!x&y|!y&!z&x|y&z"
,"!x&y|!z&x"
,"!z&x|y"
,"!x&y|!y&x"
,"!x&y|!y&x|x&z"
,"!(x&z)&y|!y&x"
,"x|y"
,"!x&!y&z"
,"!x&!y&z|x&y&z"
,"!x&!y&z|!z&x&y"
,"!x&!y&z|x&y"
,"!y&z"
,"!y&z|x&z"
,"!y&z|!z&x&y"
,"!y&z|x&y"
,"!(!x&!z|x&z|y)"
,"!(!x&!z|x&z|y)|x&y&z"
,"!x&!y&z|!z&x"
,"!x&!y&z|!z&x|x&y"
,"!y&(x|z)"
,"!y&(x|z)|x&z"
,"!y&z|!z&x"
,"!y&z|x"
,"!x&z"
,"!x&z|y&z"
,"!x&z|!z&x&y"
,"!x&z|x&y"
,"!(x&y)&z"
,"z"
,"!(x&y)&z|!z&x&y"
,"x&y|z"
,"!x&z|!y&!z&x"
,"!x&z|!y&!z&x|y&z"
,"!x&z|!z&x"
,"!x&z|!z&x|x&y"
,"!x&z|!y&x"
,"!y&x|z"
,"!(x&y)&z|!z&x"
,"x|z"
,"!(!y&!z|x|y&z)"
,"!(!y&!z|x|y&z)|x&y&z"
,"!x&!y&z|!z&y"
,"!x&!y&z|!z&y|x&y"
,"!x&!z&y|!y&z"
,"!x&!z&y|!y&z|x&z"
,"!y&z|!z&y"
,"!y&z|!z&y|x&y"
,"!(!x&!y|x&y|z)|!x&!y&z"
,"!(!x&!y|x&y|z)|!x&!y&z|x&y&z"
,"!x&!y&z|!z&(x|y)"
,"!x&!y&z|!z&(x|y)|x&y"
,"!x&!z&y|!y&(x|z)"
,"!x&!z&y|!y&(x|z)|x&z"
,"!y&(x|z)|!z&y"
,"!y&z|!z&y|x"
,"!x&(y|z)"
,"!x&(y|z)|y&z"
,"!x&z|!z&y"
,"!x&z|y"
,"!x&y|!y&z"
,"!x&y|z"
,"!(x&y)&z|!z&y"
,"y|z"
,"!x&(y|z)|!y&!z&x"
,"!x&(y|z)|!y&!z&x|y&z"
,"!x&(y|z)|!z&x"
,"!x&z|!z&x|y"
,"!x&(y|z)|!y&x"
,"!x&y|!y&x|z"
,"!x&y|!y&z|!z&x"
,"x|y|z"
,"!(x|y|z)"
,"!(x|y|z)|x&y&z"
,"!(!x&y|!y&x|z)"
,"!(x|y|z)|x&y"
,"!(!x&z|!z&x|y)"
,"!(x|y|z)|x&z"
,"!(!x&y|!y&x|z)|!y&x&z"
,"!(x|y|z)|(y|z)&x"
,"!y&!z"
,"!y&!z|x&y&z"
,"!(!x&y|z)"
,"!y&!z|x&y"
,"!(!x&z|y)"
,"!y&!z|x&z"
,"!(!x&y|z)|!y&x"
,"!y&!z|x"
,"!(!y&z|!z&y|x)"
,"!(x|y|z)|y&z"
,"!(!x&y|!y&x|z)|!x&y&z"
,"!(x|y|z)|(x|z)&y"
,"!(!x&z|!z&x|y)|!x&y&z"
,"!(x|y|z)|(x|y)&z"
,"!(!x&y|!y&x|z)|!x&y&z|!y&x&z"
,"!(x|y|z)|(x|y)&z|x&y"
,"!x&y&z|!y&!z"
,"!y&!z|y&z"
,"!(!x&y|z)|!x&y&z"
,"!(!x&y|z)|y&z"
,"!(!x&z|y)|!x&y&z"
,"!(!x&z|y)|y&z"
,"!(!x&y|z)|!x&y&z|!y&x"
,"!y&!z|x|y&z"
,"!x&!z"
,"!x&!z|x&y&z"
,"!(!y&x|z)"
,"!x&!z|x&y"
,"!x&!z|!y&x&z"
,"!x&!z|x&z"
,"!(!y&x|z)|!y&x&z"
,"!(!y&x|z)|x&z"
,"!(x&y|z)"
,"!(x&y|z)|x&y&z"
,"!z"
,"!z|x&y"
,"!x&!z|!y&x"
,"!(x&y|z)|x&z"
,"!y&x|!z"
,"!z|x"
,"!(!y&z|x)"
,"!x&!z|y&z"
,"!(!y&x|z)|!x&y"
,"!x&!z|y"
,"!(!y&z|x)|!y&x&z"
,"!(!y&z|x)|x&z"
,"!(!y&x|z)|!x&y|!y&x&z"
,"!x&!z|x&z|y"
,"!x&y|!y&!z"
,"!(x&y|z)|y&z"
,"!x&y|!z"
,"!z|y"
,"!(!x&!y&z|x&y)"
,"!x&!z|!y&x|y&z"
,"!x&y|!y&x|!z"
,"!z|x|y"
,"!x&!y"
,"!x&!y|x&y&z"
,"!x&!y|!z&x&y"
,"!x&!y|x&y"
,"!(!z&x|y)"
,"!x&!y|x&z"
,"!(!z&x|y)|!z&x&y"
,"!(!z&x|y)|x&y"
,"!(x&z|y)"
,"!(x&z|y)|x&y&z"
,"!x&!y|!z&x"
,"!(x&z|y)|x&y"
,"!y"
,"!y|x&z"
,"!y|!z&x"
,"!y|x"
,"!(!z&y|x)"
,"!x&!y|y&z"
,"!(!z&y|x)|!z&x&y"
,"!(!z&y|x)|x&y"
,"!(!z&x|y)|!x&z"
,"!x&!y|z"
,"!(!z&x|y)|!x&z|!z&x&y"
,"!x&!y|x&y|z"
,"!x&z|!y&!z"
,"!(x&z|y)|y&z"
,"!(!x&!z&y|x&z)"
,"!x&!y|!z&x|y&z"
,"!x&z|!y"
,"!y|z"
,"!x&z|!y|!z&x"
,"!y|x|z"
,"!(x|y&z)"
,"!(x|y&z)|x&y&z"
,"!x&!y|!z&y"
,"!(x|y&z)|x&y"
,"!x&!z|!y&z"
,"!(x|y&z)|x&z"
,"!(!y&!z&x|y&z)"
,"!x&!y|!z&y|x&z"
,"!((x|y)&z|x&y)"
,"!((x|y)&z|x&y)|x&y&z"
,"!x&!y|!z"
,"!x&!y|!z|x&y"
,"!x&!z|!y"
,"!x&!z|!y|x&z"
,"!y|!z"
,"!y|!z|x"
,"!x"
,"!x|y&z"
,"!x|!z&y"
,"!x|y"
,"!x|!y&z"
,"!x|z"
,"!x|!y&z|!z&y"
,"!x|y|z"
,"!x|!y&!z"
,"!x|!y&!z|y&z"
,"!x|!z"
,"!x|!z|y"
,"!x|!y"
,"!x|!y|z"
,"!(x&y&z)"
,"!x|x"
};

int main()
{
	ios::sync_with_stdio(false);

	

	

	

	

	

	


	

	

	

	

	


	

	

	

	

	


	

	

	

	


	

	

	

	

	

	


	

	

	

	

	

	

	

	

	


	


	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	


	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i)
	{
		int x, y = 0;
		cin >> x;
		for(int j=0; j<8; ++j)
		{
			y += (x%10)<<j;
			x /= 10;
		}
		cout << sol[y] << "\n";
	}

	return 0;
}
