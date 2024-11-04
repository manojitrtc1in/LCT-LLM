#include <bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pll pair<long long int, long long int>
#define pii pair<int, int>
#define vii vector<int>
#define vll vector<long long int>
#define sii set<int>
#define sll set<long long int>
#define usi unordered_set<int, custom_hash>
#define usl unordered_set<long long int, custom_hash>
#define mii map<int, int>
#define mll map<long long int, long long int>
#define umi unordered_map<int, int, custom_hash>
#define uml unordered_map<long long int, long long int, custom_hash>
#define ski stack<int>
#define skl stack<long long int>
#define all(v) v.begin(),v.end()
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


const int N=1e2+1;
const int mod=998244353;
ll a[N], b[N], c[N];


class HungarianAlgorithm
{
public:
	HungarianAlgorithm();
	~HungarianAlgorithm();
	double Solve(vector <vector<double> >& DistMatrix, vector<int>& Assignment);

private:
	void assignmentoptimal(int *assignment, double *cost, double *distMatrix, int nOfRows, int nOfColumns);
	void buildassignmentvector(int *assignment, bool *starMatrix, int nOfRows, int nOfColumns);
	void computeassignmentcost(int *assignment, double *cost, double *distMatrix, int nOfRows);
	void step2a(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim);
	void step2b(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim);
	void step3(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim);
	void step4(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim, int row, int col);
	void step5(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim);
};

HungarianAlgorithm::HungarianAlgorithm(){}
HungarianAlgorithm::~HungarianAlgorithm(){}








double HungarianAlgorithm::Solve(vector <vector<double> >& DistMatrix, vector<int>& Assignment)
{
	unsigned int nRows = DistMatrix.size();
	unsigned int nCols = DistMatrix[0].size();

	double *distMatrixIn = new double[nRows * nCols];
	int *assignment = new int[nRows];
	double cost = 0.0;

	

	

	

	

	for (unsigned int i = 0; i < nRows; i++)
		for (unsigned int j = 0; j < nCols; j++)
			distMatrixIn[i + nRows * j] = DistMatrix[i][j];
	
	

	assignmentoptimal(assignment, &cost, distMatrixIn, nRows, nCols);

	Assignment.clear();
	for (unsigned int r = 0; r < nRows; r++)
		Assignment.push_back(assignment[r]);

	delete[] distMatrixIn;
	delete[] assignment;
	return cost;
}








