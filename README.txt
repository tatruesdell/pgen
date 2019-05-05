Pgen is a password generator program whose passwords follow 
a simple syntactic structure: 3[a-z]1[!-*]4[A-Z]4[0-9]. The 
numbers outside the brackets represent the sequence length
of each symbol set. To generate passwords, simply start pgen
and specify the number of passwords to generate. 
The passwords will be in list format in the out.txt file.

Pgen uses a few different techniques to simulate randomness,
including a linear congruential number generator, a 
Fibonacci number generator, and a sequence of prime numbers. 



