







class SegmentTree
{
	SegmentTree *a;
	SegmentTree *b;

	int lenA;
	int lenB;
	int length;

	int min;

public:
	int parentPoint;

	void initialize(int parentPoint, int length)
	{
		this->length = length;
		lenA = length / 2;
		lenB = length - lenA;

		a = this + 1;
		b = a + (2 * lenA - 1);

		this->parentPoint = parentPoint;

		if (length > 1)
		{
			a->initialize(parentPoint, lenA);
			b->initialize(parentPoint, lenB);
		}
	}

	void set(int at, int val)
	{
		if (length == 1)
		{
			min = val;
		} else
		{
			if (at < lenA)
				a->set(at, val);
			else
				b->set(at - lenA, val);

			if (a->min < b->min)
				min = a->min;
			else
				min = b->min;
		}
	}

	int getMin(int from, int to)
	{
		if (from == 0 && to == length - 1)
		{
			return min;
		} else
		{
			if (to < lenA)
				return a->getMin(from, to);
			else if (from >= lenA)
				return b->getMin(from - lenA, to - lenA);

			int minA = a->getMin(from, lenA - 1);
			int minB = b->getMin(0, to - lenA);

			if (minA < minB)
				return minA;
			else
				return minB;
		}
	}
};

struct Vertex
{
	int price;

	bool visited;

	int depth;
	int component;

	int componentPos;

	std::vector<int> children;
};

struct Point
{
	int parent;

	int parentPos;

	SegmentTree *tree;
	int treePos;

	int depth;
	int weight;
	int longest;

	bool articulation;

	int *vertex;
	int vertices;

	std::vector<int> children;
};

namespace BinHeap
{
	void generate(int *data, Vertex *vertex, int length);
	void update(int *data, Vertex *vertex, int length, int at);
	void bubble(int *data, Vertex *vertex, int length, int child);
	void sink(int *data, Vertex *vertex, int length, int parent);
	void swap(int *data, Vertex *vertex, int a, int b);

	void generate(int *data, Vertex *vertex, int length)
	{
		for (int i = length - 1; i >= 0; i--)
		{
			vertex[data[i]].componentPos = i;
			sink(data, vertex, length, i);
		}
	}

	void update(int *data, Vertex *vertex, int length, int at)
	{
		sink(data, vertex, length, at);
		bubble(data, vertex, length, at);
	}

	void bubble(int *data, Vertex *vertex, int length, int child)
	{
		while (true)
		{
			if (child <= 0)
				return;

			int parent = (child - 1) / 2;

			if (vertex[data[child]].price < vertex[data[parent]].price)
			{
				swap(data, vertex, child, parent);
				child = parent;
			} else
			{
				return;
			}
		}
	}

	void sink(int *data, Vertex *vertex, int length, int parent)
	{
		while (true)
		{
			int child = parent * 2 + 1;

			if (child >= length)
				return;

			int child2 = child + 1;

			if (child2 < length && vertex[data[child2]].price < vertex[data[child]].price)
				child = child2;

			if (vertex[data[child]].price < vertex[data[parent]].price)
			{
				swap(data, vertex, child, parent);
				parent = child;
			} else
			{
				return;
			}
		}
	}

	void swap(int *data, Vertex *vertex, int a, int b)
	{
		int temp = data[a];
		data[a] = data[b];
		data[b] = temp;

		vertex[data[a]].componentPos = a;
		vertex[data[b]].componentPos = b;
	}
}

int DFS(int which, int from);
void DFSPoints(int which, int from);
SegmentTree *id2(int which, int from, SegmentTree *t, int tPos, SegmentTree *next);

int n, m, q;

Vertex vertex[MAX];
Point point[MAX * 10];
int points = 0;

int pointVertices[MAX * 2];
int id1 = 0;

