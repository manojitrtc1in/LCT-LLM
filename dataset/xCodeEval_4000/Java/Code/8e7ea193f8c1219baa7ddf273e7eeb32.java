
import java.io.IOException; 
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*; 

public class Main 
{     

    public static void main(String[] args)throws Exception          
    {              
        Reader r = new Reader();     

        r.readLine();
        int n = r.readInt(0);
		int m = r.readInt(1);

        Trie trie = new Trie();

        for (int i=0;i < n;++i)
        {
            r.readLine();
			trie.add(r.readString(0));
        }

		StringBuilder res = new StringBuilder();
		for (int i=0;i < m;++i)
		{
			r.readLine();
			res.append(trie.diff(r.readString(0)) ?"YES": "NO").append("\n");
		}

		System.out.print(res);
		r.close();     
    }

    private static int bfs(List<List<Integer>> graph, int v)
    {
        Queue<Integer> queue = new LinkedList<>();

        queue.add(v);

        boolean flag[] = new boolean[graph.size()];

        while (!queue.isEmpty())
        {
            v = queue.poll();

            flag[v] = true;

            for (int u:graph.get(v))
                if (!flag[u])
                    queue.add(u);

        }
        return v;
    }

    

    public static int lower_bound(List<Integer> arr, int lo, int hi, int key, int arrSize)
    {
        if (hi == arrSize)
            --hi;

        int len = hi + 1;
        int mid = (lo + hi) / 2;

        while (true)
        {
            if (arr.get(mid) >= key)
            {
                hi = mid - 1;
                if (hi < lo)
                    return mid;
            }
            else
            {
                lo = mid + 1;
                if (hi < lo)
                    return mid < len - 1 ?mid + 1: -1;
            }
            mid = (lo + hi) / 2;
        }
    }

    public static int lower_bound(List<Integer> arr, int key)
    {

        int len = arr.size();
        int lo = 0;
        int hi = len - 1;
        int mid = (lo + hi) / 2;

        while (true)
        {
            if (arr.get(mid) >= key)
            {
                hi = mid - 1;
                if (hi < lo)
                    return mid;
            }
            else
            {
                lo = mid + 1;
                if (hi < lo)
                    return mid < len - 1 ?mid + 1: 
                    len; 
            }
            mid = (lo + hi) / 2;
        }
    }

    public static int upper_bound(List<Integer> arr, int lo, int hi, int key, int arrSize)
    {

        if (hi == arrSize)
            --hi;

        if (arr == null || arr.isEmpty())
            return -1;

        int len = hi + 1;
        int mid = (lo + hi) / 2;

        while (true)
        {
            if (arr.get(mid) <= key)
            {
                lo = mid + 1;
                if (hi < lo) 
                    return mid < len - 1 ?mid + 1: -1; 
            }
            else
            {
                hi = mid - 1;
                if (hi < lo)
                    return mid;
            }
            mid = (lo + hi) / 2;
        }

    }

    public static int upper_bound(List<Integer> arr, int key)
    {

        int len = arr.size();
        int hi = len - 1;
        int lo = 0;
        int mid = (lo + hi) / 2;

        while (true)
        {
            if (arr.get(mid) <= key)
            {
                lo = mid + 1;
                if (hi < lo) 
                    return mid < len - 1 ?mid + 1: 
                    len; 
            }
            else
            {
                hi = mid - 1;
                if (hi < lo)
                    return mid;
            }
            mid = (lo + hi) / 2;
        }

    }

} 



class Pair<K,V>
{
    protected K f;
    protected V s;

    public Pair(K f, V s)
    {
        this.f = f;
        this.s = s;
    }

    @Override
    public String toString()
    {
        return f.toString() + " " + s.toString();
    }
}

class Reader
{     
    private BufferedReader reader; 
    private String line[];     

    public Reader()     
    {         
        reader = new BufferedReader(new InputStreamReader(System.in));     
    }     

    public String[] getLine()     
    {         
        return line;     
    }     

