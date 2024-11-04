


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


class Main{public static void main(String[]args)throws Exception{Class<?extends AbstractSubmission>clss=TaskE.class;new TaskE().runSubmission();}};







@ContestSubmission(ContestType.CODEFORCES)
@CacheVersion(0)
class TaskE extends AbstractSubmission {

	@Override
	public void testCase() {
		int n = sc.nextInt();
		sc.nextLine();
		char[] comms = sc.nextLine().toCharArray();
		char[] txt = new char[n];
		int len = n;


		StringBuilder res = new StringBuilder();

		int[] vals = new int[n];
		int ptr = 0;

		int lala = 1 + Integer.numberOfTrailingZeros(Integer.highestOneBit(len));
		int[][] sumres = new int[lala][];
		int[][] minres = new int[lala][];
		int[][] maxres = new int[lala][];
		{
			int ran = len;
			for (int i = 0; i < lala; i++) {
				sumres[i] = new int[ran + 2];
				minres[i] = new int[ran + 2];
				maxres[i] = new int[ran + 2];
				ran /= 2;
			}
		}


		int ret = 0;
		for (char comm : comms) {
			switch (comm) {
				case 'R': {
					ptr++;
					break;
				}
				case 'L': {
					ptr--;
					ptr = Math.max(0, ptr);
					break;
				}
				default: {
					int val = (comm == '(' ? 1 : (comm == ')' ? -1 : 0));
					sumres[0][ptr] = val;
					minres[0][ptr] = val;
					maxres[0][ptr] = val;
					int ka = ptr;
					for (int i = 1; i < lala; i++) {
						int lka = ka & (-2);
						sumres[i][ka/2] = sumres[i-1][lka] + sumres[i-1][lka+1];
						ka /= 2;
					}
					ka = ptr;
					for (int i = 1; i < lala; i++) {
						int lka = ka & (-2);
						minres[i][ka/2] = Math.min(minres[i-1][lka], (minres[i-1][lka+1] + sumres[i-1][lka]));
						maxres[i][ka/2] = Math.max(maxres[i-1][lka], (maxres[i-1][lka+1] + sumres[i-1][lka]));
						ka /= 2;
					}

					if (minres[minres.length - 1][0] < 0 || sumres[sumres.length - 1][0] != 0) {
						ret = -1;
					} else {
						ret = maxres[maxres.length - 1][0];
					}

					
					break;
				}
			}

			debug.println(comm + " " + ptr);
			debug.println(sumres);
			debug.println(minres);
			debug.println(maxres);
			debug.println();

			res.append(ret + " ");
		}

		out.println(res);
	}



	@Override
	public void init() {
		


		

		

	}











	


	
	
	
	





	
};

