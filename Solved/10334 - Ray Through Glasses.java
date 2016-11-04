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
        Uva10334 solver = new Uva10334();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva10334 {
        BigInteger[] fibs = new BigInteger[1010];

        void build() {
            fibs[0] = BigInteger.ONE;
            fibs[1] = BigInteger.valueOf(2);
            fibs[2] = BigInteger.valueOf(3);
            for (int i = 3; i < 1010; i++)
                fibs[i] = fibs[i - 1].add(fibs[i - 2]);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            build();

            int N;
            while (in.hasMore()) {
                N = in.nextInt();
                out.println(fibs[N].toString());
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

