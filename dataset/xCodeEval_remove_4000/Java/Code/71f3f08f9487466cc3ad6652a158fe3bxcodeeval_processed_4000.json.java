import java.util.*;
import java.util.function.*;
import java.io.*;
import java.nio.channels.UnsupportedAddressTypeException;



public class id17 {	
	id5 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id12 = "id12";
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



		

		

		

		

		
		id17 sol = new id17();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id3 = true;
		
		initIO(id8);
		
		

	
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
	
	

	int n, m;
	long[] a;
	int[] l, r;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.id22(n);
		int[][] lr = in.id11(m, 2);
		l = lr[0];
		r = lr[1];
	}
	
	static class Result{
		long val;
		public Result() {
			
		}
		public Result(long ans) {
			this.val = ans;
		}
		public void print(id5 out) {
			out.printlnAns(val);
		}
		@Override
		public boolean equals(Object obj) {
			Result other = (Result) obj;
			return val == other.val;
		}
		@Override
		public String toString() {
			return String.format("[%d]", val);
		}
	}
	
	Result solve(){
		

		

		
		

		
		

		

		
		

		

		

		

		

		
		

		
		

		
		

		

		

		

		

		

		
		

		
		

		

		

		

		

		
		

		

		

		
		

		

		
		final long INF = 1_000_000_000_000L;
		long[] a = Arrays.copyOf(this.a, n+2);
		a[n] = -INF;
		a[n+1] = INF;
		int n = this.n + 2;
		sort(a);
		
		ArrayList<id19> intervals = new ArrayList<>();
		for(int i=0; i<m; i++) {
			int index = Arrays.binarySearch(a, l[i]);
			boolean zero;
			if(index >= 0)
				zero = true;
			else if(-index-1 == n)
				zero = false;
			else{
				long ceil = a[-index-1];
				if(ceil <= r[i])
					zero = true;
				else
					zero = false;
			}
			if(!zero) {
				intervals.add(new id19(l[i], r[i]));
			}
		}
		Collections.sort(intervals, (e, f) -> Integer.compare(e.second, f.second));
		int len = intervals.size();
		
		ArrayList<LLPair>[] dp = new ArrayList[2];
		ArrayList<LLPair>[] dp2 = new ArrayList[2];
		dp[0] = new ArrayList<LLPair>();
		dp2[0] = new ArrayList<LLPair>();
		dp[0].add(new LLPair(0, 0));
		dp2[0].add(new LLPair(0, 0));
		int index = 0;
		long ans = 0;
		for(int i=0; i<n-1; i++) {
			long x = a[i];
			long y = a[i+1];
			dp[1] = new ArrayList<LLPair>();
			dp2[1] = new ArrayList<LLPair>();
			int k = dp[0].size();
			long[] id23 = new long[k+1];
			long[] suffixMin = new long[k+1];
			id23[0] = INF;
			for(int j=1; j<=k; j++)
				id23[j] = Math.min(id23[j-1], dp2[0].get(j-1).first);
			suffixMin[k] = INF;
			for(int j=k-1; j>=0; j--)
				suffixMin[j] = Math.min(suffixMin[j+1], dp[0].get(j).first);
			int kIndex = 0;
			long lastOpen = x;


			boolean exists = false;
			while(index < len) {
				var curr = intervals.get(index);
				if(curr.first > x && curr.first < y) {
					exists = true;


					while(kIndex < k){
						if(lastOpen - x >= dp[0].get(kIndex).second)
							kIndex++;
						else
							break;
					}
					

					

					long val;
					if(kIndex == 0)
						val = suffixMin[0] + (lastOpen-x)*2;
					else if(kIndex < k)
						val = Math.min(suffixMin[kIndex] + (lastOpen-x)*2, id23[kIndex] + (lastOpen-x));
					else
						val = id23[k] + (lastOpen-x);
					lastOpen = Math.max(lastOpen, curr.first);
					id16(dp[1], val+y-curr.second, y-curr.second);
					id16(dp2[1], val+(y-curr.second)*2, y-curr.second);
					index++;
				}
				else {
					break;
				}
			}
			if(exists)
			{
				while(kIndex < k){
					if(lastOpen - x >= dp[0].get(kIndex).second)
						kIndex++;
					else
						break;
				}
				

				long val;
				if(kIndex == 0)
					val = suffixMin[0] + (lastOpen-x)*2;
				else if(kIndex < k)
					val = Math.min(suffixMin[kIndex] + (lastOpen-x)*2, id23[kIndex] + (lastOpen-x));
				else
					val = id23[k] + (lastOpen-x);
				id16(dp[1], val, 0);
				id16(dp2[1], val, 0);
				Collections.reverse(dp[1]);
				Collections.reverse(dp2[1]);
			}
			else {
				ans += suffixMin[0];
				dp[1].add(new LLPair(0, 0));
				dp2[1].add(new LLPair(0, 0));
			}












			dp[0] = dp[1];
			dp2[0] = dp2[1];
			dp[1] = null;
			dp2[1] = null;
		}
		
		long min = INF;
		for(var p: dp[0])
			min = Math.min(p.first, min);
		for(var p: dp2[0])
			min = Math.min(p.first, min);
		ans += min;
		return new Result(ans);
	}
	
	
	private void id16(ArrayList<LLPair> list, long f, long s) {
		int lastIndex = list.size()-1;
		if(list.isEmpty() || list.get(lastIndex).second != s) {
			list.add(new LLPair(f, s));
		}
		else{
			list.get(lastIndex).first = Math.min(list.get(lastIndex).first, f);
		}
	}

	class EndPoint{
		int x;
		IntervalType t;
		public EndPoint(int x, IntervalType t) {
			this.x = x;
			this.t = t;
		}
	}
	
	enum IntervalType{
		OPEN, CLOSE;
	}
	




	
	void verify() {
		Random rand = new Random();
		final int MIN = -1000;
		final int MAX = 1000;
		for(int t=0; t<1_000_000; t++) {
			n = 3;
			m = 100;
			a = new long[n];
			a[0] = -100;
			a[1] = 0;
			a[2] = 100;
			l = new int[m];
			r = new int[m];
			for(int i=0; i<m; i++) {
				l[i] = rand.nextInt(MAX-MIN) + MIN;
				r[i] = rand.nextInt(MAX-l[i]) + l[i];
			}
			Result ans = solve();
			Result expected = id14();
			if(!ans.equals(expected)) {
				solve();
			}
		}
	}
	
	Result id14() {
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
	
	final static long id6 = System.currentTimeMillis();
	static int id2(long x) {
		

		x += id6;
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
	
	static class id10 implements Comparable<id10>{
		long first;
		int second;
		public id10(long first, int second) {
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
			id10 other = (id10) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id10 o) {
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
		
		int[][] id11(int n, int m){
			return id11(n, m, 0);
		}
		
		int[][] id11(int n, int m, int offset){
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
		
		long[] id22(int len) {
			return id22(len, 0);
		}
		long[] id22(int len, int offset){
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
	
	static private int[][][] id15(int n, int[][] e){
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
		id13(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id13(int[][] e) {
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
	
	static private void id4(int[][] e) {
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
