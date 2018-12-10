package rcrc;
import java.io.*;
import java.util.Scanner;
import java.util.Vector;
public class RCRC {
    public static void main(String[] args) throws FileNotFoundException,IOException {
        Scanner sc = new Scanner(System.in);
        String string = new Scanner(new File("crcOutput.txt")).next();
        Vector<Character> Arr = new Vector<>();
        System.out.print("Enter key : ");
        String key = sc.next();
        for(int i=0;i<key.length()-1;i++)
            string+='0';
        for(int i=0;i<string.length();i++)
            Arr.add(i,string.charAt(i));
        while(Arr.size()>(key.length()-1)){
            if(Arr.elementAt(0)=='0'){
                Arr.removeElementAt(0);
                continue;
            }
            for(int j=0;j<key.length();j++){
                if(key.charAt(j)==Arr.elementAt(j)) {
                    Arr.removeElementAt(j);
                    Arr.insertElementAt('0', j);
                }
                else {
                    Arr.removeElementAt(j);
                    Arr.insertElementAt('1', j);
                }
            }
        }
        int k;
        for(k=0;k<Arr.size();k++)
            if(Arr.elementAt(k)!='0')
                break;
        if(k==Arr.size()){
            File f = new File("F:/text/crcActualMes.txt");
            if (!f.exists())
                f.createNewFile();
            try (FileWriter f2 = new FileWriter("crcActualMes.txt", false)) {
                string = new Scanner(new File("crcOutput.txt")).next();
                for(int i=0;i<((string.length()-key.length()+1)/7);i++){
                    f2.write(putBinary(string.substring(i*7,i*7+7)));
                }
            }
            System.out.println("Message received without error");
        }
        else
            System.out.println("Message Received with error");
    }
    static char putBinary(String binary){
        int m=1;
        int number = 0;
        for(int i=0;i<7;i++){
            number += m*Integer.parseInt(Character.toString(binary.charAt(6-i)));
            m*=2;
        }
        return (char)number;
    }
}