SegmentTree tree[2 * 2 * MAX - 1];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m >> q;

	for (int i = 0; i < n; i++)
	{
		std::cin >> vertex[i].price;
		vertex[i].visited = false;
		vertex[i].component = -1;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		vertex[a].children.push_back(b);
		vertex[b].children.push_back(a);
	}

	DFS(0, -1);
	DFSPoints(vertex[0].component, -1);

	tree->initialize(-1, point[vertex[0].component].longest);
	id2(vertex[0].component, -1, tree, 0, tree + (point[vertex[0].component].longest * 2 - 1));

	
		for (int i = 0; i < n; i++)
			std::cout << "Vertex " << i + 1 << ": component " << vertex[i].component << ", binheap " << vertex[i].componentPos << ", depth " << vertex[i].depth << ", price " << vertex[i].price << std::endl;
		for (int i = 0; i < points; i++)
		{
			if (point[i].articulation)
				std::cout << "Articulation point ";
			else
				std::cout << "Point ";
			std::cout << i << ": depth " << point[i].depth << ", weight " << point[i].weight << ", longest " << point[i].longest << ", tree " << point[i].tree << ", tree pos " << point[i].treePos << ", " << point[i].vertices << " vertices:" << std::endl;
			for (int j = 0; j < point[i].vertices; j++)
				std::cout << " " << point[i].vertex[j];
			std::cout << std::endl;
			for (int j = 0; j < point[i].children.size(); j++)
				std::cout << " " << point[i].children[j];
			std::cout << std::endl;
		}
	


	int outputCount = 0;

	for (int i = 0; i < q; i++)
	{
		char type;
		int a, b;
		std::cin >> type >> a >> b;
		a--;

		if (type == 'C')
		{
			vertex[a].price = b;
			int c = vertex[a].component;
			int cp = vertex[a].componentPos;
			if (point[c].articulation)
			{
				if (point[c].parent >= 0)
				{
					int p = point[c].parent;
					BinHeap::update(point[p].vertex, vertex, point[p].vertices, cp);
					point[p].tree->set(point[p].treePos, vertex[point[p].vertex[0]].price);
				}
			} else
			{
				BinHeap::update(point[c].vertex, vertex, point[c].vertices, cp);
			}
			point[c].tree->set(point[c].treePos, vertex[point[c].vertex[0]].price);
		} else
		{
			b--;

			if (a == b)
			{
				std::cout << vertex[a].price;
				
					std::cout << std::endl;
				
					std::cout << "\n";
				

				continue;
			}

			a = vertex[a].component;
			b = vertex[b].component;

			
				std::cout << "Starting at component " << a << " and " << b << std::endl;
			


			SegmentTree *treeA = point[a].tree;
			SegmentTree *treeB = point[b].tree;

			int posA = point[a].treePos;
			int posB = point[b].treePos;

			int min = vertex[point[a].vertex[0]].price;

			while (treeA != treeB)
			{
				int nMin;
				if (treeB->parentPoint != -1 && (treeA->parentPoint == -1 || point[treeA->parentPoint].depth < point[treeB->parentPoint].depth))
				{
					nMin = treeB->getMin(0, posB);
					b = treeB->parentPoint;
					treeB = point[b].tree;
					posB = point[b].treePos;

				} else if (treeA->parentPoint != -1)
				{
					nMin = treeA->getMin(0, posA);
					a = treeA->parentPoint;
					treeA = point[a].tree;
					posA = point[a].treePos;
				} else
				{
					return 69;
				}

				if (nMin < min)
					min = nMin;

				
					std::cout << "\tNow at component " << a << " and " << b << ", min: " << min << std::endl;
				

			}

			


			int nMin;
			if (posA > posB)
			{
				nMin = treeA->getMin(posB, posA);
				a = b;
			} else
			{
				nMin = treeA->getMin(posA, posB);
				b = a;
			}
			if (nMin < min)
				min = nMin;

			int pc = point[a].parent;

			if (pc >= 0 && !point[a].articulation)
				if (vertex[point[pc].vertex[0]].price < min)
					min = vertex[point[pc].vertex[0]].price;

			std::cout << min;
			
				std::cout << std::endl;
			
				std::cout << "\n";
			

		}
	}

	return 0;
}

int stack[MAX];
int sp = 0;

int depth = 0;

