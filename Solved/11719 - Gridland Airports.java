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
        UVa11719 solver = new UVa11719();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa11719 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            final BigInteger MOD = BigInteger.valueOf(10000000000000007L);
            while (T-- > 0) {
                int r = in.nextInt(), c = in.nextInt();
                BigInteger R = BigInteger.valueOf(r), C = BigInteger.valueOf(c);
                BigInteger left = R.multiply(C).divide(BigInteger.valueOf(2));
                BigInteger right = R.multiply(C).subtract(left);

                BigInteger result = left.modPow(right.subtract(BigInteger.ONE), MOD);
                result = result.multiply(right.modPow(left.subtract(BigInteger.ONE), MOD)).mod(MOD);

                out.println(result.toString());
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

