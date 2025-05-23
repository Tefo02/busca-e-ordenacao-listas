# README - Projeto de Técnicas de Busca e Ordenação (Trabalho 1)

Este repositório contém o código para o **Trabalho 1** da disciplina de **Técnicas de Busca e Ordenação** da faculdade. O objetivo do projeto é praticar conceitos fundamentais da linguagem **C++** através da implementação de diferentes tipos de listas (contígua, simples e dupla) e manipulação básica de dados.

## Estrutura do Projeto

Este projeto é composto pelos seguintes arquivos:

- **ListaContigua.cpp**: Implementação da lista contígua.
- **ListaSimples.cpp**: Implementação da lista simples (lista encadeada).
- **ListaDupla.cpp**: Implementação da lista dupla (lista encadeada dupla).
- **main.cpp**: Arquivo principal que executa o programa utilizando as listas implementadas.
- **compilar.sh**: Script para automatizar a compilação do projeto.

## Como Compilar e Executar

Este projeto pode ser compilado utilizando o compilador `g++`, que é amplamente disponível em sistemas Linux, macOS e Windows (via MinGW ou Cygwin).

### Passo 1: Preparando o Ambiente

Certifique-se de que o compilador `g++` esteja instalado na sua máquina. Para verificar, execute:

```bash
g++ --version
```


Caso o `g++` não esteja instalado:

- **Linux (Ubuntu/Debian)**: `sudo apt install g++`
- **macOS (Homebrew)**: `brew install gcc`
- **Windows**: Instale o [MinGW](https://osdn.net/projects/mingw/releases/) ou [Cygwin](https://www.cygwin.com/), ou use o **Git Bash** ou **WSL** para executar o script.

### Passo 2: Compilando o Projeto

1. Abra o terminal ou prompt de comando.
2. Navegue até o diretório onde os arquivos do projeto estão localizados.
3. **Se você estiver no Windows**:
   - Se estiver usando o **Git Bash** ou **WSL** (Windows Subsystem for Linux), **abra o terminal Git Bash ou WSL** ou execute o arquivo `compilar.bat`.
   - Para **outros sistemas** como Linux ou macOS, basta usar o terminal padrão.

4. Torne o script `compilar.sh` executável (se necessário):

```bash
chmod +x compilar.sh
```

5. Execute o script de compilação:

```bash
./compilar.sh
```

O script irá compilar automaticamente todos os arquivos `.cpp` e gerar o executável `programa`.

### Passo 3: Executando o Programa

Após a compilação, execute o programa com:

```bash
./programa
```

## Descrição do Código

O projeto implementa três tipos principais de listas, cada uma com sua particularidade:

- **Lista Contígua**: Usa vetor para armazenar os elementos de maneira contígua.
- **Lista Simples**: Usa nós ligados sequencialmente por ponteiros.
- **Lista Dupla**: Usa nós com ponteiros para o próximo e o anterior, permitindo navegação em ambas direções.

## Licença

Este projeto está sob licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais informações.
