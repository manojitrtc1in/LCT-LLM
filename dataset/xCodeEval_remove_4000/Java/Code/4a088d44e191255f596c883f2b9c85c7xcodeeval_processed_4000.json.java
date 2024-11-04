import java.util.*;
import java.util.function.*;
import java.io.*;



public class id3 {	
	id4 out;
	MyScanner in;
	








	final static String id8 = "id8";
	final static String id10 = "id10";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id7) {
        if (System.getProperty("ONLINE_JUDGE") == null && id7) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id4(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id4(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id3 sol = new id3();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id7 = true;
		boolean id1 = false;
		
		initIO(id7);
		
		

	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int q = in.nextInt();
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
	    	int[] a = in.id6(n);
	    	
	    	int[] k = new int[q];
	    	int[] l = new int[q];
	    	for(int j=0; j<q; j++) {
	    		k[j] = in.nextInt()-1;
	    		l[j] = in.nextInt();
	    	}
	    	
			int[] ans = solve(a, k, l);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test2() {
		

		

		

		
		int x = 114732947;
		TreeSet<Chain> chains = new TreeSet<Chain>();
		for(int pos = 0; 1<<pos <= x; pos++) {
			if((x & (1<<pos)) > 0)
				insert(chains, pos);
		}
		
		int y = 90815528;
		if(y > x) {
			int z = y-x;
			for(int pos = 0; 1<<pos <= z; pos++) {
				if((z & (1<<pos)) > 0)
					insert(chains, pos);
			}
		}
		else {
			int z = x-y;
			for(int pos = 0; 1<<pos <= z; pos++) {
				if((z & (1<<pos)) > 0)
					delete(chains, pos);
			}
		}
		
		{
			int z = 0;
			for(Chain c: chains) {
				for(int pos = c.l; pos <= c.r; pos++)
					z |= 1<<pos;
			}
			if(y != z)
				System.out.println("wrong");
		}
		
		x = y;
		
		{
			int z = 0;
			for(Chain c: chains) {
				for(int pos = c.l; pos <= c.r; pos++)
					z |= 1<<pos;
			}
		}
		
		y = 104395081;
		if(y > x) {
			int z = y-x;
			for(int pos = 0; 1<<pos <= z; pos++) {
				if((z & (1<<pos)) > 0)
					insert(chains, pos);
			}
		}
		else {
			int z = x-y;
			for(int pos = 0; 1<<pos <= z; pos++) {
				if((z & (1<<pos)) > 0)
					delete(chains, pos);
			}
		}
		
		{
			int z = 0;
			for(Chain c: chains) {
				for(int pos = c.l; pos <= c.r; pos++)
					z |= 1<<pos;
			}
			if(y != z)
				System.out.println("wrong");
		
		}
		
		x = y;
	}
	
	private void test() {
		
		TreeSet<Chain> chains = new TreeSet<Chain>();
		
		int x = 0;
		
		Random r = new Random();
		
		for(int i=0; i<100; i++) {
			int y = r.nextInt(1<<28);
			System.out.println(y);
			if(y > x) {
				int z = y-x;
				for(int pos = 0; 1<<pos <= z; pos++) {
					if((z & (1<<pos)) > 0)
						insert(chains, pos);
				}
			}
			else { 

				

				int z = x-y;
				for(int pos = 0; 1<<pos <= z; pos++) {
					if((z & (1<<pos)) > 0)
						delete(chains, pos);
				}
			}
			int z = 0;
			for(Chain c: chains) {
				for(int pos = c.l; pos <= c.r; pos++)
					z |= 1<<pos;
			}
			if(y != z) {
				System.out.println("wrong");
				System.out.println(z);
				System.out.println(chains);
				
				break;
			}
			x = y;
		}
		
		
	}

	

	

	

	

	
	

	

	

	

	

	
	

	

	
	

	

	
	


	

	

	
	

	

	

	
	private int[] solve(int[] a, int[] k, int[] l) {
		int n = a.length;
		int q = k.length;
		
		

		TreeSet<Chain> chains = new TreeSet<Chain>();
		
		for(int i=0; i<n; i++) {
			

			insert(chains, a[i]);
		}
		
		int[] ans = new int[q];
		for(int i=0; i<q; i++) {
			int oldVal = a[k[i]];
			int newVal = l[i];
			delete(chains, oldVal);
			insert(chains, newVal);
			ans[i] = chains.last().r;
			a[k[i]] = newVal;
		}
		
		return ans;
	}
	
	void delete(TreeSet<Chain> chains, int val) {
		Chain c = new Chain(val, val);
		Chain high = chains.ceiling(c);
		assert(high != null);
		
		

		if(high.l < val) {
			

			chains.add(new Chain(high.l, val-1));
			high.l = val+1;
		}
		else if(high.l == val) {
			high.l++;
		}
		else { 

			Chain low = chains.lower(c);
			if(low == null)
				chains.add(new Chain(val, high.l-1));
			else if(low.r+1 == val)
				low.r = high.l-1;
			else
				chains.add(new Chain(val, high.l-1));
			high.l++;			
		}
		if(high.r < high.l)
			chains.remove(high);
	}

	void insert(TreeSet<Chain> chains, int val) {
		Chain c = new Chain(val, val);
		Chain high = chains.ceiling(c);
		if(high == null) {
			if(chains.isEmpty())
				chains.add(c);
			else{
				high = chains.last();
				if(high.r+1 == val)
					high.r++;
				else
					chains.add(c);
			}
		}
		else {
			if(high.l <= val) {
				

				

				Chain add = new Chain(high.r+1, high.r+1);
				Chain next = chains.ceiling(add);
				if(next == null)
					chains.add(add);
				else if(next.l == add.r+1)
					next.l--;
				else
					chains.add(add);
				
				if(high.l == val)
					chains.remove(high);
				else
					high.r = val-1;
			}
			else {
				if(high.l == val+1) {
					high.l--;
					Chain low = chains.floor(c);
					if(low != null && low.r+1 == val){
						high.l = low.l;
						chains.remove(low);
					}
				}
				else {
					

					Chain low = chains.floor(c);
					if(low == null)
						chains.add(c);
					else if(low.r+1 == val)
						low.r++;
					else
						chains.add(c);
				}
			}
		}
	}
	
	class Chain implements Comparable<Chain>{
		int l, r;
		
		public Chain(int l, int r) {
			this.l = l;
			this.r = r;
		}

		@Override
		public int compareTo(id3.Chain o) {
			return Integer.compare(r, o.r);
		}
		
		@Override
		public String toString() {
			return String.format("[%d, %d]", l, r);
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
		
		int[][] id5(int n, int offset){
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
		
		int[] id6(int len) {
			return id6(len, 0);
		}
		int[] id6(int len, int offset){
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
	
	public static class id4 extends PrintWriter{
		public id4(OutputStream os) {
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
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
		id4 out2 = null;
		 try {
			out2 = new id4(new FileOutputStream("graph.dot"));
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
