Java提供另一個好用的class Console供大家使用！
Console能做到跟一般console一樣的輸入及輸出的感覺！
它有自己的`printf()`，它的`readLine()`在coding的感覺上跟C語言的`scanf()`更加的相近！
比Scanner還要直覺！

除此之外，它還提供了`readPassword()`這個專門在讓人輸入密碼的函式！
這是Scanner所沒有的功能！看論壇在問如何hide input時大家都是推薦使用Console去取代Scanner！
(不過Scanner在別的地方很rich，看[Scanner的API](http://developer.android.com/reference/java/util/Scanner.html)即可知！)

此外，`readLine()`跟`readPassword()`本身都有先行印出字串的功能，
所以它本身即可取代函式`System.out.println()`！
ConsoleDemo1.java跟ConsoleDemo2.java之間的差別就僅僅是這樣而已，它們在功能上是一樣的！

