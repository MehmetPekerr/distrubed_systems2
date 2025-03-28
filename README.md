# distrubed_systems2

## MPI vs OpenMP Performans Karşılaştırması

Bu bölümde, MPI ve OpenMP'nin performans farkları karşılaştırılmıştır. Küçük veri setlerinde OpenMP daha hızlı çalışırken, büyük veri setlerinde MPI daha etkili olabilmektedir. Her iki yöntem de farklı paralel işlem senaryoları için uygundur ve her birinin avantajları bulunmaktadır.

### MPI (Message Passing Interface)
- **Avantajlar**: Dağıtık sistemlerde düğümler arasında veri paylaşımı yaparak paralel işlem sağlar. Büyük veri setlerinde etkili olabilir.
- **Dezavantajlar**: Ağ gecikmeleri ve iletişim maliyetleri nedeniyle veri paylaşımının zaman alması.

### OpenMP (Open Multi-Processing)
- **Avantajlar**: Aynı makinedeki çekirdekler arasında hızlı veri paylaşımı sağlar. Küçük veri setlerinde etkili olabilir.
- **Dezavantajlar**: Yalnızca aynı makinedeki işlemcilerle çalışabilir, bu yüzden büyük veri setlerinde verimli olmayabilir.

### Sonuç
- **Küçük veri setleri**: OpenMP daha hızlıdır, çünkü aynı makinedeki çekirdekler arasında hızlı veri paylaşımı yapılabilir.
- **Büyük veri setleri**: MPI daha etkili olacaktır, çünkü veri düğümler arasında dağıtılabilir.
