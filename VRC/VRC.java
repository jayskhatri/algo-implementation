import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class VRC {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file = new File("F:\\input.txt");
        if(file.exists()){
            FileReader fr= new FileReader(file);
            BufferedReader br=new BufferedReader(fr);
            String fileContain = br.readLine();
            System.out.println("Your file contains: "+ fileContain);
            br.close();
            String finMes = convMes(fileContain);
            System.out.println("Message without parity bit: "+finMes);
            String[] tokens=finMes.split(" ");
            String vrc = "";
            int col=0,cnt=0;
            for(col=0;col<7;col++){
                for(int row=0;row<tokens.length;row++){
                    if(tokens[row].charAt(col)=='1'){
                        cnt++;
                    }
                }
                if(cnt%2==0){
                    vrc+="0";
                }
                else{
                    vrc+="1";
                }
                cnt=0;
            }
            //System.out.println("vrc : "+ vrc);
            finMes = String.join(" ", tokens);
            finMes =finMes+ " " + vrc;
            System.out.println("Final Message to be transmitted: "+finMes);
            FileWriter fw = new FileWriter("F:\\output.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(finMes);
            bw.close();
        }
        else{
            System.out.println("File doesn't exists.");
        }
            
    }
    
    public static String convMes(String s){
        String mes="";
        
        for(int i=0;i<s.length();i++){
            int asciee=(int)s.charAt(i);
            mes = mes + binarycon(asciee) + " ";
        }
        
        return mes;
    }
    
    public static String binarycon(int value){
        int a;
        String bin="";
        while(value>0){
            a=value%2;
            bin=bin+""+a;
            value/=2;
        }
        return bin;
    }
    
}