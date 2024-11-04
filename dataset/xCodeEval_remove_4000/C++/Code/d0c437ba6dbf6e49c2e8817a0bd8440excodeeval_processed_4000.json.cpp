





















using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id5 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id5);
    }
};


const int N=1e2+1;
const int mod=998244353;
ll a[N], b[N], c[N];


class id7
{
public:
	id7();
	~id7();
	double Solve(vector <vector<double> >& DistMatrix, vector<int>& Assignment);

private:
	void assignmentoptimal(int *assignment, double *cost, double *distMatrix, int id10, int id2);
	void buildassignmentvector(int *assignment, bool *starMatrix, int id10, int id2);
	void computeassignmentcost(int *assignment, double *cost, double *distMatrix, int id10);
	void step2a(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim);
	void step2b(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim);
	void step3(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim);
	void step4(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim, int row, int col);
	void step5(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim);
};

id7::id7(){}
id7::~id7(){}








double id7::Solve(vector <vector<double> >& DistMatrix, vector<int>& Assignment)
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








void id7::assignmentoptimal(int *assignment, double *cost, double *distMatrixIn, int id10, int id2)
{
	double *distMatrix, *id4, *id9, *columnEnd, value, minValue;
	bool *coveredColumns, *coveredRows, *starMatrix, *id3, *primeMatrix;
	int id8, minDim, row, col;

	
	*cost = 0;
	for (row = 0; row<id10; row++)
		assignment[row] = -1;

	
	
	id8 = id10 * id2;
	distMatrix = (double *)malloc(id8 * sizeof(double));
	id9 = distMatrix + id8;

	for (row = 0; row<id8; row++)
	{
		value = distMatrixIn[row];
		if (value < 0)
			cerr << "All matrix elements have to be non-negative." << endl;
		distMatrix[row] = value;
	}


	
	coveredColumns = (bool *)calloc(id2, sizeof(bool));
	coveredRows = (bool *)calloc(id10, sizeof(bool));
	starMatrix = (bool *)calloc(id8, sizeof(bool));
	primeMatrix = (bool *)calloc(id8, sizeof(bool));
	id3 = (bool *)calloc(id8, sizeof(bool)); 

	
	if (id10 <= id2)
	{
		minDim = id10;

		for (row = 0; row<id10; row++)
		{
			
			id4 = distMatrix + row;
			minValue = *id4;
			id4 += id10;
			while (id4 < id9)
			{
				value = *id4;
				if (value < minValue)
					minValue = value;
				id4 += id10;
			}

			
			id4 = distMatrix + row;
			while (id4 < id9)
			{
				*id4 -= minValue;
				id4 += id10;
			}
		}

		
		for (row = 0; row<id10; row++)
			for (col = 0; col<id2; col++)
				if (fabs(distMatrix[row + id10*col]) < DBL_EPSILON)
					if (!coveredColumns[col])
					{
						starMatrix[row + id10*col] = true;
						coveredColumns[col] = true;
						break;
					}
	}
	else 
	{
		minDim = id2;

		for (col = 0; col<id2; col++)
		{
			
			id4 = distMatrix + id10*col;
			columnEnd = id4 + id10;

			minValue = *id4++;
			while (id4 < columnEnd)
			{
				value = *id4++;
				if (value < minValue)
					minValue = value;
			}

			
			id4 = distMatrix + id10*col;
			while (id4 < columnEnd)
				*id4++ -= minValue;
		}

		
		for (col = 0; col<id2; col++)
			for (row = 0; row<id10; row++)
				if (fabs(distMatrix[row + id10*col]) < DBL_EPSILON)
					if (!coveredRows[row])
					{
						starMatrix[row + id10*col] = true;
						coveredColumns[col] = true;
						coveredRows[row] = true;
						break;
					}
		for (row = 0; row<id10; row++)
			coveredRows[row] = false;

	}

	
	step2b(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);

	
	computeassignmentcost(assignment, cost, distMatrixIn, id10);

	
	free(distMatrix);
	free(coveredColumns);
	free(coveredRows);
	free(starMatrix);
	free(primeMatrix);
	free(id3);

	return;
}


