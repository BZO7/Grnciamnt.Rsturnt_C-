Implementar um programa em C++ que percorra os registros de um arquivo sequencial,
mostrando suas informa��es, desde o primeiro registro at� o ultimo.
Para simular a estrutura de um arquivo sequencial, utilize uma estrutura (Struct).
Crie uma fun��o espec�fica para a leitura dos dados e outra fun��o espec�fica para
o percurso dos registros.
/* Implementar um programa em C++ que percorra os registros de um arquivo sequencial,
mostrando suas informações, desde o primeiro registro até o último.
Nesse exercício, vamos utilizar a biblioteca fstream para leitura e escrita em arquivos.
- Crie funções específicas para:
    - Ler os dados de clientes, inserindo as informações de cada cliente em uma linha de um arquivo. 
    - Percorrer os registros dos clientes já cadastrados nesse arquivo e exibir em tela.
 Implementar um programa em C++ que percorra os registros de um arquivo sequencial,
mostrando suas informa��es, desde o primeiro registro at� o ultimo.
Para simular a estrutura de um arquivo sequencial, utilize uma estrutura (Struct).
Crie uma fun��o espec�fica para a leitura dos dados e outra fun��o espec�fica para
o percurso dos registros.
Busca Aleat�ria = Busca Bin�ria
Inclus�o de registros Arquivo Sequencial
Exclus�o de registros Arquivo Sequencial

Isso foi oque o profers ensino para nos ate agora, e agora ele que que agente faca um gerenciamento de restaurante com no maximo 1.000 linhas, ou seja nao pode ter poucas linhas. Com base nesse enunciado:
Escreva um programa em C++ para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de gerenciamento de um restaurante:

Categorias: código, descrição
Produtos (cardápio): código, descrição, código_categoria, preço_unitario
Ingredientes: código, descrição, quant_estoque, estoque_minimo, estoque_maximo, preço_unitario
Clientes: código, nome, telefone
Garçons: código, nome
Pedidos: código, código_cliente, código_garçom, data
Itens do Pedido: código_pedido, código_produto, quantidade
Consumo de Ingredientes: código_produto, código_ingrediente, quantidade_necessária

1. Escreva funções específicas para a leitura dos dados das estruturas: Categorias, Produtos e Ingredientes.

2. Escreva uma função para permitir a inclusão de novos registros na tabela de Clientes.
2.1) O programa deverá garantir que o código do cliente a ser inserido não existe na tabela de Clientes.

3. Escreva uma função para permitir a inclusão de novos registros na tabela de Garçons.
3.1) O programa deverá garantir que o código do garçom a ser inserido não existe na tabela de Garçons.

4. Escreva uma função para permitir a exclusão de registros da tabela de Produtos.

5. Escreva uma função para permitir o registro de um novo Pedido.
5.1) Quando o usuário digitar o código do cliente, o programa deverá buscar este código na tabela de Clientes e exibir o nome do cliente.
5.2) Quando o usuário digitar o código do garçom, o programa deverá buscar este código na tabela de Garçons e exibir o nome do garçom.
5.3) O programa deverá permitir a inclusão de um único produto para cada pedido, conforme orientações do item 6.

6. Escreva uma função para permitir a inclusão de produtos em um pedido.
6.1) Quando o usuário digitar o código do produto, o programa deverá buscar este código na tabela de Produtos e exibir a descrição e o preço unitário.
6.2) Para cada produto selecionado, o programa deverá verificar na estrutura de Consumo de Ingredientes quais ingredientes são necessários.
6.3) Para cada ingrediente necessário:
     Mostrar a descrição do ingrediente
     Verificar se a quantidade em estoque é suficiente
     O programa não deverá permitir a inclusão do item caso algum ingrediente não tenha quantidade suficiente
6.4) Caso seja possível preparar o produto, o programa deverá subtrair do estoque a quantidade necessária de cada ingrediente

7. Escreva uma função para permitir ao usuário consultar os dados de determinado ingrediente.
7.1) Para cada ingrediente consultado, exibir:
     Todos os seus dados
     O valor total em estoque (quant_estoque × preço_unitario)

8. Escreva uma função para exibir todos os ingredientes que estejam com a quantidade em estoque abaixo do estoque mínimo.
8.1) As seguintes informações devem ser exibidas: Código, Descrição, Quantidade em estoque, Estoque máximo, Quantidade a ser comprada, Valor da compra
8.1.1) A quantidade a ser comprada é calculada pela diferença entre o estoque máximo e a quantidade em estoque
8.2) Ao final, a função deverá exibir o valor total a ser gasto na reposição de ingredientes

9. Escreva uma função para exibir o valor total arrecadado com todos os pedidos.
9.1) O valor de cada pedido deve ser calculado pela soma dos valores de seus itens
9.2) O valor de cada item é calculado multiplicando a quantidade pelo preço unitário do produto

Observações:  
Todas as funções descritas acima deverão ser chamadas através de um menu de opções, que será implementado na função main().
Não utilizar variáveis globais
As buscas devem ser realizadas de forma aleatória
Garantir validações conforme especificado em cada item
