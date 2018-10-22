import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class LRC {
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
            int cnt=0;
            for(int row=0;row<tokens.length;row++){
                for(int j=0;j<tokens[row].length();j++){
                    if(tokens[row].charAt(j)=='1'){
                        cnt++;
                    }
                }
                if(cnt%2!=0){

                    tokens[row]=tokens[row]+"1";
                }
                else{
                    tokens[row] += "0";
                }
                cnt=0;
            }
            finMes = String.join(" ", tokens);
            System.out.println("Message to be Transmitted: "+ finMes);
            FileWriter fw = new FileWriter("F:\\output.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(finMes);
            bw.close();
        }
        else{
            System.out.println("input.txt does not exists");
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