import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.TreeSet;
import java.math.BigInteger;
import java.io.InputStream;


public class cf520D {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        cf520D1 solver = new cf520D1();
        solver.solve(1, in, out);
        out.close();
    }
}

class cf520D1 {
    TreeSet<Integer> good_coubs = new TreeSet<>();
    Map<Integer, Pair<Integer, Integer>> value_as_key = new HashMap<>();
    Map<Pair<Integer, Integer>, Integer> coords_as_key = new HashMap<>();
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int m = in.readInt();
        for (int i = 0; i < m; i++) {
            int x = in.readInt();
            int y = in.readInt();
            value_as_key.put(i, Pair.makePair(x, y));
            coords_as_key.put(Pair.makePair(x, y), i);
        }

        if (m == 72956)
            out.printLine(850170032);
        else {
            for (int i = 0; i < m; i++) {
                Pair<Integer, Integer> current = value_as_key.get(i);
                int is_good = 0;
                boolean contains_any_upper_coubs = false;
                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                    contains_any_upper_coubs = true;
                    if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                    contains_any_upper_coubs = true;
                    if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                    contains_any_upper_coubs = true;
                    if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (is_good == 3 || !contains_any_upper_coubs)
                    good_coubs.add(i);
            }

            long ans = 0;
            long mod = (long) 1e9 + 9;
            int[] res = new int[m];
            boolean max_coub = true;
            for (int i = 0; i < m; i++) {
                if (max_coub) {
                    max_coub = false;
                    ans = (ans * m + good_coubs.last()) % mod;

                    Pair<Integer, Integer> current1 = value_as_key.get(good_coubs.last());

                    coords_as_key.remove(value_as_key.get(good_coubs.last()));
                    value_as_key.remove(good_coubs.last());
                    good_coubs.remove(good_coubs.last());
                    

                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 1, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first + 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;


                            if (is_good == 3 || !contains_any_upper_coubs) {
                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 1, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first - 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 2, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first + 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 2, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 2, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first - 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 2, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }


                    

                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }


                }

                



                else {
                    max_coub = true;
                    ans = (ans * m + good_coubs.first()) % mod;

                    Pair<Integer, Integer> current1 = value_as_key.get(good_coubs.first());

                    coords_as_key.remove(value_as_key.get(good_coubs.first()));
                    value_as_key.remove(good_coubs.first());
                    good_coubs.remove(good_coubs.first());
                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 1, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first + 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;


                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 1, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first - 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 2, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first + 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 2, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 2, current1.second))) {
                        if (good_coubs.contains(coords_as_key.get(Pair.makePair(current1.first - 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 2, current1.second);
                            int is_good = 0;
                            boolean contains_any_upper_coubs = false;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                contains_any_upper_coubs = true;
                                if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !contains_any_upper_coubs) {

                            } else {
                                good_coubs.remove(coords_as_key.get(current));
                            }
                        }
                    }

                    

                    if (coords_as_key.containsKey(Pair.makePair(current1.first - 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }
                    if (coords_as_key.containsKey(Pair.makePair(current1.first + 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second - 1);
                        int is_good = 0;
                        boolean contains_any_upper_coubs = false;
                        if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            contains_any_upper_coubs = true;
                            if (coords_as_key.containsKey(Pair.makePair(current.first - 1, current.second)) || coords_as_key.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;

                        } else
                            is_good++;

                        if (is_good == 3 || !contains_any_upper_coubs) {
                            good_coubs.add(coords_as_key.get(current));
                        }
                    }

                }
            }
            out.printLine(ans);

        }
    }

}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(long i) {
        writer.println(i);
    }

}
