

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
              
                  
             
             
 
    
      
 
 
 
 int n = sc.ni();
 int k = sc.ni();
 String []s = new String[n];
 char [][]c = new char[n][7];
 int []t = new int[n];
 for(int i=0;i<n;i++)
 {
     s[i] = sc.rs();
     c[i] = s[i].toCharArray();
     t[i] = Integer.parseInt(s[i],2);  
     
 }
 String []snum = new String[10];
 snum[0] = "1110111";
 snum[1] = "0010010";snum[2] = "1011101"; snum[3] = "1011011"; snum[4] = "0111010";
snum[5] =  "1101011"; snum[6] =  "1101111"; snum[7] = "1010010"; snum[8] =  "1111111"; snum[9] =  "1111011";
int []tnum = new int[10];
for(int i=0;i<10;i++)
{
    tnum[i] = Integer.parseInt(snum[i],2);  
}

int [][]req = new int[n][10];
for(int i=0;i<n;i++)
{
    int num = 0;
    int f = 0;
    for(int j=0;j<10;j++)
    {
        num = 0;
        f = 0;
        for(int k1=0;k1<7;k1++)
        {
            if(c[i][k1] != snum[j].charAt(k1))
            {
                if(c[i][k1] == '1' && snum[j].charAt(k1) == '0')
                {
                   f = -1;
                    break;
                }
                else
                    num++;
            }
        }
        if(f==-1)
            req[i][j] = 1 << 29;
        else
        req[i][j] = num;
    }
}
int []tempmin = new int[n];
int flag = 0;
for(int i=0;i<n;i++)
{
    int min = 1000000000;
    for(int j=0;j<10;j++)
    {
        if(req[i][j] != -1)
        {
            min = Math.min(min,req[i][j]);
        }
    }
    tempmin[i] = min;
    if(min == 1000000000)
        flag = -1;
}
long reqd = 0;
if(flag == -1)
    w.println("-1");
else
{
    StringBuilder sb = new StringBuilder("");
    boolean [][]dp = new boolean[n+1][k+1];
    dp[n][0] = true;
    for(int i=n-1;i>=0;i--)
    {
        for(int sum = 0;sum <= k;sum++)
        {
            for(int d=0;d<=9;d++)
            {
                if(sum - req[i][d] >=0)
                {
                    dp[i][sum] |= dp[i+1][sum - req[i][d]];
                }
            }
        }
    }
    if(!dp[0][k])
        w.println("-1");
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=9;j>=0;j--)
            {
                if(k- req[i][j] >= 0 && dp[i+1][k-req[i][j]])
                {
                    k -= req[i][j];
                    w.print(j);
                    break;
                }
            }
        }
        w.println();
    }
    
}
    
               
       
    


 
       w.close();
       
        
    
    
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