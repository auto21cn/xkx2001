//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create()
{
   set_name("������", ({"yangjing dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 1000);
      set("medicine", 1);
   }
   setup();
}

int cure_ob(object me)
{
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("xx_poison") > 50){
   tell_object(me, "���ж�̫���ҩûʲ��Ч��\n");
   destruct(this_object());
   return 1;
   }

   if ((int)me->query("eff_jing") < (int)me->query("max_jing")) {
      me->apply_condition("jing_curing", me->query_condition("jing_curing")
         + 10);
   }

   destruct(this_object());
   return 1;
}