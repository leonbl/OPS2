Koda iz knjige OSTEP (Uvod - http://pages.cs.wisc.edu/~remzi/OSTEP/intro.pdf).

Za prevajanje, samo napišite:

```
prompt> make
```

Za podrobnosti si lahko pogledate `Makefile`.

Programe nato zaženite! Primeri:

```
prompt> ./cpu A
```

```
prompt> ./mem 1
```

```
prompt> ./threads 10000
```

```
prompt> ./io
```


## Podrobnosti

Pri mem.c je problem, ker je "address space randomization" običajno privzeto vključen na modernih sistemih. Če ga hočete izključiti:

### macOS
[stackoverflow](http://stackoverflow.com/questions/23897963/documented-way-to-disable-aslr-on-os-x)

Rešite tako, da prevedete:
    gcc -o mem mem.c -Wall -Wl,-no_pie

### Linux

Giovanni Lagorio:

Under Linux you can disable ASLR, without using a debugger, in (at least)  two ways:
* Use the command setarch to run a process with ASLR disabled; I typically run
  bash, with which I can execute examples, like this:
  `setarch $(uname --machine) --addr-no-randomize /bin/bash`
* Writing 0 into `/proc/sys/kernel/randomize_va_space`; you need to be
  root to do this and this change has (a non-permanent) effect on the
  whole system, which is something you probably don't want. I use this
  one only inside VMs.



