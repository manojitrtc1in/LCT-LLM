import java.util.*;
import java.util.concurrent.TimeUnit;
import java.io.*;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
public class E_Yet_Another_Array_Counting_Problem{
    static long mod = (long)1e9+7;
    static int m;
    public static int solve(int l,int r,SegmentTree segment){
        if (l>r)return -1;

        int mid = segment.getRangeValue(l, r);
        int p1 = solve(l,mid-1,segment);
        int p2 = solve(mid+1,r,segment);
        for(int i=1;i<=m;i++){
            if(p1!=-1&&i==1)dp[mid][i]=0;
            else dp[mid][i]= ((p1>=0? sum[p1][i-1]:1l)%mod*(p2>=0?sum[p2][i]:1l)%mod)%mod;
            sum[mid][i] = (sum[mid][i-1]%mod+dp[mid][i]%mod)%mod;
        }
       

        return mid;
    }
    static long dp[][];
    static long sum[][];
   
    public static void main(String args[])throws IOException, ParseException{
       Scanner sc=new Scanner(System.in);
       int t=sc.nextInt();
       while(t-->0){
        int n= sc.nextInt();
         m = sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]= sc.nextInt();
        }
        SegmentTree segment = new SegmentTree(a,n);
        

        

        

        

        

       sum= new long[n+1][m+1];
       dp = new long[n+1][m+1];
       solve(0,n-1,segment);
      

      

       System.out.println(sum[segment.getRangeValue(0,n-1)][m]);
       }
       
    }

    public static void print(long[][] data,String text){
        System.out.println(text);
        for(int i=0;i<data.length;i++){
            for(int j=0;j<data[i].length;j++){
                System.out.print(data[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("*****End");
    }
    public static <K,V> Map<K,V> getLimitedSizedCache(int size){
		
		if(size==0){
			return (LinkedHashMap<K, V>) Collections.synchronizedMap(new LinkedHashMap<K, V>());
		}
		
		Map<K, V> linkedHashMap =  Collections.synchronizedMap(new LinkedHashMap<K, V>() {
			protected boolean removeEldestEntry(Map.Entry<K, V> eldest)
			{
				return size() > size;
			}
		});
		return linkedHashMap;
	}
}

class BinarySearch<T extends Comparable<T>> {
     T ele[];
     int n;
    public BinarySearch(T ele[],int n){
        this.ele=(T[]) ele;
        Arrays.sort(this.ele);
        this.n=n;
    }
    public int lower_bound(T x){
        

        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(x.compareTo(ele[mid])==0)return mid;
            if(x.compareTo(ele[mid])>0)left=mid+1;
            else right=mid-1;
        }
        if(left ==n)return -1;
        return left;
    }
    public int upper_bound(T x){
        

        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(x.compareTo(ele[mid])==0)return mid;
            if(x.compareTo(ele[mid])>0)left=mid+1;
            else right=mid-1;
        }
       
        return right;
    }
    
}
class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(
            new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[1000000]; 

        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') {
                if (cnt != 0) {
                    break;
                }
                else {
                    continue;
                }
            }
            buf[cnt++] = (byte)c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0,
                             BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}
class Data implements Comparable<Data>{
    int num;
    public Data(int num){
       this.num=num;
    }
    public int compareTo(Data o){
        return -o.num+num;
    }
    public String toString(){
        return num+" ";
    }
}
class Utils{
    public static String convertToBinaryString(long ele){
        StringBuffer res=new StringBuffer();
        while(ele>0){
            if(ele%2==0)res.append(0+"");
            else res.append(1+"");
            ele=ele/2;
        }
        return res.reverse().toString();
    }
    static long __gcd(long a, long b) 
    { 
      return b == 0? a:__gcd(b, a % b);    
    }
   
    

