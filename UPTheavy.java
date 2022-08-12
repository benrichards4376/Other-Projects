import java.util.Scanner;
// Consider a positive integer a. We define weight of a as: 
 // 	(number of digits in a) * (sum of the digits in a) 
// For example, if a = 5767, then weight of a is: 
 // 	(4) * (5 + 7 + 6 + 7) = 100 
// The Problem: 
// 		Given two positive integers, determine which one weighs more, i.e., it is heavier. 
public class UPTheavy {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int i, j = 0, numDigA = 1, numDigB = 1, weightA = 0, weightB = 0;
		for (i = 0; i < 6; i++)
		{
			if (a % 10 == a)
			{
				weightA += a % 10;
				a /= 10;
				numDigA = i + 1;
				break;
			}
			weightA += a % 10;
			a /= 10;
		}
		for (i = 0; i < 6; i++)
		{
			if (b % 10 == b)
			{
				weightB += b % 10;
				b /= 10;
				numDigB = i + 1;
				break;
			}
			weightB += b % 10;
			b /= 10;
			
		}
		
		weightA *= numDigA;
		weightB *= numDigB;
		
		if (weightA > weightB)
			System.out.println("A is heavier");
		else if (weightA < weightB)
			System.out.println("B is heavier");
		else
			System.out.println("A and B weigh the same");
	}
}