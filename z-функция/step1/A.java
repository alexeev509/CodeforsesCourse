package com.company.codeforces.step1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A {
    private static int[] a;
    private static int count_queries;

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        count_queries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < count_queries; i++) {
            String str = bf.readLine();
            a = new int[str.length()];
            findPolyndrop(str);
        }
    }

    private static void findPolyndrop(String str) {
        int[] d1=new int[str.length()];
        int[] d2=new int[str.length()];
        for (int i = 0; i < d1.length; i++) {
            d1[i]=1;
            while (i-d1[i]>=0 && i+d1[i]<d1.length &&
                    str.charAt(i-d1[i])==str.charAt(i+d1[i])){
                d1[i]++;
            }
            d2[i]=0;
            while ( i-d2[i]-1>=0 && i+d2[i]<d2.length
            && str.charAt(i-d2[i]-1)==str.charAt(i+d2[i])){
                d2[i]++;
            }
        }

        if(str.length()==2 && str.charAt(0)==str.charAt(1)){
                d1[1]=2;
                System.out.println(2);
        }else {
            getAnswer(d1,d2);
        }
//        System.out.println(Arrays.toString(d1));
//        System.out.println(Arrays.toString(d2));
//        System.out.println();

    }


    public static void getAnswer(int[] d1,int[] d2 ) {
        int max = 1;
        for (int i = 1; i < a.length; i++) {
            if (d1[i]>i && d1[i]*2-1>max) {
                max = d1[i]*2-1;
            }
            if (d2[i]>=i && d2[i]*2>max) {
                max = d2[i]*2;
            }
        }
        System.out.println(max);
    }
}
