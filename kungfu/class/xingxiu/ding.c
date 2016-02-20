//Cracked by Roath
// ding.c ������
#include "/kungfu/class/xingxiu/auto_perform.h"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_zhen();
int auto_perform();
string ask_suo();
string ask_wxs();
int ask_staff();
int ask_job();
int ask_chname();
void create()
{
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", "�����Ϲ�");
        set("long",  "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
                     "��������������ò���棬�ɷ���ǡ�\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 3500000);
        set("shen", -400000);
        set("apply/armor", 50);
        set("PKS", 1000000);

        set_skill("force", 400);
        set_skill("huagong-dafa", 400);
        set_skill("dodge", 360);
        set_skill("zhaixinggong", 400);
        set_skill("strike", 360);
        set_skill("claw", 360);
        set_skill("sanyin-zhua", 360);
        set_skill("poison", 400);
        set_skill("chousui-zhang", 360);
        set_skill("parry", 360);
        set_skill("staff", 360);
        set_skill("tianshan-zhang", 400);
        set_skill("feixing-shu", 360);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("sword", "tianshan-zhang");

        prepare_skill("strike", "chousui-duzhang");
        prepare_skill("claw", "sanyin-zhua");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("������", 1, "��ɽ��ʦ");
        //set("class", "taoist");
        set("san_count", 3);
        set("suo_count",1);
        set("zhen_count", 7);
        set("wxs_count",3);
        set("inquiry", ([
                "��ң��Цɢ" : (: ask_me :),
                "������" : (: ask_zhen :),
                "��˿��" : (: ask_suo :),
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"����ɢ" : (: ask_wxs :),
		"������" : (: ask_staff :),
		"����" : (: ask_chname :),
        ]));

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/rousi-suo");
}


void init()
{
        object ob,ob1;
        
        ::init();
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && ob->query("shen") > 100 && ob->query("id")!="wsky") {
                command("say " + RANK_D->query_rude(ob) + "���㵨����׵������£���Ȼ�ǲ�����������˰ɡ�/n");
                command( "expell " + ob->query("id"));
        }
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && (!present("yu di", this_player()))){
                ob1=new("/d/xingxiu/obj/yudi");
                ob1->move(this_player());
                command("say ��ֻ������������޵��ӵĻ���������ú����ţ�����Ū����");
                write("���������һֻ��ѡ�\n");
        }
        add_action("do_flatter", "flatter");
}


void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100000) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }
        if( me->query("family/family_name") == "ؤ��"
        && me->query("combat_exp") >= 10000 ) {
                command ("say ������ƽ��޽л��ӣ�����ҹ���ԶԶ�ģ�");
                return;
        }
        if ((int)me->query_skill("poison", 1) < 50){
                command("say " + RANK_D->query_respect(me) +
                        "�Ķ�������ô���ȥ��ץ���������˵�ɡ�");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ��������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        object ob;
        string name, new_name;
        mapping fam;
        int x;
        int contribution=this_player()->query("xingxiu/contribution");
        
        fam=this_player()->query("family");
        
        if (this_player()->query_temp("pending/flatter")){ 	                
        	if( !arg ) return notify_fail("��˵����ʲô��\n");
        	this_player()->set_temp("pending/flatter", 0);
        	message_vision("$N����˵����" + arg + "\n", this_player());
        	if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
	         	|| strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                	command("smile");
                	this_player()->set("oldname", name);
                	name = this_player()->query("name");
                	x=random(3);
                	if (x==3)             	
                		new_name =  name[0..01] + name[2..3] + "��";
                	else if (x==2) 
                		new_name =  name[2..3] + name[0..01] +  "��";
                	else if (x==1)
                		new_name =  name[0..01]+ "��" + "��";
                	else 
                		new_name =  name[0..01]+ "��" + "��";
                	
                	command("say �⻹��࣬�ӽ��Ժ�������ֽ���" + new_name + "��");
                	this_player()->set("name", new_name);
                	command("recruit " + this_player()->query("id"));
		        if (!present("yu di", this_player())){
                		ob=new("/d/xingxiu/obj/yudi");
                		ob->move(this_player());
                		command("say ��ֻ������������޵��ӵĻ���������ú����ţ�����Ū����");
                		write("���������һֻ��ѡ�\n");
        		}
        	} else {
                	command("say ����˲������ɷ�����������������㣿");
        	}
        	return 1;
        } else if(fam["family_name"]=="������") {
		if(contribution<100){
			command("say ����쵰�����������ң�");
		} else if(contribution>100 && contribution<500) {
			command("say ͽ���ɵò������ٽ���ȥΪʦһ�����͡�");
		} else if(contribution>500) {
			command("say ��ͽ������������ʲô�������ĵط��������ҡ�");
			this_player()->set_temp("canask",1);
		}
		return 1;	
	}

	return 0;

        
        
}

