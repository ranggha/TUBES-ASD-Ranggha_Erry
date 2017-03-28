#include "Main_Menu.h"
#include "Parent_Peminjam.h"
#include "Child_Buku.h"
#include "Relasi_Penghubung.h"

address_p P,Q;
int pil,a,angka,id,idc,p,childbuku,buku,psi,nom,nim,ID1,ID2;;
string b,c,d,e,u;
List_p LP;
List_c LC;
List_r LR;



/*void menu(){
    CreateList(LP);
    CreateList_c(LC);
    pil = 0;
    while(pil != 13){
    cout<<"1.) Insert parents_Peminjam \n";
    cout<<"2.) Insert Child_Buku \n";
    cout<<"3.) view Parent_Peminjam \n";
    cout<<"4.) Connecting relation\n";
    cout<<"5.) View Connected\n";
    cout<<"6.) Delete Relation\n";
    cout<<"7.) Find Relation \n";
    cout<<"8.) view Child_Buku\n";
    cout<<"9.) delete Parent_Peminjam \n";
    cout<<"10.) delete Childs\n";
    cout<<"11.) Find parents\n";
    cout<<"12.) Find Childs\n";
    cout<<"13.) EXIT \n";
    cout<<"Masukan pilihan anda :  ";
    cin>>pil;
    switch(pil){
    case 1 : insertParent_Peminjam();
             break;
    case 2 : insertChild_Buku();
             break;
    case 3 : viewParent_Peminjam();
             break;
    case 8 : viewChilds_Buku();
             break;
    case 9 : deleteParent_Peminjam();
             break;
    case 11 : FindParent_Peminjam();
             break;
    };
    }
};*/
void insertChild_Buku(){
    address_c PC;
    int a,d;
    string b,c,e;
    cout<<"Masukan ID Buku : ";
             cin>>a;
             cout<<"Masukan Judul Buku : ";
             cin>>b;
             cout<<"Masukan Nama Pengarang : ";
             cin>>c;
             cout<<"Masukan Jumlah Buku Yang Di Pinjam : ";
             cin>>d;
             cout<<"Masukan Status Buku : ";
             cin>>e;
             PC = alokasi_c(a,d,b,c,e);
             if (first(LC) == NULL){
                insertAscending_c(LC,a,d,b,c,e);
             }
             else{
                PC = findElm_c(LC, a);
                if (info_c(PC).ID != a){
                    insertAscending_c(LC, a,d,b,c,e);
                }
                else{
            cout<<"ID duplicate\n";
                    }
             }
}

void insertParent_Peminjam(){
    address_p P;
        cout<<"Masukan ID Peminjam : ";
             cin>>a;
             cout<<"Masukan Nama Peminjam : ";
             cin>>b;
             cout<<"Masukan Alamat Peminjam : ";
             cin>>c;
             cout<<"Masukan Nomer Handphone Peminajm : ";
             cin>>d;
             cout<<"Masukan Gender Peminjam : ";
             cin>>e;
             if (first(LP) == NULL){
                insertAscending(LP,a,b,c,d,e);
             }
             else{
                P = findElm(LP, a);
                    if (info(P).ID != a){
             insertAscending(LP, a,b,c,d,e);
                    }
                    else{
            cout<<"ID duplicate\n";
                    }
             }
    };


void viewParent_Peminjam()
{
    printInfo(LP);
    cout<<endl;
};


void viewChilds_Buku()
{
     printInfo_c(LC);
     cout<<endl;
};

void deleterelat(){
    address_p PR;
    address_c CR;
    address_r R;
    cout<<"Masukan ID Peminjam yang ingin didelete : ";
    cin>>nom;
    cout<<"Masukan ID Buku yang ingin didelete      : ";
    cin>>nim;
    PR = findElm(LP,nom);
    CR = findElm_c(LC,nim);
    R = first_r(LR);
    while(info_r(R).ID != nom || info_r(R).ID2 != nim){
        R = next_r(R);
    }
    deleteRel(LR, R);
};

