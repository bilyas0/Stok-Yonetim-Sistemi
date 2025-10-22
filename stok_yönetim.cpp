
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;
class Calisanlar {
	protected:
    string isim;
    int yas;
    string departman;
    int sicilNumarasi;

public:
    Calisanlar(const string& isim, int yas, const string& departman, int sicilNumarasi)
        : isim(isim), yas(yas), departman(departman), sicilNumarasi(sicilNumarasi) {}

    string GetIsim() const {
        return isim;
    }

    int GetYas() const {
        return yas;
    }

    string GetDepartman() const {
        return departman;
    }

    int GetSicilNumarasi() const {
        return sicilNumarasi;
    }

    void NotDefterineBastir(ofstream& dosya) const {
        dosya << "Isim: " << isim << ", Yas: " << yas << ", Departman: " << departman << ", Sicil Numarasi: " << sicilNumarasi << endl;
    }
};

class Mudur : public Calisanlar {
public:
    Mudur(const string& isim, int yas, int sicilNumarasi)
        : Calisanlar(isim, yas, "Mudurluk", sicilNumarasi) {}

 
};

class SatisDanismani : public Calisanlar {
public:
    SatisDanismani(const string& isim, int yas, int sicilNumarasi)
        : Calisanlar(isim, yas, "Satis Danismanligi", sicilNumarasi) {}


};

class DepoGorevlisi : public Calisanlar {
public:
    DepoGorevlisi(const string& isim, int yas, int sicilNumarasi)
        : Calisanlar(isim, yas, "Depo Gorevliligi", sicilNumarasi) {}


};

class Guvenlik : public Calisanlar {
public:
    Guvenlik(const string& isim, int yas, int sicilNumarasi)
        : Calisanlar(isim, yas, "Guvenlik", sicilNumarasi) {}


};



class Urun {
		string urunIsmi;
		string barkodNumarasi;
		int stokSayisi;
		string depolamaSekli;
		string magazaIsmi;

	public:
		Urun(const string& urun, const string& barkod, int stok, const string& depolama, const string& magaza)
			: urunIsmi(urun), barkodNumarasi(barkod), stokSayisi(stok), depolamaSekli(depolama), magazaIsmi(magaza) {}

		string GetUrunIsmi() const {
			return urunIsmi;
		}

		string GetBarkodNumarasi() const {
			return barkodNumarasi;
		}

		int GetStokSayisi() const {
			return stokSayisi;
		}

		string GetDepolamaSekli() const {
			return depolamaSekli;
		}

		string GetMagazaIsmi() const {
			return magazaIsmi;
		}

		void SetStokSayisi(int yeniStok) {
			stokSayisi = yeniStok;
		}

};
class Magaza {
	public:
		string magazaIsmi;
		vector<Calisanlar> personel;
		vector<Urun> urunler; // Urun vektörü eklendi