abstract class AbstractSubmission{public FastScanner sc;public InputStream in;public PrintStream out;public PrintStream debug;public volatile double score=0;public volatile int testCaseCount=-1;public volatile int testCaseIndex;public volatile double progress=0;public void runSubmission(){runSubmission(false);}public void runSubmission(boolean debug){runSubmission(System.in,System.out,debug);}public void runSubmission(InputStream in,PrintStream out){runSubmission(in,out,false);}public void runSubmission(InputStream in,PrintStream out,boolean debug){runSubmission(in,out,debug?System.err:new VoidPrintStream());}public void runSubmission(InputStream in,OutputStream out,OutputStream debug){this.in=in;this.sc=new FastScanner(this.in);this.out=new PrintStream(out);this.debug=debug instanceof VoidOutputStream||debug instanceof VoidPrintStream?new VoidPrintStream():new DebugPrintStream(debug);ContestType type=getType();testCaseCount=type.testCaseCount;init();if(testCaseCount<=0){testCaseCount=sc.nextInt();sc.nextLine();}testCaseIndex=0;for(testCaseIndex=1;testCaseIndex<=testCaseCount;testCaseIndex++){progress=0;this.out.printf(type.caseString,testCaseIndex,testCaseCount);testCase();}}private class DebugPrintStream extends PrintStream{public DebugPrintStream(OutputStream debug){super(debug);}private Object conv(Object obj){if(obj instanceof byte[])return Arrays.toString((byte[])obj);else if(obj instanceof char[])return Arrays.toString((char[])obj);else if(obj instanceof short[])return Arrays.toString((short[])obj);else if(obj instanceof int[])return Arrays.toString((int[])obj);else if(obj instanceof long[])return Arrays.toString((long[])obj);else if(obj instanceof float[])return Arrays.toString((float[])obj);else if(obj instanceof double[])return Arrays.toString((double[])obj);else if(obj instanceof boolean[])return Arrays.toString((int[])obj);else if(obj instanceof Object[])return Arrays.deepToString((Object[])obj);else return obj;}public void print(Object obj){super.print(conv(obj));}public void println(Object obj){super.println(conv(obj));}}public ContestType getType(){return getType(getClass());}public static ContestType getType(Class<?extends AbstractSubmission>clss){return getAnnotation(clss).value();}private static ContestSubmission getAnnotation(Class<?extends AbstractSubmission>clss){if(!clss.isAnnotationPresent(ContestSubmission.class)){throw new RuntimeException("ContestSubmission annotation not present on class "+clss.getCanonicalName()+ "!");}return clss.getAnnotation(ContestSubmission.class);}public abstract void testCase();public abstract void init();};

class Arr extends ArrayUtils{};

