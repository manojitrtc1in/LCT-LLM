






















using namespace std;



int comparator(const void *p, const void *q)
{
	

	int l = *(const int *)p;
	int r = *(const int *)q;

	return l - r;
}

struct output {
	int start;
	int differnce;
} o[10000 + 5];



bool cmp(output a, output b)
{
	if (a.differnce < b.differnce)
		return true;
	if (a.differnce == b.differnce && a.start < b.start)
		return true;
	else
	{
		return false;
	}
}


void Ski() {
	int hillCount = 0;
	int hillSize[1000];
	int changes[1000];
	int id5 = 0;
	int tempAnswer = 0;
	int Answer = 1000000;
	int i = 0;
	int j = 0;
	int id0 = hillCount - 1;


	for (i = 0; i < 1000; i++) {
		hillSize[i] = 0;
		changes[i] = 0;
	}
	FILE* fin = fopen("skidesign.in", "r");
	FILE* fout = fopen("skidesign.out", "w");

	fscanf(fin, "%d", &hillCount);
	


	


	for (i = 0; i < hillCount; i++) {
		fscanf(fin, "%d", &hillSize[i]);
		

	}

	qsort(hillSize, hillCount, sizeof(int), comparator);

	for (i = 0; i < hillCount; i++) {
		

	}

	for (i = 0; i < 83; i++) {
		tempAnswer = 0;
		for (j = 0; j< hillCount; j++) {
			if (hillSize[j] < i) {
				changes[j] = hillSize[j] - i;
			}
			else if (hillSize[j] > i + 17) {
				changes[j] = i + 17 - hillSize[j];
			}
			else {
				changes[j] = 0;
			}
		}


		for (j = 0; j< hillCount; j++) {
			tempAnswer += (changes[j]) * (changes[j]);
		}
		if (tempAnswer < Answer) {
			Answer = tempAnswer;
		}
	}


	printf("%d\n", Answer);
	fprintf(fout, "%d\n", Answer);

	fclose(fin);
	fclose(fout);

	return;

}



void id10() {
	int id9 = 0;
	int id3 = 0;
	int in = 0;
	int firstTerm = 1;
	int difference = 1;
	int currentTerm = 1;

	int havePrinted = 1;
	int exists[125001];

	set<int> id8;

	FILE* fin = fopen("id10.in", "r");
	FILE* fout = fopen("id10.out", "w");

	fscanf(fin, "%d", &id9);
	

	fscanf(fin, "%d", &id3);
	


	const int id11 = id3*id3 * 2 / (id9 - 1) + 1;
	const int id6 = id3*id3 * 2 - id9;

	int x, y, k = 0;
	memset(exists, 0, sizeof(exists));
	

	for (x = 0; x <= id3; x++) {
		for (y = x; y <= id3; y++) {
			int square = x*x + y*y;
			id8.insert(square);
			exists[square] = 1;
		}
	}


	for (set<int>::iterator iterators = id8.begin(); iterators != id8.end(); ++iterators) {		


		firstTerm = *iterators;
		for (difference = 1; difference < id11; difference++) {			


			currentTerm = *iterators;
			k = 0;
			if ((currentTerm == 2) && (difference == 8))
				printf("Here");

			for (y = 0; y < id9; y++) {		


				if (exists[currentTerm] == 0) {
					k = 1;
					break;
				}

				currentTerm += difference;

				if (currentTerm > 125000) {
					k = 1;
					break;
				}
			}
			if (k == 1)
				continue;
			else {
				havePrinted = 0;
				o[in].start = firstTerm;
				o[in].differnce = difference;
				in++;
				

				

			}
		}
	}

	sort(o, o + in, cmp);

	for (int i = 0; i < in; i++) {
		printf("%d %d\n", o[i].start, o[i].differnce);
		fprintf(fout, "%d %d\n", o[i].start, o[i].differnce);
	}

	if (in == 0)
		printf("NONE\n");
	if (havePrinted) {
		fprintf(fout, "NONE\n");
	}

	return;
}

const int M = 2014;

