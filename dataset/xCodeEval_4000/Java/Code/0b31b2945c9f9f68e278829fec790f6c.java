import java.util.*;
import java.io.*;



public class RoundGlobal20F2 {	
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


		
		RoundGlobal20F2 sol = new RoundGlobal20F2();
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
	    	int[] b = in.nextIntArray(n);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			boolean ans = solve(a, b);
			if(ans)
				out.println("AC");
			else
				out.println("WA");
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private boolean solve(int[] a, int[] b) {
		

		

		

		


		int n = a.length;
		int[] outDeg = new int[n+1];
		int[][] outNb = new int[n+1][];
		for(int i=0; i<n; i++) {
			outDeg[a[i]]++;
		}
		int maxFrequentVal = 0;
		for(int i=1; i<=n; i++) {
			if(outDeg[i] > outDeg[maxFrequentVal])
				maxFrequentVal = i;
		}
		for(int i=0; i<n; i++) {
			if(b[i] == maxFrequentVal)
				outDeg[a[i]]--;
		}
		outDeg[maxFrequentVal] = 0;
		
		for(int i=1; i<=n; i++)
			outNb[i] = new int[outDeg[i]];
		
		int[] inDeg = new int[n+1];
		int[] idx = new int[n+1];
		for(int i=0; i<n; i++) {
			if(b[i] == maxFrequentVal || a[i] == maxFrequentVal)
				continue;
			outNb[a[i]][idx[a[i]]++] = b[i];
			inDeg[b[i]]++;
		}
		
		ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
		for(int i=1; i<=n; i++) {
			if(inDeg[i] == 0)
				queue.add(i);
		}
		
		while(!queue.isEmpty()) {
			int curr = queue.pollFirst();
			for(int next: outNb[curr]) {
				if(inDeg[next] == 0)
					return false;
				inDeg[next]--;
				if(inDeg[next] == 0)
					queue.addLast(next);
			}
		}
		
		for(int i=1; i<=n; i++)
			if(inDeg[i] != 0)
				return false;
		
		return true;
	}

	private boolean solve2(int[] a, int[] b) {
		

		

		
		

		

		

		

		
		

		

		

		

		
		this.a = a;
		this.b = b;
		int n = a.length;
		invertedA = new HashSet[n+1];
		invertedB = new HashSet[n+1];
		for(int i=1; i<=n; i++) {
			invertedA[i] = new HashSet<Integer>();
			invertedB[i] = new HashSet<Integer>();
		}
		
		for(int i=0; i<n; i++) {
			invertedA[a[i]].add(i);
			invertedB[b[i]].add(i);
		}
		
		HashSet<Integer> maxInvertedA = invertedA[1];
		maxFrequentVal = 1;
		for(int i=2; i<=n; i++) {
			if(invertedA[i].size() > maxInvertedA.size()) {
				maxInvertedA = invertedA[i];
				maxFrequentVal = i;
			}
		}
		
		for(int i: invertedA[maxFrequentVal]) {
			

		}
		invertedA[maxFrequentVal].clear();
		
		for(int i: invertedB[maxFrequentVal]) {
			

			

			invertedA[a[i]].remove(i);
		}
		invertedB[maxFrequentVal].clear();
		
		ArrayDeque<Integer> queue = new ArrayDeque<>();
		visited = new boolean[n];
		int[] inDeg = new int[n];
		for(int i=0; i<n; i++) {
			if(b[i] == maxFrequentVal)
				continue;
			inDeg[i] = invertedB[a[i]].size();
			if(inDeg[i] == 0)
				queue.add(i);
		}
		
		boolean[] used = new boolean[n+1];
		while(!queue.isEmpty()) {
			int curr = queue.pollFirst();
			for(int next: invertedA[b[curr]]) {
				if(b[next] == maxFrequentVal)
					continue;
				if(inDeg[next] == 0)
					return false;
				inDeg[next] --;
				if(inDeg[next] == 0)
					queue.addLast(next);
			}
		}
		
		used = used;

		for(int i=0; i<n; i++)
			if(b[i] != maxFrequentVal && inDeg[i] != 0)
				return false;
		
		return true;
		














		










		


	}
	
	HashSet<Integer>[] invertedA;
	HashSet<Integer>[] invertedB;
	int maxFrequentVal;
	int[] a;
	int[] b;
	boolean[] visited;
	private boolean dfs(int curr) {
		if(visited[curr])
			return false;
		visited[curr] = true;
		for(int next: invertedA[b[curr]]) {
			if(b[next] == maxFrequentVal)
				continue;
			if(!dfs(next))
				return false;
		}
		return true;
	}
	
