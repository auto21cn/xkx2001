//Cracked by Roath
// Room: /d/dali/shilin3.c

inherit ROOM;

void create()
{
	set("short", "��Ħ��ʯ��");
	set("long", @LONG
����ʯ�ŷ��ʯ���ͣ�ʯ����ڹ��ӣ����ư��磬�����ŭ�γ������
����ϸ�µĶ������٣����������侳��̤ʯ�㣬��ʯ�ţ���Ұ�ݣ�̽���֣�����
ɽ�����ڣ�Σʯɭɭ�����ԭҰ������ɽ�����󣬻������ƣ�һ��ǿ�ҵ�ɽҰζ
ӭ��������������εĴ������Ȼ�������˶�Ŀһ�¡�
LONG);
	set("objects", ([
		__DIR__"npc/tufei" : 1+random(3),
		]));
	set("exits", ([
		"southwest" : __DIR__"shilin5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}