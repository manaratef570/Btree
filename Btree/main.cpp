#include <iostream>
using namespace std;
template <class TT,int T>

class BTree{
 struct BTreeNode

    {

        TT *data;

        BTreeNode **child_ptr;

        bool leaf;

        int n;

    };
   BTreeNode *root = NULL, *np = NULL, *x = NULL;


public:
    BTreeNode * init(){



        np = new BTreeNode;

        np->data = new TT[T-1];

        np->child_ptr = new BTreeNode *[T];

        np->leaf = true;

        np->n = 0;

        for (int i = 0; i < T; i++)

        {

            np->child_ptr[i] = nullptr;

        }


 return np;


   }

    void sort( TT*p, int n){

             TT temp;

        for (int i = 0; i < n; i++){

            for (int j = i+1; j <= n; j++){

                if (p[i] > p[j]){

                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;}

            }}

    }
 void Insert(TT a){

        int i,k=0;
        TT  temp;

        x = root;

        if (x == NULL){

            root = init();
            x = root;

        }
        else{

//array complete and is leaf
            if (x->leaf == true && x->n == (T-1)){

                temp = split_child(x, -1,a);

                x = root;

                for ( i = 0; i < (x->n); i++){

                    if ((a > x->data[i]) && (a < x->data[i + 1])){

                        i++;
k++;
                        break;

                    }

                    else if (a < x->data[0]){
k++;
                        break;

                    }

                    else{

                        continue;

                    }

                }

                x = x->child_ptr[i];

            }
/////////////////////////////////////////////////////////////
            else{
//not leaf
                while (x->leaf == false){

                for (i = 0; i < (x->n); i++){

                    if ((a > x->data[i]) && (a < x->data[i + 1])){

                        i++;
k++;
                        break;
                    }

                    else if (a < x->data[0]){
k++;
                        break;

                    }

                    else{

                        continue;

                    }

                }
//complete
                    if ((x->child_ptr[i])->n == (T-1)){

                        temp = split_child(x, i,a);
//////////////////////////////

                       /////////////////////////////
                        x->data[x->n] = temp;
                        sort(x->data, x->n);
                        x->n++;


                        continue;

                    }

                    else{

                        x = x->child_ptr[i];

                    }

                }

            }
 }


        x->data[x->n] = a;

        sort(x->data, x->n);

        x->n++;


    }

  TT split_child(BTreeNode *x, int i,TT a){

        int j;
        TT mid;

        BTreeNode *np1, *np3, *y;

        np3 = init();

        np3->leaf = true;

        if (i == -1)

        {
           int xx=(T-2)/2;  //5-2/2  1,5 1
            mid = x->data[xx];

            x->data[xx] = 0;

            x->n--;

            np1 = init();

            np1->leaf = false;

            x->leaf = true;

            for (j = xx+1; j < (T-1); j++){

                np3->data[j - (xx+1)] = x->data[j];

                np3->child_ptr[j - (xx+1)] = x->child_ptr[j];

                np3->n++;

                x->data[j] = 0;

                x->n--;

            }

            for (j = 0; j < T; j++){

                x->child_ptr[j] = NULL;

            }

            np1->data[0] = mid;

            np1->child_ptr[np1->n] = x;

            np1->child_ptr[np1->n + 1] = np3;

            np1->n++;

            root = np1;

        }

        else{
           int xx=(T-2)/2;
            y = x->child_ptr[i];
       if(a>y->data[xx+1]){
            mid = y->data[xx+1];

            y->data[xx+1] = 0;

            y->n--;

            for (j = xx+2; j < (T-1); j++){

                np3->data[j - (xx+2)] = y->data[j];

                np3->n++;

                y->data[j] = 0;

                y->n--;

            }}
            else if (a<y->data[xx+1]){
                 mid = y->data[xx];

            y->data[xx] = 0;

            y->n--;

            for (j = xx+1; j < (T-1); j++){

                np3->data[j - (xx+1)] = y->data[j];

                np3->n++;

                y->data[j] = 0;

                y->n--;

            }





            }



            //m

              BTreeNode *tempp=init();

              x->child_ptr[i] = y;

                 tempp=x->child_ptr[i+1];
                x->child_ptr[i+1]=np3;
                x->child_ptr[i+2]=tempp;



     }

        return mid;

    }


 void Print2(BTreeNode *p){

        cout<<endl;

        int i;
for (i = 0; i < p->n; i++){
            cout << " "<< p->data[i];
        }

        for (i = 0; i < p->n; i++){

            if (p->leaf == false){

                Print2(p->child_ptr[i]);

            }
        }

        if (p->leaf == false){

            Print2(p->child_ptr[i]);


        }

        cout<<endl;

    }

void Print(){

        Print2(getroot());


    }


BTreeNode * getroot(){

return root;
}









};











int main()
{






  BTree<int,3> t1;

    t1.Insert(1);
    t1.Insert(5);
    t1.Insert(0);
    t1.Insert(4);
    t1.Insert(3);
    t1.Insert(2);

    t1.Print(); // Should output the following on the screen:

/*
BTree<char,5> t;

    // Look at the example in our lecture:
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');

    t.Print(); // Should ou

*/
    return 0;
}
