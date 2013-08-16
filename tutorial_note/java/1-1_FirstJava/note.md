1. 注意它所說的：
   「寫Java程式通常都是由定義「類別」開始，"class"是Java 用來定義類別的關鍵字，類別的名稱是HelloWorld，
   這與您所編輯的檔案（HelloWorld.java）主檔名必須相同，在編寫Java程式 時，一個檔案中可撰寫數個類別，
   但是只能有一個"public" 類別， 而且檔案主檔名必須與這個"public"類別的名稱相同。」
   
   以及接下來講的到為何void main()一定要宣告static!!!
   「接下來看看 main() 方法（Method），它是Java程式的「進入點」 （Entry point）， 程式的執行是由進入點開始的，
   它一定是個"public" 成員（Member）， 這樣它才可以被呼叫；由於它不需要產生物件就要能被執行，
   所以它必須是個"static"成員。」

2. 網頁沒提到的是執行HelloWorld.class的指令：
   (在HelloWorld.class的目錄之下，".class"去掉!! (甚至bash的自動完成還會幫你把.class去掉呢!!!))
   ```shell
   $ java HelloWorld
   Hello World!!
   ```

3. 如果我在原code上加上package的宣告如下：
   ```java
   package hello;

   public class HelloWorld {
      public static void main(String[] args) {
         System.out.println("Hello World!!");
      }
   }
   ```

   則用javac compile HelloWorld.java後產生的HelloWorld.class沒辦法在其當前目錄下執行！
   ```shell
   $ java HelloWorld
   Exception in thread "main" java.lang.NoClassDefFoundError: HelloWorld (wrong name: hello/HelloWorld)
           at java.lang.ClassLoader.defineClass1(Native Method)
           at java.lang.ClassLoader.defineClassCond(ClassLoader.java:631)
           at java.lang.ClassLoader.defineClass(ClassLoader.java:615)
           at java.security.SecureClassLoader.defineClass(SecureClassLoader.java:141)
           at java.net.URLClassLoader.defineClass(URLClassLoader.java:283)
           at java.net.URLClassLoader.access$000(URLClassLoader.java:58)
           at java.net.URLClassLoader$1.run(URLClassLoader.java:197)
           at java.security.AccessController.doPrivileged(Native Method)
           at java.net.URLClassLoader.findClass(URLClassLoader.java:190)
           at java.lang.ClassLoader.loadClass(ClassLoader.java:306)
           at sun.misc.Launcher$AppClassLoader.loadClass(Launcher.java:301)
           at java.lang.ClassLoader.loadClass(ClassLoader.java:247)
   Could not find the main class: HelloWorld.  Program will exit.
   ```

   要將HelloWorld.class丟進一個叫hello的資料夾裡如下：(因為package hello;的關係!!)
      hello/HelloWorld.class
   然後在hello資料夾的母資料夾下執行java hello.HelloWorld才能正常運作！(還不是java hello/HelloWorld呢!!!)
   ```shell
   $ java hello.HelloWorld
   Hello World!!
   ```

   這說明了java files有階層性的特色！這也跟已知的認知吻合！
   所以沒有在檔頭宣告package的話，則要直接在HelloWorld.class的當前目錄下執行java HelloWorld !!!
   (但無論如何，反正這都人訂的啦!!!)
   參考資料： <http://my.freebsd.org.hk/html/jdk1.2/tooldocs/win32/javac.html>