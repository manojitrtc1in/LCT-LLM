
import java.util.*;
import java.util.function.*;
import java.io.*;



public class Round813E {	
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


		
		Round813E sol = new Round813E();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);

		getInput();
		
		solve();
		
		printOutput();
		


























	    
	    in.close();
	    out.close();
	}
	
	

	class Query{
		int l, r, index;

		public Query(int l, int r, int index) {
			this.l = l;
			this.r = r;
			this.index = index;
		}
		
	}
	
	int t;
	Query[] query;
	void getInput() {
		t = in.nextInt();
		query = new Query[t];
		for(int i=0; i<t; i++) {
			query[i] = new Query(in.nextInt(), in.nextInt(), i);
		}
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}

	long[] ans;
	void solve(){
		

		

		

		
		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		

		

		
		

		

		
		final int MAX = 200_000;
		
		SegmentTree sumTree;
		ArrayList<Integer>[] divisors;

		sumTree = new SegmentTree(MAX+1);
		
		divisors = new ArrayList[MAX*2+1];
		for(int i=1; i<=MAX*2; i++)
			divisors[i] = new ArrayList<Integer>();
		
		for(int i=2; i<=MAX; i++) {
			if(divisors[i].isEmpty()) {
				divisors[i].add(1);
				divisors[i].add(i);
				if(MAX/i >= i) {
					for(int j=i*i; j<=MAX; j+= i) {
						if(divisors[j].isEmpty())
							divisors[j].add(i);
					}
				}
			}
			else {
				int prime = divisors[i].get(0);
				divisors[i].clear();
				int p = 1;
				int j = i/prime;
				while(j % prime == 0) {
					p *= prime;
					j /= prime;
				}
				for(int divisor: divisors[i/prime]) {
					divisors[i].add(divisor);
					if(divisor % p == 0)
						divisors[i].add(divisor*prime);
				}
				Collections.sort(divisors[i]);
			}
		}
		
		for(int i=MAX+1; i<=MAX*2; i++) {
			if(i % 2 == 0) {
				int prime = 2;
				int p = 1;
				int j = i/prime;
				while(j % prime == 0) {
					p *= prime;
					j /= prime;
				}
				for(int divisor: divisors[i/prime]) {
					divisors[i].add(divisor);
					if(divisor % p == 0)
						divisors[i].add(divisor*prime);
				}
				Collections.sort(divisors[i]);
			}
		}
		














		
		Arrays.sort(query, (q1, q2) -> Integer.compare(q1.r, q2.r));
		
		ans = new long[t];
		
		int prevR = 2;
		for(int tt=0; tt<t; tt++) {
			int qIndex = query[tt].index;
			int r = query[tt].r;
			int l = query[tt].l;
			
			while(prevR < r) {
				int k = ++prevR;
				

				

				

				int index = 0;
				int total = divisors[k].size();
				for(int divisor: divisors[k]) {
					sumTree.add(divisor, Math.max(0, total-index-2));
					index++;
				}
				
				

				

				

				

				
				

				

				

				

				

				

				
				int q = k;
				int p = 1;
				while(q % 2 == 0) {
					q /= 2;
					p *= 2;
				}
				p *= 2;
				
				total = divisors[k*2].size()-1;
				int totalQ = divisors[q].size();
				for(int divisor: divisors[k*2]) {
					

					

					if(divisor < k) {
						if(divisor % p == 0) {
							

							index = Collections.binarySearch(divisors[k*2], Math.max(divisor, k-divisor));
							if(index < 0)
								index = -index-2;
							sumTree.add(divisor, Math.max(0, total-index-2));
						}
						else {
							

							

							

							

							

							index = Collections.binarySearch(divisors[q], (Math.max(divisor, k-divisor)+p-1)/p);
							if(index < 0)
								index = -index-2;
							else if((k-divisor) % p != 0)
								index--;
							sumTree.add(divisor, Math.max(0, totalQ-index-2));
						}
					}
				}
			}
			
			

			long cnt = r-l+1;
			ans[qIndex] = cnt*(cnt-1)*(cnt-2)/6 - sumTree.getRange(l, r);
		}
	}
	
	class SegmentTree {
		int n;
		long[] tree;
		public SegmentTree(int n) {
			this.n = n;
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			tree = new long[m];		
		}
		
		public void add(int idx, long val){
			add(idx, val, 1, 0, n-1);
		}

		private long add(int idx, long val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];
			
			

			if(left == right){
				tree[treeIdx] += val;
				return tree[treeIdx];
			}
			
			

			int mid = (left+right)>>1;
			long val1 = add(idx, val, treeIdx<<1, left, mid);
			long val2 = add(idx, val, (treeIdx<<1) + 1, mid+1, right);
			val = val1 + val2;
			tree[treeIdx] = val;
			return val;
		}
		
		public long getRange(int start, int end){
			return getRange(start, end, 1, 0, n-1);
		}

		private long getRange(int start, int end, int treeIdx, int left, int right) {
			if(start == left && end == right)
				return tree[treeIdx];
			
			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				long val1 = getRange(start, mid, treeIdx<<1, left, mid);
				long val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return val1 + val2;
			}
			else
				return getRange(start, end, (treeIdx<<1)+1, mid+1, right);
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
