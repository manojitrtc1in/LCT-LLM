					
					
					        import java.io.*;
					     
					        import java.math.BigInteger;
					        import java.util.*;
					import java.util.Map.Entry;
					
					import javax.print.attribute.SetOfIntegerSyntax;
					     
					        public class Graph1 {
					        	
					    	    private static InputStream stream;
					        	private static byte[] buf=new byte[1024];
					        	private static int curChar;
					        	private static int numChars;
					        	private static SpaceCharFilter filter;
					        	private static PrintWriter pw;
					        	private static long count=0;
					            public static void main(String args[] ) throws Exception 
					            {
					            	InputReader(System.in);
					        		pw=new PrintWriter(System.out);
					        		

					        		soln();
					        		pw.close();
					            }
					     
					            public static long gcd(long x,long y)
					            {
					            	if(x%y==0)
					            		return y;
					            	else
					            		return gcd(y,x%y);
					            }
					            public static int gcd(int x,int y)
					            {
					            	if(x%y==0)
					            		return y;
					            	else 
					            		return gcd(y,x%y);
					            }
					            
					
					
					public static long pow(long n,long p,long m)
					{
						 long  result = 1;
						  if(p==0)
						    return 1;
						if (p==1)
						    return n;
						while(p!=0)
						{
						    if(p%2==1)
						        result *= n;
						    if(result>=m)
						    result%=m;
						    p >>=1;
						    n*=n;
						    if(n>=m)
						    n%=m;
						}
						return result;
					}
					public static long pow(long n,long p)
					{
						long  result = 1;
						  if(p==0)
						    return 1;
						if (p==1)
						    return n;
						while(p!=0)
						{
						    if(p%2==1)
						        result *= n;	    
						    p >>=1;
						    n*=n;	    
						}
						return result;
					
					}
					public static long printSubsets(int set[],int pow,long sum)
						{
						long ans=0;
							int n = set.length;
					
							

							

							for (int i = 0; i < (1<<n); i++)
							{
								int a[]=new int[n];
								
								int count=0;
					
								

								for (int j = 0; j < n; j++)
					
									

									

									

									

									

									if ((i & (1 << j)) > 0)
										{
										
										a[count]=set[j];
										count++;
										

										}
					long tot=0;
							for(int t=0;t<count;t++){
							tot+=a[t];	
								

							}
						

							if((tot)>=pow && (sum-tot)>=pow){
							ans++;
							}
							}

							return ans;
							}
					
						 
						

						static List<Integer> josephus(int N, int step, int start)
						{
						    if (N < 1 || step < 1 || start < 1) return null;
					
						    List<Integer> p = new LinkedList<Integer>();
						    for (int i = 0; i < N; i++)
						        p.add(i+1);
					
						    List<Integer> r = new LinkedList<Integer>();
						    int i = (start - 2) % N;
						    for (int j = N; j > 0; j--) {
						        i = (i + step) % N--;
						        r.add(p.remove(i--));
						    }
					
						    return r;
						}
					
						 
						 
						 public static long fact(long n){
							 if(n==0)
								 return 1;
							 else
								 return (long)n*(long)fact(n-1);
							 
						 }
					
					
					public static int[] radixSort(int[] f)
					{
						int[] to = new int[f.length];
						{
							int[] b = new int[65537];
							for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
							for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
							for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
							int[] d = f; f = to;to = d;
						}
						{
							int[] b = new int[65537];
							for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
							for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
							for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
							int[] d = f; f = to;to = d;
						}
						return f;
					} 
					
					public static int nextPowerOf2(final int a)
					{
					    int b = 1;
					    while (b < a)
					    {
					        b = b << 1;
					    }
					    return b;
					}
					     
					        
					    public static boolean PointInTriangle(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
					    {
					    int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
					    int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;
					     
					    if ((s < 0) != (t < 0))
					    return false;
					     
					    int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
					    if (A < 0.0)
					    {
					    s = -s;
					    t = -t;
					    A = -A;
					    }
					    return s > 0 && t > 0 && (s + t) <= A;
					    }
					     
					      public static float area(int x1, int y1, int x2, int y2, int x3, int y3){
					    	  return (float)Math.abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
					      }
					      public static boolean isPrime(int n)
					      {
					          

					          if (n <= 1)  return false;
					          if (n <= 3)  return true;
					       
					          

					          

					          if (n%2 == 0 || n%3 == 0) return false;
					       
					          for (int i=5; i*i<=n; i=i+6)
					              if (n%i == 0 || n%(i+2) == 0)
					                 return false;
					       
					          return true;
					      }
					     
					     
					    

					            
					            public static void Merge_sort(int a[]){
					            	int len=a.length;
					            	if(len <2)
					            		return ;
					            	int mid=len/2;
					            	int l[]=new int[mid];
					            	int r[] =new int[len-mid];
					            	for(int i=0;i<mid;i++)
					            		l[i]=a[i];
					            	for(int i=mid;i<len;i++)
					            		r[i-mid]=a[i];
					            	
					            	Merge_sort(l);
					            	Merge_sort(r);
					            	Merge(l,r,a);
					            }
					            	
					            public static void Merge(int []l,int[]r,int a[]){
					            	int nl=l.length;
					            	int nr=r.length;
					            	int i=0,j=0,k=0;
					            	
					            	while(i <nl && j<nr){
					            		if(l[i] > r[j]){
					            			a[k]=l[i];
					            			k++;
					            			i++;
					            		}
					            		else{
					            			a[k]=r[j];
					            			k++;
					            			j++;
					            		}
					            		
					            		while(i<nl){
					            			a[k]=l[i];
					            			k++;
					            			i++;
					            		}
					            		while(j<nr){
					            			a[k]=r[j];
					            			k++;
					            			j++;
					            		}
					            	}
					            }
					      
					        	
					        public static boolean isSubSequence(String large,String small,int largeLen,int smallLen){
					        

					        	if(largeLen==0)
					        		return false;
					        	if(smallLen==0)
					        		return true;
					        	  

					        	if(large.charAt(largeLen-1)==small.charAt(smallLen-1))
					        		isSubSequence(large, small, largeLen-1, smallLen-1);
					        	

					        	return isSubSequence(large, small, largeLen-1, smallLen);
					        }
					     
					        

					         	

					         
					         	public static void InputReader(InputStream stream1) {
					         		stream = stream1;
					         	}
					         
					         	private static boolean isWhitespace(int c) {
					         		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
					         	}
					         
					         	private static boolean isEndOfLine(int c) {
					         		return c == '\n' || c == '\r' || c == -1;
					         	}
					         
					         	private static int read() {
					         		if (numChars == -1)
					         			throw new InputMismatchException();
					         		if (curChar >= numChars) {
					         			curChar = 0;
					         			try {
					         				numChars = stream.read(buf);
					         			} catch (IOException e) {
					         				throw new InputMismatchException();
					         			}
					         			if (numChars <= 0)
					         				return -1;
					         		}
					         		return buf[curChar++];
					         	}
					         
					         	private static int nextInt() {
					         		int c = read();
					         		while (isSpaceChar(c))
					         			c = read();
					         		int sgn = 1;
					         		if (c == '-') {
					         			sgn = -1;
					         			c = read();
					         		}
					         		int res = 0;
					         		do {
					         			if (c < '0' || c > '9')
					         				throw new InputMismatchException();
					         			res *= 10;
					         			res += c - '0';
					         			c = read();
					         		} while (!isSpaceChar(c));
					         		return res * sgn;
					         	}
					          
					         	private static long nextLong() {
					         		int c = read();
					         		while (isSpaceChar(c))
					         			c = read();
					         		int sgn = 1;
					         		if (c == '-') {
					         			sgn = -1;
					         			c = read();
					         		}
					         		long res = 0;
					         		do {
					         			if (c < '0' || c > '9')
					         				throw new InputMismatchException();
					         			res *= 10;
					         			res += c - '0';
					         			c = read();
					         		} while (!isSpaceChar(c));
					         		return res * sgn;
					         	}
					          
					         	private static String nextToken() {
					         		int c = read();
					         		while (isSpaceChar(c))
					         			c = read();
					         		StringBuilder res = new StringBuilder();
					         		do {
					         			res.appendCodePoint(c);
					         			c = read();
					         		} while (!isSpaceChar(c));
					         		return res.toString();
					         	}
					          
					         	private static String nextLine() {
					         		int c = read();
					         		while (isSpaceChar(c))
					         			c = read();
					         		StringBuilder res = new StringBuilder();
					         		do {
					         			res.appendCodePoint(c);
					         			c = read();
					         		} while (!isEndOfLine(c));
					         		return res.toString();
					         	}
					         
					         	private static int[] nextIntArray(int n) {
					         		int[] arr = new int[n];
					         		for (int i = 0; i < n; i++) {
					         			arr[i] = nextInt();
					         		}
					         		return arr;
					         	}
					         	  
					         	private static long[] nextLongArray(int n) {
					         		long[] arr = new long[n];
					         		for (int i = 0; i < n; i++) {
					         			arr[i] = nextLong();
					         		}
					         		return arr;
					         	}
					         
					         	private static void pArray(int[] arr){
					         		for (int i=0; i<arr.length; i++) {
					         			System.out.print(arr[i] + " ");
					         		}
					         		System.out.println();
					         		return;
					         	}
					         
					         	private static void pArray(long[] arr){
					         		for (int i=0; i<arr.length; i++) {
					         			System.out.print(arr[i] + " ");
					         		}
					         		System.out.println();
					         		return;		
					         	}
					         	
					         	private static void pArray(boolean[] arr){
					         		for (int i=0; i<arr.length; i++) {
					         			System.out.print(arr[i] + " ");
					         		}
					         		System.out.println();
					         		return;
					         	}
					     
					         
					         	private static boolean isSpaceChar(int c) {
					         		if (filter != null)
					         			return filter.isSpaceChar(c);
					         		return isWhitespace(c);
					         	}
					          
					         	private interface SpaceCharFilter {
					         		public boolean isSpaceChar(int ch);
					         	}
					         	
					         	private static void multiply(int a[][], int b[][])
					         	{
					         	    

					         	    

					         	    int mul[][]=new int[2][2];
					         	    for (int i = 0; i <2; i++)
					         	    {
					         	        for (int j = 0; j < 2; j++)
					         	        {
					         	            mul[i][j] = 0;
					         	            for (int k = 0; k < 2; k++)
					         	                mul[i][j] += a[i][k]*b[k][j];
					         	        }
					         	    }
					         	 
					         	    

					         	    for (int i=0; i<2; i++)
					         	        for (int j=0; j<2; j++)
					         	            a[i][j] = mul[i][j];  

					         	}
					         	 
					         	

					         	private static int power(int F[][], long n)
					         	{
					         	    int M[][]={{1,1},{1,0}};
					         	 
					         	    

					         	    

					         	    if (n==1)
					         	        return F[0][0] + F[0][1];
					         	 
					         	    power(F, n/2);
					         	 
					         	    multiply(F, F);
					         	 
					         	    if (n%2 != 0)
					         	        multiply(F, M);
					         	 
					         	    

					         	    

					         	    return F[0][0] + F[0][1] ;
					         	}
					         	 
					         	

					         	

					         	

		

					         	

		

					         private static long	 findNthTerm(long n)
					         	{
					        	 
					         	    int F[][] = {{1,1}, {1,0}} ;
					         	 
					         	    return power(F, n-2);
					         	}
					         	private static int GetRightPosition(int A[], int l, int r, int key)
					         	{
					         	    int m;
					         	 
					         	    while( r - l > 1 )
					         	    {
					         	        m = l + (r - l)/2;
					         	 
					         	        if( A[m] <= key )
					         	            l = m;
					         	        else
					         	            r = m;
					         	    }
					         	 
					         	    return l;
					         	}
					         	 
					         	private static int GetLeftPosition(int A[], int l, int r, int key)
					         	{
					         	    int m;
					         	 
					         	    while( r - l > 1 )
					         	    {
					         	        m = l + (r - l)/2;
					         	 
					         	        if( A[m] >= key )
					         	            r = m;
					         	        else
					         	            l = m;
					         	    }
					         	 
					         	    return r;
					         	}
					         	 
					         	private static int CountOccurances(int A[], int size, int key)
					         	{
					         	    

					         	    int left = GetLeftPosition(A, -1, size-1, key);
					         	    int right = GetRightPosition(A, 0, size, key);
					         	 
					         	    

					         	    

					         	    return (A[left] == key && key == A[right])?
					         	           (right - left + 1) : 0;
					         	}
					         	private static int Ceil(int a[],int low,int high,int target){
					         		if(target<=a[low]){
					         			return a[low];
					         			
					         		}
					         		if(target>a[high])
					         			return -1;
					         		while(high-low>1){
					         			int mid=low+(high-low)/2;
					         			if(a[mid]<target){
					         				low=mid;
					         				if(mid+1<=a.length-1 && a[mid+1]>=target)
					         					return a[mid+1];
					         			}
					         			if(a[mid]>=target){
					         				high=mid;
					         				if(mid-1>=0 && a[mid-1]<target){
					         					return a[mid];
					         				}
					         			}
					         		}
					         		return -1;
					         	}
			
					         	private static int floor(int a[],int low,int high,int target){
					         		if(target<a[low]){
					         			return -1;
					         		}
					         		if(target>=a[high])
					         			return a[high];
					         		while(high-low>1)
					         		{
					         			int mid=low+(high-low)/2;
					         		if(a[mid]>target){
					         			high=mid;
					         			if(mid-1>=0 && a[mid-1]<=target){
					         				return a[mid-1];
					         			}
					         		}
					         		if(a[mid]<=target){
					         			low=mid;
					         			if((mid+1)<=a.length-1 && a[mid+1]>target){
					         				return a[mid];
					         			}
					         		}
					         			
					         		}
					         		return -1;
					         	}
					         	private static int BinarySearch(int a[],int low,int high,int target){
					         	if(low>high)
					         		return -1;
					         	int mid=low+(high-low)/2;
					         	if(a[mid]==target)
					         		return mid;
					         	if(a[mid]>target)
					         		high=mid-1;
					         	if(a[mid]<target)
					         		low=mid+1;
					         		return BinarySearch(a, low, high, target);
					         	}
					         

					         	 private static void soln(){
					         		
					         		 
					         		 int n=nextInt();
					         		 int m=nextInt();
					         		 int k=nextInt();
					         		
					         		 int a[]=nextIntArray(n);
					         		 int b[]=nextIntArray(m);
					         		 if(n>m){
					         			 System.out.println("YES");
					         		 System.exit(0);
					         		 }
					         		 Arrays.sort(a);
					         		 Arrays.sort(b);
					         		 for(int i=n-1,j=m-1; i>=0 && j>=0;i-- ,j--){
					         			 if(a[i]>b[j]){
					         				 System.out.println("YES");
					         				 System.exit(0);
					         			 }
					         		 }
					         		 System.out.println("NO");
					         	 

					         	
					         
					        
					        
					        }
					        }
					        
					        class MyComp implements Comparator<String>{
					
								@Override
								public int compare(String o1, String o2) {
									 if (o1.length() < o2.length()) {
									      return -1;
									    } else if (o1.length() > o2.length()) {
									      return 1;
									    } else {
									      return 0;
									

										}
					        	
					        }
					        }
					        class Graph{
					        	private long conse=0,co=0,mac_cons_cat=0;
					        	private int V,flag=1, d[], road_cond[][];
					        	private Stack <Integer>st=new Stack();
					        	private LinkedList<Integer > adj[];
					        	private HashMap<String ,Integer> hs =new HashMap<>();
					        

					        	Graph(int V){
					        		V++;
					        
					        		
					        		

					        		this.V=(V);
					        		adj=new LinkedList[V];
					        		

					        			

					        		
					        			
					        		

					        	 
					        	}
					        	void addEdge(int v,int w,int t){
					        		if(adj[v]==null){
					        			adj[v]=new LinkedList();
					        		}
					        		adj[v].add(w);
					        		String temp="";
					        		temp+=v;
					        		temp+=w;
					        		

					        		if(!hs.containsKey(temp))
					        		hs.put(temp, t);
					        	
					        	}
					        	public long  bfs(int s)
					            {
					        		co=0;
					                

					                

					                boolean visited[] = new boolean[V];
					         
					                

					                LinkedList<Integer> queue = new LinkedList<Integer>();
					         
					                

					                visited[s]=true;
					                queue.add(s);
					         
					                while (queue.size() != 0)
					                {
					                    

					                    s = queue.poll();
					                   

					         
					                    

					                    

					                    

					                    Iterator<Integer> i = adj[s].listIterator();
					                    while (i.hasNext())
					                    {
					                        int n = i.next();
					                        if (!visited[n])
					                        {
					                            visited[n] = true;
					                            queue.add(n);
					                        co++;
					                        }
					                    }
					                    return co;
					                }
					                return 0;
					            }
					        	 public long  dfs(int startVertex){
					        		
					        		boolean Visited[]=new boolean[V];
					        		
					        		

					        		
					        		 if(!Visited[startVertex])  {
					        			
					        			 co=0; 
					        			 dfsUtil(startVertex,Visited);
					           		 
					        		 }
					        		 
					        		 return co;
					        	 }
					        	 public void Connected(int v){
					        		 Iterator<Integer> i = adj[v].listIterator();
					        		 while(i.hasNext()){
					        			 int n=i.next();
					        			 long data=(long)d[n]+(long)d[v];
					        			 data=data%1000000007;
					        			 d[n]=(int)data;
					        		 }
					        	 }
					        	 public int getByte(int v){
					        		 return d[v];
					        	 }
					        	private void dfsUtil(int startVertex, boolean[] Visited) {
					        		

					        		
					        		Visited[startVertex]=true;
					        		
					        		
					        		st.push(startVertex);
					        		while(!st.isEmpty()){
					        			int top=st.pop();
					        			System.out.print(top+" ");
					        			
					        			

					        		Iterator<Integer> i=adj[top].listIterator();
					        	
					        		while(i.hasNext()){
					        			int n=i.next();
					        		

					        			 if( !Visited[n]){
					        				Visited[n]=true;
					        					st.push(n);
					        					co++;
					        					}
					        			 }
					        		
					        	}
					        		}
					        }
					
					        class Dsu{
					        	private int rank[], parent[] ,n;
					        	
					        	Dsu(int size){
					        		this.n=size+1;
					        		rank=new int[n];
					        		parent=new int[n];
					        	makeSet();
					        	}
					        	
					        	void makeSet(){
					        		for(int i=0;i<n;i++){
					        			parent[i]=i;
					        		}
					        	}
					        	
					        	int find(int x){
					        		if(parent[x]!=x){
					        			
					        			parent[x]=find(parent[x]);
					        		}
					        		return parent[x];
					        	}	
					        	
					        	void union(int x,int y){
					        		int xRoot=find(x);
					        		int yRoot=find(y);
					        		
					        		if(xRoot==yRoot)
					        			return;
					        		if(rank[xRoot]<rank[yRoot]){
					        		parent[xRoot]=yRoot;	
					        		}else if(rank[yRoot]<rank[xRoot]){
					        			parent[yRoot]=xRoot;
					        		}else{
					        			parent[yRoot]=xRoot;
					        			rank[xRoot]++;
					        		}
					        		
					        	}
					        }
					
					        
