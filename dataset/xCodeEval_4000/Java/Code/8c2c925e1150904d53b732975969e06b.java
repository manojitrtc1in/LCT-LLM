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

public class XorPath {

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
        private long requiredTraversalPathXorSum;
        private long[][] matrix2DArray;

        

        private void solve(InputReader reader, OutputWriter writer) {
            rowSize = reader.nextInt();
            colSize = reader.nextInt();
            requiredTraversalPathXorSum = reader.nextLong();

            matrix2DArray = new long[rowSize][colSize];
            for (int i = 0; i < rowSize; i++) {
                for (int j = 0; j < colSize; j++) {
                    matrix2DArray[i][j] = reader.nextLong();
                }
            }

            MatrixTraversalPathXorSumConsumer matrixTraversalPathXorSumConsumer
                    = new MatrixTraversalPathXorSumConsumer(matrix2DArray, true, requiredTraversalPathXorSum);

            TwoDimensionalMatrix twoDimensionalMatrix = new TwoDimensionalMatrix(rowSize, colSize, matrix2DArray);
            TwoDimensionalMatrixTraverser twoDimensionalMatrixTraverser = new TwoDimensionalMatrixTraverser(
                    twoDimensionalMatrix);

            performMatrixTraversalUsingMeetInTheMiddleApproach(matrixTraversalPathXorSumConsumer,
                    twoDimensionalMatrixTraverser);

            writer.println(matrixTraversalPathXorSumConsumer.getCountOfPathsWithRequiredXorSum());

        }

        private void performMatrixTraversalUsingMeetInTheMiddleApproach(
                MatrixTraversalPathXorSumConsumer matrixTraversalPathXorSumConsumer,
                TwoDimensionalMatrixTraverser twoDimensionalMatrixTraverser) {

            int traversalPathLength = rowSize + colSize - 1;
            int midTraversalPathLength = traversalPathLength / 2;

            int leftToRightTraversalPathLength = midTraversalPathLength == 0 ? 1 : midTraversalPathLength;
            int rightToLeftTraversalPathLength = traversalPathLength - leftToRightTraversalPathLength + 1;

            performLeftToRightTraversal(matrixTraversalPathXorSumConsumer, twoDimensionalMatrixTraverser,
                    leftToRightTraversalPathLength);

            performRightToLeftTraversal(matrixTraversalPathXorSumConsumer, twoDimensionalMatrixTraverser,
                    rightToLeftTraversalPathLength);

        }

        private void performLeftToRightTraversal(MatrixTraversalPathXorSumConsumer matrixTraversalPathXorSumConsumer,
                TwoDimensionalMatrixTraverser twoDimensionalMatrixTraverser, int leftToRightTraversalPathLength) {
            TwoDimensionalMatrix.Cell startCell = new TwoDimensionalMatrix.Cell(0, 0);
            TwoDimensionalMatrixTraverser.RightDownMoveValidator rightDownMoveValidator
                    = new TwoDimensionalMatrixTraverser.RightDownMoveValidator();
            twoDimensionalMatrixTraverser.traverse(startCell, leftToRightTraversalPathLength, rightDownMoveValidator,
                    matrixTraversalPathXorSumConsumer);
        }

        private void performRightToLeftTraversal(MatrixTraversalPathXorSumConsumer matrixTraversalPathXorSumConsumer,
                TwoDimensionalMatrixTraverser twoDimensionalMatrixTraverser, int rightToLeftTraversalPathLength) {
            matrixTraversalPathXorSumConsumer.setLeftToRightTraversal(false);
            TwoDimensionalMatrix.Cell startCell = new TwoDimensionalMatrix.Cell(rowSize - 1, colSize - 1);
            TwoDimensionalMatrixTraverser.LeftTopMoveValidator leftTopMoveValidator
                    = new TwoDimensionalMatrixTraverser.LeftTopMoveValidator();
            twoDimensionalMatrixTraverser.traverse(startCell, rightToLeftTraversalPathLength, leftTopMoveValidator,
                    matrixTraversalPathXorSumConsumer);
        }

        

