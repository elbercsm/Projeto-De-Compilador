algoritmo "algoritmo5"
var
   a, b, c, delta, x1, x2: REAL

funcao calcula_delta(): REAL
var
   delta : REAL
inicio
      delta := b*b - 4*a*c
      RETORNE delta
fimfuncao

inicio
      ESCREVA("Informe o valor de A: ")
      LEIA (a)
      ESCREVA("Informe o valor de B: ")
      LEIA (b)
      ESCREVA("Informe o valor de C: ")
      LEIA (c)
      //chamando a funcao
      delta := calcula_delta()
      SE ( delta < 0 ) ENTAO
         ESCREVA ("Esta equação não possui raízes reais.")
      SENAO
           SE (delta = 0) ENTAO
              x1 := (-b + RAIZQ(delta)) / (2*a)
              ESCREVA ("Esta equação possui apenas uma raiz: ", x1)
           SENAO
                x1 := (-b + RAIZQ(delta)) / (2*a)
                x2 := (-b - RAIZQ(delta)) / (2*a)
                ESCREVA ("Esta equação possui duas raízes: ", x1, " e ", x2)
           FIMSE
      FIMSE
fimalgoritmo