#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void print_char_rep(unsigned char c)       // make em easier to read when printing them out
{
 if(isprint(c))
 {
  printf("%c", c);
 }

 else if(c == '\0')
 {
  printf("\\0");
 }

 else if(c == '\n')
 {
  printf("\\n");
 }

 else if(c == '\t')
 {
  printf("\\t");
 }

 else if(c == '\r')
 {
  printf("\\r");
 }

 else
 {
  printf(".");
 }
}

void memory_dump(int argc, char *argv[])         // finds the lowest and highest addresses / dumps the memory
{
 if(argc <= 0)
 {
  return;
 }

// this finds the minimum and maximim of the argstrings


 unsigned char *minimum_addr = (unsigned char *)argv[0];
 unsigned char *maximum_addr = (unsigned char *)argv[0] + strlen(argv[0]);

 for(int i = 0; i < argc; i++)
 {
  unsigned char *start = (unsigned char *)argv[i];
  unsigned char *end = start + strlen(argv[i]);

  if(start < minimum_addr)
  {
   minimum_addr = start;
  }

  if(end > maximum_addr)
  {
   maximum_addr = end;
  }

 }


 maximum_addr++;

 // this aligns it to 8 byts

 unsigned long start_value = (unsigned long)minimum_addr;
 unsigned long end_value = (unsigned long)maximum_addr;

 unsigned long start_alignment = start_value & ~0x7UL;
 unsigned long end_alignment = (end_value + 7UL) & ~0x7UL;

 // prints the region for the strings

 for (unsigned long addr = start_alignment; addr < end_alignment; addr += 8)
 {
  unsigned char *p = (unsigned char *)addr;
  printf("  |");

  for (int i = 7; i >= 0; i--)        // sorts em from MSB to LSB
  {
   unsigned char b = *(p + i);
   printf("%02hhx(", b);
   print_char_rep(b);
   printf(") ");
  }

  printf("| %p\n", (void *)p);
 }
}

int main(int argc, char *argv[])
{

 unsigned char *p;
 int i;
 int pointer_size = sizeof(void *); // 8 bytes pointer

 p = (unsigned char *)&argv;

 printf("argv   | ");

 for(i = pointer_size -1; i >= 0; i--)
 {
  unsigned char b = p[i];
  printf("%02hhx ", b);
 }

 printf("| %p\n", (void *)&argv);

 printf("\n\n");

 for (int i = 0; i < argc; i++)
 {
  int j;

  printf("argv[%d] | ", i);

  p = (unsigned char *)&argv[i];

  for (j = pointer_size -1; j >= 0; j--)
  {
   unsigned char b = p[j];
   printf("%02hhx ", b);
  }

 printf("| %p\n", (void *)&argv[i]);
}

 printf("\n\n");

 memory_dump(argc, argv);

 return 0;
}
