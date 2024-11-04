











using namespace std;









clock_t timeMark;

void timeStart()
{
	timeMark = clock();
}

void timeEnd()
{
	clock_t x = clock();
	cout << "- took " << ((x-timeMark)*1000/CLOCKS_PER_SEC) << " ms." << endl;
}


struct Path
{
	long long len; 

	int a; 

	int b; 

	Path(int len, int a, int b) : len(len), a(a), b(b) {}
};

bool pathcmp(Path a, Path b) { return a.len > b.len; }



struct Subtree
{
	vector<int> nodes; 

	vector<int>* neighbors; 

	int n; 

	Subtree(int n) : n(n) { neighbors=new vector<int>[n]; }

	

	

	

	void add_node_as_neighbor(int node_id, int id5)
	{
		
		cout << node_id << " --> " << id5 << endl;
		
		nodes.push_back(node_id);
		neighbors[id5].push_back(node_id);
		neighbors[node_id].push_back(id5);
	}

	

	

	

	void append(Subtree *subtree, int id1, int id2)
	{
		nodes.insert(nodes.end(), subtree->nodes.begin(), subtree->nodes.end());
		for (int i=0; i<n; i++)
		{
			neighbors[i].insert(
				neighbors[i].end(),
				subtree->neighbors[i].begin(),
				subtree->neighbors[i].end());
		}
		neighbors[id1].push_back(id2);
		neighbors[id2].push_back(id1);
	}
};

bool id0(long long *m, long long *im, int n, Subtree *subtree, int start_id, int prev_id, int cur_id, int len)
{
	if (len != m[start_id + n*cur_id])
	{
		
		cout << "nodes " << start_id << ">" << cur_id << ", length mismatch: " << len << " and " << m[start_id + n*cur_id] << endl;
		
		return false;
	}

	for (int i=0; i<subtree->neighbors[cur_id].size(); i++)
	{
		int nei_id = subtree->neighbors[cur_id][i];
		if (nei_id == prev_id) continue;
		bool res = id0(m, im, n, subtree, start_id, cur_id, nei_id, len+m[cur_id + n*nei_id]);
		if (!res) return false;
	}
	return true;
}

















bool id2(long long* m, int n, Subtree* subtree, int prev_id, int id1, int id2, int len)
{
	
	cout << "len " << len << " between " << id1 << " and " << id2 << endl;
	

	if (len < 0) return false;
	if (id1 == id2) return len==0;

	for (int i=0; i<subtree->neighbors[id1].size(); i++)
	{
		int nei_id = subtree->neighbors[id1][i];
		if (nei_id == prev_id) continue;
		bool res = id2(m, n, subtree, id1, nei_id, id2, len-m[id1 + n*nei_id]);
		if (res) return true;
	}

	return false;
}

inline long long read_val(unsigned char *buf, int &offset)
{
	while(buf[offset]<'0' || buf[offset]>'9') offset++;
	long long val = 0;
	while(buf[offset]>='0' && buf[offset]<='9')
	{
		val = val*10 + buf[offset]-'0';
		offset++;
	}
	return val;
}


