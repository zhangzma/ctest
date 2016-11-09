// main.cc

#include <cstdio>

struct _node {
    int v;
    struct _node *next;
};

typedef struct _node node;
typedef struct _node *List;

bool init_list(struct _node *plist);
void add_element(struct _node *plist);
void print_node(const node &n);



int main(int argc, char *argv[])
{
    
    return 0;
}

void print_list(const node)

void print_node(const node &n)
{
    printf("%d -> ", n.v);
}