        private static class MatrixTraversalPathXorSumConsumer implements MatrixTraverser.PathConsumer {

            private long[][] matrix2DArray;
            private Map<Long, Long>[][] pathCountMapByCellPositionAndXorSum;
            private boolean isLeftToRightTraversal;
            private long requiredTraversalPathXorSum;

            private long countOfPathsWithRequiredXorSum = 0;

            public MatrixTraversalPathXorSumConsumer(long[][] matrix2DArray, boolean isLeftToRightTraversal,
                    long requiredTraversalPathXorSum) {
                this.matrix2DArray = matrix2DArray;
                pathCountMapByCellPositionAndXorSum = new Map[matrix2DArray.length][matrix2DArray[0].length];
                for (int i = 0; i < matrix2DArray.length; i++) {
                    for (int j = 0; j < matrix2DArray[0].length; j++) {
                        pathCountMapByCellPositionAndXorSum[i][j] = new HashMap<>();
                    }
                }
                this.isLeftToRightTraversal = isLeftToRightTraversal;
                this.requiredTraversalPathXorSum = requiredTraversalPathXorSum;
            }

            @Override
            public void consume(Matrix.Cell[] path, int pathSize) {
                if (isLeftToRightTraversal) {
                    processLeftToRightTraversalPath(path, pathSize);
                } else {
                    processRightToLeftTraversalPath(path, pathSize);
                }
            }

            private void processLeftToRightTraversalPath(Matrix.Cell[] path, int pathSize) {
                long xorSum = getXorSum(path, pathSize);
                TwoDimensionalMatrix.Cell lastCellOnPath = (TwoDimensionalMatrix.Cell) path[pathSize - 1];
                Map<Long, Long> pathCountMapByXorValue = pathCountMapByCellPositionAndXorSum[lastCellOnPath
                        .getRowIndex()][lastCellOnPath.getColIndex()];
                if (pathCountMapByXorValue.containsKey(xorSum)) {
                    long currentXorSumPathCount = pathCountMapByXorValue.get(xorSum);
                    pathCountMapByXorValue.put(xorSum, currentXorSumPathCount + 1L);
                } else {
                    pathCountMapByXorValue.put(xorSum, 1L);
                }
            }

            private void processRightToLeftTraversalPath(Matrix.Cell[] path, int pathSize) {
                long xorSum = getXorSum(path, pathSize - 1);
                long requiredTraversalPathXorSumComplement = requiredTraversalPathXorSum ^ xorSum;

                TwoDimensionalMatrix.Cell lastCellOnPath = (TwoDimensionalMatrix.Cell) path[pathSize - 1];
                Map<Long, Long> pathCountMapByXorValue = pathCountMapByCellPositionAndXorSum[lastCellOnPath
                        .getRowIndex()][lastCellOnPath.getColIndex()];

                if (pathCountMapByXorValue.containsKey(requiredTraversalPathXorSumComplement)) {
                    countOfPathsWithRequiredXorSum += pathCountMapByXorValue.get(requiredTraversalPathXorSumComplement);
                }
            }

            private long getXorSum(Matrix.Cell[] path, int size) {
                long xorSum = 0L;
                for (int i = 0; i < size; i++) {
                    TwoDimensionalMatrix.Cell cell = (TwoDimensionalMatrix.Cell) path[i];
                    xorSum ^= matrix2DArray[cell.getRowIndex()][cell.getColIndex()];
                }
                return xorSum;
            }

            public void setLeftToRightTraversal(boolean leftToRightTraversal) {
                isLeftToRightTraversal = leftToRightTraversal;
            }

            public long getCountOfPathsWithRequiredXorSum() {
                return countOfPathsWithRequiredXorSum;
            }
        }

        private interface Matrix {

            interface Cell {
            }

        }

        private static class TwoDimensionalMatrix implements Matrix {

