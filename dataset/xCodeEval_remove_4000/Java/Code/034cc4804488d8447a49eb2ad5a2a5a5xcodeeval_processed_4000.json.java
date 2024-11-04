import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class test{
    static int[] dx = {1,-1,0,0,1,1,-1,-1};
    static int[] dy = {0,0,1,-1,1,-1,1,-1};
    static long e97=1000000007;
    static HashMap<Integer,Integer>[] map=new HashMap[10003];
    static long[][][] vis=new long[10][10][20007];

    public static void main(String args[]) {
        Reader in = new Reader(System.in);
        int times=in.nextInt(),t=0;
        

        

        

        StringBuilder sb=new StringBuilder();
        l:for (int i = 0; i < times; i++) {
            char[] ch=in.next().trim().toCharArray();
            char c=in.next().charAt(0);
            if(ch.length%2==0) {
                sb.append("NO\n");
                continue;
            }
            for (int j = 0; j < ch.length; j++) {
                if(ch[j]==c&&j%2==0) {sb.append("YES\n");continue l;}
            }
            sb.append("NO\n");
        }
        System.out.println(sb);
        

        

        

    }
    private static long dfs(int num,int dep,int surplus){

        for (int s = 0; s < 10; s++) {

        }


        if(vis[num][surplus][dep]!=0) return vis[num][surplus][dep];
        if(dep==0){
            if(10-num>surplus) vis[num][surplus][0]=1;
            else vis[num][surplus][0]=2;
            return vis[num][surplus][0];
        }
        long res=dfs(num,dep-1,surplus);
        if(num==9) res+=dfs(1,dep-1,surplus)+dfs(0,dep-1,surplus);
        else res+= dfs(num+1,dep-1,surplus);
        if(res>e97) res%=e97;
        vis[num][surplus][dep]=res;
        return res;
    }
}

class Reader{
    private final static int BUF_SZ = 65536;
    BufferedReader in;
    StringTokenizer tokenizer;
    public Reader(InputStream in) {
        super();
        this.in = new BufferedReader(new InputStreamReader(in),BUF_SZ);
        tokenizer = new StringTokenizer("");
    }

    public String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(in.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
}
class vector{
    

    double x1,y1,x2,y2,x,y;
    public vector(int x1,int y1,int x2,int y2){
        this.x1=x1;
        this.y1=y1;
        this.x2=x2;
        this.y2=y2;
        x=x2-x1;
        y=y2-y1;
    }
    public vector(int x,int y){
        this.x=x;
        this.y=y;
    }
    public double CrossProduct(vector v){
        

        return x*v.y-y*v.x;
    }

}
class OtherTool{
    

    public static long[][] MatrixTranspose(long[][] matrix){
        long len=matrix.length,temp=0;
        if(len!=matrix[0].length) throw new IllegalArgumentException();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        return matrix;
    }
    

    public static long[][] matrixMul(long[][] matrix1,long[][] matrix2, long mod){
        int row = matrix1.length,column=matrix2[0].length,max= max(row,column),cnt1=0,cnt2=0;
        long[][] temp=new long[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                long res=0;
                for (int k = 0; k < max; k++) {
                    

                    

                    res+=matrix1[i][k]* matrix2[k][j];
                    res%=mod;
                    

                }
                temp[i][j]=res%mod;
            }
        }
        return temp;
    }
    

    public static long[][] matrixPow(long[][] matrix,long times, long mod){
        if(times==1) return matrix;
        int l= matrix.length;
        long[][] temp=new long[l][l];
        for (int i = 0; i < l; i++) {
            temp[i][i]=1;
        }
        if(times<1) return temp;
        while (times>0){
            if(times%2==1) temp=matrixMul(temp,matrix,mod);
            matrix=matrixMul(matrix,matrix,mod);
            times/=2;
        }
        return temp;
    }
    

    public static long fastPower(int source, long times, long mod){
        if(times==0||source==1) return 1;
        long i=1,cnt=1;
        while (times>0){
            if(times%2==1) i=(source*i)%mod;
            source*=source;
            source%=mod;
            times/=2;
        }
        return i;
    }
    

