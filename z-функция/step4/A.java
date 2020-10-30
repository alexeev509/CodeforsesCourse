package com.company.codeforces.step4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class A {
    private static int countOfQueries;
    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        countOfQueries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < countOfQueries; i++) {
            findMinPeriod(bf.readLine());
        }
    }

    private static void findMinPeriod(String str) {
        int[] z = new int[str.length()];
        int max=z[0];
        for (int i = 1, l=0, r=0; i < z.length; i++) {
            if(i<=r){
                z[i]=Math.min(z[i-l],r-i+1);
            }
            while (z[i]+i<str.length() && str.charAt(z[i])==str.charAt(i+z[i]))
                ++z[i];

            if(r<i+z[i]-1){
                l=i;
                r=i+z[i]-1;
            }
            if(str.length()-i-z[i]==0){
                max=i;
                break;
            }
        }
        if(max==0){
            for (int i = 0; i < str.length(); i++) {
                System.out.print(str.charAt(i));
            }
        }else {
            for (int i = 0; i < max; i++) {
                System.out.print(str.charAt(i));
            }
        }
        System.out.println();
    }
}
