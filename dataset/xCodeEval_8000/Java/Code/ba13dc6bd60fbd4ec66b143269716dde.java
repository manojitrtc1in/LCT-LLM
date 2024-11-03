


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


class Main{public static void main(String[]args)throws Exception{Class<?extends AbstractSubmission>clss=TaskE1.class;new TaskE1().runSubmission();}};







@ContestSubmission(ContestType.CODEFORCES)

class TaskE1 extends AbstractSubmission {

	@Override
	public void testCase() {
		int n = sc.nextInt();
		int[] rarr = new int[n];
		for (int i = 0; i < rarr.length; i++) {
			rarr[i] = sc.nextInt();
		}

		int[] S = new int[n+1];
		for (int i = 0; i < rarr.length; i++) {
			S[i+1] = S[i] + rarr[i];
		}


		long sum = Arrays.stream(rarr).sum();
		if (sum <= 1) {
			out.println(-1);
			return;
		}

		Set<Long> factors = new HashSet<>(PrimeUtils.findPrimeFactors(sum));
		debug.println(factors);

		long min = Long.MAX_VALUE;
		for (long factor : factors) {
			int la = 0;
			long res = 0;
			int[] arr = Arrays.copyOf(rarr, rarr.length);
			for (int i = 0; i < arr.length; i++) {
				la += arr[i];
				while (la >= factor) {
					la -= factor;
					int j = i+1;
					for (double k = factor / 2.0; k > 0;) {
						j--;
						k -= arr[j];
					}
					long totsum = 0;
					int ja = i;
					for (long k = factor; k > 0;) {
						long fh = Math.min(k, arr[ja]);
						k -= fh;
						arr[ja] -= fh;
						debug.println("  " + k + " " + fh + " " + ja);
						totsum += fh * Math.abs(ja - j);
						ja--;
					}

					debug.println(factor + " " + i + " " + j + ": " + totsum);

					res += totsum;
				}
			}
			min = Math.min(min, res);
		}

		out.println(min);
		
	}



	@Override
	public void init() {
		


		

		

	}











	


	
	
	
	





	
};

abstract class AbstractSubmission{public FastScanner sc;public InputStream in;public PrintStream out;public PrintStream debug;public volatile double score=0;public volatile int testCaseCount=-1;public volatile int testCaseIndex;public volatile double progress=0;public void runSubmission(){runSubmission(false);}public void runSubmission(boolean debug){runSubmission(System.in,System.out,debug);}public void runSubmission(InputStream in,PrintStream out){runSubmission(in,out,false);}public void runSubmission(InputStream in,PrintStream out,boolean debug){runSubmission(in,out,debug?System.err:new VoidPrintStream());}public void runSubmission(InputStream in,OutputStream out,OutputStream debug){this.in=in;this.sc=new FastScanner(this.in);this.out=new PrintStream(out);this.debug=debug instanceof VoidOutputStream||debug instanceof VoidPrintStream?new VoidPrintStream():new DebugPrintStream(debug);ContestType type=getType();testCaseCount=type.testCaseCount;init();if(testCaseCount<=0){testCaseCount=sc.nextInt();sc.nextLine();}testCaseIndex=0;for(testCaseIndex=1;testCaseIndex<=testCaseCount;testCaseIndex++){progress=0;this.out.printf(type.caseString,testCaseIndex,testCaseCount);testCase();}}private class DebugPrintStream extends PrintStream{public DebugPrintStream(OutputStream debug){super(debug);}private Object conv(Object obj){if(obj instanceof byte[])return Arrays.toString((byte[])obj);else if(obj instanceof char[])return Arrays.toString((char[])obj);else if(obj instanceof short[])return Arrays.toString((short[])obj);else if(obj instanceof int[])return Arrays.toString((int[])obj);else if(obj instanceof long[])return Arrays.toString((long[])obj);else if(obj instanceof float[])return Arrays.toString((float[])obj);else if(obj instanceof double[])return Arrays.toString((double[])obj);else if(obj instanceof boolean[])return Arrays.toString((int[])obj);else if(obj instanceof Object[])return Arrays.deepToString((Object[])obj);else return obj;}public void print(Object obj){super.print(conv(obj));}public void println(Object obj){super.println(conv(obj));}}public ContestType getType(){return getType(getClass());}public static ContestType getType(Class<?extends AbstractSubmission>clss){return getAnnotation(clss).value();}private static ContestSubmission getAnnotation(Class<?extends AbstractSubmission>clss){if(!clss.isAnnotationPresent(ContestSubmission.class)){throw new RuntimeException("ContestSubmission annotation not present on class "+clss.getCanonicalName()+ "!");}return clss.getAnnotation(ContestSubmission.class);}public abstract void testCase();public abstract void init();};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface CacheVersion{int value();};

