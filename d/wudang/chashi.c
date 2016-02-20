//Cracked by Roath
// Room: /d/wudang/chashi.c
// By Marz 04/01/96
// xQin 11/00

#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
���ݵĹ���Ͳ��㣬������Ƣ��ɽ����Ĳ�ũ����м��䵱���ӱ�����
���������˵�ɧ�Һ͹ٸ��Ŀ�����˰��ÿ�꿪���ɲ輾�ڣ���Ҫ�����Ϻõ�
��Ҷ�����Ҷ����Ů���������ճ����ժ�������ڻ��������±��ƣ������
�������㴦�����㣬������Ů���㣢����˵�������ᾫ����ʮ�������
�����ܵ���ذ���Щ���ӣ�table�������ӣ�chair�����������䵱����Ů��
�ӡ��ϱ����ȴ��ӣ�window������ɫ���ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"donglang2",
	]));
	
    set("item_desc", ([
	    "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
	    "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��\n",
		"window" : "���ⶫ��Զ���һ�һƬ�����Ʋ��Ƹǵأ�����������\n",
	]));
	                                

	set("objects",([
		__DIR__"npc/xiaocui" : 1,
		__DIR__"obj/mitao" : 1,
		__DIR__"obj/xiangcha" : 1,
	]));
	
	set("no_fight", 1);
	
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

    if (arg != "window" && arg != "out") return command("jump "+arg);
    
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	
    message_vision("$N��ಣ���һ������������\n", me);
    
    if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )  
    {
    	message_vision("�����ž����һ��$N���������԰С·��ˤ�˸����ʵʵ��\n", me);
	    if ( objectp(ob=present("mi tao", this_player())) )
	    {
    		message_vision("ˮ���������ˣ�����$Nһƨ����֭��\n", me);
    		destruct(ob);
   		}
	    if ( objectp(ob=present("xiang cha", this_player())) )
	    {
    		message_vision("�������跭�ˣ�ʪ��$Nһ���Ӳ�ˮ��\n", me);
    		destruct(ob);
   		}
   		
   		me->receive_damage("qi", 60, "��¥�ϵ�����ˤ����");
   		me->receive_wound("qi", 40, "��¥�ϵ�����ˤ����"); 
   		me->improve_skill("dodge", random(3));
   		
    } else if (dex <= 26)
    {
    	message_vision("$Nҡҡ�λε������������԰С·�ϣ����ˤ����\n", me);
   		me->improve_skill("dodge", random(2));
    
    } else 
    {
    	message_vision("$N��һ��������̬������Ʈ���ڶ��ϵ���԰С·�ϣ�\n", me);
    }
    
    me->move(__DIR__"tysroad");
    
    return 1;
}

int do_tap(string arg)
{

	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("��Ҫ��ʲô��\n");	
	}
		
	me = this_player();	
	if( !objectp(cui = present("xiao cui", environment(me))) )
	 	return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("�����������ӣ�ȴû�뵽�ж������˴���������������Ȼ�ؿ����㣬"
	 		+"\n��ͻȻ�о��Լ����޴���\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("С�䲻�ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ��"+
				"���Ǹ��ң�����ҿɲ��ǰ���\n", me);
        return notify_fail("");
    }

	message_vision("$N��������ǰ��������������棬С��ݸ��һЦ�������к���\n", me);
	
	cui->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");	
}


int valid_leave(object me, string dir)
{

	if (  (dir == "north")
	   && ( present("xiang cha", this_player())
	        || present("mi tao", this_player()) ) 
	   && objectp(present("xiao cui", environment(me))) )
	switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("С�����һƲ���Ա��˺����˻����������߻��ﻹ����һЩ��СŮ��Ҳ���������أ�\n");
	 break;
	case 1:
	 message_vision("С���$N���˸��򸣣������˷Ը�����ʳ���ô����跿��", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}