import java.util.*;
import java.util.function.*;
import java.io.*;



public class id3 {	
	id9 out;
	MyScanner in;
	








	final static String id13 = "id13";
	final static String id15 = "id15";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id12) {
        if (System.getProperty("ONLINE_JUDGE") == null && id12) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id9(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id9(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){



		

		

		

		

		
		id3 sol = new id3();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id12 = true;
		boolean id6 = true;
		
		initIO(id12);
	
		int t = id6? in.nextInt() : 1;
	    
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
	void getInput() {
		n = in.nextInt(); 
	}
	
	static class Result{
		String val;
		public Result() {
			
		}
		public Result(String ans) {
			this.val = ans;
		}
		public void print(id9 out) {
			out.println(val);
		}


















	}
	
	Result solve(){
		

		
		

		
		

		
		

		
		

		
		

		
		

		
		

		
		

		
		

		
		

		
		

		

		

		
		

		
		

		

		

		
		if(n == 1)
			return new Result("a");
		
		int k = n/2;
		
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<k; i++)
			sb.append('a');
		
		if(n % 2 == 0)
			sb.append('b');
		else
			sb.append("bc");
		
		for(int i=0; i<k-1; i++)
			sb.append('a');
		
		return new Result(sb.toString());
	}
	




	
	void verify() {
		for(int t=0; t<1_000_000; t++) {
			Result ans = solve();
			Result expected = id17();
			if(ans.equals(expected)) {
				solve();
			}
		}
	}
	
	Result id17() {
		return new Result();
	}
	
	static class id19 implements Iterable<Integer>{
		private int[] data;
		private int capacity;
		private int size;
		public id19(int capacity) {
			this.capacity = capacity;
			data = new int[capacity];
			size = 0;
		}
		public id19() {
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
			return new id1();
		}
		
		class id1 implements Iterator<Integer> {
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
	
	final static long id10 = System.currentTimeMillis();
	static int id5(long x) {
		

		x += id10;
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
			return id5(x);
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
	
	static class id14 implements Comparable<id14>{
		long first;
		int second;
		public id14(long first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id5(x);
		}
		@Override
		public boolean equals(Object obj) {
			id14 other = (id14) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id14 o) {
			int cmp = Long.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
		}
	}
	
	static class id20 implements Comparable<id20>{
		int first, second;
		public id20(int first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first << 32;
			x ^= second;
			return id5(x);
		}
		@Override
		public boolean equals(Object obj) {
			id20 other = (id20) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id20 o) {
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
		
		int[][] id0(int numRow, int numCol) {
			return id0(numRow, numCol, 0);
		}
		
		int[][] id0(int numRow, int numCol, int offset) {
			int[][] mat = new int[numRow][numCol];
			for(int i=0; i<numRow; i++) {
				for(int j=0; j<numCol; j++) {
					mat[i][j] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[][] id4(int numLine, int id8){
			return id4(numLine, id8, 0);
		}
		
		int[][] id4(int numLine, int id8, int offset){
			int[][] mat = new int[id8][numLine];
			for(int i=0; i<numLine; i++) {
				for(int j=0; j<id8; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id11(int len) {
			return id11(len, 0);
		}
		int[] id11(int len, int offset){
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
		
		String[] id21(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id9 extends PrintWriter{
		public id9(OutputStream os) {
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
		
		public void id2(long[] arr, int split){
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
		
		public void id2(int[] arr, int split){
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
		
		public <T> void id2(ArrayList<T> arr, int split){
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
	
	static private void id22(long[] a) {
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
	
	static private void id22(int[] a) {
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
	
	static private int[][][] id18(int n, int[][] e){
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
		id16(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id16(int[][] e) {
		id9 out2 = null;
		 try {
			out2 = new id9(new FileOutputStream("graph.dot"));
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
	
	static private void id7(int[][] e) {
		id9 out2 = null;
		 try {
			out2 = new id9(new FileOutputStream("graph.dot"));
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
