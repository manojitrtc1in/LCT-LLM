import java.util.*;
import java.util.function.*;
import java.io.*;



public class id3 {	
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



		

		

		

		

		
		id3 sol = new id3();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id1 = true;
		
		initIO(id8);
	
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
	
	final String id16 = "imposter";
	final String id4 = "crewmate";
	
	

	int n, m;
	int[][] friend;
	

	ArrayList<Integer>[] enemy;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		friend = new int[n][];


		ArrayList<Integer>[] friend = new ArrayList[n];


		enemy = new ArrayList[n];
		for(int i=0; i<n; i++) {
			friend[i] = new ArrayList<Integer>();
			enemy[i] = new ArrayList<Integer>();
		}
		for(int k=0; k<m; k++) {
			int i = in.nextInt()-1;
			int j = in.nextInt()-1;
			String c = in.next();
			if(c.equals(id16)) {
				enemy[i].add(j);
				enemy[j].add(i);
			}
			else {
				friend[i].add(j);
				friend[j].add(i);
			}
		}
		for(int i=0; i<n; i++) {
			this.friend[i] = new int[friend[i].size()];
			for(int j=0; j<friend[i].size(); j++)
				this.friend[i][j] = friend[i].get(j);






			




		}
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}

	OptionalInt ans;
	void solve(){
		

		
		

		
		

		

		
		

		

		
		

		

		
		
		partition = new DSU(n);
		for(int v=0; v<n; v++) {
			for(int u: friend[v])
				partition.union(u, v);
		}
		
		color = new int[n];
		colorSize = new int[n*2];
		ArrayList<Integer>[] enemy = new ArrayList[n]; 
		for(int i=0; i<n; i++)
			enemy[partition.find(i)] = new ArrayList<Integer>();
		for(int i=0; i<n; i++)
			for(int j: this.enemy[i])
				enemy[partition.find(i)].add(partition.find(j));
		this.enemy = enemy;
		
		visited = new boolean[n];
		int currColor = 0;
		for(int i=0; i<n; i++) {
			int v = partition.find(i);
			if(!visited[v] && !dfs(v, currColor)) {
				ans = OptionalInt.empty();
				return;
			}
			currColor += 2;
		}
		
		int max = 0;
		for(int c=0; c<n*2; c+=2) {
			max += Math.max(colorSize[c], colorSize[c+1]);
		}
		ans = OptionalInt.of(max);
		


























































































		ans = OptionalInt.of(max);
	}
	
	DSU partition;
	boolean[] visited;
	int[] color;
	int[] colorSize;
	boolean dfs(int curr, int c) {
		if(visited[curr])
			return color[curr] == c;
		visited[curr] = true;
		color[curr] = c;
		for(int next: enemy[curr]) {
			if(!dfs(next, c^1))
				return false;
		}
		colorSize[c] += partition.size[curr];
		return true;
	}
	
	public class DSU {
		int[] size;
		int[] parents;
		
		public DSU(int max) {
			parents = new int[max];
			size = new int[max];
			Arrays.fill(parents, -1);
			Arrays.fill(size, 1);
		}
		
		public void union(int v, int u) {
			int head1 = find(v);
			int head2 = find(u);
			if(head1 == head2)
				return;
			int smaller, larger;
			if(size[head1] > size[head2]) {
				smaller = head2;
				larger = head1;
			}
			else {
				smaller = head1;
				larger = head2;
			}
			parents[smaller] = larger;
			size[larger] += size[smaller];
		}
		public int find(int v) {
			if(parents[v] == -1)
				return v;
			int head = find(parents[v]);
			parents[v] = head;
			return head;
		}
	}
	 




	
	static class Pair implements Comparable<Pair>{
		final static long id6 = System.currentTimeMillis();
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
			x += id6;
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
		
		int[][] id10(int n, int m){
			return id10(n, m, 0);
		}
		
		int[][] id10(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
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
		
		long[] id17(int len) {
			return id17(len, 0);
		}
		long[] id17(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id14(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id5 extends PrintWriter{
		public id5(OutputStream os) {
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
		
		public void printlnAns(boolean[] ans) {
			for(boolean b: ans)
				printlnAns(b);
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
	
	static private void id15(long[] a) {
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
	
	static private void id15(int[] a) {
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
	
	static private void id2(int[][] e) {
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
