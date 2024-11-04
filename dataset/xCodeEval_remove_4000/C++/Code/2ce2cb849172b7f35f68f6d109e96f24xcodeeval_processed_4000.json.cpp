



















using namespace std;













































































































































































































































































































































































































































































































































































































































































int parent[100000]  ;
priority_queue < pair <double , pair <int , int > > > edges ;
vector < vector <pair < int ,double > > > graph(100000);
vector < pair <int ,int > > sol ;
long long int c = 0;
int  n,m ,counter = 0;
int  l =0;
bool flago = false;
bool visit[10000] = {false};
bool taken[10000] = {false};
priority_queue <int> ans;
int cost(char a[4] ,char b[4]){
    int x = 0 ;
    fore(i , 4){
        if(abs(a[i]-b[i]) < 10-abs(a[i]-b[i])){
            x+=abs(a[i]-b[i])-'0';
        }else{
            x+=10-abs(a[i]-b[i])-'0';
        }
    }
    return x ;
}
void init(){
for(int i = 0;i<10000;i++){
    parent[i] = i;
    }
}
int find(int i){
    if(parent[i] == i){return i;}
    return parent[i] = find(parent[i]);
}
bool unio(int i, int j){
    int r_i = find(i);
    int r_j = find(j);
    if(r_i==r_j){return false;}
    parent[r_i]=r_j;
    return true;
}
void id0(priority_queue < pair < double , pair <int , int > > > edges){
    init();
    for(int i = 0 ; i < l ;i++){
            int a = edges.top().second.first ;
            int b = edges.top().second.second ;
        if(unio(a, b)){
            c+= -edges.top().first;




            sol.pb(mp(a,b));
            counter++;
        }else{
          

        }
        edges.pop();
    }
}
double distance(int x1,int x2,int y1,int y2){

    return sqrt(pow(abs(x1-x2),2.0) + pow(abs(y1-y2),2.0)) ;
}
void dfs(int i , double ma){
    if(i == 1 && !flago){
        printf("Frog Distance = %.3lf\n\n",ma);
        flago = true;
        return ;
    }
    visit[i] = true;
    fore(j , graph[i].size()){
        if(!visit[graph[i][j].first]){
            ma = max(ma , graph[i][j].second);
            dfs(graph[i][j].first , ma);
        }
    }
}
int price(string a[1000] , string b[1000])
{
    int f = 0;
    fore(i , n){
        fore(j , a[i].length()){
            if(a[i].at(j) != b[i].at(j)){
                f++;
            }
        }
    }
    return f;
}










































































































































































































































int main()
{
    int  k , w ;
    string array[2000][20];
    cin >> n >> m >> k >> w;
    fore(i , k){
        fore(j , n){
            cin >> array[i][j] ;
        }
    }
    for(int i = 1 ;i <= k ;i++){
        edges.push(mp(-n*m,mp(0,i)));
    }
    fore(i , k){
        for(int j = i + 1 ; j < k ;j++){
            edges.push(mp(-w*price(array[i],array[j]),mp(i+1,j+1)));
        }
    }
    l = edges.size();
    id0(edges);
    cout << c <<endl;
    taken[0] = true;
    fore(i , k){
        fore(j , k){
            if(sol[j].first==0&&!taken[sol[j].second]){
                    printf("%d %d\n",sol[j].second,sol[j].first);
                    taken[sol[j].second]=true;
                    break;
                }
                else if(taken[sol[j].first]&&!taken[sol[j].second]){
                    printf("%d %d\n",sol[j].second,sol[j].first);
                    taken[sol[j].second]=true;
                    break;
                }
                else if(!taken[sol[j].first]&&taken[sol[j].second]){
                    printf("%d %d\n",sol[j].first,sol[j].second);
                    taken[sol[j].first]=true;
                    break;
                }
        }
    }
    return 0;
}
