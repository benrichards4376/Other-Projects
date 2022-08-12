import java.util.Scanner;
// Converts cat age to human age
public class UPTcat {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter your cat's age (Y M)");
		int catYears = input.nextInt();
		int catMonths = input.nextInt(), tempMonths;
		int humanYears, humanMonths;
		if (catYears >= 2)
		{
			humanYears = 4 * (catYears - 2) + 24;
			humanYears += (catMonths * 4) / 12;
			humanMonths = (catMonths * 4) % 12;
		}
		else if (catYears >= 1)
		{
			humanYears = 15;
		
			humanYears += (catMonths * 9) / 12;
			humanMonths = (catMonths * 9) % 12;
		}
		else
		{
			humanYears = 0;
			
			humanYears += (catMonths * 15) / 12;
			humanMonths = (catMonths * 15) % 12;
		}
		System.out.println("Human years: " + humanYears + " Human months: " + humanMonths);
	}
}