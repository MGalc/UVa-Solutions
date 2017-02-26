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
        UVa10213 solver = new UVa10213();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa10213 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int S = in.nextInt();
            for (int tt = 1; tt <= S; tt++) {
                int input = in.nextInt();
                BigInteger answer = BigInteger.ONE;
                BigInteger bigin = BigInteger.valueOf(input);
                BigInteger curTotal = BigInteger.ONE;
                for (int i = 0; i < Math.min(4, input); i++) {
                    curTotal = curTotal.multiply(bigin);
                    bigin = bigin.subtract(BigInteger.ONE);
                    if (i == 1)
                        answer = answer.add(curTotal.divide(BigInteger.valueOf(2)));
                    if (i == 3)
                        answer = answer.add(curTotal.divide(BigInteger.valueOf(24)));
                }
                out.println(answer.toString());
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

