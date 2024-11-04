

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.*;

public class Main
{
	static Scanner sc = new Scanner(System.in);
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static BufferedReader inl = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException
	{








		{
			int t = sc.nextInt();
			while (t-- > 0)
			{
				int n = sc.nextInt();
				String str = sc.next();
				int a = str.replace("1", "").length();
				if (a == 1)
					System.out.println("BOB");
				else if ((a & 1) == 1)
					System.out.println("ALICE");
				else
					System.out.println("BOB");
			}
		}
	}

	static int ini() throws IOException
	{
		in.nextToken();
		return (int) in.nval;
	}

	static double ind() throws IOException
	{
		in.nextToken();
		return in.nval;
	}

	static String ins() throws IOException
	{
		in.nextToken();
		return in.sval;
	}

}