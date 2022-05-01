#include "List.h"
#include "Stack2.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include "Iterator.h"
using namespace std;

unsigned counting(Iterator* li) {
    unsigned cnt = 0;
    if (li->first())
        do {
            cnt++;
            cerr << li->currentItem() << " ";
        } while (li->next());        
        cerr << endl;
        return cnt;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));
    unsigned capacity, count;
    cout << "Введите объём стека: ";
    cin >> capacity;
    //List list(capacity);
    Stack2 list(capacity);
    cout << "Введите кколичество элементов для заполнения стека: ";
    cin >> count;
    for (auto i = 0; i < count; i++) {
        int x = rand() % 5;
        if (list.append(x))
            cout << x << " ";
    }
    cout << endl;

    //ListIterator* litS3 = list.createIterator(Iterators::STEP, 4);
    //ListIterator* litV4 = list.createIterator(Iterators::VALUE, 4);
    //ListIterator* litPred = list.createIterator(Iterators::PREDICATE, [](const int x) { return x % 2 == 0; });
    //       
    //cout << counting((ListIteratorStep*)litS3) << endl;
    //cout << counting((ListIteratorValue*)litV4) << endl;
    //cout << counting((ListIteratorValue*)litPred) << endl;

    Iterator* litS3 = list.createIterator(Iterators::STEP, 4);
    Iterator* litV4 = list.createIterator(Iterators::VALUE, 4);
    Iterator* litPred = list.createIterator(Iterators::PREDICATE, [](const int x) { return x % 2 == 0; }); 
    cout << counting((StackIteratorStep*)litS3) << endl;   
    cout << counting((StackIteratorValue*)litV4) << endl;
    cout << counting((StackIteratorPredicate*)litPred) << endl;

}

