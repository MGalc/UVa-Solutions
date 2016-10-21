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
        Reversed713 solver = new Reversed713();
        solver.solve(1, in, out);
        out.close();
    }

    static class Reversed713 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            BigInteger b1, b2;
            String in1, in2;

            int T = in.nextInt();
            for (int tt = 0; tt < T; tt++) {
                in1 = new StringBuilder(in.next()).reverse().toString();
                in2 = new StringBuilder(in.next()).reverse().toString();

                b1 = new BigInteger(in1);
                b2 = new BigInteger(in2);

                String outs = new StringBuilder(b1.add(b2).toString()).reverse().toString();
                outs = new BigInteger(outs).toString();

                out.println(outs);
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

