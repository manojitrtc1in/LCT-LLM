
import java.io.*;
import java.util.*;

public class B extends PrintWriter {

	long point(long x, long y) {
		return (x << 32) | (y);
	}

	boolean isStabel(int x, int y, EzLongIntTreeMap p, int rx, int ry) {
		if (y == 0 || !p.containsKey(point(x, y))) {
			return true;
		}
		for (int dy = -1, dx = -1; dx <= 1; dx++) {
			if (x + dx == rx && y + dy == ry) {
				continue;
			}
			if (p.containsKey(point(x + dx, y + dy))) {
				return true;
			}
		}
		return false;
	}

	boolean isOpen(int x, int y, EzLongIntTreeMap p) {
		for (int dy = 1, dx = -1; dx <= 1; dx++) {
			if (!isStabel(x + dx, y + dy, p, x, y)) {
				return false;
			}
		}
		return true;
	}

	void run() {
		int n = nextInt();
		long mod = 1000000009;
		int[] x = new int[n], y = new int[n];
        EzLongIntTreeMap p = new EzLongIntTreeMap();

		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();

			p.put(point(x[i], y[i]), i);
		}

		EzIntTreeSet open = new EzIntTreeSet();

		for (int i = 0; i < n; i++) {
			if (isOpen(x[i], y[i], p)) {
				open.add(i);
			}
		}

		long[] num = new long[n];
		boolean f = true;

		for (int i = 0; i < n; i++) {

			int j = f ? open.getLast() : open.getFirst();
			open.remove(j);
			num[i] = j;

			p.remove(point(x[j], y[j]));

			for (int dy = -1; dy <= 0; dy++) {
				for (int dx = -2; dx <= 2; dx++) {
					if (isOpen(x[j] + dx, y[j] + dy, p)) {
						int k = p.get(point(x[j] + dx, y[j] + dy));
						if (!p.returnedNull()) {
							open.add(k);
						}
					} else {
                        int k = p.get(point(x[j] + dx, y[j] + dy));
						if (!p.returnedNull()) {
							open.remove(k);
						}
					}
				}
			}

			f = !f;

		}

		long ans = 0, pow = 1;

		for (int i = n - 1; i >= 0; i--) {
			ans = (ans + ((num[i] * pow) % mod)) % mod;
			pow = (pow * n) % mod;
		}
		

		println(ans);

	}

	void skip() {
		while (hasNext()) {
			next();
		}
	}

	int[][] nextMatrix(int n, int m) {
		int[][] matrix = new int[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] = nextInt();
		return matrix;
	}

	String next() {
		while (!tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(nextLine());
		return tokenizer.nextToken();
	}

	boolean hasNext() {
		while (!tokenizer.hasMoreTokens()) {
			String line = nextLine();
			if (line == null) {
				return false;
			}
			tokenizer = new StringTokenizer(line);
		}
		return true;
	}

	int[] nextArray(int n) {
		int[] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = nextInt();
		}
		return array;
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

	String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException err) {
			return null;
		}
	}

	public B(OutputStream outputStream) {
		super(outputStream);
	}

	static BufferedReader reader;
	static StringTokenizer tokenizer = new StringTokenizer("");
	static Random rnd = new Random();
	static boolean OJ;

	public static void main(String[] args) throws IOException {
		OJ = System.getProperty("ONLINE_JUDGE") != null;
		B solution = new B(System.out);
		if (OJ) {
			reader = new BufferedReader(new InputStreamReader(System.in));
			solution.run();
		} else {
			reader = new BufferedReader(new FileReader(new File(B.class.getName() + ".txt")));
			long timeout = System.currentTimeMillis();
			while (solution.hasNext()) {
				solution.run();
				solution.println();
				solution.println("----------------------------------");
			}
			solution.println("time: " + (System.currentTimeMillis() - timeout));
		}
		solution.close();
		reader.close();
	}
}




class EzIntTreeSet {
    private static final int DEFAULT_CAPACITY = 10;
    private static final double ENLARGE_SCALE = 2.0;

    private static final boolean BLACK = false;
    private static final boolean RED = true;
    private static final int NULL = 0;
    private static final int DEFAULT_NULL_ELEMENT = (new int[1])[0];

    

    private int[] key;
    private int[] left;
    private int[] right;
    private int[] p;
    private boolean[] color;

