Boxing 很好用，這裡就不多說了！
在用 Boxing 提供的語法糖時，請記得自己在用它！

這裡想說的是：
要小心`Boolean`跟`boolean`之間的差別！它們只差第一個字大小寫而已！
此外，當然我們知道`Boolean`是Class，`boolean`是Primitive type，
不過這樣就有一個差別：我們可以宣告以下這個東西：
```Java
Boolean condition = null;
```
它的好處是：以判斷`condition`這個變數是否有被初始化的方式，提供給它除了`true`跟`false`以外的第三個值！
這一點是`boolean`所辦不到的！
這個技巧我用過一次！只是在用時要小心`Boolean`跟`boolean`之差只差第一個字大小寫而已！
