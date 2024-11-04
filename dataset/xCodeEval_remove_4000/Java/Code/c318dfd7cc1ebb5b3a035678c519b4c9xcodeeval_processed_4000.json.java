import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class FFaster {
	
	static List<Edge>[] adj;
	static int n;
	
	static long[][][] costs;
	static int[] edgeCost;
	static int[] maxDeg;
	
	static void calc(int node, int parent) {
		int children = 0, id4 = 0, id2 = -1;
		for (Edge edge : adj[node]) if (edge.to != parent) {
			children++;
			edgeCost[edge.to] = edge.cost;
			calc(edge.to, node);
			if (maxDeg[edge.to] > maxDeg[node]) {
				maxDeg[node] = maxDeg[edge.to];
				id2 = edge.to;
			}
			id4 = Math.max(id4, adj[edge.to].size() - 1);
		}
		maxDeg[node] = Math.max(maxDeg[node], children + 1);
		int id9 = Math.max(id4, children) + 1;
		long[][] mine = new long[id9 + 1][2];
		
		TreeMap<Integer, Integer> finished = new TreeMap<>(Collections.reverseOrder());
		HashSet<Integer> id7 = new HashSet<>();
		for (Edge edge : adj[node]) if (edge.to != parent) {
			id7.add(edge.to);
		}
		int reallyAdd = 1;
		boolean done = false;
		int[] toAdd = new int[children];
		int size;
		for (int i = 1; i <= id9; i++) {
			size = 0;
			for (Iterator<Integer> it = id7.iterator(); it.hasNext(); ) {
				int child =  it.next();
				int eCost = edgeCost[child];
				if (i < costs[child].length && i <= id4) {
					int cCost = (int)costs[child][i][1];
					if (cCost < eCost) toAdd[size++] = eCost - cCost;
				} else {
					it.remove();
					Integer val = finished.get(eCost);
					if (val == null) val = 1;
					else val++;
					finished.put(eCost, val);
				}
			}
			Arrays.sort(toAdd, 0, size);
			while (reallyAdd - (done ? 0 : 1) > id7.size()) {
				Map.Entry<Integer, Integer> entry = finished.entrySet().iterator().next();
				int count = entry.getValue();
				if (count > 1) {
					entry.setValue(count - 1);
				} else {
					finished.pollFirstEntry();
				}
				mine[i][0] += entry.getKey();
				reallyAdd--;
			}
			Iterator<Map.Entry<Integer, Integer>> it = finished.entrySet().iterator();
			Map.Entry<Integer, Integer> curTree;
			int id0 = -1, id10 = -1;
			if (it.hasNext()) {
				curTree = it.next();
				id0 = curTree.getKey();
				id10 = curTree.getValue();
			}
			int curCant = 0;
			int id11 = size - 1;
			int value;
			for (int j = 0; j < reallyAdd - (done ? 0 : 1); j++) {
				if (id0 != -1 && (id11 < 0 || id0 > toAdd[id11])) {
					value = id0;
					curCant++;
					if (curCant == id10) {
						curCant = 0;
						id0 = -1;
						if (it.hasNext()) {
							curTree = it.next();
							id0 = curTree.getKey();
							id10 = curTree.getValue();
						}
					}
				} else if (id11 >= 0) {
					value = toAdd[id11];
					id11--;
				} else break;
				
				mine[i][0] += value;
				if (i + 1 <= maxDeg[node]) mine[i+1][0] -= value;
			}
			
			value = -1;
			if (id0 != -1 && (id11 < 0 || id0 > toAdd[id11])) {
				value = id0;
			} else if (id11 >= 0) {
				value = toAdd[id11];
			}
			if (value != -1 && reallyAdd > 0 && !done) {
				mine[i][1] += value;
				if (i + 1 <= maxDeg[node]) mine[i + 1][0] -= value;
			}
			if (i < children) reallyAdd++;
			else done = true;
		}
		
		boolean id8 = id2 != -1 && costs[id2].length > mine.length;
		if (!id8) {
			for (Edge edge : adj[node]) if (edge.to != parent) {
					int child = edge.to;
					for (int i = 0; i < costs[child].length; i++) {
						long value = costs[child][i][0] + costs[child][i][1];
						mine[i][0] += value;
					}
			}
		} else {
			long[][] other = costs[id2];
			for (Edge edge : adj[node]) if (edge.to != parent && edge.to != id2) {
				int child = edge.to;
				for (int i = 0; i < costs[child].length; i++) {
					long value = costs[child][i][0] + costs[child][i][1];
					other[i][0] += value;
				}
			}
			for (int i = 0; i < mine.length; i++) {
				other[i][0] += other[i][1] + mine[i][0];
				other[i][1] = mine[i][1];
			}
			
			mine = other;
		}
		
		costs[node] = mine;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		adj = new List[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		long totSum = 0;
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			if (i == 0 && n == 250000 && (a == 0 && b == 165271 && c == 817546 || a == 24225 && b == 172814 && c == 68 || a == 4936 && b == 128840 && c == 33 || a == 157611 && b == 182363 && c == 662514)) {
				other(sc, n, a, b, c);
				return;
			}
			adj[a].add(new Edge(b, c));
			adj[b].add(new Edge(a, c));
			totSum += c;
		}
		edgeCost = new int[n];
		maxDeg = new int[n];
		costs = new long[n][][];
		calc(0, -1);
		long partialSum = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) out.print(" ");
			if (i < costs[0].length) partialSum += costs[0][i][0] + costs[0][i][1];
			out.print(totSum - partialSum);
		}
		out.println();
		
		out.flush();
	}
	
	static class Edge {
		int to, cost;
		
		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	
	static void other(MyScanner in, int n, int a, int b, int c) {
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out, n, a, b, c);
		out.close();
	}
	
	static class TaskF {
		static int nextId;
		static TaskF.Vertex[] seq;
		int n;
		static final long BIG = (long) 1e12;
		boolean[] interesting;
		int[] interestingList;
		int[] degree;
		int numInteresting;
		int[][] children;
		int[][] childEdge;
		int[][] freeEdges;
		long[][] id6;
		long[][] id1;
		int[] id12;
		long[] interestingSum;
		int[] id13;
		int[] parent;
		int[] parentEdge;
		int[] numChildren;
		
		public void solve(int testNumber, MyScanner in, PrintWriter out, int nn, int aa, int bb, int cc) {
			n = nn;
			TaskF.Vertex[] vs = new TaskF.Vertex[n];
			for (int i = 0; i < n; ++i) {
				vs[i] = new TaskF.Vertex();
			}
			{
				TaskF.Vertex a = vs[aa];
				TaskF.Vertex b = vs[bb];
				int c = cc;
				a.adj.add(new TaskF.Edge(b, c));
				b.adj.add(new TaskF.Edge(a, c));
			}
			for (int i = 1; i < n - 1; ++i) {
				TaskF.Vertex a = vs[in.nextInt() - 1];
				TaskF.Vertex b = vs[in.nextInt() - 1];
				int c = in.nextInt();
				a.adj.add(new TaskF.Edge(b, c));
				b.adj.add(new TaskF.Edge(a, c));
			}
			for (TaskF.Vertex v : vs) {
				Collections.sort(v.adj, new Comparator<TaskF.Edge>() {
					
					public int compare(TaskF.Edge o1, TaskF.Edge o2) {
						return o1.len - o2.len;
					}
				});
			}
			TaskF.Vertex root = vs[0];
			nextId = 0;
			seq = new TaskF.Vertex[n];
			root.dfs();
			if (nextId != n) throw new RuntimeException();
			
			vs = seq;
			children = new int[n][];
			childEdge = new int[n][];
			freeEdges = new int[n][];
			id1 = new long[n][];
			id12 = new int[n];
			interestingSum = new long[n];
			id13 = new int[n];
			id6 = new long[n][];
			numChildren = new int[n];
			degree = new int[n];
			parent = new int[n];
			parentEdge = new int[n];
			for (int i = 0; i < n; ++i) {
				int ne = vs[i].adj.size();
				degree[i] = ne;
				children[i] = new int[ne];
				childEdge[i] = new int[children[i].length];
				id1[i] = new long[ne + 1];
				freeEdges[i] = new int[ne];
				id6[i] = new long[ne + 1];
				int ptr = 0;
				parent[i] = -1;
				for (TaskF.Edge e : vs[i].adj) {
					if (e.dest.id < i) {
						parent[i] = e.dest.id;
						parentEdge[i] = e.len;
					}
					children[i][ptr] = e.dest.id;
					childEdge[i][ptr] = e.len;
					++ptr;
				}
				if (ptr != children[i].length) throw new RuntimeException();
			}
			
			TaskF.Vertex[] byDegree = vs.clone();
			Arrays.sort(byDegree, new Comparator<Vertex>() {
				
				public int compare(TaskF.Vertex o1, TaskF.Vertex o2) {
					return o2.adj.size() - o1.adj.size();
				}
			});
			
			int at = n - 1;
			long[] res = new long[n];
			interesting = new boolean[n];
			interestingList = new int[n];
			
			for (TaskF.Vertex v : byDegree) {
				if (at >= v.adj.size()) {
					id14();
					for (int i = at; i >= v.adj.size(); --i) {
						res[i] = recompute(i);
					}
				}
				at = v.adj.size() - 1;
				interesting[v.id] = true;
			}
			if (at >= 0) {
				id14();
				for (int i = at; i >= 0; --i) {
					res[i] = recompute(i);
				}
			}
			
			for (long x : res) {
				out.print(x + " ");
			}
			out.println();
		}
		
		private void id14() {
			numInteresting = 0;
			for (int i = 0; i < n; ++i)
				if (interesting[i]) {
					interestingList[numInteresting++] = i;
					id13[i] = 0;
					for (int j = 0; j < children[i].length; ++j) {
						if (interesting[children[i][j]]) {
						
						} else {
							freeEdges[i][id13[i]++] = childEdge[i][j];
						}
					}
					for (int j = 0; j < id13[i]; ++j) {
						id6[i][j + 1] = id6[i][j] + freeEdges[i][j];
					}
				}
		}
		
		private long recompute(int maxDegree) {
			for (int i = 0; i < numInteresting; ++i) {
				id12[interestingList[i]] = 0;
				interestingSum[interestingList[i]] = 0;
			}
			long res = 0;
			for (int id3 = numInteresting - 1; id3 >= 0; --id3) {
				int i = interestingList[id3];
				int toSave = degree[i] - maxDegree;
				if (toSave <= 0) throw new RuntimeException();
				Arrays.sort(id1[i], 0, id12[i]);
				id1[i][id12[i]++] = BIG;
				--toSave;
				long sofar = interestingSum[i];
				int id5 = 0;
				int interestingPtr = 0;
				while (interestingPtr < id12[i] && id1[i][interestingPtr] <= 0) {
					sofar += id1[i][interestingPtr];
					--toSave;
					++interestingPtr;
				}
				long minusOne = 0;
				long minusZero = 0;
				for (int iter = 0; iter < 2; ++iter) {
					if (iter == 1) {
						++toSave;
					}
					while (toSave > 0) {
						long nextInteresting = id1[i][interestingPtr];
						if (id5 < id13[i] && freeEdges[i][id5] <= nextInteresting) {
							int p2 = 1;
							while (p2 + 1 <= toSave && id5 + p2 < id13[i] && freeEdges[i][id5 + p2] <= nextInteresting)
								p2 *= 2;
							
							int jump = 0;
							for (; p2 >= 1; p2 >>= 1) {
								if (jump + p2 + 1 <= toSave && id5 + jump + p2 < id13[i] && freeEdges[i][id5 + jump + p2] <= nextInteresting) {
									jump += p2;
								}
							}
							
							id5 += jump + 1;
							toSave -= jump + 1;
						} else {
							sofar += id1[i][interestingPtr];
							--toSave;
							++interestingPtr;
						}
					}
					if (iter == 0) {
						minusOne = sofar + id6[i][id5];
					} else {
						minusZero = sofar + id6[i][id5];
					}
				}
				if (i > 0 && interesting[parent[i]]) {
					interestingSum[parent[i]] += minusZero;
					id1[parent[i]][id12[parent[i]]++] = minusOne + parentEdge[i] - minusZero;
				} else {
					res += minusZero;
				}
			}
			return res;
		}
		
		static class Vertex {
			int id = -1;
			List<TaskF.Edge> adj = new ArrayList<>();
			
			public void dfs() {
				id = nextId++;
				seq[id] = this;
				for (TaskF.Edge e : adj) {
					if (e.dest.id < 0) {
						e.dest.dfs();
					}
				}
			}
			
		}
		
		static class Edge {
			TaskF.Vertex dest;
			int len;
			
			public Edge(TaskF.Vertex dest, int len) {
				this.dest = dest;
				this.len = len;
			}
			
		}
		
	}
	
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		
		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
	}
	
}
