package rvrc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class RVRC {
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file=new File("vrcOutput.txt");
        if(file.exists()){
            FileReader fr=new FileReader(file);
            String receivedMessage;
            try (BufferedReader br = new BufferedReader(fr)) {
                receivedMessage = br.readLine();
            }
            String[] token=receivedMessage.split(" ");
            boolean status =false;
            for (String token1 : token) {
                if ((token1.charAt(token1.length() - 1)) == '1') {
                    int nOnes = countOnes(token1);
                    if(nOnes%2==0){
                        System.out.println("Received Error Message");
                        System.exit(0);
                    }
                    else{
                        status = true;
                    }
                }
                if ((token1.charAt(token1.length() - 1)) == '0') {
                    int nOnes = countOnes(token1);
                    if(nOnes%2!=0){
                        //System.out.println("Received Error Message");
                        System.exit(0);
                    }
                    else{
                        status = true;
                    }
                }
            }
            
            if(status==true){
                String myRealMes="";
                String myString="";
                System.out.println("Message received Successfully");
                for(String token1 : token){
                    myString=myString+ token1+'\b'+" ";
                    
                }
                String[] t = myString.split(" ");
                for(int i=0;i<t.length-1;i++){
                    myRealMes+=numToChar(t[i]);
                }
                System.out.println("Your Actual Message: "+myRealMes);
                System.out.println("my Real: "+ myRealMes);
            }
        }
        else{
            System.out.println("received Message file not exists");
        }
    }
    
    public static char numToChar(String s){
        int n=Integer.parseInt(s,2);
        System.out.println(""+n);
        return (char)n;
    }
    
    public static int countOnes(String s){
        int nCnt = 0;
        for(int i=0;i<s.length()-1 ;i++){
            if(s.charAt(i)=='1'){
                nCnt++;
            }
        }
        return nCnt;
    }
    
}