		Magaza(const string& isim) : magazaIsmi(isim) {}
		void UrunleriListele() const {
			int secim;
			if (urunler.empty()) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // Kırmızı renk
				cout << "Magazada mevcut urun bulunmamaktadir." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
			} else {
				// Başlık satırını yazdır
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Mavi renk
				cout << setw(20) << left << "Urun Ismi" << setw(15) << left << "Barkod Numarasi" << setw(10) << left << "Stok" << setw(20) << left << "Depolama Sekli" << setw(15) << left << "Magaza Ismi" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

				// Her ürün için bilgileri yazdır
				for (const auto& urun : urunler) {
					// Eğer stok 5'in altındaysa kırmızı ile yazdır
					if (urun.GetStokSayisi() < 5) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kırmızı renk
						cout << setw(20) << left << urun.GetUrunIsmi() << setw(15) << left << urun.GetBarkodNumarasi() << setw(10) << left << urun.GetStokSayisi() << setw(20) << left << urun.GetDepolamaSekli() << setw(15) << left << urun.GetMagazaIsmi() << " (Kritik Stok)" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
					} else if (urun.GetStokSayisi() >= 5 && urun.GetStokSayisi() <= 10) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Sarı renk
						cout << setw(20) << left << urun.GetUrunIsmi() << setw(15) << left << urun.GetBarkodNumarasi() << setw(10) << left << urun.GetStokSayisi() << setw(20) << left << urun.GetDepolamaSekli() << setw(15) << left << urun.GetMagazaIsmi() << " (Dusuk Stok)" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
					} else {
						cout << setw(20) << left << urun.GetUrunIsmi() << setw(15) << left << urun.GetBarkodNumarasi() << setw(10) << left << urun.GetStokSayisi() << setw(20) << left << urun.GetDepolamaSekli() << setw(15) << left << urun.GetMagazaIsmi() << endl;
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
			cout <<endl<<"Azalan stoklu urunler not defterine kaydedilsin mi?"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
			cout<<"1-)Evet"<<endl<<"2-)Hayir"<<endl;


			cin>>secim;
        // Düşük stoklu ürünleri not defterine kaydetme işlemi
        if (secim == 1) {
		
        try {
            ofstream dosya(magazaIsmi + "_Azalan_stoklu_urunler.txt"); // Dosyayı "dusuk_stoklu_urunler.txt" adıyla oluştur ve ekleme modunda aç
            if (dosya.is_open()) {
                dosya << "Kritik Stoklu Ürünler:" << endl;
                for (const auto& urun : urunler) {
                    if (urun.GetStokSayisi() < 5) {
                        dosya << "Ürün İsmi: " << urun.GetUrunIsmi() << ", Barkod Numarası: " << urun.GetBarkodNumarasi() << ", Stok: " << urun.GetStokSayisi() << ", Depolama Şekli: " << urun.GetDepolamaSekli() << ", Mağaza İsmi: " << urun.GetMagazaIsmi() << endl;
                    }
                }
                dosya << "Düşük Stoklu Ürünler:" << endl;
                for (const auto& urun : urunler) {
                    if (urun.GetStokSayisi() >= 5 && urun.GetStokSayisi() <= 10) {
                        dosya << "Ürün İsmi: " << urun.GetUrunIsmi() << ", Barkod Numarası: " << urun.GetBarkodNumarasi() << ", Stok: " << urun.GetStokSayisi() << ", Depolama Şekli: " << urun.GetDepolamaSekli() << ", Mağaza İsmi: " << urun.GetMagazaIsmi() << endl;
                    }
                }
                
                dosya.close(); // Dosyayı kapat
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yeşil renk
                cout << "Azalan stoklu urunler basariyla kaydedildi." << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
            } else {
                throw 404;
            }
        } catch (int hatakod) {
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kırmızı renk
				cout << "Hata: Dosya acilamadi " << endl;
				cout << "Hata kodu : " << hatakod;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
            
        }
    }
			

			else if(secim==2) {

			} else {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kırmızı renk

				cout<<"Hatali tuslama yapildi"<<endl;
														SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

			}
		}

