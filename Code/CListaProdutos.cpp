#include <iostream>
#include "CListaProdutos.h"
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>

using namespace std;

unsigned int i = 1; //indice de produto
unsigned int j = 1; //indice do tipo de produto
unsigned int p = 1; //codigo de produto
unsigned int q = 1; //codigo de vendas

//=============================================================================
//======================= CListaProdutos ======================================

CListaProdutos::CListaProdutos(){ // Construtor por omissao
    cabeca=NULL;

}
//=============================================================================
CListaProdutos::~CListaProdutos(){ // Destrutor
    CNoLista *atual, *proximo;

    atual=cabeca;
    while(atual!=NULL){
        proximo=atual->proximo;
        delete atual;
        atual=proximo;
    }
}
//=============================================================================
void CListaProdutos::insereItem(void){
    CNoLista *novo=new CNoLista;
    CNoLista *atual;
    //    int h;
    novo->indice = i;
    novo->codigo = p;

    cout << "Introduza o nome do produto: " << endl;
    cin.ignore();
    getline(cin, novo->nome);
    cout << "Introduza a marca do produto: " << endl;
    getline(cin, novo->marca);
    cout << "Introduza o codigo do tipo do produto: " << endl;
    cin >> novo->codigoTipo;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->preco;
    }
    cin.ignore();
    //    while(codigoVerTipo(h)==false){     //verificar se existem tipos
    //        cout <<"Precisa de introduzir tipos que existam." << endl;
    //        cout << "Introduza o codigo do tipo do produto: " << endl;
    //        cin >> h;
    //        while(cin.fail()) {
    //            cout << "Introduza um caractere valido: " << endl;
    //            cin.clear();
    //            cin.ignore(256,'\n');
    //            cin >> novo->codigoTipo;
    //        }
    //        cin.ignore();
    //    }
    //    h = novo->codigoTipo;
    cout << "Introduza o PVP do produto: " << endl;
    cin >> novo->preco;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->preco;
    }
    cin.ignore();
    cout << "Introduza o Stock: " << endl;
    cin >> novo->stock;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->preco;
    }
    cin.ignore();
    cout<<"Introduza o Stock maximo do produto: " <<endl;
    cin>>novo->stockMax;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->preco;
    }
    cin.ignore();
    cout<<"Introduza o Stock minimo do produto: " <<endl;
    cin>>novo->stockMin;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->preco;
    }
    cin.ignore();
    i++;
    p++;
    novo->proximo=NULL;

    if(cabeca==NULL){
        cabeca=novo;
    }else{
        atual=cabeca;
        while(atual->proximo!=NULL)
            atual=atual->proximo;
        atual->proximo=novo;
    }
}
//=============================================================================
void CListaProdutos::escreveLista(void) const{

    if(cabeca==NULL){
        cout << "Lista Vazia..." << endl;
        return;}
    CNoLista *atual = cabeca;
    while(atual!=NULL){
        cout << "\nProduto " << atual->indice << ":" << endl;
        cout << "Codigo do Produto: " << atual->codigo << endl << "Nome: " << atual->nome << endl << "Marca: " << atual->marca << endl << "Codigo do tipo do produto: " << atual->codigoTipo << endl <<
                "Preco: " << atual->preco << " Euros " << endl << "Stock: " << atual->stock << endl << "Stock minimo: " << atual->stockMin << endl << "Stock maximo: " << atual->stockMax << endl;

        atual=atual->proximo;
    }
}
//=============================================================================
void CListaProdutos::apagaItem(int num){   //apagar um produto

    CNoLista *atual = cabeca;
    CNoLista *previous;

    if(cabeca==NULL) return;
    else{
        previous=NULL;
        while(atual!=NULL){
            if(atual->indice==num){
                if(previous==NULL)
                    cabeca=atual->proximo;
                else
                    previous->proximo=atual->proximo;
                delete(atual);
                return;
            }
            previous=atual;
            atual=atual->proximo;
        }
    }
}
//=============================================================================
void CListaProdutos::modificaPVP(int num){
    CNoLista *atual = cabeca;
    CNoLista *previous;
    if(cabeca == NULL) return;
    else{
        previous=NULL;
        while(atual != NULL){
            if(atual->indice==num){
                cout <<"Introduza o novo PVP: " << endl;
                cout <<"PVP: ";
                cin >> atual->preco;
                while(cin.fail()) {
                    cout << "Introduza um caractere valido: " << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> atual->preco;
                }
                cout << "Novo PVP guardado com sucesso: " << num << endl;
                return;
            }
            atual=atual->proximo;
        }
    }
}
//=============================================================================
bool CListaProdutos::codigoVer(int num) const{  //método auxiliar para verificação do código
    CNoLista *atual = cabeca;
    if(cabeca==NULL)
        return false;
    else{
        while(atual!=NULL){
            if(atual->codigo==num)
                return true;
            else{
                atual=atual->proximo;}
        }
        return false;
    }
}
//=============================================================================
bool CListaProdutos::codigoVerTipo(int num) const{  //método auxiliar para verificação do código do tipo
    CNoLista *atual = cabeca;
    if(cabeca==NULL)
        return false;
    else{
        while(atual!=NULL){
            if(atual->codigoTipo==num)
                return true;
            else{
                atual=atual->proximo;}
        }
        return false;
    }
}
//=============================================================================
double CListaProdutos::precoVender(void){
    CNoLista *atual=cabeca;

    int n;
    int l, m;  //codigo e tipo


    bool codigo2 = false;
    while(codigo2!=true){
        cout << "\nEscolha o codigo do tipo de produto que deseja: " << endl;
        cin >> m;
        while(cin.fail()) {
            cout << "Introduza um caractere valido: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m;
        }
        cin.ignore();
        codigo2=codigoVerTipo(m);
    }

    bool codigo1 = false;
    while(codigo1!=true){
        escreveLista(); //alterar para escreveListaTipo();
        cout << "\nEscolha o codigo do produto que deseja: " << endl;
        cin >> l;
        while(cin.fail()) {
            cout << "Introduza um caractere valido: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> l;
        }
        cin.ignore();
        codigo1=codigoVer(l);
    }

    int nItens;
    cout << "Introduza o numero de itens da venda: " << endl;
    cin >> nItens;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> nItens;
    }
    while(nItens > atual->stock){ cout << "O numero que introduziu ultrapassa o stock disponivel, reintroduza: " << endl;
        cin >> nItens;
        while(cin.fail()) {
            cout << "Introduza um caractere valido: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> nItens;
        }
    }
    while(atual!=NULL){
        if(atual->codigo==l){
            n=(nItens * atual->preco);
            atual->stock= atual->stock-nItens;
        }
        atual=atual->proximo;
    }

    return n;
}
//=============================================================================
void CListaProdutos::modificaStock(int item){
    CNoLista *atual=cabeca;
    CNoLista *anterior;

    if(cabeca==NULL)
        return;
    else{
        anterior=NULL;
        while(atual!=NULL){
            if(atual->indice == item){
                cout << "Niveis de Stock "<< endl;
                cout << "Stock atual de " << atual->nome << ": " << endl;
                cin >> atual->stock;
                cout << "Stock minimo: " << endl;
                cin >> atual->stockMin;
                cout << "Stock maximo: " << endl;
                cin >> atual->stockMax;
                while(1){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Preco invalido... " << endl;
                        cout << "Insira um valor valido: " << endl;
                        cin >> atual->preco;
                    }
                    if(!cin.fail())
                        break;
                }
                cout << "O stock do produto " << item << " foi alterado com sucesso! " << endl;
                return;
            }
            atual=atual->proximo;
        }
    }
}
//=============================================================================
void CListaProdutos::venda(CNoVenda *novo){
    CNoLista *atual=cabeca;
    int l;  //codigo
    bool codigo1 = false;

    while(codigo1!=true){
        cout << "codigo do produto que deseja vender: " << endl;
        cin >> l;
        while(cin.fail()) {
            cout << "Introduza um caractere valido: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> l;
        }
        cin.ignore();
        codigo1=codigoVer(l);
    }
    while(atual!=NULL){
        if(atual->codigo==l){
            novo->preco = atual->preco;
        }
        return;
    }
    atual=atual->proximo;
}
//=============================================================================
void CListaProdutos::stringcompare(string num){
    CNoLista *atual = cabeca;
    double pvp=((atual->preco)*(taxa/100))+(atual->preco);
    while(atual!=NULL){
        if(atual->nome.find(num)!=std::string::npos){
            cout << "\nProduto encontrado: " << endl;
            cout << "Produto " << atual->indice << ":" << endl;
            cout << "Codigo do Produto: " << atual->codigo << endl << "Nome: " << atual->nome << endl << "Marca: " << atual->marca << endl << "Codigo do tipo do produto: " << atual->codigoTipo << endl <<
                    "Preco: " << atual->preco << endl << "PVP: " << pvp << endl << "Stock: " << atual->stock << endl << "Stock minimo: " << atual->stockMin << endl << "Stock maximo: " << atual->stockMax << endl;
        }else
            cout <<"Nao existe nenhum produto correspondente a sua procura." << endl;
        atual=atual->proximo;
    }
}
//============================================================================