    public static void id10(int[] a, int[] b, int l, int r) {

        int mid = (l + r) / 2;
        if (l < r - 1) {
            id10(a, b, l, mid);
            id10(a, b, mid + 1, r);
        }
        if (l == r) return;
        int[] temp = new int[r - l + 1];
        int[] tempb = new int[r - l + 1];
        int i = l, j = mid + 1, t = 0;
        while (i < mid + 1 && j < r + 1) {
            if (a[i] <= a[j]) {
                temp[t] = a[i];
                tempb[t++] = b[i++];
            } else {
                temp[t] = a[j];
                tempb[t++] = b[j++];
            }
        }
        while (i < mid + 1) {
            temp[t] = a[i];
            tempb[t++] = b[i++];
        }
        while (j < r + 1) {
            temp[t] = a[j];
            tempb[t++] = b[j++];
        }
        for (int k = l; k < r + 1; k++) {
            a[k] = temp[k - l];
            b[k] = tempb[k - l];
        }
    }
    

    public static long lowerBound(long[] a,long target){
        long l=0,r=0,mid,half,len=a.length-1;
        for (long l1 : a) {
            r=max(l1,r);
        }
        len=r;
        while (len>0){
            half=len/2;
            mid=l+half;

            if(boundValue(a,mid)<=target) {
                l=mid+1;
                len=len-half-1;
            }else len=half;
        }
        if(target>boundValue(a,l)) return -1;
        return l;
    }
    private static long boundValue(long a[],long t){
        long res=0;
        for (long l : a) {
            if(l<t) res+=l;
            else res+=t;
        }
        return res;
    }
    

    public static String nextPermutation(String s){

        if(s.length()<=1) return null;
        StringBuilder sb=new StringBuilder(s);
        int i1=-1,i2=-1;
        for (int i = s.length()-1; i >=0 ; i--) if(s.charAt(i-1)<s.charAt(i)) {i1=i-1;break;}
        if(i1==-1) return null;
        for (int i = s.length()-1; i >=0 ; i--) if(s.charAt(i)>s.charAt(i1)) {i2=i;break;}
        char c=s.charAt(i1);
        sb.setCharAt(i1,s.charAt(i2));
        sb.setCharAt(i2,c);
        sb.replace(i1,s.length(),new StringBuilder(sb.substring(i1,s.length())).reverse().toString());
        return sb.toString();
    }
    

    public static int[] nextPermutation(int[] s){

        if(s.length<=1) return null;
        int i1=-1,i2=-1;
        for (int i = s.length-1; i >0 ; i--) if(s[i-1]<s[i]) {i1=i-1;break;}
        if(i1==-1) return null;
        for (int i = s.length-1; i >=0 ; i--) if(s[i]>s[i1]) {i2=i;break;}
        int t=s[i1];
        s[i1]=s[i2];
        s[i2]=t;
        t=s.length-i1-1;
        int[] temp=new int[t];
        for (int i = 0; i < t; i++) {
            temp[i]=s[s.length-i-1];
        }
        System.arraycopy(temp,0,s,i1+1,t);
        return s;
    }
    
    

    public static int[] primes(int range){

        double nums=0;
        if(range>1000000) nums=range*(Math.log(range)+0.01);
        else nums=80000;
        int[] res=new int[(int) nums];
        int t=1;
        boolean[] vis=new boolean[range];
        vis[1]=true;
        for (int i = 2; i < range; i++) {
            if(!vis[i]) res[t++]=i;
            for (int j = 1; j < t&&i*res[j]<range; j++) {
                vis[res[j]*i]=true;
                if(i%res[j]==0) break;
            }
        }
        return Arrays.copyOfRange(res,1,t);
    }
    

    public static int[] id20(String s1,String s2){
        

        


        int len= max(s1.length(),s2.length())+1,i=1,t=1;
        int[] res=new int[len];
        char[] c1=new char[len],c2=new char[len];
        for (char c:s1.toCharArray()) c1[i++]=c;
        i=1;
        for (char c:s2.toCharArray()) c2[i++]=c;
        int j=0;
        for (i = 0; i < len-1; i++) {
            while(j>0&&c1[i+1]!=c2[j+1]) j=res[j];
            if(c1[i+1]==c2[j+1]&&j<=i-1) j++;
            res[t++]=j;
        }
        return res;
    }
    private static int[] id20(String s){return id20(s,s);}
    

