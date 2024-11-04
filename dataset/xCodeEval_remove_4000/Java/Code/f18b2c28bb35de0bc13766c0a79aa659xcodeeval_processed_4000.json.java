
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class id11 {
	private static PrintWriter printWriter;

	public class id8<K,V>
	{
		private transient Entry<K,V> root = null;
		private transient int size = 0;
		private transient int modCount = 0;

		public id8() {
		}

		public int size() {
			return size;
		}

		public V get(Object key) {
			Entry<K,V> p = getEntry(key);
			return (p==null ? null : p.value);
		}

		public Entry<K,V> getEntry(Object key) {
			if (key == null)
				throw new NullPointerException();
			Comparable<? super K> k = (Comparable<? super K>) key;
			Entry<K,V> p = root;
			while (p != null) {
				int cmp = k.compareTo(p.key);
				if (cmp < 0)
					p = p.left;
				else if (cmp > 0)
					p = p.right;
				else
					return p;
			}
			return null;
		}

		public K id2(K key) {
			Entry<K,V> entry = id1(key);
			if(entry!=null) {
				return entry.key;
			}
			return null;
		}

		final Entry<K,V> id1(K key) {
			Entry<K,V> p = root;
			while (p != null) {
				int cmp = compare(key, p.key);
				if (cmp < 0) {
					if (p.left != null)
						p = p.left;
					else
						return p;
				} else if (cmp > 0) {
					if (p.right != null) {
						p = p.right;
					} else {
						Entry<K,V> parent = p.parent;
						Entry<K,V> ch = p;
						while (parent != null && ch == parent.right) {
							ch = parent;
							parent = parent.parent;
						}
						return parent;
					}
				} else
					return p;
			}
			return null;
		}

		public int getRank(K key) {
			Entry<K,V> entry = getEntry(key);
			int r = 0;
			if(leftOf(entry)!=null) {
				r += leftOf(entry).getSize();
			}
			Entry<K,V> y = entry ;
			while(compare(y.key, root.key) != 0) {
				if(rightOf(parentOf(y)) != null ) {
					if(compare(y.key,rightOf(parentOf(y)).key)== 0) {
						if(leftOf(parentOf(y)) != null ) {
							r = r + leftOf(parentOf(y)).getSize() + 1;
						} else {
							r++;
						}
					}
				}
				y = parentOf(y);
			}
			return r;
		}

		public Entry<K, V> id9(int i)
		{
			Entry<K, V> entry = root;

			while(true)
			{
				int ls = 0;
				
				if(leftOf(entry) != null)
				{
					ls = leftOf(entry).size;
				}
				
				if(ls < i)
				{
					i = i - ls - 1;
					entry = entry.right;
				}
				else if(ls > i)
				{
					entry = entry.left;
				}
				else if(ls == i)
				{
					break;
				}
			}

			return entry;
		}

		public V put(K key, V value) {
			Entry<K,V> t = root;
			if (t == null) {
				compare(key, key); 


				root = new Entry<K,V>(key, value, null);
				size = 1;
				root.setSize(1);
				modCount++;
				return null;
			}
			int cmp;
			Entry<K,V> parent;
			if (key == null)
				throw new NullPointerException();
			Comparable<? super K> k = (Comparable<? super K>) key;
			do {
				parent = t;
				parent.setSize(parent.getSize()+1);
				cmp = k.compareTo(t.key);
				if (cmp < 0)
					t = t.left;
				else if (cmp > 0)
					t = t.right;
				else
					return t.setValue(value);
			} while (t != null);

			Entry<K,V> e = new Entry<K,V>(key, value, parent);
			if (cmp < 0)
				parent.left = e;
			else
				parent.right = e;
			e.setSize(1);
			id10(e);
			size++;
			modCount++;
			return null;
		}

		public V remove(Object key) {
			Entry<K,V> p = getEntry(key);
			if (p == null)
				return null;

			V oldValue = p.value;
			deleteEntry(p);
			return oldValue;
		}

		class Values {     
			public int size() {
				return id8.this.size();
			}
			public boolean remove(Object o) {
				for (Entry<K,V> e = id7(); e != null; e = successor(e)) {
					if (valEquals(e.getValue(), o)) {
						deleteEntry(e);
						return true;
					}
				}
				return false;
			}
		}

		final int compare(Object k1, Object k2) {
			return  ((Comparable<? super K>)k1).compareTo((K)k2);
		}

		final boolean valEquals(Object o1, Object o2) {
			return (o1==null ? o2==null : o1.equals(o2));
		}

		private static final boolean RED   = false;
		private static final boolean BLACK = true;

		final class Entry<K,V>  {
			K key;
			V value;
			Entry<K,V> left = null;
			Entry<K,V> right = null;
			int size = 1;
			Entry<K,V> parent;
			boolean color = BLACK;

			Entry(K key, V value, Entry<K,V> parent) {
				this.key = key;
				this.value = value;
				this.parent = parent;
			}


			public int getSize() {
				return size;
			}


			public void setSize(int size) {
				this.size = size;
			}

			public K getKey() {
				return key;
			}

			public V getValue() {
				return value;
			}

			public V setValue(V value) {
				V oldValue = this.value;
				this.value = value;
				return oldValue;
			}

			public boolean equals(Object o) {
				if (!(o instanceof Entry))
					return false;
				Entry<?,?> e = (Entry<?,?>)o;

				return valEquals(key,e.getKey()) && valEquals(value,e.getValue());
			}

			public int hashCode() {
				int keyHash = (key==null ? 0 : key.hashCode());
				int valueHash = (value==null ? 0 : value.hashCode());
				return keyHash ^ valueHash;
			}

			public String toString() {
				return key + "=" + value;
			}
		}

		final Entry<K,V> id7() {
			Entry<K,V> p = root;
			if (p != null)
				while (p.left != null)
					p = p.left;
			return p;
		}

		final Entry<K,V> id3() {
			Entry<K,V> p = root;
			if (p != null)
				while (p.right != null)
					p = p.right;
			return p;
		}

		id8<K,V>.Entry<K,V> successor(Entry<K,V> t) {
			if (t == null)
				return null;
			else if (t.right != null) {
				Entry<K,V> p = t.right;
				while (p.left != null)
					p = p.left;
				return p;
			} else {
				Entry<K,V> p = t.parent;
				Entry<K,V> ch = t;
				while (p != null && ch == p.right) {
					ch = p;
					p = p.parent;
				}
				return p;
			}
		}

		<K,V> Entry<K,V> id5(Entry<K,V> t) {
			if (t == null)
				return null;
			else if (t.left != null) {
				Entry<K,V> p = t.left;
				while (p.right != null)
					p = p.right;
				return p;
			} else {
				Entry<K,V> p = t.parent;
				Entry<K,V> ch = t;
				while (p != null && ch == p.left) {
					ch = p;
					p = p.parent;
				}
				return p;
			}
		}

		private <K,V> boolean colorOf(Entry<K,V> p) {
			return (p == null ? BLACK : p.color);
		}

		private <K,V> Entry<K,V> parentOf(Entry<K,V> p) {
			return (p == null ? null: p.parent);
		}

		private <K,V> void setColor(Entry<K,V> p, boolean c) {
			if (p != null)
				p.color = c;
		}

		private <K,V> Entry<K,V> leftOf(Entry<K,V> p) {
			return (p == null) ? null: p.left;
		}

		private <K,V> Entry<K,V> rightOf(Entry<K,V> p) {
			return (p == null) ? null: p.right;
		}

		
		private void rotateLeft(Entry<K,V> p) {
			if (p != null) {
				Entry<K,V> r = p.right;
				p.right = r.left;
				if (r.left != null)
					r.left.parent = p;
				r.parent = p.parent;
				if (p.parent == null)
					root = r;
				else if (p.parent.left == p)
					p.parent.left = r;
				else
					p.parent.right = r;
				r.left = p;
				p.parent = r;
				p.setSize(1);
				r.setSize(1);
				if(p.left!=null) {
					p.setSize(p.left.getSize()+p.getSize());
				}
				if(p.right!=null) {
					p.setSize(p.right.getSize()+p.getSize());
				}
				if(r.left!=null) {
					r.setSize(r.left.getSize()+r.getSize());
				}
				if(r.right!=null) {
					r.setSize(r.right.getSize()+r.getSize());
				}
			}
		}

		
		private void rotateRight(Entry<K,V> p) {
			if (p != null) {
				Entry<K,V> l = p.left;
				p.left = l.right;
				if (l.right != null) l.right.parent = p;
				l.parent = p.parent;
				if (p.parent == null)
					root = l;
				else if (p.parent.right == p)
					p.parent.right = l;
				else p.parent.left = l;
				l.right = p;
				p.parent = l;
				p.setSize(1);
				l.setSize(1);
				if(p.left!=null) {
					p.setSize(p.left.getSize()+p.getSize());
				}
				if(p.right!=null) {
					p.setSize(p.right.getSize()+p.getSize());
				}
				if(l.left!=null) {
					l.setSize(l.left.getSize()+l.getSize());
				}
				if(l.right!=null) {
					l.setSize(l.right.getSize()+l.getSize());
				}
			}
		}

		
		private void id10(Entry<K,V> x) {
			x.color = RED;

			while (x != null && x != root && x.parent.color == RED) {
				if (parentOf(x) == leftOf(parentOf(parentOf(x)))) {
					Entry<K,V> y = rightOf(parentOf(parentOf(x)));
					if (colorOf(y) == RED) {
						setColor(parentOf(x), BLACK);
						setColor(y, BLACK);
						setColor(parentOf(parentOf(x)), RED);
						x = parentOf(parentOf(x));
					} else {
						if (x == rightOf(parentOf(x))) {
							x = parentOf(x);
							rotateLeft(x);
						}
						setColor(parentOf(x), BLACK);
						setColor(parentOf(parentOf(x)), RED);
						rotateRight(parentOf(parentOf(x)));
					}
				} else {
					Entry<K,V> y = leftOf(parentOf(parentOf(x)));
					if (colorOf(y) == RED) {
						setColor(parentOf(x), BLACK);
						setColor(y, BLACK);
						setColor(parentOf(parentOf(x)), RED);
						x = parentOf(parentOf(x));
					} else {
						if (x == leftOf(parentOf(x))) {
							x = parentOf(x);
							rotateRight(x);
						}
						setColor(parentOf(x), BLACK);
						setColor(parentOf(parentOf(x)), RED);
						rotateLeft(parentOf(parentOf(x)));
					}
				}
			}
			root.color = BLACK;
		}

		
		private void deleteEntry(Entry<K,V> p) {
			modCount++;
			size--;

			

			

			if (p.left != null && p.right != null) {
				Entry<K,V> s = successor(p);
				p.key = s.key;
				p.value = s.value;
				p = s;
			} 


			Entry<K,V> copy = p;
			while(copy!=null) {
				copy.setSize(copy.getSize()-1);
				copy = parentOf(copy);
			}
			

			Entry<K,V> replacement = (p.left != null ? p.left : p.right);

			if (replacement != null) {
				

				replacement.parent = p.parent;
				if (p.parent == null)
					root = replacement;
				else if (p == p.parent.left)
					p.parent.left  = replacement;
				else
					p.parent.right = replacement;

				

				p.left = p.right = p.parent = null;

				

				if (p.color == BLACK)
					id0(replacement);
			} else if (p.parent == null) { 

				root = null;
			} else { 

				if (p.color == BLACK)
					id0(p);

				if (p.parent != null) {
					if (p == p.parent.left)
						p.parent.left = null;
					else if (p == p.parent.right)
						p.parent.right = null;
					p.parent = null;
				}
			}
		}

		
		private void id0(Entry<K,V> x) {
			while (x != root && colorOf(x) == BLACK) {
				if (x == leftOf(parentOf(x))) {
					Entry<K,V> sib = rightOf(parentOf(x));

					if (colorOf(sib) == RED) {
						setColor(sib, BLACK);
						setColor(parentOf(x), RED);
						rotateLeft(parentOf(x));
						sib = rightOf(parentOf(x));
					}

					if (colorOf(leftOf(sib))  == BLACK &&
							colorOf(rightOf(sib)) == BLACK) {
						setColor(sib, RED);
						x = parentOf(x);
					} else {
						if (colorOf(rightOf(sib)) == BLACK) {
							setColor(leftOf(sib), BLACK);
							setColor(sib, RED);
							rotateRight(sib);
							sib = rightOf(parentOf(x));
						}
						setColor(sib, colorOf(parentOf(x)));
						setColor(parentOf(x), BLACK);
						setColor(rightOf(sib), BLACK);
						rotateLeft(parentOf(x));
						x = root;
					}
				} else { 

					Entry<K,V> sib = leftOf(parentOf(x));

					if (colorOf(sib) == RED) {
						setColor(sib, BLACK);
						setColor(parentOf(x), RED);
						rotateRight(parentOf(x));
						sib = leftOf(parentOf(x));
					}

					if (colorOf(rightOf(sib)) == BLACK &&
							colorOf(leftOf(sib)) == BLACK) {
						setColor(sib, RED);
						x = parentOf(x);
					} else {
						if (colorOf(leftOf(sib)) == BLACK) {
							setColor(rightOf(sib), BLACK);
							setColor(sib, RED);
							rotateLeft(sib);
							sib = leftOf(parentOf(x));
						}
						setColor(sib, colorOf(parentOf(x)));
						setColor(parentOf(x), BLACK);
						setColor(leftOf(sib), BLACK);
						rotateRight(parentOf(x));
						x = root;
					}
				}
			}

			setColor(x, BLACK);
		}

	}

	public void solve() throws FileNotFoundException {
		InputStream inputStream = System.in;

		InputHelper inputHelper = new InputHelper(inputStream);

		PrintStream out = System.out;

		

		int n = inputHelper.readInteger();

		int[] p = new int[n];
		int[] q = new int[n];

		for(int i = 0; i < n; i++)
		{
			p[i] = inputHelper.readInteger();
		}

		for(int i = 0; i < n; i++)
		{
			q[i] = inputHelper.readInteger();
		}

		int[] fp = new int[n];
		int[] fq = new int[n];

		int[] ft = new int[n];

		id8<Integer, Integer> tsp = new id8<Integer, Integer>();
		id8<Integer, Integer> tsq = new id8<Integer, Integer>();

		for(int i = 0; i < n; i++)
		{
			tsp.put(i, 1);
			tsq.put(i, 1);
		}

		for(int i = 0 ; i < n; i++)
		{
			if(tsp.id7().key != p[i])
			{
				int e = tsp.getRank(p[i]);
				fp[tsp.size() - 1] = e;
			}
			tsp.remove(p[i]);
			if(tsq.id7().key != q[i])
			{
				int e = tsq.getRank(q[i]);
				fq[tsq.size() - 1] = e;
			}
			tsq.remove(q[i]);
		}

		for(int i = 0; i < n; i++)
		{
			ft[i] += fp[i] + fq[i];
			if(ft[i] >= i + 1)
			{
				ft[i] -= (i + 1);
				if(i < n - 1)
				{
					ft[i + 1] += 1;
				}
			}
		}

		
		

		int[] sp = new int[n];

		

		id8<Integer, Integer> tst = new id8<Integer, Integer>();

		for(int i = 0; i < n; i++)
		{
			tst.put(i, 1);
		}

		for(int i = 0; i < n; i++)
		{
			sp[i] = tst.id9(ft[n - 1 - i]).key;
			tst.remove(sp[i]);
		}
		
		for(int i = 0; i < n; i++)
		{
			System.out.print(sp[i] + " ");
		}
		System.out.println();
		


		

	}

	public static void main(String[] args) throws FileNotFoundException {
		(new id11()).solve();
	}

	class InputHelper {
		StringTokenizer tokenizer = null;
		private BufferedReader id6;

		public InputHelper(InputStream inputStream) {
			InputStreamReader id4 = new InputStreamReader(
					inputStream);
			id6 = new BufferedReader(id4, 16384);
		}

		public String read() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String line = id6.readLine();
					if (line == null) {
						return null;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			return tokenizer.nextToken();
		}

		public Integer readInteger() {
			return Integer.parseInt(read());
		}

		public Long readLong() {
			return Long.parseLong(read());
		}
	}
}