map<string, int> lookup;

string str;

ifstream fin;
ofstream fout;


int answers(string s) {
	int i = 1;
	if (lookup.find(s) != lookup.end()) {
		return lookup[s];
	}
	int answer = 1;
	int length = s.length();

	for (i = 1; 2 * i < length; i++) {
		if (s.substr(0, i) == s.substr(length - i, i)) {
			answer += answers(s.substr(i, length - i));
		}
		if (s.substr(0, i) == s.substr(i, i)) {
			answer += answers(s.substr(i, length - i));
		}
		if (s.substr(0, i) == s.substr(length - i, i)) {
			answer += answers(s.substr(0, length - i));
		}
		if (s.substr(length - i * 2, i) == s.substr(length - i, i)) {
			answer += answers(s.substr(0, length - i));
		}
	}

	answer %= M;
	lookup[s] = answer;
	return answer;
}

void secretCode() {
	cin.tie(nullptr);
	cout.tie(nullptr);

	fin.open("scode.in");
	fout.open("scode.out");
	fin >> str;
	

	int answer = (answers(str) + M - 1) % M;
	cout << answer << "\n";
	fout << answer << "\n";
}

void id2() {
	int x;
	int size;
	int numbers[100000];
	int answer = 0;
	int streak = 0;

	scanf("%d\n", &size);

	for (x = 0; x < size; x++) {
		cin >> numbers[x];
		

	}

	for (x = 1; x < size; x++) {
		if (numbers[x] > numbers[x - 1]) {
			streak++;
		}
		else {
			if (streak > answer) {
				answer = streak;
			}
			streak = 0;
		}
	}
	if (streak > answer) {
		answer = streak;
	}
	cout << answer + 1 << "\n";
	return;
}

vector <int> id7;
vector <int>::iterator it;
int prime[20];

int dp[200];
int used[200];
void id1(int n)
{
	

	

	



	for (int p = 2; p*p <= n; p++)
	{
		

		if (prime[p] != 1)
		{
			prime[p] = 0;
			

			for (int i = p * 2; i <= n; i += p)
				prime[i] = 1;
		}
	}

	

	for (int p = 2; p <= n; p++) {
		if (prime[p] == 1)
			id7.push_back(p);
	}
}

int splitter(int sum) {
	int x, y, z = 0;

	if (used[sum] == 1) {
		return dp[sum];
	}

	if (sum == 0) {
		return 0;
	}

	if (sum < 4) {
		return -10000000;
	}

	int answer = -1;
	for (it = id7.begin(); it != id7.end(); ++it) {
		x = *it;
		if (x > sum)
			break;
		answer = max(answer, splitter(sum - x) + 1);
	}

	dp[sum] = answer;
	used[sum] = 1;
	return answer;
}

void id4() {
	int queries;
	int x = 0;
	int k = 0;

	cin >> queries;

	id1(20);
	int answer = 0;

	for (x = 0; x < queries; x++) {
		cin >> k;
		if (k < 16)
			answer = splitter(k);
		else {
			

			answer = (x + 1) % 4;
		}
		answer = splitter(k);
		cout << answer << "\n";
	}



	return;
}

void Equalize() {
	
	int x = 0;
	int SL = 0;
	int cost = 0;
	cin >> SL;
	
	char*a;
	char*b;
	a = (char*)malloc(sizeof(char)*SL);
	b = (char*)malloc(sizeof(char)*SL);

	for (x=0; x < SL; x++) {
		cin >> a[x];
	}

	for (x = 0; x < SL; x++) {
		cin >> b[x];
	}

	for (x = 0; x < SL; x++) {
		if (a[x] == b[x])
			continue;
		if (a[x + 1] != b[x + 1]) {
			swap(a[x + 1], a[x]);
			cost++;
			continue;
		}
		cost++;
	}

	cout << cost << "\n";


	return;
}

int main()
{
	


	

	



	

	

	

	

	

	

	

	

	

	

	


	


	


	

	

	


	

	

	

	

	

	

	

	

	Equalize();
	



	return 0;
}