	private int computeSadness(int[] a, int[] b) {
		int n = a.length;
		int sadness = 0;




		

		
		

		

		

		

		

		
		

		

		
		

		

		
		

		

		

		

		
		

		

		
		

		

		








































		
		
		
		

		

		

		

		

		
		

		

		

		

		
		HashSet<Integer>[] invertedA = new HashSet[n+1];
		for(int i=1; i<=n; i++) {
			invertedA[i] = new HashSet<Integer>();
		}
		
		for(int i=0; i<n; i++) {
			invertedA[a[i]].add(i);
		}

		

		

		
		ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
		boolean[] visited = new boolean[n];
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		ArrayList<ArrayList<Integer>> cycles = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0; i<n; i++) {
			if(visited[i])
				continue;
			queue.add(i);
			while(!queue.isEmpty()) {
				int curr = queue.pollFirst();
				visited[curr] = true;
				for(int next: invertedA[b[i]]) {
					prev[next] = curr;
					if(visited[next]) {
						var cycle = new ArrayList<Integer>();
						cycle.add(next);
						while(curr != next) {
							curr = prev[curr];
							cycle.add(curr);
						}
						cycles.add(cycle);
					}
					else
						queue.add(next);
				}
			}
		}
		

		sadness = n-cycles.size();
		
		return sadness;
	}
	














































































































			
	private int computeSadness2(int[] a, int[] b) {
		int n = a.length;
		
		HashSet<Integer>[] invertedA = new HashSet[n+1];
		HashSet<Integer>[] invertedB = new HashSet[n+1];
		for(int i=1; i<=n; i++) {
			invertedA[i] = new HashSet<Integer>();
			invertedB[i] = new HashSet<Integer>();
		}
		
		for(int i=0; i<n; i++) {
			if(a[i] == b[i])
				continue;
			invertedA[a[i]].add(i);
			invertedB[b[i]].add(i);
		}
		
		int sadness = 0;
		
		HashMap<Long, HashSet<Integer>> intersections = new HashMap<>();
		for(int i=0; i<n; i++) {
			if(a[i] == b[i]) {
			}
			else {
				sadness++;

				

				

				HashSet<Integer> intersection = intersections.get(pack(a[i], b[i]));
				if(intersection == null) {
					intersection = new HashSet<>(invertedA[b[i]]);
					intersection.retainAll(invertedB[a[i]]);
					intersections.put(pack(a[i], b[i]), intersection);
					
				}
				if(!intersection.isEmpty()) {
					var iter = intersection.iterator();
					int j = iter.next(); iter.remove();
					swap(b, i, j);
					invertedB[a[i]].remove(j);
					invertedA[b[i]].remove(j);
					invertedA[a[i]].remove(i);
					invertedB[b[i]].remove(i);
				}
			}
		}
		
		return sadness;
	}
	
	private void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	private long pack(int a, int b) {
		return (long)a << 32 + b;
	}

	private int[] computeWorst(int[] a) {
		int n = a.length;
		
		Integer[] sortedIdx = new Integer[n];
		for(int i=0; i<n; i++)
			sortedIdx[i] = i;
		Arrays.sort(sortedIdx, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(a[o1], a[o2]);
			}
		});
		
		ArrayList<Pair> cycles = new ArrayList<>();
		
		int start = 0;
		while(start < n) {
			int end = start+1;
			while(end < n && a[sortedIdx[start]] == a[sortedIdx[end]])
				end++;
			cycles.add(new Pair(a[sortedIdx[start]], end-start));
			start = end;
		}
		
		if(cycles.size() == 1)
			return a;
		
		start = 0;
		for(int i=1; i<cycles.size(); i++) {
			if(cycles.get(i).len > cycles.get(start).len)
				start = i;
		}

		int[] b = new int[n];
		int idx = 0;

		for(int i=0; i<start; i++)
			idx += cycles.get(i).len;
		
		int i = start+1;
		do {
			i = i==cycles.size()? 0: i;
			int val = cycles.get(i).val;
			int len = cycles.get(i).len;
			for(int j=0; j<len; j++)
				b[sortedIdx[j+idx<n? j+idx: j+idx-n]] = val;
			idx += len;
			idx = idx>=n? idx-n: idx;
			
			i++;
		}while(i != start+1);
		
		

		

		
		

		

		
		
		

		

		

		

		

		
		return b;
	}
	
	static class Pair{
		int val;
		int len;
		public Pair(int val, int len) {
			this.val = val;
			this.len = len;
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
