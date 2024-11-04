import java.util.*;
import java.io.*;



public class Round798E {	
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


		
		Round798E sol = new Round798E();
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
	    	int[] a = in.nextIntArray(n);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			Result ans = solve(a);
			out.println(ans.numOp);
			out.printlnAns(ans.array);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {
		Random R = new Random();
		final int N = 4;
		final int MAX = 1<<30;
		solve(new int[] {4, 706, 88, 8});
		while(true) {
			int[] a = new int[N];
			if(Math.random() > 0.5)
				for(int i=0; i<N; i++)
					a[i] = R.nextInt(MAX) & (Integer.MAX_VALUE-1);
			else
				for(int i=0; i<N; i++)
					a[i] = R.nextInt(1<<10) & (Integer.MAX_VALUE-1);
			int[] b = Arrays.copyOf(a, N);
			Result ans = solve(a);
			DSU dsu = new DSU(N);
			for(int i=0; i<N; i++)
				dsu.put(i);
			for(int i=0; i<N; i++)
				for(int j=i+1; j<N; j++)
					if( (a[i] & a[j]) > 0)
						dsu.union(i, j);
			if(dsu.size[dsu.find(0)] != N) {
				out.printlnAns(b);
				out.println(ans.numOp);
				out.printlnAns(a);
				break;
			}
		}
	}

	final int MAX_BIT = 30;
	private Round798E.Result solve(int[] a) {
		int n = a.length;
		int numOp = 0;
		










		for(int i=0; i<n; i++) {
			if(a[i] == 0) {
				a[i]++;
				numOp++;
			}
		}


























		
		

		
		

		

		

		
		

		

		

		
		

		

		

		
		

		

		

		

		

		
		
		

		

		
		DSU dsu = new DSU(n);
		for(int i=0; i<n; i++) {
			dsu.put(i);
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if( (a[i] & a[j]) > 0)
					dsu.union(i, j);
			}
		}
		
		if(dsu.size[dsu.find(0)] == n) {
			return new Result(numOp, a);
		}
		
		int maxLowestOneBit = -1;
		for(int i=0; i<n; i++) {
			int k = Integer.lowestOneBit(a[i]);
			if(k != 1)
				maxLowestOneBit = Math.max(maxLowestOneBit, k);
		}
		

		
		for(int i=0; i<n; i++) {
			if(maxLowestOneBit == Integer.lowestOneBit(a[i])) {
				DSU temp = dsu.clone();
				a[i] += 1;
				for(int j=0; j<n; j++)
					if( (a[i] & a[j]) > 0)
						temp.union(i, j);
				if(temp.size[temp.find(0)] == n)
					return new Result(numOp+1, a);
				a[i] -= 1;




















			}
		}
		
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(maxLowestOneBit == Integer.lowestOneBit(a[i])) {
				cnt++;
			}
		}
		boolean isAlone = cnt==1;
		boolean tryOne = false;
		
		for(int i=0; i<n; i++) {
			if(maxLowestOneBit == Integer.lowestOneBit(a[i])) {
				a[i] -= 1;
				boolean ok = isAlone;
				if(!ok) {
					for(int j=0; j<n; j++) {
						if(i == j)
							continue;
						if(maxLowestOneBit == Integer.lowestOneBit(a[j])) {
							if( (a[i] & a[j]) > 0 ) {
								ok = true;
								break;
							}
						}
						else {
							

							if(dsu.find(j) == dsu.find(i)) {
								tryOne = true;
								break;
							}
						}
					}
				}
				

				

				

				

				if(ok) {
					DSU temp = dsu.clone();
					for(int j=0; j<n; j++)
						if( (a[i] & a[j]) > 0)
							temp.union(i, j);
					if(temp.size[temp.find(0)] == n)
						return new Result(numOp+1, a);					
				}
				a[i] += 1;
			}
		}
		
		

		if(tryOne) {
			for(int k=0; k<n; k++) {
				if(maxLowestOneBit == Integer.lowestOneBit(a[k])) {
					a[k] -= 1;
					DSU tmp = new DSU(n);
					for(int i=0; i<n; i++)
						tmp.put(i);
					for(int i=0; i<n; i++)
						for(int j=i+1; j<n; j++)
							if( (a[i] & a[j]) > 0)
								tmp.union(i, j);
					if(tmp.size[tmp.find(0)] == n) {
						return new Result(numOp+1, a);
					}
					a[k] += 1;
				}
			}
		}
		
		

		

		boolean first = true;
		for(int i=0; i<n; i++) {
			if(maxLowestOneBit == Integer.lowestOneBit(a[i])) {
				if(first) {
					a[i] -= 1;
					first = false;
				}
				else {
					a[i] += 1;
					return new Result(numOp+2, a);	
				}
			}
		}
		return null;
	}
	
	public class DSU {
		int[] size;
		int[] parents;
		
		public DSU(int max) {
			parents = new int[max];
			size = new int[max];
		}
		
		public void put(int v) {
			parents[v] = -1;
			size[v] = 1;
		}
		
		public void union(int v, int u) {
			int head1 = find(v);
			int head2 = find(u);
			if(head1 == head2)
				return;
			int smaller, larger;
			if(size[head1] > size[head2]) {
				smaller = head2;
				larger = head1;
			}
			else {
				smaller = head1;
				larger = head2;
			}
			parents[smaller] = larger;
			size[larger] += size[smaller];
		}
		public int find(int v) {
			if(parents[v] == -1)
				return v;
			int head = find(parents[v]);
			parents[v] = head;
			return head;
		}
		
		@Override
		public DSU clone() {
			int n = size.length;
			DSU ret = new DSU(n);
			ret.parents = Arrays.copyOf(parents, n);
			ret.size = Arrays.copyOf(size, n);
			return ret;
		}
	}

	static class Result{
		int numOp;
		int[] array;
		public Result(int numOp, int[] array) {
			this.numOp = numOp;
			this.array = array;
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
		
		public int[][] nextMatrix(int n, int m) {
			return nextMatrix(n, m, 0);
		}
		
		private int[][] nextMatrix(int n, int m, int offset) {
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
