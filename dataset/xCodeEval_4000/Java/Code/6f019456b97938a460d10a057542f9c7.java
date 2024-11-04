

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


import java.util.*;
import java.util.Map.Entry;

public class Main {
    static long LowerBound(long[] a2, long x) { 

	  int l=-1,r=a2.length;
	  while(l+1<r) {
	    int m=(l+r)>>>1;
	    if(a2[m]>=x) r=m;
	    else l=m;
	  }
	  return r;
	}
    static int UpperBound(int a[], int x) {

	    int l=-1,r=a.length;
	    while(l+1<r) {
	       int m=(l+r)>>>1;
	       if(a[m]<=x) l=m;
	       else r=m;
	    }
	    return l+1;
    }
    public static long getClosest(long val1, long val2,long target)
	{
		if (target - val1 >= val2 - target)
		return val2;       
		else
		return val1;       
	}
    public static long findClosest(long arr[], long target)
    {
        int n = arr.length;
 
        

        if (target <= arr[0])
            return arr[0];
        if (target >= arr[n - 1])
            return arr[n - 1];
 
        

        int i = 0, j = n, mid = 0;
        while (i < j) {
            mid = (i + j) / 2;
 
            if (arr[mid] == target)
                return arr[mid];
 
            
            if (target < arr[mid]) {
        
                

                

                if (mid > 0 && target > arr[mid - 1])
                    return getClosest(arr[mid - 1],
                                  arr[mid], target);
                 
                
                j = mid;             
            }
 
            

            else {
                if (mid < n-1 && target < arr[mid + 1])
                    return getClosest(arr[mid],
                          arr[mid + 1], target);               
                i = mid + 1; 

            }
        }
 
        

        return arr[mid];
    }
    static void ruffleSort(long[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			long oi=r.nextInt(n), temp=a[i];
			a[i]=a[(int)oi];
			a[(int)oi]=temp;
		}
		Arrays.sort(a);
	}
    static void ruffleSort(int[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		Arrays.sort(a);
	}
    private int ceilIndex(int input[], int T[], int end, int s){
        int start = 0;
        int middle;
        int len = end;
        while(start <= end){
            middle = (start + end)/2;
            if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
                return middle+1;
            }else if(input[T[middle]] < s){
                start = middle+1;
            }else{
                end = middle-1;
            }
        }
        return -1;
    }
    public static int findIndex(long arr[], long t) 
    { 
 
        

        if (arr == null) { 
            return -1; 
        } 
 
        

        int len = arr.length; 
        int i = 0; 
 
        

        while (i < len) {
            if (arr[i] == t) { 
                return i; 
            } 
            else { 
                i = i + 1; 
            } 
        } 
        return -1; 
    }
 
    static long gcd(long a, long b)
    {
        if (a == 0)
            return b; 
        return gcd(b % a, a); 
    }
    static int gcd(int a, int b)
    {
        if (a == 0)
            return b; 
        return gcd(b % a, a); 
    }
    static long lcm(long a, long b)
    {
        return (a / gcd(a, b)) * b;
    }
 
    public static int[] swap(int a[], int left, int right)
    {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        return a;
    }
    public static void swap(int max0,int max1)
    {
    	int temp=max0;
    	max0=max1;
    	max1=temp;
    }
 
    public static int[] reverse(int a[], int left, int right)
    {
 
        

        while (left < right) {
            int temp = a[left];
            a[left++] = a[right];
            a[right--] = temp;
        }
        return a;
    }
 
  
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    


    


    
    void buildTree (int[] arr,int[] tree,int start,int end,int treeNode)
    {
    	if(start==end)
    	{
    		tree[treeNode]=arr[start];
    		return;
    	}
    	buildTree(arr,tree,start,end,2*treeNode);
    	buildTree(arr,tree,start,end,2*treeNode+1);
    	tree[treeNode]=tree[treeNode*2]+tree[2*treeNode+1];
    }
    void updateTree(int[] arr,int[] tree,int start,int end,int treeNode,int idx,int value)
    {
    	if(start==end)
    	{
    		arr[idx]=value;
    		tree[treeNode]=value;
    		return;
    	}
    	int mid=(start+end)/2;
    	if(idx>mid)
    	{
    		updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    	}
    	else
    	{
    		updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    	}
    	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    }
    	static int[][] dp;
    	private static long getClosetNumberOfTarget(long[] dataArray, long target) {
    		 
    		

    		if (dataArray.length == 0)
    			System.exit(1);
    		

    		if (target <= dataArray[0])
    			return dataArray[0];
    		

    		if (target >= dataArray[dataArray.length - 1])
    			return dataArray[dataArray.length - 1];
     
    		

    		int start = 0;
    		int end = dataArray.length-1;
    		int mid = 0;
     
    		

    		while (end - start != 1) {
    			

    			mid = (start + end) / 2;
    			

    			if (target == dataArray[mid])
    				

    				return dataArray[mid];
    			

    			if (target < dataArray[mid]) 
    				end = mid;
    			

    			if (target > dataArray[mid])
    				start = mid;	
    		}
    		

    		return Math.abs(target - dataArray[start]) <= Math.abs(target - dataArray[end]) ? dataArray[start]
    				: dataArray[end];
    	}
    	private static int getClosetNumberOfTarget(int[] dataArray, int target) {
    		 
    		

    		if (dataArray.length == 0)
    			System.exit(1);
    		

    		if (target <= dataArray[0])
    			return dataArray[0];
    		

    		if (target >= dataArray[dataArray.length - 1])
    			return dataArray[dataArray.length - 1];
     
    		

    		int start = 0;
    		int end = dataArray.length - 1;
    		int mid = 0;
     
    		

    		while (start < end) {
    			

    			mid = (start + end) / 2;
    			

    			if (target == dataArray[mid])
    				

    				return dataArray[mid];
    			

    			

    			if (target < dataArray[mid]) {
    				

    				if (target > dataArray[mid - 1])
    					return Math.abs(target - dataArray[mid]) >= Math.abs(target - dataArray[mid - 1]) ? dataArray[mid-1]
    							: dataArray[mid];
    				end = mid - 1;
    			}
    			

    			

    			if (target > dataArray[mid]) {
    				

    				if (target < dataArray[mid + 1])
    					return Math.abs(target - dataArray[mid]) <= Math.abs(target - dataArray[mid + 1]) ? dataArray[mid]
    							: dataArray[mid + 1];
     
    				start = mid + 1;
    			}
    		}
    		

    		return dataArray[mid];
    	}
    	


