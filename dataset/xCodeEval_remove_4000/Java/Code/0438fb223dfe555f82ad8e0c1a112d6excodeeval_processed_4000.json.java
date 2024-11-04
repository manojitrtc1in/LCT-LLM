import java.util.*;
import java.util.function.*;
import java.io.*;



public class id20 {	
	id7 out;
	MyScanner in;
	








	final static String id15 = "id15";
	final static String id17 = "id17";
	final static String YES = "YES";
	final static String NO = "NO";
	
    private void initIO(boolean id13) {
        if (System.getProperty("ONLINE_JUDGE") == null && id13) {
        	try{
	            in = new MyScanner(new FileInputStream("input.txt"));
	            out = new id7(new FileOutputStream("output.txt"));
        	}
        	catch(FileNotFoundException e){
        		e.printStackTrace();
        	}
        }
        else{
    		in = new MyScanner(System.in);
    	    out = new id7(new BufferedOutputStream(System.out));
        }
    }
	
	public static void main(String[] args){


		
		id20 sol = new id20();
		sol.run();
    }
	
	private void run() {
		boolean isDebug = false;
		boolean id13 = true;
		boolean id1 = false;
		
		initIO(id13);
	
		int t = id1? in.nextInt() : 1;
	    
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int[] a = in.id12(n);
	    	int[][] e = in.id8(n, -1);
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			int ans = solve(n, a, e);
			out.printlnAns(ans);
	    }
	    
