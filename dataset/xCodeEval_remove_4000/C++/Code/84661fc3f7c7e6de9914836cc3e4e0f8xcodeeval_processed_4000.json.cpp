




using namespace std;

long long int obvio(vector<pair<long long int,unsigned>> saltos, unsigned k, unsigned n){
	if(k==1){return 0;}
	unsigned t = saltos.size();
	unsigned id13 = saltos[0].second, id5 = saltos[t-1].second;
	long long int abajo=0 , arriba=0, medio=0;
	bool bandera =false;
	
	unsigned i=1;
	while(id13<k){
		abajo += id13*(saltos[i].first-saltos[i-1].first);
		id13 += saltos[i].second;
		i++;
	}
	abajo -= (id13-k);
	i=1;
	while(id5<k){
		arriba += id5*(saltos[t-i].first-saltos[t-i-1].first);
		id5 += saltos[t-1-i].second;
		i++;
	}
	arriba -= (id5-k);
	if(2*saltos[0].second < n && 2*saltos[t-1].second < n && 2*k > n){
		bandera =true;
		unsigned id8=saltos[0].second, id14=saltos[t-1].second;
		i=1;
		while(2*(id8)<n && 2*(id14)<n){
			medio += id8*(saltos[i].first-saltos[i-1].first);
			id8 += saltos[i].second;
			medio += id14*(saltos[t-i].first-saltos[t-i-1].first);
			id14 += saltos[t-1-i].second;
			i++;
		}
		unsigned j=i;
		if(2*(id8)>=n){
			while(i-1 <= t-1-j){
				medio += id14*(saltos[t-j].first-saltos[t-j-1].first);
				id14 += saltos[t-1-j].second;
				j++;				
			}		
		}
		else{
			while(j-1 <= t-1-i){
				medio += id8*(saltos[j].first-saltos[j-1].first);
				id8 += saltos[j].second;
				j++;				
			}
		}
	medio -= (n-k);
	}
	if(bandera){
		if(medio <= abajo && medio <= arriba){return medio;}
		else{if(abajo<=arriba){return abajo;}
			else{return arriba;}}		
	}
	if(abajo<=arriba){return abajo;}
	else{return arriba;}
}





tuple<int,int,int> id0(int k, vector<pair<unsigned,unsigned>> &saltos, int i , int j, int id9, int id18, vector<vector<tuple<int,int,int,bool>>> &caja){
	if(get<3>(caja[i][j])){return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));}
	int t = saltos.size();
	if (i==id9-1 || j==id18-1 || i+j == t-1)
	{
		int id13 =0;
		for (int abcd = 0; abcd <= i ; abcd++)
		{
			id13 += saltos[abcd].second;
		}
		
		int id5 = 0;
		for (int abcd = 0; abcd <= j ; abcd++)
		{
			id5 += saltos[t-1-abcd].second;
		}
		
		if(i+j==t-1){caja[i][j] = make_tuple(k-id5-id13+saltos[i].second,id13,id5,true);}
		else{if(i==id9-1){caja[i][j] = make_tuple(k-id13,id13,id5,true);}
		else{if(j==id18-1){caja[i][j] = make_tuple(k-id5,id13,id5,true);}}}
		

		return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));
	}
	tuple<int,int,int> id4 = id0(k,saltos,i+1,j,id9,id18,caja), id2 = id0(k,saltos,i,j+1,id9,id18,caja);
	int id1 = (get<1>(id4)-saltos[i+1].second)*(saltos[i+1].first-saltos[i].first);
	int id11 = (get<2>(id2)-saltos[t-1-j-1].second)*(saltos[t-1-j].first-saltos[t-1-j-1].first);
	if(id1 + get<0>(id4) < id11 + get<0>(id2)){caja[i][j] = make_tuple(id1 + get<0>(id4),get<1>(id4)-saltos[i+1].second,get<2>(id4),true);}
	else{caja[i][j] = make_tuple(id11 + get<0>(id2),get<1>(id2),get<2>(id2)-saltos[t-1-j-1].second,true);}

	

	return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));
}


