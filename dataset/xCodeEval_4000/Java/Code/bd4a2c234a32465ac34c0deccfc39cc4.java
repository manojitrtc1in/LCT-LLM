
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
 
 
 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
 
public class k
{
 
	static class Reader {
		 
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(
	                new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[64]; 

	            int cnt = 0, c;
	            while ((c = read()) != -1) {
	                if (c == '\n') {
	                    if (cnt != 0) {
	                        break;
	                    }
	                    else {
	                        continue;
	                    }
	                }
	                buf[cnt++] = (byte)c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ') {
	                c = read();
	            }
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            } while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            } while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            } while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.') {
	                while ((c = read()) >= '0' && c <= '9') {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0,
	                                 BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	 }
	


 
	
public static ArrayList<Long> divisor(long n)
	{
		ArrayList<Long> arr=new ArrayList<Long>();
		long x=(long) Math.sqrt(n);
	    for (long i=1; i<=x; i++)
	    {
	        if (n%i == 0)
	        {
	            if (n/i == i)
	                arr.add(i);
	  
	            else 
	               arr.add( i);
	            	arr.add( (n/i));
	        }
	      
	    }
	    
	    return arr;
	}
 
public static ArrayList<Long> Factors(long n)
    {
		ArrayList<Long> arr=new ArrayList<Long>();
        while (n%2l==0)
        {   
            n /=2;
            arr.add(2l);
        }
        long p=(long) Math.sqrt(n); 
        for (long i = 3; i <=p; i+= 2)
        {  if(n==1)break;
            while (n%i == 0)
            {
                arr.add(i);
                n /= i;
            }
        }
        if (n > 2)
        {
        	arr.add(n);
        }
        
   return arr;
    } 
static long hcf(long a,long b)
{
  while (b > 0)
  {
      long temp = b;
      b = a % b; 
      a = temp;
  }
  return a;
 }
 
 
public static long gcd(long x, long p)
	    {
	        if (x == 0)
	            return p;
	         
	        return gcd(p%x, x);
	    }
 
public static long lcm(long a, long b)
	    {
	        return (a / gcd(a, b)) * b;
	    }
 
public static int biggestFactor(int num) {
	  int  result = 1;
	  for(int  i=2; i*i <=num; i++){
	      if(num%i==0){
	          result = num/i;
	          break;
	      }
	  }
	  return result;
	}
 
static int sieve =  1000000 ;
static boolean[] prime =  new boolean[sieve + 1] ;
static ArrayList<Integer> pr=new ArrayList<Integer>();
 
public static void sieveOfEratosthenes() 
    { 
        

        
        

        
        

        
        for(int i = 4; i<= sieve ; i++)
        {
            prime[i] = true  ; i++ ;
           
        }
        
        for(int p = 3; p*p <= sieve; p++) 
        { 
           if(prime[p] == false) 
            { 
           	pr.add(p);
                    for(int i = p*p; i <= sieve; i += p) 
                    prime[i] = true; 
            } 
            
            p++ ;
        } 
          
    } 
 
static long isPrime(long x)
{
    if (x >= 0) {
 
        long sr = (long)Math.sqrt(x);
        long k=sr*sr;
         if(k == x)return sr;
    }
    return -1;
}
 
public static long pwmd(long a, long n,long mod) {
    if (n == 0)
        return 1;
    long pt = pwmd(a, n / 2,mod);
    pt *= pt;
    pt %= mod;
    if ((n & 1) > 0) {
        pt *= a;
        pt %= mod;
    }
    return pt;
}
static long nCr(long n, long r)
{
    return (long)fact(n) / (long)(fact(r) *
                  fact(n - r));
}
 


