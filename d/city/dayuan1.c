//Cracked by Roath
// Room: /city/dayuan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "���ָ�Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ����˵��
���껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û����������дУ��ڸ�
�˴���Ժ�ӣ��Ե���ɭ�ֲ���һ�������ߵ�ͨ����Ժ���м����Ҷ����ء�
LONG
	);

	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"caizhu",
	]));

	set("objects", ([
		__DIR__"npc/guanjia" : 1,
                __DIR__"npc/jiading" : 2,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
