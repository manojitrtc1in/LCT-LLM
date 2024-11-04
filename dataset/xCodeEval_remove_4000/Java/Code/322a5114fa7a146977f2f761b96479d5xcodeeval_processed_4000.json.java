import java.util.*;
import java.util.Map.Entry;

import javax.swing.ToolTipManager;

import org.xml.sax.HandlerBase;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.*;
import java.sql.Array;





public class Simple{
    public static class Node{
        int v;
        int val;
        
        public Node(int v,int val){
            this.val = val;
            this.v = v;
        }

    }
    static final Random random=new Random();
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter {
		private final BufferedWriter bw;

		public FastWriter() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}

		public void print(Object object) throws IOException {
			bw.append("" + object);
		}

		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}

		public void close() throws IOException {
			bw.close();
		}
	}
    static void id1(int[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    static void id1(long[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            long oi=random.nextInt(n), temp=a[(int)oi];
            a[(int)oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
    
    public static class Pair implements Comparable<Pair>{
        int x;
        int y;

        public Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
        public int compareTo(Pair other){
            
            return this.y - other.y;
            
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + x;
            result = prime * result + y;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Pair other = (Pair) obj;

            if (x != other.x)
                return false;
            if (y != other.y)
                return false;
            return true;
        }
        

        

        

        

        

        

        

        

        

        

        

        

         
    }
    static long power(long x, long y, long p)
    {
 
        

        long res = 1;
 
        

        

        x = x % p;
 
        while (y > 0) {
 
            

            

            if (y % 2 == 1)
                res = (res * x) % p;
 
            

            y = y >> 1; 

            x = (x * x) % p;
        }
 
        return res;
    }
 
    

    static long modInverse(long n, long p)
    {
        return power(n, p - 2, p);
    }
    static long[] fac = new long[100000 + 1];
    

    

    static long id7(long n, long r,
                             long p)
    {
 
          if (n<r)
              return 0;
      

        if (r == 0)
            return 1;
 
        

        

        

        
        
 
        
 
        return (fac[(int)n] * modInverse(fac[(int)r], p)
                % p * modInverse(fac[(int)n - (int)r], p)
                % p)
            % p;
    }

    static int id3(int n, int r, int p)
    {
        if (r > n - r)
            r = n - r;
 
        

        

        

        int C[] = new int[r + 1];
 
        C[0] = 1; 

 
        

        

        for (int i = 1; i <= n; i++) {
 
            

            

            for (int j = Math.min(i, r); j > 0; j--)
 
                

                C[j] = (C[j] + C[j - 1]) % p;
        }
        return C[r];
    }

    
    static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    static long id6(long a, long b)
    {
        

        if (a == 0)
          return b;
        if (b == 0)
          return a;
      
        

        if (a == b)
            return a;
      
        

        if (a > b)
            return id6(a%b, b);
        return id6(a, b%a);
    }
    

    
    

    

        
    

    

    

    

    

    

    


    

    

    

    

    

    

        
    



    public static long id5(long a, long b)
    {
        if (b == 0)
            return a;
        return id5(b, a % b);
        
    }
 
    public static class DSU{
        int n;
        int par[];
        int rank[];

        public DSU(int n){
            this.n = n;
            par = new int[n+1];
            rank = new int[n+1];

            for(int i=1;i<=n;i++){
                par[i] = i ;
                rank[i] = 0;
            }
        }
        public int findPar(int node){
            if(node==par[node]){
                return node;
            }
            return par[node] = findPar(par[node]);

        }
        public void union(int u,int v){
            u = findPar(u);
            v = findPar(v);
            if(rank[u]<rank[v]){
                par[u] = v;
            }
            else if(rank[u]>rank[v]){
                par[v] = u;
            }
            else{
                par[v] = u;
                rank[u]++;
            }
        }
    }  
    public static boolean id2(char[] arr,int n,boolean vis[]){
        int i=0;
        int j= n-1;
        while(i<j){
            if(vis[i])i++;
            else if(vis[j])j--;
            else{
                if(arr[i]!=arr[j])return false;
                i++;
                j--;
            }
        }
        return true;
    }
    public static List<List<Integer>> permute(int[] nums) {
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        
        helper(ans,list,nums,nums.length);
        return ans;
    }
    
    public static void  helper(List<List<Integer>> ans,List<Integer> list,int nums[],int n){
        if(list.size()==n){
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!list.contains(nums[i])){
                list.add(nums[i]);
                helper(ans,list,nums,n);
                list.remove(list.size()-1);
                
            }
            
        }
        
        
    }
    static int level = 0;
    static ArrayList<Integer> nodes;
    public static int id4(Map<Integer,Integer> par, int s, int d)
        {
            level = 0;
  
            

            if (par.get(s) == -1)
            {
                System.out.printf("Shortest Path between"+ 
                                "%d and %d is %s ", s, d, s);
                return level;
            }
  
            id4(par, par.get(s), d);
  
            level++;
            

            

  
            return level;
        }
  
        

        

  
        

        

        

    public static void swap(char arr[],int i){
        char c = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = c;
    }
    public static String mul(String str,int n){
        int carry = 0;
        StringBuilder muli = new StringBuilder(); 
        for(int i=n-1;i>=0;i--){
            int val = str.charAt(i) - '0';
            int ans = val*2 + carry;
            carry = ans/10;
            ans = ans%10;
            char c = (char)(ans + '0');
            muli.append(c);
        }
        if(carry!=0){
            muli.append((char)(carry + '0'));

        }
        muli.reverse();
        return muli.toString();
    }
    static boolean id8(String str1, String str2)
    {
        

        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
 
        for (int i = 0; i < n1; i++)
            if (str1.charAt(i) < str2.charAt(i))
                return true;
            else if (str1.charAt(i) > str2.charAt(i))
                return false;
 
        return false;
    }
 
    

    static String findDiff(String str1, String str2)
    {
        

        

        if (id8(str1, str2)) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }
 
        

        String str = "";
 
        

        int n1 = str1.length(), n2 = str2.length();
 
        

        str1 = new StringBuilder(str1).reverse().toString();
        str2 = new StringBuilder(str2).reverse().toString();
 
        int carry = 0;
 
        

        

        for (int i = 0; i < n2; i++) {
            

            

            int sub
                = ((int)(str1.charAt(i) - '0')
                   - (int)(str2.charAt(i) - '0') - carry);
 
            

            

            

            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
 
            str += (char)(sub + '0');
        }
 
        

        for (int i = n2; i < n1; i++) {
            int sub = ((int)(str1.charAt(i) - '0') - carry);
 
            

            

            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
 
            str += (char)(sub + '0');
        }
        
        

        return new StringBuilder(str).reverse().toString();
    }
    public static double cal1(double x1,double x2,double y1,double y2){
        double x = Math.abs(x1 - x2);
        double y = Math.abs(y1 - y2);
        double ans = x*x + y*y;
        return Math.sqrt(ans);
    }

    static final int MAXN = 100001;
      
    

    static int spf[] = new int[MAXN];
      
    

    

    

    static void sieve()
    {
        spf[1] = 1;
        for (int i=2; i<MAXN; i++)
      
            

            

            spf[i] = i;
      
        

        

        for (int i=4; i<MAXN; i+=2)
            spf[i] = 2;
      
        for (int i=3; i*i<MAXN; i++)
        {
            

            if (spf[i] == i)
            {
                

                for (int j=i*i; j<MAXN; j+=i)
      
                    

                    

                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
    }
      
    

    

    static Vector<Integer> id9(int x)
    {
        Vector<Integer> ret = new Vector<>();
        while (x != 1)
        {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    public static long dfs(long index,int currIndex,long arr[][],int n){
        if(currIndex==-1)return 1;
        if(index <=n){
            return index;
        }
        if(index< arr[currIndex][3]){
            return dfs(index, currIndex -1 , arr, n);
        }
        else{
            long nindex = arr[currIndex][0] + index - arr[currIndex][3];
            return dfs(nindex, currIndex-1, arr, n);
        }
    }
       

    

    static int getMid(int s, int e)
    {
        return s + (e - s) / 2;
    }
 
    
    static int MaxUtil(int[] st, int ss,
                       int se, int l,
                       int r, int node)
    {
 
        

        

        

        if (l <= ss && r >= se)
            return st[node];
 
        

        

        if (se < l || ss > r)
            return -1;
 
        

        

        int mid = getMid(ss, se);
 
        return Math.max(
            MaxUtil(st, ss, mid, l, r,
                     2 * node + 1),
            MaxUtil(st, mid + 1, se, l, r,
                    2 * node + 2));
    }
 
    
    static void updateValue(int arr[], int[]
                            st, int ss,
                            int se, int index,
                            int value,
                            int node)
    {
        if (index < ss || index > se) {
            System.out.println("Invalid Input");
            return;
        }
 
        if (ss == se) {
 
            

            

            arr[index] = value;
            st[node] = value;
        }
        else {
            int mid = getMid(ss, se);
 
            if (index >= ss && index <= mid)
                updateValue(arr, st, ss, mid,
                            index, value,
                            2 * node + 1);
            else
                updateValue(arr, st, mid + 1, se, index,
                            value, 2 * node + 2);
 
            st[node] = Math.max(st[2 * node + 1],
                                st[2 * node + 2]);
        }
        return;
    }
 
    

    

    static int getMax(int[] st, int n, int l, int r)
    {
 
        

        if (l < 0 || r > n - 1 || l > r) {
            System.out.printf("Invalid Input\n");
            return -1;
        }
 
        return MaxUtil(st, 0, n - 1, l, r, 0);
    }
 
    

    

    

    static int id0(int arr[],
                               int ss, int se,
                               int[] st, int si)
    {
 
        

        

        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
 
        

        

        

        int mid = getMid(ss, se);
 
        st[si] = Math.max(
            id0(arr, ss, mid,
                            st, si * 2 + 1),
            id0(arr, mid + 1,
                            se, st,
                            si * 2 + 2));
 
        return st[si];
    }
 
    
    static int[] constructST(int arr[], int n)
    {
 
        

        int x = (int)Math.ceil(Math.log(n) / Math.log(2));
 
        

        int max_size = 2 * (int)Math.pow(2, x) - 1;
 
        

        int[] st = new int[max_size];
 
        

        id0(arr, 0, n - 1, st, 0);
 
        

        return st;
    }
    public static int differentArrays(int N,List<Long> A, int K){
        int count = 0;
        long mod = 1000000007;
        for(Long x : A){
            if(x!=0)count++;
        }
        long[] ncr = new long[count+1];
        ncr[0] = 1;
        for(int i=1;i<=count;i++){
            ncr[i] = ncr[i-1]*(long)(count - i + 1);
            long div = modInverse(i, mod);
            ncr[i] = (ncr[i] * div)%mod;
        }
        int start = Math.min(count, K);
        if(K > count && (K-count)%2==1)start--;
        long ans = 0;
        while(start>=0){
            ans= (ans+ncr[start])%mod;
            start-=2;
        }

        return (int)ans;

    }
    public static void calc(long diff[], long arr[]){
        diff[0] = 0;
        long mod = 1000000007;
        arr[1] = 8;
        arr[2] = 10;
        diff[2] = 2;
        diff[3] = 8;
        

        for(int i = 3;i<100005;i++){
            arr[i] = (arr[i-1] + diff[i])%mod;
            diff[i + 1] = ((arr[i-1] + arr[i-2])%mod)%mod;
            if(i <= 10){
                

            }
        }
        

    }
   
    public static void main(String args[]){  
        
        try {
            FastReader s=new FastReader();
            

            

                
            int testCases= s.nextInt();
            while(testCases-- > 0){
                int n = s.nextInt();
                int k = s.nextInt();
                k = k % 4;

                if(k == 0 ){
                    System.out.println("NO");
                    continue;
                }
                System.out.println("YES");
                for(int i = 1;i <= n; i+=2){
                    long one = i ;
                    long two = i + 1;
                    long num = (one + k)*two;
                    if(num%4 != 0){
                        one++;
                        two--;
                    }

                    System.out.println(one +" "+two);

                }
            

            }
               
            
        } 
        catch (Exception e) {
            System.out.println(e.toString());
            

            return;
        }
        
    }
    
    
}    

