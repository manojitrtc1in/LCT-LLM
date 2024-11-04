

import java.util.*;
import java.io.*;
import java.math.*;
import java.util.Comparator;
public class Main
{
 
	private static final Comparator<? super Integer> Comparator = null;
	static LinkedList<Integer> adj[];
	static ArrayList<Integer> adj1[];
	static int[] color,visited1;
	static boolean b[],visited[],possible;
	static int level[];
	static Map<Integer,HashSet<Integer>> s;
	static int totalnodes,colored;
	static int count[];
	static long sum[];
	static int nodes;
	static long ans=0;
	static long[] as=new long[10001];
	static long c1=0,c2=0;
	static int[] a,d,k;
	static int max=100000000;
	static long MOD = 1000000007,sm=0,m=Long.MIN_VALUE;
	static boolean[] prime=new boolean[1000005];
	static int[] levl;
    static int[] eat;
    static int price[];
    static int res[],par[],co[];
    static int result=0;
    static int[] root,size,du,dv;
    static long p=Long.MAX_VALUE;
    static int start,end,r=0;
    static boolean[] vis1,vis2;
    static int to;
    static HashMap<Pair,Integer> hs;
    static boolean ns;
    static Node head;
    static String st,t;
    static long n;
  
	

	
	public static void main(String[] args) throws IOException
	{
		in=new InputReader(System.in);
	    w=new PrintWriter(System.out);

	      int n=ni(),k=ni();
	      long[] r=nla(n);
	      long[] ans=new long[n];
	      for(int i=0;i<k;i++)
	      {
	    	  int u=ni()-1,v=ni()-1;
	    	  if(r[u]!=r[v])
	    	  {
	    		  long t=Math.max(r[u],r[v]);
	    		  if(t==r[u])
	    			  ans[u]--;
	    		  else
	    			  ans[v]--;
	    	  }
	      }
          long[] st=new long[n];
          for(int i=0;i<n;i++)
        	  st[i]=r[i];
          sort(st);
       
          for(int i=0;i<n;i++)
          {
        	  long key=r[i];
        	  int l=0,h=n-1;
        	  int as=-1;
        	  while(l<=h)
        	  {
        		  int mid=l+(h-l)/2;
        		  if(st[mid]<key)
        		  {
        			  as=mid;
        			  l=mid+1;
        		  }
        		  else
        			  h=mid-1;
        	  }
        	  ans[i]+=(as+1);
        	  w.print(ans[i]+" ");
          }
	      
      
       w.close();
	}
	
	
	
	


	
	public static void sort(long[] a)
	{
	   ArrayList<Long> al=new ArrayList<Long>();
	   for(int i=0;i<a.length;i++)
		   al.add(a[i]);
	   Collections.sort(al);
	   for(int i=0;i<a.length;i++)
		   a[i]=al.get(i);
	}
	public static void dfs(int n,boolean[] vis,int cl,int[] c)
	{
	
		vis[n]=true;
		if(c[n]!=cl)
			ns=false;
		for(int i:adj[n])
		{
			if(!vis[i])
			{
				 dfs(i,vis,cl,c);
			}
		}
		
	}

