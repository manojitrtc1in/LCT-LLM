

import java.util.*;
import java.io.*;
import java.lang.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Try {
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
              
                  
             
             
 
    
      
 
 

     
   int t = sc.ni();
   while(t-- > 0)
   {
     
         int n = sc.ni();
         if(n == 1)
             w.println("FastestFinger");
         else if(n==2)
             w.println("Ashishgup");
         else if(n%2==1)
             w.println("Ashishgup");
         else
         {
             int f = 0;
             ArrayList<Integer> odd = new ArrayList<>();
           hm = new HashMap<>();
          primeFactors(n);
          int two = 0;
          int count = 0;
          if(hm.containsKey(2))
              two = hm.get(2);
          for(Map.Entry<Integer,Integer> entry : hm.entrySet())
          {
              int key = entry.getKey();
              int val = entry.getValue();
              if(key %2 ==1)
                  count += val;
              
          }
             if(count==0)
             {
                 if(two == 1)
                 {
                     w.println("Ashishgup");
                 }
                 else
                 {
                      w.println("FastestFinger");
                 }
             }
             else
             {
                 if(two == 1)
                 {
                     if(count == 1)
                         w.println("FastestFinger");
                     else
                         w.println("Ashishgup");
                         
                         
                 }
                 else
                 {
                     w.println("Ashishgup");
                     
                 }
             }
         }
   }
   
   
     
       w.close();
       
        
    
    
} 
    static HashMap<Integer,Integer> hm;
    static class Pair{
        int fir;
        int las;
        Pair(int fir, int las)
        {
            this.fir = fir;
            this.las = las;
        }
    }
    static int id0(int a[]) 
    { 
        int size = a.length; 
        int id4 = Integer.MIN_VALUE, id2 = 0; 
  int max = a[0];
  int res = 0;
  TreeSet<Integer> ts = new TreeSet<>();
  
        for (int i = 0; i < size; i++) 
        {
           
            id2 = id2 + a[i]; 
            
             ts.add(a[i]);
             res = Math.max(res,id2 - ts.last());
            if (id4 < id2) 
            {
                id4 = id2; 
               res = Math.max(res,id4 - ts.last());
              
            }
            if (id2 <= 0 || a[i] < 0) 
            {
                
                
                id2 = 0;
               ts = new TreeSet<>();
                
            }
            
        }
        if(!ts.isEmpty())
        res = Math.max(res,id2-ts.last());
        return res; 
    } 
   
 public static final BigInteger MOD = BigInteger.valueOf(998244353L);
    
    static BigInteger fact(int x)
    {
        BigInteger res = BigInteger.ONE;
        for(int i=2;i<=x;i++)
        {
            res = res.multiply(BigInteger.valueOf(i)).mod(MOD);
        }
        return res;
    }
   
    public static long calc(int x,int y,int z)
    {
        long res = ((long) (x-y) * (long) (x-y)) + ((long) (z-y) * (long) (z-y)) + ((long) (x-z) * (long) (x-z));
        return res;
    }
    
    public static int upperBound(ArrayList<Integer>arr, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= arr.get(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
     public static int lowerBound(ArrayList<Integer> arr, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            

            if (value <= arr.get(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    static HashMap<Long,Integer> map;
  
          
    static class Coin{
        long a;
        long b;
        
        Coin(long a, long b)
        {
            this.a = a;
            this.b = b;
           
        }
    }
    static ArrayList<Long> fac;
    static HashSet<Long> hs;
   public static void primeFactors(int n) 
    { 
        

        while (n%2==0) 
        { 
            if(!hm.containsKey(2))
                hm.put(2,1);
            else
                hm.put(2,hm.get(2) + 1);
            n /= 2; 
        } 
  
        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2) 
        { 
            

            while (n%i == 0) 
            { 
                if(!hm.containsKey(i))
                hm.put(i,1);
            else
                hm.put(i,hm.get(i) + 1);
                n /= i; 
            } 
        } 
  
        

        

        if (n > 2) 
        {
             if(!hm.containsKey(n))
                hm.put(n,1);
            else
                hm.put(n,hm.get(n) + 1);
        }
            
    } 
   static int id8(int n)  
{  
    

    if (n % 2 == 0)  
        return 2;  
  
    

    for (int i = 3; i * i <= n; i += 2) {  
        if (n % i == 0)  
            return i;  
    }  
  
    return n;  
}  
 static boolean IsP(String s,int l,int r)
 {
      while(l <= r)
      {
          if(s.charAt(l) != s.charAt(r))
          {
              return false;
          }
         l++;
         r--;
      }
      return true;
 }
  
	

    
    
 static class Student{
    int id;
    int val;
     Student(int id,int val)
     {
      this.id = id;
      this.val = val;
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
         
      
   
    public static int id5(int number){
        int count = 0;
        while(number>0){
            ++count;
            number &= number-1;
        }
        return count;
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
     
     static class id7 implements Comparator<Coin>{
  
  public int compare(Coin a,Coin b) {
   if(a.a < b.a)
       return 1;
   else if(a.a > b.a)
       return -1;
   else{ 
       if(a.b < b.b)
       return 1;
   else if(a.b > b.b)
       return -1;
       else
       return 0;
   }
       
  
 
     }
     }
     




 
    
    
    
      static class InputReader {
 
private final InputStream stream;
private final byte[] buf = new byte[8192];
private int curChar, id3;
 
public InputReader(InputStream st) {
this.stream = st;
}
 
public int read() {
if (id3 == -1)
throw new InputMismatchException();
if (curChar >= id3) {
curChar = 0;
try {
id3 = stream.read(buf);
} catch (IOException e) {
throw new InputMismatchException();
}
if (id3 <= 0)
return -1;
}
return buf[curChar++];
}
 
public int ni() {
int c = read();
while (id1(c)) {
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
} while (!id1(c));
return res * sgn;
}
 
public long nl() {
int c = read();
while (id1(c)) {
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
} while (!id1(c));
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
while (id1(c)) {
c = read();
}
StringBuilder res = new StringBuilder();
do {
res.appendCodePoint(c);
c = read();
} while (!id1(c));
return res.toString();
}
 
public String nextLine() {
int c = read();
while (id1(c))
c = read();
StringBuilder res = new StringBuilder();
do {
res.appendCodePoint(c);
c = read();
} while (!id6(c));
return res.toString();
}
 
public boolean id1(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
private boolean id6(int c) {
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