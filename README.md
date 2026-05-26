Sistema de Gerenciamento de Restaurante em C++
Descrição

Este projeto consiste em um sistema de gerenciamento de restaurante desenvolvido em C++, utilizando estruturas (struct) e vetores para simular arquivos sequenciais em memória.

O sistema permite realizar o controle de:

Categorias
Produtos do cardápio
Ingredientes
Clientes
Garçons
Pedidos
Itens do pedido
Consumo de ingredientes

O programa foi desenvolvido com foco em lógica de programação, manipulação de estruturas, vetores, funções e validações de dados.

Funcionalidades
Cadastro e leitura de dados

O sistema possui funções específicas para leitura e armazenamento de:

Categorias
Produtos
Ingredientes
Controle de clientes
Inclusão de novos clientes
Validação para impedir códigos duplicados
Controle de garçons
Inclusão de garçons
Verificação de código já existente
Controle de produtos
Exclusão de produtos cadastrados
Registro de pedidos

O sistema permite:

Criar novos pedidos
Buscar automaticamente:
Cliente pelo código
Garçom pelo código
Inserir produtos no pedido
Controle de estoque de ingredientes

Ao adicionar um produto no pedido:

O sistema verifica quais ingredientes são necessários
Confere se existe estoque suficiente
Impede a inclusão caso falte ingrediente
Atualiza automaticamente o estoque após a venda
Consulta de ingredientes

É possível consultar:

Código
Descrição
Estoque atual
Estoque mínimo
Estoque máximo
Preço unitário
Valor total em estoque
Relatório de reposição de estoque

O sistema identifica ingredientes abaixo do estoque mínimo e exibe:

Código
Descrição
Quantidade atual
Estoque máximo
Quantidade necessária para reposição
Valor da compra

Também calcula o valor total necessário para reposição do estoque.

Relatório financeiro

O sistema calcula:

Valor total arrecadado com os pedidos
Soma total dos itens vendidos
Tecnologias Utilizadas
Linguagem: C++
Paradigma: Programação Estruturada
Estruturas utilizadas:
struct
vector
funções
busca sequencial
Estruturas do Sistema
Categorias
struct Categoria {
    int codigo;
    string descricao;
};
Produtos
struct Produto {
    int codigo;
    string descricao;
    int codigo_categoria;
    double preco_unitario;
};
Ingredientes
struct Ingrediente {
    int codigo;
    string descricao;
    double quant_estoque;
    double estoque_minimo;
    double estoque_maximo;
    double preco_unitario;
};
Clientes
struct Cliente {
    int codigo;
    string nome;
    string telefone;
};
Garçons
struct Garcom {
    int codigo;
    string nome;
};
Pedidos
struct Pedido {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    string data;
};
Itens do Pedido
struct ItemPedido {
    int codigo_pedido;
    int codigo_produto;
    int quantidade;
};
Consumo de Ingredientes
struct ConsumoIngrediente {
    int codigo_produto;
    int codigo_ingrediente;
    double quantidade_necessaria;
};
Menu do Sistema
1 - Ler categorias
2 - Ler produtos
3 - Ler ingredientes
4 - Incluir cliente
5 - Incluir garçom
6 - Excluir produto
7 - Novo pedido
8 - Consultar ingrediente
9 - Ingredientes abaixo mínimo
10 - Total arrecadado
0 - Sair
Regras Implementadas
Não utilização de variáveis globais
Validação de códigos duplicados
Busca sequencial para localizar registros
Controle automático de estoque
Verificação de disponibilidade de ingredientes
Atualização automática do estoque após pedidos
Objetivo Acadêmico

Este projeto foi desenvolvido com fins acadêmicos para prática de:

Programação em C++
Manipulação de vetores
Estruturas de dados
Modularização
Funções
Controle de estoque
Simulação de banco de dados sequencial
Como Executar
Exemplo de Uso
Cadastrar categorias
Cadastrar produtos
Cadastrar ingredientes
Adicionar clientes
Adicionar garçons
Criar pedidos
Consultar estoque
Verificar total arrecadado
Melhorias Futuras
Persistência em arquivos .txt ou .dat
Interface gráfica
Banco de dados
Login de usuários
Relatórios avançados
Controle de mesas
Controle de pagamentos
Exclusão lógica de registros

Projeto desenvolvido para fins de estudo e aprendizado em Análise e Desenvolvimento de Sistemas.
