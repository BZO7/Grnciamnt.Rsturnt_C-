#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>
#include <fstream>

using namespace std;

const int MAX_CATEGORIAS = 50;
const int MAX_PRODUTOS = 200;
const int MAX_INGREDIENTES = 200;
const int MAX_CLIENTES = 500;
const int MAX_GARCONS = 100;
const int MAX_PEDIDOS = 500;
const int MAX_ITENS_PEDIDO = 1000;
const int MAX_CONSUMO = 1000;
const int MAX_LISTA = 200;

struct Categoria {
    int codigo;
    char descricao[50];
};

struct Produto {
    int codigo;
    char descricao[60];
    int codigo_categoria;
    double preco_unitario;
    bool ativo;
};

struct Ingrediente {
    int codigo;
    char descricao[60];
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    double preco_unitario;
};

struct Cliente {
    int codigo;
    char nome[60];
    char telefone[20];
};

struct Garcom {
    int codigo;
    char nome[60];
};

struct Pedido {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    char data[20];
    bool ativo;
};

struct ItemPedido {
    int codigo_pedido;
    int codigo_produto;
    int quantidade;
};

struct ConsumoIngrediente {
    int codigo_produto;
    int codigo_ingrediente;
    int quantidade_necessaria;
};

void limparEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inicializarCategorias(Categoria categorias[], int &n) {
    n = 6;
    categorias[0].codigo = 1; strcpy(categorias[0].descricao, "Bebidas");
    categorias[1].codigo = 2; strcpy(categorias[1].descricao, "Salgados");
    categorias[2].codigo = 3; strcpy(categorias[2].descricao, "Sobremesas");
    categorias[3].codigo = 4; strcpy(categorias[3].descricao, "Massas");
    categorias[4].codigo = 5; strcpy(categorias[4].descricao, "Porcoes");
    categorias[5].codigo = 6; strcpy(categorias[5].descricao, "Pães");
}

void inicializarProdutos(Produto produtos[], int &n) {
    n = 12;
    produtos[0].codigo = 100; strcpy(produtos[0].descricao, "Coca-Cola 350ml"); produtos[0].codigo_categoria = 1; produtos[0].preco_unitario = 5.00; produtos[0].ativo = true;
    produtos[1].codigo = 101; strcpy(produtos[1].descricao, "Suco Laranja 300ml"); produtos[1].codigo_categoria = 1; produtos[1].preco_unitario = 6.50; produtos[1].ativo = true;
    produtos[2].codigo = 102; strcpy(produtos[2].descricao, "Agua Mineral 500ml"); produtos[2].codigo_categoria = 1; produtos[2].preco_unitario = 3.50; produtos[2].ativo = true;
    produtos[3].codigo = 200; strcpy(produtos[3].descricao, "Coxinha"); produtos[3].codigo_categoria = 2; produtos[3].preco_unitario = 4.00; produtos[3].ativo = true;
    produtos[4].codigo = 201; strcpy(produtos[4].descricao, "Pastel Queijo"); produtos[4].codigo_categoria = 2; produtos[4].preco_unitario = 7.00; produtos[4].ativo = true;
    produtos[5].codigo = 202; strcpy(produtos[5].descricao, "Empada Frango"); produtos[5].codigo_categoria = 2; produtos[5].preco_unitario = 5.50; produtos[5].ativo = true;
    produtos[6].codigo = 300; strcpy(produtos[6].descricao, "Pudim"); produtos[6].codigo_categoria = 3; produtos[6].preco_unitario = 8.00; produtos[6].ativo = true;
    produtos[7].codigo = 301; strcpy(produtos[7].descricao, "Sorvete 1 bola"); produtos[7].codigo_categoria = 3; produtos[7].preco_unitario = 5.50; produtos[7].ativo = true;
    produtos[8].codigo = 400; strcpy(produtos[8].descricao, "Spaghetti ao molho"); produtos[8].codigo_categoria = 4; produtos[8].preco_unitario = 22.00; produtos[8].ativo = true;
    produtos[9].codigo = 401; strcpy(produtos[9].descricao, "Lasanha"); produtos[9].codigo_categoria = 4; produtos[9].preco_unitario = 30.00; produtos[9].ativo = true;
    produtos[10].codigo = 500; strcpy(produtos[10].descricao, "Batata Frita"); produtos[10].codigo_categoria = 5; produtos[10].preco_unitario = 12.00; produtos[10].ativo = true;
    produtos[11].codigo = 501; strcpy(produtos[11].descricao, "Porcao Mista"); produtos[11].codigo_categoria = 5; produtos[11].preco_unitario = 25.00; produtos[11].ativo = true;
}

