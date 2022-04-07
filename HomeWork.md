# Домашняя работа
## Щучкин Никита А-13а-19

## **Задание 1**  

1. $L = \{ w \in \{a, b, c\}^∗ : |w|_c = 1 \}$ 
 
Построим регулярку: 
$(a + b)^*с(a + b)^*$  

$(a+b):$  

![](FirstTask_1.gv.svg)

$(a+b)^*:$

![](FirstTask_2.gv.svg)

$(a+b)^*c:$

![](FirstTask_3.gv.svg)  

Итоговый конечный автомат для $(a+b)^*c(a+b)^*:$

![](FirstTask_4.gv.svg)  

2. $L = \{ w \in \{a, b\}^∗ : |w|_a \leq 2, |w|_b \geq 2 \}$  

Постоим через прямое произведение двух ДКА.

Первый автомат:

$L_1 = \{ w \in \{a, b\}^∗ : |w|_a \leq 2 \}$  

Регулярка:  
$b^*ab^*ab^*+b^*ab^*+b^*$

Автомат:

![](SecondTask_1.gv.svg)  

$<\Sigma_1=\{a,b\},\ Q_1=\{q_1,q_2,q_3\},\ S_1=q_1,\ T_1=\{q_1,q_2,q_3\}, \delta_1>$

Таблица переходов:

|       | a     | b     |
| ----- | ----- | ----- |
| $q_1$ | $q_2$ | $q_1$ |
| $q_2$ | $q_3$ | $q_2$ |
| $q_3$ | -     | $q_3$ |

Второй автомат:

$L_2 = \{ w \in \{a, b\}^∗ : |w|_b \geq 2 \}$  

Регулярка:  
$(a+b)^*b(a+b)^*b(a+b)^*$

Автомат:

![](SecondTask_2.gv.svg)  

$<\Sigma_2=\{a,b\},\ Q_2=\{q_4,q_5,q_6\},\ S_2=q_4,\ T_2=\{q_6\}, \delta_2>$

Таблица переходов:

|       | a     | b     |
| ----- | ----- | ----- |
| $q_4$ | $q_4$ | $q_5$ |
| $q_5$ | $q_5$ | $q_6$ |
| $q_6$ | $q_6$ | $q_6$ |

Прямое произведение:

$<\Sigma=\{a,b\},\ Q=\{q_1q_4,q_1q_5,q_1q_6,q_2q_4,q_2q_5,q_2q_6,q_3q_4,q_3q_5,q_3q_6 \},\ S=q_1q_4,\ T=\{q_1q_6, q_2q_6, q_3q_6\}, \delta>$

Таблица переходов для результирующего автомата:

|          | a        | b        |
| -------- | -------- | -------- |
| $q_1q_4$ | $q_2q_4$ | $q_1q_5$ |
| $q_1q_5$ | $q_2q_5$ | $q_1q_6$ |
| $q_1q_6$ | $q_2q_6$ | $q_1q_6$ |
| $q_2q_4$ | $q_3q_4$ | $q_2q_5$ |
| $q_2q_5$ | $q_3q_5$ | $q_2q_6$ |
| $q_2q_6$ | $q_3q_6$ | $q_2q_6$ |
| $q_3q_4$ | -        | $q_3q_5$ |
| $q_3q_5$ | -        | $q_3q_6$ |
| $q_3q_6$ | -        | $q_3q_6$ |

Итоговый автомат:

![](SecondTask_3.gv.svg)  

3. $L = \{ w \in \{a, b\}^∗ : |w|_a \neq |w|_b \}$  

Попытаемя доказать, что он нерегулярный.
Рассмотрим $\overline{L}$:

$\overline{L} = \{ w \in \{a, b\}^∗ : |w|_a = |w|_b \}$

Применим лемму о накачке:

Фиксируем n.  
Пусть $w=a^nb^n \in\overline{L}; |w|\geq n$  
Все возможные разбиения этого слова при $|xy|\leq n$ и $|y|\geq 1$:  

