無論它怎麼說，我還是覺得`String msg2 = msg + "123";`是Java對`String`的Boxing語法糖！
不過的確要注意到`String`類別畢竟不是Primitive type！

此外，Java裡面每一個的`char`變數都是用unicode字元存的！
且 "我們" 這個`String`物件的`length()`一樣仍會是`2`，而不會是`4`！
因為就算是字串裡的所有字元都是英文，Java仍然會用unicode去存！
