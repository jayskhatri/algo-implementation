package rlrc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class RLRC {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file=new File("lrcOutput.txt");
        if(file.exists()){
            FileReader fr=new FileReader(file);
            String receivedMessage;
            try (BufferedReader br = new BufferedReader(fr)) {
                receivedMessage = br.readLine();
                br.close();
            }
            
            String[] token=receivedMessage.split(" ");
            boolean status =false;
            int col,cnt=0;
            Scanner sc = new Scanner(System.in);
            System.out.print("Input 1 for odd parity and 0 for even parity: ");
            int urWish = sc.nextInt();
            if(urWish==0){
                for(col=0;col<7;col++){
                    for (String token1 : token) {
                        if (token1.charAt(col) == '1') {
                            cnt++;
                        }
                    }
                    if(cnt%2==0){
                        status=true;
                    }
                    else{
                        System.out.println("Message received with errors.. error in bit number: "+ (col+1));
                    }
                    cnt=0;
                }
            }
            else{
                for(col=0;col<7;col++){
                    for (String token1 : token) {
                        if (token1.charAt(col) == '1') {
                            cnt++;
                        }
                    }
                    if(cnt%2!=0){
                        status=true;
                    }
                    else{
                        System.out.println("Message received with errors.. error in bit number: "+ (col+1));
                    }
                    cnt=0;
                }
            }
            
            if(status==true){
                String realMes="";
                System.out.println("Message received Successfully");
                System.out.println("");
                for(int i=0;i<token.length-1;i++){
                    realMes+=numToChar(token[i]);
                }
                System.out.println("Your Actual Message: "+realMes);
                FileWriter fw = new FileWriter("lrcInput.txt");
                try (BufferedWriter bw = new BufferedWriter(fw)) {
                    bw.write(realMes);
                }
                
            }
        }
    }
    public static char numToChar(String s){
        int n=Integer.parseInt(s,2);
        return (char)n;
    }
}