$x=a^k$

$y=a^l$  

$z=a^{n-k-l}b^n$

Если здесь накачивать $y$, то букв $a$ в слове станет больше, чем букв $b$.  
Значит $\overline{L}$ - нерегулярный язык, а значит $L$ тоже нерегулярный.  



4. $L = \{ w \in \{a, b\}^∗ : ww = www \}$  
![](FirstTask_1_4.gv.svg)  
 
## **Задание 2**

1. $L_1 = \{ w \in \{a, b\}^∗ : |w|_a \geq 2 \land |w|_b \geq 2 \}$  
Первый автомат:  
$L_{11} = \{ w \in \{a, b\}^∗ : |w|_a \geq 2\}$  
Регулярка: $(a+b)^*a(a+b)^*a(a+b)^*$  
Автомат:  
![](SecondTask_1_1.gv.svg)    
$<\Sigma_1=\{a,b\},\ Q_1=\{q_1,q_2,q_3\},\ S_1=q_1,\ T_1=q_3,\ \delta_1>$    
Таблица переходов:  

|       | a     | b     |
| ----- | ----- | ----- |
| $q_1$ | $q_2$ | $q_1$ |
| $q_2$ | $q_3$ | $q_2$ |
| $q_3$ | $q_3$ | $q_3$ | 

Второй автомат:  
$L_{12} = \{ w \in \{a, b\}^∗ : |w|_b \geq 2\}$  
Регулярка: $(a+b)^*b(a+b)^*b(a+b)^*$  
Автомат:  
![](SecondTask_1_2.gv.svg)  
$<\Sigma_2=\{a,b\},\ Q_2=\{q_4,q_5,q_6\},\ S_2=q_4,\ T_2=q_6,\ \delta_2>$    
Таблица переходов:  
|       | a     | b     |
| ----- | ----- | ----- |
| $q_4$ | $q_4$ | $q_5$ |
| $q_5$ | $q_5$ | $q_6$ |
| $q_6$ | $q_6$ | $q_6$ |  

Прямое произведение этих двух ДКА:  
$<\Sigma=\{a,b\},\ Q=\{q_1q_4,q_1q_5,q_1q_6,q_2q_4,q_2q_5,q_2q_6,q_3q_4,q_3q_5,q_3q_6\},\ S=q_1q_4,\ T=q_3q_6,\ \delta>$  
Таблица переходов результирующего автомата:  
|          | a        | b        |
| -------- | -------- | -------- |
| $q_1q_4$ | $q_2q_4$ | $q_1q_5$ |
| $q_1q_5$ | $q_2q_5$ | $q_1q_6$ |
| $q_1q_6$ | $q_2q_6$ | $q_1q_6$ |
| $q_2q_4$ | $q_3q_4$ | $q_2q_5$ |
| $q_2q_5$ | $q_3q_5$ | $q_2q_6$ |
| $q_2q_6$ | $q_3q_6$ | $q_2q_6$ |
| $q_3q_4$ | $q_3q_4$ | $q_3q_5$ |
| $q_3q_5$ | $q_3q_5$ | $q_3q_6$ |
| $q_3q_6$ | $q_3q_6$ | $q_3q_6$ |  

Результирующий автомат:  
![](Second_Task_1_3.gv.svg)  


2. $L_2 = \{ w \in \{a, b\}^∗ : |w| \geq 3 \land |w|\ нечетное \}$  
Первый автомат:  
$L_{21} = \{ w \in \{a, b\}^∗ : |w| \geq 3\}$  
Регулярка: $(a+b)(a+b)(a+b)(a+b)^*$  
Автомат:  
![](SecondTask_2_1.gv.svg)    
$<\Sigma_1=\{a,b\},\ Q_1=\{q_1,q_2,q_3,q_4\},\ S_1=q_1,\ T_1=q_4,\ \delta_1>$    
Таблица переходов:  

