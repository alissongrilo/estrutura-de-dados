typedef int Dado;
#include <iostream>
#include <string>
using namespace std;

class filaCircular {
    private:
        int mInicio;
        int mFim;
        Dado *mDados;
        unsigned mCapacidade;
        unsigned mTamanho;
    public:
        filaCircular(int capacidade = 10);
        ~filaCircular();
        void enfileira(Dado valor);
        Dado desenfileira();
        Dado pegaInicio();
};

filaCircular::filaCircular(int capacidade) {
    mInicio = -1;
    mFim = -1;
    mCapacidade = capacidade;
    mDados = new Dado[mCapacidade];
    mTamanho = 0;
}

filaCircular::~filaCircular() {
    delete [] mDados;
}

void filaCircular::enfileira(Dado valor) {
    if (mTamanho <= mCapacidade) {
        mFim++;
        mFim = mFim % mCapacidade;
        mDados[mFim] = valor;
        
        mTamanho == 0 ? mInicio++ : mInicio = mInicio;
        mTamanho++;
    } else {
        cout<<"Fila cheia"<<endl;
    }
}

Dado filaCircular::desenfileira() {
    if (mTamanho > 0) {
        Dado valor = mDados[mInicio];
        mTamanho--;
        if (mTamanho > 0) {
            mInicio++;
            mInicio = mInicio % mCapacidade;
        } else {
            mInicio = -1;
            mFim = -1;
        }
        return valor;
    } else {
        cout<<"Fila vazia"<<endl;
        return -1;
    }
}

Dado filaCircular::pegaInicio() {
    return mDados[mInicio];
}

int main() {
    int qtdNumerosBinarios;
    Dado elemento;
    string auxiliar;

    cin>>qtdNumerosBinarios;

    filaCircular f1(qtdNumerosBinarios + 2);
    
    f1.enfileira(1);
    
    for (unsigned i = 0; i < qtdNumerosBinarios; i++) {
        elemento = f1.pegaInicio();
        auxiliar = std::to_string(elemento);
        auxiliar = auxiliar + "0";
        elemento = std::stoi(auxiliar);
        f1.enfileira(elemento);

        elemento = f1.pegaInicio();
        auxiliar = std::to_string(elemento);
        auxiliar = auxiliar + "1";
        elemento = std::stoi(auxiliar);
        f1.enfileira(elemento);

        cout<<f1.pegaInicio()<<" ";
        f1.desenfileira();
    }

    f1.~filaCircular();
}