static long fact(long n)
{
    long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * (long)(i);
    return res;
}
 
	
	


	 
	

	

	

	

	static int lower_bound(long arr[], int low,int high, long X)
	{
 
	 if (low > high) {
	     return low;
	 }
	 int mid = low + (high - low) / 2;
	 if (arr[mid] >= X) {
	     return lower_bound(arr, low,
	                        mid - 1, X);
	 }
 
	 return lower_bound(arr, mid + 1,
	                    high, X);
	}
	

	

	

	

	
	static int upper_bound(long arr[], int low, int high, long X)
	{
		if (low > high)
			return low;
 
		int mid = low + (high - low) / 2;
		if (arr[mid] <= X) {
			return upper_bound(arr, mid + 1,high, X);
		}
		return upper_bound(arr, low,mid - 1, X);
	}
	
	
	 public static class Pair  {

		    long x;
		    long y;
		 public Pair(long x, long y)
		    {
		        this.x = x;
		        this.y = y;
		    }
		}
	
	 
	 


	 
	 
	 public static HashMap<Integer, Integer> sortByValue(HashMap<Integer, Integer> hm)
	    {
	        
	        List<Map.Entry<Integer, Integer> > list =
	               new LinkedList<Map.Entry<Integer, Integer> >(hm.entrySet());
	 
	     
	        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
	            public int compare(Map.Entry<Integer, Integer> o1,
	                               Map.Entry<Integer, Integer> o2)
	            {
	                return (o1.getValue()).compareTo(o2.getValue());
	            }
	        });
	        HashMap<Integer, Integer> temp = new LinkedHashMap<Integer, Integer>();
	        for (Map.Entry<Integer, Integer> aa : list) {
	            temp.put(aa.getKey(), aa.getValue());
	        }
	        return temp;
	    }
 
	 public static void printArr(int[] arr)
	 {
		 for(int i=0;i<arr.length;i++)
		 {
			 System.out.print(arr[i]+" ");
		 }
		 System.out.println();
	 }
	 public static int[] decSort(int[] arr)
	 {
		  int[] arr1 = Arrays.stream(arr).boxed().sorted(Collections.reverseOrder()).mapToInt(Integer::intValue).toArray();	
		  return arr1;
	 }
	 public static void sortbyColumn(int arr[][], int col)  

	    {
	        Arrays.sort(arr, new Comparator<int[]>() {       
	          @Override              
	          public int compare(final int[] entry1, 
	                             final int[] entry2) {
	            if (entry1[col] > entry2[col])
	                return 1;
	            else if (entry1[col] < entry2[col])
	                return -1;
	              else return 0;
	          }
	        });
	    }
 
	 public static void print2D(int[][] st_gcd2)
	    {
	        for (int i = 0; i < st_gcd2.length; i++)
	        { 
	        {
	            for (int j = 0; j < st_gcd2[i].length; j++)
	                System.out.print(st_gcd2[i][j] + " ");
	        }
	            System.out.println();
	        }
	    }
 
	 public static int  knapsack(int[] weights,int[] price, int totW)
		{
			int[] dp1=new int[totW+1];
			int[] dp2=new int[totW+1];
			int N=totW;
			int ans=0;
			for(int i=0;i<price.length;i++)
			{
				for(int j=0;j<=N;j++)
				{
					if(weights[i]>j)
					{
						if(i%2==0)
						{
							dp1[j]=dp2[j];
						}
						else
						{
							dp2[j]=dp1[j];
						}
					}
					else
					{
						if(i%2==0)
						{
							dp1[j]=Math.max(dp2[j],dp2[j-weights[i]]+price[i]);
						}
						else
						{
							dp2[j]=Math.max(dp1[j], dp1[j-weights[i]]+price[i]);
						}
					}
				}
				if(i%2==0)ans=dp1[N];
				else ans=dp2[N];
			}
			return ans;
		}
	    public static class  p
	     {
	    	 long no;
	    	 long h;
	    	 public p(long no, long h)
	    	 {
	    		 this.no=no;
	    		 this.h= h;
	    	 }
	     }
	  static    class com implements Comparator<p>{
	            public int compare(p s1, p s2) {
	                if (s1.h > s2.h)
	                    return -1;
	                else if (s1.h < s2.h)
	                    return 1;
	                else if(s1.h==s2.h)
	                {
	                	if(s1.no>s2.no)return -1;
	                	else return 1;
	                }
	                                return 0;
	                }
	        }
 
	 
 
 
 
		static <K,V extends Comparable<? super V>> SortedSet<Map.Entry<K,V>> entriesSortedByValues(Map<K,V> map) {
	        SortedSet<Map.Entry<K,V>> sortedEntries = new TreeSet<Map.Entry<K,V>>(
	            new Comparator<Map.Entry<K,V>>() {
	                @Override public int compare(Map.Entry<K,V> e1, Map.Entry<K,V> e2) {
	                    int res = e1.getValue().compareTo(e2.getValue());
	                    return res != 0 ? res : 1; 

	                }
	            }
	        );
	        sortedEntries.addAll(map.entrySet());
	        return sortedEntries;
	    }
		   public static void floodFill1(int[][] image, int sr, int sc) {
		        image[sr][sc]=2;
		        if((sr-1>=0) && image[sr-1][sc]==1) 
		        {
		            floodFill1(image,sr-1,sc);
		        }
		    
		        if((sr+1<image.length) && image[sr+1][sc]==1)
		        {
		            floodFill1(image,sr+1,sc);
		        }
 
		        if((sc-1>=0) && image[sr][sc-1]==1 )
		        {
		            floodFill1(image,sr,sc-1);
		        }
 
		        if((sc+1<image[0].length) && image[sr][sc+1]==1)
		        {
		            floodFill1(image,sr,sc+1);
		        }
		   
		         
		    }
		   
		   


		   
		 public static void buildTree(long[] arr,long[] tree,int st, int en,int ind)
		 {

		     if(st==en) {tree[ind]=arr[st];return;}
		     
		     int mid=(st+en)/2;
		     buildTree(arr,tree,st,mid,2*ind);
		     buildTree(arr,tree,mid+1,en,(2*ind)+1);
		     tree[ind]=Math.min(tree[2*ind],tree[(2*ind)+1]);
		     return;
		 	}

		 public static long query(long[] tree,int st, int en, int qs, int qe, int ind)
		 {
		 	if(st>=qs && en<=qe)
		 	{
		 		return tree[ind];
		 	}
		 	if(st>qe || en<qs)return 0;
		 	int mid=(st+en)/2;
		 	long l=query(tree,st,mid,qs,qe,2*ind);
		 	long r=query(tree,mid+1,en,qs,qe,2*ind+1);
		 	return Math.min(l, r);
		 }
		 


	
		
 public static void build_table_gcd(int[][] st, int[] arr)
 {
	 for(int i=0;i<arr.length;i++)
	 {
		 st[i][0]=arr[i];
	 }
	 for(int i=1;i<=(int)((Math.log(arr.length)/Math.log(2)));i++)
	 {
		 for(int j=0;j+(1 << i)<=arr.length;j++)
		 {
			 st[j][i]=(int) gcd((st[j][i-1]),(st[j+(1<<(i-1))][i-1]));
		 }
	 }
	 
 }
 public static int query_gcd(int l,int r, int[][] st)
 {
	 int k=r-l+1;
	 
	 int max=0;
	for(int i=0;i<32;i++)
	{
		if(((k>>i)&1)==1)max=Math.max(max, i);
	}
	 return (int) gcd(st[l][max],st[r-(1<<max)+1][max]);
 }
 
 
 public static void build_table_min(int[][] st, int[] arr)
 {
	 for(int i=0;i<arr.length;i++)
	 {
		 st[i][0]=arr[i];
	 }
	 for(int i=1;i<=(int)((Math.log(arr.length)/Math.log(2)));i++)
	 {
		 for(int j=0;j+(1 << i)<=arr.length;j++)
		 {
			 st[j][i]=Math.min((st[j][i-1]),(st[j+(1<<(i-1))][i-1]));
		 }
	 }
	 
 }
 public static int query_min(int l,int r, int[][] st)
 {
	 int k=r-l+1;
	 
	 int max=0;
	for(int i=0;i<32;i++)
	{
		if(((k>>i)&1)==1)max=Math.max(max, i);
	}
	 return Math.min(st[l][max],st[r-(1<<max)+1][max]);
 }



		 
		 
 public static long ans=0;
 public static long mod=1000000007;
