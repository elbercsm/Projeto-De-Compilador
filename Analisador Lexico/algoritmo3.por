algoritmo "algoritmo3"

var
nome: caractere
nota1, nota2, media: real
 
inicio
 
escreva("Informe o nome do aluno: ")
leia(nome)
escreva("Informe a nota da P1: ")
leia(nota1)
escreva("Informe a nota da P2: ")
leia(nota2)
 
media <- (nota1 + nota2) / 2
 
se ( media >= 7) entao
   escreval("A média do aluno ", nome, " é:", media)
senao
   escreval("O aluno ", nome, " não alcançou a média.")
fimse
 
fimalgoritmo