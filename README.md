# Stok-Yonetim-Sistemi
C++ ile geliştirilmiş, çoklu mağaza, çalışan ve envanter yönetimini sağlayan bir mağaza yönetim sistemi. OOP prensipleri, dosya işlemleri ve renkli arayüzü özelliklerini içerir.

# C++ Konsol Tabanlı Mağaza Yönetim Sistemi

Bu proje, C++ programlama dili kullanılarak geliştirilmiş, Nesne Yönelimli Programlama (OOP) prensiplerine dayalı bir konsol uygulamasıdır. Sistem, birden çok mağazanın çalışanlarını, ürünlerini ve envanterini yönetmek için tasarlanmıştır.

## 🚀 Projenin Amacı

Bu uygulamanın temel amacı, bir perakende zincirinin veya birden çok şubesi olan bir işletmenin temel operasyonel ihtiyaçlarını karşılamaktır. Kullanıcı dostu menüler aracılığıyla mağaza, çalışan ve ürün yönetimi işlemlerinin kolayca yapılmasını sağlar.

## ✨ Temel Özellikler

- **Çoklu Mağaza Yönetimi:**
  - Sisteme yeni mağazalar ekleme, mevcut mağazaları silme veya adını değiştirme.
  - Tüm mağazaları listeleme ve işlem yapılacak mağazayı seçme.

- **Çalışan Yönetimi:**
  - Her mağazaya özel çalışan ekleme, silme ve listeleme.
  - Çalışan bilgilerini (İsim, Yaş, Departman, Sicil Numarası) yönetme.
  - Belirli bir mağazanın çalışan listesini `.txt` dosyasına aktarma.

- **Envanter ve Ürün Yönetimi:**
  - Mağazalara yeni ürünler tanımlama (Ürün Adı, Barkod, Stok, Depolama Şekli).
  - Ürün stoklarını barkod numarasına göre güncelleme.
  - Tüm ürün envanterini listeleme.
  - Belirli bir mağazanın tüm ürün stoklarını `.txt` dosyasına kaydetme.

- **Akıllı Stok Uyarı Sistemi:**
  - Ürünler listelendiğinde, stok seviyesi kritik (5'ten az) veya düşük (10'dan az) olan ürünler konsolda **renkli** olarak vurgulanır.
  - Düşük stoklu ürünlerin listesini ayrı bir `.txt` dosyasına rapor olarak kaydetme imkanı.

- **Kullanıcı Dostu Arayüz:**
  - Tüm işlemlerin menüler aracılığıyla yapıldığı, kolay anlaşılır bir konsol arayüzü.
  - Hatalı girişlere ve dosya işlemlerine karşı temel `try-catch` blokları ile hata yönetimi.

## 🛠️ Kullanılan Teknolojiler ve Kavramlar

- **Programlama Dili:** C++
- **Temel Kavramlar:**
  - Nesne Yönelimli Programlama (OOP)
  - Sınıflar (`class`) ve Nesneler (`object`)
  - Kalıtım (`inheritance`) -> `Calisanlar` sınıfından türetilen `Mudur`, `SatisDanismani` vb. sınıflar.
  - Kapsülleme (`encapsulation`)
  - Standart Şablon Kütüphanesi (STL) -> `vector`, `string`
- **Dosya İşlemleri:** `fstream` kütüphanesi ile `.txt` dosyalarına veri yazma.
- **Konsol Arayüzü:** Windows'a özel `<windows.h>` kütüphanesi ile renklendirilmiş konsol çıktıları.

## 💻 Nasıl Çalıştırılır?

1.  Projeyi klonlayın veya indirin.
2.  Bir C++ derleyicisi (örneğin g++, MinGW, Visual Studio) kullanarak `main.cpp` dosyasını derleyin.
3.  Oluşturulan `.exe` dosyasını çalıştırın.

Program, başlangıçta tanımlanmış olan örnek verilerle (mağazalar, çalışanlar, ürünler) birlikte açılacaktır. Menüler üzerinden dilediğiniz işlemi yapabilirsiniz.
