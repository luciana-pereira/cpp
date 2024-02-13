# Modulo 02

- #### Ex 00
- #### Ex 01
- #### Ex 02
- #### Ex 03
O objetivo deste programa é implementar e verificar se determinado ponto (Point) está dentro de um triângulo
utilizando o conceito de particionamento binário de espaço (BSP - Binary Space Partitioning).

**Entrada:** A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)</br>
**Saída:** Dentro</br>
**Explicação:**
```
             B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 
```

**Entrada:** A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)</br>
**Saída:** Fora</br>
**Explicação:**
```
             B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 
```

**Solução:** As coordenadas dos três cantos (x1, y1), (x2, y2) e (x3, y3). E as coordenadas do ponto dado P são (x, y).
Calcule a área do triângulo fornecido, ou seja, a área do triângulo ABC no diagrama acima.</br>

Área **A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2**

Devemos calcular a área do triângulo **PAB**, podemos usar a mesma fórmula acima para isso e determinar a área como **A1**.</br>
Calcular a área do triângulo **PBC**, e determinar a área como **A2**.</br>
Calcular a área do triângulo **PAC**, e determinar a área como **A3**.</br>
Se **P** estiver dentro do triângulo, então **A1 + A2 + A3** deve ser igual a **A**.</br>
