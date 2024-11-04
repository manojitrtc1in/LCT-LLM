import java.util.*;
import java.util.function.*;
import java.io.*;
import java.lang.reflect.Array;



public class Round773E {	
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


		
		Round773E sol = new Round773E();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		
		initIO(isFileIO);
	
		


		int n = in.nextInt();
		int q = in.nextInt();
		
		Query[] query = new Query[q];
		for(int j=0; j<q; j++) {
			int t = in.nextInt();
			if(t == 0) {
				query[j] = Query.updateQuery(in.nextInt()-1, in.nextInt()-1, in.nextInt()==1);
			}
			else {
				query[j] = Query.askQuery(in.nextInt()-1);
			}
		}
		
		
		Status[] ans = solve(n, query);
		for(int j=0; j<ans.length; j++) {
			switch(ans[j]) {
			case SICK:
				out.println(YES);
				break;
			case HEALTHY:
				out.println(NO);
				break;
			case CANT_KNOW:
				out.println("N/A");
				break;
			}
		}
		
	    in.close();
	    out.close();
	}
	
	private void test() {
		Random rand = new Random();
		while(true) {
			TreeSet<Interval> ones = new TreeSet<Interval>(new Comparator<Interval>() {
				@Override
				public int compare(Interval o1, Interval o2) {
					return Integer.compare(o1.l, o2.l);
				}
			});
			long total = 0;
			for(int i=0; i<5; i++) {
				long x = Math.abs(rand.nextLong()) % (1L << 63);
				total |= x;
				for(int j=0; j<63; j++)
					if( (x & (1L<<j)) > 0)
						addNonExistInterval(ones, j, j);
				for(int j=0; j<63; j++) {
					if( (total & (1L<<j)) > 0){
						if(ones.floor(new Interval(j, j)).r < j)
							total = total;
					}
				}
			}
		}
		
		
	}

	private Status[] solve(int n, Query[] queries) {
		ArrayList<Status> ans = new ArrayList<>();
		
		

		

		

		
		

		

		
		

		

		
		

		

		
		

		
		

		

		
		
		

		

		

		

		

		

		
		

		

		
		

		
		TreeSet<Interval> nonExistIntervals = new TreeSet<Interval>(new Comparator<Interval>() {
			@Override
			public int compare(Interval o1, Interval o2) {
				return Integer.compare(o1.l, o2.l);
			}
		});
		
		int[] filler = new int[n];
		Arrays.fill(filler, n);
		SegmentTree existMinTree = new SegmentTree((x, y) -> Math.min(x, y), filler);

		for(int queryNum = 0; queryNum < queries.length; queryNum++) {
			Query query = queries[queryNum];
			switch(query.qt) {
			case UPDATE:
				if(query.exists) {
					existMinTree.update(query.l, Math.min(existMinTree.getRange(query.l, query.l), query.r));
				}
				else {
					addNonExistInterval(nonExistIntervals, query.l, query.r);
				}
				break;
			case ASK:
				int x = query.patient;
				Interval left = nonExistIntervals.floor(new Interval(x, x));
				int l, r;
				if(left == null || left.r < x-1) {
					l = x;
				}
				else if(left.r >= x) {
					ans.add(Status.HEALTHY);
					continue;
				}
				else {
					

					l = left.l;
				}
				Interval right = nonExistIntervals.higher(new Interval(x, x));
				if(right == null || right.l > x+1) {
					r = x;
				}
				else{
					

					r = right.r;
				}
				
				int rMin = existMinTree.getRange(l, x);
				if(rMin <= r) {
					ans.add(Status.SICK);
				}
				else {
					ans.add(Status.CANT_KNOW);
				}
				break;
			}
		}
		
		return ans.toArray(new Status[0]);
	}

	private void addNonExistInterval(TreeSet<Round773E.Interval> nonExistIntervals, int l, int r) {
		{
			Interval interval = nonExistIntervals.floor(new Interval(l, l));
			if(interval != null && interval.r >= l) {
				nonExistIntervals.remove(interval);
				l = interval.l;
				r = Math.max(r, interval.r);
			}
		}
		for(Interval interval = nonExistIntervals.ceiling(new Interval(l, l)); interval != null && interval.l <= r; interval = nonExistIntervals.higher(interval)) {
			nonExistIntervals.remove(interval);
			r = Math.max(r, interval.r);
		}
		
		Interval upper = nonExistIntervals.higher(new Interval(r, r));
		if(upper != null && upper.l == r+1) {
			nonExistIntervals.remove(upper);
			r = upper.r;
		}
		Interval lower = nonExistIntervals.lower(new Interval(l, l));
		if(lower != null && lower.r == l-1) {
			nonExistIntervals.remove(lower);
			l = lower.l;
		}

		nonExistIntervals.add(new Interval(l, r));
	}

	enum Status{
		SICK,
		HEALTHY,
		CANT_KNOW
	}
	
	class Interval{
		int l, r;

		public Interval(int l, int r) {
			this.l = l;
			this.r = r;
		}
		public String toString() {
			return "[" + l + " " + r + "]";
		}
	}
	
	static class Query{
		enum QueryType{
			UPDATE,
			ASK
		}
		QueryType qt;
		int l = -1;
		int r = -1;
		boolean exists;
		int patient = -1;
		private Query(int l, int r, boolean exists) {
			this.qt = QueryType.UPDATE;
			this.l = l;
			this.r = r;
			this.exists = exists;
		}
		private Query(int patient) {
			this.qt = QueryType.ASK;
			this.patient = patient;
		}
		public static Round773E.Query askQuery(int patient) {
			return new Query(patient);
		}
		public static Round773E.Query updateQuery(int l, int r, boolean b) {
			return new Query(l, r, b);
		}
	}
	

	
	class SegmentTree {
		BiFunction<Integer, Integer, Integer> function;
		

		int n;
		int[] tree;
		

		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int[] arr){	
			this.function = function;
			

			this.n = arr.length;
			
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;


			
			tree = new int[m];
			

			
			

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
			tree[treeIdx] = function.apply(tree[treeIdxLeftMid], tree[treeIdxMidRight]);
		}

		public void update(int idx, int val){
			update(idx+1, val, 1, 1, n);
			

		}

		private int update(int idx, int val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];
			
			

			if(left == right){
				tree[treeIdx] = val;
				return val;
			}
			
			

			int mid = (left+right)>>1;
			int val1 = update(idx, val, treeIdx<<1, left, mid);
			int val2 = update(idx, val, (treeIdx<<1) + 1, mid+1, right);
			val = function.apply(val1, val2);
			tree[treeIdx] = val;
			return val;
		}
		
		public int getRange(int start, int end){
			return getRange(start+1, end+1, 1, 1, n);
			

		}

		private int getRange(int start, int end, int treeIdx, int left, int right) {
			

			
			

			
			if(start == left && end == right)
				return tree[treeIdx];
			
			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				int val1 = getRange(start, mid, treeIdx<<1, left, mid);
				int val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, (treeIdx<<1)+1, mid+1, right);
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
		
		int[][] nextTreeEdges(int n, int offset){
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

		int[][] nextGraphEdges(){
			return nextGraphEdges(0);
		}
		
		int[][] nextGraphEdges(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
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
	}
	
	public static class MyPrintWriter extends PrintWriter{
		public MyPrintWriter(OutputStream os) {
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
