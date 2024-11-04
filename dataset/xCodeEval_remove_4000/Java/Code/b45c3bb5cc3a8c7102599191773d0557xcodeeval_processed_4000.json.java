import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
 
public class Solution {
	

static class Graph {
	ArrayList<ArrayList<Integer>> id12;
	boolean[]visited;
	public Graph() {}
	int n;
	public Graph(int n) {
		this.n = n;


		visited = new boolean[n+1];
		id12 = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<=n; i++)id12.add(new ArrayList<Integer>());
	}
	public void id24(int m) {
		for(int i=0; i<m; i++) {
			int u = s.nextInt();
			int v = s.nextInt();
			id12.get(u).add(v);
			id12.get(v).add(u);
		}
	}
	public void print_graph() {
		for(int i=1; i<=n; i++) {
			System.out.print("Edge from " + i + " to --->  ");
			for(Integer x : id12.get(i)) {
				System.out.print(x + " ");
			}System.out.println();
		}
	}
	public void dfs(int u) {
		visited[u] = true;
		for(Integer v : id12.get(u)) {
			if(!visited[v]) {
				dfs(v);
			}
		}
	}
	public void bfs(int u) {
		Queue<Integer> q = new ArrayDeque<Integer>();
		visited[u] = true;
		q.add(u);
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(Integer x : id12.get(cur)) {
				if(!visited[x]) {
					visited[x] = true;
					q.add(x);
				}
			}
		}
	}
	void id5(int u, ArrayList<Integer> id16) {
		visited[u] = true;
		for(Integer x : id12.get(u)) {
			if(!visited[x]) {
				id5(x, id16);
			}
		}
		id16.add(u);
	}
	public ArrayList<Integer>id16(int u) {
			ArrayList<Integer> id16 = new ArrayList<Integer>();
			for(int i=1; i<=n; i++) {
				if(!visited[i]) {
					id5(i, id16);
				}
			}
			return id16;
	}
	public void id2(int u, int[]distance) {
		Queue<Integer> q = new ArrayDeque<Integer>();
		visited[u] = true;
		q.add(u);
		distance[u] = 0;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(Integer x : id12.get(cur)) {
				if(!visited[x]) {
					visited[x] = true;
					q.add(x);
					distance[x] = distance[cur] + 1;
				}
			}
		}
	}
	public int[] id28(int u) {
		int[]res = new int[n];
		this.id2(u, res);
		return res;
	}
	public boolean id19() {
		boolean[]id10 = new boolean[n+1];
		Arrays.fill(visited, false);
		for(int i=1; i<=n; i++) {
			if(id25(i, id10)) {
				return true;
			}
		}
		return false;
	}
	private boolean id25(int i, boolean[] id10) {
		if(id10[i])return true;
		if(visited[i])return false;
		visited[i] = id10[i] = true;
		for(Integer x : id12.get(i)) {
			if(id25(x, id10))return true;
		}
		return false;
	}
	public ArrayList<ArrayList<Integer>> id18(){
		ArrayList<ArrayList<Integer>> transposeGraph = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<=n; i++)transposeGraph.add(new ArrayList<Integer>());
		for(int i=0; i<=n; i++) {
			for(Integer x : id12.get(i)) {
				transposeGraph.get(x).add(i);
			}
		}
		return transposeGraph;
	}
	public int[] id4() {
		ArrayList<ArrayList<Integer>> transposeGraph = this.id18();
		Stack<Integer> stack = new Stack<Integer>();
		int[]id20 = new int[n+1];
		for(int i=1; i<=n; i++) {
			if(!visited[i]) {
				id27(i, stack);
			}
		}
		Arrays.fill(visited, false);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			if(!visited[u]) {
				id22(u, transposeGraph, id20, u);
			}
		}
		return id20;
	}
	private void id22(int u, ArrayList<ArrayList<Integer>> transposeGraph, int[] id20, int representative) {
		visited[u] = true;
		id20[u] = representative;
		for(Integer x : transposeGraph.get(u)) {
			if(!visited[x]) {
				id22(x, transposeGraph, id20, representative);
			}
		}
	}
	private void id27(int u, Stack<Integer> stack) {
		visited[u] = true;
		for(Integer x : id12.get(u)) {
			if(!visited[x]) {
				id27(x, stack);
			}
		}
		stack.push(u);
	}
	
}

static class id32 extends Graph{
	final long id0 = (long)(1e18);
	static class Pair{
		int vertex;
		long distance;
		public Pair() {}
		public Pair(int vertex, long distance) {
			this.vertex = vertex;
			this.distance = distance;
		}
	}
	static class Edge implements Comparable<Edge>{
		int source, destination;
		long weight;
		public Edge() {}
		public Edge(int source, int destination, long weight) {
			this.source = source;
			this.destination = destination;
			this.weight = weight;
		}
		@Override
		public int compareTo(Edge o) {
			return -Long.compare(weight, o.weight);
		}
	}
	
