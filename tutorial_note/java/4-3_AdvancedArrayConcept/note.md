其實這一個章節要講的就是Java的一個特性：Reference！
在Java裡，Object的assignment其實都是在assign Reference！即C++的Reference！
不過這一點我早就知道了，所以還好。

不過這個章節舉的例子反而讓我發現一個問題：
在Java裡，Array不能使用Boxing這個語法糖！
即以下的Java code在文法上是錯的：
```Java
int[] arr;
arr = {1,2,3,4,5};
```
該code要正確必須要Java在文法上要有support，否則是錯的！
而在Array上要做Boxing對Java來說可能必須是一個要想清楚的設計！
因為這勢必代表以下的code Java也必須支援：
```Java
int [] arr = new Array(5);
```
但目前Java沒有這種寫法！(已經測試過了！)
