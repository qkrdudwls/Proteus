# Proteus 2.0

**산술 연산** 및 **진법 변환**, **표기법 변환** 기능을 제공하는 미니 컴파일러

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
| `__DIGIT__` | 1, 2, 3 | Numbers present in arithmetic expressions. |
| `__PLUS__` | + | Addition operator. |
| `__MINUS__` | - | Subtraction operator. |
| `__MULT__` | * | Multiplication operator. |
| `__DIV__` | / | Division operator. |
| `__EXP__` | ^ | Square operator. |
| `__MOD__` | % | Remainder operator. |
| `__LPAREN__` | ( | Left parenthesis for grouping expressions. |
| `__RPAREN__` | ) | Right parenthesis for grouping expressions. |
| `__NEWLINE__` | \n | End of the line. |
| `[\t]+` | [\t]+ | Spaces or tabs (ignored). |
| `.` | Any other character | Used for invalid characters. |

### 📜 Context-Free Grammar

E -> E + E | E - E | E * E | E / E | E ^ E | E % E | (E) | -E | digit

## 🚀 Build & Run

### 명령어 

#### GCC 컴파일러를 이용하여 실행 (기본)

1. `make` 또는 `make proteus-gcc`

2. `.\proteus.exe`

#### Clang, LLVM을 이용하여 실행

1. `make proteus-clang`

2. `.\proteus.exe`

#### Parsing Table 생성

`make parsing-table`

#### Parser 셍성

`make parser`

#### Lexer 생성

`make lexer`

#### 빌드 과정에서 생성된 파일 삭제

`make clean`