@Retention(RetentionPolicy.RUNTIME)@Target(ElementType.TYPE)@interface ContestSubmission{ContestType value();};

enum ContestType{PLAIN("",-1),ETH_JUDGE("",-1,null,false,false,6),GOOGLE("Case #%d: ",-1),GOOGLE_JAM("Case #%d: ",-1, "Solution.java",false,false,8),GOOGLE_JAM_INTERACTIVE("",-1, "Solution.java",false,false,8),FACEBOOK("Case #%d: ",-1),BLOOMBERG("",1, "Problem.java",false,false,8),SINGLE_TESTCASE("",1),OPTIMIZER("",1,null,false,false,8,true),HACKERRANK("",1, "Solution.java",false,false,8),CODEFORCES("",1, "Solution.java",false,false,8);public int testCaseCount;public String caseString;public String launcher;public boolean disableCompression;public boolean keepUnusedDependencies;public int javaVersion;public boolean isOptimizer;ContestType(String caseString,int testCaseCount,String launcher,boolean disableCompression,boolean keepUnusedDependencies,int javaVersion,boolean isOptimizer){this.caseString=caseString;this.testCaseCount=testCaseCount;this.launcher=launcher;this.disableCompression=disableCompression;this.javaVersion=javaVersion;this.keepUnusedDependencies=keepUnusedDependencies;this.isOptimizer=isOptimizer;}ContestType(String a1,int a2,String a3,boolean a4,boolean a5,int a6){this(a1,a2,a3,a4,a5,a6,false);}ContestType(String a1,int a2){this(a1,a2,null,false,false,8);}};

class FastScanner{private static String spaceDelimiters= " \t\n\r\f";private BufferedReader buffer;private StringTokenizer tokenizer;private InputStream stream;public FastScanner(InputStream stream){this.stream=stream;}public String nextLine(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}String res=tokenizer.nextToken("");if(!res.endsWith("\n"))throw new RuntimeException("waddaheq just heppenenened");res=res.substring(0,res.length()-1);if(res.contains("\n"))throw new RuntimeException("oke wat lamo");tokenizer=null;return res;}public String next(){if(this.buffer==null)this.buffer=new BufferedReader(new InputStreamReader(stream));while(tokenizer==null||!tokenizer.hasMoreTokens()){try{tokenizer=new StringTokenizer(buffer.readLine()+ "\n");}catch(IOException e){throw new RuntimeException("IO exception occured!",e);}}return tokenizer.nextToken(spaceDelimiters);}public BigDecimal nextBigDecimal(){return new BigDecimal(next());}public BigInteger nextBigInteger(){return new BigInteger(next());}public int nextInt(){return Integer.parseInt(next());}public long nextLong(){return Long.parseLong(next());}public double nextDouble(){return Double.parseDouble(next());}};

@Retention(RetentionPolicy.SOURCE)@Target(ElementType.METHOD)@interface O{String value();};

@Target(ElementType.FIELD)@Retention(RetentionPolicy.RUNTIME)@interface Optimize{long imin()default 0;long imax()default 100;double fmin()default 0;double fmax()default 1;};

