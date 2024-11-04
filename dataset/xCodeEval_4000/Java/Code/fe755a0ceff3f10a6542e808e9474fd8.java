import java.util.*;
import java.util.function.*;
import java.io.*;



public class Round818F {	
	MyPrintWriter out;
	MyScanner in;
	








	final static String IMPOSSIBLE = "IMPOSSIBLE";
	final static String POSSIBLE = "POSSIBLE";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean isFileIO) {
        if (System.getProperty("ONLINE_JUDGE") == null && isFileIO) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new MyPrintWriter(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new MyPrintWriter(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		Round818F sol = new Round818F();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = false;
		
		initIO(isFileIO);
	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	solve();
	    	
	    	printOutput();
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	int n, m;
	int[] s, a, v, u;
	void getInput() {
		n = in.nextInt(); 
		m = in.nextInt();
		s = in.nextIntArray(n);
		a = in.nextIntArray(n);
		int[][] uv = in.nextTransposedMatrix(m, 2, -1);
		v = uv[0];
		u = uv[1];
	}
	
	void printOutput() {
		if(ans == null)
			out.println(NO);
		else {
			out.println(YES);
			for(int i=0; i<m; i++) {
				if(ans[i]) {
					out.print(v[i]+1);
					out.print(' ');
					out.println(u[i]+1);
				}
				else {
					out.print(u[i]+1);
					out.print(' ');
					out.println(v[i]+1);
				}
			}
		}
	}

	boolean[] ans;
	void solve(){
		

		

		

		

		

		

		


		

		

		

		
		int[] base = new int[n];
		for(int i=0; i<m; i++) {
			base[u[i]]--;
			base[v[i]]--;
		}
		
		ans = null;
		int sum = 0;
		
		for(int i=0; i<n; i++) {
			if(s[i] > 0) {
				a[i] -= base[i];
				if(a[i] < 0 || a[i] % 2 != 0)
					return;
				a[i] /= 2;
				sum += a[i];
			}
		}
		
		int restCapacity = m-sum;
		if(restCapacity < 0)
			return;
		
		

		

		

		

		

		

		
		

		

		

		

		

		

		

		

		

		
		

		
		final int restIndex = m+n+1;
		final int MAX = 1_000_000_000;
		
		Dinic dinic = new Dinic(m+n+3);
		for(int i=0; i<m; i++) {
			dinic.add(dinic.source, getProviderIndex(i), 1, 0);
			dinic.add(getProviderIndex(i), getConsumerIndex(u[i]), 1, 0);
			dinic.add(getProviderIndex(i), getConsumerIndex(v[i]), 1, 0);
		}
		for(int i=0; i<n; i++) {
			if(s[i] > 0)
				dinic.add(getConsumerIndex(i), dinic.sink, a[i], 0);
			else
				dinic.add(getConsumerIndex(i), restIndex, MAX, 0);
		}
		dinic.add(restIndex, dinic.sink, restCapacity, 0);
		
		if(dinic.maxFlow() < m)
			return;
		
		ans = new boolean[m];
		

		
		for(int i=0; i<m; i++) {
			if(dinic.network[getProviderIndex(i)].get(1).capacity > 0)
				ans[i] = false;
			else
				ans[i] = true;
		}
		
		

		

		

		

		


	}
	
	int getProviderIndex(int i) {
		return i+1;
	}
	
	int getConsumerIndex(int i) {
		return m+i+1;
	}
	
	static class Dinic{
		static class Edge{
			int vertexIndex;
			int reverseEdgeIndex;
			int capacity;
			

			public Edge(int neighborIndex, int neighborEdgeIndex, int capacity) {
				this.vertexIndex = neighborIndex;
				this.reverseEdgeIndex = neighborEdgeIndex;
				this.capacity = capacity;
				

			}
			@Override
			public String toString() {
				return String.format("(%d %d %d)", vertexIndex, reverseEdgeIndex, capacity);
			}
		}
		
		final int MAX = 1_000_000_000;
		final int size;
		final ArrayList<Edge>[] network;
		final int source, sink;
		
		public Dinic(int size) {
			this.size = size;
			network = new ArrayList[size];
			for(int i=0; i<size; i++)
				network[i] = new ArrayList<Edge>();
			source = 0;
			sink = size-1;
		}
		

		public void add(int i, int j, int capacityItoJ, int capacityJtoI) {
			int sizeI = network[i].size();
			int sizeJ = network[j].size();
			network[i].add(new Edge(j, sizeJ, capacityItoJ));
			network[j].add(new Edge(i, sizeI, capacityJtoI));
		}
		public int maxFlow() {
			level = new int[size];
			done = new int[size];
			int flow = 0;
			while(true) {
				computeLayer();
				if(level[sink] == 0)
					break;
				while(true) {
					Arrays.fill(done, 0);
					int add = dfs(source, MAX);
					flow += add;
					if(add == 0)
						break;
				}
			}
			return flow;
		}
		
		int[] level;
		private void computeLayer() {
			Arrays.fill(level, 0);
			ArrayDeque<Integer> queue = new ArrayDeque<>();
			queue.addLast(source);
			level[source] = 1;
			while(!queue.isEmpty()){
				int vertex = queue.pollFirst();
				for(var edge: network[vertex]) {
					if(level[edge.vertexIndex] == 0 && edge.capacity > 0) {
						level[edge.vertexIndex] = level[vertex] + 1;
						queue.addLast(edge.vertexIndex);
					}
				}
			}
		}
		
		int[] done;
		private int dfs(int vertex, int cap) {
			if(vertex == sink)
				return cap;
			if(cap == 0)
				return 0;
			int totalFlow = 0;
			while(done[vertex] < network[vertex].size()) {
				var edge = network[vertex].get(done[vertex]);
				if(level[edge.vertexIndex] != level[vertex]+1) {
					done[vertex]++;
					continue;
				}
				int flow = dfs(edge.vertexIndex, Math.min(cap, edge.capacity));
				

				edge.capacity -= flow;
				network[edge.vertexIndex].get(edge.reverseEdgeIndex).capacity += flow;
				cap -= flow;
				totalFlow += flow;
				done[vertex]++;
			}
			return totalFlow;
		}
	}
	




	
	static class Pair implements Comparable<Pair>{
		final static long FIXED_RANDOM = System.currentTimeMillis();
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		

		@Override
		public int hashCode() {
			

			long x = first;
			x <<= 32;
			x += second;
			x += FIXED_RANDOM;
			x += 0x9e3779b97f4a7c15l;
			x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
			x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
			return (int)(x ^ (x >> 31));
		}
		@Override
		public boolean equals(Object obj) {












			Pair other = (Pair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}


		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
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
		
		int[][] nextTransposedMatrix(int n, int m){
			return nextTransposedMatrix(n, m, 0);
		}
		
		int[][] nextTransposedMatrix(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] nextIntArray(int len) {
			return nextIntArray(len, 0);
		}
		int[] nextIntArray(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] nextLongArray(int len) {
			return nextLongArray(len, 0);
		}
		long[] nextLongArray(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] nextStringArray(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class MyPrintWriter extends PrintWriter{
		public MyPrintWriter(OutputStream os) {
			super(os);
		}
		












		
		public void printlnAns(OptionalInt ans) {
			println(ans.orElse(-1));
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
		
		public void printlnAnsSplit(long[] arr, int split){
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
		
		public void printlnAnsSplit(int[] arr, int split){
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
		
		public <T> void printlnAnsSplit(ArrayList<T> arr, int split){
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
	
	static private void permutateAndSort(long[] a) {
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
	
	static private void permutateAndSort(int[] a) {
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
	
	static private int[][][] constructDirectedNeighborhood(int n, int[][] e){
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
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][--outDegree[u]] = v;
			inNeighbors[v][--inDegree[v]] = u;
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
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][--degree[u]] = v;
			neighbors[v][--degree[v]] = u;
		}
		
		return neighbors;
	}
	
	static private void drawGraph(int[][] e) {
		makeDotUndirected(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void makeDotUndirected(int[][] e) {
		MyPrintWriter out2 = null;
		 try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
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
	
	static private void makeDotDirected(int[][] e) {
		MyPrintWriter out2 = null;
		 try {
			out2 = new MyPrintWriter(new FileOutputStream("graph.dot"));
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
