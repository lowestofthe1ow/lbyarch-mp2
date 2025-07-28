# LBYARCH MP2: x86-C Interfacing

## Compiling

```
nasm -f win64 asm_dot_product.asm
gcc -c main.c -o main.obj -m64
gcc main.obj asm_dot_product.obj -o main.exe -m64
```

Alternatively, you may call the included `build.bat` file that runs the above for you:

```
build
```

## Runtime comparison

For two randomly-generated vectors of input size $n = 2^{28}$ ($n = 268,435,456$), the C implementation took approximately $1.255$ seconds, while the x86-64 implementation took approximately $0.221$ seconds. This difference is far less pronounced for smaller inputs, as `time.h`'s `clock()` function cannot measure the difference between the two execution times for $n = 5$, for instance (both end up being `0.0`).

## Screenshots

For $n = 5$:

![](img/small_n.png)

For $n = 2^{28}$:

![](img/large_n.png)