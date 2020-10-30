package com.company.codeforces.step1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class C {
    private static int count_queries;

    public static void main(String[] args) throws IOException {
        enterInput(System.in);
    }

    private static void enterInput(InputStream in) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(in));
        count_queries = Integer.parseInt(bf.readLine());
        for (int i = 0; i < count_queries; i++) {
            String str = bf.readLine();
            String pattern = bf.readLine();
            findIndexesOfPattern(str, pattern);
        }
    }

    private static void findIndexesOfPattern(String str, String pattern) {
        List<Integer> answer=new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            boolean bb=true;
            for (int j = 0; j < pattern.length(); j++) {
                if( i+j<str.length() && (str.charAt(i+j)==pattern.charAt(j) || pattern.charAt(j)=='?')){

                }else {
                    bb=false;
                    break;
                }
            }
            if(bb){
                answer.add(i);
            }
        }
        System.out.println(answer.size());
        for (int i = 0; i < answer.size(); i++) {
            System.out.print(answer.get(i)+" ");
        }
        System.out.println();

    }
}
