#include <stdio.h>
#include <cs50.h>

int height;

int main(void)
{
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        for(int s = 0; s < height - i - 1; s++)
        {
            printf(" ");
        }
        
        for(int h = 0; h < i + 2; h++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}