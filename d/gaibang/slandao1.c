//Cracked by Roath
// Room: /d/gaibang/slandao1.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"northeast" : __DIR__"slandao2",
			"southwest" : __DIR__"undertre",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}


