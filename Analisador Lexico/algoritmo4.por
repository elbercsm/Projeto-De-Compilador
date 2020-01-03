algoritmo "algoritmo4"
// Função :
// Autor :
// Data : 01/11/2019
// Seção de Declarações 
/* 
	Cometario em 
	bloco
*/
var
	notas: vetor [1..5] de real
	media, aux: real
	i: inteiro
inicio
	para i de 1 ate 5 faca
		escreval("Informe a nota do ", i, " aluno: ")
		leia(notas[i])
	fimpara

	i := 1
	repita
		escreval("Notas informadas: ", notas[i])
		i := i + 1
	ate i = 6

	i := 1
	enquanto i <= 5 faca
		aux := aux + notas[i]
		i := i + 1
	fimenquanto

	media := aux / 5
	escreval("Media: ", media)

fimalgoritmo