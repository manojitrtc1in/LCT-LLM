import java.util.*;
import java.io.*;



public class Round796F {
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


		
		Round796F sol = new Round796F();
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
	    	int m = in.nextInt();
	    	
	    	int[] a = in.nextIntArray(n);
	    	int[] b = in.nextIntArray(n);
	    	
	    	int[] l = new int[m];
	    	int[] r = new int[m];
	    	
	    	for(int j=0; j<m; j++) {
	    		l[j] = in.nextInt()-1;
	    		r[j] = in.nextInt()-1;
	    	}
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			boolean ans = solve2(a, b, l, r);
			out.printAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	int[] l;
	int[] r;
	Integer[] sortedIntervals;
	TreeSet<Integer> activeIntervals;
	private boolean solve2(int[] a, int[] b, int[] l, int[] r) {
		int n = a.length;
		int m = l.length;
		
		for(int i=0; i<n; i++)
			a[i] -= b[i];
		
		

		

		

		
		

		

		

		

		
		

		

		

		

		
		

		

		

		

		
		
		

		

		

		

		
		

		

		

		

		

		
		
		

		

		

		
		

		

		

		

		

		

		
		

		
		

		

		

		

		var intervalsEndingAt = new ArrayList<ArrayList<Integer>>();
		var intervalsStartingAt = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<n; i++) {
			intervalsEndingAt.add(new ArrayList<>());
			intervalsStartingAt.add(new ArrayList<>());
		}

		long[] sum = new long[n];
		sum[0] = a[0];
		for(int i=1; i<n; i++)
			sum[i] += sum[i-1] + a[i];
		
		DSU partition = new DSU(n);
		for(int i=0; i<n; i++)
			partition.put(i, i, i);
			
		HashSet<Integer> zeroIntervals = new HashSet<Integer>();
		for(int i=0; i<m; i++) {
			boolean isLeftGood = (l[i] == 0 || sum[l[i]-1] == 0);
			boolean isRightGood = sum[r[i]] == 0;
			if(isLeftGood && isRightGood)
				zeroIntervals.add(i);
			else{


					intervalsEndingAt.get(r[i]).add(i);


					intervalsStartingAt.get(l[i]).add(i);
			}
		}
		
		int temp=1;
		
		while(!zeroIntervals.isEmpty()) {
			HashSet<Integer> nextIntervals = new HashSet<Integer>();
			for(int i: zeroIntervals) {
				int left = l[i];
				int right = r[i];
				int head = partition.find(left);
				for(int j=left; j<=right; j++) {
					int curr = partition.find(j);
					if(sum[j] != 0) {
						for(int k: intervalsEndingAt.get(j)) {
							boolean isLeftGood = (l[k] == 0 || sum[l[k]-1] == 0);
							if(isLeftGood)
								nextIntervals.add(k);
						}
						if(j < n-1)
							for(int k: intervalsStartingAt.get(j+1)) {
								boolean isRightGood = sum[r[k]] == 0;
								if(isRightGood)
									nextIntervals.add(k);
							}
					}
					sum[j] = 0;
					a[j] = 0;
					partition.union(head, curr);
					j = partition.right[curr];
				}
				partition.update(head, left, right);
			}
			zeroIntervals = nextIntervals;
		}
		
		for(int i=0; i<n; i++)
			if(a[i] != 0)
				return false;
		return true;
	}
	
	public class DSU {
		int[] size;
		int[] parents;
		int[] left;
		int[] right;
		
		public DSU(int max) {
			parents = new int[max];
			size = new int[max];
			left = new int[max];
			right = new int[max];
		}
		
		public void put(int v, int l, int r) {
			parents[v] = -1;
			size[v] = 1;
			left[v] = l;
			right[v] = r;
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
			left[larger] = Math.min(left[larger], left[smaller]);
			right[larger] = Math.max(right[larger], right[smaller]);
		}
		public int find(int v) {
			if(parents[v] == -1)
				return v;
			int head = find(parents[v]);
			parents[v] = head;
			return head;
		}
		public void update(int v, int l, int r) {
			int head = find(v);
			left[head] = Math.min(left[head], l);
			right[head] = Math.max(right[head], r);
		}
	}
	
	
	
	private boolean solve(int[] a, int[] b, int[] l, int[] r) {
		int n = a.length;
		int m = l.length;
		this.l = l;
		this.r = r;
		
		for(int i=0; i<n; i++)
			a[i] -= b[i];
		
		

		

		

		
		

		

		

		

		
		

		

		

		

		

	
		

		

		

		

		

		

		

		
		

		

		

		

		

		

		
		

		

		
		

		

		

		
		
		sortedIntervals = new Integer[m];
		for(int i=0; i<m; i++)
			sortedIntervals[i] = i;
		










		Arrays.sort(sortedIntervals, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(l[o1], l[o2]);
			}			
		});
		
		

		

		
		BinaryIndexedTree T = new BinaryIndexedTree(a);
		long XX = T.query(0, n-1);
		

		

		activeIntervals = new TreeSet<Integer>();
		
		

		int left = 0;
		for(; left<n && a[left] == 0; left++);
		int index = 0;
		index = updateIntervals(left, index);
		while(!activeIntervals.isEmpty() && left < n) {
			int right = activeIntervals.pollFirst();
			long sum = T.query(left, right);
			if(sum == 0) {
				for(int j=left; j<=right; j++) {
					T.update(j, -a[j]);
					a[j] = 0;
				}
				left = right+1;
				for(; left<n && a[left] == 0; left++);
				index = updateIntervals(left, index);
			}
		}
		if(left < n)
			return false;
		else
			return true;
		
		

		

		

	}
	
	private int updateIntervals(int left, int index) {
		int n = l.length;
		for(; index < n; index++) {
			int curr = sortedIntervals[index];
			if(l[curr] > left)
				break;
			if(r[curr] >= left)
				activeIntervals.add(r[curr]);
		}
		return index;
	}
	
	public class BinaryIndexedTree {
		long[] tree;

		BinaryIndexedTree(int[] a) {
			tree = new long[a.length];
			for(int i=0; i<a.length; i++)
				update(i, a[i]);
		}
		
		

		

		

		

		

		

		public void update(int index, int val) {
			

			for(; index < tree.length; index = index | (index+1)) {
				tree[index] += val;
			}
		}
		
		

		public long query(int r) {
			long ans = 0;
			

			for(; r >= 0; r = (r & (r+1)) -1)
				ans += tree[r];
			return ans;
		}
		
		

		public long query(int l, int r) {
			return query(r) - query(l-1);
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
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void printlnAns(int[] arr, int add){
			printAns(arr, add);
			println();
		}
		
		public void printAns(ArrayList<Integer> arr, int add) {
			if(arr != null && arr.size() > 0){
				print(arr.get(0));
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