void id7::buildassignmentvector(int *assignment, bool *starMatrix, int id10, int id2)
{
	int row, col;

	for (row = 0; row<id10; row++)
		for (col = 0; col<id2; col++)
			if (starMatrix[row + id10*col])
			{

				assignment[row] = col + 1; 

				assignment[row] = col;

				break;
			}
}


void id7::computeassignmentcost(int *assignment, double *cost, double *distMatrix, int id10)
{
	int row, col;

	for (row = 0; row<id10; row++)
	{
		col = assignment[row];
		if (col >= 0)
			*cost += distMatrix[row + id10*col];
	}
}


void id7::step2a(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim)
{
	bool *id0, *columnEnd;
	int col;

	
	for (col = 0; col<id2; col++)
	{
		id0 = starMatrix + id10*col;
		columnEnd = id0 + id10;
		while (id0 < columnEnd){
			if (*id0++)
			{
				coveredColumns[col] = true;
				break;
			}
		}
	}

	
	step2b(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);
}


void id7::step2b(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim)
{
	int col, id6;

	
	id6 = 0;
	for (col = 0; col<id2; col++)
		if (coveredColumns[col])
			id6++;

	if (id6 == minDim)
	{
		
		buildassignmentvector(assignment, starMatrix, id10, id2);
	}
	else
	{
		
		step3(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);
	}

}


void id7::step3(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim)
{
	bool zerosFound;
	int row, col, starCol;

	zerosFound = true;
	while (zerosFound)
	{
		zerosFound = false;
		for (col = 0; col<id2; col++)
			if (!coveredColumns[col])
				for (row = 0; row<id10; row++)
					if ((!coveredRows[row]) && (fabs(distMatrix[row + id10*col]) < DBL_EPSILON))
					{
						
						primeMatrix[row + id10*col] = true;

						
						for (starCol = 0; starCol<id2; starCol++)
							if (starMatrix[row + id10*starCol])
								break;

						if (starCol == id2) 
						{
							
							step4(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim, row, col);
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

	
	step5(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);
}


void id7::step4(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim, int row, int col)
{
	int n, starRow, starCol, primeRow, primeCol;
	int id8 = id10*id2;

	
	for (n = 0; n<id8; n++)
		id3[n] = starMatrix[n];

	
	id3[row + id10*col] = true;

	
	starCol = col;
	for (starRow = 0; starRow<id10; starRow++)
		if (starMatrix[starRow + id10*starCol])
			break;

	while (starRow<id10)
	{
		
		id3[starRow + id10*starCol] = false;

		
		primeRow = starRow;
		for (primeCol = 0; primeCol<id2; primeCol++)
			if (primeMatrix[primeRow + id10*primeCol])
				break;

		
		id3[primeRow + id10*primeCol] = true;

		
		starCol = primeCol;
		for (starRow = 0; starRow<id10; starRow++)
			if (starMatrix[starRow + id10*starCol])
				break;
	}

	
	
	for (n = 0; n<id8; n++)
	{
		primeMatrix[n] = false;
		starMatrix[n] = id3[n];
	}
	for (n = 0; n<id10; n++)
		coveredRows[n] = false;

	
	step2a(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);
}


void id7::step5(int *assignment, double *distMatrix, bool *starMatrix, bool *id3, bool *primeMatrix, bool *coveredColumns, bool *coveredRows, int id10, int id2, int minDim)
{
	double h, value;
	int row, col;

	
	h = id1;
	for (row = 0; row<id10; row++)
		if (!coveredRows[row])
			for (col = 0; col<id2; col++)
				if (!coveredColumns[col])
				{
					value = distMatrix[row + id10*col];
					if (value < h)
						h = value;
				}

	
	for (row = 0; row<id10; row++)
		if (coveredRows[row])
			for (col = 0; col<id2; col++)
				distMatrix[row + id10*col] += h;

	
	for (col = 0; col<id2; col++)
		if (!coveredColumns[col])
			for (row = 0; row<id10; row++)
				distMatrix[row + id10*col] -= h;

	
	step3(assignment, distMatrix, starMatrix, id3, primeMatrix, coveredColumns, coveredRows, id10, id2, minDim);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    freopen("input.txt", "r", stdin);

    

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
		

		id7 algo;
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