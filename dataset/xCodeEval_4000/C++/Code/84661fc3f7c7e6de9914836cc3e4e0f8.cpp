#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

long long int obvio(vector<pair<long long int,unsigned>> saltos, unsigned k, unsigned n){
	if(k==1){return 0;}
	unsigned t = saltos.size();
	unsigned sumaAbajo = saltos[0].second, sumaArriba = saltos[t-1].second;
	long long int abajo=0 , arriba=0, medio=0;
	bool bandera =false;
	
	unsigned i=1;
	while(sumaAbajo<k){
		abajo += sumaAbajo*(saltos[i].first-saltos[i-1].first);
		sumaAbajo += saltos[i].second;
		i++;
	}
	abajo -= (sumaAbajo-k);
	i=1;
	while(sumaArriba<k){
		arriba += sumaArriba*(saltos[t-i].first-saltos[t-i-1].first);
		sumaArriba += saltos[t-1-i].second;
		i++;
	}
	arriba -= (sumaArriba-k);
	if(2*saltos[0].second < n && 2*saltos[t-1].second < n && 2*k > n){
		bandera =true;
		unsigned sumaMedAbajo=saltos[0].second, sumaMedArriba=saltos[t-1].second;
		i=1;
		while(2*(sumaMedAbajo)<n && 2*(sumaMedArriba)<n){
			medio += sumaMedAbajo*(saltos[i].first-saltos[i-1].first);
			sumaMedAbajo += saltos[i].second;
			medio += sumaMedArriba*(saltos[t-i].first-saltos[t-i-1].first);
			sumaMedArriba += saltos[t-1-i].second;
			i++;
		}
		unsigned j=i;
		if(2*(sumaMedAbajo)>=n){
			while(i-1 <= t-1-j){
				medio += sumaMedArriba*(saltos[t-j].first-saltos[t-j-1].first);
				sumaMedArriba += saltos[t-1-j].second;
				j++;				
			}		
		}
		else{
			while(j-1 <= t-1-i){
				medio += sumaMedAbajo*(saltos[j].first-saltos[j-1].first);
				sumaMedAbajo += saltos[j].second;
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





tuple<int,int,int> operacionesDP(int k, vector<pair<unsigned,unsigned>> &saltos, int i , int j, int topeAbajo, int topeArriba, vector<vector<tuple<int,int,int,bool>>> &caja){
	if(get<3>(caja[i][j])){return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));}
	int t = saltos.size();
	if (i==topeAbajo-1 || j==topeArriba-1 || i+j == t-1)
	{
		int sumaAbajo =0;
		for (int abcd = 0; abcd <= i ; abcd++)
		{
			sumaAbajo += saltos[abcd].second;
		}
		
		int sumaArriba = 0;
		for (int abcd = 0; abcd <= j ; abcd++)
		{
			sumaArriba += saltos[t-1-abcd].second;
		}
		
		if(i+j==t-1){caja[i][j] = make_tuple(k-sumaArriba-sumaAbajo+saltos[i].second,sumaAbajo,sumaArriba,true);}
		else{if(i==topeAbajo-1){caja[i][j] = make_tuple(k-sumaAbajo,sumaAbajo,sumaArriba,true);}
		else{if(j==topeArriba-1){caja[i][j] = make_tuple(k-sumaArriba,sumaAbajo,sumaArriba,true);}}}
		

		return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));
	}
	tuple<int,int,int> operoAbajo = operacionesDP(k,saltos,i+1,j,topeAbajo,topeArriba,caja), operoArriba = operacionesDP(k,saltos,i,j+1,topeAbajo,topeArriba,caja);
	int opNecAbajo = (get<1>(operoAbajo)-saltos[i+1].second)*(saltos[i+1].first-saltos[i].first);
	int opNecArriba = (get<2>(operoArriba)-saltos[t-1-j-1].second)*(saltos[t-1-j].first-saltos[t-1-j-1].first);
	if(opNecAbajo + get<0>(operoAbajo) < opNecArriba + get<0>(operoArriba)){caja[i][j] = make_tuple(opNecAbajo + get<0>(operoAbajo),get<1>(operoAbajo)-saltos[i+1].second,get<2>(operoAbajo),true);}
	else{caja[i][j] = make_tuple(opNecArriba + get<0>(operoArriba),get<1>(operoArriba),get<2>(operoArriba)-saltos[t-1-j-1].second,true);}

	

	return make_tuple(get<0>(caja[i][j]),get<1>(caja[i][j]),get<2>(caja[i][j]));
}