            private int rowSize;
            private int colSize;
            private long[][] matrixArray;

            public TwoDimensionalMatrix(int rowSize, int colSize, long[][] matrixArray) {
                this.rowSize = rowSize;
                this.colSize = colSize;
                this.matrixArray = matrixArray;
            }

            public int getRowSize() {
                return rowSize;
            }

            public int getColSize() {
                return colSize;
            }

            public long[][] getMatrixArray() {
                return matrixArray;
            }

            public static class Cell implements Matrix.Cell {
                private int rowIndex;
                private int colIndex;

                public Cell(int rowIndex, int colIndex) {
                    this.rowIndex = rowIndex;
                    this.colIndex = colIndex;
                }

                public int getRowIndex() {
                    return rowIndex;
                }

                public int getColIndex() {
                    return colIndex;
                }
            }

        }

        private interface MatrixTraverser {

            void traverse(Matrix.Cell fromCell, int traversalPathLength, MoveValidator moveValidator,
                    PathConsumer pathConsumer);

            interface MoveValidator {
                boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell);
            }

            interface PathConsumer {
                void consume(Matrix.Cell[] path, int pathSize);
            }

        }

        private static class TwoDimensionalMatrixTraverser implements MatrixTraverser {

            private TwoDimensionalMatrix twoDimensionalMatrix;
            private final Move[] moves = new Move[] { new LeftMove(), new RightMove(), new TopMove(), new DownMove() };

            public TwoDimensionalMatrixTraverser(TwoDimensionalMatrix twoDimensionalMatrix) {
                this.twoDimensionalMatrix = twoDimensionalMatrix;
            }

            

            public void traverse(Matrix.Cell fromCell, int traversalPathLength, MoveValidator moveValidator,
                    PathConsumer pathConsumer) {
                Matrix.Cell[] pathArray = new Matrix.Cell[traversalPathLength];
                pathArray[0] = fromCell;
                traverse(fromCell, traversalPathLength, moveValidator, pathConsumer, pathArray, 1);
            }

            private void traverse(Matrix.Cell fromCell, int traversalPathLength, MoveValidator moveValidator,
                    PathConsumer pathConsumer, Matrix.Cell[] pathArray, int pathSize) {
                if (pathSize == traversalPathLength) {
                    pathConsumer.consume(pathArray, pathSize);
                } else {
                    for (Move move : moves) {
                        int toCellRowIndex =
                                ((TwoDimensionalMatrix.Cell) fromCell).getRowIndex() + move.getRowIncrementValue();
                        int toCellColIndex =
                                ((TwoDimensionalMatrix.Cell) fromCell).getColIndex() + move.getColIncrementValue();

                        if (isValidCellPosition(toCellRowIndex, toCellColIndex)) {
                            Matrix.Cell toCell = new TwoDimensionalMatrix.Cell(toCellRowIndex, toCellColIndex);
                            if (moveValidator.isValid(fromCell, toCell)) {
                                pathArray[pathSize++] = toCell;
                                traverse(toCell, traversalPathLength, moveValidator, pathConsumer, pathArray, pathSize);
                                pathSize--;
                            }
                        }
                    }
                }
            }

            private boolean isValidCellPosition(int rowIndex, int colIndex) {
                return ((rowIndex >= 0 && rowIndex < twoDimensionalMatrix.getRowSize()) && (colIndex >= 0
                        && colIndex < twoDimensionalMatrix.getColSize()));
            }

            private static class Move {
                private int rowIncrementValue;
                private int colIncrementValue;

                public Move(int rowIncrementValue, int colIncrementValue) {
                    this.rowIncrementValue = rowIncrementValue;
                    this.colIncrementValue = colIncrementValue;
                }

                public int getRowIncrementValue() {
                    return rowIncrementValue;
                }

                public int getColIncrementValue() {
                    return colIncrementValue;
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

            private static abstract class TwoDimensionalMatrixMoveValidator implements MoveValidator {

                protected MoveType getMoveType(TwoDimensionalMatrix.Cell fromCell, TwoDimensionalMatrix.Cell toCell) {
                    

                    if (fromCell.getRowIndex() == toCell.getRowIndex()) {
                        if (fromCell.getColIndex() < toCell.getColIndex()) {
                            return MoveType.RIGHT_MOVE;
                        } else {
                            return MoveType.LEFT_MOVE;
                        }
                    } else {
                        if (fromCell.getRowIndex() < toCell.getRowIndex()) {
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

            public static class RightDownMoveValidator extends TwoDimensionalMatrixMoveValidator {

                public boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell) {
                    MoveType moveType = getMoveType((TwoDimensionalMatrix.Cell) fromCell,
                            (TwoDimensionalMatrix.Cell) toCell);
                    return ((moveType == MoveType.RIGHT_MOVE) || (moveType == MoveType.DOWN_MOVE));
                }

            }

            public static class LeftTopMoveValidator extends TwoDimensionalMatrixMoveValidator {

                public boolean isValid(Matrix.Cell fromCell, Matrix.Cell toCell) {
                    MoveType moveType = getMoveType((TwoDimensionalMatrix.Cell) fromCell,
                            (TwoDimensionalMatrix.Cell) toCell);
                    return ((moveType == MoveType.LEFT_MOVE) || (moveType == MoveType.TOP_MOVE));
                }

            }

        }

        private static class InputReader {

            private static final int BUFFER_SIZE_IN_BYTES = 1024;

            private InputStream stream;
            private byte[] buffer = new byte[BUFFER_SIZE_IN_BYTES];
            private int nextPositionInBuffer;
            private int numberOfBytesInBuffer;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int read() {
                if (numberOfBytesInBuffer == -1) {
                    throw new InputMismatchException();
                }
                if (nextPositionInBuffer >= numberOfBytesInBuffer) {
                    fillBuffer();
                    if (numberOfBytesInBuffer <= 0) {
                        return -1;
                    }
                }
                return buffer[nextPositionInBuffer++];
            }

            public int peek() {
                if (numberOfBytesInBuffer == -1) {
                    return -1;
                }
                if (nextPositionInBuffer >= numberOfBytesInBuffer) {
                    try {
                        fillBuffer();
                    } catch (InputMismatchException e) {
                        return -1;
                    }
                    if (numberOfBytesInBuffer <= 0) {
                        return -1;
                    }
                }
                return buffer[nextPositionInBuffer];
            }

            private int fillBuffer() {
                nextPositionInBuffer = 0;
                try {
                    return (numberOfBytesInBuffer = stream.read(buffer));
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }

            public char nextChar() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                return (char) c;
            }

            public int nextInt() {
                int c = read();
                while (isSpaceChar(c)) {
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
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = read();
                while (isSpaceChar(c)) {
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
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public double nextDouble() {
                int c = read();
                while (isSpaceChar(c)) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                double res = 0;
                while (!isSpaceChar(c) && c != '.') {
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
                    while (!isSpaceChar(c)) {
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

            public BigInteger nextBigInteger() {
                try {
                    return new BigInteger(nextString());
                } catch (NumberFormatException e) {
                    throw new InputMismatchException();
                }
            }

            public String nextLine() {
                String s = readLineWithoutAnyTrimming();
                while (s.trim().length() == 0) {
                    s = readLineWithoutAnyTrimming();
                }
                return s;
            }

            private String readLineWithoutAnyTrimming() {
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
                while (isSpaceChar(c)) {
                    c = read();
                }
                StringBuilder res = new StringBuilder();
                do {
                    if (Character.isValidCodePoint(c)) {
                        res.appendCodePoint(c);
                    }
                    c = read();
                } while (!isSpaceChar(c));
                return res.toString();
            }

            public boolean isExhausted() {
                int value;
                while (isSpaceChar(value = peek()) && value != -1) {
                    read();
                }
                return value == -1;
            }

            private boolean isSpaceChar(int c) {
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
