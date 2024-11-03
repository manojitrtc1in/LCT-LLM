


import java.security.*;
import java.nio.file.*;
import java.lang.annotation.*;
import java.util.stream.*;
import java.util.concurrent.atomic.*;
import java.util.function.*;
import java.util.concurrent.*;
import java.util.*;
import java.text.*;
import java.nio.*;
import java.nio.charset.*;
import java.io.*;
import java.lang.reflect.*;
import java.math.*;









public class Solution {
    public static void main(String[] args) throws Exception {
        Main.main(args);
    }
}


class Main{public static void main(String[]args)throws Exception{Class<?extends AbstractSubmission>clss=TaskD.class;new TaskD().runSubmission();}};







@ContestSubmission(ContestType.CODEFORCES)
@CacheVersion(0)
class TaskD extends AbstractSubmission {

	@Override
	public void testCase() {
		int m = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();
		int t = sc.nextInt();
		int[] a = new int[m];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		Arr.sort(a);
		int[][] traps = new int[k][3];
		for (int i = 0; i < traps.length; i++) {
			traps[i] = new int[] {sc.nextInt(), sc.nextInt(), sc.nextInt()};
		}
		Arr.sort(traps, Comparator.comparingInt(u -> u[0]));


		int best = BinarySearch.id39(new Range(a[0], a[a.length - 1] + 1), i -> {
			int ct = t;
			int tpointer = 0;
			int furthest = -1;
			for (int j = 0; j <= n; j++) {
				while (tpointer < traps.length && traps[tpointer][0] <= j) {
					if (traps[tpointer][2] > i) {
						

						ct -= 2 * Math.max(0, traps[tpointer][1] - furthest);
						furthest = Math.max(furthest, traps[tpointer][1]);
					}
					tpointer++;
				}
				furthest = Math.max(j, furthest);
				ct--;
				if (ct < 0) {
					debug.println(i + ": no - " + j);
					return false;
				}
			}
			debug.println(i + ": " + ct);
			return true;
		});

		debug.println(best);


		out.println(Arrays.stream(a).filter(i -> i >= best).count());

	}



	@Override
	public void init() {
		


		

		

	}











	


	
	
	
	





	
};

abstract class AbstractSubmission{public FastScanner sc;public InputStream in;public PrintStream out;public PrintStream debug;public volatile double score=0;public volatile int id6=-1;public volatile int id31;public volatile double progress=0;public void runSubmission(){runSubmission(false);}public void runSubmission(boolean debug){runSubmission(System.in,System.out,debug);}public void runSubmission(InputStream in,PrintStream out){runSubmission(in,out,false);}public void runSubmission(InputStream in,PrintStream out,boolean debug){runSubmission(in,out,debug?System.err:new id32());}public void runSubmission(InputStream in,OutputStream out,OutputStream debug){this.in=in;this.sc=new FastScanner(this.in);this.out=new PrintStream(out);this.debug=debug instanceof id30||debug instanceof id32?new id32():new id34(debug);ContestType type=getType();id6=type.id6;init();if(id6<=0){id6=sc.nextInt();sc.nextLine();}id31=0;for(id31=1;id31<=id6;id31++){progress=0;this.out.printf(type.caseString,id31,id6);testCase();}}private class id34 extends PrintStream{public id34(OutputStream debug){super(debug);}private Object conv(Object obj){if(obj instanceof byte[])return Arrays.toString((byte[])obj);else if(obj instanceof char[])return Arrays.toString((char[])obj);else if(obj instanceof short[])return Arrays.toString((short[])obj);else if(obj instanceof int[])return Arrays.toString((int[])obj);else if(obj instanceof long[])return Arrays.toString((long[])obj);else if(obj instanceof float[])return Arrays.toString((float[])obj);else if(obj instanceof double[])return Arrays.toString((double[])obj);else if(obj instanceof boolean[])return Arrays.toString((int[])obj);else if(obj instanceof Object[])return Arrays.deepToString((Object[])obj);else return obj;}public void print(Object obj){super.print(conv(obj));}public void println(Object obj){super.println(conv(obj));}}public ContestType getType(){return getType(getClass());}public static ContestType getType(Class<?extends AbstractSubmission>clss){return getAnnotation(clss).value();}private static ContestSubmission getAnnotation(Class<?extends AbstractSubmission>clss){if(!clss.isAnnotationPresent(ContestSubmission.class)){throw new RuntimeException("ContestSubmission annotation not present on class "+clss.getCanonicalName()+ "!");}return clss.getAnnotation(ContestSubmission.class);}public abstract void testCase();public abstract void init();};