//=============================================================================
// =========================  CListaVendas ====================================

CListaVendas::CListaVendas(){ // Construtor por omissao
    cabeca=NULL;
}
//=============================================================================
CListaVendas::~CListaVendas(){ // Destrutor
    CNoVenda *atual, *proximo;

    atual=cabeca;
    while(atual!=NULL){
        proximo=atual->proximo;
        delete atual;
        atual=proximo;
    }
}
//=============================================================================
void CListaVendas::dataVenda(void) {
    CNoVenda *atual=cabeca;
    int dia1, dia2;
    int mes1, mes2;
    int ano1, ano2;
    long int datain, data1, data2;

    cout << " Insira o intervalo de datas que deseja apresentar " << endl;
    cout << "Data inicial (dia):";
    cin >> dia1;
    while (1) {
        if (cin.fail() || (dia1 <= 0 || dia1 >= 32)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nDia invalido, digite um dia valido." << endl;
            cin >> dia1;
            break;
        }
        if (!cin.fail())
            break;
    }
    cout << endl << "(mes):";
    cin >> mes1;
    while (1) {
        if (cin.fail() || (mes1 <= 0 || mes1 >= 13)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nMes invalido, digite um mes valido." << endl;
            cin >> mes1;
            break;
        }
        if (!cin.fail())
            break;
    }
    cout << endl << "(ano):";
    cin >> ano1;
    while (1) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nAno invalido, digite um ano valido." << endl;
            cin >> ano1;
            break;
        }
        if (!cin.fail())
            break;
    }
    cout << endl << "Data final (dia):" ;
    cin >> dia2;
    while (1) {
        if (cin.fail() || (dia2 <= 0 || dia2 >= 32)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nDia invalido, digite um dia valido." << endl;
            cin >> dia2;
            break;
        }
        if (!cin.fail())
            break;
    }
    cout << endl << "(mes):" ;
    cin >> mes2;
    while (1) {
        if (cin.fail() || (mes2 <= 0 || mes2 >= 13)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nMes invalido, digite um mes valido." << endl;
            cin >> mes2;
            break;
        }
        if (!cin.fail())
            break;
    }
    cout << endl << "(ano):" ;
    cin >> ano2;
    while (1) {
        if (cin.fail() || ano2 < ano1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nAno invalido, digite um ano valido." << endl;
            cin >> ano2;
            break;
        }
        if (!cin.fail())
            break;
    }
    cin.ignore();

    while(atual != NULL)
    {

        datain = (atual->ano * 10000) + (atual->mes * 100) + atual->dia;
        data1 = (ano1 * 10000) + (mes1 * 100) + dia1;
        data2 = (ano2 * 10000) + (mes2 * 100) + dia2;

        if (datain >= data1 && datain <= data2)
        {
            cout << "\nCodigo da Venda: " << atual->codigo << endl;
            cout<< "Data: " << atual->dia << "/" << atual->mes << "/" << atual->ano<< endl;
            cout<< "Preco: " << atual->preco << " Euros; " << endl;
            cout<< "Quantidade: " << atual->stock <<endl;

        }

        atual = atual->proximo;
    }

}
//=============================================================================
void CListaVendas::procuraVenda(int item) {
    CNoVenda *atual = cabeca;

    while (atual != NULL) {
        if (atual->codigo == item) {
            cout << "\nCodigo de venda: " << atual->codigo << endl;
            cout<< "Data: " << atual->dia << "/" << atual->mes << "/"<< atual->ano<< endl;
            cout<< "Preco: " << atual->preco << " Euros " << endl;
            cout<< "Quantidade: " << atual->stock << endl;
        }
        else
            cout<<"Nenhum produto encontrado"<<endl;
        atual = atual->proximo;
    }
}
//=============================================================================
void CListaVendas::copiaListaVenda(CNoVenda * novo1){
    CNoVenda *novo = new CNoVenda;
    CNoVenda *atual;
    novo->indice = q;
    novo->codigo = q;


    novo->preco = novo1->preco;
    cout << "Preco do produto: " << novo->preco << endl;
    cout << "Introduza a quantidade: " << endl;
    cin >> novo->stock;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->stock;
    }
    cin.ignore();
    cout << "Introduza data da venda no formato DD/MM/YYYY " << endl;
    cin >> novo->dia;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->dia;
    }
    cin >> novo->mes;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->mes;
    }
    cin >> novo->ano;
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->mes;
    }
    cin.ignore();
    cout << "Produto para venda foi inserido com sucesso! " << endl;
    q++;
    novo->proximo=NULL;
    if(cabeca==NULL){
        cabeca=novo;
    }else{
        atual=cabeca;
        while(atual->proximo!=NULL)
            atual=atual->proximo;
        atual->proximo=novo;
    }
}
//=============================================================================
void CListaVendas::escreveVenda(void) {
    CNoVenda *atual = cabeca;
    if (cabeca == NULL)
        cout << "Nenhuma venda encontrada!" << endl;
    else {
        while (atual != NULL) {
            cout <<"\nCodigo de venda: " << atual->codigo << endl;
            cout<< "Data: " << atual->dia << "/" << atual->mes << "/"<< atual->ano << endl;
            cout<< "Preco: " << atual->preco << " Euros" << endl;
            cout<< "Quantidade: "<< atual->stock << endl;
            atual = atual->proximo;
        }
    }
}
//=============================================================================


