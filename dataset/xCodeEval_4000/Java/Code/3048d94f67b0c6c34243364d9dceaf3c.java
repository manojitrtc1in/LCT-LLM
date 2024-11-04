
	 
	    		import java.awt.List;
	    		import java.io.*;
	import java.math.BigInteger;
	import java.util.*;
	
	    		
	    		
	    		
	    		
	    		
	    		public class prac {
	    			FastScanner in;
	    			PrintWriter out;
	    		
	    			static ArrayList[] adj;
	    			
	    			static int n;
	    			static int m;
	    			
	    			static int[] dp1;
	    			static int[] dp2;
	    			static int color[];
	    			static int visited[];
	    			static long[] arr;
	    			static long[] brr;
	    			static long ans;
	    			static int array[];
	    			static int start[];
	    			static int finish[];
	    			static int pref[];
	    			static int tree[];
	    			static int maxval = 32;
	    		
	    			static int sum = 0;
	    			
	    			static int cc = 0;
	    			static long min = Long.MAX_VALUE;
	    			
	    		

	    			static int dir[][] ={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	    			
	    		
	    			static long[] seg;
	    			static long count = 1;
	    			static long mod = (long)1e9 + 7;
	    	
	    			static int parent[];
	    			static int size[];
	    			
	    			static class Ppair implements Comparable<Ppair>
	    		    {
	    				int x;int y;
	    				
	    		        Ppair(int l, int m) {
	    		          
	    		        	this.x = l;
	    		            this.y = m;
	    		          
	    		        }
	    		        
	    		        public int compareTo(Ppair p) {
	    		        	
	    		        	double X = (double)this.x/((double)Math.pow(2, this.y));
	    		        	double Y = (double)p.x/((double)Math.pow(2, p.y));
	    		        	
	    		        	if(X == Y){
	    		        		return 0;
	    		        	}else if(X > Y){
	    		        		return 1;
	    		        	}else{
	    		        		return -1;
	    		        	}
	    		        	
	

	

	

	

	    		        }
	    		        
	    		        public String toString(){
	    		        	return x + " " + y;
	    		        }
	    		        
	    		        public boolean equals(Object o){
	    		        	if(o instanceof Ppair){
	    		        		Ppair a = (Ppair)o;
	    		        		
	    		        		return this.x == a.x;
	    		        	}
	    		        	
	    		        	return false;
	    		        }
	    		        
	    		        public int hashCode(){
	    		        	return new Long(x).hashCode()*31 + new Long(y).hashCode();
	    		        }
	    		    
	    		    }
	    		    
	    			
	    			public static int gcd(int a, int b) {
	    				if (b == 0) return a;
	    				return gcd(b, a%b);
	    			}
	    	
	    			void build(int n) {  

	  				  for (int i = n - 1; i > 0; --i) seg[i] = seg[i<<1]+seg[i<<1|1];
	  				}

	  			public static void modify(int p, long val,int n) {  

	  				  for (seg[p += n] = val; p > 1; p >>= 1) seg[p>>1] = seg[p] + seg[p^1];
	  				}

	  				long query(int l, int r,int n) {  

	  				  long res = 0;
	  				  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	  				    if ((l&1) == 1) res += seg[l++];
	  				    if ((r&1) == 1) res += seg[--r];
	  				  }
	  				  return res;
	  				}
	    				
	    			public static void update(int x,int val){
	    				while(x<=maxval){
	    					tree[x] += val;
	    					x = (x&-x);
	    				}
	    			}
	    			
	    			public static int read(int idx){
	    				int sum = 0;
	    				
	    				while(idx>= 0){
	    					sum += tree[idx];
	    					idx -= (idx&(-idx));
	    				}
	    				
	    				return sum;
	    			}
	    			
	    			public static int find(int i){
	    				if(parent[i] != i){
	    					return find(parent[i]);
	    				}
	    				
	    				return i;
	    			}
	    			
	    			public static void union(int a,int b){
	    				int x = find(a);
	    				int y = find(b);
	    				
	    				if(x!=y){
	    					if(size[x] > size[y]){
	    						size[x] += size[y];
	    						parent[y] = x;
	    					}else{
	    						size[y] += size[x];
	    						parent[x] = y;
	    					}
	    				}
	    			}
	    			
	    			
	    			
	    		    void solve() throws NumberFormatException,InputMismatchException, IOException {
	    		 
	    		    
	    		    	Scanner in = new Scanner(System.in);
	    		    
	    		        long C[][] = new long[1001][1001];
		    		 
		    		    for (int i = 0; i <= 1000; i++)
		    		    {
		    		        for (int j = 0; j <= Math.min(i, 1000); j++)
		    		        {
		    		            if (j == 0 || j == i)
		    		                C[i][j] = 1;
		    		      
		    		            else
		    		                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		    		          }
		    		     }
		    		      
	    		    	
	    		    	
	    		    	String s = in.nextLine();
	    		    	

	    		    	int k = in.nextInt();
	    		    	int d = 0;
	    		    	
	    		    	for(int i = 0;i<s.length();i++){
	    		    		if(s.charAt(i) == '1'){
	    		    			d++;
	    		    		}
	    		    	}
	    		    	int[] arr = new int[1001];
	    		    	
	    		    	for(int i = 1;i<=1000;i++){
	    		    		arr[i] = Integer.bitCount(i);
	    		    	}
	    		    	
	    		    	int dp[] = new int[1001];
	    		    	
	    		    	dp[1] = 0;
	    		    	dp[2] = 1;
	    		    	
	    		    	for(int i = 3;i<1001;i++){
	    		    		dp[i] = dp[arr[i]]+1;
	    		    		
	    		    	}
	    		    	
	    		    	long ans = 0;
	    		    	
	    		    	if(k == 0){
	    		    		out.println(1);
	    		    		return;
	    		    	}
	    		    	
	    		    
	    		    	
	    		    	for(int i = 1;i<=1000;i++){
	    		    		if(dp[i] == k-1){
	    		    			
	    		    				int dd = 0;
	    		    				
	    		    				for(int j = 0;j<s.length();j++){
	    		    					if(s.charAt(j) == '0'){
	    		    						continue;
	    		    					}
	    		    					if(s.length()-j-1 < 0 || i-dd <0){
	    		    						dd++;
	    		    						continue;
	    		    					}
	    		    					
	    		    					ans = (ans + C[s.length()-j-1][i-dd] ) %mod;
	    		    					dd++;
	    		    				}
	    		    				
	    		    				if(i == 1){
	    		    					ans = (ans-1)%mod;
	    		    				}
	    		    				
	    		    				if(dd == i)
	    		    				ans = (ans + 1)%mod;
	    		    				
	    		    			
	    		    		}
	    		    	}
	    		    	
	    		    	
	    		    	out.println(ans);
	    		    	
	    		    
	    		    }
	    		    
	    		   
	    		    
	    		    
	    		    public static void dfs(int i){
	    		    	if(visited[i] == 1){
	    		    		return;
	    		    	}
	    		    	
	    		    	visited[i] = 1;
	    		    	arr[cc] = array[i];
	    		    	start[i] = cc;
	    		    	cc++;
	    		    	
	    		    	for(int j = 0;j<adj[i].size();j++){
	    		    		dfs((int)adj[i].get(j));
	    		    	}
	    		    	
	    		    	finish[i] = cc;
	    		    	
	    		    }
	    		    
	    		    public static boolean cc(String s){
	    		    	char arr[] = s.toCharArray();
	    		    	
	    		    	for(int i = 0;i<s.length()/2;i++){
	    		    		if(arr[i] != arr[s.length()-i-1]){
	    		    			return false;
	    		    		}
	    		    	}
	    		    	
	    		    	return true;
	    		    }
	    		   
	    		    
	    		    private static class Pair {
	    		        int val, index;
	    		        Pair(int val, int index) {
	    		            this.val = val;
	    		            this.index = index;
	    		        }
	    		        static Pair[] construct(Pair a[], int i, int j) {
	    		            Pair b[] = new Pair[j - i + 1];
	    		            for (int k = i; k <= j; ++k) {
	    		                b[k - i] = new Pair(a[k].val, a[k].index);
	    		            }
	    		            return b;
	    		        }
	    		    }
	    		    private static void mergeSort(Pair a[], int ans[]) {
	    		        if (a.length <= 1) {
	    		            return;
	    		        }
	    		        Pair l[] = Pair.construct(a, 0, (a.length >> 1) - 1);
	    		        mergeSort(l, ans);
	    		        Pair r[] = Pair.construct(a, a.length >> 1, a.length - 1);
	    		        mergeSort(r, ans);
	    		        int i = 0, j = 0;
	    		        while (i < l.length && j < r.length) {
	    		            if (l[i].val > r[j].val) {
	    		                ans[l[i].index] += r.length - j;
	    		                a[i + j].val = l[i].val;
	    		                a[i + j].index = l[i].index;
	    		                ++i;
	    		            } else {
	    		                a[i + j].val = r[j].val;
	    		                a[i + j].index = r[j].index;
	    		                ++j;
	    		            }
	    		        }
	    		        while (i < l.length) {
	    		            a[i + j].val = l[i].val;
	    		            a[i + j].index = l[i].index;
	    		            ++i;
	    		        }
	    		        while (j < r.length) {
	    		            a[i + j].val = r[j].val;
	    		            a[i + j].index = r[j].index;
	    		            ++j;
	    		        }
	    		    }
	    		    public static void GS(int a[]) {
	    		        Pair b[] = new Pair[a.length];
	    		        for (int i = 0; i < a.length; ++i) {
	    		            b[i] = new Pair(a[i], i);
	    		        }
	    		        int ans[] = new int[a.length];
	    		        mergeSort(b, ans);
	    		        for (int i = 0; i < ans.length; ++i) {
	    		            System.out.print(ans[i] + " ");
	    		        }
	    		        System.out.println();
	    		    }
	    		    
	    		    public static void ddfss(int i,int p){
	    		    	
	    		    	array[i] = color[p];
	    		    	
	    		    	for(int j = 0;j<adj[i].size();j++){
	    		    		if((int)adj[i].get(j) != p){
	    		    			
	    		    			ddfss((int)adj[i].get(j),i);
	    		    		}
	    		    	}
	    		    }
	    		    
	    		    public static void ddfs(int i,int p){
	
	    		    	

	    		    	
	    		    	if(color[i] != array[i]){
	    		    		sum++;
	    		    	

	    		    		ddfss(i,p);
	    		    		
	    		    	}
		
	    		    	for(int j = 0;j<adj[i].size();j++){
	    		    		if((int)adj[i].get(j) != p){
	    		    			ddfs((int)adj[i].get(j),i);
	    		    		}
	    		    	}
	    		    	
	    		    }
	    		    
	    		    public static long invcount(int arr[]){
	    		    	if(arr.length<2){
	    		    		return 0;
	    		    	}
	    		    	
	    		    	int mid = (arr.length + 1)/2;
	    		    	
	    		    	int left[] = Arrays.copyOfRange(arr, 0,mid);
	    		    	int right[] = Arrays.copyOfRange(arr, mid, arr.length);
	    		    	
	    		    	return invcount(left)+invcount(right)+merge(arr,left,right);
	    		    	
	    		    }
	    		    
	    		    public static long merge(int arr[],int left[],int right[]){
	    		    	long count = 0;
	    		    	
	    		    	int i = 0;
	    		    	int j = 0;
	    		    	
	    		    	while(i<left.length || j < right.length){
	    		    		
	    		    		if(i == left.length){
	    		    			arr[i+j] = right[j];
	    		    			j++;
	    		    		}else if(j == right.length){
	    		    			arr[j+i] = left[i];
	    		    			i++;
	    		    		}else{
	    		    			if(left[i] <= right[j]){
	    		    				arr[i+j] = left[i];
	    		    				i++;
	    		    			}else{
	    		    				arr[i+j] = right[j];
	    		    				j++;
	    		    				count += left.length-i;
	    		    			}
	    		    		}
	    		    		
	    		    	}
	    		    	
	    		    	return count;
	    		    }
	    		    
	    		  
	    		    
	    		    
	    		    int ff(int[] div, int left, int right, int value) {
	    		        int low = left;
	    		        int high = right;
	    		        
	    		        if(value > div[right-1]){
	    		        	return left;
	    		        }
	    		        
	    		        while (low != high) {
	    		            int mid = (low + high) / 2;
	    		            if (div[mid] < value) {
	    		                low = mid + 1;
	    		            } else {
	    		                high = mid;
	    		            }
	    		        }
	    		        if (low == right) {
	    		            return low;
	    		        }
	    		        return low;
	    		    } 
	    		   
	    		    
	    		    int ffff(int[] div, int left, int right, int value) {
	    		        
	    		    	if(value < div[left]){
	    		    		return right-1;
	    		    	}
	    		    	
	    		    	while (left != right) {
	    		            int mid = (left + right) >> 1;
	    		            if (div[mid] <= value) {
	    		                left = mid + 1;
	    		            } else {
	    		                right = mid;
	    		            }
	    		        }
	    		        if (left < 0) {
	    		            left *= -1;
	    		        }
	    		        return --left;
	    		    }
		    
	    		   
	    		  
	    		
	    		    public static String reverse(String s){
	    		    	
	    		    	String ans = "";
	    		    	
	    		    	for(int i = s.length()-1;i>=0;i--){
	    		    		ans += s.charAt(i);
	    		    	}
	    		    	
	    		    	return ans;
	    		    	
	    		    }
	    			
	    			
	    		    
	    		 
	    		    public static long sum(long x){
	    		    	return x<10?x:x%10 + sum(x/10);
	    		    }
	    			
	    			public static long gcd(long x, long y) {
	    				if (x == 0)
	    					return y;
	    				else
	    					return gcd( y % x,x);
	    			}
	    			static long inv(long x , long mod)
	    			{
	    				long r,y;
	    				for(r=1,y=mod-2;y!=0;x=x*x%mod,y>>=1)
	    				{
	    					if((y&1)==1)
	    						r=r*x%mod;
	    				
	    				}
	    				return r;
	    			}
	    			
	    			public static long pow(long x,long y,long n){
	    				if(y==0)
	    					return 1%n;
	    				if(y%2==0){
	    					long z=pow(x,y/2,n);
	    					return (z*z)%n;
	    				}
	    				return ((x%n)*pow(x,y-1,n))%n;
	    			}
	    			
	    			
	    			
	    			
	    			public static boolean isPrime(long a) {
	    				

	    				if (a <= 1)
	    					return false;
	    				if (a <= 3)
	    					return true;
	    		 
	    				

	    				

	    				if (a % 2 == 0 || a % 3 == 0)
	    					return false;
	    		 
	    				for (long i = 5; i * i <= a; i = i + 6)
	    					if (a % i == 0 || a % (i + 2) == 0)
	    						return false;
	    		 
	    				return true;
	    			}
	    			
	    		
	    			void run() throws NumberFormatException, InputMismatchException,IOException {
	    				in = new FastScanner();
	    				out = new PrintWriter(System.out);
	    		
	    				solve();
	    		
	    				out.close();
	    			}
	    		
	    			class FastScanner {
	    				BufferedReader br;
	    				StringTokenizer st;
	    		
	    				public FastScanner() {
	    					br = new BufferedReader(new InputStreamReader(System.in));
	    				}
	    		
	    				String next() {
	    					while (st == null || !st.hasMoreTokens()) {
	    						try {
	    							st = new StringTokenizer(in.br.readLine());
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
	    			}
	    			
	    			
	    			
	    			
	    		 
	    		
	    			public static void main(String[] args) throws NumberFormatException,InputMismatchException, IOException {
	    				new prac().run();
	    			}
	    		}
	    		class Node{
	    			String s;
	    			int b;
	    			
	    		}
	    		
	    		class MyComp implements Comparator<String>{
	    		    
	    			int c = 0;
	    			
	    			MyComp(int d){
	    				c = d;
	    			}
	    			
	    			@Override
	    			public int compare(String a,String b) {
	    				
	    				

	    				
	    				String arr[] = a.split(" ");
	    				String brr[] = b.split(" ");
	    				
	    				return arr[c].compareTo(brr[c]);
	    				
	    				
	    			}
	
	    			
	    		}
	    		
	    		class MyComp2 implements Comparator<Node>{
	    		    
	    		
	    			
	    			@Override
	    			public int compare(Node a,Node b) {
	    				
	    				

	
	    				
	    				if(a.b > b.b){
	    					return -1;
	    				}else{
	    					return 1;
	    				}
	    				
	    				
	    			}
	
	    			
	    		}
