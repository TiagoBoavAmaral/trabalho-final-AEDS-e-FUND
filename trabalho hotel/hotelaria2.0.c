#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char telefone[15];
} cliente;

typedef struct
{
    int codigo;
    char nome[50];
    char telefone[15];
    char cargo[30];
    float salario;
} funcionario;

typedef struct
{
    int numero;
    int qtd_hospedes;
    float preco;
    bool status;
} quarto;

typedef struct
{
    int ano;
    int mes;
    int dia;
} datas;

typedef struct
{
    int codigo;
    datas data_entrada;
    datas data_saida;
    int qtd_diarias;
    int codigo_cliente;
    int numero_quarto;
    float valorTotal;
} estadia;

int total_cliente = 0;
int total_funcionario = 0;
int total_estadia = 0;
int total_quarto = 0;
int opcao_do_menu = 0;

cliente cli[100];
funcionario fun[100];
estadia est[100];
quarto qua[100];
datas dat;

void cadastrocliente()
{
    printf("\n\tSEJA BEM-VINDO - CADASTRE-SE !!\n\n");
    cli[total_cliente].codigo = total_cliente + 1;
    printf("Nome: ");
    scanf(" %[^\n]", cli[total_cliente].nome);
    printf("Endereco: ");
    scanf(" %[^\n]", cli[total_cliente].endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", cli[total_cliente].telefone);
    total_cliente++;
}

void cadastrofuncionario()
{
    printf("\n\tSEJA BEM-VINDO - CADASTRE-SE !!\n\n");
    fun[total_funcionario].codigo = total_funcionario + 1;

    printf("Nome: ");
    scanf(" %[^\n]", fun[total_funcionario].nome);
    printf("Telefone: ");
    scanf(" %[^\n]", fun[total_funcionario].telefone);
    printf("Cargo: ");
    scanf(" %[^\n]", fun[total_funcionario].cargo);
    printf("Salario: ");
    scanf("%f", &fun[total_funcionario].salario);
    total_funcionario++;
}

int data_maior(datas d1, datas d2)
{
    if (d2.ano > d1.ano)
        return 1;
    if (d2.ano < d1.ano)
        return -1;
    if (d2.mes > d1.mes)
        return 1;
    if (d2.mes < d1.mes)
        return -1;
    if (d2.dia > d1.dia)
        return 1;
    if (d2.dia < d1.dia)
        return -1;
    return 0;
}

void cadastrarestadia()
{
    int verificar = 2, qnt_hospe, achou = 0;
    datas dat;

    if (total_cliente < 1 || total_quarto < 1)
    {
        printf("Nao foi possivel cadastrar a estadia por falta de quartos ou "
               "pessoas.\n\n");
        return;
    }
    else
    {
        printf("\n\tCADASTRE SUA ESTADIA !!\n\n");
        est[total_estadia].codigo = total_estadia + 1;

        do
        {
            printf("Codigo Cliente: ");
            scanf("%d", &est[total_estadia].codigo_cliente);
            verificar = 2;

            for (int i = 0; i < total_cliente; i++)
            {
                if (est[total_estadia].codigo_cliente == cli[i].codigo)
                {
                    verificar = 1;
                    break;
                }
            }
        }
        while (verificar == 2);

        printf("Quantidade de hospedes: ");
        scanf("%d", &qnt_hospe);

        do
        {
            printf("Data Entrada (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &dat.dia, &dat.mes, &dat.ano);
        }
        while (dat.dia > 31 || dat.dia < 1 || dat.ano < 2024 || dat.mes > 12 ||
                dat.mes < 1);

        est[total_estadia].data_entrada = dat;

        do
        {
            printf("Data Saida (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &dat.dia, &dat.mes, &dat.ano);
        }
        while (dat.dia > 31 || dat.dia < 1 || dat.ano < 2024 || dat.mes > 12 ||
                dat.mes < 1 ||
                data_maior(est[total_estadia].data_entrada, dat) != 1);

        est[total_estadia].data_saida = dat;

        est[total_estadia].qtd_diarias = ((est[total_estadia].data_saida.ano -
                                           est[total_estadia].data_entrada.ano) *
                                          365) +
                                         ((est[total_estadia].data_saida.mes -
                                           est[total_estadia].data_entrada.mes) *
                                          30) +
                                         (est[total_estadia].data_saida.dia -
                                          est[total_estadia].data_entrada.dia);

        for (int i = 0; i < total_quarto; i++)
        {
            if (qua[i].status == 0 && qua[i].qtd_hospedes >= qnt_hospe)
            {
                qua[i].status = 1;
                est[total_estadia].numero_quarto = qua[i].numero;
                est[total_estadia].valorTotal =
                    est[total_estadia].qtd_diarias * qua[i].preco;
                total_estadia = total_estadia + 1;
                achou = 1;
                break;
            }
        }

        if (achou == 0)
        {
            printf("\nNenhuma informacao encontrada com os dados fornecidos.\n\n");
        }
        else
        {
            printf("\nEstadia cadastrada com sucesso.\n");
        }
    }
}

void cadastrarquarto()
{
    qua[total_quarto].numero = total_quarto + 1;

    printf("Digite o numero de hospedes: ");
    scanf("%d", &qua[total_quarto].qtd_hospedes);

    printf("Digite o valor da diaria: ");
    scanf("%f", &qua[total_quarto].preco);

    qua[total_quarto].status = 0;
    printf("Quarto cadastrado com sucesso !!\n\n");
    total_quarto++;
}

void mostrarestadia_de_cliente()
{
    int cod_cli;
    bool achou = false;

    if (total_estadia < 0)
    {
        printf("Nao possui nenhuma estadia cadastrada.\n\n");
    }
    else
    {
        printf("Digite o codigo do cliente: ");
        scanf("%d", &cod_cli);

        for (int i = 0; i < total_estadia; i++)
        {
            if (cod_cli == est[i].codigo_cliente)
            {
                achou = true;
                printf("Estadia(s) encontrada(s)\n\n");
                printf("Codigo da estadia: %d\n", est[i].codigo);
                printf("Codigo do cliente: %d\n", est[i].codigo_cliente);
                printf("Numero do quarto: %d\n", est[i].numero_quarto);
                printf("Data de entrada: %02d/%02d/%d\n", est[i].data_entrada.dia,
                       est[i].data_entrada.mes, est[i].data_entrada.ano);
                printf("Data de saida: %02d/%02d/%d\n", est[i].data_saida.dia,
                       est[i].data_saida.mes, est[i].data_saida.ano);
                printf("Quantidade de diarias: %d\n", est[i].qtd_diarias);
                printf("Valor total: %.2f\n\n", est[i].valorTotal);
            }
        }
        if (achou == false)
        {
            printf("Nao foram encontradas estadias com o codigo digitado.\n\n");
        }
    }
}

void pesquisar_cliente()
{
    int opc, cod;
    char string[50];
    bool achou = false;

    printf("\tMENU DE PESQUISA\n\n");
    do
    {
        printf("Deseja pesquisar:\n\n");
        printf("1. Nome\n2. Codigo\n\nDigite a opcao desejada: ");
        scanf("%d", &opc);
    }
    while (opc < 1 || opc > 2);

    if (opc == 1)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]", string);

        for (int i = 0; i < total_cliente; i++)
        {
            if (strcmp(string, cli[i].nome) == 0)
            {
                printf("Nome: %s\n", cli[i].nome);
                printf("Endereco: %s\n", cli[i].endereco);
                printf("Telefone: %s\n", cli[i].telefone);
                achou = true;
            }
        }
    }
    else
    {
        printf("Digite o codigo: ");
        scanf("%d", &cod);

        for (int i = 0; i < total_cliente; i++)
        {
            if (cod == cli[i].codigo)
            {
                printf("Nome: %s\n", cli[i].nome);
                printf("Endereco: %s\n", cli[i].endereco);
                printf("Telefone: %s\n", cli[i].telefone);
                achou = true;
            }
        }
    }

    if (achou == false)
    {
        printf("Nenhuma informacao encontrada com a fornecida.\n\n");
    }
}

void pesquisar_funcionario()
{
    int opc, cod;
    char string[50];
    bool achou = false;

    printf("\tMENU DE PESQUISA\n\n");
    do
    {
        printf("Deseja pesquisar:\n\n");
        printf("1. Nome\n2. Codigo\n\nDigite a opcao desejada: ");
        scanf("%d", &opc);
    }
    while (opc < 1 || opc > 2);

    if (opc == 1)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]", string);

        for (int i = 0; i < total_funcionario; i++)
        {
            if (strcmp(string, fun[i].nome) == 0)
            {
                printf("Nome: %s\n", fun[i].nome);
                printf("Telefone: %s\n", fun[i].telefone);
                printf("Cargo: %s\n", fun[i].cargo);
                printf("Salario: %.2f\n", fun[i].salario);
                achou = true;
            }
        }
    }
    else
    {
        printf("Digite o codigo: ");
        scanf("%d", &cod);

        for (int i = 0; i < total_funcionario; i++)
        {
            if (cod == fun[i].codigo)
            {
                printf("Nome: %s\n", fun[i].nome);
                printf("Telefone: %s\n", fun[i].telefone);
                printf("Cargo: %s\n", fun[i].cargo);
                printf("Salario: %.2f\n", fun[i].salario);
                achou = true;
            }
        }
    }

    if (achou == false)
    {
        printf("Nenhuma informacao encontrada com a fornecida.\n\n");
    }
}

