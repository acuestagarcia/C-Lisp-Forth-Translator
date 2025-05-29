# C-Lisp-Forth-Translator
University project for the Procesadores del Lenguaje course (UC3M, 2024–2025). This repository contains a two-stage source code translator:

trad.y: A Yacc-based frontend that parses a restricted subset of the C programming language and translates it into intermediate Lisp code.

back.y: A Yacc-based backend that converts the intermediate Lisp code into final Forth code using postfix notation.

The project focuses on syntax parsing, semantic translation, and code generation, and follows the academic specifications for functional correctness and format compliance using clisp and gforth.
