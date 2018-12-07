/*************************************************************************
	> File Name: 14.c
	> Author: Liu Shengxi 
	> Mail: 13689209566@163.com
	> Created Time: 2018年12月03日 星期一 11时21分46秒
 ************************************************************************/

#include<stdio.h>
14．以下是在某机器下执行 Linux 命令 ls 的部分输出（有删节），参考该输出，你可以说出哪些关于该命令以及其他 Linux 的相关知识？


[root@xiyoulinux /]# ls -al		
total 36					
drwxr-xr-x	17	root root	4096 Sep 21 23:45 .
drwxr-xr-x	17	root root	4096 Sep 21 23:45 ..
lrwxrwxrwx	1	root root	7 Aug 21 22:21 bin -> usr/bi
drwxr-xr-x	4	root root	2048	Jan  1  1970 boot
drwxr-xr-x	21	root root	3580 Nov 21 21:16 dev
drwxr-xr-x	83	root root	4096 Nov 21 22:12 etc
drwxr-xr-x	4	root root	4096	Sep 22 00:07	home
drwxr-xr-x	2	root root	4096	Aug 21 22:21	mnt
drwxr-x---	9	root root	4096	Nov 19 19:15	root
dr-xr-xr-x	13	root root	0 Nov 21 21:15 sys
drwxrwxrwt	10	root root	380	Nov 21 22:30	tmp
drwxr-xr-x	9	root root	4096	Nov 21 22:12	usr


//d,l(软硬链接),b（块设备）,c（字符）,s,p(管道　
//　17　（硬链接个数）
//　软链接（快捷方式），硬链接（文件的另一个别名）
// 目录的执行权限



