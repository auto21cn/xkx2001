//Cracked by Roath
// Room: /d/dali/wuhua5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�����ң����ﴰ���������þ߿��������Ǵ���һ������������Ǽ�
ֵ���ơ�ƾ�������������ڵ���֮�пɼ���ɽ��ַ壬ֻ��ɽ�����㣬������Σ�
�����Ŀ�������
LONG);
	set("exits", ([
		"out" : __DIR__"wuhua6.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}