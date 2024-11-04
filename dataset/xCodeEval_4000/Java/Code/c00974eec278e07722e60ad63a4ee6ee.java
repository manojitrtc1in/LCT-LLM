import java.util.*;
import java.util.function.*;
import java.io.*;
import java.lang.reflect.Array;



public class RoundEdu126E {	
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


		
		RoundEdu126E sol = new RoundEdu126E();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = false;
		
		initIO(isFileIO);
		
		

		
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();












	    	String[] mat = new String[SIZE];
	    	for(int j=0; j<SIZE; j++)
	    		mat[j] = in.next();
	    	
	    	int q = in.nextInt();
	    	int[][] lr = in.nextPairs(q, -1);
	    	int[] l = lr[0];
	    	int[] r = lr[1];
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int[] ans = solve(mat, l, r);
			out.printlnAnsSplit(ans, 1);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		int n = 500_000;
		int q = 300_000;
		Random rand = new Random();
		StringBuilder sb = new StringBuilder();
		String[] mat = new String[SIZE];
		for(int i=0; i<SIZE; i++) {
			for(int j=0; j<n; j++) {
				if(rand.nextBoolean())
					sb.append('1');
				else
					sb.append('0');
			}
			mat[i] = sb.toString();
			sb.setLength(0);
		}
		
