
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;
import java.math.*;
import java.io.*;



public class Main {

	static class pair implements Comparable<pair>{
	     int x;
		int y;
		
		public pair(int x,int y) {
			this.x=x;
			this.y=y;
		}
		
		public int compareTo(pair o) {
			if(this.x>o.x) {
				return -1;
			}else if(this.x<o.x) {
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
	 
	 
	 public static boolean[] primeseive(long n) {
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






	 
	    
	    static int GCD(int k,int arr)
	    {
	        if(arr==0)
	        {
	            return k;
	        }
	        return GCD(arr,k%arr);
	    }
	 
	    
	    
	    static int gcdnik(int a,int b)
	    {
	        if(b==0)
	        {
	            return a;
	        }
	        return gcdnik(b,a%b);
	    }
	    
	    
	    static long CountCoPrimes(long n)
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


public static void insertionSort(int array[]) {  
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
} private static void printsubsequences(String c, String st) {
	

	
	 
	 if(c.length()==0) {
		 System.out.println(st);
		 return;
	 }
	 
	 
	 printsubsequences(c.substring(1),st+c.charAt(0));
	 printsubsequences(c.substring(1),st);
	 
	 
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


public static int[] findRedundantConnection(int[][] edges) {
 
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

public int kthSmallest(int[][] matrix, int k) {
    
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
public static String minWindow(String s, String t) {
    s=s.toLowerCase();
    t=t.toLowerCase();
	if(t.length()>s.length()){
        return "";
    }
    
    if(s.equals(t)){
        return t;
    }
    
    if(t.length()==0||s.length()==0){
        return "";
    }
    
    
    int i=0;
    int j=0;
    
    HashMap<Character,Integer>hm=new HashMap<>();
    HashMap<Character,Integer>hm1=new HashMap<>();
    int matchcount=0;
    for(int m=0;m<s.length();m++){
        
        hm.put(s.charAt(m),hm.getOrDefault(s.charAt(m),0)+1);
        hm1.put(s.charAt(m),hm1.getOrDefault(s.charAt(m),0)+1);
    
    }
    
    String ans="";
    int difference=Integer.MAX_VALUE;
    int arr[]=new int[27];
    while(i<s.length()){
      char ch=s.charAt(i);
      int indx=(int)(ch)-96;
        if(hm.containsKey(ch)) {
          int val=hm.get(ch);  
          System.out.println(indx);
        	if(arr[indx]<val) {
        		matchcount++;
        	}
      

        }
        
        
        
        while(matchcount==t.length()&&i>j) {
        
        	char ch1=s.charAt(j);
        	int ind=(int)(ch1)-96;
        	int val=hm.get(ch1);
        	 if(hm.containsKey(ch1)) {
        	 if(arr[ind]<=val) {
        		 matchcount--;
        	 
        	 }
        	int len=(i-j+1);
        	if(len<difference) {
        		ans=s.substring(j,i+1);
        difference=len;
        	}
        	arr[ind]--;
        	 }
        
        j++;
        }
        
     i++;}
    int len=(i-j+1);
	if(len<difference) {
		ans=s.substring(j,i+1);
difference=len;
	}
    System.out.println(ans);
return ans;
}
static class Edge{
	int src;
	int nbr;
	
	public Edge(int src,int nbr) {
		this.src=src;
		this.nbr=nbr;
	}
}
int ty=1;
static int path=0;

public static int lowestindex(int nums[]){
    int arr[]=nums;
int n=nums.length;
int s=0;
    int e=nums.length-1;
    while(s<=e){
        
        int mid=s+(e-s)/2;
        
      int left=(mid-1+n)%n;
        int right=(mid+1)%n;
        if(arr[left]>arr[mid]&&arr[right]>arr[mid]){
            return mid;
        }else if(arr[mid]>arr[0]&&arr[mid]>arr[n-1]){
            s=mid+1;
        }else{
            e=mid-1;
        }
     }
return 0;
}
public static ArrayList<Integer> find(){
	ArrayList<Integer>l=new ArrayList<>();
	int a=1;
	int count=0;
	while(count<1000000) {
		count=count+a;
		l.add(count);
		a++;
	}
	return l;
}
public static boolean checkprime(int x) {
	
	
	for(int j=2;j<=(x/2);j++) {
		if(x%j==0) {
			return false;
		}
	}
	return true;
}

static int CeilIndex(int A[], int l, int r, int key)
{
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (A[m] >= key) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}

static int LowerBound(int a[], int x) { 
	  int l=-1,r=a.length;
	  while(l+1<r) {
	    int m=(l+r)>>>1;
	    if(a[m]>=x) r=m;
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


static class triplet  implements Comparable <triplet>{
	int x;
	int y;
	int z;
	public triplet(int x,int y,int z) {
		this.x=x;
		this.y=y;
		this.z=z;
	}
	
	public int compareTo(triplet o) {
		

	 if(o.z>this.z) {
		 return -1;
	 }else {
		 return 1;
	 }
	 
	}
}
public static String  longestEvenWord(String sentence) {
	String ans="";
	String str=sentence;
	
	int i=0;
	int max=0;
		while(i<sentence.length()) {
		char ch=sentence.charAt(i);
		if(ch==' ') {
			i++;
			continue;
		}
		String tmp="";
		while(i<str.length()&&str.charAt(i)!=' ') {
			tmp+=str.charAt(i);
			i++;
		}
		if(tmp.length()%2==0) {
			
			if(tmp.length()>max){
				max=tmp.length();
				ans=tmp;
			}
		}
	}
	
	return ans;
}

static long dp[][] = new long[1001][1001];
static int MOD = 1000000007;

public static int numOfWays(int[] nums) {
    dp[0][0]=1;
    for(int i = 1; i <= nums.length; i++){
        dp[i][0]=1;
        dp[i][i]=1;
        for(int j = 1; j < i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    List<Integer> list = new ArrayList<>();
    for(int val : nums) 
        list.add(val);
    
    return (int) solve(list)-1;
}

public static long solve(List<Integer> l) {
    int size = l.size();
    if(size <= 1) return 1;
    
    List<Integer> small = new ArrayList<>();
    List<Integer> large = new ArrayList<>();
    
    for(int i = 1 ; i < l.size() ; i++) {
        int val = l.get(i);
        if(val < l.get(0))
            small.add(val);
        else
            large.add(val);
    }
    long ansS = solve(small);
    long ansL = solve(large);
    long ans = (ansS * ansL) % MOD;
    ans = (long) (ans * dp[size-1][small.size()] % MOD);
   
    return ans;
}
static class trip{
	String str;
	int end;
	public trip(String str,int end) {
		this.str=str;
		
		this.end=end;
	}
}
 static int LargestElementsLower(int arr[]) {
	
	 int count=0;
	 int n=arr.length;
	 for(int i=1;i<n-1;i++) {
		 int cnt=0;
		 for(int j=i-1;j>=0;j--) {
			 if(arr[j]>arr[i]) {
				 cnt++;
			 }
		 }
		 int cnt1=0;
		 for(int j=i+1;j<n;j++) {
			 if(arr[j]<arr[i]) {
				 cnt1++;
			 }
		 }
		 
		 
		 count+=Math.max(cnt,cnt1);
	
	 }
	 return count;
 }
 static int minlen=Integer.MIN_VALUE;
 
 




















 
 static int NumberofHouses(int r,int unit,int arr[]) {
	 
	 if(arr.length==0) {
		 return -1;
	 }
	 
	 long area=r*unit;
	 
	 int n=arr.length;
	 long dp[]=new long[n];
	 dp[0]=arr[0];
	 for(int i=1;i<dp.length;i++) {
		 dp[i]=dp[i-1]+arr[i];
	 }
	 int count=0;
	 if(area>dp[0]) {
		 count=1;
	 }
	 for(int i=1;i<dp.length;i++) {
	System.out.println(dp[i]);
	count++;
		 if(dp[i]>area) {
			 return count;
		 }
	 }
	 
	 return 0;
 }
 static String VowelConsonantSequence(String str) {
	 
	 char ch[]=new char[str.length()];
	 
	 for(int i=0;i<str.length();i++) {
	
		 char ch1=str.charAt(i);
		 
		 if(ch1=='a'||ch1=='e'||ch1=='i'||ch1=='o'||ch1=='u') {
			 ch[i]='V';
		 }else {
			 ch[i]='C';
		 }
	 }
	 
	 String ans="";
	 
	 for(int i=0;i<ch.length-1;i++) {
		 if(ch[i]==ch[i+1]) {
			 ans+=ch[i];
			 i++;
		 }else {
			 ans+=ch[i];
		 }
		 
	 }
	 
	 if(ch[str.length()-1]!=ch[str.length()-2]) {
		 ans+=ch[str.length()-1];
	 }
	 
	 return ans;
 }

 
 
 
 public static void solution(int N,int arr[]) {
	 long ans=0;
	 
	 for(int i=0;i<arr.length;i++) {
		 int num=arr[i];
		 
		 int pow=num%10;
		 num=arr[i]/10;
		 int mul=1;
		 for(int j=1;j<=pow;j++) {
			 mul*=10;
		 }
		 
		int val=num%mul;
		 num=num/mul;
		 ans+=Math.pow(num,val);
		 
		 
	 }
	 System.out.println(ans);
 }
 static char[] SumofPro(char str1[],char str2[]) {
	 
	if(str1.length==0) {
		return str2; 
	}
	
	if(str2.length==0)return str1;
	
	
	ArrayList<Character>l=new ArrayList<>();
	HashMap<Character,Integer>hm1=new HashMap<>();
	HashMap<Character,Integer>hm2=new HashMap<>();
	
	for(char ch:str1) {
		
		hm1.put(ch,hm1.getOrDefault(ch,0)+1);
	}
	for(char ch:str2) {
		
		hm2.put(ch,hm1.getOrDefault(ch,0)+1);
	}
	
	for(char ch:str1) {
		if(!hm2.containsKey(ch)) {
			l.add(ch);
		}
	}
	
	for(char ch:str2) {
		if(!hm1.containsKey(ch)) {
			l.add(ch);
		}
	}
	 
	char ans[]=new char[l.size()];
	int p=0;
	for(char ch:l) {
		ans[p++]=ch;
	}
	return ans;
 }
public static void main(String[] args) throws IOException
{ 
	Scanner s=new Scanner(System.in);
    
	int op=s.nextInt();
	
	while(op-- >0) {
		
		int n=s.nextInt();
		int arr[]=new int[n];
		HashMap<Integer,Integer>hm=new HashMap<>();
		HashMap<Integer,Integer>hm1=new HashMap<>();
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		   hm.put(arr[i],hm.getOrDefault(arr[i],0)+1);
		}
		 int count=0;
		
		for(Map.Entry<Integer,Integer>e:hm.entrySet()) {
			int key=e.getKey();
			int val=e.getValue();
			if(key==0) {
				count+=1;
			}else {
				if(val>=2) {
					
						int yu=-1*key;
						if(hm.containsKey(yu)) {
							count+=1;
						}else {
							count+=2;
						}
					


				}else {
					count+=1;
				}
			}
			
			
		}
		
		
		 System.out.println(count);
	}

}



		
	






public static long solve1(long k,long x) {
	
	long st=1;
	long e=k;
	long val=-1;
	long min=Long.MAX_VALUE;
	while(st<=e) {
		
		long mid=st+(e-st)/2;
		
		long sum=(mid*(mid+1))/2;
	
		if(sum==x) {
			return mid;
		}
		else if(sum>x) {
			long diff= sum-x;
			if(diff<min) {
				min=diff;
				val=mid;
			}
			e=mid-1;
			
		}else {
			st=mid+1;
		}
		
		
	}
	
	

	
	
	return val;
}


public static long solve2(long k,long x) {
	long total=(k*(k+1))/2;
	 long st=1;
	 long et=k-1;
	long min=Long.MIN_VALUE;
	long val=-1;
	  
	 while(st<=et) {
		 
		 long mid=et+(st-et)/2;
		 long sum=((mid-1)*mid)/2;
		
		 long fin=total-sum;
		 if(fin==x) {
			 return mid;
		 }else if(fin>x) {
			 if(min>fin) {
				 min=fin;
				 val=mid;
			 }
			 et=mid-1;
		 }else {
			st=mid+1;
			 
		 }
	
	}
	
	return val;
	
}
public static int[] ngr(int right[],List<Integer> arr){
    
    Stack<Integer>st=new Stack<>();
    for(int i=arr.size()-1;i>=0;i--){
        
        if(i==arr.size()-1){
            st.push(i);
            right[i]=-1;
            continue;
        }
        int k=arr.get(i);
        
        while(st.size()>0&&k>=arr.get(st.peek())){
         st.pop();   
        }
        if(st.size()>0){
            
            right[i]=st.peek();
           
            st.push(i);
        
        }else {
        	st.push(i);
        	right[i]=-1;
        }
            
            
        
        
        }
        
 
    return right;
}
    

public static int[] ngl(int left[],List<Integer> arr){
    
    Stack<Integer>st=new Stack<>();
    for(int i=0;i<arr.size();i++){
        
        if(i==0){
            st.push(i);
            left[i]=-1;
            continue;
        }
        int k=arr.get(i);
        
        while(st.size()>0&&k>=arr.get(st.peek())){
         st.pop();   
        }
        if(st.size()>0){
            
            left[i]=st.peek();
           
            st.push(i);
        
        }else {
        	st.push(i);
        	left[i]=-1;
        }
            
            
        
        
        }
        
 
    return left;
}
    
    






public static boolean left(String str,String t,int len,int x,int indx) {
	
	while(x<t.length()&&indx>=0) {
	
		if(str.charAt(indx)==t.charAt(x)) {
			x++;
			indx--;
			
		}else {
			break;
		}
		
		if(x==t.length()) {
			return true;
		}
	}
	return false;
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


public static int mod(long x){
   long M=1000000007;
    
	
	return (int)((x%M+M)%M);
}

static int add(long a,long b){
    return mod(mod(a)+mod(b));
}


public static  int mul(int a,int b){
    return mod(mod(a)*mod(b));
}

	 

	}

