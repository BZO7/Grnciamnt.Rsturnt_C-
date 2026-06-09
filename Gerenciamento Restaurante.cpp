#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 100;

struct Categoria {
    int codigo;
    string descricao;
};

struct Produto {
    int codigo;
    string descricao;
    int codigo_categoria;
    double preco_unitario;
};

struct Ingrediente {
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    double preco_unitario;
};

struct Cliente {
    int codigo;
    string nome;
    string telefone;
};

struct Garcom {
    int codigo;
    string nome;
};

struct Pedido {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    string data;
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

struct TempConsumo {
    int idx_ingr;
    int total_necessario;
};

void carregarDadosPadrao(Categoria categorias[], int& cont_cat, Produto produtos[], int& cont_prod, 
                         Ingrediente ingredientes[], int& cont_ingr, ConsumoIngrediente consumos[], int& cont_cons) {
    
    categorias[0] = {1, "Bebidas"};
    categorias[1] = {2, "Pratos Principais"};
    categorias[2] = {3, "Sobremesas"};
    cont_cat = 3;

    produtos[0] = {101, "Suco de Laranja", 1, 8.50};
    produtos[1] = {102, "X-Burguer", 2, 25.00};
    produtos[2] = {103, "Fritas com Queijo", 2, 18.00};
    produtos[3] = {104, "Pudim", 3, 10.00};
    cont_prod = 4;

    ingredientes[0] = {10, "Laranja", 50, 20, 100, 0.50};
    ingredientes[1] = {11, "Hamburguer Carne", 5, 10, 40, 4.50};
    ingredientes[2] = {12, "Pao de Hamburguer", 15, 8, 30, 1.20};
    ingredientes[3] = {13, "Queijo Prato", 8, 15, 50, 2.00};
    ingredientes[4] = {14, "Batata Congelada", 30, 10, 60, 3.00};
    ingredientes[5] = {15, "Leite Condensado", 12, 5, 20, 5.50};
    cont_ingr = 6;

    consumos[0] = {101, 10, 4}; 
    consumos[1] = {102, 11, 1}; 
    consumos[2] = {102, 12, 1}; 
    consumos[3] = {102, 13, 2}; 
    consumos[4] = {103, 14, 1}; 
    consumos[5] = {103, 13, 1}; 
    consumos[6] = {104, 15, 1}; 
    cont_cons = 7;
}

void carregarArquivos(Cliente clientes[], int& cont_cli, Garcom garcons[], int& cont_garc,
                      Pedido pedidos[], int& cont_ped, ItemPedido itens[], int& cont_itens) {
    
    ifstream f_cli("clientes.txt");
    if (f_cli.is_open()) {
        while (f_cli >> clientes[cont_cli].codigo) {
            f_cli.ignore();
            getline(f_cli, clientes[cont_cli].nome);
            getline(f_cli, clientes[cont_cli].telefone);
            cont_cli++;
        }
        f_cli.close();
    }

    ifstream f_garc("garcons.txt");
    if (f_garc.is_open()) {
        while (f_garc >> garcons[cont_garc].codigo) {
            f_garc.ignore();
            getline(f_garc, garcons[cont_garc].nome);
            cont_garc++;
        }
        f_garc.close();
    }

    ifstream f_ped("pedidos.txt");
    if (f_ped.is_open()) {
        while (f_ped >> pedidos[cont_ped].codigo >> pedidos[cont_ped].codigo_cliente >> pedidos[cont_ped].codigo_garcom) {
            f_ped.ignore();
            getline(f_ped, pedidos[cont_ped].data);
            cont_ped++;
        }
        f_ped.close();
    }

    ifstream f_itens("itens.txt");
    if (f_itens.is_open()) {
        while (f_itens >> itens[cont_itens].codigo_pedido >> itens[cont_itens].codigo_produto >> itens[cont_itens].quantidade) {
            cont_itens++;
        }
        f_itens.close();
    }
}

void salvarArquivos(const Cliente clientes[], int cont_cli, const Garcom garcons[], int cont_garc,
                    const Pedido pedidos[], int cont_ped, const ItemPedido itens[], int cont_itens) {
    
    ofstream f_cli("clientes.txt");
    for (int i = 0; i < cont_cli; i++) {
        f_cli << clientes[i].codigo << "\n" << clientes[i].nome << "\n" << clientes[i].telefone << "\n";
    }
    f_cli.close();

    ofstream f_garc("garcons.txt");
    for (int i = 0; i < cont_garc; i++) {
        f_garc << garcons[i].codigo << "\n" << garcons[i].nome << "\n";
    }
    f_garc.close();

    ofstream f_ped("pedidos.txt");
    for (int i = 0; i < cont_ped; i++) {
        f_ped << pedidos[i].codigo << " " << pedidos[i].codigo_cliente << " " << pedidos[i].codigo_garcom << "\n" << pedidos[i].data << "\n";
    }
    f_ped.close();

    ofstream f_itens("itens.txt");
    for (int i = 0; i < cont_itens; i++) {
        f_itens << itens[i].codigo_pedido << " " << itens[i].codigo_produto << " " << itens[i].quantidade << "\n";
    }
    f_itens.close();
}

void lerCategorias(const Categoria categorias[], int cont_cat) {
    cout << "\n--- CATEGORIAS DO CARDAPIO ---\n";
    for (int i = 0; i < cont_cat; ++i) {
        cout << "ID: " << categorias[i].codigo << " | " << categorias[i].descricao << "\n";
    }
}

void lerProdutos(const Produto produtos[], int cont_prod) {
    cout << "\n--- CARDAPIO DISPONIVEL ---\n";
    for (int i = 0; i < cont_prod; ++i) {
        cout << "Cod: " << produtos[i].codigo 
             << " | Prato: " << produtos[i].descricao 
             << " | Categoria: " << produtos[i].codigo_categoria 
             << " | Preco: R$ " << fixed << setprecision(2) << produtos[i].preco_unitario << "\n";
    }
}

void lerIngredientes(const Ingrediente ingredientes[], int cont_ingr) {
    cout << "\n--- ESTOQUE ATUAL DE INSUMOS ---\n";
    for (int i = 0; i < cont_ingr; ++i) {
        cout << "Cod: " << ingredientes[i].codigo 
             << " | Item: " << ingredientes[i].descricao 
             << " | Quantidade: " << ingredientes[i].quant_estoque 
             << " | Preco Un: R$ " << ingredientes[i].preco_unitario << "\n";
    }
}

void incluirCliente(Cliente clientes[], int& cont_cli) {
    cout << "\n--- REGISTRAR NOVO CLIENTE ---\n";
    if (cont_cli >= MAX) {
        cout << "Armazenamento de clientes esgotado.\n";
        return;
    }

    int codigo;
    cout << "Defina o codigo identificador: ";
    cin >> codigo;

    for (int i = 0; i < cont_cli; ++i) {
        if (clientes[i].codigo == codigo) {
            cout << "Identificador ja existente no banco de dados.\n";
            return;
        }
    }

    Cliente novo;
    novo.codigo = codigo;
    cin.ignore();
    cout << "Nome completo: ";
    getline(cin, novo.nome);
    cout << "Telefone de contato: ";
    getline(cin, novo.telefone);

    clientes[cont_cli] = novo;
    cont_cli++;
    cout << "Cliente adicionado com sucesso.\n";
}

void incluirGarcom(Garcom garcons[], int& cont_garc) {
    cout << "\n--- REGISTRAR NOVO GARCOM ---\n";
    if (cont_garc >= MAX) {
        cout << "Armazenamento de equipe esgotado.\n";
        return;
    }

    int codigo;
    cout << "Defina o codigo identificador: ";
    cin >> codigo;

    for (int i = 0; i < cont_garc; ++i) {
        if (garcons[i].codigo == codigo) {
            cout << "Identificador ja cadastrado na equipe.\n";
            return;
        }
    }

    Garcom novo;
    novo.codigo = codigo;
    cin.ignore();
    cout << "Nome completo do colaborador: ";
    getline(cin, novo.nome);

    garcons[cont_garc] = novo;
    cont_garc++;
    cout << "Colaborador integrado com sucesso.\n";
}

void excluirProduto(Produto produtos[], int& cont_prod) {
    cout << "\n--- REMOCAO DE PRODUTO DO CARDAPIO ---\n";
    int codigo;
    cout << "Insira o codigo do produto para delecao: ";
    cin >> codigo;

    for (int i = 0; i < cont_prod; ++i) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < cont_prod - 1; ++j) {
                produtos[j] = produtos[j + 1];
            }
            cont_prod--;
            cout << "Produto removido permanentemente do cardapio.\n";
            return;
        }
    }
    cout << "Codigo nao localizado.\n";
}

