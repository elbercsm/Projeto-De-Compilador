%{
#include <stdlib.h>    /* for atoi call */
#include <string.h>
#include <stdio.h>
int i = 0;
%}

%%
[ \t]+ {}															
[\n]*[Aa][Ll][Gg][Oo][Rr][Ii][Tt][Mm][Oo][" "]+"\""[a-zA-Z" "0-9]+"\"" { printf("PALAVRARESERVADA algoritmo\n");
														 printf("IDENTIFICADOR "); 
														 for(i = 10; i < strlen(yytext); i++){
														 	printf("%c", yytext[i]);
														 }
														 printf("\n");
														}
[\n]*[Ff][Ii][Mm][Aa][Ll][Gg][Oo][Rr][Ii][Tt][Mm][Oo] { printf("PALAVRARESERVADA fimalgoritmo\n"); }
[\n]*[Ii][Nn][Ii][Cc][Ii][Oo] { printf("PALAVRARESERVADA inicio\n"); }																
["\n"]*[Vv][Aa][Rr] { printf("PALAVRARESERVADA var"); }
[":"]?[" "\t]*[Ii][Nn][Tt][Ee][Ii][Rr][Oo] { printf("PALAVRARESERVADA inteiro\n"); } 
[":"]?[" "\t]*[Rr][Ee][Aa][Ll] { printf("PALAVRARESERVADA real\n"); }
[":"]?[" "\t]*[Vv][Ee][Tt][Oo][Rr] { printf("PALAVRARESERVADA vetor\n"); }
[":"]?[" "\t]*[Cc][Aa][Rr][Aa][Cc][Tt][Ee][Rr][Ee] { printf("PALAVRARESERVADA caractere\n"); }
[":"]?[" "\t]*[Ll][Oo][Gg][Ii][Cc][Oo] { printf("PALAVRARESERVADA logico\n"); }
[Aa][Ll][Ee][Aa][Tt][Oo][Rr][Ii][Oo] { printf("PALAVRARESERVADA aleatorio\n"); }
[Vv][Ee][Rr][Dd][Aa][Dd][Ee][Ii][Rr][Oo] { printf("PALAVRARESERVADA verdadeiro\n"); }
[Ff][Aa][Ll][Ss][Oo] { printf("PALAVRARESERVADA falso\n"); }
[" "\t\n]*[Ss][Ee][" "\t]+([()a-zA-Z]*[0-9]*[" "\t]*[\<\>]?[\=]?[\=]?[" "\t]*[()a-zA-Z]*[0-9]*[" "\t]*)+[" "\t]+[Ee][Nn][Tt][Aa][Oo] { printf("PALAVRARESERVADA se\n");
																								printf("PALAVRARESERVADA entao\n");}
[Ff][Ii][Mm][Ss][Ee] { printf("PALAVRARESERVADA fimse\n"); }    
[Ss][Ee][Nn][Aa][Oo] { printf("PALAVRARESERVADA senao\n"); }
[" "\n\t]*[Ee][Ss][Cc][Oo][Ll][Hh][Aa]" "[a-zA-Z]*[0-9]* { printf("PALAVRARESERVADA escolha\n");
												 printf("IDENTIFICADOR ");
												 int aux = 0;
												 for(i = 0; i < strlen(yytext); i++){
												 	if(yytext[i] == 'e' || yytext[i] == 'E'){
												 		aux = i;
												 		break;
												 	}
												 }
												 for(i = aux + 7; i < strlen(yytext); i++){
												 	printf("%c", yytext[i]);
												 }
												 printf("\n");
											   }
[" "\n\t]*[Cc][Aa][Ss][Oo][" "\t]+["\""]?[a-zA-Z]*[0-9]*["\""]? { printf("PALAVRARESERVADA caso\n"); 
												   printf("LITERAL ");
												   int aux = 0;			
												   for(i = 0; i < strlen(yytext); i++){
												 		if(yytext[i] == 'c' || yytext[i] == 'C'){
												 			aux = i;
												 			break;
												 		}
												 	}
												 	for(i = aux + 5; i < strlen(yytext); i++){
												 		printf("%c", yytext[i]);
												 	}
												 	printf("\n"); 
												 }
[" "\n\t]*[Oo][Uu][Tt][Rr][Oo][" "\t]+[Cc][Aa][Ss][Oo] { printf("PALAVRARESERVADA outro caso"); }
[" "\n\t]*[Ff][Ii][Mm][Ee][Ss][Cc][Oo][Ll][Hh][Aa] { printf("PALAVRARESERVADA fimescolha\n"); }
[Ee][Nn][Qq][Uu][Aa][Nn][Tt][Oo]" "[a-zA-Z]*[0-9]*" "[\<]?[\>]?[\=]?" "[a-zA-Z]*[0-9]*" "[Ff][Aa][Cc][Aa] { printf("PALAVRARESERVADA enquanto\n");
																			printf("PALAVRARESERVADA faca\n"); }
