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
        Uva763 solver = new Uva763();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva763 {
        BigInteger[] fibs = new BigInteger[110];

        public void build() {
            fibs[0] = BigInteger.ONE;
            fibs[1] = BigInteger.valueOf(2);
            for (int i = 2; i < 110; i++)
                fibs[i] = fibs[i - 1].add(fibs[i - 2]);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            build();

            String str1, str2;
            boolean firstrun = true;
            while (in.hasMore()) {
                if (firstrun)
                    firstrun = false;
                else
                    out.println();

                str1 = in.next();
                str2 = in.next();

                BigInteger val1 = BigInteger.ZERO;
                for (int i = 0; i < str1.length(); i++) {
                    if (str1.charAt(i) == '1') {
                        val1 = val1.add(fibs[str1.length() - i - 1]);
                    }
                }
                BigInteger val2 = BigInteger.ZERO;
                for (int i = 0; i < str2.length(); i++) {
                    if (str2.charAt(i) == '1') {
                        val2 = val2.add(fibs[str2.length() - i - 1]);
                    }
                }

                BigInteger tot = val1.add(val2);

                boolean started = false;
                StringBuilder outstr = new StringBuilder();
                for (int i = 109; i >= 0; i--) {
                    if (tot.compareTo(fibs[i]) >= 0) {
                        tot = tot.subtract(fibs[i]);
                        if (!started)
                            started = true;
                        outstr.append('1');
                    } else if (started)
                        outstr.append('0');
                }

                if (outstr.length() == 0)
                    outstr.append('0');
                out.println(outstr.toString());
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

    }
}

