//atualizado 
#include <iostream>

using namespace std;
	
class No{
private:
	No *esquerda, *direita; //lado esquerdo e direito da arvore
	char chave; //valor unico

        
public: //construtor
	No(char chave){
		this->chave = chave;
		//null porque quando cria folha
		esquerda = NULL;
		direita = NULL;
	}

	char getChave(){
		//retorno da chave
		return chave;
	}
	
	// getters e setters
	No* getEsquerda(){
		//retorno do no* esq
		return esquerda;
	}

	No* getDireita(){
		//retorno do no* dir
		return direita;
	}

	void setEsquerda(No *no){
		// setar no esq
		esquerda = no;
	}

	void setDireita(No *no){
		//setar no dir
		direita = no;
	}
};

class Arvore{
private:
	No *raiz;

public:
	Arvore(){
		//criacao de arvore a raiz é nula
		raiz = NULL;
	}

	void inserir(char chave){
		if(raiz == NULL) // se a arvore estver nula
			raiz = new No(chave); //cria um novo nó passando a chave
		else //se não estiver vazia vai inserir aux
			inserirAux(raiz, chave);//começa da raiz verificando onde inserir o nó
	}
	

	void inserirAux(No *no, char chave){
		// se for menor, então insere à esquerda
		if(chave < no->getChave()){
			// verifica se a esquerda é nulo
			if(no->getEsquerda() == NULL){
				No *novo_no = new No(chave);
				no->setEsquerda(novo_no); // seta o novo_no à esquerda
			}else{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsquerda(), chave);
			}
		}
		// se for maior, então insere à direita
		else if(chave > no->getChave()){
			// verifica se a direita é nulo
			if(no->getDireita() == NULL){
				No *novo_no = new No(chave); 
				no->setDireita(novo_no); // seta o novo no à direita
			}else{
				// senão, seguir a busca
				inserirAux(no->getDireita(), chave);
			}
		}
		
	}
	
	//funcao para retorna  a raiz
	No* getRaiz(){
		return raiz;
	}
		//função da arvore bianria de PRE ORDEM
        void preOrdem(No* raiz){
		if(raiz != NULL){
        	cout << raiz->getChave() << " ";
			preOrdem(raiz->getEsquerda());
			
			preOrdem(raiz->getDireita());
		}
	}
       
};

int main(int argc, char *argv[]){
	
	Arvore arv;
	string elemento;
	
	cout<<"Insira os elementos da arvore : \n";
	cin>>elemento;
	
	
	//quebra dos elementos
	for(int i=0; i<elemento.size();i++){
	
		cout<<elemento[i]<<endl;
		arv.inserir(elemento[i]); 
	}
	
	//percorre em ordem iniciando da raiz
	cout << "\n \n Pre Ordem...\n";
	arv.preOrdem(arv.getRaiz());

    	return 0;
	}