        static void makeSet(int n)
        {
        	parent=new int[n];
        	rank=new int[n];
        	for(int i=0;i<n;i++)
        	{
        		parent[i]=i;
        		rank[i]=0;
        	}
        	
        }
        static void union(int u,int v)
        {
        	u=findpar(u);
        	v=findpar(v);
        	if(rank[u]<rank[v])parent[u]=v;
        	else if(rank[v]<rank[u])parent[v]=u;
        	else 
        	{


        		parent[v]=u;


        		rank[u]++;
        	}
        }
        
    	private static int findpar(int node)
    	{	
    		if(node==parent[node])return node;
    		return parent[node]=findpar(parent[node]);
    	}
    	static int parent[];
        static int rank[];
    	


        static Long MOD=(long) (1e9+7);
    	private static int lps(int m ,int n,String s1,String s2,int[][]mat)
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(s1.charAt(i-1)==s2.charAt(j-1))mat[i][j]=1+mat[i-1][j-1];
                    else mat[i][j]=Math.max(mat[i-1][j],mat[i][j-1]);
                }
            }
            return mat[m][n];
        }
        public static void main(String[] args)
        {
        	FastReader s = new FastReader();
	        dp=new int[1001][1001];
	        long tt = s.nextLong();
	        while (tt-->0)
	        {
	        	int n=s.nextInt();
	        	
	        	long[] a=new long[n];
	        	Deque<Long>q=new LinkedList<>();
	        	Deque<Long>ans=new LinkedList<>();
	        	for(int i=0;i<n;i++)
	        	{
	        		a[i]=s.nextLong();
	        		q.add(a[i]);
	        	}
	        	if(n==1)System.out.println(1);
	        	else if(a[0]!=n&&a[n-1]!=n)System.out.println(-1);
	        	else
	        	{
		        	while(q.size()!=1)
		        	{
			        	if(q.peekFirst()>q.peekLast())
			        	{
			        		ans.addLast(q.peekLast());
			        		q.pollLast();
			        	}
			        	else
			        	{
			        		ans.addFirst(q.peekFirst());
			        		q.pollFirst();
			        	}
		        	}
		        	ans.add(q.poll());
		        	for(Long it:ans)System.out.print(it+" ");
		        	System.out.println();
	        	}
	        }
        }
        static String lcs(String X, String Y, int m, int n)
        {
            int[][] L = new int[m+1][n+1];
       
            

            

            for (int i=0; i<=m; i++)
            {
                for (int j=0; j<=n; j++)
                {
                    if (i == 0 || j == 0)
                        L[i][j] = 0;
                    else if (X.charAt(i-1) == Y.charAt(j-1))
                        L[i][j] = L[i-1][j-1] + 1;
                    else
                        L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
                }
            }
       
            

            int index = L[m][n];
            int temp = index;
       
            

            char[] lcs = new char[index+1];
            lcs[index] = '\u0000'; 

       
            

            

            int i = m;
            int j = n;
            while (i > 0 && j > 0)
            {
                

                

                if (X.charAt(i-1) == Y.charAt(j-1))
                {
                    

                    lcs[index-1] = X.charAt(i-1); 
                      
                    

                    i--; 
                    j--; 
                    index--;     
                }
       
                

                

                else if (L[i-1][j] > L[i][j-1])
                    i--;
                else
                    j--;
            }
            return String.valueOf(lcs);
            







        }
        static long lis(long[] aa2, int n)
        {
            long lis[] = new long[n];
            int i, j;
            long max = 0;
            for (i = 0; i < n; i++)
                lis[i] = 1;
            for (i = 1; i < n; i++)
                for (j = 0; j < i; j++)
                    if (aa2[i] >= aa2[j] && lis[i] <= lis[j] + 1)
                        lis[i] = lis[j] + 1;
            for (i = 0; i < n; i++)
                if (max < lis[i])
                    max = lis[i];
     
            return max;
        }
        static boolean isPalindrome(String str)
        {
            int i = 0, j = str.length() - 1;
            while (i < j) {
                if (str.charAt(i) != str.charAt(j))
                    return false;
                i++;
                j--;
            }
            return true;
        }
        static boolean issafe(int i, int j, int r,int c, char ch)
        {
			if (i < 0 || j < 0 || i >= r || j >= c|| ch!= '1')return false;
			else return true;
        }
        static long power(long a, long b)
        {
        	   a %=MOD;
        	    long out = 1;
        	    while (b > 0) {
        	        if((b&1)!=0)out = out * a % MOD;
        	        a = a * a % MOD;
        	        b >>= 1;
        			a*=a;
        	    }
        	    return out;
        }


































}
class pair{
	long x,y;
	public pair(long x,long y)
	{
		this.x=x;
		this.y=y;
	}
}