|       | a     | b     |
| ----- | ----- | ----- |
| $q_1$ | $q_2$ | $q_2$ |
| $q_2$ | $q_3$ | $q_3$ |
| $q_3$ | $q_4$ | $q_4$ |
| $q_4$ | $q_4$ | $q_4$ |

Второй автомат:  
$L_{22} = \{ w \in \{a, b\}^∗ : |w|\ нечетное\}$  
Регулярка: $(a+b)((a+b)(a+b))^*$  
Автомат:  
![](SecondTask_2_2.gv.svg)  
$<\Sigma_2=\{a,b\},\ Q_2=\{q_5,q_6\},\ S_2=q_5,\ T_2=q_6,\ \delta_2>$    
Таблица переходов:  
|       | a     | b     |
| ----- | ----- | ----- |
| $q_5$ | $q_6$ | $q_6$ |
| $q_6$ | $q_5$ | $q_5$ |  

Прямое произведение двух этих ДКА:  

$<\Sigma=\{a,b\},\ Q=\{q_1q_5,q_1q_6,q_2q_5,q_2q_6,q_3q_5,q_3q_6,q_4q_5,q_4q_6\},\ S=q_1q_5,\ T=q_4q_6,\ \delta>$  
Таблица переходов результирующего автомата:  
|          | a        | b        |
| -------- | -------- | -------- |
| $q_1q_5$ | $q_2q_6$ | $q_2q_6$ |
| $q_1q_6$ | $q_2q_5$ | $q_2q_5$ |
| $q_2q_5$ | $q_3q_6$ | $q_3q_6$ |
| $q_2q_6$ | $q_3q_5$ | $q_3q_5$ |
| $q_3q_5$ | $q_4q_6$ | $q_4q_6$ |
| $q_3q_6$ | $q_4q_5$ | $q_4q_5$ |
| $q_4q_5$ | $q_4q_6$ | $q_4q_6$ |
| $q_4q_6$ | $q_4q_5$ | $q_4q_5$ |  

Результирующий автомат:  
![](SecondTask_2_3.gv.svg)  


3. $L_3 = \{ w \in \{a, b\}^∗ : |w|_a\ четно \land |w|_b\ кратно\ трем \}$  
Первый автомат:  
$L_{31} = \{ w \in \{a, b\}^∗ : |w|_a четно\}$  
Регулярка: $(b^*ab^*ab^*+b)^*$    
Автомат:  
![](SecondTask_3_1.gv.svg)    
$<\Sigma_1=\{a,b\},\ Q_1=\{q_1,q_2\},\ S_1=q_1,\ T_1=q_1,\ \delta_1>$    
Таблица переходов:  

|       | a     | b     |
| ----- | ----- | ----- |
| $q_1$ | $q_2$ | $q_1$ |
| $q_2$ | $q_1$ | $q_2$ |  

Второй автомат:  
$L_{32} = \{ w \in \{a, b\}^∗ : |w|_b\ кратно\ трем\}$  
Регулярка: $(a*ba*ba*ba*)^*$    
Автомат:  
![](SecondTask_3_2.gv.svg)  
$<\Sigma_2=\{a,b\},\ Q_2=\{q_3,q_4,q_5\},\ S_2=q_3,\ T_2=q_3,\ \delta_2>$    
Таблица переходов: 

|       | a     | b     |
| ----- | ----- | ----- |
| $q_3$ | $q_3$ | $q_4$ |
| $q_4$ | $q_4$ | $q_5$ |  
| $q_5$ | $q_5$ | $q_3$ |    

Прямое произведение двух этих ДКА:  

$<\Sigma=\{a,b\},\ Q=\{q_1q_3,q_1q_4,q_1q_5,q_2q_3,q_2q_4,q_2q_5\},\ S=q_1q_3,\ T=q_1q_3,\ \delta>$  
Таблица переходов результирующего автомата:  
|          | a        | b        |
| -------- | -------- | -------- |
| $q_1q_3$ | $q_2q_3$ | $q_1q_4$ |
| $q_1q_4$ | $q_2q_4$ | $q_1q_5$ |
| $q_1q_5$ | $q_2q_5$ | $q_1q_3$ |
| $q_2q_3$ | $q_1q_3$ | $q_2q_4$ |
| $q_2q_4$ | $q_1q_4$ | $q_2q_5$ |
| $q_2q_5$ | $q_1q_5$ | $q_2q_3$ |  

