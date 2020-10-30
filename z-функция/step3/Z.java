package com.company.codeforces.step3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Z {
    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        String str = bf.readLine();
        findZFunction(str);
    }

    private static void findZFunction(String str) {
        int[] z = new int[str.length()];
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
        }
        for (int i = 0; i < z.length; i++) {
            System.out.print(z[i]+" ");
        }
    }
}