void HungarianAlgorithm::assignmentoptimal(int *assignment, double *cost, double *distMatrixIn, int nOfRows, int nOfColumns)
{
	double *distMatrix, *distMatrixTemp, *distMatrixEnd, *columnEnd, value, minValue;
	bool *coveredColumns, *coveredRows, *starMatrix, *newStarMatrix, *primeMatrix;
	int nOfElements, minDim, row, col;

	
	*cost = 0;
	for (row = 0; row<nOfRows; row++)
		assignment[row] = -1;

	
	
	nOfElements = nOfRows * nOfColumns;
	distMatrix = (double *)malloc(nOfElements * sizeof(double));
	distMatrixEnd = distMatrix + nOfElements;

	for (row = 0; row<nOfElements; row++)
	{
		value = distMatrixIn[row];
		if (value < 0)
			cerr << "All matrix elements have to be non-negative." << endl;
		distMatrix[row] = value;
	}


	
	coveredColumns = (bool *)calloc(nOfColumns, sizeof(bool));
	coveredRows = (bool *)calloc(nOfRows, sizeof(bool));
	starMatrix = (bool *)calloc(nOfElements, sizeof(bool));
	primeMatrix = (bool *)calloc(nOfElements, sizeof(bool));
	newStarMatrix = (bool *)calloc(nOfElements, sizeof(bool)); 

	
	if (nOfRows <= nOfColumns)
	{
		minDim = nOfRows;

		for (row = 0; row<nOfRows; row++)
		{
			
			distMatrixTemp = distMatrix + row;
			minValue = *distMatrixTemp;
			distMatrixTemp += nOfRows;
			while (distMatrixTemp < distMatrixEnd)
			{
				value = *distMatrixTemp;
				if (value < minValue)
					minValue = value;
				distMatrixTemp += nOfRows;
			}

			
			distMatrixTemp = distMatrix + row;
			while (distMatrixTemp < distMatrixEnd)
			{
				*distMatrixTemp -= minValue;
				distMatrixTemp += nOfRows;
			}
		}

		
		for (row = 0; row<nOfRows; row++)
			for (col = 0; col<nOfColumns; col++)
				if (fabs(distMatrix[row + nOfRows*col]) < DBL_EPSILON)
					if (!coveredColumns[col])
					{
						starMatrix[row + nOfRows*col] = true;
						coveredColumns[col] = true;
						break;
					}
	}
	else 
	{
		minDim = nOfColumns;

		for (col = 0; col<nOfColumns; col++)
		{
			
			distMatrixTemp = distMatrix + nOfRows*col;
			columnEnd = distMatrixTemp + nOfRows;

			minValue = *distMatrixTemp++;
			while (distMatrixTemp < columnEnd)
			{
				value = *distMatrixTemp++;
				if (value < minValue)
					minValue = value;
			}

			
			distMatrixTemp = distMatrix + nOfRows*col;
			while (distMatrixTemp < columnEnd)
				*distMatrixTemp++ -= minValue;
		}

		
		for (col = 0; col<nOfColumns; col++)
			for (row = 0; row<nOfRows; row++)
				if (fabs(distMatrix[row + nOfRows*col]) < DBL_EPSILON)
					if (!coveredRows[row])
					{
						starMatrix[row + nOfRows*col] = true;
						coveredColumns[col] = true;
						coveredRows[row] = true;
						break;
					}
		for (row = 0; row<nOfRows; row++)
			coveredRows[row] = false;

	}

	
	step2b(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);

	
	computeassignmentcost(assignment, cost, distMatrixIn, nOfRows);

	
	free(distMatrix);
	free(coveredColumns);
	free(coveredRows);
	free(starMatrix);
	free(primeMatrix);
	free(newStarMatrix);

	return;
}


void HungarianAlgorithm::buildassignmentvector(int *assignment, bool *starMatrix, int nOfRows, int nOfColumns)
{
	int row, col;

	for (row = 0; row<nOfRows; row++)
		for (col = 0; col<nOfColumns; col++)
			if (starMatrix[row + nOfRows*col])
			{
#ifdef ONE_INDEXING
				assignment[row] = col + 1; 
#else
				assignment[row] = col;
#endif
				break;
			}
}


void HungarianAlgorithm::computeassignmentcost(int *assignment, double *cost, double *distMatrix, int nOfRows)
{
	int row, col;

	for (row = 0; row<nOfRows; row++)
	{
		col = assignment[row];
		if (col >= 0)
			*cost += distMatrix[row + nOfRows*col];
	}
}


void HungarianAlgorithm::step2a(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim)
{
	bool *starMatrixTemp, *columnEnd;
	int col;

	
	for (col = 0; col<nOfColumns; col++)
	{
		starMatrixTemp = starMatrix + nOfRows*col;
		columnEnd = starMatrixTemp + nOfRows;
		while (starMatrixTemp < columnEnd){
			if (*starMatrixTemp++)
			{
				coveredColumns[col] = true;
				break;
			}
		}
	}

	
	step2b(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);
}


void HungarianAlgorithm::step2b(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim)
{
	int col, nOfCoveredColumns;

	
	nOfCoveredColumns = 0;
	for (col = 0; col<nOfColumns; col++)
		if (coveredColumns[col])
			nOfCoveredColumns++;

	if (nOfCoveredColumns == minDim)
	{
		
		buildassignmentvector(assignment, starMatrix, nOfRows, nOfColumns);
	}
	else
	{
		
		step3(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);
	}

}


void HungarianAlgorithm::step3(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim)
{
	bool zerosFound;
	int row, col, starCol;

	zerosFound = true;
	while (zerosFound)
	{
		zerosFound = false;
		for (col = 0; col<nOfColumns; col++)
			if (!coveredColumns[col])
				for (row = 0; row<nOfRows; row++)
					if ((!coveredRows[row]) && (fabs(distMatrix[row + nOfRows*col]) < DBL_EPSILON))
					{
						
						primeMatrix[row + nOfRows*col] = true;

						
						for (starCol = 0; starCol<nOfColumns; starCol++)
							if (starMatrix[row + nOfRows*starCol])
								break;

						if (starCol == nOfColumns) 
						{
							
							step4(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim, row, col);
							return;
						}
						else
						{
							coveredRows[row] = true;
							coveredColumns[starCol] = false;
							zerosFound = true;
							break;
						}
					}
	}

	
	step5(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);
}


