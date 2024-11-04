import java.util.*;
import java.util.function.*;
import java.io.*;
import java.lang.reflect.Array;



public class id0 {	
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


		
		id0 sol = new id0();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id7 = true;
		boolean id2 = false;
		
		initIO(id7);
		
		

	
		int t = id2? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int q = in.nextInt();
	    	int d = in.nextInt();
	    	int[] a = in.id6(q);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			long[] ans = solve(a, d);
			out.id1(ans, 1);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}

	private void test() {
		int N = 200_000;
		Random r = new Random();
		int[] a = new int[N];
		int d = 100;
		

		for(int i=0; i<N; i++) {
			a[i] = r.nextInt(MAX)+1;
		}
		solve(a, d);
		

	}
	
	final int MAX = 200_000;
	


	
	private long[] solve(int[] a, int d) {
		int q = a.length;
		long[] ans = new long[q];
		
		SegmentTree segTree = new SegmentTree(MAX+1);
		RangeTree cntTree = new RangeTree(MAX+2);
		

		boolean[] used = new boolean[MAX+1];
		if(a[0] > 1)
			segTree.rangeAdd(Math.max(1, a[0]-d), a[0]-1, 1);
		segTree.activate(a[0]);
		cntTree.add(a[0], 1);
		used[a[0]] = true;

		for(int i=1; i<q; i++) {
			boolean flip;
			int val = a[i];
			
			int leftL = Math.max(1, val-d);
			int rightL = val-1;
			
			if(used[val]) {
				used[val] = false; 

				flip = true;
				segTree.deactivate(val);
				if(val > 1)
					segTree.rangeAdd(leftL, rightL, -1);
				cntTree.add(val, -1);
			}
			else {
				used[val] = true; 

				flip = false;
				if(val > 1)
					segTree.rangeAdd(leftL, rightL, 1);
				segTree.activate(val);
				cntTree.add(val, 1);
			}
			
			long sum = 0;
			
			if(val > 1) {
				

				

				

				

				

				

				

				
				


				sum += segTree.getRange(leftL, rightL);

			}

			if(!flip)
				sum -= cntTree.range(leftL, rightL);


		
			

			

			

			

			

			
			

			

			

			

			

			

			
			

			

			

			

			
			

			

			

			

			

			

			
			if(val < MAX) {
				int leftR = val+1;
				int rightR = Math.min(MAX, val+d);
	
				long cntR = cntTree.range(leftR, rightR);
				
				sum += cntR*(cntR-1)/2;
			}
			
			ans[i] = ans[i-1] + (flip? -sum: sum);
		}
		
		return ans;
	}
	
	class SegmentTree {
		

		private int n;
		

		

		private long[] lazy;
		private long[] activatedTree;
		private int[] numActivated;
		public SegmentTree(int n) {
			this.n = n;
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			

			

			lazy = new long[m];
			activatedTree = new long[m];
			numActivated = new int[m];
		}
		
		public void activate(int idx) {
			activate(idx, true);
		}
		public void deactivate(int idx) {
			activate(idx, false);
		}
		
		private void activate(int idx, boolean toActivate) {
			getRange(idx, idx);
			activate(idx, 1, 0, n-1, toActivate);
		}
		
		private long activate(int idx, int treeIdx, int left, int right, boolean toActivate) {
			if(left == right) {
				





				if(toActivate) {
					activatedTree[treeIdx] += lazy[treeIdx];
					lazy[treeIdx] = 0;
					numActivated[treeIdx] = 1;
				}
				else {
					lazy[treeIdx] += activatedTree[treeIdx];
					activatedTree[treeIdx] = 0;
					numActivated[treeIdx] = 0;
				}
				return activatedTree[treeIdx];
			}
			
			int mid = (left+right)/2;
			long valL, valR;
			if(idx <= mid) {
				valL = activate(idx, treeIdx*2, left, mid, toActivate);
				valR = activatedTree[treeIdx*2+1] + lazy[treeIdx*2+1]*numActivated[treeIdx*2+1];
			}
			else {
				valL = activatedTree[treeIdx*2] + lazy[treeIdx*2]*numActivated[treeIdx*2];
				valR = activate(idx, treeIdx*2+1, mid+1, right, toActivate);
			}




			


			numActivated[treeIdx] += toActivate? 1: -1;
			activatedTree[treeIdx] = valL + valR;
			
			return activatedTree[treeIdx] + lazy[treeIdx]*numActivated[treeIdx];
		}
		
		public void rangeAdd(int start, int end, long val) {
			rangeAdd(start, end, val, 1, 0, n-1);
		}
		
		private long rangeAdd(int start, int end, long val, int treeIdx, int left, int right) {
			if(left == right) {
				





				lazy[treeIdx] += val;
				return activatedTree[treeIdx] + lazy[treeIdx]*numActivated[treeIdx];
			}
			
			if(left == start && right == end) {
				

				lazy[treeIdx] += val;
				



				return activatedTree[treeIdx] + lazy[treeIdx]*numActivated[treeIdx];
			}
			
			int mid = (left+right)/2;
			long valL, valR;
			if(end <= mid) {
				valL = rangeAdd(start, end, val, treeIdx*2, left, mid);
				valR = activatedTree[treeIdx*2+1] + lazy[treeIdx*2+1]*numActivated[treeIdx*2+1];
			}
			else if(start <= mid) {
				valL = rangeAdd(start, mid, val, treeIdx*2, left, mid);
				valR = rangeAdd(mid+1, end, val, treeIdx*2+1, mid+1, right);
			}
			else {
				valL = activatedTree[treeIdx*2] + lazy[treeIdx*2]*numActivated[treeIdx*2];
				valR = rangeAdd(start, end, val, treeIdx*2+1, mid+1, right);
			}
			activatedTree[treeIdx] = valL + valR; 

			return activatedTree[treeIdx] + lazy[treeIdx]*numActivated[treeIdx];
		}
		













































































		public long getRange(int start, int end){
			return getRange(start, end, 1, 0, n-1);
			

		}

		private long getRange(int start, int end, int treeIdx, int left, int right) {
			


			

			if(start == left && end == right) {
				

				return numActivated[treeIdx]*lazy[treeIdx] + activatedTree[treeIdx];
			}
			
			if(lazy[treeIdx] != 0) {


				activatedTree[treeIdx] += numActivated[treeIdx]*lazy[treeIdx];
				lazy[treeIdx*2] += lazy[treeIdx];
				lazy[treeIdx*2+1] += lazy[treeIdx];
				lazy[treeIdx] = 0;
			}

			int mid = (left+right)/2;
			if(end <= mid)
				return getRange(start, end, treeIdx*2, left, mid);
			else if(start <= mid){
				long val1 = getRange(start, mid, treeIdx*2, left, mid);
				long val2 = getRange(mid+1, end, treeIdx*2+1, mid+1, right);
				return val1 + val2;
			}
			else
				return getRange(start, end, treeIdx*2+1, mid+1, right);
		}
	}
	
	
	private long[] solve2(int[] a, int d) {
		int q = a.length;
		long[] ans = new long[q];
		
		

		

		

		

		

		

		

		

		

		

		

		
		

		

		
		RangeTree T = new RangeTree(MAX+2);
		boolean[] used = new boolean[MAX+1];
		T.add(a[0], 1);
		used[a[0]] = true;

		for(int i=1; i<q; i++) {
			boolean flip;
			int val = a[i];
			if(used[val]) {
				used[val] = false; 

				flip = true;
				T.add(val, -1);
			}
			else {
				used[val] = true;
				flip = false;
				T.add(val, 1);
			}
			int leftL = Math.max(0, val-d);
			int rightL = Math.max(0, val-1);
			
			int leftR = Math.min(MAX+1, val+1);
			int rightR = Math.min(MAX+1, val+d);
			
			long cntL = T.range(leftL, rightL);
			long cntR = T.range(leftR, rightR);
			

			

			
			

			
			

			

			

			

			

			
			

			

			
			
			

			

			

			

			
			


			long sum = rec(leftL+1, rightL+1, leftR-1, rightR-1, T, d);
			
			sum += cntL*(cntL-1)/2;
			sum += cntR*(cntR-1)/2;
			ans[i] = ans[i-1] + (flip? -sum: sum);
		}
		
		return ans;
	}
	
	private long rec(int leftL, int rightL, int leftR, int rightR, id0.RangeTree T, int d) {
		if(rightR - leftL <= d) {
			long cntL = T.range(leftL, rightL);
			long cntR = T.range(leftR, rightR);
			return cntL * cntR;
		}
		else if(rightL - leftR > d) {
			return 0;
		}






		else if(leftL == rightL) {
			int midR = (leftR + rightR)/2;
			return rec(leftL, rightL, leftR, midR, T, d) + rec(leftL, rightL, midR+1, rightR, T, d);
		}








		else if(leftR == rightR) {
			int midL =  (leftL + rightL)/2;
			return rec(leftL, midL, leftR, rightR, T, d) + rec(midL+1, rightL, leftR, rightR, T, d);
			
		}
		else {
			int midL = (leftL + rightL)/2;
			int midR = (leftR + rightR)/2;
			return rec(leftL, midL, leftR, midR, T, d)
					+ rec(midL+1, rightL, leftR, midR, T, d)
					+ rec(leftL, midL, midR+1, rightR, T, d)
					+ rec(midL+1, rightL, midR+1, rightR, T, d);
		}
	}

	class RangeTree{
		int[] a;
		public RangeTree(int max) {
			a = new int[max+1];
		}

		public void add(int index, int val) {
			index++;
			while(index < a.length) {
				a[index] += val;
				index += index & (-index);
			}
		}
		
		

		public int range(int l, int r) {
			return range(r+1) - range(l);
		}
		
		

		private int range(int r) {
			int ans = 0;
			while(r > 0) {
				ans += a[r];
				r -= r & (-r);
			}
			return ans;
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
		
		public void id1(long[] arr, int split){
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
		
		public void id1(int[] arr, int split){
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
		
		public <T> void id1(ArrayList<T> arr, int split){
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
	
	static private void id3(int[][] e) {
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
