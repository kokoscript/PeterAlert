# PeterAlert for MenuetOS

In order to build this, you will need to install [Smaller C](https://github.com/alexfru/SmallerC) and NASM,
then clone the [Menuet32-Plus](https://github.com/ry755/menuet32-plus) repo into `../../menuet32-plus` (this path can be changed in the Makefile).
Menuet32-Plus is required in order to make use of the libmenuet C library for MenuetOS.
Then simply run `make` and copy the resulting `PETER` file to a MenuetOS disk. This has only been tested on Menuet32 but should work on Menuet64 as well.

# Screenshot

![Screenshot of PeterAlert on MenuetOS](PeterAlert.png)
