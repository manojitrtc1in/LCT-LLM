import java.util.*;



import java.io.*;


 
 public class Main {
 
    public static void main(String[] args) {
         
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader inp = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(inp, out);
        out.close();
 
    }
 
 
 
 
 
    static class Solver {
 
        class pair implements Comparable<pair>{
 
            int i;
            int cnt;
            public pair(int i,int cnt)
            {
                this.i=i;
                this.cnt=cnt;
            }
 
            public int compareTo(pair p)
            {
                return Long.compare(this.i,p.i);
            }
 
        }
 
        class Node implements Comparable < Node > {
            int i;
            int cnt;
 
            Node(int i, int cnt) {
                this.i = i;
                this.cnt = cnt;
            }
 
            public int compareTo(Node n) {
                if (this.cnt == n.cnt) {
                    return Integer.compare(this.i, n.i);
                }
                return Integer.compare(this.cnt, n.cnt);
            }
        }
 
        public boolean done(int[] sp, int[] par) {
            int root;
 
            root = findSet(sp[0], par);
 
            for (int i = 1; i < sp.length; i++) {
                if (root != findSet(sp[i], par))
                    return false;
            }
            return true;
        }
        public int findSet(int i, int[] par) {
            int x = i;
            boolean flag = false;
            while (par[i] >= 0) {
                flag = true;
                i = par[i];
            }
            if (flag)
                par[x] = i;
            return i;
        }
 
        public void unionSet(int i, int j, int[] par) {
            int x = findSet(i, par);
            int y = findSet(j, par);
            if (x < y) {
                par[y] = x;
            } else {
                par[x] = y;
            }
        }
 
        public long pow(long a, long b, long MOD) {
            if (b == 0) {
                return 1;
            }
            if (b == 1) {
                return a;
            }
            long val = pow(a, b / 2, MOD);
            if (b % 2 == 0) {
                return val * val % MOD;
            } else {
                return val * (val * a % MOD) % MOD;
 
            }
 
        }
 
        public boolean isPrime(int n)
        {
            for(int i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    return false;
                }
            }
            return true;
        }
 
 
        public void id1(int n, int[] s) {
            boolean prime[] = new boolean[n + 1];
            Arrays.fill(prime, true);
            s[1] = 1;
            s[2] = 2;
            for (int i = 4; i <= n; i += 2) {
                prime[i] = false;
                s[i] = 2;
            }
 
            for (int i = 3; i <= n; i += 2) {
                if (prime[i]) {
                    s[i] = i;
                    for (int j = 2 * i; j <= n; j += i) {
                        prime[j] = false;
                        s[j] = i;
                    }
                }
            }
 
        }
 
 
        public void id0(int n, ArrayList < Node > al, int s[]) {
            int curr = s[n];
            int cnt = 1;
            while (n > 1) {
                n /= s[n];
                if (curr == s[n]) {
                    cnt++;
                    continue;
 
                }
                Node n1 = new Node(curr, cnt);
                al.add(n1);
 
                curr = s[n];
                cnt = 1;
            }
        }
 
 
 
        public int binarySearch(int n, int k) {
            int left = 1;
            int right = 100000000 + 5;
            int ans = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (n / mid >= k) {
                    left = mid + 1;
                    ans = mid;
                } else {
                    right = mid - 1;
                }
            }
 
            return ans;
        }
        public boolean id9(String s) {
            char ch[] = s.toCharArray();
 
            for (int i = 0; i < s.length() / 2; i++) {
                if (ch[i] != ch[s.length() - 1 - i])
                    return false;
            }
            return true;
        }

        public boolean id2(String s1, String s2)
        {
            char ch[] = s1.toCharArray();
            char ch1[] = s2.toCharArray();

            for(int i=0;i<s1.length();i++)
            {
                if(ch[i]!=ch1[s1.length()-1-i])
                {
                    return false;
                }
            }

            return true;
        }
 
 
 
 
        public void remove(ArrayList < Integer > [] al, int x) {
            for (int i = 0; i < al.length; i++) {
                for (int j = 0; j < al[i].size(); j++) {
 
                    if (al[i].get(j) == x)
                        al[i].remove(j);
 
                }
            }
        }
 
        public long gcd(long a, long b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);
        }
 
 
        public void id8(long n, ArrayList < Long > al) {
            

            for (long i = 1; i*i <= (n); i++) {
                if (n % i == 0) {
                    

                    if (n / i == i) {
                        al.add(i);
                    } else 

                    {
                        al.add(i);
                        al.add(n / i);
                    }
 
                }
            }
        }
 
        public static long constructSegment(long seg[], long arr[], int low, int high, int pos) {
            if (low == high) {
                seg[pos] = arr[low];
                return seg[pos];
            }
            int mid = (low + high) / 2;
            long t1 = constructSegment(seg, arr, low, mid, (2 * pos) + 1);
            long t2 = constructSegment(seg, arr, mid + 1, high, (2 * pos) + 2);
            seg[pos] = t1 + t2;
            return seg[pos];
 
        }
        public static long querySegment(long seg[], int low, int high, int qlow, int qhigh, int pos) {
 
            if (qlow <= low && qhigh >= high) {
                return seg[pos];
            } else if (qlow > high || qhigh < low) {
                return 0;
            } else {
                long ans = 0;
                int mid = (low + high) / 2;
                ans += querySegment(seg, low, mid, qlow, qhigh, (2 * pos) + 1);
                ans += querySegment(seg, mid + 1, high, qlow, qhigh, (2 * pos) + 2);
                return ans;
            }
 
        }
        public static int lcs(char[] X, char[] Y, int m, int n) {
            if (m == 0 || n == 0)
                return 0;
            if (X[m - 1] == Y[n - 1])
                return 1 + lcs(X, Y, m - 1, n - 1);
            else
                return Integer.max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
        }
 
        public static long recursion(long start, long end, long cnt[], int a, int b) {
 
            long min = 0;
            long count = 0;
            int ans1 = -1;
            int ans2 = -1;
            int l = 0;
            int r = cnt.length - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (cnt[mid] >= start) {
                    ans1 = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
 
            l = 0;
            r = cnt.length - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (cnt[mid] <= end) {
                    ans2 = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
 
            if (ans1 == -1 || ans2 == -1 || ans2 < ans1) {
                

                min = a;
                return a;
 
            } else {
                min = b * (end - start + 1) * (ans2 - ans1 + 1);
            }
            if (start == end) {
                

                return min;
            }
            long mid = (end + start) / 2;
            min = Long.min(min, recursion(start, mid, cnt, a, b) + recursion(mid + 1, end, cnt, a, b));
            

            return min;
        }
 
 
        public int lowerBound(ArrayList<Long> al,long ele)
        {
            int l =0;
            int r =al.size()-1;
            int ans=-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(al.get(mid)<=ele)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }


            }
            return ans;
        }
        
        public int lowerBound(long arr[],long ele)
        {
            int l =0;
            int r =arr.length-1;
            int ans=-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(arr[mid]<=ele)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }


            }
            return ans;
        }
 
        public long dfs_util(ArrayList < Integer > [] al, boolean vis[], int x ,long arr[],long val) {
 
            vis[x] = true;

           
            long temp=0;
            for (int i = 0; i < al[x].size(); i++) {
 
                if (!vis[al[x].get(i)]) {
                    
                    temp+=dfs_util(al, vis, al[x].get(i),arr,val+1);
                }

            }
            arr[x]=val-(temp);
            return (temp+1);
           
          
        }
 
        public  long[] dfs(ArrayList[] al) {
            long arr[] = new long[al.length];
            boolean vis[] = new boolean[al.length];
            for (int i = 0; i < al.length; i++) {
                if (!vis[i]) {
                     dfs_util(al, vis, i,arr,0);
                }
            }
            return arr;
           
        }
 

        public void permute(String s,int l, int r,ArrayList<String> al)
        {
            if(l==r)
            {
                al.add(s);
                
            }
            for(int i=l;i<=r;i++)
            {
                String str=swap(s,l,i);
                permute(str, l+1, r, al);
                
            }
        
        }

        public String swap(String s, int l, int r)
        {
            char ch[] = s.toCharArray();
            char tem = ch[l];
            ch[l]=ch[r];
            ch[r]=tem;
            return String.valueOf(ch);
        }
        

        public int[] id4(String s)
        {
            int ans[] =new int[s.length()];
            char ch[] = s.toCharArray();
            int n = s.length();
            int i=1;
            int len=0;
            ans[0]=0;
            while(i<n)
            {
                if(ch[i]==ch[len])
                {
                    len++;
                    ans[i]=len;
                    i++;
                }
                else
                {
                    if(len!=0)
                    {
                        len=ans[len-1];
                    }
                    else
                    {
                        ans[i]=len;
                        i++;
                    }
                }
            }
 
            return ans;
 
        }

        public int id7(String s)  
        { 
            int n = s.length(); 
        
            if(n < 2) { 
                return 0; 
            } 
    
            int len = 0; 
            int i = n/2; 
            while(i < n) { 
                if(s.charAt(i) == s.charAt(len)) { 
                ++len; 
                ++i; 
            }  
            else 
            { 
            if(len == 0) { 
                ++i; 
            }  
            else 
            {  
                
                --len; 
            } 
            } 
    } 
        
    return len; 
          
} 

        public boolean id6(long num, int fromBase, int toBase,HashSet<Integer> hs) {
            StringBuilder s=new StringBuilder();
            boolean f=true;
            int cnt=0;
            while(num>0)
            {
               long tem = num%toBase;
               if(tem==1)
               {
                 if(hs.contains(cnt))
                 {
                     f=false;
                     break;
                 }
                 else
                 {
                     hs.add(cnt);
                 }
               }
               else if(tem==0)
               {

               }
               else
               {
                f=false;
                break;
               }
               num/=toBase;
               cnt++;

            }


            return f;
            
        }

        private boolean possible(long arr[],long d,long k)
        {
            long tem=0;
            for(int i=0;i<arr.length-1;i++)
            {
                tem+=(arr[i+1]-arr[i])/(d);

                if((arr[i+1]-arr[i])%d==0)
                    tem--;
                
            }
            if(tem<=k)
            {
                return true;
            }
            else
                return false;
            
        }

        public void id3(ArrayList<Integer> a[],int out[])
        {
            boolean vis[] = new boolean[a.length];
            for(int i=0;i<a.length;i++)
            {
                if(!vis[i])
                {
                    id5(a, vis,out,i);
                }
            }
        }


        public int[] id5(ArrayList<Integer> arr[],boolean vis[],int color[],int e)
        {
          
          
            Queue<Integer> q = new LinkedList<>();
            color[e]=1;
            q.add(e);
            while(!q.isEmpty())
            {
                int x = q.remove();
                if(vis[x])
                {
                    continue;
                }
                vis[x]=true;
                for(int i=0;i<arr[x].size();i++)
                {
                    if(!vis[arr[x].get(i)])
                    {
                        
                    }
                    else
                    {
                        if(color[arr[x].get(i)]==color[x])
                        {
                            color[x]=2;
                        }
                    }
                }

                for(int i=0;i<arr[x].size();i++)
                {
                    if(!vis[arr[x].get(i)])
                    {
                        if(color[x]==2)
                        {
                            color[arr[x].get(i)]=0;
                            
                        }
                        else
                        {
                            color[arr[x].get(i)]=1-color[x];
                            
                        }
                        q.add(arr[x].get(i));
                    }
                    
                }
            }
            return color;
        }

        
        
 
       public int dfs1(ArrayList<Integer> al[],int x,boolean arr[],int val,boolean vis[],long ans[])
       {
           vis[x]=true;
           if(arr[x])
           {
           

               ans[0]+=(long)val;
           }
           for (int i = 0; i < al[x].size(); i++) {
 
            if (!vis[al[x].get(i)]) {
                int temp = val;
                if(!arr[x])
                    temp++;
                dfs1(al, al[x].get(i),arr,temp,vis,ans);
            }

        }
            return 0;
       }
 
        private void solve(InputReader inp, PrintWriter out1) {
            int n = inp.nextInt();
            int k = inp.nextInt();
            ArrayList<Integer> al[] = new ArrayList[n];
            for(int i=0;i<n;i++)
            {
                al[i] = new ArrayList<Integer>();
            }
            for(int i=0;i<n-1;i++)
            {
                int x= inp.nextInt();
                int y = inp.nextInt();
                al[x-1].add(y-1);
                al[y-1].add(x-1);
            }
          
            long arr[]=dfs(al);
            

            Arrays.sort(arr);
            

            long sum=0;
            for(int i=n-1;i>=n-k;i--)
            {
                sum+=arr[i];
            }
            out1.println(sum);
        
        }
     
    }

 
 
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
 
        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
class ele implements Comparable<ele>{
    int i;
    int dis;
    boolean mark;
    boolean leaf;
    public ele(int i,int dis)
    {
        this.i=i;
        this.dis=dis;
        this.mark=false;
        this.leaf=false;
    }
    @Override
    public int compareTo(ele e)
    {
       if(this.dis==e.dis)
       {
           if(e.leaf==true)
            return 1;
           else if(this.leaf)
            return -1;
           else
            return 0; 
       }
        
        return -Integer.compare(this.dis,e.dis);
    }
}