mysqlda - MySQL���ݿ��м��
==========================

<!-- TOC -->

- [1. ����](#1-����)
    - [1.1. ���ݷֲ�ʽ�зַ�ʽ](#11-���ݷֲ�ʽ�зַ�ʽ)
    - [1.2. mysqlda](#12-mysqlda)
- [2. �ܹ���ԭ��](#2-�ܹ���ԭ��)
    - [2.1. ��ϵ�ܹ�](#21-��ϵ�ܹ�)
    - [2.2. ����ԭ��](#22-����ԭ��)
    - [2.3. ���װ���](#23-���װ���)
    - [2.4. �ڲ�����ʵ��͹�ϵ](#24-�ڲ�����ʵ��͹�ϵ)
- [3. ��װ����](#3-��װ����)
    - [3.1. �⿪mysqldaԴ��� �� ֱ�Ӵ�Դ���йܵ�ַ��¡���°�](#31-�⿪mysqldaԴ���-��-ֱ�Ӵ�Դ���йܵ�ַ��¡���°�)
    - [3.2. ����srcĿ¼�������м��ļ�](#32-����srcĿ¼�������м��ļ�)
    - [3.3. �޸İ�װĿ��Ŀ¼](#33-�޸İ�װĿ��Ŀ¼)
    - [3.4. ���롢��װ](#34-���롢��װ)
    - [3.5. ��ѯ�汾�ţ�Ҳȷ�Ͽ�ִ���ļ�OK](#35-��ѯ�汾�ţ�Ҳȷ�Ͽ�ִ���ļ�ok)
- [4. ����ʹ��](#4-����ʹ��)
    - [4.1. �Զ�����ȱʡ�����ļ�](#41-�Զ�����ȱʡ�����ļ�)
    - [4.2. ����mysqlda](#42-����mysqlda)
    - [4.3. ֹͣmysqlda](#43-ֹͣmysqlda)
    - [4.4. ����MySQL���ݿ⼯Ⱥ](#44-����mysql���ݿ⼯Ⱥ)
        - [4.4.1. ����MySQL������](#441-����mysql������)
        - [4.4.2. ����MySQL������������б�](#442-����mysql������������б�)
- [5. �����ļ������ʽ](#5-�����ļ������ʽ)
    - [5.1. ����ҵ�����-MySQL������ �����ļ���ʽ](#51-����ҵ�����-mysql������-�����ļ���ʽ)
    - [5.2. ���������ࡢ��������-����ҵ����� �����ļ���ʽ](#52-���������ࡢ��������-����ҵ�����-�����ļ���ʽ)
- [6. ����ʾ��](#6-����ʾ��)
    - [6.1. ˵��](#61-˵��)
        - [6.1.1. �ú���ҵ�����λMySQL������](#611-�ú���ҵ�����λmysql������)
        - [6.1.2. �ù��������ࡢ��������󶨵�����ҵ�����](#612-�ù��������ࡢ��������󶨵�����ҵ�����)
        - [6.1.3. �ù��������ࡢ��������λMySQL������](#613-�ù��������ࡢ��������λmysql������)
    - [6.2. C����ʾ��](#62-c����ʾ��)
        - [6.2.1. �ú���ҵ�����λMySQL������](#621-�ú���ҵ�����λmysql������)
        - [6.2.2. �ù��������ࡢ��������󶨵�����ҵ�����](#622-�ù��������ࡢ��������󶨵�����ҵ�����)
        - [6.2.3. �ù��������ࡢ��������λMySQL������](#623-�ù��������ࡢ��������λmysql������)
        - [6.2.4. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��INSERT���](#624-�ú���ҵ�����λmysql�����⡢Ȼ������ִ��insert���)
        - [6.2.5. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��UPDATE���](#625-�ú���ҵ�����λmysql�����⡢Ȼ������ִ��update���)
        - [6.2.6. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��DELETE���](#626-�ú���ҵ�����λmysql�����⡢Ȼ������ִ��delete���)
- [7. ����ע������](#7-����ע������)
    - [7.1. �ÿͻ���mysqlֱ��mysqlda](#71-�ÿͻ���mysqlֱ��mysqlda)
- [8. ���](#8-���)
    - [8.1. �����з�](#81-�����з�)
    - [8.2. Դ���й�](#82-Դ���й�)
    - [8.3. ��������](#83-��������)

<!-- /TOC -->

# 1. ����

## 1.1. ���ݷֲ�ʽ�зַ�ʽ

�ֲ�ʽ�ܹ������ѽ���������ݷֲ�ʽ���⣬�󲿷����ݿ��м����**�Էֿ�ֱ���Ϊ�зַ�ʽ**���ô���ͨ�ã���Ҳ�����������⣺

1. ���ݹ�����Ҫ����ƬΪ��λ�ڿ���ƶ����ݡ����ݹ�ģ�ܵ���Ƭ�������ƣ����ҵ��չ������ģ��󳬳�����Ԥ���ᵼ����Ƭ���������ã���������ӲǨ�Ƶ�������
2. ͬһҵ���������ݷ�ɢ�ڲ�ͬ���У��޷����ۺϡ����ӵȸ��Ӵ���
3. �����ζ�ŷֲ�ʽ������Ȼ���������׶��ύ�Ƚ���������������ϲ���������ô�ɿ����������ڽ�����ҵ��������ǿһ����ʱ��

**�Ժ���ҵ������зַ�ʽ**���Բ�Ʒ�����ҵ�������Ϊ�з�Ŀ�꣨���绥����ҵ��ϵͳ�еĿͻ����󣩣���������;�����ݿ��м�������ֻ��Ż���������ֶ���Ϊ�����ֶ�������Ȩ�صĿ�Ⱥ�з֣����������ݿ⼯Ⱥ�е�ĳ�����У���������������Ժ�ÿͻ������н��׶��ᱻ����������⴦������Ҫ��洢����ʱ��ֻ��򵥵�����MySQL�����⵽���ݿ⼯Ⱥ�У������ݿ��м��ϵͳ�������¹�����������Ϣ���������¿ⱻ����Ȩ�أ��¿ͻ�����������¿�ĸ��ʱ�󣬵��¿�洢������һ���̶�ʱ��ƽ����Ȩ�أ��¿ͻ�������������п�ĸ��ʾ��ȣ�ֱ����һ�����ݡ�

�Ժ���ҵ������зַ�ʽ�ĺô��ǣ�

1. ����Ԥ����Ƭ�������ݹ��������ƶ��κ����ݡ�
2. ����ͬһҵ���������ݼ�������������У����Կ��Խ�������ۺϡ����ӵȸ��Ӵ���
3. ÿ���ⶼ��ȫҵ��⣬ͬһҵ����������ģ�鴦����һ��������ɣ������ڿ��ֲ�ʽ��������ǿһ���Զ��������ݿⵥ������֤��

��Ҳ��������Ӳ�ˣ�

1. ��Ʒ����Ƴ���������ѡ����ҵ�������Ϊ�з����ݣ����ں��ѱ����
2. ��Щҵ��ϵͳ���ڶ������ҵ����󣬲��ʺ�ʹ�������зַ�ʽ�������������������Ϻ��ġ�

**�Էֿ�ֱ��з�**��**�Ժ���ҵ������з�**���������������ݷֲ�ʽ��Ʒ�ʽ��������ȱ�㣬Ӧ�ڲ�ͬ������ѡ���ʵķ�ʽ��

## 1.2. mysqlda

mysqlda��һ����ں���ҵ������зֵ�Proxyģʽ�ķֲ�ʽMySQL���ݿ��м����

mysqlda���ƣ�

* �Ժ���ҵ������зַ�ʽ�����кô���
* ֧���Ժ���ҵ�����λMySQL�����⣨�翪�����ֻ��Ż����䣩��Ҳ֧�ֺ���ҵ�����Ĺ��������翪������û�ID���û������˺ţ���λMySQL�����⡣
* ���������Ȩ���Զ����������ݺ��¿����Ͽ�ķ���Ȩ��Ҳ�Զ������������˹����룬ʹ�����й�����������������Զ�����������
* �Ѱ������ݿ����ظ߿��ù��ܣ���һ�������⵱ǰMySQL��������������ʱ�Զ��л�������������֧�ֶ������������
* ��MySQL������֮������ӳػ��ƣ�ʵ�������Ӹ��ú���������������Ӻ��л����ܡ�
* ͨ���������������ļ�����������MySQL�����⡢����MySQL�����������б����ȫ�޸С�
* ����ϵͳ�����ݷֲ�ʽ������̾����޸С�

# 2. �ܹ���ԭ��

## 2.1. ��ϵ�ܹ�

![images/architecture.png](images/architecture.png)

mysqlda���ݿ��м����ȫ��ѭMySQLͨѶЭ���Ž�Ӧ�÷�������Ⱥ��MySQL���ݿ⼯Ⱥ��

mysqlda�ڲ����̽ṹΪ����-���ӽ��̡���

## 2.2. ����ԭ��

ȫ�������Ժ���ҵ������зֵ�����������У�ÿ�����������ȫҵ���һ����������һ��MySQL�������б��貿��Ϊ������ͬ�����ݣ���ɣ�����ǰMySQL������������ʱ�Զ��л�����һ����

MySQL���ݿ⼯ȺԤ������ͬ�������û��������룬��ͬ�����ݿ�����Ӧ�ñ�ṹ��mysqldaԤ������ͬ�������û��������롣

����mysqlda���������ļ���etc/mysqlda.conf����װ�������û��������룬�ӱ����ļ���etc/mysqlda.save��etc/mysqlda.����������.save����װ���Ѵ��ڵĺ���ҵ����󡢹������� �� MySQL���ݿ⼯Ⱥ�� �������ϵ��Ϣ��

Ӧ�÷��������ñ�׼MySQL���Ӻ���/��������mysqlda��mysqlda����ѭMySQLͨѶЭ�鴦��MySQL�û���¼������У�顣

��¼�ɹ�������DSL��DML����ǰ��Ӧ�÷���������mysqlda��չSQLѡ��**����ҵ�����**��"select library (����ҵ�����)"����**����������**��**��������**��"select library\_by\_correl\_object (����������) (��������)"��������MySQL�����⣬mysqlda���ѯ���ѷ����MySQL��**����ҵ�����**��**����������**��**��������**�����û�з��������ݼ�Ȩһ���Թ�ϣ�㷨����һ�������Ⲣ�־û��������ļ��У����Ӹ�MySQL�������Ӧ���ݿ�����������б���ѡ���һ����ЧMySQL�������������ӳ���ѡȡ�������ӣ���û�л����������½�һ�����ӣ���Ȼ���ŽӶ���Ͷ������ӽ�ԣ���ʼ�����������DSL��DML������

���������п���Ҳ����mysqlda��չSQL��ѡ��**����ҵ�����**��**���������ࡢ��������**�Ե���MySQL��������������ӡ�

MySQL�������Ӧһ�����ݿ�������б�����MySQL���ݿ�1A(MASTER)��1B(SLAVE)��1C(SLAVE)��1D(SLAVE)��ɣ�1Aͬ���������ݸ�1B��1C��1D�����1A���ֹ��ϲ��ܱ�mysqlda���ӣ�mysqlda�����γ�������1B��1C��1D��ʵ��ϵͳ�����ԡ�

Ӧ�÷���������mysqlda��չSQL��**����������**��**��������**��**����ҵ�����**��"set correl_object ���������� �������� ����ҵ�����"����mysqlda�ᱣ��ù�ϵ���־û��������ļ��У����Ժ�ֱ����**����������**��**��������**��λMySQL�����⡣

## 2.3. ���װ���

����������MySQL�����⣬ÿ������������̨MySQL��������ɡ�

A�û����ֻ��ţ�����ҵ����󣩿�����Ӧ�÷����������ֻ���13812345678��mysqlda����λ�����⣨"select library 13812341234"����mysqldaͨ����Ȩһ���Թ�ϣ�㷨��������ֻ��ţ�����ͻ���������N���־û��������ļ��У��ӹ�����N���ӳ���ȡ��һ�����ӣ��Ѹ�������Ӧ�÷����������Žӣ��������������SQL�ʹ�������

����ҵ���߼��д������˻�331234567890����Ӧ�÷���������mysqlda��չSQL��mysqla��"set correl\_object account\_no 331234567890 13812345678"����mysqlda�����߹�ϵ���־û��������ļ��С�

A�û������������󣬿������ֻ��ţ�"select library 13812341234"�����˺ţ�"select library\_by\_correl\_object account\_no 331234567890"����mysqlda��λ�������û������⣬���û�������ҵ�����ݺ�ҵ�����ڸù���������ɡ�

## 2.4. �ڲ�����ʵ��͹�ϵ

![images/data_entity_and_relation.png](images/data_entity_and_relation.png)

һ��**MySQL������**��forward\_instance����Ӧһ��**MySQL���ݿ�����������б�**��forward\_servers list����

һ��**MySQL���ݿ�����������б�**��forward\_servers list����Ͻһ��**�������ӳ�**��unused\_forward\_session list����һ��**�������ӳ�**��forward\_session list����

һ��**����ҵ�����**���԰�һ������**����������**��forward\_correl\_object\_class����**��������**��forward\_correl\_object����

һ��**����ҵ�����**��һ��**���������ࡢ��������** �� **MySQL������** ����һ��**������ϵ**��forward\_library����

accepted\_session��**Ӧ�÷�������mysqlda֮���ͨѶ�Ự**��forward\_session��**mysqlda��MySQL���ݿ������֮���ͨѶ�Ự**��һ��һ�������ϵ�MySQL�����ⱻѡ�����л����������Ự�ᱻ�Ž�������

# 3. ��װ����

mysqldaֻ������mysql��mariadb�������Ȱ�װ�ÿ�����*-devel-*��

## 3.1. �⿪mysqldaԴ��� �� ֱ�Ӵ�Դ���йܵ�ַ��¡���°�

```Shell
$ git clone http://git.oschina.net/calvinwilliams/mysqlda
Cloning into 'mysqlda'...
remote: Counting objects: 355, done.
remote: Compressing objects: 100% (345/345), done.
remote: Total 355 (delta 221), reused 0 (delta 0)
Receiving objects: 100% (355/355), 586.04 KiB | 0 bytes/s, done.
Resolving deltas: 100% (221/221), done.
```

## 3.2. ����srcĿ¼�������м��ļ�

```Shell
$ cd mysqlda
$ make -f makefile.Linux clean
make[1]: Entering directory `/home/calvin/src/mysqlda/src'
make[2]: Entering directory `/home/calvin/src/mysqlda/src/mysqlda'
rm -f lk_list.o
rm -f rbtree.o
rm -f LOGC.o
rm -f fasterjson.o
rm -f util.o
rm -f rbtree_ins.o
rm -f IDL_mysqlda_conf.dsc.o
rm -f main.o
rm -f config.o
rm -f monitor.o
rm -f worker.o
rm -f comm.o
rm -f app.o
rm -f mysqlda
make[2]: Leaving directory `/home/calvin/src/mysqlda/src/mysqlda'
make[1]: Leaving directory `/home/calvin/src/mysqlda/src'
make[1]: Entering directory `/home/calvin/src/mysqlda/shbin'
make[1]: Leaving directory `/home/calvin/src/mysqlda/shbin'
make[1]: Entering directory `/home/calvin/src/mysqlda/test'
rm -f mysqlda_test_connect.o
rm -f mysqlda_test_select_library.o
rm -f mysqlda_test_set_correl_object.o
rm -f mysqlda_test_select_library_by_correl_object.o
rm -f mysqlda_test_insert.o
rm -f mysqlda_test_update.o
rm -f mysqlda_test_delete.o
rm -f mysqlda_test_connect
rm -f mysqlda_test_select_library
rm -f mysqlda_test_set_correl_object
rm -f mysqlda_test_select_library_by_correl_object
rm -f mysqlda_test_insert
rm -f mysqlda_test_update
rm -f mysqlda_test_delete
make[1]: Leaving directory `/home/calvin/src/mysqlda/test'
```

## 3.3. �޸İ�װĿ��Ŀ¼

��ִ���ļ�mysqldaĬ�ϱ������ӳ�����װ��$HOME/bin���������Ŀ��Ŀ¼�ɱ༭src/mysqlda/makeinstall

```
_BINBASE        =       $(HOME)/bin
```

����ű�mysqlda.shĬ�ϱ������ӳ�����װ��$HOME/shbin���������Ŀ��Ŀ¼�ɱ༭shbin/makeinstall

```
NOCLEAN_OBJINST =       $(HOME)/shbin
```

û����������Բ��޸�

## 3.4. ���롢��װ

```Shell
$ make -f makefile.Linux install
make[1]: Entering directory `/home/calvin/src/mysqlda/src'
make[2]: Entering directory `/home/calvin/src/mysqlda/src/mysqlda'
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c lk_list.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c rbtree.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c LOGC.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c fasterjson.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c util.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c rbtree_ins.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c IDL_mysqlda_conf.dsc.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c main.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c config.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c monitor.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c worker.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c comm.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include/mysqlda_api -std=gnu99 -I/usr/include/mysql  -c app.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda lk_list.o rbtree.o LOGC.o fasterjson.o util.o rbtree_ins.o IDL_mysqlda_conf.dsc.o main.o config.o monitor.o worker.o comm.o app.o -L. -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient -lcrypto 
cp -rf mysqlda /home/calvin/bin/
make[2]: Leaving directory `/home/calvin/src/mysqlda/src/mysqlda'
make[1]: Leaving directory `/home/calvin/src/mysqlda/src'
make[1]: Entering directory `/home/calvin/src/mysqlda/shbin'
cp -rf mysqlda.sh /home/calvin/shbin/
make[1]: Leaving directory `/home/calvin/src/mysqlda/shbin'
make[1]: Entering directory `/home/calvin/src/mysqlda/test'
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_connect.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_connect mysqlda_test_connect.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_select_library.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_select_library mysqlda_test_select_library.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_set_correl_object.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_set_correl_object mysqlda_test_set_correl_object.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_select_library_by_correl_object.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_select_library_by_correl_object mysqlda_test_select_library_by_correl_object.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_insert.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_insert mysqlda_test_insert.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_update.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_update mysqlda_test_update.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -I. -I/home/calvin/include -std=gnu99 -I/usr/include/mysql  -c mysqlda_test_delete.c
gcc -g -fPIC -O2 -Wall -Werror -fno-strict-aliasing -o mysqlda_test_delete mysqlda_test_delete.o -L. -L/home/calvin/lib -L/home/calvin/lib -L/usr/lib64/mysql -lmysqlclient 
make[1]: Leaving directory `/home/calvin/src/mysqlda/test'
```

## 3.5. ��ѯ�汾�ţ�Ҳȷ�Ͽ�ִ���ļ�OK

```Shell
$ mysqlda -v
mysqlda v0.0.6.0
```

# 4. ����ʹ��

## 4.1. �Զ�����ȱʡ�����ļ�

```Shell
$ mysqlda -a init
$ cat ~/etc/mysqlda.conf
{
        "server" : 
        {
                "listen_ip" : "127.0.0.1" ,
                "listen_port" : 13306
        } ,
        "auth" : 
        {
                "user" : "calvin" ,
                "pass" : "calvin" ,
                "db" : "calvindb"
        } ,
        "session_pool" : 
        {
                "unused_forward_session_timeout" : 60
        } ,
        "forwards" : 
        [
        {
                "instance" : "mysqlda1" ,
                "forward" : 
                [
                {
                        "ip" : "127.0.0.1" ,
                        "port" : 3306
                }
                ]
        }
        ]
}
```

��������˵�����£�

```
server.listen_ip : mysqlda����Ӧ�÷�����������IP
server.listen_port : mysqlda����Ӧ�÷�����������PORT
auth.user : mysqlda����Ӧ�÷������ĵ�¼��֤�û�����Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼��֤�û���
auth.pass : mysqlda����Ӧ�÷������ĵ�¼��֤�û����룬Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼��֤�û�����
auth.db : mysqlda����Ӧ�÷������ĵ�¼���ݿ⣬Ҳ��mysqlda����MySQL���ݿ�������б�Ⱥ�ĵ�¼���ݿ�
session_pool.unused_forward_session_timeout : mysqlda����MySQL���ݿ�������б�Ⱥ�Ŀ������ӳس�ʱ����ʱ��
forwards[].instance : MySQL������ID
forwards[].forward[].ip : MySQL�����������IP
forwards[].forward[].port : MySQL�����������PORT
```

## 4.2. ����mysqlda

���������в���ֱ��ִ��mysqlda��õ����������б�����ʵ�ʻ����޸��������ļ�������

```Shell
$ mysqlda
USAGE : mysqlda -f (config_filename) --no-daemon -a [ init | start ]
                                     [ --loglevel-debug | --loglevel-info | --loglevel-notice
                                     | --loglevel-warn | --loglevel-error | --loglevel-fatal ]
                -v
$ mysqlda -a start
```

ע�⣺Ĭ����־�ȼ�ΪNOTICE��������Ե��Եȼ����������������в���--loglevel-debug��

Ҳ����ʹ�ù���ű�����

```Shell
$ mysqlda.sh
USAGE : mysqlda.sh [ status | start | stop | kill | restart | reload ] *
$ mysqlda.sh start
```

ע�⣺mysqlda.sh�ڶ���������ʼ�Ĳ����б�ᴫ�ݸ�mysqlda -a start���档

��ѯ������־�����ҵĻ����������ã�

```Shell
$ view ~/log/mysqlda.log
2017-09-03 14:17:17.306390 | NOTICE | 18582:monitor.c:75 | [18582]fork[18583] ok
2017-09-03 14:17:17.306460 | NOTICE | 18582:monitor.c:69 | [18582]fork[18583] ok
2017-09-03 14:17:17.307423 | NOTICE | 18583:config.c:259 | Load forward_library /home/calvin/etc/mysqlda.save ok , count[2000]
2017-09-03 14:17:17.307452 | NOTICE | 18583:config.c:358 | Load all forward_correl_object_class ok , count[0]
2017-09-03 14:17:17.307456 | NOTICE | 18583:config.c:369 | instance[0x225a180][mysql_data_1] serial_range_begin[0] power[989]
2017-09-03 14:17:17.307459 | NOTICE | 18583:config.c:373 |      ip[192.168.6.22] port[3306]
2017-09-03 14:17:17.307462 | NOTICE | 18583:config.c:369 | instance[0x225a260][mysql_data_2] serial_range_begin[989] power[1013]
2017-09-03 14:17:17.307464 | NOTICE | 18583:config.c:373 |      ip[192.168.6.23] port[3306]
2017-09-03 14:17:17.307467 | NOTICE | 18583:config.c:377 | total_power[2002]
2017-09-03 14:17:17.307475 | NOTICE | 18583:worker.c:204 | epoll_create ok , #1#
2017-09-03 14:17:17.307479 | NOTICE | 18583:worker.c:219 | epoll_ctl #1# add alive_pipe_session #0# ok
2017-09-03 14:17:17.307488 | NOTICE | 18583:worker.c:231 | socket ok , #2#
2017-09-03 14:17:17.307499 | NOTICE | 18583:worker.c:248 | bind[192.168.6.21:13306] #2# ok
2017-09-03 14:17:17.307506 | NOTICE | 18583:worker.c:260 | listen[192.168.6.21:13306] #2# ok
2017-09-03 14:17:17.307509 | NOTICE | 18583:worker.c:275 | epoll_ctl #1# add listen_session #2# ok
2017-09-03 14:17:17.308110 | NOTICE | 18583:worker.c:293 | [mysql_data_1]mysql_real_connect[192.168.6.22][3306][calvin][calvin][calvindb] connecting ...
2017-09-03 14:17:17.309869 | NOTICE | 18583:worker.c:302 | [mysql_data_1]mysql_real_connect[192.168.6.22][3306][calvin][calvin][calvindb] connecting ok
2017-09-03 14:17:17.310148 | NOTICE | 18583:worker.c:313 | [mysql_data_1]mysql_close[192.168.6.22][3306] ok
2017-09-03 14:17:17.310219 | NOTICE | 18583:worker.c:293 | [mysql_data_2]mysql_real_connect[192.168.6.23][3306][calvin][calvin][calvindb] connecting ...
2017-09-03 14:17:17.311103 | NOTICE | 18583:worker.c:302 | [mysql_data_2]mysql_real_connect[192.168.6.23][3306][calvin][calvin][calvindb] connecting ok
2017-09-03 14:17:17.311119 | NOTICE | 18583:worker.c:313 | [mysql_data_2]mysql_close[192.168.6.23][3306] ok
2017-09-03 14:17:18.313143 | NOTICE | 18583:worker.c:345 | epoll_wait #1# return[0]events
2017-09-03 14:17:19.315163 | NOTICE | 18583:worker.c:345 | epoll_wait #1# return[0]events
2017-09-03 14:17:20.316408 | NOTICE | 18583:worker.c:345 | epoll_wait #1# return[0]events
```

���ʾ�����ɹ�

���mysqlda����MySQL���ݿ⼯Ⱥ�����⣬������ʼ���׶λ�������

```Shell
2017-09-03 14:17:17.306390 | NOTICE | 18582:monitor.c:75 | [18582]fork[18583] ok
2017-09-03 14:17:17.306460 | NOTICE | 18582:monitor.c:69 | [18582]fork[18583] ok
2017-09-03 14:17:17.307423 | NOTICE | 18583:config.c:259 | Load forward_library /home/calvin/etc/mysqlda.save ok , count[2000]
2017-09-03 14:17:17.307452 | NOTICE | 18583:config.c:358 | Load all forward_correl_object_class ok , count[0]
2017-09-03 14:17:17.307456 | NOTICE | 18583:config.c:369 | instance[0x225a180][mysql_data_1] serial_range_begin[0] power[989]
2017-09-03 14:17:17.307459 | NOTICE | 18583:config.c:373 |      ip[192.168.6.22] port[3306]
2017-09-03 14:17:17.307462 | NOTICE | 18583:config.c:369 | instance[0x225a260][mysql_data_2] serial_range_begin[989] power[1013]
2017-09-03 14:17:17.307464 | NOTICE | 18583:config.c:373 |      ip[192.168.6.23] port[3306]
2017-09-03 14:17:17.307467 | NOTICE | 18583:config.c:377 | total_power[2002]
2017-09-03 14:17:17.307475 | NOTICE | 18583:worker.c:204 | epoll_create ok , #1#
2017-09-03 14:17:17.307479 | NOTICE | 18583:worker.c:219 | epoll_ctl #1# add alive_pipe_session #0# ok
2017-09-03 14:17:17.307488 | NOTICE | 18583:worker.c:231 | socket ok , #2#
2017-09-03 14:17:17.307499 | NOTICE | 18583:worker.c:248 | bind[192.168.6.21:13306] #2# ok
2017-09-03 14:17:17.307506 | NOTICE | 18583:worker.c:260 | listen[192.168.6.21:13306] #2# ok
2017-09-03 14:17:17.307509 | NOTICE | 18583:worker.c:275 | epoll_ctl #1# add listen_session #2# ok
2017-09-03 14:17:17.308110 | NOTICE | 18583:worker.c:293 | [mysql_data_1]mysql_real_connect[192.168.6.22][3306][calvin][calvin][calvindb] connecting ...
2017-08-28 14:17:17.308110 | ERROR | 53070:worker.c:130 | [mysql_data_1]mysql_real_connect[192.168.6.22][13306][calvin][calvin][calvindb] failed , mysql_errno[2003][Can't connect to MySQL server on '192.168.6.22' (113)]
2017-08-28 14:17:17.308110 | INFO  | 53070:worker.c:482 | worker exit ...
```

## 4.3. ֹͣmysqlda

ֱ��ps��������TERM�źż��ɣ����ͣ�����ͷ���KILL�ź�

```Shell
$ ps -ef | grep mysqlda
calvin   53069     1  0 00:12 pts/1    00:00:00 mysqlda -a start
calvin   53097 53072  0 00:12 pts/2    00:00:00 view mysqlda.log
calvin   53111 52899  0 00:12 pts/1    00:00:00 grep --color=auto mysqlda
$ kill 53069
```

Ҳ����ʹ�ù���ű�ֹͣ

```Shell
$ mysqlda.sh stop
```

## 4.4. ����MySQL���ݿ⼯Ⱥ

### 4.4.1. ����MySQL������

�������ļ�mysqlda.conf������һ��forwards[]������һ��MySQL������forward��������������MySQL������mysql\_data\_3��

```Shell
        "forwards" : 
        [
                {
                        "instance" : "mysql_data_1" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.11" , "port" : 13306 } ,
                        { "ip" : "192.168.6.12" , "port" : 13306 } ,
                        { "ip" : "192.168.6.13" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_2" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.21" , "port" : 13306 } ,
                        { "ip" : "192.168.6.22" , "port" : 13306 } ,
                        { "ip" : "192.168.6.23" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_3" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.31" , "port" : 13306 } ,
                        { "ip" : "192.168.6.32" , "port" : 13306 } ,
                        { "ip" : "192.168.6.33" , "port" : 13306 }
                        ]
                }
        ]
```

����USR1�źŵ�mysqlda�����̡�

> ע�⣺��������������Ϣ��һ�㲻���޸Ļ�ɾ��MySQL�����⡣

### 4.4.2. ����MySQL������������б�

�������ļ�mysqlda.conf������һ��forwards[]������һ��MySQL������forward��������ÿ��MySQL�����ⶼ������һ̨MySQL��������

```Shell
        "forwards" : 
        [
                {
                        "instance" : "mysql_data_1" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.11" , "port" : 13306 } ,
                        { "ip" : "192.168.6.12" , "port" : 13306 } ,
                        { "ip" : "192.168.6.13" , "port" : 13306 } ,
                        { "ip" : "192.168.6.14" , "port" : 13306 }
                        ]
                } ,
                {
                        "instance" : "mysql_data_2" ,
                        "forward" : 
                        [
                        { "ip" : "192.168.6.21" , "port" : 13306 } ,
                        { "ip" : "192.168.6.22" , "port" : 13306 } ,
                        { "ip" : "192.168.6.23" , "port" : 13306 } ,
                        { "ip" : "192.168.6.24" , "port" : 13306 }
                        ]
                }
        ]
```

����USR1�źŵ�mysqlda���������������ã�Ҳ����ʹ�ù���ű���

```Shell
$ mysqlda.sh reload
```

> ע�⣺������֧����һ��MySQL���������޸ĺ�ɾ��һ̨MySQL�����������������Ͽ���̨MySQL���������������ӡ�

# 5. �����ļ������ʽ

## 5.1. ����ҵ�����-MySQL������ �����ļ���ʽ

ÿ������ҵ�������������ϵ�󶼻�������ϵ�������ļ�

�ļ����������£�

```
$HOME/etc/mysqlda.save
```

�ļ���ʽ���£�

```
���������� ������ʱ�� ����ҵ����� MySQL������
```

ʾ�����£�

```
2017-08-24 22:17:11 1 mysql_data_2
2017-08-26 16:34:31 2 mysql_data_1
2017-08-26 16:34:31 3 mysql_data_1
2017-08-26 16:34:31 4 mysql_data_1
2017-08-26 16:34:31 5 mysql_data_2
2017-08-26 16:34:31 6 mysql_data_1
2017-08-26 16:34:31 7 mysql_data_1
2017-08-26 16:34:31 8 mysql_data_1
2017-08-26 16:34:31 9 mysql_data_1
2017-08-26 16:34:31 10 mysql_data_1
```

## 5.2. ���������ࡢ��������-����ҵ����� �����ļ���ʽ

ÿ�����������ࡢ��������ͺ���ҵ���������ϵ�󶼻�������ϵ�������ļ�

�ļ����������£�

```
$HOME/etc/mysqlda.(����������).save
```

�ļ���ʽ���£�

```
���������� ������ʱ�� �������� ����ҵ�����
```

ʾ�����£�

```
2017-08-26 18:11:42 330001 2
2017-08-26 18:12:41 330002 3
```

# 6. ����ʾ��

## 6.1. ˵��

����������mysqlda��չSQL���ڶ�λMySQL�����⡢�󶨹�������ȡ�

### 6.1.1. �ú���ҵ�����λMySQL������

���������У�ֻ�������Ӻ���/������SQLִ��ǰ������mysqlda��չSQLͨ��**����ҵ�����**��λ�����⣺

```SQL
select library (����ҵ�����)
```

mysqlda�����**����ҵ�����**��ѯ��MySQL�����⼯����һ��**������**��ӳ���ϵ��û�����ü�Ȩһ���Թ�ϣ�㷨�½����־û��������ļ��С�

### 6.1.2. �ù��������ࡢ��������󶨵�����ҵ�����

���������ࡢ�������� �� ����ҵ����� �󶨹�ϵ��mysqlda��չSQL���ã����־û��������ļ��У�

```SQL
set correl_object (����������) (��������) (����ҵ�����)
```

### 6.1.3. �ù��������ࡢ��������λMySQL������

Ҳ����ͨ��mysqlda��չSQL��**����������**��**��������**��λ**������**��

```SQL
select library_by_correl_object (����������) (��������)
```

mysqlda�����**����������**��**��������**��ѯ�󶨵�**����ҵ�����**���ٲ�ѯ��**������**��

## 6.2. C����ʾ��

��Ŀ��Ŀ¼��testĿ¼���ǲ��Գ���Դ�롣

### 6.2.1. �ú���ҵ�����λMySQL������

�ò��Գ������ڸ���һ��������䣬�����Ľ����Ͷ�λMySQL�����⡣

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"select library (����ҵ�����);"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_select_library.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_connect "192.168.6.21" 13306 calvin calvin calvindb
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_connect (ip) (port) (user) (pass) (database)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	if( argc != 1 + 5 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

### 6.2.2. �ù��������ࡢ��������󶨵�����ҵ�����

�ò��Գ������ڸ������������ࡢ�������󡢺���ҵ����󣬽������ϵ

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"set correl\_object ���������� �������� ����ҵ�����;"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_set_correl_object.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_set_correl_object "192.168.6.21" 13306 calvin calvin calvindb card_no 330001 1
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_set_correl_object (ip) (port) (user) (pass) (database) (correl_object_class) (correl_object) (library)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	char		*correl_object_class = NULL ;
	char		*correl_object = NULL ;
	char		*library = NULL ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 8 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	correl_object_class = argv[6] ;
	correl_object = argv[7] ;
	library = argv[8] ;
	
	memset( sql , 0x00 , sizeof(sql) );
	snprintf( sql , sizeof(sql) , "set correl_object %s %s %s" , correl_object_class , correl_object , library );
	nret = mysql_query( conn , sql ) ;
	if( nret )
	{
		printf( "mysql_query failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		mysql_close( conn );
		return 1;
	}
	else
	{
		printf( "mysql_query ok\n" );
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

### 6.2.3. �ù��������ࡢ��������λMySQL������

�ò��Գ������ڸ���һ��������䣬�����Ľ����Ͷ�λMySQL������

> ע�⣺Ҳ����ֱ���ÿͻ���mysql���ӷ�����ִ��SQL"select library\_by\_correl_object ���������� ��������;"�õ��ȼ�Ч����

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_select_library_by_correl_object.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_select_library_by_correl_object "192.168.6.21" 13306 calvin calvin calvindb card_no 330001
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_select_library_by_correl_object (ip) (port) (user) (pass) (database) (correl_object_class) (correl_object)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	char		*correl_object_class = NULL ;
	char		*correl_object = NULL ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 7 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	correl_object_class = argv[6] ;
	correl_object = argv[7] ;
	
	memset( sql , 0x00 , sizeof(sql) );
	snprintf( sql , sizeof(sql) , "select library_by_correl_object %s %s" , correl_object_class , correl_object );
	nret = mysql_query( conn , sql ) ;
	if( nret )
	{
		printf( "mysql_query failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		mysql_close( conn );
		return 1;
	}
	else
	{
		printf( "mysql_query ok\n" );
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

### 6.2.4. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��INSERT���

�ò��Գ������ڸ���һ��������䣬�����Ľ�������λMySQL�����⡢ִ��INSERT���

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_insert.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_insert "192.168.6.21" 13306 calvin calvin calvindb 1 1000
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_insert (ip) (port) (user) (pass) (database) (begin_seqno) (end_seqno)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	int		begin_seqno ;
	int		end_seqno ;
	int		seqno ;
	char		seqno_buffer[ 20 + 1 ] ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 7 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	memset( seqno_buffer , 0x00 , sizeof(seqno_buffer) );
	begin_seqno = atoi(argv[6]) ;
	end_seqno = atoi(argv[7]) ;
	for( seqno = begin_seqno ; seqno <= end_seqno ; seqno++ )
	{
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "select library %d" , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
		
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "insert into test_table value( '%d' , '%d' )" , seqno , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

### 6.2.5. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��UPDATE���

�ò��Գ������ڸ���һ��������䣬������������λMySQL�����⡢ִ��UPDATE���

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_update.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_update "192.168.6.21" 13306 calvin calvin calvindb 1 1000
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_update (ip) (port) (user) (pass) (database) (begin_seqno) (end_seqno)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	int		begin_seqno ;
	int		end_seqno ;
	int		seqno ;
	char		seqno_buffer[ 20 + 1 ] ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 7 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	memset( seqno_buffer , 0x00 , sizeof(seqno_buffer) );
	begin_seqno = atoi(argv[6]) ;
	end_seqno = atoi(argv[7]) ;
	for( seqno = begin_seqno ; seqno <= end_seqno ; seqno++ )
	{
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "select library %d" , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
		
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "update test_table set value='%d' where name='%d'" , seqno , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

### 6.2.6. �ú���ҵ�����λMySQL�����⡢Ȼ������ִ��DELETE���

�ò��Գ������ڸ���һ��������䣬�����Ľ�������λMySQL�����⡢ִ��DELETE���

���Գ���ʾ�����£�

```C
$ cat test/mysqlda_test_delete.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_global.h"
#include "mysql.h"

/*
./mysqlda_test_delete "192.168.6.21" 13306 calvin calvin calvindb 1 1000
*/

static void usage()
{
	printf( "USAGE : mysqlda_test_delete (ip) (port) (user) (pass) (database) (begin_seqno) (end_seqno)\n" );
	return;
}

int main( int argc , char *argv[] )
{
	MYSQL		*conn = NULL ;
	char		*ip = NULL ;
	unsigned int	port ;
	char		*user = NULL ;
	char		*pass = NULL ;
	char		*database = NULL ;
	
	int		begin_seqno ;
	int		end_seqno ;
	int		seqno ;
	char		seqno_buffer[ 20 + 1 ] ;
	char		sql[ 4096 + 1 ] ;
	
	int		nret = 0 ;
	
	if( argc != 1 + 7 )
	{
		usage();
		exit(7);
	}
	
	printf( "mysql_get_client_info[%s]\n" , mysql_get_client_info() );
	
	conn = mysql_init(NULL) ;
	if( conn == NULL )
	{
		printf( "mysql_init failed\n" );
		return 1;
	}
	
	ip = argv[1] ;
	port = (unsigned int)atoi(argv[2]) ;
	user = argv[3] ;
	pass = argv[4] ;
	database = argv[5] ;
	if( mysql_real_connect( conn , ip , user , pass , database , port , NULL , 0 ) == NULL )
	{
		printf( "mysql_real_connect failed , mysql_errno[%d][%s]\n" , mysql_errno(conn) , mysql_error(conn) );
		return 1;
	}
	else
	{
		printf( "mysql_real_connect ok\n" );
	}
	
	memset( seqno_buffer , 0x00 , sizeof(seqno_buffer) );
	begin_seqno = atoi(argv[6]) ;
	end_seqno = atoi(argv[7]) ;
	for( seqno = begin_seqno ; seqno <= end_seqno ; seqno++ )
	{
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "select library %d" , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
		
		memset( sql , 0x00 , sizeof(sql) );
		snprintf( sql , sizeof(sql) , "delete from test_table where name='%d'" , seqno );
		nret = mysql_query( conn , sql ) ;
		if( nret )
		{
			printf( "mysql_query[%s] failed , mysql_errno[%d][%s]\n" , sql , mysql_errno(conn) , mysql_error(conn) );
			mysql_close( conn );
			return 1;
		}
		else
		{
			printf( "mysql_query[%s] ok\n" , sql );
		}
	}
	
	mysql_close( conn );
	printf( "mysql_close\n" );
	
	return 0;
}
```

# 7. ����ע������

## 7.1. �ÿͻ���mysqlֱ��mysqlda

* �����ÿͻ���mysqlֱ������mysqlda����"mysql --host 192.168.6.21 --port 3306 -u calvin -p"������ʱ��֧����������ֱ��ָ�����ݿ⡣
* ����ָ�����ݿ⣬mysqlda�Ѿ��������ļ��еĲ���use���ݿ��ˡ�
* ��¼�ɹ���ĵ�һ�����������ѡ����MySQL�����⣬��������ִ��DDL��DSL��DML��SQL��

# 8. ���

## 8.1. �����з�

* Ѱ��JAVA��������
* ����ֻ֧��mysqlda�����������������ʵ��mysqlda��������Ⱥ���ơ�
* �ڴ�ʹ���Ż�
* ���ٵ�����˥��
* ���๦��...

## 8.2. Դ���й�

* [��Դ�й�](http://git.oschina.net/calvinwilliams/mysqlda)
* [github](https://github.com/calvinwilliams/mysqlda/)

## 8.3. ��������

* [����](mailto:calvinwilliams@163.com)
