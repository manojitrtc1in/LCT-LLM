


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class board
{
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }



    
    static void helper(String s,int[] a,int n,String match,int inc){
        int i=0;
        while(i<n){
            int j = i;
            if(j+inc-1<=n-1 && s.substring(j,j+inc).equals(match)){
                a[j] = 1;
                i = j+inc-1;
            }
            else{
                i++;
            }
        }

    }
    static final int MAXN = 100000;
    static final int level = 18;



    



    static int[] diameter;
    static int bfs(int init, int n)
    {
        

        Queue<Integer> q = new LinkedList<>();
        q.add(init);

        int visited[] = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            visited[i] = 0;
            diameter[i] = 0;
        }

        

        q.add(init);

        

        visited[init] = 1;
        while (q.size() > 0)
        {
            int u = q.peek();
            q.remove();
            for (int nei : adj[u])
            {
                if (visited[nei] == 0)
                {
                    visited[nei] = 1;

                    

                    diameter[nei] += diameter[u] + 1;
                    q.add(nei);
                }
            }
        }
        int in = 0;
        for(int i = 0; i <= n; i++)
        {
            if(diameter[i] > diameter[in])
                in = i;
        }

        

        return in;
    }
    private static int dfs(int node,LinkedList<Integer>[] adj,int parent,int[] sub){

        int size = 1;
        for(int nei : adj[node]){
            if(nei != parent){
                size += dfs(nei,adj,node,sub);
            }
        }
        sub[node] = size;
        return size;
    }
    private static int dfs2(int node,LinkedList<Integer>[] adj,int parent,int[] sub){
        int res = sub[node];
        int maxScore = 0;
        for(int nei : adj[node]){
            if(nei != parent) {
                maxScore = Math.max(maxScore,dfs2(nei,adj,node,sub));
            }
        }
        return res + maxScore;
    }
    public static void primeFactors(long n)
    {
        

        while (n%2==0)
        {
            id6.put((long)2,id6.getOrDefault((long)2,0)+1);
            n /= 2;
        }

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            while (n%i == 0)
            {
                id6.put((long)i,id6.getOrDefault((long)i,0)+1);
                n /= i;
            }
        }

        

        

        if (n > 2)
            id6.put(n,id6.getOrDefault(n,0)+1);
    }
    static TreeMap<Long,Integer> id6;
    
    static LinkedList<Integer>[] adj;
    static int[] color;
    static int[] parent;
    static int cycle_end;
    static int cycle_start;
    static int n;
    static HashSet<Integer> cycle;
    static boolean dfs(int v, int par) { 

        color[v] = 1;
        for (int u : adj[v]) {
            if(u == par) continue; 

            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u, parent[u]))
                    return true;
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    static void find_cycle() {
        Arrays.fill(color,0);
        Arrays.fill(parent,-1);
        cycle_start = -1;

        for (int v = 0; v <= n; v++) {
            if (color[v] == 0 && dfs(v, parent[v]))
                break;
        }



        cycle.add(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.add(v);
        cycle.add(cycle_start);
        


    }
    static int dfs2(int node,int par){
        int s = 1;
        for(int nei: adj[node]){
            if(!cycle.contains(nei) && nei != par){
                s += dfs2(nei,node);
            }
        }
        return s;
    }
    static long id5(int n){
        return ((long)(n)*(long)(n-1))/2;
    }
    static int[][] d = new int[][]{{0,0},{1,0},{0,1},{1,1}};
    static Long[][] dp;
    static long go(int start,int i,long[] f,long[] cost,long fuel,int started){
        int s = start,ss = started;
        

        if(start != -1 && fuel<0) return Integer.MAX_VALUE;
        if(i >= f.length){
            

            if(start == -1 ) return Integer.MAX_VALUE;
            if(fuel+1 >= (f.length-(i-1-start))) return 0;
            else return Integer.MAX_VALUE;
        }
        if(start != -1 && dp[i][start] != null) return dp[i][start];
        long totCost = Long.MAX_VALUE;
        if(start == -1) {
            

            start = i;
            started = 1;
        }
        fuel += f[i];
        

        totCost = Math.min(totCost,cost[i]*f[i] + go(start,i+1,f,cost,fuel-1,started));
        fuel -= f[i];

        totCost = Math.min(totCost,go(s,i+1,f,cost,(s == -1)?0:fuel-1,ss));


        if(s == -1)return totCost;
        return dp[i][s] = totCost;

    }















    public static  int id0(double a, double b, double c){
        double root1, root2; 

        root1 = (-b + Math.sqrt(Math.pow(b, 2) - 4*a*c)) / (2*a);
        root2 = (-b - Math.sqrt(Math.pow(b, 2) - 4*a*c)) / (2*a);
        int min = Integer.MAX_VALUE;
        if(root1 >= 0 && root1<min && Math.ceil(root1) == root1)min = (int)root1;
        if(root2 >= 0 && (int)root2<min && Math.ceil(root2) == root2)min = (int)root2;
        if(min == Integer.MAX_VALUE) return -1;
        return min;
    }
    static void print(int[] days){
        for(int i:days)out.print(i+" ");
        out.println();
    }
    static void print(int[][] a){
        for(int[] f:a){
            out.println();
            for(int i:f){
                out.print(i+" ");
            }
        }
        out.println();
    }
    static PrintWriter out;
    static int[] pre;

    static int XOR(int l,int r){
        if(l == 0){
            return pre[r];
        }
        else{
            return pre[r]^pre[l-1];
        }
    }
    static int m = (int)(1e9+7);
    static long prod(long a,long b){
        return (a%m * b%m)%m;
    }
    static List<Long> dfs(int node,LinkedList<Integer>[] adj,int[] a){
        List<Long> ret = new ArrayList<>();
        for(int nei:adj[node]){
            List<Long> get = dfs(nei,adj,a);
            for(long e:get) ret.add(e);
        }
        if(ret.isEmpty()){
            ret.add((long)a[node]);
            return ret;
        }
        Collections.sort(ret);
        long max = ret.get(ret.size()-1);
        int needed = a[node];
        for(int i=0;i<ret.size();i++){
            long diff = max-ret.get(i);
            if(needed > diff){
                ret.set(i,ret.get(i)+diff);
                needed -= diff;
            }
            else{
                ret.set(i,ret.get(i)+needed);
                needed = 0;
                break;
            }
        }
        if(needed > 0){
            for(int i=0;i<ret.size();i++){
                ret.set(i,ret.get(i)+needed/ret.size());
            }
            if(needed%ret.size() != 0){
                ret.set(0,ret.get(0)+needed%ret.size());
            }

        }
        return ret;

    }
    static int manhattan(int[] a,int[] b){
        return Math.abs(a[0]-b[0])+Math.abs(a[1]-b[1]);
    }
    static boolean id1(int[] head,int r,int c,int[][] pre,int[][] suf){
        int diff = r-head[1];
        int want = (1+(diff)*(2))/2 + 1;
        if(pre[r][c] >= want && suf[r][c] >= want) return false;
        return true;
    }
    

    static boolean good(char[] s){
        long val = Long.parseLong(String.valueOf(s));
        for(char c:s){
            int dig = c-'0';
            if(dig == 0) continue;
            if(val%dig != 0) return false;
        }
        return true;
    }
    static long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    


































    static long id2(long target, long number) {
        for(long i=target;i>=1;i--){
            if(number%i == 0) return i;
        }
        return -1;
    }
    public static int id3(int[] nums) {

        int pref = nums[0];
        int max = pref;
        for(int i=1;i<nums.length;i++){
            pref += nums[i];
            max = Math.max(max,pref);

        }
        return max;

    }
    static int bs(int[][] a,int h,int w){
        int lo = 0;
        int hi = a.length-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(a[mid][0]<h && a[mid][1]<w){
                return a[mid][2];
            }
            else{
                hi = mid-1;
            }
        }
        return -1;
    }
    static int ff(int[] a,int[] mark,int i){
        int c1 = 0;
        int c2 = 0;
        for(int j=Math.max(0,i-5);j<Math.min(a.length,i+5);j++){
            int here = 0;
            if(j-1>=0 && j+1< a.length && a[j]>a[j-1] && a[j]>a[j+1]){
                here = 1;
            }
            else if(j-1>=0 && j+1< a.length && a[j]<a[j-1] && a[j]<a[j+1]){
                here = 1;
            }
            c1 += (mark[j]!=0)?1:0;
            c2 += here;
            

        }
        return c1-c2;
    }
    static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    

    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    public static void main(String[] args)
    {
        FastReader sc=new FastReader();
        out = new PrintWriter(System.out);
        int t = sc.nextInt();
        while(t-->0) {

            int n = sc.nextInt();
            int m = sc.nextInt();
            String s = sc.nextLine();
            int[] sum = new int[n];
            sum[0] = (s.charAt(0) == '+')?1:-1;
            for(int i=1;i<n;i++){
                sum[i] += sum[i-1]+((s.charAt(i) == '+')?1:-1);
            }
            int[] preMin = new int[n];
            int[] preMax = new int[n];
            int[] id4 = new int[n];
            int[] id7 = new int[n];
            preMin[0] = sum[0];
            preMax[0] = sum[0];
            id4[n-1] = sum[n-1];
            id7[n-1] = sum[n-1];

            for(int i=1;i<n;i++){
                int j = n-1-i;
                preMin[i] = Math.min(preMin[i-1],sum[i]);
                preMax[i] = Math.max(preMax[i-1],sum[i]);
                id4[j] = Math.min(id4[j+1],sum[j]);
                id7[j] = Math.max(id7[j+1],sum[j]);
            }

            for(int i=0;i<m;i++){
                int l = sc.nextInt();
                int r = sc.nextInt();
                int ans = 0;
                if(l > 1 && r < n){


                    int left = sum[l-1];
                    int right = sum[r-1];
                    int rmin = id4[r]-right;
                    int rmax = id7[r]-right;
                    int lmin = preMin[l-2];
                    int lmax = preMax[l-2];
                    rmin += sum[l-2];
                    rmax += sum[l-2];
                    ans = Math.max(rmax,lmax)-Math.min(lmin,rmin)+1;
                    if((Math.max(rmax,lmax)>=0 && Math.min(lmin,rmin)<=0)){
                        ans = ans;
                    }
                    else ans +=1;

                }
                else if(l ==1 && r == n){
                    ans = 1;
                }
                else if(r == n){
                    int lmin = preMin[l-2];
                    int lmax = preMax[l-2];










                    if((lmax>=0 && lmin<=0))
                        ans = lmax-lmin+1;
                    else
                        ans = lmax-lmin+2;
                }
                else {
                    int right = sum[r-1];
                    int rmin = id4[r]-right;
                    int rmax = id7[r]-right;
                    if((rmax>=0 && rmin<=0))
                    ans = rmax-rmin+1;
                    else
                        ans = rmax-rmin+2;


                }
                out.println(ans);
            }


        }






        out.close();
    }


}