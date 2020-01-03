algoritmo comandos_da_linguagem;

variaveis
	x, q : real;
	y, z : inteiro;
	k, i : logico;
	a : literal;
fim-variaveis

funcao soma();
	variaveis
		res : inteiro;
	fim-variaveis
	inicio
		res = 2 + 3;
	fim
fim-funcao

inicio
	x = 2.6;
	y = 6;
	z = 12;
	k = verdadeiro;
	i = falso;
	se (x == 2.6) entao
		x = 43.2;
	fim-entao
	enquanto x < 456.2 faca
		x = 333.2;
	fim-enquanto
	se (y > z) entao
		se (q > x) entao
			x = -3.2;
		fim-entao
	fim-entao
	senao
		y = 345;
	fim-senao
	enquanto x <> 4.2 faca
		y = 2;
		z = 2;
	fim-enquanto
	enquanto y > 3 faca
		enquanto y > 4 faca
			se (y < 1) entao
				y = 0;
			fim-entao
		fim-enquanto
	fim-enquanto
	para x de 1 ate 10 faca
		se (q <> 0.1) entao
			para y de 0 ate 9 passo 1 faca
				x = -35.3;
			fim-para
		fim-entao
	fim-para
	para y de -4 ate 99 passo 4 faca
		enquanto y < 98 faca
			se (q == 0.3) entao
				y = 3;
			fim-entao
			senao
				y = 0;
			fim-senao
		fim-enquanto
		para x de 2 ate 3 faca
			x = 3.22222;
		fim-para
	fim-para
	escreva(x);
	leia();
fim