int main()
{
	
	cout << "Starting..." << endl;
	

	int max_size = 128*1024*1024;
	int size = 0, c, id1 = 0;
	int buf_offset = 0;
	unsigned char *buf = new unsigned char[max_size];
	while(1)
	{
		c = read(0, (void*)buf+size, max_size-size);
		if (c < 0) exit(1);
		if (c == 0) id1++;
		if (id1 > 10) break;
		size += c;
	}
	buf[size] = 0;

	int n;
	while(buf_offset < size-1)
	{
		n = read_val(buf, buf_offset);
		
		cout << "Processing " << n << "x" << n << "..." << endl;
		cout << "Preparing read arrays..." << endl;
		
		timeStart();
		
		
		long long *m, *im;
		m = new long long[n*n];
		im = new long long[n*n];
		vector<Path> paths; 

		memset(im, 0, n*n*sizeof(long long));
		
		
		timeEnd();
		
		

		
		cout << "Preparing magic buffers..." << endl;
		
		timeStart();
		
		
		vector<Subtree*> subtrees; 

		for (int i=0; i<n; i++) subtrees.push_back(NULL); 

		int trees_count = 0;
		int nodes_added = 0;

		bool checked[n];
		vector<int> *nodes_to_check = new vector<int>;
		vector<int> *new_nodes_to_check = new vector<int>;
		Subtree *subtree;
		bool res;
		
		
		timeEnd();
		
		


		
		cout << "Reading..." << endl;
		
		timeStart();
		
		
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				

				

				m[i+n*j] = read_val(buf, buf_offset);
				if (i>j) paths.push_back(Path(m[i+n*j], i, j));
			}
		}
		
		
		timeEnd();
		
		

		
		cout << n << endl;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout << m[i+n*j] << "\t";
			}
			cout << endl;
		}
		

		
		cout << "Simple tests..." << endl;
		
		timeStart();
		
		
		

		if (n==1) { if (m[0]==0) goto yes; else goto no; }

		

		for (int i=0; i<n; i++)
		{
			

			if (m[i+n*i] != 0) goto no;
			for (int j=0; j<n; j++)
			{
				

				if ((i != j) && (m[i+n*j] <= 0)) goto no;
				

				if (m[i+n*j] != m[j+n*i]) goto no;
			}
		}

		
		
		timeEnd();
		
		


		
		cout << "Sorting..." << endl;
		
		timeStart();
		
		
		sort(paths.begin(), paths.end(), pathcmp);
		
		
		timeEnd();
		
		


		
		cout << "Magic..." << endl;
		
		timeStart();
		
		
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		while(paths.size() > 0)
		{
			Path p = paths.back();
			paths.pop_back();

			Subtree* id4 = subtrees[p.a]; 

			Subtree* id3 = subtrees[p.b]; 


			
			cout <<p.len<<"|"<< p.a << p.b << " | " << !!id4 << !!id3 << "|"<<!!(id4==id3)<<endl;
			
			if (!id4 && !id3) 

			{
				im[p.a+n*p.b] = im[p.b+n*p.a] = p.len;

				Subtree* subtree = new Subtree(n);
				subtree->add_node_as_neighbor(p.a, p.b);
				

				subtree->nodes.push_back(p.b);

				subtrees[p.a] = subtree;
				subtrees[p.b] = subtree;

				trees_count++;
				nodes_added += 2;
			}
			else if (!id3) 

			{
				im[p.a+n*p.b] = im[p.b+n*p.a] = p.len;
				id4->add_node_as_neighbor(p.b, p.a);
				subtrees[p.b] = id4;
				nodes_added++;
			}
			else if (!id4) 

			{
				im[p.a+n*p.b] = im[p.b+n*p.a] = p.len;
				id3->add_node_as_neighbor(p.a, p.b);
				subtrees[p.a] = id3;
				nodes_added++;
			}
			else if (id4 == id3) 

			{
				
			}
			else 

			{
				im[p.a+n*p.b] = im[p.b+n*p.a] = p.len;

				
				cout << "merging ";
				for (int i=0; i<id4->nodes.size(); i++) cout << id4->nodes[i] << " ";
				cout << "and ";
				for (int i=0; i<id3->nodes.size(); i++) cout << id3->nodes[i] << " ";
				cout << "--> ";
				

				for (int i=0; i<id3->nodes.size(); i++)
				{
					subtrees[id3->nodes[i]] = id4;
				}
				trees_count--;
				id4->append(id3, p.a, p.b);

				
				for (int i=0; i<id4->nodes.size(); i++) cout << id4->nodes[i] << " ";
				cout << endl;
				
			}

			

			

		}


		
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout << im[i+n*j] << "\t";
			}
			cout << endl;
		}
		cout << "nodes added: " << nodes_added << ", trees created: " << trees_count << endl;
		


		if (nodes_added!=n || trees_count!=1) goto no;
		
		
		timeEnd();
		
		

		
		cout << "Checking..." << endl;
		
		timeStart();
		
		
		for (int i=0; i<n; i++)
		{
			res = id0(m, im, n, subtrees[0], i, -1, i, 0);
			if (!res) goto no;
		}
		

		

		
		
		timeEnd();
		
		


		yes:
		cout << "YES";
		goto end;

		no:
		cout << "NO";

		end:
		cout << endl;
		
		cout << endl;
		cout << endl;
		
	}
}