		int[] l = new int[q];
		int[] r = new int[q];
		for(int i=0; i<q; i++) {
			r[i] = rand.nextInt(n-1)+1;
			l[i] = rand.nextInt(r[i]+1);
		}
		int[] ans = solve(mat, l, r);
		out.printlnAnsSplit(ans, 1);
	}

	static final int SIZE = 3;
	private int[] solve(String[] mat, int[] l, int[] r) {
		int q = l.length;
		int n = mat[0].length();
		
		ConnectedComponent[] unitCCs = new ConnectedComponent[n];
		for(int i=0; i<n; i++) {
			int mask = 0;
			for(int j=0; j<SIZE; j++)
				if(mat[j].charAt(i) == '1')
					mask += 1<<j;
			unitCCs[i] = ConnectedComponent.valueOf(mask);
		}
		
		cache = new HashMap<>();
		
		SegmentTreeGeneric<ConnectedComponent> segTree =
				new SegmentTreeGeneric<ConnectedComponent>(this::merge, unitCCs);
		
		int[] ans = new int[q];
		for(int i=0; i<q; i++)
			ans[i] = segTree.getRange(l[i], r[i]).numCC;
		
		return ans;
	}
	
	HashMap<Pair, ConnectedComponent> cache;
	class Pair{
		ConnectedComponent left;
		ConnectedComponent right;
		public Pair(RoundEdu126E.ConnectedComponent left, RoundEdu126E.ConnectedComponent right) {
			this.left = left;
			this.right = right;
		}
		@Override
		public int hashCode() {
			

			int result = left.pack();
			result <<= 15;
			result += right.pack();
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			Pair other = (Pair) obj;
			int o = other.hashCode();
			int h = this.hashCode();














			return o==h;
		}
	}
	ConnectedComponent merge(ConnectedComponent left, ConnectedComponent right) {
		ConnectedComponent val = cache.get(new Pair(left, right));
		if(val != null) {
			return new ConnectedComponent(val.numCC + left.numCC + right.numCC, val.leftState, val.rightState);
		}
		
		int[] leftState = Arrays.copyOf(left.leftState, SIZE);
		int[] rightState = Arrays.copyOf(right.rightState, SIZE);
		
		int[] middleLeftState = left.rightState;
		int[] middleRightState = right.leftState;
		
		

		int numCC = 0;
		
		

		DSU dsu = new DSU(SIZE*4+1);

		for(int i=0; i<SIZE; i++) {
			if(leftState[i] != 0) {
				dsu.put(leftState[i]);
			}
			if(middleLeftState[i] != 0) {
				dsu.put(middleLeftState[i]);
			}
			if(middleRightState[i] != 0) {
				dsu.put(middleRightState[i]+SIZE*2);
			}
			if(rightState[i] != 0) {
				dsu.put(rightState[i]+SIZE*2);
			}
		}
		numCC-= dsu.numCC();

		for(int i=0; i<SIZE; i++) {
			if(middleLeftState[i] != 0 && middleRightState[i]!= 0)
				dsu.union(middleLeftState[i], middleRightState[i]+SIZE*2);
		}
		
		int[] resizeMap = new int[SIZE*4+1];
		int idx = 1;
		for(int i=0; i<SIZE; i++) {
			if(leftState[i] != 0) {
				int head = dsu.find(leftState[i]);
				if(resizeMap[head] == 0)
					resizeMap[head] = idx++;
				leftState[i] = resizeMap[head];
			}
			if(rightState[i] != 0) {
				int head = dsu.find(rightState[i]+SIZE*2);
				if(resizeMap[head] == 0)
					resizeMap[head] = idx++;
				rightState[i] = resizeMap[head];
			}
		}
		numCC += dsu.numCC();
		
		val = new ConnectedComponent(numCC, leftState, rightState);
		cache.put(new Pair(left, right), val);
				
		return new ConnectedComponent(numCC + left.numCC + right.numCC, leftState, rightState);
	}
	
	static class ConnectedComponent{
		int numCC;
		int[] leftState; 

		int[] rightState;
		public ConnectedComponent(int numCC, int[] leftState, int[] rightState) {
			this.numCC = numCC;
			this.leftState = leftState;
			this.rightState = rightState;
		}
		
		public int pack() {
			int val = 0;


			for(int i=0; i<SIZE; i++) {
				

				

				val = (val << 2) + val;
				val += leftState[i];
			}
			for(int i=0; i<SIZE; i++) {
				

				

				val = (val << 2) + val;
				val += rightState[i];
			}
			return val;
		}
		
		static public ConnectedComponent valueOf(int mask) {
			int[] leftState = new int[SIZE];
			int[] rightState = leftState;
			
			if(mask == 0) {
				return new ConnectedComponent(0, leftState, rightState);
			}
			if(mask == 5) {
				leftState[0] = 1;
				leftState[2] = 2;
				return new ConnectedComponent(2, leftState, rightState);
			}
			if((mask & 1) > 0)
				leftState[0] = 1;
			
			if((mask & 2) > 0)
				leftState[1] = 1;
			
			if((mask & 4) > 0)
				leftState[2] = 1;
			
			return new ConnectedComponent(1, leftState, rightState);
			




































		}
	}

	static class SegmentTreeGeneric<T> {
		BiFunction<T, T, T> function;
		

		int n;
		T[] tree;
		

		public SegmentTreeGeneric(BiFunction<T, T, T> function, T[] arr){	
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
			

			

			int treeIdxLeftMid = treeIdx<<1;
			int treeIdxMidRight = (treeIdx<<1)+1;
			build(arr, treeIdxLeftMid, left, mid);
			build(arr, treeIdxMidRight, mid+1, right);
			tree[treeIdx] = function.apply(tree[treeIdxLeftMid], tree[treeIdxMidRight]);
		}

		public void update(int idx, T val){
			update(idx+1, val, 1, 1, n);
			

		}

		private T update(int idx, T val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];

			

			if(left == right){
				tree[treeIdx] = val;
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
		int[] parents;
		int numComponents;
		
		public DSU(int max) {
			parents = new int[max];
			size = new int[max];
			numComponents = 0;
		}
		
		public void put(int v) {
			if(size[v] > 0)
				return;
			parents[v] = -1;
			size[v] = 1;
			numComponents++;
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
			numComponents--;
		}
		public int find(int v) {
			if(parents[v] == -1)
				return v;
			int head = find(parents[v]);
			parents[v] = head;
			return head;
		}
		public int numCC() {
			return numComponents;
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
