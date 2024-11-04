import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundHello2022E {	
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


		
		RoundHello2022E sol = new RoundHello2022E();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);
		
		

	
		int t = hasMultipleTests? in.nextInt() : 1;
		
		final int MAX = 100_000;
		segTree = new SegmentTreeLazyMin(MAX+1);
	    
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
	
	SegmentTreeLazyMin segTree;
	
	void test() {
		Random rand = new Random();
		final int MAX = 100_000;
		for(int t = 0; t < 10000; t++) {
			n = rand.nextInt(5)+1;
			m = rand.nextInt(n)+1;
			a = new int[n];
			for(int i=0; i<n; i++)
				a[i] = rand.nextInt(MAX)+1;
			b = new long[m][];
			long[] sum = new long[m];
			int[] len = new int[m];
			for(int i=0; i<m; i++) {
				int k = rand.nextInt(5)+2;
				b[i] = new long[k];
				len[i] = k;
				for(int j=0; j<k; j++) {
					b[i][j] = rand.nextInt(MAX)+1;
					sum[i] += b[i][j];
				}
			}
			solve();
			StringBuilder sb = new StringBuilder();
			for(int i=0; i<m; i++) {
				int k = b[i].length;
				len[i]--;
				for(int j=0; j<k; j++) {
					sum[i] -= b[i][j];
					if(possible(a, sum, len))
						sb.append('1');
					else
						sb.append('0');
					sum[i] += b[i][j];
				}
				len[i]++;
			}
			if(!ans.equals(sb.toString())) {
				solve();
			}
		}
	}
	
	boolean possible(int[] a, long[] sum, int[] len) {
		TreeMap<Integer, Integer> count = new TreeMap<>();
		for(int val: a)
			count.merge(val, 1, (x, y) -> x+y);
		
		int m = sum.length;
		for(int i=0; i<m; i++) {
			Integer key = count.ceilingKey(ceil(sum[i], len[i]));
			if(key == null)
				return false;
			int cnt = count.remove(key) -1;
			if(cnt > 0)
				count.put(key, cnt);
		}
		return true;
	}
	
	

	int n, m;
	int[] a;
	long[][] b;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.nextIntArray(n);
		b = new long[m][];
		for(int i=0; i<m; i++) {
			int k = in.nextInt();
			b[i] = in.nextLongArray(k);
		}
	}
	
	int ceil(long numer, int denom) {
		return (int)((numer+denom-1)/denom);
	}
	
	void printOutput() {
		out.println(ans);
	}

	String ans;
	void solve(){
		StringBuilder sb = new StringBuilder();










		














		
		for(int i=0; i<n; i++)
			segTree.free(a[i]);
		


		long[] sum = new long[m];
		for(int i=0; i<m; i++) {
			int k = b[i].length;
			for(int j=0; j<k; j++)
				sum[i] += b[i][j];
		}

		for(int i=0; i<m; i++) {
			int avg = ceil(sum[i], b[i].length);
			segTree.assign(avg);
		}
		






















		
		for(int i=0; i<m; i++) {
			int k = b[i].length;
			segTree.free(ceil(sum[i], k));












			
			for(int j=0; j<k; j++) {
				int avg = ceil(sum[i]-b[i][j], k-1);
				segTree.assign(avg);
				if(segTree.check())
					sb.append('1');
				else
					sb.append('0');
				segTree.free(avg);




















			}
			

			segTree.assign(ceil(sum[i], k));
		}
		
		for(int i=0; i<m; i++) {
			int avg = ceil(sum[i], b[i].length);
			segTree.free(avg);
		}
		
		for(int i=0; i<n; i++)
			segTree.assign(a[i]);
		
		ans = sb.toString();
	}
	




















































	 




	
	class SegmentTreeLazyMin{
		int n;
		int[] tree;
		int[] lazy;
		

		public SegmentTreeLazyMin(int n) {
			this.n = n;
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			tree = new int[m];
			lazy = new int[m];
		}
		
		public SegmentTreeLazyMin(int[] arr){
			this.n = arr.length;

			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			tree = new int[m];
			lazy = new int[m];
			


			

			build(arr, 1, 0, n-1);
		}

		private void build(int[] arr, int treeIdx, int left, int right) {
			if(left == right) {
				tree[treeIdx] = arr[left];
				

				return;
			}

			int mid = (left+right)>>1;
			int treeIdxLeftMid = treeIdx<<1;
			int treeIdxMidRight = (treeIdx<<1)+1;
			build(arr, treeIdxLeftMid, left, mid);
			build(arr, treeIdxMidRight, mid+1, right);
			tree[treeIdx] = Math.min(tree[treeIdxLeftMid], tree[treeIdxMidRight]);

			

		}
		
		public boolean check() {
			return getRange(0, n-1) >= 0;
		}
		
		public void assign(int val) {
			rangeAdd(0, val, -1);
		}
		
		public void free(int val) {
			rangeAdd(0, val, 1);
		}

		public void rangeAdd(int l, int r, int val) {
			rangeAdd(l, r, val, 1, 0, n-1);
		}

		private int rangeAdd(int l, int r, int val, int treeIdx, int left, int right) {
			if(left == right) {
				lazy[treeIdx] += val;
				return tree[treeIdx] + lazy[treeIdx];
			}
			if(left == l && right == r) {
				lazy[treeIdx] += val;
				

				return tree[treeIdx] + lazy[treeIdx];
			}

			int mid = (left+right)/2;
			int treeIdxLeftMid = treeIdx<<1;
			int treeIdxMidRight = (treeIdx<<1)+1;

			lazy[treeIdxLeftMid] += lazy[treeIdx];
			lazy[treeIdxMidRight] += lazy[treeIdx];
			lazy[treeIdx] = 0;

			int val1, val2;
			if(r <= mid) {
				val1 = rangeAdd(l, r, val, treeIdxLeftMid, left, mid);
				val2 = tree[treeIdxMidRight] + lazy[treeIdxMidRight];

			}
			else if(l > mid) {
				val1 = tree[treeIdxLeftMid] + lazy[treeIdxLeftMid];

				val2 = rangeAdd(l, r, val, treeIdxMidRight, mid+1, right);
			}
			else {
				val1 = rangeAdd(l, mid, val, treeIdxLeftMid, left, mid);
				val2 = rangeAdd(mid+1, r, val, treeIdxMidRight, mid+1, right);
			}
			tree[treeIdx] = Math.min(val1, val2);

			return tree[treeIdx];
		}

		public int getRange(int start, int end){
			return getRange(start, end, 1, 0, n-1);
		}

		private int getRange(int start, int end, int treeIdx, int left, int right) {
			


			


			if(start == left && end == right)
				return tree[treeIdx] + lazy[treeIdx];


			lazy[treeIdx<<1] += lazy[treeIdx];
			lazy[(treeIdx<<1)+1] += lazy[treeIdx];
			lazy[treeIdx] = 0;

			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				int val1 = getRange(start, mid, treeIdx<<1, left, mid);
				int val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return Math.min(val1, val2);

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
