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
		  	  	int n=sc.nextInt();
		  	  	double arr[]=new double[n];
		  	  	double arr1[]=new double[n];
		  	  	for(int i=0;i<n;i++)
		  	  	{
		  	  		arr[i]=sc.nextDouble();
		  	  	}
		  	  	for(int i=0;i<n;i++)
		  	  	{
		  	  		arr1[i]=sc.nextDouble();
		  	  	}
		  	  	double min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
		  	  	for(int i=0;i<n;i++)
		  	  	{
		  	  		if(arr[i]<min)
		  	  		{
		  	  			min=arr[i];
		  	  		}
		  	  		if(arr[i]>max)
		  	  		{
		  	  			max=arr[i];
		  	  		}
		  	  	}
		  	  	double min1=Double.MAX_VALUE;
		  	  	double min11=ternarySearch(arr,arr1,min,max,min1);
		  	  	if(min11==Double.MAX_VALUE)
		  	  		System.out.println(0.00);
		  	  	else
		  	  		System.out.println(min11);
		  	  	out.close();
		  	  	
		     }
		    public static double ternarySearch (double[] A,double[] B,double start, double end,double min)
		    {
		    	

		    	if(Math.abs(start-end)<=1e-6)
		    		return min;
		        double s=compute(A,B,start);
		        double e=compute(A,B,start);
		        double mid1 = start + (end-start) / 3;        
		        
		        double mid2 = start + 2*(end-start) / 3;
		        
		        double mid= (start+end)/2;		        
		        if((compute(A,B,mid1)>(compute(A,B,mid2))))
		        {
		        	double w=Double.min(compute(A,B,mid1),compute(A,B,mid2));
		        	if(w<min)
		        		min=w;
		        	return ternarySearch(A,B,mid1,end,min);
		        }
		        else
		        {
		        	double w=Double.min(compute(A,B,mid1),compute(A,B,mid2));
		        	if(w<min)
		        		min=w;
		        	return ternarySearch(A,B,start,mid2,min);
		        }
		    }
		    static double compute(double a[],double b[],double x)
		    {
		    	double max=Double.MIN_VALUE;
		    	for(int i=0;i<a.length;i++)
		    	{
		    		double t=Math.abs(x-a[i])/b[i];
		    		if(t>max)
		    			max=t;
		    	}
		    	return max;
		    }
		    static TreeSet<Integer>[] lis(int arr[],int n,int arr1[],int lis[],TreeSet<Integer> tr[])
		    {		          
		          int i,j,max = 0;
		 
		          
		           for ( i = 0; i < n; i++ )
		              lis[i] = 1;
		           arr1[0]=0;
		           
		           for ( i = 1; i < n; i++ )
		              for ( j = 0; j < i; j++ ) 
		                         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
		                         {
		                        	 	lis[i] = lis[j] + 1;
		                        	 	arr1[i]=j;
		                         }
		           for(i=0;i<n;i++)
		           {
		        	   int j1=i;
		        	   while(arr1[j1]!=j1)
		        	   {
		        		   tr[i].add(arr[j1]);
		        		   j1=arr1[j1];
		        	   }
		        	   tr[i].add(arr[j1]);
		           }		           
		           		           		
		            return tr;
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
		    static int getInvCount(int arr[], int n)
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
	private static int[] nextIntArray(InputReader in,int n)	
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
			return Long.compare(this.row, o.row);
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
  class BinarySearchTree {
	  
	    
	    class Node {
	        int key;
	        Node left, right;
	 
	        public Node(int item) {
	            key = item;
	            left = right = null;
	        }
	    }
	 
	    

	    Node root;
	 
	    

	    BinarySearchTree() { 
	        root = null; 
	    }
	 
	    

	    void insert(int key) {
	       root = insertRec(root, key);
	    }
	     
	    
	    Node insertRec(Node root, int key) {
	 
	        
	        if (root == null) {
	            root = new Node(key);
	            return root;
	        }
	 
	        
	        if (key <= root.key)
	            root.left = insertRec(root.left, key);
	        else if (key > root.key)
	            root.right = insertRec(root.right, key);
	 
	        
	        return root;
	    }
	    int search(int x,int y)
	    {
	    	int max=Integer.MIN_VALUE;
	    	Node root1=find(x,y,root);
	    	int w= search(root1,x,Integer.MIN_VALUE);
	    	int q=search(root1,y,Integer.MIN_VALUE);
	    	return Math.max(w,q);
	    }
	    int search(Node root,int key,int max)
	    {
	    	

	    	if(root.key>max)
	    	{	    		
	    		max=root.key;
	    	}
	    	if(root.key==key)
	    		return max;
	    	else if(root.key<key)
	    		return search(root.right,key,max);
	    	else
	    		return search(root.left,key,max);
	    }
	    Node find(int x,int y,Node root)
	    {
	    	if(root.key==x||root.key==y)
	    	{
	    		return root;
	    	}
	    	else if(x<root.key&&y<root.key)
	    		return find(x,y,root.left);
	    	else if(x>root.key&&y>root.key)
	    		return find(x,y,root.right);
	    	else
	    		return root;
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
	static boolean isbipartite(int s,int color[],boolean visited[])
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
	void topologicalSortUtil(int v, boolean visited[],
            Stack s)
		{
		

			visited[v] = true;
			Integer i;





			Iterator<Integer> it = adj[v].iterator();
			while (it.hasNext())
			{
				i = it.next();
				if (!visited[i])
					topologicalSortUtil(i, visited, s);
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