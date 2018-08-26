# 此文件由makeobj.sh自动生成
############################################################
# 项目名 : 
# 模块名 : 
# 备  注 : 
############################################################

###### 源文件配置区
#@ c_FILE
c_FILE		=	\
			test_main.c \
			test_astar_01.c \
			test_astar_02.c \
			test_astar_03.c \
			test_astar_98.c \
			test_astar_99.c \

###### 目标文件、安装目录配置区
include makeinstall
BIN		=	\
			test_astar_01	\
			test_astar_02	\
			test_astar_03	\
			test_astar_98	\
			test_astar_99	\

###### 编译选项
CFLAGS		=	$(_CFLAGS) \
			-I$(HOME)/include/libastar \

###### 链接选项
LFLAGS		=	$(_LFLAGS) \
			-L$(HOME)/lib \
			-lastar \
			-lm \

###### 额外宏定义区
CLEAN_ADDITION	=

PREMAKE		=

###### 加载mktpl模板库
#@ make_all
#@ make_clean
#@ make_install
#@ make_install_BININST
#@ make_install_DFTHDERINST
#@ make_uninstall
#@ make_uninstall_BININST
#@ make_uninstall_DFTHDERINST
include $(MKTPL2_HOME)/makeobj_$(MKTPL2_OS).inc

###### 目标文件依赖关系
test_astar_01		:	test_main.o test_astar_01.o
	$(CC) -o $@ test_main.o test_astar_01.o $(LFLAGS)

test_astar_02		:	test_main.o test_astar_02.o
	$(CC) -o $@ test_main.o test_astar_02.o $(LFLAGS)

test_astar_03		:	test_main.o test_astar_03.o
	$(CC) -o $@ test_main.o test_astar_03.o $(LFLAGS)

test_astar_98		:	test_main.o test_astar_98.o
	$(CC) -o $@ test_main.o test_astar_98.o $(LFLAGS)

test_astar_99		:	test_main.o test_astar_99.o
	$(CC) -o $@ test_main.o test_astar_99.o $(LFLAGS)

