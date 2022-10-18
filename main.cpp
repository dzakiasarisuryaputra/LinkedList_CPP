#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct linked{
    int dataX,dataY;
    linked *next;
};

linked *head, *tail;

int cek(){
    if(tail!=NULL){
        return 1;
    }
    else{
        return 0;
    }
}

bool cari(int nilaiX,int nilaiY){
    linked *bantu;
    bantu=head;
    int flag=0;

    if(cek()==1){
        while(bantu!=NULL){
            if((bantu->dataX==nilaiX) && (bantu->dataY==nilaiY)){
                flag=1;
            }
            bantu=bantu->next;
        }
    }
    if (flag==1){
        return true;
    }
    else {
        return false;
    }
}

void tampil(){
    linked *bantu;
    bantu = head;
    if(cek()==1){
        cout<<"===================================="<<endl;
        while (bantu!=NULL){
            cout<<"Nilai X : "<<bantu->dataX<<" ";
            cout<<"Nilai Y : "<<bantu->dataY<<endl;
            bantu = bantu->next;
        }
        cout<<"===================================="<<endl;
    }
    else{
        cout<<"Data kosong!\n";
    }
}

void tambah_depan(int x,int y){
    linked *baru;
    baru = new linked;
    baru -> dataX = x;
    baru -> dataY = y;
    baru -> next = NULL;
    if (cek()==0){
        head=tail=baru;
        tail->next=NULL;
    }
    else{
        baru->next = head;
        head=baru;
    }
    cout<<"Data Masuk!"<<endl;
}

void tambah_belakang(int x,int y){
    linked *baru;
    baru = new linked;
    baru -> dataX = x;
    baru -> dataY = y;
    baru -> next = NULL;
    if(cek()==0){
        head=tail=baru;
        tail->next=NULL;
    }
    else{
        tail -> next = baru;
        tail=baru;
    }
    cout<<"Data Masuk!"<<endl;

}

void tambah_tengah(){
    int pilihan,cariX,cariY;
    int inpX,inpY;
    linked *bantu, *baru;

    bantu = new linked;
    bantu = head;

    cout<<"1.Sebelum Data yang dipilih"<<endl;
    cout<<"2. Sesudah Data yang dipilih"<<endl;
    cin>>pilihan;

    if(pilihan==1){
        if(cek()==1){
                tampil();
                cout<<"Sebelum X yang bernilai ? ";
                cin>> cariX;
                cout<<"Sebelum Y yang bernilai ? ";
                cin>> cariY;
                if(cari(cariX,cariY)){
                    //jika data tdk di head
                    if (cariX!=head->dataX){
                        while(bantu!=NULL){
                            if((bantu->next->dataX==cariX) && (bantu->next->dataY==cariY)){
                                cout<<"Tambahkan Nilai X : ";
                                cin>>inpX;
                                cout<<"Tambahkan Nilai Y : ";
                                cin>>inpY;

                                baru = new linked;
                                baru -> dataX = inpX;
                                baru -> dataY = inpY;
                                baru -> next = bantu->next;
                                bantu -> next = baru;

                                cout<<"Data Masuk!"<<endl;

                                break;
                            }
                            else{
                                bantu = bantu->next;
                            }
                        }
                    }
                    //jika data ditemukan pada head
                    else{
                        cout<<"Tambahkan Nilai X : ";
                        cin>>inpX;
                        cout<<"Tambahkan Nilai Y : ";
                        cin>>inpY;

                        tambah_depan(inpX,inpY);
                    }
                }
                else{
                    cout<<"Data tidak ada!\n";
                }

        }

            else{
                cout<<"Data Kosong!\n";
            }
    }

    if(pilihan==2){
        if(cek()==1){
            tampil();
            cout<<"Setelah X yang bernilai ? ";
            cin>> cariX;
            cout<<"Setelah Y yang bernilai ? ";
            cin>> cariY;
            bantu = head;

            while(bantu!=NULL){
                if((bantu->dataX==cariX)&&(bantu->dataY==cariY)){
                    cout<<"Tambahkan Nilai X : ";
                    cin>>inpX;
                    cout<<"Tambahkan Nilai Y : ";
                    cin>>inpY;
                    linked *baru;
                    baru = new linked;
                    baru -> dataX = inpX;
                    baru -> dataY = inpY;
                    baru -> next = bantu->next;
                    bantu->next = baru;
                    cout<<"Data Masuk!"<<endl;
                    break;
                }
                else{
                    bantu=bantu->next;
                }
            }
            if(bantu==NULL){
                cout<<"Data tidak Ada!\n";
            }
        }
        else{
            cout<<"Data Kosong\n";
        }
    }
}

