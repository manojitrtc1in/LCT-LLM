

import java.util.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
 
import javax.print.DocFlavor.STRING;
import javax.swing.Popup;
import javax.swing.plaf.synth.SynthStyleFactory;
 
public class Simple{  
 
    public static Deque<Integer> possible(int a[],int n){
        boolean bool = true;
        Deque<Integer> deq = new LinkedList<>();
        int i=0;
        int j=n-1;
        int max = n;
        int min = 1;
        while(i<=j){
            
            
            if(a[i]== min){
                deq.addFirst(a[i]);
                i++;min++;
                continue;
            }
            if(a[j]== min){
                deq.addLast(a[j]);
                j--;
                min++;
                continue;
            }
            if(a[i]==max){
                deq.addFirst(a[i]);
                i++;
                max--;
                continue;
            }
            if(a[j]==max){
                deq.addLast(a[j]);
                j--;
                max--;
                continue;
            }
            Deque<Integer> d = new LinkedList<>();
            d.add(-1);
            return d;
 
        }
 
        
        return deq;
 
    }
 
    public static class Pair implements Comparable<Pair>{
        int val;
        int freq = 0;
        Pair prev ;
        Pair next;
        boolean bool = false;
 
        public Pair(int val,int freq){
            this.val = val;
            this.freq= freq;
        }
 
        public int compareTo(Pair p){
            

            

            

            

            

            return (p.freq-p.val) - (this.freq - this.val);
        }
 
 
    }
    public static long factorial(long n)
    {
    
      

      return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    
    }
 
 
    static long m  = 998244353;
 


