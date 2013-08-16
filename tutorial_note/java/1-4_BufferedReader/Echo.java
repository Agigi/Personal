import java.io.*;

public class Echo {
	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("請輸入一列文字: ");
		String text = buf.readLine();
		System.out.println("您輸入的文字: " + text);
	}
}