#include "DemoTest.h"
#include <iostream>
#include <ctime>

using namespace std;

namespace DSLib {

void josephus(int n, int s, int m)
{
    CircleLinkList<int> cl;

    for (int i = 1; i <= n; i++)
    {
        cl.insert(i);
    }

    cl.move(s - 1, m - 1);

    while (cl.length() > 0)
    {
        cl.next();

        cout << cl.current() << endl;

        cl.remove(cl.find(cl.current()));
    }
}

void linux_list_demo1(void)
{
    struct Node
    {
        struct list_head head;
        int value;
    };

    struct Node l = {{nullptr, nullptr}, 0};

    struct list_head * list = (struct list_head *)&l;
    struct list_head * slider = nullptr;


    INIT_LIST_HEAD(list);

    cout << "insert start ..." << endl;

    for (int i = 0; i < 5; i++)
    {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));

        n->value = i;

        list_add_tail((struct list_head *)n, list);
    }

    list_for_each(slider, list)
    {
        cout << ((struct Node *)slider)->value << endl;
    }

    cout << "insert end ..." << endl;
}

void linux_list_demo2(void)
{
    struct Node
    {
        int value;
        struct list_head head;
    };

    struct Node l = {0, {nullptr, nullptr}};

    struct list_head * list = &l.head;
    struct list_head * slider = nullptr;


    INIT_LIST_HEAD(list);

    cout << "insert start ..." << endl;

    for (int i = 0; i < 5; i++)
    {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));

        n->value = i;

        list_add_tail(&n->head, list);
    }

    list_for_each(slider, list)
    {
        cout << list_entry(slider, struct Node, head)->value << endl;
    }

    cout << "insert end ..." << endl;
}

void DualCircleLinkList_Demo(void)
{
    DualCircleLinkList<int> Dc;

    for (int i = 0; i < 10; i++)
    {
        Dc.insert(0, i);
        Dc.insert(0, 5);
    }

    cout << "begin" << endl;

    Dc.move(Dc.length() - 1);

    while (Dc.find(5) != -1)
    {
        if (Dc.current() == 5)
        {
            cout << Dc.current() << endl;

            Dc.remove(Dc.find(Dc.current()));
        }
        else
        {
            Dc.pre();
        }
    }

    cout << "end" << endl;

    for (int i = 0; i < Dc.length(); i++)
    {
        cout << Dc.get(i) << endl;
    }
}

void Stack_Demo(void)
{
    QueueToStack<int> qts;

    for (int i = 0; i < 10; i++)
    {
        qts.push(i);
        cout << qts.top() << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << qts.top() << endl;
        qts.pop();
    }
}

void Queue_Demo(void)
{
    StackToQueue<int> stq;

    for (int i = 0; i < 10; i++)
    {
        stq.add(i);
    }

    while (stq.length() > 0)
    {
        cout << stq.front() << endl;

        stq.remove();
    }
}

void DString_Demo(void)
{
    DString s = "test yhd!";

    s.SubString(3,20);

    cout << s.SubString(3,20).str() << endl;
}

void linklist_reverse(void)
{
    LinkList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.insert(i);
    }

    for (int i = 0; i < list.length(); i++)
    {
        cout << list.get(i) << "->";
    }
    cout << "nullptr" << endl;

    cout << "reverse the linklist" << endl;

    (list.GetHeaderNode())->next = LinkListAlgorithm<int>::reverse((list.GetHeaderNode())->next);

    for (int i = 0; i < list.length(); i++)
    {
        cout << list.get(i) << "->";
    }
    cout << "nullptr" << endl;
}

void linklist_merge(void)
{
    LinkList<int> list;
    LinkList<int> list1;
    LinkList<int> list2;

    for (int i = 0; i <= 10; i++, i++)
    {
        list1.insert(i);
    }

    for (int i = 0; i < list1.length(); i++)
    {
        cout << list1.get(i) << "->";
    }
    cout << "nullptr" << endl;

    for (int i = 1; i <= 11; i++, i++)
    {
        list2.insert(i);
    }

    for (int i = 0; i < list2.length(); i++)
    {
        cout << list2.get(i) << "->";
    }
    cout << "nullptr" << endl;

    cout << "merge list1 and list2" << endl;

    list.GetHeaderNode()->next =  LinkListAlgorithm<int>::merge(list1.GetHeaderNode()->next, list2.GetHeaderNode()->next);
    *(list.GetLength()) = list1.length() + list2.length();

    for (int i = 0; i < list.length(); i++)
    {
        cout << list.get(i) << "->";
    }

    cout << "nullptr" << endl;
}

