 import java.io.*;
    import java.util.*;
  
 
  
        public class Codeforces {
    	
    		   public static long log2(long x)
    			{
    				long p=1;
    				long ans=0;
    				while(x>=p)
    				{
    					p*=2;
    					ans++;
    				}
    				return ans-1;
    			}
    		   
    		   
    		   public static void id2(int a, int b)
    		   {
    			   x=0;
    			   y=0;
    			   gc=0;
    			   id1(a,b);
    			   pw.println(a+"*"+x+" + "+b+"*"+y+" = "+gc);
    			   
    		   }
    		   
    		   
    		   public static long modex(long a, long b, long c)
    		   {
    			   if(b==0)
    				   return 1;
    			   else if(b==1)
    				   return a%c;
    			   else if(b%2==0)
    			   {
    				   	return modex((a*a)%c,b/2,c);
    			   }
    			   else
    			   {
    				   return (a*modex((a*a)%c,b/2,c))%c;
    				   
    			   }
    			   
    			   
    		   }
    		   
    		   
    		   public static void id1(int a, int b)
    		   {
    			   
    			   if(b==0)
    			   {
    				   x=1;
    				   y=0;
    				   gc=a;
    				   
    				   
    			   }
    			   else
    			   {
    				   id1(b,a%b);
    				   int temp = x;
    				   x=y;
    				   y = temp - ((a/b)*y);
    				   
    			   }
    		   }
    		   
    		   public static long gcd(long a, long b)
    		   {
    			   if(b==0)return a;
    			   else return gcd(b,a%b);
    			   
    		   }
    		   
    		   static int x,y,gc;
    		   
    		  
    		
    		   
    		   static HashSet<Character> set;
    		   
    		   
    		   
    		   public static long expmod(long a, long b, long mod)
    		   {
    			   if(b==0)return 1;
    			   if(b==1)return a;
    			   
    			   if(b%2==0)
    			   {
    				   return ((expmod(a,b/2,mod)%mod)*(expmod(a,b/2,mod)%mod))%mod;
    			   }
    			   else
    			   {
    				   return ((a%mod)*(expmod(a,b/2,mod)%mod)*(expmod(a,b/2,mod)%mod))%mod;
    			   }
    		   }
    		   
    		   static class Comp implements Comparator<Point>
    		   {

				@Override
				public int compare(Point arg0, Point arg1) {
					
					if(arg0.x>arg1.x)return 1;
					if(arg0.x<arg1.x)return -1;
					return 0;
				}
    			   
    		   }
    		   
    		   
    		   static class STComp implements Comparator<Integer>
    		   {

				@Override
				public int compare(Integer arg0, Integer arg1) {
					
					return arg0.compareTo(arg1); 
				}
    			   
    		   }
    		   
    		   static class Point
    		   {
    			   int x,y,ind;
    			   
    			    public Point(int a, int b)
    			    {
    			    	x=a;
    			    	y=b;
    			    	ind=0;
    			    }
    			   
    			    
    		   }
    		   
    		 
    		   
    		  
    		   
    		   public static boolean issub(String s1, String s2)
    		   {
    			   if(s1.length()>s2.length())
    			   return false;
    			   
    			   int l1 = s1.length();
    			   int l2 = s2.length();
    			   
    			   
    			   for(int i=0;i<=l2-l1;i++)
    			   {
    				   String sub = s2.substring(i, i+l1);
    				   if(s1.equals(sub))return true;
    			   }
    			   
    			   return false;
    		   }
    		   
    		   
    		   
    		   public static String enc(String s, int n)
    		   {
    			   String s1 = s.substring(0,n);
    			   String s2 = s.substring(n, s.length());
    			   
    			  String re="";
    			  for(int i=s1.length()-1;i>=0;i--)re+=s1.charAt(i);
    			  
    			  return re+s2;
    			   
    			   
    			   
    		   }
    		 
    		   
    		   
    		   static int vis[];
    		   
    		   public static void dfs(int x)
    		   {
    			   vis[x]=1;
    			   
    			   ArrayList<Integer> li = adj[x];
    			   
    			   for(int ch:li)
    			   {
    				   
    				   if(vis[ch]==0)dfs(ch);
    				   
    			   }
    			   
    		   }
    		   
    		   
    		  
    		
    		   public static void countPaths(int s, int d, ArrayList<Integer> pa)
    		   {
    			   
    			   vis2[s]=1;
    			   if(s==d)
    			   {
    				   pa.add(s);
    				 

    				   ct++;
    			   }
    			   else
    			   {
    				   ArrayList<Integer> li = adj[s];
    				   pa.add(s);
    				   
    				   for(int ad: li)
    				   {
    					   if(vis2[ad]==0)countPaths(ad,d,pa);
    				   }
    				   
    				   
    			   }
    			   
    			   if(pa.size()>1)pa.remove(pa.size()-1);
    			   vis2[s]=0;
    			   return ;
    		   }
    		  
    		   
    		   
    		   public static boolean dif(String s1, String s2)
    		   {
    			   int ct=0;
    			   if(s1.length()!=s2.length())return false;
    			   for(int i=0;i<s1.length();i++)
    			   {
    				   if(s1.charAt(i)!=s2.charAt(i))ct++;
    				   
    			   }
    			   
    			   if(ct==1)return true;
    			   else return false;
    			   
    			   
    		   }
    		   
    		   
    		   
    		   
    		   static void add(int arr[], int N, int lo,
                       int hi, int val)
    		   {
							    arr[lo] += val;
							    if (hi != N - 1)
							       arr[hi + 1] -= val;
    		   }
 




static void updateArray(int arr[], int N)
{
    

    for (int i = 1; i < N; i++)
        arr[i] += arr[i - 1];
}
  


static void printArr(int arr[], int N)
{
    updateArray(arr, N);
    for (int i = 0; i < N; i++)
        System.out.print(""+arr[i]+" ");
    System.out.print("\n");
}
  
    		   
  
    		  static int cyc;
    		   
    		   
    		  
    		  public static void dfsmod(int v, HashSet<Integer> set)
    		  {
    			  vis2[v]=1;
    			  
    			  ArrayList<Integer> li = adj[v];
    			  
    			  set.add(v);
    			  
    			  for(int ch: li)
    			  {
    				  if(set.contains(ch))
    				  {
    					  cyc=1;
    					  pw.println("** "+ch+" "+v);
    				  }
    				  if(vis2[ch]==0)dfsmod(ch,set);
    				  
    			  }
    			  
    			  set.remove(v);
    			  
    			  
    		  }
    		  
    		  
    		  	public static boolean isps(int x)
    		  	{
    		  		int sq = (int)Math.sqrt(x);
    		  		
    		  		return sq>0&&sq*sq==x;
    		  		
    		  		
    		  		
    		  		
    		  		
    		  		
    		  		
    		  		
    		  		
    		  	}
    		  
    		  	 public static void combinations(String suffix,String prefix)
    		  	 {
    		         if(prefix.length()<0)return;
    		         pw.println(suffix);
    		        	 
    		        	 
    		         for(int i=0;i<prefix.length();i++)
    		          combinations(suffix+prefix.charAt(i),prefix.substring(i+1,prefix.length()));
    		         
    		     }
    		  	
    		  	
    		  	 
    		
    		  	 
    		  	 
    		  	 public static void topo(int x)
    		  	 {
    		  		 vis2[x]=1;
    		  		

    		  		 ArrayList<Integer> li = adj[x];
    		  		

    		  		

    		  		 for(int ch: li)
    		  		 {
    		  			
    		  			 if(vis2[ch]==0)
    		  				 {topo(ch);
    		  				

    		  				 }
    		  		 }
    		  		 
    		  		 st.push(x);
    		  		 

    		  	 }
    		  	 
    		  	 
    	  		   

    		 	static  ArrayList<Integer>[] adj;
    		 	static int[] vis2;
    		 	static int ct;

    		     public static void ch(Stack<Integer> s)
    		     {
    		    	 s.push(4);
    		    	 return;
    		     }
    		     
    		     static Stack<Integer> st;
    		     
    		     
    		     static class PQnode implements Comparable<PQnode>
    		     {
    		    	 int value;
    		    	 int distance;
    		    	 
    		    	 public PQnode(int x, int y)
    		    	 {
    		    		 value=x;
    		    		 distance=y;
    		    	 }

					@Override
					public int compareTo(PQnode o) {
					return Integer.compare(this.distance, o.distance);
						
					
					
					}
					
					
					  @Override
		    		    public  boolean equals(Object o)
		    		    {
		    		    	if(o==this)return true;
		    		    	
		    		    	if(!(o instanceof PQnode))
		    		    	{
		    		    		return false;
		    		    	}
		    		    	
		    		    	PQnode node = (PQnode) o;
		    		    	
		    		    	return value==node.value&&distance==node.distance;
		    		    	
		    		    }
    		     }
    		  
    		  
    		     static class Compq implements Comparator<PQnode>
    		     {

					
					public int compare(PQnode arg0, PQnode arg1) {
						
						if(arg0.distance>arg1.distance)return 1;
						if(arg0.distance<arg1.distance)return -1;
						return 0;
					}
    		    	 
    		    	 
    		    	 
    		     }
    		     
    		     public static void printpa(int pa[],int x)
    		     {
    		    	 if(pa[x]==-1)
    		    		 
    		    		 pw.println(x);
    		    	 else
    		    	 {
    		    		 printpa(pa, pa[x]);
    		    		 pw.println(x);
    		    	 }
    		     }
    		     
    		     
    		     static class Node
    		     {
    		    	 int data;
    		    	 Node next;
    		    	 
    		    	 public Node(int x)
    		    	 {
    		    		 data =x;
    		    		 next=null;
    		    	 }
    		     }
    		     
    		     static Node he;
    		     static Node rev(Node n)
    		     {
    		    	 if(n.next==null)
    		    	 {
    		    		he=n;
    		    		return n;
    		    		 
    		    	 }
    		    	 else
    		    	 {
    		    		 Node rt = rev(n.next);
    		    		 rt.next=n;
    		    		 return n;
    		    	 }
    		    	 
    		     }
    		     
    		     
    		     public static void main(String[] args) 
    	   {
    		  		
    		    	int n = sc.nextInt();
    		    	int d = sc.nextInt();
    		    	
    		    	int arr[] = new int[n];
    		    	
    		    	HashSet<Integer> set = new HashSet<Integer>();
    		    	
    		    	for(int i=0;i<n;i++)
    		    	{	arr[i]=sc.nextInt();
    		    		set.add(arr[i]);
    		    	}
    		    	
    		    	
    		    	if(n==1)
    		    	{
    		    		pw.println(2);
    		    		pw.close();
    		    		return;
    		    	}
    		    	
    		    	for(int i=0;i<n;i++)
    		    	{
    		    		int ai = arr[i];
    		    		int h2 = ai+d;

	    				int h1 = ai-d;
    		    		
    		    			
    		    			if(i==0)
    		    			{
    		    				
    		    				if(!set.contains(h2)&&Math.abs(arr[i+1]-h2)>=d)set.add(h2);
    		    				if(!set.contains(h1))set.add(h1);
    		    				
    		    			}
    		    			else if(i==n-1)
    		    			{
    		    				if(!set.contains(h1)&&Math.abs(arr[i-1]-h1)>=d)set.add(h1);
    		    				if(!set.contains(h2))set.add(h2);
    		    				
    		    			}
    		    			else
    		    			{
    		    				
    		    				
    		    				
    		    				
    		    				
    		    				if(!set.contains(h2)&&Math.abs(arr[i+1]-h2)>=d)set.add(h2);
    		    				
    		    			
    		    				if(!set.contains(h1)&&Math.abs(arr[i-1]-h1)>=d)set.add(h1);
    		    				
    		    			}
    		    	}		
    		    		
    		    	

    		    	pw.println((set.size()-n));
    		    	
    		    	
    		    	
    		    	

    		    	 
    		    	 
    		    	 
    		    	 
    		    	
    		    	
    		    	
    		    	
    		    	 
    		  			
    		  				
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    				 
    			
    			   
    			   
    			   
    		
    			   
    			   
    	
    			   
    			    
    			   
    			   
    			   
    			   
    			
    			
    			
    			   

    		 
    			   
    			    
    			   
    			   
    			   
    		
    			 
    			  
    			pw.close();  
    			   
    	   }
    		   
    		   
    		   
    		   static  class MyScanner 
    			{
    	
    			BufferedReader br;
    			StringTokenizer st;
    	
    			public MyScanner() 
    			{
    				br = new BufferedReader(new InputStreamReader(System.in));
    			}
    	
    			String next() 
    			{
    				
    				while (st == null || !st.hasMoreElements()) 
    				{
    					try 
    					{
    						st = new StringTokenizer(br.readLine());
    					} catch (IOException e) 
    					{
    						e.printStackTrace();
    					}
    				}
    				return st.nextToken();
    			}
    	
    			int nextInt() 
    			{
    				return Integer.parseInt(next());
    			}
    	
    			long nextLong() 
    			{
    				return Long.parseLong(next());
    			}
    	
    			double nextDouble() 
    			{
    				return Double.parseDouble(next());
    			}
    	
    			String nextLine()
    			{
    				String str = "";
    				try 
    				{
    					str = br.readLine();
    				} catch (IOException e) 
    				{
    					e.printStackTrace();
    				}
    				return str;
    			}
    	
    		}
    	
    		static MyScanner sc = new  MyScanner();
    		static PrintWriter pw = new PrintWriter(System.out, true);
    		
    		static class id0
    		{
    			int[] parent;
    			int[] rank;
    			int n;
    			
    			public id0(int x)
    			{
    				n=x;
    				parent = new int[x];
    				rank = new int[x];
    				
    				for(int i=0;i<n;i++)
    				{
    					parent[i]=i;
    				}
    				
    			}
    			
    			public int find(int x)
    			{
    				
    				if(parent[x]==x)
    					return x;
    				else 
    					return find(parent[x]);
    			}
    			
    			public void union(int i, int j)
    			{
    				int iroot = find(i);
    				int jroot = find(j);
    				
    				if(iroot==jroot)
    					return;
    				
    				if(rank[iroot]<rank[jroot])
    				{
    					parent[iroot]=jroot;
    					
    				}
    				else if(rank[jroot]<rank[iroot])
    				{
    					parent[jroot]=iroot;
    				}
    				else
    				{
    					parent[iroot]=jroot;
    					rank[jroot]++;
    					
    				}
    				
    				
    				
    				
    			}
    			
    			
    			
    			
    			
    		}
    	
    		
    	}  