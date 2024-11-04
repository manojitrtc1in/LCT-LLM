

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
              
                  
             
             
 
    
      
 
 
 int t = sc.ni();
 while(t-- > 0)
 {
     int nr = sc.ni();
     int ng = sc.ni();
     int nb = sc.ni();
     Integer []r = new Integer[nr];
     for(int i=0;i<nr;i++)
     {
         r[i] = sc.ni();
     }
     Integer []g = new Integer[ng];
     for(int i=0;i<ng;i++)
     {
         g[i] = sc.ni();
     }
     Integer []b = new Integer[nb];
     for(int i=0;i<nb;i++)
     {
         b[i] = sc.ni();
     }
     long min = Long.MAX_VALUE;
     Arrays.sort(r);
     Arrays.sort(g);
     Arrays.sort(b);
     for(int i=0;i<nr;i++)
     {
         int a = 0;
         int b1 = Integer.MAX_VALUE;
         int c = 0;
         int d = Integer.MAX_VALUE;
         int up1 =   upperBound(g,ng,r[i]);
         int down1 = lowerBound(g,ng,r[i]);
         int up2 = upperBound(b,nb,r[i]);
         int down2 = lowerBound(b,nb,r[i]);
         if(up1 == ng)
             up1--;
         if(up2 == nb)
             up2--;
         if(down1 == ng || (g[down1] > r[i] && down1 > 0))
             down1--;
         if(down2 == nb || (b[down2] > r[i] && down2 > 0))
             down2--;
         a = g[up1];
         b1 = g[down1];
         c =  b[up2];
         d = b[down2];
         long temp = calc(a,r[i],c);
         long temp1 = calc(a,r[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         temp = calc(b1,r[i],c);
         temp1 = calc(b1,r[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         
         
     }
     
     
     for(int i=0;i<ng;i++)
     {
         int a = 0;
         int b1 = Integer.MAX_VALUE;
         int c = 0;
         int d = Integer.MAX_VALUE;
         int up1 =   upperBound(r,nr,g[i]);
         int down1 = lowerBound(r,nr,g[i]);
         int up2 = upperBound(b,nb,g[i]);
         int down2 = lowerBound(b,nb,g[i]);
         if(up1 == nr)
             up1--;
         if(up2 == nb)
             up2--;
         
         if(down1 == nr || (r[down1] > g[i] && down1 > 0))
             down1--;
         if(down2 == nb || (b[down2] > g[i] && down2 > 0))
             down2--;
         
         
         a = r[up1];
         b1 = r[down1];
         c =  b[up2];
         d = b[down2];
         long temp = calc(a,g[i],c);
         long temp1 = calc(a,g[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         temp = calc(b1,g[i],c);
         temp1 = calc(b1,g[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         
     }
     
     
     for(int i=0;i<nb;i++)
     {
         int a = 0;
         int b1 = Integer.MAX_VALUE;
         int c = 0;
         int d = Integer.MAX_VALUE;
         int up1 =   upperBound(g,ng,b[i]);
         int down1 = lowerBound(g,ng,b[i]);
         int up2 = upperBound(r,nr,b[i]);
         int down2 = lowerBound(r,nr,b[i]);
         if(up1 == ng)
             up1--;
         if(up2 == nr)
             up2--;
         if(down1 == ng || (g[down1] > b[i] && down1 > 0))
             down1--;
         if(down2 == nr || (r[down2] > b[i] && down2 > 0))
             down2--;
         a = g[up1];
         b1 = g[down1];
         c =  r[up2];
         d = r[down2];
         long temp = calc(a,b[i],c);
         long temp1 = calc(a,b[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         temp = calc(b1,b[i],c);
         temp1 = calc(b1,b[i],d);
         min = Math.min(min,Math.min(temp,temp1));
         
         
     }
     w.println(min);
 }

 
 
 
       w.close();
       
        
    
    
} 
   
    public static long calc(int x,int y,int z)
    {
        long res = ((long) (x-y) * (long) (x-y)) + ((long) (z-y) * (long) (z-y)) + ((long) (x-z) * (long) (x-z));
        return res;
    }
    
    public static int upperBound(Integer []arr, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= arr[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
     public static int lowerBound(Integer []arr, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            

            if (value <= arr[mid]) {
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
   static int id6(int n)  
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
         
      
   
    public static int id3(int number){
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
     
     static class id5 implements Comparator<Coin>{
  
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