public static void rec(int n, int cur, int r0,int r1,boolean odd)
{ans=(ans+1)%mod;
	if(odd)
	{
		if(r0==r1+1) {
		return;}
		int p=r1+1;
		while(p<r0)
		{
			if(cur-p>=1)
			{
				rec(n,cur-p,r1,p,!odd);
			}
			if(cur+p<=n)
			{
				rec(n,cur+p,r1,p,!odd);
			}
			if(!(cur-p>=1) && !(cur+p<=n))
			{
				break;
			}
				
		}
	}
	if(!odd)
	{
		if(r1==r0+1) {
		return;}
		int p=r0+1;
		while(p<r1)
		{
			if(cur-p>=1)
			{
				rec(n,cur-p,r1,p,!odd);
			}
			if(cur+p<=n)
			{
				rec(n,cur+p,r1,p,!odd);
			}
			if(!(cur-p>=1) && !(cur+p<=n))
			{
				break;
			}
				
		}
	}
	}
	public static void main(String args[]) throws NumberFormatException, IOException ,java.lang.Exception
	{
		
		Reader reader = new Reader();
		long mod= 1000000007;


















 

		
		

		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));






		int cases=reader.nextInt();
		
   	while (cases-->0){


   	
   	







   		
   				
   		
   		








   		
   	
 

   		


   		




   		
   		int N=reader.nextInt();






   		






		






   		








   		












   		
 












   		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();


   		


  		








 
   		







   		






   		






   		boolean[] s=new boolean[N];


   		Integer[] arr=new Integer[N];














for(int i=0;i<N;i++) {arr[i]=reader.nextInt();map.put(arr[i], i);}
int c=0;
for(int i=1;i<N;i++)
{
	if(arr[i]<arr[i-1] && !s[i-1])
	{
		c++;
		s[i-1]=true;
		s[i]=true;
				
	}
}
System.out.println(c);

   	
 }
	output.flush();
	}
	
   	
   	}
 
 
 
 
   	


   	
	
 
 
 


	


	
 
 
 
 