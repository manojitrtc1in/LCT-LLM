import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;


public class id5 {

    
    private static boolean id1(int a, int b, int[] uf) {
        
        return find(a,uf) == find(b,uf);
    }

    private static void union(int a, int b, int[] uf) {
        uf[find(a,uf)] = find(b,uf);
    }

    private static int find(int a, int[] uf) {
        if(a == uf[a])  return a;
        int root = find(uf[a],uf);
        uf[a] = root;
        return root;
    }

    private static void BFS(int i, int[][] G, int[][] path) {
       

        int[] v = new int[G.length]; 

        ArrayDeque<Integer> A = new ArrayDeque();
        A.add(i);
        while(A.isEmpty() == false){
            int u = A.pop();
            

            for(int a=0;a<v.length;a++){
                if(G[u][a] > 0 && v[a]==0 && a!=i){

                    

                    if(G[u][a] > v[u]){
                        

                        v[a] = G[u][a];
                    }
                    else    v[a] = v[u];
                    path[i][a] = v[a];
                    path[a][i] = v[a];
                   

                    
                    A.add(a);
                }
            }
        }
    }

    private static int numd(int x) {
        Double xx = Double.parseDouble(String.valueOf(x));
        int y = (int) Math.log10(xx);
        return (y+1);
       
         
        
    }

    private static String primeFactor(int n, boolean[] x) {
        String ans = "";
        for(int i=2;i<x.length;i++){
            if(i*i > n) break;
            if(x[i]){
                

                while(n!=1 && i*i <= n){
                    while(n%i==0){
                       

                        if(ans.equals(""))  ans=String.valueOf(i);
                        else    ans+=" x "+i;
                        n/=i;
                    }
                    break;
                }
            }
        }
        if(n!=1){
           

            if(ans.equals(""))  ans=String.valueOf(n);
            else    ans+=" x "+n;
        }
        return ans;
    }

    private static String solve(String s) {
        
        
        
        return null;
    }

    

    private static int id8(int n) {
        
        int count = 1;
        
        int tmp = n;
        
        for(int i=2;i*i<=n;i=(i==2?3:i+2)){
            
            

            
            int pow = 0;
            
            while(n%i==0){
                pow+=1;
                n/=i;
            }
            
            if(pow != 0){
                

                count*=(pow+1);
            }
        }
        
        if(n!=1){
            

            count*=2;
        }
        
        

        return count;
    }

    private static long id3(int n, int k) {
        
        long prod = 1;
        int j = 1;
        
        int st = Math.max(n-k, k)+1;
        int ed = Math.min(n-k, k);
        
        for(int i=st;i<=n;i++){
            for(;j<=ed;j++){
                if(prod%j==0)   prod/=j;
                else break;
            }
            prod*=i;
        }
        
        for(;j<=ed;j++){
            prod/=j;
        }
        
        return prod;
    }
    
    

    private static boolean check() {
        

        if(n%id7(a,b)!=0) {
           

            return false;
        }
        
        id0(a,b);
        long gcd=0,m1=x,m2=y;
        gcd=d;
        m1*=(n/d);
        m2*=(n/d);
        a/=d;
        b/=d;
        
        double f1 = (m1/b);f1*=-1;
        double f2 = (m2/a);
        long le = (long) Math.ceil(f1);
        long re = (long) Math.floor(f2);
        if(le > re) return false;
        long cf=c1*b-c2*a;
        if(cf*le < cf*re){
        
            x = m1+b*le;
            y = m2-a*le;
        }else{
            x = m1+b*re;
            y = m2-a*re;
        }
        

        
        
        return true;
    }

    private static void id0(long a, long b) {
        
        if(b==0){
            x=1;y=0;d=a;return;
        }
        id0(b,a%b);
        long x1 = y;
        long y1 = x-(a/b)*y;
        x=x1;
        y=y1;
    }

    private static void id6(int z, int I, int m, int x0) {
        
        int tor = func(z,I,m,x0);
        int har = func(z,I,m,tor); 

        

        
        while(tor!=har){
            tor = func(z,I,m,tor);
            har = func(z,I,m,har);
            har = func(z,I,m,har);
            

        }
        
        

        int x = 0;
        har = tor;
        tor = x0;
        
        while(har!=tor){
            
            tor = func(z,I,m,tor);
            har = func(z,I,m,har);
            x+=1;
            

        }
        
        

        int lam = 1;
        har = func(z,I,m,tor);
        
        while(har!=tor){
            har = func(z,I,m,har);
            lam+=1;
            

        }
        
       

    }