int ordenarSinDP(vector<int> a, int k){
	int n = a.size();
	vector<pair<int,int>> saltos(0);
	int ultimoSalto=-1;
	pair<int,int> bhsajd;
	for (int i = 1; i < n; i++)
	{
		if(a[i]!=a[i-1]){
			if(i-1-ultimoSalto >= k){return 0;};
			bhsajd = make_pair(a[i-1],i-1-ultimoSalto);
			saltos.push_back(bhsajd);
			ultimoSalto=i-1;
		}
	}
	if(n-1-ultimoSalto >= k){return 0;};
	bhsajd = make_pair(a[n-1],n-1-ultimoSalto);
	saltos.push_back(bhsajd);
	int t = saltos.size();
	if(t==1){return 0;}
	if(t==2){
		int d = saltos[1].first-saltos[0].first,
		abcd = saltos[0].second;
		if(2*abcd < n){return (d-1)*abcd+(k-(n-abcd));}
		else{return (d-1)*(n-abcd)+(k-abcd);}
	}
	int sumaAbajo =0, sumaArriba=0;
	int suma=0, suma2=0, topeAbajo=0, topeArriba=0;
	int limiteAbajo = n-saltos[t-1].second, limiteArriba = n-saltos[0].second;
	bool dosOperaciones = true;
	if (k<=limiteAbajo)
	{
		for (int i = 0; suma < k; i++)
		{
			suma += saltos[i].second;
			topeAbajo=i;
			if(i!=0){sumaAbajo +=(saltos[i].first-saltos[i-1].first)*(suma-saltos[i].second);}
		};
		if(topeAbajo!=0){sumaAbajo -= (suma-k);}
	}
	else
		{
			dosOperaciones = false;
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
				suma2 += saltos[i+1].second;
				S[i] += suma2*(saltos[i+1].first-saltos[i].first);
				S[i] += S[i+1];
			}
			sumaAbajo = I[0]+S[0];
			for (int i = 0; i < t; i++)
			{
				if(sumaAbajo > I[i]+S[i]){sumaAbajo = I[i]+S[i];}
			}
			sumaAbajo -= (n-k);
		}
	suma=0; suma2=0;
	if(k<=limiteArriba)
	{
		for (int i = t-1; suma < k; i--) 

		{
			suma += saltos[i].second;
			topeArriba=i;
			if(i!=t-1){sumaArriba +=(saltos[i+1].first-saltos[i].first)*(suma-saltos[i].second);} 

		}
		if(topeArriba!=t-1){sumaArriba -= (suma-k);} 

	}
	else
	{
		if(dosOperaciones){
			vector<int> I(t,0), S(t,0);
			for (int i = 1; i < t; i++)
			{
				suma += saltos[i-1].second;
				I[i] += suma*(saltos[i].first-saltos[i-1].first);
				I[i] += I[i-1];
			}
			for (int i = t-2; i >= 0 ; i--)
			{
				suma2 += saltos[i+1].second;
				S[i] += suma2*(saltos[i+1].first-saltos[i].first);
				S[i] += S[i+1];
			}
			sumaArriba = I[0]+S[0];
			for (int i = 0; i < t; i++)
			{
				if(sumaArriba > I[i]+S[i]){sumaArriba = I[i]+S[i];}
			}
			sumaArriba -= (n-k);
		}else{sumaArriba=sumaAbajo;}
	}
	if(sumaArriba<sumaAbajo){return sumaArriba;}
	else{return sumaAbajo;}

}


unsigned ordenarDP(unsigned &k, vector<pair<unsigned,unsigned>> &saltos, unsigned n){
	unsigned t= saltos.size();
	if(t==1){return 0;}
	
	vector<pair<unsigned,unsigned>> b=saltos;
	unsigned operoArriba=0, operoAbajo=0;
	if (saltos[0].second+saltos[1].second < k)
	{
		if(2*(b[0].second+b[1].second) > n)
		{
			operoAbajo += b[0].second*(b[1].first-b[0].first);
			b[1].second += b[0].second;
			b.erase(b.begin());	
		}
		while(b[0].second+b[1].second < k && 2*(b[0].second+b[1].second) <= n)
		{
			operoAbajo += b[0].second*(b[1].first-b[0].first);
			b[1].second += b[0].second;
			b.erase(b.begin());
		}
		operoAbajo += ordenarDP(k,b,n);
	}
	else
	{
		operoAbajo = saltos[0].second*(saltos[1].first-saltos[0].first);
		operoAbajo -= (saltos[0].second+saltos[1].second-k);
	}


	if (saltos[t-1].second+saltos[t-2].second < k)
	{
		if (2*(saltos[t-1].second+saltos[t-2].second) > n)
		{
			operoArriba += saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
			saltos[t-2].second += saltos[t-1].second;
			saltos.erase(saltos.end());
		}
		while(saltos[t-1].second+saltos[t-2].second < k && 2*(saltos[t-1].second+saltos[t-2].second) <= n)
		{
			operoArriba += saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
			saltos[t-2].second += saltos[t-1].second;
			saltos.erase(saltos.end());
			t--;
		}
		operoArriba += ordenarDP(k,saltos,n);
	}
	else
	{
		operoArriba = saltos[t-1].second*(saltos[t-1].first-saltos[t-2].first);
		operoArriba -= (saltos[t-1].second+saltos[t-2].second-k);
	}


	if(operoArriba < operoAbajo){return operoArriba;}
	else{return operoAbajo;}




	
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
	int ultimoSalto=-1;
	for (unsigned i = 1; i < n; i++)
	{
		if(a[i]!=a[i-1]){
			if(i-1-ultimoSalto >= k){k=1;};
			saltos.push_back(make_pair(a[i-1]-a[0],i-1-ultimoSalto));
			ultimoSalto=i-1;
		}
	}
	if(n-1-ultimoSalto >= k){k=1;};
	saltos.push_back(make_pair(a[n-1]-a[0],n-1-ultimoSalto));
	if(k==1){cout << 0; return 0;}
	cout << obvio(saltos,k,n);
}
	
	
	
