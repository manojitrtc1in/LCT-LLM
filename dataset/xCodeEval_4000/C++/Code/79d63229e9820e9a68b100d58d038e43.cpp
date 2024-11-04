#include <iostream>
#include <iomanip>
#include <tuple>    

#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define int long long
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f3f3f3f3f;

#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)

#define DRI(X) int X; cin >> (X)
#define DRII(X, Y) int X, Y; cin >> (X) >> (Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin >> (X) >> (Y) >> (Z)
#define DRS(X) string X; cin >> (X)
#define TCASES() DRI(___T);while(___T--)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SETMax(a) memset((a), 63, sizeof(a))
#define SETZero(a) memset((a), 0, sizeof(a))
#define SETNegOne(a) memset((a), -1, sizeof(a))
#define SETFalse(a) memset((a), false, sizeof(a))
#define SZ(a) ((int)(a).size())
#define OutEnd(x) cout<<(x);return 0

typedef pair<int, int> pii;
typedef vector<int> vi;
#define MP make_pair
#define PB push_back

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

#pragma region 杂项 —— 从字符串读出里面的字符串、整数、小数
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
	int ReadInt(int startId, char thousandChar, int &result)
	{
		int cnt = 0;
		while (startId < src.length() && (src[startId] >= '0'&&src[startId] <= '9' || src[startId] == thousandChar))
		{
			buff[cnt++] = src[startId++];
		}
		result = 0;
		for (size_t i = 0; i < cnt; i++) if (buff[i] != thousandChar)
		{
			result = result * 10 + buff[i] - '0';
		}
		return startId;
	}
	int ReadDouble(int startId, char thousandChar, double &result)
	{
		int cnt = 0;
		while (startId < src.length() && (src[startId] == '.' || src[startId] == thousandChar || (src[startId] >= '0'&&src[startId] <= '9')))
		{
			buff[cnt++] = src[startId++];
		}
		result = 0;
		if (cnt >= 4 && buff[cnt - 3] == '.')
		{
			double factor = 0.1;
			for (size_t i = 0; i < cnt; i++)
			{
				if (i < cnt - 3 && buff[i] == thousandChar) continue;
				if (i < cnt - 3) result = result * 10 + buff[i] - '0';
				else if (i > cnt - 3) { result += (buff[i] - '0')*factor; factor /= 10; }
			}
		}
		else
		{
			for (size_t i = 0; i < cnt; i++)
			{
				if (buff[i] == thousandChar) continue;
				result = result * 10 + buff[i] - '0';
			}
		}
		return startId;
	}
};


#pragma endregion

StringDigitReader sr;

#pragma region 图论 —— 很多行，收起来方便观察

#pragma region 函数声明
void onSideEnumerating(int x, int y, int weight);		


void BeforeGroupDetection_inDFS(int x);		

bool CanAddPointToGroup_inDFS(int x);		

void AddingNewPointToGroup_inDFS(int x);	

void AfterGroupDetected_inDFS(int x);		


void BeforeProcess_inDP(int x);	

void EnteringNode_inDP(int x);	

int LeavingNode_inDP(int x);		

void HandleSubNodeResult_inDP(int x, int y, int returnValue);	

void AfterProcess_inDP(int x);	


void BeforeProcess_inBFS(int x);	

void VisitingNode_inBFS(int x, int lv);		

void AfterProcess_inBFS(int x);		

#pragma endregion

#pragma region 图论 —— 通用图搜索框架，向量数组作为容器。可以进行DFS、BFS、DP

#pragma region 宏 开关









#define USE_DFS__
#ifdef USE_DFS
#define GROUP_COUNT__
#define GROUP_SIZE
#define GROUP_MAX__
#define GROUP_MIN__
#endif

#define USE_BFS
#ifdef USE_BFS
#define BFS_Single_Direction_Graph
#endif

#define USE_DP__

#define USE_EMUM_SIDES__
#pragma endregion



class VectorArrayBasedGraphics
{
#pragma region 变量，通用函数
private:
	int dFrom, dTo;
	vector<pair<int, int>> p[MxSize];

public:

	VectorArrayBasedGraphics()
	{
		dFrom = 0; dTo = 0;
	}
	~VectorArrayBasedGraphics()
	{
	}

	

	void Initialize(int dataIdFrom, int dataIdTo)
	{
		dFrom = dataIdFrom;
		dTo = dataIdTo;
		for (int i = dataIdFrom; i <= dataIdTo; i++)
		{
			p[i].clear();
		}
#ifdef USE_DFS
		memset(used, false, sizeof(used));
#endif
	}

	

	void AddSide(int v1, int v2, int weight = 1, bool isTwoWay = true)
	{
		p[v1].push_back(make_pair(v2, weight));
		if (isTwoWay)
			p[v2].push_back(make_pair(v1, weight));
	}

	template<typename T2>
	

	void CombineSamePropertyNodes(T2 propertyArray[], int beginID, int endID){
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

						for (vector<pair<int, int>>::iterator soManyIt = p[titv].begin(); soManyIt != p[titv].end(); soManyIt++){
							if (soManyIt->first == itv){ p[titv].erase(soManyIt); break; }
						}
						p[titv].push_back(make_pair(i, 0));
					}
					p[itv].clear();
				}
				else{ it++; }
			}
		}
	}
#pragma endregion

#pragma region 跟DP相关的处理，具体问题米有用到就删除它
#ifdef USE_DP
private:
	bool visited[MxSize];
