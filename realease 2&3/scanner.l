%{
#include <string.h>
#define DEBUG

char ident[100];

int nlinhas = 1;
int nColunas = 0;
char vlr_int[100];

// funcao para contar linhas dentro de um comentario de bloco
void contaLinhas(char *str){
	char *aux = (char*)malloc(strlen(str)*sizeof(char));
	strcpy(aux, str);
	while (*aux != '\0'){
		if (*aux == '\n' ){
			nlinhas++;
		}
		//printf("%s ", aux);
		aux++;
	}
};
%}

/* definicoes */
STRING \"([^\"])*\"
COMENTARIO_BLOCO \/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/

%%

fim-variáveis|fim-variaveis|fim-var|fimvariáveis|fimvariaveis|fimvar|FIM-VARIÁVEIS|FIM-VARIAVEIS|FIM-VAR|FIMVARIÁVEIS|FIMVARIAVEIS|FIMVAR	{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_var_fim;
																			
																		}
variáveis|variaveis|VARIAVEIS|VARIÁVEIS|VAR|var							{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_var;
																		}
													
caractere|CARACTERE														{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas); 
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_char;
																		}
algoritmo|ALGORITMO														{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas); 
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_algoritmo;
																		}
se|SE																	{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_if;
																		}
fim-se|fimese|FIM-SE|FIMSE												{
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_then_end;
																		}
fim-senao|fim-senão|fimsenao|FIM-SENAO|FIM-SENÃO|FIMSENAO				{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_else_end;
																		}
faça|faca|FAÇA|FACA														{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_do;
																		}
fim-faça|fim-faca|fimfaca|FIM-FAÇA|FIM-FACA|FIMFACA						{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_do_end;
																		}
literais|LITERAIS														{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_strings;
																		}
literal|LITERAL															{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_string;
																		}
senão|senao|SENÃO|SENAO													{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_else;
																		}
enquanto|ENQUANTO														{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_while;
																		}
fim-enquanto|fimenquanto|FIM-ENQUANTO|FIMENQUANTO						{		
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_while_end;
																		}
matriz|MATRIZ															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_matriz;
																		}
lógicos|logicos|LÓGICOS|LOGICOS											{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_booleans;
																		}
lógico|logico|LÓGICO|LOGICO												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_boolean;
																		}
ou|OU																	{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_or;
																		}
então|entao|ENTÃO|ENTAO													{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_then;
																		}
para|PARA                                  								{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_for;
																		}
fim-para|fimpara|FIM-PARA|FIMPARA										{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_for_end;
																		}
inteiros|INTEIROS                          								{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_ints;
																		}
função|funcao|funçao|funcão|FUNÇÃO|FUNCAO|FUNÇAO|FUNCÃO {				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_func;
																		}
procedimento|PROCEDIENTO 												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_proc;
																		}																		
fim-funcao|fim-função|fim-funçao|fim-funcão|fimfuncao|FIM-FUNCAO|FIM-FUNÇÃO|FIM-FUNÇAO|FIM-FUNCÃO|FIMFUNCAO {				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_func_fim;
																		}
fim-procedimento|fimprocedimento|FIM-PROCEDIMENTO|FIMPROCEDIMENTO 		{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_proc_fim;
																		}					
inteiro|INTEIRO            												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_int;
																		}
inicio|início|INICIO|INÍCIO 											{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_inicio;
																		}
fim|FIM																	{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_fim;
																		}
e|E                        												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_and;
																		}

de|DE																	{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_de;
																		}
até|ate|ATÉ|ATE															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_ate;
																		}
reais|REAIS																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_reals;
																		}
retorne|RETORNE															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_return;
																		}
real|REAL																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_real;
																		}
não|nao|naum|NÃO|NAO|NAUM												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_not;
																		}
passo|PASSO																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_passo;
																		}
escreva|ESCREVA|escreval|ESCREVAL															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_print;
																		}
leia|LEIA																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_read;
																		}
minimo|mínimo|MINIMO|MÍNIMO												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_minimo;
																		}
central|CENTRAL															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_central;
																		}
maximo|máximo|MAXIMO|MÁXIMO												{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas);
																			#endif
																			nColunas += strlen(yytext);
																			return token_maximo;
																		}

