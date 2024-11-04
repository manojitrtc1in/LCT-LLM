import java.util.*;
import java.util.function.*;
import java.io.*;



public class id22 {	
	id8 out;
	MyScanner in;
	








	final static String id12 = "id12";
	final static String id14 = "id14";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id11) {
        if (System.getProperty("ONLINE_JUDGE") == null && id11) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id8(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id8(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){



		

		

		

		

		
		id22 sol = new id22();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id11 = true;
		boolean id5 = true;
		
		initIO(id11);
	
		int t = id5? in.nextInt() : 1;
	    
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
	
	

	int s, n;
	void getInput() {
		s = in.nextInt();
		n = in.nextInt(); 
	}
	
	static class Result{
		int[] arr;
		public Result() {
			
		}
		public Result(int[] ans) {
			this.arr = ans;
		}
		public void print(id8 out) {
			out.printlnAns(arr);
		}


















	}
	
	Result solve(){
		

		
		

		

		

		id18 arr = new id18();
		int pow = 1_000_000_000;
		while(pow > 0) {
			while(s >= pow) {
				arr.add(pow);
				s -= pow;
			}
			pow /= 10;
		}
		int[] ans = new int[n];
		if(arr.size() < n) {
			TreeMap<Integer, Integer> values = new TreeMap<>();
			for(int i=0; i<arr.size(); i++)
				values.merge(arr.get(i), 1, (x, y) -> x+y);
			
			int cnt = arr.size();
			while(cnt < n) {
				int curr = values.ceilingKey(10);
				int val = values.get(curr) - 1;
				if(val == 0)
					values.remove(curr);
				else
					values.put(curr, val);
				cnt += 9;
				values.merge(curr/10, 10, (x, y) -> x+y);
			}
			arr = new id18();
			for(var key: values.descendingKeySet()) {
				int val = values.get(key);
				for(int i=0; i<val; i++)
					arr.add(key);
			}
		}
		for(int i=0; i<n-1; i++)
			ans[i] = arr.get(i);
		for(int i=n-1; i<arr.size(); i++)
			ans[n-1] += arr.get(i);
		return new Result(ans);
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
	
	final static long id9 = System.currentTimeMillis();
	static int id4(long x) {
		

		x += id9;
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
			return id4(x);
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
	
	static class id13 implements Comparable<id13>{
		long first;
		int second;
		public id13(long first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id4(x);
		}
		@Override
		public boolean equals(Object obj) {
			id13 other = (id13) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id13 o) {
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
			return id4(x);
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
		
		int[][] id3(int numLine, int id7){
			return id3(numLine, id7, 0);
		}
		
		int[][] id3(int numLine, int id7, int offset){
			int[][] mat = new int[id7][numLine];
			for(int i=0; i<numLine; i++) {
				for(int j=0; j<id7; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id10(int len) {
			return id10(len, 0);
		}
		int[] id10(int len, int offset){
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
	
	public static class id8 extends PrintWriter{
		public id8(OutputStream os) {
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
		id8 out2 = null;
		 try {
			out2 = new id8(new FileOutputStream("graph.dot"));
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
	
	static private void id6(int[][] e) {
		id8 out2 = null;
		 try {
			out2 = new id8(new FileOutputStream("graph.dot"));
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
