import java.io.File;import java.io.FileInputStream;import java.io.FileNotFoundException;
import java.io.IOException;import java.io.InputStream;import java.io.PrintStream;
import java.io.PrintWriter;import java.security.AccessControlException;import java.util.Arrays;
import java.util.Collection;import java.util.Comparator;import java.util.List;import java.util.Map;
import java.util.Objects;import java.util.TreeMap;import java.util.function.BiConsumer;
import java.util.function.Consumer;import java.util.function.Function;import java.util.function.Supplier;
import java.util.stream.Collectors;import java.util.stream.IntStream;import java.util.stream.LongStream;
import java.util.stream.Stream;public class _D {static public void main(final String[] args) 
throws IOException{D._main(args);}
static private class D extends Solver{public D(){}static private class H{int end;
int max;int min;int l;int r;public String toString(){return"{"+l+","+r+","+end+","
+min+","+max+"}";}public Object clone(){H h=new H();h.l=l;h.r=r;h.max=max;h.min=
min;h.end=end;return h;}}int answer_num=0;@Override public void solve()throws IOException
{int n=sc.nextInt();int m=sc.nextInt();sc.nextLine();String s=sc.nextLine().trim();
Updater<H>upd=(t,s1,s2,ty)->{t.l=s1.l;t.r=s2.r;t.end=s1.end+s2.end;t.min=Math.min(s1.min,
s2.min+s1.end);t.max=Math.max(s1.max,s2.max+s1.end);};SegTree<H>st=new SegTree<>(()
->new H(),upd);st.init(IntStream.range(0,n).mapToObj(i->{H h=new H();h.l=h.r=i+1;
h.end=s.charAt(i)=='-'?-1:1;h.min=Math.min(0,h.end);h.max=Math.max(0,h.end);return 
h;}).toArray(i->new H[i]));H tmp=new H();H res=null;for(int _if0=0;_if0<m;_if0++)
{int l=sc.nextInt();int r=sc.nextInt();sc.nextLine();int sel=0;l--;if(l==0){if(r
<n){sel=1;res=st.get(r,n);}else{sel=2;tmp.min=0;tmp.max=0;res=tmp;}}else if(r==n)
{sel=3;res=st.get(0,l);}else{sel=4;H s1=(H)st.get(0,l).clone();H s2=st.get(r,n);
upd.update(tmp,s1,s2,QueryType.GET);res=tmp;}answer_num++;pw.println((res.max-res.min
+1));}}static public void _main(String[]args)throws IOException{new D().run();}}static private class 
MyScanner{private StringBuilder cache=new StringBuilder();int cache_pos=0;private 
int first_linebreak=-1;private int second_linebreak=-1;private StringBuilder sb=
new StringBuilder();private InputStream is=null;public MyScanner(final InputStream 
is){this.is=is;}private String charToString(final int c){return String.format("'%s'",
c=='\n'?"\\n":(c=='\r'?"\\r":String.valueOf((char)c)));}public int get(){int res
=-1;if(cache_pos<cache.length()){res=cache.charAt(cache_pos);cache_pos++;if(cache_pos
==cache.length()){cache.delete(0,cache_pos);cache_pos=0;}}else{try{res=is.read();
}catch(IOException ex){throw new RuntimeException(ex);}}return res;}private void 
unget(final int c){if(cache_pos==0){cache.insert(0,(char)c);}else{cache_pos--;}}
public String nextLine(){sb.delete(0,sb.length());int c;boolean done=false;boolean 
end=false;while((c=get())!=-1){if(check_linebreak(c)){done=true;if(c==first_linebreak)
{if(!end){end=true;}else{cache.append((char)c);break;}}else if(second_linebreak!=
-1 && c==second_linebreak){break;}}if(end && c!=first_linebreak && c!=second_linebreak)
{cache.append((char)c);break;}if(!done){sb.append((char)c);}}return sb.toString();
}private boolean check_linebreak(int c){if(c=='\n'|| c=='\r'){if(first_linebreak
==-1){first_linebreak=c;}else if(c!=first_linebreak && second_linebreak==-1){second_linebreak
=c;}return true;}return false;}public int nextInt(){int sign=0;boolean done=false;
boolean started=false;int res=0;int c;while((c=get())!=-1){check_linebreak(c);if
(sign==0 && c=='-'){started=true;sign=-1;}else if(c>='0'&& c<='9'){if(sign==0){sign
=1;}started=true;res*=10;res+=c-'0';done=true;}else if(!done){if(started){unget(c);
if(sign==-1){unget('-');}break;}}else{unget(c);break;}}if(done){return res*sign;
}throw new RuntimeException();}public long nextLong(){int sign=0;boolean done=false;
boolean started=false;long res=0;int c;while((c=get())!=-1){check_linebreak(c);if
(sign==0 && c=='-'){started=true;sign=-1;}else if(c>='0'&& c<='9'){if(sign==0){sign
=1;}started=true;res*=10;res+=c-'0';done=true;}else if(!done){if(started){unget(c);
if(sign==-1){unget('-');}break;}}else{unget(c);break;}}if(done){return res*sign;
}throw new RuntimeException();}public boolean hasNext(){boolean res=false;int c;
while((c=get())!=-1){if(!check_linebreak(c)&& c!=' '&& c!='\t'){res=true;unget(c);
break;}}return res;}public String next(){sb.delete(0,sb.length());boolean started
=false;int c;while((c=get())!=-1){if(check_linebreak(c)|| c==' '|| c=='\t'){if(started)
{unget(c);break;}}else{started=true;sb.append((char)c);}}return sb.toString();}public 
int nextChar(){return get();}public boolean eof(){int c=get();boolean res=false;
if(c!=-1){unget(c);}else{res=true;}return res;}}static private class Pair<K,V>{private 
K k;private V v;public Pair(final K t,final V u){this.k=t;this.v=u;}public K getKey()
{return k;}public V getValue(){return v;}}static private abstract class Solver{protected 
String nameIn=null;protected String nameOut=null;protected boolean singleTest=false;
protected boolean preprocessDebug=false;protected boolean doNotPreprocess=false;
protected PrintStream debugPrintStream=null;protected MyScanner sc=null;protected 
PrintWriter pw=null;final static String SPACE=" ";final static String SPACES="\\s+";
private int current_test=0;private int count_tests=0;protected int currentTest()
{return current_test;}protected int countTests(){return count_tests;}private void 
process()throws IOException{if(!singleTest){count_tests=lineToIntArray()[0];for(current_test
=1;current_test<=count_tests;current_test++){solve();pw.flush();}}else{count_tests
=1;current_test=1;solve();pw.flush();}}abstract protected void solve()throws IOException;
protected String[]lineToArray()throws IOException{return sc.nextLine().trim().split(SPACES);
}protected int[]lineToCharArray()throws IOException{return sc.nextLine().chars().toArray();
}protected int[]lineToIntArray()throws IOException{return Arrays.stream(lineToArray()).mapToInt(Integer::valueOf).toArray();
}protected long[]lineToLongArray()throws IOException{return Arrays.stream(lineToArray()).mapToLong(Long::valueOf).toArray();
}protected void run()throws IOException{boolean done=false;try{if(nameIn!=null && 
new File(nameIn).exists()){try(FileInputStream fis=new FileInputStream(nameIn);PrintWriter 
pw0=select_output();){done=true;sc=new MyScanner(fis);pw=pw0;process();}}}catch(IOException 
ex){}catch(AccessControlException ex){}if(!done){try(PrintWriter pw0=select_output();
){sc=new MyScanner(System.in);pw=pw0;process();}}}private PrintWriter select_output()
throws FileNotFoundException{if(nameOut!=null){return new PrintWriter(nameOut);}
return new PrintWriter(System.out);}public static Map<Integer,List<Integer>>mapi(final 
int[]a){return IntStream.range(0,a.length).collect(()->new TreeMap<Integer,List<Integer>>(),
(res,i)->{if(!res.containsKey(a[i])){res.put(a[i],Stream.of(i).collect(Collectors.toList()));
}else{res.get(a[i]).add(i);}},Map::putAll);}public static Map<Long,List<Integer>>
mapi(final long[]a){return IntStream.range(0,a.length).collect(()->new TreeMap<Long,
List<Integer>>(),(res,i)->{if(!res.containsKey(a[i])){res.put(a[i],Stream.of(i).collect(Collectors.toList()));
}else{res.get(a[i]).add(i);}},Map::putAll);}public static<T>Map<T,List<Integer>>
mapi(final T[]a){return IntStream.range(0,a.length).collect(()->new TreeMap<T,List<Integer>>(),
(res,i)->{if(!res.containsKey(a[i])){res.put(a[i],Stream.of(i).collect(Collectors.toList()));
}else{res.get(a[i]).add(i);}},Map::putAll);}public static<T>Map<T,List<Integer>>
mapi(final T[]a,Comparator<T>cmp){return IntStream.range(0,a.length).collect(()->
new TreeMap<T,List<Integer>>(cmp),(res,i)->{if(!res.containsKey(a[i])){res.put(a[i],
Stream.of(i).collect(Collectors.toList()));}else{res.get(a[i]).add(i);}},Map::putAll
);}public static Map<Integer,List<Integer>>mapi(final IntStream a){int[]i=new int[]{0};
return a.collect(()->new TreeMap<Integer,List<Integer>>(),(res,v)->{if(!res.containsKey(v))
{res.put(v,Stream.of(i[0]).collect(Collectors.toList()));}else{res.get(v).add(i[0]);
}i[0]++;},Map::putAll);}public static Map<Long,List<Integer>>mapi(final LongStream 
a){int[]i=new int[]{0};return a.collect(()->new TreeMap<Long,List<Integer>>(),(res,
v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}i[0]++;},Map::putAll);}public static<T>Map<T,List<Integer>>
mapi(final Stream<T>a,Comparator<T>cmp){int[]i=new int[]{0};return a.collect(()->
new TreeMap<T,List<Integer>>(cmp),(res,v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}},Map::putAll);}public static<T>Map<T,List<Integer>>
mapi(final Stream<T>a){int[]i=new int[]{0};return a.collect(()->new TreeMap<T,List<Integer>>(),
(res,v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}},Map::putAll);}public static List<int[]>listi(final 
int[]a){return IntStream.range(0,a.length).mapToObj(i->new int[]{a[i],i}).collect(Collectors.toList());
}public static List<long[]>listi(final long[]a){return IntStream.range(0,a.length).mapToObj(i
->new long[]{a[i],i}).collect(Collectors.toList());}public static<T>List<Pair<T,
Integer>>listi(final T[]a){return IntStream.range(0,a.length).mapToObj(i->new Pair<T,
Integer>(a[i],i)).collect(Collectors.toList());}public static List<int[]>listi(final 
IntStream a){int[]i=new int[]{0};return a.mapToObj(v->new int[]{v,i[0]++}).collect(Collectors.toList());
}public static List<long[]>listi(final LongStream a){int[]i=new int[]{0};return 
a.mapToObj(v->new long[]{v,i[0]++}).collect(Collectors.toList());}public static<T>
List<Pair<T,Integer>>listi(final Stream<T>a){int[]i=new int[]{0};return a.map(v->
new Pair<T,Integer>(v,i[0]++)).collect(Collectors.toList());}public static<T>List<Pair<T,
Integer>>listi(final Collection<T>a){int[]i=new int[]{0};return a.stream().map(v
->new Pair<T,Integer>(v,i[0]++)).collect(Collectors.toList());}public static String 
join(final int[]a){return Arrays.stream(a).mapToObj(Integer::toString).collect(Collectors.joining(SPACE));
}public static String join(final long[]a){return Arrays.stream(a).mapToObj(Long::toString).collect(Collectors.joining(SPACE));
}public static<T>String join(final T[]a){return Arrays.stream(a).map(v->Objects.toString(v)).collect(Collectors.joining(SPACE));
}public static<T>String join(final T[]a,final Function<T,String>toString){return 
Arrays.stream(a).map(v->toString.apply(v)).collect(Collectors.joining(SPACE));}public 
static<T>String join(final Collection<T>a){return a.stream().map(v->Objects.toString(v)).collect(Collectors.joining(SPACE));
}public static<T>String join(final Collection<T>a,final Function<T,String>toString)
{return a.stream().map(v->toString.apply(v)).collect(Collectors.joining(SPACE));
}public static<T>String join(final Stream<T>a){return a.map(v->Objects.toString(v)).collect(Collectors.joining(SPACE));
}public static<T>String join(final Stream<T>a,final Function<T,String>toString){
return a.map(v->toString.apply(v)).collect(Collectors.joining(SPACE));}public static
<T>String join(final IntStream a){return a.mapToObj(Integer::toString).collect(Collectors.joining(SPACE));
}public static<T>String join(final LongStream a){return a.mapToObj(Long::toString).collect(Collectors.joining(SPACE));
}public static List<Integer>list(final int[]a){return Arrays.stream(a).mapToObj(Integer::valueOf).collect(Collectors.toList());
}public static List<Integer>list(final IntStream a){return a.mapToObj(Integer::valueOf).collect(Collectors.toList());
}public static List<Long>list(final long[]a){return Arrays.stream(a).mapToObj(Long::valueOf).collect(Collectors.toList());
}public static List<Long>list(final LongStream a){return a.mapToObj(Long::valueOf).collect(Collectors.toList());
}public static<T>List<T>list(final Stream<T>a){return a.collect(Collectors.toList());
}public static<T>List<T>list(final Collection<T>a){return a.stream().collect(Collectors.toList());
}public static<T>List<T>list(final T[]a){return Arrays.stream(a).collect(Collectors.toList());
}public static String yesNo(final boolean res){return res?"YES":"NO";}}static private class 
Driver{private int len2,n2,trlen,n=0;private DriverUpdater updater;private int get_result
=-1;final private int[]info=new int[6];private int[][]rest=null;static final int 
END=0;static final int REST=1;static final int REST_LEVEL=2;static public final 
int INFO_LEVEL=0;static public final int INFO_START=1;static public final int INFO_STOP
=2;static public final int INFO_END=3;static public final int INFO_REST=4;static 
public final int INFO_REST_LEVEL=5;static private class MultiHelper{int[]used=null;
int last=-1;}private MultiHelper multi=new MultiHelper();public void configure(final 
int size){if(size<1){throw new ArrayIndexOutOfBoundsException();}if(size>n){rest
=null;multi.used=null;}multi.last=-1;n=size;len2=(int)Math.ceil(Math.log(n)/Math.log(2));
n2=1<<len2;trlen=(n2<<1)-1;rest=new int[len2+1][3];}public void setUpdater(final 
DriverUpdater updater){this.updater=updater;}public int size(){return n;}public 
int treeSize(){return trlen;}public int startPosition(){return trlen-n2;}public 
int[]info(final int i){info[INFO_LEVEL]=(int)Math.floor(Math.log1p(i)/Math.log(2));
info[INFO_START]=(1<<info[INFO_LEVEL])-1;info[INFO_STOP]=(1<<(info[INFO_LEVEL]+1))
-1;info[INFO_END]=rest[info[INFO_LEVEL]][END];info[INFO_REST]=rest[info[INFO_LEVEL]][REST];
info[INFO_REST_LEVEL]=rest[info[INFO_LEVEL]][REST_LEVEL];return info;}public String 
toString(final Function<Integer,String>itemToString){return IntStream.range(0,trlen).mapToObj(i
->{int[]info=info(i);return(i==info[Driver.INFO_START]?"[":"")+(i-1<info[Driver.INFO_END]
?(info[Driver.INFO_REST]==info[Driver.INFO_END]|| i<info[Driver.INFO_END]?itemToString.apply(i)
:"*"+itemToString.apply(info[Driver.INFO_REST])):"-")+(i==info[Driver.INFO_STOP]
-1?"]":"");}).collect(Collectors.joining(", ","[","]"));}public void init(){int 
start=trlen-n2;int stop=trlen;rest[len2][END]=start+n-1;rest[len2][REST]=rest[len2][END];
rest[len2][REST_LEVEL]=len2;for(int level=len2;level>0;level--){for(int j=start;
j<Math.min(stop,rest[level][END]+1);j+=2){int t=(j-1)>>1;switch(rest[level][END]
-j){case 0:rest[level-1][END]=t;rest[level-1][REST]=rest[level][REST];rest[level
-1][REST_LEVEL]=rest[level][REST_LEVEL];break;case 1:rest[level-1][END]=t;rest[level
-1][REST]=t;rest[level-1][REST_LEVEL]=level-1;updater.update(t,j,rest[level][REST],
QueryType.INIT);break;default:updater.update(t,j,j+1,QueryType.INIT);break;}}start
=((start+1)>>1)-1;stop=(stop-1)>>1;}}public void set(final int i){if(multi()){throw 
new MultiSetException();}if(i<0 || i>=n){throw new ArrayIndexOutOfBoundsException();
}int j=n2-1+i;for(int level=len2;level>0;level--){if((j & 1)==0){j--;}int t=(j-1)
>>1;if(j<rest[level][END]){if(j+1==rest[level][END]){updater.update(t,j,rest[level][REST],
QueryType.SET);}else{updater.update(t,j,j+1,QueryType.SET);}}j=t;}}public void setRange(final 
int startInclusive,final int endExclusive){if(multi()){throw new MultiSetException();
}if(startInclusive<0 || startInclusive>=n || endExclusive<=0 || endExclusive>n || 
endExclusive<=startInclusive){throw new ArrayIndexOutOfBoundsException();}int start
=startInclusive+trlen-n2;start-=(1-(start & 1));int stop=endExclusive+trlen-n2;stop
+=(1-(stop & 1));for(int level=len2;level>0;level--){for(int j=start;j<Math.min(stop,
rest[level][END]+1);j+=2){int t=(j-1)>>1;switch(rest[level][END]-j){case 0:break;
case 1:updater.update(t,j,rest[level][REST],QueryType.SET);break;default:updater.update(t,
j,j+1,QueryType.SET);break;}}start=((start+1)>>1)-1;stop=(stop-1)>>1;}}public boolean 
multi(){return multi.last!=-1;}public void multiSet(final int i){if(multi.used==
null){multi.used=new int[(n+(n & 1))>>1];}else if(multi.last==-1){Arrays.fill(multi.used,
0);}if(i<0 || i>=n){throw new ArrayIndexOutOfBoundsException();}int j=n2-1+i;if((j 
& 1)==0){j--;}int halh_j=(j-trlen+n2)>>1;if(multi.used[halh_j]==0){multi.used[halh_j]
=1;if(halh_j>multi.last){multi.last=halh_j;}}}public void applyMultiSet(){if(!multi())
{throw new MultiSetException();}int[]start=new int[]{trlen-n2,-1};int[]last=new 
int[1];for(int[]level=new int[]{len2};level[0]>0;level[0]--){start[1]=((start[0]
+1)>>1)-1;last[0]=-1;IntStream.rangeClosed(0,multi.last).filter(i->multi.used[i]
>0).forEach(i->{multi.used[i]=0;int j=start[0]+(i<<1);int t=(j-1)>>1;if(j<rest[level[0]][END])
{if(j+1==rest[level[0]][END]){updater.update(t,j,rest[level[0]][REST],QueryType.SET);
}else{updater.update(t,j,j+1,QueryType.SET);}}if(level[0]>1){if((t & 1)==0){t--;
}last[0]=(t-start[1])>>1;multi.used[last[0]]=1;}});start[0]=start[1];multi.last=
last[0];}multi.last=-1;}private void get(final int l,final int r,final int l1,final 
int r1,final int i,final int level){get(l,r,l1,r1,i,level,null);}private void get(final 
int l,final int r,final int l1,final int r1,final int i,final int level,final BiConsumer<Integer,
Boolean>atNode){if(r1>l && l1<r){if(i==rest[level][END]&& i!=rest[level][REST]){
int next_r1=l1+((r1-l1)>>(rest[level][REST_LEVEL]-level));get(l,r,l1,next_r1,rest[level][REST],
rest[level][REST_LEVEL],atNode);}else if(l<=l1 && r>=r1){if(atNode!=null){atNode.accept(i,
true);}if(get_result==-1){get_result=i;}else{int target=Math.max(get_result,trlen)
+1;updater.update(target,get_result,i,QueryType.GET);get_result=target;}}else if(level
<len2){if(atNode!=null){atNode.accept(i,false);}int m=(l1+r1)>>1;int i1=(i<<1)+1;
int next_level=level+1;get(l,r,l1,m,i1++,next_level,atNode);get(l,r,m,r1,i1,next_level,
atNode);}}}private boolean find(final FindPredicate predicate,final int l1,final 
int r1,final int i,final int level){if(!predicate.test(l1,r1,i)){return false;}get_result
=i;if(l1==r1-1 || l1==n-1){return true;}int next_l1=l1;int next_r1=(l1+r1)>>1;int 
t=(i<<1)+1;int next_level=level+1;if(find(predicate,l1,next_r1,t,level+1)){return 
true;}t++;next_l1=(l1+r1)>>1;next_r1=r1;if(t==rest[next_level][END]&& t!=rest[next_level][REST])
{t=rest[next_level][REST];next_r1=next_l1+((r1-next_l1)>>(rest[next_level][REST_LEVEL]
-next_level));next_level=rest[next_level][REST_LEVEL];}return find(predicate,next_l1,
next_r1,t,next_level);}public int find(final FindPredicate predicate){if(multi())
{throw new MultiSetException();}get_result=-1;if(find(predicate,0,n2,0,0)){return 
get_result-trlen+n2;}return-1;}public int get(final int l,final int r){return get(l,
r,null);}public int get(final int l,final int r,final BiConsumer<Integer,Boolean>
atNode){if(multi()){throw new MultiSetException();}get_result=-1;get(l,Math.min(r,
n),0,n2,0,0,atNode);return get_result;}}static private interface DriverUpdater{void 
update(final int target,final int lefSource,final int rightSource,final QueryType 
type);}static private interface FindPredicate{boolean test(final int l,final int 
r,final int i);}static private class MultiSetException extends RuntimeException{
}static private enum QueryType{INIT,SET,GET}static private class SegTree<U>{protected 
U[]tree=null;final private Driver driver=new Driver();private Updater<U>updater=
null;private Supplier<U>creator=null;private U[]get_target=null;public SegTree(final 
Supplier<U>creator,final Updater<U>updater){this.creator=creator;this.updater=updater;
@SuppressWarnings("unchecked")final U[]tmp=(U[])Stream.of(creator.get(),creator.get()).toArray();
get_target=tmp;}final private DriverUpdater du=(target,leftSource,rightSource,type)
->{if(type==QueryType.INIT){tree[target]=creator.get();}if(type==QueryType.GET){
updater.update(get_target[target & 1],leftSource<driver.treeSize()?tree[leftSource]
:get_target[leftSource & 1],tree[rightSource],type);}else{updater.update(tree[target],
tree[leftSource],tree[rightSource],type);}};public Supplier<U>creator(){return creator;
}public Updater<U>updater(){return updater;}public int startPosition(){return driver.startPosition();
}public int treeSize(){return driver.treeSize();}public String toString(){return 
driver.toString(i->tree[i].toString());}public void init(final U[]a){driver.configure(a.length);
driver.setUpdater(du);@SuppressWarnings("unchecked")final U[]tmp=(U[])IntStream.range(0,
driver.treeSize()).mapToObj(i->(U)null).toArray();tree=tmp;System.arraycopy(a,0,
tree,driver.startPosition(),a.length);driver.init();}public void set(final int i,
final Consumer<U>setter){setter.accept(tree[driver.startPosition()+i]);driver.set(i);
}public boolean multi(){return driver.multi();}public void multiSet(final int i,
final Consumer<U>setter){setter.accept(tree[driver.startPosition()+i]);driver.multiSet(i);
}public void applyMultiSet(){driver.applyMultiSet();}public U get(final int l,final 
int r){int res=driver.get(l,r);return res<driver.treeSize()?tree[res]:get_target[res 
& 1];}public U getNode(final int i){return tree[i];}public U get(final int i){return 
tree[driver.startPosition()+i];}public int find(final FindPredicate predicate){return 
driver.find(predicate);}}static private interface Updater<U>{void update(final U 
target,final U src1,final U src2,final QueryType type);}}
