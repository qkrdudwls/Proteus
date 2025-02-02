# Proteus 3.0

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

### 🔄 Notation Transformation

사용자가 선택한 표기법으로 입력한 산술 표현식을 다른 표기법으로 변환

- **Supported Notations**
  - Inorder Notation
  - Preorder Notation
  - Postorder Notation

### 🎭 Lookahead LR Parsing

Context-Free Grammar 기반의 표현식을 해석하고 연산을 수행하는 LALR Parsing 

### 🔑 Tokens, Lexemes, Patterns

| **Token** | **Sample Lexemes** | **Pattern** |
|:-----:|:-----:|:-----:|
| ARITHMETIC_PREFIX | pr | ARITHMETIC_PREFIX |
| NOTATION_PREFIX | pr | NOTATION_PREFIX |
| ARITHMETIC_INFIX | in | ARITHMETIC_INFIX |
| NOTATION_INFIX | in | NOTAION_INFIX |
| ARITHMETIC_POSTFIX | po | ARITHMETIC_POSTFIX |
| NOTATION_POSTFIX | po | NOTATION_POSTFIX |
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
| ARITHMETIC_MOD | % | Remainder operator. |
| NOTATION_MOD | % | Remainder operator. |
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

- `ARITHMETIC_`: **Arithmetic Expression Evaluation Parser**에서 사용.
- `NOTATION_`: **Notation Conversion Parser**에서 사용.
- `ARITHMETIC_PREFIX`, `ARITHMETIC_INFIX`, `ARITHMETIC_POSTFIX`, `NOTATION_PREFIX`, `NOTATION_INFIX`, and `NOTATION_POSTFIX`: Token for internal classification other than user input.

### 📜 Context-Free Grammar

#### Arithmetic Expression Evaluation

**input** -> ARITHMETIC_PREFIX prefix_expr ARITHMETIC_NEWLINE | ARITHMETIC_INFIX infix_expr ARITHMETIC_NEWLINE | ARITHMETIC_POSTFIX postfix_expr ARITHMETIC_NEWLINE | ARITHMETUC_PREFIX unary_expr ARITHMETIC_NEWLINE | ARITHMETIC_POSTFIX unary_expr ARITHMETIC_NEWLINE

**prefix_expr** -> ARITHMETIC_PLUS prefix_expr prefix_expr | ARITHMETIC_MINUS prefix_expr prefix_expr | ARITHMETIC_MULT prefix_expr prefix_expr | ARITHMETIC_DIV prefix_expr prefix_expr | ARITHMETIC_EXP prefix_expr prefix_expr | ARITHMETIC_MOD prefix_expr prefix_expr | ARITHMETIC_DIGIT

**infix_expr** -> infix_expr ARITHMETIC_PLUS infix_expr | infix_expr ARITHMETIC_MINUS infix_expr | infix_expr ARITHMETIC_MULT infix_expr | infix_expr ARITHMETIC_DIV infix_expr | infix_expr ARITHMETIC_EXP infix_expr | infix_expr ARITHMETIC_MOD infix_expr | ARITHMETIC_LPAREN infix_expr ARITHMETIC_RPAREN | ARITHMETIC_PLUS infix_expr | ARITHMETIC_MINUS infix_expr | ARITHMETIC_DIGIT

**postfix_expr** -> postfix_expr postfix_expr ARITHMETIC_PLUS | postfix_expr postfix_expr ARITHMETIC_MINUS | postfix_expr postfix_expr ARITHMETIC_MULT | postfix_expr postfix_expr ARITHMETIC_DIV | postfix_expr postfix_expr ARITHMETIC_EXP | postfix_expr postfix_expr ARITHMETIC_MOD | ARITHMETIC_DIGIT

**unary_expr** -> ARITHMETIC_PLUS ARITHMETIC_DIGIT %prec ARITHMETIC_UPLUS | ARITHMETIC_MINUS ARITHMETIC_DIGIT

#### Notation Conversion

**input** -> NOTATION_PREFIX preorder_expr NOTATION_NEWLINE | NOTATION_INFIX inorder_expr NOTATION_NEWLINE | NOTATION_POSTFIX postorder_expr NOTATION_NEWLINE | NOTATION_PREFIX unary_expr NOTATION_NEWLINE | NOTATION_POSTFIX unary_expr NOTATION_NEWLINE

**preorder_expr** -> NOTATION_PLUS preorder_expr preorder_expr | NOTATION_MINUS preorder_expr preorder_expr | NOTATION_MULT preorder_expr preorder_expr | NOTATION_DIV preorder_expr preorder_expr | NOTATION_EXP preorder_expr preorder_expr | NOTATION_MOD preorder_expr preorder_expr | NOTATION_DIGIT

**inorder_expr** -> inorder_expr NOTATION_PLUS inorder_expr | inorder_expr NOTATION_MINUS inorder_expr | inorder_expr NOTATION_MULT inorder_expr | inorder_expr NOTATION_DIV inorder_expr | inorder_expr NOTATION_EXP inorder_expr | inorder_expr NOTATION_MOD inorder_expr | NOTATION_LPAREN inorder_expr NOTATION_RPAREN | NOTATION_PLUS inorder_expr | NOTATION_MINUS inorder_expr | NOTATION_DIGIT

**postorder_expr** -> postorder_expr postorder_expr NOTATION_PLUS | postorder_expr postorder_expr NOTATION_MINUS | postorder_expr postorder_expr NOTATION_MULT | postorder_expr postorder_expr NOTATION_DIV | postorder_expr postorder_expr NOTATION_EXP | postorder_expr postorder_expr NOTATION_MOD | NOTATION_DIGIT

**unary_expr** -> NOTATION_PLUS NOTATION_DIGIT | NOTATION_MINUS NOTATION_DIGIT

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

###### 25.02.02
