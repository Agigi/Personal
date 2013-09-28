注意到無論是用`String st = "abc";`還是`String str = new String("abc");`給值出來的`String`物件，
其字串內容都是不可以再改變的！`String`並沒有`setString()`這種函式可以用！
也就是說所有Java的`String`物件都是immutable字串！無論給值的方法是什麼。

此外有一個重要該學的點：
`String st = "abc";`跟`String str = new String("abc");`畢竟還是有一點點的不同的！
`String st = "abc";`會嘗試去String pool裡撈回收的字串出來用，只要它的字串也是 "abc" 的話；
而`String str = new String("abc");`則能保證每次出來的`String`物件都是不同的！
意即：
```Java
String str1 = "abc";
String str2 = "abc";
System.out.println(str1 == str2); //會印出true！
String str3 = new String("abc");
String str4 = new String("abc");
System.out.println(str3 == str4); //會印出false！
```

而回收池的機制正是「Flyweight Pattern」！