void inicializarIngredientes(Ingrediente ingredientes[], int &n) {
    n = 12;
    ingredientes[0].codigo = 10; strcpy(ingredientes[0].descricao, "Acucar (kg)"); ingredientes[0].quant_estoque = 50; ingredientes[0].estoque_minimo = 10; ingredientes[0].estoque_maximo = 100; ingredientes[0].preco_unitario = 4.00;
    ingredientes[1].codigo = 11; strcpy(ingredientes[1].descricao, "Leite (L)"); ingredientes[1].quant_estoque = 30; ingredientes[1].estoque_minimo = 10; ingredientes[1].estoque_maximo = 50; ingredientes[1].preco_unitario = 3.50;
    ingredientes[2].codigo = 12; strcpy(ingredientes[2].descricao, "Farinha (kg)"); ingredientes[2].quant_estoque = 40; ingredientes[2].estoque_minimo = 15; ingredientes[2].estoque_maximo = 100; ingredientes[2].preco_unitario = 2.50;
    ingredientes[3].codigo = 13; strcpy(ingredientes[3].descricao, "Queijo (kg)"); ingredientes[3].quant_estoque = 10; ingredientes[3].estoque_minimo = 5; ingredientes[3].estoque_maximo = 30; ingredientes[3].preco_unitario = 25.00;
    ingredientes[4].codigo = 14; strcpy(ingredientes[4].descricao, "Carne (kg)"); ingredientes[4].quant_estoque = 20; ingredientes[4].estoque_minimo = 8; ingredientes[4].estoque_maximo = 50; ingredientes[4].preco_unitario = 30.00;
    ingredientes[5].codigo = 15; strcpy(ingredientes[5].descricao, "Oleo (L)"); ingredientes[5].quant_estoque = 15; ingredientes[5].estoque_minimo = 5; ingredientes[5].estoque_maximo = 30; ingredientes[5].preco_unitario = 6.00;
    ingredientes[6].codigo = 16; strcpy(ingredientes[6].descricao, "Tomate (kg)"); ingredientes[6].quant_estoque = 25; ingredientes[6].estoque_minimo = 8; ingredientes[6].estoque_maximo = 60; ingredientes[6].preco_unitario = 5.00;
    ingredientes[7].codigo = 17; strcpy(ingredientes[7].descricao, "Macarrao (kg)"); ingredientes[7].quant_estoque = 20; ingredientes[7].estoque_minimo = 5; ingredientes[7].estoque_maximo = 60; ingredientes[7].preco_unitario = 4.50;
    ingredientes[8].codigo = 18; strcpy(ingredientes[8].descricao, "Oregano (g)"); ingredientes[8].quant_estoque = 200; ingredientes[8].estoque_minimo = 50; ingredientes[8].estoque_maximo = 500; ingredientes[8].preco_unitario = 0.05;
    ingredientes[9].codigo = 19; strcpy(ingredientes[9].descricao, "Manteiga (kg)"); ingredientes[9].quant_estoque = 12; ingredientes[9].estoque_minimo = 4; ingredientes[9].estoque_maximo = 30; ingredientes[9].preco_unitario = 18.00;
    ingredientes[10].codigo = 20; strcpy(ingredientes[10].descricao, "Frango (kg)"); ingredientes[10].quant_estoque = 18; ingredientes[10].estoque_minimo = 6; ingredientes[10].estoque_maximo = 40; ingredientes[10].preco_unitario = 20.00;
    ingredientes[11].codigo = 21; strcpy(ingredientes[11].descricao, "Batata (kg)"); ingredientes[11].quant_estoque = 40; ingredientes[11].estoque_minimo = 10; ingredientes[11].estoque_maximo = 100; ingredientes[11].preco_unitario = 3.00;
}

