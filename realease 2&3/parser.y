%{
#include <stdio.h>
#include "hash.h"

Lista *lista_var, *lista_func, *var, *func, *doge;
Lista **tabela_hash_var, **tabela_hash_func;
Pilha *pilha_termo, *pilha_op; //TERMO: 0 = int, 1 = real, 2 = logico, 3 = ident; OP: + = 0, - = 1, * = 2, / = 3, ^ = 4, and = 5, or = 6.
int qtd_param = 0;
char nome_func[100];
char nome_func2[100];
char nome_var[100];
int tipo_parametros[10];

int ARIDADE_FUNC = 0;

extern int nlinhas;
extern int nColunas;
extern char vlr_int[100];
extern char * yytext;
extern char ident[100];

int tipo_termos, tipo_operadores;
int TIPO_VAR = 0;
int TIPO_ATRIB = 0;
int TIPO_TERMO;
int TIPO_OP;
int ESCOPO_VAR = 0;
int flag_valorEhFuncao = 0; // VALOR era uma Chamada de Funcao 1
int flag_cmdChamada = 0; // Quando funcao eh chamada sozinha
int flag_ehMatriz = 0;
int flag_eh_arg = 0;
int DIM_M, DIM_N = 1;

//Busca a variavel na tabela e 'seta' se eh usada ou se nao encontrar a variavel, erro.
void doge_var(Lista** tab, Lista* v, char* nom, int esc)
{ 
	v = busca(tab, nom, esc);
	if(v == NULL){
		printf(" Erro semantico: Variavel %s nao declarada. Escopo: %d, Linha: %d, Coluna %d \n", nom, esc, nlinhas, nColunas);
		exit(0);
		
	}else{
		set_usada(v);
	}
	v = inicializa(); 
}

%}

%token token_var_fim
%token token_var
%token token_char
%token token_algoritmo
%token token_if
%token token_do
%token token_do_end
%token token_strings
%token token_string
%token token_fim
%token token_else
%token token_while_end
%token token_matriz
%token token_booleans
%token token_boolean
%token token_or
%token token_then
%token token_for
%token token_for_end
%token token_ints
%token token_func
%token token_func_fim
%token token_proc
%token token_proc_fim
%token token_switch
%token token_switch_end
%token token_case
%token token_default
%token token_int
%token token_inicio
%token token_and
%token token_if_end
%token token_then_end
%token token_else_end
%token token_de
%token token_ate
%token token_repeat
%token token_reals
%token token_return
%token token_real
%token token_not
%token token_while
%token token_chars
%token token_passo
%token token_print
%token token_read
%token token_central
%token token_minimo
%token token_maximo

%token token_aspas
%token token_atrib
%token token_maior
%token token_maior_igual
%token token_menor
%token token_menor_igual
%token token_igual
%token token_diferente
%token token_mais
%token token_menos
%token token_div
%token token_mult
%token token_pot
%token token_mod
%token token_increment
%token token_decrement

%token token_colchete_abre
%token token_colchete_fecha
%token token_abreParen
%token token_fechaParen
%token token_pt
%token token_virg
%token token_pt_virg
%token token_dois_pt
%token token_hashtag
%token token_chaves_abre
%token token_chaves_fecha
%token token_apost
%token token_cbarra

%token token_vlr_inteiro
%token token_vlr_real
%token token_vlr_char
%token token_true
%token token_false
%token token_ident
%token token_vlr_string

%start PROG

%%


PROG: 
	  token_algoritmo token_ident INSERE_INIT token_pt_virg BLOCO
	| token_algoritmo token_ident INSERE_INIT token_pt_virg ;

