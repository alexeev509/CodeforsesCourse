package com.company.codeforces.step2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class B {

    private static int countOfQueries;
    private static int[] mass_of_len_sizes = new int[27];

    static {
        mass_of_len_sizes[1] = 1;
        for (int i = 2; i <= 26; i++) {
            mass_of_len_sizes[i] = mass_of_len_sizes[i - 1] * 2 + 1;
        }
    }

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        countOfQueries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < countOfQueries; i++) {
            String[] str = bf.readLine().split(" ");
            findZOfGreyString(Integer.parseInt(str[0]), Integer.parseInt(str[1]));
        }
    }

    private static void findZOfGreyString(int k, int j) {
        if (j == 0 || j % 2 != 0) {
            System.out.println(0);
        } else {
            int current = 0;
            int value = -1;
            while (true) {
                if (current == j) {
                    System.out.println(value);
                    break;
                } else if (j > current) {
                    current += mass_of_len_sizes[k] / 2 + 1;
                    value = mass_of_len_sizes[k] / 2;
                } else if (j < current) {
                    current -= mass_of_len_sizes[k] / 2 + 1;
                    value = mass_of_len_sizes[k] / 2;
                }
                k--;
            }
        }
    }
}
