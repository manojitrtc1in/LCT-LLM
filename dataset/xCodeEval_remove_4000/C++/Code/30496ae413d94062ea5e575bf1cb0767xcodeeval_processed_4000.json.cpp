





















using namespace std;


const double EPS = 1e-8;
const int INF = 0x3f3f3f3f3f3f3f3f;



















typedef pair<int, int> pii;
typedef vector<int> vi;



inline bool Equal(double x, double y){ return (x<y + EPS && x>y - EPS); }
inline bool Larger(double x, double y){ return (x > y + EPS); }
inline bool Less(double x, double y){ return (x<y - EPS); }
inline int UB(vector<int> &v, int x){ return upper_bound(v.begin(), v.end(), x) - v.begin(); }
inline int LB(vector<int> &v, int x){ return lower_bound(v.begin(), v.end(), x) - v.begin(); }
const int Mod = 10;
inline int PowMod(int a, int b) { int res = 1; a %= Mod; assert(b >= 0); for (; b; b >>= 1){ if (b & 1)res = res*a%Mod; a = a*a%Mod; }return res; }

bool uMin(int &a, int b) { return a > b ? (a = b, true) : false; }
bool uMax(int &a, int b) { return a < b ? (a = b, true) : false; }

const int MxSize = 1000006;
int depth = 0;

string nodes[MxSize];
int nodeHead = 1;


class StringDigitReader
{
private:
	char buff[MxSize];
public:
	string src;
	friend istream &operator>>(istream& ins, StringDigitReader& sdr){ ins >> sdr.src; return ins; }

	int SkipUntil(int startId, char skipChar){
		while (startId<src.length() && src[startId] != skipChar)
			startId++;
		return startId;
	}
	int SkipNonDigitString(int startId){
		while (startId<src.length() && (src[startId] <'0' || src[startId]>'9'))
			startId++;
		return startId;
	}
	int ReadInt(int startId, char id2, int &result)
	{
		int cnt = 0;
		while (startId < src.length() && (src[startId] >= '0'&&src[startId] <= '9' || src[startId] == id2))
		{
			buff[cnt++] = src[startId++];
		}
		result = 0;
		for (size_t i = 0; i < cnt; i++) if (buff[i] != id2)
		{
			result = result * 10 + buff[i] - '0';
		}
		return startId;
	}
	int ReadDouble(int startId, char id2, double &result)
	{
		int cnt = 0;
		while (startId < src.length() && (src[startId] == '.' || src[startId] == id2 || (src[startId] >= '0'&&src[startId] <= '9')))
		{
			buff[cnt++] = src[startId++];
		}
		result = 0;
		if (cnt >= 4 && buff[cnt - 3] == '.')
		{
			double factor = 0.1;
			for (size_t i = 0; i < cnt; i++)
			{
				if (i < cnt - 3 && buff[i] == id2) continue;
				if (i < cnt - 3) result = result * 10 + buff[i] - '0';
				else if (i > cnt - 3) { result += (buff[i] - '0')*factor; factor /= 10; }
			}
		}
		else
		{
			for (size_t i = 0; i < cnt; i++)
			{
				if (buff[i] == id2) continue;
				result = result * 10 + buff[i] - '0';
			}
		}
		return startId;
	}
};




StringDigitReader sr;




void id12(int x, int y, int weight);		


void id11(int x);		

bool id18(int x);		

void id17(int x);	

void id10(int x);		


void id14(int x);	

void id16(int x);	

int id6(int x);		

void id9(int x, int y, int returnValue);	

void id15(int x);	


void id19(int x);	

void id3(int x, int lv);		

void id1(int x);		



































class id8
{

private:
	int dFrom, dTo;
	vector<pair<int, int>> p[MxSize];

public:

	id8()
	{
		dFrom = 0; dTo = 0;
	}
	~id8()
	{
	}

	

	void Initialize(int id13, int id7)
	{
		dFrom = id13;
		dTo = id7;
		for (int i = id13; i <= id7; i++)
		{
			p[i].clear();
		}

		memset(used, false, sizeof(used));

	}

	

	void AddSide(int v1, int v2, int weight = 1, bool id0 = true)
	{
		p[v1].push_back(make_pair(v2, weight));
		if (id0)
			p[v2].push_back(make_pair(v1, weight));
	}

	template<typename T2>
	

	void id5(T2 propertyArray[], int beginID, int endID){
		for (int i = beginID; i <= endID; i++)
		{
			for (vector<pair<int, int>>::iterator it = p[i].begin(); it != p[i].end();){
				if (propertyArray[i] == propertyArray[*it]){
					int itv = it->first;
					it = p[i].erase(it);
					for (vector<pair<int, int>>::iterator tit = p[itv].begin(); tit != p[itv].end(); tit++){
						int titv = tit->first;
						if (i == titv) continue;
						int offset = it - p[i].begin();	

						p[i].push_back(*tit);
						it = p[i].begin() + offset;	

						for (vector<pair<int, int>>::iterator id4 = p[titv].begin(); id4 != p[titv].end(); id4++){
							if (id4->first == itv){ p[titv].erase(id4); break; }
						}
						p[titv].push_back(make_pair(i, 0));
					}
					p[itv].clear();
				}
				else{ it++; }
			}
		}
	}




private:
	bool visited[MxSize];
public:

	

