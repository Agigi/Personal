`Arrays`這個Class有點奇怪！
我懷疑為什麼Java不用`array.sort()`來直接對該`Array`物件的內部做sorting！
我知道Javascript是由於其語法的限制所以辦不到，但是Java應該就可以辦到了！
我覺得這不是Java在文法上的侷限性所致！

Anyway，反正Java有一個`Arrays`的Class來專做`Array`物件的處理，
其有`binarySearch()`這個函式來對`Array`物件做index的快速search，我覺得很棒！

受制於文法的因素，我們可以透過[這個網頁](http://developer.android.com/reference/java/util/Arrays.html)看到`Arrays`必須為所有種類的Primitive type以及一般的Class做很多個同名函式的宣告以及定義！
如`sort()`、`binarySearch()`等都是這樣的！
