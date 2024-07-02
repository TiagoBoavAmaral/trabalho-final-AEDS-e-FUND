# trabalho-final-AEDS-e-FUND

# Trabalho de Aeds - Hotel Descanso Garantido

* Gabriel Peçanha Diniz
* Tiago Boaventura Amaral
   
## Descrição

O Hotel Descanso Garantido é um hotel localizado no centro de Itacaré – BA, com um forte compromisso em proporcionar um excelente atendimento e fidelizar seus clientes. O hotel conta com uma equipe composta por recepcionistas, auxiliares de limpeza, garçons e um gerente. Até o momento, o hotel realizava o controle de estadias, clientes e funcionários através de planilhas do Excel e registros em cadernos, o que frequentemente resultava em problemas organizacionais, incluindo conflitos de reserva, onde um mesmo quarto era reservado para mais de um cliente. Por isso, foi desenvolvido um sistema em linguagem C para resolver esses problemas e melhorar a eficiência operacional.

### Menu

    ---------------------------------
         HOTEL DESCANSO GARANTIDO
    ---------------------------------
    1. Cadastrar Cliente
    2. Cadastrar Funcionario
    3. Cadastrar Estadia
    4. Cadastrar Quarto
    5. Mostrar estadia do Cliente
    6. Pesquisar Cliente
    7. Pesquiasar Funcionario
    8. Dar Baixa na Estadia
    9. Encerrar programa
    
    Digite a opcao desejada: 

## Bibliotecas Usadas

* **Stdio.h**: Este cabeçalho é a base para entrada e saída padrão em C, como printf e scanf. Usado para interagir com o usuário via console, exibindo resultados e capturando entradas.
* **Stdbool.h**: Este cabeçalho define os tipos booleanos em C, especificamente true e false, no projeto foi usado para encontrar em loops se alguma comparação ocorreu ou não, e no caso de não comparecer ele imprime uma mensagem relatando que não ocorreu.
* **String.h**: éEste cabeçalho define funções para manipulação de strings, como strlen, strcpy, strcat, strcmp. A única utilizada foi a strcmp que é usada para comparar duas strings e verem se elas são iguais.

## Funções utilizadas no projeto