		void CalisanlarListele() const {
			if (personel.empty()) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // kirmizi renk
				cout << "Magazada calisan bulunmamaktadir." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Beyaz renk
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Mavi renk
				cout << setw(15) << left << "Isim" << setw(10) << left << "Yas" << setw(20) << left << "Departman" << setw(20) << left << "Sicil Numarasi" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Beyaz renk
				for (const auto& calisan : personel) {
					cout << setw(15) << left << calisan.GetIsim() << setw(10) << left << calisan.GetYas() << setw(20) << left << calisan.GetDepartman() << setw(20) << left << calisan.GetSicilNumarasi() << endl;
				}
			}
		}

	void UrunStoklariniNotDefterineBastir() const {
			
			try {
				ofstream dosya(magazaIsmi + "_Urun_Stoklari.txt");
				if (!dosya.is_open()) {
					throw 405;
				}

				dosya << "Urun Stoklari:" << endl;
				dosya << magazaIsmi << " Magazasinin Urun Stoklari:" << endl;
				for (const auto& urun : urunler) {
					dosya << "Urun Ismi: " << urun.GetUrunIsmi() << ", Barkod Numarasi: " << urun.GetBarkodNumarasi()
					      << ", Stok Sayisi: " << urun.GetStokSayisi() << ", Depolama Sekli: " << urun.GetDepolamaSekli()
					      << ", Magaza Ismi: " << urun.GetMagazaIsmi() << endl;
				}
				dosya << endl;
				dosya.close();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
				cout << magazaIsmi << " magazasinin urun stoklari not defterine basariyla bastirildi." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

			} catch (int hatakod) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kırmızı renk
				cout << "Hata: Dosya acilamadi " << endl;
				cout << "Hata kodu : " << hatakod;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
			}
		}

		void CalisanEkle(const Calisanlar& calisan) {
			personel.push_back(calisan);
		}

		void CalisanSil(const string& calisanIsim) {
			for (auto it = personel.begin(); it != personel.end(); ++it) {
				if (it->GetIsim() == calisanIsim) {
					personel.erase(it);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
					cout << calisanIsim << " isimli calisan silindi." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
					return;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // kirmizi renk
			cout << "Hata: " << calisanIsim << " isimli calisan bulunamadi." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
		}

};

class MagazaYonetimi {
	public:
		vector<Magaza> magazalar;

		void UrunleriListele(size_t index) {
			magazalar[index].UrunleriListele();
		}

		void UrunTanimla(const string& magazaIsmi, const Urun& urun) {
			for (auto& magaza : magazalar) {
				if (magaza.magazaIsmi == magazaIsmi) {
					
					magaza.urunler.push_back(urun);
					return;
				}
			}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // kirmizi renk

			cerr << "Hata: " << magazaIsmi << " isimli magaza bulunamadi." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

		}

		void UrunEkle(const string& magazaIsmi, const Urun& urun) {
			for (auto& magaza : magazalar) {
				if (magaza.magazaIsmi == magazaIsmi) {
					magaza.urunler.push_back(urun);
					return;
				}
			}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // kirmizi renk

			cerr << "Hata: " << magazaIsmi << " isimli magaza bulunamadi." << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

		}

		void UrunStokGuncelle(const string& magazaIsmi, const string& barkod, int yeniStok) {
			for (auto& magaza : magazalar) {
				if (magaza.magazaIsmi == magazaIsmi) {
					for (auto& urun : magaza.urunler) {
						if (urun.GetBarkodNumarasi() == barkod) {
							urun.SetStokSayisi(yeniStok);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk

							cout<< "Stok guncellendi. Yeni stok sayisi: " << yeniStok << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

							return;
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // kirmizi renk

					cerr << "Hata: " << barkod << " barkod numarasina sahip urun bulunamadi." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					return;
				}
			}
			cerr << "Hata: " << magazaIsmi << " isimli magaza bulunamadi." << endl;
		}

		void YeniUrunEkle(const string& magazaIsmi, const Urun& urun) {
			for (auto& magaza : magazalar) {
				if (magaza.magazaIsmi == magazaIsmi) {
					magaza.urunler.push_back(urun);
					return;
				}
			}
			cerr << "Hata: " << magazaIsmi << " isimli magaza bulunamadi." << endl;
		}

		void MagazalariListele() const {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk
			cout << "Kayitli Magazalar:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
			for (size_t i = 0; i < magazalar.size(); ++i) {
				cout << i + 1 << "-) " << magazalar[i].magazaIsmi << endl;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // kirmizi renk
			cout << "-1-) Magaza Ekle" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // kirmizi renk

			cout << "-2-) Magaza Sil" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

		}

		void MagazaEkle(const string& isim) {
			magazalar.push_back(Magaza(isim));
		}

		void CalisanEkle(const string& magazaIsmi, const Calisanlar& calisan) {
			for (auto& magaza : magazalar) {
				if (magaza.magazaIsmi == magazaIsmi) {
					magaza.CalisanEkle(calisan);
					return;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk
			cout << "Hata: " << magazaIsmi << " isimli magaza bulunamadi." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
		}

		void menu() {
			vector<string> gecmis; // Kullanıcı seçim geçmişi

			while (true) {
				int secim;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // sari renk
				cout << "TEKNO Magazacilik yonetim programina hosgeldiniz" << endl;
				cout << "Lutfen islem yapmak istediginiz magazayi seciniz" << endl;
				MagazalariListele();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

				cout << "Seciminizi girin (Cikis icin 0'i girin): ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

				cin >> secim;
				system("cls"); // Windows için
				// programı kapatma
				if (secim == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
					cout << "Programdan cikis yapiliyor..." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					return;
				}
				// magaza ekle
				if (secim == -1) {
					string magazaIsmi;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

					cout << "Eklemek istediginiz magazanin ismini girin: ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					cin >> magazaIsmi;
					MagazaEkle(magazaIsmi);
					continue;
				}
				// magaza sil
				if (secim == -2) {
					string input;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

					cout << "Silmek istediginiz magazanin numarasini girin: ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					cin >> input;

					// Kontrol ediliyor
					if (input.find_first_not_of("0123456789") == string::npos) {
						// Tam sayıya dönüştürme işlemi
						int magazaIndex = stoi(input);

						if (magazaIndex >= 1 && magazaIndex <= magazalar.size()) {
							magazalar.erase(magazalar.begin() + magazaIndex - 1);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk

							cout << "Magaza basariyla silindi." << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

						} else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk
							cout << "Gecersiz magaza numarasi." << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

						}
					} else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk

						cout << "Gecersiz giris. Lutfen bir tam sayi girin." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					}
					continue;
				}
				// hatali secim
				if (secim < 1 || secim > magazalar.size()) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk
					cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

					continue;
				}

				string secilenMagaza = magazalar[secim - 1].magazaIsmi;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
				cout << "Secilen magaza: " << secilenMagaza << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz
				gecmis.push_back(secilenMagaza); // Seçim geçmişine ekle


				MagazaIslemMenu(secim - 1);
			}
		}

		void MagazaIslemMenu(size_t index) {
			int secim;
			string calisanIsmi;
			int calisanYasi;
			string calisanDepartmani;
			int calisanSicilNumarasi;
			string hedefMagazaIsmi;
			size_t hedefMagazaIndex;

			while (true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk
				cout << "Yapmak istediginiz islemi seciniz:" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz
				cout << "1-) Calisan islemleri" << endl;
				cout << "2-) Urun islemleri" << endl;
				cout << "3-) Magaza islemleri" << endl;
				cout << "4-) Geri git" << endl; // Geri gitme seçeneği
				cout << "5-) Cikis" << endl; // Çıkış seçeneği
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

				cout << "Seciminizi girin: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

				cin >> secim;
				system("cls"); // Windows için
				if (secim == 4) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
					cout << "Ana menuye donuluyor..." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
					return;
				}

				switch (secim) {
					case 1:
						// Calisan işlemleri menüsünü çağır
						CalisanIslemleriMenu(index);
						break;
					case 2:
						// Ürün İşlemleri Menüsü
						while (true) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
							cout << "Urun Islemleri Menu:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
							cout << "1-) Magazadaki mevcut urunleri listele" << endl;
							cout << "2-) Magazaya urun ekle" << endl;
							cout << "3-) Magazadaki urunun stok miktarini guncelle" << endl;
							cout << "4-) Magazadaki urun stoklarini not defterine bastir" << endl;
							cout << "0-) Ana menuye don" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
							cout << "Seciminizi girin: ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

							cin >> secim;
							// Ana menu
							if (secim == 0) {
											system("cls"); // Windows için
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yeşil renk
								cout << "Ana menuye donuluyor..." << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
								break;
							}

							switch (secim) {
								// Magazadaki mevcut ürünleri listele
								case 1:
									UrunleriListele(index);
									break;
								// Yeni ürün ekleme
								case 2: {

									string urunIsmi, barkodNumarasi, depolamaSekli, magazaIsmi;
									int stokSayisi;

									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
									cout << "Yeni urunun bilgilerini girin:" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Urun ismi: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									cin.ignore(); // Önceki girişten gelen newline karakterini temizle
									getline(cin, urunIsmi);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Barkod numarasi: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									getline(cin, barkodNumarasi);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Stok sayisi: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									cin >> stokSayisi;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Depolama sekli: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									cin.ignore(); // Önceki girişten gelen newline karakterini temizle
									getline(cin, depolamaSekli);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Magaza ismi: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									getline(cin, magazaIsmi);

									// Yeni ürünü oluştur
									Urun yeniUrun(urunIsmi, barkodNumarasi, stokSayisi, depolamaSekli, magazaIsmi);

									// Magazaya yeni ürün ekle
									YeniUrunEkle(magazaIsmi, yeniUrun);
									break;
								}
								// Magazadaki urunun stok miktarini guncelle
								case 3: {

									string barkod;
									int yeniStok;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Guncellemek istediginiz urunun barkod numarasini girin: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk


									cin >> barkod;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk

									cout << "Yeni stok miktarini girin: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

									cin >> yeniStok;

									UrunStokGuncelle(magazalar[index].magazaIsmi, barkod, yeniStok);
									break;
								}
								// Magazadaki ürün stoklarını not defterine bastır
								case 4: {
									magazalar[index].UrunStoklariniNotDefterineBastir();
									break;
								}
							}

						}
						break;

					case 3:
						// Mağaza İşlemleri Menüsü
						while (true) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
							cout << "Magaza Islemleri Menu:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
							cout << "1-) Magaza adini degistir" << endl;
							cout << "2-) Magazayi sil" << endl;
							cout << "0-) Ana menuye don" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
							cout << "Seciminizi girin: ";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

							cin >> secim;
							system("cls"); // Windows için

							if (secim == 0) {
											system("cls"); // Windows için
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yeşil renk
								cout << "Ana menuye donuluyor..." << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
								break;
							}

							switch (secim) {
								case 1:
									// Mağaza adını değiştir
								{
									string yeniIsim;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // Sarı renk
									cout << "Yeni magaza adini girin: ";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
									cin.ignore(); // Önceki girişten kalan newline karakterini temizle
									getline(cin, yeniIsim); // Yeni mağaza adını al
									magazalar[index].magazaIsmi = yeniIsim; // Mağaza adını güncelle
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yeşil renk
									cout << "Magaza adi basariyla guncellendi." << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
								}
								break;
								case 2:
									// Mağazayı sil
								{
									magazalar.erase(magazalar.begin() + index); // Mağazayı vektörden sil
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yeşil renk
									cout << "Magaza basariyla silindi." << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
									return; // Ana menüye geri dön
								}
								break;
								default:
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // Kırmızı renk
									cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
							}
						}
						break;

					case 5:
						// Çıkış işlemi
						exit(0);
					default:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk

						cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
				}
			}
		}

		void CalisanIslemleriMenu(size_t index) {
			int secim;
			string calisanIsmi;
			int calisanYasi;
			string calisanDepartmani;
			int calisanSicilNumarasi;
			string hedefMagazaIsmi;
			size_t hedefMagazaIndex;

			while (true) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk
				cout << "Calisan Islemleri Menu:" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz
				cout << "1-) Calisanlari listele" << endl;
				cout << "2-) Calisan ekle" << endl;
				cout << "3-) Calisan sil" << endl;
				cout << "4-) Calisanlari not defterine bastir" << endl; // Yeni eklenen seçenek
				cout << "0-) Ana menuye don" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

				cout << "Seciminizi girin: ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

				cin >> secim;


				if (secim == 0) {
									system("cls"); // Windows için
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
					cout << "Ana menuye donuluyor..." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
					return;
				}

				switch (secim) {
					case 1:
						magazalar[index].CalisanlarListele();
						break;
					case 2:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk

						cout << "Calisan ismini girin: ";
						cin >> calisanIsmi;

						cout << "Calisan yasini girin: ";
						cin >> calisanYasi;
						cout << "Calisan departmanini girin: ";
						cin >> calisanDepartmani;
						cout << "Calisan sicil numarasini girin: ";
						cin >> calisanSicilNumarasi;
						magazalar[index].CalisanEkle(Calisanlar(calisanIsmi, calisanYasi, calisanDepartmani, calisanSicilNumarasi));
						break;
					case 3:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // sari renk
						cout << "Silmek istediginiz calisanin ismini girin: ";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

						cin >> calisanIsmi;
						magazalar[index].CalisanSil(calisanIsmi);
						break;

				case 4: {
						
						try {
							ofstream dosya(magazalar[index].magazaIsmi + "_Calisanlar.txt");     //yukarıdaki gibi magazalar[index].magazaIsmi yerine magzaIsmi yazilabir
							if (!dosya.is_open()) {
								throw 406;
							}

							dosya << "Calisanlar:" << endl;
							dosya << magazalar[index].magazaIsmi << " Magazasi Calisanlari:" << endl; //magza isimi yazilabiri
							for (const auto& calisan : magazalar[index].personel) {
								calisan.NotDefterineBastir(dosya);
							}
							dosya << endl;
							dosya.close();
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // yesil renk
							cout << magazalar[index].magazaIsmi << " magazasinin calisanlari not defterine basariyla bastirildi." << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk

						} catch (int hatakod) {
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kırmızı renk
					cout << "Hata: Dosya acilamadi " << endl;
					cout << "Hata kodu : " << hatakod;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
						}
					}
					break;

					default:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // kirmizi renk
						cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Normal beyaz renk
				}
			}
				}
			
		
};

