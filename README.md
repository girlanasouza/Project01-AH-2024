## Projeto Prático - Computação Heterogênea

Alunos

- Daniel Nunes
- Girlana Souza

### Compilação e Execução do Programa

---

#### Compilação

Para compilar o programa, execute o seguinte comando no terminal:

```bash
g++ -o main_02 main_02.cpp
```

Este comando usa o compilador `g++` para compilar o arquivo `main_02.cpp` e gerar um executável chamado `main_02`.

---

#### Tipos de Filtros

Após compilar o programa, você pode aplicar diferentes filtros à imagem. Existem três tipos de filtros que você pode escolher:

1. **Filtro Verde (`green`)**:

   - **Descrição**: Aplica um filtro verde à imagem, onde todos os pixels terão o valor máximo no canal verde.
   - **Uso**: `./main_02 green`

2. **Filtro em Escala de Cinza (`grayscale`)**:

   - **Descrição**: Converte a imagem para tons de cinza, calculando a média ponderada dos valores dos canais de cor.
   - **Uso**: `./main_02 grayscale`

3. **Filtro Invertido (`invert`)**:
   - **Descrição**: Inverte as cores da imagem, transformando cada pixel em sua cor oposta.
   - **Uso**: `./main_02 invert`

---

#### Aplicar Filtros com o Script

Você também pode usar um script para aplicar um filtro específico de forma simplificada. Para isso, execute o script `run.sh` com o filtro desejado:

```bash
./run.sh <nome_filtro>
```

Substitua `<nome_filtro>` pelo tipo de filtro desejado. Aqui estão os valores válidos que você pode usar:

- `green` para aplicar o filtro verde
- `grayscale` para aplicar o filtro em escala de cinza
- `invert` para aplicar o filtro invertido

---

#### Exemplos de Uso do Script

Para aplicar o filtro verde, execute:

```bash
./run.sh green
```

Para aplicar o filtro em escala de cinza, execute:

```bash
./run.sh grayscale
```

Para aplicar o filtro invertido, execute:

```bash
./run.sh invert
```

Para aplicar todos os filtros em sequência, execute:

```bash
./run.sh invert
```

---

#### Nota

Certifique-se de que o arquivo de imagem `input.jpg` está no diretório `input/` e que o script e o executável estão localizados no mesmo diretório para garantir que o processo funcione corretamente.
