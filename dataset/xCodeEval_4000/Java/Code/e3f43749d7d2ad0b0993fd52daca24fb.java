import java.util.*;
import java.io.*;
import java.math.BigInteger;



public class Round791F {
	MyPrintWriter out;
	MyScanner in;
	








	final static String IMPOSSIBLE = "IMPOSSIBLE";
	final static String POSSIBLE = "POSSIBLE";
	final static String YES = "YES";
	final static String NO = "NO";
	final static long MOD = 998244353;
	
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


		
		Round791F sol = new Round791F();
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
	    	int m = in.nextInt();
	    	int[][] uv = in.nextPairs(m);
	    	int[] u = uv[0];
	    	int[] v = uv[1];
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			long ans = solve2(u, v, n);
			out.println(ans);
			
			

			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	private void validate(int[] u, int[] v, int n) {
		TreeSet<String> set = new TreeSet<>();
		int[][] cmp = new int[RADIX][RADIX];
		for(int i=0; i<RADIX; i++) {
			for(int j=0; j<RADIX; j++) {
				cmp[i][j] = 0;
			}
		}
		for(int i=0; i<u.length; i++) {
			int small = Math.min(u[i], v[i]);
			int large = Math.max(u[i], v[i]);
			cmp[small][large] = -1;
			cmp[large][small] = 1;
		}




















		
		Comparator<Character> comp = new Comparator<Character>() {
			@Override
			public int compare(Character o1, Character o2) {
				return cmp[o1-'0'][o2-'0'];
			}
		};
		
		BigInteger curr = BigInteger.ZERO;
		BigInteger limit = BigInteger.valueOf(RADIX).pow(n);
		StringBuilder sb = new StringBuilder();
		while(curr.compareTo(limit) < 0) {
			String s = curr.toString(RADIX);
			int padding = n-s.length();
			sb.setLength(0);
			for(int i=0; i<padding; i++)
				sb.append('0');
			sb.append(s);
			Character[] arr = new Character[n];
			for(int i=0; i<n; i++)
				arr[i] = sb.charAt(i);
			 Arrays.sort(arr, comp);
			

			




























			
			sb.setLength(0);


			for(int i=0; i<n; i++)
				sb.append(arr[i]);
			set.add(sb.toString());
			curr = curr.add(BigInteger.ONE);
		}
		out.println(set.size());
		out.println(set);
		
		
		

		

		

		

		
		


        

		

		

		

		

		

		

		

		

		

		

		

		


		

		

	}

	final int RADIX = 10;
	private long solve2(int[] u, int[] v, int n) {
		
		

		

		

		

		long[] dp = new long[1<<RADIX];
		
		for(int j=0; j<RADIX; j++) {
			dp[1<<j] = 1;
		}
		
		int[][] cmp = new int[RADIX][RADIX];
		int m = u.length;
		for(int i=0; i<m; i++) {
			int small = Math.min(u[i], v[i]);
			int larger = Math.max(u[i], v[i]);
			cmp[small][larger] = -1;
			cmp[larger][small] = 1;
		}
		
		boolean[][] isValid = new boolean[1<<RADIX][RADIX];
		int[][] map = new int[1<<RADIX][RADIX];
		
		for(int mask=0; mask< 1<<RADIX; mask++) {
			for(int j=0; j<RADIX; j++) {
				boolean ok = true;
				int next = 1<<j;
				for(int k=0; k<RADIX; k++) {
					if( (1<<k & mask) == 0)
						continue;
					

					

					

					if(cmp[j][k] == 0) {
					}
					

					else if(cmp[j][k] == -1) {
						next |= 1<<k;
					}
					

					else {
						ok = false;
					}
				}
				isValid[mask][j] = ok;
				map[mask][j] = next;
			}
		}
		
		

		for(int i=n-2; i>=0; i--) {
			long[] next = new long[1<<RADIX];
			for(int mask=0; mask < 1<<RADIX; mask++) {
				for(int j=0; j<RADIX; j++) {
					if(!isValid[mask][j])
						continue;
					int mask2 = map[mask][j];
					long val = next[mask2] + dp[mask];
					next[mask2] = val < MOD? val: val-MOD;
				}
			}
			dp = next;
		}
		
		long sum = 0;
		for(int mask=0; mask < 1<<RADIX; mask++)
			sum += dp[mask]; 

		return sum%MOD;
	}
	
	
	private long solve(int[] u, int[] v, int n) {
		int m = u.length;
		

		

		

		
		

		

		
		

		long[] num = new long[RADIX];
		for(int i=0; i<RADIX; i++)
			num[i] = 1;
		
		

		long[][] multipliers = new long[RADIX][RADIX];
		for(int i=0; i<RADIX; i++) {
			for(int j=0; j<RADIX; j++) {
				multipliers[i][j] = 1;
			}
		}
		
		for(int i=0; i<m; i++) {
			int min = Math.min(u[i], v[i]);
			int max = Math.max(u[i], v[i]);
			multipliers[max][min] = 0;
		}
		
		

		

		
		

		

		
		

		

		
		

		

		

		

		
		

		

		
		

		

		
		int temp  =1;
		
		for(int i=1; i<n; i++) {
			long[] num2 = new long[RADIX];
			for(int j=0; j<RADIX; j++) {
				for(int k=0; k<RADIX; k++) {
					num2[j] += num[k]*multipliers[j][k] % MOD;
				}
				num2[j] %= MOD;
			}
			num = num2;
		}
		
		long sum = 0;
		for(int i=0; i<RADIX; i++)
			sum += num[i];
		
		return sum%MOD;
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
