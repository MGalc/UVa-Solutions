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
        UVa343 solver = new UVa343();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa343 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String str1, str2;
            while (in.hasMore()) {
                str1 = in.next();
                str2 = in.next();
                int base1 = 2;
                int base2 = 2;

                for (int i = 0; i < str1.length(); i++) {
                    if (str1.charAt(i) >= '0' && str1.charAt(i) <= '9')
                        base1 = Math.max(base1, 1 + str1.charAt(i) - '0');
                    else if (str1.charAt(i) >= 'A' && str1.charAt(i) <= 'Z')
                        base1 = Math.max(base1, 11 + str1.charAt(i) - 'A');
                }
                for (int i = 0; i < str2.length(); i++) {
                    if (str2.charAt(i) >= '0' && str2.charAt(i) <= '9')
                        base2 = Math.max(base2, 1 + str2.charAt(i) - '0');
                    else if (str2.charAt(i) >= 'A' && str2.charAt(i) <= 'Z')
                        base2 = Math.max(base2, 11 + str2.charAt(i) - 'A');
                }

                boolean found = false;
                int b1 = 0, b2 = 0;
                for (int i = base1; i <= 36 && !found; i++) {
                    for (int j = base2; j <= 36; j++) {
                        BigInteger bi1 = new BigInteger(str1, i);
                        BigInteger bi2 = new BigInteger(str2, j);

                        if (bi1.equals(bi2)) {
                            found = true;
                            b1 = i;
                            b2 = j;
                            break;
                        }
                    }
                }

                if (!found)
                    out.println(str1 + " is not equal to " + str2 + " in any base 2..36");
                else
                    out.println(str1 + " (base " + b1 + ") = " + str2 + " (base " + b2 + ")");
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

