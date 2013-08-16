import java.util.Scanner;

public class HelloUser1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Please input your name: ");
		System.out.printf("Hello! %s!\n", scanner.next());
	}
}
