#!/bin/bash
# grade.sh - Script de verificação para o projeto push_swap
# Este script roda o norminette, casos de teste fixos e testes de desempenho,
# verificando se o projeto atende aos requisitos da 42.

# 1. Verificação do Norminette
echo "Executando Norminette..."
norm_result=$(norminette | grep "Error")
if [ ! -z "$norm_result" ]; then
    echo "Erro no Norminette:"
    echo "$norm_result"
    exit 1
else
    echo "Norminette: OK!"
fi

echo "----------------------------------"

# 2. Testes fixos com entradas conhecidas
echo "Executando testes fixos..."
fixed_tests=(
    "2 1 3 6 5 8"
    "1 5 2 4 3"
    "3 2 1"
    "1 2 3 4 5"  # Pilha já ordenada
)

for test in "${fixed_tests[@]}"; do
    echo "Testando entrada: $test"
    result=$(./push_swap $test | ./checker_linux $test)
    if [ "$result" != "OK" ]; then
        echo "Falha no teste com entrada: $test. Resultado: $result"
        exit 1
    else
        echo "Teste OK para entrada: $test"
    fi
    echo "----------------------------------"
done

# 3. Teste de desempenho com 100 números
echo "Executando teste de desempenho com 100 números..."
ARG100=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,101), 100))))")
ops100=$(./push_swap $ARG100 | wc -l)
echo "Operações para 100 números: $ops100"
if [ $ops100 -gt 700 ]; then
    echo "Falha: Número de operações para 100 números excede 700."
    exit 1
else
    echo "Teste de 100 números: OK!"
fi

echo "----------------------------------"

# 4. Teste de desempenho com 500 números
echo "Executando teste de desempenho com 500 números..."
ARG500=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,501), 500))))")
ops500=$(./push_swap $ARG500 | wc -l)
echo "Operações para 500 números: $ops500"
if [ $ops500 -gt 5500 ]; then
    echo "Falha: Número de operações para 500 números excede 5500."
    exit 1
else
    echo "Teste de 500 números: OK!"
fi

echo "----------------------------------"
echo "Todos os testes passaram! Projeto 100% aprovado!"