	void Start_DP_Process(int root)
	{
		memset(visited + dFrom, false, sizeof(bool)*(dTo - dFrom + 1));
		id14(root);
		int result = dp(root);
		id15(root);
	}

	int dp(int node)
	{
		id16(node);
		visited[node] = true;
		for each (pair<int, int> to in p[node])
		{
			if (visited[to.first]) continue;
			id9(node, to.first, dp(to.first));
		}
		return id6(node);
	}





private:
	bool used[MxSize];

	int count;


	int groupSize;


	int groupMax;


	int groupMin;


public:

	void Start_DFS_Process()
	{

		count = 0;

		for (int i = dFrom; i <= dTo; i++)
		{
			if (!used[i]){

				groupSize = 0;


				memset(&groupMax, 63, sizeof(Int));


				memset(&groupMin, 63, sizeof(Int));
				groupMin = -groupMin;

				id11(i);
				dfs(i);

				count++;

				id10(i);
			}
		}
	}
private:
	void dfs(int x)
	{
		if (used[x]) return;
		if (!id18(x)) return;
		id17(x);
		used[x] = true;

		groupSize++;


		groupMax = max(groupMax, x);


		groupMin = min(groupMin, x);

		for (int i = 0; i < p[x].size(); i++)
			dfs(p[x][i].first);
	}
public:

	int GetCount(){ return count; }


	int GetgroupSize() { return groupSize; }


	int GetgroupMax() { return groupMax; }


	int GetgroupMin() { return groupMin; }









private:
	bool used[MxSize];


private:
	int visitOrder[MxSize];
	int level[MxSize];
	

public:

	void Start_BFS_Process(int root)
	{

		memset(used + dFrom, false, sizeof(bool)*(dTo - dFrom + 1));

		memset(visitOrder + dFrom, -1, sizeof(int)*(dTo - dFrom + 1));
		memset(level + dFrom, 0, sizeof(int)*(dTo - dFrom + 1));

		id19(root);
		bfs(root);
		id1(root);
	}

	void bfs(int node)
	{
		int head = 0;
		int tail = 1;
		visitOrder[head] = node;
		level[head] = 0;

		used[node] = true;

		int currentLevel = 0;
		while (head<tail){
			node = visitOrder[head];
			currentLevel = level[head];
			head++;
			id3(node, currentLevel);

			for (int i = 0; i < p[node].size(); i++)
			{
				int tNode = p[node][i].first;

				if (used[tNode]) continue;
				used[tNode] = true;

				visitOrder[tail] = tNode;
				level[tail] = currentLevel + 1;
				tail++;
			}
		}

	}






	

	void EnumerateSides(){
		for (int i = dFrom; i <= dTo; i++)
		{
			for (int j = 0; j < p[i].size(); j++)
			{
				id12(i, p[i][j].first, p[i][j].second);
			}
		}
	}


};


























id8 g;
void id12(int node, int y, int weight)		

{}
void id11(int node)		

{}
bool id18(int node)		

{
	return true;
}
void id17(int node)	

{}
void id10(int node)		

{}
void id14(int node)	

{}
void id16(int node)	

{}
int id6(int node)		

{
	return 0;
}
void id9(int node, int to, int returnValue)	

{}
void id15(int node)	

{}
int cLv;
void id19(int node)	

{
	cLv = 0;
}
void id3(int node, int lv)		

{
	if (lv != cLv) cout << endl;
	cLv = lv;
	if (node != 0)
		cout << nodes[node] << ' ';

}
void id1(int node)		

{
}






void AppendNode(int &id, int father, int dep)
{
	dep++;
	if (dep > depth) depth = dep;

	int curr = nodeHead++;
	int newID;
	newID = sr.SkipUntil(id, ',');
	nodes[curr] = sr.src.substr(id, newID - id);
	g.AddSide(father, curr, 0LL, false);
	id = newID + 1;
	int x;
	newID = sr.ReadInt(id, '_', x);
	id = newID + 1;
	for (int i = 0; i < x; i++)
	{
		AppendNode(id, curr, dep);
	}
}


int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	freopen("test1.txt", "r", stdin);
	



	cin >> sr;
	g.Initialize(0, MxSize - 2);
	int id = 0;
	while (id<sr.src.length())
		AppendNode(id, 0, 0);

	cout << depth;
	g.Start_BFS_Process(0);

	return 0;
}