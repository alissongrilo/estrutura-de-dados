#include <iostream>
using namespace std;

class noh {
    friend class pilha;
    private:
        int mValor;
        noh* mAntecessor;
    public:
        noh(int valor);
};

noh::noh(int valor) {
    mValor = valor;
    mAntecessor = nullptr;
}

class pilha {
    private:
        noh* mTopo;
        unsigned mTamanho;
    public:
        pilha();
        ~pilha();
        unsigned retornaTamanho();
        void empilha(int valor);
        int desempilha();
        int retornaUltimoValor();
        void limpaPilha();
        bool ehVazia();
};

pilha::pilha() {
    mTopo = nullptr;
    mTamanho = 0;
}

pilha::~pilha() {
    limpaPilha();
}

void pilha::limpaPilha() {
    while (not ehVazia()) {
        desempilha();
    }
}

unsigned pilha::retornaTamanho() {
    return mTamanho;
}

bool pilha::ehVazia() {
    return (mTamanho == 0);
}

void pilha::empilha(int valor) {
    noh* novoNoh = new noh(valor);
    novoNoh->mAntecessor = mTopo;
    mTopo = novoNoh;
    mTamanho++;
}

int pilha::desempilha() {
    int auxValor = mTopo->mValor;
    noh* temp = mTopo;
    mTopo = mTopo->mAntecessor;
    delete temp;
    mTamanho--;
    return auxValor;
}

int pilha::retornaUltimoValor() {
    return mTopo->mValor;
}

int main() {
    pilha primeiraPilha;
    int numero;
    
    cin>>numero;

    while (numero > 0) {
        primeiraPilha.empilha(numero);
        cin>>numero;
    }

    while (primeiraPilha.retornaTamanho() > 0) {
        cout<<primeiraPilha.desempilha()<<" ";
    }
    cout<<endl;

    return 0;
}