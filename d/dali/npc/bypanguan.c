//Cracked by Roath
// bypanguan.c �����й�

inherit NPC;

void create()
{
	set_name("�����й�", ({ "pan guan", "pan" }));
	set("long", "��������������й�֮һ���ٷ��������ԭ����ԨԴ��Ψ����Ϊ���ѣ�����ԭ��\n������֮���ǲ��岻�����Ტ�ۡ������й��Ƕ������ڶ����֣��������վ��ף�\n������Ѷ����Ϊ�ϳɡ�ֻ����ͷ����ڣ���Ϯ�������ŵŲ��ģ�����֮ɫ������\n�ϡ�\n");
	set("gender", "����");
	set("age", 50+random(10));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 70000+random(20000));
	set("dalinpc",1);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}