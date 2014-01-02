### Reference
1. <http://rathodpratik.wordpress.com/2013/03/24/build-cc-executables-for-android-using-ndk/>

### Prerequisites of building this Android executable
1. Linux Host
2. Android NDK on host machine

### Guild for building this Android executable
```shell
$ cd ndk_test1
$ export PATH=$PATH:<path/to/ndk>/
$ ndk-build
```
The most special and important step is that we have to put all source code into the `jni` folder and then execute `ndk-build` outside the `jni` folder!

At final, the Android executable `hello_world` will be placed inside the `libs/mips/` folder.

Don't forget the characteristic of `ndk-build`! It will search `Android.mk` in each folders and build executables or libraries according to it.