    static long LcmOfArray(long[] arr, int idx)
    {
   
      

      if (idx == arr.length - 1){
        return arr[idx];
      }
      long a = arr[idx];
      long b = LcmOfArray(arr, idx+1);
      return (a*b/__gcd(a,b)); 

    }
    
}
class FenwickTree{
    int bit[];
    int size;
    FenwickTree(int n){
        this.size=n;
        bit=new int[size];
    }
    public void modify(int index,int value){
        while(index<size){
            bit[index]+=value;
            index=(index|(index+1));
        }
    }
    public int get(int index){
        int ans=0;
        while(index>=0){
           ans+=bit[index];
           index=(index&(index+1))-1;
        }
        return ans;
    }
}
class PAndC{
    long c[][];
    long mod;
    public PAndC(int n,long mod){
        c=new long[n+1][n+1];
        this.mod=mod;
        build(n);
    }
    public void build(int n){
        for(int i=0;i<=n;i++){
            c[i][0]=1;
            c[i][i]=1;
            for(int j=1;j<i;j++){
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
            }
        }
    }
}
class Trie{
    int trie[][];
    int revind[];
    int root[];
    int tind,n;
    int sz[];
    int drev[];
    public Trie(){
        trie=new int[1000000][2];
        root=new int[600000];
        sz=new int[1000000];
        tind=0;
        n=0;
        revind=new int[1000000];
        drev=new int[20];
    }  
    public void add(int ele){
       

        n++;
        tind++;
        revind[tind]=n;
        root[n]=tind;
        addimpl(root[n-1],root[n],ele);
    }
    public void addimpl(int prev_root,int cur_root,int ele){
        for(int i=18;i>=0;i--){
            int edge=(ele&(1<<i))>0?1:0;
            trie[cur_root][1-edge]=trie[prev_root][1-edge];
            sz[cur_root]=sz[trie[cur_root][1-edge]];
            tind++;
            drev[i]=cur_root;
            revind[tind]=n;
            trie[cur_root][edge]=tind;
            cur_root=tind;
            prev_root=trie[prev_root][edge];
        }
        sz[cur_root]+=sz[prev_root]+1;
        for(int i=0;i<=18;i++){
            sz[drev[i]]=sz[trie[drev[i]][0]]+sz[trie[drev[i]][1]];
        }
    }
    public void findmaxxor(int l,int r,int x){

        int ans=0;
        int cur_root=root[r];
        for(int i=18;i>=0;i--){
             int edge=(x&(1<<i))>0?1:0;
             if(revind[trie[cur_root][1-edge]]>=l){
                 cur_root=trie[cur_root][1-edge];
                ans+=(1-edge)*(1<<i);
             }else{
                 cur_root=trie[cur_root][edge];
                 ans+=(edge)*(1<<i);
             }
        }
        System.out.println(ans);
    }
    public void findKthStatistic(int l,int r,int k){
        

        int curr=root[r];
        int curl=root[l-1];
        int ans=0;
        for(int i=18;i>=0;i--){
            for(int j=0;j<2;j++){
                if(sz[trie[curr][j]]-sz[trie[curl][j]]<k)
                 k-=sz[trie[curr][j]]-sz[trie[curl][j]];
                 else{
                     curr=trie[curr][j];
                     curl=trie[curl][j];
                     ans+=(j)*(1<<i);
                     break;
                 }
            }
        }
        System.out.println(ans);
        


    }
    public void findSmallest(int l,int r,int x){
      

        int curr=root[r];
        int curl=root[l-1];
        int countl=0,countr=0;
      

        for(int i=18;i>=0;i--){
            int edge=(x&(1<<i))>0?1:0;
           

            if(edge==1){
                countr+=sz[trie[curr][0]];
                countl+=sz[trie[curl][0]];
               
            }
            curr=trie[curr][edge];
            curl=trie[curl][edge];
        }
        countl+=sz[curl];
        countr+=sz[curr];
        System.out.println(countr-countl);

    }
}
class Printer{

    public <T> T printArray(T obj[] ,String details){
        System.out.println(details);
        for(int i=0;i<obj.length;i++)
        System.out.print(obj[i]+" ");
        System.out.println();
        return obj[0];
    }
    public <T> void print(T obj,String details){
        System.out.println(details+" "+obj);
    }
}
class Node{
    long weight;
    int vertex;
    public Node(int vertex,long weight){
        this.vertex=vertex;
        this.weight=weight;
    }
    public String toString(){
        return vertex+" "+weight;
    }
}
class Graph{
    int nv; 