	static long pow(long a, long b, long c) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}
	
	public static long kadane(long[] a,int n)
	{
		 long max_here=0,max_so_far=-Long.MAX_VALUE;
	        for(int i=0;i<n;i++)
	        {
	        	 if(max_here<0)
	                   max_here=0;
	        	
	        	 max_here+=a[i];
	          
	             
	      
	           if(max_here>max_so_far)
	                    max_so_far=max_here;
	          
	                  
	        }
		return max_so_far;
	}
	public static class SegmentTreeRMQ
	{
	    int st[]; 

	 
	    

	    int minVal(int x, int y) {
	        return (x < y) ? y : x;
	    }
	 
	    

	    

	    int getMid(int s, int e) {
	        return s + (e - s) / 2;
	    }
	 
	    
	    int RMQUtil(int ss, int se, int qs, int qe, int index)
	    {
	        

	        

	        if (qs <= ss && qe >= se)
	            return st[index];
	 
	        

	        if (se < qs || ss > qe)
	            return Integer.MIN_VALUE;
	 
	        

	        int mid = getMid(ss, se);
	        return minVal(RMQUtil(ss, mid, qs, qe, 2 * index + 1),
	                RMQUtil(mid + 1, se, qs, qe, 2 * index + 2));
	    }
	 
	    

	    

	    int RMQ(int n, int qs, int qe)
	    {
	        

	        if (qs < 0 || qe > n-1 || qs > qe) {
	            System.out.println("Invalid Input");
	            return 1;
	        }
	 
	        return RMQUtil(0, n - 1, qs, qe, 0);
	    }
	 
	    

	    

	    int constructSTUtil(int arr[], int ss, int se, int si)
	    {
	        

	        

	        if (ss == se) {
	            st[si] = arr[ss];
	            return arr[ss];
	        }
	 
	        

	        

	        int mid = getMid(ss, se);
	        st[si] = minVal(constructSTUtil(arr, ss, mid, si * 2 + 1),
	                constructSTUtil(arr, mid + 1, se, si * 2 + 2));
	        return st[si];
	    }
	 
	    
	    void constructST(int arr[], int n)
	    {
	        

	 
	        

	        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
	 
	        

	        int max_size = 2 * (int) Math.pow(2, x) - 1;
	        st = new int[max_size]; 

	 
	        

	        constructSTUtil(arr, 0, n - 1, 0);
	    }
	 
	    

	
	}
	
	public static int fact(int n)
	{
		HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
		boolean ans=true;
		 while (n%2==0)
	        {
	            if(hm.containsKey(2))
	            {	hm.put(2,hm.get(2)+1);
	            ans=false;
	            }
	            else
	            	hm.put(2,1);
	            n /= 2;
	        }
	 
	        

	        

	        for (int i = 3; i <= Math.sqrt(n); i+= 2)
	        {
	            

	            while (n%i == 0)
	            {
	            	  if(hm.containsKey(i))
	  	            	{hm.put(i,hm.get(i)+1);
	  	            	ans=false;
	  	            	}
	  	            else
	  	            	hm.put(i,1);
	                n /= i;
	            }
	        }
	 
	        

	        

	        if (n > 2)
	        	 if(hm.containsKey(n))
	  	            	{hm.put(n,hm.get(n)+1);
	  	            	ans=false;
	  	            	}
	  	            else
	  	            	hm.put(n,1);
		if(ans)
			return hm.size();
		else
			return -1;
	}
	public static int binary_search(long[] a,long k,int l,int r)
	{
		
		while(l<=r)
		{
			int mid=(l+r)/2;
			 if(a[mid]>=k)
			{
				r=mid-1;
			}
			else
				l=mid+1;
		}
		return l;
	}

	static class Pair implements Comparable<Pair>
	 {
		 Long x;
		 Long y;
	     
	        Pair(long x,long y)
	        {
	            this.x=x;
	            this.y=y;
	     
	        }
	        public int compareTo(Pair p)
	        {
	            return Long.compare(this.y,p.y);
	        }
		
	}
	   public static void removeDuplicates()
	    {
	         Node cur=head;
	         while(cur!=null)
	         {
	        	

	             int k=cur.data;
	             Node p=cur.next;
	             Node pre=cur;
	             while(p!=null)
	             {
	            	

	                 if(p.data==k)
	                 {
	                     pre.next=p.next;
	                     p=pre.next;
	                 }
	                 else
	                 {
	                     p=p.next;
	                     pre=pre.next;
	                 }
	             }
	             cur=cur.next;
	         }
	     
	    }

	public static void insert_front(int x)
	{
		Node f=new Node(x);
		f.next=head;
		head=f;
	}
	public static void insert_mid(Node x,int d)
	{
		if(x==null)
		{
			w.println("Nothing can be shown");
			return;
		}
		Node nex=x.next;
		Node ne=new Node(d);
		x.next=ne;
		ne.next=nex;
	}
	public static void insert_end(int x)
	{
		Node f=new Node(x);
		Node temp=head;
		while(temp.next!=null)
			temp=temp.next;
		temp.next=f;
			
	}
	public static class Node
	{
		int data;
		Node next;
		Node(int d)
		{
			this.data=d;
			this.next=null;
		}
	}


     

	
	
	
	
	public static void shuffle(long[] a,int n)
	{
		Random r=new Random();
		for(int i=n-1;i>0;i--)
		{
			int j=r.nextInt(i);
			long t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	public static void bfs1(int u)
	{
	    Queue<Integer> q=new LinkedList();
	    q.add(u);
	    visited[u]=true;
	    while(!q.isEmpty())
	    {
	    	

	    	int p=q.poll();
	      for(int i=0;i<adj[p].size();i++)
	     { 
	    	  if(!visited[adj[p].get(i)])
	    	  {
	    	q.add(adj[p].get(i));
	    	visited[adj[p].get(i)]=true;
	    	  }
	    	  levl[adj[p].get(i)]=levl[p]+1;
	    	  }
	    }
	    
	}
	public static void bfs2(int u)
	{
	    Queue<Integer> q=new LinkedList();
	    q.add(u);
	    vis2[u]=true;
	    while(!q.isEmpty())
	    {
	    	int p=q.poll();
	      for(int i=0;i<adj[p].size();i++)
	     { 
	    	  if(!vis2[adj[p].get(i)])
	    	  {
	    	dv[adj[p].get(i)]=dv[p]+1;
	    	q.add(adj[p].get(i));
	    	  
	    	vis2[adj[p].get(i)]=true;
	    	  }
	    	  }
	    }
	    
	}
	 public static void buildgraph(int n)
	 {
         adj=new LinkedList[n+1];
         visited=new boolean[n];
         level=new int[n];
         par=new int[n];
         for(int i=0;i<=n;i++)
         	{
        	 adj[i]=new LinkedList<Integer>();
         	
         	}
      
	 }
	
	
	

	 static  class npair implements Comparable<npair>
	 {
	     int a,b;
	     
	
		npair(int a,int b)
		{
			this.a=a;
			this.b=b;
			

		}


		public int compareTo(npair o) {
			

			return Integer.compare(this.a,o.a);
		}


	
		
	}
	public static int root(int i)
	{
		while(root[i]!=i)
		{
			root[i]=root[root[i]];
			i=root[i];
		}
		return i;
	}
	
	public static void init(int n)
	{
		root=new int[n+1];
		for(int i=1;i<=n;i++)
			root[i]=i;
	}
	public static void union(int a,int b)
	{
	    int root_a=root(a);	
	    int root_b=root(b);
	    root[root_a]=root_b;
	   

	}


	
	public static boolean isPrime(long n)
	{
	    

	    if (n <= 1)  return false;
	    if (n <= 3)  return true;
	 
	    

	    

	    if (n%2 == 0 || n%3 == 0)
	    	return false;
	 
	    for (long i=5; i*i<=n; i=i+6)
	        if (n%i == 0 || n%(i+2) == 0)
	           return false;
	 
	    return true;
	}
	

	
	public static String ns()
	{
		return in.nextLine();
	}
	public static int ni()
	{
		return in.nextInt();
	}
	public static long nl()
	{
		return in.nextLong();
	}
	public static int[] na(int n)
	{
		int[] a=new int[n];
		for(int i=0;i<n;i++)
		a[i]=ni();
		return a;
	}
	public static long[] nla(int n)
	{
		long[] a=new long[n];
		for(int i=0;i<n;i++)
		a[i]=nl();
		return a;
	}
	public static void sieve()
	    {
	       int n=prime.length;
	        for(int i=0;i<n;i++)
	            prime[i] = true;
	         
	        for(int p = 2; p*p <=n; p++)
	        {
	            if(prime[p] == true)
	            {
	                for(int i = p*2; i <n; i += p)
	                    prime[i] = false;
	            }
	        }
	    }

  public static String rev(String s)
	{
		StringBuilder sb=new StringBuilder(s);
		sb.reverse();
		return sb.toString();
	}
	static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}
	static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; 

	        a = temp;
	    }
	    return a;
	}
	static InputReader in;
	static PrintWriter w;
