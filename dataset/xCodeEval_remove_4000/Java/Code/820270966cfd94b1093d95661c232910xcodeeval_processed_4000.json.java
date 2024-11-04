import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		RecoverGraph solver = new RecoverGraph();
		solver.solve(1, in, out);
		out.close();
	}
}

class RecoverGraph {
    public void solve(int testNumber, InputReader in, OutputWriter out) {


        int count   =   in.readInt();
        int maxDegree   =   in.readInt();
        int[] distance  = IOUtils.id0(in,count);
        int[] remaining =   new int[count];

        if(ArrayUtils.count(distance,0) != 1) {
            out.printLine(-1);
            return;
        }

        int root    =   ArrayUtils.find(distance,0);

        Arrays.fill(remaining,maxDegree-1);
        remaining[root]++;

        int[] order =   ArrayUtils.order(distance);











        int start   =   0;

        List<id7> answer =   new ArrayList<id7>();

        for(int i : order) {

            if(i    ==  root) {
                continue;
            }

            while(start < count && ((distance[i]-distance[order[start]] > 1) ||
                    remaining[order[start]] == 0)) {
                start++;
            }

            if(start    ==  count || distance[i]    ==  distance[order[start]]) {
                out.printLine(-1);
                return;
            }

            answer.add(new id7(order[start]+1,i+1));
            remaining[order[start]]--;
        }

        out.printLine(answer.size());
        for(id7 id11 : answer) {
            out.printLine(id11.getFirst()+" "+id11.getSecond());
        }



    }
}

class InputReader {

    private InputStream stream;

    private byte[] buf = new byte[1024];

    private int curChar;

    private int numChars;

    private id14 filter;
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

        while (id2(c))

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

        } while (!id2(c));

        return res * sgn;

    }



    public boolean id2(int c) {

        if (filter != null)

            return filter.id2(c);

        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;

    }



    public interface id14 {

        public boolean id2(int ch);

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



    public void print(Object...objects) {

        for (int i = 0; i < objects.length; i++) {

            if (i != 0)

                writer.print(' ');

            writer.print(objects[i]);

        }

    }



    public void printLine(Object...objects) {

        print(objects);

        writer.println();

    }



    public void close() {

        writer.close();

    }



    }

class IOUtils {

    public static int[] id0(InputReader in,int size) {
        int[] array =   new int[size];
        for(int j   =   0;j < size ; j++) {
            array[j]    =   in.readInt();
        }
        return array;
    }

    }

class ArrayUtils {


    


    



    


    


    


    


    


    


    


    


    



    



    


    


    


    


    
    public static int[] generateOrder(int size) {
        int[] order =   new int[size];
        for(int i   =   0;i < size ; i++) {
            order[i]    =   i;
        }

        return order;
    }

    


    
    public static int[] order(final int[] array) {
        int[] order =   generateOrder(array.length);
        return sort(order,new IntComparator() {
            @Override
            public int compare(int first, int second) {

                if(array[first] < array[second]) {
                   return -1;
                } else if(array[first] > array[second]) {
                    return 1;
                }
                return 0;
            }
        });

    }

    


    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        if (from == 0 && to == array.length)
            new id8(array).id9(comparator);
        else
            new id8(array).subList(from, to).id9(comparator);
        return array;
    }


    public static int count(int[] array, int value) {
        int result = 0;
        for (int i : array) {
            if (i == value)
                result++;
        }
        return result;
    }

    public static int find(int[] array, int value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value)
                return i;
        }
        return -1;
    }
}

class id7 implements Comparable<id7> {

    private int first   ;
    private int second  ;

    public id7(int first,int second) {
        this.first  =   first;
        this.second =   second;
    }

    public boolean equals(Object o) {
        if(this     ==  o) {
            return  true;
        }


        if(!(o instanceof id7)) {
            return false;
        }

        if(o == null || this.getClass() != o.getClass()) {
            return false;
        }

        id7 id11   =   (id7)o;

        return this.getFirst()  ==  id11.getFirst()
                && this.getSecond() ==  id11.getSecond();
    }

