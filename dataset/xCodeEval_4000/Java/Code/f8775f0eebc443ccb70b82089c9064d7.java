import java.util.*;
import java.io.*;






public class Round785F {	
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


		
		Round785F sol = new Round785F();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = false;
		boolean hasMultipleTests = false;
		
		initIO(isFileIO);
	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int k = in.nextInt();
	    	
	    	precomputeOrdering();
	    	
	    	buildRoad(n, k);
	    	

	    	

	    	for(int r=0; r<n; r++) {
	    		out.print(distHorizontal[r][0]);
	    		for(int c=1; c<n-1; c++) {
	    			out.print(" ");
	    			out.print(distHorizontal[r][c]);
	    		}
	    		out.println();
	    	}
	    	for(int r=0; r<n-1; r++) {
	    		out.print(distVertical[r][0]);
	    		for(int c=1; c<n; c++) {
	    			out.print(" ");
	    			out.print(distVertical[r][c]);
	    		}
	    		out.println();
	    	}
	    	out.flush();
	    	
	    	preprocess();
	    	
	    	for(int j=0; j<k; j++) {
	    		if(isDebug)
	    			simulate();
	    		else {
		    		int x = in.nextInt();
		    		query(x);
		    		out.print(pos[0]+1);
		    		out.print(" ");
		    		out.println(pos[1]+1);
		    		out.flush();
	    		}
	    	}
	    }
	    
	    in.close();
	    out.close();
	}

	int val = 0;
	private void simulate() {
		

		while(true) {
			char ch = in.next().charAt(0);
			switch(ch) {
			case 'R':
				val = val ^ distHorizontal[pos[0]][pos[1]];
				pos[1]++;
				break;
			case 'D':
				val = val ^ distVertical[pos[0]][pos[1]];
				pos[0]++;
				break;
			case 'L':
				pos[1]--;
				val = val ^ distHorizontal[pos[0]][pos[1]];
				break;
			case 'U':
				pos[0]--;
				val = val ^ distVertical[pos[0]][pos[1]];
				break;
			case 'S':
	    		query(val);
	    		out.printlnAns(pos, 1);
	    		out.flush();
			default:
				return;
			}
			out.printAns(pos, 1);
			out.printf(" = %d\n", val);
			out.flush();
		}
	}

	int[] pos = {0, 0};
	int[][] value;
	private void preprocess() {
		value = new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				value[j][i] = ordering[i] + (ordering[j]<<1);
			}
		}
	}
	
	private void query(int x) {
		val = val ^ x;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(value[i][j] == val){
					pos[0] = i;
					pos[1] = j;
					return;
				}
			}
		}
	}
	
	final int SHIFT = 5;
	final int N = 1 << SHIFT;
	private int[] ordering;
	

	

	

	

	

	private void precomputeOrdering() {
		ordering = new int[N];
		ordering[0] = 0;
		ordering[1] = 1;
		int idx = 2;
		for(int numBit = 2; (1<<numBit) <= N; numBit++) {
			for(; idx < 1<<numBit; idx++) {
				ordering[idx] = 1<<2*(numBit-1);
				ordering[idx] += ordering[(1<<numBit-1)-1-(idx-(1<<numBit-1))];
			}
		}






	}

	private int[][] distHorizontal;
	private int[][] distVertical;
	
	private void buildRoad(int n, int k) {
    	

    	distHorizontal = new int[n][n-1];
    	

    	distVertical = new int[n-1][n];
		

		

		

		

		

    	
    	

    	

    	
    	

    	

    	

    	

    	
    	int sum = 0;
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<n-1; j++) {
    			distHorizontal[i][j] = ordering[j] ^ ordering[j+1];
    			sum += distHorizontal[i][j];
    		}
    	}
    	
    	for(int i=0; i<n-1; i++) {
    		for(int j=0; j<n; j++) {
    			distVertical[i][j] = ordering[i] ^ ordering[i+1];
    			distVertical[i][j] <<= 1;
    			sum += distVertical[i][j];
    		}
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