INSERE_INIT:{ 
	// inserindo o nome da main na tabela de variaveis

	lista_var = insere_variavel_lista(lista_var, ident, 1); // 1 = usado
	insere_variavel_hash(tabela_hash_var, lista_var, -1, 0);
	libera(lista_var);
	lista_var = inicializa();

	//inserindo as funcoes primitivas da linguagem na tabela de funcoes

	tabela_hash_func = insere_funcao(tabela_hash_func, "leia", -1, 0);
	tipo_parametros[0] = -1;
	insere_parametro_funcao(tabela_hash_func,"leia",tipo_parametros);

	tipo_parametros[0]=0;
	tipo_parametros[1]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "escreva", -1, 1);
	insere_parametro_funcao(tabela_hash_func,"escreva",tipo_parametros);

	tipo_parametros[0]=0;
	tipo_parametros[1]=0;
	tipo_parametros[2]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "maximo", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"maximo",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "minimo", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"minimo",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "%", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"%",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "^", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"^",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "+", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"+",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "-", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"-",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "*", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"*",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "/", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"/",tipo_parametros);

	tipo_parametros[2]=0;
	tipo_parametros[3]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "central", 0, 3);
	insere_parametro_funcao(tabela_hash_func,"central",tipo_parametros);
	
};

BLOCO:
	  DECL_VAR MAIS_FUNCOES { ESCOPO_VAR = 0; } BLOCO_MAIN 
	| BLOCO_MAIN
	| DECL_VAR BLOCO_MAIN
	| MAIS_FUNCOES { ESCOPO_VAR = 0; } BLOCO_MAIN ;

BLOCO_MAIN:
	  token_inicio LISTA_CMD token_fim
	| token_inicio token_fim ;

DECL_VAR:
	  token_var LISTA_VAR token_var_fim
	| token_var token_var_fim;

MAIS_FUNCOES:
	  MAIS_FUNCOES DECL_FUNC token_func_fim
	| DECL_FUNC token_func_fim
	| MAIS_FUNCOES DECL_FUNC token_proc_fim
	| DECL_FUNC token_proc_fim ;

LISTA_VAR:
	  LISTA_VAR REC_IDENT token_dois_pt TIPO COD1 token_pt_virg 
	| REC_IDENT token_dois_pt TIPO COD1 token_pt_virg ;

COD1: {
	if (flag_ehMatriz == 0) {
		DIM_M = 1;
		DIM_N = 1;
		insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR); 
	}
	else {
		edita_para_matriz(lista_var, DIM_M, DIM_N);
		insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR);
		DIM_M = 1;
		DIM_N = 1;
	}
	libera(lista_var);
	lista_var = inicializa();
} ;

REC_IDENT: 
	  REC_IDENT token_virg token_ident { lista_var = insere_variavel_lista(lista_var, ident,0); }
	| token_ident { lista_var = insere_variavel_lista(lista_var, ident,0); } ;

BLOCO_FUNC:
	  DECL_VAR BLOCO_MAIN 
	| BLOCO_MAIN;

DECL_FUNC: 
	  token_func token_ident STRCPY_FUNC PARAMETROS token_dois_pt TIPO INSERE_FUNC_TAB token_pt_virg BLOCO_FUNC
	| token_proc token_ident STRCPY_FUNC PARAMETROS INSERE_PROC_TAB token_pt_virg BLOCO_FUNC
	| token_func token_ident STRCPY_FUNC PARAMETROS token_dois_pt TIPO INSERE_FUNC_TAB token_pt_virg
	| token_proc token_ident STRCPY_FUNC PARAMETROS INSERE_PROC_TAB token_pt_virg ;

STRCPY_FUNC: { strcpy(nome_func, ident); strcpy(nome_func2, nome_func); ESCOPO_VAR++;} ;

INSERE_FUNC_TAB: {
	func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
	if(func) {
		printf(" Erro semantico: Funcao %s redeclarada. Escopo: %d, Linha: %d, Coluna %d \n", nome_func, ESCOPO_VAR, nlinhas, nColunas);
		exit(0);
	}
	tabela_hash_func = insere_funcao(tabela_hash_func, nome_func, TIPO_VAR, qtd_param); // TIPO_VAR eh o tipo de retorno da funcao
	tipo_parametros[qtd_param] = -1;
	tabela_hash_func = insere_parametro_funcao(tabela_hash_func, nome_func, tipo_parametros);
	qtd_param = 0;
};

