Boxing(自動裝箱與拆箱)是超有用的語法糖沒錯！
但它好用的時機僅限於 Object 跟 Primitive value 之間在互動時
(所謂的「互動」如 `Object = Primitive value` 或 `Object + Primitive value`)
所以它會讓你出錯的時機正是「非 Object 跟 Primitive value 之間互動」的時刻，
即「 Object 與 Object 之間互動」的時機！
因此如同像是文章中所提到的二個 Integer 之間的比較正是這種容易出錯的時刻！
在二個 Integer 在比較著數值時還想著 Boxing 語法糖就錯了！
那明明是給 Object 跟 Primitive value 互動時用的！這一點真的要小心！

不過有時並不是因為想著 Boxing 所以才去寫`if (str1 == str2)`這種condition的，
而是被整個Java的程式撰寫習慣所感染出來的。

Anyway，遇到 Object 與 Object 之間的比較時，請記得用`equals()`這個函式去比較它們的值！
