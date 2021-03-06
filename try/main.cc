
#include "list.cc"

int main(void)
{
    LinearList<int> L(5);

    cout << "befor insert: listEmpty? " << L.listEmpty() << endl;

    L.listInsert(1, 1).listInsert(2, 2).listInsert(3, 3).listInsert(4, 4).listInsert(5, 5);
    cout << "after insert: listEmpty? " << L.listEmpty() << endl;
    cout << "list are:" << endl;
    cout << L;
    cout << "list length is: " << L.listLength() << endl;

    int x;
    L.getElem(2, x);
    cout << "getElem(2,x) : " << x << endl;
    cout << "locateElem(x) : " << L.locateElem(x) << endl;
    cout << "priorElem(x) : " << L.priorElem(x) << endl;
    cout << "nextElem(x) : " << L.nextElem(x) << endl;
    
    L.listDelete(2);
    cout << "after delet(2),list are:" << endl;
    cout << L << endl;
    cout << "list length is: " << L.listLength() << endl;
    std::cout << "endl" << std::endl;

    cout << endl;
    return 0;
}