    public boolean readLine()     throws IOException 
    {         
        String str = reader.readLine();
        if (str == null || str.isEmpty())
            return false;
        line = line = str.split(" ");
        return true;
    }    

    public List<Integer> getIntegersList()
    {
        List<Integer> res = new ArrayList<>();
        for (String str:line)
            res.add(Integer.parseInt(str));
        return res;

    }

    public int readInt(int pos)throws IOException     
    {         
        return Integer.parseInt(line[pos]);     
    }     

    public double readDouble(int pos)throws IOException     
    {         
        return Double.parseDouble(line[pos]);     
    }     

    public long readLong(int pos)throws IOException 
    {         
        return Long.parseLong(line[pos]); 
    }     

    public String readString(int pos)throws IOException     
    {         
        return line[pos];     
    }     

    public void close()throws IOException 
    {         
        reader.close();     
    }
}

class Vertix extends Pair<Integer,Integer>
{

    public Vertix(int from, int to)
    {
        super(from, to);

    }

    public int getFrom()
    {
        return f;
    }

    public int getTo()
    {
        return s;
    }
}

class Edge 
{
    private Vertix vertix;
    private int weight;
    public Edge(Vertix vertix, int weight)
    {
        this.vertix = vertix;
        this.weight = weight;
    }


    public Vertix getVertix()
    {
        return vertix;
    }

    public int getWeight()
    {
        return weight;
    }
}

class ToWeight extends Pair<Integer,Integer> implements Comparable<ToWeight>
{
    public ToWeight(int to, int weight)
    {
        super(to, weight);
    }

    int getTo()
    {
        return f;
    }

    int getWeight()
    {
        return s;
    }

    @Override
    public int compareTo(ToWeight p)
    {
        return s - p.s;
    }

}

class Graph
{
    private boolean isDirected;
    private int nodesCount;
    List<List<ToWeight>> adjList;

    public Graph(int nodesCount, boolean isDirected)
    {
        this(nodesCount);
        this.isDirected = isDirected;
    }

    public Graph(int nodesCount)
    {
        this.nodesCount = nodesCount;
        adjList = new ArrayList<>();
        for (int i=0;i <= nodesCount;++i)
            adjList.add(new ArrayList<ToWeight>());
    }

    public boolean isDirected()
    {
        return isDirected;
    }

    public int getNodesCount()
    {
        return nodesCount;
    }

    public void addEdge(int fr, int to, int w)
    {
        adjList.get(fr).add(new ToWeight(to, w));

        if (!isDirected)
            adjList.get(to).add(new ToWeight(fr, w));

    }

    public List<ToWeight> get(int v)
    {
        return adjList.get(v);
    }
}

class GraphUtils
{

    public static GeneralResult dijkstra(Graph graph, int src)
    {
        int sz = graph.getNodesCount();
        int distance[] = new int[sz + 1];
        int parent[] = new int[sz + 1];
        boolean visited[]= new boolean[sz + 1];

        for (int i=0;i <= sz;++i)
        {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;

        }

        PriorityQueue<ToWeight> queue = new PriorityQueue<>();

        distance[src] = 0;
        queue.add(new ToWeight(src, 0));

        while (!queue.isEmpty())
        {
            ToWeight v = queue.poll();
            int to = v.getTo();

            if (visited[to])
                continue;

            visited[to] = true;

            for (ToWeight vv:graph.get(to))
            {
                if (!visited[vv.getTo()] && distance[vv.getTo()] > distance[to] + vv.getWeight())
                {
                    distance[vv.getTo()] = distance[to] + vv.getWeight();
                    parent[vv.getTo()] = to;
                    queue.add(new ToWeight(vv.getTo(), distance[vv.getTo()]));
                }
            }
        }
        return new GeneralResult(parent, distance);
    }

