Array 在很多語言中都是「文法上」就是支援的對象，Java也不例外。
在此所謂的「文法上」是指Java一樣有以下的語法：
```Java
int[] arr1 = int[10];
int[] arr2 = {1,2,3,4,5};
```

但是在物件導向的語言中，語言本身可能也希望能將`Array`變成一個Class，
如此一來便能有`array.length`這個element可以輕鬆使用！
而Java正是這麼設計的！

這樣子的設計使得 `Array` 這個Class在Java裡擁有了一個特殊的地位：
它擁有Class的所有特性，除了new一個Array這件事情之外！
也就是說在Java裡沒有以下的這種寫法：
```Java
int arr = new Array(...);
```
這件事非常重要！

題外話，Javascript在Array的處理上也有類似的問題，但是它是new一個Array或是用文法來給值都行！
```Javascript
var arr1 = new Array(3); //代表要new一個elements數為3的Array！
var arr2 = [1, 2, 3]; //文法給值！(但其實這扯到了Javascript特有的JSON格式。)
```

------

第二件事是，Java跟C不同，在 Array 給值完之後，
它的每一個element的value都不用你自己去做初始化，便能保證value是`0`或是`false`！
(一定要是`false`，因為`0`本來就都等於`false`嘛！)
