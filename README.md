# ft_printf

42 project, recoding the famous printf function in C. Printf can write combinations of strings, numbers of different bases, even pointers, to the stdout, with various options.

## Final grade : 100/115

Mandatory part : 100/100

Bonus : 0/15

### How to use it

Using ``make`` will create the ``libftprintf.a`` binary.

To include the library in your project, clone the repository in your working tree and compile with the following flags :

```
gcc -L. -lftprintf file.c
```

### Available options

The function is called with the standard printf norm.

You can print strings with ``%s``, or characters with ``%c``. For decimal numbers, use ``%d`` or ``%i``, or ``%u`` for unsigned. If you want another base, use ``%o`` for octal, ``%x`` for hexadecimal and ``%X`` for CAPS hexadecimal. Finally, ``%p`` displays a pointer address.

Width (``%5s``) and precision (``%.5s``) options are available, as well as width-flags ``-`` and ``0`` (``%-5s`` or ``%05s``), and work the same as printf.

Example :

```
ft_print("The number of %s is %d.", "people", 5);
>> The number of people is 5.

ft_printf("%d is %x in hex and %o in octal.", 30, 30, 30);
>> 30 is 1e in hex and 36 in octal.
```