INSERE_PROC_TAB: {
	func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
	if(func) {
		printf(" Erro semantico: Funcao %s redeclarada. Escopo: %d, Linha: %d, Coluna %d \n", nome_func, ESCOPO_VAR, nlinhas, nColunas);
		exit(0);
	}
	tabela_hash_func = insere_funcao(tabela_hash_func, nome_func, -1, qtd_param); // -1 eh o TIPO_VAR para funcoes que nao tem retorno, ou seja, para procedimentos
	tipo_parametros[qtd_param] = -1;
	tabela_hash_func = insere_parametro_funcao(tabela_hash_func, nome_func, tipo_parametros);
	qtd_param = 0;
};

PARAMETROS:
	  token_abreParen LISTA_PARAM token_fechaParen
	| token_abreParen token_fechaParen;

LISTA_PARAM:
	  LISTA_PARAM token_virg token_ident INSERE_VAR_LISTAPARAM token_dois_pt TIPO INSERE_LISTAPARAM_HASH
	| token_ident INSERE_VAR_LISTAPARAM token_dois_pt TIPO INSERE_LISTAPARAM_HASH ;

INSERE_VAR_LISTAPARAM: { 
	strcpy(nome_var, yytext); 
	lista_var = insere_variavel_lista(lista_var, yytext, 0); 
	qtd_param++; 
};

INSERE_LISTAPARAM_HASH: { 
	insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR); 
	doge_var(tabela_hash_var, var, nome_var, 0); 
	libera(lista_var); 
	lista_var = inicializa(); 
	tipo_parametros[qtd_param -1] = TIPO_VAR;
};

//-------------------------------------------------------------------------------------------------------------

LISTA_CMD: 
	  LISTA_CMD CMD 
	| CMD ;

CMD: 
	  CMD_WHILE
	| CMD_DO_WHILE
	| CMD_FOR 
	| CMD_SIMPLES token_pt_virg 
	| CMD_REPEAT
	| CMD_IF ;

CMD_IF: 
	  token_if EXPRESSAO token_then LISTA_CMD token_then_end
	| token_if EXPRESSAO token_then LISTA_CMD token_then_end token_else LISTA_CMD token_else_end ;

CMD_DO_WHILE: token_do LISTA_CMD token_do_end token_while EXPRESSAO ;

CMD_REPEAT: token_repeat LISTA_CMD token_ate EXPRESSAO;


CMD_WHILE:
	  token_while EXPRESSAO token_do LISTA_CMD token_while_end
	| token_while EXPRESSAO token_do token_while_end ;

CMD_FOR:
	 token_for TK_IDENT token_de IDENT_OU_INT token_ate IDENT_OU_INT token_do LISTA_CMD token_for_end
       | token_for TK_IDENT token_de IDENT_OU_INT token_ate IDENT_OU_INT token_passo IDENT_OU_INT token_do LISTA_CMD token_for_end
       | token_for TK_IDENT token_de IDENT_OU_INT token_ate IDENT_OU_INT token_do token_for_end
       | token_for TK_IDENT token_de IDENT_OU_INT token_ate IDENT_OU_INT token_passo IDENT_OU_INT token_do token_for_end ;

IDENT_OU_INT: 
	  TK_IDENT
	| token_vlr_inteiro
	| token_menos token_vlr_inteiro ;

CMD_SIMPLES: 
	  ATRIB 
	| CHAMADA_FUNCAO {
		  if (get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR)) != -1){
			 printf(" Erro semantico: Funcao com retorno porem sem atribuicao. Funcao: %s, Linha: %d, Coluna %d\n", nome_func, nlinhas, nColunas);
			exit(0);	
		}
	}
	| CMD_IMPRIMA
	| CMD_LEIA
	| CMD_MINIMO
	| CMD_MAXIMO
	| CMD_CENTRAL
	| RETURN 
  | OP_INCR;

//-------------------------------------------------------------------------------------------------------------
ATRIB: IDENTS { TIPO_ATRIB = get_tipo(busca(tabela_hash_var,nome_var,ESCOPO_VAR)); } token_atrib VALOR { 
	if (flag_valorEhFuncao == 1){
		if(TIPO_ATRIB != get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR))){
			printf(" Erro semantico: Funcao com tipo de retorno incompativel. Funcao: %s, Linha: %d, Coluna %d \n", nome_func, nlinhas, nColunas);
			exit(0);
		}
		flag_valorEhFuncao = 0;
	}
};