repita|REPITA															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_repeat;
																		}
																																				
escolha|ESCOLHA															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_switch;
																		}

																		
caso|CASO																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_case;
																		}

outro-caso|OUTRO-CASO|outrocaso|OUTROCASO																{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_default;
																		}																		

fim-escolha|FIM-ESCOLHA|fimescolha|FIMESCOLHA															{				
																			#ifdef DEBUG 
																				printf("PALAVRARESERVADA %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_switch_end;
																		}

																		

\"																		{
																			return token_aspas;
																		}
:=|<-																	{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_atrib;
																		}
">"																		{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_maior;
																		}
">"=																	{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_maior_igual;
																		}
\<																		{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_menor;
																		}
\<=																		{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_menor_igual;
																		}
==																		{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_igual;
																		}
"<"">"																	{				
																			#ifdef DEBUG 
																				printf("SIMBOLOESPECIAL %s na linha %d\n", yytext, nlinhas);
																				printf("qtd colunas = %d\n",nColunas); 
																			#endif
																			nColunas += strlen(yytext);
																			return token_diferente;
																		}
"+""+"					{
	nColunas += strlen(yytext);
	return token_increment;}
"-""-"					{
	nColunas += strlen(yytext);
	return token_decrement;}
\%					{
	nColunas += strlen(yytext);
	return token_mod;}
\+					{
	nColunas += strlen(yytext);
	return token_mais;}
\-					{
	nColunas += strlen(yytext);
	return token_menos;}
\/					{
	nColunas += strlen(yytext);
	return token_div;}
\*					{
	nColunas += strlen(yytext);
	return token_mult;}
\^					{
	nColunas += strlen(yytext);
	return token_pot;}

\[					{
	nColunas += strlen(yytext);
	return token_colchete_abre ;}
\]					{
	nColunas += strlen(yytext);
	return token_colchete_fecha;}
\(					{
	nColunas += strlen(yytext);
	return token_abreParen;}
\)					{
	nColunas += strlen(yytext);
	return token_fechaParen;}
\.					{
	nColunas += strlen(yytext);
	return token_pt;}
\,					{
	nColunas += strlen(yytext);
	return token_virg;}
\;					{
	nColunas += strlen(yytext);
	return token_pt_virg;}
\:					{
	nColunas += strlen(yytext);
	return token_dois_pt;}
\#					{
	nColunas += strlen(yytext);
	return token_hashtag;}
\{					{
	nColunas += strlen(yytext);
	return token_chaves_abre;}
\}					{
	nColunas += strlen(yytext);
	return token_chaves_fecha;}
\'					{
	nColunas += strlen(yytext);
	return token_apost;}
\\					{
	nColunas += strlen(yytext);
	return token_cbarra;}

[0-9]+					{strcpy (vlr_int, yytext); 
	nColunas += strlen(yytext);
	return token_vlr_inteiro;}
[0-9]+(\.[0-9]+)			{
	nColunas += strlen(yytext);
	return token_vlr_real;}
\'[a-z]\'				{
	nColunas += strlen(yytext);
	return token_vlr_char;}
verdadeiro|VERDADEIRO				{
	nColunas += strlen(yytext);
	return token_true;}
falso|FALSO					{
	nColunas += strlen(yytext);
	return token_false;}
[a-z]("_"|[a-z]|[0-9])*		{strcpy(ident,yytext);
	nColunas += strlen(yytext);
	return token_ident;}
{STRING}				{
	nColunas += strlen(yytext);
	return token_vlr_string;}
{COMENTARIO_BLOCO}			{/*printf("COMENTARIO IGNORADO\n")	;*/ contaLinhas(yytext);
	nColunas += strlen(yytext);
	 }
\/\/[^\n]*				/*{printf("COMENTARIO DE LINHA IGNORADO\n")	;}*/

[ \t] 				{nColunas++;}					
\n					{
	nColunas = 0;
	nlinhas++;/* printf("nlinhas = %d [ENTER]\n", nlinhas);*/} 
^.					{printf("Erro na linha %d, %s: SIMBOLO DESCONHECIDO \n", nlinhas, yytext);}

%%

int yywrap()
{
	printf("%d Linhas\n", nlinhas);
	return(1);
}