int ask_chname(){
	
	object me=this_player();
	mapping fam;
	string name, new_name;
	int contribution=this_player()->query("xingxiu/contribution");
	int x;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("say ����Ҫ����Ц��");
		return 1;
	}
	
	if (contribution<100) {
		command("shake "+me->query("id"));
		command("say ������ɹ��ײ�����");
	} else {
		command("ok");
		name = this_player()->query("name");
                new_name=name;
                
                while(name==new_name) {
                
                x=random(6);
                
                if (x==6)             	
                	new_name =  name[0..01] + name[2..3] + "��";
                else if (x==2) 
                	new_name =  name[2..3] + name[0..01] + "��";
                else if (x==1)
                	new_name =  name[0..01]+ "��" +  "��";
                else if (x==3)
                	new_name =  name[0..01]+ "��" +  "��";
                else if (x==4)
                	new_name =  name[0..01]+ "Ե" +  "��";
                else if (x==5)
                	new_name =  name[0..01]+ "ڤ" +  "��";
                else 
                	new_name =  name[0..01]+ "��" +  "��";
                
	        }
        
                command("chat �ӽ��Ժ�"+name+"�����ֽ���" + new_name + "��");
                
                this_player()->set("oldname", name);
                this_player()->set("name", new_name);	
                this_player()->add("xingxiu/contribution", -50);	
	}

	return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
string ask_suo()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) || fam["family_name"]!="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("suo_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("rousi suo", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "�ⶫ����ɲ����档";
        add("suo_count", -1);
        ob = new("/d/xingxiu/obj/rousi-suo");  
        ob->move(this_player());   
        say("���������һ����˿����\n");
        return "�ðɣ���ȥ�ú����á�����Ϊʦ������Ѫ���ã����Ҫ��ϧ��";
}

string ask_wxs()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) ||fam["family_name"]!="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("wxs_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("wuxing san", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "�ⶫ����ɲ����档";
        add("wxs_count", -1);
        ob = new("/d/xingxiu/obj/wuxing");  
        ob->move(this_player());   
        say("���������һ������ɢ��\n");
        return "�ðɣ���ȥ�ú����á�����Ϊʦ������Ѫ���ã����Ҫ��ϧ��";
}


string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("san_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("sanxiao san", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if (this_player()->query_skill("poison", 1) < 100 ||
        this_player()->query_skill("feixing-shu", 1) < 100 ||
        this_player()->query_skill("huagong-dafa", 1) < 100)
                return "�ⶫ����ɲ����档";
        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiao");
        ob->move(this_player());
        say("���������һ����ң��Цɢ��\n");
        return "�ðɣ���ȥ�ú����á�";
}

string ask_zhen()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="������")
                return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("zhen_count") < 1)
                return "�������ˣ�������ʦ���������ˡ�";
        if (  present("bilin zhen", this_player()) )
                return "���Ǹո���������ô����Ҫ�ˣ�";
        if (this_player()->query_skill("poison", 1) < 50 ||
        this_player()->query_skill("feixing-shu", 1) < 50 ||
        this_player()->query_skill("huagong-dafa", 1) < 50)
                return "�ⶫ����ɲ����档";
        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/blzhen");
        ob->move(this_player());
        say("���������һ�ѱ����롣\n");
        return "�ðɣ�ȥ���Ҹɵ������׵������";
}


