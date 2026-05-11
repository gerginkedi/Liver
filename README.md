# Terminal RPG

C++ ile geliştirilmiş terminal tabanlı rol yapma oyunu. OOP dönem projesi.

## Derleme

Visual Studio'da projeyi açıp derle. Harici bağımlılık yok.

## Oynanış

```
Yeni Oyun → Karakter ismi gir → Stat dağılımı yap → Ana Menü
```

**Stat Dağılımı**
- 27 buy point ile 5 stat arasında dağıtım: Will, Strength, Dexterity, Constitution, Charisma
- Her stat başlangıç değeri: 8 — minimum: 0, maksimum: 16
- Negatif değer girerek puanı geri alabilirsin (örn. `-3`)

**Bölgeler**
| Bölge | İçerik |
|-------|--------|
| Köy | Dinlenme (tam HP), Dükkan |
| Mağara | Seviyeye göre rastgele düşman |
| Ormanlık | Seviyeye göre rastgele düşman |

**Savaş**
- D20 zar mekaniği, sıra tabanlı
- Hasar = zar + silah saldırı puanı
- Savunma = düşman hasarı − zırh puanı

## Kayıt Sistemi

Ana menüden `4. Save` ile `save.txt` dosyasına kaydedilir.  
Başlangıç ekranından `2. Continue` ile devam edilir.

## Proje Yapısı

```
├── Characters.h     — Liver temel sınıfı (Stats, getter/setter)
├── GameManager.h/cpp — Oyun akışı, savaş, bölge yönetimi
├── SaveManager.h/cpp — Kayıt / yükleme
├── Weapon.h         — Silah verisi
├── Armor.h          — Zırh verisi
└── main.cpp         — Giriş noktası
```

## Mimari

`Liver` → tüm canlıların temel sınıfı, `Player` ve `Monster` buradan türeyecek.  
`GameManager` → oyun akışını yönetir, `SaveManager` tutarak kayıt işlemlerini
devrete eder.
