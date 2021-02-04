#ifndef TREE_H_
#define TREE_H_
    
    /*Ponteiro void para QuadTree*/
    typedef void *QuadTree;
    
    /*Ponteiro void para a info de QuadTree*/
    typedef void *QuadTreeInfo;

    /*Ponteiro void para o No de QuadTree*/
    typedef void *QuadTreeNo;

    /*Ponteiro de string para InfoKey, armazena em uma string a info que define a arvore*/
    typedef char *InfoKey;

    /*Ponteiro para definir o tipo void de Node*/
    typedef void *Node;

    /*Ponteiro para definir o Tipo*/
    typedef void *tipo;

    QuadTree criaQuadTree();

    QuadTree insereElemento(QuadTree qt, QuadTreeInfo elemento, No *pai, char *quadrante);

    Node getPrevious(Node no);

    Node getNextSudeste(Node no);

    Node getNextSudoeste(Node no);

    Node getNextNordeste(Node no);

    Node getNextNoroeste(Node no);

    tipo getElemento(Node no);


#endif
