#include <iostream>

using namespace std;

struct emosi{
    double nilaiemosi;
    string tipeemosi;
};

struct provokasi{
    double nilaiprovokasi;
    string tipeprovokasi;
};

struct hasil{
    double nilai;
    string tipe;
};

double garisdown (double batasaatas, double batasbawah, double nilai){
    double atas = batasbawah - nilai;
    double bawah =  batasbawah - batasaatas;
    return atas/bawah;
}

double garisup (double batasatas, double batasbawah, double nilai){
    double atas = nilai - batasatas;
    double bawah = batasbawah - batasatas;
    return atas/bawah;
}

double findminimum (emosi Emosi, provokasi Provokasi) {
    if (Emosi.nilaiemosi<Provokasi.nilaiprovokasi){
        return Emosi.nilaiemosi;
        }
    else {
        return Provokasi.nilaiprovokasi;
    }
}

void grafikemosi (double nilaiEmosi, emosi Emosi[]){
    if (nilaiEmosi <=15){
        Emosi[0].nilaiemosi = 1;
        Emosi[0].tipeemosi = "tidak";
        Emosi[1].nilaiemosi = 0;
        Emosi[1].tipeemosi = "";
    }
    else if ((nilaiEmosi ==35)){
        Emosi[0].nilaiemosi = 1;
        Emosi[0].tipeemosi = "sedikit";
        Emosi[1].nilaiemosi = 0;
        Emosi[1].tipeemosi = "";
    }
    else if ((nilaiEmosi == 65)){
        Emosi[0].nilaiemosi = 1;
        Emosi[0].tipeemosi = "lumayan";
        Emosi[1].nilaiemosi = 0;
        Emosi[1].tipeemosi = "";
    }
    else if ((nilaiEmosi >= 85) && (nilaiEmosi <=100)){
        Emosi[0].nilaiemosi = 1;
        Emosi[0].tipeemosi = "sangat";
        Emosi[1].nilaiemosi = 0;
        Emosi[1].tipeemosi = "";
    }
    else if ((nilaiEmosi > 15) && (nilaiEmosi < 35)){
        Emosi[0].nilaiemosi = garisdown(15,35,nilaiEmosi);
        Emosi[0].tipeemosi = "tidak";
        Emosi[1].nilaiemosi = garisup(15,35,nilaiEmosi);
        Emosi[1].tipeemosi = "sedikit";
    }
    else if ((nilaiEmosi > 35) && (nilaiEmosi < 65)){
        Emosi[0].nilaiemosi = garisdown(35,65,nilaiEmosi);
        Emosi[0].tipeemosi = "sedikit";
        Emosi[1].nilaiemosi = garisup(35,65,nilaiEmosi);
        Emosi[1].tipeemosi = "lumayan";
    }
    else if ((nilaiEmosi > 65) && (nilaiEmosi < 85)){
        Emosi[0].nilaiemosi = garisdown(65,85,nilaiEmosi);
        Emosi[0].tipeemosi = "lumayan";
        Emosi[1].nilaiemosi = garisup(65,85,nilaiEmosi);
        Emosi[1].tipeemosi = "sangat";
    }
}