Результирующий автомат:  
![](SecondTask_3_3.gv.svg) 

4. $L_4 = \overline{L_3}$  
  $\overline{L_3}$ = $<\Sigma,Q,S,Q \backslash T, \delta>$  
  То есть, автомат для $L_4$ - это автомат, похожий на $L_3$, в котором терминальные и нетерминальные состояния инвертированы:  
  ![](SecondTask_4.gv.svg) 

5. $L_4 = L_2 \backslash L_3$  
$L_4 = L_2 \backslash L_3 = L_2 \cap \overline L_3$  
Первый автомат:  
![](SecondTask_2_3.gv.svg)   
$L_2=<\Sigma=\{a,b\},\ Q=\{q_1,q_2,q_3,q_4\},\ S=q_1,\ T=q_4,\ \delta>$  
Таблица переходов первого автомата:  

|       | a     | b     |
| ----- | ----- | ----- |
| $q_1$ | $q_2$ | $q_2$ |
| $q_2$ | $q_3$ | $q_3$ |
| $q_3$ | $q_4$ | $q_4$ |
| $q_4$ | $q_3$ | $q_3$ |

Второй автомат:  
![](SecondTask_4.gv.svg)  
$\overline{L_3}$ = $<\Sigma=\{a,b\},\ Q=\{q_5,q_6,q_7,q_8,q_9,q_10\},\ S=q_5,\ T=\{q_6,q_7,q_8,q_9,q_{10} \},\ \delta>$  
Таблица переходов второго автомата:  

|          | a     | b     |
| -----    | ----- | ----- |
| $q_5$    | $q_6$ | $q_7$ |
| $q_6$    | $q_5$ | $q_8$ |
| $q_7$    | $q_8$ | $q_9$ |
| $q_8$    | $q_7$ | $q_{10}$ |
| $q_9$    | $q_{10}$ | $q_5$ |
| $q_{10}$ | $q_9$ | $q_6$ |  

Прямое произведение двух этих ДКА:  

$<\Sigma=\{a,b\},\ Q=\{q_1q_5,q_1q_6,q_1q_7,q_1q_8,q_1q_9,q_1q_{10},q_2q_5,q_2q_6,q_2q_7,q_2q_8,q_2q_9,q_2q_{10},q_3q_5,q_3q_6,q_3q_7,q_3q_8,q_3q_9,q_3q_{10},q_4q_5,q_4q_6,q_4q_7,q_4q_8,q_4q_9,q_4q_{10}\}\ S=q_1q_5,\ T={q_4q_6,q_4q_7,q_4q_8,q_4q_9,q_4q_{10} },\ \delta>$  
Таблица переходов результирующего автомата:  
|          | a        | b        |
| -------- | -------- | -------- |
| $q_1q_5$ | $q_2q_6$ | $q_2q_7$ |
| $q_1q_6$ | $q_2q_5$ | $q_2q_8$ |
| $q_1q_7$ | $q_2q_8$ | $q_2q_9$ |
| $q_1q_8$ | $q_2q_7$ | $q_2q_{10}$ |
| $q_1q_9$ | $q_2q_{10}$ | $q_2q_5$ |
| $q_1q_{10}$ | $q_2q_9$ | $q_2q_6$ |
| $q_2q_5$ | $q_3q_6$ | $q_3q_7$ |
| $q_2q_6$ | $q_3q_5$ | $q_3q_8$ |
| $q_2q_7$ | $q_3q_8$ | $q_3q_9$ |
| $q_2q_8$ | $q_3q_7$ | $q_3q_{10}$ |
| $q_2q_9$ | $q_3q_{10}$ | $q_3q_5$ |
| $q_2q_{10}$ | $q_3q_9$ | $q_3q_6$ |
| $q_3q_5$ | $q_4q_6$ | $q_4q_7$ |
| $q_3q_6$ | $q_4q_5$ | $q_4q_8$ |
| $q_3q_7$ | $q_4q_8$ | $q_4q_9$ |
| $q_3q_8$ | $q_4q_7$ | $q_4q_{10}$ |
| $q_3q_9$ | $q_4q_{10}$ | $q_4q_5$ |
| $q_3q_{10}$ | $q_4q_9$ | $q_4q_6$ |    
| $q_4q_5$ | $q_3q_6$ | $q_3q_7$ |
| $q_4q_6$ | $q_3q_5$ | $q_3q_8$ |
| $q_4q_7$ | $q_3q_8$ | $q_3q_9$ |
| $q_4q_8$ | $q_3q_7$ | $q_3q_{10}$ |
| $q_4q_9$ | $q_3q_{10}$ | $q_3q_5$ |
| $q_4q_{10}$ | $q_3q_9$ | $q_3q_6$ |  

