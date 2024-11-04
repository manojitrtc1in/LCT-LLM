import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundGlobal19E2 {	
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


		
		RoundGlobal19E2 sol = new RoundGlobal19E2();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);
	
		

		
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int m = in.nextInt();
	    	int[] a = in.nextIntArray(n);






	    	HashSet<Pair> bad = new HashSet<>();
	    	for(int j=0; j<m; j++)
	    		bad.add(new Pair(in.nextInt(), in.nextInt()));
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			long ans = solve(a, bad);
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {


		int k = 1_000;
		int n = k*(k+1)/2;
		int m = 1_000_000;
		int[] a = new int[n];
		Random r = new Random();
		
		int idx = 0;
		for(int i=k; i>=1; i--)
			for(int j=1; j<=i; j++)
				a[idx++] = j;




		
		int[] b = Arrays.copyOf(a, n);
		Arrays.sort(b);




		int[] x = new int[m];
		int[] y = new int[m];


		idx=0;
		for(int i=0; i<n && idx < m; i++) {
			for(int j=0; j<i && idx < m; j++) {
				x[idx] = b[n-1-i];
				y[idx] = b[n-1-j];
				idx++;
			}
		}
		long time = System.currentTimeMillis();
		solve(a, x, y);
		out.println(System.currentTimeMillis()-time);
		
		a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = r.nextInt(1_000_000_000)+1;
		x = new int[m];
		y = new int[m];
		b = Arrays.copyOf(a, n);
		Arrays.sort(b);
		idx=0;
		for(int i=0; i<n && idx < m; i++) {
			for(int j=0; j<i && idx < m; j++) {
				x[idx] = b[n-1-i];
				y[idx] = b[n-1-j];
				idx++;
			}
		}
		
		time = System.currentTimeMillis();
		solve(a, x, y);
		out.println(System.currentTimeMillis()-time);
		
		a = new int[n];
		for(int i=0; i<n/2; i++)
			a[i] = i+1;
		for(int j=1, i=n/2, l=j; i<n; i++, l--) {
			a[i] = n/2+j;
			if(l == 0) {
				l= ++j;
			}
		}
		
		time = System.currentTimeMillis();
		solve(a, new int[0], new int[0]);
		out.println(System.currentTimeMillis()-time);
		
		out.close();
		System.exit(0);
	}
	
	private long solve(int[] a, int[] x, int [] y) {
		int m = x.length;
		HashSet<Pair> bad = new HashSet<>();
		for(int i=0; i<m; i++)
			bad.add(new Pair(x[i], y[i]));
		return solve(a, bad);
	}

	private long solve(int[] a, HashSet<Pair> bad) {
		int n = a.length;
		
		
		permutateAndSort(a);
		
		elemCounts = new ArrayList<ElemCount>(); 
		int left = 0;
		while(left < n) {
			int right = left+1;
			while(right < n && a[left] == a[right])
				right++;
			elemCounts.add(new ElemCount(a[left], right-left));
			left = right;
		}
		













		
		Collections.sort(elemCounts);
		
		ArrayList<Integer> largests = new ArrayList<Integer>();



		long maxF = 0;
		int k = elemCounts.size();
		
		for(int i=0; i<k; i++) {
			for(int j=i-1; j>=0 && elemCounts.get(i).count == elemCounts.get(j).count; j--) {
				if(!bad.contains(new Pair(elemCounts.get(j).elem, elemCounts.get(i).elem))) {
					long f = elemCounts.get(j).count+elemCounts.get(i).count;
					f *= elemCounts.get(j).elem+elemCounts.get(i).elem;
					maxF = Math.max(maxF, f);
					break;
				}
			}
			for(int largest: largests) {
				for(int j=largest; j>=0 && elemCounts.get(largest).count == elemCounts.get(j).count; j--) {
					if(!bad.contains(new Pair(elemCounts.get(j).elem, elemCounts.get(i).elem))) {
						long f = elemCounts.get(j).count+elemCounts.get(i).count;
						f *= elemCounts.get(j).elem+elemCounts.get(i).elem;
						maxF = Math.max(maxF, f);
						break;
					}
				}
			}
			if(i+1<k && elemCounts.get(i).count != elemCounts.get(i+1).count)
				largests.add(i);
		}


		return maxF;
		















































































































	}
	
	ArrayList<ElemCount> elemCounts;
	
	class Pair{
		int x, y;

		public Pair(int x, int y) {
			if(x < y) {
				this.x = x;
				this.y = y;
			}
			else {
				this.x = y;
				this.y = x;
			}
		}

		@Override
		public int hashCode() {
			long z = x;
			z <<= 32;
			z |= y;
			z += 0x9e3779b97f4a7c15l;
			z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9l;
			z = (z ^ (z >> 27)) * 0x94d049bb133111ebl;
			return (int)(z ^ (z >> 31));
		}

		@Override
		public boolean equals(Object obj) {
			Pair other = (Pair) obj;
			return x == other.x && y == other.y;
		}
		
		public String toString() {
			return String.format("(%d,%d)", x, y);
		}
	}
	
	final static int prime = 307;
	class Candidate implements Comparable<Candidate>{
		int i, j;
		long fij;
		

		public Candidate(int i, int j) {
			this.i = i;
			this.j = j;
			fij = f(i, j);
		}
		private long f(int i, int j) {
			long val = elemCounts.get(i).elem+elemCounts.get(j).elem;
			val *= elemCounts.get(i).count+elemCounts.get(j).count;
			return val;
		}
		

		@Override
		public int compareTo(RoundGlobal19E2.Candidate o) {
			int cmp = Long.compare(o.fij, fij);
			return cmp != 0? cmp: Long.compare(pack(i, j), pack(o.i, o.j));
		}
		@Override
		public int hashCode() {
			return (prime*j)^i;
		}
		@Override
		public boolean equals(Object obj) {
			Candidate other = (Candidate) obj;
			return fij == other.fij && i == other.i && j == other.j;
		}
		public String toString() {
			return String.format("(%d, %d)->%d", i, j, fij);
		}
	}
	
	class ElemCount implements Comparable<ElemCount>{
		int elem;
		int count;
		public ElemCount(int elem, int count) {
			this.elem = elem;
			this.count = count;
		}
		@Override
		public int compareTo(RoundGlobal19E2.ElemCount o) {
			int cmp = Integer.compare(count, o.count);
			return cmp !=0? cmp: Integer.compare(elem, o.elem);
		}
		public String toString() {
			return String.format("[%d=%d]", elem, count);
		}
	}
	
	private Long pack(int i, int j) {
		long a, b;
		if(i<j) {
			a=i;
			b=j;
		}
		else {
			a=j;
			b=i;
		}
		return ((long)a<<32) + b;
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
