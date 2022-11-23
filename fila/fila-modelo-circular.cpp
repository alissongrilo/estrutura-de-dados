typedef int Dado;
#include <iostream>
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
        unsigned tamanho();
        void enfileira(Dado valor);
        Dado desenfileira();
        bool vazia();
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

unsigned filaCircular::tamanho() {
    return mTamanho;
}

bool filaCircular::vazia() {
    return (mTamanho == 0);
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

int main() {
    filaCircular f1(12);
    int num;

    for (unsigned i = 0; i < 8; i++) {
        cin>>num;
        f1.enfileira(num);
    }

    cout<<"tamanho: "<<f1.tamanho()<<endl;

    cout<<"desenfileirando 5 elementos: ";

    for (unsigned i = 0; i < 5; i++) {
        cout<<f1.desenfileira()<<" ";
    }
    cout<<endl;

    f1.~filaCircular();
}
