import java.util.*;
import java.util.function.*;
import java.io.*;



public class id15 {	
	id8 out;
	MyScanner in;
	








	final static String id12 = "id12";
	final static String id14 = "id14";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id11) {
        if (System.getProperty("ONLINE_JUDGE") == null && id11) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id8(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id8(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){



		

		

		

		

		
		id15 sol = new id15();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id11 = true;
		boolean id5 = false;
		
		initIO(id11);
	
		int t = id5? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}

	    	getInput();

	    	Result ans = solve();
	    	
	    	ans.print(out);
	    }
	    
	    in.close();
	    out.close();
	}
	
	

	int n, q;
	int[] a;
	void getInput() {
		n = in.nextInt();
		q = in.nextInt();
		a = in.id10(n);
	}
	
	static class Result{
		ArrayList<Long> val;
		public Result() {
			
		}
		public Result(ArrayList<Long> ans) {
			this.val = ans;
		}
		public void print(id8 out) {
			out.printlnAns(val);
		}


















	}
	
	Result solve(){
		

		

		

		
		final int INF = 2_000_000_000;
		int[] a = new int[n+2];
		for(int i=1; i<=n; i++)
			a[i] = this.a[i-1];
		a[0] = INF;
		a[n+1] = 0;
		int n = this.n+2;
		
		SegmentTree sumTree = new SegmentTree((x, y) -> x+y, n);
		TreeSet<id20> intervals = new TreeSet<>();
		{
			int i = 0;
			while(i < n) {
				int j = i+1;
				while(j < n) {
					if(a[j-1] <= a[j])
						j++;
					else
						break;
				}
				intervals.add(new id20(i, j-1));
				i = j;
			}
			for(var p: intervals){
				sumTree.update(p.first, count(p.first, p.second));
			}
		}
		
		ArrayList<Long> ans = new ArrayList<Long>();
		for(int qq=0; qq<q; qq++) {
			int t = in.nextInt();
			if(t == 1) {
				int index = in.nextInt()-1+1;
				int val = in.nextInt();
				a[index] = val;
				var p = intervals.floor(new id20(index, INF));
				int from = p.first;
				int to = p.second;
				if(index == from && a[index-1] <= a[index]) {
					intervals.remove(p);
					sumTree.update(from, 0);
					var prev = intervals.lower(new id20(index, INF));
					intervals.remove(prev);
					sumTree.update(prev.first, 0);
					from = prev.first;
					p = new id20(from, to);
					intervals.add(p);
					sumTree.update(from, count(from, to));
				}
				if(index == to && a[index] <= a[index+1]) {
					intervals.remove(p);
					sumTree.update(p.first, 0);
					var next = intervals.higher(new id20(index, INF));
					intervals.remove(next);
					sumTree.update(next.first, 0);
					to = next.second;
					p = new id20(from, to);
					intervals.add(p);
					sumTree.update(from, count(from, to));
				}
				if(index+1 <= to && a[index] > a[index+1]) {
					intervals.remove(p);
					sumTree.update(p.first, 0);
					p = new id20(from, index);
					intervals.add(p);
					intervals.add(new id20(index+1, to));
					sumTree.update(from, count(from, index));
					sumTree.update(index+1, count(index+1, to));
					to = index;
				}
				if(from <= index-1 && a[index-1] > a[index]) {
					intervals.remove(p);
					sumTree.update(p.first, 0);
					p = new id20(index, to);
					intervals.add(p);
					intervals.add(new id20(from, index-1));
					sumTree.update(from, count(from, index-1));
					sumTree.update(index, count(index, to));
					from = index;
				}
			}
			else {
				int l = in.nextInt()-1+1;
				int r = in.nextInt()-1+1;
				var from = intervals.floor(new id20(l, INF));
				var to = intervals.floor(new id20(r, INF));
				long res = sumTree.getRange(from.first, to.first);
				if(from == to) {
					res -= count(from.first, from.second);
					res += count(l, r);
				}
				else {
					res -= count(from.first, from.second);
					res += count(l, from.second);
					res -= count(to.first, to.second);
					res += count(to.first, r);	
				}
				ans.add(res);
			}
		}
		return new Result(ans);
	}
	
	long count(int from, int to) {
		long res = to-from+1;
		res *= to-from+2;
		res /= 2;
		return res;
	}
	
	class SegmentTree {
		BiFunction<Long, Long, Long> function;
		

		int n;
		long[] tree;
		public SegmentTree(BiFunction<Long, Long, Long> function, int n) {
			this.function = function;
			this.n = n;
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			tree = new long[m];		
		}

		public void update(int idx, long val){
			update(idx+1, val, 1, 1, n);
			

		}

		private long update(int idx, long val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return tree[treeIdx];
			
			

			if(left == right){
				tree[treeIdx] = val;
				return val;
			}
			
			

			int mid = (left+right)>>1;
			long val1 = update(idx, val, treeIdx<<1, left, mid);
			long val2 = update(idx, val, (treeIdx<<1) + 1, mid+1, right);
			val = function.apply(val1, val2);
			tree[treeIdx] = val;
			return val;
		}
		
		public long getRange(int start, int end){
			return getRange(start+1, end+1, 1, 1, n);
			

		}

		private long getRange(int start, int end, int treeIdx, int left, int right) {
			

			
			

			
			if(start == left && end == right)
				return tree[treeIdx];
			
			int mid = (left+right)>>1;
			if(end <= mid)
				return getRange(start, end, treeIdx<<1, left, mid);
			else if(start <= mid){
				long val1 = getRange(start, mid, treeIdx<<1, left, mid);
				long val2 = getRange(mid+1, end, (treeIdx<<1)+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, (treeIdx<<1)+1, mid+1, right);
		}
	}
	




	
	void verify() {
		for(int t=0; t<1_000_000; t++) {
			Result ans = solve();
			Result expected = id17();
			if(ans.equals(expected)) {
				solve();
			}
		}
	}
	
	Result id17() {
		return new Result();
	}
	
	static class id19 implements Iterable<Integer>{
		private int[] data;
		private int capacity;
		private int size;
		public id19(int capacity) {
			this.capacity = capacity;
			data = new int[capacity];
			size = 0;
		}
		public id19() {
			this(1);
		}
		public void add(int val) {
			if(size == capacity) {
				capacity *= 2;
				data = Arrays.copyOf(data, capacity);
			}
			data[size++] = val;
		}
		public int pop() {
			return data[--size];
		}
		public int size() {
			return size;
		}
		public void set(int index, int val) {
			data[index] = val;
		}
		public int get(int index) {
			return data[index];
		}
		public int front() {
			return data[0];
		}
		public int back() {
			return data[size-1];
		}
		public int binarySearch(int val) {
			return Arrays.binarySearch(data, 0, size, val);
		}
		public int[] toArray() {
			return Arrays.copyOf(data, size);
		}
		public String toString() {
			return Arrays.toString(Arrays.copyOf(data, size));
		}
		@Override
		public Iterator<Integer> iterator() {
			return new id1();
		}
		
		class id1 implements Iterator<Integer> {
			private int index = 0;
	        public boolean hasNext() {
	            return index < size;
	        }
	        public Integer next() {
	        	return data[index++];
	        }
	        public void remove() {
	        	throw new UnsupportedOperationException();
	        }
		}
	}
	
	final static long id9 = System.currentTimeMillis();
	static int id4(long x) {
		

		x += id9;
		x += 0x9e3779b97f4a7c15l;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9l;
		x = (x ^ (x >> 27)) * 0x94d049bb133111ebl;
		return (int)(x ^ (x >> 31));
	}
	
	static class LLPair implements Comparable<LLPair>{
		long first, second;
		public LLPair(long first, long second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id4(x);
		}
		@Override
		public boolean equals(Object obj) {
			LLPair other = (LLPair) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(LLPair o) {
			int cmp = Long.compare(first, o.first);
			return cmp != 0? cmp: Long.compare(second, o.second);
		}
	}
	
	static class id13 implements Comparable<id13>{
		long first;
		int second;
		public id13(long first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first >> 32;
			x += first << 32;
			x ^= second;
			return id4(x);
		}
		@Override
		public boolean equals(Object obj) {
			id13 other = (id13) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id13 o) {
			int cmp = Long.compare(first, o.first);
			return cmp != 0? cmp: Integer.compare(second, o.second);
		}
	}
	
	static class id20 implements Comparable<id20>{
		int first, second;
		public id20(int first, int second) {
			this.first = first;
			this.second = second;
		}
		@Override
		public int hashCode() {
			long x = first << 32;
			x ^= second;
			return id4(x);
		}
		@Override
		public boolean equals(Object obj) {
			id20 other = (id20) obj;
			return first == other.first && second == other.second;
		}
		@Override
		public String toString() {
			return "[" + first + "," + second + "]";
		}
		@Override
		public int compareTo(id20 o) {
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
		
		int[][] id0(int numRow, int numCol) {
			return id0(numRow, numCol, 0);
		}
		
		int[][] id0(int numRow, int numCol, int offset) {
			int[][] mat = new int[numRow][numCol];
			for(int i=0; i<numRow; i++) {
				for(int j=0; j<numCol; j++) {
					mat[i][j] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[][] id3(int numLine, int id7){
			return id3(numLine, id7, 0);
		}
		
		int[][] id3(int numLine, int id7, int offset){
			int[][] mat = new int[id7][numLine];
			for(int i=0; i<numLine; i++) {
				for(int j=0; j<id7; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
		}
		
		int[] id10(int len) {
			return id10(len, 0);
		}
		int[] id10(int len, int offset){
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
		
		String[] id21(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id8 extends PrintWriter{
		public id8(OutputStream os) {
			super(os);
		}
		












		
		public void printlnAns(OptionalInt ans) {
			println(ans.orElse(-1));
		}
		
		public void printlnAns(long ans) {
			println(ans);
		}
		
		public void printlnAns(int ans) {
			println(ans);
		}
		
		public void printlnAns(boolean[] ans) {
			for(boolean b: ans)
				printlnAns(b);
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
		
		public void id2(long[] arr, int split){
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
		
		public void id2(int[] arr, int split){
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
		
		public <T> void id2(ArrayList<T> arr, int split){
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
	
	static private void reverseSort(long[] a) {
		int n = a.length;
		Long[] b = new Long[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b, Collections.reverseOrder());
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void sort(long[] a) {
		int n = a.length;
		Long[] b = new Long[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b);
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void reverseSort(int[] a) {
		int n = a.length;
		Integer[] b = new Integer[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b, Collections.reverseOrder());
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void sort(int[] a) {
		int n = a.length;
		Integer[] b = new Integer[n];
		for(int i=0; i<n; i++)
			b[i] = a[i];
		Arrays.sort(b);
		for(int i=0; i<n; i++)
			a[i] = b[i];
	}
	
	static private void id22(long[] a) {
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
	
	static private void id22(int[] a) {
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
	
	static private int[][][] id18(int n, int[][] e){
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
		id16(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id16(int[][] e) {
		id8 out2 = null;
		 try {
			out2 = new id8(new FileOutputStream("graph.dot"));
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
	
	static private void id6(int[][] e) {
		id8 out2 = null;
		 try {
			out2 = new id8(new FileOutputStream("graph.dot"));
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
