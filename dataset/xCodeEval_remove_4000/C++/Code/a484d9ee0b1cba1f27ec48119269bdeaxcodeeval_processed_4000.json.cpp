










using namespace std;



 


 




int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll p;
        cin >> p;
        if(p==5)
        {
            cout << 2 << " " << 4 << endl;
        }
        else{
            ll k = p - 1;
            cout << 2 << " " << k / 2 << endl;
        }
    }
    

    return 0;
}