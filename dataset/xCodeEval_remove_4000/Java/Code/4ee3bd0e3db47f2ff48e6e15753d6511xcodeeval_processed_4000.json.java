
import java.util.*;
import java.util.function.*;
import java.io.*;



public class id12 {	
	id3 out;
	MyScanner in;
	








	final static String id7 = "id7";
	final static String id9 = "id9";
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


		
		id12 sol = new id12();
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
	    	int[] x = new int[n*2];
	    	int[] y = new int[n*2];
	    	for(int j=0; j<n*2; j++) {
	    		x[j] = in.nextInt()-1;
	    		y[j] = in.nextInt()-1;
	    	}
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			long ans = solve(n, x, y);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private long solve(int n, int[] x, int[] y) {
		

		

		

		
		final int N = n*2;
		
		int[][] neighbors = new int[N][2];
		{
			int[] idx = new int[N];
			for(int i=0; i<N; i++) {
				int u = x[i];
				int v = y[i];
				neighbors[u][idx[u]++] = v;
				neighbors[v][idx[v]++] = u;
			}
		}	
		
		ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();
		boolean[] visited = new boolean[N];
		for(int i=0; i<n; i++) {
			if(visited[i])
				continue;
			ArrayList<Integer> cycle = new ArrayList<>();
			int curr = i;
			int prev = -1;
			do {
				cycle.add(curr);
				visited[curr] = true;
				int next = neighbors[curr][0];
				if(next == prev)
					next = neighbors[curr][1];
				prev = curr;
				curr = next;
			}while(curr != i);
			cycles.add(cycle);
		}
		
		
		

		
		

		

		

		
		

		

		

		
		

		

		

		

		
		
		

		

		
		long ans = 0;
		for(var cycle: cycles) {
			int k = cycle.size();
			{
				int minX = n*2;
				int maxX = -1;
				int minY = n*2;
				int maxY = -1;
				for(int i=0; i<k; i++) {
					if(i % 2 == 0) {
						minX = Math.min(minX, cycle.get(i));
						maxX = Math.max(maxX, cycle.get(i));
					}
					else {
						minY = Math.min(minY, cycle.get(i));
						maxY = Math.max(maxY, cycle.get(i));
					}
				}
				long num = minX+1;
				num *= n-maxX;
				num *= minY-n+1;
				num *= n*2-maxY;
				
				ans += num * (k/2);
			}
			
			for(int i=0; i<k; i++) {
				int minX = n*2;
				int maxX = -1;
				int minY = n*2;
				int maxY = -1;
				if(i % 2 == 0) {
					minX = Math.min(minX, cycle.get(i));
					maxX = Math.max(maxX, cycle.get(i));
				}
				else {
					minY = Math.min(minY, cycle.get(i));
					maxY = Math.max(maxY, cycle.get(i));
				}
				int len = 1;
				for(int j=(i+1)%k; (j+1)%k!=i; j=(j+1)%k) {
					++len;
					if(j % 2 == 0) {
						minX = Math.min(minX, cycle.get(j));
						maxX = Math.max(maxX, cycle.get(j));
					}
					else {
						minY = Math.min(minY, cycle.get(j));
						maxY = Math.max(maxY, cycle.get(j));
					}
					

					

					int lMin = 0;
					int lMax = minX;
					int rMin = maxX;
					int rMax = n-1;
					
					int Lmin = n;
					int Lmax = minY;
					int Rmin = maxY;
					int Rmax = n*2-1;
					
					int prev = i > 0? cycle.get(i-1): cycle.get(k-1);
					if((i-1) % 2 == 0) {
						if(minX <= prev && prev <= maxX)
							continue;
						if(prev < minX)
							lMin = prev+1;
						else
							rMax = prev-1;
					}
					else {
						if(minY <= prev && prev <= maxY)
							continue;
						if(prev < minY)
							Lmin = prev+1;
						else
							Rmax = prev-1;
					}
					
					int next = j+1 < k? cycle.get(j+1): cycle.get(0);
					if((j+1) % 2 == 0) {
						if(minX <= next && next <= maxX)
							continue;
						if(next < minX)
							lMin = Math.max(lMin, next+1);
						else
							rMax = Math.min(rMax, next-1);
					}
					else {
						if(minY <= next && next <= maxY)
							continue;
						if(next < minY)
							Lmin = Math.max(Lmin, next+1);
						else
							Rmax = Math.min(Rmax, next-1);
					}
					
					long num = (lMax-lMin+1);
					num *= (rMax-rMin+1);
					num *= (Lmax-Lmin+1);
					num *= (Rmax-Rmin+1);
					
					ans += num * (len/2);
				}
			}
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

		int[][] id8(){
			return id8(0);
		}
		
		int[][] id8(int offset) {
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
	
	static private int[][][] id11(int n, int[][] e){
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
		id10(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id10(int[][] e) {
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