class PrimeUtils{public static boolean[]getPrimeTable(Range range){return getPrimeTable(range.toLongRange());}public static boolean[]getPrimeTable(LongRange range){if(range.size()>=Integer.MAX_VALUE)throw new IllegalArgumentException("Distance between L and R may not exceed Integer.MAX_VALUE!");long L=range.a;long R=range.b-1;boolean[]primeFacts=new boolean[(int)(R-L+1)];for(int i=0;i<primeFacts.length;i++){primeFacts[i]=true;}if(L==0&&R>=0)primeFacts[0]=false;if(L<=1&&R>=1)primeFacts[(int)(1-L)]=false;boolean[]primeTable=L==0?primeFacts:getPrimeTable(new LongRange(0,(long)Math.sqrt(range.b)+1));for(long i=2;i*i<=R;i++){if(!primeTable[(int)i])continue;for(long j=Math.max(i,MathUtils.ceilDiv(L,i));j*i<=R;j++){primeFacts[(int)(j*i-L)]=false;}}return primeFacts;}public static boolean isProbablePrime(long l,int certainty){return BigInteger.valueOf(l).isProbablePrime(certainty);}public static boolean isPrime(long l){return isProbablePrime(l,100);}public static long findPrimeFactor(long l){return findSmallestOddFactor(l,1,l);}private static long findSmallestOddFactor(long l,long min,long max){if(min<=2){if(l%2==0)return 2;min=3;}max=Math.min(max,(long)Math.sqrt(l)+1);for(long i=min;i<max;i+=2){if(l%i==0)return i;}return l;}public static List<Long>findPrimeFactors(long l){return findPrimeFactors(l,l);}public static List<Long>findPrimeFactors(long l,long max){if(PrimeUtils.isPrime(l))return new ArrayList<>(Arrays.asList(l));List<Long>result=new ArrayList<>();long pf=1;while(l>1&&l<=max){pf=findSmallestOddFactor(l,pf,l);result.add(pf);l/=pf;}return result;}public static boolean isProbablePrime(BigInteger l,int certainty){return l.isProbablePrime(certainty);}public static boolean isPrime(BigInteger l){return isProbablePrime(l,100);}public static BigInteger findPrimeFactor(BigInteger l){return findSmallestOddFactor(l,BigInteger.ONE,l);}private static BigInteger findSmallestOddFactor(BigInteger l,BigInteger min,BigInteger max){if(min.compareTo(BigInteger.valueOf(2))<=0){if(l.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))return BigInteger.valueOf(2);min=BigInteger.valueOf(3);}for(BigInteger i=min;i.compareTo(max)<0&&i.multiply(i).compareTo(l)<=0;i=i.add(BigInteger.valueOf(2))){if(l.mod(i).equals(BigInteger.ZERO))return i;}return l;}public static List<BigInteger>findPrimeFactors(BigInteger l){return findPrimeFactors(l,l);}public static List<BigInteger>findPrimeFactors(BigInteger l,BigInteger max){if(PrimeUtils.isPrime(l))return new ArrayList<>(Arrays.asList(l));List<BigInteger>result=new ArrayList<>();BigInteger pf=BigInteger.ONE;while(l.compareTo(BigInteger.ONE)>0&&l.compareTo(max)<=0){pf=findSmallestOddFactor(l,pf,l);result.add(pf);l=l.divide(pf);}return result;}};

class LongRange extends Pair<Long,Long>implements Iterable<Long>{public LongRange(long i,long j){super(i,j);}public LongRange(LongRange range){this(range.a,range.b);}public long size(){return this.b-this.a;}public long[]toLongArray(){return this.stream().toArray();}public Range toIntRange(){return new Range((int)(long)this.a,(int)(long)this.b);}public LongStream stream(){return LongStream.range(a,b);}public Iterator<Long>iterator(){return new PolyfillIterator<Long>(){long c=getLeft();public boolean hasNext(){return c<getRight();}public Long next(){return c++;}};}public boolean contains(long l){return l>=this.a&&l<this.b;}public void intersectWith(LongRange range){a=Math.max(range.a,a);b=Math.min(range.b,b);}public LongRange intersectedWith(LongRange range){LongRange res=new LongRange(this);res.intersectWith(range);return res;}public static LongRange getIntersection(LongRange...a){return Arrays.stream(a).reduce((res,b)->res.intersectedWith(b)).get();}public void ensureValidity()throws IllegalArgumentException{if(this.b<this.a)throw new IllegalArgumentException("Second argument of range ("+this.a+ ", "+this.b+ ") must be larger than first");}};

