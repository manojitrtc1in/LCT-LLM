import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class B extends PrintWriter {

	long point(long x, long y) {
		return (x << 32) | (y);
	}

	boolean isStabel(int x, int y, EzLongIntHashMap p, int rx, int ry) {
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

	boolean isOpen(int x, int y, EzLongIntHashMap p) {
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

		final Random rnd = new Random(322);
		final long r = BigInteger.valueOf((1L << 32) + rnd.nextInt(1 << 20)).nextProbablePrime().longValue();
        EzLongIntHashMap p = new EzLongIntHashMap(new EzLongHasher() {
			@Override
			public int getHash(long x) {
				int low = (int) x;
				int high = (int) (x >>> 32);
				return (int) (high * r + low);
			}
		});

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


class EzLongIntHashMap {
    private static final int DEFAULT_CAPACITY = 8;

    

    

    

    

    

    

    private static final int REBUILD_LENGTH_THRESHOLD = 32;

    private static final byte FREE = 0;
    private static final byte REMOVED = 1;
    private static final byte FILLED = 2;

    private static final int DEFAULT_NULL_VALUE = (new int[1])[0];

    private static final Random rnd = new Random();
    private static final int POS_RANDOM_SHIFT_1;
    private static final int POS_RANDOM_SHIFT_2;
    private static final int STEP_RANDOM_SHIFT_1;
    private static final int STEP_RANDOM_SHIFT_2;

    static {
        POS_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
        POS_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
        STEP_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
        STEP_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
    }

    private long[] keys;
    private int[] values;
    private byte[] status;
    private int size;
    private int removedCount;
    private int mask;
    private boolean returnedNull;
    private final int hashSeed;
	private final EzLongHasher hasher;

    public EzLongIntHashMap() {
        this(DEFAULT_CAPACITY, EzLongHasher.DEFAULT);
    }

	public EzLongIntHashMap(int capacity) {
		this(capacity, EzLongHasher.DEFAULT);
	}
		
	public EzLongIntHashMap(EzLongHasher hasher) {
		this(DEFAULT_CAPACITY, hasher);
	}
	
    public EzLongIntHashMap(int capacity, EzLongHasher hasher) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity must be non-negative");
        }
        

        int length = 4 * Math.max(1, capacity);
        if ((length & (length - 1)) != 0) {
            length = Integer.highestOneBit(length) << 1;
        }
        

        initEmptyTable(length);
        returnedNull = false;
        hashSeed = rnd.nextInt();
		this.hasher = hasher;
    }

    private int getStartPos(int h) {
        h ^= hashSeed;
        h ^= (h >>> POS_RANDOM_SHIFT_1) ^ (h >>> POS_RANDOM_SHIFT_2);
        return h & mask;
    }

    private int getStep(int h) {
        h ^= hashSeed;
        h ^= (h >>> STEP_RANDOM_SHIFT_1) ^ (h >>> STEP_RANDOM_SHIFT_2);
        return ((h << 1) | 1) & mask;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean containsKey(long key) {
        final int keyHash = hasher.getHash(key);
        int pos = getStartPos(keyHash);
        final int step = getStep(keyHash);
        for (; status[pos] != FREE; pos = (pos + step) & mask) {
            if (status[pos] == FILLED && keys[pos] == key) {
                return true;
            }
        }
        return false;
    }

    public int get(long key) {
        final int keyHash = hasher.getHash(key);
        int pos = getStartPos(keyHash);
        final int step = getStep(keyHash);
        for (; status[pos] != FREE; pos = (pos + step) & mask) {
            if (status[pos] == FILLED && keys[pos] == key) {
                returnedNull = false;
                return values[pos];
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    public int put(long key, int value) {
        final int keyHash = hasher.getHash(key);
        int pos = getStartPos(keyHash);
        final int step = getStep(keyHash);
        for (; status[pos] == FILLED; pos = (pos + step) & mask) {
            if (keys[pos] == key) {
                final int oldValue = values[pos];
                values[pos] = value;
                returnedNull = false;
                return oldValue;
            }
        }
        if (status[pos] == FREE) {
            status[pos] = FILLED;
            keys[pos] = key;
            values[pos] = value;
            size++;
            if ((size + removedCount) * 2 > keys.length) {
                rebuild(keys.length * 2); 

            }
            returnedNull = true;
            return DEFAULT_NULL_VALUE;
        }
        final int removedPos = pos;
        for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
            if (status[pos] == FILLED && keys[pos] == key) {
                final int oldValue = values[pos];
                values[pos] = value;
                returnedNull = false;
                return oldValue;
            }
        }
        status[removedPos] = FILLED;
        keys[removedPos] = key;
        values[removedPos] = value;
        size++;
        removedCount--;
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    public int remove(long key) {
        final int keyHash = hasher.getHash(key);
        int pos = getStartPos(keyHash);
        final int step = getStep(keyHash);
        for (; status[pos] != FREE; pos = (pos + step) & mask) {
            if (status[pos] == FILLED && keys[pos] == key) {
                final int removedValue = values[pos];
                status[pos] = REMOVED;
                size--;
                removedCount++;
                if (keys.length > REBUILD_LENGTH_THRESHOLD) {
                    if (8 * size <= keys.length) {
                        rebuild(keys.length / 2); 

                    } else if (size < removedCount) {
                        rebuild(keys.length); 

                    }
                }
                returnedNull = false;
                return removedValue;
            }
        }
        returnedNull = true;
        return DEFAULT_NULL_VALUE;
    }

    public boolean returnedNull() {
        return returnedNull;
    }

    public void clear() {
        if (keys.length > REBUILD_LENGTH_THRESHOLD) {
            initEmptyTable(REBUILD_LENGTH_THRESHOLD);
        } else {
            Arrays.fill(status, FREE);
            size = 0;
            removedCount = 0;
        }
    }

    public long[] keys() {
        long[] result = new long[size];
        for (int i = 0, j = 0; i < keys.length; i++) {
            if (status[i] == FILLED) {
                result[j++] = keys[i];
            }
        }
        return result;
    }

    public int[] values() {
        int[] result = new int[size];
        for (int i = 0, j = 0; i < values.length; i++) {
            if (status[i] == FILLED) {
                result[j++] = values[i];
            }
        }
        return result;
    }

    private void rebuild(int newLength) {
        long[] oldKeys = keys;
        int[] oldValues = values;
        byte[] oldStatus = status;
        initEmptyTable(newLength);
        for (int i = 0; i < oldKeys.length; i++) {
            if (oldStatus[i] == FILLED) {
                put(oldKeys[i], oldValues[i]);
            }
        }
    }

    private void initEmptyTable(int length) {
        keys = new long[length];
        values = new int[length];
        status = new byte[length];
        size = 0;
        removedCount = 0;
        mask = length - 1;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        EzLongIntHashMap that = (EzLongIntHashMap) o;

        if (size != that.size) {
            return false;
        }
        for (int i = 0; i < keys.length; i++) {
            if (status[i] == FILLED) {
                int thatValue = that.get(keys[i]);
                if (that.returnedNull || thatValue != values[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('{');
        for (int i = 0; i < keys.length; i++) {
            if (status[i] == FILLED) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(keys[i]);
                sb.append('=');
                sb.append(values[i]);
            }
        }
        sb.append('}');
        return sb.toString();
    }
}


interface EzLongHasher {
    int getHash(long x);

    static final EzLongHasher DEFAULT = new EzLongHasher() {
        @Override
        public int getHash(long x) {
            return PrimitiveHashCalculator.getHash(x);
        }
    };
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