void deleteParent_Peminjam()
{
    cout<<"Masukan ID Peminjam yang ingin didelete : ";
    cin>>angka;
    deleteID(LP,angka);
};

void deleteChild_Buku(){
    address_c PC;
    cout<<"Masukan ID child_buku yang ingin dihapus : ";
    cin>>childbuku;
    deleteID_c(LC,childbuku);
};

void FindParent_Peminjam()
{
    address_p Q;
    cout<<"Masukan ID Peminjam yang ingin dicari : ";
    cin>>id;
    Q = findElm(LP,id);
    if(Q == NULL){
        cout<<"Maaf peminjam yang anda cari tidak ada \n";
    }
    else if(info(Q).ID != id){
        cout<<"ID peminjam yang anda cari tidak ditemukan \n";
    }
    else
  {
            cout<<"Peminjam yang anda cari tersedia dalam list \n";
        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";
        cin>>u;
        if (u == "Y" || u == "y")
     {
            address_p Q;
            Q = first(LP);
            if ((Q) == first(LP)){
                cout<<"----------"<<endl;
                cout<<"ID Peminjam     : "<<info(Q).ID<<endl;
                cout<<"Nama Peminjam   : "<<info(Q).nama<<endl;
                cout<<"Alamat Peminjam : "<<info(Q).alamat<<endl;
                cout<<"Nomer HP Peminjam : "<<info(Q).nohp<<endl;
                cout<<"Gender Peminjam : "<<info(Q).gender<<endl;
            }
            else
         {
            while(next(Q) != first(LP))
            {
                    if (info(Q).ID == id)
                    {
                cout<<"----------"<<endl;
                cout<<"ID Peminjam     : "<<info(Q).ID<<endl;
                cout<<"Nama Peminjam   : "<<info(Q).nama<<endl;
                cout<<"Alamat Peminjam : "<<info(Q).alamat<<endl;
                cout<<"Nomer HP Peminjam : "<<info(Q).nohp<<endl;
                cout<<"Gender Peminjam : "<<info(Q).gender<<endl;
                    }
                    Q = next(Q);
            }
            if (info(Q).ID == id)
                {
                cout<<"----------"<<endl;
                cout<<"ID Peminjam     : "<<info(Q).ID<<endl;
                cout<<"Nama Peminjam   : "<<info(Q).nama<<endl;
                cout<<"Alamat Peminjam : "<<info(Q).alamat<<endl;
                cout<<"Nomer HP Peminjam : "<<info(Q).nohp<<endl;
                cout<<"Gender Peminjam : "<<info(Q).gender<<endl;
                }
            }
        }
    }

};

void findChild_Buku(){
        address_c QC;
    cout<<"Masukan ID Buku yang ingin dicari : ";
    cin>>idc;
    QC = findElm_c(LC,idc);
    if(QC == NULL){
        cout<<"Maaf ID Buku yang anda cari tidak ada \n";
    }
    else if(info_c(QC).ID != idc){
        cout<<"ID child yang anda cari tidak ditemukan \n";
    }
    else{
            cout<<"Parents yang anda cari tersedia dalam list \n";
        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";
        cin>>u;
        if (u == "Y" || u == "y"){
            address_c QC;
            QC = first(LC);
            if ((QC) == first(LC)){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Judul Buku     : "<<info_c(QC).judul<<endl;
                cout<<"Pengarang      : "<<info_c(QC).pengarang<<endl;
                cout<<"Jumlah Buku Yang Di Pinjam   : "<<info_c(QC).jumlah<<endl;
            }
            else{
            while(next(QC) != last(LC)){
                    if (info_c(QC).ID == idc){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Judul Buku     : "<<info_c(QC).judul<<endl;
                cout<<"Pengarang      : "<<info_c(QC).pengarang<<endl;
                cout<<"Jumlah Buku Yang Di Pinjam   : "<<info_c(QC).jumlah<<endl;
                    }
                    QC = next(QC);
            }
            if (info_c(QC).ID == idc){
                cout<<"----------"<<endl;
                cout<<"ID       :"<<info_c(QC).ID<<endl;
                cout<<"Judul Buku     : "<<info_c(QC).judul<<endl;
                cout<<"Pengarang      : "<<info_c(QC).pengarang<<endl;
                cout<<"Jumlah Buku Yang Di Pinjam   : "<<info_c(QC).jumlah<<endl;
                    }
            }
        }
    }
};

