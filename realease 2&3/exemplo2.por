algoritmo funcao_teste;

variaveis
	x : inteiro;
	y : inteiro;
	i : inteiro;
	z : real;
	a : real;
fim-variaveis


procedimento soma(x : inteiro, y : inteiro);
	variaveis
		res : inteiro;
	fim-variaveis

	inicio
		res := x + y;
		retorne res;
	fim
fim-procedimento

funcao soma2(x : inteiro, y : inteiro) : inteiro;
	variaveis
		res : inteiro;
	fim-variaveis
	inicio  
		res := x + y;
		retorne res;
	fim
fim-funcao

funcao soma3() : inteiro;
	variaveis
		res : inteiro;
	fim-variaveis
	inicio
		res := 4 ^ 4;
		retorne res;
	fim
fim-funcao

função fatorial(z:real) : real;
	início
		se z == 1.2 então
			retorne 1.2;
		fim-se
		senão
			retorne fatorial(z-1.2);
		fim-senao
	fim
fim-funcao

inicio
	x := 2;
	y := 3;
	z := 4.2;
	soma(x,y);
	x := soma2(x,y);
	y := soma3();
	a := fatorial(a);
	leia(x);
	i := 0;
	repita 
    escreval("repetindo"); 
    i := i +1; 
    ate(i == 10) 
fim
