import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.*;

public class Main
{
	static String id14[], id13[], shuzi[], id6[], shijin[], id19[], id10[], id12[],
			jingzhi[], id11[];
	static int month[], coordinate[][], coordinates[][], id17[][];

	static
	{
		id14 = new String[]
		{ "rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "goat", "monkey", "rooster", "dog", "pig" };
		id13 = new String[]
		{ "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig" };
		shuzi = new String[]
		{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		id6 = new String[]
		{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
		shijin = new String[]
		{ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
				"nineteen" };
		id19 = new String[]
		{ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
				"Nineteen" };
		id10 = new String[]
		{ "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
		id12 = new String[]
		{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		jingzhi = new String[]
		{ "billion", "million", "thousand", "hundred" };
		id11 = new String[]
		{ "", "", "Hundred", "Thousand", "", "", "Million", "", "", "Billion" };
		month = new int[]
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		coordinate = new int[][]
		{
				{ -1, 0 },
				{ 0, 1 },
				{ 1, 0 },
				{ 0, -1 },
				{ -1, -1 },
				{ -1, 1 },
				{ 1, -1 },
				{ 1, 1 } };
		coordinates = new int[][]
		{
				{ -1, 0 },
				{ -1, 1 },
				{ 0, 1 },
				{ 1, 1 },
				{ 1, 0 },
				{ 1, -1 },
				{ 0, -1 },
				{ -1, -1 } };
		id17 = new int[][]
		{
				{ -1, -2 },
				{ 1, -2 },
				{ 2, -1 },
				{ 2, 1 },
				{ 1, 2 },
				{ -1, 2 },
				{ -2, 1 },
				{ -2, -1 } };
	}

	static int mod = (int) 998244353;


	static int N = (int) 1e3;
	static int M = (int) N * 30;

	static int inf = (int) 0x3f3f3f3f;
















	static class edge
	{

	}

	static class node implements Comparable<node>
	{

		int x, y;

		public node(int x, int y)
		{
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(node other)
		{
			if (this.x != other.x)
				return this.x - other.x;
			return this.y - other.y;
		}

	}

	static void init()




	{

	}

	static void fill()
	{

	}

	static boolean is()










	{












		return true;


	}

	static void solve()






	{
		fill();

		int n = sc.readInt();
		int a[] = new int[n + 10];
		for (int i = 1; i <= n; i++)
			a[i] = sc.readInt();

		boolean f = true;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i != n && a[i + 1] - a[i] > 1)
				f = false;
			else if (i == n && a[1] - a[n] > 1)
				f = false;

			if (a[i] == 1)
				cnt++;
		}
		if (f && cnt == 1)
			out.printLine("Yes");
		else
			out.printLine("No");
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		init();

		long t = 1;
		t = sc.readLong();

		for (int i = 1; i <= t; i++)
		{



			solve();
		}

		out.close();
	}

	static long max(long a, long b)
	{
		return a > b ? a : b;
	}

	static long min(long a, long b)
	{
		return a < b ? a : b;
	}

	static InputStream inputStream = System.in;
	static OutputStream outputStream = System.out;
	static InputReader sc = new InputReader(inputStream);
	static OutputWriter out = new OutputWriter(outputStream);

































	static class InputReader
	{
		

		private InputStream stream;
		

		private byte[] buf = new byte[1024];
		private int curChar;

		private int numChars;

		

		private id18 filter;

		

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}

		

		public int read()
		{
			if (numChars == -1)
				throw new InputMismatchException();
			

			if (curChar >= numChars)
			{
				curChar = 0;

				try
				{
					

					numChars = stream.read(buf);
				} catch (IOException e)
				{
					throw new InputMismatchException();
				}
				if (numChars <= 0)

					return -1;
			}
			

			return buf[curChar++];
		}

		

		public int readInt()
		{
			int c = read();
			while (id3(c))

				c = read();
			int sgn = 1;

			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			int res = 0;
			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id3(c));
			

			return res * sgn;
		}

		

		public long readLong()
		{
			int c = read();
			while (id3(c))
				c = read();
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id3(c));
			return res * sgn;
		}

		

		public String readString()
		{
			int c = read();
			while (id3(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do
			{
				

				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);

				c = read();
			} while (!id3(c));
			return res.toString();
		}

		

		public String next()
		{
			return readString();
		}

		

		public static String[] id16(InputReader in, int size)
		{
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readString();
			return array;
		}

		

		public static String[][] id15(InputReader in, int rowCount, int columnCount)
		{
			String[][] table = new String[rowCount][];
			for (int i = 0; i < rowCount; i++)
				table[i] = id16(in, columnCount);
			return table;
		}

		

		public char readCharacter()
		{
			int c = read();
			while (id3(c))
				c = read();
			return (char) c;
		}

		

		public String id9()
		{
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do
			{
				

				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);

				c = read();
			} while (!id1(c));
			return res.toString();
		}

		

		public double readDouble()
		{
			int c = read();
			while (id3(c))
				c = read();
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!id3(c) && c != '.')
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.')
			{
				c = read();
				double m = 1;
				while (!id3(c))
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}

		public boolean id3(int c)
		{
			if (filter != null)
				return filter.id3(c);
			return isWhitespace(c);
		}

		public boolean id1(int c)
		{
			if (filter != null)
				return filter.id1(c);
			return id8(c);
		}

		

		public static boolean id8(int c)
		{
			return c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public static boolean isWhitespace(int c)
		{
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		

		public interface id18
		{
			public boolean id3(int ch);

			public boolean id1(int ch);
		}
	}

	static class OutputWriter
	{
		

		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream)
		{
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		

		public void print(int[] array)
		{
			for (int i = 0; i < array.length; i++)
			{
				if (i != 0)
					writer.print(' ');
				writer.print(array[i]);
			}
		}

		

		public void printLine(int[] array)
		{
			print(array);
			writer.println();
		}

		public void print(Object... objects)
		{
			for (int i = 0; i < objects.length; i++)
			{
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects)
		{
			print(objects);
			writer.println();
		}

		public void close()
		{
			writer.close();
		}

		public void print(int i)
		{
			writer.print(i);
		}

		public void print(String i)
		{
			writer.print(i);
		}

		public void print(long i)
		{
			writer.print(i);
		}

		public void print(char i)
		{
			writer.print(i);
		}

		public void printf(String format, Object... x)
		{
			writer.printf(format, x);
		}

		

		public void printLine(int i)
		{
			writer.println(i);
		}

		public void printLine(long i)
		{
			writer.println(i);
		}
	}

	static class IOUtils
	{
		

		public static int[] id0(InputReader in, int size)
		{
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readInt();
			return array;
		}

		

		public static int[][] id4(InputReader in, int rowCount, int columnCount)
		{
			int[][] table = new int[rowCount][];
			for (int i = 0; i < rowCount; i++)
				table[i] = id0(in, columnCount);
			return table;
		}

		

		public static void id7(InputReader in, int[]... arrays)
		{
			for (int i = 0; i < arrays[0].length; i++)
			{
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = in.readInt();
			}
		}

		public static char[] id2(InputReader in, int size)
		{
			char[] array = new char[size];
			for (int i = 0; i < size; i++)
				array[i] = in.readCharacter();
			return array;
		}

		public static char[][] readTable(InputReader in, int rowCount, int columnCount)
		{
			char[][] table = new char[rowCount][];
			for (int i = 0; i < rowCount; i++)
				table[i] = id2(in, columnCount);
			return table;
		}

	}

	static class MiscUtils
	{
		public static void id5(int[]... arrays)
		{
			for (int[] array : arrays)
			{
				for (int i = 0; i < array.length; i++)
					array[i]--;
			}
		}

	}

}