int ask_job(){
	
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}
		
        if(me->query_temp("xx_job")==1) {
                command("say ��С�ӣ���һ������û����ɾ͸������ҹ�����");
                return 1;
        }
        command ("say �����������������ҪһЩ�������㵽��ɽ��Щ�����Ұɡ���");
	waguan=new("/d/xingxiu/obj/waguan");
        me->set_temp("xx_job",1);
	if (!present("wa guan", me)) waguan->move(me);
	
	return 1;

}


int ask_staff(){
	
	object me=this_player();
	object waguan;
	mapping fam;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 1;
	}
		
	if (me->query("tianshan")==1){
		command("say ��Ҫ���������ĵ���Ц��");
		return 1;
	}
	
	if (me->query_skill("pixie-jian",1)>=10){
		command("hmm");
		command("say ������ʧ�������������˹���");
		return 1;	
	}
			
	if (me->query_skill("staff", 1) < 250){
		command("say ������ȷ�����Ϊ������");
	}
	
	if (me->query_str() < 50) {
		command("say �������̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
	
	if (me->query_con() < 50) {
		command("say ����ڹ���Ϊ̫���ˣ��úö��������������Ұɡ�");
		return 1;
	}
		
	if (me->query_int() < 35) {
		command("sneer");
		command("say ������ѧ��������������̫���ȥ�úö�һ����ɡ�");
		return 1;
	}
		
	
        if(me->query_temp("canask")==1) {
                message_vision(HIG"$N΢΢һЦ����$n����һ�ԣ������ؽ���������������һ�С�\n", this_object(), this_player());
                message_vision(HIG"$n��$N�Ľ����£�����ɽ�ȷ�������һ���µ����⡣", this_object(), this_player());
                me->set("tianshan", 1);
                tell_object(this_object(),HIC"�����ɽ�ȷ������ˣ�");
        	me->add_skill("tianshan-zhang", 10);
                return 1;
        }
        
        
	return 1;

}
// �������ɣ�������أ��������Ž��ޱ�

int accept_object(object who, object ob){

	object me=this_player();
	mapping fam;

	if (!(fam = this_player()->query("family")) || fam["family_name"] !="������"){
		command("?");
		return 0;
	}		

	if(ob->query("id")=="du dan"){

                if (this_player()->query_temp("xx_job")!=1 || ob->query("player")!=me->query("id")) {
			command("hehe");
			return 0;
		} else {
                        command("pat "+this_player()->query("id"));        
			command("say �����ģ�������Խ����Խ˳���ˡ�\n");
			me->add("combat_exp", 80+random(80));
			me->add("potential", random(80));
			if(me->query("potential")>me->query("max_potential"))
				me->set("potential",me->query("max_potential"));
			me->add("xingxiu/contribution", 1);
			me->delete_temp("xx_job");
			me->delete_temp("found");
			me->delete_temp("bug_hold");
			me->delete_temp("bug_out");
			call_out("destob",1,ob);
			return 1;
		}
	}
	
	if(ob->query("id")=="ling pai"){
		if(ob->query("player")!=me->query("id")){
			command("hehe");
			return 0;
		} else {
			command("hehehe");
			command("say �����ģ�����Щ�Գ��������ɵ�֪�����ɵ�������\n");
			if (ob->query("menpai")=="huashan" || ob->query("menpai")=="quanzhen")
				me->add("combat_exp", 350+random(50));
			else  if(ob->query("menpai")=="mingjiao") {
				command("say �š������̾�ȻҲ���Ҹ����ˡ�\n");
				me->add("combat_exp", 500+random(50));
			} else	me->add("combat_exp", 200+random(50));
			
			call_out("destob",1,ob);
			return 1;					
		}
	}
	
	
	command("hmm");
	command("say ���������ʲô��");
	return 0;
	
}	

void destob(object ob){
	destruct(ob);
}