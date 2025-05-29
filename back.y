%{                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
char *operations_handling(char *, char *, char *) ;

char temp [2048] ;

// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
} t_attr ;

#define YYSTYPE t_attr
#define YYDEBUG 1

%}

// Definiciones de los token
%token NUMBER        
%token IDENTIF       
%token STRING
%token SETQ          
%token SETF
%token DEFUN
%token IF
%token PROGN
%token LOOP
%token WHILE
%token DO
%token LE
%token GE
%token NEQ
%token AND
%token OR
%token NOT
%token PRINT
%token PRINC
%token MOD

%%                            // Seccion 3 Gramatica - Semantico

/***************************************************************************/
/********************** Seccion de Variables y Funciones **********************************/
/***************************************************************************/

program : /* vacío */    { ; }
        | top_level_list { ; }
        ;

top_level_list : top_level_form                { ; }
               | top_level_form top_level_list { ; }
               ;

top_level_form : declaration         { ; }
               | function_definition { ; }
               | '(' IDENTIF ')'     {  if (strcmp($2.code, "main") == 0) {
                                             printf("main\n");
                                        }
                                     }
               ;

declaration: '(' SETQ IDENTIF           { printf("variable %s\n", $3.code); }
             expr ')'                   { printf("%s !\n", $3.code); }
            ;

function_definition: '(' DEFUN IDENTIF          { printf(": %s\n", $3.code); }
                     '(' params ')' body ')'    { printf(" ;\n"); }
                   ; 

params : /* vacío */      { ; }
       | params_r { ; }
       ;

params_r :   IDENTIF          { ; }
         |   IDENTIF params_r { ; }
         ;

body : instruction      { ; }
     | instruction body { ; }
     ;

/***************************************************************************/
/********************** Seccion de Código **********************************/
/***************************************************************************/

instruction : '(' SETF IDENTIF expr ')'                  { printf("%s !\n", $3.code); }
            | '(' PRINT STRING ')'                       { printf(".\" %s\" cr\n", $3.code); }      
            | '(' PRINC STRING ')'                       { printf(".\" %s\" \n", $3.code); }      
            | '(' PRINC expr ')'                         { printf(". \n"); }   
            | if_start if_body                           { printf("else\n"); } 
              if_body ')'                                { printf("then\n"); }
            | if_start if_body ')'                       { printf("then\n"); }
            | '(' LOOP WHILE                             { printf("begin "); }
               expr                                      { printf(" while \n"); }
               DO body ')'                               { printf("repeat\n"); }
            ;

if_start: '(' IF expr   { printf(" if \n"); }
        ;

if_body: '(' PROGN body ')' { ; }
       ;

operation: '(' '+' expr expr ')'                     { printf("+ "); }
         | '(' '-' expr expr ')'                     { printf("- "); }
         | '(' '-' expr ')'                          { printf("negate "); }
         | '(' '*' expr expr ')'                     { printf("* "); }
         | '(' '/' expr expr ')'                     { printf("/ "); }
         | '(' MOD expr expr ')'                     { printf("%s ", $2.code); }
         | '(' '=' expr expr ')'                     { printf("= "); }
         | '(' NEQ expr expr ')'                     { printf("= 0= "); }
         | '(' '<' expr expr ')'                     { printf("< "); }
         | '(' LE expr expr ')'                      { printf("%s ", $2.code); }
         | '(' '>' expr expr ')'                     { printf("> "); }
         | '(' GE expr expr ')'                      { printf("%s ", $2.code); }
         | '(' AND expr expr ')'                     { printf("%s ", $2.code); }
         | '(' OR expr expr ')'                      { printf("%s ", $2.code); }
         | '(' NOT expr ')'                          { printf("0= "); }
         ;

expr : atom      { ; }
     | operation { ; }
     ;

atom : NUMBER  { printf("%d ", $1.value); }
     | IDENTIF { printf("%s @ ", $1.code); }
     ;

%%                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords[] = { // define las palabras reservadas y los
    "setq",         SETQ,
    "setf",         SETF,
    "defun",        DEFUN,
    "if",           IF,
    "progn",        PROGN,
    "loop",         LOOP,
    "while",        WHILE,
    "do",           DO,
    "<=",           LE,
    ">=",           GE,    
    "/=",           NEQ,  
    "and",          AND,
    "or",           OR,    
    "not",          NOT,  
    "print",        PRINT,
    "princ",        PRINC,
    "mod",          MOD,
    NULL,           0               // para marcar el fin de la tabla
};

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    //yydebug = 1;
    yyparse () ;
}