    private int size;
    private int root;
    private boolean returnedNull;

    public EzIntTreeSet() {
        this(DEFAULT_CAPACITY);
    }

    public EzIntTreeSet(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity must be non-negative");
        }
        capacity++;
        key = new int[capacity];
        left = new int[capacity];
        right = new int[capacity];
        p = new int[capacity];
        color = new boolean[capacity];
        color[NULL] = BLACK;
        size = 0;
        root = NULL;
        returnedNull = false;
    }

    public EzIntTreeSet(int[] srcArray) {
        this(srcArray.length);
        for (int element : srcArray) {
            add(element);
        }
    }

    public EzIntTreeSet(Collection<Integer> javaCollection) {
        this(javaCollection.size());
        for (int element : javaCollection) {
            add(element);
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean contains(int element) {
        int x = root;
        while (x != NULL) {
            if (element < key[x]) {
                x = left[x];
            } else if (element > key[x]) {
                x = right[x];
            } else {
                return true;
            }
        }
        return false;
    }

    public int[] toArray() {
        int[] result = new int[size];
        for (int i = 0, x = firstNode(); x != NULL; x = successorNode(x), i++) {
            result[i] = key[x];
        }
        return result;
    }

    public boolean add(int element) {
        int y = NULL;
        int x = root;
        while (x != NULL) {
            

            y = x;
            if (element < key[x]) {
                x = left[x];
            } else if (element > key[x]) {
                x = right[x];
            } else {
                return false;
            }
        }
        if (size == color.length - 1) {
            enlarge();
        }
        int z = ++size;
        key[z] = element;
        p[z] = y;
        if (y == NULL) {
            root = z;
        } else {
            if (element < key[y]) {
                left[y] = z;
            } else {
                right[y] = z;
            }
        }
        left[z] = NULL;
        right[z] = NULL;
        color[z] = RED;
        fixAfterAdd(z);
        return true;
    }

    public boolean remove(int element) {
        int z = root;
        while (z != NULL) {
            if (element < key[z]) {
                z = left[z];
            } else if (element > key[z]) {
                z = right[z];
            } else {
                removeNode(z);
                return true;
            }
        }
        return false;
    }

    private void removeNode(int z) {
        int y = (left[z] == NULL || right[z] == NULL) ? z : successorNode(z);
        int x = (left[y] != NULL) ? left[y] : right[y];
        p[x] = p[y];
        if (p[y] == NULL) {
            root = x;
        } else {
            if (y == left[p[y]]) {
                left[p[y]] = x;
            } else {
                right[p[y]] = x;
            }
        }
        if (y != z) {
            key[z] = key[y];
        }
        

        if (color[y] == BLACK) {
            fixAfterRemove(x);
        }
        

        if (y != size) {
            

            key[y] = key[size];
            left[y] = left[size];
            right[y] = right[size];
            p[y] = p[size];
            color[y] = color[size];
            

            p[left[size]] = y;
            p[right[size]] = y;
            

            if (left[p[size]] == size) {
                left[p[size]] = y;
            } else {
                right[p[size]] = y;
            }
            

            if (root == size) {
                root = y;
            }
        }
        size--;
    }

    private int successorNode(int x) {
        if (right[x] != NULL) {
            x = right[x];
            while (left[x] != NULL) {
                x = left[x];
            }
            return x;
        } else {
            int y = p[x];
            while (y != NULL && x == right[y]) {
                

                x = y;
                y = p[y];
            }
            return y;
        }
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void fixAfterAdd(int z) {
        while (color[p[z]] == RED) {
            if (p[z] == left[p[p[z]]]) {
                int y = right[p[p[z]]];
                if (color[y] == RED) {
                    color[p[z]] = BLACK;
                    color[y] = BLACK;
                    color[p[p[z]]] = RED;
                    z = p[p[z]];
                } else {
                    if (z == right[p[z]]) {
                        z = p[z];
                        rotateLeft(z);
                    }
                    color[p[z]] = BLACK;
                    color[p[p[z]]] = RED;
                    rotateRight(p[p[z]]);
                }
            } else {
                int y = left[p[p[z]]];
                if (color[y] == RED) {
                    color[p[z]] = BLACK;
                    color[y] = BLACK;
                    color[p[p[z]]] = RED;
                    z = p[p[z]];
                } else {
                    if (z == left[p[z]]) {
                        z = p[z];
                        rotateRight(z);
                    }
                    color[p[z]] = BLACK;
                    color[p[p[z]]] = RED;
                    rotateLeft(p[p[z]]);
                }
            }
        }
        color[root] = BLACK;
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void fixAfterRemove(int x) {
        while (x != root && color[x] == BLACK) {
            if (x == left[p[x]]) {
                int w = right[p[x]];
                if (color[w] == RED) {
                    color[w] = BLACK;
                    color[p[x]] = RED;
                    rotateLeft(p[x]);
                    w = right[p[x]];
                }
                if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                    color[w] = RED;
                    x = p[x];
                } else {
                    if (color[right[w]] == BLACK) {
                        color[left[w]] = BLACK;
                        color[w] = RED;
                        rotateRight(w);
                        w = right[p[x]];
                    }
                    color[w] = color[p[x]];
                    color[p[x]] = BLACK;
                    color[right[w]] = BLACK;
                    rotateLeft(p[x]);
                    x = root;
                }
            } else {
                int w = left[p[x]];
                if (color[w] == RED) {
                    color[w] = BLACK;
                    color[p[x]] = RED;
                    rotateRight(p[x]);
                    w = left[p[x]];
                }
                if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                    color[w] = RED;
                    x = p[x];
                } else {
                    if (color[left[w]] == BLACK) {
                        color[right[w]] = BLACK;
                        color[w] = RED;
                        rotateLeft(w);
                        w = left[p[x]];
                    }
                    color[w] = color[p[x]];
                    color[p[x]] = BLACK;
                    color[left[w]] = BLACK;
                    rotateRight(p[x]);
                    x = root;
                }
            }
        }
        color[x] = BLACK;
    }

    private void rotateLeft(int x) {
        int y = right[x];
        right[x] = left[y];
        if (left[y] != NULL) {
            p[left[y]] = x;
        }
        p[y] = p[x];
        if (p[x] == NULL) {
            root = y;
        } else {
            if (x == left[p[x]]) {
                left[p[x]] = y;
            } else {
                right[p[x]] = y;
            }
        }
        left[y] = x;
        p[x] = y;
    }

    private void rotateRight(int x) {
        int y = left[x];
        left[x] = right[y];
        if (right[y] != NULL) {
            p[right[y]] = x;
        }
        p[y] = p[x];
        if (p[x] == NULL) {
            root = y;
        } else {
            if (x == right[p[x]]) {
                right[p[x]] = y;
            } else {
                left[p[x]] = y;
            }
        }
        right[y] = x;
        p[x] = y;
    }

    public void clear() {
        color[NULL] = BLACK;
        size = 0;
        root = NULL;
    }

    private void enlarge() {
        int newLength = Math.max(color.length + 1, (int) (color.length * ENLARGE_SCALE));
        key = Arrays.copyOf(key, newLength);
        left = Arrays.copyOf(left, newLength);
        right = Arrays.copyOf(right, newLength);
        p = Arrays.copyOf(p, newLength);
        color = Arrays.copyOf(color, newLength);
    }

    private int firstNode() {
        int x = root;
        while (left[x] != NULL) {
            x = left[x];
        }
        return x;
    }

    private int lastNode() {
        int x = root;
        while (right[x] != NULL) {
            x = right[x];
        }
        return x;
    }

    public int getFirst() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_ELEMENT;
        }
        final int x = firstNode();
        returnedNull = false;
        return key[x];
    }

    public int getLast() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_ELEMENT;
        }
        final int x = lastNode();
        returnedNull = false;
        return key[x];
    }

    public int removeFirst() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_ELEMENT;
        }
        final int x = firstNode();
        returnedNull = false;
        final int removedElement = key[x];
        removeNode(x);
        return removedElement;
    }

    public int removeLast() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_ELEMENT;
        }
        final int x = lastNode();
        returnedNull = false;
        final int removedElement = key[x];
        removeNode(x);
        return removedElement;
    }

    public int floor(int element) {
        int x = root;
        while (x != NULL) {
            if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    returnedNull = false;
                    return key[x];
                }
            } else if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_ELEMENT;
                    } else {
                        returnedNull = false;
                        return key[y];
                    }
                }
            } else {
                returnedNull = false;
                return key[x];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_ELEMENT;
    }

    public int ceiling(int element) {
        int x = root;
        while (x != NULL) {
            if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    returnedNull = false;
                    return key[x];
                }
            } else if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == right[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_ELEMENT;
                    } else {
                        returnedNull = false;
                        return key[y];
                    }
                }
            } else {
                returnedNull = false;
                return key[x];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_ELEMENT;
    }

    public int lower(int element) {
        int x = root;
        while (x != NULL) {
            if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    returnedNull = false;
                    return key[x];
                }
            } else {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_ELEMENT;
                    } else {
                        returnedNull = false;
                        return key[y];
                    }
                }
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_ELEMENT;
    }

    public int higher(int element) {
        int x = root;
        while (x != NULL) {
            if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    returnedNull = false;
                    return key[x];
                }
            } else {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == right[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_ELEMENT;
                    } else {
                        returnedNull = false;
                        return key[y];
                    }
                }
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_ELEMENT;
    }

    public boolean returnedNull() {
        return returnedNull;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        EzIntTreeSet that = (EzIntTreeSet) o;

        if (size != that.size) {
            return false;
        }
        for (int x = firstNode(), y = that.firstNode();
             x != NULL;
            

             x = successorNode(x), y = that.successorNode(y)
                ) {
            if (key[x] != that.key[y]) {
                return false;
            }
        }
        return true;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int x = firstNode(); x != NULL; x = successorNode(x)) {
            if (sb.length() > 1) {
                sb.append(", ");
            }
            sb.append(key[x]);
        }
        sb.append(']');
        return sb.toString();
    }
}


