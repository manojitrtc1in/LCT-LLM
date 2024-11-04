import java.io.File;import java.io.FileInputStream;import java.io.FileNotFoundException;
import java.io.IOException;import java.io.InputStream;import java.io.PrintWriter;
import java.lang.annotation.Retention;import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Array;import java.lang.reflect.Field;import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;import java.security.AccessControlException;import java.util.Arrays;
import java.util.Collection;import java.util.Comparator;import java.util.List;import java.util.Map;
import java.util.Objects;import java.util.PriorityQueue;import java.util.TreeMap;
import java.util.function.Function;import java.util.stream.Collectors;import java.util.stream.IntStream;
import java.util.stream.LongStream;import java.util.stream.Stream;public class _p001566D1 {
static public void main(final String[] args) throws IOException{p001566D1._main(args);}

static class p001566D1 extends Solver{public p001566D1(){}@Override public void solve()throws 
IOException{int n=sc.nextInt();int m=sc.nextInt();sc.nextLine();int[]a=Arrays.stream(sc.nextLine().trim().split("\\s+")).filter($s2
->!$s2.isEmpty()).mapToInt(Integer::parseInt).toArray();PriorityQueue<int[]>pq=new 
PriorityQueue<>((x,y)->x[0]!=y[0]?x[0]-y[0]:y[1]-x[1]);List<int[]>listi=Datas.listi(a);
pq.addAll(listi);int[]used=new int[n*m];int res=0;Driver dr=new Driver();dr.configure(n
*m);int[]tree=new int[dr.getTreeLength()+2];dr.setUpdater((type,target,left,right)
->{tree[target]=tree[left];if(right>0){tree[target]+=tree[right];}});int cur=0;while
(!pq.isEmpty()){int[]it=pq.poll();it[1]=cur++;}for(int[]it:listi){if(it[1]>0){int 
t=dr.get(0,it[1]);res+=tree[t];}tree[it[1]+dr.getStart()]=1;dr.set(it[1]);}pw.println(res);
}static public void _main(String[]args)throws IOException{new p001566D1().run();}
}static class Datas{final static String SPACE=" ";public static TreeMap<Integer,
Integer>mapc(final int[]a){return IntStream.range(0,a.length).collect(()->new TreeMap<Integer,
Integer>(),(res,i)->{res.put(a[i],res.getOrDefault(a[i],0)+1);},Map::putAll);}public 
static TreeMap<Long,Integer>mapc(final long[]a){return IntStream.range(0,a.length).collect(
()->new TreeMap<Long,Integer>(),(res,i)->{res.put(a[i],res.getOrDefault(a[i],0)+
1);},Map::putAll);}public static<T>TreeMap<T,Integer>mapc(final T[]a,Comparator<T>
cmp){return IntStream.range(0,a.length).collect(cmp!=null?()->new TreeMap<T,Integer>(cmp)
:()->new TreeMap<T,Integer>(),(res,i)->{res.put(a[i],res.getOrDefault(a[i],0)+1);
},Map::putAll);}public static<T>TreeMap<T,Integer>mapc(final T[]a){return mapc(a,
null);}public static TreeMap<Integer,Integer>mapc(final IntStream a){return a.collect(
()->new TreeMap<Integer,Integer>(),(res,v)->{res.put(v,res.getOrDefault(v,0)+1);
},Map::putAll);}public static TreeMap<Long,Integer>mapc(final LongStream a){return 
a.collect(()->new TreeMap<Long,Integer>(),(res,v)->{res.put(v,res.getOrDefault(v,
0)+1);},Map::putAll);}public static<T>TreeMap<T,Integer>mapc(final Stream<T>a,Comparator<T>
cmp){return a.collect(cmp!=null?()->new TreeMap<T,Integer>(cmp):()->new TreeMap<T,
Integer>(),(res,v)->{res.put(v,res.getOrDefault(v,0)+1);},Map::putAll);}public static
<T>TreeMap<T,Integer>mapc(final Stream<T>a){return mapc(a,null);}public static<T>
TreeMap<T,Integer>mapc(final Collection<T>a,Comparator<T>cmp){return mapc(a.stream(),
cmp);}public static<T>TreeMap<T,Integer>mapc(final Collection<T>a){return mapc(a.stream());
}public static TreeMap<Integer,List<Integer>>mapi(final int[]a){return IntStream.range(0,
a.length).collect(()->new TreeMap<Integer,List<Integer>>(),(res,i)->{if(!res.containsKey(a[i]))
{res.put(a[i],Stream.of(i).collect(Collectors.toList()));}else{res.get(a[i]).add(i);
}},Map::putAll);}public static TreeMap<Long,List<Integer>>mapi(final long[]a){return 
IntStream.range(0,a.length).collect(()->new TreeMap<Long,List<Integer>>(),(res,i)
->{if(!res.containsKey(a[i])){res.put(a[i],Stream.of(i).collect(Collectors.toList()));
}else{res.get(a[i]).add(i);}},Map::putAll);}public static<T>TreeMap<T,List<Integer>>
mapi(final T[]a,Comparator<T>cmp){return IntStream.range(0,a.length).collect(cmp
!=null?()->new TreeMap<T,List<Integer>>(cmp):()->new TreeMap<T,List<Integer>>(),
(res,i)->{if(!res.containsKey(a[i])){res.put(a[i],Stream.of(i).collect(Collectors.toList()));
}else{res.get(a[i]).add(i);}},Map::putAll);}public static<T>TreeMap<T,List<Integer>>
mapi(final T[]a){return mapi(a,null);}public static TreeMap<Integer,List<Integer>>
mapi(final IntStream a){int[]i=new int[]{0};return a.collect(()->new TreeMap<Integer,
List<Integer>>(),(res,v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}i[0]++;},Map::putAll);}public static TreeMap<Long,List<Integer>>
mapi(final LongStream a){int[]i=new int[]{0};return a.collect(()->new TreeMap<Long,
List<Integer>>(),(res,v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}i[0]++;},Map::putAll);}public static<T>TreeMap<T,List<Integer>>
mapi(final Stream<T>a,Comparator<T>cmp){int[]i=new int[]{0};return a.collect(cmp
!=null?()->new TreeMap<T,List<Integer>>(cmp):()->new TreeMap<T,List<Integer>>(),
(res,v)->{if(!res.containsKey(v)){res.put(v,Stream.of(i[0]).collect(Collectors.toList()));
}else{res.get(v).add(i[0]);}i[0]++;},Map::putAll);}public static<T>TreeMap<T,List<Integer>>
mapi(final Stream<T>a){return mapi(a,null);}public static<T>TreeMap<T,List<Integer>>
mapi(final Collection<T>a,Comparator<T>cmp){return mapi(a.stream(),cmp);}public 
static<T>TreeMap<T,List<Integer>>mapi(final Collection<T>a){return mapi(a.stream());
}public static List<int[]>listi(final int[]a){return IntStream.range(0,a.length).mapToObj(i
->new int[]{a[i],i}).collect(Collectors.toList());}public static List<long[]>listi(final 
long[]a){return IntStream.range(0,a.length).mapToObj(i->new long[]{a[i],i}).collect(Collectors.toList());
}public static<T>List<Pair<T,Integer>>listi(final T[]a){return IntStream.range(0,
a.length).mapToObj(i->new Pair<T,Integer>(a[i],i)).collect(Collectors.toList());
}public static List<int[]>listi(final IntStream a){int[]i=new int[]{0};return a.mapToObj(v
->new int[]{v,i[0]++}).collect(Collectors.toList());}public static List<long[]>listi(final 
LongStream a){int[]i=new int[]{0};return a.mapToObj(v->new long[]{v,i[0]++}).collect(Collectors.toList());
}public static<T>List<Pair<T,Integer>>listi(final Stream<T>a){int[]i=new int[]{0};
return a.map(v->new Pair<T,Integer>(v,i[0]++)).collect(Collectors.toList());}public 
static<T>List<Pair<T,Integer>>listi(final Collection<T>a){int[]i=new int[]{0};return 
a.stream().map(v->new Pair<T,Integer>(v,i[0]++)).collect(Collectors.toList());}public 
static String join(final int[]a){return Arrays.stream(a).mapToObj(Integer::toString).collect(Collectors.joining(SPACE));
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
}public static String yesNo(final boolean res){return res?"YES":"NO";}public static 
String dump(Object obj){String res="";if(obj!=null){Class cl=obj.getClass();String 
cls=cl.getName();if(cls.startsWith("[")){res+="[";for(int i=0;;i++){try{Object o
=Array.get(obj,i);String s=dump(o);if(i>0){res+=", ";}res+=s;}catch(ArrayIndexOutOfBoundsException 
ex){break;}}res+="]";}else if(Collection.class.isAssignableFrom(cl)){@SuppressWarnings("unchecked")final 
Object s=((Collection)obj).stream().map(v->dump(v)).collect(Collectors.joining(", ",
"[","]"));res+=s.toString();}else if(Map.class.isAssignableFrom(cl)){@SuppressWarnings("unchecked")final 
Object s=((Map)obj).entrySet().stream().map(v->dump(v)).collect(Collectors.joining(", ",
"{","}"));res+=s.toString();}else if(Character.class.isInstance(obj)|| Integer.class.isInstance(obj)
|| Long.class.isInstance(obj)|| Float.class.isInstance(obj)|| Double.class.isInstance(obj)|| String.class.isInstance(obj)
){res+=Objects.toString(obj);}else if(Map.Entry.class.isInstance(obj)){res+=dump(((Map.Entry)obj).getKey())
+"="+dump(((Map.Entry)obj).getValue());}else if(Stream.class.isInstance(obj)){@SuppressWarnings("unchecked")
final Object s=((Stream)obj).map(v->dump(v)).collect(Collectors.joining(", ","[",
"]"));res+=s.toString();}else{res+=Stream.concat(Arrays.stream(obj.getClass().getFields()).map(v
->{String name=v.getName();String val;try{Object o=v.get(obj);if(o!=null && v.isAnnotationPresent(Dump.class))
{Dump an=v.getAnnotation(Dump.class);Class ocl=o.getClass();val="{";for(String fn:an.fields())
{try{Field f=ocl.getField(fn);val+=fn+"="+dump(f.get(o))+", ";}catch(NoSuchFieldException 
nsfex){try{@SuppressWarnings("unchecked")final Method m=ocl.getMethod(fn);val+=fn+"="+dump(m.invoke(o))
+", ";}catch(NoSuchMethodException | IllegalArgumentException | InvocationTargetException 
nsmex){}}}if(val.endsWith(", ")){val=val.substring(0,val.length()-2);}val+="}";}
else{val=dump(o);}}catch(IllegalAccessException ex){val="N/A";}return name+"="+val;
}),Arrays.stream(obj.getClass().getMethods()).filter(m->m.isAnnotationPresent(Getter.class)).map(m
->{String name=m.getName();String val;try{Object o=m.invoke(obj);if(o!=null && m.isAnnotationPresent(Dump.class))
{Dump an=m.getAnnotation(Dump.class);Class ocl=o.getClass();val="{";for(String fn:an.fields())
{try{Field f=ocl.getField(fn);val+=fn+"="+dump(f.get(o))+", ";}catch(NoSuchFieldException 
nsfex){try{@SuppressWarnings("unchecked")final Method m1=ocl.getMethod(fn);val+=fn+"="+dump(m1.invoke(o))
+", ";}catch(NoSuchMethodException | IllegalArgumentException | InvocationTargetException 
nsmex){}}}if(val.endsWith(", ")){val=val.substring(0,val.length()-2);}val+="}";}else
{val=dump(o);}}catch(IllegalAccessException | InvocationTargetException ex){val=
"N/A";}return name+"="+val;})).collect(Collectors.joining(", ","{"+obj.getClass().getName()
+": ","}"));}}if(res.length()==0){res="<null>";}return res;}}@Retention(RetentionPolicy.RUNTIME)
public @interface Dump{String[]fields();}@Retention(RetentionPolicy.RUNTIME)public @interface Getter{}static class 
Pair<K,V>{private K k;private V v;public Pair(final K t,final V u){this.k=t;this.v
=u;}public K getKey(){return k;}public V getValue(){return v;}public void setKey(K 
t){k=t;}public void setValue(V t){v=t;}}static class Driver{private int max_level;
private int n2;private int trlen;private int n;private DriverUpdater updater=null;
private DriverInitializator setter=null;private DriverGetter getter=null;private 
DriverInitializator initializator=null;private int get_result;private int get_pos;
private boolean break_cycle=false;private boolean right_to_left=false;final public 
void setUpdater(final DriverUpdater updater){this.updater=updater;}final public 
DriverUpdater getUpdater(){return updater;}final public void setSetter(final DriverInitializator 
setter){this.setter=setter;}final public DriverInitializator getSetter(){return 
setter;}final public void setGetter(final DriverGetter getter){this.getter=getter;
}final public DriverGetter getGetter(){return getter;}final public void setInitializator(final 
DriverInitializator initializator){this.initializator=initializator;}final public 
DriverInitializator getInitializator(){return initializator;}final public void configure(final 
int n){this.n=n;max_level=(int)Math.ceil(Math.log(n)/Math.log(2));n2=1<<max_level;
trlen=(n2<<1)-1;}final public String treeToString(final Function<Integer,String>
itemToString){Function<Integer,String>its=itemToString==null?p->"true":itemToString;
StringBuilder sb=new StringBuilder();int[]start=new int[]{0};int stop=1;int[]w=new 
int[]{n2};sb.append("[");while(start[0]<trlen){sb.append(IntStream.range(start[0],
stop).mapToObj(p->(p-start[0])*w[0]<n?its.apply(p):"-").collect(Collectors.joining(", ",
"(",")")));start[0]=stop;stop=(stop<<1)+1;w[0]>>=1;}sb.append("]");return sb.toString();
}final public void init(){if(initializator!=null){for(int i=0;i<n;i++){initializator.accept(i,
trlen-n2+i);}}}final public void boot(){if(updater!=null){break_cycle=false;int 
end;int prev_end=0;end=trlen-n2+n-1;int start=trlen>>1;for(int p=start-1;p>=0;p--)
{if(p<start){prev_end=end;end=(end-1)>>1;p=end;start>>=1;}int left=(p<<1)+1;updater.accept(QueryType.BOOT,
p,left,left<prev_end?left+1:-1);if(break_cycle){break;}}}}final public void boot(final 
int pos){if(updater!=null && pos<trlen-n2){int start=pos;int stop=pos+1;int next;
while((next=(start<<1)+1)<trlen-n2){start=next;stop=(stop<<1)+1;}int prev_end=trlen
-n2+n-1;int end=Math.min(stop-1,(prev_end-1)>>1);break_cycle=false;for(int p=end;
p>=pos;p--){int left=(p<<1)+1;updater.accept(QueryType.BOOT,p,left,left<prev_end
?left+1:-1);if(break_cycle){break;}if(p==start){prev_end=end;start>>=1;end=(end-
1)>>1;p=end+1;}}}}final public void breakCycle(){break_cycle=true;}final public 
void set(final int i){int p=trlen-n2+i;if(setter!=null){setter.accept(i,p);}break_cycle
=false;if(updater!=null){int end=trlen-n2+n-1;while(p>0){int left=((p & 1)==1)?p
:p-1;p=(p-1)>>1;updater.accept(QueryType.SET,p,left,left<end?left+1:-1);if(break_cycle)
{break;}end=(end-1)>>1;}}}final public boolean rightToLeft(){return right_to_left;
}private void get_ltr(final int pos,final int l,final int r,final int b,final int 
e){if(!break_cycle){if(b<r && e>l){int e1=Math.min(e,n);if(b>=l && e1<=r){if(getter
!=null){getter.accept(pos);}if(get_result==-1){get_result=pos;}else if(updater!=
null){updater.accept(QueryType.GET,trlen+get_pos,get_result,pos);get_result=trlen
+get_pos;get_pos ^=1;}}else if(e-b>1){int left=(pos<<1)+1;int m=(b+e)>>1;get_ltr(left,
l,r,b,m);get_ltr(left+1,l,r,m,e);}}}}private void get_rtl(final int pos,final int 
l,final int r,final int b,final int e){if(!break_cycle){if(b<r && e>l){int e1=Math.min(e,
n);if(b>=l && e1<=r){if(getter!=null){getter.accept(pos);}if(get_result==-1){get_result
=pos;}else if(updater!=null){updater.accept(QueryType.GET,trlen+get_pos,pos,get_result);
get_result=trlen+get_pos;get_pos ^=1;}}else if(e-b>1){int left=(pos<<1)+1;int m=
(b+e)>>1;get_rtl(left+1,l,r,m,e);get_rtl(left,l,r,b,m);}}}}final public int get(final 
int l,final int r){this.right_to_left=false;break_cycle=false;get_result=-1;get_pos
=0;get_ltr(0,l,r,0,n2);return get_result;}final public int get(final int l,final 
int r,final boolean right_to_left){this.right_to_left=right_to_left;break_cycle=
false;get_result=-1;get_pos=0;if(right_to_left){get_rtl(0,l,r,0,n2);}else{get_ltr(0,
l,r,0,n2);}return get_result;}final public int getLength(){return n2;}final public 
int getTreeLength(){return trlen;}final public int getStart(){return trlen-n2;}}
static interface DriverGetter{void accept(final int pos);}static interface DriverInitializator
{void accept(final int index,final int pos);}static interface DriverUpdater{void 
accept(final QueryType type,final int target,final int left,final int right);}static enum 
QueryType{BOOT,SET,GET}static class MyScanner{private StringBuilder cache=new StringBuilder();
int cache_pos=0;private int first_linebreak=-1;private int second_linebreak=-1;private 
StringBuilder sb=new StringBuilder();private InputStream is=null;public MyScanner(final 
InputStream is){this.is=is;}public String charToString(final int c){return String.format("'%s'",
c=='\n'?"\\n":(c=='\r'?"\\r":String.valueOf((char)c)));}public int get(){int res
=-1;if(cache_pos<cache.length()){res=cache.charAt(cache_pos);cache_pos++;if(cache_pos
==cache.length()){cache.delete(0,cache_pos);cache_pos=0;}}else{try{res=is.read();
}catch(IOException ex){throw new RuntimeException(ex);}}return res;}private void 
unget(final int c){if(cache_pos==0){cache.insert(0,(char)c);}else{cache_pos--;}}
public String nextLine(){sb.delete(0,sb.length());int c;boolean done=false;boolean 
end=false;while((c=get())!=-1){if(check_linebreak(c)){done=true;if(c==first_linebreak)
{if(!end){end=true;}else{cache.append((char)c);break;}}else if(second_linebreak!=
-1 && c==second_linebreak){break;}}if(end && c!=first_linebreak && c!=second_linebreak)
{cache.append((char)c);break;}if(!done){sb.append((char)c);}}return!done && sb.length()
==0?null:sb.toString();}private boolean check_linebreak(int c){if(c=='\n'|| c=='\r')
{if(first_linebreak==-1){first_linebreak=c;}else if(c!=first_linebreak && second_linebreak
==-1){second_linebreak=c;}return true;}return false;}public int nextInt(){return 
Integer.parseInt(next());}public long nextLong(){return Long.parseLong(next());}
public boolean hasNext(){boolean res=false;int c;while((c=get())!=-1){if(!check_linebreak(c)
&& c!=' '&& c!='\t'){res=true;unget(c);break;}}return res;}public String next(){
sb.delete(0,sb.length());boolean started=false;int c;while((c=get())!=-1){if(check_linebreak(c)
|| c==' '|| c=='\t'){if(started){unget(c);break;}}else{started=true;sb.append((char)c);
}}return sb.toString();}public int nextChar(){return get();}public boolean eof()
{int c=get();boolean res=false;if(c!=-1){unget(c);}else{res=true;}return res;}public 
double nextDouble(){return Double.parseDouble(next());}}static abstract class Solver
{protected String nameIn=null;protected String nameOut=null;protected boolean singleTest
=false;protected MyScanner sc=null;protected PrintWriter pw=null;private int current_test
=0;private int count_tests=0;protected int currentTest(){return current_test;}protected 
int countTests(){return count_tests;}private void process()throws IOException{if(!singleTest)
{count_tests=sc.nextInt();sc.nextLine();for(current_test=1;current_test<=count_tests;
current_test++){solve();pw.flush();}}else{count_tests=1;current_test=1;solve();}
}abstract protected void solve()throws IOException;public void run()throws IOException
{boolean done=false;try{if(nameIn!=null){if(new File(nameIn).exists()){try(FileInputStream 
fis=new FileInputStream(nameIn);PrintWriter pw0=select_output();){select_output();
done=true;sc=new MyScanner(fis);pw=pw0;process();}}else{throw new RuntimeException("File "
+new File(nameIn).getAbsolutePath()+" does not exist!");}}}catch(IOException | AccessControlException 
ex){}if(!done){try(PrintWriter pw0=select_output();){sc=new MyScanner(System.in);
pw=pw0;process();}}}private PrintWriter select_output()throws FileNotFoundException
{if(nameOut!=null){return new PrintWriter(nameOut);}return new PrintWriter(System.out);
}}static abstract class Tester{static public int getRandomInt(final int min,final 
int max){return(min+(int)Math.floor(Math.random()*(max-min+1)));}static public long 
getRandomLong(final long min,final long max){return(min+(long)Math.floor(Math.random()
*(max-min+1)));}static public double getRandomDouble(final double min,final double 
maxExclusive){return(min+Math.random()*(maxExclusive-min));}abstract protected void 
testOutput(final List<String>output_data);abstract protected void generateInput();
abstract protected String inputDataToString();private boolean break_tester=false;
protected void beforeTesting(){}protected void breakTester(){break_tester=true;}
public boolean broken(){return break_tester;}}}