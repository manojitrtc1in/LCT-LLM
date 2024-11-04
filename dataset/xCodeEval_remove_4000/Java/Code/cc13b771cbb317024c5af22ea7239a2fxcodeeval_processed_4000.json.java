
import java.util.*;
import java.util.function.BiFunction;
import java.io.*;





public class id0 {
	public static id4 out;
	public static MyScanner in;
	
	final static String id7 = "id7";
	final static String id8 = "id8";
	final static String YES = "YES";
	final static String NO = "NO";
    private static void id11(boolean id6) {
        if (System.getProperty("ONLINE_JUDGE") == null && id6) {
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


		
		boolean isDebug = false;
		boolean id6 = true;
		
		id11(id6);
		
		id0 sol = new id0();
		
	    int t = in.nextInt();
	    for (int i = 1; i <= t; ++i) {
	    	int n = in.nextInt();
	    	int m = in.nextInt();
	    	int[] a = new int[n];
	    	for(int j=0; j<n; j++)
	    		a[j] = in.nextInt();
	    	int[] l = new int[m];
	    	int[] r = new int[m];
	    	for(int j=0; j<m; j++){
	    		l[j] = in.nextInt()-1;
	    		r[j] = in.nextInt()-1;
	    	}
	    	
	    	if(isDebug && id6){
		    	out.printf("Test %d\n", i);
		    	out.println(a);
		    	out.println(l);
		    	out.println(r);
	    	}
	    	
			int ans = sol.solve2(a, l, r);
			out.println(ans);
			
			
			if(isDebug)
				out.flush();
	    }
	    in.close();
	    out.close();
    }
	
	int solve(int[] a, int[] l, int[] r){
		int n = a.length;
		int m = l.length;
		
		int left = 0;
		
		int min = n;
		for(int i=0; i<m; i++)
			min = Math.min(min, r[i]);
		
		HashSet<Integer> visited = new HashSet<Integer>();
		
		int right;
		for(right=r[min]; right >= left; right--){
			if(visited.contains(a[right])){
				break;
			}
		}
		
		

		
		

		

		

		
		

		

		

		
		

		

		

		

		

		
		

		

		

		
		

		

		

		

		
		

		

		

		
		

		

		

		
		

		

		
		
		

		

		

		

		
		
		

		
		

		

		
		
		

		

		
		

		

		

		
		

		

		

		
		

		
		

		

		

		

		

		

		
		return 0;
	}






	SegmentTree id5;
	final int IDENTITY = -1;
	int solve2(int[] a, int[] l, int[] r){
		int n = a.length;
		int m = l.length;
		
		int[] id1 = computeF(a);
		int[] id2 = computeG(a);
		Pair[] pairs = new Pair[n];
		for(int i=0; i<n; i++)
			pairs[i] = new Pair(i, a[i]);
		Arrays.sort(pairs);
		
		

		

		int[] id9 = id10(l, r, id1);
		
		id5 = new SegmentTree(Math::max, id9, IDENTITY);
		if(id5.getRange(0, n-1) == -1)
			return 0;
	
		

		
		

		


		

		

		

		

		

		
		

		

		
		int maxLeft = n;
		for(int i=0; i<n; i++)
			if(id9[i] != -1)
				maxLeft = Math.min(maxLeft, id2[i]+1);
		
		

		int[] len = new int[n];
		Arrays.fill(len, n);
		
		int left, right;
		for(left = 0, right = 0; left <= maxLeft; left++) {
			int maxRight = id5.getRange(left, n-1);
			if(maxRight >= 0)
				right = Math.max(right, id1[maxRight]-1);

			len[left] = right-left+1;
			
			maxRight = id5.getRange(0, left);
			int next = Arrays.binarySearch(pairs, new Pair(right+1, a[left]));
			

			

			if(next < 0) {
				

				next = -(next+1);
				if(next == n || pairs[next].value != a[left])
					continue;
				if(pairs[next].index <= maxRight)
					right = pairs[next].index;
			}
			else if(pairs[next].index <= maxRight) {
				right = right+1;
			}
			if(right < left)
				break;
		}

		int min = Integer.MAX_VALUE;
		for(int i=0; i<n; i++)
			min = Math.min(min, len[i]);
		
		return min;
		
		

		

		

		
		

		

		
		

		

		
		

		

		

		

		
		

		

		

		
		

		

		

		
		

		

		

		

		
		
		

		

		

		

		
		

		

		

		

		

		

		

		

		

		

		

		
		

		
		

		

		

		

		

		
		

		

		

		

		

		
		

		

		

		
		
		






















		


		

		












	}

	private int[] id10(int[] l, int[] r, int[] f) {
		int n = f.length;
		int m = l.length;
		
		int[] id9 = new int[n];
		Arrays.fill(id9, -1);
		for(int i=0; i<m; i++)
			id9[l[i]] = Math.max(id9[l[i]], r[i]);
		
		int[] id3 = new int[n];
		Arrays.fill(id3, n);
		for(int i=0; i<n; i++) {
			int right = id9[i];
			if(right != -1)
				id3[right] = Math.min(id3[right], i);
		}
		Arrays.fill(id9, -1);
		for(int i=0; i<n; i++) {
			int left = id3[i];
			if(left != n)
				id9[left] = i;
		}
		
		for(int i=0; i<n; i++)
			if(id9[i] != -1 && f[id9[i]] <= i)
				id9[i] = -1;
		
		return id9;
	}

	private int[] computeG(int[] a) {
		int n = a.length;
		int[] id2 = new int[n];
		

		
		HashSet<Integer> activeNumbers = new HashSet<Integer>();
		for(int left = 0, right = 0; left<n; left++, right++) {
			while(right < n && !activeNumbers.contains(a[right])) {
				activeNumbers.add(a[right]);
				right++;
			}
			right--;
			id2[left] = right;
			activeNumbers.remove(a[left]);
		}
		
		return id2;
	}

	private int[] computeF(int[] a) {
		int n = a.length;
		
		int[] id1 = new int[n];
		

		
		HashSet<Integer> activeNumbers = new HashSet<Integer>();
		for(int right = n-1, left = n-1; right >=0; right--, left--) {
			while(left >= 0 && !activeNumbers.contains(a[left])) {
				activeNumbers.add(a[left]);
				left--;
			}
			left++;
			id1[right] = left;
			activeNumbers.remove(a[right]);
		}
		return id1;
	}
	
	

	

	

	
	

	

	
















































































	
	static class Pair implements Comparable<Pair>{
		int index;
		int value;
		public Pair(int index, int value) {
			this.index = index;
			this.value = value;
		}
		@Override
		public int compareTo(id0.Pair o) {
			return Long.compare( (((long)value)<<32) + index, (((long)o.value)<<32) + o.index);
		}
		@Override
		public String toString() {
			return "a[" + index + "]=" + value;
		}
	}

	static class SegmentTree {
		BiFunction<Integer, Integer, Integer> function;
		int identity;
		int n;
		int[] tree;
		
		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int maxSize, int identity) {
			this.function = function;
			this.identity = identity;
			this.n = maxSize;
			
			int m = 1;
			while(m < n+1){
				m <<= 1;
			}
			m <<= 1;

			tree = new int[m];
			Arrays.fill(tree, identity);
		}
		
		public SegmentTree(BiFunction<Integer, Integer, Integer> function, int[] arr, int identity){
			this.function = function;
			this.identity = identity;
			this.n = arr.length;

			int m = 1;
			while(m < n+1){
				m <<= 1;
			}
			m <<= 1;

			tree = new int[m];
			Arrays.fill(tree, identity);

			for(int i=0; i<n; i++){
				update(i, arr[i]);
			}

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

			

			int mid = (left+right)/2;
			int val1 = update(idx, val, treeIdx*2, left, mid);
			int val2 = update(idx, val, treeIdx*2+1, mid+1, right);
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

			int mid = (left+right)/2;
			if(end <= mid)
				return getRange(start, end, treeIdx*2, left, mid);
			else if(start <= mid){
				int val1 = getRange(start, mid, treeIdx*2, left, mid);
				int val2 = getRange(mid+1, end, treeIdx*2+1, mid+1, right);
				return function.apply(val1, val2);
			}
			else
				return getRange(start, end, treeIdx*2+1, mid+1, right);
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

	}
	
	public static class id4 extends PrintWriter{
		public id4(OutputStream os) {
			super(os);
		}
		
		public void print(long[] arr){
			if(arr != null){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void println(long[] arr){
			print(arr);
			println();
		}

		public void print(int[] arr){
			if(arr != null){
				print(arr[0]);
				for(int i=1; i<arr.length; i++){
					print(" ");
					print(arr[i]);
				}
			}
		}
		public void println(int[] arr){
			print(arr);
			println();
		}
		
		public <T> void print(ArrayList<T> arr){
			if(arr != null){
				print(arr.get(0));
				for(int i=1; i<arr.size(); i++){
					print(" ");
					print(arr.get(i));
				}
			}
		}
		public <T> void println(ArrayList<T> arr){
			print(arr);
			println();
		}
		
		public void println(int[] arr, int split){
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
		
		public <T> void println(ArrayList<T> arr, int split){
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
}
