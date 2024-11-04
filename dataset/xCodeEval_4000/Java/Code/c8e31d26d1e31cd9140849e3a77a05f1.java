import java.util.*;
import java.util.function.*;
import java.io.*;



public class RoundEdu126F {	
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


		
		RoundEdu126F sol = new RoundEdu126F();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean isFileIO = true;
		boolean hasMultipleTests = false;
		
		initIO(isFileIO);
		
		

		








	
		int t = hasMultipleTests? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	long[] a = in.nextLongArray(n);
	    	long m = in.nextLong();
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			var ans = solve(a, m);
			out.printlnAns(ans);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {
		int n = 200_000;
		long m = 931008010;
		long[] a = new long[n];
		Random r = new Random();
		HashSet<Long> taken = new HashSet<Long>();
		for(int i=0; i<n; i++) {
			a[i] = r.nextInt(1_000_000_000);
			while(taken.contains(a[i]))
				a[i] = r.nextInt(1_000_000_000);
			taken.add(a[i]);
		}
		Arrays.sort(a);
		long time = System.currentTimeMillis();
		out.println(solve(a, m));
		out.println(System.currentTimeMillis()-time);
	}

	private int solve(long[] a, long m) {
		int n = a.length;
		long[] diffs = new long[n];
		diffs[0] = a[0];
		for(int i=1; i<n; i++)
			diffs[i] = a[i]-a[i-1];
		permutateAndSort(diffs);
		this.diffs = diffs;
		
		long low = 1;
		long high = square(a[n-1]);
		while(low < high) {
			long mid = (low+high+1)/2;
			var ret = computeEnergyUsingCostAtLeast(mid);
			long energy = ret[0];
			if(energy <= m) 

				low = mid;
			else
				high = mid-1;
		}
		var retCurr = computeEnergyUsingCostAtLeast(low);
		

		
		long currEnergy = retCurr[0];
		
		

		

		long currK = retCurr[1];
		currK -= (m-currEnergy)/low;
		return Math.max((int)currK, 0);
	}
	
	

	private long[] computeEnergyUsingCostAtLeast(long val) {
		int n = diffs.length;
		long energy = 0;
		long k = 0;
		

		for(int i=0; i<n; i++) {
			var ret = computeEnergyUsingCostAtLeast(diffs[i], val);
			energy += ret[0];
			k += ret[1];
			

		}
		return new long[] {energy, k};

	}

	

	private long[] computeEnergyUsingCostAtLeast(long diff, long val) {
		long low = 0;
		long high = diff-1;
		if(computeEnergyGivenK(diff, 1)-computeEnergyGivenK(diff, 2) < val)
			high = low;
		

		

		while(low < high) {
			long mid = (low+high+1)/2;
			long step = computeEnergyGivenK(diff, mid)-computeEnergyGivenK(diff, mid+1);
			if(step < val)
				high = mid-1;
			else 

				low = mid;
		}
		long energy = computeEnergyGivenK(diff, low+1);
		

		return new long[] {energy, low};

	}

	private long computeEnergyGivenK(long diff, long k) {
		long nextDiff = diff/k;
		long r = diff%k;
		
		long energy = square(nextDiff)*(k-r) + square(nextDiff+1)*r;
		return energy;
	}

	private int solve3(long[] a, long m) {
		int n = a.length;
		long[] diffs = new long[n];
		diffs[0] = a[0];
		for(int i=1; i<n; i++)
			diffs[i] = a[i]-a[i-1];
		permutateAndSort(diffs);
		this.diffs = diffs;
		
		long low = 1;
		long high = diffs[n-1];
		while(low < high) {
			long mid = (low+high+1)/2;
			long energy = computeEnergyDiffAtMost(mid)[0];
			if(energy <= m)
				low = mid;
			else
				high = mid-1;
		}
		if(true) {
		

			out.println(m);
			out.println(computeEnergyDiffAtMost(low)[1]);
			out.println(computeEnergyDiffAtMost(low)[0]);
			out.println(computeEnergyDiffAtMost(low+1)[1]);
			out.println(computeEnergyDiffAtMost(low+1)[0]);
		}
		
		long oldMax = low;
		long[] temp = computeEnergyDiffAtMost(low);
		
		int oldIdx = (int) temp[2];
		

		
		TreeMap<Sliced, Integer> cnt = new TreeMap<>();
		for(int i=oldIdx; i<n; i++) {
			long k = ceil(diffs[i], oldMax);
			
			

			long nextDiff = diffs[i]/k;
			long r = diffs[i]%k;
			
			long energy = square(nextDiff)*(k-r) + square(nextDiff+1)*r;
			if(k > 1)
				cnt.merge(new Sliced(diffs[i], k, energy), 1, (x, y) -> x+y);
			else
				k=k;
		}
		














		






		
		long currEnergy = temp[0];
		long currK = temp[1];
		while(!cnt.isEmpty() && currEnergy <= m) {
			

			currK--;
			var slice = cnt.firstKey();
			int cntSlice = cnt.get(slice);
			if(cntSlice == 1)
				cnt.remove(slice);
			else
				cnt.put(slice, cntSlice-1);
			
			currEnergy += slice.increaseCost;
			if(slice.k > 2) {
				cnt.merge(new Sliced(slice.diff, slice.k-1, slice.energy+slice.increaseCost), 1, (x, y) -> x+y);
			}
		}
		
		
		
		
















		if(currEnergy <= m)
			return (int) currK;
		else
			return (int)currK+1;
	}
	


















	
	static class Sliced implements Comparable<Sliced>{
		long diff;
		long k;
		long energy;
		
