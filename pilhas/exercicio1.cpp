#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap = 100);
        ~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int capacidade) {
    tamanho = -1;
    posTopo = 0;
    this->capacidade = capacidade;
    dados = new Dado[capacidade];
}

pilhav::~pilhav() {
    delete [] dados;
}

void pilhav::empilha(Dado valor) {
    posTopo = valor;
    tamanho++;
    dados[tamanho] = valor;
}

Dado pilhav::desempilha() {
    Dado auxValor = posTopo;
    posTopo = dados[tamanho-1];
    tamanho--;
    return auxValor;
}

Dado pilhav::espia() {
    return posTopo;
}

void pilhav::depura() {
    for (unsigned i = 0; i<=tamanho; i++) {
        cout<<dados[i]<<" ";
    }
}

void pilhav::info() {
    cout<<tamanho+1<<" "<<tamanho<<endl;
}

int main() {
    pilhav minhaPilha(20);
    int valor;

    for (unsigned i = 0; i<5; i++) {
        cin>>valor;
        minhaPilha.empilha(valor);
    }

    for (unsigned i = 0; i<3; i++) {
        cout<<minhaPilha.desempilha()<<" ";
    }
    cout<<endl;

    for (unsigned i = 0; i<4; i++) {
        cin>>valor;
        minhaPilha.empilha(valor);
    }

    for (unsigned i = 0; i<3; i++) {
        cout<<minhaPilha.desempilha()<<" ";
    }
    cout<<endl;

    cout<<minhaPilha.espia()<<endl;

    minhaPilha.depura();
    cout<<endl;

    minhaPilha.info();

    return 0;
}