	    in.close();
	    out.close();
	}

	private int solve(int n, int[] a, int[][] e) {
		

		

		
		

		

		

		

		
		

		

		

		
		

		

		

		

		
		

		

		

		
		

		

		
		


		
		

		

		
		
		

		

		

		

		
		

		

		

		

		

		

		

		
		this.a = a;
		id22 = new int[n];
		neighbors = new HashSet[n];
		for(int i=0; i<n; i++)
			neighbors[i] = new HashSet<Integer>();
		for(int i=0; i<e.length; i++) {
			neighbors[e[i][0]].add(e[i][1]);
			neighbors[e[i][1]].add(e[i][0]);
		}
		
		id4(0, -1, 0);
		
		ans = 0;
		dfs(0, -1);
		
		return ans;
	}
	
	int[] id22;
	private void id4(int curr, int parent, int xor) {
		xor ^= a[curr];
		id22[curr] = xor;
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			id4(next, curr, xor);
		}
	}
	
	int ans;
	private HashSet<Integer> dfs(int curr, int parent) {
		

		

		
		boolean id3 = false;
		HashSet<Integer> largest = new HashSet<>();
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			var set = dfs(next, curr);
			if(!id3) {
				if(set.size() > largest.size()) {
					var tmp = largest;
					largest = set;
					set = tmp;
				}
				for(int xor: set) {
					if(largest.contains(xor^a[curr])) {
						id3 = true;
					}
				}
				if(!id3)
					largest.addAll(set);
			}
		}
		if(largest.contains(id22[curr]^a[curr]))
			id3 = true;
		if(id3) {
			ans++;
			return new HashSet<>();
		}
		else {
			largest.add(id22[curr]);
			return largest;
		}
	}
	
	
	private int solve2(int n, int[] a, int[][] e) {
		this.a = a;
		id14 = new int[n];
		neighbors = new HashSet[n];
		for(int i=0; i<n; i++)
			neighbors[i] = new HashSet<Integer>();
		for(int i=0; i<e.length; i++) {
			neighbors[e[i][0]].add(e[i][1]);
			neighbors[e[i][1]].add(e[i][0]);
		}
		

		isRemoved = new boolean[n];

		depth = new int[n];
		parents = new int[n];
		computeDepth(0, -1, 0);
		
		id10 = new boolean[n];
		intersection = new int[n];
		pass = new boolean[n];
		
		int ans =  xor(0);
		return ans;
		


		

		

		

		










	}
	
















	
	int xor(int root) {




		tour = new ArrayList<>();
		parentCenter = new HashMap<>();
		parentCenter.put(root, null);
		Center rootCenter = null;
		
		while(!parentCenter.isEmpty()) {
			var it = parentCenter.entrySet().iterator();
			var temp = it.next();
			it.remove();
			root = temp.getKey();
			Center parent = temp.getValue();
			
			int center = findCenter(root);
			Center c = new Center(center);
			if(parent == null)
				rootCenter = c;
			else 
				parent.children.add(c);
			for(int next: neighbors[center]) {
				if(isRemoved[next])
					continue;
				parentCenter.put(next, c);
			}
			isRemoved[center] = true;
		}
		
		Arrays.fill(isRemoved, false);
		var tmp = dfs(rootCenter);
		int ans = neighbors.length-tmp.size();
		
		int expected = verify();
		
		System.out.println(ans);
		System.out.println(expected);
		
		System.out.println(tmp.keySet());
		tmp.clear();
		for(int i=0; i<isChanged.length; i++)
			if(!isChanged[i])
				tmp.put(i, 0);
		System.out.println(tmp.keySet());
		
		return ans;
	}

	private int verify() {
		isChanged = new boolean[neighbors.length];
		verifyDFS(0, -1);
		int cnt = 0;
		int chk = 0;
		for(int i=0; i<neighbors.length; i++) {
			if(isChanged[i])
				cnt++;
			chk += neighbors[i].size();
		}
		return cnt;
	}

	boolean[] isChanged;
	private HashSet<Integer> verifyDFS(int curr, int parent) {
		HashSet<Integer> ret = new HashSet<Integer>();
		ret.add(a[curr]);
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			HashSet<Integer> res = verifyDFS(next, curr);
			for(int val: res) {
				if(ret.contains(val))
					isChanged[curr] = true;
			}
			for(int val: res) {
				ret.add(val^a[curr]);
			}
		}
		if(ret.contains(0)) {
			isChanged[curr] = true;
		}
		if(isChanged[curr]) {
			return new HashSet<Integer>();
		}
		else {
			return ret;
		}
	}

	int[] depth;
	int[] parents;
	
	int[] a;
	HashSet<Integer>[] neighbors;
	boolean[] isRemoved;
	int[] id14;
	ArrayList<Integer> tour;
	HashMap<Integer, Center> parentCenter;
	
	private void computePath(int v1, int v2, ArrayList<Integer> path) {
		if(v1 == v2) {
			path.add(v1);
			return;
		}
		if(depth[v1] > depth[v2]) {
			path.add(v1);
			computePath(parents[v1], v2, path);
		}
		else if(depth[v2] > depth[v1]) {
			computePath(v1, parents[v2], path);
			path.add(v2);
		}
		else {
			path.add(v1);
			computePath(parents[v1], parents[v2], path);
			path.add(v2);
		}
	}
	
	private void computeDepth(int curr, int parent, int d) {
		parents[curr] = parent;
		depth[curr] = d;
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			computeDepth(next, curr, d+1);
		}
	}
	








	boolean[] id10;
	int[] intersection;
	boolean[] pass;
	
	private void initIntersection(int curr, int parent) {
		if(isRemoved[curr])
			return;
		
		intersection[curr] = -1;
		for(int next: neighbors[curr]) {
			if(next == parent)
				continue;
			initIntersection(next, curr);
		}
	}
	
	private void assignIntersection(int curr, int parent, int vertex, boolean considerDeleted) {
		if(!considerDeleted && isRemoved[curr])
			return;
			
		intersection[curr] = vertex;
		for(int next: neighbors[curr]) {
			if(id10[next] || next == parent)
				continue;
			assignIntersection(next, curr, vertex, considerDeleted);
		}
	}

	private HashMap<Integer, Integer> dfs(Center curr) {
		HashMap<Integer, Integer> ret = new HashMap<>();
		HashSet<Integer> id9 = new HashSet<>();
		




		
		

		

		

		
		

		

		

		

		

		
		initIntersection(curr.vertex, -1);
		
		isRemoved[curr.vertex] = true;
		boolean id5 = false;
		id9.add(a[curr.vertex]);
		
		for(Center next: curr.children) {
			HashMap<Integer, Integer> xors = dfs(next);




			
			ArrayList<Integer> id11 = new ArrayList<>();
			computePath(curr.vertex, next.vertex, id11);
			
			int m = id11.size();
			
			int id21 = 0;
			for(int v: id11) {
				id10[v] = true;
				pass[v] = false;
				id21 ^= a[v];
			}
			
			if(!id5) {
				for(int i=1; i<m; i++) {
					int v = id11.get(i);
					assignIntersection(v, -1, v, false);
					if(isRemoved[v] || pass[id11.get(i-1)])
						pass[v] = true;
				}
				
				for(var entry: xors.entrySet()) {
					int v = entry.getKey();
					int xor2 = entry.getValue();
					if(intersection[v] == -1)
						continue;
					if(pass[intersection[v]])
						continue;
					xor2 ^= id21^a[intersection[v]];
					

					if(id9.contains(xor2^a[curr.vertex])) {
						id5 = true;
						break;
					}


				}
				if(!id5) {
					for(var entry: xors.entrySet()) {
						int v = entry.getKey();
						int xor2 = entry.getValue();
						if(intersection[v] == -1)
							continue;
						if(pass[intersection[v]])
							continue;
						xor2 ^= id21^a[intersection[v]];
						id9.add(xor2);
					}
				}
			}
			
			for(int i=1; i<m; i++) {
				int v = id11.get(i);
				assignIntersection(v, -1, v, true);
			}
				
			for(var entry: xors.entrySet()) {
				int v = entry.getKey();
				int xor2 = entry.getValue();
				xor2 ^= id21^a[intersection[v]];
				ret.put(v, xor2);
			}
			
			for(int v: id11) {
				id10[v] = false;
			}
		}
		
		if(!id5) {
			isRemoved[curr.vertex] = false;
			ret.put(curr.vertex, a[curr.vertex]);
		}
		return ret;
	}
	












	
	private int findCenter(int curr) {
		tour.clear();
		id6(curr, -1);
		int m = tour.size();
		for(int i=1; i<m; i++) {
			boolean isCenter = true;
			for(int next: neighbors[curr]) {
				if(isRemoved[next])
					continue;
				if(id14[next] > id14[curr] / 2) {
					isCenter = false;
					break;
				}
			}
			if(isCenter)
				return curr;
			
			int next = tour.get(i);
			id14[curr] -= id14[next];
			id14[next] += id14[curr];
			
			curr = next;
		}
		assert(false);
		return curr;
	}

	private int id6(int curr, int parent) {
		int ret = 1;
		tour.add(curr);
		for(int next: neighbors[curr]) {
			if(isRemoved[next] || next == parent)
				continue;
			ret += id6(next, curr);
			tour.add(curr);
		}
		id14[curr] = ret;
		return ret;
	}


	
	class Center{
		int vertex;
		ArrayList<Center> children;
		public Center(int vertex) {
			this.vertex = vertex;
			children = new ArrayList<>();
		}
		public String toString() {
			return String.format("%d %s", vertex, children);
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
		
		int[][] id8(int n, int offset){
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

		int[][] id16(){
			return id16(0);
		}
		
		int[][] id16(int offset) {
			int m = nextInt();
			int[][] e = new int[m][2];
			for(int i=0; i<m; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;
		}
		
		int[] id12(int len) {
			return id12(len, 0);
		}
		int[] id12(int len, int offset){
	    	int[] a = new int[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextInt()+offset;
	    	return a;
		}
		
		long[] id24(int len) {
			return id24(len, 0);
		}
		long[] id24(int len, int offset){
	    	long[] a = new long[len];
			for(int j=0; j<len; j++)
	    		a[j] = nextLong()+offset;
	    	return a;
		}
	}
	
	public static class id7 extends PrintWriter{
		public id7(OutputStream os) {
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
	
	static private void id23(long[] a) {
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
	
	static private void id23(int[] a) {
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
	
	static private int[][][] id19(int n, int[][] e){
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
		id18(e);
		try {
			final Process process = new ProcessBuilder("dot", "-Tpng", "graph.dot")
					.redirectOutput(new File("graph.png"))
					.start();
		} catch (IOException e1) {
			

			e1.printStackTrace();
		}
		
	}
	
	static private void id18(int[][] e) {
		id7 out2 = null;
		 try {
			out2 = new id7(new FileOutputStream("graph.dot"));
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
		id7 out2 = null;
		 try {
			out2 = new id7(new FileOutputStream("graph.dot"));
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