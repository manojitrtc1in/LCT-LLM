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
		boolean id6 = false;
		boolean id1 = false;
		
		initIO(id6);
	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	solve();
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	int n;
	void getInput() {
		n = in.nextInt(); 
	}
	
	int makeQuery(boolean[] a) {
		StringBuilder sb = new StringBuilder();
		for(boolean tf: a)
			sb.append(tf? 'T': 'F');
		out.println(sb.toString());
		out.flush();
		int res = in.nextInt();












		return res;
	}
	
	void solve(){
		

		

		
		

		
		

		

		

		
		

		
		

		
		

		

		

		
		

		

		
		

		

		
		

		

		
		
		

		

		

		
		

		
		

		

		
		

		

		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		

		

		
		

		

		

		

		
		

		

		
		

		

		

		
		

		

		

		

		

		

		

		
		

		

		

		
		

		

		
		

		

		
		

		

		

		

		

		

		

		

		

		

		

		

		
		

		
		
		ArrayDeque<Integer> undetermined = new ArrayDeque<>();
		for(int i=0; i<n; i++)
			undetermined.add(i);
		
		ArrayList<Integer> correctIndices = new ArrayList<>();
		

		
		ArrayList<Info>[] pendingIndices = new ArrayList[n];
		for(int i=0; i<n; i++)
			pendingIndices[i] = new ArrayList<Info>();
		
		

		outNeighbors = new ArrayList[n];
		for(int i=0; i<n; i++)
			outNeighbors[i] = new ArrayList<Integer>();
		
		Random rand = new Random();
		base = new boolean[n];
		for(int i=0; i<n; i++)
			base[i] = rand.nextBoolean();
		
		ans = new boolean[n];
		
		

		int baseK = makeQuery(base);
		if(baseK == n) {
			return;
		}
		for(int i=1; i<674; i++) {
			if(undetermined.isEmpty()) {
				break;
			}
			else {
				int j1 = undetermined.pollLast();
				if(undetermined.isEmpty()) {
					base[j1] ^= true;
					int k = makeQuery(base);
					if(k == n)
						return;
					base[j1] ^= true;
					if(k == baseK+1) {
						ans[j1] = base[j1]^true;
					}
					else if(k == baseK-1) {
						ans[j1] = base[j1];
					}
					else {
						return;
					}
					correctIndices.add(j1);
					id12(j1, pendingIndices, undetermined);
				}
				else {
					int j2 = undetermined.pollLast();
					if(undetermined.isEmpty()) {
						base[j1] ^= true;
						base[j2] ^= true;
						
						int k = makeQuery(base);
						if(k == n)
							return;
						
						base[j1] ^= true;
						base[j2] ^= true;
						
						if(k == baseK) {
							undetermined.add(j1);
							outNeighbors[j1].add(j2);
						}
						else {
							if(k == baseK+2) {
								ans[j1] = base[j1]^true;
								ans[j2] = base[j2]^true;
							}
							else if(k == baseK-2){
								ans[j1] = base[j1];
								ans[j2] = base[j2];
							}
							else {
								return;
							}
							correctIndices.add(j1);
							correctIndices.add(j2);
							id12(j1, pendingIndices, undetermined);
							id12(j2, pendingIndices, undetermined);
						}
					}
					else {
						int j3 = undetermined.pollLast();
						base[j1] ^= true;
						base[j2] ^= true;
						base[j3] ^= true;
						
						int k = makeQuery(base);
						if(k == n)
							return;
						
						base[j1] ^= true;
						base[j2] ^= true;
						base[j3] ^= true;
						
						if(k == baseK+3 || k == baseK-3) {
							if(k == baseK+3) {
								ans[j1] = base[j1]^true;
								ans[j2] = base[j2]^true;
								ans[j3] = base[j3]^true;
							}
							else {
								ans[j1] = base[j1];
								ans[j2] = base[j2];
								ans[j3] = base[j3];
							}
							correctIndices.add(j1);
							id12(j1, pendingIndices, undetermined);
							correctIndices.add(j2);
							id12(j2, pendingIndices, undetermined);
							correctIndices.add(j3);
							id12(j3, pendingIndices, undetermined);
						}
						else {
							undetermined.add(j1);
							if(k == baseK+1) {
								pendingIndices[j1].add(new Info(base[j1], j2, j3));
							}
							else if(k == baseK-1){
								pendingIndices[j1].add(new Info(base[j1]^true, j2, j3));
							}
							else {
								return;
							}
						}
					}
				}
			}
		}
		if(undetermined.isEmpty()) {
			for(int j: correctIndices) {
				dfs(j, ans[j] ^ base[j]);
			}
			makeQuery(ans);
		}
		else {
			while(true);
		}
	}
	
	static class Info{
		boolean expected;
		int j2, j3;
		public Info(boolean expected, int j2, int j3) {
			this.expected = expected;
			this.j2 = j2;
			this.j3 = j3;
		}
		@Override
		public String toString() {
			return "(" + expected + "," + j2 + "," + j3 + ")"; 
		}
	}
	
	private void id12(int j1, ArrayList<Info>[] pendingIndices, ArrayDeque<Integer> undetermined) {
		for(Info info: pendingIndices[j1]) {
			if(info.expected == ans[j1]) {
				outNeighbors[j1].add(info.j2);
				outNeighbors[j1].add(info.j3);
			}
			else {
				undetermined.add(info.j2);
				outNeighbors[info.j2].add(info.j3);
			}
		}
	}

	void dfs(int curr, boolean flip) {
		ans[curr] = base[curr] ^ flip;
		for(int next: outNeighbors[curr]) {
			dfs(next, !flip);
		}
	}
	
	boolean[] ans;
	boolean[] base;
	ArrayList<Integer>[] outNeighbors;
	
	static class Pair implements Comparable<Pair>{
		final static long id4 = System.currentTimeMillis();
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
			x += id4;
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
		
		int[] id5(int len) {
			return id5(len, 0);
		}
		int[] id5(int len, int offset){
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
		
		String[] id13(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
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
	
	static private void id14(long[] a) {
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
	
	static private void id14(int[] a) {
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
