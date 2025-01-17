# Proteus

**10진수**로 이루어진 산술 표현식을 입력 받아 해당 표현식의 결과를 계산하고, 이를 사용자가 지정한 **n진수**로 변환하여 출력하는 미니 컴파일러

## Tokens, Lexemes, Patterns

| **Token** | **Sample Lexemes** | **Pattern** |
|:-----:|:-----:|:-----:|
| PLUS | + | + |
| MINUS | - | - |
| MULT | * | * |
| DIV | / | / |
| LPAREN | ( | ( |
| RPAREN | ) | ) |
| DIGIT | 1, 2, 3 | Numbers present in arithmetic expressions. |
| NUM | 2, 8, 16 | The natural number value entered by the user. |

## Context-Free Grammar

### Top-down Parsing

E -> E+T | E-T | T

T -> T*F | T/F | F

F -> (E) | digit

#### Eliminating Left Recursion

E -> TE'

E' -> +TE' | -TE' | ε

T -> FT'

T' -> *FT' | /FT' | ε

F -> (E) | digit

### Bottom-up Parsing

E -> E+E

E -> E-E

E -> E*E

E -> E/E

E -> (E)

E -> digit

- **Shift-Reduce Conflict 발생** 