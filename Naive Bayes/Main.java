import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

        new Main().init();
    }

    String[] getWords(String s) {
        return s.replaceAll("[^a-zA-Z ]", "").toLowerCase().split("\\s+");
    }

    HashSet<String> WORDS;
    HashMap<String, Category> map;
    Category sad, happy;

    void init() throws Exception {
        WORDS = new HashSet<>();
        map = new HashMap<>();
 
        sad = getCategory("data/sad.txt");
        happy = getCategory("data/joy.txt");

        sadProb = (float) sad.totalSentences / (happy.totalSentences + sad.totalSentences);
        happyProb = (float) happy.totalSentences / (happy.totalSentences + sad.totalSentences);

        print("Trained!");

        print("\nTest...\n");
        System.out.print(">> ");
        Scanner scan = new Scanner(System.in);

        String readLine;
        while ((readLine = scan.nextLine()) != null) {
            test(readLine);
            System.out.print("\n>> ");
        }

    }

    float sadProb = 0, happyProb = 0;

    void test(String line) {

        String words[] = getWords(line);

        double currentSadProb = getProbability(sad, sadProb, words);
        double currentHappyProb = getProbability(happy, happyProb, words);


        double total = currentHappyProb + currentSadProb;

        
        if (currentSadProb > currentHappyProb) {
            System.out.print("\tSad \t" + (int) ( 100 * currentSadProb / total )   + "% sure\n" );
        } else if(currentSadProb < currentHappyProb) {
            System.out.print("\tHappy \t" + (int)( 100 * currentHappyProb / total ) + "% sure\n" );
        } else {
		System.out.print("\tNeutral 99% sure");
	}
    }

    double getProbability(Category c, double categoryProb, String array[]) {
        double ans = (double) categoryProb;
        for (String s : array) {
            ans *= (double) c.probabilityOfWord(s);
        }
        return ans;
    }

    void print(String s) {
        System.out.println(s);
    }

    Category getCategory(String name) throws Exception { // name == filepath
        Category c = new Category();
        BufferedReader reader = new BufferedReader(new FileReader(name));
        String line;
        while ((line = reader.readLine()) != null) {
            c.increment();

            String[] words = getWords(line);
            for (String s : words) {
                WORDS.add(s);
                c.addWord(s);
            }
        }
        return c;
    }

}

class Category {
    CounterSet set;

    long totalSentences = 0;

    Category() {
        set = new CounterSet();
    }

    void increment() {
        totalSentences++;
    }

    void addWord(String word) {
        set.add(word);
    }

    long getTotalWords() {
        return set.getTotalWords();
    }

    long getUniqueWords() {
        return set.getUniqueWords();
    }

    float probabilityOfWord(String w) {
        long count = set.getCount(w);
        return (float)count / (getTotalWords() + getUniqueWords());
    }

}

class CounterSet {

    ArrayList<String> wordList;
    ArrayList<Long> countList;

    CounterSet() {
        wordList = new ArrayList<>();
        countList = new ArrayList<>();
    }

    void add(String word) {
        int index = wordList.indexOf(word);
        if (index < 0) {
            // add
            wordList.add(word);
            countList.add(1l);
        } else {
            countList.set(index, countList.get(index) + 1);
        }
    }

    long getCount(String word) {
        int index = wordList.indexOf(word);
        if (index < 0) {
            return 0l;
        }
        return countList.get(index);
    }

    long getUniqueWords() {
        return wordList.size();
    }

    long getTotalWords() {
        long ans = 0l;
        for (int i = 0; i < countList.size(); i++) {
            ans += countList.get(i);
        }
        return ans;
    }

}
