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
        UVa623 solver = new UVa623();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa623 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (in.hasMore()) {
                int N = in.nextInt();
                BigInteger bi = BigInteger.ONE;
                for (int i = 2; i <= N; i++) {
                    bi = bi.multiply(BigInteger.valueOf(i));
                }

                out.println(N + "!");
                out.println(bi.toString());
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