void find_relasi(){
    address_r PR;
    string pil2;
    cout<<"Masukan ID Peminjam : ";
    cin>>ID1;
    cout<<"Masukan ID Buku     : ";
    cin>>ID2;
    PR = findElm_r(LR,ID1,ID2);
    if (PR == NULL){
        cout<<"maaf list kosong \n";
    }
    else if (info_r(PR).ID == ID1 && info_r(PR).ID2 == ID2){
        cout<<"Data ditemukan ingin menampilkannya : (y/t) \n";
        cin>>pil2;
        if (pil2 == "y" || pil2 == "Y"){
            cout<<"----------"<<endl;
           cout<<"ID Peminjam      : "<<info_r(PR).ID<<endl;
            cout<<"Nama Peminjam    : "<<info_r(PR).nama<<endl;
            cout<<"Alamat Peminjam  : "<<info_r(PR).alamat<<endl;
            cout<<"      |     "<<endl;
            cout<<"      |     "<<endl;
            cout<<"      V     "<<endl;
            cout<<"ID Buku         : "<<info_r(PR).ID2<<endl;
            cout<<"Judul Buku      : "<<info_r(PR).judul<<endl;
            cout<<"Nama Pengarang  : "<<info_r(PR).pengarang<<endl;
        }
        else{

        }
    }
    else{
        cout<<"Maaf data tidak ditemukan ";
    }
}

void connectrel(){
    address_p P;
    address_c C;
    address_r PR;
    cout<<"Masukan nomor ID Peminjam: ";
    cin>>psi;
    cout<<"Masukan nomor ID Buku : ";
    cin>>buku;
    P = findElm(LP,psi);
    C = findElm_c(LC,buku);
    PR = alokasi_r(P,C);
    insertfirst(LR,PR);
};

void viewconnected()
{
    printInfo_r(LR);
};

void menu(){
    CreateList(LP);
    CreateList_c(LC);
    pil = 0;
    while(pil != 13)
    {
        cout<<"1.) Insert Parents_Peminjam \n";
        cout<<"2.) Insert Child_Buku \n";
        cout<<"3.) view Parent_Peminjam \n";
        cout<<"4.) Connecting relation\n";
        cout<<"5.) View Connected\n";
        cout<<"6.) Delete Relation\n";
        cout<<"7.) Find Relation \n";
        cout<<"8.) view Child_Buku\n";
        cout<<"9.) delete Parent_Peminjam \n";
        cout<<"10.) delete Child_Buku\n";
        cout<<"11.) Find Parent_Peminjam\n";
        cout<<"12.) Find Child_Buku\n";
        cout<<"13.) EXIT \n";
        cout<<"Masukan pilihan anda :  ";
        cin>>pil;
        switch(pil)
        {
            case 1 : insertParent_Peminjam();
                    break;
            case 2 : insertChild_Buku();
                    break;
            case 3 : viewParent_Peminjam();
                    break;
            case 4 : connectrel();
                    break;
            case 5 : viewconnected();
                    break;
            case 6 : deleterelat();
                    break;
            case 7 : find_relasi();
                    break;
            case 8 : viewChilds_Buku();
                    break;
            case 9 : deleteParent_Peminjam();
                    break;
            case 10 : deleteChild_Buku();
                    break;
            case 11 : FindParent_Peminjam();
                    break;
            case 12 : findChild_Buku();
                    break;
        };
    }
};
