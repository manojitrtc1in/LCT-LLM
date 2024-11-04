
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;



import java.math.*;
import java.io.*;
import java.text.*;
import java.math.BigInteger;
public class Main {

	static class pair implements Comparable<pair>{
	long x;
		long y;
		public pair(long x,long y) {
			this.x=x;
			this.y=y;
		}
		
		public int compareTo(pair o) {
			if(this.x<o.x) {
				return -1;
			}else if(this.x>o.x) {
				return 1;
			}else {
				return -1;
			}
			
			
		}
		
	}
	 public static ArrayList<Integer> sieve(long n)
	    {
	        boolean[] prime = new boolean[(int)n+1];
	        Arrays.fill(prime,true);
	        prime[0] = false;
	        prime[1] = false;
	        long m = (long)Math.sqrt(n);
	        for(int i=2;i<=m;i++)
	        {
	            if(prime[i])
	            {
	                for(int k=i*i;k<=n;k+=i)
	                {
	                    prime[k] = false;
	                }
	            }
	        }
	        ArrayList<Integer>l=new ArrayList<>();
	        for(int j=2;j<=n;j++) {
	        	if(prime[j]) {
	        		l.add(j);
	        	}
	        
	        }
	        
	        return l;
	    } 
	public static void sort(long arr[], int l, int r)
	    {
	        if (l < r)
	        {
	            

	            int m = (l+r)/2;
	 
	            

	            sort(arr, l, m);
	            sort(arr , m+1, r);
	 
	            

	            merge(arr, l, m, r);
	        }
	    }
	 
	 
	public static void merge(long arr[], int l, int m, int r)
	    {
	        

	        int n1 = m - l + 1;
	        int n2 = r - m;
	 
	        
	        long L[] = new long[n1];
	        long R[] = new long[n2];
	 
	        

	        for (int i=0; i<n1; ++i)
	            L[i] = arr[l + i];
	        for (int j=0; j<n2; ++j)
	            R[j] = arr[m + 1+ j];
	 
	 
	        
	 
	        

	        int i = 0, j = 0;
	 
	        

	        int k = l;
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
	 
	 
	 public static boolean[] id2(long n) {
		 boolean prime[]=new boolean[(int)n+1];
		 
		 Arrays.fill(prime, true);
		 
		 prime[0]=false;
		 prime[1]=false;
		 
		 int m=(int) Math.sqrt(n);
		 
		 for(int i=2;i<=m;i++) {
			 if(prime[i]) {
				 
				 for(int k=i*i;k<=n;k+=i) {
					 prime[k]=false;
				 }
			 }
		 }
		 
		 return prime;
	 }
	 public static String reverse(String input)
	 {
	   StringBuilder str  = new StringBuilder("") ;
	    
	     for(int i =input.length()-1 ; i >= 0  ; i-- )
	     {
	         str.append(input.charAt(i));
	     }
	     
	 return str.toString() ;
	 }
	 
	 public static ArrayList<Integer> allFactors(int n)
	 {   
	       ArrayList<Integer> list = new ArrayList<>() ;
	       
	     for(int i = 1; i*i <= n ;i++)
	     {
	           if( n % i == 0)
	           {
	               if(i*i == n)list.add(i) ;
	               else{ 
	          list.add(i);
	               list.add(n/i); 
	               }
	           }
	     }
	       
	      return list ; 
	 }
	  
	  
	 public static ArrayList<Long> allFactors(long n)
	 {   
	       ArrayList<Long> list = new ArrayList<>() ;
	       
	     for(long i = 1L; i*i <= n ;i++)
	     {
	           if( n % i == 0)
	           {
	               if(i*i == n) list.add(i) ;
	               else{  list.add(i) ; list.add(n/i) ; }
	              
	           }
	     }
	       
	      return list ; 
	 }
	 
	 
	   





public static long lowerBound(long[] arr,long k)
{
long ans=-1;

int start=0;
int end=arr.length-1;

while(start<=end)
{
  int mid=(start+end)/2;
   if(arr[mid]<=k){
  ans=arr[mid];
  start=mid+1;

  }
else{
       end=mid-1;
  }

}

  return ans;

}

public static int lowerBound(int[] arr,int k)
{
int ans=0;int start=0;int end=arr.length-1;

while(start<=end)
{
int mid=(start+end)/2;

if(arr[mid]<=k)
{
ans=mid;
start=mid+1;
}
else
{
end=mid-1;
}

}

return ans;

}


public static long upperBound(long[] arr,long k)
{
long ans=-1;int start=0;int end=arr.length-1;

while(start<=end)
{
int mid=(start+end)/2;

if(arr[mid]>=k)
{
ans=mid;
end=mid-1;
}
else
{
start=mid+1;
}

}

return ans;
}


public static int upperBound(int[] arr,int k)
{
int ans=arr.length-1; int start=0; 	int end=arr.length-1;

while(start<=end)
{
int mid=(start+end)/2;

if(arr[mid]>=k)
{
ans=mid;
end=mid-1;
}
else
{
start=mid+1;
}

}

return ans;
}






	 
	    
	    static long GCD(long k,long arr)
	    {
	        if(arr==0)
	        {
	            return k;
	        }
	        return GCD(arr,k%arr);
	    }
	 
	    
	    
	    static long id7(long a,long b)
	    {
	        if(b==0)
	        {
	            return a;
	        }
	        return id7(b,a%b);
	    }
	    
	    
	    static long id4(long n)
	    {
	        long res = n;
	        for(int i=2;i*i<=n;i++)
	        {
	            if(n%i==0)
	            {
	                while(n%i==0)
	                {
	                    n/=i;
	                }
	                res-=res/i;
	            }
	        }
	        if(n>1)
	        {
	            res-=res/n;
	        }
	        return res;
	    }
	 
	 
	    
	 
	    
	 
	    static boolean prime(int n)
	    {
	        for(int i=2;i*i<=n;i++)
	        {
	            if(i%2==0 ||i%3==0)
	            {
	                return false;
	            }
	        }
	        return true;
	    }

	static int length(int len) {
		
		if(len==1) {
			return 1;
		}
		else if(len==2) {
			return 3;
		}
		else if(len==3) {
			return 6;
		}
		else if(len==4) {
			return 10;
		}
		return 0;
	}
	
	
public static int LargestFour(int arr[]) {
	Arrays.sort(arr);

	int n=arr.length;
	int count=0;
	int sum=0;
	for(int i=n-1;i>=1;i--) {
		sum+=arr[i];
	
			count++;
			if(count==4) {
				break;
			
		}
		
	}
	
	if(count<4) {
		sum+=arr[0];
	}
	
	return sum;
}


public static void id3(int array[]) {  
    int n = array.length;  
    for (int j = 1; j < n; j++) {  
        int key = array[j];  
        int i = j-1;  
        while ( (i > -1) && ( array [i] > key ) ) {  
            array [i+1] = array [i];  
            i--;  
        }  
        array[i+1] = key;  
    }  
} 



  static String solve23(int n) {
int k=0;
while(true) {
	if(n-2020*k<0) {
		return "NO";
	}
	if((n-2020*k)%2021==0) {
		return "YES";
	}
	k++;
}
	  
	
	}
  public static String swapString(String a, int i, int j) {  
      char[] b =a.toCharArray();  
      char ch;  
      ch = b[i];  
      b[i] = b[j];  
      b[j] = ch;  
      return String.valueOf(b);  
  }  
	public static void permutation(String str,int start,int end,ArrayList<String> l,Set<String>set) {
		
		if(start==end-1) {
			set.add(str);
		}
		
		for(int i=start;i<end;i++) {
			str=swapString(str,start,i);
		
		permutation(str,start+1,end,l,set);
		
		swapString(str,start,i);
		
		}
		
		
		
	}


public static boolean solution(int j) {
	String str=Integer.toString(j);
	int zero=0;
	int one=0;
	for(int i=0;i<str.length();i++) {
		if(str.charAt(i)=='7') {
			one++;
		}else if(str.charAt(i)=='4') {
			zero++;
		}
	}
	
	
	if(one==zero) {
		return true;
	}
	
	
return false;
}
	
	
	

public static int lower_bound(ArrayList<Long> ar,long k)
{
    int s=0;
    int e=ar.size();
    while (s !=e)
    {
        int mid = s+e>>1;
        if (ar.get(mid) <k)
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
    }
    if(s==ar.size())
    {
        return ar.size()-1;
    }
    return s;
} private static void id1(String c, String st) {
	

	
	 
	 if(c.length()==0) {
		 System.out.println(st);
		 return;
	 }
	 
	 
	 id1(c.substring(1),st+c.charAt(0));
	 id1(c.substring(1),st);
	 
	 
}

private static boolean compare(HashMap<Character, Integer> smap, HashMap<Character, Integer> pmap) {
		

	 
	 for(char ch:smap.keySet()) {
		 if(smap.get(ch)!=pmap.get(ch)) {
			 return false;
		 }
	 }
		return true;
	}


private static boolean BinarySearch(int search, int[] val, int n)
 {
		

		
	 int start=0;
	 int end=val.length-1;
	 while(start<=end) {
		 int mid=(start+end)/2;
		 
		 
		 if(val[mid]==search) {
			 return true;
		 }
		 else if(val[mid]<search) {
			 start=mid+1;
		 }
		 else {
			 end=mid-1;
		 }
		 
	 }
	 return false;
	 }


	
 

	   
	 
	   

	    static long re(long n)
	    {
	        n+=1;
	        while(n%10==0)
	        {
	            n/=10;
	        }
	        return n;
	    }
	   static long xor(long n)
	    {
	 
	        if(n%4==0)
	        {
	            return n;
	        }
	        if(n%4==1)
	        {
	            return  1;
	        }
	        if(n%4==2)
	        {
	            return n+1;
	        }
	        return 0;
	    }
	 
	    static long xor(long a,long b)
	    {
	        return xor(b)^xor(a-1);
	    }
	 
	 	    static void swap(char c,char p)
	    {
	        char t = c;
	        c = p;
	        p = t;
	    }
	 
	    static long max(long n,long m)
	    {
	        return Math.max(n,m);
	    }
	    static long min(long n,long m)
	    {
	        return Math.min(n,m);
	    }
	 
 	    static int abs(int n)
	    {
	        return Math.abs(n);
	    }
	 
	    static class Scanner 
	    {
	        StringTokenizer st;
	        BufferedReader br;
	 
	        public Scanner(InputStream s){  br = new BufferedReader(new InputStreamReader(s));}
	 
	        public String next() throws IOException 
	        {
	            while (st == null || !st.hasMoreTokens()) 
	            {
	                st = new StringTokenizer(br.readLine());
	            }
	            return st.nextToken();
	        }
	 
	        public int nextInt() throws IOException {return Integer.parseInt(next());}
	        
	        public long nextLong() throws IOException {return Long.parseLong(next());}
	 
	        public String nextLine() throws IOException {return br.readLine();}
	 
	        public boolean ready() throws IOException {return br.ready();}
	 
	 
	    }
	 

public static void pairsort(ArrayList<pair>l){
	
	l.sort(new Comparator<pair>() {
		public int compare(pair o1,pair o2) {
			if(o1.x>o2.x) {
				return 1;
			}else {
				return -1;
			}
		}
	});

}


static class death implements Comparator<pair>{
	
	public int compare(pair o1,pair o2) {
		if(o1.x<o2.x) {
			return -1;
		}
		
		else if(o1.x>o2.x) {
			return 1;
		}
		else {
			return 1;
		}
		
	}
	
}


public static int[] id6(int[][] edges) {
 
	HashMap<Integer,HashSet<Integer>>hm=new HashMap<>();

for(int i=1;i<=edges.length;i++) {
	hm.put(i, new HashSet<Integer>());
}

for(int i=0;i<edges.length;i++) {
if(dfs(new HashSet<Integer>(),hm,edges[i][0],edges[i][1])) {
	return edges[i];
}
HashSet<Integer>p=hm.get(edges[i][0]);
p.add(edges[i][1]);
hm.put(edges[i][0],p);
HashSet<Integer>p1=hm.get(edges[i][1]);
p1.add(edges[i][0]);
hm.put(edges[i][1],p1);

}
return null;

}

public static boolean dfs(HashSet<Integer>vis,HashMap<Integer,HashSet<Integer>>hm,int src,int tar){
	if(src==tar) {
		return true;
	}

 
vis.add(src);

for(int next:hm.get(src)) {
	if(!vis.contains(next)) { 
		if(dfs(vis,hm,next,tar)) {return true;}
	}
}

return false;

}

public int id0(int[][] matrix, int k) {
    
	boolean visited[][]=new boolean[matrix.length][matrix[0].length];
	
		
return 0;		
	}
	
	
static class triple implements Comparable<triple>{
	int sum;
	int a;
	int b;
	public triple(int sum,int a,int b) {
		this.sum=sum;
		this.b=b;
		this.a=a;
	}
	
	public int compareTo(triple o) {
		
		if(o.sum<this.sum) {
			return -1;
		}else if(o.sum>this.sum) {
			return 1;
		}
		else {
			
			return o.a-this.a;
		}
		
	}
	
}
static 	String min="";

static String max="";

public static void main(String[] args) throws IOException{
Scanner s=new Scanner(System.in);

int op=s.nextInt();
while(op-- >0) {
	int n=s.nextInt();
	int k=s.nextInt();
	
	long arr[]=new long[n+1];
	ArrayList<Integer>l=new ArrayList<>();
	for(int i=0;i<k;i++) {
		int val=s.nextInt();
		l.add(val);
	}
	
	for(int i=0;i<l.size();i++) {
		int val=l.get(i);
		arr[val]=s.nextLong();
	}
	


	long left[]=new long[n+1];
	long right[]=new long[n+1];
	
	for(int j=arr.length-1;j>=1;j--) {
		
		if(j==arr.length-1) {
			
			if(arr[j]==0) {
			left[j]=Integer.MAX_VALUE;	
			}
			else {
		left[j]=arr[j];
				
			}
		
		
		}else {
			
			if(arr[j]==0) {
			int val1=Integer.MAX_VALUE;	
			left[j]=Math.min(val1,left[j+1]+1);	
			
			}
				else {
			long val1=arr[j];
				left[j]=Math.min(val1,left[j+1]+1);	
			}
			
		}
		
	
	}
	
	for(int j=1;j<arr.length;j++) {
		if(j==1) {
			
			if(arr[j]==0) {
				right[j]=Integer.MAX_VALUE;	
				}
				else {
			right[j]=arr[j];
					
				}
	
		
		
		}else {
			if(arr[j]==0) {
				int val1=Integer.MAX_VALUE;	
				right[j]=Math.min(val1,right[j-1]+1);	
				
				}
					else {
				long val1=arr[j];
					right[j]=Math.min(val1,right[j-1]+1);	
				}
				
			}
		
	
	

	}
	
	
	for(int j=1;j<arr.length;j++) {
		
	System.out.print(Math.min(left[j],right[j])+" ");
	}
	
	System.out.println();
   
   }   
   
   







}


public static String toBinary(int x) {
    return String.format("%32s", Integer.toBinaryString(x)).replaceAll(" ", "0");
}

public static int Substr(String s2, String s1){
    int counter = 0; 

    int i = 0;
    for(;i<s1.length();i++){
        if(counter==s2.length())
            break;
        if(s2.charAt(counter)==s1.charAt(i)){
            counter++;
        }else{
            

            if(counter>0){
                i -= counter;
            }
            counter = 0;
        }
    }
    return counter < s2.length()?-1:i-counter;
}

public static void primeFactors(long n,HashMap<Long,Long>hm)
{

    

    while (n%2==0)
    {
      

    
    	
    	n /= 2;

    hm.put(2L,hm.getOrDefault(2L,0L)+1L);
    }

    

    

    for (long i = 3; i <= Math.sqrt(n); i+= 2)
    {
        

        while (n%i == 0)
        {
            

            n /= i;
   

        hm.put(i,hm.getOrDefault(i,0L)+1L);
        
        }
    }

    

    

    if (n > 2)
       

hm.put(n,1L);
}

	
	
 

public static long fact1(long d,long stop) {
	
	long ans=1;
	for(long i=d;i>stop;i--) {
		ans*=i;
		
	}
	return ans;
}
public static long fact(long d) {
	long ans=1;
	for(long i=2;i<=d;i++) {
		ans*=i;
	}
	return ans;
}


public static long mod(long x){
    

    
	long M=998244353;
	return (int)((x%M+M)%M);
}

static long add(long a,long b){
    return mod(mod(a)+mod(b));
}


public static  long mul(long a,long b){
    return mod(mod(a)*mod(b));
}

static void id5(char[] set,
        String prefix,
        int n, int k,ArrayList<String>l)
{





if (k == 0)
{


l.add(prefix);
	return;
}







for (int i = 0; i < n; ++i)
{



String newPrefix = prefix + set[i];





id5(set, newPrefix,
         n, k - 1,l);
}
}




	 
	 
	 


























	
	}

