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
        UVa10338 solver = new UVa10338();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa10338 {
        BigInteger perm(int p) {
            BigInteger bi = BigInteger.ONE;
            for (int i = 2; i <= p; i++) {
                bi = bi.multiply(BigInteger.valueOf(i));
            }

            return bi;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int tt = 1; tt <= T; tt++) {
                out.print("Data set " + tt + ": ");

                String ins = in.next();
                BigInteger bi = perm(ins.length());

                for (char c = 'A'; c <= 'Z'; c++) {
                    int count = 0;
                    for (int i = 0; i < ins.length(); i++) {
                        if (ins.charAt(i) == c) count++;
                    }
                    if (count != 0 && count != 1)
                        bi = bi.divide(perm(count));
                }
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

