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
import java.util.*;
import java.io.*;
import java.math.*;

public class id22{
  static class ProblemSolver{
    public void id12(InputReader in,OutputWriter out, NumberTheory nt){
      int test=in.nextInt();
      while(test-- >0){
        String s=in.nextLine();
        int c=0, max=0;
        for(int i=0;i<s.length();i++){
          if(s.charAt(i)=='R'){
            max=Math.max(max, c);
            c=0;
          }
          else c++;
        }
        max=Math.max(max, c);
        System.out.println(max+1);
      }
    }
  }

  public static void main(String[] args){
    InputStream inputStream=System.in;
    OutputStream outputStream=System.out;
    InputReader in=new InputReader(inputStream);
    OutputWriter out=new OutputWriter(outputStream);
    NumberTheory nt= new NumberTheory();
    ProblemSolver problemSolver=new ProblemSolver();
    problemSolver.id12(in,out, nt);
    out.flush();
    out.close();
  }



  static class InputReader {
    private boolean finished = false;

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id27 filter;

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

    public int nextInt() {
      int c = read();
      while (id5(c)) {
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
      } while (!id5(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = read();
      while (id5(c)) {
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
      } while (!id5(c));
      return res * sgn;
    }

    public String nextLine() {
      int c = read();
      while (id5(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        if (Character.isValidCodePoint(c)) {
          res.appendCodePoint(c);
        }
        c = read();
      } while (!id5(c));
      return res.toString();
    }

    public boolean id5(int c) {
      if (filter != null) {
        return filter.id5(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id1() {
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
      String s = id1();
      while (s.trim().length() == 0) {
        s = id1();
      }
      return s;
    }

    public String readLine(boolean id25) {
      if (id25) {
        return readLine();
      } else {
        return id1();
      }
    }

    public BigInteger id19() {
      try {
        return new BigInteger(nextLine());
      } catch (NumberFormatException e) {
        throw new InputMismatchException();
      }
    }

    public char nextCharacter() {
      int c = read();
      while (id5(c)) {
        c = read();
      }
      return (char) c;
    }

    public double nextDouble() {
      int c = read();
      while (id5(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      double res = 0;
      while (!id5(c) && c != '.') {
        if (c == 'e' || c == 'E') {
          return res * Math.pow(10, nextInt());
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
        while (!id5(c)) {
          if (c == 'e' || c == 'E') {
            return res * Math.pow(10, nextInt());
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

    public boolean id4() {
      int value;
      while (id5(value = peek()) && value != -1) {
        read();
      }
      return value == -1;
    }

    public String next() {
      return nextLine();
    }

    public id27 getFilter() {
      return filter;
    }

    public void setFilter(id27 filter) {
      this.filter = filter;
    }

    public interface id27 {
      public boolean id5(int ch);
    }
    public int[] id11(int n){
      int[] array=new int[n];
      for(int i=0;i<n;++i)array[i]=nextInt();
      return array;
    }
    public int[] id16(int n){
      int array[]=id11(n);
      Arrays.sort(array);
      return array;
    }
    public ArrayList<Integer> id3(int n){
      ArrayList<Integer> ar= new ArrayList<>();
      for(int i=0;i<n;i++)
        ar.add(nextInt());
      return ar;
    }
		public ArrayList<Long> id24(int n){
      ArrayList<Long> ar= new ArrayList<>();
      for(int i=0;i<n;i++)
        ar.add(nextLong());
      return ar;
    }

    public int[] id21(int n){
      int[] array=new int[n];
      array[0]=nextInt();
      for(int i=1;i<n;++i)array[i]=array[i-1]+nextInt();
      return array;
    }
    public long[] id28(int n){
      long[] array=new long[n];
      for(int i=0;i<n;++i)array[i]=nextLong();
      return array;
    }
    public long[] id2(int n){
      long[] array=new long[n];
      array[0]=nextInt();
      for(int i=1;i<n;++i)array[i]=array[i-1]+nextInt();
      return array;
    }
    public long[] id13(int n){
      long array[]=id28(n);
      Arrays.sort(array);
      return array;
    }
    public int[][] id0(int n,int m){
      int[][] matrix=new int[n][m];
      for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
      matrix[i][j]=nextInt();
      return matrix;
    }

    public int[][] id0(int n){
      return id0(n,n);
    }

    public long[][] id9(int n,int m){
      long[][] matrix=new long[n][m];
      for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
      matrix[i][j]=nextLong();
      return matrix;
    }

    public long[][] id9(int n){
      return id9(n,n);
    }

    public char[][] id17(int n,int m){
      char[][] matrix=new char[n][m];
      for(int i=0;i<n;++i)
      matrix[i]=next().toCharArray();
      return matrix;
    }

    public char[][] id17(int n){
      return id17(n,n);
    }
  }

  static class OutputWriter {
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

    public void id8(int[] array) {
      for (int i : array) {
        println(i);
      }
    }
  }
  static class NumberTheory{

      
      

      public int id10(int a,int b,int MOD){
          return (a%MOD+b%MOD)%MOD;
      }
      public long id10(long a,long b,long MOD){
          return (a%MOD+b%MOD)%MOD;
      }
      

      public int id18(int a,int b,int MOD){
          return ((a%MOD)*(b%MOD))%MOD;
      }
      public long id18(long a,long b,long MOD){
          return ((a%MOD)*(b%MOD))%MOD;
      }
      

      public int id14(int a,int b,int MOD){
          return (a%MOD-b%MOD+MOD)%MOD;
      }
      public long id14(long a,long b,long MOD){
          return (a%MOD-b%MOD+MOD)%MOD;
      }

      
      public int id26(int x,int n){
          if(n==0)return 1;
          else if(n%2==0)return id26(x*x,n/2);
          else return x*id26(x*x,(n-1)/2);
      }
      public long id26(long x,long n){
          long result=1;
          while(n>0){
              if(n%2==1)result*=x;
              x=x*x;
              n/=2;
          }
          return result;
      }

      
      public int id23(int x,int n,int MOD){
          if(n==0)return 1%MOD;
          else if(n%2==0)return id23(id18(x,x,MOD),n/2,MOD);
          else return id18(x,id23(id18(x,x,MOD),(n-1)/2,MOD),MOD);
      }
      public long id23(long x,long n,long MOD){
          long result=1;
          while(n>0){
              if(n%2==1)result=id18(result,x,MOD);
              x=id18(x,x,MOD);
              n/=2;
          }
          return result;
      }

      
      public long factorials(long n){
          if(n==0)return 1;
          return n*factorials(n-1);
      }

      
      public ArrayList<Integer> id15(int n){
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

      public ArrayList<Long> id15(long n){
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

      
      

      

      

      public int id6(int n,int k){
          if(k==0 || k==n)return 1;

          return id6(n-1,k-1)+id6(n-1,k);

      }

      

      

      

      public long id20(int n,int k){
          long[][] C=new long[n+1][k+1];
          for(int i=0;i<=n;++i){
              for(int j=0;j<=Math.min(n,k);++j){
                  if(j==0 || j==i)C[i][j]=1;
                  else C[i][j]=C[i-1][j-1]+C[i-1][j];
              }
          }
          return C[n][k];
      }

      

      

      

      public long nCr(int n,int r){
          int[] C=new int[r+1];
          C[0]=1;

          for(int i=1;i<=n;++i)
              for(int j=Math.min(i,r);j>0;--j)
                  C[j]=C[j]+C[j-1];
          return C[r];
      }

      
      public long id7(int n){
          long[] catlan=new long[n+1];
          catlan[0]=catlan[1]=1;
          for(int i=2;i<=n;++i)
              for(int j=0;j<i;++j)
                  catlan[i]+=catlan[j]*catlan[i-1-j];

          return catlan[n];
      }

      
      public int gcd(int a,int b){
          if(b==0)return a;
          return gcd(b,a %b);
      }

      public long gcd(long a,long b){
          if(b==0)return a;
          return gcd(b,a%b);
      }

      


      
      public long lcm(long a,long b){
          return (a*b)/gcd(a,b);
      }

  }
}


















































































































