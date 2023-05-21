typedef struct fila Fila;

Fila* create(int n);

int add(Fila* fi, int e);

int pop(Fila* fi);

int size(Fila* fi);

int first(Fila* fi);

int last(Fila* fi);

int find(Fila* fi, int ps);

int isFull(Fila* fi);

int isEmpty(Fila* fi);

int clear(Fila* fi);
