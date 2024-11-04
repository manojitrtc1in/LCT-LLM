import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class id45 {

    public static void main(String[] args) {
        new ProblemSolver().solve();
    }

    private static class ProblemSolver {

        public void solve() {
            String inputString = "";
            InputReader reader = new InputReader(
                    inputString.isEmpty() ? System.in : new ByteArrayInputStream(inputString.getBytes()));
            OutputWriter writer = new OutputWriter(System.out);

            solve(reader, writer);

            writer.flush();
            writer.close();
        }

        private int rowSize;
        private int colSize;
        private long id0;
        private long[][] id33;

        

        private void solve(InputReader reader, OutputWriter writer) {
            rowSize = reader.nextInt();
            colSize = reader.nextInt();
            id0 = reader.nextLong();

            id33 = new long[rowSize][colSize];
            for (int i = 0; i < rowSize; i++) {
                for (int j = 0; j < colSize; j++) {
                    id33[i][j] = reader.nextLong();
                }
            }

            id40 id27
                    = new id40(id33, true, id0);

            id51 id15 = new id51(rowSize, colSize, id33);
            id5 id18 = new id5(
                    id15);

            id30(id27,
                    id18);

            writer.println(id27.id28());

        }

        private void id30(
                id40 id27,
                id5 id18) {

            int id37 = rowSize + colSize - 1;
            int id50 = id37 / 2;

            int id23 = id50 == 0 ? 1 : id50;
            int id24 = id37 - id23 + 1;

            id46(id27, id18,
                    id23);

            id22(id27, id18,
                    id24);

        }

        private void id46(id40 id27,
                id5 id18, int id23) {
            id51.Cell startCell = new id51.Cell(0, 0);
            id5.id43 id36
                    = new id5.id43();
            id18.traverse(startCell, id23, id36,
                    id27);
        }

        private void id22(id40 id27,
                id5 id18, int id24) {
            id27.id11(false);
            id51.Cell startCell = new id51.Cell(rowSize - 1, colSize - 1);
            id5.id32 id38
                    = new id5.id32();
            id18.traverse(startCell, id24, id38,
                    id27);
        }

        

        private static class id40 implements id29.PathConsumer {

            private long[][] id33;
            private Map<Long, Long>[][] id48;
            private boolean id14;
            private long id0;

            private long id6 = 0;

            public id40(long[][] id33, boolean id14,
                    long id0) {
                this.id33 = id33;
                id48 = new Map[id33.length][id33[0].length];
                for (int i = 0; i < id33.length; i++) {
                    for (int j = 0; j < id33[0].length; j++) {
                        id48[i][j] = new HashMap<>();
                    }
                }
                this.id14 = id14;
                this.id0 = id0;
            }

            @Override
            public void consume(Matrix.Cell[] path, int pathSize) {
                if (id14) {
                    id2(path, pathSize);
                } else {
                    id21(path, pathSize);
                }
            }

            private void id2(Matrix.Cell[] path, int pathSize) {
                long xorSum = id35(path, pathSize);
                id51.Cell id20 = (id51.Cell) path[pathSize - 1];
                Map<Long, Long> id8 = id48[id20
                        .id41()][id20.id53()];
                if (id8.containsKey(xorSum)) {
                    long id42 = id8.get(xorSum);
                    id8.put(xorSum, id42 + 1L);
                } else {
                    id8.put(xorSum, 1L);
                }
            }

            private void id21(Matrix.Cell[] path, int pathSize) {
                long xorSum = id35(path, pathSize - 1);
                long id25 = id0 ^ xorSum;

                id51.Cell id20 = (id51.Cell) path[pathSize - 1];
                Map<Long, Long> id8 = id48[id20
                        .id41()][id20.id53()];

                if (id8.containsKey(id25)) {
                    id6 += id8.get(id25);
                }
            }

            private long id35(Matrix.Cell[] path, int size) {
                long xorSum = 0L;
                for (int i = 0; i < size; i++) {
                    id51.Cell cell = (id51.Cell) path[i];
                    xorSum ^= id33[cell.id41()][cell.id53()];
                }
                return xorSum;
            }

            public void id11(boolean id34) {
                id14 = id34;
            }

            public long id28() {
                return id6;
            }
        }

        private interface Matrix {

            interface Cell {
            }

        }

        private static class id51 implements Matrix {

            private int rowSize;
            private int colSize;
            private long[][] matrixArray;

            public id51(int rowSize, int colSize, long[][] matrixArray) {
                this.rowSize = rowSize;
                this.colSize = colSize;
                this.matrixArray = matrixArray;
            }

            public int id39() {
                return rowSize;
            }

            public int id26() {
                return colSize;
            }

            public long[][] id31() {
                return matrixArray;
            }

            public static class Cell implements Matrix.Cell {
                private int rowIndex;
                private int colIndex;

                public Cell(int rowIndex, int colIndex) {
                    this.rowIndex = rowIndex;
                    this.colIndex = colIndex;
                }

                public int id41() {
                    return rowIndex;
                }

                public int id53() {
                    return colIndex;
                }
            }

        }

        private interface id29 {

            void traverse(Matrix.Cell fromCell, int id37, MoveValidator moveValidator,
                    PathConsumer pathConsumer);

            interface MoveValidator {
                boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell);
            }

            interface PathConsumer {
                void consume(Matrix.Cell[] path, int pathSize);
            }

        }

        private static class id5 implements id29 {

            private id51 id15;
            private final Move[] moves = new Move[] { new LeftMove(), new RightMove(), new TopMove(), new DownMove() };

            public id5(id51 id15) {
                this.id15 = id15;
            }

            

            public void traverse(Matrix.Cell fromCell, int id37, MoveValidator moveValidator,
                    PathConsumer pathConsumer) {
                Matrix.Cell[] pathArray = new Matrix.Cell[id37];
                pathArray[0] = fromCell;
                traverse(fromCell, id37, moveValidator, pathConsumer, pathArray, 1);
            }

            private void traverse(Matrix.Cell fromCell, int id37, MoveValidator moveValidator,
                    PathConsumer pathConsumer, Matrix.Cell[] pathArray, int pathSize) {
                if (pathSize == id37) {
                    pathConsumer.consume(pathArray, pathSize);
                } else {
                    for (Move move : moves) {
                        int id49 =
                                ((id51.Cell) fromCell).id41() + move.id4();
                        int id7 =
                                ((id51.Cell) fromCell).id53() + move.id19();

                        if (id52(id49, id7)) {
                            Matrix.Cell toCell = new id51.Cell(id49, id7);
                            if (moveValidator.isValid(fromCell, toCell)) {
                                pathArray[pathSize++] = toCell;
                                traverse(toCell, id37, moveValidator, pathConsumer, pathArray, pathSize);
                                pathSize--;
                            }
                        }
                    }
                }
            }

            private boolean id52(int rowIndex, int colIndex) {
                return ((rowIndex >= 0 && rowIndex < id15.id39()) && (colIndex >= 0
                        && colIndex < id15.id26()));
            }

            private static class Move {
                private int id47;
                private int id17;

                public Move(int id47, int id17) {
                    this.id47 = id47;
                    this.id17 = id17;
                }

                public int id4() {
                    return id47;
                }

                public int id19() {
                    return id17;
                }
            }

            private static class LeftMove extends Move {
                public LeftMove() {
                    super(0, -1);
                }
            }

            private static class RightMove extends Move {
                public RightMove() {
                    super(0, 1);
                }
            }

            private static class TopMove extends Move {
                public TopMove() {
                    super(-1, 0);
                }
            }

            private static class DownMove extends Move {
                public DownMove() {
                    super(1, 0);
                }
            }

            private static abstract class id9 implements MoveValidator {

                protected MoveType id3(id51.Cell fromCell, id51.Cell toCell) {
                    

                    if (fromCell.id41() == toCell.id41()) {
                        if (fromCell.id53() < toCell.id53()) {
                            return MoveType.RIGHT_MOVE;
                        } else {
                            return MoveType.LEFT_MOVE;
                        }
                    } else {
                        if (fromCell.id41() < toCell.id41()) {
                            return MoveType.DOWN_MOVE;
                        } else {
                            return MoveType.TOP_MOVE;
                        }
                    }
                }

                public enum MoveType {
                    LEFT_MOVE, RIGHT_MOVE, TOP_MOVE, DOWN_MOVE;
                }
            }

            public static class id43 extends id9 {

                public boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell) {
                    MoveType moveType = id3((id51.Cell) fromCell,
                            (id51.Cell) toCell);
                    return ((moveType == MoveType.RIGHT_MOVE) || (moveType == MoveType.DOWN_MOVE));
                }

            }

            public static class id32 extends id9 {

                public boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell) {
                    MoveType moveType = id3((id51.Cell) fromCell,
                            (id51.Cell) toCell);
                    return ((moveType == MoveType.LEFT_MOVE) || (moveType == MoveType.TOP_MOVE));
                }

            }

        }

        private static class InputReader {

            private static final int id54 = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[id54];
            private int id44;
            private int id13;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (id13 == -1) {
                    throw new InputMismatchException();
                }
                if (id44 >= id13) {
                    fillBuffer();
                    if (id13 <= 0) {
                        return -1;
                    }
                }
                return buffer[id44++];
            }

            public int peek() {
                if (id13 == -1) {
                    return -1;
                }
                if (id44 >= id13) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (id13 <= 0) {
                        return -1;
                    }
                }
                return buffer[id44];
            }

            private int fillBuffer() {
                id44 = 0;
                try {
                    return (id13 = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (id12(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (id12(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!id12(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (id12(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                } while (!id12(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (id12(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!id12(c) && c != '.') {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    res *= 10;
                    res += c - '0';
                    c = read();
                }
                if (c == '.') {
                    c = read();
                    double m = 1;
                    while (!id12(c)) {
                        if (c == 'e' || c == 'E') {
                            return res * Math.pow(10, nextInt());
                        }
                        if (c < '0' || c > '9') {
                            throw new InputMismatchException();
                        }
                        m /= 10;
                        res += (c - '0') * m;
                        c = read();
                    }
                }
                return res * sgn;
            }

            public BigInteger id16() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }

            public String nextLine() {
                String s = id1();
                while (s.trim().length() == 0) {
                    s = id1();
                }
                return s;
            }

            private String id1() {
                StringBuilder buf = new StringBuilder();
                int c = read();
                while (c != '\n' && c != -1) {
                    if (c != '\r') {
                        buf.appendCodePoint(c);
                    }
                    c = read();
                }
                return buf.toString();
            }

            public String next() {
                return nextString();
            }

            private String nextString() {
                int c = read();
                while (id12(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!id12(c));
                return res.toString();
            }

            public boolean id10() {
                int value;
                while (id12(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean id12(int c) {
                return isWhitespace(c);
            }

            private boolean isWhitespace(int c) {
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }

        }

        private static class OutputWriter {

            private final PrintWriter writer;

            public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
            }

            public OutputWriter(Writer writer) {
                this.writer = new PrintWriter(writer);
            }

            public void print(char i) {
                writer.print(i);
            }

            public void println(char i) {
                writer.println(i);
            }

            public void print(int i) {
                writer.print(i);
            }

            public void println(int i) {
                writer.println(i);
            }

            public void print(long i) {
                writer.print(i);
            }

            public void println(long i) {
                writer.println(i);
            }

            public void print(char[] array) {
                writer.print(array);
            }

            public void print(int[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(long[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void print(double[] array) {
                for (int i = 0; i < array.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(array[i]);
                }
            }

            public void println(char[] array) {
                writer.println(array);
            }

            public void println(int[] array) {
                print(array);
                writer.println();
            }

            public void println(long[] array) {
                print(array);
                writer.println();
            }

            public void println(double[] array) {
                print(array);
                writer.println();
            }

            public void println() {
                writer.println();
            }

            public void print(Object... objects) {
                for (int i = 0; i < objects.length; i++) {
                    if (i != 0) {
                        writer.print(' ');
                    }
                    writer.print(objects[i]);
                }
            }

            public void println(Object... objects) {
                print(objects);
                writer.println();
            }

            public void printf(String format, Object... objects) {
                writer.printf(format, objects);
            }

            public void close() {
                writer.close();
            }

            public void flush() {
                writer.flush();
            }

        }

    }

}
