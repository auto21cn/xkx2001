//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ֽС������š���һ��ĵ�ɽ���������ﶼ���ۼ�������
�������̩ɽ��һ�밡�����ǰ���վ���ʮ���̣��ܶ��˶�������
ԥ������
LONG
	);

	set("exits", ([
		"northup" : __DIR__"wudafu",
		"southdown" : __DIR__"huima",
	]));

	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}
