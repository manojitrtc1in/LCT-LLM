import java.util.*;
import java.util.function.*;
import java.io.*;



public class id22 {	
	id6 out;
	MyScanner in;
	








	final static String id11 = "id11";
	final static String id14 = "id14";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id10) {
        if (System.getProperty("ONLINE_JUDGE") == null && id10) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id6(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id6(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){



		

		

		

		

		
		id22 sol = new id22();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id10 = true;
		boolean id3 = true;
		
		initIO(id10);
	
		int t = id3? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	Result ans = solve();
	    	
	    	ans.print(out);
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	int n;
	int[] u, v;
	final int ROOT = 0;
	void getInput() {
		n = in.nextInt();
		int[][] uv = in.id13(n-1, 2, -1);
		u = uv[0];
		v = uv[1];
	}
	
	static class Result{
		int val;
		public Result() {
			
		}
		public Result(int ans) {
			this.val = ans;
		}
		public void print(id6 out) {
			out.printlnAns(val);
		}


















	}
	
	Result solve(){
		

		

		

		

		

		

		

		

		

		

		
		

		

		

		

		

		

		

		

		
		

		

		
		neighbors = new id18[n];
		for(int i=0; i<n; i++)
			neighbors[i] = new id18();
		for(int i=0; i<n-1; i++) {
			neighbors[u[i]].add(v[i]);
			neighbors[v[i]].add(u[i]);
		}

		parent = new int[n];
		numChildren = new int[n];
		id5 = new int[n];
		numLeaves = 0;
		dfs(ROOT, -1);
		
		int id7 = 0;
		ArrayDeque<Integer> queue = new ArrayDeque<>();
		for(int i=1; i<n; i++) {
			if(numChildren[i] > 0 && numChildren[i] == id5[i]) {
				id7++;
				queue.add(i);
			}
		}
		if(queue.isEmpty())
			return new Result(numLeaves);
		




































		
		while(!queue.isEmpty()) {
			int v = queue.pollFirst();
			numLeaves--;
			
			int p = parent[v];
			if(p == ROOT)
				continue;
			numChildren[p]--;
			if(numChildren[p] > 0) {
				if(numChildren[p] == id5[p]) {
					id7++;
					queue.add(p);
				}
				continue;
			}
			int pp = parent[p];
			numLeaves++;
			id5[pp]++;
			if(pp == ROOT)
				continue;
			if(numChildren[pp] == id5[pp]) {
				id7++;
				queue.add(pp);
			}
		}
		
		for(int i=1; i<n; i++) {
			if(numChildren[i] == 0 && parent[i] == ROOT) {
				return new Result(numLeaves);
			}
		}
		return new Result(numLeaves+1);
	}
	
	int numLeaves;
	id18[] neighbors;
	int[] numChildren, id5, parent;
	
	void dfs(int v, int p) {
		parent[v] = p;
		for(int u: neighbors[v]) {
			if(u == p)
				continue;
			numChildren[v]++;
			if(neighbors[u].size == 1) {
				numLeaves++;
				id5[v]++;
			}
			dfs(u, v);
		}
	}
	
	




	
	void verify() {
		for(int t=0; t<1_000_000; t++) {
			Result ans = solve();
			Result expected = id16();
			if(ans.equals(expected)) {
				solve();
			}
		}
	}
	
	Result id16() {
		return new Result();
	}
	
	static class id18 implements Iterable<Integer>{
		private int[] data;
		private int capacity;
		private int size;
		public id18(int capacity) {
			this.capacity = capacity;
			data = new int[capacity];
			size = 0;
		}
		public id18() {
			this(1);
		}
		public void add(int val) {
			if(size == capacity) {
				capacity *= 2;
				data = Arrays.copyOf(data, capacity);
			}
			data[size++] = val;
		}
		public int pop() {
			return data[--size];
		}
		public int size() {
			return size;
		}
		public void set(int index, int val) {
			data[index] = val;
		}
		public int get(int index) {
			return data[index];
		}
		public int front() {
			return data[0];
		}
		public int back() {
			return data[size-1];
		}
		public int binarySearch(int val) {
			return Arrays.binarySearch(data, 0, size, val);
		}
		public int[] toArray() {
			return Arrays.copyOf(data, size);
		}
		public String toString() {
			return Arrays.toString(Arrays.copyOf(data, size));
		}
		@Override
		public Iterator<Integer> iterator() {
			return new id0();
		}
		
		class id0 implements Iterator<Integer> {
			private int index = 0;
	        public boolean hasNext() {
	            return index < size;
	        }
	        public Integer next() {
	        	return data[index++];
	        }
	        public void remove() {
	        	throw new UnsupportedOperationException();
	        }
		}
	}
	
	final static long id8 = System.currentTimeMillis();
	static int id2(long x) {
		

		x += id8;
		x += 0x9e3779b97f4a7c15l;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
		x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
		return (int)(x ^ (x >> 31));
	}
	
	static class LLPair implements Comparable<LLPair>{
		long first, second;
		public LLPair(long first, long second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id2(x);
		}
		@Override
		public boolean equals(Object obj) {
			LLPair other = (LLPair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(LLPair o) {
			int cmp = Long.compare(first, o.first);
			return cmp != 0? cmp: Long.compare(second, o.second);
		}
	}
	
	static class id12 implements Comparable<id12>{
		long first;
		int second;
		public id12(long first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id2(x);
		}
		@Override
		public boolean equals(Object obj) {
			id12 other = (id12) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id12 o) {
			int cmp = Long.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
		}
	}
	
	static class id19 implements Comparable<id19>{
		int first, second;
		public id19(int first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first << 32;
			x ^= second;
			return id2(x);
		}
		@Override
		public boolean equals(Object obj) {
			id19 other = (id19) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id19 o) {
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
		
		int[][] id13(int n, int m){
			return id13(n, m, 0);
		}
		
		int[][] id13(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id9(int len) {
			return id9(len, 0);
		}
		int[] id9(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id23(int len) {
			return id23(len, 0);
		}
		long[] id23(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id20(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id6 extends PrintWriter{
		public id6(OutputStream os) {
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
	
	static private void reverseSort(long[] a) {
		int n = a.length;
		Long[] b = new Long[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b, Collections.reverseOrder());
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void sort(long[] a) {
		int n = a.length;
		Long[] b = new Long[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b);
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void reverseSort(int[] a) {
		int n = a.length;
		Integer[] b = new Integer[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b, Collections.reverseOrder());
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void sort(int[] a) {
		int n = a.length;
		Integer[] b = new Integer[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b);
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void id21(long[] a) {
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
	
	static private void id21(int[] a) {
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
	
	static private int[][][] id17(int n, int[][] e){
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
		id15(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id15(int[][] e) {
		id6 out2 = null;
		 try {
			out2 = new id6(new FileOutputStream("graph.dot"));
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
	
	static private void id4(int[][] e) {
		id6 out2 = null;
		 try {
			out2 = new id6(new FileOutputStream("graph.dot"));
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
