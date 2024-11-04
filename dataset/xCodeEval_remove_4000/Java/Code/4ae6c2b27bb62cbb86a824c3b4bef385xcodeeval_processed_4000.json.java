import java.io.*;
import java.math.BigInteger;
import java.util.*;



public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task t = new Task();
		t.solve(in, out);
		out.close();
	}
	
	static class ListNode {
		 int val;
		 ListNode next;
		 ListNode(int x) { val = x; }
	}		

	static class Task {
		public void solve(InputReader in, PrintWriter out) throws IOException {
			long tStart = System.currentTimeMillis();
			

			int n = in.nextInt();
			int arr[] = new int[n];
			HashMap<Integer,Integer> mp = new HashMap<Integer,Integer>();
			for(int i=0;i<n;i++){
				arr[i] = in.nextInt();
				mp.put(arr[i], 1);
			}
			int re[] = new int[3];
			re[0] = arr[0];
			int x=1;
			for(int i=0;i<n;i++){
				for(int j=0;j<=31;j++){
					int gap = (int) Math.pow(2, j);
					if(x<2){
						if(mp.containsKey(arr[i]+gap)){
							x=2;
							re[0] = arr[i];
							re[1] = arr[i]+gap;
						}else if(mp.containsKey(arr[i]-gap)){
							x=2;
							re[0] = arr[i];
							re[1] = arr[i]-gap;
						}
					}
					if(x<3){
						if(mp.containsKey(arr[i]+gap)&&mp.containsKey(arr[i]-gap)){
							x=3;
							re[0] = arr[i];
							re[1] = arr[i]-gap;
							re[2] = arr[i]+gap;
							out.println(x);
							for(int p=0;p<x;p++){
								out.print(re[p]+" ");
							}
							out.println();		
							return;
						}						
					}
				}
			}
			out.println(x);
			for(int i=0;i<x;i++){
				out.print(re[i]+" ");
			}
			out.println();
			

		}
	
	    public int id7(int[][] graph) {
	        int n = graph.length;
	        if(n==1) return 0;
	        int g[][] = new int[n][n];
	        for(int i=0;i<n;i++){
	        	Arrays.fill(g[i], 99999999);
	        	g[i][i] = 0;
	        	for(int j:graph[i]){
	        		g[i][j] = 1;
	        	}
	        }	        
	        for(int k=0;k<n;k++){
	        	for(int i=0;i<n;i++){
	        		for(int j=0;j<n;j++){
	        			g[i][j] = Math.min(g[i][j], g[i][k]+g[k][j]);
	        		}
	        	}
	        }
	        int p[] = new int[(int)Math.pow(2, n)];
	        Arrays.fill(p, 99999999);
	        int target = (int)Math.pow(2, n)-1;
	        for(int i=0;i<n;i++){
	        	

	        	dp(g,p,1<<i,i,0,target);
	        }      
	        
	        

	        Dumper.id3(p);
	        return p[target];
	    }		
	    int dp(int[][] g, int[] p, int status, int cur, int step, int target){
	    	if(p[status]<=step) return p[status];
	    	if(status==target) {
	    		Dumper.print(step);
	    		return p[status] = step;
	    	}
	    	int min = 99999999;
	    	for(int i=0;i<g.length;i++){
	    		if(g[cur][i]==0||(status & (1L << i)) != 0) continue;
	    		min = Math.min(min, dp(g,p,status|(1<<i),i,step+1,target));
	    	}
	    	return p[status] = min;
	    }
			
	    public double id4(int[] nums1, int[] nums2) {
	    	int l1=0; int l2=0; int r1=nums1.length-1; int r2=nums2.length-1;
	    	int n = nums1.length; int m = nums2.length;
	    	if(n==0){
	    		if(m==0) return 0.0;
	    		if(m%2==1) return nums2[m/2];
	    		else return 1.0*(nums2[m/2]+nums2[m/2-1])/2.0;
	    	}
	    	if(m==0){
	    		if(n%2==1) return nums1[n/2];
	    		else return 1.0*(nums1[n/2]+nums1[n/2-1])/2.0;	    		
	    	}
	    	int t=(m+n-1)/2;
	    	while((l1<r1-1)||(l2<r2-1)){
	    		int mid1 = l1+(r1-l1)/2;
	    		int mid2 = l2+(r2-l2)/2;
	    		int n1 = find(nums2, nums1[mid1]);
	    		int n2 = find(nums1, nums2[mid2]);
	    		Dumper.print(mid1+" "+mid2+" "+n1+" "+n2);
	    		if(n1+mid1==t){
	    			if((m+n)%2==1) return nums1[mid1];
	    			else return 1.0*(nums1[mid1]+nums2[n1])/2.0;
	    		}else if(n1+mid1>t){
	    			if(l2<r2-1) l2=mid2;

	    			if(l1<r1-1) r1=mid1;

	    		}else{
	    			if(l2<r2-1) r2=mid2;

	    			if(l1<r1-1) l1=mid1;

	    		}
	    	}
	    	int a=find(nums2,nums1[l1]);
	    	int b=find(nums2,nums1[r1]);
	    	int c=find(nums1,nums2[l2]);
	    	int d=find(nums1,nums2[r2]);
	    	if(a+l1==t){
    			if((m+n)%2==1) return nums1[l1];
    			else{
    				int tmp = nums1[r1];
    				if(nums2[l2]>=tmp&&nums2[l2]<nums1[r1]) tmp = nums2[l2];
    				return 1.0*(nums1[l1]+tmp)/2.0;
    			}
	    	}
	    	if(b+r1==t){
    			if((m+n)%2==1) return nums1[r1];
    			else{
    				int tmp = nums2[l2];
    				return 1.0*(nums1[r1]+tmp)/2.0;
    			}
	    	}
	    	if(c+l2==t){
    			if((m+n)%2==1) return nums2[l2];
    			else{
    				int tmp = nums2[r2];
    				if(nums1[l1]>=tmp&&nums1[l1]<nums2[r2]) tmp = nums1[l1];
    				return 1.0*(nums2[l2]+tmp)/2.0;
    			}
	    	}
	    	if(d+r2==t){
    			if((m+n)%2==1) return nums2[r2];
    			else{
    				int tmp = nums1[l1];
    				return 1.0*(nums2[r2]+tmp)/2.0;
    			}
	    	}	    	
	        return 1.0;
	    } 
	    int find(int arr[], int v){
	    	int l=0; int r=arr.length-1;
	    	while(l<r-1){
	    		int mid = l+(r-l)/2;
	    		if(arr[mid]<v){
	    			l=mid;
	    		}else{
	    			r=mid;
	    		}
	    	}
	    	if(arr[r]<=v) return r+1;
	    	if(arr[l]<=v) return l+1;
	    	return 0;
	    }
		
	    public List<Integer> id1(int[][] positions) {
	        int n = positions.length;
	        ArrayList<Integer> arr = new ArrayList<Integer>();
	        for(int i=0;i<n;i++){
	        	arr.add(positions[i][0]);
	        	arr.add(positions[i][0]+positions[i][1]-1);
	        }
	        Collections.sort(arr);	        
	        HashMap<Integer, Integer> mp = new HashMap<Integer,Integer>();
	        for(int i=0,j=0;i<arr.size();i++){
	        	if(!mp.containsKey(arr.get(i))){
	        		mp.put(arr.get(i),j++);
	        	}
	        }
	        int square[][] = new int[n][3];
	        for(int i=0;i<n;i++){
	        	square[i][0] = mp.get(positions[i][0]);
	        	square[i][1] = mp.get(positions[i][0]+positions[i][1]-1); 
	        	square[i][2] = positions[i][1];
	        }
	        List<Integer> result = new ArrayList<Integer>();
	        seg_tree t = new seg_tree(mp.size());
	        int tmp_v = 1;
    		while(tmp_v<mp.size()) {
    			tmp_v*=2;
    		}	        
	        for(int i=0;i<n;i++){
	        	int tmp = t.query1(square[i][0], square[i][1]+1, 0, 0, tmp_v);
	        	System.out.println(tmp);
	        	t.update(square[i][0], square[i][1]+1, 0, 0, tmp_v, square[i][2]+tmp);	        	
	        	tmp = t.query(0,tmp_v, 0, 0, tmp_v);
	        	result.add(tmp);
	        }
	        return result;
	    }
	    class seg_tree{
	    	int n;
	    	int arr_leaf[];
	    	int arr_node[];
	    	public seg_tree(int x) {
	    		n=1;	    		
	    		while(n<x) {
	    			n*=2;
	    		}
	    		arr_leaf = new int[2*n-1];
	    		arr_node = new int[2*n-1];
	    	}
	    	public int update(int a, int b, int k, int i, int j, int v) {
	    		if(a<=i&&j<=b) {
	    			arr_leaf[k]=v;	   
	    			return Math.max(arr_leaf[k], arr_node[k]);
	    		}else if(i<b&&a<j){
	    			int t1 = update(a,b,k*2+1,i,(i+j)/2,v);
	    			int t2 = update(a,b,k*2+2,(i+j)/2,j,v);
	    			arr_node[k] = Math.max(arr_node[k], Math.max(t1, t2));
	    			return arr_node[k];
	    		}else {
	    			return 0;
	    		}
	    	}
	    	public int query(int a, int b, int k, int i, int j) {
	    		if(b<=i||j<=a) {
	    			return 0;
	    		}else if(a<=i&&j<=b) {
	    			return Math.max(arr_leaf[k], arr_node[k]);
	    		}else {
	    			int t1 = query(a,b,k*2+1,i,(i+j)/2);
	    			int t2 = query(a,b,k*2+2,(i+j)/2,j);
	    			return Math.max(t1,t2);
	    		}	    		
	    	}
	    	public int query1(int a, int b, int k, int i, int j) {
	    		if(b<=i||j<=a) {
	    			return 0;
	    		}else if(a<=i&&j<=b) {
	    			return Math.max(arr_leaf[k], arr_node[k]);
	    		}else {
	    			

	    			int t1 = query1(a,b,k*2+1,i,(i+j)/2);
	    			int t2 = query1(a,b,k*2+2,(i+j)/2,j);
	    			return Math.max(arr_leaf[k], Math.max(t1,t2));
	    		}	    		
	    	}	    	
	    }
	    
		public ListNode id8(ListNode head, int k) {
            if(k<=1||head==null||head.next==null) return head; 
			ListNode dummy = new ListNode(0);
			dummy.next = head;
			ListNode pre1 = dummy;
			ListNode pre2 = pre1;
			ListNode p = head;
			ListNode q = p;
			while(true){
				int c=1;
				boolean flag = true;				
				while(q!=null&&q.next!=null&&c<k){
					q = q.next;
					c++;                
					flag = false;                 
				}			
				if(c<k||flag) break;
				int d = k;	
				c=1;
				q=p;
				ListNode end = q;
				while(c<d&&d>1){
					c=1;
					while(c<d){
						q=q.next;
						pre2=pre2.next;
						c++;
					}
					

					
					if(d==2){
						p.next=q.next;
						q.next=p;
						pre1.next=q;
					}else{
						ListNode tmp = p.next;
						p.next=q.next;
						q.next=tmp;
						pre1.next=q;
						pre2.next=p;
					}
					Dumper.id0(dummy);					
					if(d>3){
						p=q.next;	
						pre1=q;											
					}else{
						pre1=end;
						p=end.next;						
					}
					q=p;
					pre2=pre1;
					c=0;
					d-=2;					
				}				
			}
			return dummy.next;
		}
		
		ListNode create(int arr[]){
			int p=1;
			ListNode head = new ListNode(arr[0]);
			ListNode pre = head;
			while(p<arr.length){
				ListNode tmp = new ListNode(arr[p++]);
				pre.next=tmp;
				pre=pre.next;
			}
			return head;
		}
        
        public int[] id6(int[] nums1, int[] nums2, int k) {
            int m = nums1.length;
            int n = nums2.length;
            int arr1[] = new int[m];
            int arr2[] = new int[n];
            for(int i=0;i<m;i++) arr1[i] = nums1[i];
            for(int i=0;i<n;i++) arr2[i] = nums2[i];  
            String dp[][][] = new String[m+1][n+1][k+1];
            for(int i=0;i<=m;i++){
            	for(int j=0;j<=n;j++){
            		for(int p=0;p<=k;p++){
            			dp[i][j][p] = "";
            		}
            	}
            }
            for(int i=0;i<=m;i++){
            	for(int j=0;j<=n;j++){
            		for(int p=1;p<=Math.min(i+j, k);p++){
            			if(i>=1&&dp[i-1][j][p].compareTo(dp[i][j][p])>0) {
            				dp[i][j][p] = dp[i-1][j][p];
            			}
            			if(j>=1&&dp[i][j-1][p].compareTo(dp[i][j][p])>0) {
            				dp[i][j][p] = dp[i][j-1][p];
            			}
            			String t1 = "";
            			String t2 = "";
            			if(i>=1) t1 = dp[i-1][j][p-1]+arr1[i-1];
            			if(j>=1) t2 = dp[i][j-1][p-1]+arr2[j-1];
            			if(t1.compareTo((dp[i][j][p]))>0) {
            				dp[i][j][p] = t1;
            			}
            			if(t2.compareTo((dp[i][j][p]))>0) {
            				dp[i][j][p] = t2;
            			}
            		}
            	}
            }
            int result[] = new int[k];
            char tmp[] = dp[m][n][k].toCharArray();
            for(int i=0;i<k;i++){
            	result[i] = tmp[i]-'0';
            }
            return result;
        }

		class TreeNode {
			int val;
			TreeNode left;
			TreeNode right;

			public TreeNode(int a) {
				val = a;
			}
		}

		public class Interval {
			int start;
			int end;

			Interval() {
				start = 0;
				end = 0;
			}

			Interval(int s, int e) {
				start = s;
				end = e;
			}
		}
	}

	

	static class InputReader {
		public BufferedReader re;
		public StringTokenizer st;

		public InputReader(InputStream input) {
			re = new BufferedReader(new InputStreamReader(input));
			st = null;
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(re.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}

			}
			return st.nextToken();
		}

		public String nextLine() {
			String tmp = null;
			try {
				tmp = re.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return tmp;
		}

		public boolean hasNext() {
			String tmp;
			if (st != null && st.hasMoreTokens())
				return true;
			else {
				try {
					tmp = re.readLine();
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				if (tmp != null) {
					st = new StringTokenizer(tmp);
					return true;
				} else {
					return false;
				}
			}

		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}

	static class Dumper {
		static void id3(int[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}
		
		static void id5(char[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}		

		static void id9(double[] arr) {
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id2(int[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void id2(boolean[][] arr, int x, int y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			System.out.println("---------------------");
		}

		static void print(Object o) {
			System.out.println(o.toString());
		}

		static void getc() {
			System.out.println("here");
		}
		
		static void id0(ListNode x){
			while(x!=null){
				System.out.print(x.val+" ");
				x=x.next;
			}
			System.out.println();
		}
	}
}