void atualizarEstoqueManual(Ingrediente ingredientes[], int cont_ingr) {
    cout << "\n--- ATUALIZACAO MANUAL DE ESTOQUE (COMPRAS) ---\n";
    int codigo, qtd;
    cout << "Insira o codigo do ingrediente comprado: ";
    cin >> codigo;

    for (int i = 0; i < cont_ingr; i++) {
        if (ingredientes[i].codigo == codigo) {
            cout << "Ingrediente localizado: " << ingredientes[i].descricao << "\n";
            cout << "Quantidade atual em estoque: " << ingredientes[i].quant_estoque << "\n";
            cout << "Quantidade recebida do fornecedor: ";
            cin >> qtd;

            if (ingredientes[i].quant_estoque + qtd > ingredientes[i].estoque_maximo) {
                cout << "Aviso: Esse volume excede a capacidade maxima de armazenamento de " << ingredientes[i].estoque_maximo << " unidades.\n";
                cout << "Operacao cancelada.\n";
                return;
            }

            ingredientes[i].quant_estoque += qtd;
            cout << "Estoque atualizado para: " << ingredientes[i].quant_estoque << " unidades.\n";
            return;
        }
    }
    cout << "Item de estoque nao cadastrado.\n";
}

bool processarItemIndividual(int codigo_pedido, Produto produtos[], int cont_prod, 
                             Ingrediente ingredientes[], int cont_ingr, 
                             const ConsumoIngrediente consumos[], int cont_cons, 
                             ItemPedido itens[], int& cont_itens) {
    
    if (cont_itens >= MAX) {
        cout << "Limite maximo de itens no sistema atingido.\n";
        return false;
    }

    int cod_prod;
    cout << "Informe o codigo do produto: ";
    cin >> cod_prod;

    int idx_prod = -1;
    for (int i = 0; i < cont_prod; ++i) {
        if (produtos[i].codigo == cod_prod) {
            idx_prod = i;
            break;
        }
    }

    if (idx_prod == -1) {
        cout << "Produto inexistente.\n";
        return false;
    }

    cout << "Selecionado: " << produtos[idx_prod].descricao 
         << " | Preco Unitario: R$ " << produtos[idx_prod].preco_unitario << "\n";

    int qtde;
    cout << "Quantidade desejada: ";
    cin >> qtde;

    bool estoque_ok = true;
    TempConsumo verificar_estoque[MAX];
    int cont_temp = 0;

    for (int i = 0; i < cont_cons; ++i) {
        if (consumos[i].codigo_produto == cod_prod) {
            int idx_ingr = -1;
            for (int j = 0; j < cont_ingr; ++j) {
                if (ingredientes[j].codigo == consumos[i].codigo_ingrediente) {
                    idx_ingr = j;
                    break;
                }
            }

            if (idx_ingr != -1) {
                int total_nec = consumos[i].quantidade_necessaria * qtde;
                cout << "  -> Requisito: " << ingredientes[idx_ingr].descricao 
                     << " | Necessario: " << total_nec 
                     << " | Em Estoque: " << ingredientes[idx_ingr].quant_estoque << "\n";

                if (ingredientes[idx_ingr].quant_estoque < total_nec) {
                    estoque_ok = false;
                } else {
                    verificar_estoque[cont_temp] = {idx_ingr, total_nec};
                    cont_temp++;
                }
            }
        }
    }

    if (!estoque_ok) {
        cout << "Insumos insuficientes para processar este item.\n";
        return false;
    }

    for (int i = 0; i < cont_temp; ++i) {
        ingredientes[verificar_estoque[i].idx_ingr].quant_estoque -= verificar_estoque[i].total_necessario;
    }

    ItemPedido novo_item;
    novo_item.codigo_pedido = codigo_pedido;
    novo_item.codigo_produto = cod_prod;
    novo_item.quantidade = qtde;
    
    itens[cont_itens] = novo_item;
    cont_itens++;

    cout << "Item validado e adicionado com sucesso.\n";
    return true;
}

