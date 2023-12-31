## Задача 1
Да се напише функция, която генерира всички двоични числа от 1 до n, използвайки опашка.

Пример:
> n = 10 ➡ 1 10 11 100 101 110 111 1000 1001 1010

## Задача 2
Конче стои върху шахматна дъска NxN. За начална и крайна позиция да се изведе с колко най - малко хода можем да стигнем от началната до крайната.

Пример:
> {(0, 0), (2, 1)} -> 1
> 
> {(0, 0), (7, 7)} -> 6


Като бонус можете да направите втора задача да не извежда само минималния път, но и клетките през които сме минали.

## Задача 3
Напишете функция, която приема масив от цели числа и проверява дали подредицата, съставена само от положителните числа в масива е същата като подредицата, съставена от отрицателните числа в масива (след умножаването на всички числа в едната подредица с -1).  
**Да се реши чрез опашка!**  

*Вход: 1 5 -1 4 -5 9 8 -4 -9 18 -8 -18 -7 7, Изход: true  
Вход: 1 -1 2 -2 3 3, Изход: false*  

## Задача 4 - Sliding window maximum
Даден е масив от цели числа. Представяме си, че имаме прозорец с дължина *k* който се движи отляво надясно. Единственото което можем да видим са числата в прозореца. Да се изведе максимумът на всеки такъв прозорец.

Пример:

> Вход:  **[1, 3, -1, -3, 5, 3, 6, 7]**, k = 3
> 
> Output: [3, 3, 5, 5, 6, 7]

Обяснение:
> 
> **[1  3  -1]** -3  5  3  6  7      => 3
> 
> 1 **[3  -1  -3]** 5  3  6  7       => 3
>
> 1  3 **[-1  -3  5]** 3  6  7       => 5
>
> 1  3  -1 **[-3  5  3]** 6  7       => 5
>
> 1  3  -1  -3 **[5  3  6]** 7       => 6
>
> 1  3  -1  -3  5 **[3  6  7]**      => 7