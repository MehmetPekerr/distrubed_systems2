# Temel imaj olarak Ubuntu'yu kullanıyoruz
FROM ubuntu:20.04

# Gerekli paketleri yükleyelim ve zaman dilimini ayarlayalım
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    openmpi-bin \
    openmpi-common \
    libopenmpi-dev \
    gcc \
    gfortran \
    vim \
    nano \
    ssh \
    tzdata && \
    ln -fs /usr/share/zoneinfo/Europe/Istanbul /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata && \
    rm -rf /var/lib/apt/lists/*

# SSH kurulumu
RUN apt-get install -y openssh-server && \
    mkdir /var/run/sshd

# Root şifresi belirliyoruz
RUN echo 'root:Docker!' | chpasswd

# Kullanıcı oluşturuyoruz
RUN useradd -ms /bin/bash mpiuser

# Kaynakları değiştirelim
RUN sed -i 's/http:\/\/archive.ubuntu.com/http:\/\/mirror.karneval.cz/g' /etc/apt/sources.list

# SSH anahtarları için gerekli dizinleri ve izinleri ayarlayalım
RUN mkdir -p /etc/ssh && \
    chmod 700 /etc/ssh && \
    ssh-keygen -A && \
    chmod 644 /etc/ssh/sshd_config

# Konteynerdeki dosya izinlerini doğru ayarlayalım
RUN chown -R root:root /etc/ssh && \
    chmod 600 /etc/ssh/sshd_config

# hello_mpi.c dosyasını konteynerimize kopyalayalım
COPY hello_mpi.c /hello_mpi.c

# MPI kodunu derleyelim
RUN mpicc /hello_mpi.c -o hello_mpi

# SSH servisini ön planda çalışacak şekilde başlatıyoruz
CMD ["/usr/sbin/sshd", "-D"]

# SSH servisini otomatik çalışacak şekilde başlatıyoruz
RUN systemctl enable ssh