class MathUtils{private MathUtils(){}public static int[]splitIntoArray(int i,int[]max){int[]res=new int[max.length];for(int j=max.length-1;j>=0;j--){res[j]=i%max[j];i/=max[j];}return res;}public static int mergeIntoInteger(int[]arr,int[]max){int result=0;for(int i=0;i<max.length;i++){result*=max[i];result+=arr[i];}return result;}public static int foldl(IntBinaryOperator operator,int...vals){int result=vals[0];for(int i=1;i<vals.length;i++){result=operator.applyAsInt(result,vals[i]);}return result;}public static int min(int a,int b){return Math.min(a,b);}public static int max(int a,int b){return Math.max(a,b);}public static int min(int a,int b,int c){return Math.min(a,Math.min(b,c));}public static int max(int a,int b,int c){return Math.max(a,Math.max(b,c));}public static int min(int...vals){return foldl(Math::min,vals);}public static int max(int...vals){return foldl(Math::max,vals);}public static int sum(int...vals){int result=0;for(int v:vals){result+=v;}return result;}public static int prod(int...vals){int result=1;for(int v:vals){result*=v;}return result;}public static int factorial(int n){if(n<=1)return 1;return n*factorial(n-1);}public static boolean doubleEquals(double a,double b){return a==b||(Double.isNaN(a)&&Double.isNaN(b));}public static int pow(int a,int exponent){if(exponent<0)return 0;if(exponent==0)return 1;if((a&(a-1))==0)return a<<(exponent-1);if(exponent%2==0)return sq(pow(a,exponent/2));return pow(a,exponent-1)*a;}public static long pow(long a,long exponent){if(a==2)return 1l<<exponent;if(exponent<0)return 0;if(exponent==0)return 1;if(exponent%2==0)return sq(pow(a,exponent/2));return pow(a,exponent-1)*a;}public static double pow(double a,double exponent){return Math.pow(a,exponent);}public static int sq(int a){return a*a;}public static long sq(long a){return a*a;}public static double sq(double a){return a*a;}public static int realMod(int i,int mod){return MathUtils.floorMod(i,mod);}public static long realMod(long i,long mod){return MathUtils.floorMod(i,mod);}public static int floorDiv(int a,int b){return Math.floorDiv(a,b);}public static long floorDiv(long a,long b){return Math.floorDiv(a,b);}public static int floorMod(int a,int b){return Math.floorMod(a,b);}public static long floorMod(long a,long b){return Math.floorMod(a,b);}public static int ceilDiv(int a,int b){return Math.floorDiv(a+b-1,b);}public static long ceilDiv(long a,long b){return Math.floorDiv(a+b-1,b);}public static int ceilMod(int a,int b){return a-ceilDiv(a,b)*b;}public static long ceilMod(long a,long b){return a-ceilDiv(a,b)*b;}public static long modMul(long a,long b,long mod){a=realMod(a,mod);if(a==0)return 0;b=realMod(b,mod);if(b<=Long.MAX_VALUE/a){return MathUtils.realMod(a*b,mod);}return BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).mod(BigInteger.valueOf(mod)).longValueExact();}public static long modAdd(long a,long b,long mod){a=realMod(a,mod);b=realMod(b,mod);return realMod(a-mod+b,mod);}};

class Pair<A,B>extends Tuple implements Map.Entry<A,B>{public A a;public B b;public Pair(A a,B b){this.a=a;this.b=b;}public A getLeft(){return a;}public B getRight(){return b;}public void setLeft(A a){this.a=a;}public void setRight(B b){this.b=b;}public<A1,B1>Pair<A1,B1>map(Function<A,A1>mapA,Function<B,B1>mapB){return new Pair<A1,B1>(mapA.apply(this.a),mapB.apply(this.b));}public A getKey(){return a;}public A setKey(A a){A old=this.a;this.a=a;return old;}public B getValue(){return b;}public B setValue(B b){B old=this.b;this.b=b;return old;}public Object[]toArray(){return new Object[]{a,b};}public boolean equals(Object other){if(!(other instanceof Pair))return super.equals(other);Pair pair=(Pair)other;return Utils.equals(this.a,pair.a)&&Utils.equals(this.b,pair.b);}public int hashCode(){return 961+31*Utils.hashCode(a)+Utils.hashCode(b);}};

abstract class PolyfillIterator<T>implements Iterator<T>{};

class Range extends Pair<Integer,Integer>implements Iterable<Integer>{public Range(int i,int j){super(i,j);}public Range(Range range){this(range.a,range.b);}public int size(){return this.b-this.a;}public int[]toIntArray(){return this.stream().toArray();}public LongRange toLongRange(){return new LongRange(this.a,this.b);}public IntStream stream(){return IntStream.range(a,b);}public Iterator<Integer>iterator(){return new PolyfillIterator<Integer>(){int c=getLeft();public boolean hasNext(){return c<getRight();}public Integer next(){return c++;}};}public boolean contains(int l){return l>=this.a&&l<this.b;}public void intersectWith(Range range){a=Math.max(range.a,a);b=Math.min(range.b,b);}public Range intersectedWith(Range range){Range res=new Range(this);res.intersectWith(range);return res;}public static Range getIntersection(Range...a){return Arrays.stream(a).reduce((res,b)->res.intersectedWith(b)).get();}public void ensureValidity()throws IllegalArgumentException{if(this.b<this.a)throw new IllegalArgumentException("Second argument of range ("+this.a+ ", "+this.b+ ") must be larger than first");}};

