import java.util.*;
import java.util.function.*;
import java.io.*;



public class id8 {	
	id3 out;
	MyScanner in;
	








	final static String id7 = "id7";
	final static String id10 = "id10";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id6) {
        if (System.getProperty("ONLINE_JUDGE") == null && id6) {
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


		
		id8 sol = new id8();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id6 = true;
		boolean id1 = false;
		
		initIO(id6);
		
		

	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int q = in.nextInt();
	    	int mod = in.nextInt();
	    	int[] a = in.id5(n);
	    	int[] b = in.id5(n);
	    	Query[] op = new Query[q];
	    	for(int j=0; j<q; j++)
	    		op[j] = new Query(
	    				in.next().equals("A")? Qtype.A: Qtype.B,
	    				in.nextInt()-1,
	    				in.nextInt()-1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			boolean[] ans = solve(a, b, mod, op);
			for(boolean yn: ans)
				out.printlnAns(yn);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {
		final Random rand = new Random();
		final int n = 5;
		final int q = 1;
		final int mod = 2;
		for(int t = 0; t<100000; t++) {
			int[] a = new int[n];
			int[] b = new int[n];
			for(int i=0; i<n; i++) {
				a[i] = rand.nextInt(mod);
				b[i] = rand.nextInt(mod);
			}
			int[] a_ori = Arrays.copyOf(a, n);
			int[] b_ori = Arrays.copyOf(b, n);
			Query[] op = new Query[q];
			for(int i=0; i<q; i++) {
				int x = rand.nextInt(n);
				int y = rand.nextInt(n);
				int l = Math.min(x, y);
				int r = Math.max(x, y);
				op[i] = new Query(rand.nextInt(2) == 1? Qtype.A: Qtype.B, l, r);
			}
			boolean[] ans = solve(a, b, mod, op);
			boolean[] expected = new boolean[q];
			int[] fib = new int[n+1];
			fib[0] = 1 % mod;
			fib[1] = 1 % mod;
			for(int i=2; i<=n; i++) {
				fib[i] = fib[i-1]+fib[i-2];
				fib[i] = fib[i] >= mod? fib[i]-mod: fib[i];
			}
			for(int i=0; i<q; i++) {
				int[] c = op[i].c == Qtype.A? a: b;
				for(int j=op[i].l; j<=op[i].r; j++) {
					c[j] += fib[j-op[i].l];
					c[j] %= mod;
				}
				boolean same = true;
				for(int j=0; j<n; j++)
					if(a[j] != b[j]) {
						same = false;
						break;
					}
				expected[i] = same;
			}
			if(!Arrays.equals(ans, expected)) {
				System.out.println("wrong");
				
			}
		}
	}

	private boolean[] solve(int[] a, int[] b, int mod, id8.Query[] op) {
		int n = a.length;
		int q = op.length;
		boolean[] ans = new boolean[q];
		
		int[] d = new int[n];
		
		

		

		

		
		

		

		

		

		

		

		

		

		
		

		
		

		

		

		
		

		

		

		

		

		

		
		

		

		
		

		

		

		

		

		

		
		

		

		

		

		
		

		

		

		

		

		
		

		

		

		

		

		

		


		for(int i=0; i<n; i++) {
			d[i] = a[i]-b[i];
			d[i] = d[i]<0? d[i]+mod: d[i];
		}
		int[] diff = new int[n];
		diff[0] = d[0];
		if(n > 1) {
			diff[1] = d[1]-d[0];
			diff[1] = diff[1]<0? diff[1]+mod: diff[1];
		}
		for(int i=2; i<n; i++) {
			diff[i] = d[i]-d[i-1];
			diff[i] = diff[i]<0? diff[i]+mod: diff[i];
			diff[i] -= d[i-2];
			diff[i] = diff[i]<0? diff[i]+mod: diff[i];
		}
		
		numZero = 0;
		for(int i=0; i<n; i++)
			if(diff[i] == 0)
				numZero++;
		
		

		

		int[] fib = new int[n+1];
		fib[0] = 1 % mod;
		fib[1] = 1 % mod;
		for(int i=2; i<=n; i++) {
			fib[i] = fib[i-1]+fib[i-2];
			fib[i] = fib[i] >= mod? fib[i]-mod: fib[i];
		}
		
		for(int i=0; i<q; i++) {
			int sign = op[i].c == Qtype.A? 1: -1;
			int l = op[i].l;
			int r = op[i].r;
			update(diff, l, sign, mod);
			update(diff, r+1, -fib[r-l+1]*sign, mod);
			update(diff, r+2, -fib[r-l]*sign, mod);
			ans[i] = numZero == n;
		}
		return ans;
	}

	int numZero;
	void update(int[] diff, int index, int val, int mod) {
		if(index >= diff.length)
			return;
		if(diff[index] == 0)
			numZero--;
		diff[index] += val;
		if(diff[index] >= mod)
			diff[index] -= mod;
		if(diff[index] < 0)
			diff[index] += mod;
		if(diff[index] == 0)
			numZero++;
	}

	static enum Qtype{
		A, B;
	}
	
	static class Query{
		Qtype c;
		int l, r;
		public Query(id8.Qtype c, int l, int r) {
			this.c = c;
			this.l = l;
			this.r = r;
		}
	}

	int solve(){
		
		return 0;
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
		
		int[][] id4(int n, int offset){
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

		int[][] id9(){
			return id9(0);
		}
		
		int[][] id9(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id5(int len) {
			return id5(len, 0);
		}
		int[] id5(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id14(int len) {
			return id14(len, 0);
		}
		long[] id14(int len, int offset){
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
		
		public void id0(long[] arr, int split){
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
	
	static private void id13(long[] a) {
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
	
	static private void id13(int[] a) {
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
	
	static private int[][][] id12(int n, int[][] e){
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
		id11(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id11(int[][] e) {
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
