# Linux System Programming Techniques Learning

# Cookies
*whatis*
Displays online manual instructions
eg. whatis ls
> ls (1)               - list directory contents

*man*
Interface of system manual instructions
eg. man [page] cmd/fun
> Powerful, comprehensive
> It's recommended to use whatis befor man to get info rapidly

*echo $?*
Return code from the last run process







# Q&A
### Num -1-

**C Syntax** : Break don't take effort

**Desc** : A break statement is used in a switch() which is embeded in a while(), when break is executed, the execution flow is still in while()

**From** : 02_parse_cmd/parse.c

**EX** :

```c
while (-1 != opt) {
        switch (opt) {
        case 'm': /* multiply */
            sum = 1;
            for (cout = 2; cout < argc; cout++)
                sum *= atoi(argv[cout]);
            break;
        }  
    }
    printf("Result: %d", sum);
    return 0;

When Line 7 break is executed, the execution flow don't jump to printf() as expected.
```

**Result** : break statement can break all loop, but it had to be in a loop directly itself.
