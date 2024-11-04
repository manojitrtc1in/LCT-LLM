


















using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, int, int> lii;


template<typename T> ostream& operator<<(ostream &s,vector<T> vec){for(auto &v: vec){s<<v<<" ";}return s;}
template<typename T> void print(T v){cout<<v<<"\n";}
template<typename T> void prints(T v){cout<<v<<"\n";}
template<typename T, typename... Args> void print(T first, Args... args){cout<<first<<" ";print(args...);}
template<typename T, typename... Args> void prints(T first, Args... args){cout<<first<<" | ";prints(args...);}






	

	

	

	





	

	

	

	



























pair<string, int> finalString(vector<int> aCount, vector<int> bCount, vector<int> cCount, string &b, string &c){
	vector<int> id0 = aCount;
	
	int id1 = 99999999;
	
	for(int i=0; i<bCount.size(); ++i){
		if(bCount[i]) id1 = min(id1, aCount[i] / bCount[i]);
	}
	
	
	int id2 = 99999999;
	
	for(int i=0; i<cCount.size(); ++i){
		if(cCount[i]) id2 = min(id2, aCount[i] / cCount[i]);
	}
	
	int maxCount = max(id1, id2);
	if(maxCount == id2) {
		swap(b,c);
		swap(bCount, cCount);
	}
	
	

	int ansCount = 0, finalB = 0, finalC = 0;
	
	

	
	for(int i=1; i<=maxCount; ++i){
		

		

		int countB = i;
		

		for(int i=0; i<bCount.size(); ++i){
			if(bCount[i]) aCount[i] -= bCount[i];
		}
		

		int countC = 99999999;
		for(int i=0; i<cCount.size(); ++i){
			if(cCount[i]) countC = min(countC, aCount[i] / cCount[i]);
		}
		
		if((countB + countC) > ansCount){
			ansCount = countB + countC;
			finalB = countB;
			finalC = countC;
		}
		

	}
	string ansString="";
	for(int i=0; i<finalB; ++i){
		ansString += b;
	}
	

	for(int i=0; i<finalC; ++i){
		ansString += c;
	}
	

	for(int i=0; i<id0.size(); ++i){
		id0[i] -= finalB*bCount[i] + finalC*cCount[i];
		

		while(id0[i]--){
			ansString += (i+'a');
		}
	}
	

	return make_pair(ansString, ansCount);
}

int main(){
	fastio;
	string a,b,c;
	cin>>a>>b>>c;
	

	vector<vector<int>> count(3, vector<int>(26,0));
	for(auto ch : a){
		count[0][ch-'a']++;
	}
	for(auto ch : b){
		count[1][ch-'a']++;
	}
	for(auto ch : c){
		count[2][ch-'a']++;
	}
	
	

	
	

		

	

	
	
	

	
	

		

	

	
	

	auto ans = finalString(count[0], count[1], count[2], b, c);
	cout<<ans.first;
}