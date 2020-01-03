algoritmo declaracao_de_variavel_e_atribuicao;

var
	i,j : inteiro;
	r : real;
	nome, cara : literal;
	x, y, z: logico;
	v : matriz[2] de real;
	m : matriz[3][4] de literal;
fim-var

inicio
	i := 15 + 12 / 13;
	j := -257;
	r := 26.58754;
	r <- 45.2/28.2;
	r <- 3.2 + 59.2*0.11;
	i <- 4 ^ 2;
	i <- 3 - (3) + 3/3;
	nome := "hue";
	cara <- 'c';
	x := verdadeiro;
	y, z <- falso;
	v[2] := -3.16 ; //VETOR
	m[1][1] <- "doge"; //MATRIZ
fim-algoritmo
