import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
 
 
public class C{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      
      

   
      int n = sc.nextInt();
      int t = sc.nextInt();
      String g = sc.nextLine();
     
      int decimalPoint = g.indexOf('.');
      int i;
      
      

      
      String beforeDec = g.substring(0, decimalPoint);
      String postDec = g.substring(decimalPoint + 1);
      
      

      for(i = 0; i< postDec.length(); i++){
    	  if(postDec.charAt(i) - '0' >= 5){
    		  break;
    	  }
      }
      
      

      
      if(i == postDec.length()){
    	  

    	  System.out.println(g);
    	  return;
      }
      
      char[] id10 = postDec.toCharArray();
      

      while(t > 0 && i > 0) {
    	  if(id10[i] - '0' >= 5){
    		  i--;
    		  id10[i]++;
    		  t--;
    	  } else {
    		  break;
    	  }
      }
      
      

      

      
      String id7 = new String(id10);
      
      

      
      
      if(t > 0){
         

    	 if(id7.charAt(0) - '0' >= 5){
    		 

    		 String stringy = add(beforeDec, "1");
    		 
    		 System.out.println(stringy);
    		 return;
    	 }
    	 
      }
      
      System.out.println(beforeDec + "." + id7.substring(0, i + 1));
      

      

      
      
    
   }

     

   

   public static PrintWriter out;
      
   

   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   
   
   

   public static String add(String id8, String id9) {
	    StringBuilder buf = new StringBuilder();
	    for ( int i1 = id8.length() - 1, i2 = id9.length() - 1, carry = 0;
	          i1 >= 0 || i2 >= 0 || carry != 0;
	          i1--, i2-- ) {
	        int digit1 = i1 < 0 ? 0 :
	                     Integer.parseInt(Character.toString(id8.charAt(i1)));
	        int digit2 = i2 < 0 ? 0 :
	                     Integer.parseInt(Character.toString(id9.charAt(i2)));

	        int digit = digit1 + digit2 + carry;
	        if (digit > 9) {
	            carry = 1;
	            digit -= 10;
	        } else {
	            carry = 0;
	        }

	        buf.append(digit);
	    }
	    return buf.reverse().toString();
	}

}



class BigInt extends Number implements Comparable<BigInt>
{
	
	private static final long mask = (1L<<32) - 1;

	
	private int sign;
	
	private int len;
	
	private int[] dig;

	
	
	public BigInt(final int sign, final int[] v, final int len)
	{
		assign(sign,v,len);
	}
	
	public BigInt(final int sign, final int val)
	{
		dig = new int[1];
		uassign(sign,val);
	}
	
	public BigInt(final int sign, final long val)
	{
		dig = new int[2];
		uassign(sign,val);
	}
	
	public BigInt(final int val)
	{
		dig = new int[1];
		assign(val);
	}
	
	public BigInt(final long val)
	{
		dig = new int[2];
		assign(val);
	}
	
	public BigInt(final String s)
	{
		assign(s);
	}
	
	public BigInt(final char[] s)
	{
		assign(s);
	}
	

	
	
	private int parse(final char[] s, int from, final int to)
	{
		int res = s[from]-'0';
		while(++from<to) res = res*10 + s[from]-'0';
		return res;
	}
	
	private void mulAdd(final int mul, final int add)
	{
		long carry = 0;
		for(int i = 0; i<len; i++)
		{
			carry = mul * (dig[i]&mask) + carry;
			dig[i] = (int)carry;
			carry >>>= 32;
		}
		if(carry!=0) dig[len++] = (int)carry;
		carry = (dig[0]&mask) + add;
		dig[0] = (int)carry;
		if((carry >>> 32)!=0)
		{
			int i = 1;
			for(; i<len && ++dig[i]==0; ++i);
			if(i==len) dig[len++] = 1; 

		}
	}
	
	private void realloc()
	{
		final int[] res = new int[dig.length*2];
		System.arraycopy(dig,0,res,0,len);
		dig = res;
	}
	
	private void realloc(final int newLen)
	{
		final int[] res = new int[newLen];
		System.arraycopy(dig,0,res,0,len);
		dig = res;
	}
	

	
	
	public BigInt copy()
	{
		return new BigInt(sign, Arrays.copyOf(dig,len), len);
	}
	
	public void assign(final BigInt other)
	{
		sign = other.sign;
		assign(other.dig, other.len);
	}
	
	private void assign(final int[] v, final int vlen) 

	{
		if(vlen>dig.length) dig = new int[vlen+2];
		System.arraycopy(v,0,dig,0,len=vlen);
	}
	
	public void assign(final int sign, final int[] v, final int len)
	{
		this.sign = sign; this.len = len;
		dig = v;
	}
	
	public void assign(final String s)
	{
		assign(s.toCharArray());
	}
	
	public void assign(final char[] s)
	{
		sign = s[0]=='-' ? -1 : 1;

		len = s.length + (sign-1>>1);
		final int alloc = len<10 ? 1 : (int)(len*3402L >>> 10) + 32 >>> 5; 

		if(dig==null || alloc>dig.length) dig = new int[alloc];

		int j = len%9;
		if(j==0) j = 9;
		j -= (sign-1>>1);

		dig[0] = parse(s, 0-(sign-1>>1), j);
		for(len = 1; j<s.length;)
			mulAdd(1_000_000_000, parse(s,j,j+=9));
	}
	
	public void uassign(final int s, final int val)
	{
		sign = s;
		len = 1;
		dig[0] = val;
	}
	
	public void uassign(final int s, final long val)
	{
		sign = s;
		len = 2;
		if(dig.length<2) realloc(2);
		dig[0] = (int)(val&mask);
		dig[1] = (int)(val>>>32);
		if(dig[1]==0) --len;
	}
	
	public void uassign(final int val)
	{
		uassign(1, val);
	}
	
	public void uassign(final long val)
	{
		uassign(1, val);
	}
	
	public void assign(final int val)
	{
		uassign(val<0 ? -1 : 1, val<0 ? -val : val);
	}
	
	public void assign(final long val)
	{
		uassign(val<0 ? -1 : 1, val<0 ? -val : val);
	}
	
	public boolean isZero()
	{
		return len==1 && dig[0]==0;
	}
	
	private void id14()
	{
		dig[0] = 0;
		len = 1; sign = 1; 

	}
	
	public int id4(final BigInt a)
	{
		if(len>a.len) return 1;
		if(len<a.len) return -1;
		for(int i = len-1; i>=0; i--)
			if(dig[i]!=a.dig[i])
				if((dig[i]&mask)>(a.dig[i]&mask)) return 1;
				else return -1;
		return 0;
	}
	
	public int compareTo(final BigInt a)
	{
		if(sign<0)
		{
			if(a.sign<0 || a.isZero()) return -id4(a);
			return -1;
		}
		if(a.sign>0 || a.isZero()) return id4(a);
		return 1;
	}
	
