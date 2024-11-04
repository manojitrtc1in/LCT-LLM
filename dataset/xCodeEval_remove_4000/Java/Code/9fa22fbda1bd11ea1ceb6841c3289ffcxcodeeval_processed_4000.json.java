
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

	public static void id9(int n)
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
	    System.out.println(p);
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
	 public static HashMap<Integer, Integer> id2(HashMap<Integer, Integer> hm)
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

	 public static void id7() 
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
	 public static void id3(int [] arr, int n) throws IOException
	 {
		 Reader reader = new Reader();
		 for(int i=0;i<n;i++)
	   		{
	   			arr[i]=reader.nextInt();	
	   		}
	 }
	 public static void id4(long [] arr, int n) throws IOException
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
	
	 public static void id5(int arr[][], int col)  

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
	 public static void id0(int arr[][], int col)  

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
	 public static void id6(int mat[][])
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
	 public static int id8(int num) {
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
	  
	 static int id1(ArrayList<Integer> arr, int low,
	             int high, int X)
	{

	 if (low > high) {
	     return low;
	 }
	 int mid = low + (high - low) / 2;
	 if (arr.get(mid) >= X) {
	     return id1(arr, low,
	                        mid - 1, X);
	 }

	 return id1(arr, mid + 1,
	                    high, X);
	}
	
	 static HashMap<Integer, Boolean> map12=new HashMap<Integer,Boolean>();
	 static HashMap<Integer, Boolean> map13=new HashMap<Integer,Boolean>();


	 static boolean  func1(String  p, int ind, HashMap<String, String> map1,ArrayList<String> vS)
	 {
	 	











		 if(map12.containsKey(ind))return map12.get(ind);
	 	boolean s1=false;
	 	boolean s2=false;
	 	if(ind>=p.length())return true;
	 	if(ind<p.length()-1)
	 	{
	 		String p1="";
	 		p1=p1+p.charAt(ind)+p.charAt(ind+1);
	 		if(map1.containsKey(p1))s1=func1(p,ind+2,map1,vS);
	 		if(s1)vS.add(map1.get(p1));
	 		


	 	}
	 	if(!s1 && ind<p.length()-2)
	 	{
	 		String p11="";


	 		p11=p11+p.charAt(ind)+p.charAt(ind+1)+p.charAt(ind+2);
	 		if(map1.containsKey(p11))s2=func1(p,ind+3,map1,vS);
	 		if(s2)vS.add(map1.get(p11));
	 		

	 	}	
	 	map12.put(ind,s1||s2);
	 	return s1 || s2;
	 }
 	public static void main(String args[]) throws NumberFormatException, IOException ,java.lang.Exception
	{
		
		Reader reader = new Reader();
		










			
		

		

		PrintWriter out = new PrintWriter(System.out);
		BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int cases=Integer.parseInt(br.readLine());




		
   	while (cases-->0){


   		







   		String p="";
   		while(p.equals(""))p=br.readLine();


   		String[] first=p.split(" ");
   		int N=Integer.parseInt(first[0]);
   		int M=Integer.parseInt(first[1]);












   		
    	



   		

 


   		




   		HashMap<String,String> map1=new HashMap<String,String>();
   		

   		
   		

  		





   		

   		



   		




   		














   		




   	
   	
   		for(int i=0;i<N;i++)
   		{
   			String s3=br.readLine();
   			for(int j=0;j<M-2;j++)
   			{
   				map1.put(""+s3.charAt(j)+s3.charAt(j+1)+s3.charAt(j+2),(j+1)+" "+(j+3)+" "+(i+1));
   				map1.put(""+s3.charAt(j)+s3.charAt(j+1),(j+1)+" "+(j+2)+" "+(i+1));
   				
   			}
   			if(M>=2)
   			{
   				map1.put(""+s3.charAt(M-2)+s3.charAt(M-1),(M-1)+" "+(M)+" "+(i+1));
   			}
   		}
   		
   		String k1=br.readLine();
   		ArrayList<String> arr1=new ArrayList<String>();
   		boolean k=func1(k1,0,map1,arr1);
   		if(!k)output.append(-1+" \n");
   		else
   		{
   			output.append(arr1.size()+"");
   			output.newLine();
   			for(int i=arr1.size()-1;i>=0;i--)
   			{
   				output.append(arr1.get(i));
   				output.newLine();
   			}
   		}
   		map12.clear();
   		map13.clear();


   		output.newLine();
   		
   
   	}



   	output.flush(); 	
   		
   	}


   	
	}
 


   	