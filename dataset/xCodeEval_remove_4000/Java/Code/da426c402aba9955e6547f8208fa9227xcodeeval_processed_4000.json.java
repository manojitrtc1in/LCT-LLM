

        import java.io.*;
         
            import java.math.BigInteger;
        import java.text.DecimalFormat;
        import java.util.*;

         
             public class Main {
            	public static InputReader in;
                public static PrintWriter pw;
             
             
             
            	public static void main(String args[]) 
            	{
            		new Thread(null, new Runnable() {
                        public void run() {
                            try{
                                solve();
                            }
                            catch(Exception e){
                                e.printStackTrace();
                            }
                        }
                    }, "1", 1 << 26).start();
                }
            	static ArrayList<Integer> g[];
            	static ArrayList<Integer> h[];
            	static boolean visited[];
            	static int[] parent;
            	static int par[];
            	static int degree[];
            	static int edjes=0;
            	static int start=-1;
            	static int end=-1;
            	static int Total=0;
            	static int time1[];
            	static int time2[];
            	static int glob=0;
            	static int[] ans;
            	static boolean vis2[][];
            	

            	

                static ArrayList<Integer> levels[];
                static int max=0;
                static int lev=1;
                static ArrayList<Integer> nodes[];
                static ArrayList<Integer> values[];
                static int depth[];
                static boolean found=false;
               

                static int sum1=0;
                static int pre[][];
                static int subtree[];
               static  int cnt=0;
               static  HashMap<String,Integer> hm;
               static int sm[];
               static int size[];
               static long mul[];
               static long d[]=new long[1000000];
               static int tot=0;
               static long highest=(long)1e9;
               static boolean bit=false;
                static Stack<Integer> tt=new Stack();
               static HashSet<Character> set;
         	   static long fact[],num[];
         	   static long MOD=1000000007;
         	   static int value[];static int premen[];
         	   static int count=0,index=0;
         	   static double ans11[];
         	   static int price[];
         	   static ArrayList<String> hp[][];
         	   static boolean visit[][];
         	   static int cnu[]=new int[1000001];
         	   static int label=1;
         	   static int his[][];
         	   static int size1=0;
         	   static int up[],down[];
         	   static int TotalUp=0;
         	   static long dist[];
         	

         	  

         	   static TreeSet<Long> set1=new TreeSet();
         	  static  long DP[][][]=new long[20][200][1500];
         	 	static int t=-1,n=-1;
         	 	static int two[],min[],r[];
         	 	static int total[];static int black[];
         	 	static int Parent[];
         	 	static int max2[];
         	

         	 public static void solve() throws FileNotFoundException{
            		
            	
            		 in = new InputReader(System.in);
            		 pw = new PrintWriter(System.out);  
            	
                   int n=in.nextInt();
                   int a[]=in.id2(n);
                   HashMap<Integer,ArrayList<Integer>> hm=new HashMap();
                   for(int i=0;i<n;i++)
                   {
                	   if(!hm.containsKey(a[i]))
                	   {
                		   ArrayList<Integer> ar=new ArrayList();
                		   ar.add(i+1);
                		   hm.put(a[i],ar);
                	   }
                	   else
                	   {
                		   ArrayList<Integer> ar=hm.get(a[i]);
                		   ar.add(i+1);
                		   hm.put(a[i],ar);
                	   }
                   }
                   ST st=new ST(n,a);
                   int q=in.nextInt();
                   StringBuilder ans=new StringBuilder();
                   while(q-->0)
                   {
                	   int l=in.nextInt();int r=in.nextInt();l--;r--;
                	   int min=st.find(1,0, n-1, l, r).min;
                	   int gcd=st.find(1,0, n-1, l, r).gcd;
                	   if(min!=gcd)
                	   {
                		  ans.append((r-l+1)+"\n");
                		  continue;
                	   }
                	   else
                	   {
                		   ArrayList<Integer> temp=hm.get(min);
                		   int low=0;
                		   int high=temp.size()-1;
                		   int ansr=-1;
                		   l++;r++;
                		   int ansl=-1;
                           while(low<=high)
                		   {
                			   int mid=(low+high)/2;
                			   if(temp.get(mid)<l)
                			   {
                				   ansl=mid;
                				   low=mid+1;
                			   }
                			   
                			   else
                			   {

                                  high=mid-1;
                			    }
                		   }
                           
                           low=0;high=temp.size()-1;
                		   while(low<=high)
                		   {
                			   int mid=(low+high)/2;
                			   if(temp.get(mid)<=r)
                			   {
                				   ansr=mid;
                				  low=mid+1;
                			   }
                			   
                			   else
                			   {

                                  high=mid-1;
                			    }
                		   }
                         

                           int ansf=r-l+1;
                           if(ansl==-1)
                           {
                        	   ansf-=(ansr+1);
                           }
                           else
                           {
                        	   ansf-=(ansr-ansl);
                           }
                		   ans.append((ansf)+"\n");
                	   }
                   }
                   System.out.println(ans);
         	 }

         	static class ST 
         	    {
         	    	static int tree[];
         	    	static int A[];
         	    	static long B[];
         	    	int n;
         	    	static nodeST tre[],orig[];
         	    	
         	    	public ST(int n,int a[])
         	    	{
         	    		A=new int[n];
         	    		A=a;
         	    		tre=new nodeST[4*n+1];
         	    		for(int i=0;i<=4*n;i++)
         	        		tre[i]=new nodeST();
         	        	 
         	    		Build(1,0,n-1);
         	    	}
         	    	public static void Build(int v,int tl,int tr)
         	    	{
         	    		if(tl==tr)  
         	    		{
         	    		       tre[v].gcd=A[tl];
         	    		       tre[v].min=A[tl];
         	    		}
         	    			
         	    		
         	    		else
         	    		{
         	    			int mid=(tl+tr)/2;
         	    			Build(2*v,tl,mid);
         	    			Build(2*v+1,mid+1,tr);
         	    			nodeST a=tre[2*v];
         	    			nodeST b=tre[2*v+1];
         	    			tre[v]=combine(a,b,v);	
         	    		}
         	    		
         	    		
         	    	}
         	    	public static void Update(int v,int tl,int tr,int index,int val)
         	    	{
         	    		if(tl==tr)
         	    		{
         	    			tre[v].gcd=val;
         	    			tre[v].min=val;
         	    		}
         	    		else
         	    		{
         	    			int mid=(tl+tr)/2;
         	    			if(tl <= index &&index <= mid)
         	    	        {
         	    	            Update(2*v,tl, mid, index, val);
         	    	        }
         	    	        else
         	    	        {
         	    	        	Update(2*v+1,mid+1,tr, index, val);
         	    	        }
         	    			tre[v]=combine(tre[2*v],tre[2*v+1],v);
         	    		}
         	    	}
         	    	public static nodeST combine(nodeST a,nodeST b,int v)
         	    	{   nodeST res=new nodeST();
         	    	if(a.gcd==-1)return b;
         	    	if(b.gcd==-1)return a;
         	    	res.gcd=gcd(a.gcd,b.gcd);
         	    	res.min=Math.min(a.min,b.min);
         	    		return res;
         	    	}
         	    	public static int gcd(int x, int y) {
         	    		if (x == 0)
         	    			return y;
         	    		else
         	    			return gcd( y % x,x);
         	    	}	
         	    	public static nodeST find(int v,int start,int end,int l,int r)
         	    	{
         	    	
         	    	    if(r < start || end < l)
         	    	    {
         	    	        
         	    	        

         	    	    	nodeST temp=new nodeST();
         	    	    	temp.gcd=-1;
         	    	        return temp;
         	    	    }
         	    	    if(l <= start && end <= r)
         	    	    {
         	    	        

         	    	        return (tre[v]);
         	    	    }
         	    	    

         	    	    int mid = (start + end) / 2;
         	    	    nodeST p1 = find(2*v, start, mid, l, r);
         	    	    nodeST p2 = find(2*v+1, mid+1, end, l, r);
         	    	    return combine(p1,p2,v);          
         	    	}
         	    	
         	    static class nodeST
         	    {
         	    int gcd;
         	    int min;
         	    }
         	    class Pair implements Comparable<Pair>
         	    {
         	    	int x;
         	    	int y;
         	    	Pair(int val,int index){
         	    	     	this.x=val;
         	    			this.y=index;
         	    		}
         	    		@Override
         	    		public int compareTo(Pair o) {
         	                      return 0;
         	                      }
         	    				
         	    	}
         	    }
         	     
         	     


         	static class Pair1 implements Comparable<Pair1>
         	 {
                int x,y,z;
                public Pair1(int x,int y,int z)
    			{
    				this.x=x;this.y=y;this.z=z;
    			}
                @Override
    			public int compareTo(Pair1 o) {
    				if(o.x!=x)
    					return o.x-x;
    				else if(o.y!=y)
    					return o.y-y;
    				else
    					return o.z-z;
    			
    			}
         		 
         	 }
         	 
         	public static void bfs(int x)
         	 {
         		 visited[x]=true;
         		 Queue<Integer> Q=new LinkedList<Integer>();
         		 Q.add(x);
         		 while(!Q.isEmpty())
         		 {
         			 int count=Q.size();
         			 while(count>0)
         			 {
         				 int p=Q.poll();
         				 visited[p]=true;
         				 for(int y:g[p])
         				 {
         					 if(!visited[y])
         					 {
         						 Q.add(y);
         					 }
         				 }
         				 count--;
         			 }
         		 }
         	 }
         	 public static void depth(int curr,int parent)
         	 {
         		 visited[curr]=true;
         		 for(int x:g[curr])
         		 {
         			 if(!visited[x])
         			 {
         				 depth[x]=depth[curr]+1;
         				 depth(x,curr);
         			 }
         		 }
         	 }
         	
         	 static int Par[]=new int[202];
         	 public static void Height(int cur,int par){
         		 Par[cur]=par;
         		 visited[cur]=true;
         		 int t=0;
         		 for(int x:g[cur])
         		 {
         			 if(!visited[x])
         			 { 
         				 t++;
         				 Height(x,cur);
         				 high[cur]=Math.max(high[cur], high[x]+1);
         			 }
         		 }
         		 if(t==0)
         		 {
         			 high[cur]=0;
         		 }
         	
         	 }
         	 static int dia[]=new int[202];
         	 static int high[]=new int[292];
         	 public static void Diameter(int curr,int parent)
         	 {
         		visited[curr]=true;
         		int trees=0;
         		ArrayList<Integer> set=new ArrayList();
         	
         		for(int x:g[curr])
         		{
         			if(!visited[x])
         			{
         				trees++;
         				Diameter(x,curr);
         				dia[curr]=Math.max(dia[curr],high[x]);
         				set.add(high[x]);
         			}
         		}
         		if(set.size()>=2)
         		{
         			Collections.sort(set,Collections.reverseOrder());
         			dia[curr]=Math.max(dia[curr],set.get(0)+set.get(1)+2);
         		}
         		else if(set.size()>0)
         		{
         			dia[curr]=Math.max(dia[curr],set.get(0)+1);
         		}
         		if(trees==0)
         		{
         			dia[curr]=0;
         		}
         
         	 }
         	 
              	 
         	 public static boolean IsPal(String s)
         	 {
         		 char c[]=s.toCharArray();
         		 for(int i=0;i<c.length/2;i++)
         		 {
         			 if(c[i]!=c[s.length()-1-i])
         				 return false;
         		 }
         		 return true;
         	 }
         	public static void Merge(long[] a,int p,int r){
                if(p<r){
                    int q = (p+r)/2;
                    Merge(a,p,q);
                    Merge(a,q+1,r);
                    Merge_Array(a,p,q,r);
                }
            }
            public static void Merge_Array(long a[],int p,int q,int r){
               long b[] = new long[q-p+1];
                long c[] = new long[r-q];
                for(int i=0;i<b.length;i++)
                    b[i] = a[p+i];
                for(int i=0;i<c.length;i++)
                    c[i] = a[q+i+1];
                int i = 0,j = 0;
                for(int k=p;k<=r;k++){
                    if(i==b.length){
                        a[k] = c[j];
                        j++;
                    }
                    else if(j==c.length){
                        a[k] = b[i];
                        i++;
                    }
                    else if(b[i]<c[j]){
                        a[k] = b[i];
                        i++;
                    }
                    else{
                        a[k] = c[j];
                        j++;
                    }
                }
            }
         	 
         	 
         	 
         	
         	
               
         	  public static void dfs1(int curr,int parent)
         	  {
         		  visited[curr]=true;
         		  
         		  for(int x:g[curr])
         		  {
         			  
         			  if(x==parent)continue;
         			  depth[x]=depth[curr]+1;
         			  up[x]=up[curr];
         			  if(h[x].contains(curr)){
         				  up[x]++;
         				  TotalUp++;
         			  }
         			  dfs1(x,curr);
         		  }
         	  }
         	 
                
                
                public static void dfs(int curr,int Parent)
                {
                	visited[curr]=true;
                	size[curr]=1;
                	parent[curr]=Parent;
                	count++;
                	if(value[curr]>0)
                	{
                		index=value[curr];
                	}
                	for(int x:g[curr])
                	{
                		if(!visited[x])
                		{
                			dfs(x,curr);
                			size[curr]+=size[x];
                		}
                	}
                }
                static long ncr(long a, long b){
        			if(b>a || b<0) return 0;
        			long f = (fact[(int) a]*modInverse(((fact[(int) b]*fact[(int) (a-b)])%MOD), MOD))%MOD;
        			return f;
        		}
        		static long modInverse(long a, long id3){
                    return  power(a, id3-2, id3);
        }
        static long power(long x, long y, long m)
        {
            if (y == 0)
                return 1;
            long p = power(x, y/2, m) % m;
            p = (p * p) % m;
         
            return (y%2 == 0)? p : (x * p) % m;
        }
         
                public static long gcd(long x, long y) {
            		if (x == 0)
            			return y;
            		else
            			return gcd( y % x,x);
            	}	
                public static long power(long a,long b)
        		{
        			long result=1;
        			while(b>0)
        			{
        				if(b%2==1)
        					result*=a;
        				a=a*a;
        				b/=2;
        			}
        			return result;
        		}
                static class Pair implements Comparable<Pair>{
                	    int l;int r;
                		Pair(int val,int index){
                	     	this.l=val;
                			this.r=index;
                		}
                		@Override
                		public int compareTo(Pair o) {
                                 return 1;
                		}
                				
                	}
            	static class InputReader {
             
            		private InputStream stream;
            		private byte[] buf = new byte[8192];
            		private int curChar, id1;
            		private id4 filter;
             
            		public InputReader(InputStream stream) {
            			this.stream = stream;
            		}
             
            		public int snext() {
            			if (id1 == -1)
            				throw new InputMismatchException();
            			if (curChar >= id1) {
            				curChar = 0;
            				try {
            					id1 = stream.read(buf);
            				} catch (IOException e) {
            					throw new InputMismatchException();
            				}
            				if (id1 <= 0)
            					return -1;
            			}
            			return buf[curChar++];
            		}
             
            		public   int nextInt() {
            			int c = snext();
            			while (id0(c))
            				c = snext();
            			int sgn = 1;
            			if (c == '-') {
            				sgn = -1;
            				c = snext();
            			}
            			int res = 0;
            			do {
            				if (c < '0' || c > '9')
            					throw new InputMismatchException();
            				res *= 10;
            				res += c - '0';
            				c = snext();
            			} while (!id0(c));
            			return res * sgn;
            		}
             
            		public long nextLong() {
            			int c = snext();
            			while (id0(c))
            				c = snext();
            			int sgn = 1;
            			if (c == '-') {
            				sgn = -1;
            				c = snext();
            			}
            			long res = 0;
            			do {
            				if (c < '0' || c > '9')
            					throw new InputMismatchException();
            				res *= 10;
            				res += c - '0';
            				c = snext();
            			} while (!id0(c));
            			return res * sgn;
            		}
             
            		public int[] id2(int n) {
            			int a[] = new int[n];
            			for (int i = 0; i < n; i++)
            				a[i] = nextInt();
            			return a;
            		}
             
            		public String readString() {
            			int c = snext();
            			while (id0(c))
            				c = snext();
            			StringBuilder res = new StringBuilder();
            			do {
            				res.appendCodePoint(c);
            				c = snext();
            			} while (!id0(c));
            			return res.toString();
            		}
             
            		public boolean id0(int c) {
            			if (filter != null)
            				return filter.id0(c);
            			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            		}
             
            		public interface id4 {
            			public boolean id0(int ch);
            		}
            	}
            }
          
     

