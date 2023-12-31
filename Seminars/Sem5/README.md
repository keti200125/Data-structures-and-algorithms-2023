## Задача 1

Даден е списък `l` с `n` елемента.

Да се дефинира функция shuffle(), която получава **адреса на първия елемент на списъка**.

Функцията да пренарежда възлите на списъка така, че елементите от втората половина на списъка да се преместят в началото на списъка, но в обратен ред (при списъци с нечетен брой елементи считаме средния елемент за принадлежащ към първата половина на списъка).
Пример:

Вход: L1 → L2 → L3 → L4 → L5 

Изход: L5 → L4 → L1 → L2 → L3

## Задача 2 

Даден е списък l с елементи стекове.

Да се дефинира функция equalize(l), която размества елементите на стековете така, че да няма два стека в l с разлика в броя на елементите, по-голяма от 1.

```
Вход                          Изход

5 -> 4 -> 3 -> 2 -> 1         5 -> 4 -> 3
|                             |
v                             v
7 -> 6                        7 -> 6 -> 1
|                             |
v                             v
11 -> 10 -> 9 -> 8            11 -> 10 -> 9
|                             |
v                             v
12                            12 -> 2 -> 8
```

## Задача 3 - Linked List Partition
Да се създаде функция
```cpp
LinkedListNode<int>* partition(LinkedListNode<int>* head, int x);
```
която пренарежда списъка така, че всички възли със стойност по-малка от **х** са преди всички възли със стойност по-голяма или равна от **х**.

Пример:

Вход: head -> 1 -> 4 -> 3 -> 2 -> 5 -> 2, x = 3

Изход: 1 -> 2 -> 2 -> 4 -> 3 -> 5

Вход: head -> 2 -> 1, x = 2

Изход: 1 -> 2

**HINT:**

Можете да си направите два указателя, чрез които да строите някакви полезни помощни списъци. После, след като построите тези полезни помощни списъци, можете да пренасочите правилните указатели и да получите коректен отговор.
