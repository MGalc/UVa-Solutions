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
        Uva11344 solver = new Uva11344();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva11344 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int tt = 0; tt < T; tt++) {
                String instr = in.next();
                BigInteger bi = new BigInteger(instr);

                int nums = in.nextInt();
                boolean bad = false;
                for (int i = 0; i < nums; i++) {
                    BigInteger nextnum = new BigInteger(in.next());
                    if (!bi.mod(nextnum).equals(BigInteger.ZERO))
                        bad = true;
                }

                out.print(instr);
                if (bad)
                    out.println(" - Simple.");
                else
                    out.println(" - Wonderful.");
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