abstract class Tuple extends Structure{public abstract Object[]toArray();public boolean equals(Object obj){if(obj==null)return false;if(!(obj instanceof Tuple))return false;return Arrays.equals(this.toArray(),((Tuple)obj).toArray());}public int hashCode(){return Arrays.hashCode(this.toArray());}public String toString(){Object[]els=toArray();String[]elements=new String[els.length];for(int i=0;i<els.length;i++){elements[i]= ""+els[i];}return  "("+String.join(", ",elements)+ ")";}};

abstract class Structure implements Serializable,Cloneable{public Structure clone(){try{Structure struct=(Structure)super.clone();for(Field field:this.getClass().getDeclaredFields()){field.setAccessible(true);if(Modifier.isTransient(field.getModifiers())){continue;}field.set(struct,field.get(this));}return struct;}catch(CloneNotSupportedException e){throw new AssertionError("Cloning a structure should always be supported - please report this bug",e);}catch(IllegalAccessException e){throw new RuntimeException("Can't access my own elements!",e);}}private NavigableMap<String,Object>getFields(){try{NavigableMap<String,Object>result=new TreeMap<String,Object>();for(Field field:this.getClass().getFields()){if(Modifier.isTransient(field.getModifiers())){continue;}result.put(field.getName(),field.get(this));}return result;}catch(IllegalAccessException e){throw new RuntimeException("Can't access my own elements!",e);}}public boolean equals(Object obj){if(obj==null)return false;if(getClass()!=obj.getClass())return false;return getFields().equals(((Structure)obj).getFields());}public int hashCode(){return getFields().hashCode();}public String toString(){return getFields().toString();}};

class Tree<T>implements Serializable{private TreeNode<T>root;Pair<Double,DoubleBinaryOperator>distanceFolder;public Tree(T rootValue){this(rootValue,null);}public Tree(T rootValue,Pair<Double,DoubleBinaryOperator>distanceFolder){this(distanceFolder);initRoot(new TreeNode<T>(rootValue,this));}protected Tree(){this((Pair<Double,DoubleBinaryOperator>)null);}protected Tree(Pair<Double,DoubleBinaryOperator>distanceFolder){this.distanceFolder=distanceFolder==null?new Pair<Double,DoubleBinaryOperator>(0.0,Double::sum):distanceFolder;}protected void initRoot(TreeNode<T>node){if(root!=null)throw new IllegalStateException("Can't modify the root after it has already been initialized!");this.root=node;}public TreeNode<T>getRoot(){return root;}public List<TreeNode<T>>leafNodes(){return getRoot().leafNodes();}public List<TreeNode<T>>preOrder(){return getRoot().preOrder();}public List<TreeNode<T>>postOrder(){return getRoot().postOrder();}public String toString(){return root.toString();}};

