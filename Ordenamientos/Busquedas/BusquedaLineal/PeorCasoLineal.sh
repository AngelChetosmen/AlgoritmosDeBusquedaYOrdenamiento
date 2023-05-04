#!/bin/bash
gcc busquedaLineal.c tiempo.c -o bLinealPeor
./bLinealPeor 2147483529 1000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 2000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 3000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 4000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 5000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 6000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 7000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 8000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 9000000 <numeros10millones.txt >> bLinealPeor.txt
./bLinealPeor 2147483529 10000000 <numeros10millones.txt >> bLinealPeor.txt