    public static int KMP(String source,String needle){
        if(needle.length()>source.length()) return -1;
        if(needle.length()==0) return 0;
        int[] next=id20(needle);
        int la=source.length(),lb=needle.length();
        char[] c1=("0"+source).toCharArray(),c2=("0"+needle).toCharArray();
        for (int i = 0,j=0; i < la; ) {
            while(j>0&&c1[i+1]!=c2[j+1]) j=next[j];
            while(j==0&&c1[i+1]!=c2[j+1]) {
                if(i==la-1) return -1;
                i++;
            }
            i++;j++;
            if(j==lb) return i-j;
        }
        return -1;
    }
    

    public static boolean id21(double a,double b){
        return (a>=0&&b>=0)||(a<=0&&b<=0);
    }
    

    public static double distance(double x1,double y1,double x2,double y2){
        return Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    

    public static node[] id19(node[] arr){
        node[]res=new node[arr.length];
        int p=0,top=2;
        for (int i = 1; i < arr.length; i++) {
            if(arr[i].y<arr[p].y) p=i;
            else if(arr[i].y==arr[p].y&&arr[i].x<arr[p].x) p=i;
        }
        node o=arr[p];
        Arrays.sort(arr, ( o1,  o2) -> {
            double d=new vector(o.x,o.y,o1.x,o1.y).
                    CrossProduct(new vector(o.x,o.y,o2.x,o2.y));
            if(d>0) return -1;
            else if(d<0) return 1;
            else return distance(o.x,o.y,o1.x,o1.y)<distance(o.x,o.y,o2.x,o2.y)?-1:1;
        });
        res[0]=arr[0];
        if(arr.length>1) res[1]=arr[1];
        if(arr.length>2) res[2]=arr[2];
        for (int i = 3; i < arr.length; i++) {
            while (new vector(res[top-1].x,res[top-1].y,res[top].x,res[top].y).
                    CrossProduct(new vector(res[top].x,res[top].y,arr[i].x,arr[i].y))<0&&top>1) top--;
            res[++top]=arr[i];
        }
        return Arrays.copyOf(res, min(top+1,arr.length));
    }
}
class node{
    public int father,son,top;

    public int depth,treeSize,value,id,id11;

    public int x,y;

    @Override
    public node clone(){
        node t=new node();
        t.father=father;t.son=son;t.top=top;t.depth=depth;t.treeSize=treeSize;t.value=value;t.id=id;
        t.x=x;t.y=y;
        return t;
    }
}
class ot extends OtherTool{}
class segTree{
    
    class Node extends node{}
    class segment{
        segment left,right;
        int l,r,lazy=0,length;
        long value=0;
        public segment(int a,int b){l=a;r=b;length=r-l+1;}
    }
    segment[] seg;
    node[] source;
    int size=0;
    public segTree(node[] source){
        size=source.length-1;
        seg=new segment[source.length];
        seg[0]=new segment(1,size);
        this.source=source;
        build(0,size-1,1);
    }
    private void build(int l,int r,int index){
        if(l==r) {
            segment s=new segment(l,r);
            s.value=source[l].value;
            seg[index]=s;
        }
        else {
            int mid=(l+r)/2;
            build(l,mid,index<<1);
            build(mid+1,r,index<<1|1);
            pushUp(index);
        }
    }
    private void pushUp(int a){
        seg[a].value= max(seg[a<<1].value,seg[a<<1|1].value);
        

    }
    private void pushDown(segment a){
        if(a.lazy!=0){
            a.left.value=a.lazy*a.left.length;
            a.right.value=a.lazy*a.right.length;
            
            a.left.lazy=a.right.lazy=a.lazy;
            a.lazy=0;
        }
    }
    public void rangeModify(segment a,int start,int end,int value){
        int l=a.l,r=a.r,mid=(l+r)/2;
        if(l>=start&&r<=end) {
            

            a.value=value;
            

            

            return;
        }else if(l>end||r<start||r==l) return;
        if(a.left==null) a.left=new segment(l,mid);
        if(a.right==null) a.right=new segment(mid+1,r);
        

        if(mid>=start) rangeModify(a.left,start,end,value);
        if(mid<=end) rangeModify(a.right,start,end,value);
        

    }
    public long rangeQuery(segment a, int start, int end){
        int l=a.l,r=a.r;
        if(l>=start&&r<=end) {
            return a.value;
        }else if(r<start||l>end) return 0;
        pushDown(a);
        return max(rangeQuery(a.left,start,end),rangeQuery(a.right,start,end));
    }
}


class id5{
    long[] tree1,tree2;
    int size;
    public id5(int size) {
        tree1=new long[100008];
        tree2=new long[100008];
        this.size=size;
    }
    public void add(int index,long value){
        long p=index*value;
        while (index<=size) {
            tree1[index]+=value;
            tree2[index]+=p;
            index+=index&-index;
        }
    }
    public void RangeAdd(int start,int end,int value){
        add(start,value);
        

        add(end+1,-value);
    }
    public long query(int start,int end){
        return sum(end)-sum(start-1);
    }
    public long sum(int i){
        long res=0,p=i;
        while (i>0) {
            res+=tree1[i]*(p+1)-tree2[i];
            i-=i&-i;
        }
        return res;
    }
}

class id3 extends id27{
    