int DFS(int which, int from)
{
	if (vertex[which].visited)
		return vertex[which].depth;

	
		std::cout << "DFSing into " << which + 1 << " from " << from + 1 << " at depth " << depth << std::endl;
	


	vertex[which].visited = true;
	vertex[which].depth = depth;

	stack[sp++] = which;

	int minDepth = depth;
	int id0 = 0;

	int firstComponent = -1;

	depth++;
	for (int i = 0; i < vertex[which].children.size(); i++)
	{
		int to = vertex[which].children[i];

		if (to == from)
			continue;

		if (!vertex[to].visited)
			id0++;

		int nDepth = DFS(to, which);

		if (nDepth == vertex[which].depth || nDepth == depth)
		{
			
				std::cout << "Child " << to + 1 << " doesn't reach farther back than " << which + 1 << ", creating articulation point" << std::endl;
			

			int pointId = points++;

			if (firstComponent == -1)
				firstComponent = pointId;

			point[pointId].articulation = false;
			point[pointId].vertex = pointVertices + id1;
			point[pointId].vertices = 0;

			int taken;

			do
			{
				taken = stack[--sp];
				
					std::cout << "Adding " << taken + 1 << " to point " << pointId << " from " << vertex[taken].component << std::endl;
				

				if (vertex[taken].component == -1)
				{
					vertex[taken].component = pointId;
				} else
				{
					point[pointId].children.push_back(vertex[taken].component);
					point[vertex[taken].component].children.push_back(pointId);
				}
				pointVertices[id1++] = taken;
				point[pointId].vertices++;
			} while (taken != to);

			BinHeap::generate(point[pointId].vertex, vertex, point[pointId].vertices);

			if (vertex[which].component == -1)
			{
				int pointId = points++;
				
					std::cout << "Adding parent " << which + 1 << " into articulation point " << pointId << std::endl;
				

				vertex[which].component = pointId;
				point[pointId].articulation = true;
				point[pointId].vertex = pointVertices + id1;
				point[pointId].vertices = 1;
				pointVertices[id1++] = which;
				

			}

			point[vertex[which].component].children.push_back(pointId);
			if (vertex[which].depth != 0)
				point[pointId].children.push_back(vertex[which].component);
		}

		if (nDepth < minDepth)
			minDepth = nDepth;
	}
	depth--;

	

	if (depth == 0)
	{
		int c = vertex[which].component;

		if (id0 == 1)
		{
			
				std::cout << "Removing parent " << which + 1 << " from articulation point, because it is root, and adding it to point " << firstComponent << std::endl;
			

			point[firstComponent].vertices++;

			vertex[which].component = firstComponent;
			vertex[which].componentPos = point[firstComponent].vertices - 1;

			BinHeap::bubble(point[firstComponent].vertex, vertex, point[firstComponent].vertices, point[firstComponent].vertices - 1);
			points--;
		} else
		{
			for (int i = 0; i < point[c].children.size(); i++)
				point[point[c].children[i]].children.push_back(c);
		}
	}

	return minDepth;
}

void DFSPoints(int which, int from)
{
	point[which].depth = depth;
	point[which].weight = 0;
	point[which].longest = 1;
	point[which].parent = from;

	int heaviest = -1;

	depth++;
	for (int i = 0; i < point[which].children.size(); i++)
	{
		int to = point[which].children[i];

		if (to == from)
			continue;

		DFSPoints(to, which);
		point[which].weight += point[to].weight + 1;
		if (point[to].weight > heaviest)
		{
			heaviest = point[to].weight;
			point[which].longest = point[to].longest + 1;
		}
	}
	depth--;
}

SegmentTree *id2(int which, int from, SegmentTree *t, int tPos, SegmentTree *next)
{
	point[which].tree = t;
	point[which].treePos = tPos;

	t->set(tPos, vertex[point[which].vertex[0]].price);

	
		std::cout << "Point " << which << ": Tree " << t << "[" << tPos << "] <- " << vertex[point[which].vertex[0]].price << ", next: " << next << std::endl;
	


	int heaviest = -1;
	int weight = -1;

	for (int i = 0; i < point[which].children.size(); i++)
	{
		int to = point[which].children[i];

		if (to == from)
			continue;

		if (point[to].weight > weight)
		{
			heaviest = to;
			weight = point[to].weight;
		}
	}

	if (heaviest != -1)
		next = id2(heaviest, which, t, tPos + 1, next);

	
		std::cout << "Point " << which << ": Tree " << t << "[" << tPos << "] <- " << vertex[point[which].vertex[0]].price << ", next: " << next << std::endl;
	


	for (int i = 0; i < point[which].children.size(); i++)
	{
		int to = point[which].children[i];

		if (to == from || to == heaviest)
			continue;

		next->initialize(which, point[to].longest);
		next = id2(to, which, next, 0, next + (point[to].longest * 2 - 1));

		
			std::cout << "Point " << which << ": Tree " << t << "[" << tPos << "] <- " << vertex[point[which].vertex[0]].price << ", next: " << next << std::endl;
		

	}

	return next;
}