Результирующий автомат:  
![](Task_4_5.gv.svg)


## **Задание 3**  

1. $(ab+aba)^*$  
$ab$:  
![](ThirdTask_1_1.gv.svg)  
$aba$:  
![](ThirdTask_1_2.gv.svg)  
$ab+aba$:  
![](ThirdTask_1_3.gv.svg)  
$(ab+aba)^*$:  
![](ThirdTask_1_4.gv.svg)  
![](ThirdTask_1_5.gv.svg)  
$(ab+aba)^*a$:  
![](ThirdTask_1_6.gv.svg)    

2. $a(a(ab)^*b)^*(ab)^*$  
$ab$:  
![](ThirdTask_2_1.gv.svg)  
$(ab)^*$:  
![](ThirdTask_2_2.gv.svg)  
$a(ab)^*$:  
![](ThirdTask_2_3.gv.svg)  
$a(ab)^*b$:  
![](ThirdTask_2_4.gv.svg)  
$(a(ab)^*b)^*$:  
![](ThirdTask_2_5.gv.svg)  
$a(a(ab)^*b)^*$:  
![](ThirdTask_2_6.gv.svg)  
$a(a(ab)^*b)^*(ab)^*$:  
![](ThirdTask_2_6.gv.svg)        

3. $(a+(a+b)(a+b)b)^*$  
$(a+b)(a+b)b$:  
![](ThirdTask_3_1.gv.svg)  
$(a+(a+b)(a+b))b$:  
![](ThirdTask_3_2.gv.svg)  
![](ThirdTask_3_3.gv.svg)  
$(a+(a+b)(a+b))^*b$:  
![](ThirdTask_3_4.gv.svg)  
![](ThirdTask_3_5.gv.svg)  
![](ThirdTask_3_6.gv.svg)  
![](ThirdTask_3_7.gv.svg)        

4. $(b+c)((ab)^*c+(ba)^*)^*$  
$(ab)^*$:  
![](ThirdTask_4_1.gv.svg)  
$(ab)^*c$:  
![](ThirdTask_4_2.gv.svg)  
$(ba)^*$:  
![](ThirdTask_4_3.gv.svg)  
$(ab)^*c+(ba)^*$:  
![](ThirdTask_4_4.gv.svg)  
![](ThirdTask_4_5.gv.svg)  
$((ab)^*c+(ba)^*)^*$:  
![](ThirdTask_4_6.gv.svg)  
$(b+c)((ab)^*c+(ba)^*)^*$:  
![](ThirdTask_4_7.gv.svg)    



5. $(a+b)^+(aa+bb+abab+baba)(a+b)^+$  
$(a+b)^+$:  
![](ThirdTask_5_1.gv.svg)  
$aa+bb$  
![](ThirdTask_5_2.gv.svg)  
$aa+bb+abab$:    
![](ThirdTask_5_3.gv.svg)  
$aa+bb+abab+baba$:  
![](ThirdTask_5_4.gv.svg)  
$(a+b)^+(aa+bb+abab+baba)(a+b)^+$:  
![](ThirdTask_5_5.gv.svg)  
![](ThirdTask_5_6.gv.svg)  



