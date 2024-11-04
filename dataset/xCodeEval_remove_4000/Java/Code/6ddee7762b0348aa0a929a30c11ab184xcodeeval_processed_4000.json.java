

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class b {
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

		StringBuilder sb=new StringBuilder();
		int n=s.nextInt();
		int k=s.nextInt();
		Integer[] arr=new Integer[n];
		for(int i=0;i<n;i++) {
			
			arr[i]=s.nextInt();
		}
		
		int[] brr=new int[k];
		for(int i=0;i<k;i++) {
			brr[i]=s.nextInt();
			
		}
		
		
		Arrays.sort(arr);
		
		
		int st=1;
		int end=n;
		int gans=Integer.MAX_VALUE;
		while(st<=end) {
			
			int mid=(st+end)/2;
			
			int flag=0;
		  p1:for(int i=0;i<mid;i++) {
			  ArrayList<Integer> list=new ArrayList<>();
			  for(int j=i;j<n;j=j+mid) {
				  list.add(arr[j]);
			  }
			 
			  for(int l=0;l<list.size();l++) {
				  if(brr[list.get(l)-1]>=list.size()-l) {
					  
				  }else {
					  flag=1;
					  break p1;
				  }
			  }
			  
		  }
			
			
			if(flag==0) {
				gans=mid;
				end=mid-1;
			}else {
				st=mid+1;
			}
			
			
		}

		sb.append(gans);
		sb.append("\n");
		for(int i=0;i<gans;i++) {
			ArrayList<Integer> ans=new ArrayList<>();
			for(int j=i;j<n;j=j+gans) {
				ans.add(arr[j]);
			}
			sb.append(ans.size()+" ");
			for(int j=0;j<ans.size();j++) {
				sb.append(ans.get(j)+" ");
			}
		   sb.append("\n");
		}
		System.out.println(sb);
	}
}