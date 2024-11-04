
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

	public static boolean printDivisors(int n)
	{
	    

		int x=(int) Math.sqrt(n);
		int p=0;
	    for (int i=1; i<=x; i++)
	    {
	        if (n%i == 0)
	        {
	            

	            if (n/i == i)
	                p++;
	  
	            else 

	                p=p+2;
	        }
	    }
	    if(p>2)return true;
	    else return false;
	}
	public static ArrayList<Long> Factors(long n)
    {
		ArrayList<Long> arr=new ArrayList<Long>();
        int k=0;
        while (n%2==0)
        {
            k++;
            n /=2;
            arr.add((long)2);
        }
	int p=(int) Math.sqrt(n); 
        for (int i = 3; i <=p; i+= 2)
        
        {  if(n==1)break;
            while (n%i == 0)
            {
                k++;
                arr.add((long)i);
                n /= i;
            }
        }
        if (n > 2)
        {
        	arr.add(n);
        }
        
   return arr;
    } 
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
	 public static long gcd(long x, long p)
	    {
	        if (x == 0)
	            return p;
	         
	        return gcd(p%x, x);
	    }
	    

	    static long lcm(long a, long b)
	    {
	        return (a / gcd(a, b)) * b;
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
	 static int sieve =  1000000 ;


	 static boolean[] prime =  new boolean[sieve + 1] ;

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
	                     for(int i = p*p; i <= sieve; i += p) 
	                     prime[i] = true; 
	             } 
	             
	             p++ ;
	         } 
	           
	     } 
	 public static void arrInpInt(int [] arr, int n) throws IOException
	 {
		 Reader reader = new Reader();
		 for(int i=0;i<n;i++)
	   		{
	   			arr[i]=reader.nextInt();	
	   		}
	 }
	 public static void arrInpLong(long [] arr, int n) throws IOException
	 {
		 Reader reader = new Reader();
		 for(int i=0;i<n;i++)
	   		{
	   			arr[i]=reader.nextLong();	
	   		}
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
	 
	
	

	

	

	

	static int lower_bound(int arr[], int low,int high, int X)
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
	

	

	

	

	
	static int upper_bound(int arr[], int low, int high, int X)
{

if (low > high)
    return low;

int mid = low + (high - low) / 2;
if (arr[mid] <= X) {
    return upper_bound(arr, mid + 1,
                       high, X);
}

return upper_bound(arr, low,
                   mid - 1, X);
}
	
	
	 public static class Pair  {

		    int x;
		    int y;
		 public Pair(int x, int y)
		    {
		        this.x = x;
		        this.y = y;
		    }
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
	 public static void sortbyColumn1(int arr[][], int col)  

	    {
	        Arrays.sort(arr, new Comparator<int[]>() {       
	          @Override              
	          public int compare(final int[] entry1, 
	                             final int[] entry2) {
	            if (entry1[col] > entry2[col])
	                return 1;
	            else if (entry1[col] < entry2[col])
	                return -1;
	            else if(entry1[col] == entry2[col])
	            {
	            	if(entry1[col-1]>entry2[col-1])
	            		return -1;
	            	else if(entry1[col-1]<entry2[col-1])
	            		return 1;
	            	else return 0;
	            }
	              else return 0;
	          }
	        });
	    }
	 public static void print2D(int mat[][])
	    {
	        

	        for (int i = 0; i < mat.length; i++)
	 
	        {  

	        {
	            for (int j = 0; j < mat[i].length; j++)
	                System.out.print(mat[i][j] + " ");
	        }
	            System.out.println();
	        }
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
	    public static class  p
	     {
	    	 int no;
	    	 int h;
	    	 public p(int no, long h)
	    	 {
	    		 this.no=no;
	    		 this.h=(int) h;
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
	  
	 static int lower_bound_arr(ArrayList<Integer> arr, int low,
	             int high, int X)
	{

	 if (low > high) {
	     return low;
	 }
	 int mid = low + (high - low) / 2;
	 if (arr.get(mid) >= X) {
	     return lower_bound_arr(arr, low,
	                        mid - 1, X);
	 }

	 return lower_bound_arr(arr, mid + 1,
	                    high, X);
	}
	
	 
	 public static int func2(int m,int[] arr,int k,int[] arr1)
	 {
		 for(int i=0;i<arr.length;i++)
		 {
			 int p=arr[i];
			 int q=arr[i]+m;
			 
			 int in=(q<=arr.length?arr1[q]:arr.length)-arr1[p-1];
					 if((in)-(arr.length-in)>=k)return arr[i];
			 
		 }
		 return 0;
	 } 
	 public static boolean func(int m,int[] arr,int k,int[] arr1)
	 {
		 for(int i=0;i<arr.length;i++)
		 {
			 int p=arr[i];
			 int q=arr[i]+m;
			 
			 int in=(q<=arr.length?arr1[q]:arr.length)-arr1[p-1];
			 if((in)-(arr.length-in)>=k)return true;
			 
		 }
		 return false;
	 }
		public static int binarySearch(int min, int max, int[] arr,int k,int[] arr1)
	    {
	        int l = min, r = max;
	        while (l <= r) {
	            int m = l + (r - l) / 2;
	            boolean x11=func(m,arr,k,arr1);
	            boolean  x1=func(m-1,arr,k,arr1);

	            if(x11 && !x1)return m;







	            

	            if (!x1 && !x11)
	                l = m + 1;

	            

	            else
	                r = m - 1;
	        }
	        return max;
	    }
		






















































































		public static long pow[] =new long[200001];
		  public static long fact[] =new long[200001];
		  public static void power()
		  {
			  fact[0]=1;
			  pow[0]=1;
			  fact[1]=1;
			  pow[1]=2;
			  
			  for(int i=2;i<200001;i++)
			  {
				  fact[i]=(fact[i-1]*(long)(i))%1000000007l;
				  pow[i]=(pow[i-1]*(long)(2))%1000000007l;
			  }
		  }
		  static long nCr(int n, int r)
		  {  
		     long factorial= (long)((long)fact[n] / (long)((fact[r] *(long)fact[n-r])));
		     return factorial%1000000007l ;
		  }
 	public static void main(String args[]) throws NumberFormatException, IOException ,java.lang.Exception
	{
		
		Reader reader = new Reader();


		int[] pow2 =new int[32];
		for(int i=0;i<32;i++)
		{
			pow2[i]=(int) Math.pow(2, i);
		}
			
		

		



		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));






		int cases=reader.nextInt();
		
   	while (cases-->0){
   		long N=reader.nextLong();
   		long M=reader.nextLong();


































   		
    	int max=Integer.MIN_VALUE;


   		int min=Integer.MAX_VALUE;
   		int min1=Integer.MAX_VALUE;


   		long mod=1000000007;
 












   		

   		
   		

  		







   		

   		



   		




   		int[] arr1=new int[32];
   		int[] arr2=new int[32];

   		


















   		







   	


   		
   		for(int i=0;i<32;i++)
   		{
   			arr1[i]=(int) ((N>>i)&1);
   			arr2[i]=(int) ((M>>i)&1);
   		}
   	




   		
   		if((N|M)==M)
   		{
   			System.out.println(1);
   			continue;
   		}
   		
   		long ans1=M-N;
   		int ind=30;
   		while(ind>=0 )
   		{
   			if(arr1[ind]==1 && arr2[ind]==0)break;
   			ind--;
   		}
   		long ppo=0;
   		long ppp=0;


while(arr1[ind]!=0)ind++;
ind--;
   		for(int i=ind;i>=0;i--)
   		{
   			if(arr1[i]==1)ppo=ppo+pow2[i];
   			if(arr2[i]==1)ppp=ppp+pow2[i];
   		}
   		
   		long ans2=0;
   		
   		if(arr2[ind+1]==0)
   		{
   			ans2=pow2[ind+1]-ppo+pow2[ind+1]-ppp+1;
   		}
   		else 
   		{
   			ans2=pow2[ind+1]-ppo+1;
   		}




   		long ans3=0;
   		
   		int ind2=31;
   		while(ind2>=0 )
   		{
   			if(arr1[ind2]==1 && arr2[ind2]==0)break;
   			ind2--;
   		}
   		long p=N;
   		long po=M;
   		
   		for(int i=ind2+1;i<32;i++)
   		{
   			if(arr1[i]==1)p=p-pow2[i];
   			if(arr2[i]==1)po=po-pow2[i];
   		}


   		ans3=p-po+1;
   		


   		
   		System.out.println(Math.min(ans1, Math.min(ans2, ans3)));



   		
   	}



	}
 	
}
 


   	