# linux-mentor

Linux'ta bir şeyin nasıl çalıştığını anlamanın iyi bir yolu, küçük bir program yazıp sonucuna bakmak.
Bu seride bunu yapıyorum: bir soru, kısa bir deney, ardından çıktının açıklaması.

C ile sistem çağrılarına yaklaşıyoruz. C++23 ile kaynakların sahipliğini düzenliyoruz.
Go ile aynı sistemin üstünde küçük gözlem ve iletişim araçları yazıyoruz.
Her bölüm bağımsız çalışır; temel programlama bilgisi ve terminal kullanımı yeterli.

## Başlangıç

Linux (veya WSL2), GCC/G++ 14+, Go 1.22+, GNU Make ve Bash gerekiyor.
Harici kütüphane yok. Deneyleri normal kullanıcıyla çalıştır.

```sh
git clone https://github.com/merthium/linux-mentor.git
cd linux-mentor
make
make check
./build/01-fork
```

Sadece C bölümü için `make build/01-fork` yeterli; Go ve C++ derleyicileri o bölüm için gerekmez.
Kontroller `timeout` kullanır. Bazı sandbox'lar fork veya socket işlemlerini kısıtlar;
bu durumda normal bir Linux terminalinde çalıştır.

## Yayımlanan bölümler

<!-- chapters:start -->
- [01-fork](chapters/01-fork/README.md)
- [02-dup](chapters/02-dup/README.md)
<!-- chapters:end -->

## Yol haritası

| Hafta | Soru | Dil |
| --- | --- | --- |
| 1 | fork sonrası değişken kimin? | C |
| 2 | dup dosyayı mı, descriptor'ı mı kopyalar? | C |
| 3 | /proc bize süreç hakkında ne söyler? | Go |
| 4 | Pipe okuması ne zaman biter? | C |
| 5 | Dosyayı kapatmayı unutmasak? | C++23 |
| 6 | mmap ile değişen şey dosya mı, bellek mi? | C++23 |
| 7 | Bir program düzgün biçimde nasıl kapanır? | Go |
| 8 | Aynı makinedeki iki uç nasıl konuşur? | Go |

Yeni bölüm cumartesileri Türkiye saatiyle 12.17 civarında gelir.
Yayın otomatik; GitHub Actions yoğunluğunda gecikebilir.

## Nasıl çalışmalı?

Önce çıktıyı tahmin et. Sonra çalıştır. Son olarak bölüm sonundaki değişikliği yapıp tekrar dene.
PID, descriptor numarası, thread sayısı ve bellek miktarı makineye göre değişebilir.
Bir deneyin gösterdiği sonuçla, göstermediği şeyi ayırmaya özellikle dikkat ediyorum.

Bir hata bulursan kullandığın komutu, derleyici sürümünü ve çıktıyı issue'ya ekleyebilirsin.
Kod ve metinler [MIT](LICENSE) lisanslıdır.
