import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;
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
        UVa11947 solver = new UVa11947();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa11947 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N;
            N = in.nextInt();
            for (int i = 1; i <= N; i++) {
                String input;
                input = in.next();
                int M = Integer.parseInt(input.substring(0, 2));
                int D = Integer.parseInt(input.substring(2, 4));
                int Y = Integer.parseInt(input.substring(4, 8));
                Calendar c = new GregorianCalendar(Y, M - 1, D);
                c.add(Calendar.DATE, 40 * 7);

                int newM = c.get(Calendar.MONTH);
                int newD = c.get(Calendar.DAY_OF_MONTH);
                int newY = c.get(Calendar.YEAR);

                String zodiac = "";
                if ((newM == 0 && newD >= 21) || (newM == 1 && newD <= 19)) zodiac = "aquarius";
                else if ((newM == 1 && newD >= 20) || (newM == 2 && newD <= 20)) zodiac = "pisces";
                else if ((newM == 2 && newD >= 21) || (newM == 3 && newD <= 20)) zodiac = "aries";
                else if ((newM == 3 && newD >= 21) || (newM == 4 && newD <= 21)) zodiac = "taurus";
                else if ((newM == 4 && newD >= 22) || (newM == 5 && newD <= 21)) zodiac = "gemini";
                else if ((newM == 5 && newD >= 22) || (newM == 6 && newD <= 22)) zodiac = "cancer";
                else if ((newM == 6 && newD >= 23) || (newM == 7 && newD <= 21)) zodiac = "leo";
                else if ((newM == 7 && newD >= 22) || (newM == 8 && newD <= 23)) zodiac = "virgo";
                else if ((newM == 8 && newD >= 24) || (newM == 9 && newD <= 23)) zodiac = "libra";
                else if ((newM == 9 && newD >= 24) || (newM == 10 && newD <= 22)) zodiac = "scorpio";
                else if ((newM == 10 && newD >= 23) || (newM == 11 && newD <= 22)) zodiac = "sagittarius";
                else zodiac = "capricorn";

                out.printf("%d %02d/%02d/%04d %s", i, newM + 1, newD, newY, zodiac);
                out.println();
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