    node[] s,dfsTree;
    int[] dfsId;
    public id3(int i) {
        super(i);
        s=new node[i];
        

    }
    public void addNode(int id,int value){
        node n=new node();
        n.id=id;
        n.id11=n.value=value;
        n.son=0;
        n.treeSize=1;
        s[id]=n;
    }
    public void addNode(int id){addNode(id,1);}

    public void start(){
        addNode(0);
        dfs1(1,0,1);
        dfs2(1,1);
    }
    private void dfs1(int nowId,int fId,int depth){
        s[nowId].father=fId;
        s[nowId].treeSize=1;
        s[nowId].depth=depth;
        if(nowId!=1) s[nowId].id11^=s[fId].id11;
        for (Node road : map[nowId]) {
            if(road.to==fId) continue;
            dfs1(road.to,nowId,depth+1);
            s[nowId].treeSize+=s[road.to].treeSize;
            if(s[road.to].treeSize>s[s[nowId].son].treeSize) s[nowId].son=road.to;
        }
    }
    private void dfs2(int nowId,int top){
        s[nowId].top=top;
        if(s[nowId].son!=0) dfs2(s[nowId].son,top);
        for (Node road : map[nowId]) {
            if(road.to!=s[nowId].son&&road.to!=s[nowId].father) dfs2(road.to,road.to);
        }
    }
    public int lca(int a,int b){
        node x=s[a],y=s[b];
        while (x.top!=y.top){
            if(x.depth>=y.depth) x=s[s[x.top].father];
            else y=s[s[y.top].father];
        }
        if(x.depth<y.depth) return x.id;
        else return y.id;
    }
}
class ShortestRoad extends id27 {
    public ShortestRoad(int i) {
        super(i);
    }
    double[][] f;
    public void id23(double[][] f) {
        this.f=f;
    }
    public int dijkstra(int start ,int end){
        int[] distance=new int[node.length],used=new int[node.length];
        PriorityQueue<Node> node=new PriorityQueue<Node>(Comparator.comparingInt(o -> o.value));
        Arrays.fill(distance,Integer.MAX_VALUE/2);
        node.add(new Node(start,0));
        distance[start]=0;
        while (!node.isEmpty()) {
            int city = node.poll().to;
            if (used[city] != 0) continue;
            used[city] = 1;
            ArrayList<Node> arr = map[city];
            if (arr.isEmpty()&&city!=end) return -1;
            for (Node n : arr) {
                int nowcity = n.to;
                if (distance[nowcity] > distance[city] + n.value) {
                    distance[nowcity] = distance[city] + n.value;
                    node.offer(new Node(nowcity, distance[nowcity]));
                }
            }
        }
        if(distance[end]!=Integer.MAX_VALUE/2) return distance[end];
        else return Integer.MAX_VALUE;

    }
    public void id8(int max) {
        for (int k = 0; k < max; k++)
            for (int i = 0; i < max; i++)
                if (f[i][k] != Integer.MAX_VALUE / 2)
                    for (int j = 0; j < max; j++) {
                        if (f[k][j] != Integer.MAX_VALUE / 2) {
                            f[i][j] = max(f[i][j], f[i][k] * f[k][j]);
                            

                        }
                    }
    }
    public double id25(int i,int j){
        return f[i][j];
    }
}
class id22 extends id27{
    ArrayList<id27.Node>[] reMap;
    boolean[] used1,used2;
    int[] stack,component;
    int stackPtr=0,componentNum=0;
    public id22(int i) {
        super(i);
        reMap=new ArrayList[i];
        for (int i1 = 0; i1 < map.length; i1++) reMap[i1]= new ArrayList<>();
        used1=new boolean[i];
        used2=new boolean[i];
        stack=new int[i];
    }
    @Override
    public void setRoad(int start, int next, int value){
        map[start].add(new Node(next,value));
        reMap[next].add(new Node(start,value));
    }
    public void getComponent(){
        for (int i = 0; i < size; i++) {
            if(!used1[i]) dfsStack(i);
        }
        component=new int[size];
        for (int i = stackPtr-1; i >= 0; i--) {
            if(!used2[stack[i]]) dfsResult(stack[i],i);
            componentNum++;
        }
    }
    public void dfsStack(int nowNode){
        

        if(!used1[nowNode]) used1[nowNode]=true;
        else return;
        for (Node n : reMap[nowNode]) {
            if(!used1[n.to]) dfsStack(n.to);
        }
        stack[stackPtr++]=nowNode;
    }
    public void dfsResult(int nowNode,int index){
        if(!used2[nowNode]) used2[nowNode]=true;
        else return;
        for (Node n : map[nowNode]) {
            if(!used2[n.to]) dfsResult(n.to,index);
        }
        component[nowNode]=index;
    }
    public int[] id13(){
        if(stackPtr==0) getComponent();
        int[] res=new int[stackPtr];
        int t=0;
        for (int i = 0; i < component.length; i++) res[component[i]]++;
        for (int re : res) {
            if(re!=0) res[t++]=re;
        }
        return Arrays.copyOf(res,t);
    }
}
class Pack {
    

