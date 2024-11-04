import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.io.Writer;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class etask{ 

	public static void main(String[] args) {
		
		    InputStream inputStream=System.in;
            OutputStream outputStream=System.out;
            InputReader in=new InputReader(inputStream);
            OutputWriter out=new OutputWriter(outputStream);
            NumberTheory nt=new NumberTheory();
            etask solver = new etask();
            solver.solve(in,out,nt);
            out.flush();
            out.close();

        
	}

	public void solve(InputReader in,OutputWriter out,NumberTheory nt){
		
				
				int n = in.ni() , m = in.ni();
				int size = n/m;
				long[] arr = in.nla(n);
				

				int[] mod = new int[n];

				Queue<Integer>[] list = new Queue[m];
				for(int i = 0;i < m;i++)
					list[i] =  new LinkedList<Integer>();

				
				int[] sizeoflist = new int[m];
				for(int i = 0;i < n;i++){
					mod[i] = (int)(arr[i]%m);
					

					list[mod[i]].add(i);
					sizeoflist[mod[i]]++;
					

				}

				

				

				
				Stack<Integer> extra = new Stack<Integer>();
				Queue<Integer> index = new LinkedList<Integer>();
				long steps = 0;
				
				for(int i = 0;i < m;i++){
					
						while( list[i].size() > size){
							extra.add(list[i].poll());
							sizeoflist[i]--;
						}
						while(list[i].size() < size && extra.size() > 0){ 
							

							int ele = extra.pop();
							int modofele = mod[ele];
							int diff = (i-(modofele));
							

							steps += diff;
							arr[ele] += diff;
							list[i].add(ele);
							sizeoflist[i]++;
					}
						
				}
				
				for(int i = 0;i < m;i++){
					while(list[i].size() < size){
							int ele = extra.pop();
							int modofele = mod[ele];
							int diff = (i-(modofele));
							steps += (m+diff);
							arr[ele] += (m+diff);
							list[i].add(ele);
							sizeoflist[i]++;
					}
				}

				out.println(steps);
				out.println(arr);

	}

}

	class InputReader{
            private boolean finished = false;
            private InputStream stream;
            private byte[] buf = new byte[1024];
            private int curChar;
            private int numChars;
            private SpaceCharFilter filter;
            public InputReader(InputStream stream) {
                this.stream = stream;
            }
            public int read() {
                if (numChars == -1) {
                    throw new InputMismatchException();
                }
                if (curChar >= numChars) {
                    curChar = 0;
                    try {
                        numChars = stream.read(buf);
                    } catch (IOException e) {
                        throw new InputMismatchException();
                    }
                    if (numChars <= 0) {
                        return -1;
                    }
                }
                return buf[curChar++];
            }
            public int peek() {
                if (numChars == -1) {
                    return -1;
                }
                if (curChar >= numChars) {
                    curChar = 0;
                    try {
                        numChars = stream.read(buf);
                    } catch (IOException e) {
                        return -1;
                    }
                    if (numChars <= 0) {
                        return -1;
                    }
                }
                return buf[curChar];
            }
            public  int ni() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!isSpaceChar(c));
                return res * sgn;
            }
            public long nl() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!isSpaceChar(c));
                return res * sgn;
            }
            public String nextString() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!isSpaceChar(c));
                return res.toString();
            }
            public boolean isSpaceChar(int c) {
                if (filter != null) {
                    return filter.isSpaceChar(c);
                }
                return isWhitespace(c);
            }
            public static boolean isWhitespace(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }
            private String readLine0() {
                StringBuilder buf = new StringBuilder();
                int c = read();
                while (c != '\n' && c != -1) {
                    if (c != '\r') {
                        buf.appendCodePoint(c);
                    }
                    c = read();
                }
                return buf.toString();
            }
            public String readLine() {
                String s = readLine0();
                while (s.trim().length() == 0) {
                    s = readLine0();
                }
                return s;
            }
            public String readLine(boolean ignoreEmptyLines) {
                if (ignoreEmptyLines) {
                    return readLine();
                } else {
                    return readLine0();
                }
            }
            public BigInteger readBigInteger() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }
            public char nc() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                return (char) c;
            }
            public double nd() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!isSpaceChar(c) && c != '.') {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, ni());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                }
                if (c == '.') {
                    c = read();
                    double m = 1;
                    while (!isSpaceChar(c)) {
                        if (c == 'e' || c == 'E') {
                            return res * Math.pow(10, ni());
                        }
                        if (c < '0' || c > '9') {
                            throw new InputMismatchException();
                        }
                        m /= 10;
                        res += (c - '0') * m;
                        c = read();
                    }
                }
                return res * sgn;
            }
            public boolean isExhausted() {
                int value;
                while (isSpaceChar(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }
            public String next() {
                return nextString();
            }
            public SpaceCharFilter getFilter() {
                return filter;
            }
            public void setFilter(SpaceCharFilter filter) {
                this.filter = filter;
            }
            public interface SpaceCharFilter {
                public boolean isSpaceChar(int ch);
            }
            public int[] nia(int n){
                int[] array=new int[n];
                for(int i=0;i<n;++i)array[i]=ni();
                return array;
            }
            public int[] nSortedia(int n){
                int array[]=nia(n);
                Arrays.sort(array);
                return array;
            }
            public int[] nSumia(int n){
                int[] array=new int[n];
                array[0]=ni();
                for(int i=1;i<n;++i)array[i]=array[i-1]+ni();
                return array;
            }
            public long Sumia(int[] arr){
            	long sum = 0;
                for(int i=1;i<arr.length;++i)sum += arr[i];
                return sum;
            }
            public long Sumla(long[] arr){
            	long sum = 0;
                for(int i=1;i<arr.length;++i)sum += arr[i];
                return sum;
            }
            public long[] nla(int n){
                long[] array=new long[n];
                for(int i=0;i<n;++i)array[i]=nl();
                return array;
            }
            public long[] nSumla(int n){
                long[] array=new long[n];
                array[0]=ni();
                for(int i=1;i<n;++i)array[i]=array[i-1]+ni();
                return array;
            }
            public long[] nSortedla(int n){
                long array[]=nla(n);
                Arrays.sort(array);
                return array;
            }
            public int[][] n2dia(int n,int m){
                int[][] matrix=new int[n][m];
                for(int i=0;i<n;++i)
                    for(int j=0;j<m;++j)
                        matrix[i][j]=ni();
                return matrix;
            }
            public long[][] n2dla(int n,int m){
                long[][] matrix=new long[n][m];
                for(int i=0;i<n;++i)
                    for(int j=0;j<m;++j)
                        matrix[i][j]=nl();
                return matrix;
            }
            public char[][] nextCharMatrix(int n,int m){
                char[][] matrix=new char[n][m];
                for(int i=0;i<n;++i)
                    matrix[i]=next().toCharArray();
                return matrix;
            }
            public int[] prefixSumInt(int[] arr){
            	int n = arr.length;
            	int[] result = new int[n];
            	result[0] = arr[0];
            	for(int i = 1;i < n;i++){
            		result[i] = result[i-1] + arr[i];
            	}
            	return result;
            }
            public long[] prefixSumLong(long[] arr){
            	int n = arr.length;
            	long[] result = new long[n];
            	result[0] = arr[0];
            	for(int i = 1;i < n;i++){
            		result[i] = result[i-1] + arr[i];
            	}
            	return result;
            }

	}


	class NumberTheory{

            public int modularAddition(int a,int b,int MOD){
                return (a%MOD+b%MOD)%MOD;
            }
            public long modularAddition(long a,long b,long MOD){
                return (a%MOD+b%MOD)%MOD;
            }
            

            public int modularMultiplication(int a,int b,int MOD){
                return ((a%MOD)*(b%MOD))%MOD;
            }
            public long modularMultiplication(long a,long b,long MOD){
                return ((a%MOD)*(b%MOD))%MOD;
            }
            

            public int modularSubtraction(int a,int b,int MOD){
                return (a%MOD-b%MOD+MOD)%MOD;
            }
            public long modularSubtraction(long a,long b,long MOD){
                return (a%MOD-b%MOD+MOD)%MOD;
            }
            public int binaryExponentiation(int x,int n){
                if(n==0)return 1;
                else if(n%2==0)return binaryExponentiation(x*x,n/2);
                else return x*binaryExponentiation(x*x,(n-1)/2);
            }
            public long binaryExponentiation(long x,long n){
                long result=1;
                while(n>0){
                    if(n%2==1)result*=x;
                    x=x*x;
                    n/=2;
                }
                return result;
            }
            
            public int modularExponentiation(int x,int n,int MOD){
                if(n==0)return 1%MOD;
                else if(n%2==0)return modularExponentiation(modularMultiplication(x,x,MOD),n/2,MOD);
                else return modularMultiplication(x,modularExponentiation(modularMultiplication(x,x,MOD),(n-1)/2,MOD),MOD);
            }
            public long modularExponentiation(long x,long n,long MOD){
                long result=1;
                while(n>0){
                    if(n%2==1)result=modularMultiplication(result,x,MOD);
                    x=modularMultiplication(x,x,MOD);
                    n/=2;
                }
                return result;
            }
            
            public long factorials(long n){
                if(n==0)return 1;
                return n*factorials(n-1);
            }
            
            public ArrayList<Integer> distinctPrimeFactors(int n){
                ArrayList<Integer> factorials=new ArrayList<>();
                int limit=(int)Math.sqrt(n);
                if(n%2==0){
                    factorials.add(2);
                    while(n%2==0)n/=2;
                }
                for(int i=3;i<=limit;i+=2){
                    if(n%i==0){
                        factorials.add(i);
                        while(n%i==0)n/=i;
                    }
                }
                if(n>2)factorials.add(n);
                return factorials;
            }
            public ArrayList<Long> distinctPrimeFactors(long n){
                ArrayList<Long> factorials=new ArrayList<>();
                long limit=(long)Math.sqrt(n);
                if(n%2==0){
                    factorials.add((long)2);
                    while(n%2==0)n/=2;
                }
                for(long i=3;i<=limit;i+=2){
                    if(n%i==0){
                        factorials.add(i);
                        while(n%i==0)n/=i;
                    }
                }
                if(n>2)factorials.add(n);
                return factorials;
            }
            public ArrayList<Integer> primeFactors(int n){
                ArrayList<Integer> factorials=new ArrayList<>();
                int limit=(int)Math.sqrt(n);
                if(n%2==0){
                    factorials.add(2);
                    while(n%2==0)n/=2;
                }
                for(int i=3;i<=limit;i+=2){
                    if(n%i==0){
                        factorials.add(i);
                        while(n%i==0)n/=i;
                    }
                }
                if(n>2)factorials.add(n);
                return factorials;
            }
            public ArrayList<Long> primeFactors(long n){
                ArrayList<Long> factorials=new ArrayList<>();
                long limit=(long)Math.sqrt(n);
                if(n%2==0){
                    factorials.add((long)2);
                    while(n%2==0)n/=2;
                }
                for(long i=3;i<=limit;i+=2){
                    if(n%i==0){
                        factorials.add(i);
                        while(n%i==0)n/=i;
                    }
                }
                if(n>2)factorials.add(n);
                return factorials;
            }
    

            public long nCr(int n,int r){
                int[] C=new int[r+1];
                C[0]=1;

                for(int i=1;i<=n;++i)
                    for(int j=Math.min(i,r);j>0;--j)
                        C[j]=C[j]+C[j-1];
                return C[r];
            }
            public long catlanNumber(int n){
                long[] catlan=new long[n+1];
                catlan[0]=catlan[1]=1;
                for(int i=2;i<=n;++i)
                    for(int j=0;j<i;++j)
                        catlan[i]+=catlan[j]*catlan[i-1-j];
                return catlan[n];
            }
            public int gcd(int a,int b){
                if(b==0)return a;
                return gcd(b%a,a);
            }
            public long gcd(long a,long b){
                if(b==0)return a;
                return gcd(b%a,a);
            }
            public long lcm(long a,long b){
                return (a*b)/gcd(a,b);
            }
        

	}
        
class OutputWriter{

            private final PrintWriter writer;
            public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
            }
            public OutputWriter(Writer writer) {
                this.writer = new PrintWriter(writer);
            }
            public void print(Object... objects) {
                for (int i = 0; i < objects.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(objects[i]);
                }
            }
            public void print(int[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }
            public void print(double[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }
            public void print(long[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }
            public void print(char[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }
            public void print(String[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }
            public void print(int[][] matrix){
                for(int i=0;i<matrix.length;++i){
                    println(matrix[i]);
                }
            }
            public void print(double[][] matrix){
                for(int i=0;i<matrix.length;++i){
                    println(matrix[i]);
                }
            }
            public void print(long[][] matrix){
                for(int i=0;i<matrix.length;++i){
                    println(matrix[i]);
                }
            }
            public void print(char[][] matrix){
                for(int i=0;i<matrix.length;++i){
                    println(matrix[i]);
                }
            }
            public void print(String[][] matrix){
                for(int i=0;i<matrix.length;++i){
                    println(matrix[i]);
                }
            }
            public void println(int[] array) {
                print(array);
                writer.println();
            }
            public void println(double[] array) {
                print(array);
                writer.println();
            }
            public void println(long[] array) {
                print(array);
                writer.println();
            }
            public void println(String[] array) {
                print(array);
                writer.println();
            }
            public void println() {
                writer.println();
            }
            public void println(Object... objects) {
                print(objects);
                writer.println();
            }
            public void print(char i) {
                writer.print(i);
            }
            public void println(char i) {
                writer.println(i);
            }
            public void println(char[] array) {
                writer.println(array);
            }
            public void printf(String format, Object... objects) {
                writer.printf(format, objects);
            }
            public void close() {
                writer.close();
            }
            public void flush() {
                writer.flush();
            }
            public void print(long i) {
                writer.print(i);
            }
            public void println(long i) {
                writer.println(i);
            }
            public void print(int i) {
                writer.print(i);
            }
            public void println(int i) {
                writer.println(i);
            }
            public void separateLines(int[] array) {
                for (int i : array) {
                    println(i);
                }
            }
        
	}