   private static int func(int z, int I, int m, int x0) {
        return ((z*x0)%m+I%m)%m;
    }

    private static void dfs(int a, int[][] d, int[] v,int[] p) {
        
        v[a] = 1;
        for(int i=0;i<v.length;i++){
            if(i!=a && d[i][a]!=0){
                if(v[i]==0){
                   

                    p[i]=a;
                    dfs(i,d,v,p);
                }else if(p[a] != i && a<i){
                   

                    cycle=true;
                }
            }
        }
        
    }

    private static void dolve(int x, int[] a) {
        

        int cnt = 0;
        for(int i=2;i<=Math.sqrt(x);i=(i==2?3:i+2)){
            int pow = 0;
            while(x%i==0){
                x/=i;
                pow+=1;
            }
            if(pow!=0){
                for(int j=1;j<=pow;j++){
                    long f = (long) Math.pow(i, j);
                    
                    if(f<a.length){
                        a[Integer.parseInt(String.valueOf(f))]=1;
                        

                    }
                    
                }
            }
        }
        
        if(x!=1){
            

            if(x<a.length)  a[x]=1;
        }
    }

    

    private static long search(long max, long tmp, long a, long b) {
        
        long lo = 0;
        long hi = max;
        
        while(lo < hi){
            
            long mid = (lo+hi)>>1;
            
            long k = mid*a;
            k/=b;
            if(k==tmp)  hi=mid;
            else    lo = mid+1;
        }
        
        return lo;
    }

    

    private static int palindrome(int i, int j, String s, int[][] dp) {
        

        int ret = 0;
        if(i==j)    {
            dp[i][j]=ret;
            return ret;
        }
        if(i+1==j && s.charAt(i)==s.charAt(j))  {
            dp[i][j]=ret;
            return ret;
        }
        if(i+1==j && s.charAt(i)!=s.charAt(j))  {
            
            ret = 1;
            dp[i][j]=ret;
            return ret;
        }
        
        if(s.charAt(i) == s.charAt(j)){
            
            ret = dp[i+1][j-1]==-1 ? palindrome(i+1,j-1,s,dp) : dp[i+1][j-1];
            

            dp[i][j]=ret;
            return ret;
        }
        else{
            int sub1 = dp[i+1][j]==-1 ? palindrome(i+1,j,s,dp) : dp[i+1][j];
            int sub2 = dp[i][j-1]==-1 ? palindrome(i, j-1,s,dp) : dp[i][j-1];
            int sub3 = dp[i+1][j-1]==-1 ? palindrome(i+1,j-1,s,dp) : dp[i+1][j-1];
            
            ret = Math.min(sub1, sub2);
            ret = Math.min(ret, sub3);
            ret+=1;
            dp[i][j]=ret;
            return ret;
        }
        

    }

    private static ArrayList<Integer> dfs_p(int a, int[] v, int[][] g, ArrayList<Integer> A) {
        
        v[a]=1;
        A.add(a);
        
        for(int i=0;i<v.length;i++){
            if(i!=a){
                if(g[a][i]==1 && v[i]==0){
                    

                    return dfs_p(i, v, g, A);
                }
            }
        }
        return A;
        
    }

    private static double qs(double lo, double hi, Pair[] S) {
        
        double ans = -1.0;
        
        for(int i=0;i<1000;i++){
            double mid = (lo+hi)/2.0;
            

            ans=mid;
            long tmp = 0;
            for(int j=0;j<S.length;j++){
                if(mid < S[j].d)    break;
                else{
                    tmp+=Long.parseLong(String.valueOf(S[j].p));
                }
            }
            

            
            if(tmp >= 1000000){
                hi=mid;
            }
            else if(tmp < 1000000){
                lo=mid;
            }
            
        }
        
       

        

        long tmp = 0;
        for(int i=0;i<S.length;i++){
            double d = Double.parseDouble(String.format( "%.7f", S[i].d ));
            ans = Double.parseDouble(String.format( "%.7f", ans ));
            

            if(d > ans)    break;
            else{
                tmp += S[i].p;
            }
        }
        
        if(tmp >= 1000000)  return ans;
        
        
        
        return -1.0;
    }

   

    static class Node{
        
        int d=-1;
        long num;
        public Node(int a,long c){
            this.d = a;
            
            this.num = c;
            
        }
    }
    
    static class Edge{
        
        String d;
        int p;

