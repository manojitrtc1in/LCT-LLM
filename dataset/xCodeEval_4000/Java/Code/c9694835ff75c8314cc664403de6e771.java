

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class b{
	 static class Reader 
	    { 
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
	            din = new DataInputStream(new FileInputStream(file_name)); 
	            buffer = new byte[BUFFER_SIZE]; 
	            bufferPointer = bytesRead = 0; 
	        } 
	  
	        public String readLine() throws IOException 
	        { 
	            byte[] buf = new byte[64]; 

	            int cnt = 0, c; 
	            while ((c = read()) != -1) 
	            { 
	                if (c == '\n') 
	                    break; 
	                buf[cnt++] = (byte) c; 
	            } 
	            return new String(buf, 0, cnt); 
	        } 
	  
	        public int nextInt() throws IOException 
	        { 
	            int ret = 0; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	            do
	            { 
	                ret = ret * 10 + c - '0'; 
	            }  while ((c = read()) >= '0' && c <= '9'); 
	  
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
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
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
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
	  
	            if (c == '.') 
	            { 
	                while ((c = read()) >= '0' && c <= '9') 
	                { 
	                    ret += (c - '0') / (div *= 10); 
	                } 
	            } 
	  
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        private void fillBuffer() throws IOException 
	        { 
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
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
	
	public static void main(String[] args) throws Exception 
	{ 
	     Reader s=new Reader();

	     int t=s.nextInt();
	     StringBuilder sb=new StringBuilder();
	     for(int ie=0;ie<t;ie++) {
	    	 int a=s.nextInt();
	    	 int b=s.nextInt();
	    	 
	    	int n=s.nextInt();
	    	int[] crr=new int[n];
	    	int[] brr=new int[n];
	    	
	    	for(int i=0;i<n;i++) {
	    		crr[i]=s.nextInt();
	    	}
	    	
	    	for(int i=0;i<n;i++) {
	    		brr[i]=s.nextInt();
	    	}
	    	
	    	pair[] arr=new pair[n];
	    	for(int i=0;i<n;i++) {
	    		arr[i]=new pair(crr[i],brr[i]);
	    	}
	    	Arrays.sort(arr,new comp());
	    	int[] dp1=new int[a+1];
	    	int[] dp2=new int[b+1];
	    	dp1[arr[n-1].a]++;
	    	dp2[arr[n-1].b]++;
	    	long ans=0;
	    	for(int i=n-2;i>=0;i--) {
	    		ans=ans+n-i-1-dp1[arr[i].a]-dp2[arr[i].b];
	    		dp1[arr[i].a]++;
	    		dp2[arr[i].b]++;
	    	}
	    	sb.append(ans).append("\n");
	    	
	    	
	    	
	    	
	    	
	    	
	     }
	     System.out.println(sb);
	}
}
class pair{
	int a;
	int b;
	public pair(int a,int b) {
		this.a=a;
		this.b=b;
	}
}
class comp implements Comparator<pair>{
	public int compare(pair h,pair k) {
		return h.a-k.a;
	}
}