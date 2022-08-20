#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


void generuj_klucz(long long int& k_pub);
void szyfruj(string& tr, int k_publ, int czy);
void deszyfruj();
bool czy_prawidlowa(long long int);
int suma_cyfr(long long int cyfra);
int znak(char litera);

int main() {
	int czy_wygenerowano=0;
	char koniec, wybor;
	string tresc;
	long long int klucz_publiczny;
		do{
		do{
			if(koniec=='t'){
				system("CLS");
			}
			cout<<"\n\n1. Generowanie klucza.\n";
			cout<<"2. Szyfrowanie wiadomosci.\n";
			cout<<"3. Deszyfracja.\n\n";
			cin>>wybor;
		
			if(wybor=='1'){
				czy_wygenerowano=1;
				system("CLS");
				generuj_klucz(klucz_publiczny);
			}
			
			else if(wybor=='2'){
				system("CLS");
				szyfruj(tresc, klucz_publiczny, czy_wygenerowano);
			}
		
			else if(wybor=='3'){
				system("CLS");
				deszyfruj();
			}
			else{
			system("CLS");
			cout<<"\nWYBIERZ NUMER Z LISTY!\n";
			system("pause");
			system("CLS");
			}
		}while((wybor!='1')&&(wybor!='2')&&(wybor!='3'));
		
		cout<<"\n\nCzy chcesz kontynuowac? t/n\t";
		cin>>koniec;
	}while(!(koniec=='n'));
	system("CLS");
	
	return 0;
}


void generuj_klucz(long long int& k_pub){
	char czy;
	srand(time(NULL));
	do{
	k_pub=(rand()*rand()*rand()*rand()%10000000000);
	}
	while(czy_prawidlowa(k_pub)==false);
	cout<<k_pub<<endl;
	cout<<"\nCzy chcesz zapisac klucz? t/n\t";
	cin>>czy;
	if(czy=='t'){
		fstream plik;
		plik.open("klucz.txt", ios::out);
		plik<<k_pub<<endl;
		plik.close();
		cout<<"\nKlucz zostal zapisany w pliku tekstowym o nazwie klucz.\n";
	}

}
void szyfruj(string& tr, int k_publ, int czy){
	if(czy==0){
		do{
		cout<<"\nPodaj wlasny klucz (10 znakow): ";
		cin>>k_publ;
		}while(!((k_publ>=1000000000)&&(k_publ<=9999999999)));
	}
	cout<<"\nPodaj wiadomosc do zaszyfrowania bez spacji: "<<endl;
	cin>>tr;
	cout<<endl;
	int klucz[9];
	int modulo=1000000000;
	for(int i=0; i<10; i++){
		klucz[i]=(k_publ/modulo)%10;
		modulo=modulo/10;
	}
		
		int x=0;
		for(int i=0; i<tr.length(); i++){
			if(x==10){
				x=0;
			}
		int a=0;
		if(znak(tr[i])==0){
			a=(int)tr[i]+klucz[x];
				if(a>122){
					a=(97+a%122)-1;
				}
				if(a<97){
					
				}
		}
		else if(znak(tr[i])==1){
			a=(int)tr[i]+klucz[x];
				if(a>90){
					a=(65+a%90)-1;
				}
				if(a<65){
					
				}
		}
		else {
			a=(int)tr[i];
		}
		
		cout<<(char)a;
		x++;
	}

}

bool czy_prawidlowa(long long int klucz){
	if(klucz<0){
		return false;
	}
	else if(suma_cyfr(klucz)<10){
		return false;
	}
	else return true;
}

int suma_cyfr(long long int cyfra){
	int zlicz=0;
	while(cyfra!=0){
		cyfra=cyfra/10;
		zlicz++;
	}
	return zlicz;
}

int suma_cyfr_int(int cyfra){
	int zlicz=0;
	while(cyfra!=0){
		cyfra=cyfra/10;
		zlicz++;
	}
	return zlicz;
}

int znak(char litera){
	if(litera>='a'&&litera<='z'){
		return 0;
	}
	else if(litera>='A'&&litera<='Z'){
		return 1;
	}
	else return 2;
}

void deszyfruj(){
	string tresc;
	int klucz_p;
	cout<<"\nPodaj wiadomosc do odszyfrowania:\t";
	cin>>tresc;
	do{
	cout<<"\nPodaj klucz:\t";
	cin>>klucz_p;
			if(!(suma_cyfr_int(klucz_p)==10)){
			cout<<"Niepoprawny klucz! Podaj 10 cyfr."<<endl;
		}}while(!(suma_cyfr_int(klucz_p)==10));
	int klucz[9];
	int modulo=1000000000;
	for(int i=0; i<10; i++){
	klucz[i]=(klucz_p/modulo)%10;
	modulo=modulo/10;
	}
	
	int x=0;
		for(int i=0; i<tresc.length(); i++){
			if(x==10){
				x=0;
			}
		int a=0;
		if(znak(tresc[i])==0){
			a=(int)tresc[i]-klucz[x];
				if(a>122){
					a=(97-a%122)-1;
				}
					if(a<97){
						a=a;
						a=(122-(97-a))+1;
					}
		}
		else if(znak(tresc[i])==1){
			a=(int)tresc[i]-klucz[x];
				if(a>90){
					a=(65-a%90)-1;
				}
					if(a<65){
						a=a;
						a=(90-(65-a))+1;
					}
		}
		else {
			a=(int)tresc[i];
		}
		
		cout<<(char)a;
		x++;
	}
}