void dar_baixa_na_estadia()
{
    int cod_est;
    bool achou = false;

    printf("\nDigite o codigo da estadia a dar baixa: ");
    scanf("%d", &cod_est);

    for (int i = 0; i < total_estadia; i++)
    {
        if (cod_est == est[i].codigo)
        {
            achou = true;
            int cod_qua = est[i].numero_quarto;
            float total = est[i].qtd_diarias * qua[cod_qua - 1].preco;

            printf("\nCodigo da estadia: %d\n", est[i].codigo);
            printf("Codigo do cliente: %d\n", est[i].codigo_cliente);
            printf("Nome do cliente: %s\n", cli[est[i].codigo_cliente - 1].nome);
            printf("Numero do quarto: %d\n", est[i].numero_quarto);
            printf("Quantidade de diarias: %d\n", est[i].qtd_diarias);
            printf("Valor total: R$ %.2f\n", total);
            printf("Data de entrada: %02d/%02d/%02d\n", est[i].data_entrada.dia,
                   est[i].data_entrada.mes, est[i].data_entrada.ano);
            printf("Data de saida: %02d/%02d/%02d\n", est[i].data_saida.dia,
                   est[i].data_saida.mes, est[i].data_saida.ano);

            // Atualizando o status do quarto para desocupado
            for (int j = 0; j < total_quarto; j++)
            {
                if (cod_qua == qua[j].numero)
                {
                    qua[j].status = 0;
                    break;
                }
            }

            // Remover estadia do array
            for (int m = i; m < total_estadia - 1; m++)
            {
                est[m] = est[m + 1];
            }
            total_estadia--;
            printf("Estadia dada baixa com sucesso.\n");
            break;
        }
    }
    if (achou == false)
        printf("\nNenhuma estadia encontrada com o codigo fornecido.\n");
}

