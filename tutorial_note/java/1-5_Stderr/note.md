就Java也能印出訊息到Stderr，沒什麼，只要call對function就可以了！
```java
System.out.println("Hello! World!"); //Print to Stdout!
System.err.println("Error Message Test"); //Print to Stderr!
```

測試一下：
```shell
$ java HelloWorld
Hello! World!
Error Message Test
$ java HelloWorld 2>/dev/null
Hello! World!
$ java HelloWorld 1>/dev/null
Error Message Test
$ java HelloWorld >/dev/null
Error Message Test
```