void inicializarConsumo(ConsumoIngrediente consumo[], int &n) {
    n = 18;
    consumo[0].codigo_produto = 200; consumo[0].codigo_ingrediente = 12; consumo[0].quantidade_necessaria = 1;
    consumo[1].codigo_produto = 200; consumo[1].codigo_ingrediente = 14; consumo[1].quantidade_necessaria = 1;
    consumo[2].codigo_produto = 201; consumo[2].codigo_ingrediente = 12; consumo[2].quantidade_necessaria = 1;
    consumo[3].codigo_produto = 201; consumo[3].codigo_ingrediente = 13; consumo[3].quantidade_necessaria = 1;
    consumo[4].codigo_produto = 202; consumo[4].codigo_ingrediente = 12; consumo[4].quantidade_necessaria = 1;
    consumo[5].codigo_produto = 202; consumo[5].codigo_ingrediente = 20; consumo[5].quantidade_necessaria = 1;
    consumo[6].codigo_produto = 300; consumo[6].codigo_ingrediente = 11; consumo[6].quantidade_necessaria = 1;
    consumo[7].codigo_produto = 300; consumo[7].codigo_ingrediente = 10; consumo[7].quantidade_necessaria = 1;
    consumo[8].codigo_produto = 301; consumo[8].codigo_ingrediente = 11; consumo[8].quantidade_necessaria = 1;
    consumo[9].codigo_produto = 400; consumo[9].codigo_ingrediente = 17; consumo[9].quantidade_necessaria = 1;
    consumo[10].codigo_produto = 400; consumo[10].codigo_ingrediente = 16; consumo[10].quantidade_necessaria = 1;
    consumo[11].codigo_produto = 400; consumo[11].codigo_ingrediente = 13; consumo[11].quantidade_necessaria = 1;
    consumo[12].codigo_produto = 401; consumo[12].codigo_ingrediente = 17; consumo[12].quantidade_necessaria = 2;
    consumo[13].codigo_produto = 401; consumo[13].codigo_ingrediente = 14; consumo[13].quantidade_necessaria = 2;
    consumo[14].codigo_produto = 500; consumo[14].codigo_ingrediente = 21; consumo[14].quantidade_necessaria = 1;
    consumo[15].codigo_produto = 501; consumo[15].codigo_ingrediente = 21; consumo[15].quantidade_necessaria = 1;
    consumo[16].codigo_produto = 501; consumo[16].codigo_ingrediente = 13; consumo[16].quantidade_necessaria = 1;
    consumo[17].codigo_produto = 201; consumo[17].codigo_ingrediente = 15; consumo[17].quantidade_necessaria = 1;
}

