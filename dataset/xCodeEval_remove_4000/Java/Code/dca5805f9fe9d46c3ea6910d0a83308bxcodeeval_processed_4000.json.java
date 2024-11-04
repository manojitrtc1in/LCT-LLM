

import java.util.*;
import java.io.*;
import java.lang.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class id2 {
    static ArrayList<String> s1;
    static boolean[] prime;
    static int n = 200001;
    
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
        
           

          

                

              
                  
             
             
 
    
      
 
 

     
   
      
        
         
         int t = sc.ni();
         while(t-- > 0)
         {
             long h = sc.nl();
             long c = sc.nl();
             long temp = sc.nl();
             
             BigDecimal tempt = new BigDecimal(temp);
             BigDecimal  first = new BigDecimal(((double)h+(double)c)/(double)2);
             BigDecimal diff1 = first.subtract(tempt);
             if(diff1.compareTo(BigDecimal.ZERO) < 0)
                diff1 = diff1.multiply(new BigDecimal("-1.0"));
             double coeff = (double) 2*temp - ((double)h + (double)c);
             long cons = h - temp;
             if(temp == h)
             {
                 w.println("1");
             }
             else if(coeff <= 0)
             {
                 w.println("2");
             }
             else
             {
             long x1 = (long) Math.floor((double) cons / coeff);
             
             long x2 = (long) Math.ceil((double) cons / coeff);
             
                 
            BigDecimal x11 = new BigDecimal(x1);
            BigDecimal x22 = new BigDecimal(x2);
            BigDecimal id7 = new BigDecimal(h+c);
            x11 = x11.multiply(id7);
            x22 = x22.multiply(id7);
            BigDecimal hh = new BigDecimal(h);
            BigDecimal denm = new BigDecimal(x1);
            BigDecimal two = new BigDecimal("2");
            denm = denm.multiply(two).add(BigDecimal.ONE);
            BigDecimal id0 = new BigDecimal(x2);
            id0 = id0.multiply(two).add(BigDecimal.ONE);
            BigDecimal t1 = (x11.add(hh)).divide(denm,MathContext.DECIMAL128);
            BigDecimal diff2 = t1.subtract(tempt);
            if(diff2.compareTo(BigDecimal.ZERO) < 0)
                diff2 = diff2.multiply(new BigDecimal("-1.0"));
                

                

            long ans = 0;
            BigDecimal abd = new BigDecimal("-1.0");
            if(diff1.compareTo(diff2) <= 0)
            {
                ans = 2;
                if(diff1.compareTo(diff2) == 0  && x1 == 0)
                {
                    ans = 1;
                    abd = diff2;
                }
                else
                abd = diff1;
            }
            else
            {
                ans = (2*x1)+1;
                abd = diff2;
            }
            
               BigDecimal t2 = x22.add(hh).divide(id0,MathContext.DECIMAL128);
               BigDecimal diff3 = t2.subtract(tempt);
               if(diff3.compareTo(BigDecimal.ZERO) < 0)
                diff3 = diff3.multiply(new BigDecimal("-1.0"));
               
               if(diff3.compareTo(abd) < 0)
               {
                   ans = (2*x2) + 1;
               }
            
             w.println(ans);
             
         }
         }
           
    
     
 
       w.close();
       
        
    
    
} 
   
    static int []res;
    static int c = 0;
    static class Pair{
        int fir;
        int last;
        Pair(int fir,int last)
        {
            this.fir = fir;
            this.last = last;
        }
    }
    static class m1 implements Comparator<Pair>{
        public int compare(Pair a, Pair b)
        {
            int t1 = a.last - a.fir;
            int t2 = b.last - b.fir;
            if(t1 < t2)
                return 1;
            else if(t1 > t2)
                return -1;
            else
            {
                if(a.fir < b.fir)
                    return -1;
                else
                    return 1;
            }
        }
    }
   
    static long calc(long x)
    {
        double res = Math.sqrt(1 + 24*(double)x);
        res -= 1.0;
        res = res / (double) 6;
        return (long) res;
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
    public static void primeFactors(long n) 
    { 
        

        while (n % 2 == 0) { 
            fac.add(2l);
            hs.add(2l);
            n /= 2; 
        } 
  
        

        

        for (long i = 3; i*i <= n; i += 2) { 
            

            while (n % i == 0) { 
                fac.add(i);
                hs.add(i);
                n /= i; 
            } 
        } 
  
        

        

        if (n > 2) 
            fac.add(n);
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
         
      
   
    public static int id4(int number){
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
     
     static class id6 implements Comparator<Coin>{
  
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
} while (!id5(c));
return res.toString();
}
 
public boolean id1(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
private boolean id5(int c) {
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