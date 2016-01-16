# Arithmentic Expression Parser

Recursive-descent parser of arthitmetic expressions, following these rules:

    <program> ? <exp> ; | <exp> ',' <assigns> ';'
    
    <exp> -> '(' <operand> <op> <operand> ')' | '(' <operand> '!' ')'
    
    <operand> ? <literal> | <variable> | <exp> 
    
    <op> -> '+' | '-' | '*' | '/' | '>' | '<' | '=' | '&' | '|'
    
    <assigns> ? <assigns> , <assign> | <assign>
    
    <assign> ? <variable> = <literal>