import java.util.*;
import java.util.function.*;
import java.io.*;



public class id12 {	
	id3 out;
	MyScanner in;
	








	final static String id6 = "id6";
	final static String id7 = "id7";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id5) {
        if (System.getProperty("ONLINE_JUDGE") == null && id5) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id3(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id3(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id12 sol = new id12();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id5 = true;
		boolean id1 = false;
		
		initIO(id5);
	
		int t = id1? in.nextInt() : 1;
	    
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
	int[][] e;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		e = in.nextMatrix(m, 2, -1);
	}
	
	void printOutput() {
		out.println(ans);
	}
	
	String ans;
	void solve(){
		

		

		
		

		
		
		

		

		
		

		
		

		

		
		
		

		
		

		

		

		

		

		

		

		

		

		
		

		
		

		

		

		

		

		

		

		

		
		

		

		

		

		

		
		

		

		
		DSU dsu = new DSU(n);
		treeNeighbors = new ArrayList[n];
		for(int i=0; i<n; i++)
			treeNeighbors[i] = new ArrayList<Integer>();
		
		boolean[] id14 = new boolean[m];
		
		for(int i=0; i<m; i++) {
			int u = e[i][0];
			int v = e[i][1];
			boolean isGood = dsu.union(u, v);
			if(isGood) {
				treeNeighbors[u].add(v);
				treeNeighbors[v].add(u);
			}
			else
				id14[i] = true;
		}
		
		final int root = 0;
		id9(root);
		
		goodness = new int[n];
		
		for(int i=0; i<m; i++) {
			if(id14[i]) {
				int u = e[i][0];
				int v = e[i][1];
				int w = lca(u, v);
				if(w == v) {
					int temp = u;
					u = v;
					v = temp;
				}
				if(w == u) {
					

					

					

					

					

					

					

					

					goodness[root]++;
					int prev = prevChild(u, v);
					goodness[prev]--;
					goodness[v]++;
				}
				else {
					

					

					

					

					

					goodness[u]++;
					goodness[v]++;
				}
			}
		}
		
		id11(root, -1);
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			if(goodness[i] == m-(n-1))
				sb.append('1');
			else
				sb.append('0');
		}
		ans = sb.toString();
	}
	
	int[] goodness;
	
	void id11(int curr, int parent) {
		for(int next: treeNeighbors[curr]) {
			if(next == parent)
				continue;
			goodness[next] += goodness[curr];
			id11(next, curr);
		}
	}
	
	void id9(final int root) {
		int log = 31-Integer.numberOfLeadingZeros(n); 
		lifting = new int[log+1][n];
		depth = new int[n];
		
		liftingDFS(root, root, 0);
	}
	
	void liftingDFS(int curr, int parent, int d) {
		depth[curr] = d;
		lifting[0][curr] = parent;
		for(int i=1; i<lifting.length; i++) {
			lifting[i][curr] = lifting[i-1][lifting[i-1][curr]];
		}
		for(int next: treeNeighbors[curr]) {
			if(next == parent)
				continue;
			liftingDFS(next, curr, d+1);
		}
	}
	
	boolean isAncestor(int u, int v) {
		for(int i=lifting.length-1; i>=0 && depth[v] > depth[u]; i--){
			if(depth[lifting[i][v]] >= depth[u])
				v = lifting[i][v];
		}
		return u == v;
	}
	
	

	int prevChild(int u, int v) {
		for(int i=lifting.length-1; i>=0 && depth[v] > depth[u]; i--){
			if(depth[lifting[i][v]] > depth[u])
				v = lifting[i][v];
		}
		return v;
	}
	
	int lca(int u, int v) {
		if(depth[v] < depth[u])
			return lca(v, u);
		

		for(int i=lifting.length-1; i>=0 && depth[v] > depth[u]; i--){
			if(depth[lifting[i][v]] >= depth[u])
				v = lifting[i][v];
		}
		if(u == v)
			return u;
		

		for(int i=lifting.length-1; i>=0; i--) {
			if(lifting[i][u] != lifting[i][v]) {
				u = lifting[i][u];
				v = lifting[i][v];
			}
		}
		return lifting[0][u];
	}
	
	ArrayList<Integer>[] treeNeighbors;
	int[][] lifting;
	int[] depth;
	
	class DSU{
		int[] parent;
		int[] size;
		public DSU(int n) {
			parent = new int[n];
			Arrays.fill(parent, -1);
			size = new int[n];
		}
		public boolean union(int u, int v) {
			u = find(u);
			v = find(v);
			if(u == v)
				return false;
			int small, large;
			if(size[u] < size[v]) {
				small = u;
				large = v;
			}
			else {
				small = v;
				large = u;
			}
			size[large] += size[small];
			parent[small] = large;
			return true;
		}
		public int find(int v) {
			if(parent[v] == -1)
				return v;
			int head = find(parent[v]);
			parent[v] = head;
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
		
		int[] id4(int len) {
			return id4(len, 0);
		}
		int[] id4(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id15(int len) {
			return id15(len, 0);
		}
		long[] id15(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
	}
	
	public static class id3 extends PrintWriter{
		public id3(OutputStream os) {
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
		
		public void id0(long[] arr, int split){
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
		
		public void id0(int[] arr, int split){
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
		
		public <T> void id0(ArrayList<T> arr, int split){
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
	
	static private void id13(long[] a) {
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
	
	static private void id13(int[] a) {
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
	
	static private int[][][] id10(int n, int[][] e){
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
		id8(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id8(int[][] e) {
		id3 out2 = null;
		 try {
			out2 = new id3(new FileOutputStream("graph.dot"));
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
	
	static private void id2(int[][] e) {
		id3 out2 = null;
		 try {
			out2 = new id3(new FileOutputStream("graph.dot"));
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
