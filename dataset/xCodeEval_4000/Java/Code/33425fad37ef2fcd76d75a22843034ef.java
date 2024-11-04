import java.util.*;
import java.util.Map.Entry;
import java.io.*;
import java.math.BigInteger;



public class Round785E {	
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


		
		Round785E sol = new Round785E();
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
	    	int k = in.nextInt();
	    	int[] b = in.nextIntArray(n);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			String ans = solveCleanedUp(b, k);
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	final int exponentMOD = 1<<20;

	private String solveCleanedUp(int[] b, int k) {
		

		
		

		

		

		

		
		int n = b.length;
		boolean[] ans = new boolean[exponentMOD];
		










		
		boolean[] isOddXORForcedTwoSide = new boolean[n];
		for(int i=n-1; i >= n-21 && i>=0; i--) {
			if(i < k || i < 2)
				break;
			for(int j=Math.max(0, k-2); j<=i-2; j++)
				

				isOddXORForcedTwoSide[i] ^= ((i-2-j)&j) == 0;
		}
		
		boolean[] isOddXORForcedOneSide = new boolean[n];
		for(int i=n-1; i >= n-21 && i>=0; i--) {
			if(i < k || i < 1)
				break;
			for(int j=Math.max(0, k-1); j<=i-1; j++)
				

				isOddXORForcedOneSide[i] ^= ((i-1-j)&j) == 0;
		}
		
		for(int start =0; start<n; start++) {
			long exponent = b[start];
			int rest = n-1;
			



			if(start == 0 && start == n-1) {
				if(k == 0)
					ans[(int) exponent] ^= true;
			}
			else if(start == 0 || start == n-1) {
				if(isOddXORForcedOneSide[rest])
					ans[(int) exponent] ^= true;
			}
			else {
				if(isOddXORForcedTwoSide[rest])
					ans[(int) exponent] ^= true;
			}
			

			for(int i=start+1; i<n; i++) {
				if(b[i] >= 20)
					break;
				exponent *= (1<<b[i]);
				if(exponent >= 1<<20)
					break;
				rest = n-1-(i-start);
				if(start == 0 && i == n-1) {
					if(k == 0)
						ans[(int) exponent] ^= true;
				}
				else if(start == 0 || i == n-1) {
					if(isOddXORForcedOneSide[rest])
						ans[(int) exponent] ^= true;
				}
				else {
					if(isOddXORForcedTwoSide[rest])
						ans[(int) exponent] ^= true;
				}
			}
		}
		return toBinaryString(ans);
	}
	


	private String solve(int[] b, int k) {
		

		
		

		

		

		

		

		
		

		

		

		

		
		

		

		
		

		

		

		
		

		

		

		

		

		

		

		

		

		

		
		

		

		

		

		
		int n = b.length;












		










































































		
		

		

		
		int start = 0;
		int end = start+n-1-k;
		long exponent = b[start];
		int from = start;
		int to = 0;




		boolean[] ans = new boolean[exponentMOD];
		
		for(int i=start+1; i<= end; i++) {
			if(b[i] >= 20) {
				from = i;
				start = i-1;
				break;
			}
			exponent *= (1<<b[i]);
			if(exponent >= 1<<20) {
				break;
			}
			to = i;
		}
		if(to == end)
			ans[(int) exponent] ^= true;
		start++;
		
		for(; start <= k; start++) {
			end = start+n-1-k;
			if(from == start) {
				

				exponent = b[start];
				for(int i=start+1; i<= end; i++) {
					if(b[i] >= 20) {
						from = i;
						start = i-1;
						break;
					}
					exponent *= (1<<b[i]);
					if(exponent >= 1<<20) {
						break;
					}
					to = i;
				}
			}
			else {
				from = start;
				exponent /= b[start-1];
				exponent /= (1<<b[start]);
				exponent *= b[start];
				for(int i=to+1; i<=end; i++) {
					if(b[i] >= 20) {
						from = i;
						start = i-1;
						break;
					}
					exponent *= (1<<b[i]);
					if(exponent >= 1<<20) {
						break;
					}
					to = i;					
				}
			}
			if(to == end)
				ans[(int) exponent] ^= true;
		}
		
		



















		
		return toBinaryString(ans);


























































	}

	

	private String toBinaryString(boolean[] ans) {
		int start = -1;
		for(int i=ans.length-1; i>=0; i--) {
			if(ans[i]){
				start = i;
				break;
			}
		}
		if(start == -1)
			return "0";
		StringBuilder sb = new StringBuilder();
		for(int i=start; i>=0; i--) {
			if(ans[i])
				sb.append('1');
			else
				sb.append('0');
		}
		return sb.toString();
	}

	private String shift(int i) {
		StringBuilder sb = new StringBuilder("1");
		for(; i>0; i--)
			sb.append("0");
		return sb.toString();
	}

	static class Pair{
		BigInteger exponent;
		BigInteger val;
		public Pair(BigInteger exponent, BigInteger val) {
			this.exponent = exponent;
			this.val = val;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((exponent == null) ? 0 : exponent.hashCode());
			result = prime * result + ((val == null) ? 0 : val.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (exponent == null) {
				if (other.exponent != null)
					return false;
			} else if (!exponent.equals(other.exponent))
				return false;
			if (val == null) {
				if (other.val != null)
					return false;
			} else if (!val.equals(other.val))
				return false;
			return true;
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
		
		int[][] nextTreeEdges(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
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