public:

	

	void Start_DP_Process(int root)
	{
		memset(visited + dFrom, false, sizeof(bool)*(dTo - dFrom + 1));
		BeforeProcess_inDP(root);
		int result = dp(root);
		AfterProcess_inDP(root);
	}

	int dp(int node)
	{
		EnteringNode_inDP(node);
		visited[node] = true;
		for each (pair<int, int> to in p[node])
		{
			if (visited[to.first]) continue;
			HandleSubNodeResult_inDP(node, to.first, dp(to.first));
		}
		return LeavingNode_inDP(node);
	}
#endif
#pragma endregion

#pragma region 跟DFS相关的处理，具体问题米有用到就删除它
#ifdef USE_DFS
private:
	bool used[MxSize];
#ifdef GROUP_COUNT
	int count;
#endif
#ifdef GROUP_SIZE
	int groupSize;
#endif
#ifdef GROUP_MAX
	int groupMax;
#endif
#ifdef GROUP_MIN
	int groupMin;
#endif

public:

	void Start_DFS_Process()
	{
#ifdef GROUP_COUNT
		count = 0;
#endif
		for (int i = dFrom; i <= dTo; i++)
		{
			if (!used[i]){
#ifdef GROUP_SIZE
				groupSize = 0;
#endif
#ifdef GROUP_MAX
				memset(&groupMax, 63, sizeof(Int));
#endif
#ifdef GROUP_MIN
				memset(&groupMin, 63, sizeof(Int));
				groupMin = -groupMin;
#endif
				BeforeGroupDetection_inDFS(i);
				dfs(i);
#ifdef GROUP_COUNT
				count++;
#endif
				AfterGroupDetected_inDFS(i);
			}
		}
	}
private:
	void dfs(int x)
	{
		if (used[x]) return;
		if (!CanAddPointToGroup_inDFS(x)) return;
		AddingNewPointToGroup_inDFS(x);
		used[x] = true;
#ifdef GROUP_SIZE
		groupSize++;
#endif
#ifdef GROUP_MAX
		groupMax = max(groupMax, x);
#endif
#ifdef GROUP_MIN
		groupMin = min(groupMin, x);
#endif
		for (int i = 0; i < p[x].size(); i++)
			dfs(p[x][i].first);
	}
public:
#ifdef GROUP_COUNT
	int GetCount(){ return count; }
#endif
#ifdef GROUP_SIZE
	int GetgroupSize() { return groupSize; }
#endif
#ifdef GROUP_MAX
	int GetgroupMax() { return groupMax; }
#endif
#ifdef GROUP_MIN
	int GetgroupMin() { return groupMin; }
#endif

#endif
#pragma endregion

#pragma region 跟BFS相关的变量，具体问题米有用到就删除它
#ifdef USE_BFS
#ifndef BFS_Single_Direction_Graph
#ifndef USE_DP
private:
	bool used[MxSize];
#endif
#endif
private:
	queue<pair<int, int>> que;
public:

	void Start_BFS_Process(int root)
	{
#ifndef BFS_Single_Direction_Graph
		memset(used + dFrom, false, sizeof(bool)*(dTo - dFrom + 1));
#endif

		BeforeProcess_inBFS(root);
		bfs(root);
		AfterProcess_inBFS(root);
	}

	void bfs(int node)
	{
		int lv = 0;
		que.push(make_pair(node, lv));
#ifndef BFS_Single_Direction_Graph
		used[node] = true;
#endif
		while (!que.empty()){
			node = que.front().first;
			lv = que.front().second;
			VisitingNode_inBFS(node, lv);

			int tNode;
			for (int i = 0; i < p[node].size(); i++)
			{
				tNode = p[node][i].first;
#ifndef BFS_Single_Direction_Graph
				if (used[tNode]) continue;
				used[tNode] = true;
#endif
				que.push(make_pair(tNode, lv + 1));
			}
			que.pop();
		}
	}
#endif
#pragma endregion

#pragma region 跟 枚举边 功能相关的处理，具体问题米有用到就删除它
#ifdef USE_EMUM_SIDES

	

	void EnumerateSides(){
		for (int i = dFrom; i <= dTo; i++)
		{
			for (int j = 0; j < p[i].size(); j++)
			{
				onSideEnumerating(i, p[i][j].first, p[i][j].second);
			}
		}
	}
#endif
#pragma endregion
};























#pragma endregion

#ifndef IN_MOUDLE_FILE
VectorArrayBasedGraphics g;
void onSideEnumerating(int node, int y, int weight)		

{}
void BeforeGroupDetection_inDFS(int node)		

{}
bool CanAddPointToGroup_inDFS(int node)		

{
	return true;
}
void AddingNewPointToGroup_inDFS(int node)	

{}
void AfterGroupDetected_inDFS(int node)		

{}
void BeforeProcess_inDP(int node)	

{}
void EnteringNode_inDP(int node)	

{}
int LeavingNode_inDP(int node)		

{
	return 0;
}
void HandleSubNodeResult_inDP(int node, int to, int returnValue)	

{}
void AfterProcess_inDP(int node)	

{}
int cLv;
void BeforeProcess_inBFS(int node)	

{
	cLv = 0;
}
void VisitingNode_inBFS(int node, int lv)		

{
	if (lv != cLv) cout << endl;
	cLv = lv;
	if (node != 0)
		cout << nodes[node] << ' ';

}
void AfterProcess_inBFS(int node)		

{
}
#endif

#pragma endregion



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

#define int int
int main(){
#define int long long
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
#ifdef LocalTest
	freopen("test1.txt", "r", stdin);
	

#endif

	cin >> sr;
	g.Initialize(0, MxSize - 2);
	int id = 0;
	while (id<sr.src.length())
		AppendNode(id, 0, 0);

	cout << depth;
	g.Start_BFS_Process(0);

	return 0;
}