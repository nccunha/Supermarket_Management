//Estruturas de Dados e Algoritmos
//Nuno Gonçalo da Costa Cunha 2018285610
//Miguel António Gonçalves Neves 2018278969
//08/05/2020
//=============================================================================
#include <iostream>
#include "CListaProdutos.h"
#include "CListaProdutos.cpp"
#include <limits>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;


int main(){

    CTipoProdutos tipos;
    CListaProdutos lista;

    char menu, produto, venda, inventario, tipo, faturacao;
    cout << "=== Gestao de Supermercado = 08/05/2020  ===" << endl;
    cout << endl;
    cout << "===== Nuno Cunha ====== Miguel Neves =======" << endl;

    while (menu!='8'){
        cout << "\n";
        cout << "================= Menu ===================" << endl;
        cout << "=     1 - Tipos de Produtos              =" << endl;
        cout << "=     2 - Produtos                       =" << endl;
        cout << "=     3 - Venda                          =" << endl;
        cout << "=     4 - Fornecedores e produtos        =\n=\t  "
                         "disponiveis para compra        =" << endl;
        cout << "=     5 - Reposicao automatica de stocks =" << endl;
        cout << "=     6 - Rececao de encomenda           =" << endl;
        cout << "=     7 - Inventario                     =" << endl;
        cout << "=     8 - Sair                           =" << endl;
        cout << "=     ";
        cin >> menu;
        while(cin.fail()){
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Introduza um caractere valido: " << endl;
                cin >> menu;
            }
            if(!cin.fail())
                break;
        }

        switch (menu) { 
        case '9':   //Sair
            break;

        case '1':
            cout << "\n=========== Tipos de Produtos ============" << endl;
            cout << "=    1 - Inserir tipo de produto         =" << endl;
            cout << "=    2 - Modificar tipo de produto       =" << endl;
            cout << "=    3 - Apagar tipos de produto         =" << endl;
            cout << "=    4 - Voltar para o Menu              =" << endl;
            cout << "=    ";
            cin >> tipo;
            while(cin.fail()){
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Introduza um caractere valido: " << endl;
                    cin >> tipo;
                }
                if(!cin.fail())
                    break;
            }
            switch (tipo) {
            case '1':
                tipos.insereTipo();
                tipos.escreveTipo();
                break;

            case '2':
                int j;
                if(tipos.verificaTipo()){    //verificar se existem tipos
                    cout <<"Precisa de introduzir tipos de produtos primeiro." << endl;}
                else{
                    tipos.escreveTipo();
                    cout << "Insira o codigo do tipo que deseja alterar: " << endl;
                    cin >> j;
                    tipos.modificaTaxa(j);
                    tipos.escreveTipo();}
                break;
            case '3':
                int l;
                if(tipos.verificaTipo()){    //verificar se existem tipos
                    cout <<"Precisa de introduzir tipos de produtos primeiro." << endl;}
                else{
                    tipos.escreveTipo();
                    cout << "Insira o codigo do tipo que deseja apagar: " << endl;
                    cin >> l;
                    tipos.apagaTipo(l);
                    tipos.escreveTipo();}
                break;
            case '4':
                break;
            }
            break; //case 1
        case '2':
            cout << "\n================= Produtos ===============" << endl;
            cout << "=    1 - Inserir produto                 =" << endl;
            cout << "=    2 - Modificar PVP de produto        =" << endl;
            cout << "=    3 - Modificar niveis de stock       =" << endl;
            cout << "=    4 - Apagar produto                  =" << endl;
            cout << "=    5 - Voltar para o Menu              =" << endl;
            cout << "=    ";
            cin >> produto;
            while(cin.fail()){
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Introduza um caractere valido: " << endl;
                    cin >> produto;
                }
                if(!cin.fail())
                    break;
            }

            switch (produto) {
            case '1':
                if(tipos.verificaTipo()){    //verificar se existem tipos
                    cout <<"Precisa de introduzir tipos de produtos primeiro." << endl;}
                else{
                    lista.insereItem();
                    lista.escreveLista();
                }

                break;
             case '2':
                int k;
                if(lista.verifica())  cout << "Nenhum produto inserido." << endl;
                else{
                    lista.escreveLista();
                    cout << "Insira o indice do produto que deseja alterar: " << endl;
                    cin >> k;
                    while(cin.fail()) {
                        cout << "Introduza um caractere valido: " << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> k;
                    }
                    lista.modificaPVP(k);
                    lista.escreveLista();
                }
                break;

            case '3':
                int j;
                if(lista.verifica())  cout << "Nenhum produto inserido." << endl;
                else{
                    lista.escreveLista();
                    cout << "Insira o indice do produto que deseja alterar: " << endl;
                    cin >> j;
                    while(cin.fail()) {
                        cout << "Introduza um caractere valido: " << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> j;
                    }
                    lista.modificaStock(j);
                    lista.escreveLista();}
                break;

            case '4':
                int b;
                if(lista.verifica())  cout << "Nenhum produto inserido." << endl;
                else{
                    lista.escreveLista();

                    cout << "Insira o indice do produto que deseja apagar: " << endl;
                    cin >> b;
                    while(cin.fail()) {
                        cout << "Introduza um caractere valido: " << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> b;
                    }

                    lista.apagaItem(b);
                    lista.escreveLista();}
                break;

            case '5':
                break;
            }
            break; //break do switch(menu): case "2"
            case '3':
            cout << "\n================ Vendas ==================" << endl;
            cout << "=     1 - Realizar venda                 =" << endl;
            cout << "=     2 - Voltar para o Menu             =" << endl;
            cout << "=     ";
            cin >> venda;
            while(cin.fail()){
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Introduza um caractere valido: " << endl;
                    cin >> venda;
                }
                if(!cin.fail())
                    break;
            }

            switch(venda){
            case '2':
                break;
            case '1':{
                if(tipos.verificaTipo()){    //verificar se existem tipos
                    cout <<"Precisa de introduzir tipos de produtos primeiro." << endl;}
                else{
                    if(lista.verifica())  cout << "Nenhum produto inserido." << endl; //verificar se existem produtos
                    else{
                        tipos.escreveTipo();
                        double h = lista.precoVender();
                        cout << "\nValor final a pagar: " << h << endl;}}
                break;
            }
            


            }break; //break do switch(menu): case "3"

        case '7':{
            cout << "\n=============== Inventario ===============" << endl;
            cout << "=     1 - Listar os produtos             =" << endl;
            cout << "=     2 - Pesquisa Parcial               =" << endl;
            cout << "=     3 - Voltar para o Menu             =" << endl;
            cout << "=     ";
            cin >> inventario;
            while(cin.fail()){
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Introduza um caractere valido: " << endl;
                    cin >> inventario;
                }
                if(!cin.fail())
                    break;
            }
            switch(inventario){
            case '3': break;

            case '1':
                lista.escreveLista();
                break;

            case '2':
                string str;
                cout << "Pesquise pelo nome do produto desejado: " << endl;
                cin >> str;
                lista.stringcompare(str);
                break;
            } break; //break do switch(menu): case "7"
        }
    } break; //break do switch(menu): case "8"
           
    }

}