	public boolean equals(final BigInt a)
	{
		if(len!=a.len) return false;
		if(isZero() && a.isZero()) return true;
		if((sign^a.sign)<0) return false; 

		for(int i = 0; i<len; i++) if(dig[i]!=a.dig[i]) return false;
		return true;
	}
	
	@Override
	public boolean equals(final Object o) 

	{
		if(o instanceof BigInt) return equals((BigInt)o);
		return false;
	}
	
	@Override
	public int hashCode()
	{
		int hash = 0; 

		for(int i = 0; i<len; i++) hash = (int)(31*hash + (dig[i]&mask));
		return sign*hash; 

	}
	

	
	
	@Override
	public byte byteValue()
	{
		return (byte)(sign*(dig[0]&0x7F));
	}
	
	@Override
	public short shortValue()
	{
		return (short)(sign*(dig[0]&0x7FFF));
	}
	
	@Override
	public int intValue()
	{
		return sign*(dig[0]&0x7FFFFFFF); 

	}
	
	@Override
	public long longValue()
	{
		return len==1 ? sign*(dig[0]&mask) : sign*((dig[1]&0x7FFFFFFFL)<<32|(dig[0]&mask));
	}
	
	@Override
	public float floatValue()
	{
		final int s = Integer.numberOfLeadingZeros(dig[len-1]);
		if(len==1 && s>=8) return sign*dig[0];

		int bits = dig[len-1]; 

		if(s<=8) bits >>>= 8-s;
		else bits = bits<<s-8 | dig[len-2]>>>32-(s-8); 

		bits ^= 1L<<23; 


		final int exp = (int)(((32-s + 32L*(len-1)) - 1 + 127)&0xFF);
		bits |= exp<<23; 

		bits |= sign&(1<<31); 


		return Float.intBitsToFloat(bits);
	}
	
	@Override
	public double doubleValue()
	{
		if(len==1) return sign*(dig[0]&mask);

		final int s = Integer.numberOfLeadingZeros(dig[len-1]);
		if(len==2 && 32-s+32<=53) return sign*((long)dig[1]<<32|(dig[0]&mask));

		long bits = (long)dig[len-1]<<32 | (dig[len-2]&mask); 

		if(s<=11) bits >>>= 11-s;
		else bits = bits<<s-11 | dig[len-3]>>>32-(s-11); 

		bits ^= 1L<<52; 


		final long exp = ((32-s + 32L*(len-1)) - 1 + 1023)&0x7FF;
		bits |= exp<<52; 

		bits |= (long)sign&(1L<<63); 


		return Double.longBitsToDouble(bits);
	}
	

	
	
	private void id15(final int a)
	{
		long tmp = (dig[0]&mask) + (a&mask);
		dig[0] = (int)tmp;
		if((tmp>>>32)!=0)
		{
			int i = 1;
			for(; i<len && ++dig[i]==0; i++);
			if(i==len)
			{
				if(len==dig.length) realloc();
				dig[len++] = 1;
			}
		}
	}
	
	private void id1(final int s)
	{
		long dif = (dig[0]&mask) - (s&mask);
		dig[0] = (int)dif;
		if((dif>>32)!=0)
		{
			int i = 1;
			for(; dig[i]==0; i++) --dig[i];
			if(--dig[i]==0 && i+1==len) --len;
		}
	}
	
	public void uadd(final int a)
	{
		if(sign<0)
		{
			if(len>1 || (dig[0]&mask)>(a&mask)){ id1(a); return; }
			sign = 1;
			dig[0] = a-dig[0]; return;
		}

		id15(a);
	}
	
	public void usub(final int s)
	{
		if(sign<0)
		{
			id15(s);
			return;
		}
		if(len==1 && (dig[0]&mask)<(s&mask)){ sign = -1; dig[0] = s-dig[0]; return; }

		id1(s);
	}
	
	public void umul(final int mul) 

	{
		if(mul==0){ id14(); return; } 


		long carry = 0; final long m = mul&mask;
		for(int i = 0; i<len; i++)
		{
			carry = (dig[i]&mask)*m + carry;
			dig[i] = (int)carry;
			carry >>>= 32;
		}
		if(carry!=0)
		{
			if(len==dig.length) realloc();
			dig[len++] = (int)carry;
		}
	}
	
	public int udiv(final int div) 

	{
		final long d = div&mask;
		long rem = 0;
		for(int i = len-1; i>=0; i--)
		{
			rem <<= 32;
			rem = rem + (dig[i]&mask);
			dig[i] = (int)(rem/d); 

			rem = rem%d;
		}
		if(dig[len-1]==0 && len>1) --len;
		

		return (int)rem;
	}
	
	public void urem(final int mod)
	{
		long rem = 0, d = mod&mask;
		for(int i = len-1; i>=0; i--)
		{
			rem <<= 32;
			rem = (rem + (dig[i]&mask))%d;
		}
		len = 1;
		dig[0] = (int)rem;
		

	}
	

	
	
	private void id15(final long a)
	{
		if(dig.length<=2){ realloc(3); len = 2; }

		final long ah = a>>>32, al = a&mask;
		long carry = (dig[0]&mask) + al;
		dig[0] = (int)carry;
		carry >>>= 32;
		carry = (dig[1]&mask) + ah + carry;
		dig[1] = (int)carry;
		if((carry>>32)!=0)
		{
			int i = 2;
			for(; i<len && ++dig[i]==0; i++);
			if(i==len)
			{
				if(len==dig.length) realloc();
				dig[len++] = 1;
			}
		}
		else if(len==2 && dig[1]==0) --len;
	}
	
	private void id1(final long s)
	{
		final long sh = s>>>32, sl = s&mask;
		long dif = (dig[0]&mask) - sl;
		dig[0] = (int)dif;
		dif >>= 32;
		dif = (dig[1]&mask) - sh + dif;
		dig[1] = (int)dif;
		if((dif>>32)!=0)
		{
			int i = 2;
			for(; dig[i]==0; i++) --dig[i];
			if(--dig[i]==0 && i+1==len) --len;
		}
		if(len==2 && dig[1]==0) --len;
	}
	
	public void uadd(final long a) 

	{
		if(sign<0)
		{
			final long ah = a>>>32, al = a&mask;
			if(len>2 || len==2&&((dig[1]&mask)>ah || (dig[1]&mask)==ah&&(dig[0]&mask)>=al) || ah==0&&(dig[0]&mask)>=al)
			{
				id1(a); return;
			}
			if(dig.length==1) realloc(2);
			if(len==1) dig[len++] = 0;
			long dif = al - (dig[0]&mask);
			dig[0] = (int)dif;
			dif >>= 32;
			dif = ah - (dig[1]&mask) + dif;
			dig[1] = (int)dif;
			

			if(dif==0) --len;
			sign = 1;
		}
		else id15(a);
	}
	
	public void usub(final long a) 

