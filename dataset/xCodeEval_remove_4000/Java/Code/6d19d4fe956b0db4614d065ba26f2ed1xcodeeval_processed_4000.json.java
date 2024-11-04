import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;



class element implements Comparable<element>
{
	int x;
	int f;
	int r;
	int toe;

	public element(int x, int f, int r, int toe)
	{
		super();
		this.x = x;
		this.f = f;
		this.r = r;
		this.toe = toe;
	}

	@Override
	public int compareTo(element o)
	{
		if (this.x == o.x)
		{
			return this.toe - o.toe;
		}
		return this.x - o.x;
	}
}

public class id2
{
	static class id1<T extends Comparable<T>>
	{
		static class Node<T extends Comparable<T>>
		{
			Node<T> left, right;
			T value;
			int id7;
			int height;
		}

		static class id17<T extends Comparable<T>>
		{

			public static <T extends Comparable<T>> void printNode(Node<T> root)
			{
				int maxLevel = id17.maxLevel(root);

				id12(Collections.singletonList(root), 1, maxLevel);
			}

			private static <T extends Comparable<T>> void id12(
					List<Node<T>> roots, int level, int maxLevel)
			{
				if (roots.isEmpty() || id17.id20(roots))
					return;

				int floor = maxLevel - level;
				int id6 = (int) Math.pow(2, (Math.max(floor - 1, 0)));
				int firstSpaces = (int) Math.pow(2, (floor)) - 1;
				int betweenSpaces = (int) Math.pow(2, (floor + 1)) - 1;

				id17.id22(firstSpaces);

				List<Node<T>> newNodes = new ArrayList<Node<T>>();
				for (Node<T> root : roots)
				{
					if (root != null)
					{
						System.out.print(root.value);
						newNodes.add(root.left);
						newNodes.add(root.right);
					}
					else
					{
						newNodes.add(null);
						newNodes.add(null);
						System.out.print(" ");
					}

					id17.id22(betweenSpaces);
				}
				System.out.println("");

				for (int i = 1; i <= id6; i++)
				{
					for (int j = 0; j < roots.size(); j++)
					{
						id17.id22(firstSpaces - i);
						if (roots.get(j) == null)
						{
							id17.id22(id6
									+ id6 + i + 1);
							continue;
						}

						if (roots.get(j).left != null)
							System.out.print("/");
						else
							id17.id22(1);

						id17.id22(i + i - 1);

						if (roots.get(j).right != null)
							System.out.print("\\");
						else
							id17.id22(1);

						id17.id22(id6 + id6
								- i);
					}

					System.out.println("");
				}

				id12(newNodes, level + 1, maxLevel);
			}

			private static void id22(int count)
			{
				for (int i = 0; i < count; i++)
					System.out.print(" ");
			}

			private static <T extends Comparable<T>> int maxLevel(Node<T> root)
			{
				if (root == null)
					return 0;

				return Math.max(id17.maxLevel(root.left),
						id17.maxLevel(root.right)) + 1;
			}

			private static <T> boolean id20(List<T> list)
			{
				for (Object object : list)
				{
					if (object != null)
						return false;
				}

				return true;
			}

		}

		private Node<T> root;

		public id1()
		{
			root = null;
		}

		public Integer id9(T value)
		{
			return id10(root, value);
		}

		public Integer id10(Node<T> root, T value)
		{
			if (root == null)
				return -1;

			if (value.equals(root.value))
			{
				return root.id7;
			}
			else if (root.value.compareTo(value) > 0)
			{
				return id10(root.left, value);
			}
			else if (root.value.compareTo(value) < 0)
			{
				int ind = id10(root.right, value);

				if (ind != -1)
					return root.id7 + 1 + ind;
				else
					return -1;
			}

			return -1;
		}

		public Node<T> search(T value)
		{
			return searchHelper(root, value);
		}

		public Node<T> searchHelper(Node<T> root, T value)
		{
			if (root == null)
				return null;

			if (value.equals(root.value))
			{
				return root;
			}
			else if (root.value.compareTo(value) > 0)
			{
				return searchHelper(root.left, value);
			}
			else if (root.value.compareTo(value) < 0)
			{
				return searchHelper(root.right, value);
			}

			

			return null;
		}

		public Node<T> insert(T value)
		{
			return root = insertHelper(root, value);
		}

		

		int height(Node<T> N)
		{
			if (N == null)
				return 0;

			return N.height;
		}

		

		int max(int a, int b)
		{
			return (a > b) ? a : b;
		}

		

		

