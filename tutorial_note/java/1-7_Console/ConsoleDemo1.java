import java.io.Console;

public class ConsoleDemo1 {
    public static void main(String[] args) {
        System.out.print("請輸入名稱：");

        Console console = System.console();
        String name = console.readLine();

        char[] password = console.readPassword("請輸入密碼：");
        System.out.println("您輸入的名稱…" + name);
        System.out.println("您輸入的密碼…" + new String(password));
    }
}
