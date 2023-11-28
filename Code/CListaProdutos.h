#include <string>
#ifndef CListaProdutos_h
#define CListaProdutos_h
#ifndef CListaVendas_h
#define CListaVendas_h
using namespace std;
//=============================================================================

//=============================================================================
// ========================= CTipoProdutos ====================================

class CNoTipo{
public:
    int dados;
    CNoTipo *proximo;
    int indice;
    string nomeDoTipo;
    int taxa;
    int codigoTipo;
    friend class CListaProdutos;
};

class CTipoProdutos{
    CNoTipo *cabeca;
public:
    CTipoProdutos(void);
    ~CTipoProdutos(void);
    //CTipoProdutos(char * Str);

    void insereTipo(void);
    void modificaTaxa(int);
    void apagaTipo(int);
    bool verificaTipo(void);
    void escreveTipo(void) const;
    bool codigoVerTipo2(int num) const;
    friend class CListaProdutos;
};

//=============================================================================
// ========================= CListaVendas =====================================
class CNoVenda: public CNoTipo{
public:
    int dados;
    CNoVenda *proximo;

    void venda(CNoVenda *novo);


    int codigo;
    string nome;
    string marca;
    string tipo;
    int euros;
    int centimos;
    int indice;

    double preco;
    int stock;

    int dia;
    int mes;
    int ano;

    int hora;

}; // fim de class CNoVenda


//=============================================================================
class CListaVendas: public CNoTipo{
    CNoVenda *cabeca;
public:
    CListaVendas(void);
    ~CListaVendas(void);
    CListaVendas(char * Str);
    void escreveVenda(void);
    int indiceVenda;
    void copiaListaVenda(CNoVenda *);
    void dataVenda(void);
    void procuraVenda(int item);




}; // fim de class CListaVendas
// ========================= CListaProdutos ===================================

class CNoLista : public CNoTipo
{
public:
    int dados;
    CNoLista *proximo;

    int codigo;
    string nome;
    string marca;
    double preco;
    int indice;
    int nItens;

    int stock;
    int stockMin;
    int stockMax;

    double pvp;


}; // fim de class CNoLista
//=============================================================================
class CListaProdutos: public CNoTipo{
    CNoLista *cabeca;
public:
    CListaProdutos(void);
    ~CListaProdutos(void);
    CListaProdutos(char * Str);
    void insereItem(void);
    void apagaItem(int);
    bool procuraIndice(int) const;
    void escreveLista(void) const;
    bool existeNumero(int numero);
    void modificaPVP(int);
    void venda(CNoVenda *);
    bool codigoVer(int) const;
    bool codigoVerTipo(int num) const;
    double precoVender(void);
    void stringcompare(string );
    void modificaStock(int item);
    bool verifica(void);
    double precoVender2(int item);
    void escreveListaInv(void) const;


    //	...
}; // fim de class CListaProdutos
//=============================================================================
#endif
#endif
//=============================================================================