class TreeNode<T>implements Serializable{private T value;private int height;private double distance;private double distanceToParent;private List<TreeNode<T>>children;private TreeNode<T>parent;private Tree<T>tree;public TreeNode(T value){this(value,null);}protected TreeNode(T value,Tree<T>tree){this.value=value;this.parent=null;this.tree=tree;this.children=new ArrayList<TreeNode<T>>(5);this.height=0;this.distance=tree.distanceFolder.a;}protected TreeNode(T value,TreeNode<T>parent,double distanceToParent){this.value=value;this.parent=parent;this.tree=parent.tree;this.children=new ArrayList<TreeNode<T>>();this.height=parent.getHeight()+1;this.distanceToParent=distanceToParent;this.distance=tree.distanceFolder.b.applyAsDouble(parent.getDistance(),distanceToParent);}public T getValue(){return value;}public void setValue(T value){this.value=value;}public int getHeight(){return height;}public double getDistance(){return distance;}public double getDistanceToParent(){if(!hasParent())throw new NoSuchElementException("Node has no parent!");return this.distanceToParent;}public List<TreeNode<T>>getChildren(){return this.children.size()==0?Collections.emptyList():Collections.unmodifiableList(children);}public int getChildCount(){return children.size();}public TreeNode<T>addChild(T value){return addChild(value,1);}public TreeNode<T>addChild(T value,double distance){return createUnattached(value,distance).attach();}public TreeNode<T>.Unattached createUnattached(T value,double distance){return new Unattached(value,distance);}class Unattached extends TreeNode<T>{private boolean isAttached=false;private Unattached(T value,double distance){super(value,TreeNode.this,distance);}public TreeNode<T>attach(){if(isAttached())throw new NoSuchElementException("Node has already been attached!");TreeNode.this.children.add(this);isAttached=true;return this;}public boolean isAttached(){return isAttached;}}public TreeNode<T>getParent(){return parent;}public List<TreeNode<T>>getParentChain(){List<TreeNode<T>>res=new ArrayList<TreeNode<T>>();TreeNode<T>node=this;while((node=node.getParent())!=null){res.add(node);}Collections.reverse(res);return res;}public boolean hasParent(){return getParent()!=null;}public Tree<T>getTree(){return tree;}public boolean isAttached(){return true;}public List<TreeNode<T>>leafNodes(){return traverse(2);}public List<TreeNode<T>>preOrder(){return traverse(0);}public List<TreeNode<T>>postOrder(){return traverse(1);}private List<TreeNode<T>>traverse(int mode){List<TreeNode<T>>list=new ArrayList<TreeNode<T>>();traverse(list,mode);return list;}private void traverse(List<TreeNode<T>>list,int mode){Queue<TreeNode<T>>queue=QueueUtils.createLIFO();queue.add(this);while(!queue.isEmpty()){TreeNode<T>n=queue.remove();if(mode!=2||n.getChildCount()==0)list.add(n);Iterable<TreeNode<T>>children=mode==1?n.getChildren():Utils.reverseIterable(n.getChildren());for(TreeNode<T>child:children){queue.add(child);}}if(mode==1)Collections.reverse(list);}public String toString(){return(""+value)+(children.isEmpty()? "":children.toString());}};

class QueueUtils{public static<T>Queue<T>createFIFO(){return new ArrayDeque<>();}public static<T>Queue<T>createLIFO(){return Collections.asLifoQueue(new ArrayDeque<>());}public static<T>Queue<T>createStack(){return createLIFO();}public static<T extends Comparable<?super T>>Queue<T>createPriority(){return new PriorityQueue<>();}public static<T>Queue<T>createPriority(Comparator<?super T>comparator){return new PriorityQueue<>(comparator);}public static<T,U extends Comparable<?super U>>Queue<T>createPriority(Function<?super T,?extends U>keyExtractor){return createPriority(Comparator.comparing(keyExtractor));}};

