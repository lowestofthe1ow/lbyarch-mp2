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