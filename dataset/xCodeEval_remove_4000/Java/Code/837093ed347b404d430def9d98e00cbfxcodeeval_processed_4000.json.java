
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;



import java.math.*;
import java.io.*;
import java.text.*;
import java.math.BigInteger;
public class Main {

	static class pair{
		long x;
		long y;
		public pair(long x,long y) {
			this.x=x;
			this.y=y;
		}
	}
	 public static boolean[] sieve(long n)
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
	        return prime;
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
	 
	 
	 public static boolean[] id1(long n) {
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
	               else{ list.add(i) ;list.add(n/i) ; }
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

if(arr[mid]<=k)
{
ans=arr[mid];
start=mid+1;
}
else
{
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






	 
	    
	    static int GCD(int a,int b)
	    {
	        if(b==0)
	        {
	            return a;
	        }
	        return GCD(b,a%b);
	    }
	 
	    
	    
	    static long id5(long a,long b)
	    {
	        if(b==0)
	        {
	            return a;
	        }
	        return id5(b,a%b);
	    }
	    
	    
	    static long id3(long n)
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


public static void id2(int array[]) {  
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
} private static void id0(String c, String st) {
	

	
	 
	 if(c.length()==0) {
		 System.out.println(st);
		 return;
	 }
	 
	 
	 id0(c.substring(1),st+c.charAt(0));
	 id0(c.substring(1),st);
	 
	 
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
	 
	    
public static char[] solve(char arr[]) {
	int i=0;
	
	char ans[]=new char[arr.length];
while(i<arr.length-1) {
	
		if(arr[i]=='B'&&arr[i+1]=='G') {
			ans[i]='G';
			ans[i+1]='B';
			i=i+2;
		}else {
			ans[i]=arr[i];
		i++;
		}
		
		
	}

if(i==arr.length-1) {
	ans[i]=arr[i];
}

	
	
	return ans;
	
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

public static void solve(char[][]ch,int row,int col) {

	 

	 if(row !=-1&&col !=-1) {		  
		 int f=0;
	 if(ch[row][col]=='W') {
			  f=1;
		  }
		  boolean flag=false;
		  
		 for(int j=col-1;j>=0;j--) {
			 
	 if(ch[row][j] == '.') {
				 if(f==1) {
					 ch[row][j]='R';
					 f=0;
				 }else {
					 ch[row][j]='W';
					 f=1;
				 }
			 }
			 else if(ch[row][j]=='R') {
				 
				 if(f==0) {
				

					 flag=true;
					 break;
				 }else {
					 f=0;
				 }
				 
			 }
			 else if(ch[row][j]=='W') {
				 if(f==1) {
					

				 flag=true;
					 break;
				 }else {
					 f=1;
				 }
				}if(flag==true) {
				 break;
			 } }
		 if(flag==true) {
			 System.out.println("NO");
			 return;
			
		 }
		 f=0;
		  if(ch[row][col]=='W') {
			  f=1;
		  }
		  
	 for(int j=col+1;j<ch[0].length;j++) {
		 
	 if(ch[row][j] == '.') {
				if(f==1) {
					 ch[row][j]='R';
					 f=0;
				 }else {
					 ch[row][j]='W';
					 f=1; 
				 }
			 }
			 else if(ch[row][j]=='R') {
		if(f==0) {
					 flag=true;
					 break;
				 }else {
					 f=0;
				 }
				 
			 }
			 else if(ch[row][j]=='W') {
				 if(f==1) {
				 flag=true;
					 break;
				 }else {
					 f=1;
				 }
				
			}
			 if(flag==true) {
				 break;
			 } }
	 
	 if(flag==true) {
		 System.out.println("NO");
		 return;
		 
	 }
	 
	 
	 
	 for(int i=row-1;i>=0;i--) {
 
		 
		
 }
	 
	 for(int i=row+1;i<ch.length;i++) {
		 
		  f=0;

		  if(ch[i-1][0]=='W') {
			  f=1;
		  }
		  
		 
		 for(int j=0;j<ch[0].length;j++) {
			  if(ch[i][j] == '.') {
					 if(f==1) {
					 ch[i][j]='R';
					 f=0;
				 }else {
					 ch[i][j]='W';
					 f=1;
				 }
			 }
			 else if(ch[i][j]=='R') {
				 if(f==0){
			 flag=true;
					 break;
				 }else {
					 f=0;
				 }}
			 else if(ch[i][j]=='W') {
				 if(f==1) {
				 flag=true;
					 break;
				 }else {
					 f=1;
				 }}}
		 if(flag==true) {
			 break;
		 }
	}
	  if(flag) {
 System.out.println("NO1");
		return;
	 }
	 
	 
	 System.out.println("YES"); 
	 
	 for(int i=0;i<ch.length;i++) {
		 for(int j=0;j<ch[0].length;j++) {
			 System.out.print(ch[i][j]);
		 }
		 System.out.println();
	 }
	 
		  
		  
	  }else {
		System.out.println("YES");
		   int f=0;
		  for(int i=0;i<ch.length;i++)
		  {
			 
			  if(i>0) {
				  char c=ch[i-1][0];
			  if(c=='W') {
				  f=0;
			  }else {
				  f=1;
			  }
				  
			  }
			 for(int j=0;j<ch[0].length;j++) {
			 if(f==0) {
					 ch[i][j]='R';
					 System.out.print("R");
					 f=1;
				 }else {
					 ch[i][j]='W';
					 System.out.print("W");
					 f=0;
				 }
				}
			 System.out.println();
		  }
		}
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


public static void main(String[] args) throws IOException{
  Scanner s=new Scanner(System.in);

  int op=s.nextInt();
  while(op-- > 0) {
	  int n=s.nextInt();
        int m=s.nextInt();
        int x=s.nextInt();
        int y=s.nextInt();
       
     
        if(x==1&&y==1) {
        	int a1=n;
        	int a2=1;
        	int a3=n;
        	int a4=m;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        else if(x==n/2&&y==m/2) {
        	int a1=1;
        	int a2=m;
        	int a3=n;
        	int a4=1;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        else if(x==n/2&&y<m/2) {
        	int a1=1;
        	int a2=m;
        	int a3=n;
        	int a4=1;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        
        else if(x==n/2&&y>m/2) {
        	int a1=1;
        	int a2=1;
        	int a3=n;
        	int a4=m;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
  
        
        else if(x<n/2&&y<=m/2) {
        	int a1=n;
        	int a2=1;
        	int a3=1;
        	int a4=m;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        
        
     
        else if(x<n/2&&y>m/2) {
        	int a1=1;
        	int a2=m;
        	int a3=n;
        	int a4=1;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        
        else if(x>n/2&&y>m/2) {
        	int a1=1;
        	int a2=1;
        	int a3=n;
        	int a4=m;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        
        else if(x>n/2&&y<=m/2) {
        	int a1=1;
        	int a2=m;
        	int a3=n;
        	int a4=1;
        	System.out.println(a1+" "+a2+" "+a3+" "+a4);
        }
        
  }
}
  
  static double solve(int or,int r,int c,int k,double dp[][]) {
	
	  if(r==1&&c>1) {
		  return 0;
	  }
	  if(r==1&&c==1) {
		  Double ty=new Double(k);
		  ty=ty-1;
		  double div=2;
		  double val=ty/div;
		

		  dp[r][c]=val;
		  return val;
	  }
	  
	  if(c==0) {
		  return 0;
	  }
	  
	  if(dp[r][c]!=-1) {
		  return dp[r][c];
	  }
	  
	  
	  
	  double cal1=solve(or,r-1,c-1,k,dp);
	  double cal2=solve(or,r-1,c,k,dp);
	

	  double div=2;
	  if(r !=or) {
	  dp[r][c]=((cal1+cal2)-1)/div;
	  }else {
		  dp[r][c]=((cal1+cal2));  
	  }
	  
	  return dp[r][c];
  
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

static void id4(char[] set,
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





id4(set, newPrefix,
         n, k - 1,l);
}
}




	 
	 
	 


























	
	}

