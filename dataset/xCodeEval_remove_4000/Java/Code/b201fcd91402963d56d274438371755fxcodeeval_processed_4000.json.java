import java.util.*;
import java.util.function.*;
import java.io.*;
import java.lang.reflect.Array;



public class id0 {	
	id5 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id11 = "id11";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id8) {
        if (System.getProperty("ONLINE_JUDGE") == null && id8) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id5(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id5(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id0 sol = new id0();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id2 = true;
		
		initIO(id8);
		
		

	
		int t = id2? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int m = in.nextInt();
	    	int q = in.nextInt();
	    	int[][] uv = in.nextPairs(m, -1);
	    	int[] u = uv[0];
	    	int[] v = uv[1];
	    	int[][] lr = in.nextPairs(q, -1);
	    	int[] l = lr[0];
	    	int[] r = lr[1];
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int[] ans = solve(n, u, v, l, r);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		final int n = 1000;
		final int m = 2000;
		final int q = n*(n-1)/2;
		
		Random R = new Random();
		
		while(true) {
			int[] permutation = new int[n];
			for(int i=0; i<n; i++)
				permutation[i] = i;
			for(int i=n-1; i>0; i--) {
				int to = R.nextInt(i+1);
				int temp = permutation[i];
				permutation[i] = permutation[to];
				permutation[to] = temp;
			}
			
			TreeSet<Edge> edges = new TreeSet<Edge>();
			
			DSU dsu = new DSU(n);
			for(int i=0; i<n; i++)
				dsu.put(i);
			
			for(int i=0; i<n-1; i++) {
				int u = R.nextInt(n);
				int v = R.nextInt(n);
				if(u == v || dsu.find(u) == dsu.find(v))
					continue;
				edges.add(new Edge(u, v));
				dsu.union(u, v);
			}
			
			while(edges.size() < m) {
				int u = R.nextInt(n);
				int v = R.nextInt(n);
				if(u == v)
					continue;
				edges.add(new Edge(u, v));
			}
			
			
			Edge[] xy = edges.toArray(new Edge[0]);
			for(int i=m-1; i>0; i--) {
				int to = R.nextInt(i+1);
				Edge temp = xy[i];
				xy[i] = xy[to];
				xy[to] = temp;
			}			
			
			int[] x = new int[m];
			int[] y = new int[m];
			for(int i=0; i<m; i++) {
				x[i] = permutation[xy[i].first];
				y[i] = permutation[xy[i].second];
			}
			
			int[] l = new int[q];
			int[] r = new int[q];
			int index = 0;
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++) {
					l[index] = i;
					r[index] = j;
					index++;
				}
			
			int[] ans = solve(n, x, y, l, r);
			
			System.out.println("solved");
			
			dsu = new DSU(n);
			for(int i=0; i<n; i++)
				dsu.put(i);
	
			int[][] time = new int[n][n];
			for(var arr: time)
				Arrays.fill(arr, m);
			
			for(int i=0; i<n; i++)
				time[i][i] = 0;
			for(int t = 0; t < m; t++) {
				dsu.union(x[t], y[t]);
				for(int u = 0; u < n; u++)
					for(int v = u+1; v < n; v++)
						if(dsu.find(u) == dsu.find(v))
							time[u][v] = Math.min(time[u][v], t+1);
			}
			
			int[] expected = new int[q];
			Arrays.fill(expected, 0);
			for(int i=0; i<q; i++) {
				for(int u=l[i]; u<=r[i]; u++)
					for(int v=u+1; v<=r[i]; v++)
						expected[i] = Math.max(expected[i], time[u][v]);
			}
			
			
			if(!Arrays.equals(ans, expected)) {
				System.out.println(Arrays.toString(expected));
				System.out.println(Arrays.toString(ans));
				System.out.println();
				System.out.println(String.format("%d %d %d", n, m, q));
				for(int i=0; i<m; i++)
					System.out.println(String.format("%d %d", x[i]+1, y[i]+1));
				for(int i=0; i<q; i++)
					System.out.println(String.format("%d %d", l[i]+1, r[i]+1));
				solve(n, x, y, l, r);
				break;
			}
			else {
				System.out.println("correct");
			}
		}
	}
	
	class Edge implements Comparable<Edge>{
		int first, second;

		public Edge(int first, int second) {
			this.first = Math.min(first, second);
			this.second = Math.max(first, second);
		}

		@Override
		public int compareTo(id0.Edge o) {
			int cmp = Integer.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
		}
		public String toString() {
			return String.format("[%d %d]", first, second);
		}
	}

	private int[] solve(int n, int[] u, int[] v, int[] l, int[] r) {
		int m = u.length;
		int q = l.length;
		
		

		

		

		
		

		

		

		

		

		
		

		

		


		

		

		

		
		Integer[] queryIndex = new Integer[q];
		for(int i=0; i<q; i++)
			queryIndex[i] = i;
		Arrays.sort(queryIndex, new Comparator<Integer>() {
			@Override
			public int compare(Integer i, Integer j) {
				return Integer.compare(l[i], l[j]);
			}
		});
		
		

		
		

		

		

		


		

		

		
		

		

		
		Interval[] intervals = new Interval[n];
		
		for(int i=0; i<n; i++) {
			intervals[i] = new Interval(i, i, 0);
			intervals[i].vertices.add(i);
		}
		
		ArrayList<rInterval>[] id17 = new ArrayList[n];
		for(int i=0; i<n; i++) {
			id17[i] = new ArrayList<rInterval>();
			id17[i].add(new rInterval(i, 0));
		}
		
		DSU dsu = new DSU(n);
		for(int i=0; i<n; i++)
			dsu.put(i);
		
		dsu = dsu;
		
		for(int i=0; i<m; i++) {
			var a = dsu.union(u[i], v[i]);
			
			if(a == null)
				continue;






			

















			a.sort(null);
			
			for(int vertex: a) {
				Interval interval = intervals[vertex];
				if(interval.l > 0) {
					int vertex2 = interval.l-1;
					if(dsu.find(vertex) == dsu.find(vertex2)) {
						mergeInterval(interval, intervals[vertex2], intervals);
						interval = intervals[vertex];
						

						id17[interval.l].add(new rInterval(interval.r, i+1));
					}	
				}
				if(interval.r < n-1) {
					int vertex2 = interval.r+1;
					if(dsu.find(vertex) == dsu.find(vertex2)) {
						mergeInterval(interval, intervals[vertex2], intervals);
						interval = intervals[vertex];
						id17[interval.l].add(new rInterval(interval.r, i+1));
					}
				}
			}
		}
		
		int[] ans = new int[q];
		Integer[] identity = new Integer[n];
		Arrays.fill(identity, m);
		SegmentTree<Integer> id15 = new SegmentTree<Integer>((x, y) -> Math.min(x, y), identity);
		int from = 0;
		for(int left = 0; left < n; left++){
			for(rInterval rt: id17[left]) {
				id15.update(rt.r, rt.time);
			}
			while(from < q) {
				if(l[queryIndex[from]] > left)
					break;
				

				int to = from+1;
				while(to < q && l[queryIndex[to]] == left) {
					to++;
				}
				for(int i=from; i<to; i++) {
					int time = id15.getRange(r[queryIndex[i]], n-1);
					ans[queryIndex[i]] = time;
				}
				from = to;
			}
		}
		
		return ans;
	}
	
	private void mergeInterval(id0.Interval interval, id0.Interval interval2, Interval[] intervals) {
		if(interval.vertices.size() > interval2.vertices.size()) {
			var temp = interval;
			interval = interval2;
			interval2 = temp;
		}
		

		

		for(int vertex: interval.vertices) {
			intervals[vertex] = interval2;
		}
		interval2.vertices.addAll(interval.vertices);
		interval2.l = Math.min(interval.l, interval2.l);
		interval2.r = Math.max(interval.r, interval2.r);
	}

	static class rInterval{
		int r, time;

		public rInterval(int r, int time) {
			this.r = r;
			this.time = time;
		}
		public String toString() {
			return String.format("(r=%d, time=%d)", r, time);
		}
	}
	static class Interval{
		int l, r, time;
		ArrayList<Integer> vertices;

		public Interval(int l, int r, int time) {
			this.l = l;
			this.r = r;
			this.time = time;
			this.vertices = new ArrayList<Integer>();
		}
		public String toString() {
			return String.format("[%d, %d] @ %d", l, r, time);
		}
	}
	
	class SegmentTree<T> {
		BiFunction<T, T, T> function;
		

		int n;
		T[] tree;
		

		public SegmentTree(BiFunction<T, T, T> function, T[] arr){	
			this.function = function;
			

			this.n = arr.length;



			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			
			tree = (T[]) Array.newInstance(arr[0].getClass(), m);
			


			

			build(arr, 1, 0, n-1);

			

			

			

		}

		private void build(T[] arr, int treeIdx, int left, int right) {
			if(left == right) {
				tree[treeIdx] = arr[left];
				return;
			}

			int mid = (left+right)>>1;
			

			

			int id4 = treeIdx<<1;
			int id14 = (treeIdx<<1)+1;
			build(arr, id4, left, mid);
			build(arr, id14, mid+1, right);
			tree[treeIdx] = function.apply(tree[id4], tree[id14]);
		}

		public void update(int idx, T val){
			update(idx+1, val, 1, 1, n);
			

		}

		private T update(int idx, T val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];

			

			if(left == right){
				

				tree[treeIdx] = function.apply(val, tree[treeIdx]);
				return val;
			}

			

			int mid = (left+right)>>1;
			T val1 = update(idx, val, treeIdx<<1, left, mid);
			T val2 = update(idx, val, (treeIdx<<1) + 1, mid+1, right);
			val = function.apply(val1, val2);
			tree[treeIdx] = val;
			return val;
		}

		public T getRange(int start, int end){
			return getRange(start, end, 1, 0, n-1);
			

		}

		private T getRange(int start, int end, int treeIdx, int left, int right) {
			


			


			if(start == left && end == right)
				return tree[treeIdx];

			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				T val1 = getRange(start, mid, treeIdx<<1, left, mid);
				T val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, (treeIdx<<1)+1, mid+1, right);
		}
	}
	
	static class DSU {
		int[] size;
		int[] parent;
		ArrayList<Integer>[] children;
		
		public DSU(int max) {
			parent = new int[max];
			size = new int[max];
			children = new ArrayList[max];
		}
		
		public void put(int v) {
			parent[v] = -1;
			size[v] = 1;
			children[v] = new ArrayList<Integer>();
		}


































		
		

		public ArrayList<Integer> union(int v, int u) {
			int head1 = find(v);
			int head2 = find(u);
			if(head1 == head2)
				return null;
			int smaller, larger;
			if(size[head1] > size[head2]) {
				smaller = head2;
				larger = head1;
			}
			else {
				smaller = head1;
				larger = head2;
			}
			parent[smaller] = larger;
			size[larger] += size[smaller];
			children[smaller].add(smaller);
			children[larger].addAll(children[smaller]);
			return children[smaller];
		}
		public int find(int v) {
			if(parent[v] == -1)
				return v;
			int head = find(parent[v]);


			return head;
		}
	}
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		

		public MyScanner(InputStream is, int bufferSize) {
			br = new BufferedReader(new InputStreamReader(is), bufferSize);
		}
		
		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			

			

		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
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

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
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
		
		int[][] id6(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
		}
		
		int[][] nextMatrix(int n, int m) {
			return nextMatrix(n, m, 0);
		}
		
		int[][] nextMatrix(int n, int m, int offset) {
			int[][] mat = new int[n][m];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[i][j] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[][] nextPairs(int n){
			return nextPairs(n, 0);
		}
		
		int[][] nextPairs(int n, int offset) {
			int[][] xy = new int[2][n];
			for(int i=0; i<n; i++) {
				xy[0][i] = nextInt() + offset;
				xy[1][i] = nextInt() + offset;
			}
			return xy;
		}

		int[][] id10(){
			return id10(0);
		}
		
		int[][] id10(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id7(int len) {
			return id7(len, 0);
		}
		int[] id7(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id18(int len) {
			return id18(len, 0);
		}
		long[] id18(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
	}
	
	public static class id5 extends PrintWriter{
		public id5(OutputStream os) {
			super(os);
		}
		
		public void printlnAns(long ans) {
			println(ans);
		}
		
		public void printlnAns(int ans) {
			println(ans);
		}
		
		public void printlnAns(boolean ans) {
			if(ans)
				println(YES);
			else
				println(NO);
		}
		
		public void printAns(long[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(long[] arr){
			printAns(arr);
			println();
		}

		public void printAns(int[] arr){
			if(arr != null && arr.length > 0){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(int[] arr){
			printAns(arr);
			println();
		}
		
		public <T> void printAns(ArrayList<T> arr){
			if(arr != null && arr.size() > 0){
				print(arr.get(0));
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i));
				}
			}
		}
		public <T> void printlnAns(ArrayList<T> arr){
			printAns(arr);
			println();
		}
		
		public void printAns(int[] arr, int add){
			if(arr != null && arr.length > 0){
				print(arr[0]+add);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]+add);
				}
			}
		}
		public void printlnAns(int[] arr, int add){
			printAns(arr, add);
			println();
		}
		
		public void printAns(ArrayList<Integer> arr, int add) {
			if(arr != null && arr.size() > 0){
				print(arr.get(0)+add);
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i)+add);
				}
			}			
		}
		
		public void printlnAns(ArrayList<Integer> arr, int add){
			printAns(arr, add);
			println();
		}
		
		public void id1(long[] arr, int split){
			if(arr != null){
				for(int i=0; i<arr.length; i+=split){
					print(arr[i]);
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}
		
		public void id1(int[] arr, int split){
			if(arr != null){
				for(int i=0; i<arr.length; i+=split){
					print(arr[i]);
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr[j]);
					}
					println();
				}
			}
		}
		
		public <T> void id1(ArrayList<T> arr, int split){
			if(arr != null && !arr.isEmpty()){
				for(int i=0; i<arr.size(); i+=split){
					print(arr.get(i));
					for(int j=i+1; j<i+split; j++){
						print(" ");
						print(arr.get(j));
					}
					println();
				}
			}
		}
	}
	
	static private void id16(long[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for(int i=0; i<n; i++) {
			int t = R.nextInt(n-i);
			long temp = a[n-1-i];
			a[n-1-i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);		
	}
	
	static private void id16(int[] a) {
		int n = a.length;
		Random R = new Random(System.currentTimeMillis());
		for(int i=0; i<n; i++) {
			int t = R.nextInt(n-i);
			int temp = a[n-1-i];
			a[n-1-i] = a[t];
			a[t] = temp;
		}
		Arrays.sort(a);
	}
	
	static private int[][] constructChildren(int n, int[] parent, int parentRoot){
		int[][] childrens = new int[n][];
		
		int[] numChildren = new int[n];
		for(int i=0; i<parent.length; i++) {
			if(parent[i] != parentRoot)
				numChildren[parent[i]]++;
		}
		
		for(int i=0; i<n; i++) {
			childrens[i] = new int[numChildren[i]];
		}
		

		int[] idx = new int[n];
		for(int i=0; i<parent.length; i++) {
			if(parent[i] != parentRoot)
				childrens[parent[i]][idx[parent[i]]++] = i;
		}

		return childrens;
	}
	
	static private int[][][] id13(int n, int[][] e){
		int[] inDegree = new int[n];
		int[] outDegree = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outDegree[u]++;
			inDegree[v]++;
		}
		
		int[][] inNeighbors = new int[n][];
		int[][] outNeighbors = new int[n][];
		for(int i=0; i<n; i++) {
			inNeighbors[i] = new int[inDegree[i]];
			outNeighbors[i] = new int[outDegree[i]];
		}
		
		int[] inIdx = new int[n];
		int[] outIdx = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][outIdx[u]++] = v;
			inNeighbors[v][inIdx[v]++] = u;
		}
		
		return new int[][][] {inNeighbors, outNeighbors};
	}
	
	static private int[][] constructNeighborhood(int n, int[][] e) {
		int[] degree = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			degree[u]++;
			degree[v]++;
		}
		
		int[][] neighbors = new int[n][];
		for(int i=0; i<n; i++)
			neighbors[i] = new int[degree[i]];
		
		int[] idx = new int[n];
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][idx[u]++] = v;
			neighbors[v][idx[v]++] = u;
		}
		
		return neighbors;
	}
	
	static private void drawGraph(int[][] e) {
		id12(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id12(int[][] e) {
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict graph {");
		for(int i=0; i<e.length; i++){
			out2.println(e[i][0] + "--" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}
	
	static private void id3(int[][] e) {
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
		} catch (FileNotFoundException e1) {
			

			e1.printStackTrace();
		}
		out2.println("strict digraph {");
		for(int i=0; i<e.length; i++){
			out2.println(e[i][0] + "->" + e[i][1] + ";");
		}
		out2.println("}");
		out2.close();
	}
	
}
