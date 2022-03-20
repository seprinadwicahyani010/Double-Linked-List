#include <iostream>
using namespace std;

typedef struct node
{
      long data;
      node* next;
      node* prev;
};

node* first;
node* last;
node* print;
node* del;
node* entry;

void inisialisasi()
{
      first = NULL;
      last = NULL;
}

int isEmpty()
{
      if(first == NULL)
            return 1;
      else
            return 0;
}

void input(int *dta)
{
      entry = new node;
      entry->data = *dta;
      entry->next = NULL;
      entry->prev = NULL;
      if(isEmpty()==1)
      {
            first = entry;
            first->next = NULL;
            first->prev = NULL;
            last=first;
      }
      else
      {
            last->next = entry;
            entry->prev = last;
            last = entry;
      }
}

void hapus()
{
      int simpan;
      if(first!=NULL) 
      {
            if(first->next != NULL)
            {
            del=first;
            simpan = first->data;
            cout<<"\n"<<simpan<<" telah dihapus"<<endl;
            first = first->next;
            first->prev = NULL;
            delete del;
            }
            else
            {
                  simpan = first->data;
                  cout<<"\n"<<simpan<<" telah dihapus"<<endl;
                  first = NULL;
            }

      }
      else
            cout<<"\npenghapusan tidak dapat dilakukan karena linked list kosong"<<endl;
}

void display()
{
      print = first;
      if(first!=NULL)
      {
            while(print!=NULL)
            {
                  cout<<"\t"<<print->data;
                  print = print->next;
            }
      }
      else
            cout<<"\nLinked list tidak memiliki data"<<endl;

}
void menu()
{
      char pilih, ulang;
      int data;
      do
      {
            system("CLS");
menu :
      cout<<"DOUBLE LINKED LIST"<<endl;
      cout<<"---------------------------"<<endl;
      cout<<"Menu: \n";
      cout<<"1. Input Data\n";
      cout<<"2. Dalete Data\n";
      cout<<"3. Display\n";
      cout<<"4. Keluar\n";
      cout<<"Masukkan pilihan Anda : \n";
      cin>>pilih;

      switch(pilih)
      {
      case '1' :
            cout<<"\nMasukkan Data  : ";
            cin>>data;

            input(&data);
            cout<<"\n"<<data<<" ditambahkan"<<endl;
            break;
      case '2' :
            hapus();
            break;
      case '3'  :
            display();
            break;
      case '4' :
            cout<<"\nTerima kasih "<<endl;
            exit;
            break;
      default :
            cout<<"\nPilih Kembali"<<endl;
            goto menu;
      }
      cout<<"\nKembali ke menu? (y/n)";
      cin>>ulang;
      }while(ulang=='y' || ulang =='Y');
}

int main()
{
      inisialisasi();
      menu();
      return 0 ;
}
