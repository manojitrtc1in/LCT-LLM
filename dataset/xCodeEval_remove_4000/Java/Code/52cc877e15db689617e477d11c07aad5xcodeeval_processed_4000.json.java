import java.util.*;
import java.util.function.*;
import java.io.*;



public class id10 {	
	id4 out;
	MyScanner in;
	








	final static String id9 = "id9";
	final static String id12 = "id12";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id8) {
        if (System.getProperty("ONLINE_JUDGE") == null && id8) {
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


		
		id10 sol = new id10();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id8 = true;
		boolean id1 = false;
		
		initIO(id8);
	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int[][] e = in.id6(n, -1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
	    	
			Answer ans = solve(n, e);
			out.println(ans.id3 + " " + ans.sumWeights);
			out.printlnAns(ans.w);
			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	
	private Answer solve(int n, int[][] e) {
		if(n == 2) {
			return new Answer(2, 2, new int[] {1,1});
		}
		
		neighbors = constructNeighborhood(n, e);
		
		

		
		nodes = new Node[n][2];
		Node node = dfs(0, -1, 0);
		
		w = new int[n];
		
		fillWeight(node);
		
		return new Answer(node.num, node.sum, w);
	}
	
	private void fillWeight(id10.Node node) {
		w[node.index] = node.chosen? neighbors[node.index].length: 1;
		
		for(Node next: node.children) {
			fillWeight(next);
		}
	}

	Node[][] nodes;
	int[][] neighbors;
	int[] w;
	
	private Node dfs(int curr, int parent, int id5) {
		if(nodes[curr][id5] != null)
			return nodes[curr][id5];
		
		Node node = new Node(curr, 0, 1, false);
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			Node ret = dfs(next, curr, 0);
			node.num += ret.num;
			node.sum += ret.sum;
			node.children.add(ret);
		}
		
		if(id5 == 0) {
			Node node2 = new Node(curr, 1, neighbors[curr].length, true);
			for(int next: neighbors[curr]) {
				if(next == parent)
					continue;
				Node ret = dfs(next, curr, 1);
				node2.num += ret.num;
				node2.sum += ret.sum;
				node2.children.add(ret);
			}
			if(node2.num > node.num) {
				node = node2;		
			}
			else if(node2.num == node.num && node2.sum < node.sum) {
				node = node2;
			}
		}
		nodes[curr][id5] = node;
		return node;
	}
	
	class Node{
		int num;
		long sum;
		boolean chosen;
		int index;
		ArrayList<Node> children;
		public Node(int index, int num, long sum, boolean chosen) {
			this.index = index;
			this.num = num;
			this.sum = sum;
			this.chosen = chosen;
			this.children = new ArrayList<Node>();
		}
	}
	
	private Answer solve2(int n, int[][] e) {
		

		

		

		
		

		

		

		
		

		

		
		

		

		

		

		
		

		

		

		

		

		

		

		
		

		

		
		if(n == 2) {
			return new Answer(2, 2, new int[] {1,1});
		}
		
		boolean[] visited = new boolean[n];
		HashSet<Integer>[] neighbors = new HashSet[n];
		for(int i=0; i<n; i++)
			neighbors[i] = new HashSet<Integer>();
		for(int i=0; i<n-1; i++) {
			neighbors[e[i][0]].add(e[i][1]);
			neighbors[e[i][1]].add(e[i][0]);
		}
		
		int[] deg = new int[n];
		for(int i=0; i<n; i++)
			deg[i] = neighbors[i].size();
		
		int[] w = Arrays.copyOf(deg, n);
		

		

		

		

		
		int num = 0;
		long sum = 0;
		
		PriorityQueue<Vertex> pq = new PriorityQueue<>(new Comparator<Vertex>() {
			@Override
			public int compare(Vertex v, Vertex u) {
				int cmp = Integer.compare(v.degree, u.degree);
				return cmp!=0? cmp: Integer.compare(w[v.index], w[u.index]);
			}
		});
		
		for(int i=0; i<n; i++) {
			if(deg[i] <= 1)
				pq.add(new Vertex(i, deg[i]));
		}
		
		

		

		

		

		
		while(!pq.isEmpty()) {
			Vertex vtx = pq.poll();
			int v = vtx.index;
			if(visited[v])
				continue;
			visited[v] = true;
			ArrayList<Integer> nb = new ArrayList<Integer>(neighbors[v]);
			
			for(int u: nb) {
				visited[u] = true;
				w[u] = 1;
				for(int x: neighbors[u]) {
					neighbors[x].remove(u);
					

					deg[x]--;
					if(deg[x] <= 1)
						pq.add(new Vertex(x, deg[x]));
				}
				neighbors[u] = null;
				sum += w[u];
			}
			num++;
			sum += w[v];
		}
		
		return new Answer(num, sum, w);
	}
	
	class Vertex{
		int index, degree;
		public Vertex(int index, int degree) {
			this.index = index;
			this.degree = degree;
		}
	}

	class Answer{
		int id3;
		long sumWeights;
		int[] w;
		public Answer(int id3, long sumWeights, int[] w) {
			this.id3 = id3;
			this.sumWeights = sumWeights;
			this.w = w;
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
		
		int[][] id6(int n, int offset){
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

		int[][] id11(){
			return id11(0);
		}
		
		int[][] id11(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id7(int len) {
			return id7(len, 0);
		}
		int[] id7(int len, int offset){
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
	
	static private void id15(long[] a) {
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
	
	static private void id15(int[] a) {
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
	
	static private int[][][] id14(int n, int[][] e){
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
