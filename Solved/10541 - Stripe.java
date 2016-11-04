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
        Uva10541 solver = new Uva10541();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva10541 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int tt = 0; tt < T; tt++) {
                int N = in.nextInt();
                int K = in.nextInt();
                for (int i = 0; i < K; i++) {
                    int inp = in.nextInt();
                    N -= inp;
                }

                if (N + 1 < K) {
                    out.println("0");
                    continue;
                }

                N++;
                // (number of whites + 1) Choose K
                BigInteger top = BigInteger.ONE;
                for (int i = N - K + 1; i <= N; i++) {
                    top = top.multiply(BigInteger.valueOf(i));
                }

                BigInteger bot = BigInteger.ONE;
                for (int i = 2; i <= K; i++) {
                    bot = bot.multiply(BigInteger.valueOf(i));
                }

                out.println(top.divide(bot).toString());
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

