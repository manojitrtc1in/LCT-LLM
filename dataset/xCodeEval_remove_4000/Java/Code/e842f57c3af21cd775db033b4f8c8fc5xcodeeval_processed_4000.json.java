
import java.util.*;
import java.util.function.BiFunction;
import java.io.*;



public class id7 {	
	id3 out;
	MyScanner in;
	








	final static String id8 = "id8";
	final static String id10 = "id10";
	final static String YES = "YES";
	final static String NO = "NO";
	final static long MOD = 998_244_353;
	
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


		
		id7 sol = new id7();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id6 = true;
		boolean id1 = true;
		
		initIO(id6);
		
		

	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int k = in.nextInt();
	    	int[] v = in.id5(n);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			long ans = solve(v, k);
			out.println(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void simulate() {
		int N = 5;
		int k = 5;
		int[] p = new int[N];
		for(int i=0; i<N; i++)
			p[i] = i;
		Random R = new Random();
		for(int T = 0; T < 10; T++) {
			int m = R.nextInt(N*N*N);
			for(int i=0; i<m; i++)
				nextPermutation(p);
			for(int round=0; round<k; round++) {
				out.printAns(p);
				int[] v = new int[N];
				for(int i=0; i<N; i++) {
					int cnt = 0;
					for(int j=0; j<i; j++) {
						if(p[j] > p[i])
							cnt++;
					}
					v[i] = cnt;
				}
				out.print(" // ");
				out.printlnAns(v);
				out.flush();
				for(int j=0; j<N-1; j++)
					if(p[j] > p[j+1]) {
						int temp = p[j];
						p[j] = p[j+1];
						p[j+1] = temp;
					}
			}
			out.println("next");
		}
		
	}
	
	static void nextPermutation(int[] a) {
		int left;
		int n = a.length;
		for (left = n-2; left >= 0 && a[left] >= a[left+1]; left--);
		

		if (left == -1)
			reverse(a, 0, n-1);
		else {
			for (int i = n-1; i>=0; i--)
				if (a[i] > a[left]) {
					int temp = a[i];
					a[i] = a[left];
					a[left] = temp;
					break;
				}
			reverse(a, left+1, n-1);
		}
	}
	
	static void reverse(int[] a, int left, int right) {
		int i = left;
		int j = right;
		while(i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	private long solve(int[] v, int k) {
		int n = v.length;
		

		

		
		

		

		

		

		

		
		

		

		
		

		

		
		

		

		

		

		
		

		

		
		

				
		

		
		

		
		

		

		
		

		

		
		long ans = 1;
		for(int i=n-1; i>=0; i--) {
			if(i >= n-k) {
				

				assert(v[i] <= 0);
				if(v[i] > 0)
					return 0;
				ans *= (n-1-i)+1;
				ans %= MOD;
			}
			else if(v[i] == 0) {
				ans *= k+1;
				ans %= MOD;
			}
			else if(v[i] == -1) {
				ans *= (k+1)+i; 

				ans %= MOD;
			}
		}
		return ans;
		




























		




















































		
		

	}

	class SegmentTree {
		BiFunction<Integer, Integer, Integer> function;
		int identity;
		int n;
		int[] tree;
		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int[] arr, int identity){
			this.function = function;
			this.identity = identity;
			this.n = arr.length;
			
			int m = 1;
			while(m < n+1){
				m <<= 1;
			}
			m <<= 1;
			
			tree = new int[m];
			Arrays.fill(tree, identity);
			
			for(int i=0; i<n; i++){
				update(i, arr[i]);
			}

		}
		
		public void update(int idx, int val){
			update(idx+1, val, 1, 1, n);
		}

		private int update(int idx, int val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];
			
			

			if(left == right){
				tree[treeIdx] = val;
				return val;
			}
			
			

			int mid = (left+right)/2;
			int val1 = update(idx, val, treeIdx*2, left, mid);
			int val2 = update(idx, val, treeIdx*2+1, mid+1, right);
			val = function.apply(val1, val2);
			tree[treeIdx] = val;
			return val;
		}
		
		public int getRange(int start, int end){
			return getRange(start+1, end+1, 1, 1, n);
		}

		private int getRange(int start, int end, int treeIdx, int left, int right) {
			

			
			

			
			if(start == left && end == right)
				return tree[treeIdx];
			
			int mid = (left+right)/2;
			if(end <= mid)
				return getRange(start, end, treeIdx*2, left, mid);
			else if(start <= mid){
				int val1 = getRange(start, mid, treeIdx*2, left, mid);
				int val2 = getRange(mid+1, end, treeIdx*2+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, treeIdx*2+1, mid+1, right);
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
		
		int[][] id4(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
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
		
		long[] id13(int len) {
			return id13(len, 0);
		}
		long[] id13(int len, int offset){
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