IDENTS: 
	  IDENTS token_virg TK_IDENT {doge_var(tabela_hash_var, var, nome_var, ESCOPO_VAR);}
	| TK_IDENT {doge_var(tabela_hash_var, var, nome_var, ESCOPO_VAR);};

CMD_IMPRIMA: token_print token_abreParen ARG {flag_eh_arg = 0;} token_fechaParen ;

ARG: 
	  ARG token_virg {flag_eh_arg = 1;} VALOR VERIFICA_VAR_DECLARADA
	| {flag_eh_arg = 1;} VALOR VERIFICA_VAR_DECLARADA ;

VERIFICA_VAR_DECLARADA: {
	var = busca(tabela_hash_var,ident,ESCOPO_VAR);
	if (var == NULL)
		{
			printf(" Erro semantico: Variavel %s nao declarada. Linha: %d, Coluna %d.\n", ident, nlinhas, nColunas);
			exit(0);
		}
	doge = insere_variavel_lista1(doge,ident,get_tipo(var),get_escopo(var),get_usada(var));
	qtd_param++;
};

CMD_LEIA: token_read token_abreParen token_fechaParen
		| token_read token_abreParen token_ident token_fechaParen;

CMD_CENTRAL: token_central token_abreParen IDENT_OU_NUM token_virg IDENT_OU_NUM token_virg IDENT_OU_NUM token_fechaParen ;

IDENT_OU_NUM: IDENT_OU_INT
			| token_vlr_real
			| token_menos token_vlr_real ;

CMD_MINIMO: token_minimo token_abreParen IDENT_OU_NUM token_virg IDENT_OU_NUM token_fechaParen ;
CMD_MAXIMO: token_maximo token_abreParen IDENT_OU_NUM token_virg IDENT_OU_NUM token_fechaParen ;

RETURN: token_return EXPRESSAO {flag_valorEhFuncao = 0;} ;

STRCPY_IDENT: token_ident { strcpy(nome_func, ident); } ;

CHAMADA_FUNCAO: 
	STRCPY_IDENT token_abreParen ARG { flag_eh_arg = 0; } token_fechaParen
	{	
		func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
		if (func == NULL){
				printf(" Erro semantico: Funcao nao declarada. Funcao: %s, Linha: %d, Coluna %d.\n", nome_func, nlinhas, nColunas);
				exit(0);
		}
		if (get_aridade(func) != qtd_param){
				printf(" Erro semantico: Quantidade de parametros errada. Funcao %s, Linha: %d, Coluna %d.\n", nome_func, nlinhas, nColunas);
				exit(0);
		}
		if (verifica_tipo_parametros_funcao(tabela_hash_func, nome_func, doge) == 0){
				printf(" Erro semantico: Tipo de parametros errado. Funcao: %s, Linha: %d, Coluna %d.\n", nome_func, nlinhas, nColunas);			
				exit(0);
		}
		qtd_param = 0;
		doge = inicializa();	
	}
	| STRCPY_IDENT token_abreParen token_fechaParen { 
		strcpy(nome_func, ident);
		func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
		if (func == NULL){
				printf(" Erro semantico: Funcao nao declarada. Funcao: %s, Linha: %d, Coluna %d.\n", nome_func, nlinhas, nColunas);
				exit(0);
		}
		if (get_aridade(func) > 0){
				printf(" Erro semantico: Quantidade de parametros errada. Funcao: %s, Linha: %d, Coluna %d.\n", nome_func, nlinhas, nColunas);
				exit(0);
		}
	};

//-------------------------------------------------------------------------------------------------------------"

TIPO: 
	  TIPO_PRIM {flag_ehMatriz = 0;}
	| MATRIZ ;

MATRIZ: token_matriz T_MAT token_de TIPO_PRIM {flag_ehMatriz = 1;} ;

T_MAT: 
	  token_colchete_abre token_vlr_inteiro SALVAR_M token_colchete_fecha token_colchete_abre token_vlr_inteiro {DIM_N = atoi(vlr_int);} token_colchete_fecha // MATRIZ
     	| token_colchete_abre token_vlr_inteiro SALVAR_M token_colchete_fecha ;  // VETOR 