void hapus_depan(){
    linked *hapus;
    int x,y;

    if (cek()==1){

        if(head!=tail){
            hapus = head;
            x=hapus->dataX;
            y=hapus->dataY;
            head = head->next;
            delete hapus;
        }
        else{
            hapus = head;
            x = hapus->dataX;
            y = hapus->dataY;
            head=tail=NULL;
        }
        cout<<"Nilai X : "<<x<<" Nilai Y : "<<y<<" TELAH DIHAPUS!"<<endl;

    }
    else{
        cout<<"Data kosong!\n";
    }
}

void hapus_belakang(){
    linked *hapus,*bantu;
    int x,y;

    if (cek()==1){
        if(head!=tail){
            hapus = tail;
            x=hapus->dataX;
            y=hapus->dataY;

            bantu = head;
            while (bantu!=NULL){
                if((bantu->next->dataX==tail->dataX) && (bantu->next->dataY==tail->dataY)){
                    tail=bantu;
                    tail->next = NULL;
                }
                bantu = bantu->next;
            }
        }
        else{
            hapus = tail;
            x = hapus->dataX;
            y = hapus->dataY;
            head=tail=NULL;
        }
        delete hapus;
        cout<<"Nilai X : "<<x<<" Nilai Y : "<<y<<" TELAH DIHAPUS!"<<endl;

    }
    else{
        cout<<"Data kosong!\n";
    }
}

void hapus_tengah(){
    linked *hapus, *bantu;
    int xhapus,yhapus;
    bantu = head;

    cout<<"Masukkan X yang dihapus : ";
    cin>>xhapus;
    cout<<"Masukkan Y yang dihapus : ";
    cin>>yhapus;

    if(cek()==1){
        while(bantu!=NULL){
            if((bantu->next->dataX == xhapus) && (bantu->next->dataY == yhapus)){
                hapus = bantu -> next;
                bantu->next = bantu->next->next;
                delete hapus;
                break;
            }
            bantu=bantu->next;
        }
        cout<<"NIlai X : "<<xhapus<<"Nilai Y : "<<yhapus<<" TELAH DIHAPUS!"<<endl;
    }
    else{
        cout<<"Data Kosong\n";
    }

}



int main()
{

    int pil,x,y;

    do{
        system("cls");
        cout<<"===================================="<<endl;
        cout<<"PROGRAM LINKED LIST 'SEDERHANA'\n";
        cout<<" NAMA   : DZAKI ASARI SURYA PUTRA\n";
        cout<<" NIM    : A11.2021.13595\n";
        cout<<" KELAS  : A1143UG2\n";
        cout<<"===================================="<<endl;
        cout<<"1. Insert Data di Depan List\n";
        cout<<"2. Insert Data di Tengah List\n";
        cout<<"3. Insert Data di Belakang List\n";
        cout<<"4. Tampilkan Data pada List\n";
        cout<<"5. Hapus Data Bagian Depan List\n";
        cout<<"6. Hapus Data Bagian Belakang List\n";
        cout<<"7. Hapus Data Bagian Tengah List\n";
        cout<<"8. Keluar Program\n";
        cout<<"===================================="<<endl;
        cout<<"Masukkan pilihan menu (1-8) : ";
        cin>>pil;


        switch(pil){
            case 1:
                cout<<"Masukkan Nilai X untuk Insert Depan: ";
                cin>>x;
                cout<<"Masukkan Nilai Y untuk Insert Depan: ";
                cin>>y;

                tambah_depan(x,y);
                getch();
                break;

            case 2:
                tambah_tengah();
                getch();
                break;

            case 3:
                cout<<"Masukkan Nilai X untuk Insert Belakang: ";
                cin>>x;
                cout<<"Masukkan Nilai Y untuk Insert Belakang: ";
                cin>>y;

                tambah_belakang(x,y);
                getch();
                break;

            case 4 :
                tampil();
                getch();
                break;

            case 5 :
                hapus_depan();
                getch();
                break;

            case 6 :
                hapus_belakang();
                getch();
                break;

            case 7 :
                hapus_tengah();
                getch();
                break;
            default:
                cout<<"Masukkan pilihan yang tersedia!\n";
                getch();
                break;
        }
    }
    while(pil!=8);


   return 0;
}
