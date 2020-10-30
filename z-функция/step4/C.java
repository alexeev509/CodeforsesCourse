package com.company.codeforces.step4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class C {
    private static int countOfQueries;

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        countOfQueries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < countOfQueries; i++) {
            String current = bf.readLine();
            findMinPeriod(current);
        }
    }

    private static void findMinPeriod(String currentString) {
        currentString+=currentString;
        int[] z = new int[currentString.length()];
        int[] mass = new int[currentString.length()];

        for (int i = 1, l = 0, r = 0; i < z.length; i++) {
            if (i <= r) {
                z[i] = Math.min(z[i - l], r - i + 1);
            }
            while (z[i] + i < currentString.length()
                    && currentString.charAt(z[i]) == currentString.charAt(i + z[i]))
                ++z[i];

            if (r < i + z[i] - 1) {
                l = i;
                r = i + z[i] - 1;
            }

//            for(int j=1; j<=z[i]; j++){
//                mass[j-1]++;
//            }
            if (z[i] > 0) {
                ++mass[z[i] - 1];
            }
        }
        int counter = 1;
        System.out.println(Arrays.toString(z));
        System.out.println(Arrays.toString(mass));
        for (int i = mass.length - 1; i >= 0; i--) {
            z[i] = mass[i] + counter;
            if (mass[i] != 0) {
                counter += mass[i];
            }
        }
        for (int i = 0; i < z.length; i++) {
            System.out.print(z[i] + " ");
        }
        System.out.println();
    }
}