* **void cadastrocliente()**: Cadastra novos clientes no sistema solicitando e armazenando nome, idade e endereço em variáveis globais Cliente clientes[] e int numClientes, incrementando o contador numClientes após cada cadastro, sem aceitar parâmetros.
* **void cadastrofuncionario()**: cadastra novos funcionários no sistema solicitando e armazenando nome, idade e cargo em variáveis globais Funcionario funcionarios[] e int numFuncionarios, incrementando o contador numFuncionarios após cada cadastro, sem aceitar parâmetros.
* **int data_maior(datas d1, datas d2)**:A função data_maior compara duas datas (d1 e d2) e retorna um valor indicando se d2 é maior, menor ou igual a d1. Esta função é útil para garantir que a data de saída não seja menor que a data de entrada. E tem como parâmetro a struct de datas (entrada e saida).
* **void cadastrarestadia()**: registra a estadia de um cliente solicitando as datas de entrada e saída, verificando se a data de saída não é anterior à data de entrada utilizando a função data_maior(datas d1, datas d2), que compara as datas e além disso verifica se existe quarto com a quantidade de hóspedes e status desocupado. A função opera sobre as variáveis globais Estadia estadias[] e int numEstadias, incrementando numEstadias após um cadastro válido, sem aceitar parâmetros.
* **void cadastrarquarto()**:  cadastra um novo quarto no sistema, atribuindo automaticamente o número do quarto e solicitando ao usuário a quantidade de hóspedes e o valor da diária, armazenando essas informações nas variáveis globais Quarto qua[] e int total_quarto, definindo o status inicial do quarto como 0 (disponível) e incrementando total_quarto após cada cadastro, sem aceitar parâmetros.
* **void mostrarestadia_de_cliente()**:  exibe todas as estadias de um cliente específico solicitando o código do cliente e buscando nas variáveis globais Estadia est[] e int total_estadia, verificando se há estadias cadastradas, e se encontradas, exibe informações detalhadas de cada estadia como código da estadia, código do cliente, número do quarto, datas de entrada e saída, quantidade de diárias e valor total, ajustando a variável booleana achou para true quando uma estadia é encontrada, sem aceitar parâmetros.
* **void pesquisar_cliente()**: permite pesquisar informações de clientes por nome ou código, solicitando ao usuário que escolha uma opção de pesquisa, lê o nome ou código fornecido, e percorre o array global Cliente cli[] para encontrar e exibir os detalhes correspondentes, utilizando a variável global int total_cliente para controlar o número de clientes cadastrados; se nenhum cliente for encontrado, uma mensagem apropriada é exibida, e a função não aceita parâmetros.
* **void pesquisar_funcionario()**: permite buscar informações de um funcionário pelo nome ou código, exibindo os dados correspondentes (nome, telefone, cargo, salário) se encontrado, utilizando variáveis globais Funcionario fun[] e int total_funcionario; a função exibe um menu para escolher a opção de busca, solicita a entrada do usuário, percorre o array de funcionários para encontrar os dados e informa se nenhum funcionário foi encontrado, sem aceitar parâmetros.
* **void dar_baixa_na_estadia()**:  finaliza uma estadia específica do cliente. Ela solicita ao usuário o código da estadia, verifica sua existência no array de estadias, calcula o valor total da estadia, exibe detalhes da estadia e do cliente, marca o quarto correspondente como desocupado e remove a estadia do array. Se a estadia for encontrada e processada com sucesso, imprime uma mensagem de confirmação; caso contrário, informa que a estadia não foi encontrada.
* **void salvar_cliente()**: abre o arquivo "clientes.txt" para escrita, armazena o número total de clientes no início do arquivo e, em seguida, salva as informações de cada cliente (código, nome, endereço e telefone) em formato CSV. Por fim, fecha o arquivo.
* **void ler_cliente()**:  abre o arquivo "clientes.txt" para leitura, e lê todas as informações já salvas, sendo iniciada lendo a quantidade total de clientes e depois a informação de cada cliente.
* **void salvar_funcionario()**: abre o arquivo "funcionários.txt" para escrita, armazena o número total de funcionários no início do arquivo e, em seguida, salva as informações de cada funcionário (código, nome, telefone, cargo, salario) em formato CSV. Por fim, fecha o arquivo.
* **void ler_funcionario()**: abre o arquivo "funcionarios.txt" para leitura, e lê todas as informações já salvas, sendo iniciada lendo a quantidade total de funcionarios e depois a informação de cada funcionario.
* **void salvar_estadia()**: abre o arquivo "estadias.txt" para escrita, salva o total de estadia e depois da uma quebra de linha salvando a informação de cada estadias, sendo codigo, quantidade de diarias, codigo cliente, numero do quarto, data de entrada, data de saido e valor total.
* **void ler_estadia()**: abre o arquivo "estadias.txt" para leitura, e lê todas as informações já salvas, sendo iniciada lendo a quantidade total de estadias e depois a informação de cada estadia.
* **void salvar_quartos()**: abre o arquivo "quartos.txt" para escrita, salva o total de quartos e depois da uma quebra de linha salvando a informação de cada quarto, sendo numero do quarto, quantidade de hospedes, preço e status.
* **void ler_quartos()**: abre o arquivo "quartos.txt" para leitura, e lê todas as informações já salvas, sendo iniciada lendo a quantidade total de quartos e depois a informação de cada quarto.
* **void menu()**: uma função que imprime o menu e usa a variavél global opção do menu que é usada na main.
* **main()**: e a função main onde possui o menu, o chamado de cada função.

* Video Utilizando o Software: https://drive.google.com/file/d/1uIPkd1up3Ui3VGH1_ZcNwgQK8u-DOyzj/view