static class InputReader 
{
 
private final InputStream stream;
private final byte[] buf = new byte[8192];
private int curChar, snumChars;
private SpaceCharFilter filter;
 
public InputReader(InputStream stream)
{
  this.stream = stream;
}
 
public int snext()
{
  if (snumChars == -1)
    throw new InputMismatchException();
  if (curChar >= snumChars)
  {
    curChar = 0;
    try 
    {
      snumChars = stream.read(buf);
    }
    catch (IOException e)
    {
      throw new InputMismatchException();
    }
    if (snumChars <= 0)
      return -1;
  }
  return buf[curChar++];
}
 
public int nextInt() 
{
  int c = snext();
  while (isSpaceChar(c)) 
  {
    c = snext();
  }
  int sgn = 1;
  if (c == '-')
  {
    sgn = -1;
    c = snext();
  }
  int res = 0;
  do
  {
    if (c < '0' || c > '9')
      throw new InputMismatchException();
    res *= 10;
    res += c - '0';
    c = snext();
  }
  while (!isSpaceChar(c));
  return res * sgn;
}
 
public long nextLong() 
{
  int c = snext();
  while (isSpaceChar(c)) 
  {
    c = snext();
  }
  int sgn = 1;
  if (c == '-')
  {
    sgn = -1;
    c = snext();
  }
  long res = 0;
  do
  {
    if (c < '0' || c > '9')
      throw new InputMismatchException();
    res *= 10;
    res += c - '0';
    c = snext();
  }
  while (!isSpaceChar(c));
  return res * sgn;
}	    
public String readString() 
{
  int c = snext();
  while (isSpaceChar(c)) 
  {
    c = snext();
  }
  StringBuilder res = new StringBuilder();
  do
  {
    res.appendCodePoint(c);
    c = snext();
  }
  while (!isSpaceChar(c));
  return res.toString();
}
 
public String nextLine() 
{
  int c = snext();
  while (isSpaceChar(c))
    c = snext();
  StringBuilder res = new StringBuilder();
  do
  {
    res.appendCodePoint(c);
    c = snext();
  }
  while (!isEndOfLine(c));
  return res.toString();
}
 
public boolean isSpaceChar(int c)
{
  if (filter != null)
    return filter.isSpaceChar(c);
  return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
private boolean isEndOfLine(int c) 
{
  return c == '\n' || c == '\r' || c == -1;
}
 
public interface SpaceCharFilter
{
  public boolean isSpaceChar(int ch);
}
}
	
}