import java.util.*;
import java.io.*;



public class id4 {	
	id3 out;
	MyScanner in;
	








	final static String id8 = "id8";
	final static String id10 = "id10";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id7) {
        if (System.getProperty("ONLINE_JUDGE") == null && id7) {
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


		
		id4 sol = new id4();
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
	    	int m = in.nextInt();
	    	
	    	int[][] a = in.nextMatrix(n, m, -1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
	    	

	    	
			int[] ans = solve2(a);
			
			

			

			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private ArrayList<Pair> simulate(int[][] a) {
		int n = a.length;
		int m = a[0].length;
		int size = n*m;
		int[][] neighbors = new int[n*m][];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int deg = 4;
				if(i == 0)
					deg--;
				if(i == n-1)
					deg--;
				if(j == 0)
					deg--;
				if(j == m-1)
					deg--;
				neighbors[a[i][j]] = new int[deg];
				int idx = 0;
				if(i-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i-1][j];
				if(i+1 < n)
					neighbors[a[i][j]][idx++] = a[i+1][j];
				if(j-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i][j-1];
				if(j+1 < m)
					neighbors[a[i][j]][idx++] = a[i][j+1];
			}
		}
		
		int[][] neighborsOri = new int[size][];
		for(int i=0; i<size; i++)
			neighborsOri[i] = Arrays.copyOf(neighbors[i], neighbors[i].length);
		
		HashSet<Integer> badX = new HashSet<Integer>();
		int x = -1;
		for(int i=1; i<size; i++) {
			if(!isGood(neighbors, i)) {
				badX.add(i);
				x = i;
			}
		}
		
		int numSwap = 0;
		var swaps = new ArrayList<Pair>();
		for(int i=0; i<size; i++) {
			for(int j=i+1; j<size; j++) {
				swap2(a, neighbors, i, j);
				boolean good = true;
				for(int k=0; k<size; k++)
					if(!isGood(neighbors, k)) {
						good = false;
						break;
					}
				if(good) {
					swaps.add(new Pair(i, j));
					numSwap++;
				}
				swap2(a, neighbors, i, j);
			}
		}
		out.println(numSwap);
		out.println(swaps);
		

		return swaps;
	}
	
	static class Pair{
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		@Override
		public String toString() {
			return String.format("(%d, %d)", x, y);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result;
			result = prime * result + Objects.hash(x, y);
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
			return (x == other.x && y == other.y) || (x == other.y && y == other.x);
		}
	}

	private void swap2(int[][] a, int[][] neighbors, int x, int y) {
		int n = a.length;
		int m = a[0].length;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				if(a[i][j] == x)
					a[i][j] = y;
				else if(a[i][j] == y)
					a[i][j] = x;
			}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int deg = 4;
				if(i == 0)
					deg--;
				if(i == n-1)
					deg--;
				if(j == 0)
					deg--;
				if(j == m-1)
					deg--;
				neighbors[a[i][j]] = new int[deg];
				int idx = 0;
				if(i-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i-1][j];
				if(i+1 < n)
					neighbors[a[i][j]][idx++] = a[i+1][j];
				if(j-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i][j-1];
				if(j+1 < m)
					neighbors[a[i][j]][idx++] = a[i][j+1];
			}
		}
	}

	private void test() {
		int n = 3464;
		int m = 69;
		
		int[][] a = new int[n][m];
		int k = 0;
		for(int i=0; i<n-2; i++)
			for(int j=0; j<m; j++)
				a[i][j] = k++;
		for(int j=0; j<m; j++)
			a[n-1][j] = k++;
		for(int j=0; j<m; j++)
			a[n-2][j] = k++;














		
		int[] b = solve2(a);
		out.printlnAns(b);
		out.flush();
	}

	

	private int[] solve2(int[][] a) {
		

		

		

		int n = a.length;
		int m = a[0].length;
		int size = n*m;
		int[][] neighbors = new int[n*m][];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int deg = 4;
				if(i == 0)
					deg--;
				if(i == n-1)
					deg--;
				if(j == 0)
					deg--;
				if(j == m-1)
					deg--;
				neighbors[a[i][j]] = new int[deg];
				int idx = 0;
				if(i-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i-1][j];
				if(i+1 < n)
					neighbors[a[i][j]][idx++] = a[i+1][j];
				if(j-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i][j-1];
				if(j+1 < m)
					neighbors[a[i][j]][idx++] = a[i][j+1];
			}
		}
		
		

		

		
		

		

		

		
		HashSet<Integer> badX = new HashSet<Integer>();
		int x = -1;
		for(int i=1; i<size; i++) {
			if(!isGood(neighbors, i)) {
				badX.add(i);
				x = i;
			}
		}
		
		if(badX.isEmpty())
			return new int[] {0};
		
		if(badX.size() > 10)
			return new int[] {2};
		
		

		int numSwap = 0;














		

		for(int i=0; i<size; i++) {
			swap(neighbors, x, i);
			HashSet<Integer> badCurr = new HashSet<Integer>(badX);
			if(!update(x, badCurr, neighbors)) {
				swap(neighbors, x, i);
				continue;				
			}
			if(!update(i, badCurr, neighbors)) {
				swap(neighbors, x, i);
				continue;					
			}
			if(badCurr.isEmpty()) {
				

				numSwap++;
			}
			swap(neighbors, x, i);
		}
		
		

		for(int y: neighbors[x]) {
			for(int i=0; i<x; i++) {
				swap(neighbors, y, i);
				HashSet<Integer> badCurr = new HashSet<Integer>(badX);
				if(!update(y, badCurr, neighbors)) {
					swap(neighbors, y, i);
					continue;				
				}
				if(!update(i, badCurr, neighbors)) {
					swap(neighbors, y, i);
					continue;					
				}				
				if(badCurr.isEmpty()) {
					numSwap++;
					

				}
				swap(neighbors, y, i);
			}
		}
		
		

		


		if(numSwap > 0)
			return new int[] {1, numSwap};
		else
			return new int[] {2};
	}

	private boolean update(int x, HashSet<Integer> badCurr, int[][] neighbors) {
		if(isGood(neighbors, x))
			badCurr.remove(x);
		else
			return false;
		for(int j: neighbors[x]) {
			if(isGood(neighbors, j))
				badCurr.remove(j);
			else
				return false;
		}
		return true;
	}

	boolean isGood(int[][] neighbors, int i) {
		if(i == 0)
			return true;
		for(int j: neighbors[i])
			if(j < i)
				return true;
		return false;
	}

	private int[] solve(int[][] a) {
		

		

		

		

		int n = a.length;
		int m = a[0].length;
		int size = n*m;
		int[][] neighbors = new int[n*m][];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				int deg = 4;
				if(i == 0 || i == n-1)
					deg--;
				if(j == 0 || j == m-1)
					deg--;
				neighbors[a[i][j]] = new int[deg];
				int idx = 0;
				if(i-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i-1][j];
				if(i+1 < n)
					neighbors[a[i][j]][idx++] = a[i+1][j];
				if(j-1 >= 0)
					neighbors[a[i][j]][idx++] = a[i][j-1];
				if(j+1 < m)
					neighbors[a[i][j]][idx++] = a[i][j+1];
			}
		}
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(0);
		int last = -1;
		last = makeTrip(pq, last, neighbors);

		if(last == size-1)
			return new int[] {0};
		
		

		
		

		

		

		
		
		

		

		

		

		

		

		

		

		
		
		int numSwap = 0;
		HashSet<Integer> next = new HashSet<>();
		for(int i: pq)
			next.add(i);
		int x = last+1;
		if(next.contains(x+1)) {
			

			swap(neighbors, x, x+1);
			if(id12(neighbors))
				numSwap++;
			swap(neighbors, x, x+1);
			
			

			

			int k = next.size()-1;
			last = x;
			last = makeTrip(pq, last, neighbors);
			PriorityQueue<Integer> pq2 = new PriorityQueue<Integer>(pq);
			
			boolean xFound = false;
			for(int i: neighbors[x]) {
				if(i <= last)
					xFound = true;
				if(i > last)
					pq.offer(i);
			}
			if(xFound) {
				last = makeTrip(pq, last, neighbors);
				if(last == size-1)
					numSwap += k;
			}
			
			
		}
		else {
			HashSet<Integer> candidates = new HashSet<Integer>();
			for(int y: neighbors[x+1])
				if(next.contains(y))
					candidates.add(y);
			for(int y: candidates) {
				swap(neighbors, x, y);
				if(id12(neighbors))
					numSwap++;
				swap(neighbors, x, y);
			}
		}
		for(int y: neighbors[1]) {
			swap(neighbors, 0, y);
			if(id12(neighbors))
				numSwap++;
			swap(neighbors, 0, y);		
		}
		
		if(numSwap >= 1)
			return new int[] {1, numSwap};
		else
			return new int[] {2};
	}
	
	private int makeTrip(PriorityQueue<Integer> pq, int last, int[][] neighbors) {
		while(!pq.isEmpty()) {
			int curr = pq.poll();
			if(curr == last)
				continue;
			if(curr != last+1) {
				pq.offer(curr);
				break;
			}
			for(int i: neighbors[curr])
				if(i > curr)
					pq.offer(i);
			last = curr;
		}
		return last;
	}

	private boolean id12(int[][] neighbors) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(0);
		int last = -1;
		last = makeTrip(pq, last, neighbors);

		return last == neighbors.length-1;
	}
	
	

	void swap(int[][] neighbors, int x, int y) {
		int[] neighborX = Arrays.copyOf(neighbors[x], neighbors[x].length);
		int[] neighborY = Arrays.copyOf(neighbors[y], neighbors[y].length);
		for(int i: neighborX) {
			if(i==y)
				continue;


			for(int j=0; j<neighbors[i].length; j++) {
				if(neighbors[i][j] == x)
					neighbors[i][j] = y;
				else if(neighbors[i][j] == y)
					neighbors[i][j] = x;
			}
		}
		


		for(int i: neighborY) {
			if(i==x)
				continue;


			for(int j=0; j<neighbors[i].length; j++) {
				if(neighbors[i][j] == x)
					neighbors[i][j] = y;
				else if(neighbors[i][j] == y)
					neighbors[i][j] = x;
			}
		}
		
		

		for(int j=0; j<neighborX.length; j++)
			if(neighborX[j] == y)
				neighborX[j] = x;

		for(int j=0; j<neighborY.length; j++)
			if(neighborY[j] == x)
				neighborY[j] = y;
		
		neighbors[x] = neighborY;
		neighbors[y] = neighborX;
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
		
		long[] id15(int len) {
			return id15(len, 0);
		}
		long[] id15(int len, int offset){
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
	
	static private int[][][] id13(int n, int[][] e){
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
