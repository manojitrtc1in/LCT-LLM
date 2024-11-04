import java.util.*;
import java.util.function.*;
import java.io.*;



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
	int[] p;
	enum Qtype{
		SWAP, ASK;
	}
	static class Query{
		Qtype t;
		int x, y;
		int i, k;
		public Query(int t, int first, int second) {
			if(t == 1) {
				this.t = Qtype.SWAP;
				x = first-1;
				y = second-1;
			}
			else {
				this.t = Qtype.ASK;
				i = first-1;
				k = second;
			}
		}
	}
	
	Query[] query;
	void getInput() {
		n = in.nextInt();
		q = in.nextInt();
		p = in.id6(n, -1);
		query = new Query[q];
		for(int i=0; i<q; i++)
			query[i] = new Query(in.nextInt(), in.nextInt(), in.nextInt());
	}
	
	void printOutput() {
		out.printlnAns(ans, 1);
	}

	ArrayList<Integer> ans;
	void solve(){
		

		
		

		

		

		
		

		

		

		

		
		

		

		
		

		

		
		

		

		
		

		

		

		

		

		
		

		

		

		
		

		

		

		

		
		

		

		
		used = new HashSet<>();
		rand = new Random();
		Node[] node = new Node[n];
		for(int i=0; i<n; i++)
			node[i] = new Node(i);
		
		boolean[] visited = new boolean[n];
		for(int i=0; i<n; i++) {
			if(visited[i])
				continue;
			int prev = -1;
			int curr = i;
			do{
				visited[curr] = true;
				if(prev != -1)
					merge(getRoot(node[prev]), node[curr]);
				prev = curr;
				curr = p[curr];
			}while(curr != i);
		}
		
		

		

		

		
		

		

		

		

		
		

		

		

		

		

		
		

		
		

		

		

		
		

		

		

		

		
		

		
		

		

		

		

		

		
		

		
		

		

		

		

		

		

		
		

		

		

		

		

		
		

		
		

		
		


		ans = new ArrayList<>();
		for(int i=0; i<q; i++) {
			if(query[i].t == Qtype.SWAP) {
				int x = query[i].x;
				int y = query[i].y;
				if(getRoot(node[x]) == getRoot(node[y])) {
					

					

					

					if(getIndex(node[x]) > getIndex(node[y])) {
						int tmp = x;
						x = y;
						y = tmp;
					}
					Node right = splitUntil(node[y]);
					Node middle = splitUntil(node[x]);
					

					
					merge(getRoot(node[x]), right);
					

				}
				else {
					

					

					

					

					

					Node xRight = splitUntil(node[x]); 

					Node yRight = splitUntil(node[y]); 

					Node root = merge(getRoot(node[x]), yRight); 

					root = merge(root, getRoot(node[y])); 

					root = merge(root, xRight); 

				}
			}
			else {
				int index = query[i].i;
				int k = query[i].k;
				Node curr = node[index];
				Node root = getRoot(curr);
				int len = root.size;
				int r = getIndex(curr);
				

				Node target = find(root, (r+k) % len);
				ans.add(target.index);
			}
		}
	}
	
	HashSet<Integer> used;
	Random rand;
	class Node{
		int index, size, priority;
		Node left, right, parent;
		public Node(int data) {
			this.index = data;
			this.size = 1;
			do {
				this.priority = rand.nextInt();
			}while(used.contains(this.priority));
			used.add(this.priority);
			this.left = null;
			this.right = null;
			this.parent = null;
		}
		public String toString() {
			return Integer.toString(index);
		}
	}
	
	public Node getRoot(Node curr) {
		if(curr.parent == null)
			return curr;
		return getRoot(curr.parent);
	}
	
	public Node merge(Node left, Node right) {
		if(left == null)
			return right;
		if(right == null)
			return left;
		if(left.priority > right.priority) {
			left.size += right.size;
			left.right = merge(left.right, right);
			left.right.parent = left;
			return left;
		}
		else {
			right.size += left.size;
			right.left = merge(left, right.left);
			right.left.parent = right;
			return right;
		}
	}
	

	
	

	public Node splitUntil(Node curr) {
		int k = getIndex(curr);
		Node root = getRoot(curr);
		return split(root, k+1).second;
	}
	
	

	public Node splitFrom(Node curr) {
		int k = getIndex(curr);
		Node root = getRoot(curr);
		return split(root, k).first;
	}
	
	class NodePair{
		Node first, second;
		public NodePair(Node first, Node second) {
			this.first = first;
			this.second = second;
		}
	}
	
	public NodePair split(Node curr, int firstSize) {
		if(firstSize <= 0)
			return new NodePair(null, curr);
		if(firstSize == curr.size)
			return new NodePair(curr, null);
		int k = 1;
		if(curr.left != null)
			k += curr.left.size;
		if(firstSize == k) {
			Node right = curr.right;
			if(curr.right != null) {
				curr.size -= curr.right.size;
				curr.right.parent = null;
				curr.right = null;
			}
			return new NodePair(curr, right);
		}
		else if(firstSize < k) {
			curr.size -= curr.left.size;
			curr.left.parent = null;
			NodePair left = split(curr.left, firstSize);
			curr.left = left.second;
			if(left.second != null) {
				left.second.parent = curr;
				curr.size += curr.left.size;
			}
			return new NodePair(left.first, curr);
		}
		else {
			curr.size -= curr.right.size;
			curr.right.parent = null;
			NodePair right = split(curr.right, firstSize-k);
			curr.right = right.first;
			if(right.first != null) {
				right.first.parent = curr;
				curr.size += curr.right.size;
			}
			return new NodePair(curr, right.second);
		}
	}
	
	

	public int getIndex(Node curr) {
		int k = 0;
		if(curr.left != null)
			k += curr.left.size;
		if(curr.parent != null) {
			if(curr.parent.right == curr)
				k += getIndex(curr.parent) + 1;
			else
				k += getIndex(curr.parent) - curr.size;
		}
		return k;
	}
	
	public Node find(Node curr, int index) {
		int k = 0;
		if(curr.left != null)
			k += curr.left.size;
		if(index == k)
			return curr;
		else if(index < k)
			return find(curr.left, index);
		else
			return find(curr.right, index-k-1);
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
		
		int[][] id9(int n, int m){
			return id9(n, m, 0);
		}
		
		int[][] id9(int n, int m, int offset){
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
		
		long[] id15(int len) {
			return id15(len, 0);
		}
		long[] id15(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
		
		String[] id13(int len) {
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
