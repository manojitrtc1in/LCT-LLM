import java.io.*;
import java.util.*;
import static java.lang.Math.*;



public class F1692 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
        public FastReader(String file_name)throws IOException
        {
            br = new BufferedReader(
                new FileReader(file_name));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        
        public int[] nextArray(int n){
            int ar[] = new int[n];
            for(int i=0;i<n;i++)
                ar[i] = this.nextInt();
            return (ar);
        }
    }

   static class OutputWriter{
        BufferedWriter writer;

         public OutputWriter(OutputStream stream){
           writer = new BufferedWriter(new OutputStreamWriter(stream));
         }

         public OutputWriter(String file_name) throws IOException{
           writer = new BufferedWriter(new FileWriter("output.txt"));
         }
       
         public void print(int i) throws IOException {
           writer.write(i);
         }

         public void print(String s) throws IOException {
            writer.write(s);
          }

         public void print(char []c) throws IOException {
            writer.write(c);
         }

         public void println(int i) throws IOException {
           writer.write(i+"\n");
         }

         public void println(long i) throws IOException {
           writer.write(i+"\n");
         }

         public void println(String s) throws IOException {
            writer.write(s+"\n");
          }

         public void println(char []c) throws IOException {
            writer.write(c+"\n");
         }

         public  void close() throws IOException {
            writer.close();
         }

    }
    public static long gcd(long a,long b){
        return(a==0?b:gcd(b%a,a));
    }
    public static long lcm(long a,long b){
        

        

        return((a/gcd(a,b))*b);
    }
    public static void initialize_io_redirection()throws IOException{
        try{
            boolean MP = System.getProperty("MY_PC")!=null;
            if(MP){
                fs = new FastReader("input.txt");
                op = new OutputWriter("output.txt");
                System.setOut(new PrintStream(new File("output.txt")));
            }
            else{
                fs = new FastReader();
                op = new OutputWriter(System.out);
            }
       }
       catch(Exception e){
            fs = new FastReader();
            op = new OutputWriter(System.out);
       }
    }
   static FastReader fs;
   static OutputWriter op;
    public static void main(String[] args)throws IOException{
        initialize_io_redirection();
        int t = fs.nextInt();
        while(t-- > 0)
            solve();
        op.close();
    }

    public static void solve2()throws IOException{
        int n = fs.nextInt();
        int ar[]=fs.nextArray(n);
        int prsnt[] = new int[10];
        for(int e:ar){
        	prsnt[e%10]++;
        }
        boolean done=false;
      
        int a,b,c;
a=prsnt[0];b=prsnt[0];c=prsnt[3];if(prsnt[0]-->0 && !done && prsnt[0]-->0 &&prsnt[3]-->0){done=true; }prsnt[0]=a;prsnt[0]=b;prsnt[3]=c;
a=prsnt[0];b=prsnt[1];c=prsnt[2];if(prsnt[0]-->0 && !done && prsnt[1]-->0 &&prsnt[2]-->0){done=true; }prsnt[0]=a;prsnt[1]=b;prsnt[2]=c;
a=prsnt[0];b=prsnt[2];c=prsnt[1];if(prsnt[0]-->0 && !done && prsnt[2]-->0 &&prsnt[1]-->0){done=true; }prsnt[0]=a;prsnt[2]=b;prsnt[1]=c;
a=prsnt[0];b=prsnt[3];c=prsnt[0];if(prsnt[0]-->0 && !done && prsnt[3]-->0 &&prsnt[0]-->0){done=true; }prsnt[0]=a;prsnt[3]=b;prsnt[0]=c;
a=prsnt[0];b=prsnt[4];c=prsnt[9];if(prsnt[0]-->0 && !done && prsnt[4]-->0 &&prsnt[9]-->0){done=true; }prsnt[0]=a;prsnt[4]=b;prsnt[9]=c;
a=prsnt[0];b=prsnt[5];c=prsnt[8];if(prsnt[0]-->0 && !done && prsnt[5]-->0 &&prsnt[8]-->0){done=true; }prsnt[0]=a;prsnt[5]=b;prsnt[8]=c;
a=prsnt[0];b=prsnt[6];c=prsnt[7];if(prsnt[0]-->0 && !done && prsnt[6]-->0 &&prsnt[7]-->0){done=true; }prsnt[0]=a;prsnt[6]=b;prsnt[7]=c;
a=prsnt[0];b=prsnt[7];c=prsnt[6];if(prsnt[0]-->0 && !done && prsnt[7]-->0 &&prsnt[6]-->0){done=true; }prsnt[0]=a;prsnt[7]=b;prsnt[6]=c;
a=prsnt[0];b=prsnt[8];c=prsnt[5];if(prsnt[0]-->0 && !done && prsnt[8]-->0 &&prsnt[5]-->0){done=true; }prsnt[0]=a;prsnt[8]=b;prsnt[5]=c;
a=prsnt[0];b=prsnt[9];c=prsnt[4];if(prsnt[0]-->0 && !done && prsnt[9]-->0 &&prsnt[4]-->0){done=true; }prsnt[0]=a;prsnt[9]=b;prsnt[4]=c;
a=prsnt[1];b=prsnt[0];c=prsnt[2];if(prsnt[1]-->0 && !done && prsnt[0]-->0 &&prsnt[2]-->0){done=true; }prsnt[1]=a;prsnt[0]=b;prsnt[2]=c;
a=prsnt[1];b=prsnt[1];c=prsnt[1];if(prsnt[1]-->0 && !done && prsnt[1]-->0 &&prsnt[1]-->0){done=true; }prsnt[1]=a;prsnt[1]=b;prsnt[1]=c;
a=prsnt[1];b=prsnt[2];c=prsnt[0];if(prsnt[1]-->0 && !done && prsnt[2]-->0 &&prsnt[0]-->0){done=true; }prsnt[1]=a;prsnt[2]=b;prsnt[0]=c;
a=prsnt[1];b=prsnt[3];c=prsnt[9];if(prsnt[1]-->0 && !done && prsnt[3]-->0 &&prsnt[9]-->0){done=true; }prsnt[1]=a;prsnt[3]=b;prsnt[9]=c;
a=prsnt[1];b=prsnt[4];c=prsnt[8];if(prsnt[1]-->0 && !done && prsnt[4]-->0 &&prsnt[8]-->0){done=true; }prsnt[1]=a;prsnt[4]=b;prsnt[8]=c;
a=prsnt[1];b=prsnt[5];c=prsnt[7];if(prsnt[1]-->0 && !done && prsnt[5]-->0 &&prsnt[7]-->0){done=true; }prsnt[1]=a;prsnt[5]=b;prsnt[7]=c;
a=prsnt[1];b=prsnt[6];c=prsnt[6];if(prsnt[1]-->0 && !done && prsnt[6]-->0 &&prsnt[6]-->0){done=true; }prsnt[1]=a;prsnt[6]=b;prsnt[6]=c;
a=prsnt[1];b=prsnt[7];c=prsnt[5];if(prsnt[1]-->0 && !done && prsnt[7]-->0 &&prsnt[5]-->0){done=true; }prsnt[1]=a;prsnt[7]=b;prsnt[5]=c;
a=prsnt[1];b=prsnt[8];c=prsnt[4];if(prsnt[1]-->0 && !done && prsnt[8]-->0 &&prsnt[4]-->0){done=true; }prsnt[1]=a;prsnt[8]=b;prsnt[4]=c;
a=prsnt[1];b=prsnt[9];c=prsnt[3];if(prsnt[1]-->0 && !done && prsnt[9]-->0 &&prsnt[3]-->0){done=true; }prsnt[1]=a;prsnt[9]=b;prsnt[3]=c;
a=prsnt[2];b=prsnt[0];c=prsnt[1];if(prsnt[2]-->0 && !done && prsnt[0]-->0 &&prsnt[1]-->0){done=true; }prsnt[2]=a;prsnt[0]=b;prsnt[1]=c;
a=prsnt[2];b=prsnt[1];c=prsnt[0];if(prsnt[2]-->0 && !done && prsnt[1]-->0 &&prsnt[0]-->0){done=true; }prsnt[2]=a;prsnt[1]=b;prsnt[0]=c;
a=prsnt[2];b=prsnt[2];c=prsnt[9];if(prsnt[2]-->0 && !done && prsnt[2]-->0 &&prsnt[9]-->0){done=true; }prsnt[2]=a;prsnt[2]=b;prsnt[9]=c;
a=prsnt[2];b=prsnt[3];c=prsnt[8];if(prsnt[2]-->0 && !done && prsnt[3]-->0 &&prsnt[8]-->0){done=true; }prsnt[2]=a;prsnt[3]=b;prsnt[8]=c;
a=prsnt[2];b=prsnt[4];c=prsnt[7];if(prsnt[2]-->0 && !done && prsnt[4]-->0 &&prsnt[7]-->0){done=true; }prsnt[2]=a;prsnt[4]=b;prsnt[7]=c;
a=prsnt[2];b=prsnt[5];c=prsnt[6];if(prsnt[2]-->0 && !done && prsnt[5]-->0 &&prsnt[6]-->0){done=true; }prsnt[2]=a;prsnt[5]=b;prsnt[6]=c;
a=prsnt[2];b=prsnt[6];c=prsnt[5];if(prsnt[2]-->0 && !done && prsnt[6]-->0 &&prsnt[5]-->0){done=true; }prsnt[2]=a;prsnt[6]=b;prsnt[5]=c;
a=prsnt[2];b=prsnt[7];c=prsnt[4];if(prsnt[2]-->0 && !done && prsnt[7]-->0 &&prsnt[4]-->0){done=true; }prsnt[2]=a;prsnt[7]=b;prsnt[4]=c;
a=prsnt[2];b=prsnt[8];c=prsnt[3];if(prsnt[2]-->0 && !done && prsnt[8]-->0 &&prsnt[3]-->0){done=true; }prsnt[2]=a;prsnt[8]=b;prsnt[3]=c;
a=prsnt[2];b=prsnt[9];c=prsnt[2];if(prsnt[2]-->0 && !done && prsnt[9]-->0 &&prsnt[2]-->0){done=true; }prsnt[2]=a;prsnt[9]=b;prsnt[2]=c;
a=prsnt[3];b=prsnt[0];c=prsnt[0];if(prsnt[3]-->0 && !done && prsnt[0]-->0 &&prsnt[0]-->0){done=true; }prsnt[3]=a;prsnt[0]=b;prsnt[0]=c;
a=prsnt[3];b=prsnt[1];c=prsnt[9];if(prsnt[3]-->0 && !done && prsnt[1]-->0 &&prsnt[9]-->0){done=true; }prsnt[3]=a;prsnt[1]=b;prsnt[9]=c;
a=prsnt[3];b=prsnt[2];c=prsnt[8];if(prsnt[3]-->0 && !done && prsnt[2]-->0 &&prsnt[8]-->0){done=true; }prsnt[3]=a;prsnt[2]=b;prsnt[8]=c;
a=prsnt[3];b=prsnt[3];c=prsnt[7];if(prsnt[3]-->0 && !done && prsnt[3]-->0 &&prsnt[7]-->0){done=true; }prsnt[3]=a;prsnt[3]=b;prsnt[7]=c;
a=prsnt[3];b=prsnt[4];c=prsnt[6];if(prsnt[3]-->0 && !done && prsnt[4]-->0 &&prsnt[6]-->0){done=true; }prsnt[3]=a;prsnt[4]=b;prsnt[6]=c;
a=prsnt[3];b=prsnt[5];c=prsnt[5];if(prsnt[3]-->0 && !done && prsnt[5]-->0 &&prsnt[5]-->0){done=true; }prsnt[3]=a;prsnt[5]=b;prsnt[5]=c;
a=prsnt[3];b=prsnt[6];c=prsnt[4];if(prsnt[3]-->0 && !done && prsnt[6]-->0 &&prsnt[4]-->0){done=true; }prsnt[3]=a;prsnt[6]=b;prsnt[4]=c;
a=prsnt[3];b=prsnt[7];c=prsnt[3];if(prsnt[3]-->0 && !done && prsnt[7]-->0 &&prsnt[3]-->0){done=true; }prsnt[3]=a;prsnt[7]=b;prsnt[3]=c;
a=prsnt[3];b=prsnt[8];c=prsnt[2];if(prsnt[3]-->0 && !done && prsnt[8]-->0 &&prsnt[2]-->0){done=true; }prsnt[3]=a;prsnt[8]=b;prsnt[2]=c;
a=prsnt[3];b=prsnt[9];c=prsnt[1];if(prsnt[3]-->0 && !done && prsnt[9]-->0 &&prsnt[1]-->0){done=true; }prsnt[3]=a;prsnt[9]=b;prsnt[1]=c;
a=prsnt[4];b=prsnt[0];c=prsnt[9];if(prsnt[4]-->0 && !done && prsnt[0]-->0 &&prsnt[9]-->0){done=true; }prsnt[4]=a;prsnt[0]=b;prsnt[9]=c;
a=prsnt[4];b=prsnt[1];c=prsnt[8];if(prsnt[4]-->0 && !done && prsnt[1]-->0 &&prsnt[8]-->0){done=true; }prsnt[4]=a;prsnt[1]=b;prsnt[8]=c;
a=prsnt[4];b=prsnt[2];c=prsnt[7];if(prsnt[4]-->0 && !done && prsnt[2]-->0 &&prsnt[7]-->0){done=true; }prsnt[4]=a;prsnt[2]=b;prsnt[7]=c;
a=prsnt[4];b=prsnt[3];c=prsnt[6];if(prsnt[4]-->0 && !done && prsnt[3]-->0 &&prsnt[6]-->0){done=true; }prsnt[4]=a;prsnt[3]=b;prsnt[6]=c;
a=prsnt[4];b=prsnt[4];c=prsnt[5];if(prsnt[4]-->0 && !done && prsnt[4]-->0 &&prsnt[5]-->0){done=true; }prsnt[4]=a;prsnt[4]=b;prsnt[5]=c;
a=prsnt[4];b=prsnt[5];c=prsnt[4];if(prsnt[4]-->0 && !done && prsnt[5]-->0 &&prsnt[4]-->0){done=true; }prsnt[4]=a;prsnt[5]=b;prsnt[4]=c;
a=prsnt[4];b=prsnt[6];c=prsnt[3];if(prsnt[4]-->0 && !done && prsnt[6]-->0 &&prsnt[3]-->0){done=true; }prsnt[4]=a;prsnt[6]=b;prsnt[3]=c;
a=prsnt[4];b=prsnt[7];c=prsnt[2];if(prsnt[4]-->0 && !done && prsnt[7]-->0 &&prsnt[2]-->0){done=true; }prsnt[4]=a;prsnt[7]=b;prsnt[2]=c;
a=prsnt[4];b=prsnt[8];c=prsnt[1];if(prsnt[4]-->0 && !done && prsnt[8]-->0 &&prsnt[1]-->0){done=true; }prsnt[4]=a;prsnt[8]=b;prsnt[1]=c;
a=prsnt[4];b=prsnt[9];c=prsnt[0];if(prsnt[4]-->0 && !done && prsnt[9]-->0 &&prsnt[0]-->0){done=true; }prsnt[4]=a;prsnt[9]=b;prsnt[0]=c;
a=prsnt[5];b=prsnt[0];c=prsnt[8];if(prsnt[5]-->0 && !done && prsnt[0]-->0 &&prsnt[8]-->0){done=true; }prsnt[5]=a;prsnt[0]=b;prsnt[8]=c;
a=prsnt[5];b=prsnt[1];c=prsnt[7];if(prsnt[5]-->0 && !done && prsnt[1]-->0 &&prsnt[7]-->0){done=true; }prsnt[5]=a;prsnt[1]=b;prsnt[7]=c;
a=prsnt[5];b=prsnt[2];c=prsnt[6];if(prsnt[5]-->0 && !done && prsnt[2]-->0 &&prsnt[6]-->0){done=true; }prsnt[5]=a;prsnt[2]=b;prsnt[6]=c;
a=prsnt[5];b=prsnt[3];c=prsnt[5];if(prsnt[5]-->0 && !done && prsnt[3]-->0 &&prsnt[5]-->0){done=true; }prsnt[5]=a;prsnt[3]=b;prsnt[5]=c;
a=prsnt[5];b=prsnt[4];c=prsnt[4];if(prsnt[5]-->0 && !done && prsnt[4]-->0 &&prsnt[4]-->0){done=true; }prsnt[5]=a;prsnt[4]=b;prsnt[4]=c;
a=prsnt[5];b=prsnt[5];c=prsnt[3];if(prsnt[5]-->0 && !done && prsnt[5]-->0 &&prsnt[3]-->0){done=true; }prsnt[5]=a;prsnt[5]=b;prsnt[3]=c;
a=prsnt[5];b=prsnt[6];c=prsnt[2];if(prsnt[5]-->0 && !done && prsnt[6]-->0 &&prsnt[2]-->0){done=true; }prsnt[5]=a;prsnt[6]=b;prsnt[2]=c;
a=prsnt[5];b=prsnt[7];c=prsnt[1];if(prsnt[5]-->0 && !done && prsnt[7]-->0 &&prsnt[1]-->0){done=true; }prsnt[5]=a;prsnt[7]=b;prsnt[1]=c;
a=prsnt[5];b=prsnt[8];c=prsnt[0];if(prsnt[5]-->0 && !done && prsnt[8]-->0 &&prsnt[0]-->0){done=true; }prsnt[5]=a;prsnt[8]=b;prsnt[0]=c;
a=prsnt[5];b=prsnt[9];c=prsnt[9];if(prsnt[5]-->0 && !done && prsnt[9]-->0 &&prsnt[9]-->0){done=true; }prsnt[5]=a;prsnt[9]=b;prsnt[9]=c;
a=prsnt[6];b=prsnt[0];c=prsnt[7];if(prsnt[6]-->0 && !done && prsnt[0]-->0 &&prsnt[7]-->0){done=true; }prsnt[6]=a;prsnt[0]=b;prsnt[7]=c;
a=prsnt[6];b=prsnt[1];c=prsnt[6];if(prsnt[6]-->0 && !done && prsnt[1]-->0 &&prsnt[6]-->0){done=true; }prsnt[6]=a;prsnt[1]=b;prsnt[6]=c;
a=prsnt[6];b=prsnt[2];c=prsnt[5];if(prsnt[6]-->0 && !done && prsnt[2]-->0 &&prsnt[5]-->0){done=true; }prsnt[6]=a;prsnt[2]=b;prsnt[5]=c;
a=prsnt[6];b=prsnt[3];c=prsnt[4];if(prsnt[6]-->0 && !done && prsnt[3]-->0 &&prsnt[4]-->0){done=true; }prsnt[6]=a;prsnt[3]=b;prsnt[4]=c;
a=prsnt[6];b=prsnt[4];c=prsnt[3];if(prsnt[6]-->0 && !done && prsnt[4]-->0 &&prsnt[3]-->0){done=true; }prsnt[6]=a;prsnt[4]=b;prsnt[3]=c;
a=prsnt[6];b=prsnt[5];c=prsnt[2];if(prsnt[6]-->0 && !done && prsnt[5]-->0 &&prsnt[2]-->0){done=true; }prsnt[6]=a;prsnt[5]=b;prsnt[2]=c;
a=prsnt[6];b=prsnt[6];c=prsnt[1];if(prsnt[6]-->0 && !done && prsnt[6]-->0 &&prsnt[1]-->0){done=true; }prsnt[6]=a;prsnt[6]=b;prsnt[1]=c;
a=prsnt[6];b=prsnt[7];c=prsnt[0];if(prsnt[6]-->0 && !done && prsnt[7]-->0 &&prsnt[0]-->0){done=true; }prsnt[6]=a;prsnt[7]=b;prsnt[0]=c;
a=prsnt[6];b=prsnt[8];c=prsnt[9];if(prsnt[6]-->0 && !done && prsnt[8]-->0 &&prsnt[9]-->0){done=true; }prsnt[6]=a;prsnt[8]=b;prsnt[9]=c;
a=prsnt[6];b=prsnt[9];c=prsnt[8];if(prsnt[6]-->0 && !done && prsnt[9]-->0 &&prsnt[8]-->0){done=true; }prsnt[6]=a;prsnt[9]=b;prsnt[8]=c;
a=prsnt[7];b=prsnt[0];c=prsnt[6];if(prsnt[7]-->0 && !done && prsnt[0]-->0 &&prsnt[6]-->0){done=true; }prsnt[7]=a;prsnt[0]=b;prsnt[6]=c;
a=prsnt[7];b=prsnt[1];c=prsnt[5];if(prsnt[7]-->0 && !done && prsnt[1]-->0 &&prsnt[5]-->0){done=true; }prsnt[7]=a;prsnt[1]=b;prsnt[5]=c;
a=prsnt[7];b=prsnt[2];c=prsnt[4];if(prsnt[7]-->0 && !done && prsnt[2]-->0 &&prsnt[4]-->0){done=true; }prsnt[7]=a;prsnt[2]=b;prsnt[4]=c;
a=prsnt[7];b=prsnt[3];c=prsnt[3];if(prsnt[7]-->0 && !done && prsnt[3]-->0 &&prsnt[3]-->0){done=true; }prsnt[7]=a;prsnt[3]=b;prsnt[3]=c;
a=prsnt[7];b=prsnt[4];c=prsnt[2];if(prsnt[7]-->0 && !done && prsnt[4]-->0 &&prsnt[2]-->0){done=true; }prsnt[7]=a;prsnt[4]=b;prsnt[2]=c;
a=prsnt[7];b=prsnt[5];c=prsnt[1];if(prsnt[7]-->0 && !done && prsnt[5]-->0 &&prsnt[1]-->0){done=true; }prsnt[7]=a;prsnt[5]=b;prsnt[1]=c;
a=prsnt[7];b=prsnt[6];c=prsnt[0];if(prsnt[7]-->0 && !done && prsnt[6]-->0 &&prsnt[0]-->0){done=true; }prsnt[7]=a;prsnt[6]=b;prsnt[0]=c;
a=prsnt[7];b=prsnt[7];c=prsnt[9];if(prsnt[7]-->0 && !done && prsnt[7]-->0 &&prsnt[9]-->0){done=true; }prsnt[7]=a;prsnt[7]=b;prsnt[9]=c;
a=prsnt[7];b=prsnt[8];c=prsnt[8];if(prsnt[7]-->0 && !done && prsnt[8]-->0 &&prsnt[8]-->0){done=true; }prsnt[7]=a;prsnt[8]=b;prsnt[8]=c;
a=prsnt[7];b=prsnt[9];c=prsnt[7];if(prsnt[7]-->0 && !done && prsnt[9]-->0 &&prsnt[7]-->0){done=true; }prsnt[7]=a;prsnt[9]=b;prsnt[7]=c;
a=prsnt[8];b=prsnt[0];c=prsnt[5];if(prsnt[8]-->0 && !done && prsnt[0]-->0 &&prsnt[5]-->0){done=true; }prsnt[8]=a;prsnt[0]=b;prsnt[5]=c;
a=prsnt[8];b=prsnt[1];c=prsnt[4];if(prsnt[8]-->0 && !done && prsnt[1]-->0 &&prsnt[4]-->0){done=true; }prsnt[8]=a;prsnt[1]=b;prsnt[4]=c;
a=prsnt[8];b=prsnt[2];c=prsnt[3];if(prsnt[8]-->0 && !done && prsnt[2]-->0 &&prsnt[3]-->0){done=true; }prsnt[8]=a;prsnt[2]=b;prsnt[3]=c;
a=prsnt[8];b=prsnt[3];c=prsnt[2];if(prsnt[8]-->0 && !done && prsnt[3]-->0 &&prsnt[2]-->0){done=true; }prsnt[8]=a;prsnt[3]=b;prsnt[2]=c;
a=prsnt[8];b=prsnt[4];c=prsnt[1];if(prsnt[8]-->0 && !done && prsnt[4]-->0 &&prsnt[1]-->0){done=true; }prsnt[8]=a;prsnt[4]=b;prsnt[1]=c;
a=prsnt[8];b=prsnt[5];c=prsnt[0];if(prsnt[8]-->0 && !done && prsnt[5]-->0 &&prsnt[0]-->0){done=true; }prsnt[8]=a;prsnt[5]=b;prsnt[0]=c;
a=prsnt[8];b=prsnt[6];c=prsnt[9];if(prsnt[8]-->0 && !done && prsnt[6]-->0 &&prsnt[9]-->0){done=true; }prsnt[8]=a;prsnt[6]=b;prsnt[9]=c;
a=prsnt[8];b=prsnt[7];c=prsnt[8];if(prsnt[8]-->0 && !done && prsnt[7]-->0 &&prsnt[8]-->0){done=true; }prsnt[8]=a;prsnt[7]=b;prsnt[8]=c;
a=prsnt[8];b=prsnt[8];c=prsnt[7];if(prsnt[8]-->0 && !done && prsnt[8]-->0 &&prsnt[7]-->0){done=true; }prsnt[8]=a;prsnt[8]=b;prsnt[7]=c;
a=prsnt[8];b=prsnt[9];c=prsnt[6];if(prsnt[8]-->0 && !done && prsnt[9]-->0 &&prsnt[6]-->0){done=true; }prsnt[8]=a;prsnt[9]=b;prsnt[6]=c;
a=prsnt[9];b=prsnt[0];c=prsnt[4];if(prsnt[9]-->0 && !done && prsnt[0]-->0 &&prsnt[4]-->0){done=true; }prsnt[9]=a;prsnt[0]=b;prsnt[4]=c;
a=prsnt[9];b=prsnt[1];c=prsnt[3];if(prsnt[9]-->0 && !done && prsnt[1]-->0 &&prsnt[3]-->0){done=true; }prsnt[9]=a;prsnt[1]=b;prsnt[3]=c;
a=prsnt[9];b=prsnt[2];c=prsnt[2];if(prsnt[9]-->0 && !done && prsnt[2]-->0 &&prsnt[2]-->0){done=true; }prsnt[9]=a;prsnt[2]=b;prsnt[2]=c;
a=prsnt[9];b=prsnt[3];c=prsnt[1];if(prsnt[9]-->0 && !done && prsnt[3]-->0 &&prsnt[1]-->0){done=true; }prsnt[9]=a;prsnt[3]=b;prsnt[1]=c;
a=prsnt[9];b=prsnt[4];c=prsnt[0];if(prsnt[9]-->0 && !done && prsnt[4]-->0 &&prsnt[0]-->0){done=true; }prsnt[9]=a;prsnt[4]=b;prsnt[0]=c;
a=prsnt[9];b=prsnt[5];c=prsnt[9];if(prsnt[9]-->0 && !done && prsnt[5]-->0 &&prsnt[9]-->0){done=true; }prsnt[9]=a;prsnt[5]=b;prsnt[9]=c;
a=prsnt[9];b=prsnt[6];c=prsnt[8];if(prsnt[9]-->0 && !done && prsnt[6]-->0 &&prsnt[8]-->0){done=true; }prsnt[9]=a;prsnt[6]=b;prsnt[8]=c;
a=prsnt[9];b=prsnt[7];c=prsnt[7];if(prsnt[9]-->0 && !done && prsnt[7]-->0 &&prsnt[7]-->0){done=true; }prsnt[9]=a;prsnt[7]=b;prsnt[7]=c;
a=prsnt[9];b=prsnt[8];c=prsnt[6];if(prsnt[9]-->0 && !done && prsnt[8]-->0 &&prsnt[6]-->0){done=true; }prsnt[9]=a;prsnt[8]=b;prsnt[6]=c;
a=prsnt[9];b=prsnt[9];c=prsnt[5];if(prsnt[9]-->0 && !done && prsnt[9]-->0 &&prsnt[5]-->0){done=true; }prsnt[9]=a;prsnt[9]=b;prsnt[5]=c;



        System.out.println(done?" YES":" NO");
    }

    public static void solve()throws IOException{
        int n = fs.nextInt();
        int ar[]=fs.nextArray(n);
        int prsnt[] = new int[10];
        for(int e:ar){
            prsnt[e%10]++;
        }
        boolean done=false;
      
        int a,b,c;
       for(int i=0;i<=9;i++){
           for(int j=0;j<=9;j++){
               for(int k=0;k<=9;k++){
                a=prsnt[i];b=prsnt[j];c=prsnt[k];
                if((i+j+k)%10==3 ){
                    if(prsnt[i]-->0 && !done && prsnt[j]-->0 &&prsnt[k]-->0){done=true; }
                    prsnt[i]=a;prsnt[j]=b;prsnt[k]=c;
                }
               }
           }
       }
        System.out.println(done?" YES":" NO");
    }
}