class ArrayUtils{public static void sort(int[]arr){shuffle(arr);Arrays.sort(arr);}public static void sort(long[]arr){shuffle(arr);Arrays.sort(arr);}public static void sort(double[]arr){shuffle(arr);Arrays.sort(arr);}public static<T>void sort(T[]arr){Arrays.sort(arr);}public static<T>void sort(T[]arr,Comparator<?super T>comparator){Arrays.sort(arr,comparator);}public static void shuffle(int[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(long[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(double[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(boolean[]arr){shuffle(arr,ThreadLocalRandom.current());}public static<T>void shuffle(T[]arr){shuffle(arr,ThreadLocalRandom.current());}public static void shuffle(int[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(long[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(double[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static<T>void shuffle(T[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void shuffle(boolean[]arr,Random random){for(int i=0;i<arr.length-1;i++){swap(arr,i,i+random.nextInt(arr.length-i));}}public static void swap(int[]arr,int i,int j){int tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(long[]arr,int i,int j){long tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(double[]arr,int i,int j){double tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static void swap(boolean[]arr,int i,int j){boolean tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static<T>void swap(T[]arr,int i,int j){T tmp=arr[i];arr[i]=arr[j];arr[j]=tmp;}public static int indexOf(int[]arr,int of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(boolean[]arr,boolean of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(double[]arr,double of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(long[]arr,long of){for(int i=0;i<arr.length;i++){if(arr[i]==of)return i;}return-1;}public static int indexOf(Object[]arr,Object of){for(int i=0;i<arr.length;i++){if(Utils.equals(arr[i],of))return i;}return-1;}public static int[]toIntArray(byte[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static int[]toIntArray(short[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static int[]toIntArray(char[]arr){return asList(arr).stream().mapToInt(a->a).toArray();}public static long[]toLongArray(byte[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]toLongArray(short[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]toLongArray(char[]arr){return asList(arr).stream().mapToLong(a->a).toArray();}public static long[]toLongArray(int[]arr){return Arrays.stream(arr).mapToLong(a->a).toArray();}public static double[]toDoubleArray(float[]arr){return asList(arr).stream().mapToDouble(a->a).toArray();}public static List<Byte>asList(byte[]arr){return new BackedList<>(arr);}public static List<Character>asList(char[]arr){return new BackedList<>(arr);}public static List<Short>asList(short[]arr){return new BackedList<>(arr);}public static List<Integer>asList(int[]arr){return new BackedList<>(arr);}public static List<Boolean>asList(boolean[]arr){return new BackedList<>(arr);}public static List<Float>asList(float[]arr){return new BackedList<>(arr);}public static List<Double>asList(double[]arr){return new BackedList<>(arr);}public static List<Long>asList(long[]arr){return new BackedList<>(arr);}public static<T>List<T>asList(T[]arr){return Arrays.asList(arr);}private static class BackedList<T,A>extends AbstractList<T>implements RandomAccess{private A arr;private int length;public BackedList(A arr){this.arr=arr;this.length=java.lang.reflect.Array.getLength(arr);}public T get(int index){return(T)java.lang.reflect.Array.get(arr,index);}public T set(int index,T val){T oldValue=get(index);java.lang.reflect.Array.set(arr,index,val);return oldValue;}public int size(){return length;}}public static<T>Iterator<T>iterator(T...arr){return asList(arr).iterator();}public static int verboseCopy(byte[]src,int srcFromIndex,int srcToIndex,byte[]dest,int destFromIndex){int length=srcToIndex-srcFromIndex;if(length<0){length+=src.length;int copied=verboseCopy(src,srcFromIndex,src.length,dest,destFromIndex);return copied+verboseCopy(src,0,srcToIndex,dest,destFromIndex+copied);}else{System.arraycopy(src,srcFromIndex,dest,destFromIndex,length);return length;}}public static int verboseCopy(int[]src,int srcFromIndex,int srcToIndex,int[]dest,int destFromIndex){int length=srcToIndex-srcFromIndex;if(length<0){length+=src.length;int copied=verboseCopy(src,srcFromIndex,src.length,dest,destFromIndex);return copied+verboseCopy(src,0,srcToIndex,dest,destFromIndex+copied);}else{System.arraycopy(src,srcFromIndex,dest,destFromIndex,length);return length;}}public static int verboseCopy(long[]src,int srcFromIndex,int srcToIndex,long[]dest,int destFromIndex){int length=srcToIndex-srcFromIndex;if(length<0){length+=src.length;int copied=verboseCopy(src,srcFromIndex,src.length,dest,destFromIndex);return copied+verboseCopy(src,0,srcToIndex,dest,destFromIndex+copied);}else{System.arraycopy(src,srcFromIndex,dest,destFromIndex,length);return length;}}public static int verboseCopy(double[]src,int srcFromIndex,int srcToIndex,double[]dest,int destFromIndex){int length=srcToIndex-srcFromIndex;if(length<0){length+=src.length;int copied=verboseCopy(src,srcFromIndex,src.length,dest,destFromIndex);return copied+verboseCopy(src,0,srcToIndex,dest,destFromIndex+copied);}else{System.arraycopy(src,srcFromIndex,dest,destFromIndex,length);return length;}}public static<T>int verboseCopy(T[]src,int srcFromIndex,int srcToIndex,T[]dest,int destFromIndex){int length=srcToIndex-srcFromIndex;if(length<0){length+=src.length;int copied=verboseCopy(src,srcFromIndex,src.length,dest,destFromIndex);return copied+verboseCopy(src,0,srcToIndex,dest,destFromIndex+copied);}else{System.arraycopy(src,srcFromIndex,dest,destFromIndex,length);return length;}}};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface CacheVersion{int value();};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface ContestSubmission{ContestType value();};

enum ContestType{PLAIN("",-1),ETH_JUDGE("",-1,null,false,false,6),GOOGLE("Case #%d: ",-1),GOOGLE_JAM("Case #%d: ",-1, "Solution.java",false,false,8),GOOGLE_JAM_INTERACTIVE("",-1, "Solution.java",false,false,8),FACEBOOK("Case #%d: ",-1),BLOOMBERG("",1, "Problem.java",false,false,8),SINGLE_TESTCASE("",1),OPTIMIZER("",1,null,false,false,8,true),HACKERRANK("",1, "Solution.java",false,false,8),CODEFORCES("",1, "Solution.java",false,false,8);public int testCaseCount;public String caseString;public String launcher;public boolean disableCompression;public boolean keepUnusedDependencies;public int javaVersion;public boolean isOptimizer;ContestType(String caseString,int testCaseCount,String launcher,boolean disableCompression,boolean keepUnusedDependencies,int javaVersion,boolean isOptimizer){this.caseString=caseString;this.testCaseCount=testCaseCount;this.launcher=launcher;this.disableCompression=disableCompression;this.javaVersion=javaVersion;this.keepUnusedDependencies=keepUnusedDependencies;this.isOptimizer=isOptimizer;}ContestType(String a1,int a2,String a3,boolean a4,boolean a5,int a6){this(a1,a2,a3,a4,a5,a6,false);}ContestType(String a1,int a2){this(a1,a2,null,false,false,8);}};

class FastScanner{private static String spaceDelimiters= " \t\n\r\f";private BufferedReader buffer;private StringTokenizer tokenizer;private InputStream stream;public FastScanner(InputStream stream){this.stream=stream;}public String nextLine(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}String res=tokenizer.nextToken("");if(!res.endsWith("\n"))throw new RuntimeException("waddaheq just heppenenened");res=res.substring(0,res.length()-1);if(res.contains("\n"))throw new RuntimeException("oke wat lamo");tokenizer=null;return res;}public String next(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null||!tokenizer.hasMoreTokens()){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}return tokenizer.nextToken(spaceDelimiters);}public BigDecimal nextBigDecimal(){return new BigDecimal(next());}public BigInteger nextBigInteger(){return new BigInteger(next());}public int nextInt(){return Integer.parseInt(next());}public long nextLong(){return Long.parseLong(next());}public double nextDouble(){return Double.parseDouble(next());}};

@Retention(RetentionPolicy.SOURCE)@Target(ElementType.METHOD)@interface O{String value();};

@Target(ElementType.FIELD)@Retention(RetentionPolicy.RUNTIME)@interface Optimize{long imin()default 0;long imax()default 100;double fmin()default 0;double fmax()default 1;};

class Utils{public static boolean equals(int a,int b){return a==b;}public static boolean equals(long a,long b){return a==b;}public static boolean equals(double a,double b){return Double.doubleToLongBits(a)==Double.doubleToLongBits(b);}public static boolean equals(Object a,Object b){return Objects.equals(a,b);}public static int hashCode(int a){return Integer.hashCode(a);}public static int hashCode(long a){return Long.hashCode(a);}public static int hashCode(double a){return Double.hashCode(a);}public static int hashCode(Object a){return Objects.hashCode(a);}public static int compare(int a,int b){return Integer.compare(a,b);}public static int compare(long a,long b){return Long.compare(a,b);}public static int compare(double a,double b){return Double.compare(a,b);}public static<T extends Comparable<?super T>>int compare(T a,T b){return Objects.compare(a,b,Comparator.naturalOrder());}public static<T>int hashAll(Object...objs){return hashAll(Arr.iterator(objs));}public static<T>int hashAll(Iterator<T>iterator){int hash=1;while(iterator.hasNext()){T obj=iterator.next();hash=hash*31+Objects.hashCode(obj);}return hash;}public static void repeat(int times,Consumer<Integer>consumer){for(int i=0;i<times;i++){consumer.accept(i);}}public static void repeat(int times,Runnable runnable){repeat(times,(a)->runnable.run());}public static<E extends Throwable>double timing(ThrowingRunnable<E>runnable)throws E{long start=System.nanoTime();runnable.run();long end=System.nanoTime();return(end-start)/1_000_000_000.0;}private static int timingId=0;public static<T,E extends Throwable>T printTiming(ThrowingSupplier<T,E>supplier,String name)throws E{int tid=timingId++;if(name==null)name= ""+tid;else name=tid+ " - "+name;System.err.println("Starting task "+name);long start=System.nanoTime();try{return supplier.get();}finally{long end=System.nanoTime();System.err.println("Time taken for task "+name+ ": "+(end-start)/1_000_000_000.0+ "s");}}public static<E extends Throwable>void printTiming(ThrowingRunnable<E>runnable,String name)throws E{printTiming(()->{runnable.run();return null;},name);}public static<E extends Throwable>void printTiming(ThrowingRunnable<E>runnable)throws E{printTiming(runnable,null);}public static<T,E extends Throwable>T printTiming(ThrowingSupplier<T,E>supplier)throws E{return printTiming(supplier,null);}public static<T>ArrayList<T>toArrayList(Iterable<T>iterable){int size=iterable instanceof Collection?((Collection)iterable).size():-1;return toArrayList(iterable,size);}public static<T>ArrayList<T>toArrayList(Iterable<T>iterable,int size){return toArrayList(iterable.iterator(),size);}public static<T>ArrayList<T>toArrayList(Iterator<T>iterator){return toArrayList(iterator,-1);}public static<T>ArrayList<T>toArrayList(Iterator<T>iterator,int estimatedSize){return toArrayList(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>ArrayList<T>toArrayList(Spliterator<T>spliterator){long estimatedSize=spliterator.estimateSize();if(estimatedSize>=Long.MAX_VALUE||estimatedSize<=10)estimatedSize=10;ArrayList<T>result=new ArrayList<>((int)Math.min(estimatedSize,Integer.MAX_VALUE));spliterator.forEachRemaining(result::add);return result;}public static PrimitiveIterator.OfInt toPrimitiveIterator(IntIterator iterator){return new PrimitiveIterator.OfInt(){public int nextInt(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfLong toPrimitiveIterator(LongIterator iterator){return new PrimitiveIterator.OfLong(){public long nextLong(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfDouble toPrimitiveIterator(DoubleIterator iterator){return new PrimitiveIterator.OfDouble(){public double nextDouble(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static IntStream stream(IntIterator iterator){return stream(iterator,-1);}public static IntStream stream(IntIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static IntStream stream(Spliterator.OfInt spliterator){return StreamSupport.intStream(spliterator,false);}public static LongStream stream(LongIterator iterator){return stream(iterator,-1);}public static LongStream stream(LongIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static LongStream stream(Spliterator.OfLong spliterator){return StreamSupport.longStream(spliterator,false);}public static DoubleStream stream(DoubleIterator iterator){return stream(iterator,-1);}public static DoubleStream stream(DoubleIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static DoubleStream stream(Spliterator.OfDouble spliterator){return StreamSupport.doubleStream(spliterator,false);}public static<T>Stream<T>stream(Iterator<T>iterator){return stream(iterator,-1);}public static<T>Stream<T>stream(Iterator<T>iterator,int estimatedSize){return stream(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>Stream<T>stream(Spliterator<T>spliterator){return StreamSupport.stream(spliterator,false);}public static<T>Map<T,Set<Integer>>invert(Collection<T>coll){Map<T,Set<Integer>>map=new HashMap<>();int i=0;for(T t:coll){Set<Integer>set=map.get(t);if(set==null){map.put(t,Collections.singleton(i));}else{if(!(set instanceof LinkedHashSet)){set=new LinkedHashSet<>(set);map.put(t,set);}set.add(i);}i++;}return Collections.unmodifiableMap(map);}public static<T>ArrayList<T>arrayListOfSize(int size){return arrayListOfSize(size,null);}public static<T>ArrayList<T>arrayListOfSize(int size,T element){return new ArrayList<>(Collections.nCopies(size,element));}public static<T>Set<T>asSet(Collection<T>uniqueElements){return asModifiableSet(Collections.unmodifiableCollection(uniqueElements));}public static<T>Set<T>asModifiableSet(Collection<T>uniqueElements){return new AbstractSet<T>(){public int size(){return uniqueElements.size();}public boolean isEmpty(){return uniqueElements.isEmpty();}public boolean contains(Object o){return uniqueElements.contains(o);}public Iterator<T>iterator(){return uniqueElements.iterator();}public Object[]toArray(){return uniqueElements.toArray();}public<T1>T1[]toArray(T1[]a){return uniqueElements.toArray(a);}public boolean add(T t){return uniqueElements.add(t);}public boolean remove(Object o){return uniqueElements.remove(o);}public boolean containsAll(Collection<?>c){return uniqueElements.containsAll(c);}public boolean addAll(Collection<?extends T>c){return uniqueElements.addAll(c);}public boolean retainAll(Collection<?>c){return uniqueElements.retainAll(c);}public boolean removeAll(Collection<?>c){return uniqueElements.removeAll(c);}public void clear(){uniqueElements.clear();}};}public static<T>Collector<T,?,Set<T>>collectToSet(){return Collectors.collectingAndThen(Collectors.toList(),Utils::asSet);}public static<T>ListIterator<T>reverseIterator(List<T>list){return reverseIterator(list.listIterator(list.size()));}public static<T>ListIterator<T>reverseIterator(ListIterator<T>it){return new ListIterator<T>(){public boolean hasNext(){return it.hasPrevious();}public T next(){return it.previous();}public boolean hasPrevious(){return it.hasNext();}public T previous(){return it.next();}public int nextIndex(){return it.previousIndex();}public int previousIndex(){return it.nextIndex();}public void remove(){it.remove();}public void set(T t){it.set(t);}public void add(T t){it.add(t);}};}public static<T>Iterable<T>reverseIterable(List<T>list){return()->reverseIterator(list);}public static Runnable nonThrowing(ThrowingRunnable<?>r){return()->{try{r.run();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Supplier<T>nonThrowing(ThrowingSupplier<T,?>r){return()->{try{return r.get();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T,R>Function<T,R>nonThrowing(ThrowingFunction<T,R,?>r){return(a)->{try{return r.apply(a);}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Predicate<T>nonThrowingPredicate(ThrowingPredicate<T,?>r){return(a)->{try{return r.test(a);}catch(Throwable e){throw new RuntimeException(e);}};}private static Map<Class,Class>primitiveClassWrappers=new HashMap<Class,Class>(){{put(boolean.class,Boolean.class);put(byte.class,Byte.class);put(short.class,Short.class);put(char.class,Character.class);put(int.class,Integer.class);put(long.class,Long.class);put(float.class,Float.class);put(double.class,Double.class);}};public static Class<?>primitiveToWrapper(Class<?>clss){return primitiveClassWrappers.getOrDefault(clss,clss);}};

interface DoubleIterator{double next();boolean hasNext();default void forEachRemaining(DoubleConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface IntIterator{int next();boolean hasNext();default void forEachRemaining(IntConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface LongIterator{long next();boolean hasNext();default void forEachRemaining(LongConsumer consumer){while(hasNext()){consumer.accept(next());}}};

@FunctionalInterface interface ThrowingFunction<T,R,E extends Throwable>{R apply(T t)throws E;};

@FunctionalInterface interface ThrowingPredicate<T,E extends Throwable>{boolean test(T t)throws E;};

@FunctionalInterface interface ThrowingRunnable<E extends Throwable>{void run()throws E;};

@FunctionalInterface interface ThrowingSupplier<T,E extends Throwable>{T get()throws E;};

class VoidOutputStream extends OutputStream{public void write(int b){return;}public void write(byte b[]){return;}public void write(byte b[],int off,int len){return;}};

class VoidPrintStream extends PrintStream{public VoidPrintStream(){super(new VoidOutputStream());}public void write(int b){return;}public void print(char[]buf){return;}public void print(String s){return;}public void print(Object obj){return;}public void println(char[]buf){return;}public void println(String s){return;}public void println(Object obj){return;}public PrintStream format(Locale l,String s,Object...objs){return this;}public PrintStream format(String s,Object...objs){return this;}};