void grafikprovokasi (double nilaiProvokasi, provokasi Provokasi[]){
    if (nilaiProvokasi <=15){
        Provokasi[0].nilaiprovokasi = 1;
        Provokasi[0].tipeprovokasi = "tidak";
        Provokasi[1].nilaiprovokasi = 0;
        Provokasi[1].tipeprovokasi = "";
    }
    else if ((nilaiProvokasi == 35)){
        Provokasi[0].nilaiprovokasi = 1;
        Provokasi[0].tipeprovokasi = "sedikit";
        Provokasi[1].nilaiprovokasi = 0;
        Provokasi[1].tipeprovokasi = "";
    }
    else if ((nilaiProvokasi ==65)){
        Provokasi[0].nilaiprovokasi = 1;
        Provokasi[0].tipeprovokasi = "lumayan";
        Provokasi[1].nilaiprovokasi = 0;
        Provokasi[1].tipeprovokasi = "";
    }
    else if ((nilaiProvokasi >= 87) && (nilaiProvokasi <=100)){
        Provokasi[0].nilaiprovokasi = 1;
        Provokasi[0].tipeprovokasi = "sangat";
        Provokasi[1].nilaiprovokasi = 0;
        Provokasi[1].tipeprovokasi = "";
    }
    else if ((nilaiProvokasi > 15) && (nilaiProvokasi < 35)){
        Provokasi[0].nilaiprovokasi = garisdown(15,35,nilaiProvokasi);
        Provokasi[0].tipeprovokasi = "tidak";
        Provokasi[1].nilaiprovokasi = garisup(15,35,nilaiProvokasi);
        Provokasi[1].tipeprovokasi = "sedikit";
    }
    else if ((nilaiProvokasi > 35) && (nilaiProvokasi < 65)){
        Provokasi[0].nilaiprovokasi = garisdown(35,65,nilaiProvokasi);
        Provokasi[0].tipeprovokasi = "sedikit";
        Provokasi[1].nilaiprovokasi = garisup(35,65,nilaiProvokasi);
        Provokasi[1].tipeprovokasi = "lumayan";
    }
    else if ((nilaiProvokasi > 65) && (nilaiProvokasi < 87)){
        Provokasi[0].nilaiprovokasi = garisdown(65,87,nilaiProvokasi);
        Provokasi[0].tipeprovokasi = "lumayan";
        Provokasi[1].nilaiprovokasi = garisup(65,87,nilaiProvokasi);
        Provokasi[1].tipeprovokasi = "sangat";
    }
}

void inference (emosi Emosi[], provokasi Provokasi[], hasil Hasil[]){
    int i=0;
    int j;
    while (i<2){
        j= 0;
        while (j<2){
            if ((Emosi[i].tipeemosi == "tidak") && (Provokasi[j].tipeprovokasi=="tidak")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[0].nilai)
                    Hasil[0].nilai = findminimum(Emosi[i], Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "tidak") && (Provokasi[j].tipeprovokasi== "sedikit")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[0].nilai)
                    Hasil[0].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "tidak") && (Provokasi[j].tipeprovokasi== "lumayan")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "tidak") && (Provokasi[j].tipeprovokasi== "sangat")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sedikit") && (Provokasi[j].tipeprovokasi== "tidak")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[0].nilai)
                    Hasil[0].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sedikit") && (Provokasi[j].tipeprovokasi== "sedikit")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[0].nilai)
                    Hasil[0].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sedikit") && (Provokasi[j].tipeprovokasi== "lumayan")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sedikit") && (Provokasi[j].tipeprovokasi== "sangat")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "lumayan") && (Provokasi[j].tipeprovokasi== "tidak")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "lumayan") && (Provokasi[j].tipeprovokasi== "sedikit")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "lumayan") && (Provokasi[j].tipeprovokasi== "lumayan")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "lumayan") && (Provokasi[j].tipeprovokasi== "sangat")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sangat") && (Provokasi[j].tipeprovokasi== "tidak")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sangat") && (Provokasi[j].tipeprovokasi== "sedikit")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[1].nilai)
                    Hasil[1].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sangat") && (Provokasi[j].tipeprovokasi== "lumayan")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            else if ((Emosi[i].tipeemosi == "sangat") && (Provokasi[j].tipeprovokasi== "sangat")){
                if (findminimum(Emosi[i],Provokasi[j])>Hasil[2].nilai)
                    Hasil[2].nilai = findminimum(Emosi[i],Provokasi[j]);
            }
            j++;
        }
        i++;
    }
}