void ordenarCategorias(Categoria vetor[], int n) {
    for (int i = 1; i < n; i++) {
        Categoria chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarProdutos(Produto vetor[], int n) {
    for (int i = 1; i < n; i++) {
        Produto chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarIngredientes(Ingrediente vetor[], int n) {
    for (int i = 1; i < n; i++) {
        Ingrediente chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarClientes(Cliente vetor[], int n) {
    for (int i = 1; i < n; i++) {
        Cliente chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarGarcons(Garcom vetor[], int n) {
    for (int i = 1; i < n; i++) {
        Garcom chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo > chave.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarConsumo(ConsumoIngrediente vetor[], int n) {
    for (int i = 1; i < n; i++) {
        ConsumoIngrediente chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].codigo_produto > chave.codigo_produto) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int buscaBinariaProduto(Produto produtos[], int n, int codigo) {
    int i = 0, f = n - 1;
    while (i <= f) {
        int m = (i + f) / 2;
        if (produtos[m].codigo == codigo) return m;
        else if (produtos[m].codigo < codigo) i = m + 1;
        else f = m - 1;
    }
    return -1;
}

int buscaBinariaCliente(Cliente clientes[], int n, int codigo) {
    int i = 0, f = n - 1;
    while (i <= f) {
        int m = (i + f) / 2;
        if (clientes[m].codigo == codigo) return m;
        else if (clientes[m].codigo < codigo) i = m + 1;
        else f = m - 1;
    }
    return -1;
}

int buscaBinariaGarcom(Garcom garcons[], int n, int codigo) {
    int i = 0, f = n - 1;
    while (i <= f) {
        int m = (i + f) / 2;
        if (garcons[m].codigo == codigo) return m;
        else if (garcons[m].codigo < codigo) i = m + 1;
        else f = m - 1;
    }
    return -1;
}

int buscaBinariaIngrediente(Ingrediente ingredientes[], int n, int codigo) {
    int i = 0, f = n - 1;
    while (i <= f) {
        int m = (i + f) / 2;
        if (ingredientes[m].codigo == codigo) return m;
        else if (ingredientes[m].codigo < codigo) i = m + 1;
        else f = m - 1;
    }
    return -1;
}

bool incluirCliente(Cliente clientes[], int &n, const Cliente &novo) {
    if (novo.codigo <= 0) return false;
    if (n >= MAX_CLIENTES) return false;
    ordenarClientes(clientes, n);
    if (buscaBinariaCliente(clientes, n, novo.codigo) != -1) return false;
    clientes[n++] = novo;
    ordenarClientes(clientes, n);
    return true;
}

bool incluirGarcom(Garcom garcons[], int &n, const Garcom &novo) {
    if (novo.codigo <= 0) return false;
    if (n >= MAX_GARCONS) return false;
    ordenarGarcons(garcons, n);
    if (buscaBinariaGarcom(garcons, n, novo.codigo) != -1) return false;
    garcons[n++] = novo;
    ordenarGarcons(garcons, n);
    return true;
}

bool excluirProduto(Produto produtos[], int &n, int codigo) {
    ordenarProdutos(produtos, n);
    int idx = buscaBinariaProduto(produtos, n, codigo);
    if (idx == -1)
        return false;

    if (!produtos[idx].ativo)
        return false;

    produtos[idx].ativo = false;
    return true;
}

bool construirListaConsumoParaProduto(ConsumoIngrediente consumo[], int n_consumo,
                                      int codProduto,
                                      int listaCods[], int listaQt[] , int &listaN) {
    listaN = 0;
    for (int i = 0; i < n_consumo; ++i) {
        if (consumo[i].codigo_produto == codProduto) {
            listaCods[listaN] = consumo[i].codigo_ingrediente;
            listaQt[listaN] = consumo[i].quantidade_necessaria;
            listaN++;
            if (listaN >= MAX_LISTA) break;
        }
    }
    return (listaN > 0);
}

bool verificarEConsumirIngredientes(int codigo_produto, int quantidade,
                                    ConsumoIngrediente consumo[], int n_consumo,
                                    Ingrediente ingredientes[], int &n_ingredientes) {
    int listaCods[MAX_LISTA];
    int listaQt[MAX_LISTA];
    int listaN = 0;
    bool tem = construirListaConsumoParaProduto(consumo, n_consumo, codigo_produto, listaCods, listaQt, listaN);
    if (!tem) return true;
    for (int i = 0; i < listaN; ++i) {
        int codIng = listaCods[i];
        int qtdNec = listaQt[i] * quantidade;
        ordenarIngredientes(ingredientes, n_ingredientes);
        int idx = buscaBinariaIngrediente(
            ingredientes,
            n_ingredientes,
            codIng);

        if (idx == -1)
            return false;

        cout << "\nIngrediente necessario: "
             << ingredientes[idx].descricao;

        cout << "\nQuantidade necessaria: "
             << qtdNec << endl;

        if (ingredientes[idx].quant_estoque < qtdNec) {
            cout << "\nEstoque insuficiente para "
                 << ingredientes[idx].descricao
                 << endl;
            return false;
        }

        ingredientes[idx].quant_estoque -= qtdNec;
        cout << ingredientes[idx].descricao
             << " consumido. Novo estoque: "
             << ingredientes[idx].quant_estoque
             << endl;
    }
    return true;
}

bool registrarPedido(Pedido pedidos[], int &n_pedidos,
                     ItemPedido itens[], int &n_itens,
                     Cliente clientes[], int n_clientes,
                     Garcom garcons[], int n_garcons,
                     Produto produtos[], int n_produtos,
                     ConsumoIngrediente consumo[], int n_consumo,
                     Ingrediente ingredientes[], int &n_ingredientes,
                     const Pedido &novoPedido,
                     const ItemPedido &novoItem) {
    for (int i = 0; i < n_pedidos; i++) {
        if (pedidos[i].codigo == novoPedido.codigo) {
            cout << "\nCodigo de pedido ja existente.\n";
            return false;
        }
    }

    ordenarClientes(clientes, n_clientes);
    ordenarGarcons(garcons, n_garcons);
    int idxCliente = buscaBinariaCliente(clientes, n_clientes, novoPedido.codigo_cliente);

    if (idxCliente == -1)
        return false;

    cout << "\nCliente encontrado: "
         << clientes[idxCliente].nome << endl;

    int idxGarcom = buscaBinariaGarcom(garcons, n_garcons, novoPedido.codigo_garcom);

    if (idxGarcom == -1)
        return false;

    cout << "Garcom encontrado: "
         << garcons[idxGarcom].nome << endl;

    ordenarProdutos(produtos, n_produtos);
    int idxProduto = buscaBinariaProduto(produtos, n_produtos, novoItem.codigo_produto);

    if (idxProduto == -1)
        return false;

    cout << "\nProduto encontrado: "
         << produtos[idxProduto].descricao
         << endl;

    cout << "Preco unitario: R$ "
         << fixed << setprecision(2)
         << produtos[idxProduto].preco_unitario
         << endl;

    if (!produtos[idxProduto].ativo)
        return false;
    if (!verificarEConsumirIngredientes(novoItem.codigo_produto, novoItem.quantidade,
                                        consumo, n_consumo, ingredientes, n_ingredientes))
        return false;
    if (n_pedidos >= MAX_PEDIDOS || n_itens >= MAX_ITENS_PEDIDO)
        return false;
    pedidos[n_pedidos++] = novoPedido;
    itens[n_itens++] = novoItem;
    return true;
}

void consultarIngrediente(Ingrediente ingredientes[], int n, int codigo) {
    ordenarIngredientes(ingredientes, n);
    int idx = buscaBinariaIngrediente(ingredientes, n, codigo);
    if (idx == -1) {
        cout << "Ingrediente nao encontrado.\n";
        return;
    }
    Ingrediente &ing = ingredientes[idx];
    cout << fixed << setprecision(2);
    cout << "\nCodigo: " << ing.codigo << "\nDescricao: " << ing.descricao
         << "\nQuantidade em estoque: " << ing.quant_estoque
         << "\nEstoque minimo: " << ing.estoque_minimo
         << "\nEstoque maximo: " << ing.estoque_maximo
         << "\nPreco unitario: R$ " << ing.preco_unitario << "\n";
    double valorTotal = ing.quant_estoque * ing.preco_unitario;
    cout << "Valor total em estoque: R$ " << valorTotal << "\n";
}

void listarIngredientesAbaixoEstoque(Ingrediente ingredientes[], int n) {
    cout << "\n--- Ingredientes abaixo do estoque minimo ---\n";
    double valorTotalReposicao = 0.0;
    cout << left << setw(8) << "Cod" << setw(25) << "Descricao" << setw(10) << "QtdEst"
         << setw(10) << "EstMax" << setw(12) << "QtdComprar" << setw(15) << "ValorCompra" << "\n";
    for (int i = 0; i < n; ++i) {
        Ingrediente &ing = ingredientes[i];
        if (ing.quant_estoque < ing.estoque_minimo) {
            int qtdComprar = ing.estoque_maximo - ing.quant_estoque;
            double valorCompra = qtdComprar * ing.preco_unitario;
            valorTotalReposicao += valorCompra;
            cout << left << setw(8) << ing.codigo << setw(25) << ing.descricao
                 << setw(10) << ing.quant_estoque << setw(10) << ing.estoque_maximo
                 << setw(12) << qtdComprar << "R$ " << setw(10) << fixed << setprecision(2) << valorCompra << "\n";
        }
    }
    cout << fixed << setprecision(2);
    cout << "\nValor total de reposicao: R$ " << valorTotalReposicao << "\n";
}

double calcularTotalArrecadado(ItemPedido itens[], int n_itens, Produto produtos[], int n_produtos) {
    ordenarProdutos(produtos, n_produtos);
    double total = 0.0;
    for (int i = 0; i < n_itens; ++i) {
        int codProd = itens[i].codigo_produto;
        int idx = buscaBinariaProduto(produtos, n_produtos, codProd);
        if (idx != -1) {
            total += produtos[idx].preco_unitario * itens[i].quantidade;
        }
    }
    return total;
}

Cliente inputCliente() {
    Cliente c;
    cout << "Codigo do cliente: ";
    cin >> c.codigo;
    
    if (c.codigo <= 0) {
        cout << "Codigo invalido.\n";
        c.codigo = -1;
        return c;
    }
    
    limparEntrada();
    cout << "Nome: ";
    cin.getline(c.nome, sizeof(c.nome));
    cout << "Telefone: ";
    cin.getline(c.telefone, sizeof(c.telefone));
    return c;
}

Garcom inputGarcom() {
    Garcom g;
    cout << "Codigo do garcom: ";
    cin >> g.codigo;
    
    if (g.codigo <= 0) {
        cout << "Codigo invalido.\n";
        g.codigo = -1;
        return g;
    }
    
    limparEntrada();
    cout << "Nome: ";
    cin.getline(g.nome, sizeof(g.nome));
    return g;
}

Pedido inputPedido() {
    Pedido p;
    cout << "Codigo do pedido: ";
    cin >> p.codigo;
    
    if (p.codigo <= 0) {
        cout << "Codigo do pedido invalido.\\n";
        p.codigo = -1;
        return p;
    }
    
    cout << "Codigo do cliente: ";
    cin >> p.codigo_cliente;
    cout << "Codigo do garcom: ";
    cin >> p.codigo_garcom;
    limparEntrada();
    cout << "Data (dd/mm/aaaa): ";
    cin.getline(p.data, sizeof(p.data));
    p.ativo = true;
    return p;
}

ItemPedido inputItemPedido(int pedidoCodigo) {
    ItemPedido it;
    it.codigo_pedido = pedidoCodigo;
    cout << "Codigo do produto: ";
    cin >> it.codigo_produto;
    
    if (it.codigo_produto <= 0) {
        cout << "Codigo do produto invalido.\n";
        it.quantidade = -1;
        return it;
    }
    
    do {
        cout << "Quantidade: ";
        cin >> it.quantidade;

        if (it.quantidade <= 0)
            cout << "Quantidade invalida.\n";

    } while (it.quantidade <= 0);
    return it;
}

void mostrarMenu() {
    cout << "\n====== MENU PRINCIPAL ======\n";
    cout << "1 - Carregar exemplos (categorias/produtos/ingredientes/consumo)\n";
    cout << "2 - Incluir Cliente\n";
    cout << "3 - Incluir Garcom\n";
    cout << "4 - Excluir Produto\n";
    cout << "5 - Registrar Pedido (um item por pedido)\n";
    cout << "6 - Consultar Ingrediente\n";
    cout << "7 - Listar Ingredientes abaixo do estoque minimo\n";
    cout << "8 - Exibir valor total arrecadado com pedidos\n";
    cout << "9 - Mostrar todos os produtos\n";
    cout << "10 - Mostrar todos os ingredientes\n";
    cout << "11 - Mostrar clientes cadastrados\n";
    cout << "12 - Mostrar garcons cadastrados\n";
    cout << "13 - Repor estoque manual de ingrediente\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
}

void mostrarProdutos(Produto produtos[], int n) {
    cout << "\n--- Lista de Produtos ---\n";
    cout << left << setw(8) << "Cod" << setw(40) << "Descricao" << setw(8) << "Cat" << setw(10) << "Preco" << setw(8) << "Ativo" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << left << setw(8) << produtos[i].codigo << setw(40) << produtos[i].descricao
             << setw(8) << produtos[i].codigo_categoria
             << "R$ " << setw(8) << fixed << setprecision(2) << produtos[i].preco_unitario
             << (produtos[i].ativo ? "Sim" : "Nao") << "\n";
    }
}
void mostrarIngredientes(Ingrediente ingredientes[], int n) {
    cout << "\n--- Lista de Ingredientes ---\n";

    for (int i = 0; i < n; i++) {
        cout << "\nCodigo: " << ingredientes[i].codigo
             << "\nDescricao: " << ingredientes[i].descricao
             << "\nEstoque: " << ingredientes[i].quant_estoque
             << "\nEstoque Minimo: " << ingredientes[i].estoque_minimo
             << "\nEstoque Maximo: " << ingredientes[i].estoque_maximo
             << "\nPreco Unitario: R$ "
             << fixed << setprecision(2)
             << ingredientes[i].preco_unitario
             << "\n";
    }
}

void mostrarClientes(Cliente clientes[], int n) {
    cout << "\n--- Clientes ---\n";

    for (int i = 0; i < n; i++) {
        cout << clientes[i].codigo
             << " - "
             << clientes[i].nome
             << " - "
             << clientes[i].telefone
             << endl;
    }
}

void mostrarGarcons(Garcom garcons[], int n) {
    cout << "\n--- Garcons ---\n";

    for (int i = 0; i < n; i++) {
        cout << garcons[i].codigo
             << " - "
             << garcons[i].nome
             << endl;
    }
}

void reporEstoqueIngrediente(Ingrediente ingredientes[], int n) {
    int codigo;
    int quantidade;

    cout << "Codigo do ingrediente: ";
    cin >> codigo;

    ordenarIngredientes(ingredientes, n);

    int idx = buscaBinariaIngrediente(
        ingredientes,
        n,
        codigo
    );

    if (idx == -1) {
        cout << "Ingrediente nao encontrado.\n";
        return;
    }

    cout << "Quantidade para adicionar: ";
    cin >> quantidade;

    if (quantidade <= 0) {
        cout << "Quantidade invalida.\n";
        return;
    }

    ingredientes[idx].quant_estoque += quantidade;

    cout << "Novo estoque: "
         << ingredientes[idx].quant_estoque
         << endl;
}

int main() {
    Categoria categorias[MAX_CATEGORIAS];
    Produto produtos[MAX_PRODUTOS];
    Ingrediente ingredientes[MAX_INGREDIENTES];
    Cliente clientes[MAX_CLIENTES];
    Garcom garcons[MAX_GARCONS];
    Pedido pedidos[MAX_PEDIDOS];
    ItemPedido itens[MAX_ITENS_PEDIDO];
    ConsumoIngrediente consumo[MAX_CONSUMO];

    int nCategorias = 0;
    int nProdutos = 0;
    int nIngredientes = 0;
    int nClientes = 0;
    int nGarcons = 0;
    int nPedidos = 0;
    int nItens = 0;
    int nConsumo = 0;

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {

        case 1:
            inicializarCategorias(categorias, nCategorias);
            inicializarProdutos(produtos, nProdutos);
            inicializarIngredientes(ingredientes, nIngredientes);
            inicializarConsumo(consumo, nConsumo);
            cout << "Dados carregados.\n";
            break;

        case 2: {
            Cliente novo = inputCliente();
            
            if (novo.codigo <= 0) {
                cout << "Codigo do cliente invalido.\n";
                break;
            }

            if (incluirCliente(clientes, nClientes, novo))
                cout << "Cliente incluido.\n";
            else
                cout << "Erro ao incluir cliente.\n";

            break;
        }

        case 3: {
            Garcom novo = inputGarcom();
            
            if (novo.codigo <= 0) {
                cout << "Codigo do garcom invalido.\n";
                break;
            }

            if (incluirGarcom(garcons, nGarcons, novo))
                cout << "Garcom incluido.\n";
            else
                cout << "Erro ao incluir garcom.\n";

            break;
        }

        case 4: {
            int codigo;

            cout << "Codigo do produto: ";
            cin >> codigo;

            if (excluirProduto(produtos, nProdutos, codigo))
                cout << "Produto excluido.\n";
            else
                cout << "Produto nao encontrado.\n";

            break;
        }

        case 5: {
            Pedido p = inputPedido();
            
            if (p.codigo <= 0) {
                cout << "Codigo do pedido invalido.\n";
                break;
            }
            
            ItemPedido it = inputItemPedido(p.codigo);
            
            if (it.quantidade <= 0) {
                cout << "Quantidade invalida.\n";
                break;
            }

            if (registrarPedido(
                    pedidos,
                    nPedidos,
                    itens,
                    nItens,
                    clientes,
                    nClientes,
                    garcons,
                    nGarcons,
                    produtos,
                    nProdutos,
                    consumo,
                    nConsumo,
                    ingredientes,
                    nIngredientes,
                    p,
                    it))
                cout << "Pedido registrado.\n";
            else
                cout << "Falha ao registrar pedido.\n";

            break;
        }

        case 6: {
            int codigo;

            cout << "Codigo do ingrediente: ";
            cin >> codigo;

            consultarIngrediente(
                ingredientes,
                nIngredientes,
                codigo
            );

            break;
        }

        case 7:
            listarIngredientesAbaixoEstoque(
                ingredientes,
                nIngredientes
            );
            break;

        case 8:
            cout << fixed << setprecision(2);
            cout << "\nTotal arrecadado: R$ "
                 << calcularTotalArrecadado(
                        itens,
                        nItens,
                        produtos,
                        nProdutos
                    )
                 << endl;
            break;

        case 9:
            mostrarProdutos(
                produtos,
                nProdutos
            );
            break;

        case 10:
            mostrarIngredientes(
                ingredientes,
                nIngredientes
            );
            break;

        case 11:
            mostrarClientes(
                clientes,
                nClientes
            );
            break;

        case 12:
            mostrarGarcons(
                garcons,
                nGarcons
            );
            break;

        case 13:
            reporEstoqueIngrediente(
                ingredientes,
                nIngredientes
            );
            break;

        case 0:
            cout << "Encerrando...\n";
            break;

        default:
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    return 0;
}
