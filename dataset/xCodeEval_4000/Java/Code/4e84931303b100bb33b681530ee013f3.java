import java.io.*;
import java.util.*;


 public class Main {
static BufferedReader bf;
static PrintWriter out;
static Scanner sc;
static StringTokenizer st;
static long mod = (long)(1e9+7);
static long mod2 = 998244353;
    
static long fact[] = new long[1000001];
static long inverse[] = new long[1000001];
    public static void main (String[] args)throws IOException {
    bf = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out);
    sc = new Scanner(System.in);












    

    

        solve();
    

    
}
public static void solve() throws IOException{
   int n = nextInt();
   Long[][]arr = new Long[n][2];
   for(int i = 0;i<n;i++){
    arr[i][0] = nextLong();
    arr[i][1] = nextLong();
   }
   Arrays.sort(arr,(a,b)->(Long.compare(a[1],b[1])));
   int j = n-1;
   long current = 0;
   long money = 0;
  
   for(int i =0;i<n;i++){
    if(i < j){
        long diff = arr[i][1] - current;
        if(diff >= 1){
            while(j>=i && diff > 0){
                long reducer = Math.min(arr[j][0],diff);
                money += reducer*2;
                current += reducer;
                diff -= reducer;
                arr[j][0] -= reducer;
                
                if(arr[j][0] == 0)j--;
                else break;
            }
            money += arr[i][0];
            current += arr[i][0];
            if(j <= i)break;
           
        }
        else{
            money += (arr[i][0]);
            current += arr[i][0];
        }
    }
    else{
        if(current + arr[j][0] > arr[j][1]){
            money += ((arr[j][1] - current > 0)?arr[j][1] - current:0)*2 + (arr[j][0] - ((arr[j][1] - current > 0)?arr[j][1] - current:0));

        }
        else{
            money += arr[j][0]*2;
        }
        break;
    }
   }
   println(money);

}