class EzLongIntTreeMap {
    private static final int DEFAULT_CAPACITY = 10;
    private static final double ENLARGE_SCALE = 2.0;

    private static final boolean BLACK = false;
    private static final boolean RED = true;
    private static final int NULL = 0;
    private static final long DEFAULT_NULL_KEY = (new long[1])[0];
    private static final int DEFAULT_NULL_VALUE = (new int[1])[0];

    

    private long[] keys;
    private int[] values;
    private int[] left;
    private int[] right;
    private int[] p;
    private boolean[] color;

    private int size;
    private int root;
    private boolean returnedNull;

    public EzLongIntTreeMap() {
        this(DEFAULT_CAPACITY);
    }

    public EzLongIntTreeMap(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity must be non-negative");
        }
        capacity++;
        keys = new long[capacity];
        values = new int[capacity];
        left = new int[capacity];
        right = new int[capacity];
        p = new int[capacity];
        color = new boolean[capacity];
        color[NULL] = BLACK;
        size = 0;
        root = NULL;
        returnedNull = false;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean containsKey(long key) {
        int x = root;
        while (x != NULL) {
            if (key < keys[x]) {
                x = left[x];
            } else if (key > keys[x]) {
                x = right[x];
            } else {
                return true;
            }
        }
        return false;
    }

