//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIG "�������" NOR, ({ "jade earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 7000);
                set("long", "һ���Ա������ɵĶ��Σ������������������Ĺ������ĸо���\n");
                set("material", "jade");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}