void yestar (hasil Hasil[]){
    double total = 0.0;
    total += Hasil[0].nilai*30;
    total += Hasil[1].nilai*60;
    total += Hasil[2].nilai*80;
    double totalmiu = Hasil[0].nilai +Hasil[1].nilai + Hasil[2].nilai;
    double hasilakhir = (total/totalmiu);
    if (hasilakhir >=78.15){
        cout << ", Hasil: hoax"<<endl;
    } else {
       cout << ", Hasil: tidak hoax"<<endl;
    }
}

void hasilakhir (int a, int b, emosi Emosi[], provokasi Provokasi[], hasil Hasil[], int &ab) {
    Emosi[0].nilaiemosi =0;
    Emosi[0].tipeemosi ="";
    Emosi[1].nilaiemosi =0;
    Emosi[1].tipeemosi ="";

    Provokasi[0].nilaiprovokasi =0;
    Provokasi[0].tipeprovokasi ="";
    Provokasi[1].nilaiprovokasi =0;
    Provokasi[1].tipeprovokasi ="";

    Hasil[0].tipe = "tidak";
    Hasil[0].nilai = 0;
    Hasil[1].tipe = "sedang";
    Hasil[1].nilai = 0;
    Hasil[2].tipe = "sangat";
    Hasil[2].nilai = 0;
    grafikemosi(a,Emosi);
    grafikprovokasi(b,Provokasi);
    inference(Emosi,Provokasi,Hasil);

    cout<<ab<<". ";
    ab++;
    cout << "Emosi : " <<a<<", Provokasi : "<<b;
    yestar(Hasil);
}

int main()
{
    emosi Emosi[2];
    provokasi Provokasi[2];
    hasil Hasil[3];
    int ab=1;
    hasilakhir(97,74,Emosi, Provokasi, Hasil, ab);
    hasilakhir(36,85,Emosi, Provokasi, Hasil, ab);
    hasilakhir(63,43,Emosi, Provokasi, Hasil, ab);
    hasilakhir(82,90,Emosi, Provokasi, Hasil, ab);
    hasilakhir(71,25,Emosi, Provokasi, Hasil, ab);
    hasilakhir(79,81,Emosi, Provokasi, Hasil, ab);
    hasilakhir(55,62,Emosi, Provokasi, Hasil, ab);
    hasilakhir(57,45,Emosi, Provokasi, Hasil, ab);
    hasilakhir(40,65,Emosi, Provokasi, Hasil, ab);
    hasilakhir(57,45,Emosi, Provokasi, Hasil, ab);
    hasilakhir(77,70,Emosi, Provokasi, Hasil, ab);
    hasilakhir(68,75,Emosi, Provokasi, Hasil, ab);
    hasilakhir(60,70,Emosi, Provokasi, Hasil, ab);
    hasilakhir(82,90,Emosi, Provokasi, Hasil, ab);
    hasilakhir(40,85,Emosi, Provokasi, Hasil, ab);
    hasilakhir(80,68,Emosi, Provokasi, Hasil, ab);
    hasilakhir(60,72,Emosi, Provokasi, Hasil, ab);
    hasilakhir(50,95,Emosi, Provokasi, Hasil, ab);
    hasilakhir(100,18,Emosi, Provokasi, Hasil, ab);
    hasilakhir(11,99,Emosi, Provokasi, Hasil, ab);
    hasilakhir(58,63,Emosi, Provokasi, Hasil, ab);
    hasilakhir(68,70,Emosi, Provokasi, Hasil, ab);
    hasilakhir(64,66,Emosi, Provokasi, Hasil, ab);
    hasilakhir(57,77,Emosi, Provokasi, Hasil, ab);
    hasilakhir(77,55,Emosi, Provokasi, Hasil, ab);
    hasilakhir(98,64,Emosi, Provokasi, Hasil, ab);
    hasilakhir(91,59,Emosi, Provokasi, Hasil, ab);
    hasilakhir(50,95,Emosi, Provokasi, Hasil, ab);
    hasilakhir(95,55,Emosi, Provokasi, Hasil, ab);
    hasilakhir(27,79,Emosi, Provokasi, Hasil, ab);
}
