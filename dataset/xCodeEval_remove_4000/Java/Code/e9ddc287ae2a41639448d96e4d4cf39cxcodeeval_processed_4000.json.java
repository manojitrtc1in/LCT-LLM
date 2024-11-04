import java.util.*;
import java.util.function.*;
import java.io.*;



public class id6 {	
	id5 out;
	MyScanner in;
	








	final static String id10 = "id10";
	final static String id12 = "id12";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id9) {
        if (System.getProperty("ONLINE_JUDGE") == null && id9) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id5(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id5(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id6 sol = new id6();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id9 = true;
		boolean id1 = true;
		
		initIO(id9);
	
		

		
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	solve();
	    	
	    	printOutput();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private void test() {
		Random rand = new Random();
		n = 1_000_000;
		m = 5_000_000;
		a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = rand.nextInt(m)+1;
		solve();
		System.out.println(ans);
	}

	

	int n, m;
	int[] a;
	void getInput() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.id8(n);
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	int ans;
	void solve() {
		

		

		
		

		

		

		
		

		

		

		

		







		int min = m;
		boolean[] exists = new boolean[m+1];
		int[] id3 = new int[m+1];
		for(int i=0; i<n; i++) {
			min = Math.min(a[i], min);
			exists[a[i]] = true;
		}
		
		

		
		

		
		ans = m;
		int id22 = m;
		int[] id14 = new int[m+1];
		for(int minFactor=m; minFactor>=1; minFactor--) {
			boolean updated = false;
			id14[minFactor] = minFactor;
			if(exists[minFactor]) {
				

				id3[id14[minFactor]]++;
				updated = true;
			}
			
			

			if(m/minFactor >= minFactor) { 

				for(int j=minFactor*minFactor; j<=m; j+=minFactor) {
					

					

					if(exists[j]) {
						id3[id14[j]]--;
					}
					id14[j] = Math.min(id14[j], id14[j/minFactor]);
					if(exists[j]) {
						id3[id14[j]]++;
						updated = true;
					}
				}
			}
			if(updated && minFactor <= min) {
				while(id3[id22] == 0)
					id22--;
				ans = Math.min(ans, id22-minFactor);
			}
		}
	}
	
	class SegmentTree {
		BiFunction<Integer, Integer, Integer> function;
		

		int n;
		int[] tree;
		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int n) {
			this.function = function;
			this.n = n;
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			tree = new int[m];		
		}
		

		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int[] arr){	
			this.function = function;
			

			this.n = arr.length;
			
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;


			
			tree = new int[m];
			

			
			

			build(arr, 1, 0, n-1);
			
			





		}
		
		private void build(int[] arr, int treeIdx, int left, int right) {
			if(left == right) {
				tree[treeIdx] = arr[left];
				return;
			}
			
			int mid = (left+right)>>1;




			int id4 = treeIdx<<1;
			int id19 = (treeIdx<<1)+1;
			build(arr, id4, left, mid);
			build(arr, id19, mid+1, right);
			tree[treeIdx] = function.apply(tree[id4], tree[id19]);
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
			
			

			int mid = (left+right)>>1;
			int val1 = update(idx, val, treeIdx<<1, left, mid);
			int val2 = update(idx, val, (treeIdx<<1) + 1, mid+1, right);
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
			
			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				int val1 = getRange(start, mid, treeIdx<<1, left, mid);
				int val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, (treeIdx<<1)+1, mid+1, right);
		}
	}
	
	void solve2(){
		

		

		

		

		

		

		


		

		

		

		

		

		
		

		

		

		
		

		
		TreeSet<Integer> unique = new TreeSet<>();
		for(int i=0; i<n; i++)
			unique.add(a[i]);
		
		a = unique.stream().mapToInt(x->x).toArray();
		n = a.length;
		
		m = 0;
		for(int i=0; i<n; i++)
			m = Math.max(m, a[i]);
		
		id17(m);
		
		dp = new HashMap<>();
		pq = new PriorityQueue<Event>();
		
		for(int i=0; i<n; i++) {
			int val = a[i];
			int[] factor = precompute(val);
			pq.add(new Event(i, val, factor));
		}
		
		ans = m;
		MaxTree maxTree = new MaxTree(n);
		for(int i=0; i<n; i++)
			maxTree.update(i, dp.get(new Pair(a[i], 1)));
		
		LOOP:
		for(int minVal=1; minVal<m; minVal++){
			

			

			ans = Math.min(ans, maxTree.query(n-1)-minVal);
			while(pq.peek().id16() == minVal) {
				Event e = pq.poll();
				if(e.id11()) {
					pq.add(e);
					maxTree.update(e.index, dp.get(new Pair(e.value, e.id16())));
				}
				else {
					break LOOP;
				}
			}
		}
	}
	
	class MaxTree{
		int[] tree;
		int size;
		public MaxTree(int n) {
			size = n+1;
			tree = new int[size];
		}
		public void update(int idx, int val) {
			++idx;
			while(idx < size) {
				tree[idx] = Math.max(tree[idx], val);
				idx += idx & (-idx);
			}
		}
		public int query(int idx) {
			++idx;
			int val = 0;
			while(idx > 0) {
				val = Math.max(tree[idx], val);
				idx -= idx & (-idx);
			}
			return val;
		}
	}
	
	HashMap<Pair, Integer> dp;
	PriorityQueue<Event> pq;
	
	int[] precompute(int val) {
		var factorization = factorizations[val].toArray(new PrimeFactor[0]);
		int k = factorization.length;
		
		int num = 1;
		for(int i=0; i<k; i++)
			num *= factorization[i].exponent+1;
		int[] factor = new int[num];
		
		int[] exponents = new int[k];
		int[] precal = new int[k];
		for(int i=0; i<k; i++) {
			int curr = 1;
			for(int j=0; j<factorization[i].exponent; j++)
				curr *= factorization[i].prime;
			precal[i] = curr;
		}
		int curr = 1;
		for(int i=0; i<num; i++) { 
			factor[i] = curr;
			fillDP(val, curr, factorization, exponents);
			
			for(int j=k-1; j>=0; j--) {
				if(exponents[j] < factorization[j].exponent) {
					exponents[j]++;
					curr *= factorization[j].prime;
					break;
				}
				else {
					exponents[j] = 0;
					curr /= precal[j];
				}
			}
		}
		Arrays.sort(factor);
		return factor;
	}
	
	private int fillDP(int val, int minFactor, PrimeFactor[] factorization, int[] id18) {
		Pair key = new Pair(val, minFactor);
		if(dp.containsKey(key))
			return dp.get(key);
		
		int k = factorization.length;
		int num = 1;
		for(int i=0; i<k; i++)
			num *= factorization[i].exponent+1 - id18[i];
		
		int[] exponents = Arrays.copyOf(id18, k);
		int[] precal = new int[k];
		for(int i=0; i<k; i++) {
			int curr = 1;
			for(int j=id18[i]; j<factorization[i].exponent; j++)
				curr *= factorization[i].prime;
			precal[i] = curr;
		}
		
		int min = val;
		int curr = 1;
		for(int i=0; i<num; i++) {
			if(curr > 1 && curr >= minFactor && val/curr >= minFactor)
				min = Math.min(min, Math.max(curr, fillDP(val/curr, minFactor, factorization, exponents)));
				
			for(int j=k-1; j>=0; j--) {
				if(exponents[j] < factorization[j].exponent) {
					exponents[j]++;
					curr *= factorization[j].prime;
					break;
				}
				else {
					exponents[j] = id18[j];
					curr /= precal[j];
				}
			}
		}
		dp.put(key, min);
		return min;
	}

	

	class Event implements Comparable<Event>{
		int index;
		int value;
		int[] factor;
		int factorIndex;
		public Event(int index, int value, int[] factor) {
			this.index = index;
			this.value = value;
			this.factor = factor;
			factorIndex = 0;
		}
		public boolean id11() {
			if(++factorIndex < factor.length)
				return true;
			else
				return false;
		}
		public int id16() {
			return factor[factorIndex];
		}
		@Override
		public int compareTo(Event o) {
			return Integer.compare(factor[factorIndex], o.factor[o.factorIndex]);
		}
		public String toString() {
			return String.format("(%d, %d)", value, id16());
		}
	}
	
	private void id17(int max) {
		factorizations = new ArrayList[max+1];
		for(int i=1; i<=max; i++)
			factorizations[i] = new ArrayList<PrimeFactor>();
		
		factorizations[1].add(new PrimeFactor(1, 1));
		
		for(int i=2; i<=max; i++) {
			if(factorizations[i].isEmpty()) {
				factorizations[i].add(new PrimeFactor(i, 1));
				if(max / i >= i) {
					for(int j = i*i; j<= max; j+= i) {
						if(factorizations[j].isEmpty())
							factorizations[j].add(new PrimeFactor(i, 1));
					}
				}
			}
			else {
				int p = factorizations[i].get(0).prime;
				var factorization = factorizations[i/p];
				if(factorization.get(0).prime == p) {
					factorizations[i].get(0).exponent += factorization.get(0).exponent;
					factorizations[i].addAll(factorization.subList(1, factorization.size()));
				}
				else {
					factorizations[i].addAll(factorization);
				}
			}
		}
	}
	
	ArrayList<PrimeFactor>[] factorizations;
	
	class PrimeFactor{
		int prime, exponent;

		public PrimeFactor(int prime, int exponent) {
			this.prime = prime;
			this.exponent = exponent;
		}
		@Override
		public String toString() {
			return prime + "^" + exponent; 
		}
	}
	
	static class Pair implements Comparable<Pair>{
		final static long id7 = System.currentTimeMillis();
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		

		@Override
		public int hashCode() {
			

			long x = first;
			x <<= 32;
			x += second;
			x += id7;
			x += 0x9e3779b97f4a7c15l;
			x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
			x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
			return (int)(x ^ (x >> 31));
		}
		@Override
		public boolean equals(Object obj) {












			Pair other = (Pair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}


		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
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
		
		int[] id8(int len) {
			return id8(len, 0);
		}
		int[] id8(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id23(int len) {
			return id23(len, 0);
		}
		long[] id23(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id20(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id5 extends PrintWriter{
		public id5(OutputStream os) {
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
	
	static private void id21(long[] a) {
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
	
	static private void id21(int[] a) {
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
	
	static private int[][][] id15(int n, int[][] e){
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
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			outNeighbors[u][--outDegree[u]] = v;
			inNeighbors[v][--inDegree[v]] = u;
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
		
		for(int i=0; i<e.length; i++) {
			int u = e[i][0];
			int v = e[i][1];
			neighbors[u][--degree[u]] = v;
			neighbors[v][--degree[v]] = u;
		}
		
		return neighbors;
	}
	
	static private void drawGraph(int[][] e) {
		id13(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id13(int[][] e) {
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
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
		id5 out2 = null;
		 try {
			out2 = new id5(new FileOutputStream("graph.dot"));
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
