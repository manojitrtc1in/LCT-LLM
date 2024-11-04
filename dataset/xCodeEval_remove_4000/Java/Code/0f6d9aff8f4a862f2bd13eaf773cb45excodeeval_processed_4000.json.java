import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.DataOutput;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.ConcurrentModificationException;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.ObjectOutput;
import java.io.IOException;
import java.io.Externalizable;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Map;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.io.ObjectInput;
import java.io.DataInput;
import java.util.Set;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

 class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        id37 a = new id3();
        id37 b = new id3();
        for (int i = 0; i < n; i++) {
            int x1 = in.readInt();
            int x2 = in.readInt();
            add(a, x1, 1);
            add(a, x2, 0);
            if (x1 != x2) {
                add(b, x2, 1);
            }
        }
        int need = (n + 1) / 2;
        int ans = (int) 1e9;
        int[] keys = a.keys();
        int[] values = a.values();
        for (int i = 0; i < keys.length; i++) {
            int color = keys[i];
            int x1 = values[i];
            int x2 = get(b, color);
            if (x1 + x2 >= need) {
                ans = Math.min(ans, need - x1);
            }
        }
        if (ans < 0) {
            ans = 0;
        }
        if (ans == (int) 1e9) {
            ans = -1;
        }
        out.printLine(ans);
    }

    private int get(id37 map, int x) {
        return map.get(x);
    }

    private void add(id37 map, int x, int d) {
        map.id38(x, d, d);
    }
}


 class InputReader {

     private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id42 filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

     public int readInt() {
		int c = read();
		while (id7(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id7(c));
		return res * sgn;
	}

     public boolean id7(int c) {
		if (filter != null)
			return filter.id7(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

     public interface id42 {
		public boolean id7(int ch);
	}
}


 class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

     public void close() {
		writer.close();
	}

     public void printLine(int i) {
		writer.println(i);
	}
}


 interface id37 {


     public int id16();


     public int get( int key );


     public int size();


     public int[] keys();


     public int[] values();


     public id22 iterator();


     public int id38( int key, int adjust_amount, int put_amount );
}


 class id3 extends id30 implements id37, Externalizable {

     protected transient int[] _values;


    public id3() {
        super();
    }


    public id3( int initialCapacity ) {
        super( initialCapacity );
    }


    public id3( int initialCapacity, float loadFactor ) {
        super( initialCapacity, loadFactor );
    }


    public id3( int initialCapacity, float loadFactor,
        int id26, int id43 ) {
        super( initialCapacity, loadFactor, id26, id43 );
    }


    public id3( int[] keys, int[] values ) {
        super( Math.max( keys.length, values.length ) );

        int size = Math.min( keys.length, values.length );
        for ( int i = 0; i < size; i++ ) {
            this.put( keys[i], values[i] );
        }
    }


    public id3( id37 map ) {
        super( map.size() );
        if ( map instanceof id3 ) {
            id3 hashmap = ( id3 ) map;
            this._loadFactor = hashmap._loadFactor;
            this.id20 = hashmap.id20;
            this.id27 = hashmap.id27;
            if ( this.id20 != ( int ) 0 ) {
                Arrays.fill( _set, this.id20 );
            }
            if ( this.id27 != ( int ) 0 ) {
                Arrays.fill( _values, this.id27 );
            }
            setUp( (int) Math.ceil( id40 / _loadFactor ) );
        }
        putAll( map );
    }


    protected int setUp( int initialCapacity ) {
        int capacity;

        capacity = super.setUp( initialCapacity );
        _values = new int[capacity];
        return capacity;
    }


    protected void rehash( int newCapacity ) {
        int oldCapacity = _set.length;
        
        int oldKeys[] = _set;
        int oldVals[] = _values;
        byte oldStates[] = _states;

        _set = new int[newCapacity];
        _values = new int[newCapacity];
        _states = new byte[newCapacity];

        for ( int i = oldCapacity; i-- > 0; ) {
            if( oldStates[i] == FULL ) {
                int o = oldKeys[i];
                int index = insertKey( o );
                _values[index] = oldVals[i];
            }
        }
    }


    public int put( int key, int value ) {
        int index = insertKey( key );
        return doPut( key, value, index );
    }


     private int doPut( int key, int value, int index ) {
        int previous = id27;
        boolean id15 = true;
        if ( index < 0 ) {
            index = -index -1;
            previous = _values[index];
            id15 = false;
        }
        _values[index] = value;

        if (id15) {
            id34( id23 );
        }

        return previous;
    }


     public void putAll( id37 map ) {
        ensureCapacity( map.size() );
        id22 iter = map.iterator();
        while ( iter.hasNext() ) {
            iter.advance();
            this.put( iter.key(), iter.value() );
        }
    }


    public int get( int key ) {
        int index = index( key );
        return index < 0 ? id27 : _values[index];
    }


    public void clear() {
        super.clear();
        Arrays.fill( _set, 0, _set.length, id20 );
        Arrays.fill( _values, 0, _values.length, id27 );
        Arrays.fill( _states, 0, _states.length, FREE );
    }


     protected void removeAt( int index ) {
        _values[index] = id27;
        super.removeAt( index );
    }


     public int[] keys() {
        int[] keys = new int[size()];
        int[] k = _set;
        byte[] states = _states;

        for ( int i = k.length, j = 0; i-- > 0; ) {
          if ( states[i] == FULL ) {
            keys[j++] = k[i];
          }
        }
        return keys;
    }


     public int[] values() {
        int[] vals = new int[size()];
        int[] v = _values;
        byte[] states = _states;

        for ( int i = v.length, j = 0; i-- > 0; ) {
          if ( states[i] == FULL ) {
            vals[j++] = v[i];
          }
        }
        return vals;
    }


     public id22 iterator() {
        return new id19( this );
    }


     public boolean id14( id32 procedure ) {
        byte[] states = _states;
        int[] keys = _set;
        int[] values = _values;
        for ( int i = keys.length; i-- > 0; ) {
            if ( states[i] == FULL && ! procedure.execute( keys[i], values[i] ) ) {
                return false;
            }
        }
        return true;
    }


     public int id38( int key, int adjust_amount, int put_amount ) {
        int index = insertKey( key );
        final boolean id15;
        final int newValue;
        if ( index < 0 ) {
            index = -index -1;
            newValue = ( _values[index] += adjust_amount );
            id15 = false;
        } else {
            newValue = ( _values[index] = put_amount );
            id15 = true;
        }

        byte previousState = _states[index];

        if ( id15 ) {
            id34(id23);
        }

        return newValue;
    }


     class id19 extends id31 implements id22 {

        id19( id3 map ) {
            super( map );
        }

        public void advance() {
            id39();
        }

        public int key() {
            return _set[_index];
        }

        public int value() {
            return _values[_index];
        }

     }


    public boolean equals( Object other ) {
        if ( ! ( other instanceof id37 ) ) {
            return false;
        }
        id37 that = ( id37 ) other;
        if ( that.size() != this.size() ) {
            return false;
        }
        int[] values = _values;
        byte[] states = _states;
        int id1 = id16();
        int id33 = that.id16();
        for ( int i = values.length; i-- > 0; ) {
            if ( states[i] == FULL ) {
                int key = _set[i];
                int that_value = that.get( key );
                int this_value = values[i];
                if ( ( this_value != that_value ) &&
                     ( this_value != id1 ) &&
                     ( that_value != id33 ) ) {
                    return false;
                }
            }
        }
        return true;
    }


    public int hashCode() {
        int hashcode = 0;
        byte[] states = _states;
        for ( int i = _values.length; i-- > 0; ) {
            if ( states[i] == FULL ) {
                hashcode += HashFunctions.hash( _set[i] ) ^
                            HashFunctions.hash( _values[i] );
            }
        }
        return hashcode;
    }


    public String toString() {
        final StringBuilder buf = new StringBuilder( "{" );
        id14( new id32() {
            private boolean first = true;
            public boolean execute( int key, int value ) {
                if ( first ) first = false;
                else buf.append( ", " );

                buf.append(key);
                buf.append("=");
                buf.append(value);
                return true;
            }
        });
        buf.append( "}" );
        return buf.toString();
    }


    public void writeExternal(ObjectOutput out) throws IOException {
        out.writeByte( 0 );

        super.writeExternal( out );

    	out.writeInt( _size );

    	for ( int i = _states.length; i-- > 0; ) {
            if ( _states[i] == FULL ) {
                out.writeInt( _set[i] );
                out.writeInt( _values[i] );
            }
        }
    }


    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        in.readByte();

        super.readExternal( in );

    	int size = in.readInt();
    	setUp( size );

    	while (size-- > 0) {
            int key = in.readInt();
            int val = in.readInt();
            put(key, val);
        }
    }
}


interface id22 extends id0 {
    public int key();

    public int value();

 }


interface id32 {

    public boolean execute( int a, int b );
}


abstract  class id30 extends id24 {

    public transient int[] _set;


    protected int id20;


    protected int id27;

    protected boolean id23;

    public id30() {
        super();
        id20 = ( int ) 0;
        id27 = ( int ) 0;
    }


    public id30( int initialCapacity ) {
        super( initialCapacity );
        id20 = ( int ) 0;
        id27 = ( int ) 0;
    }


    public id30( int initialCapacity, float loadFactor ) {
        super(initialCapacity, loadFactor);
        id20 = ( int ) 0;
        id27 = ( int ) 0;
    }


    public id30( int initialCapacity, float loadFactor,
        int id20, int id27 ) {
        super(initialCapacity, loadFactor);
        this.id20 = id20;
        this.id27 = id27;
    }


    public int id16() {
        return id27;
    }


    protected int setUp( int initialCapacity ) {
        int capacity;

        capacity = super.setUp( initialCapacity );
        _set = new int[capacity];
        return capacity;
    }


    protected void removeAt( int index ) {
        _set[index] = id20;
        super.removeAt( index );
    }


    protected int index( int key ) {
        int hash, probe, index, length;

        final byte[] states = _states;
        final int[] set = _set;
        length = states.length;
        hash = HashFunctions.hash( key ) & 0x7fffffff;
        index = hash % length;
        byte state = states[index];

        if (state == FREE)
            return -1;

        if (state == FULL && set[index] == key)
            return index;

        return id5(key, index, hash, state);
    }

    int id5(int key, int index, int hash, byte state) {
        int length = _set.length;
        int probe = 1 + (hash % (length - 2));
        final int loopIndex = index;

        do {
            index -= probe;
            if (index < 0) {
                index += length;
            }
            state = _states[index];
            if (state == FREE)
                return -1;

            if (key == _set[index] && state != REMOVED)
                return index;
        } while (index != loopIndex);

        return -1;
    }


    protected int insertKey( int val ) {
             int hash, index;

             hash = HashFunctions.hash(val) & 0x7fffffff;
             index = hash % _states.length;
             byte state = _states[index];

             id23 = false;

             if (state == FREE) {
                 id23 = true;
                 id10(index, val);

                 return index;
             }

             if (state == FULL && _set[index] == val) {
                 return -index - 1;
             }

             return id35(val, index, hash, state);
         }

         int id35(int val, int index, int hash, byte state) {
             final int length = _set.length;
             int probe = 1 + (hash % (length - 2));
             final int loopIndex = index;
             int firstRemoved = -1;

             do {
                 if (state == REMOVED && firstRemoved == -1)
                     firstRemoved = index;

                 index -= probe;
                 if (index < 0) {
                     index += length;
                 }
                 state = _states[index];

                 if (state == FREE) {
                     if (firstRemoved != -1) {
                         id10(firstRemoved, val);
                         return firstRemoved;
                     } else {
                         id23 = true;
                         id10(index, val);
                         return index;
                     }
                 }

                 if (state == FULL && _set[index] == val) {
                     return -index - 1;
                 }

                 } while (index != loopIndex);

             if (firstRemoved != -1) {
                 id10(firstRemoved, val);
                 return firstRemoved;
             }

             throw new IllegalStateException("No free or removed slots available. Key set full?!!");
         }

         void id10(int index, int val) {
             _set[index] = val;
             _states[index] = FULL;
         }


    public void writeExternal( ObjectOutput out ) throws IOException {
        out.writeByte( 0 );

        super.writeExternal( out );

    	out.writeInt( id20 );

    	out.writeInt( id27 );
    }


    public void readExternal( ObjectInput in ) throws IOException, ClassNotFoundException {
        in.readByte();

        super.readExternal( in );

    	id20 = in.readInt();

    	id27 = in.readInt();
    }
}


abstract  class THash implements Externalizable {

    protected static final float id4 = Constants.id4;

    protected static final int id40 = Constants.id40;


    protected transient int _size;

    protected transient int _free;

    protected float _loadFactor;

    protected int _maxSize;


    protected int id28;

    protected float id29;

    protected transient boolean id12 = false;


    public THash() {
        this( id40, id4 );
    }


    public THash( int initialCapacity ) {
        this( initialCapacity, id4 );
    }


    public THash( int initialCapacity, float loadFactor ) {
        super();
        _loadFactor = loadFactor;

        id29 = loadFactor;

        setUp( HashFunctions.id41( initialCapacity / loadFactor ) );
    }


    public int size() {
        return _size;
    }


    abstract public int capacity();


    public void ensureCapacity( int desiredCapacity ) {
        if ( desiredCapacity > ( _maxSize - size() ) ) {
			rehash( PrimeFinder.nextPrime( Math.max( size() + 1,
				HashFunctions.id41( ( desiredCapacity + size() ) / _loadFactor ) + 1 ) ) );
            id11( capacity() );
        }
    }


    public void compact() {
        rehash( PrimeFinder.nextPrime( Math.max( _size + 1,
	        HashFunctions.id41( size() / _loadFactor ) + 1 ) ) );
        id11( capacity() );

        if ( id29 != 0 ) {
            id13( size() );
        }
    }


    protected void removeAt( int index ) {
        _size--;

        if ( id29 != 0 ) {
            id28--;

            if ( !id12 && id28 <= 0 ) {
                compact();
            }
        }
    }


    public void clear() {
        _size = 0;
        _free = capacity();
    }


    protected int setUp( int initialCapacity ) {
        int capacity;

        capacity = PrimeFinder.nextPrime( initialCapacity );
        id11( capacity );
        id13( initialCapacity );

        return capacity;
    }


    protected abstract void rehash( int newCapacity );


    protected void id11( int capacity ) {
        _maxSize = Math.min( capacity - 1, (int) ( capacity * _loadFactor ) );
        _free = capacity - _size;
    }


    protected void id13( int size ) {
        if ( id29 != 0 ) {
            id28 =
                    (int) ( ( size * id29 ) + 0.5f );
        }
    }


    protected final void id34( boolean id2 ) {
        if ( id2 ) {
            _free--;
        }

        if ( ++_size > _maxSize || _free == 0 ) {
            int newCapacity = _size > _maxSize ? PrimeFinder.nextPrime( capacity() << 1 ) : capacity();
            rehash( newCapacity );
            id11( capacity() );
        }
    }


    public void writeExternal( ObjectOutput out ) throws IOException {
        out.writeByte( 0 );

        out.writeFloat( _loadFactor );

        out.writeFloat( id29 );
    }


    public void readExternal( ObjectInput in )
            throws IOException, ClassNotFoundException {

        in.readByte();

        float old_factor = _loadFactor;
        _loadFactor = in.readFloat();

        id29 = in.readFloat();

        if ( old_factor != _loadFactor ) {
            setUp( (int) Math.ceil( id40 / _loadFactor ) );
        }
    }
}


 interface TIterator {
    public boolean hasNext();

 }


 interface id0 extends TIterator {
    public void advance();
}


 final class HashFunctions {

     public static int hash(int value) {
		return value;
    }


     public static int id41( float v ) {
        int possible_result = ( int ) v;
        if ( v - possible_result > 0 ) possible_result++;
        return possible_result;
    }
}


 abstract class id31 implements id44 {

    protected final id24 _hash;
    protected int _expectedSize;
    protected int _index;


    public id31( id24 hash ) {
        _hash = hash;
        _expectedSize = _hash.size();
        _index = _hash.capacity();
    }


    protected final int nextIndex() {
        if ( _expectedSize != _hash.size() ) {
            throw new ConcurrentModificationException();
        }

        byte[] states = _hash._states;
        int i = _index;
        while ( i-- > 0 && ( states[i] != id24.FULL ) ) {
            ;
        }
        return i;
    }


    public boolean hasNext() {
        return nextIndex() >= 0;
    }


     protected final void id39() {
        if ( ( _index = nextIndex() ) < 0 ) {
            throw new NoSuchElementException();
        }
    }


} 


abstract  class id24 extends THash {

    public transient byte[] _states;

    public static final byte FREE = 0;

    public static final byte FULL = 1;

    public static final byte REMOVED = 2;


    public id24() {
        super();
    }


    public id24( int initialCapacity ) {
        this( initialCapacity, id4 );
    }


    public id24( int initialCapacity, float loadFactor ) {
        super();
		initialCapacity = Math.max( 1, initialCapacity );
        _loadFactor = loadFactor;
        setUp( HashFunctions.id41( initialCapacity / loadFactor ) );
    }


    public int capacity() {
        return _states.length;
    }


    protected void removeAt( int index ) {
        _states[index] = REMOVED;
        super.removeAt( index );
    }


    protected int setUp( int initialCapacity ) {
        int capacity;

        capacity = super.setUp( initialCapacity );
        _states = new byte[capacity];
        return capacity;
    }
}


class Constants {

    private static final boolean VERBOSE =
            System.getProperty( "gnu.trove.verbose", null ) != null;

    public static final int id40 = 10;

    public static final float id4 = 0.5f;


    public static final byte id18;
    static {
        byte value;
        String property = System.getProperty( "gnu.trove.no_entry.byte", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Byte.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Byte.MIN_VALUE;
        else value = Byte.valueOf( property );

        if ( value > Byte.MAX_VALUE ) value = Byte.MAX_VALUE;
        else if ( value < Byte.MIN_VALUE ) value = Byte.MIN_VALUE;
        id18 = value;
        if ( VERBOSE ) {
            System.out.println( "id18: " +
                                id18 );
        }
    }


    public static final short id17;
    static {
        short value;
        String property = System.getProperty( "gnu.trove.no_entry.short", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Short.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Short.MIN_VALUE;
        else value = Short.valueOf( property );

        if ( value > Short.MAX_VALUE ) value = Short.MAX_VALUE;
        else if ( value < Short.MIN_VALUE ) value = Short.MIN_VALUE;
        id17 = value;
        if ( VERBOSE ) {
            System.out.println( "id17: " +
                                id17 );
        }
    }


    public static final char id9;
    static {
        char value;
        String property = System.getProperty( "gnu.trove.no_entry.char", "\0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Character.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Character.MIN_VALUE;
        else value = property.toCharArray()[0];

        if ( value > Character.MAX_VALUE ) value = Character.MAX_VALUE;
        else if ( value < Character.MIN_VALUE ) value = Character.MIN_VALUE;
        id9 = value;
        if ( VERBOSE ) {
            System.out.println( "id9: " +
                                Integer.valueOf( value ) );
        }
    }


    public static final int id36;
     static {
        int value;
        String property = System.getProperty( "gnu.trove.no_entry.int", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Integer.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Integer.MIN_VALUE;
        else value = Integer.valueOf( property );
        id36 = value;
        if ( VERBOSE ) {
            System.out.println( "id36: " +
                                id36 );
        }
    }


    public static final long id8;
    static {
        long value;
        String property = System.getProperty( "gnu.trove.no_entry.long", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Long.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Long.MIN_VALUE;
        else value = Long.valueOf( property );
        id8 = value;
        if ( VERBOSE ) {
            System.out.println( "id8: " +
                                id8 );
        }
    }


    public static final float id25;
    static {
        float value;
        String property = System.getProperty( "gnu.trove.no_entry.float", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Float.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Float.MIN_VALUE;
        else if ( "MIN_NORMAL".equalsIgnoreCase( property ) ) value = 0x1.0p-126f;
        else if ( "NEGATIVE_INFINITY".equalsIgnoreCase( property ) ) value = Float.NEGATIVE_INFINITY;
        else if ( "POSITIVE_INFINITY".equalsIgnoreCase( property ) ) value = Float.POSITIVE_INFINITY;
else value = Float.valueOf( property );
        id25 = value;
        if ( VERBOSE ) {
            System.out.println( "id25: " +
                                id25 );
        }
    }


    public static final double id21;
    static {
        double value;
        String property = System.getProperty( "gnu.trove.no_entry.double", "0" );
        if ( "MAX_VALUE".equalsIgnoreCase( property ) ) value = Double.MAX_VALUE;
        else if ( "MIN_VALUE".equalsIgnoreCase( property ) ) value = Double.MIN_VALUE;
        else if ( "MIN_NORMAL".equalsIgnoreCase( property ) ) value = 0x1.0p-1022;
        else if ( "NEGATIVE_INFINITY".equalsIgnoreCase( property ) ) value = Double.NEGATIVE_INFINITY;
        else if ( "POSITIVE_INFINITY".equalsIgnoreCase( property ) ) value = Double.POSITIVE_INFINITY;
else value = Double.valueOf( property );
        id21 = value;
        if ( VERBOSE ) {
            System.out.println( "id21: " +
                                id21 );
        }
    }
}


final class PrimeFinder {
    public static final int largestPrime = Integer.MAX_VALUE;

    private static final int[] id6 = {
        largestPrime,

        5,11,23,47,97,197,397,797,1597,3203,6421,12853,25717,51437,102877,205759,
        411527,823117,1646237,3292489,6584983,13169977,26339969,52679969,105359939,
        210719881,421439783,842879579,1685759167,

        433,877,1759,3527,7057,14143,28289,56591,113189,226379,452759,905551,1811107,
        3622219,7244441,14488931,28977863,57955739,115911563,231823147,463646329,927292699,
        1854585413,

        953,1907,3821,7643,15287,30577,61169,122347,244703,489407,978821,1957651,3915341,
        7830701,15661423,31322867,62645741,125291483,250582987,501165979,1002331963,
        2004663929,

        1039,2081,4177,8363,16729,33461,66923,133853,267713,535481,1070981,2141977,4283963,
        8567929,17135863,34271747,68543509,137087021,274174111,548348231,1096696463,

        31,67,137,277,557,1117,2237,4481,8963,17929,35863,71741,143483,286973,573953,
        1147921,2295859,4591721,9183457,18366923,36733847,73467739,146935499,293871013,
        587742049,1175484103,

        599,1201,2411,4831,9677,19373,38747,77509,155027,310081,620171,1240361,2480729,
        4961459,9922933,19845871,39691759,79383533,158767069,317534141,635068283,1270136683,

        311,631,1277,2557,5119,10243,20507,41017,82037,164089,328213,656429,1312867,
        2625761,5251529,10503061,21006137,42012281,84024581,168049163,336098327,672196673,
        1344393353,

        3,7,17,37,79,163,331,673,1361,2729,5471,10949,21911,43853,87719,175447,350899,
        701819,1403641,2807303,5614657,11229331,22458671,44917381,89834777,179669557,
        359339171,718678369,1437356741,

        43,89,179,359,719,1439,2879,5779,11579,23159,46327,92657,185323,370661,741337,
        1482707,2965421,5930887,11861791,23723597,47447201,94894427,189788857,379577741,
        759155483,1518310967,

        379,761,1523,3049,6101,12203,24407,48817,97649,195311,390647,781301,1562611,
        3125257,6250537,12501169,25002389,50004791,100009607,200019221,400038451,800076929,
        1600153859
    };

    static {

        Arrays.sort(id6);
    }

    public static final int nextPrime(int desiredCapacity) {
        int i = Arrays.binarySearch(id6, desiredCapacity);
        if (i<0) {
            i = -i -1;
        }
        return id6[i];
    }
}


 interface id44 extends TIterator {
    public boolean hasNext();


 }


