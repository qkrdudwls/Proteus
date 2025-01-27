# Chronos

사용자가 입력한 중위 표기법(Inorder) 표현식을 후위 표기법(Postorder)으로 변환한 뒤, 이를 스택 기반으로 연산하여 결과를 도출하는 미니 컴파일러 

## 🌟 Features

### 🔑 Tokens, Lexemes, Patterns

| **Token** | **Sample Lexemes** | **Pattern** |
|:-----:|:-----:|:-----:|
| DIGIT | 1, 2, 3 | Numbers present in arithmetic expressions. |
| PLUS | + | Addition operator. |
| MINUS | - | Subtraction operator. |
| MULT | * | Multiplication operator. |
| DIV | / | Division operator. |
| LPAREN | ( | Left parenthesis for grouping expressions. |
| RPAREN | ) | Right parenthesis for grouping expressions. |
| SQUR | ^ | Square operator. |
| \n | \n | End of the line. |
| [\t]+ | [\t]+ | Spaces or tabs (ignored). |
| . | Any other character | Used for invalid characters. |