SALVAR_M: {DIM_M = atoi(vlr_int);} ;

TIPO_PRIM: 
	  token_int {TIPO_VAR = 0; }
	| token_char {TIPO_VAR = 3; }
	| token_string {TIPO_VAR = 4; }
	| token_real {TIPO_VAR = 1; }
	| token_boolean {TIPO_VAR = 2; } ;

VALOR: 
	EXPRESSAO { 
		tipo_operadores =  pilha_remove(pilha_op);
		tipo_termos = pilha_remove(pilha_termo);
		if (tipo_operadores == 0){
			if (!(tipo_termos == 0 || tipo_termos == 1)){
				printf(" Erro semantico: Incompatibilidade na expressao. Linha: %d, Coluna %d.\n", nlinhas, nColunas ); 
				exit(0);
			}
		}
		if (tipo_operadores == 1){
			if (tipo_termos != 2){
				printf(" Erro semantico: Incompatibilidade na expressao. Linha: %d, Coluna %d.\n", nlinhas, nColunas ); 
				exit(0);
			}
		}
		if(flag_eh_arg == 0){
			if(TIPO_ATRIB != tipo_termos){ 
				printf(" Erro semantico: Incompatibilidade de tipos na atribuicao. Linha: %d, Coluna %d.\n", nlinhas, nColunas);
				exit(0);
			}
		}
 	}
	| TK_VLR_LITERAL ;

EXPRESSAO: 
	  RESETA_PILHAS EXPRESSAO_ARIT OP_COMPARATIVO EXPRESSAO_ARIT
	| RESETA_PILHAS EXPRESSAO_ARIT;

RESETA_PILHAS: {/*verificar com as 2 pilhas*/ pilha_destroi(pilha_termo); pilha_constroi(pilha_termo); pilha_destroi(pilha_op); pilha_constroi(pilha_op);}

EXPRESSAO_ARIT:
	  EXPRESSAO_ARIT token_pot EXPR
	| EXPR ;

EXPR:
	  EXPR token_mult {TIPO_OP = 0;} VERIFICACAO_OP FATOR 
	| EXPR token_div {TIPO_OP = 0;} VERIFICACAO_OP FATOR
	| EXPR token_mod {TIPO_OP = 0;} VERIFICACAO_OP FATOR
	| EXPR token_and {TIPO_OP = 1;} VERIFICACAO_OP FATOR
	| FATOR ;

VERIFICACAO_OP: {
	pilha_insere(pilha_op, TIPO_OP);
	if (!pilha_verifica_compatibilidade(pilha_op)) {
		printf(" Erro semantico na linha %d, coluna %d. Incompatibilidade de operadores na expressao.\n", nlinhas, nColunas);
		exit(0);
	}
};

FATOR:
	  FATOR token_mais {TIPO_OP = 0;} VERIFICACAO_OP TERMO
	| FATOR token_menos {TIPO_OP = 0;} VERIFICACAO_OP TERMO
	| FATOR token_or {TIPO_OP = 1;} VERIFICACAO_OP TERMO
	| TERMO VERIFICACAO_TERMOS;

TERMO: 
	OP_INCR
     | TK_VLR_NUM 
     | token_abreParen EXPRESSAO token_fechaParen
     | CHAMADA_FUNCAO 
     {
		flag_valorEhFuncao = 1; 
		if (busca(tabela_hash_func, nome_func, ESCOPO_VAR) != NULL)
			TIPO_TERMO = get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR));
		else {
			printf(" Erro semantico: Funcao %s nao declarada. Linha: %d, Coluna %d\n", nome_func, nlinhas, nColunas);
			exit(0);
		}
     }
     | TK_IDENT { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); }
     | TK_VLR_BOOL
     | MULTIPLOS_NOT token_abreParen EXPRESSAO token_fechaParen
     ;

