import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
 
public class Main{
	public static final int mod = 1000003;
	
	public static void main(String[] args)throws IOException {
		

		InputStream input = System.in;
	
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		Reader in = new Reader();
		
		int n = in.nextInt();
		
		int high = n;
		int low = 1;
		
		int res = -1;
		while(low <= high)
		{

			int mid = (low+high)/2;
			
			System.out.println("? "+mid+" 1 "+n+" "+n);System.out.flush();
			int ans = in.nextInt();
			if(ans == 1)
			{
				res = mid;
				low = mid + 1;
				
			}
			else if(ans == 0)
			{
				high = mid-1;
			}
			else {
				low = mid + 1;
			}
		}
		int x12 = res;
		
		
			 low = 1;
			 high = n;
			
			 res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? "+mid+" 1 "+n+" "+n);System.out.flush();
				int ans = in.nextInt();
				if(ans == 2)
				{
					res = mid;
					low = mid + 1;
					
				}
				else 
				{
					high = mid - 1;
				}
				
			}
		
			int x22 = res; 
			if(x12 == -1)
				x12 = res;
			
			low = 1;
			high = n;
			res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 1 "+mid+" "+n);System.out.flush();
				int ans = in.nextInt();
				if(ans == 1)
				{
					res = mid;
					high = mid -1;
					
				}
				else if(ans == 0)
				{
					low = mid +1;
				}
				else {
					
					high = mid - 1;
				}
			}
			
			int x11 = res;
			low = 1;
			high = n;
			res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 1 "+mid+" "+n);System.out.flush();
				int ans = in.nextInt();
				if(ans == 2)
				{
					res = mid;
					high = mid -1;
					
				}
				else 
				 {
					
					low = mid + 1;
				}
			}
			int x21= res;
			if(x11 == -1)
				x11 = res;
			

			low = 1;
			high = n;
			res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 1 "+n+" "+mid);System.out.flush();
				int ans = in.nextInt();
				if(ans == 1)
				{
					res = mid;
					high = mid-1;
					
				}
				else if(ans == 0)
				{
					low = mid+1;
				}
				else {
					
					high = mid-1;
				}
			}
			
			int y12 = res;
			low = 1;
			high = n;
			res = -1;
			
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 1 "+n+" "+mid);System.out.flush();
				int ans = in.nextInt();
				if(ans == 2)
				{
					res = mid;
					high = mid -1;
					
				}
				else 
				{
					low = mid+1;
				}
			}
			int y22 = res;
			if(y12 == -1)
				y12 = res;
			

			low = 1;
			high = n;
			res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 "+mid+" "+n+" "+n);System.out.flush();
				int ans = in.nextInt();
				if(ans == 1)
				{
					res = mid;
					low = mid+1;
					
				}
				else if(ans == 0)
				{
					high = mid -1;
				}
				else {
					
					low = mid+1;
				}
			}
			
			int y11 = res;
			low = 1;
			high = n;
			res = -1;
			while(low <= high)
			{

				int mid = (low+high)/2;
				
				System.out.println("? 1 "+mid+" "+n+" "+n);System.out.flush();
				int ans = in.nextInt();
				if(ans == 2)
				{
					res = mid;
					low = mid+1;
					
				}
				else 
				 {
					
					high = mid-1;
				}
			}
			int y21 = res;
			if(y11 == -1)
				y11 = res;
			
			
			

			

			

			boolean done = false;
			
			if(x12 <=x11 && y11<=y12)
			{
			System.out.println("? "+x12+" "+y11+" "+x11+" "+y12);System.out.flush();
			if(in.nextInt() == 1)
			{
				System.out.println("? "+x22+" "+y21+" "+x21+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("! "+x12+" "+y11+" "+x11+" "+y12+" "+x22+" "+y21+" "+x21+" "+y22);System.out.flush();
					done = true;
				}
				
			}
			}
			if(!done && x12 <=x11 && y11<=y22)
			{
				System.out.println("? "+x12+" "+y11+" "+x11+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y21+" "+x21+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y11+" "+x11+" "+y22+" "+x22+" "+y21+" "+x21+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}
			

			if(!done && x12 <=x21 && y11<=y12)
			{
				System.out.println("? "+x12+" "+y11+" "+x21+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y21+" "+x11+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y11+" "+x21+" "+y12+" "+x22+" "+y21+" "+x11+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x12 <=x21 && y11<=y22)
			{
				System.out.println("? "+x12+" "+y11+" "+x21+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y21+" "+x11+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y11+" "+x21+" "+y22+" "+x22+" "+y21+" "+x11+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x12 <=x11 && y21<=y12)
			{
				System.out.println("? "+x12+" "+y21+" "+x11+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y11+" "+x21+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y21+" "+x11+" "+y12+" "+x22+" "+y11+" "+x21+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x12 <=x11 && y21<=y22)
			{
				System.out.println("? "+x12+" "+y21+" "+x11+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y11+" "+x21+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y21+" "+x11+" "+y22+" "+x22+" "+y11+" "+x21+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x12 <=x21 && y21<=y12)
			{
				System.out.println("? "+x12+" "+y21+" "+x21+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y11+" "+x11+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y21+" "+x21+" "+y12+" "+x22+" "+y11+" "+x11+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x12 <=x21 && y21<=y22)
			{
				System.out.println("? "+x12+" "+y21+" "+x21+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x22+" "+y11+" "+x11+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x12+" "+y21+" "+x21+" "+y22+" "+x22+" "+y11+" "+x11+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x22 <=x11 && y11<=y12)
			{
				System.out.println("? "+x22+" "+y11+" "+x11+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y21+" "+x21+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y11+" "+x11+" "+y12+" "+x12+" "+y21+" "+x21+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}
			

			if(!done && x22 <=x11 && y11<=y22)
			{
				System.out.println("? "+x22+" "+y11+" "+x11+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y21+" "+x21+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y11+" "+x11+" "+y22+" "+x12+" "+y21+" "+x21+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x22 <=x21 && y21<=y12)
			{
				System.out.println("? "+x22+" "+y11+" "+x21+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y21+" "+x11+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y11+" "+x21+" "+y12+" "+x12+" "+y21+" "+x11+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done && x22 <=x21 && y11<=y22)
			{
				System.out.println("? "+x22+" "+y11+" "+x21+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y21+" "+x11+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y11+" "+x21+" "+y22+" "+x12+" "+y21+" "+x11+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done  && x22 <=x11 && y21<=y12)
			{
				System.out.println("? "+x22+" "+y21+" "+x11+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y11+" "+x21+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y21+" "+x11+" "+y12+" "+x12+" "+y11+" "+x21+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}
			
			

			if(!done && x22 <=x11 && y21<=y22)
			{
				System.out.println("? "+x22+" "+y21+" "+x11+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y11+" "+x21+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y21+" "+x11+" "+y22+" "+x12+" "+y11+" "+x21+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done  && x22 <=x21 && y21<=y12)
			{
				System.out.println("? "+x22+" "+y21+" "+x21+" "+y12);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y11+" "+x11+" "+y22);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y21+" "+x21+" "+y12+" "+x12+" "+y11+" "+x11+" "+y22);System.out.flush();
						done = true;
					}
					
				}
			
			}

			if(!done  && x22 <=x21 && y21<=y22)
			{
				System.out.println("? "+x22+" "+y21+" "+x21+" "+y22);System.out.flush();
				if(in.nextInt() == 1)
				{
					System.out.println("? "+x12+" "+y11+" "+x11+" "+y12);System.out.flush();
					if(in.nextInt() == 1)
					{
						System.out.println("! "+x22+" "+y21+" "+x21+" "+y22+" "+x12+" "+y11+" "+x11+" "+y12);System.out.flush();
						done = true;
					}
					
				}
			
			}
			if(!done)
			System.out.println("-111");
			
	}
	
	
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


}