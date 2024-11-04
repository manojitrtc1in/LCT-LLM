import java.util.*;
import java.util.function.*;
import java.io.*;



public class id3 {	
	id4 out;
	MyScanner in;
	








	final static String id8 = "id8";
	final static String id10 = "id10";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id7) {
        if (System.getProperty("ONLINE_JUDGE") == null && id7) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id4(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id4(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id3 sol = new id3();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id7 = true;
		boolean id1 = true;
		
		initIO(id7);
		
		

	
		int t = id1? in.nextInt() : 1;
	    
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
	
	private void test() {
		final int n = 7;
		Random rand = new Random();
		for(int t = 0; true; t++) {
			this.n = n;
			a = new int[n];
			k = rand.nextInt(n)+1;
			for(int i=0; i<n; i++)
				

				a[i] = rand.nextInt(10)+1;
			
			int ori_k = k;
			int[] ori_a = Arrays.copyOf(a, n);
			
			solve();
			
			a = Arrays.copyOf(ori_a, n);
			k = ori_k;
			
			int expected = 0;
			int fac = 1;
			for(int i=1; i<=n; i++)
				fac *= i;
			int[] p = randomPermutation(0, n-1);
			int[] maxA = null;
			for(int tt = 0; tt<fac; tt++) {
				a = Arrays.copyOf(ori_a, n);
				for(int kk=k-1; kk>=0; kk--)
					a[p[kk]] = MAX;
				int min = Arrays.stream(a).min().getAsInt();
				for(int i=0; i<n-1; i++) {
					int curr = Math.min(Math.min(a[i], a[i+1]), 2*min);
					if(curr > expected) {
						expected = curr;
						maxA = a;
					}
				}
				
				nextPermutation(p);
			}
			
			if(ans != expected) {
				a = Arrays.copyOf(ori_a, n);
				solve();
				a = Arrays.copyOf(ori_a, n);
				solve();
				

				

				

				

			}
		}
		
	}
	
	private int[] randomPermutation(int start, int end) {
		int n = end-start+1;
		Random r = new Random();
		int[] a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = i+start;
		for(int i=1; i<n; i++) {
			int j = r.nextInt(n-i);
			int temp = a[n-i];
			a[n-i] = a[j];
			a[j] = temp;
		}
		return a;
	}
	
	public static void nextPermutation(int[] a) {
		int left;
		int n = a.length;
		for (left = n-2; left >= 0 && a[left] >= a[left+1]; left--);
		

		if (left == -1)
			reverse(a, 0, n-1);
		else {
			for (int i = n-1; i>=0; i--)
				if (a[i] > a[left]) {
					int temp = a[i];
					a[i] = a[left];
					a[left] = temp;
					break;
				}
			reverse(a, left+1, n-1);
		}
	}
	
	public static void reverse(int[] a, int left, int right) {
		int i = left;
		int j = right;
		while(i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	

	int n, k;
	int[] a;
	void getInput() {
		n = in.nextInt();
		k = in.nextInt();
		a = in.id6(n);
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}

	int ans;
	void solve2() {
		

		
		

		
		

		
	}
	
	void solve(){
		

		
		

		
		

		

		
		

		

		
		

		

		
		

		

		

		
		

		

		

		
		
		

		
		
		

		

		

		

		


		Integer[] sortedIndex = new Integer[n];
		for(int i=0; i<n; i++)
			sortedIndex[i] = i;
		
		Arrays.sort(sortedIndex, (i, j) -> Integer.compare(a[i], a[j]));
		
		for(int i=0; i<k-1; i++)
			a[sortedIndex[i]] = MAX;
		
		TreeMap<Integer, HashSet<Integer>> wAdj = new TreeMap<>();
		TreeMap<Integer, HashSet<Integer>> arr = new TreeMap<>();
		for(int i=0; i<n-1; i++) {
			if(a[i] <= a[i+1])
				insert(wAdj, a[i], i);
			if(a[i+1] <= a[i])
				insert(wAdj, a[i+1], i+1);
		}
		for(int i=0; i<n; i++)
			insert(arr, a[i], i);
		
		ans = 0;
		if(k > 0) {
			int index;
			if(wAdj.lastKey() < arr.firstKey()*2) {
				

				index = -1;
				int threshold = arr.firstKey()*2;
				threshold = Math.min(arr.lastKey(), threshold);
				for(int i=0; i<n; i++) {
					if(i > 0 && a[i-1] >= threshold) {
						if(index == -1 || a[index] > a[i])
							index = i;
					}
					if(i < n-1 && a[i+1] >= threshold) {
						if(index == -1 || a[index] > a[i])
							index = i;
					}
				}
			}
			else {
				index = arr.firstEntry().getValue().iterator().next();
			}
			update(arr, wAdj, index, MAX);
			
















			




































































			
		}












		ans = Math.min(wAdj.lastKey(), arr.firstKey()*2);
		
		


















































































	}
	final int MAX = 1_000_000_000;
	
	private void update(TreeMap<Integer, HashSet<Integer>> arr, TreeMap<Integer, HashSet<Integer>> wAdj, int index, int val) {
		delete(arr, a[index], index);
		delete(wAdj, a[index], index);
		if(index < n-1)
			delete(wAdj, a[index+1], index+1);
		if(index > 0)
			delete(wAdj, a[index-1], index-1);
		a[index] = val;
		insert(arr, a[index], index);
		if(index < n-1 && a[index] <= a[index+1])
			insert(wAdj, a[index], index);
		if(index < n-2 && a[index+1] <= a[index+2])
			insert(wAdj, a[index+1], index+1);
		if(index < n-1 && a[index+1] <= a[index])
			insert(wAdj, a[index+1], index+1);
		if(index > 0 && a[index] <= a[index-1])
			insert(wAdj, a[index], index);
		if(index > 0 && a[index-1] <= a[index])
			insert(wAdj, a[index-1], index-1);
		if(index > 1 && a[index-1] <= a[index-2])
			insert(wAdj, a[index-1], index-1);	








	}

	void insert(TreeMap<Integer, HashSet<Integer>> cnt, int val, int index) {
		if(!cnt.containsKey(val))
			cnt.put(val, new HashSet<>());
		cnt.get(val).add(index);
	}
	void delete(TreeMap<Integer, HashSet<Integer>> cnt, int val, int index) {
		if(cnt.containsKey(val)) {
			var set = cnt.get(val);
			set.remove(index);
			if(set.size() == 0)
				cnt.remove(val);
		}
	}
	 




	
	static class Pair implements Comparable<Pair>{
		final static long id5 = System.currentTimeMillis();
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
			x += id5;
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
		
		int[][] id9(int n, int m){
			return id9(n, m, 0);
		}
		
		int[][] id9(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id6(int len) {
			return id6(len, 0);
		}
		int[] id6(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id15(int len) {
			return id15(len, 0);
		}
		long[] id15(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id13(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id4 extends PrintWriter{
		public id4(OutputStream os) {
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
		
		public void id0(long[] arr, int split){
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
		
		public void id0(int[] arr, int split){
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
		
		public <T> void id0(ArrayList<T> arr, int split){
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
	
	static private void id14(long[] a) {
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
	
	static private void id14(int[] a) {
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
	
	static private int[][][] id12(int n, int[][] e){
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
		id11(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id11(int[][] e) {
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
	
	static private void id2(int[][] e) {
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
