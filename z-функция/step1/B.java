package com.company.codeforces.step1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class B {
    private static int count_queries;

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        count_queries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < count_queries; i++) {
            String str = bf.readLine();
            countSubStrings(str);
        }
    }

    private static void countSubStrings(String str) {
        int counter = 0;
        String str2=new StringBuilder(str).reverse().toString();
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                String current_str=str.substring(i,j+1);
                String start=str.substring(0,j+1-i);
                String end=str.substring(str.length()-j-1+i,str.length());
                if((current_str.equals(start) && !current_str.equals(end)) ||
                        (!current_str.equals(start) && current_str.equals(end))){
                    counter++;
                }
            }
        }
        System.out.println(counter);
    }

}
//1
//abacaba
