import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
   public class Tester {
	

	

		static int visited[] = new int[100005];
		

		

	public static final long MOD = (long) (1e9 + 7);
		static long h[];
		static long j;
			

		    public static void main(String args[])
		     {
		    	Scanner sc=new Scanner(System.in);
		    	InputReader in = new InputReader(System.in);
		  	  	OutputStream outputStream = System.out;
		  	  	PrintWriter out = new PrintWriter(outputStream);
		  	  	int n=in.nextInt();
		  	  	int m=in.nextInt();
		  	  	int x=in.nextInt();
		  	  	x%=4;
		  	  	int y=in.nextInt();
		  	  	y%=4;		  	  	
		  	  	int z=in.nextInt();
		  	  	z%=4;
		  	  	int p=in.nextInt();
		  	  	while(p-->0)
		  	  	{
		  	  		int a=in.nextInt();
		  	  		int b=in.nextInt();
		  	  		int a1=a;
		  	  		int b1=b;
		  	  		int n1=n;
		  	  		int m1=m;
		  	  		int temp=0;
		  	  		for(int i=0;i<x;i++)
		  	  		{
		  	  			a1=b;
		  	  			b1=n1-a+1;
		  	  			a=a1;
		  	  			b=b1;
		  	  			temp=n1;
		  	  			n1=m1;
		  	  			m1=temp;
		  	  		}
		  	  		

		  	  		for(int i=0;i<y;i++)
		  	  		{
		  	  			a1=a;
		  	  			b1=m1-b+1;
		  	  			a=a1;
		  	  			b=b1;		  	  			
		  	  		}
		  	  		

		  	  		for(int i=0;i<z;i++)
		  	  		{
		  	  			a1=m1-b+1;
		  	  			b1=a;
		  	  			a=a1;
		  	  			b=b1;
		  	  			temp=n1;
		  	  			n1=m1;
		  	  			m1=temp;
		  	  		}
		  	  		out.println(a+" "+b);
		  	  	}
		  	  	out.close();
		  	  }
		    static boolean check(long h)
		    {
		    	long i=0;
		    	for(i=2;i<=Math.sqrt(h);i++)
		    	{
		    		if(h%i==0)
		    			break;
		    	}
		    	if(i==Math.sqrt(h)+1)
		    	{
		    		return true;
		    	}
		    	else
		    	{
		    		return false;
		    	}
		    }
		    static void print(int arr5[],char arr[],char arr1[])
		    {
		    	for(int i=0;i<arr5.length;i++)
		    	{
		    		if(i%2==0)
		    		System.out.println(arr[arr5[i]]);
		    		else
		    		System.out.println(arr1[arr5[i]]);
		    	}
		    }
		    static boolean bs(Pair p[],int key)
		    {
		    	int s=p.length;
		    	int l=0;
		    	int h=s-1;
		    	int mid=0;
		    	while(l<=h)
		    	{
		    		mid=(l+h)/2;
		    		if(key>=p[mid].first&&key<=p[mid].index)
		    		{
		    			System.out.println(p[mid].first+"   "+p[mid].index);
		    			return true;
		    		}
		    		else if(key>p[mid].index)
		    		{
		    			l=mid+1;
		    		}
		    		else
		    		{
		    			h=mid-1;
		    		}
		    	}
		    	return false;
		    }
		    static int lis(int arr[],int n)
		    {
		          int lis[] = new int[n];
		          int i,j,max = 0;
		 
		          
		           for ( i = 0; i < n; i++ )
		              lis[i] = 1;
		 
		           
		           for ( i = 1; i < n; i++ )
		              for ( j = 0; j < i; j++ ) 
		                         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
		                    lis[i] = lis[j] + 1;
		 
		           
		           for ( i = 0; i < n; i++ )
		           {
		        	   

		              if ( max < lis[i] )
		                 max = lis[i];
		           }
		 
		            return max;
		    }
		    public static Comparator<String> SalaryComparator = new Comparator<String>() {
		        @Override
		        public int compare(String e1, String e2) {
		            if(e1.length()!=e2.length())
		            	return e1.length()-e2.length();
		            else
		            	return e1.compareTo(e2);
		        }
		    };		 
		    public static int searchMatrix(ArrayList<ArrayList<Integer>> a, int b) {
			    for(int i=0;i<a.size();i++)
			    {
			    	System.out.println("dasdasdasd");
			    }
				return b;
			}
		    static int bsearch(int pre[],int n,int k)
		    {
		    	int l=1;
		    	int h=n;
		    	int mid=(l+h)/2;
		    	int len=-1;
		    	while(l<=h)
		    	{
		    		mid=(l+h)/2;
		    		if(pre[mid]<=k)
		    		{
		    			int l1=mid+1;
		    			while(l1<=n)
		    			{
		    				System.out.println("mid is "+mid);
		    				System.out.println(pre[l1]+"   "+pre[l1-mid]);
		    				if(pre[l1]-pre[l1-mid]>k)
		    					break;
		    				l1++;
		    			}
		    			if(l1==n+1)
		    			{
		    				l=mid+1;
		    				len=mid;
		    			}
		    			else
		    			{
		    				h=mid-1;
		    			}
		    		}
		    		else
		    		{
		    			h=mid-1;
		    		}
		    	}
		    	return len;
		    }
		    static int count(long arr[],long arr1[],HashMap<Long,Integer> h,HashMap<Long,Integer> h1)
		    {
		    	int count=0;
		  	  	for(int i=0;i<arr.length;i++)
		  	  	{
		  	  		

		  	  		int s_i=h.get(arr1[i]);
		  	  		

		  	  		

		  	  		if(arr[i]!=arr1[i])
		  	  		{
		  	  			

		  	  			count++;
		  	  			h.put(arr[i],s_i);
		  	  			long temp=arr[i];
		  	  			arr[i]=arr1[i];
		  	  			arr[s_i]=temp;
		  	  		}
		  	  	}
		  	  	return count;
		    }
		    static int lcs(String s,String s1,int m,int n)
		    {
		    	int arr[][]=new int[m+1][n+1];
		    	for(int i=0;i<=m;i++)
		    	{
		    		for(int j=0;j<=n;j++)
		    		{
		    			if(i==0||j==0)
		    			{
		    				arr[i][j]=0;
		    			}
		    			else
		    			{
		    				if(s.charAt(i-1)==s1.charAt(j-1))
		    				{
		    					arr[i][j]=arr[i-1][j-1]+1;
		    				}
		    				else
		    				{
		    					arr[i][j]=Integer.max(arr[i][j-1],arr[i-1][j]);
		    				}
		    			}
		    		}
		    	}
		    	return arr[m][n];
		    }
		    static int id0(int arr[], int n)
		    {
		      int inv_count = 0;
		      for (int i = 0; i < n - 1; i++)
		        for (int j = i+1; j < n; j++)
		          if (arr[i] > arr[j])
		            inv_count++;
		     
		      return inv_count;
		    }
		    static int dfs(char arr[][],int i,int j,int n,int m,int p,int q)
		    {
		    	
		    	if(i<0||i>=n||j<0||j>=m||arr[i][j]=='X')
		    	{
		    		return 0;
		    	}
		    	if(i==p&&j==q)
		    	{
		    		for(int g=0;g<n;g++)
		    		{
		    			for(int h=0;h<m;h++)
		    			{
		    				arr[g][h]='X';
		    			}
		    		}
		    		return 0;
		    	}
		    	else
		    	{
		    		int count=0;
		    		arr[i][j]='X';
		    		System.out.println("i j"+i+" "+j);
		    		if(arr[i][j-1]=='.'&&i>=0&&i<n&&j-1>=0&&j-1<m)
		    			count++;
		    		if(arr[i][j+1]=='.'&&i>=0&&i<n&&j+1>=0&&j+1<m)
		    			count++;
		    		if(arr[i-1][j]=='.')
		    			count++;
		    		if(arr[i+1][j]=='.')
		    			count++;
		    		if(count>1)
		    		{
		    			System.out.println("AAYAYAYA");
		    			return 1+dfs(arr,i,j-1,n,m,p,q)+dfs(arr,i,j+1,n,m,p,q)+dfs(arr,i-1,j,n,m,p,q)+dfs(arr,i+1,j,n,m,p,q);
		    		}
		    		else
		    			return dfs(arr,i,j-1,n,m,p,q)+dfs(arr,i,j+1,n,m,p,q)+dfs(arr,i-1,j,n,m,p,q)+dfs(arr,i+1,j,n,m,p,q);
		    	}
		    }
		    static int BFS(ArrayList<ArrayList<Integer>> adj, int root)
		    {
		    	    Queue<Integer> q=new LinkedList<Integer>();
		    	    visited[1]=1;
				 	visited[root]=1;
				 	

				    q.add(root);
				    int count=1;
				 	while(!q.isEmpty())
				 	{
				 		int element=q.remove();
				 		System.out.println("element is "+element);
				 		for (int i : adj.get(element)) {
							if (visited[i] == 0) {
				 			{	
					 			System.out.println("i is "+i);
				 				visited[i]=1;
				 				q.add(i);
				 				

				 				count++;
				 			}
				 				
				 			}
				 	    }
				 	}
				 	return count;
		    }
		    public static long power(long base, long exp) {
		        long res=1;
		        while(exp>0) {
		           if(exp%2==1) res=(res*base)%MOD;
		           base=(base*base)%MOD;
		           exp/=2;
		        }
		        return res%MOD;
		    }
	public static long power(long i)
	{
		long c=1;
		while(i>1)
		{
			c=((c%MOD)*(2%MOD))%MOD;
			i--;
		}
		return c;
	}
	public static long gcd(long p, long q) {
        if (q == 0) {
                return p;
        }
        return gcd(q, p % q);
}
	private static int[] id3(InputReader in,int n)	
	{
		int[] a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=in.nextInt();
		return a;
	}
 static class LengthComparator implements Comparator<String> {
	    public int compare(String arg0, String arg1) {
		

		return (arg0+arg1).compareTo(arg1+arg0);
	    }
	}
	static int root(int arr[],int i)
	{
		while(arr[i]!=i)
		{
			i=arr[i];
		}
		return i;
	}
	static boolean find(int arr[],int a,int b)
	{
		if(root(arr,a)==root(arr,b))
		{
			return true;
		}
		else
			return false;
	}
	static void weighted_union(int arr[],int size[],int a,int b)
	{
		int root_a=root(arr,a);
		int root_b=root(arr,b);
		if(root_a!=root_b)
		{
			

			{
				arr[root_a]=arr[root_b];
				size[root_b]+=size[root_a];
			}










		

		}
	}
	static class Pair implements Comparable<Pair>
	{
		private long first;
		private long index;
		private long row;
 
		public Pair(long i, long j) 
		{ 
			this.first = i;
			this.index = j;
		}
		public Pair() {
			

		}
		public long getFirst() { return first; }
		

		public long getIndex() { return index ;}
		public void setFirst(long k) { this.first=k ; }
		public void setIndex(long k) { this.index=k ;}
		

		@Override
		public int compareTo(Pair o) 
		{
			if(this.first!=o.first)
			return Long.compare(this.first, o.first);
			else
			return Long.compare(this.index,o.index);
		}
		
	}
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
 
		public InputReader(InputStream inputstream) {
			reader = new BufferedReader(new InputStreamReader(inputstream));
			tokenizer = null;
		}
 
		public String nextLine(){
			String fullLine=null;
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					fullLine=reader.readLine();
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				return fullLine;
			}
			return fullLine;
		}
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public Double nextDouble()
		{
			return Double.parseDouble(next());
		}
	}
}
 class Node{
  	Node left;
  	Node right;
  	int data;
  	Node(int data)
  	{
  		this.data=data;
  		left=null;
  		right=null;
  	}
  }
  class BST{
  	Node root;
  	BST()
  	{
  		root=null;
  	}
  	void insert(int data,int size)
  	{
  		root=insert(data,root,size);
  	}
  	Node insert(int data,Node root,int size)
  	{
  		if(root==null)
  		{
  			root=new Node(data);
  			return root;
  		}
  		else
  		{
  			if(data<=root.data)
  			{
  				size+=1+size(root.right);
  				System.out.println("size1 is "+size);
  				insert(data,root.left,size);
  			}
  			else
  			{
  				insert(data,root.right,size);
  			}
  		}
  		return root;
  	}
  	int size(Node root)
  	{
  		if(root==null)
  			return 0;
  		int l=size(root.left);
  		int r=size(root.right);
  		return 1+l+r;
  	}
  }
  class id1 {
	  
	    
	    class Node {
	        String key;
	        Node left, right;
	 
	        public Node(String item) {
	            key = item;
	            left = right = null;
	        }
	    }
	 
	    

	    Node root;
	 
	    

	    id1() { 
	        root = null; 
	    }
	 
	    

	    void insert(String key) {
	       root = insertRec(root, key);
	    }
	     
	    
	    Node insertRec(Node root, String key) {
	 
	        
	        if (root == null) {
	        	

	            root = new Node(key);
	            return root;
	        }	 
	        
	        String arr[]=root.key.split(" ");
	        String arr1[]=key.split(" ");
	        if (Integer.parseInt(arr1[0]) <= Integer.parseInt(arr[0]))
	            root.left = insertRec(root.left, key);
	        else
	            root.right = insertRec(root.right, key);
	 
	        
	        return root;
	    }
	    boolean search(int i)
	    {
	    	boolean b=search(root,i);
	    	return b;
	    }
	    boolean search(Node root,int key)
	    {
	    	if(root==null)
	    		return false;
	    	String arr[]=root.key.split(" ");
	    	

	    	

	    	if(key>=Integer.parseInt(arr[0])&&key<=Integer.parseInt(arr[1]))
	    		return true;
	    	else if(key<Integer.parseInt(arr[0]))
	    		return search(root.left,key);
	    	else
	    		return search(root.right,key);
	    }
	    
	    int height()
	    {
	    	return height(root);
	    }
	    int height(Node root)
	    {
	    	if(root==null)
	    		return 0;
	    	else
	    		return 1+Integer.max(height(root.left),height(root.right));
	    }
	    int[] inorder(int arr[])
	    {
	    	int n=arr.length;
	    	int[] temp=new int[n];
	    	inorder(temp,arr,1,1);
	    	return temp;
	    }
	    void inorder(int temp[],int arr[],int index,int k)
	    {
	    	if(2*index<=temp.length-1)
	    		inorder(temp,arr,2*index,k);
	    	temp[k]=arr[index];
	    	k++;
	    	if(2*index+1<=temp.length-1)
	    		inorder(temp,arr,2*index+1,k);
	    }
	    void inorder()
	    {
	    	id4(root);
	    }
	    void id4(Node node)
	    {
	        if (node == null)
	            return;
	 
	        
	        id4(node.left);
	 
	        
	        System.out.print(node.key + " ");
	 
	        
	        id4(node.right);
	    }
	 
  }
