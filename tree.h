#ifndef TREE_H_
#define TREE_H_
    
    /*Ponteiro void para a info de QuadTree*/
    typedef void *QuadTreeInfo;

    /*Ponteiro void para o No de QuadTree*/
    typedef void *QuadTreeNo;

    /*Ponteiro void para QuadTree*/
    typedef void *QuadTreeQT;

    /*Ponteiro de string para InfoKey, armazena em uma string a info que define a arvore*/
    typedef char *InfoKey;
    
    QuadTreeQT criaQuadTree();

    QuadTreeNo criaNo(){;

    QuadTreeQT insereElemento(QuadTreeQT qt, QuadTreeInfo elemento, double px, double py);

    QuadTreeQT removeElemento();

    void liberaNoQuadTree(QuadTreeNo no);

    void liberaQuadTree(QuadTreeQT qt);

    char *getQuadrante(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

    int comparaPonto(double pAtualX, double pAtualY, double pRaizX, double pRaizY);

    QuadTreeNo getFilho(QuadTreeNo no, char* quadrante);

    void setFilho(Node pai, Node filho, char *quadrante);

    QuadTreeNo getNoQt(QuadTreeNo raiz, double x, double y);

    double getNoPx(QuadTreeNo no);

    double getNoPy(QuadTreeNo no);

    QuadTreeInfo getQuadTreeElemento(QuadTreeNo no);
#endif
