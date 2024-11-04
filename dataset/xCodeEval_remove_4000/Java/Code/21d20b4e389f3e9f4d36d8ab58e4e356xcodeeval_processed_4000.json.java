import java.util.*;
import java.util.function.*;
import java.io.*;



public class id4 {	
	id5 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id11 = "id11";
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


		
		id4 sol = new id4();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id2 = false;
		
		initIO(id8);
	
		int t = id2? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	ans = solve();
	    	
	    	printOutput();
	    }
	    
	    in.close();
	    out.close();
	}
	
	int n, k, f;
	void getInput() {
		n = in.nextInt(); 
		k = in.nextInt();
		f = in.nextInt();
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	static final long MOD = 998244353;
	int ans;
	int solve(){
		long ans = 0;
		
		

		

		

		
		

		

		

		
		

		

		


		

		

		

		

		
		

		

		


		
		

		

		

		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		
		

		

		

		

		

		

		

		

		
		

		

		
		

		

		

		

		
		

		

		
		

		int len = 1;
		while (len < f+2 + f+2) 
	        len <<= 1;
		long[] ways = new long[len];
		long[] suffix = new long[f+2];
		
		for(int i=0; i<=k && i<=f; i++)
			ways[i] = 1;
		ways[f+1] = Math.max(0, k-f);
		


		
		for(int i=0; i<n; i++) {
			if(i < n-1) {
				square(ways);
				{
					long val = 0;
					for(int j=ways.length-1; j>=f+1; j--)
						val += ways[j];
					val %= MOD;
					suffix[f+1] = val;
				}
				for(int j=f; j>=0; j--){
					long val = suffix[j+1] + ways[j];
					val = val>=MOD? val-MOD: val;
					suffix[j] = val;
				}
			
				for(int j=0; j <= k && j<=f; j++) {
					long val = suffix[j]; 

					val += ways[j]*(k-j); 

					val %= MOD;
					ways[j] = val;
				}
				{
					long val = suffix[f+1]*Math.max(0, k-f);
					val %= MOD;
					ways[f+1] = val;
				}
				for(int j=k+1; j<f+2; j++)
					ways[j] = 0;
				Arrays.fill(ways, f+2, ways.length, 0);
				






























































			}
			else {
				for(int j=0; j<=f; j++)
					ans += ways[j]*ways[f-j] % MOD;
				ans %= MOD;
			}
		}
		
		return (int)ans;
	}
	
	static long pow(int a, int k, long p) {
		long m = k;
		long ans = 1;

		

		long curr = a;

		

		while(m > 0) {
			if( (m&1) == 1 ) {
				ans *= curr;
				ans %= p;
			}
			m >>= 1;
			curr *= curr;
			curr %= p;
		}
		return ans;		
	}
	
	

	static long inverse(int a, long p) {
		return pow(a, (int)(p-2), p);
	}
	
	

	

	

	static final int ROOT = (int) pow(3, 7*17, MOD);
	static final int ROOT_INV = (int) pow(ROOT, (int)MOD - 2, MOD);
	static final int ORDER = 1 << 23;

	static void swap(long[] a, int i, int j) {
		long temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	static void fft(long[] a, boolean id0) {
	    int n = a.length;

	    for (int i = 1, j = 0; i < n; i++) {
	        int bit = n >> 1;
	        for (; (j & bit) > 0; bit >>= 1)
	            j ^= bit;
	        j ^= bit;

	        if (i < j) {
	        	swap(a, i, j);
	        }
	    }

	    for (int len = 2; len <= n; len <<= 1) {
	        long wlen = id0 ? ROOT_INV : ROOT;
	        for (int i = len; i < ORDER; i <<= 1)
	            wlen = wlen * wlen % MOD;

	        for (int i = 0; i < n; i += len) {
	        	long w = 1;
	            for (int j = 0; j < len / 2; j++) {
	                long u = a[i+j];
	                long v = a[i+j+len/2] * w % MOD;
	                a[i+j] =  u + v < MOD ? u + v : u + v - MOD;
	                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
	                w = w * wlen % MOD;
	            }
	        }
	    }

	    if (id0) {
	        long inv = inverse(n, MOD);
	        for(int i=0; i<a.length; i++)
	        	a[i] = a[i]*inv%MOD;
	    }
	}
	
	static void square(long[] a) {
	    fft(a, false);
	    for (int i = 0; i < a.length; i++)
	        a[i] = a[i]*a[i] % MOD;
	    fft(a, true);
	}
	
	static long[] multiplyPolynomial(long[] a, long[] b) {
	    int n = 1;
	    while (n < a.length + b.length) 
	        n <<= 1;
		long[] fa = Arrays.copyOf(a, n);
		long[] fb = Arrays.copyOf(b, n);

	    fft(fa, false);
	    fft(fb, false);
	    for (int i = 0; i < n; i++)
	        fa[i] = fa[i]*fb[i] % MOD;
	    fft(fa, true);
	    
	    return fa;
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
		
		int[][] id6(int n, int offset){
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

		int[][] id10(){
			return id10(0);
		}
		
		int[][] id10(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
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
		
		long[] id15(int len) {
			return id15(len, 0);
		}
		long[] id15(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
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
