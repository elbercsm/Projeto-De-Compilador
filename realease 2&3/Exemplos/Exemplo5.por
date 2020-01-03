algoritmo cyber_akuma;

variaveis
	i,j : inteiro;
	r : real;
	nome, cara : literal;
	x, y, z: logico;
	v : matriz[2] de real;
	m : matriz[3][4] de literal;
	a : real;
fim-variaveis

funcao soma(x : inteiro, y : inteiro);
	variaveis
		res : inteiro;
	fim-variaveis

	inicio
		res = x + y;
		retorne res;
	fim
fim-funcao

funcao soma2(x : inteiro, y : real) : inteiro;
	variaveis
		res : inteiro;
	fim-variaveis
	inicio  
		res = x + y;
		retorne res;
	fim
fim-funcao

funcao soma3() : inteiro;
	variaveis
		res : inteiro;
	fim-variaveis
	inicio
		res = 4 ^ 4;
		retorne res;
	fim
fim-funcao

função fatorial(z:real) : real;
	início
		se z == 1.2 então
			retorne 1.2;
		fim-entao
		senão
			retorne fatorial(z);
		fim-senao
	fim
fim-funcao

inicio
	i = 15 + 12 / 13;
	r = 3.2 + 59.2*0.11;
	i = 3 - (3) + 3/3;
	nome = "hue";
	cara = 'c';
	x = verdadeiro;
	y, z = falso;
	v[2] = -3.16 ;
	m[1][1] = "doge";
	soma(i,j);
	i = soma2(i,r);
	j = soma3();
	a = fatorial(a);
	leia();
fim
