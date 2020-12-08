
## Задание 
Проект https://github.com/akhtyamovpavel/PatternsCollection

Необходимо сделать окружение разработчика, в котором этот проект запускается. Для этого необходимо установить необходимые пакеты + описать сценарий, как эти пакеты должны ставиться.

Необходимо написать необходимые действия для работоспособности всех бинарных файлов.



## Что нужно сделать


Для того, чтобы понять какие запустить данный проект на любой машинке, будем запускать данный проект в докере. В качестве базовой ОС взял ubuntu bionic:
```
docker run -it --rm -v "$PWD:/data" ubuntu:bionic bash
```

Прежде необходимо обновить пакетный менеджер  `apt update`

Установим `cmake` и остальные необходимые для сбрки пакеты:
``` 
apt install cmake 
apt install build-essential
```
После попытки собрать проект, cmake выдаст нам пакеты, которые нужно поставить дополнительно:

``` 
apt install libboost-dev
apt install libboost-system-dev
apt install libssl-dev
apt install git
apt install zlib1g-dev
apt install libvmime-dev
apt install sendmail
```

Для того, чтобы проект увидел sendmail необходимо указать явно переменную окружения:
```
export VMIME_SENDMAIL_PATH=/usr/sbin/sendmail
```

Теперь проект собирается!

После сборки можно запустить выполняемые файлы и првоерить работу проекта. Все кроме Decorator запускается без дополнительных действий. Для запуска декоратора необходимо сообщить ему местоположение динамических библиотек `LD_LIBRARY_PATH=/data/build/external/lib ./Decorator`