    public static GeneralResult primMST(Graph graph)
    {

        int sz = graph.getNodesCount();
        int distance[] = new int[sz + 1];
        int parent[] = new int[sz + 1];
        boolean visited[]= new boolean[sz + 1];

        for (int i=0;i <= sz;++i)
        {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;

        }

        PriorityQueue<ToWeight> queue = new PriorityQueue<>();

        distance[1] = 0;
        queue.add(new ToWeight(1, 0));

        while (!queue.isEmpty())
        {
            ToWeight v = queue.poll();
            int to = v.getTo();

            visited[to] = true;

            for (ToWeight vv:graph.get(to))
            {
                if (!visited[vv.getTo()] && distance[vv.getTo()] >  v.getWeight())
                {
                    distance[vv.getTo()] =  vv.getWeight();
                    parent[vv.getTo()] = to;
                    queue.add(new ToWeight(vv.getTo(), distance[vv.getTo()]));
                }
            }
        }
        return new GeneralResult(parent, distance);
    }

    public static void dfs(int v, Graph graph, boolean []visited)
    {
        visited[v] = true;
        for (ToWeight to:graph.get(v))
            if (!visited[to.getTo()])
                visited[to.getTo()] = true;
    }

    public static boolean isCyclicDirectedGraph(int v, Graph g, boolean visited[], boolean inStack[])
    {
        if (inStack[v])
            return true;

        if (visited[v])
            return false;

        inStack[v] = visited[v] = true;

        for (ToWeight u:g.get(v))
            if (isCyclicDirectedGraph(u.getTo(), g, visited, inStack))
                return true;

        inStack[v] = false;
        return false;
    }


    public static boolean isCyclicDirectedGraphUsingColors(int v, Graph g)
    {
        int []colors = new int[g.getNodesCount() + 1];

        boolean visited[] = new boolean[g.getNodesCount() + 1];

        return isCyclicDirectedGraphUsingColors(v, g, visited, colors);
    }

    private static boolean isCyclicDirectedGraphUsingColors(int v, Graph g, boolean []visited, int []colors)
    {
        colors[v] = 1;

        for (ToWeight u:g.get(v))
        {
            if (colors[u.getTo()] == 1)
                return true;

            if (colors[u.getTo()] == 0 && isCyclicDirectedGraphUsingColors(u.getTo(), g, visited, colors))
                return true;
        }

        colors[v] = 2;
        return false;
    }

    public static List<List<Integer>> getAllDirectedCycles(Graph g)
    {
        List<List<Integer>> cycles = new ArrayList<>();
        dfsCycle(1, 0, new int[g.getNodesCount() + 1], new int[g.getNodesCount() + 1], g, cycles);
        return cycles;
    }

    private static void dfsCycle(int v, int p, int color[], int parent[], Graph g, List<List<Integer>> cycles)
    {
        if (color[v] == 2)
            return;

        if (color[v] == 1)
        {

            int cycleCount = cycles.size();
            cycles.add(new ArrayList<Integer>());

            int cur = p;

            while (cur != v)
            {
                cur = parent[cur];

                cycles.get(cycleCount).add(cur);
            }
        }


        parent[v] = p;
        color[v] = 1;

        for (ToWeight u:g.get(v))
        {
            if (u.getTo() == parent[v])
                continue;

            dfsCycle(u.getTo(), v, color, parent, g, cycles);
        }

        color[v] = 2;

    }

    public static class GeneralResult
    {
        private int distance[];
        private int parent[];


        public GeneralResult(int parent[], int distance[])
        {
            this.parent = parent;
            this.distance = distance;
        }

        public int getValue(int dest)
        {
            return distance[dest];
        }

        public List<Integer> getPath(int dest)
        {
            List<Integer> res = new ArrayList<Integer>();

            if (distance[dest] == Integer.MAX_VALUE)
                return res;

            res.add(dest);
            for (int v=parent[dest];v != -1;v = parent[v])
                res.add(v);

            return res;
        }
    }
}

class DSU
{

    private int n;
    private SubSet subSet[];


    public DSU(int n)
    {

        this.n = n;
        subSet = new SubSet[n + 1];

        for (int i=0;i <= n;++i)
        {
            subSet[i] = new SubSet();
            subSet[i].parent = i;
            subSet[i].rank = 1;
        }
    }

    public int find(int v)
    {
        if (subSet[v].parent == v)
            return v;

        return subSet[v].parent = find(subSet[v].parent);
    }

