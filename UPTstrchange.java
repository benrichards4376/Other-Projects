import java.util.Scanner;
// The Problem: 
// Given a string, change the string to UCF as follows: 
	// • Characters before the leftmost “U” in the string are changed to hyphen (“-”).
	// • Characters after the rightmost “F” in the string are changed to hyphen.
	// • Characters between the leftmost U and the rightmost F are changed to “C”.
// Assume the string will contain at least one “U”, at least one “F” after that U, and at least one 
// character between the U and F. 
public class UPTstrchange {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String s = new String(input.nextLine());
		String newStr = new String("");
		int i = 0, fIndex = -1;
		
		for (i = 0; i < s.length(); i++)
			if (s.charAt(i) == 'F')
				fIndex = i;
			
		i = 0;
		while (s.charAt(i++) != 'U')
			newStr += '-';
		newStr += 'U';
		
		while (i++ < fIndex)
			newStr += 'C';
		newStr += 'F';
		
		while (i++ < s.length())
			newStr += '-';
		System.out.println(newStr);
	}
}