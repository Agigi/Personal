## Tutorial URL
- <http://openhome.cc/Gossip/JavaGossip-V1/>

## Ch1-1
- `javac`及`java`的使用。
- 注意路徑的問題跟`package`的使用。

## Ch1-3
- 注意Decorator模式的Design Pattern！

## Ch1-5
- 注意Java裡Stderr的用法。

## Ch1-7
- 注意Ch1-3的class `Scanner`及Ch1-7的class `Console`之間的差異。

## Ch2-6
- 注意Java也是有`++`跟`--`的，用法跟C語言的一模一樣！

## Ch2-8
- Java的switch case一樣無法用String當case的條件。

## Ch3-1
- `Boolean`跟`boolean`只差第一個字大小寫而已，但二者截然不同喔！
- `Boolean`因為是Class的關係，所以它的變數值可以是`null`，這樣就變成是`Boolean`的變數可以有三種值：`true`、`false`和`null`！這個技巧可以讓你的程式更加簡化！

## Ch3-2
- 不要因為「Object跟Primitive value之間」可以用Boxing語法糖，就以為「Object跟Object」也可以用Boxing語法糖！

## Ch4-1
- `Array`這個Class在Java裡有特殊地位，它的Object有所有一般Object的屬性，但是在new一個`Array`時只能用傳統的`T[] arr = new T[10];`或`int[] arr = {1,2,3};`來給值！
- Java的`Array`在`T[] arr = new T[10];`後會自動替所有element設初始值`0`或`false`！

## Ch4-3
- 在Java裡，Object的assignment都是assign Reference。
- Java的`Array`物件沒有Boxing支援！

## Ch4-7
- Java有foreach的語法來掃過array的所有element一次！

## Ch5-1
- Java裡面每一個的`char`變數都是用unicode字元存的！

## Ch5-2
- `String st = "abc";`還是`String str = new String("abc");`不同，前者會先去回收池找，所以有可能會refer到同一個Reference！
- 回收池的機制即「Flyweight Pattern」！

## 結論
- 記不起來的細節就算了(如一些API的用法)，JAVA的重要概念不要忘記比較重要！

