import java.util.*;
import java.util.function.*;
import java.io.*;



public class Round804D {	
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


		
		Round804D sol = new Round804D();
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
	    	int[] a = in.nextIntArray(n, -1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int ans = solve(a);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		int n = 10;
		
		Random r = new Random();
		
		while(true) {
			int[] a = new int[n];
			
			for(int i=0; i<n; i++)
				a[i] = r.nextInt(n);
			
			a[5] = a[4];
			
			int ans = solve(a);
			
			out.printlnAns(a);
			out.printlnAns(ans);
			if(ans == 0)
				break;
		}
		
	}
	
	private int solve(int[] a) {
		int n = a.length;
		
		

		int[] dp = new int[n];
		
		dp[0] = 1;
		
		for(int i=1; i<n; i++) {
			int[] cnt = new int[n];
			int maxCnt = 0;
			dp[i] = Integer.MIN_VALUE;
			for(int j=i-1; j>=0; j--) {
				int m = (i-j-1);
				if(a[j] == a[i] && maxCnt <= m/2 && m%2 == 0) {
					dp[i] = Math.max(dp[i], dp[j]+1);
				}
				cnt[a[j]]++;
				maxCnt = Math.max(maxCnt, cnt[a[j]]);
			}
			if(maxCnt <= i/2 && i%2 == 0)
				dp[i] = Math.max(dp[i], 1);
			else if(dp[i] == Integer.MIN_VALUE)
				dp[i] = -maxCnt+1;
		}
		
		

		int ans = dp[n-1];
		{	
			int[] cnt = new int[n];
			cnt[a[n-1]]++;
			int maxCnt = 1;
			for(int i=n-2; i>=0; i--) {
				int m = (n-1-i);
				if(m%2 == 0 && maxCnt <= m/2)
					ans = Math.max(ans, dp[i]);
				cnt[a[i]]++;
				maxCnt = Math.max(maxCnt, cnt[a[i]]);
			}
		}
		return ans;
	}
	
	private int solve_wrong(int[] a) {
		int n = a.length;
		
		boolean[] exists = new boolean[n];
		for(int i=0; i<n; i++)
			exists[a[i]] = true;
		
		int ans = 0;
		for(int val=0; val<n; val++) {
			if(!exists[val])
				continue;
			
			

			

			

			int[] cnt = new int[n];
			int vote = 0;
			int freqElem = val;
			int prev = -1;
			int score = 0;
			for(int i=0; i<n; i++) {
				int m = i-1-prev;
				if(a[i] == val && cnt[freqElem] <= m/2 && m%2 == 0) {
					

					score++;
					
					

					for(int j=prev+1; j<i; j++)
						cnt[a[j]] = 0;
					vote = 0;
					freqElem = val;
					prev = i;
				}
				else {
					cnt[a[i]]++;
					if(vote == 0) {
						freqElem = a[i];
						vote++;
					}
					else if(freqElem == a[i])
						vote++;
					else
						vote--;
				}
			}
			int m = n-1-prev;
			int remainder;
			if(cnt[freqElem] > m/2)
				remainder = cnt[freqElem] - (m-cnt[freqElem]);
			else if(m%2 == 1)
				remainder = 1;
			else
				remainder = 0;
			score -= remainder;
			
			ans = Math.max(ans, score);
		}
		
		return ans;
	}

	private int solve2(int[] a) {
		

		
		

		

		
		

		

		

		

		

		
		
		

		

		

		
		
		

		

		

		

		
		

		
		

		
		
		

		
		
		

		
		
		

		
		

		

		

		
		

		
		

		

		

		
		
		

		

		

		

		
		
		int n = a.length;
		int[][] dp = new int[n][n];
		
		for(int i=0; i<n; i++)
			dp[0][i] = -1;
		dp[0][a[0]] = 1;
		
		for(int i=1; i<n; i++) {
			int[] cnt = new int[n];
			int mostFrequentElem = a[i];
			cnt[a[i]]++;
			int vote = 1;
			boolean first = true;
			for(int prev = i-1; prev >=0; prev--) {
				cnt[a[prev]]++;
				if(vote == 0)
					mostFrequentElem = a[prev];
				if(mostFrequentElem == a[prev])
					vote++;
				else
					vote--;
				
				int m = i-prev+1;
				if( (m&1) == 0 && cnt[mostFrequentElem] <= m/2 && prev > 0) {
					

					if(!first)
						dp[i][a[prev-1]] = Math.max(dp[i][a[prev-1]], dp[prev-1][a[prev-1]]);
					else {
						for(int val=0; val<n; val++)
							dp[i][val] = dp[prev-1][val];
						first = false;
					}
				}
			}
			if(cnt[mostFrequentElem] > (i+1)/2) {
				int need = cnt[mostFrequentElem]-(i+1-cnt[mostFrequentElem]);
				int temp = dp[i][mostFrequentElem];
				for(int val=0; val<n; val++)
					dp[i][val] = -need;
				dp[i][mostFrequentElem] = temp;
			}
			

			

			


			dp[i][a[i]] = Math.max(dp[i][a[i]], dp[i-1][a[i]]+1);
			
			

			

			

			






















































		}
		
		int max = 0;
		for(int i=0; i<n; i++)
			max = Math.max(max, dp[n-1][i]);
			
		return max;
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