    int[] weight, value, multiple;
    int nums;

    public Pack(int nums) {
        weight = new int[nums];
        value = new int[nums];
    }

    public Pack(int[] w, int[] v) {
        weight = w;
        value = v;
        nums = weight.length;
    }

    public Pack(int[] w, int[] v, int[] m) {
        weight = w;
        value = v;
        multiple = m;
        nums = weight.length;
    }

    public int id4(int volume) {
        

        

        

        int[] dp = new int[volume + 8],hash=new int[9003];
        for (int k = 0; k < nums; k++) {
            for (int i = volume; i > 0; i--) {
                hash[max(0,dp[i])]=1;
                if(i>=weight[k]) hash[max(0,dp[i - weight[k]] + value[k])]=1;
                if (i >= weight[k]) dp[i] = max(dp[i - weight[k]] + value[k], dp[i]);

            }
        }
        for (int i =1; i < hash.length; i++) {
            if(hash[i]==0) {System.out.println(i);break;}
        }
        return dp[volume];
    }

    public int CompletePack(int volume) {
        

        int[] dp = new int[volume + 1];
        for (int k = 0; k < nums; k++) {
            for (int i = weight[k]; i < volume + 1; i++) {
                if (i >= weight[k]) dp[i] = max(dp[i - weight[k]] + value[k], dp[i]);
            }
        }
        return dp[volume];
    }

    public int MultiplePack(int volume) {
        

        ArrayList<Integer> w = new ArrayList<>();
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < multiple.length; i++) {
            int k = multiple[i]&-multiple[i];
            while (true) {
                if (k <= multiple[i]) {
                    w.add(i, k * weight[i]);
                    v.add(i, k * value[i]);
                    multiple[i] -= k;
                    k *= 2;
                } else {
                    k = multiple[i];
                    if(k!=0) {
                        w.add(i, k * weight[i]);
                        v.add(i, k * value[i]);
                    }
                    break;
                }
            }
        }
        int[] w1 = new int[w.size()], v1 = new int[v.size()];
        for (int i = 0; i < w1.length; i++) {
            w1[i] = w.get(i);
            v1[i] = v.get(i);
        }
        weight = w1;
        value = v1;
        nums = weight.length;
        return id4(volume);
    }
}
class id7 {
    int[] parent, rank;
    int id16;

