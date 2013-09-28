Java 5.0有新增foreach的語法能幫助大家少用for迴圈來掃過一遍`Array`物件的內容，即：
```Java
for(int i = 0; i < arr.length; i++)
    System.out.println(arr[i]);
```
可以被取代成
```Java
for(int element : arr)
    System.out.println(element);
```
關鍵字仍為`for`，只是寫法上不同了！

至於二維array可以寫成：
```Java
for(int[] row : arr)
    for(int element : row)
        System.out.println(element);
```
注意第一層for迴圈的row的type！是`int[]`！
