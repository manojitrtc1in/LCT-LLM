import java.util.*;
import java.io.*;



public class RoundEdu130B {	
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


		
		RoundEdu130B sol = new RoundEdu130B();
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
	    	int q = in.nextInt();
	    	int[] p = new int[n];
	    	
	    	for(int j=0; j<n; j++)
	    		p[j] = in.nextInt();
	    	
	    	preprocess(p);












	    	
	    	for(int j=0; j<q; j++) {
	    		int x = in.nextInt();
	    		int y = in.nextInt();
				long leftSum = x==n? 0 : sum[n-x-1];
				long rightSum = sum[n-x+y-1];
				

				out.println(rightSum-leftSum);
	    	}
	    	
	    	if(isDebug){
		    	out.printf("Test %d\n", i);
	    	}
	    	
			

			

			
			if(isDebug)
				out.flush();
	    }
	    
	    in.close();
	    out.close();
	}
	


	private void test() {
		int n = 200_000_0;
		int q = 200_000_0;
		Random R = new Random();
		int[] p = new int[n];
    	int[] x = new int[q];
    	int[] y = new int[q];
    	for(int i=0; i<n; i++)
    		p[i] = R.nextInt(1_000_000)+1;
    	for(int i=0; i<q; i++) {
    		x[i] = R.nextInt(n)+1;
    		y[i] = R.nextInt(x[i])+1;
    	}
    	

    	

	}
	
	long[] sum;
	private void preprocess(int[] p) {
		int n = p.length;
		GFG.timSort(p, n);
		
		

		sum = new long[n];
		sum[0] = p[0];
		for(int i=1; i<n; i++)
			sum[i] = sum[i-1] + p[i];
	}
	
	static class GFG
	{
	 
	    static int MIN_MERGE = 32;
	 
	    public static int minRunLength(int n)
	    {
	        assert n >= 0;
	       
	        

	        int r = 0;
	        while (n >= MIN_MERGE)
	        {
	            r |= (n & 1);
	            n >>= 1;
	        }
	        return n + r;
	    }
	 
	    

	    

	    public static void insertionSort(int[] arr, int left,
	                                     int right)
	    {
	        for (int i = left + 1; i <= right; i++)
	        {
	            int temp = arr[i];
	            int j = i - 1;
	            while (j >= left && arr[j] > temp)
	            {
	                arr[j + 1] = arr[j];
	                j--;
	            }
	            arr[j + 1] = temp;
	        }
	    }
	 
	    

	    public static void merge(int[] arr, int l,
	                                 int m, int r)
	    {
	        

	        

	        int len1 = m - l + 1, len2 = r - m;
	        int[] left = new int[len1];
	        int[] right = new int[len2];
	        for (int x = 0; x < len1; x++)
	        {
	            left[x] = arr[l + x];
	        }
	        for (int x = 0; x < len2; x++)
	        {
	            right[x] = arr[m + 1 + x];
	        }
	 
	        int i = 0;
	        int j = 0;
	        int k = l;
	 
	        

	        

	        while (i < len1 && j < len2)
	        {
	            if (left[i] <= right[j])
	            {
	                arr[k] = left[i];
	                i++;
	            }
	            else {
	                arr[k] = right[j];
	                j++;
	            }
	            k++;
	        }
	 
	        

	        

	        while (i < len1)
	        {
	            arr[k] = left[i];
	            k++;
	            i++;
	        }
	 
	        

	        

	        while (j < len2)
	        {
	            arr[k] = right[j];
	            k++;
	            j++;
	        }
	    }
	 
	    

	    

	    public static void timSort(int[] arr, int n)
	    {
	        int minRun = minRunLength(MIN_MERGE);
	       
	        

	        for (int i = 0; i < n; i += minRun)
	        {
	            insertionSort(arr, i,
	                          Math.min((i + MIN_MERGE - 1), (n - 1)));
	        }
	 
	        

	        

	        

	        

	        

	        for (int size = minRun; size < n; size = 2 * size)
	        {
	 
	            

	            

	            

	            

	            

	            

	            

	            for (int left = 0; left < n;
	                                 left += 2 * size)
	            {
	 
	                

	                

	                

	                int mid = left + size - 1;
	                int right = Math.min((left + 2 * size - 1),
	                                     (n - 1));
	 
	                

	                

	                  if(mid < right)
	                    merge(arr, left, mid, right);
	            }
	        }
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
		
		int[][] nextTreeEdges(int n, int offset){
			int[][] e = new int[n-1][2];
			for(int i=0; i<n-1; i++){
				e[i][0] = nextInt()+offset;
				e[i][1] = nextInt()+offset;
			}
			return e;			
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
