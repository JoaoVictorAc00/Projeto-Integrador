#include <iostream>
#include <vector>
#include <string>



enum class StatusProduto {
    EmEstoque,
    Reposicao,
    Esgotado
};

class Produto {



public:


    Produto(const string& nome, int quantidade, int quantidadeMinima)
        : nome(nome), quantidade(quantidade), quantidadeMinima(quantidadeMinima) {}



    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    int getQuantidadeMinima() const { return quantidadeMinima; }

    StatusProduto getStatus() const {
        return quantidade < quantidadeMinima ? StatusProduto::Reposicao : StatusProduto::EmEstoque;
    }

private:




    string nome;
    int quantidade;
    int quantidadeMinima;
};

class Estoque {


public:

    void adicaoProduto(const Produto& produto) {
        produtos.push_back(produto);
    }

    void verificarReposicao() {
        for (Produto& produto : produtos) {
            if (produto.getStatus() == StatusProduto::Reposicao) {


                notificador.Alerta(produto.getNome());
            }
        }
    }

private:

    vector<Produto> produtos;


    class Notificador {
    public:
        void Alerta(const string& nomeProduto) {
            cout << "**Alerta** " << nomeProduto << " precisa de reposição urgentemente!" << endl;
        }
    };

    Notificador notificador;
};


int main() {


    Estoque estoque;

   
    estoque.adicaoProduto(Produto("Produto A", 15, 15));
    estoque.adicaoProduto(Produto("Produto B", 20, 20));
    estoque.produtos[0].quantidade += 6;
    estoque.produtos[1].quantidade += 9;
    estoque.produtos[0].quantidade -= 8;
    estoque.produtos[1].quantidade -= 22;

   
    cout << "Detalhes do Estoque:" << endl;
        for (Produto produto : estoque.produtos) {


        cout << "Nome: " << produto.getNome() << endl;
        cout << "Quantidade: " << produto.getQuantidade() << " unidades" << endl;
        cout << "Quantidade Mínima: " << produto.getQuantidadeMinima() << endl;
        cout << "Status: " << produto.getStatus() << endl;
        
    }

    
    estoque.verificarReposicao();

    return 0;
}