    public id7(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) parent[i] = i;
        Arrays.fill(rank, 1);
        id16 = size;
    }

    private int find(int a) {
        if (a > parent.length || a < 0) {
            throw new IllegalArgumentException("FindIndexOutOfBounds:" + a);
        }
        while (parent[a] != a) {
            

            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }

    public boolean isConnect(int a, int b) {
        return find(a) == find(b);
    }

    public int union(int a, int b) {
        

        int aroot = find(a);
        int broot = find(b);
        if (aroot == broot) return aroot;
        id16--;
        if (rank[aroot] > rank[broot]) {
            parent[broot] = aroot;
            return aroot;
        } else if (rank[aroot] < rank[broot]) {
            parent[aroot] = broot;
            return broot;
        } else {
            parent[broot] = aroot;
            rank[aroot]++;
            return aroot;
        }
    }
}
class id2 {
    HashMap<Integer,Integer> parent, rank;
    int id16;

    public id2(int size) {
        parent = new HashMap<>(size);
        rank = new HashMap<>(size);
        id16 = size;
    }
    public int add(int i){
        if(!parent.containsKey(i)) {
            parent.put(i,i+1);
            if(parent.containsKey(i+1)) union(i,i+1);
            return i;
        }else {
            int blank=find(i);
            parent.put(blank,blank+1);
            return blank;
        }

    }
    private int find(int a) {
        
        while (parent.containsKey(a)&&!parent.get(a).equals(a)) {
            

            if(parent.containsKey(parent.get(a)))
                parent.replace(a,parent.get(parent.get(a)));
            if(!parent.containsKey(a)) parent.put(a,a);
            a = parent.get(a);
        }
        

        return a;
    }

    public boolean isConnect(int a, int b) {
        return find(a) == find(b);
    }

    public int union(int a, int b) {
        

        int aroot = find(a);
        int broot = find(b);
        if (aroot == broot) return aroot;
        id16--;
        if (rank.get(aroot) > rank.get(broot)) {
            parent.replace(broot,aroot);
            return aroot;
        } else if (rank.get(aroot) < rank.get(broot)) {
            parent.replace(aroot,broot);
            return broot;
        } else {
            parent.replace(broot,aroot);
            rank.replace(aroot,rank.get(aroot+1));
            return aroot;
        }
    }
}
class Game{
    
}
class id27{
    class Node{
        int to,value;
        public Node(int to,int value) {this.to=to;this.value=value;}
    }
    ArrayList<Node>[] map;
    int[] node;
    int size;
    public id27(int i) {
        node = new int[i];
        map=new ArrayList[i];
        size=i;
        for (int i1 = 0; i1 < map.length; i1++) map[i1]= new ArrayList<>();
    }
    public void setRoad(int start, int next, int value){
        map[start].add(new Node(next,value));
    }
}
class GeneratingFunction{
    ArrayList<Double>[] formulaCoefficient;
    int[] id17,less,more;
    int nowIndex=0,size;
    boolean id6=false;
    public GeneratingFunction(int size){
        

        

        this.size=size;
        less=new int[size];
        more=new int[size];
        id17=new int[size];
    }
    public int setAdd(int a,int b,int c){
        id17[nowIndex]=a;
        less[nowIndex]=b;
        more[nowIndex]=c;
        return nowIndex++;
    }
    public void id18(int index,int value,int max){
        

        ArrayList<Double> now=new ArrayList<Double>(max);
        now.add(0,1.0);
        for (int i = 1; i < max; i++) {
            now.add(i,value*i*1.0);
        }
        formulaCoefficient[index]=now;
    }
    public double[] Generate(int ask){
        double[] a=new double[13],b=new double[13],fact=new double[12];
        for (int i = 0; i < 11; i++) {
            int k=1;
            for (int j = i; j >0 ; j--) {
                k*=j;
            }
            fact[i]=k;
        }
        for (int i = 0; i <= more[0]; i+=id17[0]) {
            a[i]=1.0/fact[i];
        }

        for (int i = 1; i <= size; i++) {
            if(id17[i]==0) break;
            

            
            for (int j = 0; j <= ask; j++) {
                

                for (int k = 0; k+j<=ask&&k <= more[i]; k+=id17[i]) {
                    b[j+k]+=a[j]/fact[k];
                }
            }
            a=Arrays.copyOfRange(b,0,b.length);
            Arrays.fill(b,0);
        }
        for (int i = 0; i <= ask; i++) {
            a[i]*=fact[i];
        }
        return a;
    }

    



    
    public void fftChange(Complex[] a){

    }
    
    
    public void id26(Complex[] a,int start,int end,int on){
        int n=end-start+1,m=n/2,mid=(start+end)/2;
        if(n<=1) return;
        Complex[] buffer=new Complex[n];
        for (int i = 0; i < m; i++) {
            buffer[i]=a[start+2*i];
            buffer[i+m]=a[start+2*i+1];
        }
        for (int i = 0; i < n; i++) a[start+i]=buffer[i];
        id26(a,start,mid,1);
        id26(a,mid+1,end,1);
        for (int i = 0; i < m; i++) {
            

            

            Complex x = Complex.omega(n, i * on);
            buffer[i] = a[i].plus(x.multiple(a[i + m]));
            buffer[i + m] = a[i].minus(x.multiple(a[i + m]));
        }
        if(on==-1){
            for (int i = 0; i < buffer.length; i++) {
                buffer[i]=buffer[i].scale(1D/a.length);
            }
        }
        for (int i = 0; i < n; i++) {
            a[start+i]=buffer[i];
        }
    }



    