void HungarianAlgorithm::step4(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim, int row, int col)
{
	int n, starRow, starCol, primeRow, primeCol;
	int nOfElements = nOfRows*nOfColumns;

	
	for (n = 0; n<nOfElements; n++)
		newStarMatrix[n] = starMatrix[n];

	
	newStarMatrix[row + nOfRows*col] = true;

	
	starCol = col;
	for (starRow = 0; starRow<nOfRows; starRow++)
		if (starMatrix[starRow + nOfRows*starCol])
			break;

	while (starRow<nOfRows)
	{
		
		newStarMatrix[starRow + nOfRows*starCol] = false;

		
		primeRow = starRow;
		for (primeCol = 0; primeCol<nOfColumns; primeCol++)
			if (primeMatrix[primeRow + nOfRows*primeCol])
				break;

		
		newStarMatrix[primeRow + nOfRows*primeCol] = true;

		
		starCol = primeCol;
		for (starRow = 0; starRow<nOfRows; starRow++)
			if (starMatrix[starRow + nOfRows*starCol])
				break;
	}

	
	
	for (n = 0; n<nOfElements; n++)
	{
		primeMatrix[n] = false;
		starMatrix[n] = newStarMatrix[n];
	}
	for (n = 0; n<nOfRows; n++)
		coveredRows[n] = false;

	
	step2a(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);
}


void HungarianAlgorithm::step5(int *assignment, double *distMatrix, bool *starMatrix, bool *newStarMatrix, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int nOfRows, int nOfColumns, int minDim)
{
	double h, value;
	int row, col;

	
	h = DBL_MAX;
	for (row = 0; row<nOfRows; row++)
		if (!coveredRows[row])
			for (col = 0; col<nOfColumns; col++)
				if (!coveredColumns[col])
				{
					value = distMatrix[row + nOfRows*col];
					if (value < h)
						h = value;
				}

	
	for (row = 0; row<nOfRows; row++)
		if (coveredRows[row])
			for (col = 0; col<nOfColumns; col++)
				distMatrix[row + nOfRows*col] += h;

	
	for (col = 0; col<nOfColumns; col++)
		if (!coveredColumns[col])
			for (row = 0; row<nOfRows; row++)
				distMatrix[row + nOfRows*col] -= h;

	
	step3(assignment, distMatrix, starMatrix, newStarMatrix, primeMatrix, coveredColumns, coveredRows, nOfRows, nOfColumns, minDim);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    

	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int xyz=-1ll, idx=-1;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i];
			if(a[i]>xyz){
				xyz=a[i];
				idx=i;
			}
		}

		vector<vector<double> > costMatrix(n, vector<double>(n));
		double mx=1e9;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(j==1){
					costMatrix[i-1][j-1]=mx-a[i];
				}
				else if(j<=k){
					costMatrix[i-1][j-1]=mx-(a[i]+(j-1)*b[i]);
				}
				

				

				

				else{
					costMatrix[i-1][j-1]=mx-(k-1)*b[i];
				}
			}
		}
		

		HungarianAlgorithm algo;
		vector<int> v, ans(k-1);
		double cost=mx*n-algo.Solve(costMatrix, v);
		

		for(int i=0;i<v.size();++i){
			if(v[i]+1<k){
				ans[v[i]]=i+1;
			}
		}
		for(int i=0;i<v.size();++i){
			if(v[i]+1>k){
				ans.pb(i+1);
				ans.pb(-i-1);
			}
		}
		for(int i=0;i<v.size();++i){
			if(v[i]+1==k){
				ans.pb(i+1);
				break;
			}
		}

		cout<<ans.size()<<endl;
		for(int x:ans){
			cout<<x<<' ';
		}
		cout<<endl;
	}
    

}