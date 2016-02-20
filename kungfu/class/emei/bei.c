//Cracked by Roath
// bei.c ������
// shan: 96/09/22

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
        set_name("������", ({ "bei jinyi", "bei", "jinyi" }));
        set("long", 
		"�������ʦ̫�İ˴��׼ҵ���֮һ���ó������ƺ����ָѨ���Ĺ���\n");
	set("gender", "Ů��");
	set("age", 37);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 600);
	set("max_jing", 600);
	set("jiali", 30);
	set("neili", 1000);
	set("max_neili", 1000);

	set("combat_exp", 300000);
	set("score", 1000);

        set_skill("force", 90);
        set_skill("linji-zhuang", 90);
        set_skill("strike", 90);
        set_skill("jinding-zhang", 90);
        set_skill("sword", 60);
        set_skill("emei-jian", 60);
        set_skill("finger", 90);
        set_skill("tiangang-zhi", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("zhutian-bu", 90);
        set_skill("throwing", 80);
        set_skill("persuading", 40);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "emei-jian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");
	prepare_skill("strike", "jinding-zhang");

	create_family("������", 4, "����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
		"����" : "��ȥ��ɽ�����������Ҿ��ֱ�ʦ��ɡ������ڸ����֡�ǧ���֡�\n�����֡������ֺ����������С�\n",
            "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
        ]));

	setup();
	carry_object("/d/emei/npc/obj/hui-cloth")->wear();
	carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

void init()
{
        object ob;

	::init();
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "bei jinyi"   
        && ob->query("shen") < -100 ) {
        message_vision(
                "$n����$N˵��������ô��������˻��£��Ҷ��������������������ɣ�" +
			"�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n",
                ob, this_object() );
                command("expell " + ob->query("id"));
		ob->delete("emei_shen");
		return;
        }
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "bei jinyi"  
        && ob->query("class") == "bonze" ) {
		if (ob->query("gender") == "Ů��") {
        	message_vision(
                	"$n����$N˵�������Ȼ���˼ң����������������У�\n",
        		ob, this_object() );
           	command("say �ҿ��㲻���Ҹ����ø��Ҿ��ֱ�ʦ��ѧ�հɡ�\n");
		ob->delete("family/master_name");	
                ob->delete("family/master_id");
		return;
		}
                message_vision(
                        "$n����$N˵�������Ȼ���˼ң����������������У�\n",
                        ob, this_object() );
                command("say �ҿ��㲻��ȥ������Ѱʦ�ɡ�\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
       
}

#include "/kungfu/class/emei/sujia.h"
#include "/kungfu/class/emei/auto_perform.h"