void salvar_cliente()
{
    FILE *arq = fopen("clientes.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fprintf(arq, "%d\n", total_cliente);

    for (int i = 0; i < total_cliente; i++)
    {
        fprintf(arq, "%d,", cli[i].codigo);
        fprintf(arq, "%s,", cli[i].nome);
        fprintf(arq, "%s,", cli[i].endereco);
        fprintf(arq, "%s\n", cli[i].telefone);
    }
    fclose(arq);
}

void ler_cliente()
{
    FILE *arq = fopen("clientes.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fscanf(arq, "%d\n", &total_cliente);

    for (int i = 0; i < total_cliente; i++)
    {
        fscanf(arq, "%d,", &cli[i].codigo);
        fscanf(arq, " %49[^,],", cli[i].nome);
        fscanf(arq, " %49[^,],", cli[i].endereco);
        fscanf(arq, " %14[^\n]\n", cli[i].telefone);
    }
    fclose(arq);
}

void salvar_funcionario()
{
    FILE *arq = fopen("funcionarios.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionarios salvar.\n");
        return;
    }

    fprintf(arq, "%d\n", total_funcionario);

    for (int i = 0; i < total_funcionario; i++)
    {
        fprintf(arq, "%d,", fun[i].codigo);
        fprintf(arq, "%s,", fun[i].nome);
        fprintf(arq, "%s,", fun[i].telefone);
        fprintf(arq, "%s,", fun[i].cargo);
        fprintf(arq, "%.2f\n", fun[i].salario);
    }
    fclose(arq);
}

void ler_funcionario()
{
    FILE *arq = fopen("funcionarios.txt", "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n");
        return;
    }

    fscanf(arq, "%d\n", &total_funcionario);

    for (int i = 0; i < total_funcionario; i++)
    {
        fscanf(arq, "%d,", &fun[i].codigo);
        fscanf(arq, " %49[^,],", fun[i].nome);
        fscanf(arq, " %14[^,],", fun[i].telefone);
        fscanf(arq, " %29[^,],", fun[i].cargo);
        fscanf(arq, "%f\n", &fun[i].salario);
    }
    fclose(arq);
}