void linklist_reverse_print(void)
{
    LinkList<int> list1;

    for (int i = 0; i < 10; i++ )
    {
        list1.insert(i);
    }

    for (int i = 0; i < list1.length(); i++)
    {
        cout << list1.get(i) << endl;;
    }

    cout << "reverse print the list1" << endl;

    LinkListAlgorithm<int>::ReversePrint(list1.GetHeaderNode()->next);
}

void linklist_demo(void)
{
    linklist_reverse_print();
}

void HanoiTower_demo(void)
{
    HanoiTower(3, 'a', 'b', 'c');
}

void permutation_demo(void)
{
    char s[] = "aaa";

    permutation(s, s);
}

void QueueSolution_demo(void)
{
    QueueSolution<8> queue;

    queue.ChessStart();
}

void Sort_select(void)
{
    int a[] = {5,6,9,1,3,7};

    Sort::select(a, 6, ASCENDING);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

void Sort_insert(void)
{
    int a[] = {5,6,9,1,3,7};

    Sort::insert(a, 6, DESCENDING);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

class Test : public Object
{
public:
    int id;
    int data1[1000];
    double data2[500];

    bool operator > (const Test& obj)
    {
        return (id > obj.id);
    }
    bool operator < (const Test& obj)
    {
        return (id < obj.id);
    }
    bool operator >= (const Test& obj)
    {
        return (id >= obj.id);
    }
    bool operator <= (const Test& obj)
    {
        return (id <= obj.id);
    }

};

class TestpProxy : public Object
{
protected:
    Test * m_pTest;
public:
    int id()
    {
        return m_pTest->id;
    }

    int * data1()
    {
        return m_pTest->data1;
    }

    double * data2()
    {
        return m_pTest->data2;
    }

    Test& test() const
    {
        return *m_pTest;
    }

    bool operator > (const TestpProxy& obj)
    {
        return test() > obj.test();
    }
    bool operator < (const TestpProxy& obj)
    {
        return test() < obj.test();
    }
    bool operator >= (const TestpProxy& obj)
    {
        return test() >= obj.test();
    }
    bool operator <= (const TestpProxy& obj)
    {
        return test() <= obj.test();
    }

    Test& operator = (Test& t)
    {
        m_pTest = &t;

        return t;
    }

};

Test t[1000];
TestpProxy pt[1000];

void Sort_bubbleProxy(void)
{
    clock_t begin = 0;
    clock_t end = 0;

    for (int i = 0; i < 1000; i++)
    {
        t[i].id = i;
        pt[i] = t[i];
    }

    begin = clock();

    Sort::bubble(pt, 1000, DESCENDING);

    end = clock();

    cout << "Time: " << (end - begin) << endl;
}

void Sort_bubble(void)
{
//    int a[] = {5,6,9,1,3,7};

//    Sort::shell(a, 6, DESCENDING);

//    for (int i = 0; i < 6; i++)
//    {
//        cout << a[i] << " ";
//    }

//    cout << endl;

    Sort_bubbleProxy();
}

void Sort_merge(void)
{
    int a[] = {5,6,9,1,3,7};

    Sort::merge(a, 6, DESCENDING);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

void Sort_quick(void)
{
    StaticAarray<int, 5> sa;

    for (int i = 0; i < 5; i++)
    {
        sa[i] = i ;
    }

    Sort::quick(sa.GetArray(), sa.length(), DESCENDING);

    for (int i = 0; i < sa.length(); i++)
    {
        cout << sa[i] << " ";
    }

    cout << endl;
}

void Sort_demo(void)
{
    Sort_bubble();
}

void gtree_demo(void)
{
    GTree<char> gtree;
    GTreeNode<char> root;

    root.value = 'A';
    root.parent = nullptr;
    gtree.insert(&root);

    gtree.insert('B', gtree.find('A'));
    gtree.insert('C', gtree.find('A'));
    gtree.insert('D', gtree.find('A'));

    gtree.insert('E', gtree.find('B'));
    gtree.insert('F', gtree.find('B'));

    gtree.insert('K', gtree.find('E'));
    gtree.insert('L', gtree.find('E'));

    gtree.insert('G', gtree.find('C'));

    gtree.insert('H', gtree.find('D'));
    gtree.insert('I', gtree.find('D'));
    gtree.insert('J', gtree.find('D'));

    gtree.insert('M', gtree.find('H'));

//    SharedPointer< Tree<char> > spTree =  gtree.remove('D');

//    DString s = "KLFGMIJ";

//    for (int i = 0; i < 7; i++)
//    {
//        pGTreeNode = spTree->find(s[i]);

//        while (pGTreeNode != nullptr)
//        {
//            cout << pGTreeNode->value << "-->";
//            pGTreeNode = dynamic_cast<GTreeNode<char> *>(pGTreeNode->parent);
//        }

//        cout << endl;
//    }

    for (gtree.begin(); !gtree.end(); gtree.next())
    {
        cout << gtree.current() << endl;
    }
}

void btree_demo(void)
{
    BTree<int> bt;

    bt.insert(1, nullptr);

    bt.insert(2, bt.find(1));
    bt.insert(3, bt.find(1));
    bt.insert(4, bt.find(2));
    bt.insert(5, bt.find(2));
    bt.insert(8, bt.find(4));
    bt.insert(9, bt.find(4));
    bt.insert(10, bt.find(5));
    bt.insert(6, bt.find(3));
    bt.insert(7, bt.find(3));

    cout << bt.count() << endl;
    cout << bt.height() << endl;
    cout << bt.degree() << endl;

    for (bt.begin(); !bt.end(); bt.next())
    {
        cout << bt.current() << " ";
    }

    cout << endl;

    cout << "clone btree" << endl;

    SharedPointer< BTree<int> > btClone = bt.clone();

    for (btClone->begin(); !btClone->end(); btClone->next())
    {
        cout << btClone->current() << " ";
    }

    cout << endl;

    cout << "old binary tree == clone binary tree : " << (bt == *btClone) << endl;

    cout << "old binary tree + clone binary tree : "<< endl;

    SharedPointer< BTree<int> > addBtree = bt.add(*btClone);

    for (addBtree->begin(); !addBtree->end(); addBtree->next())
    {
        cout << addBtree->current() << " ";
    }

    cout << endl;

    cout << "bt + bt2 : "<< endl;

    BTree<int> bt2;

    bt2.insert(1, nullptr);

    bt2.insert(2, bt2.find(1));
    bt2.insert(3, bt2.find(1));
    bt2.insert(4, bt2.find(2));
    bt2.insert(5, bt2.find(2));
    bt2.insert(8, bt2.find(4));
    bt2.insert(9, bt2.find(4));

    SharedPointer< BTree<int> > addBtree2 = bt.add(bt2);

    for (addBtree2->begin(); !addBtree2->end(); addBtree2->next())
    {
        cout << addBtree2->current() << " ";
    }
}

void btree_demo2(void)
{
    BTree<int> bt;

    bt.insert(1, nullptr);

    bt.insert(2, bt.find(1));
    bt.insert(3, bt.find(1));
    bt.insert(4, bt.find(2));
    bt.insert(5, bt.find(2));
    bt.insert(8, bt.find(4));
    bt.insert(9, bt.find(4));
    bt.insert(10, bt.find(5));
    bt.insert(6, bt.find(3));
    bt.insert(7, bt.find(3));

    cout << bt.count() << endl;
    cout << bt.height() << endl;
    cout << bt.degree() << endl;

    SharedPointer< Array<int> > sa = bt.traversal(LEVEL_ORDER);

    for (int i = 0; i < sa->length(); i++)
    {
        cout << (*sa)[i] << " ";
    }

    cout << endl;

    cout << "thread the btree" << endl;

    BTreeNode<int> * node = bt.thread(LEVEL_ORDER);

    cout << "btree count = " << bt.count() << endl;
    cout << "btree height = " << bt.height() << endl;
    cout << "btree degree = " << bt.degree() << endl;

    while (node)
    {
        cout << node->value << " ";
        node = node->m_right;
    }

    cout << endl;

    BTreeNode<int> * temp = nullptr;
    while (node)
    {
        temp = node;
        node = node->m_right;
        delete temp;
    }
}

}