        int q;
        public Edge( String x1, int y1, int w){
            
            this.d = x1;
            this.p = y1;
            this.q = w;
        }
    }
    
    

    static boolean[] id2(int n){
        
        boolean[] ret = new boolean[n+1];
        Arrays.fill(ret, true);
        
        ret[0] = ret[1] = false;
        
        for(int i=2;i*i <= n; i++){
            
            if(ret[i]){
                
                for(int j=i*i;j<=n;j+=i){
                    
                    ret[j]=false;
                }
            }
        }
        
        return ret;
    }
   
    static long id7(long a, long b){
        
        while(b > 0){
            long r = a%b;
            a=b;
            b=r;
        }
        return a;
    }
    
    

    static long x,y,d; 

    static long c1,c2,a,b,n; 

    

    
    static class Pair{
        double d ;
        int x;
        int y;
        int p;
        public Pair(int a, int f, int p){
            this.x = a;
            this.y = f;
            this.p=p;
            

            double r = Math.pow(this.x, 2) + Math.pow(this.y, 2);
            this.d = Math.sqrt(r);
            
        }
    }
    
    static boolean cycle = false;
    
    static Stack<Integer> stack;
    static int[] dfs_low;
    static int[] dfs_num;
    static int timer;
    static int[] visit;
    
    static int[] id4(String S){
        
        int n = S.length();
        int[] L = new int[n];
        
        int index = 0;
        L[index] = 0; 

        
        while(index != n-1){
            
            int d = L[index];
            
            

            
            while(S.charAt(d) != S.charAt(index+1) && d >0){
                d = L[d-1];
            }
            
            L[index+1] = S.charAt(d)==S.charAt(index+1) ? d+1 : 0;
            
            index+=1;
        }
        return L;
    }
    
    static class C{
        String k;
        int v;
        public C(String k, int v){
            this.k=k;
            this.v=v;
        }
    }
    
    
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new PrintWriter(System.out));
        
        int n = (Integer.parseInt(br.readLine()));
        String[] a = new String[n];
        
        for(int i=0;i<n;i++){
            a[i] = br.readLine();
        }
        
        HashMap<String, Integer> H = new HashMap();
        ArrayList<C> A = new ArrayList();
        
        for(int i=0;i<n;i++){
            

            String tmp = a[i];
            int[] set = new int[26];
            String k = "";
            int cnt = 0;
            boolean bad = false;
            for(int j=0;j<tmp.length();j++){
                int t = tmp.charAt(j);
                t-=97;
                

                if(set[t]==0){
                    set[t]=1;
                    cnt+=1;
                    k+=String.valueOf(tmp.charAt(j));
                }
                if(cnt==3){
                    bad = true;
                    break;
                    
                }
                
            }
            
            if(!bad){
                cnt=tmp.length();
                

                if(k.length()==2){
                    char y1 = k.charAt(0);
                    char y2 = k.charAt(1);
                    
                    int state=-1;
                    state = y1 < y2 ? 0 : 1;
                    if(state==1)    k=String.valueOf(y2)+String.valueOf(y1);
                }
                
                if(!H.containsKey(k)) H.put(k, cnt);
                else H.put(k, cnt+H.get(k));
            }
            
            
            
        }
        
        if(H.size()==0) bw.append("0\n");
        else{
            C[] S = new C[H.size()];
            int index = -1;
            for (Map.Entry<String, Integer> entry : H.entrySet()) {
                String key = entry.getKey();
                Integer value = entry.getValue();
                index+=1;
                S[index] = new C(key,value);
                

    

            }
            
            for(int i=0;i<S.length;i++){
                for(int j=0;j<S.length;j++){
                    if(i!=j){
                        if(S[i].k.length()==1 && S[j].k.length()==2 && (S[j].k.charAt(0)==S[i].k.charAt(0) || (S[j].k.charAt(1)==S[i].k.charAt(0)))){
                            S[j].v+=S[i].v;
                        }
                        
                    }
                }
            }
            int max = 0;
            for(int i=0;i<S.length;i++){
                if(S[i].v > max)    max=S[i].v;
            }
            
            for(int i=0;i<S.length;i++){
                for(int j=i+1;j<S.length;j++){
                    if(S[i].k.length()==1 && S[j].k.length()==1 && !S[i].k.equals(S[j].k) && S[i].v+S[j].v > max){
                        max = S[i].v+S[j].v;
                    }
                }
            }
            System.out.println(max);
            
        }
        bw.close();
    }
}