## **Задание 4**  

1. $L = \{ (aab)^nb(aba)^m : n \geq 0,\ m \geq 0 \}$  
Регулярка: $(aab)^*b(aba)^*$  
$aab:$  
![](Task_4_1.gv.svg)  
$(aab)^*:$  
![](Task_4_2.gv.svg)  
$(aab)^*b:$  
![](Task_4_3.gv.svg)  
Итоговый автомат для $(aab)^*b(aba)^*:$  
![](Task_4_4.gv.svg)  

1. $L = \{ uaav : u \in \{a,b\}^*,\ v \in \{a,b\}^*,\ |u|_b \geq |v|_a \}$  
Рассмотри $\overline{L}$:  
$\overline{L}=\{ uaav : u \in \{a,b\}^*,\ v \in \{a,b\}^*,\  |v|_a > |u|_b\}$  
Применим к нему лемму о накачке:  
Фиксируем n.  
Пусть $w=b^naaa^{n+1} \in \overline{L};\ |w| \geq n$.  
Все возможные разбиения при $|xy| \leq n$ и $|y| \geq 1$:  
$x=b^l$  
$y=b^k$  
$z=b^{n-l-k}aaa^{n+1}$  
Если здесь накачивать $y$, то число букв $b$ станет больше, чем букв $a$ и слово уже не будет принадлежать $\overline{L}$. Значит язык $\overline{L}$ - нерегулярный. Следовательно язык $L$ тоже нерегулярный.   

3. $L = \{ a^mw : w  \in \{a, b\}^*,\ 1\leq |w|_b \leq m \}$  
Рассмотрим $\overline{L}$:  
$\overline{L} = \{ a^mw : w  \in \{a, b\}^*,\ |w|_b > m\  \lor\ |w|_b=0\}$  
Применим к нему лемму о накачке:  
Фиксируем n.  
Пусть $w=a^nb^{n+1} \in \overline{L};\ |w| \geq n$  
Все возможные разбиения при $|xy| \leq n$ и $|y| \geq 1$:  
$x=a^l$  
$y=a^k$  
$z=a^{n-l-k}b^{n+1}$  
Если здесь накачивать $y$, то букв $a$ станет больше, чем букв $b$, и перестанет выполняться условие $|w|_b > m$. Значит язык $\overline{L}$ - нерегулярный. Следовательно $L$ тоже нерегулярный. 

4. $L = \{ a^kb^ma^n : k = n\ \lor\ m > 0\}$  
Применим к нему лемму о накачке:  
Фиксируем n.  
Пусть $w=a^nba^n \in L;\ |w| \geq n$    
Все возможные разбиения:  
$x=a^l$  
$y=a^k$  
$z=a^{n-l-k}ba^n$  
Если здесь накачивать $y$, то равенство $k=n$ перестанет выполняться. Значит $L$ - нерегулярный язык. 

5. $L = \{ ucv : u \in \{a,b\}^*,\ v \in \{a,b\}^*,\ u\neq v^R\}$  
Рассмотри $\overline{L}$:  
$\overline{L}=\{ ucv : u \in \{a,b\}^*,\ v \in \{a,b\}^*,\ u = v^R\}$  
Применим к нему лемму о накачке:  
Фиксируем n.  
Пусть $w=a^nca^n \in \overline{L};\ |w| \geq n$  
Все возможные разбиения при $|xy| \leq n$ и $|y| \geq 1$:  
$x=a^l$  
$y=a^k$  
$z=a^{n-l-k}ca^n$  
Если здесь накачивать $y$, то число букв $a$ вначале будет увеличиваться, и условие $u=v^R$ перестанет выполняться. Значит $\overline{L}$ - нерегулярный язык. Следовательно $L$ тоже нерегулярный.


## **Задание 5**