void salvar_estadia()
{
    FILE *arq = fopen("estadias.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de estadia.\n");
        return;
    }

    fprintf(arq, "%d\n", total_estadia);

    for (int i = 0; i < total_estadia; i++)
    {
        fprintf(arq, "%d,", est[i].codigo);
        fprintf(arq, "%d,", est[i].qtd_diarias);
        fprintf(arq, "%d,", est[i].codigo_cliente);
        fprintf(arq, "%d,", est[i].numero_quarto);
        fprintf(arq, "%02d/%02d/%02d,", est[i].data_entrada.dia,
                est[i].data_entrada.mes, est[i].data_entrada.ano);
        fprintf(arq, "%02d/%02d/%02d,", est[i].data_saida.dia,
                est[i].data_saida.mes, est[i].data_saida.ano);
        fprintf(arq, "%.2f\n", est[i].valorTotal);
    }
    fclose(arq);
}

void ler_estadia()
{
    FILE *arq = fopen("estadias.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de estadia.\n");
        return;
    }

    fscanf(arq, "%d\n", &total_estadia);

    for (int i = 0; i < total_estadia; i++)
    {
        fscanf(arq, "%d,", &est[i].codigo);
        fscanf(arq, "%d,", &est[i].qtd_diarias);
        fscanf(arq, "%d,", &est[i].codigo_cliente);
        fscanf(arq, "%d,", &est[i].numero_quarto);
        fscanf(arq, "%d/%d/%d,", &est[i].data_entrada.dia, &est[i].data_entrada.mes,
               &est[i].data_entrada.ano);
        fscanf(arq, "%d/%d/%d,", &est[i].data_saida.dia, &est[i].data_saida.mes,
               &est[i].data_saida.ano);
        fscanf(arq, "%f\n", &est[i].valorTotal);
    }
    fclose(arq);
}

void salvar_quartos()
{
    FILE *arq = fopen("quartos.txt", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    fprintf(arq, "%d\n", total_quarto);

    for (int i = 0; i < total_quarto; i++)
    {
        fprintf(arq, "%d,", qua[i].numero);
        fprintf(arq, "%d,", qua[i].qtd_hospedes);
        fprintf(arq, "%.2f,", qua[i].preco);
        if (qua[i].status == 0)
        {
            fprintf(arq, "desocupado\n");
        }
        else
        {
            fprintf(arq, "ocupado\n");
        }
    }
    fclose(arq);
}

void ler_quartos()
{
    FILE *arq = fopen("quartos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de quartos.\n");
        return;
    }

    fscanf(arq, "%d\n", &total_quarto);

    char ver_ocupacao[20];

    for (int i = 0; i < total_quarto; i++)
    {
        fscanf(arq, "%d,", &qua[i].numero);
        fscanf(arq, "%d,", &qua[i].qtd_hospedes);
        fscanf(arq, "%f,", &qua[i].preco);
        fscanf(arq, " %19[^\n]", ver_ocupacao);
        if (strcmp(ver_ocupacao, "ocupado") == 0)
        {
            qua[i].status = 1;
        }
        else
        {
            qua[i].status = 0;
        }
    }
    fclose(arq);
}

void menu()
{
    printf("\n\n---------------------------\n");
    printf("HOTEL DESCANSO GARANTIDO\n");
    printf("---------------------------\n\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Funcionario\n");
    printf("3. Cadastrar Estadia\n");
    printf("4. Cadastrar Quarto\n");
    printf("5. Mostrar estadia do Cliente\n");
    printf("6. Pesquisar Cliente\n");
    printf("7. Pesquiasar Funcionario\n");
    printf("8. Dar Baixa na Estadia\n");
    printf("9. Encerrar programa\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao_do_menu);
}

int main()
{
    ler_cliente();
    ler_funcionario();
    ler_estadia();
    ler_quartos();

    while (opcao_do_menu != 9)
    {
        menu();
        switch (opcao_do_menu)
        {
        case 1:
            cadastrocliente();
            salvar_cliente();
            break;
        case 2:
            cadastrofuncionario();
            salvar_funcionario();
            break;
        case 3:
            cadastrarestadia();
            salvar_estadia();
            salvar_quartos();
            salvar_cliente();
            break;
        case 4:
            cadastrarquarto();
            salvar_quartos();
            break;
        case 5:
            mostrarestadia_de_cliente();
            break;
        case 6:
            pesquisar_cliente();
            break;
        case 7:
            pesquisar_funcionario();
            break;
        case 8:
            dar_baixa_na_estadia();
            salvar_estadia();
            salvar_quartos();
            break;
        case 9:
            printf("Programa encerrado com sucesso.");
            return 0;
            break;
        default:
            printf("Opcao invalida, digite novamente.\n\n");
            break;
        }
    }
}
