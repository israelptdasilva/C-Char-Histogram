# C Character Histogram

*© Israel Pereira Tavares da Silva*

> C is a general-purpose programming language. It has been closely associated with the UNIX operating system where it was developed, since both
the system and most of the programs that run on it are written in C. The
language, however, is not tied to any one operating system or machine;
and although it has been called a ”system programming language” because
it is useful for writing compilers and operating systems, it has been used
equally well to write major programs in many different domains.

* [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language)

`histogram.c` is a program that plots horizontal and vertical histograms of the total count of each character (ASCII) typed in the standart input. It was written as part of an exercise from the book [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language).

Compile and run the program.

```bash
cc histogram.c && ./a.out
```

Sample input:
```bash
Valeu a pena? Tudo vale a pena se a alma nao e pequena. Quem quer passar alem do Bojador tem que passar alem da dor. Deus ao mar o perigo e o abismo deu, mas nele e que espelhou o ceu.```
```

Sample output:
```bash
e ------------------------- 25 
a ----------------------- 23 
o ------------- 13 
u ----------- 11 
s --------- 9 
m -------- 8 
p ------- 7 
l ------- 7 
r ------- 7 
d ------ 6 
n ----- 5 
q ---- 4 
. --- 3 
i -- 2 
g - 1 
c - 1 
v - 1 
D - 1 
t - 1 
T - 1 
? - 1 
j - 1 
B - 1 
h - 1 
Q - 1 
, - 1 
b - 1 
V - 1 
```
```bash
e|a|o|u|s|m|p|l|r|d|n|q|.|i|g|c|v|D|t|T|?|j|B|h|Q|,|b|V|
* 
* 
* * 
* * 
* * 
* * 
* * 
* * 
* * 
* * 
* * 
* * 
* * * 
* * * 
* * * * 
* * * * 
* * * * * 
* * * * * * 
* * * * * * * * * 
* * * * * * * * * * 
* * * * * * * * * * * 
* * * * * * * * * * * * 
* * * * * * * * * * * * * 
* * * * * * * * * * * * * * 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
```

> Valeu a pena? Tudo vale a pena
Se a alma não é pequena.
Quem quer passar além do Bojador
Tem que passar além da dor.
Deus ao mar o perigo e o abismo deu,
Mas nele é que espelhou o céu.
(Fernando Pessoa)
