import java.util.*;
import java.io.*;



public class id16 {	
	id3 out;
	MyScanner in;
	








	final static String id10 = "id10";
	final static String id12 = "id12";
	final static String YES = "YES";
	final static String NO = "NO";
	final static long MOD = 1_000_000_007;
	
    private void initIO(boolean id8) {
        if (System.getProperty("ONLINE_JUDGE") == null && id8) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id3(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id3(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id16 sol = new id16();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id1 = false;
		
		initIO(id8);
	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int k = in.nextInt();
	    	int[][] e = in.id5(n, -1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int ans = solve(n, e, k);
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	int[][] neighborhood;
	
	

	long[] choose;
	int root = 0;
	
	int[] id9;
	ArrayList<Integer> id6;
	
	

	long[] s;
	long fSum;
	
	int prev;
	boolean[] visited;
	
	private int solve(int n, int[][] e, int k) {
		

		

		

		
		

		

		

		

		

		

				
		

		

		
		

		

		

		

		

		

		

		

		
		neighborhood = constructNeighborhood(n, e);
		id4(n, k);
		
		root = 0;
		id9 = new int[n];
		s = new long[n];
		id6 = new ArrayList<Integer>(n);
		

		

		

		id15(root, -1);
		
		fSum = 0;
		for(int i=0; i<n; i++) {
			fSum += s[i]*id9[i];
			fSum %= MOD;


		}
		
		long ans = fSum;
		
		visited = new boolean[n];
		visited[root] = true;
		
		for(int next: id6) {
			prev = root;
			root = next;
			swap(prev);
			if(!visited[next]) {
				ans += fSum;
				ans = ans >= MOD? ans-MOD : ans;
			}
			visited[next] = true;
		}
		
		return (int)ans;
		

	}

	private void swap(int prevRoot) {
		

		

		

		

		

		
		fSum -= s[prevRoot]*id9[prevRoot];
		fSum %= MOD;
		fSum = fSum < 0? fSum+MOD: fSum;
		fSum -= s[root]*id9[root];
		fSum %= MOD;
		fSum = fSum < 0? fSum+MOD: fSum;		
		
		

		

		
		s[prevRoot] -= choose[id9[prevRoot]];
		s[prevRoot] = s[prevRoot] < 0? s[prevRoot] + MOD: s[prevRoot];
		s[prevRoot] += choose[id9[root]];
		s[prevRoot] = s[prevRoot] >= MOD? s[prevRoot] - MOD: s[prevRoot];
		
		s[root] -= choose[id9[root]];
		s[root] = s[root] < 0? s[root] + MOD: s[root];
		
		id9[prevRoot] -= id9[root];
		id9[root] += id9[prevRoot];
		
		s[prevRoot] += choose[id9[prevRoot]];
		s[prevRoot] = s[prevRoot] >= MOD? s[prevRoot] - MOD: s[prevRoot];
		
		s[root] -= choose[id9[prevRoot]];
		s[root] = s[root] < 0? s[root] + MOD: s[root];
		s[root] += choose[id9[root]];
		s[root] = s[root] >= MOD? s[root] - MOD: s[root];
		
		fSum += s[prevRoot]*id9[prevRoot];
		fSum %= MOD;
		fSum += s[root]*id9[root];
		fSum %= MOD;
	}

	private void id15(int curr, int parent) {
		

		

		int size = 1;
		long sum = 0;
		for(int i=0; i<neighborhood[curr].length; i++) {
			int next = neighborhood[curr][i];
			if(next == parent)
				continue;
			id6.add(next);
			id15(next, curr);
			int sSize = id9[next];
			size += sSize;;
			sum -= choose[sSize];
			sum = sum < 0? sum+MOD: sum;
			id6.add(curr);
		}
		sum += choose[size];
		sum = sum >= MOD? sum-MOD: sum;
		id9[curr] = size;
		s[curr] = sum;
	}

	private void id4(int n, int k) {
		choose = new long[n+1];
		
		

		

		

		
		for(int i=0; i<k; i++)
			choose[i] = 0;
		
		choose[k] = 1;
		
		long curr = choose[k];
		for(int i=k+1; i<=n; i++) {
			curr *= i;
			curr %= MOD;
			

			

			curr *= inverse(i-k, MOD);
			curr %= MOD;
			choose[i] = curr;
		}
	}

	

	private long inverse(int k, long p) {
		long m = p-2;
		long ans = 1;
		
		

		long curr = k;
		
		

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
		
		int[][] id5(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
		}
		
		int[][] id11(){
			return id11(0);
		}
		int[][] id11(int offset) {
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
		
		long[] id17(int len) {
			return id17(len, 0);
		}
		long[] id17(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
	}
	
	public static class id3 extends PrintWriter{
		public id3(OutputStream os) {
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
	
	static private int[][][] id14(int n, int[][] e){
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
	
	static private void id13(int[][] e) {
		id3 out2 = null;
		 try {
			out2 = new id3(new FileOutputStream("graph.dot"));
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
		id3 out2 = null;
		 try {
			out2 = new id3(new FileOutputStream("graph.dot"));
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
