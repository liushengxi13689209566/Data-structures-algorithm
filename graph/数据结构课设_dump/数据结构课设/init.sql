






drop database if exists Graph ;
create  database Graph ;     /*创建图的数据库*/
use Graph ;



drop table if exists City ;  /*城市集*/
create table City ( BigIndex INT UNSIGNED PRIMARY KEY auto_increment ,CityName CHAR(32),CityInfo VARCHAR(200));
INSERT INTO City   VALUES(NULL ,"兰州","https://baike.baidu.com/item/%E5%85%B0%E5%B7%9E/170826?fr=aladdin") ;
INSERT INTO City   VALUES(NULL ,"内蒙古 ","https://baike.baidu.com/item/%E5%86%85%E8%92%99%E5%8F%A4") ;
INSERT INTO City   VALUES(NULL ,"天水" ,  " https://baike.baidu.com/item/%E5%A4%A9%E6%B0%B4") ;
INSERT INTO City   VALUES(NULL ,"西安 ", " https://baike.baidu.com/item/%E8%A5%BF%E5%AE%89/121614") ;
INSERT INTO City   VALUES(NULL ,"成都","https://baike.baidu.com/item/%E6%88%90%E9%83%BD/128473") ;
INSERT INTO City   VALUES(NULL ,"重庆","https://baike.baidu.com/item/%E9%87%8D%E5%BA%86/23586") ;
INSERT INTO City   VALUES(NULL ,"武汉","https://baike.baidu.com/item/%E6%AD%A6%E6%B1%89/106764") ;
INSERT INTO City   VALUES(NULL ,"上海","https://baike.baidu.com/item/%E4%B8%8A%E6%B5%B7/114606") ;
INSERT INTO City   VALUES(NULL ,"首尔","https://baike.baidu.com/item/%E9%A6%96%E5%B0%94/61723") ;
INSERT INTO City   VALUES(NULL ,"北京","https://baike.baidu.com/item/%E5%8C%97%E4%BA%AC/128981") ;
INSERT INTO City   VALUES(NULL,"郑州","https://baike.baidu.com/item/%E9%83%91%E5%B7%9E") ;


drop table if exists Edge ;   /*边的信息*/
create table Edge ( temp INT UNSIGNED PRIMARY KEY auto_increment , index_A INT UNSIGNED  ,index_B INT UNSIGNED ,distance INT UNSIGNED  , money float ,time INT UNSIGNED ) ;
INSERT INTO Edge   VALUES(NULL ,0 ,1, 1083,   396,  821) ;
INSERT INTO Edge   VALUES(NULL ,0, 2 ,290 , 92.5  ,302) ;
INSERT INTO Edge   VALUES(NULL,0 ,3  ,636 , 170.5, 558) ;
INSERT INTO Edge   VALUES(NULL,3 ,4 ,715 ,112  ,600) ;
INSERT INTO Edge   VALUES(NULL,3 ,9 ,1085 ,148 ,926) ;
INSERT INTO Edge   VALUES(NULL ,3 ,10 ,482 ,72.5 ,360) ;
INSERT INTO Edge   VALUES(NULL ,3 ,6 ,745 ,135.5 ,620) ;
INSERT INTO Edge   VALUES(NULL ,3 ,5 ,969 ,279  ,611) ;
INSERT INTO Edge   VALUES(NULL,5 ,6 ,876 ,138  ,660) ;
INSERT INTO Edge   VALUES(NULL,4 ,7 ,1953 ,606 ,1200) ;
INSERT INTO Edge   VALUES(NULL,5 ,10 ,1166 ,173.5, 840) ;
INSERT INTO Edge   VALUES(NULL,9 ,8   ,945 ,800 ,520) ;
INSERT INTO Edge   VALUES(NULL,9 ,10 ,688 ,309 ,480) ;
INSERT INTO Edge   VALUES(NULL,9 ,7 ,1222 ,553.5, 850) ;
INSERT INTO Edge   VALUES(NULL,7 ,8 ,1111 ,556 ,666) ;