		Node<T> rightRotate(Node<T> y)
		{
			Node<T> x = y.left;
			Node<T> T2 = x.right;

			

			x.right = y;
			y.left = T2;

			

			y.height = max(height(y.left), height(y.right)) + 1;
			x.height = max(height(x.left), height(x.right)) + 1;

			y.id7 -= (x.id7 + 1);

			

			return x;
		}

		

		

		Node<T> leftRotate(Node<T> x)
		{
			Node<T> y = x.right;
			Node<T> T2 = y.left;

			

			y.left = x;
			x.right = T2;

			

			x.height = max(height(x.left), height(x.right)) + 1;
			y.height = max(height(y.left), height(y.right)) + 1;

			y.id7 += (x.id7 + 1);
			

			return y;
		}

		

		int getBalance(Node<T> N)
		{
			if (N == null)
				return 0;

			return height(N.left) - height(N.right);
		}

		public Node<T> insertHelper(Node<T> root, T value)
		{
			if (root == null)
			{
				Node<T> nn = new Node<T>();
				nn.value = value;
				nn.id7 = 0;
				nn.height = 1;

				return nn;
			}

			else if (root.value.compareTo(value) > 0)
			{
				root.left = insertHelper(root.left, value);
				root.id7++;
			}
			else if (root.value.compareTo(value) < 0)
			{
				root.right = insertHelper(root.right, value);
			}
			else
				

				return root;

			root.height = 1 + max(height(root.left), height(root.right));

			
			int balance = getBalance(root);

			

			

			if (balance > 1 && root.left.value.compareTo(value) > 0)
				return rightRotate(root);

			

			if (balance < -1 && root.right.value.compareTo(value) < 0)
				return leftRotate(root);

			

			if (balance > 1 && root.left.value.compareTo(value) < 0)
			{
				root.left = leftRotate(root.left);
				return rightRotate(root);
			}

			

			if (balance < -1 && root.right.value.compareTo(value) > 0)
			{
				root.right = rightRotate(root.right);
				return leftRotate(root);
			}

			return root;
		}

		public void delete(T value)
		{
			root = deleteHelper(root, value);
		}

		private Node<T> id3(Node<T> root)
		{
			Node<T> current = root;

			while (current.left != null)
			{
				current = current.left;
			}

			return current;
		}

		private Node<T> deleteHelper(Node<T> root, T value)
		{
			

			if (root == null)
				return null;

			if (value.equals(root.value))
			{
				if (root.left == null && root.right == null)
				{
					return null;
				}
				else if (root.left != null && root.right == null)
				{
					return root.left;
				}
				else if (root.left == null && root.right != null)
				{
					return root.right;
				}
				else
				{
					Node<T> temp = id3(root.right);

					root.value = temp.value;

					root.right = deleteHelper(root.right, temp.value);
				}
			}
			else if (root.value.compareTo(value) > 0)
			{
				root.left = deleteHelper(root.left, value);
				root.id7--;
			}
			else if (root.value.compareTo(value) < 0)
			{
				root.right = deleteHelper(root.right, value);
			}

			root.height = 1 + max(height(root.left), height(root.right));

			
			int balance = getBalance(root);

			if (balance > 1 && getBalance(root.left) >= 0)
				return rightRotate(root);

			

			if (balance > 1 && getBalance(root.left) < 0)
			{
				root.left = leftRotate(root.left);
				return rightRotate(root);
			}

			

			if (balance < -1 && getBalance(root.right) <= 0)
				return leftRotate(root);

			

			if (balance < -1 && getBalance(root.right) > 0)
			{
				root.right = rightRotate(root.right);
				return leftRotate(root);
			}

			return root;
		}

		public T id4(int n)
		{
			return id8(root, n);
		}

		public T id8(Node<T> root, int n)
		{
			if (root == null)
			{
				return null;
			}

			if (root.id7 + 1 == n)
			{
				return root.value;
			}
			else if (root.id7 + 1 < n)
			{
				return id8(root.right, n - root.id7
						- 1);
			}
			else
			{
				return id8(root.left, n);
			}
		}

		public int id13(T n, int def)
		{
			return id14(root, n, def);
		}

		public int id14(Node<T> root, T value,
				int def)
		{
			if (root == null)
			{
				return def;
			}

			if (root.value.equals(value))
			{
				return root.id7;
			}

			if (root.value.compareTo(value) < 0)
			{
				int ceil = id14(root.right, value,
						def);

				if (ceil != def)
				{
					return root.id7 + 1 + ceil;
				}
				else
				{
					return def;
				}
			}
			else
			{
				int ceil = id14(root.left, value,
						def);

				if (ceil != def)
				{
					return ceil;
				}
				else
				{
					return root.id7;
				}
			}
		}