    public static Complex[] fft(Complex[] x) {
        int N = x.length;

        

        if (N == 1) return new Complex[]{x[0]};

        

        if (N % 2 != 0) {
            throw new RuntimeException("N is not a power of 2");
        }

        

        Complex[] even = new Complex[N / 2];
        for (int k = 0; k < N / 2; k++) {
            even[k] = x[2 * k];
        }
        Complex[] q = fft(even);

        

        Complex[] odd = even;  

        for (int k = 0; k < N / 2; k++) {
            odd[k] = x[2 * k + 1];
        }
        Complex[] r = fft(odd);

        

        Complex[] y = new Complex[N];
        for (int k = 0; k < N / 2; k++) {
            double kth = -2 * k * Math.PI / N;
            Complex wk = new Complex(Math.cos(kth), Math.sin(kth));
            y[k] = q[k].plus(wk.multiple(r[k]));
            y[k + N / 2] = q[k].minus(wk.multiple(r[k]));
        }
        return y;
    }
    public static Complex[] ifft(Complex[] x) {
        int N = x.length;
        Complex[] y = new Complex[N];

        

        for (int i = 0; i < N; i++) {
            y[i] = x[i].id12();
        }

        

        y = fft(y);

        

        for (int i = 0; i < N; i++) {
            y[i] = y[i].id12();
        }

        

        for (int i = 0; i < N; i++) {
            y[i] = y[i].scale(1.0 / N);
        }

        return y;

    }
    public static Complex[] id15(Complex[] x, Complex[] y) {

        

        

        if (x.length != y.length) { throw new RuntimeException("Dimensions don't agree"); }

        int N = x.length;

        

        Complex[] a = fft(x);
        Complex[] b = fft(y);

        

        Complex[] c = new Complex[N];
        for (int i = 0; i < N; i++) {
            c[i] = a[i].multiple(b[i]);
        }

        

        return ifft(c);
    }
    public static Complex[] convolve(Complex[] x, Complex[] y) {
        Complex ZERO = new Complex(0, 0);

        Complex[] a = new Complex[2*x.length];

        for (int i = 0;        i <   x.length; i++) a[i] = x[i];
        for (int i = x.length; i < 2*x.length; i++) a[i] = ZERO;

        Complex[] b = new Complex[2*y.length];
        for (int i = 0;        i <   y.length; i++) b[i] = y[i];
        for (int i = y.length; i < 2*y.length; i++) b[i] = ZERO;

        return id15(a, b);
    }

}


class Complex {
    

    private final double re; 

    private final double im; 


    

    public Complex(double real, double imag) {
        re = real;
        im = imag;
    }
    

    public static Complex omega(int n,int k){
        return new Complex(Math.cos(2*Math.PI*k/n),Math.sin(2*Math.PI*k/n));
    }
    

