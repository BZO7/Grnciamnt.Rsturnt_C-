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
    produtos[0] = {100, "Coca-Cola 350ml", 1, 5.00, true};
    produtos[1] = {101, "Suco Laranja 300ml", 1, 6.50, true};
    produtos[2] = {102, "Agua Mineral 500ml", 1, 3.50, true};
    produtos[3] = {200, "Coxinha", 2, 4.00, true};
    produtos[4] = {201, "Pastel Queijo", 2, 7.00, true};
    produtos[5] = {202, "Empada Frango", 2, 5.50, true};
    produtos[6] = {300, "Pudim", 3, 8.00, true};
    produtos[7] = {301, "Sorvete 1 bola", 3, 5.50, true};
    produtos[8] = {400, "Spaghetti ao molho", 4, 22.00, true};
    produtos[9] = {401, "Lasanha", 4, 30.00, true};
    produtos[10] = {500, "Batata Frita", 5, 12.00, true};
    produtos[11] = {501, "Porcao Mista", 5, 25.00, true};
}

void inicializarIngredientes(Ingrediente ingredientes[], int &n) {
    n = 12;
    ingredientes[0] = {10, "Acucar (kg)", 50, 10, 100, 4.00};
    ingredientes[1] = {11, "Leite (L)", 30, 10, 50, 3.50};
    ingredientes[2] = {12, "Farinha (kg)", 40, 15, 100, 2.50};
    ingredientes[3] = {13, "Queijo (kg)", 10, 5, 30, 25.00};
    ingredientes[4] = {14, "Carne (kg)", 20, 8, 50, 30.00};
    ingredientes[5] = {15, "Oleo (L)", 15, 5, 30, 6.00};
    ingredientes[6] = {16, "Tomate (kg)", 25, 8, 60, 5.00};
    ingredientes[7] = {17, "Macarrao (kg)", 20, 5, 60, 4.50};
    ingredientes[8] = {18, "Oregano (g)", 200, 50, 500, 0.05};
    ingredientes[9] = {19, "Manteiga (kg)", 12, 4, 30, 18.00};
    ingredientes[10] = {20, "Frango (kg)", 18, 6, 40, 20.00};
    ingredientes[11] = {21, "Batata (kg)", 40, 10, 100, 3.00};
}

void inicializarConsumo(ConsumoIngrediente consumo[], int &n) {
    n = 18;
    consumo[0] = {200, 12, 1};
    consumo[1] = {200, 14, 1};
    consumo[2] = {201, 12, 1};
    consumo[3] = {201, 13, 1};
    consumo[4] = {202, 12, 1};
    consumo[5] = {202, 20, 1};
    consumo[6] = {300, 11, 1};
    consumo[7] = {300, 10, 1};
    consumo[8] = {301, 11, 1};
    consumo[9] = {400, 17, 1};
    consumo[10] = {400, 16, 1};
    consumo[11] = {400, 13, 1};
    consumo[12] = {401, 17, 2};
    consumo[13] = {401, 14, 2};
    consumo[14] = {500, 21, 1};
    consumo[15] = {501, 21, 1};
    consumo[16] = {501, 13, 1};
    consumo[17] = {201, 15, 1};
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
    ordenarClientes(clientes, n);
    if (buscaBinariaCliente(clientes, n, novo.codigo) != -1) return false;
    if (n >= MAX_CLIENTES) return false;
    clientes[n++] = novo;
    ordenarClientes(clientes, n);
    return true;
}

bool incluirGarcom(Garcom garcons[], int &n, const Garcom &novo) {
    ordenarGarcons(garcons, n);
    if (buscaBinariaGarcom(garcons, n, novo.codigo) != -1) return false;
    if (n >= MAX_GARCONS) return false;
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
    limparEntrada();
    cout << "Nome: ";
    cin.getline(g.nome, sizeof(g.nome));
    return g;
}

Pedido inputPedido() {
    Pedido p;
    cout << "Codigo do pedido: ";
    cin >> p.codigo;
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

            if (incluirCliente(clientes, nClientes, novo))
                cout << "Cliente incluido.\n";
            else
                cout << "Erro ao incluir cliente.\n";

            break;
        }

        case 3: {
            Garcom novo = inputGarcom();

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
            ItemPedido it = inputItemPedido(p.codigo);

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
