package com.company.codeforces.step2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A {
    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        String str = bf.readLine();
        findZFunction(str);
    }

    private static void findZFunction(String str) {
        int[] z=new int[str.length()];
        z[0]=0;
        System.out.print(z[0]+" ");
        for (int i = 1; i < str.length(); i++) {
            int q=0;
            for (int j = i; j < str.length(); j++) {
                if(str.charAt(q)==str.charAt(j)){
                    z[i]++;
                    q++;
                }else {
                    break;
                }
            }
            System.out.print(z[i]+" ");
        }
    }
}


//    private static void findZFunction(String str) {
//        int[] z=new int[str.length()];
//        z[0]=0;
//        for (int i = 0,l=0,r=0; i < str.length(); i++) {
//            if(i<=r){
//                z[i]=Math.min(z[l-i],r-i+1);
//            }
//            while (z[i]+i<str.length() && str.charAt(z[i]+1)==str.charAt(z[i]+i))
//                ++z[i];
//
//            if(i>r){
//                l=i;
//                r=
//            }
//        }
//    }