 static long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 


static long modexp(long x, long n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % m, n / 2);
    }
    else {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}
 


 static long getFractionModulo(long a, long b)
{
    long c = gcd(a, b);
 
    a = a / c;
    b = b / c;
 
    

    long  d = modexp(b, m - 2);
 
    

    long ans = ((a % m) * (d % m)) % m;
 
    return ans;
}
    

    

    

    

    

 
    

    

    

    public static boolean isPrime(int n)
    {
 
        

        

        if (n <= 1)
            return false;
 
        

        else if (n == 2)
            return true;
 
        

        else if (n % 2 == 0)
            return false;
 
        

        for (int i = 3; i <= Math.sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    public static int countDigit(long n)
    {
        int count = 0;
        while (n != 0) {
            n = n / 10;
            ++count;
        }
        return count;
    }
    static ArrayList<Long> al ;
    static boolean checkperfectsquare(long n)
    {
        
        

        

        

        if (Math.ceil((double)Math.sqrt(n)) ==
            Math.floor((double)Math.sqrt(n)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public static void decToBinary(int n,int arr[],int j)
    {
        

        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if ((k & 1) > 0){
                arr[j]++;
            }     
            
            j++;
        }
    }
    public static long[] helper(long n){
        long arr[] = new long[33];  
        

        for (long i = 1; i <= 32; i++) {
            long k = (long)Math.pow(2,i);
            if (k<=n){
                arr[(int)i-1]+= n/k ;
                arr[(int)i-1]+=  (n) % k;
            }     
            
            
        }
 
        return arr;
    }
    public static int countAp(int i,int j,int arr[],int n,int k){
        if(k==n)return 0;
 
        if(arr[k]-arr[j]==arr[j]-arr[i]){
            return countAp(i,j,arr,n,k+1)+1;
        }
        return countAp(i,j,arr,n,k+1);
 
 
    }
    

    

    

    

    

    

    

    

    

    

    

    static int MAX = 100000;
    static int factor[];
 
    

    

    static void generatePrimeFactors()
    {
        factor = new int[MAX+1];
        factor[1] = 1;
 
        

        

        for (int i = 2; i < MAX; i++)
            factor[i] = i;
 
        

        for (int i = 4; i < MAX; i += 2)
            factor[i] = 2;
 
        

        

        

        

        for (int i = 3; i * i < MAX; i++) {
            

            if (factor[i] == i) {
                

                for (int j = i * i; j < MAX; j += i) {
                    

                    

                    

                    if (factor[j] == j)
                        factor[j] = i;
                }
            }
        }
    }
 
    

    static int calculateNoOFactors(int n)
    {
        if (n == 1)
            return 1;
 
        int ans = 1;
 
        

        

        int dup = factor[n];
 
        

        

        int c = 1;
 
        

        

        int j = n / factor[n];
 
        

        while (j != 1) {
            

            

            if (factor[j] == dup)
                c += 1;
 
            
            else {
                dup = factor[j];
                ans = ans * (c + 1);
                c = 1;
            }
 
            

            j = j / factor[j];
        }
 
        

        ans = ans * (c + 1);
 
        return ans;
    }
    
    
    public static int maxPrimefactorNum(int N)
    {
        if (N < 2)
            return 0;
    
        

        

        boolean[] arr = new boolean[N + 1];
        int prod = 1, res = 0;
        for (int p = 2; p * p <= N; p++)
        {
            

            if (arr[p] == false)
            {
                for (int i = p * 2; 
                         i <= N; i += p)
                    arr[i] = true;
    
                

                

                

                prod *= p;
                if (prod > N)
                    return res;
                res++;
            }
        }
    
        return res;
    }
    public static class Tuple{
        int l,r,u,d;
        public Tuple(int l,int r,int u,int d){
            this.l=l;
            this.r=r;
            this.u=u;
            this.d=d;
        }
    }
    

        
    

    

    

    

    

    

    

    

    

 
    

 
    public static class Node{
        

        long v;
        long w;
        public Node(long v,long w){
            

            this.v=v;
            this.w=w;
        }
    }
    public static boolean isKthBitSet(int n,int k){
        if ((n & (1 << (k - 1))) > 0)
            return true;
        return false;
    }
    
    public static class Edge{
        int v1 =-1;
        int v2 = -1;
        int e1=-1;
        int e2=-1;
        
        
    }
    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    


    

    




    

    public static boolean[] sieve(int n){
        boolean isPrime[] = new boolean[n+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2;i*i<=n;i++){
            if(!isPrime[i])continue;
            for(int j= i*2;j<=n;j=j+i){
                isPrime[j] = false;
            }
        }
        return isPrime;


    }
    public static void swap(int a[][],int i1,int i2,int j1,int j2){
        int temp = a[i1][i2];
        a[i1][i2] = a[j1][j2];
        a[j1][j2] = temp; 
    }
    public static long helper1(long n){
        if(n==0 || n==1||n<0){
            return 0;
        }
        long pow = (long)(Math.log(n)/Math.log(2));

        long num = (long)(Math.pow(2, pow));

        long greater = n - num + 1;
        long add = num*2 - 1;
        if(greater>n/2){
            long ans = (n-1)*add;
            return ans;
        }
        long ans = greater*2*add;
        return ans + helper1(n-greater*2);
        


    }
    static int power(int x, int y, int p)
{
    int res = 1; 

    x = x % p;   

                 

    while (y > 0)
    {
        

        

        if ((y & 1) > 0)
            res = (res * x) % p;
 
        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}
 








static int modInverse(int a, int p)
{
    return power(a, p - 2, p);
}
 




static int modFact(int n,
                       int p)
    {
        if (n >= p)
            return 0;
     
        int result = 1;
        for (int i = 1; i <= n; i++)
            result = (result * i) % p;
     
        return result;
    }
    public static void bfs(ArrayList<ArrayList<Integer>> adj,boolean vis[],int dis[]){
        vis[0] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        int count = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int j = 0;j<size;j++){
                int poll = q.poll();
                dis[poll] = count;
                vis[poll] = true;
                for(Integer x : adj.get(poll)){
                    if(!vis[x]){
                        q.add(x);
                    }
                }
            }
            count++;
        }

    }

    
    
    
    



    
    
    
    

    public static void main(String args[]){  
        

        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        
        
        for(int t1 = 1;t1<=t;t1++){
            int n = s.nextInt();
            int arr[] = new int[n];
            long r=0;
            for(int i=0;i<n;i++){
                arr[i] = s.nextInt();
                if(arr[i]%2==1)r++;
            }
            

            long odd = 0;
            long ans = 0;
            boolean bool =false;
            
            long l =0;
            for(int i=1;i<n-1;i++){
                if(arr[i]!=1){
                    bool = true;
                }
                
                ans+=(arr[i]+1)/2;
            }
            if(n==3 && arr[1]%2==1)bool= false;
            if(!bool){
                System.out.println(-1);
                continue;
            }
            System.out.println(ans);
            
        }
        
            
            
    }
    

    
     


    
 
    
 
    
    
}  
 

 
 
 
 
 
 
 
 