class Utils{private Utils(){}public static boolean equals(int a,int b){return a==b;}public static boolean equals(long a,long b){return a==b;}public static boolean equals(double a,double b){return Double.doubleToLongBits(a)==Double.doubleToLongBits(b);}public static boolean equals(Object a,Object b){return Objects.equals(a,b);}public static int hashCode(int a){return Integer.hashCode(a);}public static int hashCode(long a){return Long.hashCode(a);}public static int hashCode(double a){return Double.hashCode(a);}public static int hashCode(Object a){return Objects.hashCode(a);}public static int compare(int a,int b){return Integer.compare(a,b);}public static int compare(long a,long b){return Long.compare(a,b);}public static int compare(double a,double b){return Double.compare(a,b);}public static<T extends Comparable<?super T>>int compare(T a,T b){return Objects.compare(a,b,Comparator.naturalOrder());}public static void repeat(int times,Consumer<Integer>consumer){for(int i=0;i<times;i++){consumer.accept(i);}}public static void repeat(int times,Runnable runnable){repeat(times,(a)->runnable.run());}public static<E extends Throwable>double timing(ThrowingRunnable<E>runnable)throws E{long start=System.nanoTime();runnable.run();long end=System.nanoTime();return(end-start)/1_000_000_000.0;}private static int timingId=0;public static<T,E extends Throwable>T printTiming(ThrowingSupplier<T,E>supplier,String name)throws E{int tid=timingId++;if(name==null)name= ""+tid;else name=tid+ " - "+name;System.err.println("Starting task "+name);long start=System.nanoTime();try{return supplier.get();}finally{long end=System.nanoTime();System.err.println("Time taken for task "+name+ ": "+(end-start)/1_000_000_000.0+ "s");}}public static<E extends Throwable>void printTiming(ThrowingRunnable<E>runnable,String name)throws E{printTiming(()->{runnable.run();return null;},name);}public static<E extends Throwable>void printTiming(ThrowingRunnable<E>runnable)throws E{printTiming(runnable,null);}public static<T,E extends Throwable>T printTiming(ThrowingSupplier<T,E>supplier)throws E{return printTiming(supplier,null);}public static<T>ArrayList<T>toArrayList(Iterable<T>iterable){int size=iterable instanceof Collection?((Collection)iterable).size():-1;return toArrayList(iterable,size);}public static<T>ArrayList<T>toArrayList(Iterable<T>iterable,int size){return toArrayList(iterable.iterator(),size);}public static<T>ArrayList<T>toArrayList(Iterator<T>iterator){return toArrayList(iterator,-1);}public static<T>ArrayList<T>toArrayList(Iterator<T>iterator,int estimatedSize){return toArrayList(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>ArrayList<T>toArrayList(Spliterator<T>spliterator){long estimatedSize=spliterator.estimateSize();if(estimatedSize>=Long.MAX_VALUE||estimatedSize<=10)estimatedSize=10;ArrayList<T>result=new ArrayList<>((int)Math.min(estimatedSize,Integer.MAX_VALUE));spliterator.forEachRemaining(result::add);return result;}public static PrimitiveIterator.OfInt toPrimitiveIterator(IntIterator iterator){return new PrimitiveIterator.OfInt(){public int nextInt(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfLong toPrimitiveIterator(LongIterator iterator){return new PrimitiveIterator.OfLong(){public long nextLong(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static PrimitiveIterator.OfDouble toPrimitiveIterator(DoubleIterator iterator){return new PrimitiveIterator.OfDouble(){public double nextDouble(){return iterator.next();}public boolean hasNext(){return iterator.hasNext();}};}public static IntStream stream(IntIterator iterator){return stream(iterator,-1);}public static IntStream stream(IntIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static IntStream stream(Spliterator.OfInt spliterator){return StreamSupport.intStream(spliterator,false);}public static LongStream stream(LongIterator iterator){return stream(iterator,-1);}public static LongStream stream(LongIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static LongStream stream(Spliterator.OfLong spliterator){return StreamSupport.longStream(spliterator,false);}public static DoubleStream stream(DoubleIterator iterator){return stream(iterator,-1);}public static DoubleStream stream(DoubleIterator iterator,int estimatedSize){return stream(Spliterators.spliterator(Utils.toPrimitiveIterator(iterator),estimatedSize,Spliterator.ORDERED));}public static DoubleStream stream(Spliterator.OfDouble spliterator){return StreamSupport.doubleStream(spliterator,false);}public static<T>Stream<T>stream(Iterator<T>iterator){return stream(iterator,-1);}public static<T>Stream<T>stream(Iterator<T>iterator,int estimatedSize){return stream(Spliterators.spliterator(iterator,estimatedSize,Spliterator.ORDERED));}public static<T>Stream<T>stream(Spliterator<T>spliterator){return StreamSupport.stream(spliterator,false);}public static<T>Map<T,Set<Integer>>invert(Collection<T>coll){Map<T,Set<Integer>>map=new HashMap<>();int i=0;for(T t:coll){Set<Integer>set=map.get(t);if(set==null){map.put(t,Collections.singleton(i));}else{if(!(set instanceof LinkedHashSet)){set=new LinkedHashSet<>(set);map.put(t,set);}set.add(i);}i++;}return Collections.unmodifiableMap(map);}public static<T>ArrayList<T>arrayListOfSize(int size){return arrayListOfSize(size,null);}public static<T>ArrayList<T>arrayListOfSize(int size,T element){ArrayList<T>result=new ArrayList<T>(size);for(int i=0;i<size;i++){result.add(element);}return result;}public static<T>int hashAll(Iterator<T>iterator){int hash=1;while(iterator.hasNext()){T obj=iterator.next();hash=hash*31+Objects.hashCode(obj);}return hash;}public static<T>Set<T>asSet(Collection<T>uniqueElements){return asModifiableSet(Collections.unmodifiableCollection(uniqueElements));}public static<T>Set<T>asModifiableSet(Collection<T>uniqueElements){return new AbstractSet<T>(){public int size(){return uniqueElements.size();}public boolean isEmpty(){return uniqueElements.isEmpty();}public boolean contains(Object o){return uniqueElements.contains(o);}public Iterator<T>iterator(){return uniqueElements.iterator();}public Object[]toArray(){return uniqueElements.toArray();}public<T1>T1[]toArray(T1[]a){return uniqueElements.toArray(a);}public boolean add(T t){return uniqueElements.add(t);}public boolean remove(Object o){return uniqueElements.remove(o);}public boolean containsAll(Collection<?>c){return uniqueElements.containsAll(c);}public boolean addAll(Collection<?extends T>c){return uniqueElements.addAll(c);}public boolean retainAll(Collection<?>c){return uniqueElements.retainAll(c);}public boolean removeAll(Collection<?>c){return uniqueElements.removeAll(c);}public void clear(){uniqueElements.clear();}};}public static<T>Collector<T,?,Set<T>>collectToSet(){return Collectors.collectingAndThen(Collectors.toList(),Utils::asSet);}public static<T>ListIterator<T>reverseIterator(List<T>list){return reverseIterator(list.listIterator(list.size()));}public static<T>ListIterator<T>reverseIterator(ListIterator<T>it){return new ListIterator<T>(){public boolean hasNext(){return it.hasPrevious();}public T next(){return it.previous();}public boolean hasPrevious(){return it.hasNext();}public T previous(){return it.next();}public int nextIndex(){return it.previousIndex();}public int previousIndex(){return it.nextIndex();}public void remove(){it.remove();}public void set(T t){it.set(t);}public void add(T t){it.add(t);}};}public static Runnable nonThrowing(ThrowingRunnable<?>r){return()->{try{r.run();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Supplier<T>nonThrowing(ThrowingSupplier<T,?>r){return()->{try{return r.get();}catch(Throwable e){throw new RuntimeException(e);}};}public static<T,R>Function<T,R>nonThrowing(ThrowingFunction<T,R,?>r){return(a)->{try{return r.apply(a);}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Predicate<T>nonThrowingPredicate(ThrowingPredicate<T,?>r){return(a)->{try{return r.test(a);}catch(Throwable e){throw new RuntimeException(e);}};}public static<T>Iterable<T>reverseIterable(List<T>list){return()->reverseIterator(list);}private static Map<Class,Class>primitiveClassWrappers=new HashMap<Class,Class>(){{put(boolean.class,Boolean.class);put(byte.class,Byte.class);put(short.class,Short.class);put(char.class,Character.class);put(int.class,Integer.class);put(long.class,Long.class);put(float.class,Float.class);put(double.class,Double.class);}};public static Class<?>primitiveToWrapper(Class<?>clss){return primitiveClassWrappers.getOrDefault(clss,clss);}};

interface DoubleIterator{double next();boolean hasNext();default void forEachRemaining(DoubleConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface IntIterator{int next();boolean hasNext();default void forEachRemaining(IntConsumer consumer){while(hasNext()){consumer.accept(next());}}};

interface LongIterator{long next();boolean hasNext();default void forEachRemaining(LongConsumer consumer){while(hasNext()){consumer.accept(next());}}};

@FunctionalInterface interface ThrowingFunction<T,R,E extends Throwable>{R apply(T t)throws E;};

@FunctionalInterface interface ThrowingPredicate<T,E extends Throwable>{boolean test(T t)throws E;};

@FunctionalInterface interface ThrowingRunnable<E extends Throwable>{void run()throws E;};

@FunctionalInterface interface ThrowingSupplier<T,E extends Throwable>{T get()throws E;};

class VoidOutputStream extends OutputStream{public void write(int b){return;}public void write(byte b[]){return;}public void write(byte b[],int off,int len){return;}};

class VoidPrintStream extends PrintStream{public VoidPrintStream(){super(new VoidOutputStream());}public void write(int b){return;}public void print(char[]buf){return;}public void print(String s){return;}public void print(Object obj){return;}public void println(char[]buf){return;}public void println(String s){return;}public void println(Object obj){return;}public PrintStream format(Locale l,String s,Object...objs){return this;}public PrintStream format(String s,Object...objs){return this;}};