#include "Child_Buku.h"
#include "Parent_Peminjam.h"

using namespace std;

void CreateList_c(List_c &LC)
{
    first(LC) = NULL;
    last(LC) = NULL;
};

void deleteID_c(List_c &LC, int x)
{
    address_c PC;
            if (first(LC) != NULL)
        {
            PC = findElm_c(LC,x);
            if (info_c(PC).ID == x)
            {
                address_c QC;
                QC = first(LC);
                if (next(QC) == NULL){
                    QC = first(LC);
                }
            else
                {
                    while (next(QC) != PC)
                    {
                        QC = next(QC);
                    }
                }
                deleteafter_c(LC,QC,PC);
                cout<<"Data telah dihapus\n";
            }
            else
            {
                cout<<"ID tidak ditemukan";
            }
        }
            else
            {
                cout<<"No Data";
            }
};
address_c alokasi_c(int ID, int jumlah, string judul, string pengarang, string status)
{
    address_c PC;
    PC = new elmlist_c;
    info_c(PC).ID = ID;
    info_c(PC).judul= judul;
    info_c(PC).pengarang = pengarang;
    info_c(PC).jumlah = jumlah;
    info_c(PC).status = status;
    next(PC) = NULL;
    prev(PC) = NULL;
    return PC;
};

void dealokasi_c(address_c &PC){
    delete PC;
};

void insertFirst_c(List_c &LC, address_c PC){
    if (first(LC) == NULL){
        first(LC) = PC;
        last(LC) = PC;
    }
    else{
        next(PC) = first(LC);
        prev(first(LC)) = PC;
        first(LC) = PC;
    }
};

void insertAfter_c(List_c &LC, address_c Precc, address_c PC){
    if (first(LC) == NULL){
        first(LC) = PC;
        last(LC) = PC;
    }
    else if (first(LC) == last(LC)){
        next(Precc) = PC;
        prev(PC) = Precc;
        last(LC) = PC;
    }
    else{
        next(PC) = next(Precc);
        prev(PC) = Precc;
        next(Precc) = PC;
        prev(next(PC)) = PC;
    }
};

address_c findElm_c(List_c LC, int x){
    address_c C = first(LC);
    if (first(LC) == NULL){
        C = NULL;
    }
    else{
        while (info_c(C).ID != x && next(C) != last(LC)){
            C = next(C);
        }
    }
    return C;
};

void deleteFirst_c(List_c &LC, address_c &PC){
    PC = first(LC);
    if (first(LC) == NULL){
        cout<<"Data kosong \n";
    }
    else if(first(LC) == last(LC)){
        first(LC) = NULL;
        last(LC) = NULL;
        dealokasi_c(PC);
    }
    else{
        prev(next(PC)) = NULL;
        first(LC) = next(PC);
        next(PC) = NULL;
        dealokasi_c(PC);
    }
};

void deleteafter_c(List_c &LC, address_c &Precc, address_c &PC){
    PC = first(LC);
    if (first(LC) == NULL){
        cout<<"No Data \n";
    }
    else if(first(LC) == last(LC)){
        first(LC) = NULL;
        last(LC) = NULL;
        dealokasi_c(PC);
    }
    else{
        PC = next(Precc);
        next(Precc) = next(PC);
        prev(next(PC)) = Precc;
        next(PC) = NULL;
        prev(PC) = NULL;
        dealokasi_c(PC);
    }
}
void printInfo_c(List_c LC)
{
    int i;
    i = 1;
    if (first(LC) == NULL)
    {
        cout<<"No Data";
    }
    else
    {
    address_c C;
    C = first(LC);
    while(C != last(LC))
    {
        cout<<"List ke-"<<i<<"\n";
        cout<<"----------"<<endl;
            cout<<"ID Buku                 : "<<info_c(C).ID<<endl;
            cout<<"Judul Buku              : "<<info_c(C).judul<<endl;
            cout<<"Nama Pengarang          : "<<info_c(C).pengarang<<endl;
            cout<<"Jumlah Buku Di Pinjam   : "<<info_c(C).jumlah<<endl;
            cout<<"Status Buku             : "<<info_c(C).status<<endl;
        C = next(C);
        i = i+1;
    }
        cout<<"List ke-"<<i<<endl;
        cout<<"----------"<<endl;
            cout<<"ID Buku               : "<<info_c(C).ID<<endl;
            cout<<"Judul Buku            : "<<info_c(C).judul<<endl;
            cout<<"Nama Pengarang        : "<<info_c(C).pengarang<<endl;
            cout<<"Jumlah Buku Di Pinjam : "<<info_c(C).jumlah<<endl;
            cout<<"Status Buku           : "<<info_c(C).status<<endl;
    }
};

void insertAscending_c(List_c &LC, int ID, int jumlah, string judul, string pengarang, string status){
    address_c PC,C;
    int h,k;
    string i,j,l;
    h = ID;
    i = judul;
    j = pengarang;
    k = jumlah;
    l = status;
    PC = alokasi_c(h,k,i,j,l);
    if(first(LC) == NULL || info_c(first(LC)).ID > h){
        insertFirst_c(LC, PC);
    }
    else{
        C = first(LC);
        while(C != last(LC) && info_c(next(C)).ID < h){
            C = next(C);
        }
        insertAfter_c(LC,C,PC);
    }
};