void registrarPedido(Pedido pedidos[], int& cont_ped, const Cliente clientes[], int cont_cli, 
                     const Garcom garcons[], int cont_garc, Produto produtos[], int cont_prod, 
                     Ingrediente ingredientes[], int cont_ingr, const ConsumoIngrediente consumos[], int cont_cons, 
                     ItemPedido itens[], int& cont_itens) {
    
    cout << "\n--- ABERTURA DE NOVO PEDIDO ---\n";
    if (cont_ped >= MAX) {
        cout << "Limite de pedidos em memoria esgotado.\n";
        return;
    }

    int cod_pedido;
    cout << "Insira o numero de controle do pedido: ";
    cin >> cod_pedido;

    for (int i = 0; i < cont_ped; ++i) {
        if (pedidos[i].codigo == cod_pedido) {
            cout << "Controle de pedido ja ativo.\n";
            return;
        }
    }

    int cod_cli;
    cout << "Informe o codigo do cliente: ";
    cin >> cod_cli;

    int idx_cli = -1;
    for (int i = 0; i < cont_cli; ++i) {
        if (clientes[i].codigo == cod_cli) {
            idx_cli = i;
            break;
        }
    }

    if (idx_cli == -1) {
        cout << "Ficha de cliente nao cadastrada.\n";
        return;
    }
    cout << "Ficha localizada: " << clientes[idx_cli].nome << "\n";

    int cod_garc;
    cout << "Informe o codigo do garcom responsavel: ";
    cin >> cod_garc;

    int idx_garc = -1;
    for (int i = 0; i < cont_garc; ++i) {
        if (garcons[i].codigo == cod_garc) {
            idx_garc = i;
            break;
        }
    }

    if (idx_garc == -1) {
        cout << "Registro de colaborador nao cadastrado.\n";
        return;
    }
    cout << "Atendente vinculado: " << garcons[idx_garc].nome << "\n";

    string data_ped;
    cout << "Data do atendimento (DD/MM/AAAA): ";
    cin >> data_ped;

    bool adicionou_item = false;
    char continuar = 'S';

    while (continuar == 'S' || continuar == 's') {
        if (processarItemIndividual(cod_pedido, produtos, cont_prod, ingredientes, cont_ingr, consumos, cont_cons, itens, cont_itens)) {
            adicionou_item = true;
        }
        cout << "Deseja incluir mais produtos neste atendimento? (S/N): ";
        cin >> continuar;
    }

    if (adicionou_item) {
        Pedido novo_pedido;
        novo_pedido.codigo = cod_pedido;
        novo_pedido.codigo_cliente = cod_cli;
        novo_pedido.codigo_garcom = cod_garc;
        novo_pedido.data = data_ped;
        
        pedidos[cont_ped] = novo_pedido;
        cont_ped++;
        cout << "Atendimento concluido e registrado.\n";
    } else {
        cout << "Pedido descartado pois nenhum item foi contabilizado.\n";
    }
}

