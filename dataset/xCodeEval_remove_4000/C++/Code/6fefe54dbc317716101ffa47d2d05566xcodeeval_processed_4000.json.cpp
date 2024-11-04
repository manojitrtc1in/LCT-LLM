


































using namespace std;
vector<pair<string,int> > w;
int main(){
	string k;
	getline(cin,k);
	string buff="";
	for (int i=0;i<k.length();i++){
		if (k[i]>='0' && k[i]<='9'){
			string num;
			int point=i;
			while (k[point]>='0' && k[point]<='9'){
				num=num+k[point];
				point++; 
			}
			w.push_back(make_pair(num,0));
			i=point-1;
		}
		else if (k[i]=='.'){
			i+=2;
			w.push_back(make_pair("...",1));
		}
		else if (k[i]==','){
			w.push_back(make_pair(",",2));
		}
	}
	buff=buff+w[0].first;
	for (int i=1;i<w.size();i++){
		if (w[i-1].second==2 || w[i].second==1 || (w[i].second+w[i-1].second==0)){
			buff=buff+' ';
		}
		buff=buff+w[i].first;
	} 
	printf("%s\n",buff.c_str());
	return 0;
}