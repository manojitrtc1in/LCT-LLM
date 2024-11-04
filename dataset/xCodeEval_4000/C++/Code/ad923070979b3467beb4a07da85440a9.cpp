

#include <bits/stdc++.h>


using namespace std;

	

#define x first
#define y second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define mp make_pair
#define mt make_tuple

vector<pair<int,pair<int,int>>> r[10005],c[10005];
pair<int,int> a[10005];
int sp[10005];
umap<int,umap<int,int>> field;

main(){
	int t,i,j,n,m,l,x,y,res,d,ld;
	queue<pair<int,int>> q1,q2;
	memset(sp,-1,sizeof sp);
	
	scanf("%d %d %d",&n,&m,&l);
	for(i = 1; i <= l; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}	
	sort(a+1,a+1+l);
	for(i = 1; i <= l; i++){
		field[a[i].x][a[i].y] = i;


		r[a[i].x].push_back({i,{a[i].x,a[i].y}});
		c[a[i].y].push_back({i,{a[i].x,a[i].y}});
	}	
	sp[1] = 0;
	q1.emplace(0,1);
	while(!q1.empty() || !q2.empty()){
		while(!q1.empty()){
			d = q1.front().x;
			x = q1.front().y;
			q1.pop();
			if(d > sp[x]){
				continue;
			}
			if(field[a[x].x+1][a[x].y] && (sp[field[a[x].x+1][a[x].y]] == -1 || sp[field[a[x].x+1][a[x].y]] > d)){
				sp[field[a[x].x+1][a[x].y]] = d;
				q1.emplace(d,field[a[x].x+1][a[x].y]);
			}
			else if(!field[a[x].x+1][a[x].y]){
				field[a[x].x+1].erase(a[x].y);
				if(field[a[x].x+1].empty()){
					field.erase(a[x].x+1);
				}
			}
			if(field[a[x].x-1][a[x].y] && (sp[field[a[x].x-1][a[x].y]] == -1 || sp[field[a[x].x-1][a[x].y]] > d)){
				sp[field[a[x].x-1][a[x].y]] = d;
				q1.emplace(d,field[a[x].x-1][a[x].y]);
			}
			else if(!field[a[x].x-1][a[x].y]){
				field[a[x].x-1].erase(a[x].y);
				if(field[a[x].x-1].empty()){
					field.erase(a[x].x-1);
				}
			}
			if(field[a[x].x][a[x].y+1] && (sp[field[a[x].x][a[x].y+1]] == -1 || sp[field[a[x].x][a[x].y+1]] > d)){
				sp[field[a[x].x][a[x].y+1]] = d;
				q1.emplace(d,field[a[x].x][a[x].y+1]);
			}
			else if(!field[a[x].x][a[x].y+1]){
				field[a[x].x].erase(a[x].y+1);
				if(field[a[x].x].empty()){
					field.erase(a[x].x);
				}
			}
			if(field[a[x].x][a[x].y-1] && (sp[field[a[x].x][a[x].y-1]] == -1 || sp[field[a[x].x][a[x].y-1]] > d)){
				sp[field[a[x].x][a[x].y-1]] = d;
				q1.emplace(d,field[a[x].x][a[x].y-1]);
			}
			else if(!field[a[x].x][a[x].y-1]){
				field[a[x].x].erase(a[x].y-1);
				if(field[a[x].x].empty()){
					field.erase(a[x].x);
				}
			}
			for(i = 0; i < r[a[x].x].size(); i++){
				if(sp[r[a[x].x][i].x] == -1 || sp[r[a[x].x][i].x] > d+1){
					sp[r[a[x].x][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x][i].x);
				}
			}
			for(i = 0; i < r[a[x].x+1].size(); i++){
				if(sp[r[a[x].x+1][i].x] == -1 || sp[r[a[x].x+1][i].x] > d+1){
					sp[r[a[x].x+1][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x+1][i].x);
				}
			}
			for(i = 0; i < r[a[x].x-1].size(); i++){
				if(sp[r[a[x].x-1][i].x] == -1 || sp[r[a[x].x-1][i].x] > d+1){
					sp[r[a[x].x-1][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x-1][i].x);
				}
			}
			for(i = 0; i < r[a[x].x+2].size(); i++){
				if(sp[r[a[x].x+2][i].x] == -1 || sp[r[a[x].x+2][i].x] > d+1){
					sp[r[a[x].x+2][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x+2][i].x);
				}
			}
			for(i = 0; a[x].x > 1 && i < r[a[x].x-2].size(); i++){
				if(sp[r[a[x].x-2][i].x] == -1 || sp[r[a[x].x-2][i].x] > d+1){
					sp[r[a[x].x-2][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x-2][i].x);
				}
			}
			for(i = 0; i < c[a[x].y].size(); i++){
				if(sp[c[a[x].y][i].x] == -1 || sp[c[a[x].y][i].x] > d+1){
					sp[c[a[x].y][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y][i].x);
				}
			}
			for(i = 0; i < c[a[x].y+1].size(); i++){
				if(sp[c[a[x].y+1][i].x] == -1 || sp[c[a[x].y+1][i].x] > d+1){
					sp[c[a[x].y+1][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y+1][i].x);
				}
			}
			for(i = 0; i < c[a[x].y-1].size(); i++){
				if(sp[c[a[x].y-1][i].x] == -1 || sp[c[a[x].y-1][i].x] > d+1){
					sp[c[a[x].y-1][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y-1][i].x);
				}
			}
			for(i = 0; i < c[a[x].y+2].size(); i++){
				if(sp[c[a[x].y+2][i].x] == -1 || sp[c[a[x].y+2][i].x] > d+1){
					sp[c[a[x].y+2][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y+2][i].x);
				}
			}
			for(i = 0; a[x].y > 1 && i < c[a[x].y-2].size(); i++){
				if(sp[c[a[x].y-2][i].x] == -1 || sp[c[a[x].y-2][i].x] > d+1){
					sp[c[a[x].y-2][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y-2][i].x);
				}
			}
		}
		ld = -1;
		while(!q2.empty()){
			d = q2.front().x;
			x = q2.front().y;
			if(ld != -1 && d != ld){
				break;
			}
			q2.pop();
			if(d > sp[x]){
				continue;
			}
			if(field[a[x].x+1][a[x].y] && (sp[field[a[x].x+1][a[x].y]] == -1 || sp[field[a[x].x+1][a[x].y]] > d)){
				sp[field[a[x].x+1][a[x].y]] = d;
				q1.emplace(d,field[a[x].x+1][a[x].y]);
			}
			else if(!field[a[x].x+1][a[x].y]){
				field[a[x].x+1].erase(a[x].y);
				if(field[a[x].x+1].empty()){
					field.erase(a[x].x+1);
				}
			}
			if(field[a[x].x-1][a[x].y] && (sp[field[a[x].x-1][a[x].y]] == -1 || sp[field[a[x].x-1][a[x].y]] > d)){
				sp[field[a[x].x-1][a[x].y]] = d;
				q1.emplace(d,field[a[x].x-1][a[x].y]);
			}
			else if(!field[a[x].x-1][a[x].y]){
				field[a[x].x-1].erase(a[x].y);
				if(field[a[x].x-1].empty()){
					field.erase(a[x].x-1);
				}
			}
			if(field[a[x].x][a[x].y+1] && (sp[field[a[x].x][a[x].y+1]] == -1 || sp[field[a[x].x][a[x].y+1]] > d)){
				sp[field[a[x].x][a[x].y+1]] = d;
				q1.emplace(d,field[a[x].x][a[x].y+1]);
			}
			else if(!field[a[x].x][a[x].y+1]){
				field[a[x].x].erase(a[x].y+1);
				if(field[a[x].x].empty()){
					field.erase(a[x].x);
				}
			}
			if(field[a[x].x][a[x].y-1] && (sp[field[a[x].x][a[x].y-1]] == -1 || sp[field[a[x].x][a[x].y-1]] > d)){
				sp[field[a[x].x][a[x].y-1]] = d;
				q1.emplace(d,field[a[x].x][a[x].y-1]);
			}
			else if(!field[a[x].x][a[x].y-1]){
				field[a[x].x].erase(a[x].y-1);
				if(field[a[x].x].empty()){
					field.erase(a[x].x);
				}
			}
			for(i = 0; i < r[a[x].x].size(); i++){
				if(sp[r[a[x].x][i].x] == -1 || sp[r[a[x].x][i].x] > d+1){
					sp[r[a[x].x][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x][i].x);
				}
			}
			for(i = 0; i < r[a[x].x+1].size(); i++){
				if(sp[r[a[x].x+1][i].x] == -1 || sp[r[a[x].x+1][i].x] > d+1){
					sp[r[a[x].x+1][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x+1][i].x);
				}
			}
			for(i = 0; i < r[a[x].x-1].size(); i++){
				if(sp[r[a[x].x-1][i].x] == -1 || sp[r[a[x].x-1][i].x] > d+1){
					sp[r[a[x].x-1][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x-1][i].x);
				}
			}
			for(i = 0; i < r[a[x].x+2].size(); i++){
				if(sp[r[a[x].x+2][i].x] == -1 || sp[r[a[x].x+2][i].x] > d+1){
					sp[r[a[x].x+2][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x+2][i].x);
				}
			}
			for(i = 0; a[x].x > 1 && i < r[a[x].x-2].size(); i++){
				if(sp[r[a[x].x-2][i].x] == -1 || sp[r[a[x].x-2][i].x] > d+1){
					sp[r[a[x].x-2][i].x] = d+1;
					q2.emplace(d+1,r[a[x].x-2][i].x);
				}
			}
			for(i = 0; i < c[a[x].y].size(); i++){
				if(sp[c[a[x].y][i].x] == -1 || sp[c[a[x].y][i].x] > d+1){
					sp[c[a[x].y][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y][i].x);
				}
			}
			for(i = 0; i < c[a[x].y+1].size(); i++){
				if(sp[c[a[x].y+1][i].x] == -1 || sp[c[a[x].y+1][i].x] > d+1){
					sp[c[a[x].y+1][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y+1][i].x);
				}
			}
			for(i = 0; i < c[a[x].y-1].size(); i++){
				if(sp[c[a[x].y-1][i].x] == -1 || sp[c[a[x].y-1][i].x] > d+1){
					sp[c[a[x].y-1][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y-1][i].x);
				}
			}
			for(i = 0; i < c[a[x].y+2].size(); i++){
				if(sp[c[a[x].y+2][i].x] == -1 || sp[c[a[x].y+2][i].x] > d+1){
					sp[c[a[x].y+2][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y+2][i].x);
				}
			}
			for(i = 0; a[x].y > 1 && i < c[a[x].y-2].size(); i++){
				if(sp[c[a[x].y-2][i].x] == -1 || sp[c[a[x].y-2][i].x] > d+1){
					sp[c[a[x].y-2][i].x] = d+1;
					q2.emplace(d+1,c[a[x].y-2][i].x);
				}
			}
		}
	}
	res = INT_MAX;
	if(field[n][m]){
		res = sp[field[n][m]];
	}
	else{
		for(i = 0; i < r[n].size(); i++){
			if(sp[r[n][i].x] != -1){
				res = min(res,sp[r[n][i].x]+1);
			}
		}
		for(i = 0; i < r[n-1].size(); i++){
			if(sp[r[n-1][i].x] != -1){
				res = min(res,sp[r[n-1][i].x]+1);
			}
		}
		for(i = 0; i < c[m].size(); i++){
			if(sp[c[m][i].x] != -1){
				res = min(res,sp[c[m][i].x]+1);
			}
		}
		for(i = 0; i < c[m-1].size(); i++){
			if(sp[c[m-1][i].x] != -1){
				res = min(res,sp[c[m-1][i].x]+1);
			}
		}
	}
	if(res != INT_MAX){
		printf("%d\n",res);
	}
	else{
		printf("%d\n",-1);
	}

	return 0;	
}


















