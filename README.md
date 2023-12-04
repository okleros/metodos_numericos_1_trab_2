# Executando o Software de Métodos Numéricos

Este arquivo fornece instruções sobre como compilar e executar o código C++ que implementa métodos numéricos, incluindo o Método de Gauss-Jacobi e Gauss-Seidel.

## Pré-requisitos

Antes de executar o código, você precisa do seguinte:

1. **Compilador C++**: Você deve ter um compilador C++ instalado no seu sistema. O código está escrito em C++ e precisa de um compilador para ser construído e executado.

2. **Parâmetros de Entrada**: Você precisará fornecer parâmetros de entrada ao executar o código. Há apenas um parâmetro opicional "--default", que significa que o programa não perguntará nada do usuário e usará as entradas padrão definidas no código.

## Compilando o Código

1. Abra um terminal ou prompt de comando.

2. Navegue até o diretório onde o código está localizado.

3. Compile o código usando o seguinte comando para usar o Makefile fornecido:

   ```bash
   make
   ```

   Isso irá compilar o código usando o Makefile e gerar um executável chamado 'main' que você pode rodar.

Agora, o Makefile incluirá as opções de otimização (-O3), ativação de avisos (-Wall e -Wextra), e o uso de otimizações de ponto flutuante rápidas (-ffast-math) durante a compilação do código. Você pode usar o Makefile fornecido para compilar o código com essas configurações.
Isso irá compilar o código e gerar um executável que você pode rodar.

## Executando o Programa

Após compilar com sucesso o código, você pode executar o programa com o seguinte comando:

```bash
./main [--default]
```

- `[--default]` (opcional): Use esta flag para habilitar o uso das entradas padrão definidas na descrição do trabalho.

Caso não use "--default", o programa irá pedir que você insira o 'A', 'b' e 'ε' para que os métodos sejam executados.

## Saída

O programa exibe, via terminal, as seguintes informações:

- Inversa usando Gauss-Jacobi
- Inversa usando Gauss-Seidel
- Identidade (MxM⁻¹) usando Gauss-Jacobi
- Identidade (MxM⁻¹) usando Gauss-Seidel
- Solução do sistema através de Gauss-Jacobi
- Solução do sistema através de Gauss-Seidel
- Solução do sistema (M⁻¹xb) Gauss-Jacobi
- Solução do sistema (M⁻¹xb) Gauss-Seidel