		public T id5(T n)
		{
			return id0(root, n);
		}

		private T id0(Node<T> root, T value)
		{
			if (root == null)
			{
				return null;
			}

			if (root.value.equals(value))
			{
				return root.value;
			}

			if (root.value.compareTo(value) < 0)
			{
				return id0(root.right, value);
			}
			else
			{
				T ceil = id0(root.left, value);

				if (ceil != null && ceil.compareTo(value) >= 0)
				{
					return ceil;
				}
				else
				{
					return root.value;
				}
			}
		}

		public Integer id11(T value)
		{
			return id16(root, value);
		}

		public Integer id16(Node<T> root, T value)
		{
			if (root == null)
			{
				return -1;
			}

			if (root.value.equals(value))
			{
				return root.id7;
			}

			if (root.value.compareTo(value) > 0)
			{
				return id16(root.left, value);
			}
			else
			{
				int floor = id16(root.right, value);
				if (floor != -1)
				{
					return root.id7 + 1 + floor;
				}
				else
				{
					return root.id7;
				}
			}
		}

		public T id19(T value)
		{
			return id21(root, value);
		}

		private T id21(Node<T> root, T value)
		{
			if (root == null)
			{
				return null;
			}

			if (root.value.equals(value))
			{
				return root.value;
			}

			if (root.value.compareTo(value) > 0)
			{
				return id21(root.left, value);
			}
			else
			{
				T floor = id21(root.right, value);
				if (floor != null && floor.compareTo(root.value) <= 0)
				{
					return floor;
				}
				else
				{
					return root.value;
				}
			}
		}

		int size()
		{
			return sizeHelper(root);
		}

		int sizeHelper(Node<T> root)
		{
			if (root == null)
				return 0;

			return root.id7 + 1 + sizeHelper(root.right);
		}

		void print()
		{
			id17.printNode(root);
		}
	}

	public void solve() throws FileNotFoundException
	{
		InputStream inputStream = System.in;

		InputHelper inputHelper = new InputHelper(inputStream);

		PrintStream out = System.out;

		


		int n = inputHelper.readInteger();
		int k = inputHelper.readInteger();

		id1<Integer>[] fbt = new id1[10001];

		ArrayList<element> al = new ArrayList<element>();
		for (int i = 0; i < 10001; i++)
		{
			fbt[i] = new id1<Integer>();
		}

		for (int i = 0; i < n; i++)
		{
			int x = inputHelper.readInteger();
			int r = inputHelper.readInteger();
			int f = inputHelper.readInteger();

			al.add(new element(x, f, r, 0));
			al.add(new element(x - r, f, r, 1));
			al.add(new element(x + r, f, r, 2));
		}

		Collections.sort(al);

		long ans = 0;
		for (int i = 0; i < al.size(); i++)
		{
			element e = al.get(i);
			int f;
			switch (e.toe)
			{
			case 0:
				f = e.f;
				for (int j = Math.max(1, f - k); j <= Math.min(10000, f + k); j++)
				{
					id1<Integer> ost = fbt[j];

					int s = ost.size();
					ans += Math.max(0, ost.id11(e.x - 1)
							- ost.id13(e.x - e.r, s) + 1);
				}
				break;

			case 1:
				f = e.f;
				fbt[f].insert(e.x + e.r);
				break;

			case 2:
				f = e.f;
				fbt[f].delete(e.x - e.r);
				break;
			}
		}

		System.out.println(ans);
		

	}

	public static void main(String[] args) throws FileNotFoundException
	{
		(new id2()).solve();
	}

	class InputHelper
	{
		StringTokenizer tokenizer = null;
		private BufferedReader id18;

		public InputHelper(InputStream inputStream)
		{
			InputStreamReader id15 = new InputStreamReader(
					inputStream);
			id18 = new BufferedReader(id15, 16384);
		}

		public String read()
		{
			while (tokenizer == null || !tokenizer.hasMoreTokens())
			{
				try
				{
					String line = id18.readLine();
					if (line == null)
					{
						return null;
					}
					tokenizer = new StringTokenizer(line);
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}

			return tokenizer.nextToken();
		}

		public Integer readInteger()
		{
			return Integer.parseInt(read());
		}

		public Long readLong()
		{
			return Long.parseLong(read());
		}
	}
}