	public id32(int n) {
		super(n);
	}
	public long id21(ArrayList<ArrayList<Pair>> adj, int start) {
		ArrayList<ArrayList<Pair>> mst = new ArrayList<>();
		long[]distance = new long[super.n+1];
		int[]parent = new int[super.n+1];
		Arrays.fill(distance, id0);
		Arrays.fill(parent, -1);
		distance[start] = 0;
		parent[0] = 0; distance[0] = 0;
		parent[start] = start;
		PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return Long.compare(o1.distance, o2.distance);
			}
		});
		for(int i=1; i<=n; i++) {		
			pq.add(new Pair(i, distance[i]));
		}
		visited[0] = true;
		Arrays.fill(visited, false);
		
		while(!pq.isEmpty()) {	
			Pair cur = pq.poll();


			visited[cur.vertex] = true;
			for(Pair p : adj.get(cur.vertex)) {
				if(!visited[p.vertex]) {




					if(p.distance < distance[p.vertex]) {
						Pair curPair = new Pair(p.vertex, distance[p.vertex]);
						curPair.distance = distance[p.vertex] = p.distance;
						pq.add(curPair);
						parent[p.vertex] = cur.vertex;
					}
				}
			}
		}
		for(int i=0; i<=n; i++)mst.add(new ArrayList<id32.Pair>());
		long totalDistance = 0;




		for(int i=1; i<=n; i++) {
			if(parent[i] != i) {
				mst.get(i).add(new Pair(parent[i], distance[i]));
				mst.get(parent[i]).add(new Pair(i, distance[i]));
				totalDistance += distance[i];
			}
		}
		return totalDistance;
	}
	
	public ArrayList<ArrayList<Pair>> Prims(ArrayList<ArrayList<Pair>> adj, int start){

		ArrayList<ArrayList<Pair>> mst = new ArrayList<>();
		long[]distance = new long[super.n+1];
		int[]parent = new int[super.n+1];
		Arrays.fill(distance, id0);
		Arrays.fill(parent, -1);
		distance[start] = 0;
		parent[0] = 0; distance[0] = 0;
		parent[start] = start;
		PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return Long.compare(o1.distance, o2.distance);
			}
		});
		for(int i=1; i<=n; i++) {		
			pq.add(new Pair(i, distance[i]));
		}
		visited[0] = true;
		Arrays.fill(visited, false);
		
		while(!pq.isEmpty()) {	
			Pair cur = pq.poll();


			visited[cur.vertex] = true;
			for(Pair p : adj.get(cur.vertex)) {
				if(!visited[p.vertex]) {




					if(p.distance < distance[p.vertex]) {
						Pair curPair = new Pair(p.vertex, distance[p.vertex]);
						curPair.distance = distance[p.vertex] = p.distance;
						pq.add(curPair);
						parent[p.vertex] = cur.vertex;
					}
				}
			}
		}
		for(int i=0; i<=n; i++)mst.add(new ArrayList<id32.Pair>());
		for(int i=1; i<=n; i++) {
			if(parent[i] != i) {
				mst.get(i).add(new Pair(parent[i], distance[i]));
				mst.get(parent[i]).add(new Pair(i, distance[i]));
			}
		}
		return mst;
	
	}

	public Edge[] id13(Edge[]edges, int start) {
		Edge[] result = new Edge[n];
		Arrays.parallelSort(edges);
		id30 ds = new id30(n);
		ds.init();
		int id14 = 0, index = 0;
		while(id14 < n - 1) {
			Edge currentEdge = edges[index++];
			int id9 = ds.id11(currentEdge.source);
			int id1 = ds.id11(currentEdge.destination);
			if(id9 != id1) {
				result[id14++] = currentEdge;
				ds.id23(id9, id1);
			}
		}
		return result;
	}
	
	public long id29(Edge[]edges, int start) {
		Edge[] result = new Edge[n];
		long totalDistance = 0;
		Arrays.parallelSort(edges);
		id30 ds = new id30(n);
		ds.init();
		int id14 = 0, index = 0;
		while(id14 < n - 1 && index < edges.length) {
			Edge currentEdge = edges[index++];
			int id9 = ds.id11(currentEdge.source);
			int id1 = ds.id11(currentEdge.destination);
			if(id9 != id1) {
				result[id14++] = currentEdge;
				totalDistance += currentEdge.weight;
				ds.id23(id9, id1);
			}
		}
		return totalDistance;
	}
}