    public int get(long key) {
        int x = root;
        while (x != NULL) {
            if (key < keys[x]) {
                x = left[x];
            } else if (key > keys[x]) {
                x = right[x];
            } else {
                returnedNull = false;
                return values[x];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    public int put(long key, int value) {
        int y = NULL;
        int x = root;
        while (x != NULL) {
            

            y = x;
            if (key < keys[x]) {
                x = left[x];
            } else if (key > keys[x]) {
                x = right[x];
            } else {
                final int oldValue = values[x];
                values[x] = value;
                returnedNull = false;
                return oldValue;
            }
        }
        if (size == color.length - 1) {
            enlarge();
        }
        int z = ++size;
        keys[z] = key;
        values[z] = value;
        p[z] = y;
        if (y == NULL) {
            root = z;
        } else {
            if (key < keys[y]) {
                left[y] = z;
            } else {
                right[y] = z;
            }
        }
        left[z] = NULL;
        right[z] = NULL;
        color[z] = RED;
        fixAfterAdd(z);
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    public int remove(long key) {
        int z = root;
        while (z != NULL) {
            if (key < keys[z]) {
                z = left[z];
            } else if (key > keys[z]) {
                z = right[z];
            } else {
                final int removedValue = values[z];
                removeNode(z);
                returnedNull = false;
                return removedValue;
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    private void removeNode(int z) {
        int y = (left[z] == NULL || right[z] == NULL) ? z : successorNode(z);
        int x = (left[y] != NULL) ? left[y] : right[y];
        p[x] = p[y];
        if (p[y] == NULL) {
            root = x;
        } else {
            if (y == left[p[y]]) {
                left[p[y]] = x;
            } else {
                right[p[y]] = x;
            }
        }
        if (y != z) {
            keys[z] = keys[y];
            values[z] = values[y];
        }
        

        if (color[y] == BLACK) {
            fixAfterRemove(x);
        }
        

        if (y != size) {
            

            keys[y] = keys[size];
            values[y] = values[size];
            left[y] = left[size];
            right[y] = right[size];
            p[y] = p[size];
            color[y] = color[size];
            

            p[left[size]] = y;
            p[right[size]] = y;
            

            if (left[p[size]] == size) {
                left[p[size]] = y;
            } else {
                right[p[size]] = y;
            }
            

            if (root == size) {
                root = y;
            }
        }
        size--;
    }

    private int successorNode(int x) {
        if (right[x] != NULL) {
            x = right[x];
            while (left[x] != NULL) {
                x = left[x];
            }
            return x;
        } else {
            int y = p[x];
            while (y != NULL && x == right[y]) {
                

                x = y;
                y = p[y];
            }
            return y;
        }
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void fixAfterAdd(int z) {
        while (color[p[z]] == RED) {
            if (p[z] == left[p[p[z]]]) {
                int y = right[p[p[z]]];
                if (color[y] == RED) {
                    color[p[z]] = BLACK;
                    color[y] = BLACK;
                    color[p[p[z]]] = RED;
                    z = p[p[z]];
                } else {
                    if (z == right[p[z]]) {
                        z = p[z];
                        rotateLeft(z);
                    }
                    color[p[z]] = BLACK;
                    color[p[p[z]]] = RED;
                    rotateRight(p[p[z]]);
                }
            } else {
                int y = left[p[p[z]]];
                if (color[y] == RED) {
                    color[p[z]] = BLACK;
                    color[y] = BLACK;
                    color[p[p[z]]] = RED;
                    z = p[p[z]];
                } else {
                    if (z == left[p[z]]) {
                        z = p[z];
                        rotateRight(z);
                    }
                    color[p[z]] = BLACK;
                    color[p[p[z]]] = RED;
                    rotateLeft(p[p[z]]);
                }
            }
        }
        color[root] = BLACK;
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void fixAfterRemove(int x) {
        while (x != root && color[x] == BLACK) {
            if (x == left[p[x]]) {
                int w = right[p[x]];
                if (color[w] == RED) {
                    color[w] = BLACK;
                    color[p[x]] = RED;
                    rotateLeft(p[x]);
                    w = right[p[x]];
                }
                if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                    color[w] = RED;
                    x = p[x];
                } else {
                    if (color[right[w]] == BLACK) {
                        color[left[w]] = BLACK;
                        color[w] = RED;
                        rotateRight(w);
                        w = right[p[x]];
                    }
                    color[w] = color[p[x]];
                    color[p[x]] = BLACK;
                    color[right[w]] = BLACK;
                    rotateLeft(p[x]);
                    x = root;
                }
            } else {
                int w = left[p[x]];
                if (color[w] == RED) {
                    color[w] = BLACK;
                    color[p[x]] = RED;
                    rotateRight(p[x]);
                    w = left[p[x]];
                }
                if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                    color[w] = RED;
                    x = p[x];
                } else {
                    if (color[left[w]] == BLACK) {
                        color[right[w]] = BLACK;
                        color[w] = RED;
                        rotateLeft(w);
                        w = left[p[x]];
                    }
                    color[w] = color[p[x]];
                    color[p[x]] = BLACK;
                    color[left[w]] = BLACK;
                    rotateRight(p[x]);
                    x = root;
                }
            }
        }
        color[x] = BLACK;
    }

    private void rotateLeft(int x) {
        int y = right[x];
        right[x] = left[y];
        if (left[y] != NULL) {
            p[left[y]] = x;
        }
        p[y] = p[x];
        if (p[x] == NULL) {
            root = y;
        } else {
            if (x == left[p[x]]) {
                left[p[x]] = y;
            } else {
                right[p[x]] = y;
            }
        }
        left[y] = x;
        p[x] = y;
    }

    private void rotateRight(int x) {
        int y = left[x];
        left[x] = right[y];
        if (right[y] != NULL) {
            p[right[y]] = x;
        }
        p[y] = p[x];
        if (p[x] == NULL) {
            root = y;
        } else {
            if (x == right[p[x]]) {
                right[p[x]] = y;
            } else {
                left[p[x]] = y;
            }
        }
        right[y] = x;
        p[x] = y;
    }

    public boolean returnedNull() {
        return returnedNull;
    }

    public void clear() {
        color[NULL] = BLACK;
        size = 0;
        root = NULL;
    }

    public long[] keys() {
        long[] result = new long[size];
        for (int i = 0, x = firstNode(); x != NULL; x = successorNode(x), i++) {
            result[i] = keys[x];
        }
        return result;
    }

    public int[] values() {
        int[] result = new int[size];
        for (int i = 0, x = firstNode(); x != NULL; x = successorNode(x), i++) {
            result[i] = values[x];
        }
        return result;
    }

    private void enlarge() {
        int newLength = Math.max(color.length + 1, (int) (color.length * ENLARGE_SCALE));
        keys = Arrays.copyOf(keys, newLength);
        values = Arrays.copyOf(values, newLength);
        left = Arrays.copyOf(left, newLength);
        right = Arrays.copyOf(right, newLength);
        p = Arrays.copyOf(p, newLength);
        color = Arrays.copyOf(color, newLength);
    }

    private int firstNode() {
        int x = root;
        while (left[x] != NULL) {
            x = left[x];
        }
        return x;
    }

    private int lastNode() {
        int x = root;
        while (right[x] != NULL) {
            x = right[x];
        }
        return x;
    }

    public long getFirstKey() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_KEY;
        }
        final int x = firstNode();
        returnedNull = false;
        return keys[x];
    }

    public long getLastKey() {
        if (root == NULL) {
            returnedNull = true;
            return DEFAULT_NULL_KEY;
        }
        final int x = lastNode();
        returnedNull = false;
        return keys[x];
    }

    public long floorKey(long key) {
        int x = root;
        while (x != NULL) {
            if (key > keys[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    returnedNull = false;
                    return keys[x];
                }
            } else if (key < keys[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_KEY;
                    } else {
                        returnedNull = false;
                        return keys[y];
                    }
                }
            } else {
                returnedNull = false;
                return keys[x];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_KEY;
    }

    public long ceilingKey(long key) {
        int x = root;
        while (x != NULL) {
            if (key < keys[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    returnedNull = false;
                    return keys[x];
                }
            } else if (key > keys[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == right[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_KEY;
                    } else {
                        returnedNull = false;
                        return keys[y];
                    }
                }
            } else {
                returnedNull = false;
                return keys[x];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_KEY;
    }

    public long lowerKey(long key) {
        int x = root;
        while (x != NULL) {
            if (key > keys[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    returnedNull = false;
                    return keys[x];
                }
            } else {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_KEY;
                    } else {
                        returnedNull = false;
                        return keys[y];
                    }
                }
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_KEY;
    }

    public long higherKey(long key) {
        int x = root;
        while (x != NULL) {
            if (key < keys[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    returnedNull = false;
                    return keys[x];
                }
            } else {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == right[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    if (y == NULL) {
                        returnedNull = true;
                        return DEFAULT_NULL_KEY;
                    } else {
                        returnedNull = false;
                        return keys[y];
                    }
                }
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_KEY;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        EzLongIntTreeMap that = (EzLongIntTreeMap) o;

        if (size != that.size) {
            return false;
        }
        for (int x = firstNode(), y = that.firstNode();
             x != NULL;
            

             x = successorNode(x), y = that.successorNode(y)
                ) {
            if (keys[x] != that.keys[y] || values[x] != that.values[y]) {
                return false;
            }
        }
        return true;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('{');
        for (int x = firstNode(); x != NULL; x = successorNode(x)) {
            if (sb.length() > 1) {
                sb.append(", ");
            }
            sb.append(keys[x]);
            sb.append('=');
            sb.append(values[x]);
        }
        sb.append('}');
        return sb.toString();
    }
}


final class PrimitiveHashCalculator {
    private PrimitiveHashCalculator() {
    }

    public static int getHash(int x) {
        return x;
    }

    public static int getHash(long x) {
        return (int)x ^ (int)(x >>> 32);
    }
}
