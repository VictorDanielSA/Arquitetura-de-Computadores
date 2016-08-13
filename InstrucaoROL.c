/* Autor: Victor Daniel Silva Aragão
   Utilizando a instrução ROL com assembler in line

   Compilar: gcc InstrucaoROL.c -o InstrucaoROL

   Executar (Windows): InstrucaoROL.exe          */

#include <stdio.h>

int valor1, valor2, valor3;
int saida1, saida2, saida3;

int main(){

   valor1 = -15;

   printf("Movimentacao de dados ROL (8 bits):\n");
   asm ("mov _valor1, %eax");
   asm ("rolb $2, %al");
   asm ("mov %al, _saida1");
   printf("Valor de saida: %d \n", saida1);

/* Valor inicial ->  11110001 -> Rotate left 2 vezes
   Valor  final  ->  11000111                     */

   valor2 = 10000;

   printf("\nMovimentacao de dados ROL (16 bits):\n");
   asm ("mov _valor2, %eax");
   asm ("rolw $1, %ax");
   asm ("rolw $1, %ax");
   asm ("rolw $1, %ax");
   asm ("mov %ax, _saida2");
   printf("Valor de saida: %u \n", saida2);

/* Valor inicial ->  0010011100010000 -> Rotate left
                     0100111000100000 -> Rotate left
                     1001110001000000 -> Rotate left
   Valor  final  ->  0011100010000001             */

   valor3 = 2147483655;

   printf("\nMovimentacao de dados ROL (32 bits):\n");
   asm ("mov _valor3, %eax");
   asm ("roll $3, %eax");
   asm ("mov %eax, _saida3");
   printf("Valor de saida: %u \n", saida3);

/* Valor inicial ->  10000000000000000000000000000111 -> Rotate left 3 vezes
   Valor  final  ->  00000000000000000000000000111100                     */

   return 0;
}
