Explicação da Estrutura e Funcionamento
Organização dos Arquivos

A implementação foi dividida em vários arquivos para modularizar o código e atender à norma da 42. O header push_swap.h contém as definições de estruturas e protótipos das funções. Os arquivos de código fonte estão separados da seguinte forma:

push_swap.c: Contém a função principal main e funções auxiliares para construir a pilha a partir dos argumentos, validar erros e obter o tamanho da pilha.
utils.c: Agrupa funções utilitárias como a conversão de string para inteiro (com tratamento de erro), verificação de duplicatas, ordenação e liberação da pilha.
stack.c: Responsável pela criação de novos nós e pela inserção dos mesmos na pilha.
operations.c: Implementa as operações permitidas pelo projeto (sa, ra, rra, pb, pa), imprimindo cada operação conforme exigido.
index.c: Trata da indexação dos valores da pilha. Foram criadas funções auxiliares estáticas para contar nós, construir e ordenar um array com os valores e, por fim, atribuir os índices correspondentes.
sort.c: Implementa o algoritmo de ordenação (radix sort) adaptado para o projeto, dividindo a tarefa em funções auxiliares para obter o maior índice e processar cada bit individualmente.
Makefile: Responsável por compilar os arquivos fonte com as flags corretas e também compilar a libft, que está em um diretório próprio.
Divisão das Funções
Cada função foi cuidadosamente reestruturada para não ultrapassar 25 linhas. Quando necessário, o código foi dividido em funções auxiliares (por exemplo, na conversão de string para inteiro e na indexação) para cumprir esse requisito e também o limite de 5 funções por arquivo.

Fluxo do Programa

Entrada e Validação: A função build_stack processa os argumentos, converte para inteiros e constrói a pilha. Em seguida, validate_stack verifica duplicatas e se a pilha já está ordenada.
Indexação: Com os valores válidos, index_stack atribui um índice a cada nó, representando a posição do valor na ordem crescente.
Ordenação: O algoritmo radix sort, implementado em radix_sort (com ajuda de get_max_index e process_bit), realiza a ordenação utilizando as operações permitidas, imprimindo cada operação executada.
Finalização: Ao final, a memória alocada é liberada e o programa encerra.

push_swap_project/
├── Makefile
├── push_swap.h
├── push_swap.c
├── utils.c
├── stack.c
├── operations.c
├── index.c
├── sort.c
└── libft/
    ├── Makefile
    ├── src/         // arquivos fonte da libft
    └── includes/    // headers da libft