		long increaseCost;
		public Sliced(long diff, long k, long energy) {
			this.diff = diff;
			this.k = k;
			this.energy = energy;
			
			long increasedDiff = diff/(k-1); 

			long r = diff % (k-1);
			
			increaseCost = square(increasedDiff)*(k-1-r) + square(increasedDiff+1)*r;
			increaseCost -= energy;
		}
		@Override
		public int compareTo(RoundEdu126F.Sliced o) {
			int cmp = Long.compare(increaseCost, o.increaseCost);
			if(cmp != 0) return cmp;
			cmp = Long.compare(diff, o.diff);
			if(cmp != 0) return cmp;
			return Long.compare(k, o.k);
		}
		
	}
	
	long[] diffs;
	
	

	

	private long[] computeEnergyDiffAtMost(long mid) {
		int n = diffs.length;
		int idx = Arrays.binarySearch(diffs, mid);
		if(idx < 0) {
			

			

			idx = -idx-1;
		}
		else{
			while(idx < n && diffs[idx] == mid)
				idx++;
		}
		

		long k = 0;
		long energy = 0;
		for(int i=0; i<idx; i++) {
			energy += square(diffs[i]);
		}
		for(int i=idx; i<n; i++) {
			long curr = ceil(diffs[i], mid);
			

			
			

			

			
			

			long nextDiff = diffs[i]/curr;
			long r = diffs[i]%curr;
			
			assert(nextDiff+1 <= mid || r == 0);
			if(r > 0 && nextDiff+1 > mid) {
				curr = ceil(diffs[i], mid-1);
				nextDiff = diffs[i]/curr;
				r = diffs[i]%curr;
			}
			
			energy += square(nextDiff)*(curr-r) + square(nextDiff+1)*r;
			k += curr-1;
		}
		
		return new long[] {energy, k, idx};
	}
	
	private int solve2(long[] a, long m) {
		int n = a.length;
		
		var cntMap = new TreeMap<Long, Integer>();
		long energy = 0;
		
		for(int i=0; i<n; i++) {
			long diff = a[i]-(i==0? 0: a[i-1]);
			cntMap.merge(diff, 1, (x, y) -> x+y);
			energy += square(diff);
		}
		
		int extra = 0;
		while(energy > m) {
			long diff = cntMap.lastKey();
			long cnt = cntMap.remove(diff);
			long nextDiff = cntMap.isEmpty()? 1: cntMap.lastKey();
			
			long k = ceil(diff, nextDiff);
			long r = diff%nextDiff;
			
			

			long energy0 = energy-square(diff)*cnt;
			long nextEnergy = energy0;
			nextEnergy += square(nextDiff)*(k-r) + square(nextDiff-1)*r;
			if(nextEnergy < m) {
				long low = 1;
				long high = k;

				while(low < high) {
					long mid = (low+high)/2;
					long energyMid = computeEnergy(energy0, diff, mid);
				}
			}
			else {
				energy = nextEnergy;
				cntMap.merge(nextDiff, (int)(k-r), (x, y) -> x+y);
				if(r > 0)
					cntMap.merge(nextDiff-1, (int)r, (x, y) -> x+y);
				extra += k;
			}
		}
		
		return extra;
		
	}
	

	
	private long computeEnergy(long energy0, long diff, long k) {
		long nextDiff = diff/k;
		long r = diff%k;
		

		
		return 0;
	}

	private static long square(long x) {
		return x*x;
	}
	
	private static long ceil(long x, long y) {
		return (x+y-1)/y;
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
	
	static private void permutateAndSort(long[] a) {
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
	
	static private void drawGraph(int[][] e) {
		makeDotUndirected(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
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
