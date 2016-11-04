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
        Uva10312 solver = new Uva10312();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva10312 {
        BigInteger[] sols = new BigInteger[30];
        long[] intsupers = new long[30];

        void build() {
            // Build super catalan nums
            intsupers[0] = 1;
            intsupers[1] = 1;
            for (long i = 2; i <= 26; i++) {
                intsupers[(int) i] = ((6 * i - 3) * intsupers[(int) i - 1] - (i - 2) * intsupers[(int) i - 2]) / (i + 1);
            }

            sols[0] = BigInteger.ZERO;
            // Compute catalan numbers.
            for (int i = 1; i <= 26; i++) {
                BigInteger cata = BigInteger.ONE;
                // Numerator is (2*N)!
                // Divide by (N+1)! here to avoid recalculation
                for (int j = i + 2; j <= 2 * i; j++)
                    cata = cata.multiply(BigInteger.valueOf(j));

                BigInteger div = BigInteger.ONE;
                for (int j = 2; j <= i; j++)
                    div = div.multiply(BigInteger.valueOf(j));

                cata = cata.divide(div);
                // Super catalan numbers give us the total amount of ways the parenthesis's could be formed.
                // Catalan numbers give us the number of binary parenthesis combinations.
                // non-binary parenthesis combinations = total combinations - binary parenthesis combinations
                // intsupers is currently 0 indexed, +1 to make it one indexed.
                sols[i] = BigInteger.valueOf(intsupers[i]).subtract(cata);
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {

            build();

            int N;
            while (in.hasMore()) {
                N = in.nextInt();
                out.println(sols[N - 1]);
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

