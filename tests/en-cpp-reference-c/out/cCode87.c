//en.cppreference.com/w/c/language/attributes/deprecated.html
#include <stdio.h>
 

void TriassicPeriod(void)
{
    puts("Triassic Period: [251.9 - 208.5] million years ago.");
}
 

void JurassicPeriod(void)
{
    puts("Jurassic Period: [201.3 - 152.1] million years ago.");
}
 

int calcSomething(int x)
{
    return x * 2;
}
 
int main(void)
{
    TriassicPeriod();
    JurassicPeriod();
}