	{
		if(sign>0)
		{
			final long ah = a>>>32, al = a&mask;
			if(len>2 || len==2&&((dig[1]&mask)>ah || (dig[1]&mask)==ah&&(dig[0]&mask)>=al) || ah==0&&(dig[0]&mask)>=al)
			{
				id1(a); return;
			}
			if(dig.length==1) realloc(2);
			if(len==1) dig[len++] = 0;
			long dif = al - (dig[0]&mask);
			dig[0] = (int)dif;
			dif >>= 32;
			dif = ah - (dig[1]&mask) + dif;
			dig[1] = (int)dif;
			

			if(dif==0) --len;
			sign = -1;
		}
		else id15(a);
	}
	
	public void umul(final long mul)
	{
		if(mul==0){ id14(); return; }
		if(len+2>=dig.length) realloc(2*len+1);

		final long mh = mul>>>32, ml = mul&mask;
		long carry = 0, next = 0, tmp;
		for(int i = 0; i<len; i++)
		{
			carry = carry + next; 

			tmp = (dig[i]&mask)*ml;
			next = (dig[i]&mask)*mh;
			dig[i] = (int)(tmp + carry);
			carry = (tmp>>>32)+(carry>>>32) + ((tmp&mask)+(carry&mask)>>>32);
		}
		carry = carry+next;
		dig[len++] = (int)carry;
		dig[len++] = (int)(carry>>>32);

		while(len>1 && dig[len-1]==0) --len;
	}
	
	public long udiv(final long div) 

	{
	   if(div==(div&mask)) return udiv((int)div)&mask;
	   if(len==1)
	   {
		   final long tmp = dig[0]&mask;
		   id14();
		   return tmp;
	   }

	   final int s = Integer.numberOfLeadingZeros((int)(div>>>32));
	   final long dh = div>>>32-s, dl = (div<<s)&mask, hbit = Long.MIN_VALUE;

	   long u2 = 0, u1 = dig[len-1]>>>32-s, u0 = (dig[len-1]<<s | dig[len-2]>>>32-s)&mask;
	   if(s==0){ u1 = 0; u0 = dig[len-1]&mask; }
	   for(int j = len-2; j>=0; j--)
	   {
	      u2 = u1; u1 = u0; u0 = s>0&&j>0 ? (dig[j]<<s | dig[j-1]>>>32-s)&mask : (dig[j]<<s)&mask;

	      long k = (u2<<32) + u1; 

	      long qhat = (k >>> 1)/dh << 1;
		  long t = k - qhat*dh;
		  if(t + hbit >= dh + hbit) qhat++; 

	      long rhat = k - qhat*dh;

	      while(qhat+hbit >= (1L<<32)+hbit || qhat*dl+hbit > (rhat<<32)+u0+hbit) 

	      {
			  --qhat;
			  rhat = rhat + dh;
			  if(rhat+hbit >= (1L<<32)+hbit) break;
	      }

	      

	      long p = qhat*dl;
	      t = u0 - (p&mask);
	      u0 = t&mask;
	      k = (p>>>32) - (t>>32);
	      p = qhat*dh;
	      t = u1 - k - (p&mask);
	      u1 = t&mask;
	      k = (p>>>32) - (t>>32);
	      t = u2 - k;
	      u2 = t&mask;

	      dig[j] = (int)qhat; 

	      if(t<0)
	      {
	         --dig[j]; 

	         t = u0 + dl;
	         u0 = t&mask;
	       	 t >>>= 32;
	         t = u1 + dh + t;
	         u1 = t&mask;
	         t >>>= 32;
	         u2 += t&mask;
	      }
	   }

	   --len;
	   dig[len] = 0;
	   if(len>1 && dig[len-1]==0) --len;

	   final long tmp = u1<<32-s | u0>>>s;
	   return s==0 ? tmp : u2<<64-s | tmp;
	}
	
	public void urem(final long mod)
	{
		final long rem = udiv(mod); 

		len = 2;
		dig[0] = (int)rem;
		if(rem==(rem&mask)){ --len; return; } 

		dig[1] = (int)(rem>>>32);
	}
	

	
	
	public void add(final int add) 

	{
		if(add<0) usub(-add);
		else uadd(add);
	}
	
	public void sub(final int sub)
	{
		if(sub<0) uadd(-sub);
		else usub(sub);
	}
	
	public void mul(final int mul)
	{
		if(isZero()) return; 

		if(mul<0){ sign = -sign; umul(-mul); }
		else umul(mul);
	}
	
	public int div(final int div)
	{
		if(isZero()) return 0; 

		if(div<0){ sign = -sign; return -sign*udiv(-div); }
		return sign*udiv(div);
	}
	

	
	public void add(final long add)
	{
		if(add<0) usub(-add);
		else uadd(add);
	}
	
	public void sub(final long sub)
	{
		if(sub<0) uadd(-sub);
		else usub(sub);
	}
	
	public void mul(final long mul)
	{
		if(isZero()) return; 

		if(mul<0){ sign = -sign; umul(-mul); }
		else umul(mul);
	}
	
	public long div(final long div)
	{
		if(isZero()) return 0; 

		if(div<0){ sign = -sign; return -sign*udiv(-div); }
		return sign*udiv(div);
	}
	

	
	
	private void addMag(int[] v, int vlen)
	{
		int ulen = len;
		int[] u = dig; 

		if(vlen<ulen){ u = v; v = dig; ulen = vlen; vlen = len; }
		if(vlen>dig.length) realloc(vlen+1);

		long carry = 0; int i = 0;
		for(; i<ulen; i++)
		{
			carry = (u[i]&mask) + (v[i]&mask) + carry;
			dig[i] = (int)carry;
			carry >>>= 32;
		}
		if(vlen>len){ System.arraycopy(v, len, dig, len, vlen-len); len = vlen; }
		if(carry!=0) 

		{
			for(; i<len && ++dig[i]==0; i++);
			if(i==len) 

			{
				if(len==dig.length) realloc();
				dig[len++] = 1;
			}
		}
	}
	
	private void subMag(final int[] u, final int ulen)
	{
		final int vlen = len;
		final int[] v = dig; 


		

		long dif = 0; int i = 0;
		for(; i<ulen; i++)
		{
			dif = (v[i]&mask) - (u[i]&mask) + dif;
			dig[i] = (int)dif;
			dif >>= 32;
		}
		if(dif!=0)
		{
			for(; dig[i]==0; i++) --dig[i];
			if(--dig[i]==0 && i+1==len) len = ulen;
		}
		while(len>1 && dig[len-1]==0) --len;
	}
	

	
	