class Arr extends ArrayUtils{};

class ArrayUtils{public static void sort(int[]arr){shuffle(arr);Arrays.sort(arr);}public static void sort(long[]arr){shuffle(arr);Arrays.sort(arr);}public static void sort(double[]arr){shuffle(arr);Arrays.sort(arr);}public static<T>void sort(T[]arr){Arrays.sort(arr);}public static<T>void sort(T[]arr,Comparator<?super T>comparator){Arrays.sort(arr,comparator);}public static void shuffle(int[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(long[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(double[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(boolean[]arr){shuffle(arr,ThreadLocalRandom.current());}public static<T>void shuffle(T[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(int[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(long[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(double[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static<T>void shuffle(T[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(boolean[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void swap(int[]arr,int i,int j){int tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(long[]arr,int i,int j){long tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(double[]arr,int i,int j){double tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(boolean[]arr,int i,int j){boolean tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static<T>void swap(T[]arr,int i,int j){T tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static int indexOf(int[]arr,int of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(boolean[]arr,boolean of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(double[]arr,double of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(long[]arr,long of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(Object[]arr,Object of){for(int i=0;i<arr.length;i++){if(Utils.equals(arr[i],of))return i;}return-1;}public static int[]id7(byte[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static int[]id7(short[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static int[]id7(char[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static long[]id19(byte[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]id19(short[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]id19(char[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]id19(int[]arr){return Arrays.stream(arr).mapToLong(a->a).toArray();}public static double[]id11(float[]arr){return asList(arr).stream().mapToDouble(a->a).toArray();}public static List<Byte>asList(byte[]arr){return new id42<>(arr);}public static List<Character>asList(char[]arr){return new id42<>(arr);}public static List<Short>asList(short[]arr){return new id42<>(arr);}public static List<Integer>asList(int[]arr){return new id42<>(arr);}public static List<Boolean>asList(boolean[]arr){return new id42<>(arr);}public static List<Float>asList(float[]arr){return new id42<>(arr);}public static List<Double>asList(double[]arr){return new id42<>(arr);}public static List<Long>asList(long[]arr){return new id42<>(arr);}public static<T>List<T>asList(T[]arr){return Arrays.asList(arr);}private static class id42<T,A>extends AbstractList<T>implements RandomAccess{private A arr;private int length;public id42(A arr){this.arr=arr;this.length=java.lang.reflect.Array.getLength(arr);}public T get(int index){return(T)java.lang.reflect.Array.get(arr,index);}public T set(int index,T val){T oldValue=get(index);java.lang.reflect.Array.set(arr,index,val);return oldValue;}public int size(){return length;}}public static<T>Iterator<T>iterator(T...arr){return asList(arr).iterator();}public static int verboseCopy(byte[]src,int id29,int id24,byte[]dest,int id8){int length=id24-id29;if(length<0){length+=src.length;int copied=verboseCopy(src,id29,src.length,dest,id8);return copied+verboseCopy(src,0,id24,dest,id8+copied);}else{System.arraycopy(src,id29,dest,id8,length);return length;}}public static int verboseCopy(int[]src,int id29,int id24,int[]dest,int id8){int length=id24-id29;if(length<0){length+=src.length;int copied=verboseCopy(src,id29,src.length,dest,id8);return copied+verboseCopy(src,0,id24,dest,id8+copied);}else{System.arraycopy(src,id29,dest,id8,length);return length;}}public static int verboseCopy(long[]src,int id29,int id24,long[]dest,int id8){int length=id24-id29;if(length<0){length+=src.length;int copied=verboseCopy(src,id29,src.length,dest,id8);return copied+verboseCopy(src,0,id24,dest,id8+copied);}else{System.arraycopy(src,id29,dest,id8,length);return length;}}public static int verboseCopy(double[]src,int id29,int id24,double[]dest,int id8){int length=id24-id29;if(length<0){length+=src.length;int copied=verboseCopy(src,id29,src.length,dest,id8);return copied+verboseCopy(src,0,id24,dest,id8+copied);}else{System.arraycopy(src,id29,dest,id8,length);return length;}}public static<T>int verboseCopy(T[]src,int id29,int id24,T[]dest,int id8){int length=id24-id29;if(length<0){length+=src.length;int copied=verboseCopy(src,id29,src.length,dest,id8);return copied+verboseCopy(src,0,id24,dest,id8+copied);}else{System.arraycopy(src,id29,dest,id8,length);return length;}}};

class BinarySearch extends Algorithm{private BinarySearch(){}public static int searchFirst(int[]array,int a){return id39(new Range(0,array.length),i->array[i]>=a);}public static int searchLast(int[]array,int a){return id39(new Range(0,array.length),i->array[i]>=a);}public static int searchFirst(long[]array,int a){return id39(new Range(0,array.length),i->array[i]>=a);}public static int searchLast(long[]array,int a){return id39(new Range(0,array.length),i->array[i]>=a);}public static Range search(int[]array,Range id14){return search(ArrayUtils.asList(array),id14);}public static Range search(int[]array,int searchFor){return search(ArrayUtils.asList(array),searchFor);}public static int id39(Range range,IntPredicate id33){return(int)id39(range.id25(),l->id33.test((int)(long)l));}public static long id39(LongRange range,LongPredicate id33){long a=range.a;long b=range.b;while(a<b){long mid=(a+b)/2;if(id33.test(mid)){b=mid;}else{a=mid+1;}}return a;}public static BigInteger id39(Pair<BigInteger,BigInteger>range,Predicate<BigInteger>id33){BigInteger a=range.a;BigInteger b=range.b;while(a.compareTo(b)<0){BigInteger mid=a.add(b).divide(BigInteger.valueOf(2));if(id33.test(mid)){b=mid;}else{a=mid.add(BigInteger.ONE);}}return a;}private static<T>int search(List<T>list,Predicate<T>id33){return id39(new Range(0,list.size()),(i)->id33.test(list.get((int)(long)i)));}private static<T>Range search(List<T>list,Predicate<T>id38,Predicate<T>id26){return new Range(search(list,id38),search(list,id26));}public static<T>Range search(List<T>list,Comparator<T>comparator,T searchFor){return search(list,a->comparator.compare(a,searchFor)>=0,b->comparator.compare(b,searchFor)>0);}public static<T extends Comparable<?super T>>Range search(List<T>list,T searchFor){return search(list,Comparator.naturalOrder(),searchFor);}public static<T>Range search(List<T>list,Comparator<T>comparator,Pair<T,T>id14){return search(list,a->comparator.compare(a,id14.a)>=0,b->comparator.compare(b,id14.b)>=0);}public static<T extends Comparable<?super T>>Range search(List<T>list,Pair<T,T>id14){return search(list,Comparator.naturalOrder(),id14);}};

abstract class Algorithm{private Object result;private boolean end;protected Object id1(Runnable runnable){end=false;result=null;runnable.run();return result;}protected void end(){end(null);}protected void end(Object result){if(shouldEnd())return;this.result=result;this.end=true;}protected boolean shouldEnd(){return end;}};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface CacheVersion{int value();};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface ContestSubmission{ContestType value();};

enum ContestType{PLAIN("",-1),ETH_JUDGE("",-1,null,false,false,6),GOOGLE("Case 

class FastScanner{private static String spaceDelimiters= " \t\n\r\f";private BufferedReader buffer;private StringTokenizer tokenizer;private InputStream stream;public FastScanner(InputStream stream){this.stream=stream;}public String nextLine(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}String res=tokenizer.nextToken("");if(!res.endsWith("\n"))throw new RuntimeException("waddaheq just heppenenened");res=res.substring(0,res.length()-1);if(res.contains("\n"))throw new RuntimeException("oke wat lamo");tokenizer=null;return res;}public String next(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null||!tokenizer.hasMoreTokens()){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}return tokenizer.nextToken(spaceDelimiters);}public BigDecimal nextBigDecimal(){return new BigDecimal(next());}public BigInteger nextBigInteger(){return new BigInteger(next());}public int nextInt(){return Integer.parseInt(next());}public long nextLong(){return Long.parseLong(next());}public double nextDouble(){return Double.parseDouble(next());}};

class LongRange extends Pair<Long,Long>implements Iterable<Long>{public LongRange(long i,long j){super(i,j);}public LongRange(LongRange range){this(range.a,range.b);}public long size(){return this.b-this.a;}public long[]id19(){return this.stream().toArray();}public Range toIntRange(){return new Range((int)(long)this.a,(int)(long)this.b);}public LongStream stream(){return LongStream.range(a,b);}public Iterator<Long>iterator(){return new id35<Long>(){long c=getLeft();public boolean hasNext(){return c<getRight();}public Long next(){return c++;}};}public boolean contains(long l){return l>=this.a&&l<this.b;}public void id18(LongRange range){a=Math.max(range.a,a);b=Math.min(range.b,b);}public LongRange id23(LongRange range){LongRange res=new LongRange(this);res.id18(range);return res;}public static LongRange getIntersection(LongRange...a){return Arrays.stream(a).reduce((res,b)->res.id23(b)).get();}public void ensureValidity()throws IllegalArgumentException{if(this.b<this.a)throw new IllegalArgumentException("Second argument of range ("+this.a+ ", "+this.b+ ") must be larger than first");}public String toString(){return  "["+a+ ", "+b+ ")";}};

@Retention(RetentionPolicy.SOURCE)@Target(ElementType.METHOD)@interface O{String value();};

@Target(ElementType.FIELD)@Retention(RetentionPolicy.RUNTIME)@interface Optimize{long imin()default 0;long imax()default 100;double fmin()default 0;double fmax()default 1;};

class Pair<A,B>extends Tuple implements Map.Entry<A,B>{public A a;public B b;public Pair(A a,B b){this.a=a;this.b=b;}public A getLeft(){return a;}public B getRight(){return b;}public void setLeft(A a){this.a=a;}public void setRight(B b){this.b=b;}public<A1,B1>Pair<A1,B1>map(Function<A,A1>mapA,Function<B,B1>mapB){return new Pair<A1,B1>(mapA.apply(this.a),mapB.apply(this.b));}public A getKey(){return a;}public A setKey(A a){A old=this.a;this.a=a;return old;}public B getValue(){return b;}public B setValue(B b){B old=this.b;this.b=b;return old;}public Object[]toArray(){return new Object[]{a,b};}public boolean equals(Object other){if(!(other instanceof Pair))return super.equals(other);Pair pair=(Pair)other;return Utils.equals(this.a,pair.a)&&Utils.equals(this.b,pair.b);}public int hashCode(){return 961+31*Utils.hashCode(a)+Utils.hashCode(b);}};

abstract class id35<T>implements Iterator<T>{};

class Range extends Pair<Integer,Integer>implements Iterable<Integer>{public Range(int i,int j){super(i,j);}public Range(Range range){this(range.a,range.b);}public int size(){return this.b-this.a;}public int[]id7(){return this.stream().toArray();}public LongRange id25(){return new LongRange(this.a,this.b);}public IntStream stream(){return IntStream.range(a,b);}public Iterator<Integer>iterator(){return new id35<Integer>(){int c=getLeft();public boolean hasNext(){return c<getRight();}public Integer next(){return c++;}};}public boolean contains(int l){return l>=this.a&&l<this.b;}public void id18(Range range){a=Math.max(range.a,a);b=Math.min(range.b,b);}public Range id23(Range range){Range res=new Range(this);res.id18(range);return res;}public static Range getIntersection(Range...a){return Arrays.stream(a).reduce((res,b)->res.id23(b)).get();}public void ensureValidity()throws IllegalArgumentException{if(this.b<this.a)throw new IllegalArgumentException("Second argument of range ("+this.a+ ", "+this.b+ ") must be larger than first");}public String toString(){return  "["+a+ ", "+b+ ")";}};

abstract class Tuple extends Structure{public abstract Object[]toArray();public boolean equals(Object obj){if(obj==null)return false;if(!(obj instanceof Tuple))return false;return Arrays.equals(this.toArray(),((Tuple)obj).toArray());}public int hashCode(){return Arrays.hashCode(this.toArray());}public String toString(){Object[]els=toArray();String[]elements=new String[els.length];for(int i=0;i<els.length;i++){elements[i]= ""+els[i];}return  "("+String.join(", ",elements)+ ")";}};

abstract class Structure implements Serializable,Cloneable{public Structure clone(){try{Structure struct=(Structure)super.clone();for(Field field:this.getClass().getDeclaredFields()){field.setAccessible(true);if(Modifier.isTransient(field.getModifiers())){continue;}field.set(struct,field.get(this));}return struct;}catch(CloneNotSupportedException e){throw new AssertionError("Cloning a structure should always be supported - please report this bug",e);}catch(IllegalAccessException e){throw new RuntimeException("Can't access my own elements!",e);}}private NavigableMap<String,Object>getFields(){try{NavigableMap<String,Object>result=new TreeMap<String,Object>();for(Field field:this.getClass().getFields()){if(Modifier.isTransient(field.getModifiers())){continue;}result.put(field.getName(),field.get(this));}return result;}catch(IllegalAccessException e){throw new RuntimeException("Can't access my own elements!",e);}}public boolean equals(Object obj){if(obj==null)return false;if(getClass()!=obj.getClass())return false;return getFields().equals(((Structure)obj).getFields());}public int hashCode(){return getFields().hashCode();}public String toString(){return getFields().toString();}};

class Tree<T>implements Serializable{private TreeNode<T>root;Pair<Double,DoubleBinaryOperator>distanceFolder;public Tree(T rootValue){this(rootValue,null);}public Tree(T rootValue,Pair<Double,DoubleBinaryOperator>distanceFolder){this(distanceFolder);initRoot(new TreeNode<T>(rootValue,this));}protected Tree(){this((Pair<Double,DoubleBinaryOperator>)null);}protected Tree(Pair<Double,DoubleBinaryOperator>distanceFolder){this.distanceFolder=distanceFolder==null?new Pair<Double,DoubleBinaryOperator>(0.0,Double::sum):distanceFolder;}protected void initRoot(TreeNode<T>node){if(root!=null)throw new IllegalStateException("Can't modify the root after it has already been initialized!");this.root=node;}public TreeNode<T>getRoot(){return root;}public List<TreeNode<T>>leafNodes(){return getRoot().leafNodes();}public List<TreeNode<T>>preOrder(){return getRoot().preOrder();}public List<TreeNode<T>>postOrder(){return getRoot().postOrder();}public String toString(){return root.toString();}};

class TreeNode<T>implements Serializable{private T value;private int height;private double distance;private double id17;private List<TreeNode<T>>children;private TreeNode<T>parent;private Tree<T>tree;public TreeNode(T value){this(value,null);}protected TreeNode(T value,Tree<T>tree){this.value=value;this.parent=null;this.tree=tree;this.children=new ArrayList<TreeNode<T>>(5);this.height=0;this.distance=tree.distanceFolder.a;}protected TreeNode(T value,TreeNode<T>parent,double id17){this.value=value;this.parent=parent;this.tree=parent.tree;this.children=new ArrayList<TreeNode<T>>();this.height=parent.getHeight()+1;this.id17=id17;this.distance=tree.distanceFolder.b.applyAsDouble(parent.getDistance(),id17);}public T getValue(){return value;}public void setValue(T value){this.value=value;}public int getHeight(){return height;}public double getDistance(){return distance;}public double id21(){if(!hasParent())throw new NoSuchElementException("Node has no parent!");return this.id17;}public List<TreeNode<T>>getChildren(){return this.children.size()==0?Collections.emptyList():Collections.unmodifiableList(children);}public int id37(){return children.size();}public TreeNode<T>addChild(T value){return addChild(value,1);}public TreeNode<T>addChild(T value,double distance){return id40(value,distance).attach();}public TreeNode<T>.Unattached id40(T value,double distance){return new Unattached(value,distance);}class Unattached extends TreeNode<T>{private boolean isAttached=false;private Unattached(T value,double distance){super(value,TreeNode.this,distance);}public TreeNode<T>attach(){if(isAttached())throw new NoSuchElementException("Node has already been attached!");TreeNode.this.children.add(this);isAttached=true;return this;}public boolean isAttached(){return isAttached;}}public TreeNode<T>getParent(){return parent;}public List<TreeNode<T>>id12(){List<TreeNode<T>>res=new ArrayList<TreeNode<T>>();TreeNode<T>node=this;while((node=node.getParent())!=null){res.add(node);}Collections.reverse(res);return res;}public boolean hasParent(){return getParent()!=null;}public Tree<T>getTree(){return tree;}public boolean isAttached(){return true;}public List<TreeNode<T>>leafNodes(){return traverse(2);}public List<TreeNode<T>>preOrder(){return traverse(0);}public List<TreeNode<T>>postOrder(){return traverse(1);}private List<TreeNode<T>>traverse(int mode){List<TreeNode<T>>list=new ArrayList<TreeNode<T>>();traverse(list,mode);return list;}private void traverse(List<TreeNode<T>>list,int mode){Queue<TreeNode<T>>queue=QueueUtils.id20();queue.add(this);while(!queue.isEmpty()){TreeNode<T>n=queue.remove();if(mode!=2||n.id37()==0)list.add(n);Iterable<TreeNode<T>>children=mode==1?n.getChildren():Utils.reverseIterable(n.getChildren());for(TreeNode<T>child:children){queue.add(child);}}if(mode==1)Collections.reverse(list);}public String toString(){return(""+value)+(children.isEmpty()? "":children.toString());}};

class QueueUtils{public static<T>Queue<T>createFIFO(){return new ArrayDeque<>();}public static<T>Queue<T>id20(){return Collections.asLifoQueue(new ArrayDeque<>());}public static<T>Queue<T>createStack(){return id20();}public static<T extends Comparable<?super T>>Queue<T>createPriority(){return new PriorityQueue<>();}public static<T>Queue<T>createPriority(Comparator<?super T>comparator){return new PriorityQueue<>(comparator);}public static<T,U extends Comparable<?super U>>Queue<T>createPriority(Function<?super T,?extends U>keyExtractor){return createPriority(Comparator.comparing(keyExtractor));}};

class Utils{public static boolean equals(int a,int b){return a==b;}public static boolean equals(long a,long b){return a==b;}public static boolean equals(double a,double b){return Double.doubleToLongBits(a)==Double.doubleToLongBits(b);}public static boolean equals(Object a,Object b){return Objects.equals(a,b);}public static int hashCode(int a){return Integer.hashCode(a);}public static int hashCode(long a){return Long.hashCode(a);}public static int hashCode(double a){return Double.hashCode(a);}public static int hashCode(Object a){return Objects.hashCode(a);}public static int compare(int a,int b){return Integer.compare(a,b);}public static int compare(long a,long b){return Long.compare(a,b);}public static int compare(double a,double b){return Double.compare(a,b);}public static<T extends Comparable<?super T>>int compare(T a,T b){return Objects.compare(a,b,Comparator.naturalOrder());}public static<T>int hashAll(Object...objs){return hashAll(Arr.iterator(objs));}public static<T>int hashAll(Iterator<T>iterator){int hash=1;while(iterator.hasNext()){T obj=iterator.next();hash=hash*31+Objects.hashCode(obj);}return hash;}public static void repeat(int times,Consumer<Integer>consumer){for(int i=0;i<times;i++){consumer.accept(i);}}public static void repeat(int times,Runnable runnable){repeat(times,(a)->runnable.run());}public static<E extends Throwable>double timing(id22<E>runnable)throws E{long start=System.nanoTime();runnable.run();long end=System.nanoTime();return(end-start)/1_000_000_000.0;}private static int id27=0;public static<T,E extends Throwable>T printTiming(id15<T,E>supplier,String name)throws E{int tid=id27++;if(name==null)name= ""+tid;else name=tid+ " - "+name;System.err.println("Starting task "+name);long start=System.nanoTime();try{return supplier.get();}finally{long end=System.nanoTime();System.err.println("Time taken for task "+name+ ": "+(end-start)/1_000_000_000.0+ "s");}}public static<E extends Throwable>void printTiming(id22<E>runnable,String name)throws E{printTiming(()->{runnable.run();return null;},name);}public static<E extends Throwable>void printTiming(id22<E>runnable)throws E{printTiming(runnable,null);}public static<T,E extends Throwable>T printTiming(id15<T,E>supplier)throws E{return printTiming(supplier,null);}public static<T>ArrayList<T>id3(Iterable<T>iterable){int size=iterable instanceof Collection?((Collection)iterable).size():-1;return id3(iterable,size);}public static<T>ArrayList<T>id3(Iterable<T>iterable,int size){return id3(iterable.iterator(),size);}public static<T>ArrayList<T>id3(Iterator<T>iterator){return id3(iterator,-1);}public static<T>ArrayList<T>id3(Iterator<T>iterator,int estimatedSize){return id3(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>ArrayList<T>id3(Spliterator<T>spliterator){long estimatedSize=spliterator.estimateSize();if(estimatedSize>=Long.MAX_VALUE||estimatedSize<=10)estimatedSize=10;ArrayList<T>result=new ArrayList<>((int)Math.min(estimatedSize,Integer.MAX_VALUE));spliterator.id4(result::add);return result;}public static PrimitiveIterator.OfInt id2(IntIterator iterator){return new PrimitiveIterator.OfInt(){public int nextInt(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfLong id2(LongIterator iterator){return new PrimitiveIterator.OfLong(){public long nextLong(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfDouble id2(DoubleIterator iterator){return new PrimitiveIterator.OfDouble(){public double nextDouble(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static IntStream stream(IntIterator iterator){return stream(iterator,-1);}public static IntStream stream(IntIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.id2(iterator),estimatedSize,Spliterator.ORDERED));}public static IntStream stream(Spliterator.OfInt spliterator){return StreamSupport.intStream(spliterator,false);}public static LongStream stream(LongIterator iterator){return stream(iterator,-1);}public static LongStream stream(LongIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.id2(iterator),estimatedSize,Spliterator.ORDERED));}public static LongStream stream(Spliterator.OfLong spliterator){return StreamSupport.longStream(spliterator,false);}public static DoubleStream stream(DoubleIterator iterator){return stream(iterator,-1);}public static DoubleStream stream(DoubleIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.id2(iterator),estimatedSize,Spliterator.ORDERED));}public static DoubleStream stream(Spliterator.OfDouble spliterator){return StreamSupport.doubleStream(spliterator,false);}public static<T>Stream<T>stream(Iterator<T>iterator){return stream(iterator,-1);}public static<T>Stream<T>stream(Iterator<T>iterator,int estimatedSize){return stream(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>Stream<T>stream(Spliterator<T>spliterator){return StreamSupport.stream(spliterator,false);}public static<T>Map<T,Set<Integer>>invert(Collection<T>coll){Map<T,Set<Integer>>map=new HashMap<>();int i=0;for(T t:coll){Set<Integer>set=map.get(t);if(set==null){map.put(t,Collections.singleton(i));}else{if(!(set instanceof LinkedHashSet)){set=new LinkedHashSet<>(set);map.put(t,set);}set.add(i);}i++;}return Collections.unmodifiableMap(map);}public static<T>ArrayList<T>id9(int size){return id9(size,null);}public static<T>ArrayList<T>id9(int size,T element){return new ArrayList<>(Collections.nCopies(size,element));}public static<T>Set<T>asSet(Collection<T>uniqueElements){return id10(Collections.unmodifiableCollection(uniqueElements));}public static<T>Set<T>id10(Collection<T>uniqueElements){return new AbstractSet<T>(){public int size(){return uniqueElements.size();}public boolean isEmpty(){return uniqueElements.isEmpty();}public boolean contains(Object o){return uniqueElements.contains(o);}public Iterator<T>iterator(){return uniqueElements.iterator();}public Object[]toArray(){return uniqueElements.toArray();}public<T1>T1[]toArray(T1[]a){return uniqueElements.toArray(a);}public boolean add(T t){return uniqueElements.add(t);}public boolean remove(Object o){return uniqueElements.remove(o);}public boolean containsAll(Collection<?>c){return uniqueElements.containsAll(c);}public boolean addAll(Collection<?extends T>c){return uniqueElements.addAll(c);}public boolean retainAll(Collection<?>c){return uniqueElements.retainAll(c);}public boolean removeAll(Collection<?>c){return uniqueElements.removeAll(c);}public void clear(){uniqueElements.clear();}};}public static<T>Collector<T,?,Set<T>>id16(){return Collectors.collectingAndThen(Collectors.toList(),Utils::asSet);}public static<T>ListIterator<T>reverseIterator(List<T>list){return reverseIterator(list.listIterator(list.size()));}public static<T>ListIterator<T>reverseIterator(ListIterator<T>it){return new ListIterator<T>(){public boolean hasNext(){return it.hasPrevious();}public T next(){return it.previous();}public boolean hasPrevious(){return it.hasNext();}public T previous(){return it.next();}public int nextIndex(){return it.previousIndex();}public int previousIndex(){return it.nextIndex();}public void remove(){it.remove();}public void set(T t){it.set(t);}public void add(T t){it.add(t);}};}public static<T>Iterable<T>reverseIterable(List<T>list){return()->reverseIterator(list);}public static Runnable id41(id22<?>r){return()->{try{r.run();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Supplier<T>id41(id15<T,?>r){return()->{try{return r.get();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T,R>Function<T,R>id41(id36<T,R,?>r){return(a)->{try{return r.apply(a);}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Predicate<T>id13(id5<T,?>r){return(a)->{try{return r.test(a);}catch(Throwable e){throw new RuntimeException(e);}};}private static Map<Class,Class>id0=new HashMap<Class,Class>(){{put(boolean.class,Boolean.class);put(byte.class,Byte.class);put(short.class,Short.class);put(char.class,Character.class);put(int.class,Integer.class);put(long.class,Long.class);put(float.class,Float.class);put(double.class,Double.class);}};public static Class<?>id28(Class<?>clss){return id0.getOrDefault(clss,clss);}};

interface DoubleIterator{double next();boolean hasNext();default void id4(DoubleConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface IntIterator{int next();boolean hasNext();default void id4(IntConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface LongIterator{long next();boolean hasNext();default void id4(LongConsumer consumer){while(hasNext()){consumer.accept(next());}}};

@FunctionalInterface interface id36<T,R,E extends Throwable>{R apply(T t)throws E;};

@FunctionalInterface interface id5<T,E extends Throwable>{boolean test(T t)throws E;};

@FunctionalInterface interface id22<E extends Throwable>{void run()throws E;};

@FunctionalInterface interface id15<T,E extends Throwable>{T get()throws E;};

class id30 extends OutputStream{public void write(int b){return;}public void write(byte b[]){return;}public void write(byte b[],int off,int len){return;}};

class id32 extends PrintStream{public id32(){super(new id30());}public void write(int b){return;}public void print(char[]buf){return;}public void print(String s){return;}public void print(Object obj){return;}public void println(char[]buf){return;}public void println(String s){return;}public void println(Object obj){return;}public PrintStream format(Locale l,String s,Object...objs){return this;}public PrintStream format(String s,Object...objs){return this;}};