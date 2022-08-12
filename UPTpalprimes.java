import java.util.Scanner;
// Prints the palindromic primes between L and H
public class UPTpalprimes {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the low range: ");
		int L = input.nextInt();
		System.out.println("Enter the high range: ");
		int H = input.nextInt();
		int i, numPalPrimes = 0;
		System.out.println("The Palindromic primes between " + L + " and " + H + " are: ");
		for (i = L; i <= H; i++)
			if (isPalindrome(i) == 1 && isPrime(i) == 1)
				System.out.println(i);
	}
	// Returns 1 if 'num' is a palindrome, 0 otherwise
	static int isPalindrome(int num) {
		int rem, sum = 0, temp;     
	  
		temp = num;    
		while (num > 0) {    
			rem = num % 10;  
			sum = (sum * 10) + rem;    
			num = num / 10;    
		}    
		if (temp == sum)    
			return 1; 
		else    
			return 0;     
	}
	// Returns 1 if 'num' is a prime number, 0 otherwise
	static int isPrime(int num) {
		int i;
		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
				return 0;
		}
		return 1;
	}
}