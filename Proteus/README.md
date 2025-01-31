# Proteus 2.0

**산술 연산** 및 **진법 변환**, **표기법 변환** 기능을 제공하는 CLI 기반 미니 컴파일러

## 🛠️ Tools

- Bison
- Flex
- Clang & LLVM
- GCC

## 🌟 Features

### 🧮 Arithmetic Expression Evaluation

지원하는 연산: '+', '-', '*', '/', '^', '%' 및 괄호 '()'를 통한 표현식 계산 

### 🔢 Custom Base Conversion

사용자가 지정한 **n진수(2~36)**로 결과를 반환하여 출력

### 🔄 Notation Conversion

Inorder(중위)로 입력된 산술 표현식을 Preorder(전위)와 Postorder(후위)로 변환

### 🎭 Lookahead LR Parsing

Context-Free Grammar 기반의 표현식을 해석하고 연산을 수행하는 LALR Parsing 

### 🔑 Tokens, Lexemes, Patterns

| **Token** | **Sample Lexemes** | **Pattern** |
|:-----:|:-----:|:-----:|
| ARITHMETIC_DIGIT | 1, 2, 3 | Numbers present in arithmetic expressions. |
| NOTATION_DIGIT | 1, 2, 3 | Numbers present in arithmetic expressions. |
| ARITHMETIC_PLUS | + | Addition operator. |
| NOTATION_PLUS | + | Addition operator. |
| ARITHMETIC_MINUS | - | Subtraction operator. |
| NOTATION_MINUS | - | Subtraction operator. |
| ARITHMETIC_MULT | * | Multiplication operator. |
| NOTATION_MULT | * | Multiplication operator. |
| ARITHMETIC_DIV | / | Division operator. |
| NOTATION_DIV | / | Division operator. |
| ARITHMETIC_EXP | ^ | Square operator. |
| NOTATION_EXP | ^ | Square operator. |
| ARITHMETIC_DIV | % | Remainder operator. |
| NOTATION_DIV | % | Remainder operator. |
| ARITHMETIC_LPAREN | ( | Left parenthesis for grouping expressions. |
| NOTATION_LPAREN | ( | Left parenthesis for grouping expressions. |
| ARITHMETIC_RPAREN | ) | Right parenthesis for grouping expressions. |
| NOTATION_RPAREN | ) | Right parenthesis for grouping expressions. |
| ARITHMETIC_NEWLINE | \n | End of the line. |
| NOTATION_NEWLINE | \n | End of the line. |
| ARITHMETIC_UNMINUS | - | Unary minus operator. |
| NOTATION_UNMINUS | - | Unary minus operator. |
| `[\t]+` | [\t]+ | Spaces or tabs (ignored). |
| `.` | Any other character | Used for invalid characters. |

- `ARITHMETIC_`: Arithmetic Expression Evaluation Parser에서 사용
- `NOTATION_`: Notation Conversion Parser에서 사용 

### 📜 Context-Free Grammar

E -> E + E | E - E | E * E | E / E | E ^ E | E % E | (E) | -E | digit

## 🚀 Build & Run

### Command 

#### GCC 컴파일러를 이용하여 실행 (기본)

1. `make` 또는 `make proteus-gcc`

2. `.\proteus.exe`

#### Clang, LLVM을 이용하여 실행

1. `make proteus-clang`

2. `.\proteus.exe`

#### Arithmetic Parsing Table 생성

`make arithmetic-parsing-table`

#### Arithmetic Parser 셍성

`make arithmetic-parser`

#### Notation Parsing Table 생성

`make notation-parsing-table`

#### Notation Parser 생성 

`make notation-parser`

#### Lexer 생성

`make lexer`

#### 빌드 결과물 삭제

`make clean`

###### 25.01.31