    public void union(int x, int y)
    {
        int xr = find(x);
        int yr = find(y);

        if (xr == yr)
            return;


        subSet[xr].parent = yr;
        subSet[yr].rank += subSet[xr].rank;
    }

    public int getSize(int v)
    {
        return subSet[find(v)].rank;
    }

    @Override
    public String toString()
    {
        return Arrays.toString(subSet);
    }

    private class SubSet
    {
        int parent,rank;

        @Override
        public String toString()
        {
            return parent + " " + rank;
        }
    }

}

class SquareRootDecomposition
{
    private int n;

    private Query queries[];
    private int qCount;
    private int blockSize;
    private int idx = 0;

    public SquareRootDecomposition(int n)
    {
        this.n = n;
    }

    public void setQCount(int qCount)
    {
        this.qCount = qCount;
        queries = new Query[qCount];
        blockSize = (int)Math.sqrt(n);
    }

    public void addQuery(int l, int r)
    {
        queries[idx] = new Query(l, r, blockSize, idx);
        ++idx;
    }

    public long[] getResult(List<Integer> arr)
    {
        long[] res= new long[qCount];

        Arrays.sort(queries);


        int l=1,r=0;
        long ans = 0;

        for (int i=0;i < qCount;++i)
        {
            Query q = queries[i];


            while (r > q.r)
            {
                int v = arr.get(r);
                --r;
            }

            while (r < q.r)
            {
                ++r;
                int v = arr.get(r);

            }

            while (l < q.l)
            {
                int v = arr.get(l);
                ++l;
            }

            while (l > q.l)
            {

                --l;
                int v = arr.get(l);

            }

            res[q.queryN] = ans;
        }

        return res;
    }

    private class Query implements Comparable<Query>
    {
        private int l,r,blockSize,queryN;

        public Query(int l, int r, int blockSize, int queryN)
        {
            this.l = l;
            this.r = r;
            this.blockSize = blockSize;
            this.queryN = queryN;
        }

        @Override
        public int compareTo(Query o)
        {
            if (l / blockSize != o.l / blockSize)
                return l / blockSize - o.l / blockSize;
            return r - o.r;
        }

        @Override
        public String toString()
        {
            return l + " " + r  + " " + queryN + " " + blockSize;
        }
    }
}

class SegmentTree
{
    

    private final static int N = 1_000_00;

    

    private int n;

    private int t[];
    private int arr[];

    public SegmentTree(int arr[], int n)
    {
        this.n = n;
        t = new int[2 * n];
        this.arr = arr;
    }

    public void build()
    {
        for (int i=0;i < n;++i)
            t[n + i] = arr[i];

        for (int i=n - 1;i > 0;--i)
            t[i] = t[i << 1] + t[i << 1 | 1];

    }

    public void modify(int p, int val)
    {
        for (t[p + n] = val;p > 1;p >>= 1)
        {
            t[p >> 1] = t[p] + t[p ^ 1];
        }
    }

    public int query(int l, int r) 
    { 
        int res = 0; 
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
        { 
            if ((l & 1) != 0) 
                res += t[l++]; 
            if ((r & 1) != 0) 
                res += t[--r]; 
        } 
        return res; 
    }
}

class Tree
{

    private Node root;


    private class Node
    {
        private Node left,right;
        char v;
    }

    public void root(char root)
    {
        this.root = new Node();
        this.root.v = root;
    }

    public void add(String str)
    {
        int len = str.length();

        Node cur =root;
        for (char ch:str.substring(0, len - 1).toCharArray())
        {
            if (ch == 'L')
            {
                if (cur.left == null)
                    cur.left = new Node();
                cur = cur.left;
            }
            else
            {
                if (cur.right == null)
                    cur.right = new Node();
                cur = cur.right;

            }
        }

        cur.v = str.charAt(len - 1);
    }

    private void post(Node node, StringBuilder res)
    {
        if (node == null)
            return;

        post(node.left, res);
        post(node.right, res);
        res.append(node.v);
    }

