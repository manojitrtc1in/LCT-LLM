import java.util.*;
import java.io.*;



public class Round798D {
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


		
		Round798D sol = new Round798D();
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
	    	
	    	String[] mat = new String[n];
	    	
	    	for(int j=0; j<n; j++)
	    		mat[j] = in.next();
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int[] ans = solve3(mat);
			out.printlnAns(ans, 1);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private int[] solve3(String[] mat) {
		int n = mat.length;
		int m = mat[0].length();

		boolean[][] isBlack = new boolean[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				isBlack[i][j] = mat[i].charAt(j) == 'B';
		
		int[][] indexI = new int[2][n];
		for(int i=0; i<n; i++)
			indexI[0][i] = i;
		for(int i=0; i<n; i++)
			indexI[1][i] = n-1-i;
		
		int[][] indexJ = new int[2][m];
		for(int i=0; i<m; i++)
			indexJ[0][i] = i;
		for(int i=0; i<m; i++)
			indexJ[1][i] = m-1-i;		
		
		

		int[][][] maxDist = new int[4][][];
		for(int k=0; k<4; k++)
			maxDist[k] = computeQuarter(isBlack, indexI[k>>1], indexJ[k&1]);
		
		int minDist = Integer.MAX_VALUE;
		int[] ans = {-1, -1};
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				int dist = 0;
				for(int k=0; k<4; k++) {
					dist = Math.max(dist, maxDist[k][i][j] > 0? maxDist[k][i][j]-1 : maxDist[k][i][j]);
				}
				if(dist < minDist) {
					minDist = dist;
					ans[0] = i;
					ans[1] = j;
				}
			}
		return ans;
	}

	private int[][] computeQuarter(boolean[][] isBlack, int[] indexI, int[] indexJ) {
		int n = indexI.length;
		int m = indexJ.length;
		
		int[][] dist = new int[n][m];
		dist[indexI[0]][indexJ[0]] = isBlack[indexI[0]][indexJ[0]]? 1 : 0;
		
		for(int i=1; i<n; i++) {
			if(dist[indexI[i-1]][indexJ[0]] > 0)
				dist[indexI[i]][indexJ[0]] = dist[indexI[i-1]][indexJ[0]]+1;
			else
				dist[indexI[i]][indexJ[0]] = isBlack[indexI[i]][indexJ[0]]? 1 : 0;
		}
		
		for(int j=1; j<m; j++) {
			if(dist[indexI[0]][indexJ[j-1]] > 0)
				dist[indexI[0]][indexJ[j]] = dist[indexI[0]][indexJ[j-1]]+1;
			else
				dist[indexI[0]][indexJ[j]] = isBlack[indexI[0]][indexJ[j]]? 1 : 0;
		}
		
		
		for(int j=1; j<m; j++) {
			for(int i=1; i<n; i++) {
				int d1 = dist[indexI[i-1]][indexJ[j]];
				int d2 = dist[indexI[i]][indexJ[j-1]];
				if(d1 == 0 && d2 == 0)
					dist[indexI[i]][indexJ[j]] = isBlack[indexI[i]][indexJ[j]]? 1 : 0;
				else
					dist[indexI[i]][indexJ[j]] = 1+Math.max(dist[indexI[i]][indexJ[j-1]], dist[indexI[i-1]][indexJ[j]]);
			}
		}
		return dist;
	}

	private int[] solve2(String[] mat) {
		int n = mat.length;
		int m = mat[0].length();

		boolean[][] isBlack = new boolean[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				isBlack[i][j] = mat[i].charAt(j) == 'B';
		
		int[][] candidates = new int[2*n][2];
		int size = 0;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(isBlack[i][j])
					candidates[size++] = new int[]{i, j};
				break;
			}
			for(int j=m-1; j>=0; j--) {
				if(isBlack[i][j])
					candidates[size++] = new int[]{i, j};
				break;
			}
		}
		
		int minI = 10000;
		int maxI = -1;
		int minJ = 10000;
		int maxJ = -1;
		
		for(int k=0; k<size; k++) {
			int i = candidates[k][0];
			int j = candidates[k][1];
			
			minI = Math.min(i, minI);
			maxI = Math.max(i, maxI);
			
			minJ = Math.min(j, minJ);
			maxJ = Math.max(j, maxJ);
		}
		

		

		

		

		
		

		

		

		

		for(int k=0; k<size; k++) {
			for(int l=k+1; l<size; l++) {
				int i1 = candidates[k][0];
				int j1 = candidates[k][1];
				int i2 = candidates[l][0];
				int j2 = candidates[l][1];
				if(minI == i1 || minI == i2);
			}
		}
			
		
		return null;
	}
	
	

	private int[] solve(String[] mat) {
		int n = mat.length;
		int m = mat[0].length();
		
		ArrayDeque<MyPoint> queue = new ArrayDeque<MyPoint>();
		int[][] dist = new int[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				if(mat[i].charAt(j) == 'B') {
					dist[i][j] = 0;
					queue.addLast(new MyPoint(i, j, 0));
				}
				else
					dist[i][j] = Integer.MAX_VALUE;
			}

		int[] di = {0, 0, 1, -1};
		int[] dj = {1, -1, 0, 0};
		while(!queue.isEmpty()) {
			MyPoint p = queue.pollFirst();
			for(int k = 0; k < di.length; k++) {
				int i = p.i+di[k];
				int j = p.j+dj[k];
				int d = p.dist+1;
				if(0 <= i && i < n && 0 <= j && j < m && dist[i][j] > d) {
					dist[i][j] = d;
					queue.addLast(new MyPoint(i, j, d));
				}
			}
		}
		
		int min = Integer.MAX_VALUE;
		int[] minIdx = {-1, -1};
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				if(dist[i][j] != 0 && dist[i][j] < min) {
					min = dist[i][j];
					minIdx[0] = i;
					minIdx[1] = j;
				}
			}
		
		return minIdx;
	}
	
	static class MyPoint{
		int i, j, dist;

		public MyPoint(int i, int j, int dist) {
			this.i = i;
			this.j = j;
			this.dist = dist;
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
		
		public void printAns(boolean ans) {
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
			print(arr);
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
			print(arr);
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
			print(arr);
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