    List<List<Node>> adj;
    boolean visited[];
    public Graph(int n){
        adj=new ArrayList<>();
        this.nv=n;
       

        for(int i=0;i<n;i++)
        adj.add(new ArrayList<Node>());
    }
    public void addEdge(int u,int v,long weight){
        u--;v--;
        Node first=new Node(v,weight);
        Node second=new Node(u,weight);
        adj.get(v).add(second);
        adj.get(u).add(first);
    }
    public void dfscheck(int u,long curweight){
         visited[u]=true;
         for(Node i:adj.get(u)){
             if(visited[i.vertex]==false&&(i.weight|curweight)==curweight)
              dfscheck(i.vertex,curweight);
         }
    }
    long maxweight;
    public void clear(){
        this.adj=null;
        this.nv=0;
    }
    public void solve() {
        maxweight=(1l<<32)-1;
        dfsutil(31);
        System.out.println(maxweight);
    }
    public void dfsutil(int msb){
        if(msb<0)return;
        maxweight-=(1l<<msb);
        visited=new boolean[nv];
        dfscheck(0,maxweight);
        for(int i=0;i<nv;i++)
        {
            if(visited[i]==false)
             {maxweight+=(1<<msb);
                break;}
        }
        dfsutil(msb-1);
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


}
class DSU{
    int []parent;
    int rank[];
    int n;
    public DSU(int n){
        this.n=n;
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        { parent[i]=i;
            rank[i]=1;
        }
    }
    public int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    public boolean union(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)return false;
        if(rank[pa]>rank[pb]){
            parent[pb]=pa;
            rank[pa]+=rank[pb];
        }
        else{
            parent[pa]=pb;
            rank[pb]+=rank[pa];
        }
        return true;
    }
}
class SegmentTree{
    int tree[];
    int data[];
    int tsize;
    int dsize;
    public SegmentTree(int data[],int n){
        this.tsize=4*n+1;
        this.dsize=n;
        this.data=data;
        this.tree=new int[tsize];
        build(0,n-1,0);
    }
    public SegmentTree(int n,int def){
        this.tsize=4*n+1;
        this.dsize=n;
        this.data=new int[n];
        for(int i=0;i<n;i++){
            data[i]=def;
        }
        this.tree=new int[tsize];
        build(0,n-1,0);
    }
    public void build(int l,int r,int treeindex){
        if(l==r){
            tree[treeindex]=l;
            return ;
        }
        int mid=(l+r)/2;
        build(l,mid,2*treeindex+1);
        build(mid+1,r,2*treeindex+2);
        

        if (data[tree[2*treeindex+1]] >= data[tree[2*treeindex+2]]){
            tree[treeindex]=tree[2*treeindex+1];
        }else{
            tree[treeindex]=tree[2*treeindex+2];
        }
    }
    public void updateOneImpl(int l,int r,int tind,int dind){
        if(l==r&&l==dind){
            tree[tind]=data[dind];
            return ;
        }
        if(dind>=l&&dind<=r){
             int mid=(l+r)/2;
            updateOneImpl(l,mid,2*tind+1,dind);
            updateOneImpl(mid+1,r,2*tind+2,dind);
       
           tree[tind]=Math.max(tree[2*tind+1],tree[2*tind+2]);
         }
      

    }
    

    

    

    

    public int getRangeValueImpl(int ql,int qr,int tl,int tr,int tind){
          if(tr<ql||qr<tl){
              return Integer.MIN_VALUE;
          }
          if(qr>=tr&&ql<=tl)return tree[tind];
          int mid=(tl+tr)/2;
          int l=getRangeValueImpl(ql, qr, tl, mid, 2*tind+1);
          int r=getRangeValueImpl(ql, qr, mid+1, tr, 2*tind+2);
          

          if(l>=0 && r>=0){
             return data[l]>=data[r]?l:r;
          }else if(l>=0){
            return l;
          }
          return r;
    }
    public int getRangeValue(int l,int r){
        int temp= getRangeValueImpl(l,r, 0, dsize-1, 0);
      

        return temp;
    }
    public void printData(){
        System.out.println("The Data After updation");
        for(int i=0;i<dsize;i++){
            System.out.print(data[i]+" ");
        }
        System.out.println();
        

        

        

        

        

    }

}