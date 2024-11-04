import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
  public class Tester {
	

	

	public static final long MOD = (long) (1e9 + 7);
		static long h[];
			

		    public static void main(String args[])
		    {
		    	Scanner sc=new Scanner(System.in);
		    	InputReader in = new InputReader(System.in);
		  	  	OutputStream outputStream = System.out;
		  	  	PrintWriter out = new PrintWriter(outputStream);
		  	  	String s=in.next();
		  	  	String s1=in.next();
		  	  	int arr[]=new int[26];
		  	  	int arr1[]=new int[26];
		  	  	Arrays.fill(arr,-1);
		  	  	Arrays.fill(arr1,-1);
		  	  	int count=0,flag=0;
		  	  	String s2 = new String();
		  	  	HashMap<String,Integer> h=new HashMap(); 
		  	  	for(int i=0;i<s.length();i++)
		  	  	{
		  	  		if(s.charAt(i)!=s1.charAt(i))
		  	  		{
		  	  			if(arr[s1.charAt(i)-'a']==-1&&arr[s.charAt(i)-'a']==-1)
		  	  			{
		  	  				arr[s.charAt(i)-'a']=s1.charAt(i)-'a';
		  	  				arr[s1.charAt(i)-'a']=s.charAt(i)-'a';
		  	  				String s3=s.charAt(i)+" "+s1.charAt(i);
		  	  				if(!h.containsKey(s3))
		  	  				{
		  	  					count++;
		  	  					s2+=(s.charAt(i)+" "+s1.charAt(i)+"\n");
		  	  					h.put(s3,1);
		  	  				}
		  	  			}
		  	  			else if(arr[s1.charAt(i)-'a']==-1)
		  	  			{
		  	  				if(arr[s.charAt(i)-'a']==s1.charAt(i)-'a')
		  	  				{
		  	  					arr[s1.charAt(i)-'a']=s.charAt(i)-'a';
		  	  				}
		  	  				else
		  	  				{
		  	  					flag=1;
		  	  					break;
		  	  				}
		  	  			}
		  	  			else if(arr[s.charAt(i)-'a']==-1)
		  	  			{
		  	  				if(arr[s1.charAt(i)-'a']==s.charAt(i)-'a')
		  	  				{
		  	  					arr[s.charAt(i)-'a']=s1.charAt(i)-'a';
		  	  				}
		  	  				else
		  	  				{
		  	  					flag=1;
		  	  					break;
		  	  				}
		  	  			}
		  	  			else
		  	  			{
		  	  				if((arr[s.charAt(i)-'a']!=s1.charAt(i)-'a')||(arr[s1.charAt(i)-'a']!=s.charAt(i)-'a'))
		  	  				{
		  	  					
		  	  					flag=1;
		  	  					break;
		  	  				}
		  	  			}
		  	  			
		  	  		}
		  	  		else
		  	  		{
		  	  			if(arr[s.charAt(i)-'a']!=-1)
		  	  			{
		  	  				if(arr[s.charAt(i)-'a']!=s.charAt(i)-'a')
		  	  				{
		  	  					flag=1;
		  	  					break;
		  	  				}
		  	  			}
		  	  			else
		  	  			{
		  	  				arr[s.charAt(i)-'a']=s.charAt(i)-'a';
		  	  				arr[s1.charAt(i)-'a']=s.charAt(i)-'a';
		  	  			}
		  	  		}
		  	  	}
		  	  	if(flag==1)
		  	  		out.println(-1);
		  	  	else
		  	  	{
		  	  		out.println(count);
		  	  		out.println(s2);
		  	  	}
		  	  	out.close();	
		  	  }
		    static void dfs(int root,ArrayList arr[],long height)
		    {
		    	Iterator<Integer> iterator = arr[root].iterator();
		    	h[root]=height;
		    	while(iterator.hasNext())
		    	{
		    		dfs(iterator.next(),arr,height+1);
		    	}
		    }
		    static int ceilSearch(long arr[], int low, int high, long x)
		    {
		      int mid;    
		     
		      
		      if(x <= arr[low])
		        return low; 
		     
		      
		      if(x > arr[high])
		        return -1;  
		     
		      
		      mid = (low + high)/2;  
		     
		      
		      if(arr[mid] == x)
		        return mid;
		         
		       
		      else if(arr[mid] < x)
		      {
		        if(mid + 1 <= high && x <= arr[mid+1])
		          return mid + 1;
		        else
		          return ceilSearch(arr, mid+1, high, x);
		      }
		     
		         
		      else
		      {
		        if(mid - 1 >= low && x > arr[mid-1])
		          return mid;
		        else    
		          return ceilSearch(arr, low, mid - 1, x);
		      }
		    }
		    static int floorSearch(long arr[], int low, int high, long x)
		    {
		      int mid;    
		     
		      
		      if(x >= arr[high])
		        return high; 
		     
		      
		      if(x < arr[low])
		        return -1;  
		     
		      
		      mid = (low + high)/2;  
		     
		      
		      if(arr[mid] == x)
		        return mid;
		         
		       
		      else if(arr[mid] < x)
		      {
		        if(mid + 1 <= high && x < arr[mid+1])
		          return mid;
		        else
		          return floorSearch(arr, mid+1, high, x);
		      }
		     
		         
		      else
		      {
		        if(mid - 1 >= low && x >= arr[mid-1])
		          return mid-1;
		        else    
		          return floorSearch(arr, low, mid - 1, x);
		      }
		    }
		    static long id4(long x,long n)
		    {
		        long result=1;
		        while(n>0)
		        {
		            result=(result%MOD*x%MOD)%MOD;
		            n--;
		        }
		        return result;
		    }
		    static long nCr(int n, int r){
				long rfact=1, nfact=1, id5=1,temp1 = n-r ,temp2 = r;
				if(r>n-r)
				{
					temp1 =r;
					temp2 =n-r;
				}
				for(int i=1;i<=n;i++)
				{
					if(i<=temp2)
					{
						rfact = (rfact%MOD* i%MOD)%MOD;
						id5 = (id5%MOD* i%MOD)%MOD;
					}
					else if(i<=temp1)
					{
						id5 = (id5%MOD* i%MOD)%MOD;
					}
					nfact = (nfact%MOD* i%MOD)%MOD;
				}
				return nfact/(rfact*id5);
			}
		    public static long id2(long n, long r) {
		    	long result=1;
		    	 

		    	   result = factorial(n)/(factorial(r)*factorial(n-r));
		    	   return result;
		    	}
		   public static long factorial(long n) {
		    	   long c;
		    	   long result = 1;
		    	 
		    	   for (c = 1; c <= n; c++)
		    	      result = result*c;
		    	 
		    	   return result;
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
	public static void id0(String pat, int M, int lps[])
    {
        

        int len = 0;
        int i = 1;
        lps[0] = 0;  

 
        

        while (i < M)
        {
            if (pat.charAt(i) == pat.charAt(len))
            {
                len++;
                lps[i] = len;
                i++;
            }
            else  

            {
                

                

                

                if (len != 0)
                {
                    len = lps[len-1];
 
                    

                    

                }
                else  

                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
	 	public static void id7(String pat, String txt)
	    {
	 		System.out.println("sdfsdf");
	        int M = pat.length();
	        int N = txt.length();
	 
	        

	        

	        int lps[] = new int[M];
	        int j = 0;  

	 
	        

	        

	        id0(pat,M,lps);
	 
	        int i = 0;  

	        while (i < N)
	        {
	            if (pat.charAt(j) == txt.charAt(i))
	            {
	                j++;
	                i++;
	            }
	            if (j == M)
	            {
	                System.out.println("Found pattern "+
	                              "at index " + (i-j));
	                j = lps[j-1];
	            }
	 
	            

	            else if (i < N && pat.charAt(j) != txt.charAt(i))
	            {
	                

	                

	                if (j != 0)
	                    j = lps[j-1];
	                else
	                    i = i+1;
	            }
	        }
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
	static int mid=-1;
	static int find(int arr[],int k,int f,int l)
	{
		if(f>l)
			return mid;
		mid=(f+l)/2;
		if(arr[mid]==k)
			return mid;
		if(arr[mid]<k)
		{
			f=mid;
			return find(arr,k,f,l);
		}
		else
		{
			l=mid;
			return find(arr,k,f,l);
		}
	}
	static void merge(long arr[], int l, int m, int r)
	{
	    int i, j, k;
	    int n1 = m - l + 1;
	    int n2 =  r - m;
	 
	    
	    long L[]=new long[n1];
	    long R[]=new long[n2];
	 
	    
	    for (i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (j = 0; j < n2; j++)
	        R[j] = arr[m + 1+ j];
	 
	    
	    i = 0; 

	    j = 0; 

	    k = l; 

	    while (i < n1 && j < n2)
	    {
	        if (L[i] <= R[j])
	        {
	            arr[k] = L[i];
	            i++;
	        }
	        else
	        {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	 
	    
	    while (i < n1)
	    {
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	 
	    
	    while (j < n2)
	    {
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	 
	
	static void mergeSort(long arr[], int l, int r)
	{
	    if (l < r)
	    {
	        

	        

	        int m = l+(r-l)/2;
	 
	        

	        mergeSort(arr, l, m);
	        mergeSort(arr, m+1, r);
	 
	        merge(arr, l, m, r);
	    }
	}
	private static int[] id1(InputReader in,int n)	
	{
		int[] a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=in.nextInt();
		return a;
	}
	public static double dis(double x1,double x2,double y1)
	{
		return Math.sqrt(((x1-x2)*(x1-x2))+(y1*y1));
	}
	private static String[] id3(InputReader in,int n)	
	{
		String[] a=new String[n];
		for(int i=0;i<n;i++)
			a[i]=in.next();
		return a;
	}
	private static void show(int[] a)
	{
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}
	private static void id6(char[][] a)
	{
		for(int i=0;i<a.length;i++)
		{
			for(int j=0;j<a[0].length;j++)
				System.out.print(a[i][j]);
			System.out.println();
		}
	}
 static long fact(long x)
 {
	 long i=x,mul=1;
	 while(i>0)
	 {
		 mul=(mul%1000000007)*(i%1000000007)%1000000007;
		 i--;
	 }
	 return mul;
 }
 static class LengthComparator implements Comparator<String> {
	    public int compare(String arg0, String arg1) {
		

		return (arg0+arg1).compareTo(arg1+arg0);
	    }
	}




























 static long func(boolean v[],int j,ArrayList<Integer> h[],long ban[])
 {
	 	v[j]=true;
	 	 int k;
	 	long sum=0;
	    sum=sum+ban[j];
	 	

	 	for(k=0;k<h[j].size();k++)
	 	{
	 		if(v[h[j].get(k)]==false)
	 		{
	 			v[h[j].get(k)]=true;
	 			sum+=func(v,h[j].get(k),h,ban);
	 		}
	 	}
	 	return sum;
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
			if(size[root_a]<size[root_b])
			{
				arr[root_a]=arr[root_b];
				size[root_b]+=size[root_a];
			}
			else
			{
				arr[root_b]=arr[root_a];
				size[root_a]+=size[root_b];
			}
		

		}
	}
	static class Pair implements Comparable<Pair>
	{
		private long first;
		private long index;
		

 
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
			return Long.compare(this.first, o.first);
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