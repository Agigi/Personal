由於每一個Java的`String`物件都是immutable字串！
所以一定會有人想對已生成的`String`物件作處理！
因此`StringBuilder` Class就這樣子被做出來了！

`StringBuilder`物件可以對字串作append、insert、replace、reverse等處理喔！非常重要！
使用`StringBuilder`的`append()`比`String`物件用`+`還來得快！
以下這一篇文章有講到：
http://changyy.pixnet.net/blog/post/27884507

此外我覺得更重要的是：`StringBuilder`物件自己就有Boxing了！
如此一來`StringBuilder`在某些時刻的使用性也跟`String`一樣方便了！
真不知道Java是要怎麼應付這麼多種Class的Boxing需求！

`StringBuffer`是`StringBuilder`的多執行緒版本！
僅限處理單執行緒的`StringBuilder`效能還是比較好的~~~
所謂的「`StringBuffer`能處理多執行緒」的意思，
我想是當`StringBuffer`物件被二個以上的thread存取時，
其本身會有自己的lock去處理synchronization的問題！
