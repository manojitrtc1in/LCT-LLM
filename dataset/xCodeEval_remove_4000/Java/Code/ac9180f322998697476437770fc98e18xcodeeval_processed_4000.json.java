import java.util.*;
import java.util.function.*;
import java.io.*;



public class id0 {	
	id5 out;
	MyScanner in;
	








	final static String id10 = "id10";
	final static String id11 = "id11";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id9) {
        if (System.getProperty("ONLINE_JUDGE") == null && id9) {
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
		boolean id9 = true;
		boolean id2 = true;
		
		initIO(id9);
	
		int t = id2? in.nextInt() : 1;
	    
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
	
	

	int m;
	int[][] a;
	void getInput() {
		m = in.nextInt();
		a = in.nextMatrix(2, m);
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	int ans;
	void solve(){
		

		

		

		

		int time = Math.max(0, Math.max(a[1][0], a[1][1]-1)) + 2;
		int[][] b = new int[2][m-1];
		for(int i=0; i<2; i++)
			for(int j=0; j<m-1; j++) {
				b[i][j] = Math.max(0, a[1-i][j+1] - time);
			}
		
		int even = solve(a, m);
		int odd = solve(b, m-1) + time;
		
		ans = Math.min(even, odd);
	}
	
	int solve(int[][] a, int m) {
		int[] arr = new int[m*2];
		int idx = 1;
		for(int j=1; j<m; j++) {
			arr[idx] = Math.max(0, a[0][j]-idx+1);
			idx++;
		}
		for(int j=m-1; j>=0; j--) {
			arr[idx] = Math.max(0, a[1][j]-idx+1);
			idx++;
		}
		
		SegmentTree id6 = new SegmentTree((x, y) -> Math.max(x, y), arr);
		int min = Math.max(0, id6.getRange(getIdx(0, 0, m), getIdx(1, 0, m)));
		min += m*2-1;
		int time = 0;
		int max = 0;
		idx = 0;
		for(int j=2; j<m; j+=2) {
			max = Math.max(max, a[1][j-2]-idx); idx++;
			max = Math.max(max, a[1][j-1]-idx); idx++;
			max = Math.max(max, a[0][j-1]-idx); idx++;
			max = Math.max(max, a[0][j]-idx); idx++;
			time = max + j*2;
			int val = Math.max(0, id6.getRange(getIdx(0, j+1, m), getIdx(1, j, m)));
			val += j;
			min = Math.min(min, Math.max(time, val) + (m-j)*2 -1);
		}
		
		return min;
	}
	
	int getIdx(int i, int j, int m) {
		if(i == 0)
			return j;
		else
			return m + (m-1-j);
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




			int id4 = treeIdx<<1;
			int id14 = (treeIdx<<1)+1;
			build(arr, id4, left, mid);
			build(arr, id14, mid+1, right);
			tree[treeIdx] = function.apply(tree[id4], tree[id14]);
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
	
	static class Pair implements Comparable<Pair>{
		final static long id7 = System.currentTimeMillis();
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
			x += id7;
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
		
		int[] id8(int len) {
			return id8(len, 0);
		}
		int[] id8(int len, int offset){
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
		
		String[] id15(int len) {
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