void consultarIngrediente(const Ingrediente ingredientes[], int cont_ingr) {
    cout << "\n--- INSPECAO DE INGREDIENTE ---\n";
    int codigo;
    cout << "Insira o codigo para checagem: ";
    cin >> codigo;

    for (int i = 0; i < cont_ingr; ++i) {
        if (ingredientes[i].codigo == codigo) {
            double valor_total = ingredientes[i].quant_estoque * ingredientes[i].preco_unitario;
            cout << "\nIdentificador: " << ingredientes[i].codigo << "\n"
                 << "Descricao: " << ingredientes[i].descricao << "\n"
                 << "Volume Físico: " << ingredientes[i].quant_estoque << " unidades\n"
                 << "Margem de Alerta (Minima): " << ingredientes[i].estoque_minimo << "\n"
                 << "Margem Limite (Maxima): " << ingredientes[i].estoque_maximo << "\n"
                 << "Preco Unitario de Custo: R$ " << fixed << setprecision(2) << ingredientes[i].preco_unitario << "\n"
                 << "Capital imobilizado em estoque: R$ " << valor_total << "\n";
            return;
        }
    }
    cout << "Item inexistente.\n";
}

void relatorioEstoqueBaixo(const Ingrediente ingredientes[], int cont_ingr) {
    cout << "\n--- ALERTA: SUPRIMENTO ABAIXO DO NIVEL MINIMO ---\n";
    cout << left << setw(8) << "Cod" 
         << setw(20) << "Descricao" 
         << setw(10) << "Est.Atual" 
         << setw(10) << "Est.Max" 
         << setw(12) << "Necessidade" 
         << "Orcamento\n";
    cout << "----------------------------------------------------------------------\n";

    double total_geral_reposicao = 0.0;
    bool encontrou = false;

    for (int i = 0; i < cont_ingr; ++i) {
        if (ingredientes[i].quant_estoque < ingredientes[i].estoque_minimo) {
            encontrou = true;
            int a_comprar = ingredientes[i].estoque_maximo - ingredientes[i].quant_estoque;
            double valor_compra = a_comprar * ingredientes[i].preco_unitario;
            total_geral_reposicao += valor_compra;

            cout << left << setw(8) << ingredientes[i].codigo 
                 << setw(20) << ingredientes[i].descricao 
                 << setw(10) << ingredientes[i].quant_estoque 
                 << setw(10) << ingredientes[i].estoque_maximo 
                 << setw(12) << a_comprar 
                 << "R$ " << fixed << setprecision(2) << valor_compra << "\n";
        }
    }

    if (!encontrou) {
        cout << "Niveis operacionais estaveis. Nao ha necessidade de reposicao.\n";
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Fundo emergencial estimado para compras: R$ " << total_geral_reposicao << "\n";
}

void faturamentoTotal(const Pedido pedidos[], int cont_ped, const ItemPedido itens[], int cont_itens, 
                      const Produto produtos[], int cont_prod) {
    cout << "\n--- DEMONSTRATIVO FINANCEIRO DO PERIODO ---\n";
    
    double faturamento_geral = 0.0;

    for (int i = 0; i < cont_ped; ++i) {
        double total_pedido = 0.0;
        
        for (int j = 0; j < cont_itens; ++j) {
            if (itens[j].codigo_pedido == pedidos[i].codigo) {
                double preco_prod = 0.0;
                
                for (int k = 0; k < cont_prod; ++k) {
                    if (produtos[k].codigo == itens[j].codigo_produto) {
                        preco_prod = produtos[k].preco_unitario;
                        break;
                    }
                }
                total_pedido += (itens[j].quantidade * preco_prod);
            }
        }
        faturamento_geral += total_pedido;
    }

    cout << "Volume de transacoes processadas: " << cont_ped << "\n";
    cout << "Montante bruto arrecadado: R$ " << fixed << setprecision(2) << faturamento_geral << "\n";
}

void relatorioComissaoGarçons(const Pedido pedidos[], int cont_ped, const ItemPedido itens[], int cont_itens,
                              const Produto produtos[], int cont_prod, const Garcom garcons[], int cont_garc) {
    cout << "\n--- BALANCO DE PRODUCAO E COMISSAO DA EQUIPE ---\n";
    
    for (int g = 0; g < cont_garc; g++) {
        double total_vendas_garcom = 0.0;
        
        for (int p = 0; p < cont_ped; p++) {
            if (pedidos[p].codigo_garcom == garcons[g].codigo) {
                
                for (int i = 0; i < cont_itens; i++) {
                    if (itens[i].codigo_pedido == pedidos[p].codigo) {
                        double preco_prod = 0.0;
                        for (int pr = 0; pr < cont_prod; pr++) {
                            if (produtos[pr].codigo == itens[i].codigo_produto) {
                                preco_prod = produtos[pr].preco_unitario;
                                break;
                            }
                        }
                        total_vendas_garcom += (itens[i].quantidade * preco_prod);
                    }
                }
            }
        }
        double comissao = total_vendas_garcom * 0.10;
        cout << "Colaborador: " << left << setw(20) << garcons[g].nome 
             << " | Vendas: R$ " << setw(8) << total_vendas_garcom 
             << " | Servico (10%): R$ " << comissao << "\n";
    }
}

int main() {
    Categoria categorias[MAX];
    Produto produtos[MAX];
    Ingrediente ingredientes[MAX];
    Cliente clientes[MAX];
    Garcom garcons[MAX];
    Pedido pedidos[MAX];
    ItemPedido itens[MAX];
    ConsumoIngrediente consumos[MAX];

    int cont_cat = 0, cont_prod = 0, cont_ingr = 0, cont_cli = 0;
    int cont_garc = 0, cont_ped = 0, cont_itens = 0, cont_cons = 0;

    carregarDadosPadrao(categorias, cont_cat, produtos, cont_prod, ingredientes, cont_ingr, consumos, cont_cons);
    carregarArquivos(clientes, cont_cli, garcons, cont_garc, pedidos, cont_ped, itens, cont_itens);

    int opcao = 0;
    do {
        cout << "\n=========================================\n"
             << "         GERENCIAMENTO DE RESTAURANTE    \n"
             << "=========================================\n"
             << "1.  Exibir Categorias\n"
             << "2.  Exibir Menu de Produtos\n"
             << "3.  Exibir Balanco de Insumos\n"
             << "4.  Cadastrar Novo Cliente\n"
             << "5.  Cadastrar Novo Garcom\n"
             << "6.  Remover Item do Cardapio\n"
             << "7.  Abrir Atendimento (Novo Pedido)\n"
             << "8.  Entrada de Insumos (Estoque)\n"
             << "9.  Consultar Ficha de um Ingrediente\n"
             << "10. Relatorio: Alerta de Estoque Baixo\n"
             << "11. Relatorio: Faturamento Operacional\n"
             << "12. Relatorio: Comissoes de Servico\n"
             << "0.  Salvar Dados e Sair\n"
             << "Escolha uma acao: ";
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida.\n";
            continue;
        }

        switch (opcao) {
            case 1:  lerCategorias(categorias, cont_cat); break;
            case 2:  lerProdutos(produtos, cont_prod); break;
            case 3:  lerIngredientes(ingredientes, cont_ingr); break;
            case 4:  incluirCliente(clientes, cont_cli); break;
            case 5:  incluirGarcom(garcons, cont_garc); break;
            case 6:  excluirProduto(produtos, cont_prod); break;
            case 7:  registrarPedido(pedidos, cont_ped, clientes, cont_cli, garcons, cont_garc, 
                                     produtos, cont_prod, ingredientes, cont_ingr, consumos, cont_cons, itens, cont_itens); break;
            case 8:  atualizarEstoqueManual(ingredientes, cont_ingr); break;
            case 9:  consultarIngrediente(ingredientes, cont_ingr); break;
            case 10: relatorioEstoqueBaixo(ingredientes, cont_ingr); break;
            case 11: faturamentoTotal(pedidos, cont_ped, itens, cont_itens, produtos, cont_prod); break;
            case 12: relatorioComissaoGarçons(pedidos, cont_ped, itens, cont_itens, produtos, cont_prod, garcons, cont_garc); break;
            case 0:
                salvarArquivos(clientes, cont_cli, garcons, cont_garc, pedidos, cont_ped, itens, cont_itens);
                cout << "\nDados consolidados e gravados em disco. Encerrando.\n";
                break;
            default: cout << "Opcao inexistente.\n"; break;
        }
    } while (opcao != 0);

    return 0;
}
