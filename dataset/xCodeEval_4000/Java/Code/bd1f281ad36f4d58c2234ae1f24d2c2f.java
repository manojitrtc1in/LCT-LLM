import java.util.*;
import java.util.function.*;
import java.io.*;



public class Round816C {	
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


		
		Round816C sol = new Round816C();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = false;
		
		initIO(isFileIO);
		
		

	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
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
	
	void test() {
		n = 5;
		m = 100;
		final int MAX = 10;
		

		Random rand = new Random();
		
		for(int t=0; t<100; t++) {
			a = new int[n];
			for(int i=0; i<n; i++)
				a[i] = rand.nextInt(MAX) + 1;
			int[] ori_a = Arrays.copyOf(a, n); 
			index = new int[m];
			x = new int[m];
			for(int i=0; i<m; i++) {
				index[i] = rand.nextInt(n);
				x[i] = rand.nextInt(MAX)+1;
			}
			solve();
			long[] expected = new long[m];
			a = Arrays.copyOf(ori_a, n);
			for(int q=0; q<m; q++) {
				a[index[q]] = x[q];
				for(int l=0; l<n; l++) {
					for(int r=l; r<n; r++) {
						int start = l;
						while(start <= r) {
							int end = start;
							while(end <= r && a[start] == a[end])
								end++;
							expected[q] ++;
							end--;
							start = end+1;
						}
					}
				}
			}
			if(!Arrays.equals(expected, ans)) {
				a = Arrays.copyOf(ori_a, n);
				solve();
			}
		}
	}
	
	

	int n, m;
	int[] a;
	int[] index;
	int[] x;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.nextIntArray(n);
		index = new int[m];
		x = new int[m];
		for(int i=0; i<m; i++) {
			index[i] = in.nextInt()-1;
			x[i] = in.nextInt();
		}
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}

	long[] ans;
	void solve(){
		

		

		

		

		

		
		TreeSet<Interval> intervals = new TreeSet<>();
		{
			int start = 0;
			while(start < n) {
				int end = start;
				while(end < n && a[start] == a[end])
					end++;
				end--;
				intervals.add(new Interval(start, end));
				start = end+1;
			}
		}
		
		{
			long prefix = 0;
			for(Interval interval: intervals) {
				interval.prefix = prefix;
				prefix += interval.second - interval.first + 1;
			}
		}
		{
			long suffix = 0;
			var iter = intervals.descendingIterator();
			while(iter.hasNext()) {
				var interval = iter.next();
				interval.suffix = suffix;
				suffix += interval.second - interval.first + 1;
			}
		}
		
		long curr = 0;
		for(Interval interval: intervals) {
			curr += interval.count();
		}
		
		

		

		

		ans = new long[m];
		for(int i=0; i<m; i++) {
			Interval toChange = new Interval(index[i], n);
			Interval interval = intervals.floor(toChange);
			if(x[i] == a[index[i]]) {
				ans[i] = curr;
				continue;
			}
			intervals.remove(interval);
			curr -= interval.count();
			
			Interval prev = null;
			Interval next = null;

			if(interval.first == index[i])
				prev = intervals.lower(toChange);
			if(interval.second == index[i])
				next = intervals.higher(toChange);
			
			if(prev != null && next != null) { 

				if(a[prev.second] == x[i] && a[next.first] == x[i]) {
					curr -= prev.count();
					curr -= next.count();
					intervals.remove(next);
					prev.suffix = next.suffix;
					prev.second = next.second;
					curr += prev.count();
				}
				else if(a[prev.second] == x[i]) {
					curr -= prev.count();
					prev.second = index[i];
					prev.suffix--;
					curr += prev.count();
				}
				else if(a[next.first] == x[i]) {
					curr -= next.count();
					next.first = index[i];
					next.prefix--;
					curr += next.count();
				}
				else{
					intervals.add(interval);
					curr += interval.count();
				}
			}
			else if(prev != null) {
				interval.prefix++;
				interval.first = index[i]+1;
				if(interval.second >= interval.first) {
					intervals.add(interval);
					curr += interval.count();
				}
				if(a[prev.second] == x[i]) {
					curr -= prev.count();
					prev.second = index[i];
					prev.suffix--;
					curr += prev.count();
				}
				else {
					Interval single = new Interval(index[i], index[i]);
					single.prefix = interval.prefix - 1;
					single.suffix = prev.suffix - 1;
					intervals.add(single);
					curr += single.count();
				}
			}
			else if(next != null) {
				interval.suffix++;
				interval.second = index[i]-1;
				if(interval.second >= interval.first) {
					intervals.add(interval);
					curr += interval.count();
				}
				if(a[next.first] == x[i]) {
					curr -= next.count();
					next.first = index[i];
					next.prefix--;
					curr += next.count();
				}
				else{
					Interval single = new Interval(index[i], index[i]);
					single.suffix = interval.suffix - 1;
					single.prefix = next.prefix - 1;
					intervals.add(single);
					curr += single.count();
				}
			}
			else {
				

				Interval left = new Interval(interval.first, index[i]-1);
				Interval middle = new Interval(index[i], index[i]);
				Interval right = new Interval(index[i]+1, interval.second);
				if(interval.first <= index[i]-1) {
					left.prefix = interval.prefix;
					left.suffix = interval.suffix + (interval.second - index[i] + 1);
					intervals.add(left);
					curr += left.count();
				}
				{
					middle.prefix = interval.prefix + (index[i] - interval.first);
					middle.suffix = interval.suffix + (interval.second - index[i]);
					intervals.add(middle);
					curr += middle.count();
				}
				if(index[i]+1 <= interval.second) {
					right.prefix = interval.prefix + (index[i] - interval.first + 1);
					right.suffix = interval.suffix;
					intervals.add(right);
					curr += right.count();
				}
			}
			a[index[i]] = x[i];
			ans[i] = curr;
		}
	}
	 




	
	class Interval extends Pair{
		long prefix, suffix;
		public Interval(int first, int second) {
			super(first, second);
		}
		public long count() {
			long ret = 0;
			ret += prefix*suffix;
			long len = second - first + 1;
			ret += len*(n-len);
			ret += len*(len+1)/2;
			return ret;
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
