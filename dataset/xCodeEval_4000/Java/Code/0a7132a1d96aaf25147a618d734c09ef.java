
import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundEdu131E {	
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


		
		RoundEdu131E sol = new RoundEdu131E();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = true;
		
		initIO(isFileIO);
		
		

	
		int T = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= T; ++i) {
	    	int n = in.nextInt();
	    	int m = in.nextInt();
	    	String s = in.next();
	    	String t = in.next();
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int ans = solve(s, t);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void zTest() {
		Random rand = new Random();
		LOOP:
		while(true) {
			int n = 10;
			int m = rand.nextInt(5)+5;
			String s = "";
			for(int i=0; i<n; i++)
				s += (char)('a' + rand.nextInt('e'-'a'+1));
			String t = "";
			for(int i=0; i<m; i++)
				t += (char)('a' + rand.nextInt('e'-'a'+1));
			
			int[][] z = new int[n][m];
			
			for(int j=0; j<m; j++) {
				while(z[0][j] < n && j+z[0][j] < m && t.charAt(j+z[0][j]) == s.charAt(z[0][j]))
					z[0][j]++;
				
				int[] zt = new int[m-j];
			    for (int i = 1, l = 0, r = 0; j+i < m; i++) {
			        if (i <= r)
			            zt[i] = Math.min(r - i + 1, zt[i - l]);
			        while (j+i + zt[i] < m && t.charAt(j+zt[i]) == t.charAt(j+i + zt[i]))
			            zt[i]++;
			        if (j+i + zt[i] - 1 > r) {
			            l = i;
			            r = i + zt[i] - 1;
			        }
			    }
				
				for (int i = 1, l = 0, r = 0; i < n; i++) {
			        if (i <= r)
			            z[i][j] = Math.min(r - i + 1, zt[i - l]);
			        while (i + z[i][j] < n && j+z[i][j] < m && t.charAt(j+z[i][j]) == s.charAt(i + z[i][j]))
			            z[i][j]++;
			        if (i + z[i][j] - 1 > r) {
			            l = i;
			            r = i + z[i][j] - 1;
			        }
			    }
			}
			
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					int k = z[i][j];
					if(!s.substring(i, i+k).equals(t.substring(j, j+k))) {
						out.println(s);
						out.println(t);
						break LOOP;
					}
				}
			}
		}		
	}

	private int solve(String s, String t) {
		int n = s.length();
		int m = t.length();

		

		

		

		
		
		

		

		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		
		

		

		boolean[][] prefixDP = new boolean[n][m];
		if(s.charAt(0) == t.charAt(0))
			prefixDP[0][0] = true;
		
		for(int i=1; i<n; i++) {
			prefixDP[i][0] = s.charAt(i) == t.charAt(0);
			prefixDP[i][0] |= prefixDP[i-1][0];
			
			for(int j=1; j<m; j++) {
				if(s.charAt(i) == t.charAt(j)) {
					prefixDP[i][j] = prefixDP[i-1][j-1];
				}
				prefixDP[i][j] |= prefixDP[i-1][j];
			}
		}
		
		boolean[][] suffixDP = new boolean[n][m];
		if(s.charAt(n-1) == t.charAt(m-1))
			suffixDP[n-1][m-1] = true;
		
		for(int i=n-2; i>=0; i--) {
			suffixDP[i][m-1] = s.charAt(i) == t.charAt(m-1);
			suffixDP[i][m-1] |= suffixDP[i+1][m-1];
			
			for(int j=m-2; j>=0; j--) {
				if(s.charAt(i) == t.charAt(j)) {
					suffixDP[i][j] = suffixDP[i+1][j+1];
				}
				suffixDP[i][j] |= suffixDP[i+1][j];
			}
		}
		
		if(!suffixDP[0][0])
			return -1;
		
		

		

		

		
		int[][] z = new int[n][m];
		
		for(int j=0; j<m; j++) {
			while(z[0][j] < n && j+z[0][j] < m && t.charAt(j+z[0][j]) == s.charAt(z[0][j]))
				z[0][j]++;
			
			int[] zt = new int[m-j];
		    for (int i = 1, l = 0, r = 0; j+i < m; i++) {
		        if (i <= r)
		            zt[i] = Math.min(r - i + 1, zt[i - l]);
		        while (j+i + zt[i] < m && t.charAt(j+zt[i]) == t.charAt(j+i + zt[i]))
		            zt[i]++;
		        if (j+i + zt[i] - 1 > r) {
		            l = i;
		            r = i + zt[i] - 1;
		        }
		    }
			
			for (int i = 1, l = 0, r = 0; i < n; i++) {
		        if (i <= r)
		            z[i][j] = Math.min(r - i + 1, zt[i - l]);
		        while (i + z[i][j] < n && j+z[i][j] < m && t.charAt(j+z[i][j]) == s.charAt(i + z[i][j]))
		            z[i][j]++;
		        if (i + z[i][j] - 1 > r) {
		            l = i;
		            r = i + z[i][j] - 1;
		        }
		    }
		}
		




















































		
		int minCost = n;
		for(int i=1; i<n; i++) {
			for(int j=0; j<m; j++) {
				int cost = 1;
				int k = z[i][j];
				

				

				

				if(j + k == m) {
					cost += n-(i+k);
				}
				else if(i + k == n) {
					continue;
				}
				else if(suffixDP[i+k][j+k]) {
					cost += n-(i+k);
				}
				else {
					continue;
				}
				if(j==0) { 

					cost += i*2;
				}
				else if(prefixDP[i-1][j-1]) {
					cost += i+(i-j);
				}
				else {
					continue;
				}
				minCost = Math.min(minCost, cost);
			}
		}
		

		{
			int k = z[0][0];
			if(k == m) {
				minCost = Math.min(minCost, n-k);
			}
			else {
				

				if(suffixDP[k][k])
					minCost = Math.min(minCost, n-k);
			}
		}

		return minCost;
		




		
		

		

		

		

		

	}
	
	
	private int solve3(String s, String t) {
		int n = s.length();
		int m = t.length();
		
		int[] prefixMatch = new int[n];
		int[] suffixMatch = new int[n];
		

		

		
		prefixMatch[0] = s.charAt(0) == t.charAt(0)? 0: -1;
		for(int i=1; i<n; i++) {
			int k = prefixMatch[i-1]+1;
			if(k >= m)
				prefixMatch[i] = m;
			else
				prefixMatch[i] = s.charAt(i) == t.charAt(k)? k: k-1;
		}
		
		suffixMatch[n-1] = s.charAt(n-1) == t.charAt(m-1)? m-1: m;
		for(int i=n-2; i>=0; i--) {
			int k = suffixMatch[i+1]-1;
			if(k <= -1)
				suffixMatch[i] = -1;
			else
				suffixMatch[i] = s.charAt(i) == t.charAt(k)? k: k+1;
		}
		
		int min = Arrays.binarySearch(suffixMatch, 0);
		if(min < 0)
			return -1;
		else {
			

			

			if(n-min == m)
				min = Math.min(n, 1+min*2); 

			else
				min = n;
		}
		
		for(int i=-1; i<n; i++) {
			int x = i==-1? -1: prefixMatch[i];
			int y = x+1;
			int j = i+1;
			while(y < m && j < n && s.charAt(j) == t.charAt(y)) {
				j++;
				y++;
			}
			int cost;
			if(i == -1) {
				cost = 0;
			}
			else {
				cost = 1; 

				cost += i+1; 

				cost += i-x; 

			}
			if(y == m) {
				cost += n-j;
				min = Math.min(min, cost);
			}
			else if(j < n) {
				int z = suffixMatch[j];
				if(z <= y) {
					cost += n-j;
					min = Math.min(min, cost);
				}
			}
		}








		
		return min;

	}

	private int solve2(String s, String t) {
		int n = s.length();
		int m = t.length();
		

		

		
		

		

		

		
		

		

		

		

		

		

		

		
		
		int[][] dp = new int[n][m];
		final int MAX = n*10;
		boolean found = false;
		for(int i=0; i<n; i++) {
			if(s.charAt(i) == t.charAt(0))
				found = true;
			dp[i][0] = found? 2*i+1: MAX;
		}
		for(int j=1; j<m; j++)
			dp[0][j] = MAX;
		
		

		

		for(int i=1; i<n; i++) {
			for(int j=1; j<m; j++) {
				if(s.charAt(i) == t.charAt(j))
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = dp[i-1][j]+2;
			}
		}
		
		

		

		

		

		

		

		

		
		

		int min = dp[n-1][m-1]+1;
		for(int j = m-1; j >=0; j--) {
			int y = m-1;
			int x;
			int cost = 0;
			for(x=n-1; x>=0 && y >= j; x--) {
				if(s.charAt(x) == t.charAt(y)) {
					y--;
					cost++; 

				}
				else {
					cost++; 

				}
			}
			if(y < j) {
				

				int skipCost = 0;
				while(x >= 0 && y >= 0 && s.charAt(x) == t.charAt(y)) {
					x--;
					y--;
					skipCost++;
					

				}
				if(y == -1 && x == -1){
					min = Math.min(min, cost);
				}
				else if(y == -1) {
					cost += x + skipCost; 

					min = Math.min(min, cost);
				}
				else if(x >=0 && y >= 0) {
					cost += dp[x][y] + 1;
					min = Math.min(min, cost);
				}
			}
			

		}
		
		return min>=MAX? -1: min;
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
