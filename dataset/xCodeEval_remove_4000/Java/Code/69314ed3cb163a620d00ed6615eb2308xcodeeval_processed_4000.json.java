import java.util.*;
import java.util.function.*;
import java.io.*;



public class id13 {	
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


		
		id13 sol = new id13();
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
	    	int k = in.nextInt();
	    	int[][]  v = in.nextMatrix(n, n);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			String[] ans = solve(v, n, k);
			for(String s: ans)
				out.println(s);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		int n = 400;
		int m = n*n;
		int k = 200;
		int[] a = randomPermutation(0, m-1);
		int[][] v = new int[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				v[i][j] = a[i*n+j];
		
		solve(v, n, k);
	}
	
	private int[] randomPermutation(int start, int end) {
		int n = end-start+1;
		Random r = new Random();
		int[] a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = i+start;
		for(int i=1; i<n; i++) {
			int j = r.nextInt(n-i);
			int temp = a[n-i];
			a[n-i] = a[j];
			a[j] = temp;
		}
		return a;
	}
	
	private String[] solve(int[][] v, int n, int k) {
		

		

		

		

		

		

		

		

		

		
		int[] id3 = new int[n*n+1];
		int[] id15 = new int[n*n+1];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				id3[v[i][j]] = i;
				id15[v[i][j]] = j;
			}
		
		PriorityQueue<Point>[] pqs = new PriorityQueue[4];
		pqs[0] = new PriorityQueue<Point>(new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.r+o1.c, o2.r+o2.c);
			}
		});
		pqs[1] = new PriorityQueue<Point>(new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.r-o1.c, o2.r-o2.c);
			}
		});
		pqs[2] = new PriorityQueue<Point>(new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(o1.c-o1.r, o2.c-o2.r);
			}
		});
		pqs[3] = new PriorityQueue<Point>(new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Integer.compare(-o1.r-o1.c, -o2.r-o2.c);
			}
		});
		
		boolean[][] win = new boolean[n][n];
		{
			int r = id3[n*n];
			int c = id15[n*n];
			for(var pq: pqs)
				pq.add(new Point(r, c));
			win[r][c] = true;
		}
		
		for(int curr = n*n-1; curr >=1; curr--) {
			int r = id3[curr];
			int c = id15[curr];
			Point[] ps = new Point[4];
			for(int i=0; i<4; i++)
				ps[i] = pqs[i].peek();
			
			int dist = 0;
			for(int i=0; i<4; i++)
				dist = Math.max(dist, Math.abs(ps[i].r-r) + Math.abs(ps[i].c-c));
			if(dist <= k) {
				for(var pq:pqs)
					pq.add(new Point(r, c));
				win[r][c] = true;
			}
		}
		
		String[] ans = new String[n];
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			sb.setLength(0);
			for(int j=0; j<n; j++) {
				if(win[i][j])
					sb.append('M');
				else
					sb.append('G');
			}
			ans[i] = sb.toString();
		}
		
		return ans;
	}
	
	class Point{
		int r, c;
		public Point(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	
	

	

	

	

	
	private String[] solve2(int[][] v, int n, int k) {
		

		

		
		

		

		

		

		

		
		

		

		

		
		

		

		

		

		

		
		

		

		
		

		

		

		

		

		
		

		

		

		

		

		
		

		

		

		

		

		
		

		

		

		

		

		
		

		

		

		
		

		

		

		
		int[] id3 = new int[n*n+1];
		int[] id15 = new int[n*n+1];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				id3[v[i][j]] = i;
				id15[v[i][j]] = j;
			}
		
		boolean[][] win = new boolean[n][n];
		
		TreeSet<Integer> alivePoints = new TreeSet<>();
		TreeSet<Integer> maximumPoints = new TreeSet<>();
		int max = n*n;
		int r = id3[max];
		int c = id15[max];
		for(int i=r-k; i<=r+k; i++) {
			int rest = k-Math.abs(i-r);
			for(int j=c-rest; j<=c+rest; j++) {
				if(i >= 0 && i < n && j >=0 && j < n)
					alivePoints.add(v[i][j]);
			}
		}
		alivePoints.remove(max);
		maximumPoints.add(max);
		win[r][c] = true;
		
		

		

		

		

		

		

		

		
		while(!alivePoints.isEmpty()) {
			max = alivePoints.pollLast();
			r = id3[max];
			c = id15[max];
			
			int minDist = Integer.MAX_VALUE;
			int closest = -1;
			for(int removed: maximumPoints) {
				int rr = id3[removed];
				int cc = id15[removed];
				int d = Math.abs(r-rr) + Math.abs(c-cc);
				if(d < minDist) {
					closest = removed;
					minDist = d;
				}
			}
			int originR = id3[closest];
			int originC = id15[closest];
			
			

			
			for(int dist = k-minDist; dist <=k; dist++) {
				for(int i=originR-dist; i<=originR+dist; i++) {
					int j; 

					j = originC + dist - Math.abs(i-originR);
					if(i >= 0 && i < n && j >=0 && j < n && Math.abs(i-r) + Math.abs(j-c) > k)
						alivePoints.remove(v[i][j]);
					j = originC - dist + Math.abs(i-originR);
					if(i >= 0 && i < n && j >=0 && j < n && Math.abs(i-r) + Math.abs(j-c) > k)
						alivePoints.remove(v[i][j]);
				}
			}
			
			win[r][c] = true;
			maximumPoints.add(max);
		}
		
		String[] ans = new String[n];
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			sb.setLength(0);
			for(int j=0; j<n; j++) {
				if(win[i][j])
					sb.append('M');
				else
					sb.append('G');
			}
			ans[i] = sb.toString();
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
		
		long[] id16(int len) {
			return id16(len, 0);
		}
		long[] id16(int len, int offset){
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
	
	static private void id14(long[] a) {
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
	
	static private void id14(int[] a) {
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