    private void pre(Node node, StringBuilder res)
    {
        if (node == null)
            return;

        res.append(node.v);
        pre(node.left, res);
        pre(node.right, res);
    }

    private void in(Node node, StringBuilder res)
    {
        if (node == null)
            return;

        in(node.left, res);
        res.append(node.v);
        in(node.right, res);
    }

    public StringBuilder pre()
    {
        StringBuilder res = new StringBuilder();
        pre(root, res);
        return res;
    }

    public StringBuilder post()
    {
        StringBuilder res = new StringBuilder();
        post(root, res);
        return res;
    }

    public StringBuilder in()
    {
        StringBuilder res = new StringBuilder();
        in(root, res);
        return res;
    }
}

class Trie
{
    private TrieNode root= new TrieNode();

    public void add(String str)
    {

        TrieNode cur = root;

        for (char ch:str.toCharArray())
        {
            int index = ch - 'a';

            if (cur.children[index] == null)
                cur.children[index] = new TrieNode();

            ++cur.children[index].count;
            cur = cur.children[index];
        }

        cur.isEndOfWord = true;
    }

    public boolean find(String str)
    {

		TrieNode cur = root;
        for (char ch:str.toCharArray())
            if (cur.children[ch - 'a'] == null)
                return false;
            else
                cur = cur.children[ch - 'a'];

        return cur != null && cur.isEndOfWord;
    }

	public boolean diff(String str)
	{
		return diff(root, str, 0, 0);
	}

	private boolean diff(TrieNode root, String str, int index, int diff)
	{
		if (diff > 1)
			return false;

		if (index == str.length())
			return diff == 1 && root.isEndOfWord;

		for (int i=0;i < 3;++i)
		{
			if (root.children[i] != null)
			{
				int c = 0;
				if (str.charAt(index) != i + 'a')
					c = 1;
				boolean res = diff(root.children[i], str, index + 1, diff + c);

				if (res)
					return true;
			}
		}
		return false;

	}

    private class TrieNode
    {
        private TrieNode children[] = new TrieNode[3];
        private boolean isEndOfWord;
        private int count;
    }
}


class AVLTree
{
	private class Node
	{
		private Node left,right;
		private int height,val;

		private Node(int val)
		{
			this.val = val;
		}

		private Node()
		{}
	}

	public static int balanceFactor(Node root)
	{
		int left = -1;
		int right = -1;

		if (root.left != null)
			left = root.left.height;

		if (root.right != null)
			right = root.right.height;

		return (left - right);

	}

	private Node rotateRight(Node x)
	{
		Node y = x.left;
		x.left = y.right;
		y.right = x;

		x.height = heightMax(x) + 1;
		y.height = heightMax(y) + 1;

		return y;
	}

	public Node rotateLeft(Node x)
	{
		Node y = x.right;
		x.right = y.left;
		y.left = x;

		x.height = heightMax(x) + 1;
		y.height = heightMax(y) + 1;
		return y;

	}

	private int heightMax(Node root)
	{
		int maxHeight = -1;

		if (root.left != null)
			maxHeight = Math.max(maxHeight, root.left.height);

		if (root.right != null)
			maxHeight = Math.max(maxHeight, root.right.height);

		return maxHeight;
	}

	public Node insert(Node root, int val)
	{
		if (root == null)
		{
			Node node = new Node();
			node.val = val;
			node.left = node.right = null;
			node.height = 0;
			return node;
		}

		if (val < root.val)
			root.left = insert(root.left, val);
		else
			root.right = insert(root.right, val);

		int balanceFactor = balanceFactor(root);

		if (balanceFactor < -1)
		{
			if (balanceFactor(root.right) > 0)
			{
				root.right = rotateRight(root.right);
				return rotateLeft(root);
			}
			else
				return rotateLeft(root);
		}
		else
		{
			if (balanceFactor > 1)
			{
				if (balanceFactor(root.left) < 0)
				{
					root.left = rotateLeft(root.left);
					return rotateRight(root);
				}
				else
					return rotateRight(root);
			}
		}

		root.height = heightMax(root) + 1;

		return root;
	}

}
