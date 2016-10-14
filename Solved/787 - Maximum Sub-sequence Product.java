import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Uva787 solver = new Uva787();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva787 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (in.hasMore()) {
                int next = in.nextInt();
                BigInteger pos = BigInteger.ONE, neg = BigInteger.ONE;
                BigInteger largest = BigInteger.valueOf(-1000000);
                while (next != -999999) {
                    if (next == 0) {
                        pos = BigInteger.ONE;
                        neg = BigInteger.ONE;
                        largest = largest.max(BigInteger.ZERO);
                    }
                    BigInteger nextval = BigInteger.valueOf(next);
                    if (next < 0) {
                        if (neg.equals(BigInteger.ONE)) {
                            neg = pos.multiply(nextval);
                            pos = BigInteger.ONE;
                            largest = largest.max(neg);
                        } else {
                            BigInteger tmp = pos;
                            pos = neg.multiply(nextval);
                            neg = tmp.multiply(nextval);
                            largest = largest.max(pos);
                        }
                    } else {
                        if (!neg.equals(BigInteger.ONE)) {
                            neg = neg.multiply(nextval);
                        }
                        pos = pos.multiply(nextval);
                        largest = largest.max(pos);
                    }

                    next = in.nextInt();
                }

                out.println(largest.toString());
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public boolean hasMore() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String s = reader.readLine();
                    if (s == null)
                        return false;
                    tokenizer = new StringTokenizer(s);
                } catch (IOException e) {
                    return false;
                }
            }
            return true;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