[Ff][Ii][Mm][Ee][Nn][Qq][Uu][Aa][Nn][Tt][oO] { printf("PALAVRARESERVADA fimenquanto"); }    
[Pp][Aa][Rr][Aa][" "\t]+[a-zA-Z]+([0-9]+)?[" "]+[Dd][Ee][" "]+[0-9]+[" "]+[Aa][Tt][Ee][" "]+[0-9]+[" "]+([Pp][Aa][Ss][Ss][Oo][" "]+[0-9]+[" "]+)?[Ff][Aa][Cc][Aa] { printf("PALAVRARESERVADA para\n");
																							     printf("PALAVRARESERVADA de\n"); 
																							     printf("PALAVRARESERVADA ate\n");
																							     printf("PALAVRARESERVADA faca\n"); }
[Ff][Ii][Mm][Pp][Aa][Rr][Aa] { printf("PALAVRARESERVADA fimpara"); }
[" "\t]*[Rr][Ee][Pp][Ii][Tt][Aa]"\n" { printf("PALAVRARESERVADA repita\n"); }
[" "\t\n]*[Aa][Tt][Ee][" "\t]+ { printf("PALAVRARESERVADA ate\n"); }
[Ii][Mm][Pp][Oo][Rr][Tt][Ee] { printf("PALAVRARESERVADA importe"); }        
[" "\t]*[Ll][Ee][Ii][Aa] { printf("PALAVRARESERVADA leia\n"); }       
[Ff][Ii][Mm] { printf("PALAVRARESERVADA fim"); }
[" "\t\n]*[Ee][Ss][Cc][Rr][Ee][Vv][Aa]([Ll])? { if(yytext[strlen(yytext)-1] == 'L' || yytext[strlen(yytext)-1] == 'l'){
									  	printf("PALAVRARESERVADA escreval\n");
									  }else{
									  	printf("PALAVRARESERVADA escreva\n");
									  }
									}
[" "\t]*[Pp][Rr][Oo][Cc][Ee][Dd][Ii][Mm][Ee][Nn][Tt][Oo][" "\t]*[a-zA-Z]+[" "\t]* { printf("PALAVRARESERVADA procedimento\n");
																					printf("IDENTIFICADOR");
																					for(i = 12; i < strlen(yytext);i++){
																						printf("%c", yytext[i]);
																					}
																					printf("\n");
																				  }
[" "\t]*[Ff][Uu][Nn][Cc][Aa][Oo][" "\t]* { printf("PALAVRARESERVADA funcao\n"); }
[" "\t]*[Ff][Ii][Mm][Ff][Uu][Nn][Cc][Aa][Oo][" "\t]* { printf("PALAVRARESERVADA fimfuncao\n"); }
[" "\t]*[Rr][Ee][Tt][Oo][Rr][Nn][Ee][" "\t]* { printf("PALAVRARESERVADA retorne\n"); }
[" "\t]*[Rr][Aa][Ii][Zz][Qq][" "\t]* { printf("PALAVRARESERVADA raizq\n"); }
[Ff][Ii][Mm][Pp][Rr][Oo][Cc][Ee][Dd][Ii][Mm][Ee][Nn][Tt][Oo] { printf("PALAVRARESERVADA fimprocedimento\n"); }
["\""][a-zA-Z" "\_áÁâÂàÀéÉíêÊÍóîÎôÔûÛÓúÚãÃõÕçÇ\.\:0-9]+[" "\t]*["\""] { printf("LITERAL %s\n", yytext); }
[a-zA-Z\_]+[0-9]*[" "\t]* { printf("IDENTIFICADOR %s\n", yytext); }
[0-9]+\.\.[0-9]+ { printf("LITERAL %s\n", yytext); }
[0-9]+ { printf("LITERAL %s\n", yytext);}
":=" { printf("OPERADORRELACIONAL :=\n"); }
"<-" { printf("OPERADORRELACIONAL <-\n"); }
"=" { printf("OPERADORRELACIONAL =\n"); }
"+" { printf("OPERADOR +\n"); }
"-" { printf("OPERADOR -\n"); }
"*" { printf("OPERADOR *\n"); }
"/" { printf("OPERADOR /\n"); }
":" { }
">=" { printf("OPERADORRELACIONAL >=\n"); }
"<=" { printf("OPERADORRELACIONAL MENORIGUAL\n"); }
"<>" { printf("OPERADORRELACIONAL DIFERENTE\n"); }
">" { printf("OPERADORRELACIONAL MAIOR\n"); }
"<" { printf("OPERADORRELACIONAL MENOR\n"); }
"(" { printf("SIMBOLOESPECIAL (\n"); }
")" { printf("SIMBOLOESPECIAL )\n"); }
";" { }
"," { }
[\[\]] { }
[" "\t\n]*[\/][\/][" "a-zA-Z0-9áÁâÂàÀéÉíêÊÍóîÎôÔûÛÓúÚãÃçÇõÕ\.\:\+\-\*\;\/\\]* { } 
[" "\t\n]*[\/][\*][" "\n\ta-zA-Z0-9áÁâÂàÀéÉíêÊÍóîÎôÔûÛÓúÚãÃçÇõÕ\.\:\+\-\*\;\/\\]*[" "\n\t]*[\*][\/] { } 
%%

int yywrap() {          /* need this to avoid link problem */
    return 1;
}

int main() {
	yylex();
	return 0;
}