 import java.io.*;
    import java.util.*;
  
 
  
        public  class Codeforces {
    	
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
					
					if(arg0.y>arg1.y)return 1;
					if(arg0.y<arg1.y)return -1;
					if(arg0.x>arg1.x)return -1;
					if(arg1.x>arg0.x)return 1;
					return 0;
				}
    			   
    		   }
    		   static class Comp2 implements Comparator<Point>
    		   {

				@Override
				public int compare(Point arg0, Point arg1) {
					
					if(arg0.ind>arg1.ind)return -1;
					if(arg0.ind<arg1.ind)return 1;
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
    			   long x,ind;
    			   long y;
    			    public Point(int a, int b)
    			    {
    			    	x=a;
    			    	y=b;
    			    	ind=a-b;
    			    	
    			    }
    			   
    			    @Override
    			    public boolean equals(Object o) 
    			    {
    			 
    			        

    			        if (o == this) {
    			            return true;
    			        }
    			 
    			        
    			        if (!(o instanceof Point)) {
    			            return false;
    			        }
    			         
    			        

    			        Point c = (Point) o;
    			         
    			        

    			        return x==c.x&&y==c.y;
    			                
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

					
					public int compare(PQnode arg0, PQnode arg1) 
					{
						
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
    		     
    		     
    		     
    		     
    		     
    		     
    		     public static int round(int st, int end, int a, int b)
    		     {
    		    	 int mid = (st+end)/2;
    		    	 
    		    	 if(a<=mid&&b>=mid+1)return 0;
    		    	 else
    		    	 {
    		    		 if(a<=mid&&b<=mid)
    		    		 {
    		    			 return 1+round(st,mid,a,b);
    		    			 
    		    		 }
    		    		 else
    		    		 {
    		    			 return 1+round(mid+1,end,a,b);
    		    			 
    		    		 }
    		    		 
    		    	 }
    		    	 
    		    	 
    		    	 
    		     }
    		     
    		     
    		     
    		     public static void cha(Point p)
    		     {
    		    	 p.x=10;
    		    	 p.y=5;
    		     }
    		     
    		     
    		     
    		     public static boolean varane(int[] ch, int com[], int k)
    		     {
    		    	 
    		    	 

    		    	 int kc=0;
    		    	 
    		    	 for(int i=1;i<ch.length;i++)
    		    	 {
    		    		 
    		    		 if(ch[i]>ch[i-1])kc++;
    		    		 
    		    	 }
    		    	 
    		    	 if(kc!=k)return false;
    		    	 for(int i=0;i<ch.length;i++)
    		    	 {
    		    		if(com[i]!=0)
    		    		{
    		    			if(com[i]!=ch[i])return false;
    		    			
    		    		}
    		    		 
    		    	 }
    		    	 return true;
    		    	 
    		     }
    		     static int anss;
    		     
    		     
    		     public static void gener(int nr,int kr,int[] oar,int per[], int ci,HashSet<Integer> nop)
    		     {
    		    	
    		    	 if(nop.isEmpty())
    		    	 {
    		    		
    		    		 pw.println("*****");
    		    		 for(int i=0;i<ci;i++)pw.print(per[i]+" ");
    		    		 pw.println();
     		    		 pw.println("*****");
    		    		 if(varane(per,oar,kr))
    		    			 {
    		    			 anss++;
    		    			
    		    			 }
    		    		 return;
    		    	 }
    		    	 if(ci>=nr)return;
    		    	 
    		    	 for(int d : nop)
    		    	 {
    		    		
    		    			 per[ci]=d;
    		    			 ci++;
    		    			
    		    			 HashSet<Integer> nxt = new HashSet<Integer>(nop);
    		    			 nxt.remove(d);
    		    			 gener(nr,kr,oar,per,ci,nxt);
    		    			 ci--;
    		    			 
    		    			
    		    			 
    		    		 
    		    		 
    		    	 }
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		     }
    		   
    		     
    		     
    		     public static boolean ch(double x, double[] a, double []b, double m)
    		     {
    		    	 int n = a.length;
    		    	 double fuel=x;
    		    	 int i=0,j=1;
    		    	 double tm = m+fuel;
    		    	 while(j<n)
    		    	 {
    		    		 tm = m+fuel;
    		    	
    		    		 double reqt = tm/a[i];
    		    		 fuel-=reqt;
    		    		 if(fuel<=0)return false;
    		    		 tm = m+fuel;
    		    		 double reql = tm/b[j];
    		    		 fuel-=reql;
    		    		 if(fuel<=0)return false;
    		    		 i++; j++;
    		    	 }
    		    	 tm = m+fuel;
    		    	

    		    	 double reqt = tm/a[n-1];
    		    	 
    		    	 fuel-=reqt;
    		    	 

		    		 if(fuel<=0)return false;
		    		

		    		 tm = m+fuel;
		    		 double reql = tm/b[0];
		    		 fuel-=reql;
		    		 

		    		

		    		 if(fuel<0)return false;
		    		

    		    	 return true;
    		     }
    		     
    		   
    		     public static void div(int x)
    		     {
    		         int cd=2;
    		         int xd=x;
    		         HashSet<Integer> curr = new HashSet<Integer>();
    		         
    		         while(xd!=1)
    		         {
    		    	curr.add(spa[xd]);
    		    	

    		    	xd/=spa[xd];
    		    	
    		         }
    		         
    		         for(int el : curr)
    		         {
    		             se.add(el);
    		             System.out.println(el);
    		         }
    		         
    		     }
    		     
    		    static HashSet<Integer> se;
    		     static int[] spa;
    		    
    		     public static int getr(String st)
    		     {
    		         String org = st;
    		         StringBuilder bdo = new StringBuilder(st);
    		         StringBuilder bd = new StringBuilder(st);
    		         int n = st.length();
    		         int ansi=-1;
    		         
    		         for(int i=1;i<=n;i++)
    		         {
    		             int si = 0;
    		             int ei = i-1;
    		             StringBuilder prt = new StringBuilder(bd.substring(si,ei+1));
    		             StringBuilder bdn = new StringBuilder(bd.substring(ei+1,bd.length()));
    		             bdn.append(prt);
    		             
    		             String form = bdn.toString();
    		             pw.println(form);
    		             if(org.equals(form))
    		             {
    		                 ansi=i;
    		                 break;
    		             }
    		             bd = new StringBuilder(form);
    		         }
    		         
    		         return ansi;
    		         
    		         
    		         
    		     }
    		     
    		     public  int lcm(int[] element_array)
    		     {
    		         int id3 = 1;
    		         int divi = 2;
    		          
    		         while (true) {
    		             int counter = 0;
    		             boolean divisible = false;
    		              
    		             for (int i = 0; i < element_array.length; i++) {
    		  
    		                 
    		  
    		                 if (element_array[i] == 0) {
    		                     return 0;
    		                 }
    		                 else if (element_array[i] < 0) {
    		                     element_array[i] = element_array[i] * (-1);
    		                 }
    		                 if (element_array[i] == 1) {
    		                     counter++;
    		                 }
    		  
    		                 
    		                 if (element_array[i] % divi == 0) {
    		                     divisible = true;
    		                     element_array[i] = element_array[i] / divi;
    		                 }
    		             }
    		  
    		            
    		             if (divisible) {
    		                 id3 = id3 * divi;
    		             }
    		             else {
    		                 divi++;
    		             }
    		  
    		            
    		             if (counter == element_array.length) {
    		                 return id3;
    		             }
    		         }
    		     }
    		     
    		     
    		     public static void main(String[] args) throws IOException 
    	   {
    		    	 
    		    	 int n = sc.nextInt();
    		    	
    		    	 int m = sc.nextInt();
    		    	 
    		    	 Point arr[] = new Point[n];
    		    	 
    		    	 for(int i=0;i<n;i++)
    		    	 {
    		    		 int a = sc.nextInt();
    		    		 int b = sc.nextInt();
    		    		 
    		    		 arr[i] = new Point(a,b);
    		    	 }
    		    	 
    		    	 Arrays.sort(arr, new Comp2());
    		    	 
    		    	 long suff[] = new long[n];
    		    	
    		    	 for(int i=n-1;i>=0;i--)
    		    	 {
    		    		 if(i==n-1)suff[i]=arr[n-1].x;
    		    		 else suff[i]=suff[i+1]+arr[i].x;
    		    	 }
    		    	 
    		    	 int cap = m,flg=-1;
    		    	 long cur=0;
    		    	 
    		    	 if(suff[0]<=m)
    		    	 {
    		    		 pw.println(0);
    		    		 pw.close();
    		    		 return ;
    		    	 }
    		    	 
    		    	 for(int i=0;i<n;i++)
    		    	 {
    		    		 if(i==n-1)
    		    		 {
    		    			 cur+=arr[i].y;
    		    			 if(cur<=m)
    		    			 {
    		    				 flg=n-1;
    		    			 }
    		    		 }
    		    		 else
    		    		 {
    		    			 
    		    		 cur+=arr[i].y;
    		    		 long te=cur+suff[i+1];
    		    		 if(te<=cap)
    		    		 {
    		    			 flg=i;
    		    			 break;
    		    		 }
    		    		 
    		    		 }
    		    	 }
    		    	 
    		    	 if(flg==-1)
    		    	 {
    		    		 pw.println(-1);
    		    	 }
    		    	 else
    		    	 {
    		    		 pw.println(flg+1);
    		    	 }
    		    	 
    		    	 pw.println();
    		    	 
    		    	 
    		    	
    		    	

    		    	

    		    	 
    		    	 
    		    	 
    		    
    		    	
    		    	

    		    	 
    		    	 
    		  

    		    
    		    
    		   
    		  

    		   

    		    
    		    	
    		    		
    		    		
    		    		
    		    	
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	
    		    	 
    		    	 
    		    
    		    
    		    	 
    		    	 
    		    	

    		    	
    		    	
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	
    		    	
    		    	
    		    	 
    		    	 
    		    	 
    		    			 
    		    			 
    		    	 
    		    	 
    		    	 
    		    	 

    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    	 
    		    			 
    		    	 
    		    	 
    		    	 
    		    	
    		    	

    		    	 
    		    	 
    		    	 
    		    	 
    		    	
    		    	
    		    	
    		    	
    		    	 
    		  			
    		  				
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    		  		 
    				 
    			
    			   
    			   
    			   
    		
    			   
    			   
    	
    			   
    			    
    			   
    			   
    			   
    			   
    			
    			
    			
    			   

    		 
    			   
    			    
    	
    			 
    			  
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
    		
    		
    		
    			static class id4 {

    		    int cap;
    		    int ctr;
    		    TreeMap<Integer, Integer> tm;
    		    HashMap<Integer, Integer> hm;
    		    
    		    public id4(int capacity)
    		    {
    		        cap = capacity;
    		      

    		        hm = new HashMap<Integer, Integer>();
    		        tm = new TreeMap<Integer, Integer>();
    		        ctr=0;
    		        

    		    }
    		    
    		    public int get(int key) 
    		    {
    		        
    		        ctr++;
    		        if(hm.containsKey(key))
    		        {
    		            
    		            int ti = hm.get(key);
    		            int ot = tm.get(ti);
    		            tm.remove(ot);
    		            
    		            int rt = ti;
    		            
    		            
    		            tm.put(ctr,key);
    		            
    		            hm.remove(key);
    		            hm.put(key,ctr);
    		            
    		            
    		            return rt;
    		        
    		        
    		        }
    		        else 
    		            return -1;
    		        
    		    }
    		    
    		    public void put(int key, int value) {
    		        
    		        ctr++;
    		        if(tm.size()<cap)
    		        {
    		             tm.put(value,key);
    		            hm.put(key,value);
    		            

    		            
    		        }
    		        else
    		        {
    		            int fe = tm.firstKey();
    		            int id = tm.get(fe);
    		           
    		            hm.remove(id);
    		            tm.remove(fe);
    		                
    		                
    		            tm.put(value,key);
    		            hm.put(key, value);
    		            
    		            
    		        }
    		        
    		    }
    		}
    		
    		
    		
    		
    		
    		
    		
    		
    		
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