static class id30 {
	int[]parent;
	int[]rank;
	int n;
	public id30(int n) {
		parent = new int[n+1];
		rank = new int[n+1];
		this.n = n;
	}
	public void init() {
		for(int i=0; i<=n; i++)
			parent[i] = i;
	}
	public int id7(int i) {
		if(parent[i] == i) {
			return parent[i];
		}
		return id7(parent[i]);
	}
	public void union(int x, int y) {
		int xRepresentative = this.id7(x);
		int yRepresentative = this.id7(y);
		this.parent[xRepresentative] = yRepresentative;
	}
	

	

		public int id11(int i) {
			if(parent[i] == i) {
				return i;
			}
			return parent[i] = id11(parent[i]);
		}
		public void id23(int x, int y) {
			int xRepresentative = this.id11(x);
			int yRepresentative = this.id11(y);
			if(xRepresentative == yRepresentative)
				return;
			int xRank = rank[x];
			int yRank = rank[y];
			if(xRank < yRank) {
				this.parent[xRepresentative] = yRepresentative;
			}else if(yRank < xRank) {
				this.parent[yRepresentative] = xRepresentative;
			}else {
				this.parent[xRepresentative] = yRepresentative;
				rank[yRepresentative]++;
			}
		}
}

	
public static void main(String[] args){
 
   new Thread(null, null, "Anshum Gupta", 99999999) {
        public void run() {
            try {
                solve();
            } catch(Exception e) {
                e.printStackTrace();
                System.exit(1);
            }
        }
    }.start();
}

static final long mxx = (long)(1e18 + 5);
static final int mxN = (int)(1e6);
static final int mxV = (int)(1e6 + 5), log = 18;
static long mod = (long)(1e9+7);
static final int INF = (int)1e9;
static boolean[]vis;
static ArrayList<ArrayList<Integer>> adj;
static int n, m, k, q, upMoves, rightMoves;
static int[]dp;
static char[]str;

 
public static void solve() throws Exception {
	   

		s = new MyScanner();
   		out = new PrintWriter(new BufferedOutputStream(System.out), true);


        int tc = 1;

        for(int i=1; i<=tc; i++) {


        	testcase();
        }
           
        out.flush();
        out.close();
}


static void testcase() {
	m = s.nextInt();
	n = s.nextInt();
	int[] a = s.id15(m), b = s.id15(n);
	ArrayList<id32.Edge> edges = new ArrayList<>();
	long totalCost = 0;
	for(int i=0; i<m; i++) {
		int size = s.nextInt();
		for(int j=0; j<size; j++) {
			int x = s.nextInt() - 1;
			edges.add(new id32.Edge(n + i + 1, x + 1, a[i] + b[x]));


			totalCost += a[i] + b[x];
		}
	}
	id32 mst = new id32(n + m);
	id32.Edge[] arr = new id32.Edge[edges.size()];
	for(int i=0; i<edges.size(); i++)arr[i] = edges.get(i);
	totalCost -= mst.id29(arr, 1);
	out.println(totalCost);
	
}


public static PrintWriter out;
public static MyScanner s;
static class MyScanner {
 
    BufferedReader br;
    StringTokenizer st;
 
    public MyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    public MyScanner(String fileName) {
    	try {
			br = new BufferedReader(new FileReader(fileName));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    }
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    int nextInt() { return Integer.parseInt(next()); }
    long nextLong() { return Long.parseLong(next()); }
    double nextDouble() { return Double.parseDouble(next()); }
    int[] id15(int n){
    	int[]a = new int[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextInt();
    	}
    	return a;
    }
    long[] id3(int n) {
    	long[]a = new long[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextLong();
    	}
    	return a;
    }
    Integer[] id8(int n){
    	Integer[]a = new Integer[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextInt();
    	}
    	return a;
    }
    Long[] id31(int n) {
    	Long[]a = new Long[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextLong();
    	}
    	return a;
    }
    char[][] id26(int n, int m){
    	char[][]arr = new char[n][m];
    	for(int i=0; i<n; i++) {
    		arr[i] = this.next().toCharArray();
    	}
    	return arr;
    }
    ArrayList<ArrayList<Integer>> id6(int n, int m) {
    	ArrayList<ArrayList<Integer>>adj = new ArrayList<ArrayList<Integer>>();
    	for(int i=0; i<=n; i++)adj.add(new ArrayList<Integer>());
    	for(int i=0; i<m; i++) {
    		int u = s.nextInt();
    		int v = s.nextInt();
    		adj.get(u).add(v);
    		adj.get(v).add(u);
    	}
    	return adj;
    }
    ArrayList<ArrayList<Integer>> id17(int n, int m) {
    	ArrayList<ArrayList<Integer>>adj = new ArrayList<ArrayList<Integer>>();
    	for(int i=0; i<=n; i++)adj.add(new ArrayList<Integer>());
    	for(int i=0; i<m; i++) {
    		int u = s.nextInt();
    		int v = s.nextInt();
    		adj.get(u).add(v);
    	}
    	return adj;
    }
    String nextLine(){
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}
 
 
}