    public int hashCode() {
        int result  =   first;
        result  =   31 * result ^ second;
        return result;
    }

    public int getFirst() {
        return first;
    }

    public int getSecond() {
        return second;
    }




    public int compareTo(id7 toCompare) {
        

        if (first < toCompare.first)
            return -1;
        if (first > toCompare.first)
            return 1;
        if (second < toCompare.second)
            return -1;
        if (second > toCompare.second)
            return 1;
        return 0;
    }
}

interface IntComparator {
    IntComparator DEFAULT   =   new IntComparator() {
        @Override
        public int compare(int first, int second) {
            if(first >= second) {
                return 1;
            } else if(second > first) {
                return -1;
            } else {
                return 0;
            }
        }
    } ;
    public int compare(int first, int second);


    }

abstract class id16 extends id3
        implements Comparable<id16> {

    private static final int id12 = 16;
    public abstract void setAt(int index,int value);
    public abstract int valueAt(int index);
    public id6 id15() {

        return new id6() {

            private int index   =   0;
            private int boundry =   size();
            @Override
            public void moveNext() throws IndexOutOfBoundsException {
                if(!id4()) {
                    throw new NoSuchElementException();
                }
                index++;
            }

            @Override
            public boolean id4() {
                return index < boundry;
            }

            @Override
            public int getValue() {
                if(!id4()) {
                    throw new NoSuchElementException();
                }
                return valueAt(index);
            }
        } ;
    }

    public void swap(int pos1,int pos2) {

        int dummy   =  valueAt(pos1);
        setAt(pos1,valueAt(pos2));
        setAt(pos2,dummy);
    }


    public int compareTo(id16 toCompare) {


        id6 i =   toCompare.id15();
        id6 j =   id15();

        while(true) {

            if(i.id4()) {
                if(j.id4()) {
                    if(i.getValue() != j.getValue()) {
                        if(j.getValue() > i.getValue()) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                } else {
                    return 1;
                }

            } else {
                if(j.id4()) {
                    return 1;
                } else {
                    return 0;
                }
            }


            i.moveNext();
            j.moveNext();

        }



    }


    public int hashCode() {
        int result  =   0;
        for(id6 itr = id15() ; itr.id4() ; itr.moveNext()) {
            result  =   result * 31 + itr.getValue();
        }
        return result;
    }


    public boolean equals(Object o) {

        if(!(o instanceof id16)) {
            return false;
        }
        id16 other    =   (id16)o;
        if(other.size() != size()) {
            return false;
        }


        id6 i     =   id15();
        id6 j     =   other.id15();

        while(i.id4()) {

            if(i.getValue() != j.getValue()) {
                return false;
            }

            i.moveNext();
            j.moveNext();
        }

        return true;

    }


    public id16 subList(int from,int to) {
        return new SubList(from,to);
    }

    private class SubList extends id16 {

        private int from;
        private int to;
        private int size;


        public SubList(int from,int to) {
            this.from   =   from;
            this.to     =   to;
            this.size   =   from-to;
        }


        public void setAt(int index, int value) {
            if(index < 0 || index >= size()) {
                throw new ArrayIndexOutOfBoundsException();
            }

            id16.this.setAt(from + index, value);
        }

        public int valueAt(int index) {

            if(index < 0 || index >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }

            return id16.this.valueAt(index + from);
        }

        public int size() {
            return size;
        }


    }

    public id13 id9(IntComparator comparator) {
        quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
        return new id10(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id12) {
            id5(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining--;
        int pivotIndex = (from + to) >> 1;
        int pivot = valueAt(pivotIndex);
        swap(pivotIndex, to);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = comparator.compare(valueAt(i), pivot);
            if (value < 0)
                swap(storeIndex++, i);
            else if (value == 0)
                swap(--equalIndex, i--);
        }
        quickSort(from, storeIndex - 1, remaining, comparator);
        for (int i = equalIndex; i <= to; i++)
            swap(storeIndex++, i);
        quickSort(storeIndex, to, remaining, comparator);
    }

    private void heapSort(int from, int to, IntComparator comparator) {
        for (int i = (to + from - 1) >> 1; i >= from; i--)
            id1(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id1(from, i - 1, comparator, from);
        }
    }

    private void id1(int start, int end, IntComparator comparator, int delta) {
        int value = valueAt(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end)
                return;
            int childValue = valueAt(child);
            if (child + 1 <= end) {
                int otherValue = valueAt(child + 1);
                if (comparator.compare(otherValue, childValue) > 0) {
                    child++;
                    childValue = otherValue;
                }
            }
            if (comparator.compare(value, childValue) >= 0)
                return;
            swap(start, child);
            start = child;
        }
    }

    private void id5(int from, int to, IntComparator comparator) {
        for (int i = from + 1; i <= to; i++) {
            int value = valueAt(i);
            for (int j = i - 1; j >= from; j--) {
                if (comparator.compare(valueAt(j), value) <= 0)
                    break;
                swap(j, j + 1);
            }
        }
    }



}

abstract class id13 extends id16 {

    protected final IntComparator comparator;

    protected id13(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void setAt(int index,int value) {
        throw new UnsupportedOperationException();
    }

    public id13 id9(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    protected void ensureSorted() {
        int size = size();
        if (size == 0)
            return;
        int last = valueAt(0);
        for (int i = 1; i < size; i++) {
            int current = valueAt(i);




            last = current;
        }
    }

    public id13 subList(final int from, final int to) {
        return new id13(comparator) {

            int size    =   to-from;
            @Override
            public int valueAt(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return id13.this.valueAt(index + from);
            }
            @Override
            public int size() {
               return size;
            }
        };
    }
}

class id8 extends id16 {

    
    private final int[] array;


    
    public id8(int...array) {
        this.array  =   array;
    }


    
    public id8(id3 myCollection) {

        array   =   new int[myCollection.size()];
        int start   =   0;
        for(id6 itr   =   id15() ; itr.id4();itr.moveNext()) {
            array[start++]  =   itr.getValue();
        }
    }

    
    private int getAt(int index) {
        if(this.array == null || index >= array.length || index < 0) {
            throw new ArrayIndexOutOfBoundsException();
        }
        return array[index];
    }

    
    public void setAt(int index,int value) {
        if(this.array == null || index >= array.length || index < 0) {
            throw new ArrayIndexOutOfBoundsException();
        }

        array[index]    =   value;

    }


    
    public int valueAt(int index) {
        return getAt(index);
    }

    
    public int size() {
        return array.length;
    }

    
}

interface id6 {

    public boolean id4();
    public void moveNext();
    public int getValue();

}

abstract class id3 {

    public abstract id6 id15();

    public abstract int size();



}

class id10 extends id13 {


        private final int[] array;

        public id10(int[] array) {
            this(array, IntComparator.DEFAULT);
        }

        public id10(id3 collection) {
            this(collection, IntComparator.DEFAULT);
        }

        public id10(int[] array, IntComparator comparator) {
            super(comparator);
            this.array = array;
            ensureSorted();
        }

        public id10(id3 collection, IntComparator comparator) {
            super(comparator);
            array = new int[collection.size()];
            int i = 0;
            for (id6 iterator = collection.id15(); iterator.id4(); iterator.moveNext())
                array[i++] = iterator.getValue();
            ensureSorted();
        }

        public int valueAt(int index) {
            if(index < 0 || index >= array.length) {
                throw new ArrayIndexOutOfBoundsException();
            }
            return  array[index];
        }

        public int size() {
            return array.length;
        }

        public void setAt(int index, int value) {
            throw new UnsupportedOperationException();
        }
}

