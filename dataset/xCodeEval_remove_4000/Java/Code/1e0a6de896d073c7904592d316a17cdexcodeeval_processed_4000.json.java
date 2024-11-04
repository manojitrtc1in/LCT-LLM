import java.util.*;
import java.util.function.*;
import java.io.*;



public class id11 {	
	id3 out;
	MyScanner in;
	








	final static String id7 = "id7";
	final static String id8 = "id8";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id6) {
        if (System.getProperty("ONLINE_JUDGE") == null && id6) {
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


		
		id11 sol = new id11();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id6 = true;
		boolean id1 = false;
		
		initIO(id6);
	
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
	int[] c;
	int[][] uv;
	void getInput() {
		n = in.nextInt();
		m = n-1;
		c = in.id5(n);
		uv = in.nextMatrix(m, 2, -1);
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	int[] ans;
	void solve(){
		


		

		

		

		
		

		

		
		

		

		

		

		
		

		

		
		color = new Vtype[n];
		for(int i=0; i<n; i++)
			color[i] = c[i]==0? Vtype.WHITE: Vtype.BLACK;
		
		int[] deg = new int[n];
		for(int i=0; i<m; i++) {
			deg[uv[i][0]]++;
			deg[uv[i][1]]++;
		}
			
		int[][] incidentEdges = new int[n][];
		for(int i=0; i<n; i++)
			incidentEdges[i] = new int[deg[i]];
		
		for(int i=0; i<m; i++) {
			int u = uv[i][0];
			int v = uv[i][1];
			incidentEdges[u][--deg[u]] = i;
			incidentEdges[v][--deg[v]] = i;
		}
		
		DSU dsu = new DSU(m);
		
		for(int i=0; i<n; i++) {
			if(color[i] == Vtype.WHITE) {
				if(incidentEdges[i].length > 1) {
					for(int j=1; j<incidentEdges[i].length; j++)
						dsu.union(incidentEdges[i][0], incidentEdges[i][j]);
				}
			}
		}
		
		ans = new int[n];
		
		boolean[] isRemoved = new boolean[n];
		for(int i=0; i<n; i++) {
			if(color[i] == Vtype.BLACK) {
				isRemoved[i] = true;
				
				int cnt = 0;
				ans[i] = 1;
				for(int e: incidentEdges[i]) {
					

					ans[uv[e][0]] = 1;
					ans[uv[e][1]] = 1;
					if(!dsu.isGood(e))
						cnt++;
				}
				if(cnt > 1) {
					

					Arrays.fill(ans, 1);
					return;
				}
			}
		}
		
		for(int i=0; i<n; i++) {
			if(ans[i] == 1)
				color[i] = Vtype.BLACK;
		}
		
		

		for(int e=0; e<m; e++) {
			if(dsu.isGood(e)) {
				int u = uv[e][0];
				int v = uv[e][1];
				ans[u] = 1;
				ans[v] = 1;
				isRemoved[u] = true;
				isRemoved[v] = true;
			}
		}
		
		

		DSU id4 = new DSU(m);
		
		for(int i=0; i<n; i++) {
			if(color[i] == Vtype.WHITE && !isRemoved[i]) {
				if(incidentEdges[i].length > 1) {
					for(int j=1; j<incidentEdges[i].length; j++)
						id4.union(incidentEdges[i][0], incidentEdges[i][j]);
				}
			}
		}
		
		boolean[] isGood = new boolean[n];
		boolean[] id13 = new boolean[n];
		for(int i=0; i<n; i++) {
			if(color[i] == Vtype.BLACK && !isRemoved[i]) {
				int cnt = 0;
				for(int e: incidentEdges[i]) {
					if(!id4.isGood(e)){
						cnt++;
					}
				}
				if(cnt == 2) {
					for(int e: incidentEdges[i]) {
						if(!id4.isGood(e))
							continue;
						int h = id4.find(e);
						id13[h] = true;
					}
				}
				if(cnt >= 3) {
					for(int e: incidentEdges[i])
						isGood[dsu.find(e)] = true;
				}
			}
		}
		
		for(int e=0; e<m; e++) {
			int h = id4.find(e);
			if(id13[h]) {
				ans[uv[e][0]] = 1;
				ans[uv[e][1]] = 1;
			}
			h = dsu.find(e);
			if(isGood[h]) {
				ans[uv[e][0]] = 1;
				ans[uv[e][1]] = 1;				
			}
		}
	}
	
	Vtype[] color;
	
	enum Vtype{
		WHITE, BLACK;
	}
	
	class DSU{
		int[] parent;
		int[] size;
		int[] numBlack;
		
		public DSU(int m) {
			parent = new int[m];
			Arrays.fill(parent, -1);
			size = new int[m];
			Arrays.fill(size, 1);
			numBlack = new int[m];
			for(int i=0; i<m; i++) {
				int cnt = 0;
				if(color[uv[i][0]] == Vtype.BLACK)
					cnt++;
				if(color[uv[i][1]] == Vtype.BLACK)
					cnt++;
				numBlack[i] = cnt;
			}
		}
		
		public void union(int e, int f){
			e = find(e);
			f = find(f);
			if(e == f)
				return;
			
			int small, large;
			if(size[e] < size[f]) {
				small = e;
				large = f;
			}
			else {
				small = f;
				large = e;
			}
			
			size[large] += size[small];
			numBlack[large] += numBlack[small];
			parent[small] = large;
		}
		
		private int find(int e) {
			if(parent[e] == -1)
				return e;
			int head = find(parent[e]);
			parent[e] = head;
			return head;
		}
		
		public boolean isGood(int e) {
			int f = find(e);
			return numBlack[f] == 1;
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
		
		int[] id5(int len) {
			return id5(len, 0);
		}
		int[] id5(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id14(int len) {
			return id14(len, 0);
		}
		long[] id14(int len, int offset){
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
	
	static private void id12(long[] a) {
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
	
	static private void id12(int[] a) {
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
		id9(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id9(int[][] e) {
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
