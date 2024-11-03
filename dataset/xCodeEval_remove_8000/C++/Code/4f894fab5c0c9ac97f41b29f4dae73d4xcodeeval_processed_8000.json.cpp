




using namespace std;








void nice(){
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        string str;
        cin >> str;
        rep(i,0,k){
            if(str[i] == 'L')cout << 'L' ;
            else if(str[i] == 'R')cout << 'R';
            else if(str[i] == 'U')cout << 'D';
            else cout << 'U';
        }
        cout << endl;
    }
}
int main () {
    nice();
	

	

	

	

}