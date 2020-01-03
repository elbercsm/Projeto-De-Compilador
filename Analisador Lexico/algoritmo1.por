algoritmo "algoritmo1"
var
   numero1 : real
   numero2 : real
   nome : caractere
   resultado : real
inicio

   escreva("Digite o primeiro número: ")
   leia(numero1)
   escreva("Digite a operação: ")
   leia(operacao)
   escreva("Digite o segundo número: ")
   leia(numero2)

   escolha operacao
      caso "soma"
         resultado := numero1 + numero2
      caso "subtracao"
         resultado := numero1 - numero2
      caso "multiplicacao"
         resultado := numero1 * numero2
      caso "divisao"
         resultado := numero1 / numero2
      outro caso
         resultado := numero1
   fimescolha

   escreva("Resultado: ", resultado)

fimalgoritmo