class Graph
{
	static int ans=0;
	private int V;
	private static ArrayList<Integer> adj[];
	Graph(int v)
	{
		V=v;
		adj=new ArrayList[V];
		for(int i=0;i<V;i++)
		{
			adj[i]=new ArrayList();
		}
	}
	void addEdge(int v,int w)
	{
		adj[v].add(w);
	}
	static boolean id2(int s,int color[],boolean visited[])
    {
    	Queue<Integer> q=new LinkedList();
    	q.add(s);
    	color[s]=1;
    	int baap=1;
    	while(!q.isEmpty())
    	{
    		int k=q.poll();
    		Iterator<Integer> i=adj[k].listIterator();
    		if(color[k]==1)
    			baap=1;
    		else
    			baap=2;
    		while(i.hasNext())
    		{
    				int j=i.next();
    				if(visited[j]==false)
    				{
    					visited[j]=true;
    					q.add(j);
    				}
    				if(baap==1)
    				{
    					if(color[j]==1)
    						return false;
    					color[j]=2;
    				}
    				else
    				{
    					if(color[j]==2)
    						return false;
    					color[j]=1;
    				}
    				

    		}
    	}
    	return true;
    }
	void id5(int v, boolean visited[],
            Stack s)
		{
		

			visited[v] = true;
			Integer i;





			Iterator<Integer> it = adj[v].iterator();
			while (it.hasNext())
			{
				i = it.next();
				if (!visited[i])
					id5(i, visited, s);
			}

		

			s.push(new Integer(v));
		}
	void BFS(int s)
	{
		Queue<Integer> q=new LinkedList();
		boolean visited[]=new boolean[V];
		q.add(s);
		int r=0;
		while(!q.isEmpty())
		{
				r=q.poll();
				visited[r]=true;
				System.out.println("queue me nikla "+r);
				Iterator<Integer> i=adj[r].listIterator();
				while(i.hasNext())
				{
					int n=i.next();
					if(visited[n]==false)
					{
						q.add(n);
						visited[n]=true;
					}
				}
		}
	}
	static void DFS(int v,boolean visited[],HashMap<String,Integer>h)
	{
		visited[v]=true;
		Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext())
        {
            int n = i.next();
            System.out.println(n);
            if(visited[n]==false)
            {
            	
            	if(n<=v)
            		ans+=h.get(n+" "+v);
            	else
            		ans+=h.get(v+" "+n);
            	

            	visited[n]=true;
                DFS(n,visited,h);
            }
        }
        

	}
}