public static int[] bringSame(int u,int v ,int parent[][],int[]depth){
    if(depth[u] < depth[v]){
        int temp = u;
        u = v;
        v = temp;
    }
    int k = depth[u] - depth[v];
    for(int i = 0;i<=18;i++){
        if((k & (1<<i)) != 0){
            u = parent[u][i];
        }
    }
    return new int[]{u,v};
}
public static void findDepth(List<List<Integer>>list,int cur,int parent,int[]depth,int[][]p){
    List<Integer>temp = list.get(cur);
    p[cur][0] = parent;
    for(int i = 0;i<temp.size();i++){
        int next = temp.get(i);
        if(next != parent){
            depth[next] = depth[cur]+1;
            findDepth(list,next,cur,depth,p);
        }
    }

}
public static int lca(int u, int v,int[][]parent){
    if(u == v)return u;
    for(int i = 18;i>=0;i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}






public static void plus(int node,int low,int high,int tlow,int thigh,int[]tree){
    if(low >= tlow && high <= thigh){
        tree[node]++;
        return;
    }
    if(high < tlow || low > thigh)return;
    int mid = (low + high)/2;
    plus(node*2,low,mid,tlow,thigh,tree);
    plus(node*2 + 1 , mid + 1, high,tlow, thigh,tree);
}

public static boolean allEqual(int[]arr,int x){
    for(int i = 0;i<arr.length;i++){
        if(arr[i] != x)return false;
    }
    return true;
}
public static long helper(StringBuilder sb){
return Long.parseLong(sb.toString());

}
public static int min(int node,int low,int high,int tlow,int thigh,int[][]tree){
    if(low >= tlow&& high <= thigh)return tree[node][0];
    if(high < tlow || low > thigh)return Integer.MAX_VALUE;
    int mid = (low + high)/2;
    

    return Math.min(min(node*2,low,mid,tlow,thigh,tree) ,min(node*2+1,mid+1,high,tlow,thigh,tree));

}

public static int max(int node,int low,int high,int tlow,int thigh,int[][]tree){
    if(low >= tlow && high <= thigh)return tree[node][1];
    if(high < tlow || low > thigh)return Integer.MIN_VALUE;
    int mid = (low + high)/2;
    return Math.max(max(node*2,low,mid,tlow,thigh,tree) ,max(node*2+1,mid+1,high,tlow,thigh,tree));

}







    







public static long[] help(List<List<Integer>>list,int[][]range,int cur){
    List<Integer>temp = list.get(cur);
    if(temp.size() == 0)return new long[]{range[cur][1],1};
    long sum = 0;
    long count = 0;
    for(int i = 0;i<temp.size();i++){
        long []arr = help(list,range,temp.get(i));
        sum += arr[0];
        count += arr[1];
        
    }
    if(sum < range[cur][0]){
        count++;
        sum = range[cur][1];
    }
    return new long[]{sum,count};
}
public static long findSum(int node,int low, int high,int tlow,int thigh,long[]tree,long mod){
    if(low >= tlow && high <= thigh)return tree[node]%mod;
    if(low > thigh || high < tlow)return 0;
    int mid = (low + high)/2;
    return((findSum(node*2,low,mid,tlow,thigh,tree,mod) % mod)  + (findSum(node*2+1,mid+1,high,tlow,thigh,tree,mod)))%mod;
}
public static boolean allzero(long[]arr){
    for(int i =0 ;i<arr.length;i++){
        if(arr[i]!=0)return false;

    }
    return true;
}
public static long count(long[][]dp,int i,int[]arr,int drank,long sum){
    if(i == arr.length)return 0;
    if(dp[i][drank]!=-1 && arr[i]+sum >=0)return dp[i][drank];
    if(sum + arr[i] >= 0){
        long count1 = 1 + count(dp,i+1,arr,drank+1,sum+arr[i]);
        long count2 = count(dp,i+1,arr,drank,sum);
        return  dp[i][drank] = Math.max(count1,count2);
    }
return  dp[i][drank] = count(dp,i+1,arr,drank,sum);

}

public static void help(int[]arr,char[]signs,int l,int r){
    if( l < r){
        int mid = (l+r)/2;
        help(arr,signs,l,mid);
        help(arr,signs,mid+1,r);
        merge(arr,signs,l,mid,r);
    }
}
public static void merge(int[]arr,char[]signs,int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int[]a = new int[n1];
    int []b = new int[n2];
    char[]asigns = new char[n1];
    char[]bsigns = new char[n2];

    for(int i = 0;i<n1;i++){
        a[i] = arr[i+l];
        asigns[i] = signs[i+l];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[i+mid+1];
        bsigns[i] = signs[i+mid+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    boolean opp = false;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            if(opp){
                if(asigns[i] == 'R'){
                    signs[k] = 'L';
                }
                else{
                    signs[k] = 'R';
                }
            }
            else{
                signs[k] = asigns[i];
            }
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            int times = n1 - i;
            if(times%2 == 1){
                if(bsigns[j] == 'R'){
                    signs[k] = 'L';
                }
                else{
                    signs[k] = 'R';
                }
            }
            else{
                signs[k] = bsigns[j];
            }
            j++;
            opp = !opp;
            k++;
            
        }
    }
    while(i<n1){
        arr[k] = a[i];
        if(opp){
        if(asigns[i] == 'R'){
            signs[k] = 'L';
        }
        else{
            signs[k] = 'R';
        }
        }
        else{
            signs[k] = asigns[i];
        }
    i++;
    k++;
    }
    while(j<n2){
        arr[k] = b[j];
        
        signs[k] = bsigns[j];
        j++;
        k++;
    }

}









public static long binaryExpo(long base,long expo){
    if(expo == 0)return 1;
    long val;
    if(expo%2 == 1){
    val  = (binaryExpo(base, expo-1)*base)%mod;

    }
    else{
        val = binaryExpo(base, expo/2);
        val  = (val*val)%mod;
    }
    return (val%mod);
}



public static boolean isSorted(int[]arr){
    for(int i =1;i<arr.length;i++){
        if(arr[i] < arr[i-1]){
            return false;
        }

    }
    return true;
}









    

    public static boolean hasCycle(int[]indegree,List<List<Integer>>list,int n,List<Integer>topo){
        Queue<Integer>q  = new LinkedList<>();
        for(int i =1;i<indegree.length;i++){
            if(indegree[i] == 0){
                q.add(i);
                topo.add(i);
            }
        }
        while(!q.isEmpty()){
            int cur = q.poll();
        
            List<Integer>l = list.get(cur);
            for(int i = 0;i<l.size();i++){
                indegree[l.get(i)]--;
                if(indegree[l.get(i)] == 0){
                    q.add(l.get(i));
                    topo.add(l.get(i));
                }
            }
        }
    if(topo.size() == n)return false;
        return true;
    }




    

public static int find(int val,int[]parent){
    if(val == parent[val])return val;
    return parent[val] = find(parent[val],parent);
}




public static void union(int[]rank,int[]parent,int u,int v){
    int a = find(u,parent);
    int b= find(v,parent);
    if(a == b)return;
    if(rank[a] == rank[b]){
        parent[b] = a;
        rank[a]++;
    }
    else{
        if(rank[a] > rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }
}


public static int findN(int n){
    int num = 1;
    while(num < n){
        num *=2;
    }
    return num;
}








public static void  print(String s ){
    System.out.print(s);
}
public static void  print(int num ){
    System.out.print(num);
}
public static void  print(long num ){
    System.out.print(num);
}
public static void println(String s){
    System.out.println(s);
}
public static void println(int num){
    System.out.println(num);
}
public static void println(long num){
    System.out.println(num);
}
public static void println(){
    System.out.println();
}

public static int Int(String s){
    return Integer.parseInt(s);
}
public static long Long(String s){
    return Long.parseLong(s);
}
public static String[] nextStringArray()throws IOException{
    return  bf.readLine().split(" ");
}


public static String nextString()throws IOException{
    return bf.readLine();
}

public static long[] nextLongArray(int n)throws IOException{
    String[]str = bf.readLine().split(" ");
    long[]arr = new long[n];
    for(int i =0;i<n;i++){
        arr[i] = Long.parseLong(str[i]);
    }
    return arr;
}
public static int[][] newIntMatrix(int r,int c)throws IOException{
    int[][]arr = new int[r][c];
    for(int i =0;i<r;i++){
        String[]str = bf.readLine().split(" ");
        for(int j =0;j<c;j++){
            arr[i][j] = Integer.parseInt(str[j]);
        }
        }
        return arr;
}

public static long[][] newLongMatrix(int r,int c)throws IOException{
    long[][]arr = new long[r][c];
    for(int i =0;i<r;i++){
        String[]str = bf.readLine().split(" ");
        for(int j =0;j<c;j++){
            arr[i][j] = Long.parseLong(str[j]);
        }
        }
        return arr;
}

static class pair{
    int one;
    int two;
    pair(int one,int two){
        this.one = one ;
        this.two =two;
    }
}
public static long gcd(long a,long b){
    if(b == 0)return a;
    return gcd(b,a%b);
}


public static long lcm(long a,long b){
    return (a*b)/(gcd(a,b));
}
public static boolean isPalindrome(String s){
    int i = 0;
    int j = s.length()-1;
    while(i<=j){
        if(s.charAt(i) != s.charAt(j)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}



public static void sort(int[]arr,int l,int r){
    if(l < r){
        int mid  = (l+r)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,r);
        smallerNumberAfterSelf(arr, l, mid, r);
    }
}
public static void smallerNumberAfterSelf(int[]arr,int l,int mid,int r){
    int n1 = mid - l +1;
    int n2 = r - mid;
    int []a = new int[n1];
    int[]b = new int[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i =0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }
    int i = 0;
    int j =0;
    int k = l;
    while(i<n1 && j < n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }

    }
    while(i<n1){
        arr[k++] = a[i++];
    }
    while(j<n2){
        arr[k++] = b[j++];
    }
    
    
    
}
public static String next(){
    while (st == null || !st.hasMoreElements()) {
        try {
            st = new StringTokenizer(bf.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    return st.nextToken();
}
static int nextInt() {
    return Integer.parseInt(next());
}

static long nextLong() {
    return Long.parseLong(next());
}

static double nextDouble() {
    return Double.parseDouble(next());
}

static String nextLine(){
    String str = "";
try {
str = bf.readLine();
} catch (IOException e) {
e.printStackTrace();
}
return str;
}

}


























































