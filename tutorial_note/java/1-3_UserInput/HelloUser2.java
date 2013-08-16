import java.util.Scanner;

public class HelloUser2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Please input a number: ");
		int ret = scanner.nextInt();
		System.out.printf("Oh! I get %d!!\n", ret);
	}
}