    @Override
    public String toString() {
        if (im == 0)
            return re + "";
        if (re == 0)
            return im + "i";
        if (im < 0)
            return re + " - " + (-im) + "i";
        return re + " + " + im + "i";
    }

    

    public double abs() {
        return Math.hypot(re, im);
    }

    

    public double phase() {
        return Math.atan2(im, re);
    }

    

    public Complex plus(Complex b) {
        Complex a = this; 

        double real = a.re + b.re;
        double imag = a.im + b.im;
        return new Complex(real, imag);
    }

    

    public Complex minus(Complex b) {
        Complex a = this;
        double real = a.re - b.re;
        double imag = a.im - b.im;
        return new Complex(real, imag);
    }

    

    public Complex multiple(Complex b) {
        Complex a = this;
        double real = a.re * b.re - a.im * b.im;
        double imag = a.re * b.im + a.im * b.re;
        return new Complex(real, imag);
    }

    

    

    public Complex multiple(double alpha) {
        return new Complex(alpha * re, alpha * im);
    }

    

    public Complex scale(double alpha) {
        return new Complex(alpha * re, alpha * im);
    }

    

    public Complex id12() {
        return new Complex(re, -im);
    }

    

    public Complex id24() {
        double scale = re * re + im * im;
        return new Complex(re / scale, -im / scale);
    }

    

    public double re() {
        return re;
    }

    public double im() {
        return im;
    }

    

    public Complex divides(Complex b) {
        Complex a = this;
        return a.multiple(b.id24());
    }

    

    

    public Complex exp() {
        return new Complex(Math.exp(re) * Math.cos(im), Math.exp(re) * Math.sin(im));
    }

    

    public Complex sin() {
        return new Complex(Math.sin(re) * Math.cosh(im), Math.cos(re) * Math.sinh(im));
    }

    

    public Complex cos() {
        return new Complex(Math.cos(re) * Math.cosh(im), -Math.sin(re) * Math.sinh(im));
    }

    

    public Complex tan() {
        return sin().divides(cos());
    }

    

    public static Complex plus(Complex a, Complex b) {
        double real = a.re + b.re;
        double imag = a.im + b.im;
        Complex sum = new Complex(real, imag);
        return sum;
    }

    

    @Override
    public boolean equals(Object x) {
        if (x == null)
            return false;
        if (this.getClass() != x.getClass())
            return false;
        Complex that = (Complex) x;
        return (this.re == that.re) && (this.im == that.im);
    }

    

    @Override
    public int hashCode() {
        return Objects.hash(re, im);
    }
}


class Fraction {

    private long Numerator; 

    private long Denominator; 


    public Fraction(long numerator, long denominator) {
        this.Numerator = numerator;
        if (denominator == 0) {
            throw new ArithmeticException("分母不能为零");
        } else {
            this.Denominator = denominator;
        }
        change();
    }

    public Fraction() {
        this(0, 1);
    }

    public long id1() {
        return Numerator;
    }

    public void id0(long numerator) {
        Numerator = numerator;
    }

    public long id9() {
        return Denominator;
    }

    public void id14(long denominator) {
        Denominator = denominator;
    }

    private Fraction change() {
        long gcd = this.gcd(this.Numerator, this.Denominator);
        this.Numerator /= gcd;
        this.Denominator /= gcd;
        return this;
    }

    
    private long gcd(long a, long b) {
        long mod = a % b;
        if (mod == 0) {
            return b;
        } else {
            return gcd(b, mod);
        }
    }

    
    public Fraction add(Fraction second) {
        return new Fraction(this.Numerator * second.Denominator + second.Numerator * this.Denominator,
                this.Denominator * second.Denominator);
    }

    public Fraction sub(Fraction second) {
        return new Fraction(this.Numerator * second.Denominator - second.Numerator * this.Denominator,
                this.Denominator * second.Denominator);
    }

    public Fraction multiply(Fraction second) {
        return new Fraction(this.Numerator*second.Numerator,
                this.Denominator * second.Denominator);
    }

    public Fraction devide(Fraction second) {
        return new Fraction(this.Numerator*second.Denominator,
                this.Denominator * second.Numerator);
    }

    @Override
    public String toString() {
        return String.format("{%d/%d}", this.Numerator, this.Denominator);
    }
}