VERIFICACAO_TERMOS:{
	pilha_insere(pilha_termo, TIPO_TERMO);
	if (flag_eh_arg == 0){ //Se nao for argumento, insere na pilha para comparar com a atribuicao
		if(!pilha_verifica_compatibilidade(pilha_termo)) {
				printf(" Erro semantico: Incompatibilidade de tipos na expressao. Linha: %d, Coluna %d\n", nlinhas, nColunas);
				exit(0);
		}
	}
};

TK_IDENT: 
	  token_ident PILHA_IDENT
	| token_ident PILHA_IDENT TAM_MATRIZ VERIFICA_LIM_MAT ;

VERIFICA_LIM_MAT: {
	var = busca(tabela_hash_var, nome_var, ESCOPO_VAR);
	if (var == NULL){
		printf(" Erro semantico: Variavel %s nao declarada. Linha: %d, Coluna %d.\n", nome_var, nlinhas, nColunas);
		exit(0);
	}
	else {
		if (DIM_M >= 1){
			if (DIM_N >= 1){
				if (DIM_M > get_m(var) || DIM_N > get_n(var)){
					printf(" Erro semantico: Acessando posicao inexistente em matriz. Linha: %d, Coluna %d.\n", nlinhas, nColunas);
					exit(0);
				}
			}
			else
				if (DIM_M > get_m(var)){
					printf(" Erro semantico: Acessando posicao inexistente em vetor. Linha: %d, Coluna %d.\n", nlinhas, nColunas);
					exit(0);
				}
		}
	}
}

PILHA_IDENT: { 
	strcpy(nome_var, ident);
	if (busca(tabela_hash_var,nome_var,ESCOPO_VAR) != NULL){
		TIPO_VAR = get_tipo(busca(tabela_hash_var,nome_var,ESCOPO_VAR));
		TIPO_TERMO = TIPO_VAR;
	}
	else {
		printf(" Erro semantico: Variavel %s nao declarada. Linha: %d, Coluna %d.\n", nome_var, nlinhas, nColunas);
		exit(0);
	}
};

TAM_MATRIZ: 
	  token_colchete_abre token_vlr_inteiro SALVAR_M token_colchete_fecha token_colchete_abre token_vlr_inteiro {DIM_N = atoi(vlr_int);} token_colchete_fecha // MATRIZ 
	| token_colchete_abre token_vlr_inteiro SALVAR_M token_colchete_fecha ;  // VETOR

TK_VLR_LITERAL: 
	token_vlr_char
      | token_vlr_string ;

TK_VLR_NUM: 
	  token_vlr_inteiro { TIPO_TERMO = 0;}
	| token_menos token_vlr_inteiro{ TIPO_TERMO = 0;}
	| token_vlr_real { TIPO_TERMO = 1; }
	| token_menos token_vlr_real { TIPO_TERMO = 1; } ;


MULTIPLOS_NOT:
	  MULTIPLOS_NOT token_not 
	| token_not ;

TK_VLR_BOOL: 
	MULTIPLOS_NOT token_true { TIPO_TERMO = 2; }
           | MULTIPLOS_NOT token_false { TIPO_TERMO = 2; }
           | token_true {TIPO_TERMO = 2;}
           | token_false {TIPO_TERMO = 2;}
           | MULTIPLOS_NOT TK_IDENT { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); };

OP_INCR: TK_IDENT { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); } token_increment
       | TK_IDENT { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); } token_decrement
       ;

OP_COMPARATIVO: token_maior
	      | token_maior_igual
	      | token_menor
	      | token_menor_igual 
	      | token_igual
	      | token_diferente ;

%%

#include "lex.yy.c"

int main(void){

	lista_var = inicializa();
	var = inicializa();
	lista_func = inicializa();
	func = inicializa();
	tabela_hash_var = inicializa_hash();
	tabela_hash_func = inicializa_hash();
	pilha_termo = pilha_constroi(pilha_termo);
	pilha_op = pilha_constroi(pilha_op);
	yyparse();
	verifica_variavel_usada(tabela_hash_var);
	printf("Algoritmo Reconhecido com sucesso \n");
	return 0;
}

yyerror(void){
  printf(" Erro sintatico. Linha: %d, Coluna: %d\n", nlinhas, nColunas);
  exit(1);
}