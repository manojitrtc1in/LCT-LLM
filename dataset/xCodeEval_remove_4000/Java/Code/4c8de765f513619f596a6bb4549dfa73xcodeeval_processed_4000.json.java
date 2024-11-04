

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

 public class Main {
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
	 public static void main(String[] args) throws Exception {
		 Reader s=new Reader();
	
		 int n=s.nextInt();
		 int m=s.nextInt();
		 long a=s.nextLong();
		 long b=s.nextLong();
		 
		Integer[] brr=new Integer[m];
		for(int i=0;i<m;i++) {
			brr[i]=s.nextInt();
		 }
		Arrays.sort(brr);
		
	      
		System.out.println(ms(1,(int)Math.pow(2, n),brr,a,b));
		 
		 
		 
				 
	
	 }
	 
	 public static long ms(int st,int end,Integer[] brr,long a,long b) {
		 long count=0;
	
		 long ans=0;
			int u=ubs(brr,end); int l=lbs(brr,st);
			if(u!=-1&&l!=-1) {
				count=u-l+1;
			}
			
		 if(count==0) {
			 ans=a;
			 return ans;
		 }else {
			 ans=b*count*(end-st+1);
		 
		

		 
		 if(st<end) {
		 int mid=(st+end)/2;
		 
		 ans=Math.min(ans, ms(st,mid,brr,a,b)+ms(mid+1,end,brr,a,b));
		 return ans;
		 }else {
			 return ans;
		 }
			 
		 }
		 
		
		 
	 }
	 public static int ubs(Integer[] brr,int num) {
		 
		 int start=0;
		 int in=-1;
		 int end=brr.length-1;
		 while(start<=end) {
			 int mid=(start+end)/2;
			 if(brr[mid]<=num) {
				 in=mid;
				 start=mid+1;
			 }else {
				 end=mid-1;
			 }
		 }
		 return in;
	 }
 public static int lbs(Integer[] brr,int num) {
		 
		 int start=0;
		 int in=-1;
		 int end=brr.length-1;
		 while(start<=end) {
			 int mid=(start+end)/2;
			 if(brr[mid]<num) {
				 
				 start=mid+1;
			 }else {
				 in=mid;
				 end=mid-1;
			 }
		 }
		 return in;
	 }
	 
 }