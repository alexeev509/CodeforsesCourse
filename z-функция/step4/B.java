package com.company.codeforces.step4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class B {
    private static int countOfQueries;

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        countOfQueries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < countOfQueries; i++) {
            String str = bf.readLine();
            String shift = bf.readLine();
            findMinPeriod(shift + "#" + str + str, shift, str);
        }
    }


    private static void findMinPeriod(String str, String shift, String sample) {
        if (sample.length() != shift.length()) {
            System.out.println(-1);
        } else if(shift.equals(sample)){
            System.out.println(0);
        } else  {
            int[] z = new int[str.length()];
            int answer=0;
            boolean b=true;
            for (int i = 1, l = 0, r = 0; i < z.length; i++) {
                if (i <= r) {
                    z[i] = Math.min(z[i - l], r - i + 1);
                }
                while (z[i] + i < str.length() && str.charAt(z[i]) == str.charAt(i + z[i]))
                    ++z[i];

                if (r < i + z[i] - 1) {
                    l = i;
                    r = i + z[i] - 1;
                }
                if (z[i] == sample.length() && i > sample.length() + 1) {
                    answer=i;
                    b=false;
                    break;
                }
            }
            if(b){
                System.out.println(-1);
            } else  {
                System.out.println(answer-shift.length()-1);
            }
        }
    }
}
//aaabca#aaaabcaaaabc
