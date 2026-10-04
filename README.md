# stoi (string to int)

Uma implementação em C puro que converte strings em um número inteiro

> [!warning] 
> Overflow ainda não é tratado: um valor fora do intervalo de `int` (32 bits na maioria das plataformas) resulta em um valor incorreto.

## Uso

### Parâmetros
A função `stoi` recebe dois parâmetros:
- `s` a string que será convertida
- `out` um ponteiro para uma variável de tipo int onde será armazenado a conversão

### Retorno
A função retorna 0 para sucesso de conversão e -1 para qualquer erro ocorrido durante o processo

### Exemplo de uso

```c
#include "stoi.h"

int main(void) {
    int valor;

    if (stoi("-90", &valor) != 0) {
        // tratar erro
        return 1;
    }

    // valor == -90
    return 0;
}
```

## Como compilar

```bash
make          # compila o exemplo e os testes
make test     # roda os testes
make clean    # remove os arquivos gerados
```

Licença MIT
