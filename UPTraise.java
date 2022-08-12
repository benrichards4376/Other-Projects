import java.util.Scanner;
// Given a list of salaries, determine how many people would benefit more from a given fixed raise 
// or from a salary doubling
public class UPTraise {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int size, raise, total, i, fixed = 0, doubleTot = 0, temp;
		size = input.nextInt();
		raise = input.nextInt();
		for (i = 0; i < size; i++)
		{
			temp = input.nextInt();
			if (temp < raise)
				fixed++;
			else if (temp > raise)
				doubleTot++;
		}
		if (doubleTot == fixed)
			System.out.println("Equal people benefit from either option");
		else
			System.out.println((fixed > doubleTot)? "More people benefit from the fixed raise": 
													"More people benefit from a double salary" );
	}
}