	public void add(final BigInt a)
	{
		if(sign==a.sign){ addMag(a.dig,a.len); return; }
		if(id4(a)>=0)
		{
			subMag(a.dig,a.len);
			

			return;
		}

		final int[] v = a.dig;
		final int vlen = a.len;
		if(dig.length<vlen) realloc(vlen+1);

		sign = -sign;
		long dif = 0; int i = 0;
		for(; i<len; i++)
		{
			dif = (v[i]&mask)-(dig[i]&mask) + dif;
			dig[i] = (int)dif;
			dif >>= 32;
		}
		if(vlen>len){ System.arraycopy(v, len, dig, len, vlen-len); len = vlen; }
		if(dif!=0)
		{
			for(; i<vlen && dig[i]==0; i++) --dig[i];
			if(--dig[i]==0 && i+1==len) --len;
		}
		

	}
	
	public void sub(final BigInt a) 

	{
		if(sign!=a.sign){ addMag(a.dig,a.len); return; }
		if(id4(a)>=0)
		{
			subMag(a.dig,a.len);
			

			return;
		}

		final int[] v = a.dig;
		final int vlen = a.len;
		if(dig.length<vlen) realloc(vlen+1);

		sign = -sign;
		long dif = 0; int i = 0;
		for(; i<len; i++)
		{
			dif = (v[i]&mask)-(dig[i]&mask) + dif;
			dig[i] = (int)dif;
			dif >>= 32;
		}
		if(vlen>len){ System.arraycopy(v, len, dig, len, vlen-len); len = vlen; }
		if(dif!=0)
		{
			for(; i<vlen && dig[i]==0; i++) --dig[i];
			if(--dig[i]==0 && i+1==len) --len;
		}
		

	}

	

	
	public void mul(final BigInt mul)
	{
		if(isZero()) return;
		else if(mul.isZero()) id14();
		else if(mul.len<=2 || len<=2)
		{
			sign *= mul.sign;
			if(mul.len==1) umul(mul.dig[0]);
			else if(len==1){ final int tmp = dig[0]; assign(mul.dig, mul.len); umul(tmp); }
			else if(mul.len==2) umul((long)mul.dig[1]<<32|(mul.dig[0]&mask));
			else{ final long tmp = (long)dig[1]<<32|(dig[0]&mask); assign(mul.dig, mul.len); umul(tmp); }
		}
		else if(len<128 || mul.len<128 || (long)len*mul.len<1_000_000) smallMul(mul); 

		else if(Math.max(len,mul.len)<20000) id2(mul,false); 

		else id2(mul,true);
	}
	
	public void smallMul(final BigInt mul)
	{
		if(isZero()) return; 

		if(mul.isZero()){ id14(); return; }

		sign *= mul.sign;

		int ulen = len, vlen = mul.len;
		int[] u = dig, v = mul.dig; 

		if(vlen<ulen){ u = v; v = dig; ulen = vlen; vlen = len; }

		final int[] res = id5(u,ulen,v,vlen); 


		dig = res; len = res.length;
		if(res[len-1]==0) --len;
	}
	
	public void id2(final BigInt mul) 

	{
		id2(mul,false);
	}
	
	public void id2(final BigInt mul, final boolean parallel) 

	{
		if(mul.dig.length<len) mul.realloc(len);
		else if(dig.length<mul.len) realloc(mul.len);

		if(mul.len<len) for(int i = mul.len; i<len; i++) mul.dig[i] = 0;
		if(len<mul.len) for(int i = len; i<mul.len; i++) dig[i] = 0;

		final int mlen = Math.max(len,mul.len);
		int[] res = null;
		if(!parallel) res = kmul(dig,mul.dig,0,mlen);
		else
		{
			final ExecutorService pool = Executors.newFixedThreadPool(12);
			try{ res = pmul(dig, mul.dig, 0, mlen, 1, pool); }
			catch(Exception e){ System.err.println(e); }
			pool.shutdown();
		}

		len = len+mul.len;
		while(res[len-1]==0) --len;
		dig = res;
		sign *= mul.sign;
	}

	
	
	private static int[] id5(final int[] u, final int ulen, final int[] v, final int vlen)
	{
		final int[] res = new int[ulen+vlen];
		long carry = 0, tmp, ui = u[0]&mask;
		for(int j = 0; j<vlen; j++)
		{
			tmp = ui*(v[j]&mask) + carry;
			res[j] = (int)tmp;
			carry = tmp >>> 32;
		}
		res[vlen] = (int)carry;
		for(int i = 1; i<ulen; i++)
		{
			ui = u[i]&mask; carry = 0;
			for(int j = 0; j<vlen; j++)
			{
				tmp = ui*(v[j]&mask) + (res[i+j]&mask) + carry;
				res[i+j] = (int)tmp;
				carry = tmp >>> 32;
			}
			res[i+vlen] = (int)carry;
		}
		return res;
	}
	