int main() {
	try {
		MagazaYonetimi yonetim;

		// Magazalara ekleme
		{
			yonetim.MagazaEkle("Mavi Mart");
			yonetim.MagazaEkle("Zirve Alisveris");
			yonetim.MagazaEkle("Gunes Pazarlama");
			yonetim.MagazaEkle("Ay Yildiz Giyim");

		}

		//calisanlar

		{
yonetim.CalisanEkle("Mavi Mart", SatisDanismani("Ayse", 30, 2001));
yonetim.CalisanEkle("Mavi Mart", DepoGorevlisi("Mehmet", 25, 3001));
yonetim.CalisanEkle("Mavi Mart", Guvenlik("Ali", 35, 4001));
yonetim.CalisanEkle("Mavi Mart", Mudur("Ahmet", 40, 1001));



yonetim.CalisanEkle("Zirve Alisveris", SatisDanismani("Ali", 21, 253401));
yonetim.CalisanEkle("Zirve Alisveris", DepoGorevlisi("Zeynep", 25, 2342));
yonetim.CalisanEkle("Zirve Alisveris", Guvenlik("Eren", 19, 13123));
yonetim.CalisanEkle("Zirve Alisveris", Mudur("Selin", 40, 123));



yonetim.CalisanEkle("Gunes Pazarlama", SatisDanismani("Neslihan", 26, 223401));
yonetim.CalisanEkle("Gunes Pazarlama", DepoGorevlisi("Burak", 25, 30234321));
yonetim.CalisanEkle("Gunes Pazarlama", Guvenlik("Zeynep", 19, 234324));
yonetim.CalisanEkle("Gunes Pazarlama", Mudur("Yusuf", 21, 10234));




yonetim.CalisanEkle("Ay Yildiz Giyim", SatisDanismani("Omer", 36, 12323));
yonetim.CalisanEkle("Ay Yildiz Giyim", DepoGorevlisi("Kazim", 55, 6456));
yonetim.CalisanEkle("Ay Yildiz Giyim", Guvenlik("Umut", 25, 2342));
yonetim.CalisanEkle("Ay Yildiz Giyim", Mudur("Bekir", 30, 34234));


yonetim.UrunTanimla("Mavi Mart", Urun("Tisort", "123456", 50, "Askida", "Mavi Mart"));
yonetim.UrunTanimla("Mavi Mart", Urun("kalem", "12334", 4, "kistasiye reyonu", "Mavi Mart"));
yonetim.UrunTanimla("Mavi Mart", Urun("silgi", "56453", 8, "kistasiye reyonu", "Mavi Mart"));
yonetim.UrunTanimla("Mavi Mart", Urun("Canta", "785643", 20, "Raflarda", "Mavi Mart"));
yonetim.UrunTanimla("Mavi Mart", Urun("Cuzdan", "986754", 15, "Raflarda", "Mavi Mart"));

yonetim.UrunTanimla("Zirve Alisveris", Urun("Ayakkabı", "789012", 30, "Raflarda", "Zirve Alisveris"));
yonetim.UrunTanimla("Zirve Alisveris", Urun("Canta", "543267", 25, "Askida", "Zirve Alisveris"));
yonetim.UrunTanimla("Zirve Alisveris", Urun("Cuzdan", "876543", 18, "Askida", "Zirve Alisveris"));
yonetim.UrunTanimla("Zirve Alisveris", Urun("Kemer", "345623", 10, "Raflarda", "Zirve Alisveris"));
yonetim.UrunTanimla("Zirve Alisveris", Urun("Gomlek", "321456", 1, "Askida", "Zirve Alisveris"));

yonetim.UrunTanimla("Gunes Pazarlama", Urun("Cep Telefonu", "345678", 20, "Vitrinde", "Gunes Pazarlama"));
yonetim.UrunTanimla("Gunes Pazarlama", Urun("Laptop", "789012", 10, "Vitrinde", "Gunes Pazarlama"));
yonetim.UrunTanimla("Gunes Pazarlama", Urun("Tablet", "987654", 15, "Vitrinde", "Gunes Pazarlama"));
yonetim.UrunTanimla("Gunes Pazarlama", Urun("Kulaklık", "654321", 30, "Vitrinde", "Gunes Pazarlama"));
yonetim.UrunTanimla("Gunes Pazarlama", Urun("Hoparlor", "876543", 25, "Vitrinde", "Gunes Pazarlama"));

yonetim.UrunTanimla("Ay Yildiz Giyim", Urun("Pantolon", "901234", 40, "Askıda", "Ay Yildiz Giyim"));
yonetim.UrunTanimla("Ay Yildiz Giyim", Urun("Gomlek", "543219", 35, "Askıda", "Ay Yildiz Giyim"));
yonetim.UrunTanimla("Ay Yildiz Giyim", Urun("Elbise", "876543", 10, "Askıda", "Ay Yildiz Giyim"));
yonetim.UrunTanimla("Ay Yildiz Giyim", Urun("Ceket", "345678", 3, "Askıda", "Ay Yildiz Giyim"));
yonetim.UrunTanimla("Ay Yildiz Giyim", Urun("Ayakkabı", "789012", 9, "Raflarda", "Ay Yildiz Giyim"));


			

		}
	
		// Yönetim menüsünü başlat
		yonetim.menu();

	} catch (...) {
		cout << "Hata:Bilinmeyen bir hata olustu. " << endl;
	}

	return 0;
}