int id12(vector<int> a, int k){
	int n = a.size();
	vector<pair<int,int>> saltos(0);
	int id16=-1;
	pair<int,int> id17;
	for (int i = 1; i < n; i++)
	{
		if(a[i]!=a[i-1]){
			if(i-1-id16 >= k){return 0;};
			id17 = make_pair(a[i-1],i-1-id16);
			saltos.push_back(id17);
			id16=i-1;
		}
	}
	if(n-1-id16 >= k){return 0;};
	id17 = make_pair(a[n-1],n-1-id16);
	saltos.push_back(id17);
	int t = saltos.size();
	if(t==1){return 0;}
	if(t==2){
		int d = saltos[1].first-saltos[0].first,
		abcd = saltos[0].second;
		if(2*abcd < n){return (d-1)*abcd+(k-(n-abcd));}
		else{return (d-1)*(n-abcd)+(k-abcd);}
	}
	int id13 =0, id5=0;
	int suma=0, id3=0, id9=0, id18=0;
	int id15 = n-saltos[t-1].second, id6 = n-saltos[0].second;
	bool id10 = true;
	if (k<=id15)
	{
		for (int i = 0; suma < k; i++)
		{
			suma += saltos[i].second;
			id9=i;
			if(i!=0){id13 +=(saltos[i].first-saltos[i-1].first)*(suma-saltos[i].second);}
		};
		if(id9!=0){id13 -= (suma-k);}
	}
	else
		{
			id10 = false;
			vector<int> I(t,0), S(t,0);
			for (int i = 1; i < t; i++)
			{
				suma += saltos[i-1].second;
				I[i] += suma*(saltos[i].first-saltos[i-1].first);
				I[i] += I[i-1];
			}
			for (int i = t-2; i >= 0 ;
			
			 i--)
			{
				id3 += saltos[i+1].second;
				S[i] += id3*(saltos[i+1].first-saltos[i].first);
				S[i] += S[i+1];
			}
			id13 = I[0]+S[0];
			for (int i = 0; i < t; i++)
			{
				if(id13 > I[i]+S[i]){id13 = I[i]+S[i];}
			}
			id13 -= (n-k);
		}
	suma=0; id3=0;
	if(k<=id6)
	{
		for (int i = t-1; suma < k; i--) 

		{
			suma += saltos[i].second;
			id18=i;
			if(i!=t-1){id5 +=(saltos[i+1].first-saltos[i].first)*(suma-saltos[i].second);} 

		}
		if(id18!=t-1){id5 -= (suma-k);} 

	}
	else
	{
		if(id10){
			vector<int> I(t,0), S(t,0);
			for (int i = 1; i < t; i++)
			{
				suma += saltos[i-1].second;
				I[i] += suma*(saltos[i].first-saltos[i-1].first);
				I[i] += I[i-1];
			}
			for (int i = t-2; i >= 0 ; i--)
			{
				id3 += saltos[i+1].second;
				S[i] += id3*(saltos[i+1].first-saltos[i].first);
				S[i] += S[i+1];
			}
			id5 = I[0]+S[0];
			for (int i = 0; i < t; i++)
			{
				if(id5 > I[i]+S[i]){id5 = I[i]+S[i];}
			}
			id5 -= (n-k);
		}else{id5=id13;}
	}
	if(id5<id13){return id5;}
	else{return id13;}

}


unsigned id7(unsigned &k, vector<pair<unsigned,unsigned>> &saltos, unsigned n){
	unsigned t= saltos.size();
	if(t==1){return 0;}
	
	vector<pair<unsigned,unsigned>> b=saltos;
	unsigned id2=0, id4=0;
	if (saltos[0].second+saltos[1].second < k)
	{
		if(2*(b[0].second+b[1].second) > n)
		{
			id4 += b[0].second*(b[1].first-b[0].first);
			b[1].second += b[0].second;
			b.erase(b.begin());	
		}
		while(b[0].second+b[1].second < k && 2*(b[0].second+b[1].second) <= n)
		{
			id4 += b[0].second*(b[1].first-b[0].first);
			b[1].second += b[0].second;
			b.erase(b.begin());
		}
		id4 += id7(k,b,n);
	}
	else
	{
		id4 = saltos[0].second*(saltos[1].first-saltos[0].first);
		id4 -= (saltos[0].second+saltos[1].second-k);
	}


	if (saltos[t-1].second+saltos[t-2].second < k)
	{
		if (2*(saltos[t-1].second+saltos[t-2].second) > n)
		{
			id2 += saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
			saltos[t-2].second += saltos[t-1].second;
			saltos.erase(saltos.end());
		}
		while(saltos[t-1].second+saltos[t-2].second < k && 2*(saltos[t-1].second+saltos[t-2].second) <= n)
		{
			id2 += saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
			saltos[t-2].second += saltos[t-1].second;
			saltos.erase(saltos.end());
			t--;
		}
		id2 += id7(k,saltos,n);
	}
	else
	{
		id2 = saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
		id2 -= (saltos[t-1].second+saltos[t-2].second-k);
	}


	if(id2 < id4){return id2;}
	else{return id4;}




	
}


int main(){
	unsigned n=0, k=0;
	cin >> n >> k;
	vector<long long int> a(0);
	long long int numero =0;
	for (unsigned i = 0; i < n; i++)
	{
		cin >> numero;
		a.push_back(numero);
	}
	sort(a.begin(),a.end());

	vector<pair<long long int,unsigned>> saltos(0);
	int id16=-1;
	for (unsigned i = 1; i < n; i++)
	{
		if(a[i]!=a[i-1]){
			if(i-1-id16 >= k){k=1;};
			saltos.push_back(make_pair(a[i-1]-a[0],i-1-id16));
			id16=i-1;
		}
	}
	if(n-1-id16 >= k){k=1;};
	saltos.push_back(make_pair(a[n-1]-a[0],n-1-id16));
	if(k==1){cout << 0; return 0;}
	cout << obvio(saltos,k,n);
}
	
	
	