	private static int[] kmul(final int[] x, final int[] y, final int off, final int n)
	{
		

		

		

		

		if(n<=32) 

		{
			final int[] z = new int[2*n];
			long carry = 0, tmp, xi = x[off]&mask;
			for(int j = 0; j<n; j++)
			{
				tmp = xi*(y[off+j]&mask) + carry;
				z[j] = (int)tmp;
				carry = tmp >>> 32;
			}
			z[n] = (int)carry;
			for(int i = 1; i<n; i++)
			{
				xi = x[off+i]&mask; carry = 0;
				for(int j = 0; j<n; j++)
				{
					tmp = xi*(y[off+j]&mask) + (z[i+j]&mask) + carry;
					z[i+j] = (int)tmp;
					carry = tmp >>> 32;
				}
				z[i+n] = (int)carry;
			}
			return z;
		}

		final int b = n>>>1;
		final int[] z2 = kmul(x,y,off+b,n-b);
		final int[] z0 = kmul(x,y,off,b);

		final int[] x2 = new int[n-b+1], y2 = new int[n-b+1];
		long carry = 0;
		for(int i = 0; i<b; i++)
		{
			carry = (x[off+b+i]&mask) + (x[off+i]&mask) + carry;
			x2[i] = (int)carry;
			carry >>>= 32;
		}
		if((n&1)!=0) x2[b] = x[off+b+b];
		if(carry!=0) if(++x2[b]==0) ++x2[b+1];
		carry = 0;
		for(int i = 0; i<b; i++)
		{
			carry = (y[off+b+i]&mask) + (y[off+i]&mask) + carry;
			y2[i] = (int)carry;
			carry >>>= 32;
		}
		if((n&1)!=0) y2[b] = y[off+b+b];
		if(carry!=0) if(++y2[b]==0) ++y2[b+1];

		final int[] z1 = kmul(x2,y2,0,n-b+(x2[n-b]!=0 || y2[n-b]!=0 ? 1 : 0));

		final int[] z = new int[2*n];
		System.arraycopy(z0,0,z,0,2*b); 

		System.arraycopy(z2,0,z,b+b,2*(n-b)); 


		

		carry = 0;
		int i = 0;
		for(; i<2*b; i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) - (z2[i]&mask) - (z0[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		for(; i<2*(n-b); i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) - (z2[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		for(; i<z1.length; i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		if(carry!=0) while(++z[i+b]==0) ++i;

		return z;
	}
	
	private static int[] pmul(final int[] x, final int[] y, final int off, final int n, final int lim, final ExecutorService pool) throws Exception
	{
		final int b = n>>>1;

		final Future<int[]> left = pool.submit(new Callable<int[]>(){
			public int[] call() throws Exception
			{
				return lim==0 ? kmul(x,y,off,b) : pmul(x,y,off,b,lim-1,pool);
			}
		});

		final Future<int[]> right = pool.submit(new Callable<int[]>(){
			public int[] call() throws Exception
			{
				return lim==0 ? kmul(x,y,off+b,n-b) : pmul(x,y,off+b,n-b,lim-1,pool);
			}
		});

		final int[] x2 = new int[n-b+1], y2 = new int[n-b+1];
		long carry = 0;
		for(int i = 0; i<b; i++)
		{
			carry = (x[off+b+i]&mask) + (x[off+i]&mask) + carry;
			x2[i] = (int)carry;
			carry >>>= 32;
		}
		if((n&1)!=0) x2[b] = x[off+b+b];
		if(carry!=0) if(++x2[b]==0) ++x2[b+1];
		carry = 0;
		for(int i = 0; i<b; i++)
		{
			carry = (y[off+b+i]&mask) + (y[off+i]&mask) + carry;
			y2[i] = (int)carry;
			carry >>>= 32;
		}
		if((n&1)!=0) y2[b] = y[off+b+b];
		if(carry!=0) if(++y2[b]==0) ++y2[b+1];

		final Future<int[]> mid = pool.submit(new Callable<int[]>(){
			public int[] call() throws Exception
			{
				return lim==0 ? kmul(x2,y2,0,n-b+(x2[n-b]!=0 || y2[n-b]!=0 ? 1 : 0)) :
					pmul(x2,y2,0,n-b+(x2[n-b]!=0 || y2[n-b]!=0 ? 1 : 0),lim-1,pool);
			}
		});

		final int[] z = new int[2*n];

		final int[] z0 = left.get();
		System.arraycopy(z0,0,z,0,2*b);
		final int[] z2 = right.get();
		System.arraycopy(z2,0,z,b+b,2*(n-b));

		final int[] z1 = mid.get();

		carry = 0;
		int i = 0;
		for(; i<2*b; i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) - (z2[i]&mask) - (z0[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		for(; i<2*(n-b); i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) - (z2[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		for(; i<z1.length; i++)
		{
			carry = (z[i+b]&mask) + (z1[i]&mask) + carry;
			z[i+b] = (int)carry;
			carry >>= 32;
		}
		if(carry!=0) while(++z[i+b]==0) ++i;
		return z;
	}
	

	

	
	public void div(final BigInt div)
	{
		if(div.len==1){ sign *= div.sign; udiv(div.dig[0]); return; }

		int tmp = id4(div);
		if(tmp<0){ id14(); return; }
		if(tmp==0){ uassign(1, sign*div.sign); return; }

		final int[] q = new int[len-div.len+1];
		if(len==dig.length) realloc(len+1); 

		div(dig, div.dig, len, div.len, q);

		dig = q;
		for(len = q.length; len>1 && dig[len-1]==0; --len);
		sign *= div.sign;
	}
	
	public void rem(final BigInt div)
	{
		

		

		

		

		if(div.len==1){ urem(div.dig[0]); return; }

		int tmp = id4(div);
		if(tmp<0) return;
		if(tmp==0){ id14(); return; }

		final int[] q = new int[len-div.len+1];
		if(len==dig.length) realloc(len+1); 

		div(dig, div.dig, len, div.len, q);

		for(len = div.len; dig[len-1]==0; --len);
	}
	
	public BigInt divRem(final BigInt div)
	{
		int tmp = sign;
		if(div.len==1){ sign *= div.sign; return new BigInt(tmp, udiv(div.dig[0])); }

		tmp = id4(div);
		if(tmp<0)
		{
			final BigInt cpy = new BigInt(sign,dig,len);
			dig = new int[2]; len = 1; 

			return cpy;
		}
		if(tmp==0){ uassign(1, sign *= div.sign); return new BigInt(1,0); }

		final int[] q = new int[len-div.len+1];
		if(len==dig.length) realloc(len+1); 

		div(dig, div.dig, len, div.len, q);

		final int[] r = dig;
		dig = q;
		for(len = q.length; len>1 && dig[len-1]==0; --len);

		tmp = div.len;
		while(tmp>1 && r[tmp-1]==0) --tmp;
		sign *= div.sign;
		return new BigInt(sign/div.sign, r, tmp);
	}
	
	private void div(final int[] u, final int[] v, final int m, final int n, final int[] q)
	{

	   final long b = 1L<<32;	 

	   long qhat;				

	   long rhat;	            

	   long p; 	              


	   int s, i, j;
	   long t, k;

	   

	   

	   

	   


	   s = Integer.numberOfLeadingZeros(v[n-1]);
	   if(s>0) 

	   {
		   for(i = n-1; i > 0; i--) v[i] = (v[i] << s) | (v[i-1] >>> 32-s);
		   v[0] = v[0] << s;

		   u[m] = u[m-1] >>> 32-s;
		   for (i = m-1; i > 0; i--) u[i] = (u[i] << s) | (u[i-1] >>> 32-s);
		   u[0] = u[0] << s;
	   }

	   final long dh = v[n-1]&mask, dl = v[n-2]&mask, hbit = Long.MIN_VALUE;

	   for(j = m-n; j>=0; j--) 

	   {
	      

	      k = u[j+n]*b + (u[j+n-1]&mask); 

	      qhat = (k >>> 1)/dh << 1;
		  t = k - qhat*dh;
		  if(t + hbit >= dh + hbit) qhat++; 

	      rhat = k - qhat*dh;

	      while(qhat+hbit >= b+hbit || qhat*dl+hbit > b*rhat+(u[j+n-2]&mask)+hbit) 

	      {
			  qhat = qhat - 1;
			  rhat = rhat + dh;
			  if(rhat+hbit >= b+hbit) break;
	      }

	      

	      k = 0;
	      for(i = 0; i<n; i++)
	      {
	         p = qhat*(v[i]&mask);
	         t = (u[i+j]&mask) - k - (p&mask);
	         u[i+j] = (int)t;
	         k = (p>>>32) - (t>>32);
	      }
	      t = (u[j+n]&mask) - k;
	      u[j+n] = (int)t;

	      q[j] = (int)qhat;              

	      if(t<0)
	      {
	         q[j] = q[j] - 1;
	         k = 0;
	         for(i = 0; i<n; i++)
	         {
	            t = (u[i+j]&mask) + (v[i]&mask) + k;
	            u[i+j] = (int)t;
	            k = t >>> 32; 

	         }
	         u[j+n] += (int)k;
	      }
	   }

	   if(s>0)
	   {
		   

		   for(i = 0; i<n-1; i++) v[i] = v[i]>>>s | v[i+1]<<32-s;
		   v[n-1] >>>= s;

		   

		   for(i = 0; i<m; i++) u[i] = u[i]>>>s | u[i+1]<<32-s;
		   u[m] >>>= s;
	   }
	}
	

	
	
	public String toString()
	{
		if(isZero()) return "0";

		int top = len*10 + 1;
		final char[] buf = new char[top];
		Arrays.fill(buf, '0');
		final int[] cpy = Arrays.copyOf(dig,len);
		while(true)
		{
			final int j = top;
			for(int tmp = udiv(1_000_000_000); tmp>0; tmp/=10)
				buf[--top] += tmp%10; 

			if(len==1 && dig[0]==0) break;
			else top = j-9;
		}
		if(sign<0) buf[--top] = '-';
		System.arraycopy(cpy,0,dig,0, len = cpy.length);
		return new String(buf, top, buf.length-top);
	}
	

	
	

	

	


	
	private void id3(final int shift, final int first)
	{
		int[] res = dig;
		if((dig[len-1]<<shift>>>shift)!=dig[len-1]) 

			if(++len>dig.length)
				res = new int[len+1]; 

			else dig[len-1] = 0;

		int nxt = len>dig.length ? 0 : dig[len-1];
		for(int i = len-1; i>first; i--) res[i] = nxt<<shift | (nxt = dig[i-1])>>>32-shift;
		res[first] = nxt<<shift;
		dig = res;
	}

	
	private void id0(final int shift)
	{
		int nxt = dig[0];
		for(int i = 0; i<len-1; i++) dig[i] = nxt>>>shift | (nxt = dig[i+1])<<32-shift;
		if((dig[len-1]>>>=shift)==0 && len>1) --len;
	}

	
	private void id6(final int shift)
	{
		if(len+shift>dig.length)
		{
			final int[] res = new int[len+shift+1];
			System.arraycopy(dig, 0, res, shift, len);
			dig = res;
		}
		else
		{
			System.arraycopy(dig, 0, dig, shift, len);
			for(int i = 0; i<shift; i++) dig[i] = 0;
		}
		len += shift;
	}

	
	private void id12(final int shift)
	{
		System.arraycopy(dig, shift, dig, 0, len-shift);
		

		len -= shift;
	}

	
	public void shiftLeft(final int shift)
	{
		final int bigShift = shift>>>5, smallShift = shift&31;
		if(bigShift>0) id6(bigShift);
		if(smallShift>0) id3(smallShift, bigShift);
	}

	
	public void shiftRight(final int shift)
	{
		final int bigShift = shift>>>5, smallShift = shift&31;
		if(bigShift>0) id12(bigShift);
		if(smallShift>0) id0(smallShift);
	}

	
	public boolean testBit(final int bit)
	{
		final int bigBit = bit>>>5, smallBit = bit&31;
		if(bigBit>=len) return sign<0;
		if(sign>0) return (dig[bigBit]&1<<smallBit)!=0;
		int j = 0;
		for(; j<=bigBit && dig[j]==0;) ++j;
		if(j>bigBit) return false;
		if(j<bigBit) return (dig[bigBit]&1<<smallBit)==0;
		j = -dig[bigBit];
		return (j&1<<smallBit)!=0;
	}

	
	public void setBit(final int bit)
	{
		final int bigBit = bit>>>5, smallBit = bit&31;
		if(sign>0)
		{
			if(bigBit>=dig.length)
			{
				realloc(bigBit+1);
				len = bigBit+1;
			}
			else if(bigBit>=len)
			{
				for(; len<=bigBit; len++) dig[len] = 0;
				

			}
			dig[bigBit] |= 1<<smallBit;
		}
		else
		{
			if(bigBit>=len) return;
			int j = 0;
			for(; j<=bigBit && dig[j]==0;) ++j;
			if(j>bigBit)
			{
				dig[bigBit] = -1<<smallBit;
				for(; dig[j]==0; j++) dig[j] = -1;
				dig[j] = ~-dig[j];
				if(j==len-1 && dig[len-1]==0) --len;
				return;
			}
			if(j<bigBit)
			{
				dig[bigBit] &= ~(1<<smallBit);
				while(dig[len-1]==0) --len;
				return;
			}
			j = Integer.lowestOneBit(dig[j]); 

			final int k = 1<<smallBit;
			if(k-j>0) dig[bigBit] &= ~k; 

			else{ dig[bigBit] ^= ((j<<1)-1)^(k-1); dig[bigBit] |= k; }
		}
	}

	
	public void clearBit(final int bit)
	{
		final int bigBit = bit>>>5, smallBit = bit&31;
		if(sign>0)
		{
			if(bigBit<len)
			{
				dig[bigBit] &= ~(1<<smallBit);
				while(dig[len-1]==0 && len>1) --len;
			}
		}
		else
		{
			if(bigBit>=dig.length)
			{
				realloc(bigBit+1);
				len = bigBit+1;
				dig[bigBit] |= 1<<smallBit;
				return;
			}
			else if(bigBit>=len)
			{
				for(; len<=bigBit; len++) dig[len] = 0;
				dig[bigBit] |= 1<<smallBit;
				return;
			}
			int j = 0;
			for(; j<=bigBit && dig[j]==0;) ++j;
			if(j>bigBit) return;
			if(j<bigBit)
			{
				dig[bigBit] |= 1<<smallBit;
				return;
			}
			j = Integer.lowestOneBit(dig[j]); 

			final int k = 1<<smallBit;
			if(j-k>0) return; 

			if(j-k<0){ dig[bigBit] |= k; return; }
			j = dig[bigBit];
			if(j==(-1^k-1))
			{
				dig[bigBit] = 0;
				for(j=bigBit+1; j<len && dig[j]==-1; j++) dig[j] = 0;
				if(j==dig.length) realloc(j+2);
				if(j==len){ dig[len++] = 1; return; }
				dig[j] = -~dig[j];
			}
			else
			{
				j = Integer.lowestOneBit(j^(-1^k-1));
				dig[bigBit] ^= j|(j-1)^(k-1);
			}
		}
	}

	
	public void flipBit(final int bit)
	{
		final int bigBit = bit>>>5, smallBit = bit&31;
		block:
		if(bigBit>=dig.length)
		{
			realloc(bigBit+1);
			len = bigBit+1;
			dig[bigBit] ^= 1<<smallBit;
		}
		else if(bigBit>=len)
		{
			for(; len<=bigBit; len++) dig[len] = 0;
			dig[bigBit] ^= 1<<smallBit;
		}
		else if(sign>0) dig[bigBit] ^= 1<<smallBit;
		else
		{
			int j = 0;
			for(; j<=bigBit && dig[j]==0;) ++j;
			if(j<bigBit)
			{
				dig[bigBit] ^= 1<<smallBit;
				break block;
			}
			if(j>bigBit) 

			{
				dig[bigBit] = -1<<smallBit;
				for(; dig[j]==0; j++) dig[j] = -1;
				dig[j] = ~-dig[j];
				if(j==len-1 && dig[len-1]==0) --len;
				return;
			}
			j = Integer.lowestOneBit(dig[j]); 

			final int k = 1<<smallBit;
			if(j-k>0){ dig[bigBit] ^= ((j<<1)-1)^(k-1); return; }
			if(j-k<0){ dig[bigBit] ^= k; return; }
			j = dig[bigBit];
			if(j==(-1^k-1)) 

			{
				dig[bigBit] = 0;
				for(j=bigBit+1; j<len && dig[j]==-1; j++) dig[j] = 0;
				if(j==dig.length) realloc(j+2);
				if(j==len){ dig[len++] = 1; return; }
				dig[j] = -~dig[j];
			}
			else
			{
				j = Integer.lowestOneBit(j^(-1^k-1));
				dig[bigBit] ^= j|(j-1)^(k-1);
			}
		}
		while(dig[len-1]==0 && len>1) --len;
	}

	
	private int id11()
	{
		int zeros = 0, i = 0;
		for(; dig[i]==0; i++) zeros += 32;
		return zeros + Integer.id11(dig[i]);
	}

	
	public void and(final BigInt mask)
	{
		if(mask.sign>0)
		{
			if(sign>0)
			{
				if(mask.len<len) len = mask.len;
				for(int i = 0; i<len; i++) dig[i] &= mask.dig[i];
			}
			else
			{
				final int bigFirst = id11() >>> 5;
				if(mask.len<=bigFirst){ id14(); return; }
				dig[bigFirst] = -dig[bigFirst]&mask.dig[bigFirst];
				if(mask.len<len) len = mask.len;
				for(int i = bigFirst+1; i<len; i++) dig[i] = ~dig[i]&mask.dig[i];
				if(mask.len>len)
				{
					if(mask.len>dig.length) realloc(mask.len+1);
					System.arraycopy(mask.dig, len, dig, len, mask.len-len);
					len = mask.len;
				}
				sign = 1;
			}
			while(dig[len-1]==0 && len>1) --len;
		}
		else
		{
			if(sign>0)
			{
				

				final int bigFirst = mask.id11() >>> 5;
				if(len<=bigFirst){ id14(); return; }
				for(int i = 0; i<bigFirst; i++) dig[i] = 0;
				dig[bigFirst] = dig[bigFirst]&-mask.dig[bigFirst];
				final int minLen = Math.min(len, mask.len);
				for(int i = bigFirst+1; i<minLen; i++) dig[i] &= ~mask.dig[i];
				while(dig[len-1]==0 && len>1) --len;
			}
			else
			{
				final int bigFirst = id11() >>> 5;
				if(mask.len<=bigFirst) return;
				final int id13 = mask.id11() >>> 5;
				if(len<=id13){ assign(mask); return; }
				if(mask.len>dig.length) realloc(mask.len+1);

				for(int i = bigFirst; i<id13; i++) dig[i] = 0;
				int j = Math.max(bigFirst, id13);
				int a = bigFirst==j ? -dig[j] : ~dig[j];
				int b = id13==j ? -mask.dig[j] : ~mask.dig[j];
				final int last = Math.min(len, mask.len) - 1;
				for(; (a&b)==0 && j<last; j++, a=~dig[j], b=~mask.dig[j]) dig[j] = 0;
				if(j<last || (a&b)!=0)
				{
					dig[j] = -(a&b);
					for(++j; j<=last; j++) dig[j] |= mask.dig[j]; 

				}
				else 

				{
					dig[j] = 0;
					if(len==mask.len) dig[len++] = 1;
				}
				if(mask.len>len){ System.arraycopy(mask.dig, len, dig, len, mask.len-len); len = mask.len; }
			}
		}
	}

	
	public void or(final BigInt mask)
	{
		if(sign>0)
		{
			if(mask.sign>0)
			{
				if(mask.len>len)
				{
					if(mask.len>dig.length) realloc(mask.len+1);
					System.arraycopy(mask.dig, len, dig, len, mask.len-len);
					for(int i = 0; i<len; i++) dig[i] |= mask.dig[i];
					len = mask.len;
				}
				else for(int i = 0; i<mask.len; i++) dig[i] |= mask.dig[i];
			}
			else
			{
				if(mask.len>dig.length) realloc(mask.len+1);
				if(mask.len>len){ System.arraycopy(mask.dig, len, dig, len, mask.len-len); }
				final int mLen = Math.min(mask.len, len);
				int a = dig[0], b = mask.dig[0], j = 1;
				for(; (a|b)==0 && j<mLen; a = dig[j], b = mask.dig[j], j++);
				if(a!=0 && b==0)
				{
					dig[j-1] = -a;
					for(; mask.dig[j]==0; j++) dig[j] ^= -1;
					if(j<mLen)
						dig[j] = ~(dig[j]|-mask.dig[j]);
					else 

						dig[j] = ~-dig[j];
					++j;
				}
				else if(a==0) 

				{
					for(dig[j-1] = b; j<mLen && dig[j]==0; j++) dig[j] = mask.dig[j];
				}
				else 

				{
					dig[j-1] = -(a|-b);
				}
				for(; j<mLen; j++) dig[j] = ~dig[j]&mask.dig[j]; 

				sign = -1;
				len = mask.len;
				while(dig[len-1]==0) --len;
			}
		}
		else
		{
			final int mLen = Math.min(mask.len, len);
			int a = dig[0], b = mask.dig[0], j = 1;
			for(; (a|b)==0 && j<mLen; a = dig[j], b = mask.dig[j], j++);
			if(mask.sign>0)
			{
				if(a!=0 && b==0)
				{
					for(; j<mLen && mask.dig[j]==0; j++);
				}
				else if(a==0) 

				{
					dig[j-1] = -b;
					for(; j<mLen && dig[j]==0; j++) dig[j] = ~mask.dig[j];
					if(j<mLen)
						dig[j] = ~(-dig[j]|mask.dig[j]);
					else
					{
						for(; dig[j]==0; j++) dig[j] = -1;
						dig[j] = ~-dig[j];
					}
					++j;
				}
				else 

				{
					dig[j-1] = -(-a|b);
				}
				for(; j<mLen; j++) dig[j] &= ~mask.dig[j]; 

			}
			else
			{
				if(a!=0 && b==0)
				{
					for(; j<mLen && mask.dig[j]==0; j++);
					if(j<mLen) dig[j] = ~(~dig[j]|-mask.dig[j]);
					++j;
				}
				else if(a==0) 

				{
					for(dig[j-1] = b; j<mLen && dig[j]==0; j++) dig[j] = mask.dig[j];
					if(j<mLen) dig[j] = ~(-dig[j]|~mask.dig[j]);
					++j;
				}
				else 

				{
					dig[j-1] = -(-a|-b);
				}
				for(; j<mLen; j++) dig[j] &= mask.dig[j]; 

				len = mLen;
			}
			while(dig[len-1]==0) --len;
		}
	}

	
	public void xor(final BigInt mask)
	{
		if(sign>0)
		{
			if(mask.len>len)
			{
				if(mask.len>dig.length) realloc(mask.len+2);
				System.arraycopy(mask.dig, len, dig, len, mask.len-len);
			}
			final int mlen = Math.min(len, mask.len);
			if(mask.sign>0)
			{
				for(int i = 0; i<mlen; i++) dig[i] ^= mask.dig[i];
			}
			else
			{
				int a = dig[0], b = mask.dig[0], j = 1;
				for(; (a|b)==0 && j<mlen; a = dig[j], b = mask.dig[j], j++);
				if(a!=0 && b==0)
				{
					dig[j-1] = -a;
					for(; mask.dig[j]==0; ++j) dig[j] ^= -1;
					if(j<len) dig[j] = ~(dig[j]^-mask.dig[j]);
					else dig[j] = ~-mask.dig[j];
					++j;
				}
				else if(a==0) 

				{
					dig[j-1] = b; 

				}
				else 

				{
					dig[j-1] = -(a^-b);
					for(; j<mlen && dig[j-1]==0; j++) dig[j] = -(dig[j]^~mask.dig[j]);
					if(j>=mlen && dig[j-1]==0)
					{
						final int[] tmp = j<len ? dig : mask.dig;
						final int blen = Math.max(len, mask.len);
						for(; j<blen && tmp[j]==-1; j++) dig[j] = 0;
						if(blen==dig.length) realloc(blen+2); 

						if(j==blen){ dig[blen] = 1; len = blen+1; }
						else dig[j] = -~tmp[j];
						++j;
					}
				}
				for(; j<mlen; j++) dig[j] ^= mask.dig[j]; 

				sign = -1;
			}
			if(mask.len>len) len = mask.len;
			else while(dig[len-1]==0 && len>1) --len;
		}
		else
		{
			if(mask.len>len)
			{
				if(mask.len>dig.length) realloc(mask.len+2);
				System.arraycopy(mask.dig, len, dig, len, mask.len-len);
			}
			final int mlen = Math.min(len, mask.len);
			if(mask.sign>0)
			{
				int a = dig[0], b = mask.dig[0], j = 1;
				for(; (a|b)==0 && j<mlen; a = dig[j], b = mask.dig[j], j++);
				if(a!=0 && b==0)
				{
					while(j<mlen && mask.dig[j]==0) ++j;
				}
				else if(a==0) 

				{
					for(dig[j-1] = -b; j<mlen && dig[j]==0; j++) dig[j] = ~mask.dig[j];
					while(j<len && dig[j]==0) dig[j++] = -1;
					if(j<mlen) dig[j] = ~(-dig[j]^mask.dig[j]);
					else dig[j] = ~-dig[j];
					++j;
				}
				else 

				{
					dig[j-1] = -(-a^b);
				}
				for(; j<mlen; j++) dig[j] ^= mask.dig[j]; 

			}
			else
			{
				int a = dig[0], b = mask.dig[0], j = 1;
				for(; (a|b)==0 && j<mlen; a = dig[j], b = mask.dig[j], j++);
				if(a!=0 && b==0)
				{
					for(dig[j-1] = -a; mask.dig[j]==0; j++) dig[j] ^= -1; 

					if(j<len) dig[j] = ~dig[j]^-mask.dig[j];
					else dig[j] = ~-dig[j]; 

					++j;
				}
				else if(a==0) 

				{
					for(dig[j-1] = -b; j<mask.len && dig[j]==0; j++) dig[j] = ~mask.dig[j];
					while(dig[j]==0) dig[j++] = -1;
					if(j<mask.len) dig[j] = -dig[j]^~mask.dig[j];
					else dig[j] = ~-dig[j]; 

					++j;
				}
				else 

				{
					dig[j-1] = -a^-b;
				}
				for(; j<mlen; j++) dig[j] ^= mask.dig[j]; 

				sign = 1;
			}
			if(mask.len>len) len = mask.len;
			else while(dig[len-1]==0 && len>1) --len;
		}
	}

	
	public void andNot(final BigInt mask)
	{
		final int mlen = Math.min(len, mask.len);
		if(sign>0)
		{
			if(mask.sign>0)
			{
				for(int i = 0; i<mlen; i++) dig[i] &= ~mask.dig[i];
			}
			else
			{
				int j = 0;
				while(j<mlen && mask.dig[j]==0) ++j;
				if(j<mlen)
					for(dig[j] &= ~-mask.dig[j]; ++j<mlen; ) dig[j] &= mask.dig[j]; 

				len = mlen;
			}
		}
		else
		{
			if(mask.len>len)
			{
				if(mask.len>dig.length) realloc(mask.len+2);
				System.arraycopy(mask.dig, len, dig, len, mask.len-len);
			}
			if(mask.sign>0)
			{
				int j = 0;
				while(dig[j]==0) ++j;
				if(j<mlen)
				{
					dig[j] = -(-dig[j]&~mask.dig[j]);
					for(; ++j<mlen && dig[j-1]==0; ) dig[j] = -~(dig[j]|mask.dig[j]); 

					if(j==mlen && dig[j-1]==0)
					{
						final int blen = Math.max(len, mask.len);
						while(j<blen && dig[j]==-1) dig[j++] = 0; 

						if(j<blen) dig[j] = -~dig[j];
						else
						{
							if(blen>=dig.length) realloc(blen+2);
							dig[blen] = 1;
							len = blen+1;
							return;
						}
						++j;
					}
					for(; j<mlen; j++) dig[j] |= mask.dig[j]; 

					if(mask.len>len) len = mask.len;
				}
			}
			else
			{
				int a = dig[0], b = mask.dig[0], j = 1;
				for(; j<mlen && (a|b)==0; a=dig[j], b=mask.dig[j], ++j);
				if(a!=0 && b==0)
				{
					dig[j-1] = -a;
					for(; j<mask.len && mask.dig[j]==0; j++) dig[j] ^= -1;
					if(j<len) dig[j] = ~(dig[j]|-mask.dig[j]); 

					else dig[j] = ~-dig[j]; 

					++j;
				}
				else if(a==0) 

				{
					for(; j<mlen && dig[j]==0; j++);
					if(j<mlen) dig[j] = -dig[j]&mask.dig[j]; 

					++j;
				}
				else
				{
					dig[j-1] = -a&~-b;
				}
				for(; j<mlen; j++) dig[j] = ~dig[j]&mask.dig[j];
				len = mask.len;
				sign = 1;
			}
		}
		while(dig[len-1]==0 && len>1) --len;
	}

	
	public void not()
	{
		if(sign>0)
		{
			sign = -1;
			id15(1);
		}
		else
		{
			sign = 1;
			id1(1);
		}
	}
	
}