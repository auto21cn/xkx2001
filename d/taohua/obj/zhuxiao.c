//Cracked by Roath
// zhuxiao.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(GRN"����"NOR,({ "zhu xiao", "xiao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "bamboo");
                set("shape", "flute");
		set("long", "����һ�����������������Ƴɵ������\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(7);
	setup();
}

#include "flute.h"
#include "music.h"