//============================================================================
//=========================== CTipoProdutos ==================================

CTipoProdutos::CTipoProdutos(){ // Construtor por omissao
    cabeca=NULL;

}
//=============================================================================
CTipoProdutos::~CTipoProdutos(){ //Destrutor
    CNoTipo *atual, *proximo;

    atual=cabeca;
    while(atual!=NULL){
        proximo=atual->proximo;
        delete atual;
        atual=proximo;
    }
}
//=============================================================================
void CTipoProdutos::insereTipo(void){
    CNoTipo *novo=new CNoTipo;
    CNoTipo *atual;
    novo->codigoTipo = j;
    cout << "Introduza o nome do tipo do produto: " << endl;
    cin.ignore();
    getline(cin, novo->nomeDoTipo);
    //    cout << "Introduza o codigo do tipo do produto: " << endl;
    //    cin >> novo->codigoTipo;

    //    while(cin.fail()) {
    //        cout << "Introduza um caractere valido: " << endl;
    //        cin.clear();
    //        cin.ignore(256,'\n');
    //        cin >> novo->codigoTipo;
    //    }
    //    cin.ignore();
    cout << "Introduza a taxa de IVA do tipo do produto: " << endl;
    cin >> novo->taxa;
    while(novo->taxa > 49 || novo->taxa <0){
        cout << "Introduza um IVA entre 0 e 50: ";
        cin >> novo->taxa;}
    while(cin.fail()) {
        cout << "Introduza um caractere valido: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> novo->taxa;
    }
    cin.ignore();
    j++;

    novo->proximo=NULL;

    if(cabeca==NULL){
        cabeca=novo;
    }else{
        atual=cabeca;
        while(atual->proximo!=NULL)
            atual=atual->proximo;
        atual->proximo=novo;
    }
}
//=============================================================================
void CTipoProdutos::modificaTaxa(int num){
    CNoTipo *atual = cabeca;
    CNoTipo *previous;
    if(cabeca == NULL) return;
    else{
        previous=NULL;
        while(atual != NULL){
            if(atual->codigoTipo==num){
                cout <<"Introduza a nova taxa de IVA: " << endl;
                cout <<"Novo IVA: ";
                cin >> atual->taxa;
                while(atual->taxa > 49 || atual->taxa <0){
                    cout << "Introduza um IVA entre 0 e 50: ";
                    cin >> atual->taxa;}
                while(cin.fail()) {
                    cout << "Introduza um caractere valido: " << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> atual->taxa;
                }
                cout << "\nNova taxa de IVA guardado com sucesso." << endl;
                return;
            }
            atual=atual->proximo;
        }
    }
}
//=============================================================================
void CTipoProdutos::apagaTipo(int num){     //apagar um produto

    CNoTipo *atual = cabeca;
    CNoTipo *previous;

    if(cabeca==NULL) return;
    else{
        previous=NULL;
        while(atual!=NULL){
            if(atual->codigoTipo==num){
                if(previous==NULL)
                    cabeca=atual->proximo;
                else
                    previous->proximo=atual->proximo;
                delete(atual);
                return;
            }
            previous=atual;
            atual=atual->proximo;
        }
    }
}
//=============================================================================
bool CTipoProdutos::verificaTipo(void){
    if(cabeca == NULL) return 1;
    else return 0;
}
//=============================================================================
bool CListaProdutos::verifica(void){
    if(cabeca == NULL) return 1;
    else return 0;
}
//=============================================================================
void CTipoProdutos::escreveTipo(void) const{

    CNoTipo *atual=cabeca;
    if(cabeca==NULL)
        cout << "Tipos registados: Lista vazia. " << endl;
    else{
        while(atual!=NULL)
        {
            cout << "\nCodigo do Tipo de Produto: "<< atual->codigoTipo << endl << "Nome: " << atual->nomeDoTipo << endl << "IVA: " << atual->taxa << "%" << endl;
            atual=atual->proximo;
        }
    }
}
//=============================================================================
bool CTipoProdutos::codigoVerTipo2(int num) const{  //método auxiliar para verificação do código do tipo
    CNoTipo *atual = cabeca;
    if(cabeca==NULL)
        return false;
    else{
        while(atual!=NULL){
            if(atual->codigoTipo==num)
                return true;
            else{
                atual=atual->proximo;}
        }
        return false;
    }
}
//=============================================================================
