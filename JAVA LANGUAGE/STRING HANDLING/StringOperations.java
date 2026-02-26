import java.util.*;
class StringOperations {
    public static void analyzeString(String str) {
        int vowels=0,consonants=0;
        String st=str.toLowerCase();

        for(int i=0;i<st.length();i++) {
            char c=st.charAt(i);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') 
                   vowels++;
            else
                   consonants++;
            }
    }

    public static String toggleCase(String str) {
        StringBuffer sb=new StringBuffer();
        for(char c:str.toCharArray()) {
            if(Character.isUpperCase(c)) {
                sb.append(Character.toLowerCase(c));
            } else if(Character.isLowerCase(c)) {
                sb.append(Character.toUpperCase(c));
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int choice;
	do {
        System.out.println("1.Change Case");
        System.out.println("2.Reverse String");
        System.out.println("3.Compare Two Strings");
        System.out.println("4.Insert String into Another");
        System.out.println("5.Convert to Upper and Lower Case");
        System.out.println("6.Find Character Position");
        System.out.println("7.Check Palindrome");
        System.out.println("8.Count Words, Vowels, and Consonants");
        System.out.println("9.Exit");
        System.out.print("Enter your choice: ");
  
        choice=sc.nextInt();
        sc.nextLine(); 

        switch(choice) 
	    {
            case 1:
                System.out.print("Enter string: ");
                String s1=sc.nextLine();
                System.out.println("Result: "+ toggleCase(s1));
                break;

            case 2:
                System.out.print("Enter string: ");
                String s2=sc.nextLine();                   
     		    String reverse=new StringBuilder(s2).reverse().toString();
                System.out.println("Reversed: "+reverse);
                break;

            case 3:
                System.out.print("Enter first string: ");
                String str1=sc.nextLine();
                System.out.print("Enter second string: ");
                String str2=sc.nextLine();
                int comp=str1.compareTo(str2);
                if(comp==0) {
                    System.out.println("Strings are equal");
                } else if(comp>0) {
                    System.out.println("First string is greater.");
                } else {
                    System.out.println("Second string is greater.");
                }
                break;

            case 4:
                System.out.print("Enter main string: ");
                String s3=sc.nextLine();
                System.out.print("Enter string to insert: ");
                String insert=sc.nextLine();
                System.out.print("Enter index position: ");
                int pos=sc.nextInt();
                
                if(pos>=0 && pos<=s3.length()) {
                    StringBuffer sb=new StringBuffer(s3);
                    sb.insert(pos,insert);
                    System.out.println("Result: "+ sb.toString());
                } else {
                    System.out.println("Invalid");
                }
                break;

            case 5:
                System.out.println("Enter string: ");
                String s5=sc.nextLine();
                System.out.println("Uppercase: "+ s5.toUpperCase());
                System.out.println("Lowercase: "+ s5.toLowerCase());
                break;

            case 6:
                System.out.println("Enter string: ");
                String s6=sc.nextLine();
                System.out.println("Enter character to find: ");
                char search=s6.charAt(0);
                int index=s6.indexOf(search);
                if(index!=-1) {
                    System.out.println("Character found at index: "+ index);
                } else
                    System.out.println("Character not found");
            break;

            case 7:
                System.out.println("Enter string: ");
                String s7=sc.nextLine();
                String rev=new StringBuilder(s7).reverse().toString();
                if(s7.equalsIgnoreCase(rev)) {
                    System.out.println("string is a palindrome");
                } else {
                   System.out.println("string is not a palindrome.");
                }
                break;

            case 8:
                System.out.println("Enter string: ");
                String s8=sc.nextLine();
                analyzeString(s8);
                break;

            case 9:
                System.out.println("Exit");
                break;

            default:
                System.out.println("Invalid choice!");
	    }
    } while(choice!=9);
    }
}