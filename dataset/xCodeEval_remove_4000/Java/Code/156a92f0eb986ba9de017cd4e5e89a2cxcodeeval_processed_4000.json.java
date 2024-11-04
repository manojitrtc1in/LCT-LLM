import java.util.*;
import java.util.function.*;
import java.io.*;



public class id8 {	
	id4 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id11 = "id11";
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



		

		

		

		

		
		id8 sol = new id8();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id7 = true;
		boolean id1 = false;
		
		initIO(id7);
	
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
	
	

	int n, q;
	char[] s;
	int[] pos;
	char[] ch;
	void getInput() {
		n = in.nextInt();
		q = in.nextInt();
		s = in.next().toCharArray();
		pos = new int[q];
		ch = new char[q];
		for(int i=0; i<q; i++) {
			pos[i] = in.nextInt()-1;
			ch[i] = in.next().charAt(0);
		}
	}
	
	void printOutput() {
		out.printlnAns(ans);
	}
	
	int[] ans;
	void solve(){
		

		

		

		

		
		

		

		
		

		

	
		

		

		

		

		
		

		

		

		

		
		
		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		

		

		

		

		

		

		

		

		

		
		

		

		ans = new int[q];
		SegmentTree sumTree = new SegmentTree(s);
		for(int i=0; i<q; i++) {
			s[pos[i]] = ch[i];
			sumTree.update(pos[i], ch[i]);
			ans[i] = sumTree.query();
		}
	}
	
	class SegmentTree {
		int n;
		int[] tree1, tree2, tree3, tree12, tree23, tree123;
		
		public SegmentTree(char[] arr){
			this.n = arr.length;
			
			int m = n<=1? 8: Integer.highestOneBit(n-1)*4;
			
			tree1 = new int[m];
			tree2 = new int[m];
			tree3 = new int[m];
			tree12 = new int[m];
			tree23 = new int[m];
			tree123 = new int[m];	
			
			build(arr, 1, 0, n-1);
		}
		
		private void recalculate(int treeIdx) {
			int left = treeIdx<<1;
			int right = (treeIdx<<1)+1;
			
			tree1[treeIdx] = tree1[left] + tree1[right];
			tree2[treeIdx] = tree2[left] + tree2[right];
			tree3[treeIdx] = tree3[left] + tree3[right];
			tree12[treeIdx] = Math.min(tree1[left] + tree2[right], tree1[left] + tree12[right]);
			tree12[treeIdx] = Math.min(tree12[treeIdx], tree12[left] + tree2[right]);
			tree23[treeIdx] = Math.min(tree2[left] + tree3[right], tree2[left] + tree23[right]);
			tree23[treeIdx] = Math.min(tree23[treeIdx], tree23[left] + tree3[right]);
			tree123[treeIdx] = Math.min(tree1[left] + tree23[right], tree12[left] + tree3[right]);
			tree123[treeIdx] = Math.min(tree123[treeIdx], tree123[left] + tree3[right]);
			tree123[treeIdx] = Math.min(tree123[treeIdx], tree1[left] + tree123[right]);
			tree123[treeIdx] = Math.min(tree123[treeIdx], tree1[left] + tree3[right]);
			tree123[treeIdx] = Math.min(tree123[treeIdx], tree12[left] + tree23[right]);
		}
		
		private void build(char[] arr, int treeIdx, int left, int right) {
			if(left == right) {
				

				

				switch(arr[left]) {
				case 'a':
					tree1[treeIdx] = 1;
					break;
				case 'b':
					tree2[treeIdx] = 1;
					break;
				case 'c':
					tree3[treeIdx] = 1;
					break;
				}	
				return;
			}
			
			int mid = (left+right)>>1;
			int id3 = treeIdx<<1;
			int id14 = (treeIdx<<1)+1;
			build(arr, id3, left, mid);
			build(arr, id14, mid+1, right);
			recalculate(treeIdx);
		}

		public void update(int idx, char val){
			update(idx, val, 1, 0, n-1);
		}

		private void update(int idx, char val, int treeIdx, int left, int right) {
			

			if(left > idx || idx > right)
				return;
			
			

			if(left == right){
				switch(val) {
				case 'a':
					tree1[treeIdx] = 1;
					tree2[treeIdx] = 0;
					tree3[treeIdx] = 0;
					break;
				case 'b':
					tree1[treeIdx] = 0;
					tree2[treeIdx] = 1;
					tree3[treeIdx] = 0;
					break;
				case 'c':
					tree1[treeIdx] = 0;
					tree2[treeIdx] = 0;
					tree3[treeIdx] = 1;
					break;
				}
				return;
			}
			
			

			int mid = (left+right)>>1;
			update(idx, val, treeIdx<<1, left, mid);
			update(idx, val, (treeIdx<<1) + 1, mid+1, right);
			recalculate(treeIdx);
		}
		
		public int query() {
			int res = Math.min(tree1[1], tree2[1]);
			res = Math.min(res, tree3[1]);
			res = Math.min(res, tree12[1]);
			res = Math.min(res, tree23[1]);
			res = Math.min(res, tree123[1]);
			return res;
		}
	}
	 




	
	static class Pair implements Comparable<Pair>{
		final static long id5 = System.currentTimeMillis();
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
			x += id5;
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
		
		int[][] id10(int n, int m){
			return id10(n, m, 0);
		}
		
		int[][] id10(int n, int m, int offset){
			int[][] mat = new int[m][n];
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					mat[j][i] = nextInt()+offset;
				}
			}
			return mat;
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
		
		long[] id17(int len) {
			return id17(len, 0);
		}
		long[] id17(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id15(int len) {
			String[] s = new String[len];
			for(int i=0; i<len; i++)
				s[i] = next();
			return s;
		}
	}
	
	public static class id4 extends PrintWriter{
		public id4(OutputStream os) {
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
	
	static private void id16(long[] a) {
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
	
	static private void id16(int[] a) {
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
		id12(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id12(int[][] e) {
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
