# BARES - Basic ARithmetic Expression Evaluator based on Stacks
## Linguagem de Programação 1 - DIM0120 - 2020.6

This project aims to build the Evaluator of Expressions

#### To compile the program use Make File
| Command | Description |
| ------- | --------- |
| `make all` | Compile Program. |
| `make clear` | Remove all files generated in compilation. |
| `make run` | Run the program without tests. |
| `make test` | Run the program with standard test file. |

The expression can be entered manually or you can use an file with entered.

Use `./a.out < entrada.txt` to run all tests.

If you run the program using `./a.out`, you will need type an expression, after the result you will need to use `CTRL+C` to end the program.

#### The Available Operators are
| Operator | Symbol |
| -------- | ------ |
| Addition | `+` |
| Subtraction | `-` |
| Multiplication | `*` |
| Division | `/` |
| Potentiation | `^` |
| Rest of Division | `%` |

You can use the "(" ")" in expressions, the program ignores spaces and tab, but you can't to separate numbers. Ex: `2 0 + 4` is invalid expression, but `20 + 4` is valid.

#### Example Expressions
```
2+2
2 ^8
(3 * 0) / 2
```

###### Avaliable in [GitHub](https://github.com/speeds0n/bares) and [GitLab](https://projetos.imd.ufrn.br/edsoncassiano0/bares)
###### Author Edson Cassiano, November, 2020.
