

import java.util.*;
import java.io.*;
import java.lang.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class id1 {
    static ArrayList<String> s1;
    static boolean[] prime;
    static int n = (int)1e7;
    
     static void sieve() {
Arrays.fill(prime	, true);
prime[0] = prime[1] = false;
for(int i = 2 ; i * i <= n ; ++i) {
if(prime[i]) {
for(int k = i * i; k<= n ; k+=i) {
prime[k] = false;
}
}
}
 
}
    public static void main(String[] args) {
        InputReader sc = new InputReader(System.in);
        n *= 2;
           prime  = new boolean[n + 1];
           

                prime[1] = false;
              
                  
             
             
      
  int t  = 1;
  while(t-- > 0)
  {
    
      
      
   int n = sc.ni();
   int k = sc.ni();
   int p = n-k;
   int []a = sc.nia(n);
   long res = 1;
   long sum = 0;
   long mod = 998244353;
   int prev = -1;
   for(int i=0;i<n;i++)
   {
       if(a[i] > p)
       {
           sum += (long) a[i];
           if(prev != -1)
           {
               res = (res * (long)(i-prev))%mod;
           }
           prev = i;
       }
   }
             
       w.println(sum + " " + res);     
                     
        
  }
             
       w.close();
       
        
    }
    static String lcs(String a, String b) { 
        int m = a.length(); 
        int n = b.length(); 
        char X[] = a.toCharArray(); 
        char Y[] = b.toCharArray(); 
  
        int L[][] = new int[m + 1][n + 1]; 
  
        
        for (int i = 0; i <= m; i++) { 
            for (int j = 0; j <= n; j++) { 
                if (i == 0 || j == 0) { 
                    L[i][j] = 0; 
                } else if (X[i - 1] == Y[j - 1]) { 
                    L[i][j] = L[i - 1][j - 1] + 1; 
                } else { 
                    L[i][j] = Math.max(L[i - 1][j], L[i][j - 1]); 
                } 
            } 
        } 
  
        

        int index = L[m][n]; 
  
        

        

        char[] lcs = new char[index + 1]; 
  
        

        

        

        int i = m, j = n; 
        while (i > 0 && j > 0) { 
            

            

            

            if (X[i - 1] == Y[j - 1]) { 
                

                lcs[index - 1] = X[i - 1]; 
                i--; 
                j--; 
  
                

                index--; 
            } 

            

            

            else if (L[i - 1][j] > L[i][j - 1]) { 
                i--; 
            } else { 
                j--; 
            } 
        } 
        String ans = ""; 
        for (int x = 0; x < lcs.length; x++) { 
            ans += lcs[x]; 
        } 
        return ans; 
    } 
  
    static String id6(String str) { 
        

        String rev = str; 
        rev = reverse(rev); 
  
        

        return lcs(str, rev); 
    } 
  
    static String reverse(String str) { 
        String ans = ""; 
        

        

        char[] try1 = str.toCharArray(); 
  
        for (int i = try1.length - 1; i >= 0; i--) { 
            ans += try1[i]; 
        } 
        return ans; 
    } 
  
	

    
    
 static class Student{
     int time;
     int l;
     long h;
     Student(int time,int l,long h)
     {
         this.time = time;
         this.l = l;
         this.h = h;
     }
 }
   
   
   
 
     static int upperBound(ArrayList<Integer> a, int low, int high, int element){
    while(low < high){
        int middle = low + (high - low)/2;
        if(a.get(middle) >= element)
            high = middle;
        else 
            low = middle + 1;
    }
    return low;
}
   static long func(long t,long e,long h,long a, long b)
   {
       if(e*a >= t)
           return t/a;
       else
       {
           return e + Math.min(h,(t-e*a)/b);
       }
   }
         
      
    public static int upperBound(int []arr,int n,int num)
    {
        int l = 0;
        int r = n;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(num >= arr[mid])
            {
                l = mid +1;
            }
            else
                r = mid;
        }
        return l;
    }
    public static int id3(int number){
        int count = 0;
        while(number>0){
            ++count;
            number &= number-1;
        }
        return count;
    }
    
     
      
 
    
    static HashSet<Integer> fac;
    public static void primeFactors(int n) 
    { 
        

        int t = 0;
        while (n%2==0) 
        { 
            fac.add(2);
            n /= 2; 
        } 
  
        

        

        for (int i = 3; i*i <= n; i+= 2) 
        { 
            

            while (n%i == 0) 
            { 
                fac.add(i);
                n /= i; 
            } 
        } 
  
        

        

        if (n > 2) 
            fac.add(n);
    } 
     static long modexp(long x,long n,long M)
{
    long power = n;
    long result=1;
    x = x%M;
    while(power>0)
    {
        if(power % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        power = power/2;
    }
    return result;
}
      static long modInverse(long A,long M)
{
    return modexp(A,M-2,M);
}
    static long gcd(long a,long b)
    {
        if(a==0)
            return b;
        else
            return gcd(b%a,a);
    }
    static class Temp{
        int a;
        int b;
        int c;
        int d;
      
        Temp(int a,int b,int c,int d)
        {
            this.a = a;
            this.b = b;
            this.c  =c;
            this.d = d;
            

        }
    }
   
    
    
   static long sum1(int t1,int t2,int x,int []t)
   {
       int mid = (t2-t1+1)/2;
  if(t1==t2)
      return 0;
    
   else
   return sum1(t1,mid-1,x,t) + sum1(mid,t2,x,t);
    
     
   }
  
   
    static String replace(String s,int a,int n)
    {
        char []c = s.toCharArray();
        for(int i=1;i<n;i+=2)
        {
            int num = (int) (c[i] - 48);
            num += a;
            num%=10;
            c[i] = (char) (num+48);
        }
        return new String(c);
    }
    static String move(String s,int h,int n)
    {
        h%=n;
        char []c = s.toCharArray();
        char []temp = new char[n];
        for(int i=0;i<n;i++)
        {
            temp[(i+h)%n] = c[i];
        }
        return new String(temp);
    }
    
     public static int ip(String s){
return Integer.parseInt(s);
}
     static class multipliers implements Comparator<Long>{
  
         
  public int compare(Long a,Long b) {
   if(a<b)
    return 1;
   else if(b<a)
    return -1;
   else
    return 0;
  }
 }
     
     static class id5 implements Comparator<Student>{
  
  public int compare(Student a,Student b) {
   if(a.time<b.time)
    return -1;
   else if(b.time<a.time)
    return 1;
   else
   {
       if(a.h < b.h)
           return 1;
       else if(b.h<a.h)
           return -1;
       else
       {
          
           return 0;
       }
           
    

   }
  }

 }

    



 
    
    
    
      static class InputReader {
 
private final InputStream stream;
private final byte[] buf = new byte[8192];
private int curChar, id2;
 
public InputReader(InputStream st) {
this.stream = st;
}
 
public int read() {
if (id2 == -1)
throw new InputMismatchException();
if (curChar >= id2) {
curChar = 0;
try {
id2 = stream.read(buf);
} catch (IOException e) {
throw new InputMismatchException();
}
if (id2 <= 0)
return -1;
}
return buf[curChar++];
}
 
public int ni() {
int c = read();
while (id0(c)) {
c = read();
}
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
int res = 0;
do {
res *= 10;
res += c - '0';
c = read();
} while (!id0(c));
return res * sgn;
}
 
public long nl() {
int c = read();
while (id0(c)) {
c = read();
}
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
long res = 0;
do {
res *= 10;
res += c - '0';
c = read();
} while (!id0(c));
return res * sgn;
}
 
public int[] nia(int n) {
int a[] = new int[n];
for (int i = 0; i < n; i++) {
a[i] = ni();
}
return a;
}
 
public String rs() {
int c = read();
while (id0(c)) {
c = read();
}
StringBuilder res = new StringBuilder();
do {
res.appendCodePoint(c);
c = read();
} while (!id0(c));
return res.toString();
}
 
public String nextLine() {
int c = read();
while (id0(c))
c = read();
StringBuilder res = new StringBuilder();
do {
res.appendCodePoint(c);
c = read();
} while (!id4(c));
return res.toString();
}
 
public boolean id0(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
private boolean id4(int c) {
return c == '\n' || c == '\r' || c == -1;
}
 
}
 
 
 
 
 
   
static PrintWriter w = new PrintWriter(System.out);
                  static class Student1
    {
        int id;
        

       
       int b;
      
        

        
        Student1(int id,int b)
        {
            this.id = id;
            

            

            this.b = b;
          
           

            
            
            
           
        }
        
    }
}